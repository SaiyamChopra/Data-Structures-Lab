#include <stdio.h>
#include <stdlib.h>

// Graph structure
struct Graph {
    int numVertices;
    int **adjMatrix;
    int *visited;
};

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjMatrix and visited array
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        graph->visited[i] = 0;

        // Initialize the adjacency matrix to 0 (no edges)
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// DFS traversal function
void dfs(struct Graph* graph, int vertex) {
    printf("%d ", vertex);
    graph->visited[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && graph->visited[i] == 0) {
            dfs(graph, i);
        }
    }
}

int main() {
    int vertices, edges, startVertex;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input the edges
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Input the starting vertex for DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS
    printf("DFS traversal starting from vertex %d:\n", startVertex);
    dfs(graph, startVertex);

    return 0;
}
