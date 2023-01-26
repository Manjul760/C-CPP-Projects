#include<bits/stdc++.h>
using namespace std;
class IDEA
{
    // private:
    public:
        bool key_set=false;      
        char process_text[8],key_text[16];
        int process_number[4],key1[9][4],key2[8][2],key1_inv[9][4],key2_inv[8][2];
        int modulic_inv(int a,int c=65537){for (int i = 0; i < c; i++){if((i*a)%c==1){return i;}}return 0; }
        int addition_inv(int a ,int c=65536){return ((a^(c-1))+1)%c;}
        int modulic_multiply(intmax_t a,intmax_t b,intmax_t c=65537)
        {
            if(a==0){a=c-1;}
            if(b==0){b=c-1;}
            return ((a*b)%c)%(c-1);
        }
        int modulic_add(int a,int b,int c=65536){return (a+b)%c;}
        string char_to_binary(int a,int neededlength=8)
        {
            string binary="";
            while(a>0){if(a%2==0){binary="0"+binary;}else{binary="1"+binary;}a/=2;}
            if(binary.length()<neededlength){int a=neededlength-binary.length();for (int i = 0; i < a; i++){binary="0"+binary;}}
            return binary;
        }
        int string_to_number(string input)
        {
            int value = 0,base=1, len =(input.length());
            for (int i = len-1; i >=0; i--){ if(input[i]=='1'){value+=base;}base*=2; }return value; 
        }

    // public: 
        void input_text_input()
        {
            cout<<"Enter input text[8 chars]: ";
            for (int i = 0; i < 8; i++){cin>>process_text[i];}
            for (int i = 0,j=0; i <8,j<4; i+=2,j++)
            {
                process_number[j]=string_to_number(
                    char_to_binary((unsigned int)process_text[i])+
                    char_to_binary((unsigned int)process_text[i+1])
                );
            }
        }

        void print_text()
        {
            string tot = "",p1,p2;
            for (int i = 0; i < 4; i++)
            {
                tot = char_to_binary(process_number[i],16);p1="";p2="";
                for (int j = 0; j < 8; j++) {p1 +=tot[j]; }
                for (int j = 8; j < 16; j++) {p2 +=tot[j];}
                cout<<(char)string_to_number(p1)<<(char)string_to_number(p2); 
            }cout<<endl;  
        }

        void key_text_input()
        {
            cout<<"Enter key text[16 chars]: ";
            string key_128="";
            for (int i = 0; i < 16; i++)
            {
                cin>>key_text[i];
                key_128+=char_to_binary(key_text[i]);
            }
           
            //generating 52 key and converting it into number all at once
            cout<<"\nGenerating 52 key \n";
            int round=0,key_index=0,key[52];
            string needed_number;
            bool reached_52=false;
            for (int round = 0; round < 9; round++)
            {
                for (int i = 0; i < 128; i+=16,key_index++)
                {
                    needed_number="";
                    for (int j = 0; j < 16; j++){needed_number+=key_128[(i+j+round*25)%128]; }
                    cout<<needed_number<<" ";
                    key[key_index]=string_to_number(needed_number);
                    if(key_index==52){reached_52=true;break;}   
                }cout<<endl;
                if(reached_52){break;}
            }cout<<endl;

            //reassigning values according to need
            cout<<"Encription keys\n";
            for (int i = 0; i < 52; i++)
            {
                if(i%6==0&&i>1){cout<<endl;}
                if(i%6<4)
                {
                    key1_inv[8-(i/6)][i%6] = key[i];
                    key1[i/6][i%6] = key[i];
                    cout<<key1[i/6][i%6]<<" ";
                }
                else
                {
                    key2_inv[7-(i/6)][i%6-4] = key[i];
                    key2[i/6][i%6-4] = key[i];
                    cout<<key2[i/6][i%6-4]<<" ";
                }
            }cout<<endl;

            //inverse generated
            cout<<"\nKeys for decription\n";
            for (int i = 0; i < 9; i++)
            {
                key1_inv[i][0] = modulic_inv(key1_inv[i][0]);
                key1_inv[i][1] = addition_inv(key1_inv[i][1]);
                key1_inv[i][2] = addition_inv(key1_inv[i][2]);
                key1_inv[i][3] = modulic_inv(key1_inv[i][3]);

                for (int j = 0; j < 4; j++){cout<<key1_inv[i][j]<<" ";}
                if(i<8){cout<<key2_inv[i][0]<<" "<<key2_inv[i][1]<<" "<<endl;}else{cout<<endl; }
            }            
        }

