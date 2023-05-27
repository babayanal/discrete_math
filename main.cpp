#include <iostream>
#include <bits/stdc++.h>
#include "getDataFromFile.hpp"
#include "printAdjacencyMatrix.hpp"
#include "findArticulationPoints.hpp"
using std::vector;

int main()
{
    int vertices = getVerticesFromFile();
    int adjacencyMatrix[maxSize][maxSize];
    vector<int> adjVector[vertices + 1];

    getDataFromFile(adjVector, adjacencyMatrix);
    printAdjacencyMatrix(adjacencyMatrix, vertices);
    findArticulationPoints(adjVector, vertices);
	system("dot -Tpng new.gv -o new.png");
}
