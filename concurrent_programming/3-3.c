#include <stdbool.h>

bool	lock = false;

bool	test_and_set(volatile bool *p);
void	tas_release(volatile bool *p);

// 3.3 Mutex
void	some_func() {
retry:
	if (!test_and_set(&lock)) {
		// Critical Section
	} else {
		goto retry;
	}
	tas_release(&lock);
}


// 3.3.1 Spin Lock
/* This works fine, but penalty of Atomic Operation is huge.
void	spinlock_acquire(bool *lock) {
	while (test_and_set(lock));
}
*/

// Use volatile to prevent loop being optimized
void	spinlock_acquire(volatile bool *lock) {
	for (;;) {
		while (*lock);
		if (!test_and_set(lock))
			break ;
	}
}

void	spinlock_release(bool *lock) {
	tas_release(lock);
}

void	some_func2() {
	for (;;) {
		spinlock_acquire(&lock);
		// Critical Section
		spinlock_release(&lock);
	}
}
