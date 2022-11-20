#include<iostream>
#include<string.h>
using namespace std;enum states {q0,q1,q2,q3,q4,q5,Rejected};

bool TM_accepting_0n_1n(char[]);
int main()
{
    string choice = "y";
    do{
        char a[50];
        cout <<"\nNote that input symbol = 0,1"<<endl;
        cout <<"Enter string to evaluate :";cin>>a;
        if (TM_accepting_0n_1n(a)){cout<<"String is accepted"<<endl;}
        else{cout<<"String is rejected"<<endl;}
        cout<<"\nDo you want exit [y,n]:";cin>>choice;
    }while(choice != "n");
}
bool TM_accepting_0n_1n(char a[])
{
    int length,state = q0,p_l = 0,i;
    //replacing garbage values with #
    length = strlen(a);for (i = length;i<50;i++){a[i]=35;}
    while(state!= Rejected && state != q5)
    {
        if(state == q0 && a[p_l] == 48){a[p_l] = 88;p_l++;state = q1;}
        else if(state == q1 && a[p_l] == 48){p_l++;state = q1;}
        else if(state == q1 && a[p_l] == 49){p_l++;state = q1;}
        else if(state == q1 && a[p_l] == 89){p_l++;state = q1;}
        else if(state == q1 && a[p_l] == 35){p_l--;state = q2;}
        else if(state == q2 && a[p_l] == 89){p_l--;state = q2;}
        else if(state == q2 && a[p_l] == 49){a[p_l] = 89;p_l--;state = q3;}
        else if(state == q3 && a[p_l] == 48){p_l--;state = q3;}
        else if(state == q3 && a[p_l] == 49){p_l--;state = q3;}
        else if(state == q3 && a[p_l] == 89){p_l--;state = q3;}
        else if(state == q3 && a[p_l] == 88){p_l++;state = q0;}
        else if(state = q0 && a[p_l] == 89){p_l++;state=q4;}
        else if(state = q4 && a[p_l] == 89){p_l++;state=q4;}
        else if(state = q4 && a[p_l] == 35){p_l++;state=q5;}
        else {state = Rejected;}           
    }
    if (state == q5){return true;} else {return false;}
}






