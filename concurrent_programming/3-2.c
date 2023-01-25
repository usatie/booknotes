#include <stdbool.h>
#include <stdint.h>

bool	compare_and_swap(uint64_t *p, uint64_t val, uint64_t newval)
{
	return __sync_bool_compare_and_swap(p, val, newval);
}

bool	test_and_set(volatile bool *p)
{
	return __sync_lock_test_and_set(p, 1);
}

void	tas_release(volatile bool *p)
{
	return __sync_lock_release(p);
}
