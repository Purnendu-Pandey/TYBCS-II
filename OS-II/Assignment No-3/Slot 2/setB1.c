#include<stdio.h>
#include<stdlib.h>
int main()
{
	int q[100],j,n,i,seek=0,max,head,move;
	printf("Enter the number of request: ");
	scanf("%d",&n);
	printf("Enter the request sequence: ");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
		
	printf("Enter initial head position: ");
	scanf("%d",&head);
	printf("Enter total disk size: ");
	scanf("%d",&max);
	printf("Enter the head movement direction for high 1 and for low 0: ");
	scanf("%d",&move);
	
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n-i-1;j++)
	   {
	       if(q[j]>q[j+1])
	       {
		  int temp;
 		  temp=q[j];
		  q[j]=q[j+1];
	          q[j+1]=temp;
	       }
	    }
	}
	int index;
	for(i=0;i<n;i++)
	{
	   if(head<q[i])
	   {
	       index=i;
	       break;
	   }
	}
	printf("Sequence of head movement: ");
	if(move==1)
	{
	    printf("%d\t",head);
	    for(i=index;i<n;i++)
	    {
		seek+=abs(q[i]-head);
		head=q[i];
		printf("%d\t",q[i]);
	    }
	    seek+=abs(max-q[i-1]-1);
	    head=max-1;
	    printf("%d\t",head);
	    for(i=index-1;i>=0;i--)
	    {
		seek+=abs(q[i]-head);
		head=q[i];
		printf("%d\t",q[i]);
	    }
	}
	else
	{
	     printf("%d\t",head);
	     for(i=index-1;i>=0;i--)
	     {
		seek+=abs(q[i]-head);
		head=q[i];
		printf("%d\t",q[i]);
	     }
	     seek+=abs(q[i+1]-0);
	     head=0;
	     printf("%d\t",head);
	     for(i=index;i<n;i++)
	     {
		seek+=abs(q[i]-head);
		head=q[i];
		printf("%d\t",q[i]);
	     }
	}
	printf("\n\n Total head movement are %d",seek);
	return 0;
}
/*
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 2$ cc setB1.c
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 2$ ./a.out
Enter the number of request: 8
Enter the request sequence: 98
183 
41 
122
14
124
65
67
Enter initial head position: 53
Enter total disk size: 200
Enter the head movement direction for high 1 and for low 0: 1
Sequence of head movement: 53	65	67	98	122	124	183	199	41	14	
Total head movement are 331

ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 2$ cc setB1.c
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 2$ ./a.out
Enter the number of request: 8
Enter the request sequence: 98
183
41 
122
14
124  
65
67
Enter initial head position: 53
Enter total disk size: 200
Enter the head movement direction for high 1 and for low 0: 0
Sequence of head movement: 53	41	14	0	65	67	98	122	124	183	
Total head movement are 236
*/
