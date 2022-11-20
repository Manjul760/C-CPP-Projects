#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    string choice = "y"; bool end_flag;
    int no_of_sequence,prev_head,head,i,j,Total_movement,init_value,index,temp,increment,min=299,max=0;
    do{
        Total_movement = 0;end_flag = false;
        cout<<"\nEnter the number of sequene: "; cin>>no_of_sequence;
        int Disk_sequence[no_of_sequence][2];
        cout<<"Enter the initial position of head: "; cin>>head;
        cout<<"Enter the previous position of head: "; cin>>prev_head;
        cout<<"Note that the disk size is of 300 ie 0 to 299"<<endl;
        cout<<"Enter the sequence:"<<endl;
        for(i=0;i<no_of_sequence;i++)
        { 
            cout<<i+1<<": ";  cin>>Disk_sequence[i][0];  Disk_sequence[i][1] = 0;
            if(Disk_sequence[i][0] > max){ max = Disk_sequence[i][0]; }
            if(Disk_sequence[i][0] < min){ min = Disk_sequence[i][0]; }
            if (Disk_sequence[i][0] > 299){Disk_sequence[i][0] = 299;}
            else if(Disk_sequence[i][0] < 0){Disk_sequence[i][0] = 0;}
        }
        if(prev_head - head < 0){increment = 1;}else{increment = -1;}
        init_value =  head;
        cout<<"\nProcess of CLOOK is:"<<endl;
        while(!end_flag)
        {
            if (head == max && increment == 1)
            {
                Total_movement = Total_movement + abs(init_value - max) + abs(max-min) ;
                head = min-1;
                init_value = min;
            } 
            else if(head == min && increment == -1)
            {
                Total_movement = Total_movement + abs(init_value - min)+abs(max-min);
                head = max+1;
                init_value = max;
            }
            head = head + increment; end_flag = true;
            for(i=0;i<no_of_sequence;i++)
            {    
                if(Disk_sequence[i][0] == head && Disk_sequence[i][1] != 1)
                {
                    Disk_sequence[i][1] = 1;
                    cout<<"complete = "<<Disk_sequence[i][0]<<endl;
                } 
            }
            for(i=0;i<no_of_sequence;i++)
            { 
                if(Disk_sequence[i][0] > max && Disk_sequence[i][1] != 1){ max = Disk_sequence[i][0]; }
                if(Disk_sequence[i][0] < min && Disk_sequence[i][1] != 1){ min = Disk_sequence[i][0]; }
            }
            for(i=0;i<no_of_sequence;i++) { if(Disk_sequence[i][1] == 0) { end_flag = false;  }   }
            if (end_flag){ Total_movement= Total_movement + abs(head - init_value);  }
        }
        cout<<"Final head position = "<<head;
        cout<<"\nTotal movement = "<<Total_movement<<endl;
        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");
}