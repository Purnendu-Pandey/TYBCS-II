#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,n,init,total=0;
     printf("Enter no. of disk req. : ");
     scanf("%d",&n);
     int req[n];
     printf("Enter disk req queue : ");
     for (i=0;i<n;i++)
          scanf("%d",&req[i]);
     printf("enter initial head position : ");
     scanf("%d",&init);
     for (i=0;i<n;i++)
     {
          total+=abs(req[i]-init);
          init=req[i];
     }
     printf("total head movements : %d",total);          
}
/*
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 1$ cc setA1.c
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 1$ ./a.out
Enter no. of disk req. : 8
Enter disk req queue : 
98
183
41
122
14
124
65 
67
enter initial head position : 53
total head movements : 632
*/
