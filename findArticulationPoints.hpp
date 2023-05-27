#ifndef FINDARTICULATIONPOINTS_HPP
#define FINDARTICULATIONPOINTS_HPP
using std::vector;

/* 
*brief: checks the tree of the graph and its nodes, parents, children
*/
void APUtil(vector<int> [], int, bool [], int [], int [], int&, int, bool []);

/* 
*brief: finds articulation points by using tree of the graph
*/
void findArticulationPoints(vector<int> [], int);

#endif // FINDARTICULATIONPOINTS_HPP
