%{
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;
    extern FILE *yyout;
    
    // Symbol table structure
    struct SymbolTable {
    char* name;
    int isAssigned;
    int intValue;
    float floatValue;
    int dataType;  // 0 for INT, 1 for FLOAT, add more if needed
    };

    struct FunctionTable {
    char* name;
    int no_of_param;
    int return_value_int;
    float return_value_float;
    int return_type;  // 0 for INT, 1 for FLOAT, add more if needed
    };
    
    struct SymbolTable* searchVariable(char* name);
    struct FunctionTable* searchFunction(char* name);

    

    int type_of_data;
    int condition_val = 1;
    /*int loop_inc_val;
    int loop_inc_op;
    int loop_ini_val;
    int loop_con_st_val;
    int loop_con_end_val;
    int loop_con_op;*/
    int no_of_func_param=0;

    // Function to insert a new variable into the symbol table
    void insertVariable(char* name, int isAssigned, int intValue, float floatValue, int dataType);
    void insertFunction(char* name, int no_of_param, int return_value_int, float return_value_float, int return_type);

    void yyerror(char *s); //declaration
    #define MAX_SYMBOLS 100
    struct SymbolTable symbolTable[MAX_SYMBOLS];
    struct FunctionTable functionTable[MAX_SYMBOLS];

int index = 0;
int functionTableSize = 0;
%}
%token <stringValue> ID
%token <intValue> NUM
%token <floatValue> FLOAT

%token INPUT SIN COS TAN FACTORIAL PRIME FUNC RETURN HEADERFILE MAINSTART SINGLE_LINE_COMMENT MULTI_LINE_COMMENT INT HASH DOT LT GT NEWLINE TAB SPACE HASH_HASH COMMENT IF ELSE SHOW LOOP

%start start
%left '<' '>'
%left '+' '-'
%left '*' '/'

%nonassoc IFX
%nonassoc ELSE
%union
{
    int intValue;
        float floatValue;
        char *stringValue;
 
};
%type <floatValue> var_dec2  
%type <floatValue> expression
%type <intValue> data_type
%type <intValue> condition
%type <intValue> initialize
%type <intValue> loop_con_symbol
%type <intValue> loop_inc_symbol
%type <floatValue> return_val
%%

start:  header main 
    ;
header:   header1 user_function
    ;
header1:    header2;
header2:   
    |   HEADERFILE header2 {printf("HEADERFILE included\n");} 
    ;
user_function:
    |  function user_function
    ;

main:   main2 mainbegin2 main3
    ;
main2:  MAINSTART  {printf("\n\nMain Started.\n\n");}
    ;
main3: '}' { printf("\n\n");
            printSymbolTable();
            printf("\n\n");
            printFunctionTable();
    printf("\n\nMain ENDED\n");}


// from mainbegin2 i will continue repeating
mainbegin2:
    |   mainbegin2 var_dec
    |   mainbegin2 comment
    |   mainbegin2 if_structure
    | mainbegin2 statement;
    //| mainbegin2 condition
    | mainbegin2 loop_structure
    | mainbegin2 function_call
    | mainbegin2 builtin_function
    | mainbegin2 user_input
    ;

