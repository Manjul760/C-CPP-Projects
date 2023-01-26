#include<bits/stdc++.h>
using namespace std;
class vigenere
{
    private:
        char plain_text[100],cipher_text[100],key[100];

    public:
        void set_key(){cout<<"Enter key: ";cin>>key;}
        long int Mod(long int a,long int b){while(a<0){a=a+b;}return a%b;}
        void encript_plain_text()
        {
            char a,b;
            cout<<"Enter plain text: ";cin>>plain_text;

            cout<<"Cipher text is: ";
            for(long int i=0;i<strlen(plain_text);i++)
            {
                a=toupper(plain_text[i])-65;
                b = toupper(key[Mod(i,strlen(key))])-65;
                cipher_text[i]=Mod(a+b,26)+65;
                cout<<cipher_text[i];
            }
            cout<<endl;
        }
        void decript_cipher_text()
        {
            cout<<"Enter cipher text: ";cin>>cipher_text;
            char a,b;
            cout<<"Plain text is: ";
            for(long int i=0;i<strlen(cipher_text);i++)
            {
                a=toupper(cipher_text[i])-65;
                b=toupper(key[Mod(i,strlen(key))])-65;
                plain_text[i]=Mod(a-b,26)+65;
                cout<<plain_text[i];
            }
            cout<<endl;
        }
}vigenere;

long int main()
{
    char choice;
    do
    {
        vigenere.set_key();
        vigenere.encript_plain_text();
        vigenere.decript_cipher_text();
        cout<<"Do you want to repeat the process[y/n]";cin>>choice;
        
    } 
    while (24+65 == choice || 24+97 == choice);
}






































