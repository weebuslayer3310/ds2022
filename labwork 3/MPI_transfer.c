#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);
    
    int rank, cluster, x;
    MPI_Comm_size(MPI_COMM_WORLD, &cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
        x = 69420;
        MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Data Sent: %d\n", x);
    }

    else if(rank == 1){
        MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Data Received: %d\n", x);
    }

    MPI_Finalize();
    return 0;
}
