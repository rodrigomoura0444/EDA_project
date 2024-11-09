#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structure.h"
#include <stdbool.h>

/**
 * @brief Initializes a graph with a specified number of vertices.
 * 
 * @param graph Pointer to the Graph structure.
 * @param vertices Number of vertices in the graph.
 * @return bool Returns true if initialization was successful, false if memory allocation failed.
 */
bool initializeGraph(Graph* graph, int vertices);

/**
 * @brief Adds an edge to the graph between two vertices with a specified weight.
 * 
 * @param graph Pointer to the Graph structure.
 * @param source Source vertex of the edge.
 * @param destination Destination vertex of the edge.
 * @param weight Weight of the edge.
 * @return bool Returns true if the edge was successfully added, false if memory allocation failed.
 */
bool addEdge(Graph* graph, int source, int destination, int weight);

/**
 * @brief Lists all the vertices of the graph along with their respective edges and weights.
 * 
 * @param graph Pointer to the Graph structure.
 * @return bool Returns true if the listing was successful, false if the graph is empty.
 */
bool listGraph(Graph* graph);

/**
 * @brief Performs a Depth-First Search (DFS) starting from a specified vertex, marking all visited vertices.
 * 
 * @param graph Pointer to the Graph structure.
 * @param vertex Initial vertex for the DFS.
 * @param visited Array of integers representing the visited vertices.
 * @param total Pointer to an integer that accumulates the total weight of visited edges.
 * @return bool Returns true if the search was performed successfully, false if there was an error due to invalid parameters.
 */
bool DFS(Graph* graph, int vertex, int visited[], int* total);

/**
 * @brief Conducts a complete DFS traversal starting from a specified initial vertex, printing the result and the total weight.
 * 
 * @param graph Pointer to the Graph structure.
 * @param startVertex Initial vertex for the DFS traversal.
 */
void DFSTraversal(Graph* graph, int startVertex);

#endif // FUNCTIONS_H
