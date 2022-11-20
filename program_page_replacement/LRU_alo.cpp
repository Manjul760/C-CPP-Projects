#include<iostream>
using namespace std;

int main()
{
    string choice = "y";
    int no_of_sequence,i,j,frame_size,hit,max_stay_time,max_stay_index;
    bool exist;
    do{
        hit = 0;
        cout<<"Note that -1 means empty page and page number starts from 0: "<<endl;
        cout<<"Enter the length of page sequence: ";cin>>no_of_sequence;
        
        int page_sequence[no_of_sequence];
        cout<<"Enter the frame size: ";cin>>frame_size;
        //index 0 = page no  index 1 = stay time
        int frame[frame_size][2];
        cout<<"Enter the page sequence linearly with space: ";
        for(i = 0 ; i < no_of_sequence ; i++){cin>>page_sequence[i]; if(page_sequence[i] < 0 ){page_sequence[i]=0;} }
        for(j = 0 ; j < frame_size ; j ++){ frame[j][0] = -1;frame[j][1] = 0; }

        cout<<"The process of LRU involves: "<<endl;
        for(i = 0 ; i < no_of_sequence ; i++)
        { 
            for(j = 0 ; j < frame_size ; j ++){if(frame[j][0] == page_sequence[i]){exist = true;max_stay_index=j;break;}else{exist = false;}}
            if(!exist)
            {
                max_stay_time = -1;max_stay_index = -1;
                for(j = 0 ; j < frame_size ; j ++)
                {  
                    if(frame[j][0] == -1)
                    {
                        max_stay_index = j;
                        break;
                    }
                    if(frame[j][1] > max_stay_time)
                    {
                        max_stay_time = frame[j][1];max_stay_index = j;
                    }
                }
                frame[max_stay_index][0]=page_sequence[i];
                frame[max_stay_index][1]=0;
                cout<<"Sequence "<<i+1<<":";
                for(j = 0 ; j < frame_size ; j ++) { cout<<" "<<frame[j][0]; }
                cout<<endl;

            }
            else
            {
                cout<<"Sequence "<<i+1<<":";
                for(j = 0 ; j < frame_size ; j ++) { cout<<" "<<frame[j][0]; }
                cout<<" hit"<<endl;
                frame[max_stay_index][1]=0;
                hit++; 
            }
            for(j = 0 ; j < frame_size ; j ++){frame[j][1] = frame[j][1] + 1;}
        }
        cout<<"\nPage hit = "<<hit<<" Page fault = "<<no_of_sequence - hit<<endl;
        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");
}

