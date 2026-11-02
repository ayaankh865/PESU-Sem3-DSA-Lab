#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* ------------------------------------------------------------------
 * Problem 1 : Graph using an ADJACENCY LIST
 * Complete every function marked TODO. Do not change graph.h or main1.c.
 * Vertices are numbered 0..n-1 and printed as letters A, B, C ...
 * ------------------------------------------------------------------ */

// ---------- list functions ----------

// GIVEN: makes an empty list
void init_list(list_t *ptr_list)
{
	ptr_list->head_ = ptr_list->tail_ = NULL;
}

// TODO 1: create a new node holding v and append it at the END of the list.
//         Handle both cases: empty list and non-empty list.
//         Hint: tail_ lets you append in O(1).
void add_list(list_t *ptr_list, int v)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	if(new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->vertex_ = v;
	new_node->next_ = NULL;

	if(ptr_list->head_ == NULL)
	{
		ptr_list->head_ = new_node;
		ptr_list->tail_ = new_node;
	}
	else
	{
		ptr_list->tail_->next_ = new_node;
		ptr_list->tail_ = new_node;
	}
}

// GIVEN: prints the neighbour numbers of one list on a single line
void disp_list(list_t* ptr_list)
{
	node_t* temp = ptr_list->head_;
	while(temp)
	{
		printf("%d ", temp->vertex_);
		temp = temp->next_;
	}
	printf("\n");
}

// TODO 2: free EVERY node of the list, then leave the list empty
//         (head_ and tail_ NULL). Save next_ before calling free().
void free_list(list_t *ptr_list)
{
	node_t *current = ptr_list->head_;
	while(current != NULL)
	{
		node_t *next_node = current->next_;
		free(current);
		current = next_node;
	}
	ptr_list->head_ = NULL;
	ptr_list->tail_ = NULL;
}

// ---------- graph functions ----------

// TODO 3: store n_vertices and n_edges, then make every adjacency list empty.
void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
	if(n_vertices < 0 || n_vertices > MAXSIZE)
	{
		fprintf(stderr, "Invalid number of vertices\n");
		exit(EXIT_FAILURE);
	}
	ptr_graph->n_vertices_ = n_vertices;
	ptr_graph->n_edges_ = n_edges;
	for(int i = 0; i < n_vertices; ++i)
		init_list(&ptr_graph->adj_list_[i]);
}

// TODO 4: the graph is UNDIRECTED, so an edge u - v means
//         v goes into u's list AND u goes into v's list.
void add_edge(graph_t *ptr_graph, int u, int v)
{
	if(u < 0 || u >= ptr_graph->n_vertices_ || v < 0 || v >= ptr_graph->n_vertices_)
		return;
	add_list(&ptr_graph->adj_list_[u], v);
	add_list(&ptr_graph->adj_list_[v], u);
}

// TODO 5: print "displaying", then one line per vertex in the form
//             A : 1
//             B : 0 2
//         (vertex letter = i + 'A', then its neighbour list).
//         Use disp_list(). No extra header, no blank lines.
void disp(graph_t *ptr_graph)
{
	printf("displaying\n");
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		printf("%c : ", i + 'A');
		disp_list(&ptr_graph->adj_list_[i]);
	}
}

// TODO 6: free all lists (use free_list) and set n_vertices_, n_edges_ to 0.
//         Calling init_list here would leak memory - why?
void deinit_graph(graph_t *ptr_graph)
{
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
		free_list(&ptr_graph->adj_list_[i]);
	ptr_graph->n_vertices_ = 0;
	ptr_graph->n_edges_ = 0;
}
