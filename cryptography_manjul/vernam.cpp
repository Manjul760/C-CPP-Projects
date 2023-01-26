#include<iostream>
#include<string.h>
using namespace std;
class vernam
{
    private:
        char Input_text[100],Output_text[100],key[100];
        long int Mod(long int a,long int b){while(a<0){a=a+b;}return a%b;}
    public:
        void set_key(){cout<<"Enter key: ";cin>>key;};
        void process()
        {
            cout<<"Enter text to encript or decript: ";cin>>Input_text;
            char a,b;
            cout<<"Output text is: ";
            for(long int i=0;i<strlen(Input_text);i++)
            {
                a=toupper(Input_text[i])-65;
                b=toupper(key[Mod(i,strlen(key))])-65;
                Output_text[i]=(a^b)+65;
                cout<<Output_text[i];
            }
            cout<<endl;
        }
        

}vernam;

long int main()
{
    vernam.set_key();
    vernam.process();
    vernam.process();
    char a;cin>>a;
}