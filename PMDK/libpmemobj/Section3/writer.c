#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>
#include "layout.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: %s file-name\n", argv[0]);
		return 1;
	}
	
	PMEMobjpool *pop = pmemobj_create(argv[1], POBJ_LAYOUT_NAME(string_store), PMEMOBJ_MIN_POOL, 0666);
	if (pop == NULL) {
		perror("pmemobj_create");
		return 1;
	}

	TOID(struct my_root) root = POBJ_ROOT(pop, struct my_root);

	char my_buf[MAX_BUF_LEN] = {0};
	if(scanf("%9s", my_buf) == EOF) {
		perror("pmemobj_create");
		return 1;
	}

	TX_BEGIN(pop) {
		TX_MEMCPY(D_RW(root)->buf, my_buf, strlen(my_buf));
	} TX_END

	pmemobj_close(pop);
	return 0;
}
