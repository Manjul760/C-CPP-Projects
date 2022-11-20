#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    string choice = "y";
    int no_of_sequence,head,i,Total_movement;
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

        cout<<"\nProcess of FCFS is:"<<endl;
        for(i=0;i<no_of_sequence;i++)
        { 
            cout<<"Head position = "<<head<<" Movement = "<<abs(head - Disk_sequence[i]);
            Total_movement = Total_movement + abs(head - Disk_sequence[i]); 
            head = Disk_sequence[i]; 
            cout<<" Going to = "<<head<<endl;

        }
        cout<<"Final head position = "<<head;
        cout<<"\nTotal movement = "<<Total_movement<<endl;
        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");

}