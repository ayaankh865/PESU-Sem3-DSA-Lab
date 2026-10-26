#ifndef GRAPH_H
#define GRAPH_H 

#define MAXSIZE 10
struct graph 
{
	int n_vertices_; // # of vertices 
	int n_edges_; // # of edges 
	int adj_mat_[MAXSIZE][MAXSIZE];
};
typedef struct graph graph_t;

void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges);
void add_edge(graph_t *ptr_graph, int from, int to);
void dfs(graph_t *ptr_graph,  int u);
void disp(graph_t *ptr_graph);
void deinit_graph(graph_t *ptr_graph);
#endif 
