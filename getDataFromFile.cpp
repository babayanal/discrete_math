#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using std::vector;
constexpr int maxSize = 999;

void addVerge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int getVerticesFromFile()
{
    std::fstream inputFile;
    inputFile.open("input.txt", std::ios::in);

    if(!inputFile.is_open())
    {
        std::cout << "CANNOT OPEN INPUT FILE" << std::endl;
        exit(1);
    }

    std::string fileData;
    int i, j, vertices;
    constexpr int maxVertexDigits = 3;

    getline(inputFile, fileData);
    while(isdigit(fileData[i]) && j < maxVertexDigits)
    {
        vertices = vertices * 10 + (fileData[i] - '0');
        ++i;
        ++j;
    }

    return vertices;
}

void getDataFromFile(vector<int> adj[], int adjacencyMatrix[][maxSize])
{
    std::fstream inputFile;
    inputFile.open("input.txt", std::ios::in);

    if(!inputFile.is_open())
    {
        std::cout << "CANNOT OPEN INPUT FILE" << std::endl;
        exit(1);
    }

	std::ofstream vizFile("new.gv");
	vizFile << "Graph G {\n";
	vizFile << "	node [ style = filled, color = red]\n";

	std::string fileData;
    int i, j, left, right;
    constexpr int maxVertexDigits = 3;

    getline(inputFile, fileData);

    while(getline(inputFile, fileData))
    {
        left = right = 0;
        i = j = 0;

        while(isdigit(fileData[i]) && j < maxVertexDigits)
        {
            left = left * 10 + (fileData[i] - '0');
            ++i;
            ++j;
        }

        ++i;
        j = 0;

        while(isdigit(fileData[i]) && j < maxVertexDigits)
        {
            right = right * 10 + (fileData[i] - '0');
            ++i;
            ++j;
        }
		vizFile << "	" << left << " -- " << right << ";\n";
        adjacencyMatrix[left][right] = adjacencyMatrix[right][left] = 1;
        addVerge(adj, left, right);
    }

	vizFile.close();
}
