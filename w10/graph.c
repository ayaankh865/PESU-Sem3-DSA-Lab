#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define DEBUG 0
void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
	ptr_graph->n_vertices_ = n_vertices;
	ptr_graph->n_edges_ = n_edges;
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		for(int j = 0; j < ptr_graph->n_vertices_; ++j)
		{		
			ptr_graph->adj_mat_[i][j] = 0;
		}
	}
}

void add_edge(graph_t *ptr_graph, int from, int to)
{
	if(DEBUG)
		printf("Adding an edge %d - %d\n", from, to);
	ptr_graph->adj_mat_[from][to] = 1;
	ptr_graph->adj_mat_[to][from] = 1;
}

void dfs_recursive(int n, int a[n][MAXSIZE], int visited[], int u)
{
	visited[u] = 1;
	printf("visited %d \n", u);
	for(int i = 0; i < n; ++i)
	{
		if(a[u][i] && ! visited[i])
		{
			dfs_recursive(n, a, visited, i);
		}
	}
}
// vertex to start : u 
// visited so far : visited 
void dfs(graph_t *ptr_graph,  int u)
{
	int visited[MAXSIZE];
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
		visited[i] = 0;
	dfs_recursive(ptr_graph->n_vertices_, ptr_graph->adj_mat_, visited, u);
	printf("\n");
}

void disp(graph_t *ptr_graph)
{
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		printf("%c  ", i);
		for(int j = 0; j < ptr_graph->n_vertices_; ++j)
		{
			printf("%2d ", ptr_graph->adj_mat_[i][j]);
		}
		printf("\n");
	}

}

void deinit_graph(graph_t *ptr_graph)
{
	ptr_graph->n_vertices_ = 0;
	ptr_graph->n_edges_ = 0;

}