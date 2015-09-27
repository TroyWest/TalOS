#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/paging.h>

void kernel_early(void)
{
	terminal_initialize();
}

void kernel_main(void)
{
	printf("Welcome to TalOS v0.0.2\nPaging Directory is locateed at ");
	long page = &page_directory;
	printf("%d", page);
}
