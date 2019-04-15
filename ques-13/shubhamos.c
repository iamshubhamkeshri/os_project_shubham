#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
void result();
struct Processes
{
	int P_ID; 
	int prio;
	int BT;
	int AT;
	int WT;
};
int main()
{
	int i,y,j,k[3],p_zero=0;
	float avg_wt=0,avg_tt=0;
	printf("\t\t\t\tProject of operating system\n");
	printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("\t\t\t\tNAME->SHUBHAM KESHRI\n\n");
	printf("Range of priority\t\t\tLimits\n\n");
	printf("QUEUE1-Lowest priority range\t\t1-10\t\t(FIFO)\n");
	printf("QUEUE2-Middle priority range\t\t11-20\t\t(Priority Sheduling) priority increases from  11 to 20\n");
	printf("QUEUE3-Highest priority range\t\t21-30\t\t(Round Robin Sheduling Time quantum=4 sec)\n\n");
	printf("Round Robin with Time quantum=10 between each Queues\n\n");
	printf("NOTE: CPU cannot be idle\n\n");
	int n;
	printf("Enter the number of the processes :");
	scanf("%d",&n);
	int p[n],burst[n],arr[n],fifosave[n],pssave[n],rrsave[n];
	struct Processes fifo[n],ps[n],rr[n];
	for(i=0;i<n;i++)
	{
		printf("\n\n ID of the process is:%d",(i+1));
		printf("\nEnter Priority of process :");
		scanf("%d",&p[i]);
		printf("Enter ARRIVAL Time of process :");
		scanf("%dArival Time :",&arr[i]);
		printf("Enter Burst Time of process :");
		scanf("%d",&burst[i]);
		
	}
	int l;
	for( l=0;l<n;l++)
	{
		if(arr[l]==0)
		    p_zero++;
	}
	if(p_zero==0)
	{
		printf("\n\n\t\tCPU is idle at time 0");
	}
	else
	{
	k[1]=0;k[2]=0;k[3]=0;
	for( i=0;i<n;i++)
	{
		 if(p[i]<=10&&p[i]>0)
		      { 
			  fifo[k[1]].P_ID=i+1;
		      fifo[k[1]].prio=p[i];
		      fifo[k[1]].BT=burst[i];
		      fifosave[k[1]]=fifo[k[1]].BT;
		      fifo[k[1]].AT=arr[i];
			  k[1]++;
			  }
		 else if(p[i]>=11&&p[i]<=20) 
		      {
			  ps[k[2]].P_ID=i+1; 
		      ps[k[2]].prio=p[i];
		      ps[k[2]].BT=burst[i];
		      pssave[k[2]]=ps[k[2]].BT;
		      ps[k[2]].AT=arr[i];
		      k[2]++;
			  }
		 else if(p[i]>=21&&p[i]<=30) 
		      {
			  rr[k[3]].P_ID=i+1; 
		      rr[k[3]].prio=p[i];
		      rr[k[3]].BT=burst[i];
		      pssave[k[2]]=ps[k[2]].BT;
		      rr[k[3]].AT=arr[i];
		      k[3]++;
			  }     
	}
	printf("\nQUEUE1---Lowest priority range Queue (",k[1]);
	printf(" Process)\t(FIFO)\n");
	if(k[1]==0)
		printf("No process in this priority range 0-5\n\n");
	else
	{
		printf("PID | Priority | ARRIVAL Time | Burst Time\n");
		int j;
	    for(j=0;j<k[1];j++)
		{
		 	printf("\n",fifo[j].P_ID);
			 printf("\t",fifo[j].prio);printf("\t\t",fifo[j].AT);
			 printf("\t",fifo[j].BT);
			 printf("\n");
		}
    }
	printf("\nQUEUE2---Middle priority range Queue (",k[2]);
	printf(" process)\t(Priority Sheduling)\n");
	if(k[2]==0)
	    printf("No process in this priority range 5-10\n\n");
	else
	{
	    printf("PID | Priority | ARRIVAL Time | Burst Time\n");
		for( j=0;j<k[2];j++)
	    {
		 	printf(" ",ps[j].P_ID);
		 	 printf("\t",ps[j].prio);
		 	 printf("\t\t",ps[j].AT);
		 	 printf("\t",ps[j].BT);
		}
	} 
	printf("\n\nQUEUE3---Highest priority range Queue  (",k[3]);
	printf(" process) (Round Robin scheduling)\n");
	if(k[3]==0)
		printf("No process in this priority range 10-15\n\n");
    else
    {
		printf("PID | Priority | ARRIVAL Time | Burst Time\n");
		for( j=0;j<k[3];j++)
		 {
		 	 printf("rr[j].P_ID");
		 	 printf("\t",rr[j].prio);
		 	 printf("\t\t",rr[j].AT);
		 	 printf("\t",rr[j].BT);
		}	
	}  
	int o=0;
	int m,t=0,imp=0,Queuecount=0,Qsize=0,flag[k[1]],flag1[k[2]],flag2[k[3]],sig=0,sig1=0,sig2=0;
	int Q[3];
	
	 for( m=0;m<3;m++)
    {  
	    Q[m]=1;
    }
    for(m=0;m<k[1];m++)
    {  
	    flag[m]=1;
	    fifo[j].WT=0;
    }
    for(m=0;m<k[2];m++)
    {  
	    flag1[m]=1;
    }
    for(m=0;m<k[3];m++)
    {  
	    flag2[m]=1;
    }
    struct Processes c;  //sorting QUEUE2 according to the priority 
		    	int u;for( u=0;u<k[2];u++)
		    	{
		    		int r;for( r=u;r<k[2];r++)
		    		{
		    		if(ps[u].prio<ps[r].prio)
		    		{
		    			c=ps[u];
		    			ps[u]=ps[r];
		    			ps[r]=c;
		    		}
				  }
				}
    struct Processes c1;  //sorting QUEUE1 according to the ARRIVAL time
	for(u=0;u<k[1];u++)
	{
		int r; for( r=u;r<k[1];r++)
		{
		    if(fifo[u].AT>fifo[r].AT)
		    {
		    	c1=fifo[u];
		    	fifo[u]=fifo[r];
		    	fifo[r]=c1;
		    }
		}
	}
	struct Processes c2; //sorting QUEUE2 according to the ARRIVAL time
		    	for(u=0;u<k[3];u++)
		    	{
		    		 int r;       for( r=u;r<k[3];r++)
		    		        {
		    		          if(rr[u].AT>rr[r].AT)
		    		           {
		    		            	c2=rr[u];
		    		            	rr[u]=rr[r];
		    		            	rr[r]=c2;
		    		         }
				             }
				}			
	printf("\n\nSHEDULING :(please wait(10 sec) after gantt chat to see turnaround time and waiting time of each process)\n\n");
	int pro=0,pro1=0,pro2=0;
	while(t<=90)
	{	
    if(Q[imp]==0)
	{
		for( m=0;m<3;m++)
	    {
	        if(Q[m]==0)
		    {
		   	    Queuecount++;
		    }
	    }
        	if(Queuecount==3)
	        { 
	            break;
	            break;
	        }  
	        }
  else{
	switch(imp)
	{
		case 2:
		    {
		    	//Lowest priority range Queue
		    	int count=0;	
        	    int e=t+10;
        	    if(k[1]==0){
        	    	Q[2]=0;
        	    	break;
			    }
        	  else{
           	  while(t<=e)
	          {		
	              if(flag[pro]==0)
				  {
		          for( m=0;m<k[1];m++)
	              {
	        	         if(flag[m]==0)
		                 {
		   	                    count++;
		                 }
	              }
        	      if(count==k[1])
	              { 
	                     Q[2]=0; 
	                     break;
	              }  
	              }
	              else
	              {	
	                   fifo[pro].WT+=(t-fifo[pro].WT);
	                   if(fifo[pro].AT>t)
					   {
					   	   sig++;
						} 
	                   else if(fifo[pro].AT<=t)
	                   {	
             		   int remtime=fifo[pro].BT;
             		   if((t+remtime)>e && remtime>0)
             		   {
             		   	  int h=t+remtime;
					      remtime=h-e;
						  fifo[pro].BT=remtime;		   
             		   	  printf("\tQUEUE1\tp",fifo[pro].P_ID);
	   					  printf( "process from ",t);
	   					  printf("---(sec/n)",(e));
             		   	  t=e;
             		   	  break;
						}
             		    else if(remtime<=10)
					    {
					     
					     printf("\tQUEUE1\tp",fifo[pro].P_ID);
	   					  printf( "process from ",t);
	   					  printf("---(sec/n)",(t+remtime));
					     flag[pro]=0;
					     t+=remtime;
					     fifo[pro].BT=0;
					   }
					   else if(remtime>10)
					   {
					   	  
					   	  printf("\tQUEUE1\tp",fifo[pro].P_ID);
	   					  printf( "process from ",t);
	   					  printf("---(sec/n)",(t+10));
					   	  t=t+10;
					      fifo[pro].BT-=10;
					   }   
             		  }
             		  if(sig==k[1])
             		  { break;
					   }
             		    sleep(1);
    					pro++;
    					pro=pro%k[1];}
    					
				}
		     }
		    }   
		    break;	
	    case 1:
		    {
		    	//Middle priority range Queue
		    	int count=0;
		    	 int e=t+10;
        	  if(k[2]==0){
        	  	Q[1]=0;
			  }
        	  else{
           	  while(t<=e)
	          {		
	              if(flag1[pro1]==0)
				  {
		          for( m=0;m<k[2];m++)
	              {
	        	         if(flag1[m]==0)
		                 {
		   	                    count++;
		                 }
	              }
        	      if(count==k[2])
	              { 
	                     Q[1]=0; 
	                     break;
	                     break;
	              }  
	              }
	              else
	              {	
	                  ps[pro1].WT+=(t-ps[pro1].WT);
	                  if(ps[pro1].AT>t)
					   {
					   	   sig1++;
						} 
	                  else if(ps[pro1].AT<=t)
	                   {
	                  int QTime=10;
             		   int remtime=ps[pro1].BT;
             		   if(t+remtime>e && remtime>0)
             		   {
             		   	  int h=t+remtime;
					      remtime=h-e;
						  ps[pro1].BT=remtime;		   
             		   	  printf("\tQUEUE2\tp",ps[pro1].P_ID);
	   					  printf( "process from ",t);
	   					  printf("---(sec/n)",(e));
             		   	  t=e;
             		   	  break;
             		   	
						}
             		   
					   else if(remtime<=10)
					   {
					     
					     printf("\tQUEUE2\tp",ps[pro1].P_ID);
	   					  printf( "process from ",t);
	   					  printf("---(sec/n)",(t+remtime));
					     flag1[pro1]=0;
					     t+=remtime;
					     ps[pro1].BT=0;
					   }
					   else if(remtime>10)
					   {
					   	  
					   	  printf("\tQUEUE2\tp",ps[pro1].P_ID);
	   					  printf( "process from ",t);
	   					  printf("---(sec/n)",(t+10));
					      ps[pro1].BT-=10;
					      t=t+10;
					   }    	    
	              
	              }}
	              if(sig1==k[2])
             		  { break;
					   }
	                sleep(1);
    					pro1++;
    					pro1=pro1%k[2];
    		        	}	
			         }  
			        
		        }
		        break;
		case 0:
			{
				//Highest priority range Queue
			  int count=0;	
         	  int e=t+10;
        	  if(k[3]==0){
        	  	Q[0]=0;
			  }
        	  else{
           	  while(t<=e)
	          {		
	              if(flag2[pro2]==0)
				  {
		          for( m=0;m<k[3];m++)
	              {
	        	         if(flag2[m]==0)
		                 {
		   	                    count++;
		                 }
	              }
        	      if(count==k[3])
	              { 
	                     Q[0]=0;
	                     break;
	                     break;
	               }  
	              }
	              else
	              {	
	                  rr[pro2].WT+=(t-rr[pro2].WT);
	                  if(rr[pro2].AT>t)
					   {
					   	   sig2++;
						} 
	                    if(rr[pro2].AT<=t)
	                   { 
             			int timeq=4;
	            		int remtime=rr[pro2].BT;   
	            		if((t+remtime)>e && remtime>0 && remtime<=4)
	          			{  
	                 		int h=t+remtime;
	                 		remtime=h-e; 
	                 		rr[pro2].BT=remtime;
	                 		printf("\tQUEUE3\tp",rr[pro2].P_ID);
	   						printf( "process from ",t);
	   						printf("---(sec/n)",(e));
	                 		t=e;
	                  		break;
	           			}    
	           			else if(remtime<=timeq)
	            		{   	 
	                    	printf("\tQUEUE3\tp",rr[pro2].P_ID);
	   						printf( "process from ",t);
	   						printf("---(sec/n)",(t+remtime));
	                    	t+=remtime;
	                    	rr[pro2].BT=0;
		                	flag2[pro2]=0;
	            		}
	                    else
	  					{	
	   						 printf("\tQUEUE3\tp",rr[pro2].P_ID);
	   						 printf( "process from ",t);
	   						 printf("---(sec/n)",(t+timeq));
	     					 rr[pro2].BT-=timeq;
	     					 t+=timeq;
       					}
                        }}
                        if(sig2==k[3])
             		   { break;
					   }
                        sleep(1);
    					pro2++;
    					pro2=pro2%k[3];
    					break;
    			}
			} 
			}
			
            
		
	}
   
     }    
 
imp++;
imp=imp%3;
}
printf("\n");
for(j=0;j<k[1];j++)
{   
    printf("\n\nQUEUE1:p",fifo[j].P_ID);
    if(j!=0){

		printf("\nWaiting Time(sec/n)\t=",(fifo[j].WT-fifo[j-1].AT-fifo[j].AT));
		printf("Turnaround time(sec\n)\t=",((fifo[j].WT-fifo[j-1].AT-fifo[j].AT)+fifosave[j]));
		avg_wt+=(fifo[j].WT-fifo[j-1].AT-fifo[j].AT);
		avg_tt+=((fifo[j].WT-fifo[j-1].AT-fifo[j].AT)+fifosave[j]);
		}
		else{
		printf("Waiting Time(sec/n)\t=",(fifo[j].WT));
		printf("Turnaround time(sec\n)\t=",(fifo[j].WT+fifosave[j]));
		avg_wt+=(fifo[j].WT);
		avg_tt+=(fifo[j].WT+fifosave[j]);
		}
}
for(j=0;j<k[2];j++)
{   
    printf("\n\nQUEUE2:p",ps[j].P_ID);
    if(j!=0){

		printf("\nWaiting Time(sec/n)\t=",(ps[j].WT-ps[j-1].AT-ps[j].AT));
		printf("Turnaround time(sec\n)\t=",((ps[j].WT-ps[j-1].AT-ps[j].AT)+pssave[j]));
		avg_wt+=(ps[j].WT-ps[j-1].AT-ps[j].AT);
		avg_tt+=((ps[j].WT-ps[j-1].AT-ps[j].AT)+pssave[j]);
		}
		else{
		printf("Waiting Time(sec/n)\t=",(ps[j].WT));
		printf("Turnaround time(sec/n)\t=",(ps[j].WT+pssave[j]));
		avg_wt+=(ps[j].WT);
		avg_tt+=(ps[j].WT+pssave[j]);
		}
}
for( j=0;j<k[3];j++)
{   
    printf("\n\nQUEUE3:p",rr[j].P_ID);
    if(j!=0)
	{

		printf("/nWaiting Time(sec/n)\t=",(rr[j].WT-rr[j-1].AT-rr[j].AT));
		printf("Turnaround time(sec/n)\t=",((rr[j].WT-rr[j-1].AT-rr[j].AT)+rrsave[j]));
		avg_wt+=(rr[j].WT-rr[j-1].AT-rr[j].AT);
		avg_tt+=((rr[j].WT-rr[j-1].AT-rr[j].AT)+rrsave[j]);
		}
		else{
		printf("Waiting Time(sec/n)\t=",(rr[j].WT));
		printf("Turnaround time(sec/n)\t=",(rr[j].WT+rrsave[j]));
		avg_wt+=(rr[j].WT);
		avg_tt+=(rr[j].WT+rrsave[j]);
		}
}
printf("\nAverage waiting time (sec\n)): ",(avg_wt/n));
printf("\nAverage Turnaround time (sec\n): ",(avg_tt/n));
printf("THE PROGRAM IS OVER");
return 0;
}
}
