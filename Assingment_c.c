// Assingment in c programming


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


struct Edge {
    int source;
    int target;
    int weight;
};


int networkDelayTime(struct Edge* times, int numEdges, int n, int k) {
    
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;
    
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = times[j].source;
            int v = times[j].target;
            int w = times[j].weight;
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    
    int maxTime = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            return -1;  
        }
        maxTime = (dist[i] > maxTime) ? dist[i] : maxTime;
    }
    
    return maxTime;
}

int main() {
    int n = 4;  
    int numEdges = 3;  
    
    struct Edge times[] = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    
    int k = 2; 
    
    int result = networkDelayTime(times, numEdges, n, k);
    
    printf("Minimum time taken for all nodes to receive the signal: %d\n", result);
    
    return 0;
}


// Output:  Minimum time taken for all nodes to receive the signal: 2
