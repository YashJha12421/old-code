// Online C compiler to run C program online
#include <stdio.h>
#include<limits.h>

#define V 7

int g[V][V]={{0,2,0,4,0,0,0},
                    {0,0,0,8,6,0,0},
                    {1,0,0,0,0,0,0},
                    {0,0,0,0,0,7,3},
                    {0,0,0,0,0,0,5},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0}};


void adj() {
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++)
printf("%2d ", g[i][j]);
printf("\n");
}
}



void dij(int s) {
int d[V], vis[V] = {0};
for (int i = 0; i < V; i++) d[i] = INT_MAX;
d[s] = 0;

for (int c = 0; c < V - 1; c++) {
int m = INT_MAX, u;
for (int i = 0; i < V; i++)
if (!vis[i] && d[i] < m)
m = d[i], u = i;

vis[u] = 1;

for (int v = 0; v < V; v++)
if (!vis[v] && g[u][v] && d[u] != INT_MAX && d[u] + g[u][v] < d[v])
d[v] = d[u] + g[u][v];
}

for (int i = 0; i < V; i++)
printf("A -> %c = %d\n", 'A' + i, d[i]);
}

void bell(int s) {
int d[V];
for (int i = 0; i < V; i++) d[i] = INT_MAX;
d[s] = 0;

for (int i = 0; i < V - 1; i++)
for (int u = 0; u < V; u++)
for (int v = 0; v < V; v++)
if (g[u][v] && d[u] != INT_MAX && d[u] + g[u][v] < d[v])
d[v] = d[u] + g[u][v];

for (int i = 0; i < V; i++)
printf("A -> %c = %d\n", 'A' + i, d[i]);
}

void fw() {
int d[V][V], i, j, k;
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
d[i][j] = (i == j) ? 0 : (g[i][j] ? g[i][j] : INT_MAX);

for (k = 0; k < V; k++)
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][k] + d[k][j] < d[i][j])
d[i][j] = d[i][k] + d[k][j];

for (i = 0; i < V; i++) {
for (j = 0; j < V; j++) {
if (d[i][j] == INT_MAX) printf("inf ");
else printf("%3d ", d[i][j]);
}
printf("\n");
}
}
int main() {
adj();
printf("\n");
dij(0);
printf("\n");
bell(0);
printf("\n");
fw();
return 0;
}