#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>
#include "layout.h"

int main(int argc, char *argv[])
{
	PMEMobjpool *pop = pmemobj_create(argv[1], LAYOUT_NAME, PMEMOBJ_MIN_POOL, 0666);
	if (pop == NULL) {
		perror("pmemobj_create");
		return 1;
	}

	PMEMoid root = pmemobj_root(pop, sizeof (struct my_root));
	struct my_root *rootp = pmemobj_direct(root);

	char my_buf[MAX_BUF_LEN];
	scanf("%9s", my_buf);

	TX_BEGIN(pop) {
		pmemobj_tx_add_range(root, 0, sizeof (struct my_root));
		memcpy(rootp->buf, my_buf, strlen(my_buf));
	} TX_END

	pmemobj_close(pop);
	return 0;
}
