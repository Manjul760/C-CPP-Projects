#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    string choice = "y";bool All_greater_or_equal,All_zero;
    int no_of_processes,no_of_resource,i,j,k,sequence_index;
    do{
        cout<<"\nEnter the number of processes: ";cin>>no_of_processes;
        cout<<"Enter the number of resources: ";cin>>no_of_resource;cout<<endl;
        int processes_hold[no_of_processes][no_of_resource], processes_need[no_of_processes][no_of_resource];
        int sequence[no_of_processes],effective_number[no_of_processes][no_of_resource],avilable[no_of_resource];
        for(i = 0 ; i < no_of_processes ; i++)
        {
            cout<<"Enter the recourses held by Process "<<i+1<<" in a line: "<<endl;
            for(j = 0 ; j < no_of_resource ; j++){cin>>processes_hold[i][j];}
            cout<<"Enter the recourses needed by Process "<<i+1<<" in a line: "<<endl;
            for(j = 0 ; j < no_of_resource ; j++){cin>>processes_need[i][j];}
            for(j = 0 ; j < no_of_resource ; j++){effective_number[i][j] = processes_need[i][j] - processes_hold[i][j];}
            cout<<endl;
        }
        cout<<"Enter the avilable resources: "<<endl;
        for(j = 0 ; j < no_of_resource ; j++){cin>>avilable[j];} sequence_index = 0 ;
        for (k = 0 ; k < no_of_processes ; k++)
        {
            for(i = 0 ; i < no_of_processes ; i++)
            {   
                All_zero = true;All_greater_or_equal = true;
                for(j = 0 ; j < no_of_resource ; j++)
                {
                    if(avilable[j] < effective_number[i][j]){ All_greater_or_equal = false;  }
                    if(effective_number != 0){All_zero = false;}
                }
                if(All_greater_or_equal && !All_zero)
                {
                    for(j = 0 ; j < no_of_resource ; j++)
                    {   
                        avilable[j] = avilable[j] + processes_hold[i][j]; processes_hold[i][j] = 0;
                        processes_need[i][j] = 0; effective_number[i][j] = 0;
                    }
                    All_greater_or_equal = false;
                    for(j = 0 ; j <sequence_index; j ++){if(sequence[j] == i){All_greater_or_equal = true;}}
                    if (!All_greater_or_equal){ sequence[sequence_index] = i;  sequence_index++; }      
                }
            }
        }
        All_zero = true;
        for(i = 0 ; i < no_of_processes ; i++)
        {   for(j = 0 ; j < no_of_resource ; j++)
            { if(effective_number[i][j] != 0){All_zero = false;} }
        }
        if(All_zero)
        {
            cout<<"\nNo deadlock occurs the sequence is:";
            for(i = 0 ; i < sequence_index ; i++)
            {   if(i<sequence_index-1){ cout<<"P"<<sequence[i]+1<<"->";}
                else{ cout<<"P"<<sequence[i]+1 <<endl; } 
            }
        }
        else{ cout<<"Deadlock occred!!!"<<endl;  }
        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");
}
