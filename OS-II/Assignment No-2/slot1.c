#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bv[50],i,st,j,len,c,k;
char name[10][30];
int start[10],length[10],num=0;

void displayBitVector()
{
     printf("\nBit Vector contents :\n");
     for (i=0;i<50;i++)
          printf("%d ",bv[i]);
}
void createFile()
{
     char temp[30];
     printf("Enter the name of file : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
          if (strcmp(name[i],temp)==0)
          {
              printf("\nFilename already exists");
              return;
          } 
     strcpy(name[num],temp);
     printf("Enter the start block of the file : ");
     scanf("%d",&start[num]);
     printf("Enter the length of the file : ");
     scanf("%d",&length[num]);
     
     for (j=start[num];j<(start[num]+length[num]);j++)
          if (bv[j]==0)
          {
              printf("File cannot be allocated.... block already allocated");
              strcpy(name[j],"-");
              start[j]=0;
              length[j]=0;
              return;
          }
     for (j=start[num];j<(start[num]+length[num]);j++)
     {
          bv[j]=0;
          printf("\n%d->%d",j,bv[j]);
     }
     num++;
}
void showDirectory()
{
      printf("Directory contents\n");
      printf("%s%s%s\n","File Name","Start Block","Length");
      int i;
      for (i=0;i<num;i++)
      {
           if (strcmp(name[i],"-")!=0)
           {
               printf("  %s    %d   %d\n",name[i],start[i],length[i]);
           }
      }
}
void deleteFile()
{
     char temp[10];
     printf("\nEnter the filename : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
     {
          if (strcmp(name[i],temp)==0)
          {
             
                   for (j=start[i];j<(start[i]+length[i]);j++)
                   {
                        bv[j]=1;
                        printf("\n%d->%d",j,bv[j]);
                   }
                   printf("\nFile successfully deleted...");
                   strcpy(name[i],"-");
                   start[i]=1;
                   length[i]=1;
                   return;           
          }
     }
}
int main()
{
    int ch=0;
    for (i=0;i<50;i++)
         bv[i]=1;
         
    do 
    {
        printf("\n---Select One Of The Option----\n");
        printf("\n1.Show bit Vector :");
        printf("\n2.Create New File :");
        printf("\n3.Show Directory :");
        printf("\n4.Delete File :");
        printf("\n5.Exit:\n");
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);
        
        switch (ch)
        {
                case 1: displayBitVector();
                        break;
                case 2: createFile();
                        break;
                case 3: showDirectory();
                        break;
                case 4: deleteFile();
                        break;
        }
    }
    while(ch!=5);
}

/*
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-2$ cc slot1.c
ty32@pc37:~/TYBCS(VI)-32/OS/Assignment No-2$ ./a.out

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :1
Bit Vector contents :
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :2
Enter the name of file : s1
Enter the start block of the file : 0
Enter the length of the file : 4

0->0
1->0
2->0
3->0

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :1
Bit Vector contents :
0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :2
Enter the name of file : s2 
Enter the start block of the file : 6
Enter the length of the file : 12

6->0
7->0
8->0
9->0
10->0
11->0
12->0
13->0
14->0
15->0
16->0
17->0

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :1
Bit Vector contents :
0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :3
Directory contents
File NameStart BlockLength
 s1     0         4
 s2     6         12

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :4
Enter the filename : s1
0->1
1->1
2->1
3->1
File successfully deleted...

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :3
Directory contents
File NameStart BlockLength
  s2    6   12

---Select One Of The Option----
1.Show bit Vector :
2.Create New File :
3.Show Directory :
4.Delete File :
5.Exit:

Enter Your Choice :5
*/




















