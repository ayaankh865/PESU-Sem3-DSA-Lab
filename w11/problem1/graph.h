#ifndef GRAPH_H
#define GRAPH_H

#define MAXSIZE 10

struct node
{
	int vertex_;
	struct node* next_;
};
typedef struct node node_t;

struct list
{
	node_t* head_;
	node_t* tail_;
};
typedef struct list list_t;

struct graph
{
	int n_vertices_; // # of vertices
	int n_edges_;    // # of edges
	list_t adj_list_[MAXSIZE];
};
typedef struct graph graph_t;

void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges);
void add_edge(graph_t *ptr_graph, int from, int to);
void disp(graph_t *ptr_graph);
void deinit_graph(graph_t *ptr_graph);

#endif
