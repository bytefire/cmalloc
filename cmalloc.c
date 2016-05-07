#include <stdint.h>

#include "cmalloc.h"

struct cmalloc_config {
        int length;
        int percentage_allocs;
};

static void *superset;
static int superset_length;
static struct cmalloc_config *configs;
static configs_count;
static bool initialised = false;

int cmalloc_init(void *buf, int buf_len, cmalloc_config *possible_configs, int number_of_configs)
{
	superset = buf;
	superset_length = buf_len;

	// TODO: check each possible_config's percentage allocs add up to 100
	configs = possible_configs;
	configs_count = number_of_configs;
	initialised = true;

	return 0;
}
	
void *cmalloc(int config_index)
{
	if (!initialised)
		return NULL;


void cmalloc_get(void *ptr);
void cmalloc_put(void *ptr);

