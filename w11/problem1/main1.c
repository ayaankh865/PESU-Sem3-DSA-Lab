#include "graph.h"

int main(void)
{
	graph_t g;
	init_graph(&g, 8, 4);
	add_edge(&g, 0, 1);   /* A-B */
	add_edge(&g, 1, 2);   /* B-C */
	add_edge(&g, 3, 4);   /* D-E */
	add_edge(&g, 5, 6);   /* F-G */
	disp(&g);
	deinit_graph(&g);
	return 0;
}
