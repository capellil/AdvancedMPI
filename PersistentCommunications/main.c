#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);

	int comm_size;
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
	if(comm_size != 2)
	{
		printf("Nope.\n");
		MPI_Abort(MPI_COMM_WORLD, -1);
	}

	int my_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	int my_array[10];
	MPI_Request request;

	if(my_rank == 0)
	{
		MPI_Send_init(my_array, 10, MPI_INT, 1, 0, MPI_COMM_WORLD, &request);
	}
	for(int i = 0; i < 99; i++)
	{

		if(my_rank == 0)
		{
			MPI_Start(&request);
			MPI_Wait(&request, MPI_STATUS_IGNORE);
		}
		else
		{
			MPI_Recv(my_array, 10, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
	}

	MPI_Finalize();
	return EXIT_SUCCESS;
}
