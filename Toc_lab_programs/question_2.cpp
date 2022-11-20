#include<iostream>
#include<string.h>
using namespace std;

void substring_2(char[],int,int);
int main()
{
    char input[100]; int no_of_string ,pos_start;string choice;
    do{
    cout<<"Note that any non int position is converted to respective ascii code ie a = 67 and starting position is 1"<<endl;
    cout<<"enter the string :";  cin>>input;
    cout<<"enter the starting position :"; cin>>pos_start;
    cout<<"enter number of string :"; cin>>no_of_string;
    substring_2(input,pos_start,no_of_string);
    cout<<"do  you want to continue[y/n]"; cin>>choice;
    }while(choice != "n");
}

//Q2 make a function substring2(w,a,b),
//where w is a string input
//a is starting position
//b is the number of symbols
void substring_2(char input[],int pos,int no_of_string)
{
    if ((pos >0 && pos + no_of_string >0) && (pos <= strlen(input) && pos + no_of_string <= strlen(input)) )
    {
        cout<<"Substring is :";
        pos --; if(no_of_string<0){no_of_string++;}else{no_of_string--;}
        if(pos<=(pos + no_of_string)) { for(int i = pos;i<=(pos + no_of_string);i++ ){ cout<<input[i];  } }
        else if(pos>(pos + no_of_string)){ for(int i = (pos + no_of_string);i<=pos;i++ ){ cout<<input[i];  } }
        cout<<endl;
    }
    else
    { cout<<"error occured enter correct index and string"<<endl; }
    
}
