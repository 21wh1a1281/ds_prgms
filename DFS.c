#include<stdio.h>
#include<stdlib.h>

struct node
{
	int vertex;
	struct node* next;
};

struct node* create_node(int);
struct Graph
{
	int num_vertices;
	struct node** adjlists;
	int* visited;
};

struct Graph* create_graph(int vertices)
{
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph -> num_vertices = vertices;
	graph -> adjlists = malloc(vertices* sizeof(struct node*));
	graph -> visited = malloc(vertices* sizeof(int));
	int i;
	for(i=1;i<=vertices;i++)
	{
		graph -> adjlists[i] = NULL;
		graph -> visited[i] = 0;
	}
	return graph;
}

struct node* create_node(int data)
{
	struct node* new_node = malloc(sizeof(struct node));
	new_node -> vertex = data;
	new_node -> next = NULL;
	return new_node;
}

void add_edge(struct Graph* graph,int i,int data)
{
	struct node* new_node = create_node(data);
	new_node ->next = graph -> adjlists[i];
	graph -> adjlists[i] = new_node;
	new_node = create_node(i);
	new_node -> next = graph -> adjlists[data];
	graph -> adjlists[data] = new_node;
}
void dfs_traverse(struct Graph* graph,int vertex)
{
	struct node* adjlist = graph -> adjlists[vertex];
	struct node* temp = adjlist;

	graph -> visited[vertex] = 1;
	printf("visited %d \n",vertex);

	while(temp != NULL)
	{
		int connected_vertex = temp -> vertex;
		if(graph -> visited[connected_vertex] == 0)
		{
			dfs_traverse(graph,connected_vertex);
		}
		temp = temp -> next;
	}
}

int main()
{
	struct Graph* graph = create_graph(4);
	add_edge(graph,1,2);
	add_edge(graph,1,3);
	add_edge(graph,2,3);
	add_edge(graph,2,5);
	add_edge(graph,2,4);
	add_edge(graph,3,5);
	add_edge(graph,4,5);
	dfs_traverse(graph,1);
}

