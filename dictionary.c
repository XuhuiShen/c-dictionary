#include "dictionary.h"
#include "utility.h"
#include <assert.h>
#include <search.h>
#include <string.h>

typedef struct {
	const char *k;
	void *v;
} data_t;

static int __cmp(const void *_a, const void *_b)
{
	const data_t *a = _a;
	const data_t *b = _b;
	return strcmp(a->k, b->k);
}

void dictionary_init(dictionary_t *d)
{
	d->data = NULL;
}

int dictionary_query(dictionary_t *d, const char *k, void **v)
{
	data_t data = { .k = k };
	data_t **found = tfind(&data, &d->data, __cmp);
	if (!found)
		return -1;
	*v = (*found)->v;
	return 0;
}

void dictionary_add(dictionary_t *d, const char *k, void *v)
{
	void *tmp;
	assert(dictionary_query(d, k, &tmp));

	data_t *new = xmalloc(sizeof(*new));
	new->k = k;
	new->v = v;

	data_t **loc = tsearch(new, &d->data, __cmp);
	assert(new);
	*loc = new;
}
