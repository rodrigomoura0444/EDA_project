/**
 * @file funcoes.c
 * @brief Implementations of graph operations such as initialization, edge addition, listing, and depth-first search traversal.
 *
 * This file contains functions for managing a graph structure, including initializing a graph, adding edges, listing the graph's adjacency list,
 * performing a depth-first search, and traversing the graph starting from a specified vertex.
 */

#include "structure.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Initializes a graph with a specified number of vertices.
 * 
 * @param graph Pointer to the graph to be initialized.
 * @param vertices Number of vertices in the graph.
 * @return bool True if the graph was successfully initialized, False if memory allocation failed.
 */
bool initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    graph->adjList = malloc(vertices * sizeof(Node*));
    if (graph->adjList == NULL) {
        return false;
    }
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }
    return true;
}

/**
 * @brief Adds an edge to the graph.
 * 
 * @param graph Pointer to the graph.
 * @param source Source vertex of the edge.
 * @param destination Destination vertex of the edge.
 * @param weight Weight of the edge.
 * @return bool True if the edge was successfully added, False if memory allocation failed.
 */
bool addEdge(Graph* graph, int source, int destination, int weight) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = NULL;

    if (graph->adjList[source] == NULL) {
        graph->adjList[source] = newNode;
    } else {
        Node* current = graph->adjList[source];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return true;
}

/**
 * @brief Lists the graph by printing its adjacency list.
 * 
 * @param graph Pointer to the graph.
 * @return bool True if the graph is not empty, False otherwise.
 */
bool listGraph(Graph* graph) {
    if (graph == NULL || graph->adjList == NULL) {
        return false;
    }
    printf("Graph:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d:", i);
        Node* current = graph->adjList[i];
        while (current != NULL) {
            printf(" -> %d(%d)", current->destination, current->weight);
            current = current->next;
        }
        printf("\n");
    }
    return true;
}

/**
 * @brief Performs a Depth-First Search (DFS) starting from a given vertex.
 * 
 * @param graph Pointer to the graph.
 * @param vertex The starting vertex for the DFS.
 * @param visited Array to track visited vertices.
 * @param total Pointer to sum the weights of visited edges.
 * @return bool True if the operation was successful, False if any parameter is invalid.
 */
bool DFS(Graph* graph, int vertex, int visited[], int* total) {
    if (graph == NULL || graph->adjList == NULL || visited == NULL || total == NULL) {
        return false;
    }
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* current = graph->adjList[vertex];
    while (current != NULL) {
        if (!visited[current->destination]) {
            *total += current->weight;
            DFS(graph, current->destination, visited, total);
        }
        current = current->next;
    }
    return true;
}

/**
 * @brief Traverses the graph using DFS starting from a specified initial vertex and prints the total weight of the traversed edges.
 * 
 * @param graph Pointer to the graph.
 * @param startVertex The starting vertex for the DFS traversal.
 */
void DFSTraversal(Graph* graph, int startVertex) {
    int* visited = malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }
    int total = 0;

    printf("DFS starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, visited, &total);
    printf("\nTotal weight: %d", total);
    printf("\n");

    free(visited);
}
