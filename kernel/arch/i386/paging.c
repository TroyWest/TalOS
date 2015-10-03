#include <kernel/paging.h>
unsigned long *page_directory = (unsigned long *) 0x9C000;
unsigned long *page_table = (unsigned long *) 0x9D000;

void build_page_table()
{
	unsigned long address  = 0; // holds the physical address for a page
	unsigned int i = 0;
	
	for(i = 0; i < 1024; i++)
	{
		page_table[i] = address | 3; // attribute set to supervisor level. Read/write, present(011 in binary)
		address = address + 4096; // move to next 4kb page.		
	}
	
}

void build_page_directory()
{
	page_directory[0] = page_table;
	page_directory[0] = page_directory[0] | 3;
	unsigned int i = 1;
	
	for(i = 1; i < 1024 ; i++)
	{
		page_directory[i] = 0 | 2;
		
	}
	
}

void start_paging()
{
	_write_cr3(page_directory);
	_write_cr0(_read_cr0() | 0x80000000);
}

int initialize_paging()
{
	build_page_table();	
	build_page_directory();
	start_paging();
	
	return 1;
}

unsigned long * get_page_directory()
{
	return page_directory;
}

