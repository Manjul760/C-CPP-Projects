#include<bits/stdc++.h>
using namespace std;
void extendedeuclid(int ans[],int a,int b,int x1=1,int y1=0,int x2=0,int y2=1)
{
    if(b==0){ans[0]=a; ans[1]=x1; ans[2]=x2;return; }
    extendedeuclid(ans,b,a%b,y1,x1-(a/b)*y1,y2,x2-(a/b)*y2);
}
int main()
{
    int a,b,ans[3];
    cout<<"Enter two numbers to find gcd :"<<endl;cin>>a>>b;
    extendedeuclid(ans,a,b);
    cout<<"GCD "<<ans[0]<<" = "<<ans[1]<<"*"<<a<<" + "<<ans[2]<<"*"<<b<<endl<<endl;
    main();
}