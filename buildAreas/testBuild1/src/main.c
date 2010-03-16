#include <stdio.h>
#include <stdlib.h>

#include "a.h"
#include "b.h"


int main(void)
{
	printf("Starting In main()\n");
	printf("about to call a()\n");
	a();
	printf("returned from a()\n");
	printf("about to call b()\n");
	b();
	printf("returned from b()\n");
	printf("In main(), about to terminate\n");
}

