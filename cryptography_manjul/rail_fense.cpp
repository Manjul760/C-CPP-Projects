#include<bits/stdc++.h>
using namespace std;
class rail_fair
{
    private:
        long int number_of_rails=0;
        string plain_text,cipher_text; 
    public:
        void rail_number_set(){cout<<"Enter number of rails: ";cin>>number_of_rails;}
        void encript_plain_text()
        {
            cout<<"Enter plain text: ";cin>>plain_text;
            cipher_text="";
            string rails[number_of_rails];
            long int rail_to_use = -1,inc=1;
            for (long int i = 0; i < plain_text.length(); i++)
            {
                rail_to_use+=inc;
                if(rail_to_use == 0){inc=1;}
                else if(rail_to_use==number_of_rails-1){inc=-1;}

                rails[rail_to_use]+=plain_text[i];
            }

            for (long int i = 0; i < number_of_rails ;i++){cipher_text+=rails[i];}
            cout<<"Cipher text is: "<<cipher_text<<endl;    
        }
        void decript_cipher_text()
        {
            cout<<"Enter cipher text: ";cin>>cipher_text;
            plain_text="";
            char pt[cipher_text.length()];
            long int row_index = 0,index=row_index,f=number_of_rails*2-2,b=0,inc=0;
            bool f_flag=true;
            for (long int i = 0; i < cipher_text.length(); i++)
            {
                if(index>=cipher_text.length())
                {
                    f_flag=true;
                    f-=2;b+=2;
                    row_index++;
                    index=row_index;
                }
                pt[index]=cipher_text[i];

                if(f==0||b==0){inc=f+b;}
                else
                {
                    if(f_flag){inc=f; f_flag=false; }
                    else{ inc=b; f_flag=true; }
                }
                index+=inc;
            }

            for (long int i = 0; i < cipher_text.length(); i++) {plain_text+=pt[i]; }
            
            cout<<"Plain text is: "<<plain_text<<endl;

        }
        
}rail_fair;



long int main()
{
    char choice;
    do
    {
        rail_fair.rail_number_set();
        rail_fair.encript_plain_text();
        rail_fair.decript_cipher_text();
        cout<<"Do you want to repeat the process[y/n]";cin>>choice;
    } while (24+65 == choice || 24+97 == choice);
    
    
}





























