#include<bits\stdc++.h>
using namespace std;
class one_time_pad
{
    private:
        char Input_text[100],Output_text[100],key[100];
        long int Mod(long int a,long int b){while(a<0){a=a+b;}return a%b;}
    public:
        one_time_pad(){srand(time(0));}
        void set_key()
        {   
            long int length = 10+rand()%91;
            for (long int i = 0; i < length; i++){key[i]=rand()%26+65;}key[length]='\0';
            cout<<"Random key generated\n";
        }
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
        

}one_time_pad;

long int main()
{
    one_time_pad.set_key();
    one_time_pad.process();
    one_time_pad.process();
    char a;cin>>a;
}