        void encription()
        {
            if(strlen(process_text)<8 && strlen(key_text)<16){cout<<"!!!!!Problem in length!!!!!\n";return;}

            cout<<"\nEncription processs:\n";
            int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;

            for (int i = 0; i < 4; i++){cout<<process_number[i]<<" ";}cout<<endl;
            for (int i = 0; i < 8; i++)
            {
                s1 = modulic_multiply(process_number[0],key1[i][0]);
                s2 = modulic_add(process_number[1],key1[i][1]);
                s3 = modulic_add(process_number[2],key1[i][2]);
                s4 = modulic_multiply(process_number[3],key1[i][3]);
                s5 = s1^s3;
                s6 = s2^s4;
                s7 = modulic_multiply(s5,key2[i][0]);
                s8 = modulic_add(s6,s7);
                s9 = modulic_multiply(s8,key2[i][1]);
                s10 = modulic_add(s7,s9);
                process_number[0] = s1^s9;
                process_number[1] = s2^s10;
                process_number[2] = s3^s9;
                process_number[3] = s4^s10; 

                for (int j = 0; j < 4; j++){cout<<process_number[j]<<" ";}cout<<endl;
            }
            process_number[0] = modulic_multiply(process_number[0],key1[8][0]);
            process_number[1] = modulic_add(process_number[1],key1[8][1]);
            process_number[2] = modulic_add(process_number[2],key1[8][2]);
            process_number[3] = modulic_multiply(process_number[3],key1[8][3]);

            for (int i = 0; i < 4; i++){cout<<process_number[i]<<" ";}cout<<endl;
            cout<<"Encripted text is: ";print_text();     
        }

        void decription()
        {
            if(strlen(process_text)<8 && strlen(key_text)<16){cout<<"!!!!!Problem in length!!!!!\n";return;}

            cout<<"\nDecription processs:\n";
            for (int i = 0; i < 4; i++){cout<<process_number[i]<<" ";}cout<<endl;

            int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
            for (int i = 0; i < 8; i++)
            {
                s1 = modulic_multiply(process_number[0],key1_inv[i][0]);
                s2 = modulic_add(process_number[1],key1_inv[i][1]);
                s3 = modulic_add(process_number[2],key1_inv[i][2]);
                s4 = modulic_multiply(process_number[3],key1_inv[i][3]);
                s5 = s1^s3;
                s6 = s2^s4;
                s7 = modulic_multiply(s5,key2_inv[i][0]);
                s8 = modulic_add(s6,s7);
                s9 = modulic_multiply(s8,key2_inv[i][1]);
                s10 = modulic_add(s7,s9);
                process_number[0] = s1^s9;
                process_number[1] = s2^s10;
                process_number[2] = s3^s9;
                process_number[3] = s4^s10; 

                for (int j = 0; j < 4; j++){cout<<process_number[j]<<" ";}cout<<endl;
            }
            process_number[0] = modulic_multiply(process_number[0],key1_inv[8][0]);
            process_number[1] = modulic_add(process_number[1],key1_inv[8][1]);
            process_number[2] = modulic_add(process_number[2],key1_inv[8][2]);
            process_number[3] = modulic_multiply(process_number[3],key1_inv[8][3]);
            
            for (int i = 0; i < 4; i++){cout<<process_number[i]<<" ";}cout<<endl;
            cout<<"Decripted text is: ";print_text();
        }    
}IDEA;

int main()
{
    IDEA.input_text_input();
    IDEA.key_text_input();
    IDEA.encription();
    IDEA.decription();
}



































