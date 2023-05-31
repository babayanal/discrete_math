#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using std::vector;
using std::min;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points

void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int& time, int parent, bool isAP[])
{
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
 
    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, isAP);
            low[u] = min(low[u], low[v]);
            if(parent != -1 && low[v] >= disc[u])
            {
                isAP[u] = true;
            }
        }
 
        else if(v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
 
    if(parent == -1 && children > 1)
    {
        isAP[u] = true;
    }
}

void findArticulationPoints(vector<int> adj[], int V)
{
    int disc[V] = { 0 };
    int low[V];
    bool visited[V] = { false };
    bool isAP[V] = { false };
    int time = 0, par = -1;

	std::fstream vizFile("new.gv", std::ios::app);

    for(int u = 0 ; u < V ; ++u)
    {
        if(!visited[u])
        {
            APUtil(adj, u, visited, disc, low, time, par, isAP);
        }
    }
    std::cout << std::endl;
    std::cout << "\033[1;93m" << "ARTICULATION POINTS: ";
    std::cout << "\033[1;92m";
    for(int u = 0 ; u < V ; ++u)
    {
        if(isAP[u] == true)
        {
            std::cout << u << " ";
			vizFile << "	" << u << " [ color = green ] \n";
        }
    }
    std::cout << std::endl;
	vizFile << "}\n";
	vizFile.close();
}
