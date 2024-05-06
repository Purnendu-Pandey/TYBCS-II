#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char *argv[]) 
{
    MPI_Init(&argc, &argv);
    int rank, size;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elements_per_process = 1000 / size;
    srand(rank);
    int local_numbers[elements_per_process];
    for (int i = 0; i < elements_per_process; i++) 
    {
        local_numbers[i] = rand();
    }
    int all_numbers[1000];
    MPI_Gather(local_numbers, elements_per_process, MPI_INT, all_numbers, elements_per_process, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) 
    {
        printf("Generated Numbers:\n");
        for (int i = 0; i < 1000; i++)
        {
          printf("%d ", all_numbers[i]);   
        }
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}