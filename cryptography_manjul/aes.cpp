#include<bits/stdc++.h>
using namespace std;
class aes
{
    private:
	long int a = long int_MAX;
		char multiply_output[2];
		void multiply_hex(char inputa[2],char inputb[2])
		{
			// cout<<inputa[0]<<inputa[1]<<" * "<<inputb[0]<<inputb[1]<<" = ";
			long int product[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};bool a[8],b[8],value_gt7exist=true;

			//memory issues redefining values
			char ain[2];ain[1]=inputa[1];ain[0]=inputa[0];
			char bin[2];bin[1]=inputb[1];bin[0]=inputb[0];

			ain[0]=hex2dec[ain[0]];ain[1]=hex2dec[ain[1]];bin[0]=hex2dec[bin[0]];bin[1]=hex2dec[bin[1]];

			//converting input to binary by dividing by 2
			for (long int i = 3; i >= 0; i--){a[i]=ain[0]%2;ain[0]/=2; a[4+i]=ain[1]%2;ain[1]/=2;	b[i]=bin[0]%2;bin[0]/=2; b[4+i]=bin[1]%2;bin[1]/=2;	}

			//first multiply
			for (long int i = 7; i >=0; i--){for (long int j = 7; j >=0; j--){if(a[i] && b[j]){product[(7-i)+(7-j)]+=1;}}}

			//second multiply to reduce power over 7
			while(value_gt7exist)
			{
				//prlong int by modding by 2
				for (long int i = 15; i >= 0; i--){product[i]=product[i]%2;}
				//galileo polynomial theorem
				for (long int i = 15; i >= 8; i--)
				{
					if(product[i]){product[i]=0;product[4+(i%8)]+=1; product[3+(i%8)]+=1; product[1+(i%8)]+=1; product[0+(i%8)]+=1;  value_gt7exist=true;break;}
					else{value_gt7exist=false;}
				}
			}
			//output stored in variable below cause c++ is annoying
			multiply_output[1]=dec2hex[product[3]*2*2*2+product[2]*2*2+product[1]*2+product[0]];
			multiply_output[0]=dec2hex[product[7]*2*2*2+product[6]*2*2+product[5]*2+product[4]];
			// cout<<inputa[0]<<inputa[1]<<"*"<<inputb[0]<<inputb[1]<<"="<<multiply_output[0]<<multiply_output[1]<<endl;
		}

