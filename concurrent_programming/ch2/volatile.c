// cc -O3 -S non_volatil.c
void	wait_while_0(volatile int *p) {
	while (*p == 0) {}
}
