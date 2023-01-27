#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

pthread_mutex_t	mut = PTHREAD_MUTEX_INITIALIZER;

int	cnt = 0;

void	*some_func3(void *arg) {
	for (int i = 0; i < 10000000; i++) {
		if (pthread_mutex_lock(&mut) != 0) {
			perror("pthread_mutex_lock");
			exit(-1);
		}
		
		// Critical Section
		cnt++;
		if (pthread_mutex_unlock(&mut) != 0) {
			perror("pthread_mutex_unlock");
			exit(-1);
		}
	}
	return (NULL);
}

bool	lock;
void	spinlock_acquire(volatile bool *lock);
void	spinlock_release(bool *lock);

void	*some_func4(void *arg) {
	for (int i = 0; i < 10000000; i++) {
		//spinlock_acquire(&lock);
		
		// Critical Section
		cnt++;
		//spinlock_release(&lock);
	}
	return (NULL);
}

// gcc 3-3-2.c 3-2.c 3-3.c && ./a.out
int	main(int argc, char *argv[]) {
	pthread_t	th1, th2;

	if (pthread_create(&th1, NULL, some_func4, NULL) != 0) {
		perror("pthread_create");
		exit(-1);
	}
	if (pthread_create(&th2, NULL, some_func4, NULL) != 0) {
		perror("pthread_create");
		exit(-1);
	}
	if (pthread_join(th1, NULL) != 0) {
		perror("pthread_join");
		exit(-1);
	}
	if (pthread_join(th2, NULL) != 0) {
		perror("pthread_join");
		exit(-1);
	}
	printf("cnt = %d\n", cnt);
	if (pthread_mutex_destroy(&mut) != 0) {
		perror("pthread_mutex_destroy");
		exit(-1);
	}
	return (0);
}
