#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    string choice = "y";
    int no_of_holes,no_of_processes,i,j,min_among_max_index,min;
    do{
        cout<<"Enter number of holes: ";cin>>no_of_holes;
        cout<<"Enter number of processes to allocate: ";cin>>no_of_processes;

        int processes[no_of_processes],holes[no_of_holes];

        cout<<"Enter The size of holes one by one: \n";
        for(i = 0 ; i < no_of_holes ; i++){  cout<<i+1<<": ";cin>>holes[i];}

        cout<<"Enter The size of process one by one: \n";
        for(i = 0 ; i < no_of_processes ; i++){  cout<<i+1<<": ";cin>>processes[i];   }
        
        for(i = 0 ; i < no_of_processes ; i++)
        {  
            min_among_max_index = -1;
            min = INT_MAX;
            for(j = 0 ; j < no_of_holes ; j++)
            {  
                if(processes[i] <= holes[j])
                {
                    if(holes[j]<min)
                    {
                        min = holes[j]; min_among_max_index = j;
                    }
                }     
            } 
            if (min_among_max_index != -1)
            {
                cout<<"Process "<<i+1<<" Fitted in hole "<<min_among_max_index + 1<<endl;
                holes[min_among_max_index] = holes[min_among_max_index] - processes[i];
            } 
        }

        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");
}
