%{
	#include <bits/stdc++.h>
	#include<string.h>
	using namespace std;
		map<string,string>mp;
		
		int total_statement=0;
		int total_keyword=0;
%}
com_op (<|>|<=|>=)
math_op ("+"|"-"|"*"|"/")
gap [ \t\n]*
var [a-z][a-z0-9]*
val [0-9]+
initialization {var}{gap}([=]{gap}{val})?
condition ({var}|{val}){gap}{com_op}{gap}(({var}|{val}){gap}[math_op])*{gap}({val}|{var})
increment {var}{gap}[=]{gap}{var}{gap}{math_op}{gap}{val}
datatype ("intg"|"char"|"floating"|"string")
print_statement (print[(]["].*["][)][;])
exp2 ({var}|{val}){gap}{math_op}{gap}
exp ({gap}{var}{gap}[=]{gap}({exp2})*{gap}({var}|{val}){gap}[;])
statements ({exp}|{print_statement})
%%
{gap}[#]contain[<][a-z]+[.][h][>]['\n'] {cout<<"Header file Included.\n";}
{gap}int{gap}main\(\){gap}[{]['\n'] { cout<<"Code started\n";}

{gap}{datatype}{gap}{var}{gap}([=]{gap}{val})?({gap}[,]{gap}{var}{gap}([=]{gap}{val})?)*?{gap}[;] {
	cout<<"variable declared\n";
	total_statement++;
	total_keyword++;
	
	string line,v_name="",v_type;
	line=yytext;
	int flag=0;

	char delimiter[] =" =,;";

	

	char *cstr = strdup(line.c_str()); // Convert to C-style string
    char *token = strtok(cstr, delimiter);
	v_type=token;
	token = strtok(nullptr, delimiter);
	
	while (token != nullptr) {

		if(token[0]>='a'&&token[0]<='z'){ // flag 0 means no v_name exists
			v_name=token;
			if(mp.find(v_name)==mp.end()){
				mp[v_name]=v_type;
			}
			else{
				//cout<<"Already declared variable\n";
			}
			
		}
		
        token = strtok(nullptr, delimiter);
		
    }

	/*cout<<"Show map content"<<endl;
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		cout << i->first << "	 " << i->second<< endl;
	}*/
  
}


{gap}loop{gap}[#]{gap}{initialization}{gap}[#]{gap}{condition}{gap}[#]{gap}{increment}{gap}[#]{gap}({gap}{statements}{gap})*{gap}[#]['\n'] {
	cout<<"found loop\n";
	total_keyword++;
	string line;
	line=yytext;

	char delimiter[] ="#;";

	char *cstr = strdup(line.c_str()); // Convert to C-style string
    char *token = strtok(cstr, delimiter);

	token = strtok(nullptr, delimiter);
	token = strtok(nullptr, delimiter);
	token = strtok(nullptr, delimiter);
	
	while (token != nullptr) {

        token = strtok(nullptr, delimiter);
		if(token!=nullptr){
			// checking if there is a print keyword
			if(token[0]=='p'&&token[0]=='r'&&token[0]=='i'&&token[0]=='n'&&token[0]=='t'){
				total_keyword++;
			}
			//
			for(int i=0;i<strlen(token);i++)
			{
				if(token[i]!=' '){	total_statement++;	break;}
			}
			
		}
    }

}
{gap}if{gap}[#]{gap}{condition}{gap}[#]{gap}({gap}{statements}{gap})*{gap}[#]['\n'] {
	cout<<"if found\n";
	total_keyword++;
	string line;
	line=yytext;
	char delimiter[] ="#;";

	char *cstr = strdup(line.c_str()); // Convert to C-style string
    char *token = strtok(cstr, delimiter);
	token = strtok(nullptr, delimiter);
	
	while (token != nullptr) {

        token = strtok(nullptr, delimiter);
		if(token!=nullptr){
			// checking if there is a print keyword
			if(token[0]=='p'&&token[0]=='r'&&token[0]=='i'&&token[0]=='n'&&token[0]=='t'){
				total_keyword++;
			}
			//if given token is only spaces then dont count statement
			for(int i=0;i<strlen(token);i++)
			{
				if(token[i]!=' '){	total_statement++;	break;}
			}
			

		}
    }

}

{gap}[#][#].*([\n]+?.*)*?[#][#]['\n'] { cout<<"Multiline comment\n";}
{gap}[*][*].*['\n'] { cout<<"Singleline comment\n";}

{gap}return{gap}[0]{gap}[;]{gap}[}] {cout<<"Code ended.\n";}
%%
int yywrap()
{
	return 1;
}
int main()
{
	yyin=fopen("wlc.txt","r");
	yylex();
	cout<<"Total no of statements : "<<total_statement<<endl;
	cout<<"Total no of keyword : "<<total_keyword<<endl;
	return 0;
}