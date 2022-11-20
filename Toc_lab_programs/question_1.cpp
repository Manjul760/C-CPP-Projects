#include<iostream>
#include<string.h>
using namespace std; void substring_1(char[],int,int);
int main()
{
    char input_string[100]; int pos_end ,pos_start;string choice;
    cout<<"Note that any non int position is converted to respective ascii code ie a = 67 and starting position is 1"<<endl;
    do{
    cout<<"enter the string :"; cin>>input_string;
    cout<<"enter the starting position :"; cin>>pos_start;
    cout<<"enter the ending position :";  cin>>pos_end;
    substring_1(input_string,pos_start,pos_end);
    cout<<"do  you want to continue[y/n]"; cin>>choice;
    }while(choice != "n");
}

//Q1 make a function substring1(w,a,b),
//where w is a string input given by user
//a is the starting position for extracting substring 
//b is the ending position of the substring
void substring_1(char input[],int start_pos,int end_pos)
{   int len;
    if ((start_pos >0 && end_pos >0) && (start_pos <= strlen(input) && end_pos <= strlen(input)) )
    {
        cout<<"Substring is :"; start_pos --;end_pos--;
        if(start_pos<=end_pos)
        { for(int i = start_pos;i<=end_pos;i++ ){ cout<<input[i];  } }
        else if(start_pos>end_pos)
        { for(int i = start_pos;i>=end_pos;i-- ){ cout<<input[i];  } }
        cout<<endl;
    }
    else { cout<<"error occured enter correct index and string"<<endl; }
    
}




