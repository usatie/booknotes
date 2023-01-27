#define NUM 10

void	semaphore_acquire(volatile int *cnt) {
	for (;;) {
		while (*cnt >= NUM);
		__sync_fetch_and_add(cnt, 1);
		if (*cnt <= NUM)
			break ;
		__sync_fetch_and_sub(cnt, 1);
	}
}

void	semaphore_release(int *cnt) {
	__sync_fetch_and_sub(cnt, 1);
}

/* Example Usage
// Semaphore can limit the usage of resource, 
// but of course it (almost always) can't prevent the race condition.

void	some_func() {
	for (;;) {
		semaphore_acquire(&cnt);
		// Critical Section
		semaphore_release(&cnt);
	}
}
*/
