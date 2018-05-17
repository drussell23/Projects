/**
    Derek J. Russell
    Professor Jonathan Traugott
    DFS LAB (Due May 15th)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: May 17th, 2018
    ===========================================

       - Put the functions below in a driver to perform dfs on the graph specified at the very bottom.
        That means you'll call the  conn_components function  to fill a parents array and a cc array.
        The driver can then output the two arrays to show what the connected components are and who
        the parent is for each non root vertex. Also: Modify the original code to loop through the
        array in reverse order. You should get a different output for the two arrays. Your output
        should be something like this:


    1       3       0       6       2       3       12      9       7       16      15      10      18      11      13      16      -1      -1      -1      -1

    18      18      18      18      18      18      18      16      16      16      16      16      18      16      16      16      16      17      18      19
    ==========================================================================================================================================================
   -1      0       4       1       3       3       5       -1      7       -1      8       10      10      11      13      7       -1      16      -1      16

    0      0       0       0       0       0       0       7       7       9       7       7       7       7       7       7       16      16      18      16


void ccdfs(vector<int> alists[], int v, int ccnum,bool marked[], int parents[], int cc[])
    // v is the vertex whose adjacency list will be traversed
    // ccnum is the current connected component name
{
    marked[v] = true;
    cc[v] = ccnum; // Each connected component is named by its root.
    for (int i = 0; i < alists[v].size(); i++)
    {
        int w = alists[v][i];
        if (!marked[w])
        {
            parents[w] = v;
            ccdfs(alists, w, ccnum, marked, parents, cc);
        }//endif
    }//endfor
}
void conn_components(vector<int> alists[], int size, int parents[], int cc[])
{
    bool* marked = new bool[size];
    for (int i = 0; i < size; i++) marked[i] = false;
    for (int i = 0; i < size; i++)
        if (!marked[i])
        {
            parents[i] = -1; // root of a tree in the dfs forest
            ccdfs(alists, i, i, marked, parents, cc);
        }
    delete [] marked;
}
________________________________________________________________________
ADJACENCY LISTS TO USE
----------------------
alists[0].push_back(1);
alists[0].push_back(2);
alists[1].push_back(0);
alists[1].push_back(3);
alists[2].push_back(0);
alists[2].push_back(4);
alists[3].push_back(1);
alists[3].push_back(4);
alists[3].push_back(5);
alists[3].push_back(6);
alists[4].push_back(2);
alists[5].push_back(3);
alists[5].push_back(6);
alists[6].push_back(3);
alists[6].push_back(5);
alists[7].push_back(4);
alists[7].push_back(8);
alists[7].push_back(15);
alists[8].push_back(5);
alists[8].push_back(10);
alists[8].push_back(7);
alists[9].push_back(6);
alists[9].push_back(7);
alists[9].push_back(10);
alists[10].push_back(1);
alists[10].push_back(11);
alists[10].push_back(12);
alists[11].push_back(13);
alists[12].push_back(6);
alists[13].push_back(14);
alists[14].push_back(13);
alists[15].push_back(10);
alists[16].push_back(15);
alists[16].push_back(17);
alists[18].push_back(12);
alists[16].push_back(19);
alists[16].push_back(9);
**/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void ccdfs(vector<int> alists[], int v, int ccnum,bool marked[], int parents[], int cc[]);
void conn_components(vector<int> alists[], int size, int parents[], int cc[]);

void ccdfs(vector<int> alists[], int v, int ccnum,bool marked[], int parents[], int cc[])
{
     /// v is the vertex whose adjacency list will be traversed
    /// ccnum is the current connected component name

    marked[v] = true;
    cc[v] = ccnum; /// Each connected component is named by its root.

    for (unsigned int i = 0; i < alists[v].size(); i++)
    {
        int w = alists[v][i];
        if (!marked[w])
        {
            parents[w] = v;
            ccdfs(alists, w, ccnum, marked, parents, cc);
        } /// endif
    } /// endfor
}
void conn_components(vector<int> alists[], int size, int parents[], int cc[])
{
    bool* marked = new bool[size];

    for (int i = 0; i < size; i++)
    {marked[i] = false;}
    for (int i = 0; i < size; i++)
        if (!marked[i])
        {
            parents[i] = -1; /// root of a tree in the dfs forest
            ccdfs(alists, i, i, marked, parents, cc);
        }
    delete [] marked;
}
int main()
{
   const int size = 20;
   int parent[size];
   int cc[size];
   vector<int> alists[size];

    alists[0].push_back(1);
    alists[0].push_back(2);
    alists[1].push_back(0);
    alists[1].push_back(3);
    alists[2].push_back(0);
    alists[2].push_back(4);
    alists[3].push_back(1);
    alists[3].push_back(4);
    alists[3].push_back(5);
    alists[3].push_back(6);
    alists[4].push_back(2);
    alists[5].push_back(3);
    alists[5].push_back(6);
    alists[6].push_back(3);
    alists[6].push_back(5);
    alists[7].push_back(4);
    alists[7].push_back(8);
    alists[7].push_back(15);
    alists[8].push_back(5);
    alists[8].push_back(10);
    alists[8].push_back(7);
    alists[9].push_back(6);
    alists[9].push_back(7);
    alists[9].push_back(10);
    alists[10].push_back(1);
    alists[10].push_back(11);
    alists[10].push_back(12);
    alists[11].push_back(13);
    alists[12].push_back(6);
    alists[13].push_back(14);
    alists[14].push_back(13);
    alists[15].push_back(10);
    alists[16].push_back(15);
    alists[16].push_back(17);
    alists[18].push_back(12);
    alists[16].push_back(19);
    alists[16].push_back(9);

    conn_components(alists, size, parent, cc);

    for(int count = 0; count < size; count++)
    {
        cout << parent[count] << setw(5.8) << cc[count] << endl;
        cout << endl;
    }
    return (0);
}

