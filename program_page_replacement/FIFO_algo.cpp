#include<iostream>
using namespace std;

int main()
{
    string choice = "y";
    int no_of_sequence,i,j,frame_size,hit,sequence_fallback;
    bool exist;
    do{
        hit = 0,sequence_fallback = 0;
        cout<<"Note that -1 means empty page and page number starts from 0: "<<endl;
        cout<<"Enter the length of page sequence: ";cin>>no_of_sequence;
        int page_sequence[no_of_sequence];
        cout<<"Enter the frame size: ";cin>>frame_size;
        int frame[frame_size];
        cout<<"Enter the page sequence linearly with space: ";
        for(i = 0 ; i < no_of_sequence ; i++){cin>>page_sequence[i]; if(page_sequence[i] < 0 ){page_sequence[i]=0;} }
        for(j = 0 ; j < frame_size ; j ++){ frame[j] = -1; }

        cout<<"The process of FIFO involves: "<<endl;
        for(i = 0 ; i < no_of_sequence ; i++)
        { 
            for(j = 0 ; j < frame_size ; j ++){if(frame[j] == page_sequence[i]){exist = true;break;}else{exist = false;}}

            if(!exist)
            {
                cout<<"Sequence "<<i+1<<":";
                frame[(i-sequence_fallback)%frame_size] = page_sequence[i];
                for(j = 0 ; j < frame_size ; j ++) { cout<<" "<<frame[j]; }
                cout<<endl;
            }
            else
            {
                cout<<"Sequence "<<i+1<<":";
                for(j = 0 ; j < frame_size ; j ++) { cout<<" "<<frame[j]; }
                cout<<" hit"<<endl;
                hit++;  sequence_fallback++;
            }

        }
        cout<<"\nPage hit = "<<hit<<" Page fault = "<<no_of_sequence - hit<<endl;
        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");
}

