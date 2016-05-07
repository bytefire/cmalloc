#ifndef __CMALLOC_H__
#define __CMALLOC_H__

struct cmalloc_config {
	int length;
	int percentage_allocs;
};

int cmalloc_init(void *buf, int buf_len, cmalloc_config *configs, int number_of_configs);
void *cmalloc(int config_index);
void cmalloc_get(void *ptr);
void cmalloc_put(void *ptr);

#endif // __CMALLOC_H__
