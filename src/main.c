/**
 * @file main.c
 * @brief Main program to demonstrate graph operations.
 *
 * This program reads graph data from a file, initializes a graph structure, adds edges based on the file data,
 * lists the graph, performs a DFS traversal from a specified vertex, and finally cleans up the allocated resources.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

/**
 * @brief Main function that orchestrates reading graph data, initializing graph, adding edges, and performing traversals.
 * 
 * @return int Returns 0 on success, 1 on file open error, and 0 on other failures with cleanup.
 */
int main() {
    Graph graph;  ///< Graph instance to hold the adjacency list.

    FILE* file;   ///< File pointer for reading the graph data.
    char line[100]; ///< Buffer to hold each line of input from the file.

    // Open the file containing the graph data.
    file = fopen("dados.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Count the number of vertices in the graph by reading line counts.
    int nVertices = 0;
    while (fgets(line, sizeof(line), file)) {
        nVertices++;
    }

    // Reset the file pointer to the beginning of the file for actual data processing.
    fseek(file, 0, SEEK_SET);

    // Initialize the graph with the counted vertices.
    bool success = initializeGraph(&graph, nVertices);
    if(!success) {
        return 0;
    }
    
    // Read the file again to populate the adjacency list.
    int i = 0;
    char* value;
    while (fgets(line, sizeof(line), file)) {
        value = strtok(line, ";");
        int j = 0;
        while (value != NULL && j < nVertices) {
            int weight = atoi(value);
            success = addEdge(&graph, i, j, weight);
            if(!success) {
                return 0;
            }
            value = strtok(NULL, ";");
            j++;
        }
        i++;
    }

    // Close the file as it's no longer needed.
    fclose(file);

    // List all vertices with their edges and weights.
    success = listGraph(&graph);
    if(!success) {
        return 0;
    }
    
    // Perform a DFS traversal starting from vertex 0.
    int startVertex = 0;
    success = DFSTraversal(&graph, startVertex);
    if(!success) {
        return 0;
    }
    
    // Clean up dynamically allocated memory for each node.
    for (i = 0; i < graph.vertices; ++i) {
        Node* current = graph.adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    // Free the adjacency list array itself.
    free(graph.adjList);

    return 0;
}
