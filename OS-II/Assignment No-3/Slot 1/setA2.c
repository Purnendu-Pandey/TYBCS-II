#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,n,initial,total=0,min,index,temp,dist,j;
     printf("Enter no. of disk req. : ");
     scanf("%d",&n);
     int req[n];
     printf("Enter disk request queue :\n");
     for (i=0;i<n;i++)
          scanf("%d",&req[i]);
     printf("Enter initial head position : ");
     scanf("%d",&initial);
     for (i=0;i<n;i++)
     {
          min= abs(req[i]-initial);
          index = i;
          for (j=i+1;j<n;j++)
          {
              dist = abs(req[j]-initial);
              if (dist<=min)
              {
                 min=dist;
                 index=j;
              }
          }
          total+=min;
          temp=req[i];
          req[i]=req[index];
          req[index]=temp;
          initial=req[i];
     }
     printf("Total head movements : %d\n",total);          
}
/*
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-3/Slot 1$ cc setA2.c
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
Enter initial head position : 53
Total head movements : 236
*/

