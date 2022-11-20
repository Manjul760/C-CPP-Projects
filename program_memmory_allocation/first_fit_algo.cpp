#include<iostream>
using namespace std;

int main()
{
    string choice = "y";
    int no_of_holes,no_of_processes,i,j;
    do{
        cout<<"Enter number of holes: ";cin>>no_of_holes;
        cout<<"Enter number of processes to allocate: ";cin>>no_of_processes;

        int processes[no_of_processes],holes[no_of_holes];

        cout<<"Enter The size of holes one by one: \n";
        for(i = 0 ; i < no_of_holes ; i++){  cout<<i+1<<": ";cin>>holes[i];   }

        cout<<"Enter The size of process one by one: \n";
        for(i = 0 ; i < no_of_processes ; i++){  cout<<i+1<<": ";cin>>processes[i];   }
        
        for(i = 0 ; i < no_of_processes ; i++)
        {  
            for(j = 0 ; j < no_of_holes ; j++)
            {  
                if(processes[i] <= holes[j])
                {
                    cout<<"Process "<<i+1<<" Fitted in hole "<<j+1<<endl;
                    holes[j] = holes[j] - processes[i];
                    break;
                } 
                
            }   
        
        }

        cout<<"\nDo you want to continue [y/n]: ";cin>>choice;
    }while(choice != "n");
}

