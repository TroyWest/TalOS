#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/paging.h>

void kernel_early(void)
{
	int paging = initialize_paging();
	terminal_initialize();
	
	if(paging == 1)
	{
		unsigned long * directory = get_page_directory();
		unsigned long * table = directory[0];
		printf("Paging Directory is located at %p", directory);
		printf("Paging Directory address 1 contains %p", directory[1]);
		printf("\nPaging Table is located at %p\n", table);		
	} else {
		printf("Paging setup failed!\n");
	}
	
}

void kernel_main(void)
{
	
	printf("Welcome to TalOS v0.0.2\n");
	
	
}
