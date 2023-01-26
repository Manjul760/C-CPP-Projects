#include<bits/stdc++.h>
using namespace std;
class hill_cipher
{
    private:
        //basic definition of check flags and needed elemts like pt ct key key matrix etc
        char cipher_text[100],plain_text[100],key[100];
        float key_matrix[10][10],inverse_key[10][10];
        long int size_of_matrix = 0;
        bool inverse_made = false;
        
    public:
        long int modulo_inv(long int a)
        {
            //to find modulic inverse iteratvely
            a = mod(a,26);
            long int i=0;

            while(mod((a*i),26)!=1){   i++;  }

            return i;
        }

        void set_plain_text()
        {
            cout<<"Enter plain text: ";
            cin>>plain_text;
        }
        
        void set_cipher_text()
        {
            cout<<"Enter cipher text: ";
            cin>>cipher_text;
        }

        bool has_molulic_inv(long int a,long int b,bool prlong int_flag=false)
        {
            //check if modullic inverse exists euclidion method
            if(b == 0)
            {
                return false;
            }
            else if(b == 1)
            {
                return true;
            }

            long int c=a/b,d = a%b;

            if(prlong int_flag){cout<<a<<" = "<<b<<"*"<<c<<" + "<<d<<endl;}

            if(has_molulic_inv(b,d,prlong int_flag))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        long int filter_ascii(long int a)
        {
            // filter the input char using their ascii value to 0-26
            if(a>=65 && a<=90)
            {
                a= a - 65;
            }
            else if(a>=97 && a<=122)
            {
                a= a - 97;
            }
            else
            {
                a= - 1;
            }
            return a;
        }

        long int mod(long int a,long int b)
        { 
            //cause modulus causes error in -ve sometimes
            while(a<0)
            {
                a=a+b;
            }
            return a%b;
        }

        long int determinant(long int size,float matrix[][10])
        {   
            //recursively find determinant as end is a 2*2 matrix whose determinant is ad-bc
            if(size ==2)
            {
                return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
            }
            else if(size == 1)
            {
                return matrix[0][0];
            }
            else if(size <= 0)
            {
                cout<<"Learn some mathematics:"<<endl;
                return 0;
            }
            else
            {
                float matrix_send[size-1][10];
                long int sign =-1,sum = 0,row_m2,column_m2=0;
                for(long int i = 0;i<size;i++)
                {
                    row_m2=0;
                    //start from row 1 ignore 0 to reduce conditions
                    for(long int row =1;row<size;row++)
                    {   
                        for(long int column = 0;column<size;column++)
                        {
                            //ignore the column in which the element lies like for a b c and b element ignore index 1 column
                            if(column != i)
                            {
                                //define send matrix
                                matrix_send[row_m2][column_m2]=matrix[row][column];
                                column_m2++;
                            }
                        }
                        row_m2++;
                        column_m2=0;
                    }
                    //determinant is the sum of upper elements product to its cofactors
                    //send matrix determinanat calculated
                    sum = sum + matrix[0][i]*pow(sign,i)*determinant(size-1,matrix_send);
                }
                return sum;
            }
        }
        void inverse_matrix()
        {
            //to find the inverse use cofactor method
            inverse_made = true;
            float cofactor_matrix[size_of_matrix-1][10],determinant_of_matrix = determinant(size_of_matrix,key_matrix);
            long int sign = -1,row_m2,column_m2;

            for(long int row_inv=0;row_inv<size_of_matrix;row_inv++)
            {
                for (long int col_inv = 0; col_inv < size_of_matrix; col_inv++)
                {
                    row_m2= 0,column_m2=0;
                    for (long int row_cofac = 0; row_cofac < size_of_matrix; row_cofac++)
                    {
                        //making of cofactor matrix ignoring the elements row and column
                        if(row_cofac!=row_inv)
                        {
                            for (long int col_cofac = 0; col_cofac < size_of_matrix; col_cofac++)
                            {
                            
                                if(col_cofac!=col_inv)
                                {
                                    cofactor_matrix[row_m2][column_m2]=key_matrix[row_cofac][col_cofac];
                                    column_m2++;

                                    //resetting values according to need like type writer
                                    if(column_m2>=size_of_matrix-1)
                                    {
                                        row_m2++;
                                        column_m2=0;
                                    }
                                }
                            }
                        }
                    }
                    //assigninng the value of each elements of matrix in inverse order as adjolong int is inverse of cofactor matrix
                    inverse_key[col_inv][row_inv] = pow(sign,(col_inv+row_inv))*determinant(size_of_matrix-1,cofactor_matrix)*modulo_inv(determinant_of_matrix);
                }
            }

            cout<<"\nInverse matrix: "<<endl;
            for (long int i = 0; i < size_of_matrix; i++)
            {
                for (long int j = 0; j < size_of_matrix; j++)
                {
                    cout<<mod(inverse_key[i][j],26)<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void set_key()
        {
            cout<<"Enter key [only alphabets]: ";
            cin>>key;
            
            cout<<"Edited key is: ";
            long int key_len = strlen(key),count = 0,deter;
            size_of_matrix = ceil(sqrt(key_len));
            inverse_made=false;

            //resizing key by adding X as last elements if not enough also checking if matrix is square also filter ascii code as need
            for(long int i = key_len;i<pow(size_of_matrix,2);i++)
            {
                key[i] = (23+65);
            }

            //prlong inting key matrix
            cout<<"\nKey matrix: "<<endl;
            for (long int i = 0; i < size_of_matrix; i++)
            {
                for (long int j = 0; j < size_of_matrix; j++)
                {
                    key_matrix[i][j]=(float)filter_ascii(key[count]);
                    count ++;
                    cout<<key_matrix[i][j]<<" ";
                }
                cout<<endl;
            } 

            //finding determinant and prlong inting it also the mod value of determinant with 26
            deter = determinant(size_of_matrix,key_matrix);
            cout<<"Determinant is: "<<deter<<"\nModulus of determinant is: "<<mod(deter,26)<<endl;

            //exception handling incase inverse matrix doesnot exist
            if(deter == 0)
            {
                cout<<"Inverse matrix doesnt exist"<<endl;
            }
            else if(has_molulic_inv(deter,26))
            {
                //verifying euclidion method 1=true 0=false prlong inting it if exists
                cout<<"\nThe eclidion process is: "<<endl;
                has_molulic_inv(26,mod(deter,26),true);
                cout<<" Modulic inv is: "<<modulo_inv(deter)<<endl;
                inverse_matrix();
            }
            else
            {
                char choice = 24+65;
                cout<<"\nThe eclidion process is: "<<endl;
                has_molulic_inv(deter,26,true);cout<<endl;
                cout<<"Inverse matrix exists but no modulic inverse of determinant "<<endl;

                //if user still wants to encript other wise call same function for re assignment
                cout<<"Cant generate inverse matrix to run with reset key?[y/n]:";
                cin>>choice;

                if(filter_ascii(choice)==24){set_key();}
            }
        }
        void encript_text()
        {
            //exception handling if input not given and inverse not made
            char choice = 24+65;
            if(!inverse_made)
            {
                cout<<"Can't decript code continue?[y/n]: ";cin>>choice;
            }

            if(filter_ascii(choice) == 24 && strlen(plain_text) !=0)
            {
                //defining pt ct and needed length of matrices
                long int needed_len = ceil((float)strlen(plain_text)/size_of_matrix),inc=0,pt_matrix[10][10],ct_matrix[10][10];

                //reassigning 0 because formula is sum
                for(long int i = 0 ;i < needed_len;i++)
                {
                    for(long int j = 0;j < size_of_matrix;j++)
                    {
                        ct_matrix[i][j]=0; 
                    }
                }

                //assigning X to Pt if size is not enough
                for(long int i = strlen(plain_text);i<needed_len*size_of_matrix;i++)
                {
                    plain_text[i] = (23+65);
                }

                //just prlong int pt
                cout<<"The edited plain text is:";
                for(long int i = 0;i<needed_len*size_of_matrix;i++)
                {
                    cout<<plain_text[i];
                }
                cout<<endl;

                //prlong inting pt
                cout<<"\nPT_matrix:\n";
                for(long int i = 0 ;i < needed_len;i++)
                {
                    for(long int j = 0;j < size_of_matrix;j++)
                    {
                        pt_matrix[i][j]=filter_ascii(plain_text[inc]);
                        cout<<pt_matrix[i][j]<<" ";
                        inc++;
                    }
                    cout<<endl;
                }

                //calculating ct matrix by matrix multiplication and prlong inting it
                cout<<"\nCT matrix: \n";
                for(long int i = 0 ;i < needed_len;i++)
                {
                    for(long int j = 0;j < size_of_matrix;j++)
                    {
                        for(long int k = 0;k < size_of_matrix;k++)
                        {
                            ct_matrix[i][j]=ct_matrix[i][j]+(key_matrix[k][j]*pt_matrix[i][k]);
                        }
                        ct_matrix[i][j] = round(mod(ct_matrix[i][j],26));
                        cout<<ct_matrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;

                inc=0;
                cout<<"CT_text: ";
                for(long int i=0;i<needed_len;i++)
                {
                    for(long int j=0;j<size_of_matrix;j++)
                    {
                        cout<<(char)(ct_matrix[i][j]+65);
                        cipher_text[inc]=ct_matrix[i][j]+65;
                        inc++;
                    }
                }
                cout<<endl;
            } 
            else
            {
                //exception no pt input
                cout<<"No plain test"<<endl;
            } 
        }
        void decript_text()
        {
            //exception incase no inverse matrix can be made
            if(!inverse_made && strlen(cipher_text) == 0)
            {
                cout<<"No inverse matrix or cipher to decript with: \n";
            }
            else
            {
                // needed len and ct pt defining
                long int needed_len = ceil((float)strlen(cipher_text)/size_of_matrix),inc=0, ct_matrix[10][10],pt_matrix[10][10];

                //initializing 0 cause formula result is sum
                for(long int i=0;i<needed_len;i++)
                {
                    for(long int j=0;j<size_of_matrix;j++)
                    {
                        pt_matrix[i][j]=0; 
                    }
                }

                //if not enough char add X
                for(long int i=strlen(cipher_text);i<needed_len*size_of_matrix;i++)
                {
                    cipher_text[i] = (23+65);
                }

                //prlong inting edited text
                cout<<"The edited cipher text is:";
                for(long int i=0;i<needed_len*size_of_matrix;i++)
                {
                    cout<<cipher_text[i];
                }
                cout<<endl;

                //prlong inting matrix by filtering 
                cout<<"\nCt_matrix:\n";
                for(long int i=0;i<needed_len;i++)
                {
                    for(long int j=0;j<size_of_matrix;j++)
                    {
                        ct_matrix[i][j]=filter_ascii(cipher_text[inc]);
                        cout<<ct_matrix[i][j]<<" ";
                        inc++;
                    }
                    cout<<endl;
                }

                //matrix multiplication according to n*2  *  2*2
                cout<<"\nPT_text matrix: \n";
                for(long int i=0;i<needed_len;i++)
                {
                    for(long int j=0;j<size_of_matrix;j++)
                    {
                        for(long int k=0;k<size_of_matrix;k++)
                        {
                            pt_matrix[i][j]=pt_matrix[i][j]+(inverse_key[k][j]*ct_matrix[i][k]);
                        }

                        pt_matrix[i][j] = round(mod(pt_matrix[i][j],26));
                        cout<<pt_matrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;

                //converting from matrix to plain text
                inc=0;
                cout<<"PT_text: ";
                for(long int i=0;i<needed_len;i++)
                {
                    for(long int j=0;j<size_of_matrix;j++)
                    {
                        cout<<(char)(pt_matrix[i][j]+65);
                        plain_text[inc]=pt_matrix[i][j]+65;
                        inc++;
                    }
                }
                cout<<endl;
            }
        } 
//defining of class done     
}hill_cipher;

long int main()
{
    char choice;
    do
    {
        //call of processes according to need 
        hill_cipher.set_key();
        hill_cipher.set_plain_text();
        hill_cipher.encript_text();

        //not necessary if encriptionn performed
        hill_cipher.set_cipher_text();

        hill_cipher.decript_text();

        //condition for redoing the process
        cout<<"Do you want to redo the process[y/n]: ";
        cin>>choice;
    } 
    while (hill_cipher.filter_ascii(choice) == 24);
}
