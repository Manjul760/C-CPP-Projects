#include<bits/stdc++.h>
using namespace std;
class RSA
{
    private:
        intmax_t first_prime,second_prime,multiply_prime,totent,power_to_raise,private_key_number; 
        char plain_text[100],cipher_text[100];bool key_set_flag = false,key_generated = false;

    public:
        intmax_t filter_ascii(intmax_t a){if(a>=65 && a<=90){a= a - 65;}else if(a>=97 && a<=122){a= a - 97;}else{a= - 1;}return a;}
        bool is_prime(intmax_t a)
        {
            if (a==2){return true;}
            bool ret=true;
            for(int i=1;i<11;i++)
            {
                if(modulus_with_power((int)pow(2,i),a-1,a)==1){ret = ret & true;}
                else{ret=ret&false;}
            }
            return ret;
        }
        intmax_t mod(intmax_t a,intmax_t b){while(a<0){a=a+b;}return a%b;}
        intmax_t modulo_inv(intmax_t a,intmax_t b){a = mod(a,b);intmax_t i=0;while(mod((a*mod(i,b)),b)!=1){i++;}return mod(i,b);}
        intmax_t modulus_with_power(intmax_t a,intmax_t e,intmax_t b){a = a%b;intmax_t return_value=1;for(intmax_t i = 0;i<e;i++){return_value = mod(return_value*a,b);}return return_value;}
        bool is_relatively_prime(intmax_t a,intmax_t b,bool printmax_t_flag = false)
        {
            if (b==1){return true;}else if(b==0){return false;}
            intmax_t c = a/b,d=a%b;
            if(printmax_t_flag){cout<<a<<" = "<<b<<"*"<<c<<" + "<<d<<endl;}
            if(is_relatively_prime(b,d,printmax_t_flag)){return true;}else{return false;}
        }
        void set_prime_numbers()
        {
            cout<<"Enter first prime number: ";cin>>first_prime;
            cout<<"Enter Second prime number: ";cin>>second_prime;
            if(is_prime(first_prime) && is_prime(second_prime)){multiply_prime = first_prime * second_prime;totent = (first_prime -1) * (second_prime-1);key_set_flag = true;}
            else{cout<<"Entered numbers are not prime try again!!!"<<endl;set_prime_numbers();}
        }
        void generate_key()
        {
            if (key_set_flag)
            {
                intmax_t i =0;bool found = false,is_relatively_prime_no;
                cout<<"Generating random key please wait: "<<endl;

                for(intmax_t i = 2;i<totent;i++)
                {
                    power_to_raise=i; 
                    if(is_relatively_prime(totent,power_to_raise,true))
                    {
                        private_key_number=modulo_inv(power_to_raise,totent);
                        if(power_to_raise != private_key_number){found=true;break;}  
                    }
                }

                if(found)
                {
                    cout<<"The value of public key is: ("<<power_to_raise<<","<<multiply_prime<<")"<<endl;
                    cout<<"The value of private key is: ("<<private_key_number<<","<<multiply_prime<<")"<<endl;
                    key_generated = true;
                }else{cout<<"Cant find assymetric keys"<<endl;}
            }
            else{cout<<"Enter prime numbers first!!!"<<endl;}
        }
        void encription_decription_process()
        {
            if(key_generated)
            {
                intmax_t temp,temp2,temp3;
                cout<<"Enter plain text: ";cin>>plain_text;
                cout<<"Output as \nPlain text--cipher text--plain text(d)"<<endl;
                for(intmax_t i=0;i<strlen(plain_text);i++)
                {
                    temp = plain_text[i];cout<<temp<<"("<<(char)temp<<")--------";
                    //encrip
                    temp2=modulus_with_power(temp,private_key_number,multiply_prime);cout<<temp2<<"-------";
                    //decrip
                    temp3=modulus_with_power(temp2,power_to_raise,multiply_prime);cout<<temp3<<"("<<(char)temp3<<")"<<endl;
                    if(temp >= multiply_prime){cout<<"Error in value because n=p*q < given input:"<<endl;}
                }
            }else{cout<<"No key generated:"<<endl;}
        }


}RSA;

int main()
{
    
    char choice;
    do
    {
        RSA.set_prime_numbers();
        RSA.generate_key();
        RSA.encription_decription_process();
        cout<<"Do you want to continue[y/n]: ";cin>>choice;
    } while (RSA.filter_ascii(choice) == 24);
}