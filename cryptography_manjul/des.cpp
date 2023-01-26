#include<bits/stdc++.h>
using namespace std;
class DES
{
    private:
        int Initial_permutation[64] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44,36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22,14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57,49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35,27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13,5, 63, 55, 47, 39, 31, 23, 15, 7 };
        int Final_permutation[64] = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47,15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22,62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36,4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11,51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58,26, 33, 1, 41, 9, 49, 17, 57, 25 };

        int Permutation_1_key[56]= { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34,26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3,60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7,62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37,29, 21, 13, 5, 28, 20, 12, 4 };
        int Permutation_2_key[48] = { 14, 17, 11, 24, 1, 5, 3, 28,15, 6, 21, 10, 23, 19, 12, 4,26, 8, 16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55, 30, 40,51, 45, 33, 48, 44, 49, 39, 56,34, 53, 46, 42, 50, 36, 29, 32 };
        int Shift_table[16] = { 1, 1, 2, 2, 2, 2, 2, 2,	1, 2, 2, 2, 2, 2, 2, 1 };

        int Expansion_box[48]= { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
        int Permutation_after_S_box[32]	= { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23,26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27,3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };
        int S_box_table[8][4][16]={ 
                { { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{ 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{ 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{ 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
                { { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{ 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},{ 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{ 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
                { { 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{ 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},{ 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{ 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
                { { 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{ 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},{ 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{ 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
                { { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{ 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},{ 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{ 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
                { { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{ 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},{ 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{ 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
                { { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{ 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},{ 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{ 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
                { { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{ 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},{ 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{ 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
            };

        void key_generation()
        {
            bool Permuted_key[56],Lkey_28[28],Rkey_28[28],values_shift_l[2],values_shift_r[2];

            //initial key permutation 1
            for(int i=0;i<56;i++){Permuted_key[i] = Key_64[Permutation_1_key[i]-1];}
            for(int i=0;i<28;i++){Lkey_28[i]=Permuted_key[i];} for(int i =28;i<56;i++){Rkey_28[i-28]=Permuted_key[i];}
            for(int i=0;i<16;i++)
            {
                //Shift according to shift table
                for(int j=0;j<Shift_table[i];j++){values_shift_l[j]=Lkey_28[j];values_shift_r[j]=Rkey_28[j];}
                for(int j=Shift_table[i];j<28;j++){Lkey_28[j-Shift_table[i]]=Lkey_28[j];Rkey_28[j-Shift_table[i]]=Rkey_28[j];}
                for(int j=28-Shift_table[i];j<28;j++){Lkey_28[j]=values_shift_l[j-(28-Shift_table[i])];Rkey_28[j]=values_shift_r[j-(28-Shift_table[i])];}

                //retotaling
                for(int j=0;j<28;j++){Permuted_key[j]=Lkey_28[j];} for(int j =28;j<56;j++){Permuted_key[j]=Rkey_28[j-28];}

                //permutation 2 key after each shift
                for(int j=0;j<48;j++){Keys[i][j]=Permuted_key[Permutation_2_key[j]-1];}
                
            }
        }

        int generate_binary(int a){int bin=0,i=1;while(a>0){bin += i*(a%2);a/=2;i*=10;}return bin;}
        int hex_value(char a){if(a<=57&&a>=48){return a-48;}else if(a>=65&&a<=70){return 10+a-65;}else if(a>=97&&a<=102){return 10+a-97;}else{return -1;}}
        char value_hex(int a){if(a>=0 && a<=9){return 48+a;}else if(a<=16 && a>=10){return 55+a;}else{return -1;}}
        bool Key_64[64],Keys[16][48],key_set=false,pt_set=false,ct_set=false,Plain_text_64[64],Cipher_text_64[64];

    public:
    
        //can have "Plain text", "Cipher text" and "Key" as input
        void set(string input)
        {
            char text_input[16];
            cout<<"Enter the "<<input<<" value: ";cin>>text_input;
            if(strlen(text_input)<16){cout<<"!!!!!Insuffiient "<<input<<" size!!!!!!\n";set(input);}
            else
            {
                bool value_set=true;
                for(int i=0;i<16;i++){if(hex_value(text_input[i]) == -1){value_set=false;}}
                if(value_set)
                {
                    cout<<"!!"<<input<<" set in binary as!!! -> ";

                    bool bit_conversion[64];int binary_value;
                    for(int i=0;i<16;i++)
                    {
                        binary_value = generate_binary(hex_value(text_input[i]));
                        for(int j=3;j>=0;j--){bit_conversion[4*i+j]=binary_value%10;binary_value/=10;}
                    }

                    for(int i=0;i<64;i++){cout<<bit_conversion[i];if(i%4==3){cout<<" ";}}cout<<endl;
                    
                    if(input == "Key"){for(int i=0;i<64;i++){Key_64[i]=bit_conversion[i];}key_set=true;key_generation();}
                    else if(input == "Plain text"){for(int i=0;i<64;i++){Plain_text_64[i]=bit_conversion[i];}pt_set=true;}
                    else if(input == "Cipher text"){for(int i=0;i<64;i++){Cipher_text_64[i]=bit_conversion[i];}ct_set=true;}

                }
                else{cout<<"!!!!Value error in setting "<<input<<" try again!!!!\n";set(input);}
            }
        }

        //values can be encription or decription
        void process(string input)
        {
            bool do_process=false,Input_text_64[64];int inc,i;
            if(input=="Encription" && pt_set && key_set){for(int i =0;i<64;i++){Input_text_64[i]=Plain_text_64[i];}i=0;inc=1;do_process=true;}
            else if(input=="Decription" && ct_set && key_set){for(int i =0;i<64;i++){Input_text_64[i]=Cipher_text_64[i];}i=15;inc=-1;do_process=true;}
            if(do_process)
            {
                bool Permuted_input_text_64[64],RIT_32[32],LIT_32[32],Extended_RIT_48[48],Xor_key_RIT_48[48],
                 S_box_output_32[32],Permuted_sbox_output_32[32],New_LIT_32[32],Final_text[64];
                int sbox_value;

                //initial permutation
                for(int i =0;i<64;i++){Permuted_input_text_64[i]=Input_text_64[Initial_permutation[i]-1];}
                cout<<"Permuted text initially is: ";for(int i =0;i<16;i++){cout<<value_hex(Permuted_input_text_64[4*i]*2*2*2+Permuted_input_text_64[4*i+1]*2*2+Permuted_input_text_64[4*i+2]*2+Permuted_input_text_64[4*i+3]);}cout<<endl;

                //seperation
                for(int i =0;i<32;i++){LIT_32[i]=Permuted_input_text_64[i];}; for(int i =32;i<64;i++){RIT_32[i-32]=Permuted_input_text_64[i];}

                //printing text
                for(int j=0;j<8;j++){cout<<value_hex(LIT_32[4*j]*2*2*2+LIT_32[4*j+1]*2*2+LIT_32[4*j+2]*2+LIT_32[4*j+3]);}cout<<" ";
                for(int j=0;j<8;j++){cout<<value_hex(RIT_32[4*j]*2*2*2+RIT_32[4*j+1]*2*2+RIT_32[4*j+2]*2+RIT_32[4*j+3]);}cout<<endl;

                while (i>=0 && i<=15)
                {
                    //extend right side text
                    for (int j = 0; j < 48; j++){Extended_RIT_48[j]=RIT_32[Expansion_box[j]-1];}

                    //xor with key
                    for (int j = 0; j < 48; j++){Xor_key_RIT_48[j]=Keys[i][j]^Extended_RIT_48[j];}

                    //sbox output
                    for (int j = 0; j < 8; j++)
                    {
                        sbox_value=generate_binary(S_box_table[j][Xor_key_RIT_48[6*j]*2+Xor_key_RIT_48[6*j+5]][Xor_key_RIT_48[6*j+1]*2*2*2+Xor_key_RIT_48[6*j+2]*2*2+Xor_key_RIT_48[6*j+3]*2+Xor_key_RIT_48[6*j+4]]);
                        for(int k=3;k>=0;k--){S_box_output_32[4*j+k]=sbox_value%10;sbox_value/=10;}
                    }

                    //permute sbox output
                    for (int j = 0; j < 32; j++){Permuted_sbox_output_32[j]=S_box_output_32[Permutation_after_S_box[j]-1];}

                    //xor permuted sbox output with LIT to get new LIT
                    for (int j = 0; j < 32; j++){New_LIT_32[j]=Permuted_sbox_output_32[j]^LIT_32[j];}

                    //Rit becomes lit and new lit becomes lit
                    for (int j = 0; j < 32; j++){LIT_32[j]=RIT_32[j];} for (int j = 0; j < 32; j++){RIT_32[j]=New_LIT_32[j];}

                    cout<<"Round "<<i<<"-> ";
                    for(int j=0;j<8;j++){cout<<value_hex(LIT_32[4*j]*2*2*2+LIT_32[4*j+1]*2*2+LIT_32[4*j+2]*2+LIT_32[4*j+3]);}cout<<" ";
                    for(int j=0;j<8;j++){cout<<value_hex(RIT_32[4*j]*2*2*2+RIT_32[4*j+1]*2*2+RIT_32[4*j+2]*2+RIT_32[4*j+3]);}cout<<" ";

                    //printing key
                    cout<<"Key "<<i<<"-> ";for(int j=0;j<12;j++){cout<<value_hex(Keys[i][j*4]*2*2*2+Keys[i][j*4+1]*2*2+Keys[i][j*4+2]*2+Keys[i][j*4+3]);}cout<<endl;
                    i=i+inc;
                }
                //final text = rit + lit
                for(int i =0;i<32;i++){Final_text[i]=RIT_32[i];} for(int i =32;i<64;i++){Final_text[i]=LIT_32[i-32];}

                if(input=="Encription")
                {
                    //final permuted text
                    for(int i =0;i<64;i++){Cipher_text_64[i]=Final_text[Final_permutation[i]-1];ct_set=true;}
                    cout<<"Cipher text is: ";for(int i =0;i<16;i++){cout<<value_hex(Cipher_text_64[4*i]*2*2*2+Cipher_text_64[4*i+1]*2*2+Cipher_text_64[4*i+2]*2+Cipher_text_64[4*i+3]);}cout<<endl;
                }
                else
                {
                    //final permuted text
                    for(int i =0;i<64;i++){Plain_text_64[i]=Final_text[Final_permutation[i]-1];pt_set=true;}
                    cout<<"Plain text is: ";for(int i =0;i<16;i++){cout<<value_hex(Plain_text_64[4*i]*2*2*2+Plain_text_64[4*i+1]*2*2+Plain_text_64[4*i+2]*2+Plain_text_64[4*i+3]);}cout<<endl;
                }
            }
            else{cout<<"!!!Enter correct parameters and set values first!!!\n";}
        }
   
}DES;

int main()
{
    DES.set("Key");
    DES.set("Plain text");
    DES.process("Encription");
    DES.process("Decription");
    
}