// user_input started
user_input: ID '=' INPUT '(' FLOAT ')' ';' {
        
        struct SymbolTable* variable = searchVariable($1);
            if(variable){
                printf("\nUser input is at variable %s with value %f\n",$1,$5);
                if (variable->dataType == 0) {
                    variable->isAssigned = 1;
                    variable->intValue = $5;
                    variable->floatValue = $5;
                } else if (variable->dataType == 1) {
                    variable->isAssigned = 1;
                    variable->intValue = $5;
                    variable->floatValue = $5;
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable not declared.\n");
            }

    }
    |   ID '=' INPUT '(' NUM ')' ';' {
            struct SymbolTable* variable = searchVariable($1);
            if(variable){
                printf("\nUser input is at variable %s with value %d\n",$1,$5);
                if (variable->dataType == 0) {
                    variable->isAssigned = 1;
                    variable->intValue = $5;
                    variable->floatValue = $5;
                } else if (variable->dataType == 1) {
                    variable->isAssigned = 1;
                    variable->intValue = $5;
                    variable->floatValue = $5;
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable not declared.\n");
            }
        }



// user_input ended
// builtin_function started

builtin_function:   PRIME '(' NUM ')' ';' {
            // this will check if prime or not
            int n, i, flag = 0;
            n = $3;
            if (n == 0 || n == 1){flag = 1;}
                        
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) { printf("%d is a prime number.", n); }
            else{
                printf("\n%d is not a prime number.\n", n);
            }
        }
    | FACTORIAL '(' NUM ')' ';' {
        // this will find FACTORIAL of a value
            int n, i;
            n = $3;
            unsigned long long fact = 1;
        if (n < 0){ printf("Error! Factorial of a negative number doesn't exist.");}
        else {
                for (i = 1; i <= n; ++i) {
                    fact *= i;
                }
                printf("\nFactorial of %d = %llu\n", n, fact);
        }
    }
    | SIN '(' FLOAT ')' ';' {
        float i = $3;
        float sin_value = sin(i);
        printf("The value of sin(%f) : %f \n", i, sin_value);
    }
    | COS '(' FLOAT ')' ';' {
        float i = $3;
        float cos_value = cos(i);
        printf("The value of cos(%f) : %f \n", i, cos_value)
    }
    | TAN '(' FLOAT ')' ';' {
        float i = $3;
        float tan_value = tan(i);
        printf("The value of tan(%f) : %f \n", i, tan_value);
    }
    ;


// builtin_function ended
// Function Started


function: func_start data_type ID '('parameter_list ')' '{' mainbegin2 RETURN return_val ';' '}' {
    
    //printf("Number of parameter of this function is %d\n",no_of_func_param);
    insertFunction($3, no_of_func_param, $10, $10, $2);
    //printf("Return value is %f\n",$10);
    no_of_func_param=0;
    printf("User defined function ended\n");
    //printFunctionTable();
};
func_start: FUNC {printf("\n\nUser defined function started\n");}
parameter_list:
             | expression {no_of_func_param++; }
             | parameter_list ',' expression {no_of_func_param++; }
    ;

return_val: FLOAT {  
                $$ = $1; // Store the parsed float value
                //printf("float %f %f\n",$1,$$);
        } 
    
    |   NUM {   
                $$ = $1; // Store the parsed integer value
                printf("float %d %d\n",$1,$$);
        } 


//Function ended

// function_call start
function_call: ID '('parameter_list ')' ';' {
    struct FunctionTable* func = searchFunction($1);
            if(func){
                if(func->no_of_param!=no_of_func_param){
                    printf("\nNo of parameter do not match\n");
                }
                else{
                    printf("\nUser defined Funtion Called\n");
                }
            }
             else {
                printf("\nFunction does not exist.\n");
            }
}
// function_call end
// loop_structure Started
loop_con_symbol:    '<' {$$=1;}
            |   '>' {$$=2;}
             |   '<=' {$$=3;}
              |   '>=' {$$=4;}
              ;

loop_inc_symbol:    '+' {$$=1; }
            |   '-' {$$=2;}
             |   '*' {$$=3;}
              |   '/' {$$=4;}
              ;
loop_structure: LOOP '#' initialize '#' ID loop_con_symbol NUM '#' ID '=' ID loop_inc_symbol NUM '#' mainbegin2 '#'{
        if($6==1){
            if($12==1){
                for(int i=$3;i<$7;i=i+$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==2){
                for(int i=$3;i<$7;i=i-$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==3){
                for(int i=$3;i<$7;i=i*$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==4){
                for(int i=$3;i<$7;i=i/$13){
                    printf("value of var is %d\n",i);
                }
            }
        }
        else if($6==2){
            if($12==1){
                for(int i=$3;i>$7;i=i+$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==2){
                for(int i=$3;i>$7;i=i-$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==3){
                for(int i=$3;i>$7;i=i*$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==4){
                for(int i=$3;i>$7;i=i/$13){
                    printf("value of var is %d\n",i);
                }
            }
        }
        else if($6==3){
            if($12==1){
                for(int i=$3;i<=$7;i=i+$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==2){
                for(int i=$3;i<=$7;i=i-$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==3){
                for(int i=$3;i<=$7;i=i*$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==4){
                for(int i=$3;i<=$7;i=i/$13){
                    printf("value of var is %d\n",i);
                }
            }
        }
        else if($6==4){
            if($12==1){
                for(int i=$3;i>=$7;i=i+$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==2){
                for(int i=$3;i>=$7;i=i-$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==3){
                for(int i=$3;i>=$7;i=i*$13){
                    printf("value of var is %d\n",i);
                }
            }
            else if($12==4){
                for(int i=$3;i>=$7;i=i/$13){
                    printf("value of var is %d\n",i);
                }
            }
        }

        printf("LOOP ENDED\n");
        
}


initialize: ID '=' NUM {

            printf("\n\nLOOP STARTED\n");
            //loop_ini_val = $3;
                //printf("came to initialization\n");
                struct SymbolTable* variable = searchVariable($1);
            if(variable){
                variable->intValue = $3;
                variable->floatValue = $3; 
                variable->isAssigned = 1;
                $$ = $3;
            }
             else {
                printf("Variable not declared.\n");
            }
        }
        |   ID {
                    printf("\n\nLOOP STARTED\n");

            struct SymbolTable* variable = searchVariable($1);
            if(variable){
                //loop_ini_val = variable->intValue ;
                $$ = variable->intValue;
            }
             else {
                printf("Variable not declared.\n");
            }
        }


// if sturc Started
if_structure:
        |   if_structure IF '(' condition ')' '{' mainbegin2 '}' ELSE '{' mainbegin2 '}'  { printf("\n  IF ELSE executed\n"); }
        |   if_structure IF '(' condition ')' '{'  mainbegin2 '}'  %prec IFX { printf("\n  IF executed\n"); }
        ;
/*statements:
        | statements statement;*/
statement:  
        |    ID '=' expression ';'{
            //printf("statement\n");

            if(condition_val==1){
                struct SymbolTable* variable = searchVariable($1);
            if(variable){
                if (variable->dataType == 0) {
                    variable->intValue = $3;
                    variable->floatValue = $3;
                    variable->isAssigned = 1;
                } else {
                    // Handle other data types as needed
                    printf("Variable %s Not declared\n",$1);
                }
            }
            //printSymbolTable();
         }
         else{
            condition_val=1;
         }
            
        }
        | SHOW '(' var_dec2 ')' ';' {
            printf("\nprinting : %f\n",$3);
        }
        ;

condition:
    expression '<' expression {  
       // printf("came to initialization <\n");
        /*loop_con_st_val = $1;
        loop_con_op = 1;
        loop_con_end_val = $3;*/
        if($1<$3){
             $$ = 1; } 
             else{
                $$=0;
                condition_val=0;
             }
        }
    |   expression '>' expression {
        //printf("came to initialization >\n");
        /*loop_con_st_val = $1;
        loop_con_op = 2;
        loop_con_end_val = $3;*/
        if($1>$3){
             $$ = 1; } 
             else{
                $$=0;
                condition_val=0;
             }
        }
    |   expression '<=' expression {
        //printf("came to initialization <=\n");
        /*loop_con_st_val = $1;
        loop_con_op = 3;
        loop_con_end_val = $3;*/
        if($1<=$3){
             $$ = 1; } 
             else{
                $$=0;
                condition_val=0;
             }
        }
    |   expression '>=' expression {
       // printf("came to initialization >=\n");
        /*loop_con_st_val = $1;
        loop_con_op = 4;
        loop_con_end_val = $3;*/
        if($1>=$3){
             $$ = 1; } 
             else{
                $$=0;
                condition_val=0;
             }
        }
    ; 

// expression evalution Started
expression: NUM {$$ = $1; }
        | ID {
            struct SymbolTable* variable = searchVariable($1);
            if(variable){
                if (variable->dataType == 0) {
                    $$ = variable->intValue;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    $$ = variable->floatValue;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
        }
        |expression '+' expression {$$ = $1 + $3;}
        |expression '-' expression {$$ = $1 - $3;}
        |expression '*' expression {$$ = $1 * $3;}
        |expression '/' expression {$$ = $1 / $3;}

// expression evalution ended

comment:    SINGLE_LINE_COMMENT {printf("\n\nSINGLE_LINE_COMMENT\n\n");}
    
    ;

//variable declaration Started
var_dec:    data_type ID var_dec1 {
                
                struct SymbolTable* var = searchVariable($2);
                if (var) {
                    printf("variable %s already exists\n",$2);
                } else {
                    type_of_data = $1;
                    insertVariable($2, 0, 0, 0, $1);
                    printf("Variable %s is declared\n",$2);
                }   
            }
            | data_type ID '=' var_dec2 var_dec1 {
                
                struct SymbolTable* var = searchVariable($2);
                if (var) {
                    printf("variable %s already exists\n",$2);
                } else {
                    type_of_data = $1;
                    
                    if($1==0||$1==1){
                        insertVariable($2, 1, $4, $4, $1);
                        printf("Variable %s is declared \n",$2);
                    }
                    else{
                        printf("Type is not matched, give int or float\n");
                    }
                    
                     
                }
            }
            ;
var_dec2: FLOAT { $$ = $1;  } 
     |   NUM  {   $$ = $1; } 
     |   ID {
            struct SymbolTable* variable = searchVariable($1);
            if(variable){
                if (variable->dataType == 0) {
                    $$ = variable->intValue;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    $$ = variable->floatValue;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
    }
    |   var_dec2 '+' ID {
            struct SymbolTable* variable = searchVariable($3);
            if(variable){
                if (variable->dataType == 0) {
                    $$ = variable->intValue + $1;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    $$ = variable->floatValue + $1;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
    }
    |   var_dec2 '+' NUM {  $$ = $1 + $3 ;  }
    |   var_dec2 '+' FLOAT {  $$ = $1 + $3 ;  }
    |   var_dec2 '-' ID {
            struct SymbolTable* variable = searchVariable($3);
            if(variable){
                if (variable->dataType == 0) {
                    $$ = $1 - variable->intValue ;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    $$ = $1 - variable->floatValue;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
                }
            } else {
                printf("Variable does not exist.\n");
            }
    }
    |   var_dec2 '-' NUM { $$ = $1 - $3 ; }
    |   var_dec2 '-' FLOAT { $$ = $1 - $3 ; }
    |   var_dec2 '*' ID {
            struct SymbolTable* variable = searchVariable($3);
            if(variable){
                if (variable->dataType == 0) {
                    $$ = variable->intValue * $1;
                   // printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    $$ = variable->floatValue * $1;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable %s does not exist.\n", variable);
            }
    }
    |   var_dec2 '*' NUM {  $$ = $1 * $3 ;  }
    |   var_dec2 '*' FLOAT {  $$ = $1 * $3 ;  }

    |   var_dec2 '/' ID {
            struct SymbolTable* variable = searchVariable($3);
            if(variable){
                if (variable->dataType == 0) {
                    $$ = $1 / variable->intValue;
                    //printf("Variable val %d\n",variable->intValue);
                    //printf("first condition\n");
                } else if (variable->dataType == 1) {
                    $$ = $1 / variable->floatValue ;
                    //printf("second condition\n");
                } else {
                    // Handle other data types as needed
                    printf("Unknown data type\n");
            }
            } else {
                printf("Variable does not exist.\n");
            }
    }
    |   var_dec2 '/' NUM {  $$ = $1 / $3;}
    |   var_dec2 '/' FLOAT { $$ = $1 / $3;}
    ;
var_dec1:   ';'
    |   ',' ID var_dec1 {
       // printf("ID is %s\n",$2);
                struct SymbolTable* var = searchVariable($2);
                if (var) {
                    printf("variable %s already exists\n",$2);
                } else {
                    insertVariable($2, 0, 0, 0, type_of_data);
                    printf("Variable %s is declared\n",$2);
                }
    }
    |    ',' ID '=' var_dec2 var_dec1 {
       // printf("%s value is %d\n",$2,$4);
                struct SymbolTable* var = searchVariable($2);
                if (var) {
                    printf("variable %s already exists\n",$2);
                } else {
                    
                    insertVariable($2, 1, $4, $4, type_of_data);
                    printf("Variable %s is declared\n",$2);

                }
        }
    ;
data_type: INT { $$ = 0;}
    |   FLOAT { $$ = 1;}
    ;
// variable declaration ended

// if structure


%%
int main()
{

    // Open a file for writing
    FILE *outputFile = fopen("output.txt", "w");

    // Check if the file opened successfully
    if (outputFile == NULL) {
        perror("Error opening output.txt");
        return EXIT_FAILURE;
    }
    if (freopen("output.txt", "w", stdout) == NULL)
    {
        perror("freopen");
        return EXIT_FAILURE;
    }
    
   yyin = freopen("wlc.txt","r",stdin);
    yyparse();
    printf("\nParser is finished");
    
    fclose(outputFile);


    return 0;
}


void yyerror(char *s)
{
    printf("Error %s\n",s);
    return;
}





// Symbol table management
struct SymbolTable* searchVariable(char* name) {
    // Implement your search logic here
     for (int i = 0; i < index; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return &symbolTable[i];
        }
    }
    return NULL;
}

void insertVariable(char* name, int isAssigned, int intValue, float floatValue, int dataType) {
    
    struct SymbolTable* symbol = searchVariable(name);

    if (symbol) {
        // Variable already exists, handle accordingly
        printf("Variable %s already exists\n", name);
    } else {
        if (index < MAX_SYMBOLS) {
            symbolTable[index].name = strdup(name);
            symbolTable[index].isAssigned = isAssigned;
            symbolTable[index].intValue = intValue;
            symbolTable[index].floatValue = floatValue;
            symbolTable[index].dataType = dataType;
            
            index++;

        } else {
            printf("Symbol table is full. Cannot insert %s\n", name);
        }
    }
}


void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Name", "IsAssigned", "IntValue", "FloatValue", "DataType");

    for (int i = 0; i < index; i++) {
        printf("%-20s%-15d", symbolTable[i].name, symbolTable[i].isAssigned);

        if (symbolTable[i].dataType == 0) {
            printf("%-15d%-15s%-15s\n", symbolTable[i].intValue, "-", "INT");
        } else if (symbolTable[i].dataType == 1) {
            printf("%-15s%-15.2f%-15s\n", "-", symbolTable[i].floatValue, "FLOAT");
        } else {
            // Handle other data types if needed
            printf("%-15s%-15s%-15s\n", "-", "-", "UNKNOWN");
        }
    }
}



//

// function table management
struct FunctionTable* searchFunction(char* name) {
    // Implement your search logic here
     for (int i = 0; i < functionTableSize; i++) {
        if (strcmp(functionTable[i].name, name) == 0) {
            return &functionTable[i];
        }
    }
    return NULL;
}

void insertFunction(char* name, int no_of_param, int return_value_int, float return_value_float, int return_type) {
   
    struct FunctionTable* symbol = searchFunction(name);

    if (symbol) {
        // Variable already exists, handle accordingly
        printf("Function %s already exists\n", name);
    } else {
        if (functionTableSize < MAX_SYMBOLS) {
            functionTable[functionTableSize].name = strdup(name);
            functionTable[functionTableSize].no_of_param = no_of_param;
            functionTable[functionTableSize].return_value_int = return_value_int;
            functionTable[functionTableSize].return_value_float = return_value_float;
            functionTable[functionTableSize].return_type = return_type;
            
            functionTableSize++;

           
        } else {
            printf("Symbol table is full. Cannot insert %s\n", name);
        }
    }
}

void printFunctionTable() {
    printf("Function Table:\n");
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Name", "No_of_Param", "Return_Int", "Return_Float", "Return_Type");

    for (int i = 0; i < functionTableSize; i++) {
        printf("%-20s%-15d", functionTable[i].name, functionTable[i].no_of_param);

        if (functionTable[i].return_type == 0) {
            printf("%-15d%-15s%-15s\n", functionTable[i].return_value_int, "-", "INT");
        } else if (functionTable[i].return_type == 1) {
            printf("%-15s%-15.2f%-15s\n", "-", functionTable[i].return_value_float, "FLOAT");
        } else {
            // Handle other return types if needed
            printf("%-15s%-15s%-15s\n", "-", "-", "UNKNOWN");
        }
    }
}
