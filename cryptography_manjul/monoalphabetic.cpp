#include<bits/stdc++.h>
using namespace std;

class monoalphabetic_cipher
{
    private:
        void swap(int *a,int*b){int temp = *a;*a=*b;*b=temp;}
        int list[26];
        char plain_text[100],cipher_text[100],a;
        
    public:
        monoalphabetic_cipher()
        {
            srand(time(0));
            for(int i=0;i<26;i++){list[i]=i;}
            
            int random_index1,random_index2;

            for (int i = 0; i < 50; i++)
            {
                random_index1=rand()%26;random_index2=rand()%26;
                if(random_index1!=random_index2){swap(&list[random_index1],&list[random_index2]);} 
            }
            cout<<"chars are: "; for (int i = 0; i < 26; i++){cout<<char(i+65)<<" ";}cout<<endl;
            cout<<"char2 are: ";for (int i = 0; i < 26; i++){cout<<char(list[i]+65)<<" ";}cout<<endl;
        }

        void encription()
        {
            cout<<"Enter plain text: ";cin>>plain_text;
            cout<<"the encripted text is ";

            for(int i=0;i<strlen(plain_text);i++)
            {
                a=toupper(plain_text[i]);
                if(a<=90 && a>=65)
                {
                    cipher_text[i]=list[a-65]+65;
                    cout<<cipher_text[i];
                }
                else{cout<<a;}
            }cout<<endl;
        }

        void decription()
        {
            cout<<"Enter cipher text: ";cin>>cipher_text;
            cout<<"the decripted text is ";
            for(int i=0;i<strlen(cipher_text);i++)
            {
                a=toupper(cipher_text[i]);
                if(a<=90 && a>=65)
                {
                    for(int j=0;j<26;j++)
                    {
                        if(list[j]==(a-65))
                        {
                            plain_text[i]=j+65;
                            cout<<plain_text[i];
                        }
                    }  
                }
                else{cout<<a;}  
            }
        }
}monoalphabetic_cipher;

int main()
{
    monoalphabetic_cipher.encription();
    monoalphabetic_cipher.decription();
    char a;cin>>a;
}
