		//for normal process
		char S_box_inv[16][16][2]={
			{{'5','2'},	{'0','9'},	{'6','a'},	{'d','5'},	{'3','0'},	{'3','6'},	{'a','5'},	{'3','8'},	{'b','f'},	{'4','0'},	{'a','3'},	{'9','e'},	{'8','1'},	{'f','3'},	{'d','7'},	{'f','b'}},
			{{'7','c'},	{'e','3'},	{'3','9'},	{'8','2'},	{'9','b'},	{'2','f'},	{'f','f'},	{'8','7'},	{'3','4'},	{'8','e'},	{'4','3'},	{'4','4'},	{'c','4'},	{'d','e'},	{'e','9'},	{'c','b'}},
			{{'5','4'},	{'7','b'},	{'9','4'},	{'3','2'},	{'a','6'},	{'c','2'},	{'2','3'},	{'3','d'},	{'e','e'},	{'4','c'},	{'9','5'},	{'0','b'},	{'4','2'},	{'f','a'},	{'c','3'},	{'4','e'}},
			{{'0','8'},	{'2','e'},	{'a','1'},	{'6','6'},	{'2','8'},	{'d','9'},	{'2','4'},	{'b','2'},	{'7','6'},	{'5','b'},	{'a','2'},	{'4','9'},	{'6','d'},	{'8','b'},	{'d','1'},	{'2','5'}},
			{{'7','2'},	{'f','8'},	{'f','6'},	{'6','4'},	{'8','6'},	{'6','8'},	{'9','8'},	{'1','6'},	{'d','4'},	{'a','4'},	{'5','c'},	{'c','c'},	{'5','d'},	{'6','5'},	{'b','6'},	{'9','2'}},
			{{'6','c'},	{'7','0'},	{'4','8'},	{'5','0'},	{'f','d'},	{'e','d'},	{'b','9'},	{'d','a'},	{'5','e'},	{'1','5'},	{'4','6'},	{'5','7'},	{'a','7'},	{'8','d'},	{'9','d'},	{'8','4'}},
			{{'9','0'},	{'d','8'},	{'a','b'},	{'0','0'},	{'8','c'},	{'b','c'},	{'d','3'},	{'0','a'},	{'f','7'},	{'e','4'},	{'5','8'},	{'0','5'},	{'b','8'},	{'b','3'},	{'4','5'},	{'0','6'}},
			{{'d','0'},	{'2','c'},	{'1','e'},	{'8','f'},	{'c','a'},	{'3','f'},	{'0','f'},	{'0','2'},	{'c','1'},	{'a','f'},	{'b','d'},	{'0','3'},	{'0','1'},	{'1','3'},	{'8','a'},	{'6','b'}},
			{{'3','a'},	{'9','1'},	{'1','1'},	{'4','1'},	{'4','f'},	{'6','7'},	{'d','c'},	{'e','a'},	{'9','7'},	{'f','2'},	{'c','f'},	{'c','e'},	{'f','0'},	{'b','4'},	{'e','6'},	{'7','3'}},
			{{'9','6'},	{'a','c'},	{'7','4'},	{'2','2'},	{'e','7'},	{'a','d'},	{'3','5'},	{'8','5'},	{'e','2'},	{'f','9'},	{'3','7'},	{'e','8'},	{'1','c'},	{'7','5'},	{'d','f'},	{'6','e'}},
			{{'4','7'},	{'f','1'},	{'1','a'},	{'7','1'},	{'1','d'},	{'2','9'},	{'c','5'},	{'8','9'},	{'6','f'},	{'b','7'},	{'6','2'},	{'0','e'},	{'a','a'},	{'1','8'},	{'b','e'},	{'1','b'}},
			{{'f','c'},	{'5','6'},	{'3','e'},	{'4','b'},	{'c','6'},	{'d','2'},	{'7','9'},	{'2','0'},	{'9','a'},	{'d','b'},	{'c','0'},	{'f','e'},	{'7','8'},	{'c','d'},	{'5','a'},	{'f','4'}},
			{{'1','f'},	{'d','d'},	{'a','8'},	{'3','3'},	{'8','8'},	{'0','7'},	{'c','7'},	{'3','1'},	{'b','1'},	{'1','2'},	{'1','0'},	{'5','9'},	{'2','7'},	{'8','0'},	{'e','c'},	{'5','f'}},
			{{'6','0'},	{'5','1'},	{'7','f'},	{'a','9'},	{'1','9'},	{'b','5'},	{'4','a'},	{'0','d'},	{'2','d'},	{'e','5'},	{'7','a'},	{'9','f'},	{'9','3'},	{'c','9'},	{'9','c'},	{'e','f'}},
			{{'a','0'},	{'e','0'},	{'3','b'},	{'4','d'},	{'a','e'},	{'2','a'},	{'f','5'},	{'b','0'},	{'c','8'},	{'e','b'},	{'b','b'},	{'3','c'},	{'8','3'},	{'5','3'},	{'9','9'},	{'6','1'}},
			{{'1','7'},	{'2','b'},	{'0','4'},	{'7','e'},	{'b','a'},	{'7','7'},	{'d','6'},	{'2','6'},	{'e','1'},	{'6','9'},	{'1','4'},	{'6','3'},	{'5','5'},	{'2','1'},	{'0','c'},	{'7','d'}}
		};
		char Mix_matrix_inv[4][4][2]={
			{{'0','e'},{'0','b'},{'0','d'},{'0','9'}},
			{{'0','9'},{'0','e'},{'0','b'},{'0','d'}},
			{{'0','d'},{'0','9'},{'0','e'},{'0','b'}},
			{{'0','b'},{'0','d'},{'0','9'},{'0','e'}}
		};

