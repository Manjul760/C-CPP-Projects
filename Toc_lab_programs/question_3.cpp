#include<iostream>
#include<string.h>
using namespace std;
void suffix(char[]);
void prefix(char[]);
int main()
{
    char input[100];string choice;
    do{
    cout<<"Enter the string: "; cin>>input;
    prefix(input); suffix(input);
    cout<<"do  you want to continue[y/n]"; cin>>choice;
    }while(choice != "n");
    return 0;
}
void prefix(char w[])
{
    cout<<"The possible prefixes are: "<<endl;
    for(int i = 0; i<strlen(w);i++)
    {
        for(int j = 0;j<=i;j++){cout<<w[j]; }
        cout<<endl;
    }
}
void suffix(char w[])
{
    cout<<"The possible suffix are: "<<endl;
    for(int i = strlen(w)-1; i>=0;i--)
    { 
        for(int j = i;j<strlen(w);j++){cout<<w[j]; } 
        cout<<endl;  
    }
}