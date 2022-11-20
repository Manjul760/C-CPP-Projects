#include<iostream>
#include<string.h>
using namespace std;
bool NFA_with_001(char[]);
enum states{q0_starting,q1,q2,q3_finish,Rejected};
int main()
{
    int i;char input[100];string choice;
    do{
    cout<<"Consider that this program is only for input symbols {0,1} with substring 001"<<endl;
    cout<<"Enter string :";
    cin>>input;    
    if (NFA_with_001(input)) {cout<<"String is accepted"<<endl;}
    else{cout<<"String is rejected"<<endl;}
    cout<<"do  you want to continue[y/n]"; cin>>choice;
    }while(choice != "n");
    return 0;

}
bool NFA_with_001(char w[])
{
    string check_value;int state = q0_starting;
    for(int i = 0;i<strlen(w);i++)
    {
        check_value = w[i];
        if (check_value != "1" && check_value != "0"){cout<<"Please enter valid string"<<endl;state = Rejected;break;}
        else
        {
            if(state ==q0_starting && check_value == "0") {state = q1;}
            else if(state ==q1 && check_value == "0"){state = q2;}
            else if(state ==q1 && check_value == "1"){state = q0_starting;}
            else if(state ==q2 && check_value == "1"){state = q3_finish;}
        }
    }
    if (state ==q3_finish){return true;} else {return false;}

}





