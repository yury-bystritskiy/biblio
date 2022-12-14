#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../src/biblio.h"

int main()
{
	if (access(cachefile, F_OK) == 0)	// If cache exists,
		remove(cachefile);				// remove it.

	load_records();
	cleanup();
	
	if (access(cachefile, F_OK) != 0)	// If cache is not generated...
	{
		printf("Test failed! (cache file was not generated)\n");
		return 1;
	}

	printf("Test passed.\n");
	return 0;
}
