#include<stdio.h>
#include<stdlib.h>
int max[10][10];
int alloc[10][10];
int need[10][10];
int avail[10];
int n, r;
int sq[10];
int work[10];
void input() 
{
    int i, j;
    printf("Enter the no of Processes : ");
    scanf("%d",&n);
    printf("Enter the no of resources instances : ");
    scanf("%d",&r);
    printf("Enter the Max Matrix\n");
    for (i=0;i<n;i++) 
    {
        for (j=0;j<r;j++) 
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i=0;i<n;i++) 
    {
        for (j=0;j<r;j++) 
        {
           scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the available Resources\n");
    for (j=0;j<r;j++) 
    {
        printf("For R[%d] : ",j+1);
        scanf("%d", &avail[j]);
    }
    printf("\n");
    
}
void show()
{
    printf("PID\tAlloc\tMax\tneed\n");
    for(int i=0; i<n; i++)
    {
        printf("P[%d]\t",i);
        for(int j=0;j<r;j++)
            printf("%d ",alloc[i][j]);
        printf("\t");
        for(int j=0;j<r;j++)
            printf("%d ",max[i][j]);
        printf("\t");
        for(int j=0;j<r;j++)
            printf("%d ",need[i][j]=(max[i][j]-alloc[i][j]));
        printf("\n");                 
    }
     printf("\n\nAvailable Array is : \n");
    for (int i=0;i<r;i++)
        printf("%d\t",avail[i]);
}
int safety()
{
    int finish[10];
    for(int i=0;i<r;i++)
    {
        work[i]=avail[i];
    }
    for(int i=0; i<n; i++)
        finish[i]=0;

    int proceed=1;
    int k=0;
    int c=0;
    while(proceed)
    {
        proceed=0;
        for(int i=0;i<n;i++)
        {
            int flag=1;
            if(finish[i]==0)
            {

                for(int j=0; j<r; j++)
                {
                    if(need[i][j] <= work[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    continue;
                for(int j=0; j<r; j++)
                    work[j]=work[j]+ alloc[i][j];
                finish[i]=1;
                sq[k++]=i;
                proceed=1;
            }
        }
    } 
    int i;
    for( i=0; i<n ; i++)
    {
       if(finish[i]==1)
           c++;
    }
}
void main()
{
    input();
    show();
    safety();
}

/*
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-1$ cc slot1.c
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-1$ ./a.out
Enter the no of Processes : 5
Enter the no of resources instances : 3
Enter the Max Matrix
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the Allocation Matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the available Resources
For R[1] : 10  
For R[2] : 5
For R[3] : 7

PID	    Alloc	Max	need
P[0]	0 1 0 	7 5 3 	7 4 3 
P[1]	2 0 0 	3 2 2 	1 2 2 
P[2]	3 0 2 	9 0 2 	6 0 0 
P[3]	2 1 1 	4 2 2 	2 1 1 
P[4]	0 0 2 	5 3 3 	5 3 1 

Available Array is : 
10	5	7	
*/


	


