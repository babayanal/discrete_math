#ifndef GETDATAFROMFILE_HPP
#define GETDATAFROMFILE_HPP
using std::vector;
constexpr int maxSize = 999;

/* 
*brief: adds verges to adjacency vector
*/
void addVerge(vector<int> [], int, int);

/* 
*brief: returns the amount of vertices written in the input file
*/
int getVerticesFromFile();

/* 
*brief: gets data of verges from the input file
*/
void getDataFromFile(vector<int> [], int [][maxSize]);

#endif // GETDATAFROMFILE_HPP
