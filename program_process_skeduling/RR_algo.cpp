#include<iostream>
using namespace std;
int main()
{
    string choice = "y";
    bool end_flag;
    int i,no_of_process,sum_burst_time,quantum = 0;
    float TTAT,TWT,TAT,WT ;
    do{

        TTAT = 0; TWT = 0 ;sum_burst_time = 0;end_flag = false;
        //defining matrix to store process no and burst time
        cout<<"\nEnter the number of processes: ";cin>>no_of_process;

        //index 0 = process no ,index 1 = burst time,index 2 = completed time
        int process[no_of_process][3];

        //taking input of burst time
        cout<<"Enter the burst time : \n";
        for (i=0;i<no_of_process;i++){ cout<<"Process "<<i+1<<": ";  cin>>process[i][1];   process[i][0]=i+1; process[i][2]=0;}

        cout<<"Enter the quantum : ";cin>>quantum;

        cout<<"\nRR process has following info\n";
        while(!end_flag)
        {
            end_flag = true;
            for(i = 0; i < no_of_process;i++ )
            {
                //Note that arrival time here is not taken as input thus arrival time =0
                //TAT = completion time - arrival time     WT = TAT - burst time
                if (process[i][1]-process[i][2] == 0){ }
                else if (process[i][1]-process[i][2] > quantum)
                {
                    sum_burst_time = sum_burst_time + quantum;
                    process[i][2] = process[i][2] + quantum;
                }
                else if (process[i][1]-process[i][2] <= quantum)
                {
                    sum_burst_time = sum_burst_time + process[i][1]-process[i][2];
                    process[i][2] = process[i][1];
                    TTAT = TTAT + sum_burst_time;
                    TWT = TWT + sum_burst_time - process[i][1];
                    cout<<"Process "<<process[i][0]<<" TAT = "<<sum_burst_time<<" Waiting time= "<<sum_burst_time - process[i][1]<<" burst time = "<<process[i][1]<<endl;
                }
            }
            for(i = 0; i < no_of_process;i++){  if((process[i][1] - process[i][2]) > 0 ){end_flag = false;}  }
        }
        cout<<"\nTotal turn around time = "<<TTAT<<" average  = "<<TTAT/no_of_process <<endl;
        cout<<"Total wait time time = "<<TWT<<" average  = "<<TWT/no_of_process <<endl;
        cout<<"\nDo you want to cntinue [y/n]: ";cin>>choice;

    }while(choice != "n");

}