		char S_box[16][16][2] = {
			{{'6','3'},	{'7','c'},	{'7','7'},	{'7','b'},	{'f','2'},	{'6','b'},	{'6','f'},	{'c','5'},	{'3','0'},	{'0','1'},	{'6','7'},	{'2','b'},	{'f','e'},	{'d','7'},	{'a','b'},	{'7','6'}},
			{{'c','a'},	{'8','2'},	{'c','9'},	{'7','d'},	{'f','a'},	{'5','9'},	{'4','7'},	{'f','0'},	{'a','d'},	{'d','4'},	{'a','2'},	{'a','f'},	{'9','c'},	{'a','4'},	{'7','2'},	{'c','0'}},
			{{'b','7'},	{'f','d'},	{'9','3'},	{'2','6'},	{'3','6'},	{'3','f'},	{'f','7'},	{'c','c'},	{'3','4'},	{'a','5'},	{'e','5'},	{'f','1'},	{'7','1'},	{'d','8'},	{'3','1'},	{'1','5'}},
			{{'0','4'},	{'c','7'},	{'2','3'},	{'c','3'},	{'1','8'},	{'9','6'},	{'0','5'},	{'9','a'},	{'0','7'},	{'1','2'},	{'8','0'},	{'e','2'},	{'e','b'},	{'2','7'},	{'b','2'},	{'7','5'}},
			{{'0','9'},	{'8','3'},	{'2','c'},	{'1','a'},	{'1','b'},	{'6','e'},	{'5','a'},	{'a','0'},	{'5','2'},	{'3','b'},	{'d','6'},	{'b','3'},	{'2','9'},	{'e','3'},	{'2','f'},	{'8','4'}},
			{{'5','3'},	{'d','1'},	{'0','0'},	{'e','d'},	{'2','0'},	{'f','c'},	{'b','1'},	{'5','b'},	{'6','a'},	{'c','b'},	{'b','e'},	{'3','9'},	{'4','a'},	{'4','c'},	{'5','8'},	{'c','f'}},
			{{'d','0'},	{'e','f'},	{'a','a'},	{'f','b'},	{'4','3'},	{'4','d'},	{'3','3'},	{'8','5'},	{'4','5'},	{'f','9'},	{'0','2'},	{'7','f'},	{'5','0'},	{'3','c'},	{'9','f'},	{'a','8'}},
			{{'5','1'},	{'a','3'},	{'4','0'},	{'8','f'},	{'9','2'},	{'9','d'},	{'3','8'},	{'f','5'},	{'b','c'},	{'b','6'},	{'d','a'},	{'2','1'},	{'1','0'},	{'f','f'},	{'f','3'},	{'d','2'}},
			{{'c','d'},	{'0','c'},	{'1','3'},	{'e','c'},	{'5','f'},	{'9','7'},	{'4','4'},	{'1','7'},	{'c','4'},	{'a','7'},	{'7','e'},	{'3','d'},	{'6','4'},	{'5','d'},	{'1','9'},	{'7','3'}},
			{{'6','0'},	{'8','1'},	{'4','f'},	{'d','c'},	{'2','2'},	{'2','a'},	{'9','0'},	{'8','8'},	{'4','6'},	{'e','e'},	{'b','8'},	{'1','4'},	{'d','e'},	{'5','e'},	{'0','b'},	{'d','b'}},
			{{'e','0'},	{'3','2'},	{'3','a'},	{'0','a'},	{'4','9'},	{'0','6'},	{'2','4'},	{'5','c'},	{'c','2'},	{'d','3'},	{'a','c'},	{'6','2'},	{'9','1'},	{'9','5'},	{'e','4'},	{'7','9'}},
			{{'e','7'},	{'c','8'},	{'3','7'},	{'6','d'},	{'8','d'},	{'d','5'},	{'4','e'},	{'a','9'},	{'6','c'},	{'5','6'},	{'f','4'},	{'e','a'},	{'6','5'},	{'7','a'},	{'a','e'},	{'0','8'}},
			{{'b','a'},	{'7','8'},	{'2','5'},	{'2','e'},	{'1','c'},	{'a','6'},	{'b','4'},	{'c','6'},	{'e','8'},	{'d','d'},	{'7','4'},	{'1','f'},	{'4','b'},	{'b','d'},	{'8','b'},	{'8','a'}},
			{{'7','0'},	{'3','e'},	{'b','5'},	{'6','6'},	{'4','8'},	{'0','3'},	{'f','6'},	{'0','e'},	{'6','1'},	{'3','5'},	{'5','7'},	{'b','9'},	{'8','6'},	{'c','1'},	{'1','d'},	{'9','e'}},
			{{'e','1'},	{'f','8'},	{'9','8'},	{'1','1'},	{'6','9'},	{'d','9'},	{'8','e'},	{'9','4'},	{'9','b'},	{'1','e'},	{'8','7'},	{'e','9'},	{'c','e'},	{'5','5'},	{'2','8'},	{'d','f'}},
			{{'8','c'},	{'a','1'},	{'8','9'},	{'0','d'},	{'b','f'},	{'e','6'},	{'4','2'},	{'6','8'},	{'4','1'},	{'9','9'},	{'2','d'},	{'0','f'},	{'b','0'},	{'5','4'},	{'b','b'},	{'1','6'}}
		};

