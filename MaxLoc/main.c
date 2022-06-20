#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int my_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);	
	int my_values[2];
	my_values[0] = my_rank * 100;
	my_values[1] = my_rank;

	int max_values[2];

	MPI_Allreduce(my_values,
               max_values,
               1,
               MPI_2INT,
               MPI_MAXLOC,
               MPI_COMM_WORLD);
	printf("Rank of the max value is: %d\n", max_values[1]);

	MPI_Finalize();
	return EXIT_SUCCESS;
}
