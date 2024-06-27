#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){if(b==0){return a;}return gcd(b,a%b);}
int eulerTotient(int n) 
{
    int c=0;
    for(int i =0;i<n;i++)
    {
        cout<<"gcd("<<n<<","<<i<<") ="<<gcd(n,i)<<endl;
        if(gcd(n,i)==1){c++;}
    }
    return c;
}

int main() 
{
    int n;
    while(1)
    {
        cout<<"Enter number to find totent of: ";cin>>n;
        cout <<"Euler totent =" <<eulerTotient(n) << endl<<endl;
    }
}