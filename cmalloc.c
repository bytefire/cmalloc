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

struct piece_metadata {
	uint16_t ref_count;
	uint16_t config_index;
};

struct hole {
	uint16_t start;
	uint16_t length;
};

static void *find_piece(int idx)
{
}

int cmalloc_init(void *buf, int buf_len, cmalloc_config *possible_configs, int number_of_configs)
{
	superset = buf;
	superset_length = buf_len;

	// TODO: check each possible_config's percentage allocs add up to 100
	// TODO: add sizeof(struct piece_metadata) to the length of each piece for metadata
	configs = possible_configs;
	configs_count = number_of_configs;
	initialised = true;

	return 0;
}
	
void *cmalloc(uint16_t config_index)
{
	void *piece;
	struct piece_metadata *md;

	if (!initialised)
		return NULL;

	piece = find_piece(config_index);
	if (!piece)
		return NULL;

	md = (struct piece_metadata *)piece;
	md->ref_count = 1;
	md->config_index = config_index;

	return (piece + sizeof(struct piece_metadata));
}

void cmalloc_get(void *ptr)
{
	struct piece_metadata *md = (ptr - sizeof(struct piece_metadata));
	md->ref_count++;
}
void cmalloc_put(void *ptr)
{
	struct piece_metadata *md = (ptr - sizeof(struct piece_metadata));
	md->ref_count--;

	if (md->ref_count == 0) {
		// TODO: update holes
	}
}

