#include<iostream>
using namespace std;
int main()
{
    //basic definitions
    string choice = "y";
    int no_of_process,i,min,idx_min,j,temp_process_no,temp_burst_time,sum_burst_time;
    float TTAT,TWT,TAT ,WT ;
    do{
        TTAT = 0; TWT = 0 ;sum_burst_time = 0;
        //defining matrix to store process no and burst time
        cout<<"\nEnter the number of processes: ";cin>>no_of_process;
        int process[no_of_process][2];

        //taking input of burst time
        cout<<"Enter the burst time : \n";
        for (i=0;i<no_of_process;i++) { cout<<"Process "<<i+1<<": ";  cin>>process[i][1];   process[i][0]=i+1;}

        //sorting using bubble sort
        for (j=0;j<no_of_process;j++)
        {
            min = process[j][1];idx_min = j;
            for(i = no_of_process-1;i>=j;i--) {  if(min>=process[i][1]){min = process[i][1];idx_min = i;} }
            if (idx_min != j )
            {
                temp_burst_time = process[idx_min][1];
                temp_process_no = process[idx_min][0];

                process[idx_min][1] = process[j][1];
                process[idx_min][0] = process[j][0];

                process[j][1] = temp_burst_time ;
                process[j][0] = temp_process_no ;
            }
        }

        //calculating the burst time and turn around time
        cout<<"\nSJB process has following info\n";
        for (i=0;i<no_of_process;i++) 
        {    
            sum_burst_time = sum_burst_time + process[i][1];

            //Note that arrival time here is not taken as input thus arrival time =0
            //TAT = completion time - arrival time     WT = TAT - burst time
            TAT = sum_burst_time;   WT = sum_burst_time - process[i][1];

            TTAT = TTAT + TAT;  TWT = TWT + WT;

            cout<<"Process "<<process[i][0]<<" BT = "<<process[i][1]<<" TAT = "<<TAT<<" WT = "<<WT<<endl;
        }
        cout<<"\nTotal turn around time = "<<TTAT<<" average  = "<<TTAT/no_of_process <<endl;
        cout<<"Total wait time time = "<<TWT<<" average  = "<<TWT/no_of_process <<endl;
        
        cout<<"\nDo you want to cntinue [y/n]: ";cin>>choice;
    }while(choice != "n");
}