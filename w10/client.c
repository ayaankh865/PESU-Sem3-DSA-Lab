#include <stdio.h>
#include "graph.h" 

int main()
{
	graph_t g;
	int n_edge = 11;
	int n_vertex = 8;
	init_graph(&g, n_vertex, n_edge);
	int e[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, 
		{3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}; 
	//{"AB", "AC", "BC", "BD", "CE",
	//			"DE", "DF", "EG", "FG", "FH", "GH"};
	//disp(&g);
	
	for(int i = 0; i < n_edge; ++i)
	{
	
		add_edge(&g, e[i][0], e[i][1]);
	}
	printf("disp:\n");
	disp(&g);
	dfs(&g, 0);
} 
