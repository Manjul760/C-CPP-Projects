#include<bits/stdc++.h>
using namespace std;
class caeser
{
    private:
        char mod(int a,int b){while(a<0){a = a + b;}return a % b;}
    public:
        string process(string input,int key,bool encript=true)
        {
            int ed = 1;
            char a;
            if(!encript){ed = -1;}
            for (int i = 0; i < input.length(); i++)
            {
                a=toupper(input[i]);
                if(a<=90 && a>=65){input[i]=mod(a-65+key*ed,26)+65;}
                else{input[i]=a;}
            }
            return input;
        }

}caeser;
int main()
{
    string input;
    int key;
    cout<<"Enter Key[int only]:";cin>>key;
    cout<<"Note: special characters ignored"<<endl;
    cout<<"Enter PT: ";cin>>input;
    cout<<"CT is---> "<<caeser.process(input,key,1)<<endl;
    cout<<"Enter CT: ";cin>>input;
    cout<<"PT is---> "<<caeser.process(input,key,0)<<"\n"<<endl;
    char a;cin>>a;
}