#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "types.h"
#include "utility.h"

typedef struct {
	void *data;
} dictionary_t;

void dictionary_init(dictionary_t *d);
void dictionary_add(dictionary_t *d, const char *k, void *v);
int dictionary_query(dictionary_t *d, const char *k, void **v);

#endif /* __DICTIONARY_H__ */
