/*
Author: TRAN DUY THANH (thanhtd@uel.edu.vn)
Student code: 20207144
Professor:Kil-Woong Jang (jangkw@kmou.ac.kr)
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
//infinity if there is no connection
#define INF 1000000 
typedef struct GraphType 
{
    int n; // number of vertices
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;
/* Shortest path distance from the starting point */
int distance[MAX_VERTICES];
/* Mark visited vertices */
int found[MAX_VERTICES]; 
int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i<n; i++)
        if (distance[i]< min && !found[i]) 
        {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}
// Output the current table (s/t,L) status
void print_status(GraphType* g)
{
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);

    }
    printf("\n");
    printf("        found:    ");
    for (int i = 0; i < g->n; i++)

        printf("%2d ", found[i]);

    printf("\n\n");
}
//
void shortest_path(GraphType* g, int start)
{
    int i, u, w;
    // initialization
    for (i = 0; i<g->n; i++) 
    {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    //mark start vertex visit
    found[start] = TRUE; 
    distance[start] = 0;
    for (i = 0; i<g->n-1; i++) 
    {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w = 0; w<g->n; w++)
            if (!found[w])
                if (distance[u] + g->weight[u][w]<distance[w])
                    distance[w] = distance[u] + g->weight[u][w];
    }
}
//test the graph
int main(int argc, char const *argv[])
{
   GraphType g = { 7,
    {{ 0, 35, INF, 247, INF, INF, INF },
    { 35, 0, 126, INF, 150, INF, INF },
    { INF, 126, 0, INF, 162, INF, 220 },
    { 247, INF, INF, 0, 82, 98, INF },
    { INF, 150, 162, 82, 0, 120, 154 },
    { INF, INF, INF, 98, 120, 0, 170 },
    { INF, INF, 220, INF, 154, 170, 0 } }
    };
    shortest_path(&g, 0);
    return 0;
}
