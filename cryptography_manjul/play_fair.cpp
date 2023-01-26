#include<bits/stdc++.h>
using namespace std;
class play_fare
{
    private:
        char input_text[100],output_text[100],key[100],matrix[5][5];
        bool key_given = false;
        int output_text_length = 0,input_text_length = 0;
    
    public:
        int filter_ascii(int a){if(a>=65 && a<=90){a= a - 65;}else if(a>=97 && a<=122){a= a - 97;}else{a= - 1;}if(a==25){return 23;}else{return a;}}
        int mod(int a,int b){while(a<0){a=a+b;}return a%b;}
        void set_input_text ()
        {
            cout<<"Enter the input text: ";cin>>input_text;input_text_length = strlen(input_text);
            for(int i = 0;i<input_text_length;i++){if(filter_ascii(input_text[i])==-1){cout<<"!!Enter correct text!!"<<endl;input_text_length=0;break;}}
        }

        void set_key()
        {
            cout<<"Enter the key value to use: ";cin>>key;
            int row = 0,column = 0,pointer = 0,value=0;key_given=true;
            for(int i = 0;i<5;i++){for(int j = 0;j<5;j++){matrix[i][j]=35;}}
            while(pointer<strlen(key))
            {
                value = filter_ascii(key[pointer]);

                if(matrix[row][column] == 35){matrix[row][column] = value;row=0;column=0;pointer++;}
                else if(value == matrix[row][column]){row=0;column=0;pointer++;}
                else{column++;if(column == 5){row++;column = 0;}}    
            }
            //pointer acts as substitution for value cz of i and j 
            value = 0;row=0;column=0;pointer = value;
            while(value<26)
            {
                if(value == 25){pointer=23;}else{pointer=value;}

                if(matrix[row][column] == 35){matrix[row][column] = pointer;row=0;column=0;value++;}
                else if(pointer == matrix[row][column]){row=0;column=0;value++;}
                else{column++;if(column == 5){row++;column = 0;}}                
            }
            
            cout<<"The matrix is: "<<endl;
            for(int i = 0;i<5;i++){for(int j = 0;j<5;j++){cout<<char(matrix[i][j]+65)<<"  ";}cout<<endl;}
        }
        void process(bool encript=true)
        {
            output_text_length=0;
            if(input_text_length == 0 || !key_given){cout<<"No plain text or no key\n";}
            else
            {
                int ed=1;
                if(encript){ed=1;}else{ed=-1;}
                for(int i = 0;i<input_text_length;i+=2)
                {
                    output_text[output_text_length]=filter_ascii(input_text[i]);
                    output_text[output_text_length+1]=filter_ascii(input_text[i+1]);

                    if(output_text[output_text_length]==output_text[output_text_length+1]){i--;output_text[output_text_length+1]=23;}
                    output_text_length=output_text_length+2;
                }  
            
                if(output_text[output_text_length-1]==-1){output_text[output_text_length-1]=23;}
                for(int i = 0,row=0,row1=0,column=0,column1=0;i<output_text_length;i=i+2)
                {
                    for(int j = 0;j<5;j++)
                    {
                        for(int k = 0;k<5;k++)
                        {
                            if(matrix[j][k] == output_text[i]){row=j;column=k;}
                            else if(matrix[j][k] == output_text[i+1]){row1=j;column1=k;}
                        }
                    }
                    if(row == row1){output_text[i]=matrix[row][mod((column+ed),5)];output_text[i+1]=matrix[row1][mod((column1+ed),5)];}
                    else if(column == column1){output_text[i]=matrix[mod((row+ed),5)][column];output_text[i+1]=matrix[mod((row1+ed),5)][column1];}
                    else{output_text[i]=matrix[row1][column];output_text[i+1]=matrix[row][column1];}
                }
                cout<<"Output text is: ";
                for(int i =0;i<output_text_length;i++){cout<<char(output_text[i]+65);}
                cout<<endl;
            }
            output_text_length=0;input_text_length=0;
        }

}play_fare;
//97 122 small   and     65 90 big   I in 8 J in 9

int main()
{
    char choice;
    do
    {
        cout<<"Note that special characters are skipped in key and causes error in plain text"<<endl;
        play_fare.set_key();
        play_fare.set_input_text();
        play_fare.process();
        play_fare.set_input_text();
        play_fare.process(0);
        cout<<"Do you want to repeat the process[y/n]";cin>>choice;
    } while (24+64 == choice || 24+97==choice);  
}