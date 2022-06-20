#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);

	int my_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	int my_array[10];

	for(int i = 0; i < 99; i++)
	{
		if(my_rank == 0)
		{
			MPI_Send(my_array, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
		}
		else
		{
			MPI_Recv(my_array, 10, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
	}

	MPI_Finalize();
	return EXIT_SUCCESS;
}
