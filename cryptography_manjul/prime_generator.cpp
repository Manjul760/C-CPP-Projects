#include<bits/stdc++.h>
using namespace std;
int mod(int a,int m){while(a<0){a+=m;}return a%m;}
int modwithpower(int a,int e,int m)
{
    int value=1;
    a=mod(a,m);
    for(int i=0;i<e;i++)
    {
        value = mod(value*a,m);
    }
    return value;
}

bool is_prime(int input)
{
    if (input==2){return true;}
    bool ret=true;
    for(int i=1;i<11;i++)
    {
        if(modwithpower((int)pow(2,i),input-1,input)==1){ret = ret & true;}
        else{ret=ret&false;}
    }
    return ret;
}
int main()
{
    srand(time(0));
    intmax_t prime_number;
    char choice=24+65;
    do
    {
        for (int i = 0; i < 10; i++)
        {
            do{prime_number=rand();} while (!is_prime(prime_number));
            cout<<"Random prime number is: "<<prime_number<<endl;
        }
        cout<<"Generate another [y/n]: ";cin>>choice;
    }while (choice == 24+65 || choice == 24+97);
    
}
