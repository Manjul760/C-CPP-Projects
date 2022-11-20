#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    string choice = "y";
    int no_of_sequence,head,i,j,Total_movement,min_movement,index_min,temp;
    do{
        Total_movement = 0;
        cout<<"\nNote that the disk size is of 300 ie 0 to 299"<<endl;
        cout<<"Enter the number of sequene: "; cin>>no_of_sequence;
        int Disk_sequence[no_of_sequence];
        cout<<"Enter the initial position of head: "; cin>>head;
        cout<<"Enter the sequence:"<<endl;
        for(i=0;i<no_of_sequence;i++)
        { 
            cout<<i+1<<": ";
            cin>>Disk_sequence[i]; 
            if (Disk_sequence[i] > 299){Disk_sequence[i] = 299;}
            else if(Disk_sequence[i] < 0){Disk_sequence[i] = 0;}
        }

        cout<<"\nProcess of SSTF is:"<<endl;
        for(i=0;i<no_of_sequence;i++)
        {     
            index_min = i;
            min_movement = abs(head - Disk_sequence[i]);
            for(j = no_of_sequence - 1;j >=i;j--)
            {
                if(abs(head - Disk_sequence[j]) <= min_movement)
                {
                    index_min = j;
                    min_movement = abs(head - Disk_sequence[j]);
                }
            }
            cout<<"Head position = "<<head<<" Movement = "<<abs(head - Disk_sequence[index_min]);
            head = Disk_sequence[index_min];
            cout<<" Going to = "<<head<<endl;
            Total_movement = Total_movement + min_movement;
            temp = Disk_sequence[i];
            Disk_sequence[i] = Disk_sequence[index_min];
            Disk_sequence[index_min] = temp;
            

        }
        cout<<"Final head position = "<<head;
        cout<<"\nTotal movement = "<<Total_movement<<endl;
        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");

}