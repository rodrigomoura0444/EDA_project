#ifndef STRUCTURE_H
#define STRUCTURE_H

/**
 * @file structure.h
 * @brief Defines the data structures for a graph using an adjacency list representation.
 *
 * This file contains definitions for the Node and Graph structures that represent a graph 
 * in adjacency list format, which is suitable for various graph algorithms.
 */

/**
 * @brief Represents a node in the adjacency list of a graph.
 *
 * Each node corresponds to an edge in the graph, containing the destination vertex,
 * the weight of the edge, and a pointer to the next node in the adjacency list.
 */
typedef struct Node {
    int destination;         ///< Destination vertex of the edge.
    int weight;              ///< Weight of the edge.
    struct Node* next;       ///< Pointer to the next node in the adjacency list.
} Node;

/**
 * @brief Represents a graph structure using an adjacency list.
 *
 * This structure contains the total number of vertices and an array of pointers to Node,
 * where each pointer corresponds to the head of the adjacency list for each vertex.
 */
typedef struct {
    int vertices;            ///< Total number of vertices in the graph.
    Node** adjList;          ///< Pointer to an array of pointers to Node, representing the adjacency list for each vertex.
} Graph;

#endif // STRUCTURE_H
