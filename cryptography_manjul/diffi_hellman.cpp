#include<iostream>
#include<string.h>
using namespace std;
class Diffi_hellman
{
    private:
        int alpha,q,xa,xb,ya,yb,ka,kb;
    public:
        int mod(int a,int b){while(a<0){a=a+b;}return a%b;}
        int modulus_with_power(int a,int e,int b){a = mod(a,b);int return_value=1;for(int i = 0;i<e;i++){return_value = mod(return_value*a,b);}return return_value;}
        bool is_primitive_prime()
        {
            if(alpha>=q){return false;}
            int array_of_values[q],break_flag=false;
            for(int i=1;i<q;i++)
            {
                array_of_values[i-1]=modulus_with_power(alpha,i,q);
                if(array_of_values[i-1] == 0){return false;}
                for(int j=0;j<i-2;j++){if(array_of_values[i-1]==array_of_values[j]){break_flag=true;break;}}
                if(break_flag){return false;}
            }
            return true;
        }
        void set_primitive_primes()
        {
            cout<<"Enter the number to find primitive root for: ";cin>>q;
            cout<<"Enter the primitive prime of the number: ";cin>>alpha;
            if(!is_primitive_prime()){cout<<"Value not correct:"<<endl;set_primitive_primes();}
            else{cout<<"Prime numbers set:"<<endl;}
        }
        void set_private_keys()
        {
            cout<<"Enter the private key for A: ";cin>>xa;
            cout<<"Enter the private key for B: ";cin>>xb;
        }
        void verification_process()
        {
            ya = modulus_with_power(alpha,xa,q);
            yb = modulus_with_power(alpha,xb,q);

            cout<<"Value of public key ya is = "<<ya<<" Value of public key yb is = "<<yb<<endl;
            ka = modulus_with_power(yb,xa,q);
            kb = modulus_with_power(ya,xb,q);
            cout<<"Value of ka is = "<<ka<<" Value of kb is = "<<kb<<" ";
            if(ka==kb){cout<<"Verified safe transfer of key"<<endl;}else{cout<<"Unsafe transfer of key"<<endl;}

        }

}Diffi_hellman;

int main()
{
    char choice;
    do
    {
        Diffi_hellman.set_primitive_primes();
        Diffi_hellman.set_private_keys();
        Diffi_hellman.verification_process();
        cout<<"Do you want to continue[y/n]: ";cin>>choice;
    } while (choice == 24+65 || choice == 24+97);
}