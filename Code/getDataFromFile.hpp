#ifndef GETDATAFROMFILE_HPP
#define GETDATAFROMFILE_HPP
using std::vector;
constexpr int maxSize = 999;

/* 
 adds verges to adjacency vector
*/
void addVerge(vector<int> [], int, int);

/* 
 returns the amount of vertices written in the input file
*/
int getVerticesFromFile();

/* 
 gets data of verges from the input file
*/
void getDataFromFile(vector<int> [], int [][maxSize]);

#endif // GETDATAFROMFILE_HPP