		char Round_key[4][10][2]={
			{{'0','1'},{'0','2'},{'0','4'},{'0','8'},{'1','0'},{'2','0'},{'4','0'},{'8','0'},{'1','b'},{'3','6'}},
			{{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
			{{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
			{{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'},{'0','0'}}
		};
		char Mix_matrix[4][4][2]={
			{{'0','2'},{'0','3'},{'0','1'},{'0','1'}},
			{{'0','1'},{'0','2'},{'0','3'},{'0','1'}},
			{{'0','1'},{'0','1'},{'0','2'},{'0','3'}},
			{{'0','3'},{'0','1'},{'0','1'},{'0','2'}}
		};
        unordered_map<char,long int> hex2dec;
		unordered_map<long int,char> dec2hex;
        char Keys[4][44][2],PT_matrix[4][4][2],Key[16];
		char Xor_hex(char a,char b){return dec2hex[hex2dec[a]^hex2dec[b]];}
		bool key_set=false,pt_set=false,ct_set=false;
		//made because the % causes error occasionally in -ve value
        long int mod(long int a,long int b){while(a<0){a = a + b;}{return a % b;}}
		void key_generation()
		{
			char sub_value_a,sub_value_b;long int round_key_index=-1;
			for (long int i = 4; i < 44; i++)
			{
				if(i%4==0){round_key_index++;}
				if(i==4){/*rotation*/for (long int j = 0; j < 4; j++){Keys[mod(j-1,4)][i][0] = Keys[j][i-1][0];	Keys[mod(j-1,4)][i][1] = Keys[j][i-1][1];}}
				else{/*no rotation assign value*/for (long int j = 0; j < 4; j++){Keys[j][i][0] = Keys[j][i-1][0];	Keys[j][i][1] = Keys[j][i-1][1];}}
				for(long int j=0;j<4;j++)
				{
					if(i%4==0)
					{
						//substitution part
						// cout<<hex2dec[Keys[j][i][0]]<<hex2dec[Keys[j][i][1]]<<"&";
						sub_value_a=S_box[hex2dec[Keys[j][i][0]]][hex2dec[Keys[j][i][1]]][0];sub_value_b=S_box[hex2dec[Keys[j][i][0]]][hex2dec[Keys[j][i][1]]][1];
						Keys[j][i][0]=sub_value_a;Keys[j][i][1]=sub_value_b;

						//xor round const
						Keys[j][i][0]=Xor_hex(Keys[j][i][0],Round_key[j][round_key_index][0]);Keys[j][i][1]=Xor_hex(Keys[j][i][1],Round_key[j][round_key_index][1]);
						// cout<<hex2dec[Round_key[j][round_key_index][0]]<<hex2dec[Round_key[j][round_key_index][1]]<<" ";
					}
					//xor part also with w0 or 4-4 for w4 and 5-4 for w5 ..
					Keys[j][i][0]=Xor_hex(Keys[j][i][0],Keys[j][i-4][0]);Keys[j][i][1]=Xor_hex(Keys[j][i][1],Keys[j][i-4][1]);	
				}
				
			}cout<<endl;
			//prlong inting keys
			for (long int i = 0; i < 4; i++){for (long int j = 0; j < 44; j++){cout<<Keys[i][j][0]<<Keys[i][j][1];if(j%4==3){cout<<" | ";}else{cout<<" ";}}cout<<endl;}
		}
    public:
        char Plain_text[16],CT_matrix[4][4][2];
        aes()
        {
			hex2dec['0'] = 0;hex2dec['1'] = 1;hex2dec['2'] = 2;hex2dec['3'] = 3;hex2dec['4'] = 4;hex2dec['5'] = 5; 
			hex2dec['6'] = 6;hex2dec['7'] = 7;hex2dec['8'] = 8;hex2dec['9'] = 9;
			hex2dec['a'] = 10;hex2dec['b'] = 11;hex2dec['c'] = 12;hex2dec['d'] = 13;hex2dec['e'] = 14;hex2dec['f'] = 15;
			dec2hex[0] = '0';dec2hex[1] = '1';dec2hex[2] = '2';dec2hex[3] = '3';dec2hex[4] = '4';dec2hex[5] = '5';
			dec2hex[6] = '6';dec2hex[7] = '7';dec2hex[8] = '8';dec2hex[9] = '9';
			dec2hex[10] = 'a';dec2hex[11] = 'b';dec2hex[12] = 'c';dec2hex[13] = 'd';dec2hex[14] = 'e';dec2hex[15] = 'f';
        }
		void set(string input_choice)
		{
			if(input_choice=="Key" || input_choice == "Plain text")
			{

				char input_text[16],matrix_input[4][4][2];
				cout<<"Enter "<<input_choice<<": ";cin>>input_text;
				if(strlen(input_text)<16){cout<<"!!!Not enough text try again!!!\n";set(input_choice);}
				else
				{
					long int inc=0;
					for(long int i =0;i<4;i++){for(long int j=0;j<4;j++){matrix_input[j][i][1]=input_text[inc]%16;matrix_input[j][i][0]=input_text[inc]/16;inc++;}}

					if(input_choice == "Key")
					{
						cout<<"!!! "<<input_choice<<" set as!!!\n";key_set=true;
						inc = 0;
						for(long int i=0;i<4;i++){
							for(long int j=0;j<4;j++)
							{
								Keys[i][j][0]=dec2hex[matrix_input[i][j][0]];Keys[i][j][1]=dec2hex[matrix_input[i][j][1]];
								Key[inc]=input_text[inc];
								cout<<Keys[i][j][0]<<Keys[i][j][1]<<" ";inc++;
							}cout<<endl;
						}cout<<endl;
						cout<<"Keys set as:\n";key_generation();cout<<endl;
					}
					else if(input_choice == "Plain text")
					{
						cout<<"!!! "<<input_choice<<" set as!!!\n";pt_set=true;
						inc=0;
						for(long int i=0;i<4;i++)
						{
							for(long int j=0;j<4;j++)
							{
								PT_matrix[i][j][0]=dec2hex[matrix_input[i][j][0]];	PT_matrix[i][j][1]=dec2hex[matrix_input[i][j][1]];
								Plain_text[inc]=input_text[inc]; cout<<PT_matrix[i][j][0]<<PT_matrix[i][j][1]<<" ";inc++;
							}cout<<endl;
						}cout<<endl;
					}		
				}
			}
			else if(input_choice == "Cipher text")
			{
				cout<<"Enter the cipher text matrix row wise: \n";

				for (long int i = 0; i < 4; i++){for (long int j = 0; j < 4; j++){cin>>CT_matrix[i][j];}}
				
				cout<<"!!! "<<input_choice<<" set !!!\n"<<endl;ct_set=true;cout<<endl;
				// for (long int i = 0; i < 4; i++){for (long int j = 0; j < 4; j++){cout<<CT_matrix[i][j][0]<<CT_matrix[i][j][1]<<" ";	}cout<<endl;}
			}
			else{cout<<"Error in parameter use \"Key\" \"Plain text\" \"Cipher text\" \nEnter the parameter: ";cin>>input_choice;set(input_choice);}
		}

		void encription()
		{
			if(pt_set && key_set)
			{
				long int initial_index_column_key=0,suba,subb;char for_shift[4][2];

				cout<<"Initial Xor value are: \n";
				for(long int i=0;i<4;i++)
				{
					for (long int j = 0; j<4 ; j++)
					{
						CT_matrix[i][j][0]=Xor_hex(PT_matrix[i][j][0],Keys[i][j][0]);CT_matrix[i][j][1]=Xor_hex(PT_matrix[i][j][1],Keys[i][j][1]);
						cout<<CT_matrix[i][j][0]<<CT_matrix[i][j][1]<<" ";
					}cout<<endl;	
				}cout<<endl;

				for(long int round=1;round<=10;round++)
				{
					cout<<"After substitution:\n";
					for (long int i = 0; i < 4; i++)
					{
						for (long int j = 0; j < 4; j++)
						{
							suba = S_box[hex2dec[CT_matrix[i][j][0]]][hex2dec[CT_matrix[i][j][1]]][0];subb = S_box[hex2dec[CT_matrix[i][j][0]]][hex2dec[CT_matrix[i][j][1]]][1];
							CT_matrix[i][j][0]=suba;CT_matrix[i][j][1]=subb;
							cout<<CT_matrix[i][j][0]<<CT_matrix[i][j][1]<<" ";
						}cout<<endl;
					}cout<<endl;

					cout<<"After shifting:\n";
					for (long int i = 0; i < 4; i++)
					{
						for(long int j=0;j<4;j++)
						{
							for_shift[j][0]=CT_matrix[i][mod(j+i,4)][0];for_shift[j][1]=CT_matrix[i][mod(j+i,4)][1];
							//cout<<for_shift[j][0]<<for_shift[j][1]<<" ";
						}//cout<<endl;

						for (long int j = 0; j <4 ; j++)
						{
							CT_matrix[i][j][0]=for_shift[j][0];CT_matrix[i][j][1]=for_shift[j][1];
						}

					}
					//prlong int CT_matrix
					for (long int i = 0; i < 4; i++){for (long int j = 0; j < 4; j++){cout<<CT_matrix[i][j][0]<<CT_matrix[i][j][1]<<" ";}cout<<endl;}cout<<endl;

					if(round!=10)
					{
						//temp place for mixing matrix and redefining for no memory error
						char for_mix[4][4][2]={
							{{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
							{{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
							{{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
							{{'0','0'},{'0','0'},{'0','0'},{'0','0'}}
						};
						cout<<"Matrix mixing: \n";
						for (long int i = 0; i < 4; i++)
						{
							for (long int j = 0; j < 4; j++)
							{
								for (long int k = 0; k < 4; k++)
								{
									multiply_hex(Mix_matrix[j][k],CT_matrix[k][i]);
									for_mix[j][i][0]=Xor_hex(for_mix[j][i][0],multiply_output[0]);for_mix[j][i][1]=Xor_hex(for_mix[j][i][1],multiply_output[1]);
								}						
							}
						}
						//replacing with ct matrix
						for (long int i = 0; i < 4; i++)
						{
							for (long int j = 0; j < 4; j++)
							{
								CT_matrix[i][j][0]=for_mix[i][j][0];CT_matrix[i][j][1]=for_mix[i][j][1];
								cout<<CT_matrix[i][j][0]<<CT_matrix[i][j][1]<<" ";				
							}cout<<endl;
						}cout<<endl;
					}

					initial_index_column_key+=4;
					cout<<"xor with key index start "<<initial_index_column_key<<endl;
					for(long int i=0;i<4;i++)
					{
						for (long int j = 0; j<4 ; j++)
						{
							CT_matrix[i][j][0]=Xor_hex(CT_matrix[i][j][0],Keys[i][j+initial_index_column_key][0]);
							CT_matrix[i][j][1]=Xor_hex(CT_matrix[i][j][1],Keys[i][j+initial_index_column_key][1]);
							cout<<CT_matrix[i][j][0]<<CT_matrix[i][j][1]<<" ";
						}cout<<endl;	
					}cout<<endl;
				}
				//end of the round otputting ct
				ct_set=true;
				cout<<"Cipher text: \n";
				for(long int i=0;i<4;i++){for (long int j = 0; j<4 ; j++){cout<<char(hex2dec[CT_matrix[j][i][0]]*16+hex2dec[CT_matrix[j][i][1]]);}}cout<<endl;
				cout<<"Prefarably use matrix cz of unknown chars can also include backsapace enter etc\n"<<endl;
				
			}else{cout<<"!!!Set plain text and key from from function first!!!\n";}
		}

		void decription()
		{
			long int initial_index_column_key=40,suba,subb;char for_shift[4][2];

			cout<<"Initial Xor value are: "<<initial_index_column_key<<"\n";
			for(long int i=0;i<4;i++)
			{
				for (long int j = 0; j<4 ; j++)
				{
					PT_matrix[i][j][0]=Xor_hex(CT_matrix[i][j][0],Keys[i][j+initial_index_column_key][0]);
					PT_matrix[i][j][1]=Xor_hex(CT_matrix[i][j][1],Keys[i][j+initial_index_column_key][1]);
					cout<<PT_matrix[i][j][0]<<PT_matrix[i][j][1]<<" ";
				}cout<<endl;	
			}cout<<endl;

			for(long int round=1;round<=10;round++)
			{
				cout<<"After substitution:\n";
				for (long int i = 0; i < 4; i++)
				{
					for (long int j = 0; j < 4; j++)
					{
						suba = S_box_inv[hex2dec[PT_matrix[i][j][0]]][hex2dec[PT_matrix[i][j][1]]][0];subb = S_box_inv[hex2dec[PT_matrix[i][j][0]]][hex2dec[PT_matrix[i][j][1]]][1];
						PT_matrix[i][j][0]=suba;PT_matrix[i][j][1]=subb;
						cout<<PT_matrix[i][j][0]<<PT_matrix[i][j][1]<<" ";
					}cout<<endl;
				}cout<<endl;

				cout<<"After shifting:\n";
				for (long int i = 0; i < 4; i++)
				{
					for(long int j=0;j<4;j++)
					{
						for_shift[j][0]=PT_matrix[i][mod(j-i,4)][0];for_shift[j][1]=PT_matrix[i][mod(j-i,4)][1];
						//cout<<for_shift[j][0]<<for_shift[j][1]<<" ";
					}//cout<<endl;

					for (long int j = 0; j <4 ; j++)
					{
						PT_matrix[i][j][0]=for_shift[j][0];	PT_matrix[i][j][1]=for_shift[j][1];
					}

				}
				//prlong int PT_matrix
				for (long int i = 0; i < 4; i++){for (long int j = 0; j < 4; j++){cout<<PT_matrix[i][j][0]<<PT_matrix[i][j][1]<<" ";}cout<<endl;}cout<<endl;


				initial_index_column_key-=4;
				cout<<"xor with key index start "<<initial_index_column_key<<endl;
				for(long int i=0;i<4;i++)
				{
					for (long int j = 0; j<4 ; j++)
					{
						PT_matrix[i][j][0]=Xor_hex(PT_matrix[i][j][0],Keys[i][j+initial_index_column_key][0]);
						PT_matrix[i][j][1]=Xor_hex(PT_matrix[i][j][1],Keys[i][j+initial_index_column_key][1]);
						cout<<PT_matrix[i][j][0]<<PT_matrix[i][j][1]<<" ";
					}cout<<endl;	
				}cout<<endl;

				if(round!=10)
				{
					//temp place for mixing matrix and redefining for no memory error
					char for_mix[4][4][2]={
						{{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
						{{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
						{{'0','0'},{'0','0'},{'0','0'},{'0','0'}},
						{{'0','0'},{'0','0'},{'0','0'},{'0','0'}}
					};
					cout<<"Matrix mixing: \n";
					for (long int i = 0; i < 4; i++)
					{
						for (long int j = 0; j < 4; j++)
						{
							for (long int k = 0; k < 4; k++)
							{
								multiply_hex(Mix_matrix_inv[j][k],PT_matrix[k][i]);
								for_mix[j][i][0]=Xor_hex(for_mix[j][i][0],multiply_output[0]);for_mix[j][i][1]=Xor_hex(for_mix[j][i][1],multiply_output[1]);
							}						
						}
					}
					//replacing with pt matrix
					for (long int i = 0; i < 4; i++)
					{
						for (long int j = 0; j < 4; j++)
						{
							PT_matrix[i][j][0]=for_mix[i][j][0];PT_matrix[i][j][1]=for_mix[i][j][1];
							cout<<PT_matrix[i][j][0]<<PT_matrix[i][j][1]<<" ";				
						}cout<<endl;
					}cout<<endl;
				}	
			}
			///end of the round outputting pt
			pt_set=true;long int inc=0;
			cout<<"Plain text: \n";
			for(long int i=0;i<4;i++){for (long int j = 0; j<4 ; j++){Plain_text[inc] = char(hex2dec[PT_matrix[j][i][0]]*16+hex2dec[PT_matrix[j][i][1]]);inc++;}}
			for (long int i = 0; i < 16; i++){cout<<Plain_text[i];}cout<<endl;
			cout<<endl;
		}	
}aes;

long int main()
{
	aes.set("Key");
	aes.set("Plain text");
	aes.encription();
	aes.set("Cipher text");
	aes.decription();
}
