#include<iostream>
#include<string.h>
using namespace std;
void suffix_2(char[],int);
void prefix_2(char[],int);
int main()
{
    char input[100];int s_remove,p_remove;string choice;
    do{
    cout<<"Enter the string: "; cin>>input;
    cout<<"Enter suffix removal value: "; cin>>s_remove;
    cout<<"Enter prefix removal value: "; cin>>p_remove;
    suffix_2(input,s_remove);
    prefix_2(input,p_remove);
    cout<<"do  you want to continue[y/n]"; cin>>choice;
    }while(choice != "n");
    return 0;
}
void prefix_2(char w[],int n)
{   
    if(n>=0 && n <strlen(w))
    {
        cout<<"The prefix removed string is: ";
        for(int i = n; i<strlen(w);i++) { cout<<w[i]; }
        cout<<endl;
    }else{cout<<"error occured index out of range"<<endl;}
}
void suffix_2(char w[],int n)
{
    if(n>=0 && n <strlen(w))
    {
        cout<<"The suffix removed string is: ";
        for(int i = 0; i<strlen(w) - n;i++){ cout<<w[i]; }
        cout<<endl;
    }else{cout<<"error occured index out of range"<<endl;}
}