#include "algo.h"
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

std::vector<std::vector<int>> shortest_path_all(const std::vector<std::vector<edge>>& graph) {
    int V = graph.size(); // Number of vertices in graph
    
    vector< vector<int> > final_matrix(V + 1, vector<int>(V + 1, INF));

    for (int k = 0; k < V; ++k) {
        // Initialize distance of all vertices as 0.
        int dist[V];
        for (int i = 0; i < V; ++i) {
            dist[i] = INF;
        }

        // initialize distance of source as 0 
        dist[k] = 0;

        // Relax all edges |V| - 1 times. A simple 
        // shortest path from src to any other 
        // vertex can have at-most |V| - 1 edges 
        for (int i = 0; i < V - 1; ++i) {
            for (int j = 0; j < V; ++j) {
                for (auto& it : graph[j]) {
                    if (dist[j] + it.second < dist[it.first]) {
                        dist[it.first] = dist[j] + it.second;
                    }
                }   
            }
        }

        // check for negative-weight cycles. 
        // The above step guarantees shortest 
        // distances if graph doesn't contain 
        // negative weight cycle.  If we get a 
        // shorter path, then there is a cycle.
        for (int i = 0; i < V; ++i) {
            for (auto& it : graph[i]) {
                int x = i;
                int y = it.first;
                int weight = it.second;

                if (dist[x] != INF && dist[x] + weight < dist[y]) {
                    return vector<vector<int>>(V, vector<int>(V, -1));
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            final_matrix[k][i] = dist[i];
        }

    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (final_matrix[i][j] == INF) {
                final_matrix[i][j] = -1;
            }
        }
    }

    return final_matrix;
}