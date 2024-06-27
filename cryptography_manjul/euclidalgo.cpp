#include<bits/stdc++.h>
using namespace std;
int euclid(int a,int b){if(b==0){return a;}return euclid(b,a%b);}
int main()
{
    int a,b,gcd;
    cout<<"Enter two numbers :"<<endl;cin>>a>>b;
    if(a>b){gcd=euclid(a,b);}else{gcd=euclid(b,a);}
    cout<<"Gcd is :"<<gcd<<endl<<endl;
    main();
}