#include <pthread.h>
#include <stdio.h>

volatile int	num = 10;

void	barrier(volatile void *cnt, int max);

void	*worker(void *arg) {
	barrier(&num, 10);
	// some process
	return NULL;
}

int	main(int argc, char *argv[]) {
	pthread_t	th[10];

	for (int i = 0; i < 10; i++) {
		if (pthread_create(&th[i], NULL, worker, NULL) != 0) {
			perror("pthread_create"); return -1;
		}
	}
	return 0;
}
