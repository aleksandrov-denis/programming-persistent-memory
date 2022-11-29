POBJ_LAYOUT_BEGIN(string_store);
POBJ_LAYOUT_ROOT(string_store, struct my_root);
POBJ_LAYOUT_END(string_store);

#define LAYOUT_NAME "intro_3"   /* will use this in create and open */
#define MAX_BUF_LEN 10          /* maximum length of our buffer */

struct my_root {
	char buf[MAX_BUF_LEN];
};
