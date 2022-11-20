#include<iostream>
#include<string.h>
using namespace std;
/*Note:C- identifiers are used to identify  so they cant be keywords
1.they must not begin with number
2.they can have a "_" as special character 
*/
enum state{q0_start,q1_final,Rejected};
bool IS_number_check(int);bool IS_alphabet_or_underscore_check(int);
bool C_identifier_DFA(char[]);bool IS_Keyword(string);
int main()
{
    int i;char input[100];string choice;
    do{
    cout<<"Note that identifiers are used to identify objects or variables"<<endl;
    cout<<"Enter string :";
    cin>>input;    
    if (C_identifier_DFA(input)) {cout<<input<<" is a valid identifier"<<endl;}
    else{cout<<input<<" is not a valid identifier"<<endl;}
    cout<<"do  you want to continue[y/n]"; cin>>choice;
    }while(choice != "n");
    return 0;
}

bool C_identifier_DFA(char w[])
{
    int state = q0_start ;
    if(IS_Keyword(w)){state = Rejected;}
    else 
    {
        if (IS_number_check(w[0])){state = Rejected;}
        else if(IS_alphabet_or_underscore_check(w[0]))
        {
            state = q1_final;
            for(int i = 1; i<strlen(w);i++)
            {
                if(IS_alphabet_or_underscore_check(w[i]) || IS_number_check(w[i])) { state = q1_final; }
                else{state = Rejected;break;}
            }
        }
    }
    if (state == q1_final){return true;}
    else{return false;}
}

bool IS_Keyword(string s)
{
    if (s == "auto" || s == "break" || s == "case" || s == "char" || s == "float" || s == "int" ||
    s == "const" || s == "continue" || s == "do" || s == "default" || s == "double" || s == "if" ||
    s == "else" || s == "for" || s == "enum" || s == "extern" || s == "goto" || s == "long" || s == "return" ||
    s == "signed" || s == "static" || s == "sizeof" || s == "short" || s == "struct" || s == "switch" ||
    s == "typedef" || s == "union" || s == "void" || s == "go" || s == "while" || s == "volatile" || s == "unsigned" || s == "int")
    {return true;}
    else
    {return false;}
}

bool IS_alphabet_or_underscore_check(int a)
{
    if((a<=122 && a>=97) || (a <=90 && a >=65) || a == 95){return true;}else{return false;}
}
bool IS_number_check(int a)
{
    if(a<=57 && a>=48){return true;} else{return false;}
}

























