#include <iostream>
#define v 4
#define inf 99999
using namespace std;
int main() {
        int graph[v][v] = {
            {0,2,4,0},{2,0,1,3},{4,1,2,0},{0,3,2,0}
        };

    bool visited[v];
    fill(visited, visited + v, false);
    visited[0] = true;
    int weight = 0;

    for (int count = 0; count < v ; ++count) {
        int mini = inf;
        int x = 0, y = 0;   

        for (int i = 0; i < v; ++i) {
            if (visited[i]) {
                for (int j = 0; j < v; ++j) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < mini) 
                    {
                        mini = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if(x!=-1 && y!=-1)
        {
        visited[y] = true;
        cout << x << " - " << y << "    " << graph[x][y] << endl;
        weight=weight+graph[x][y];
        }
    }
    cout<<"Result by Prims algorithm: "<<weight<<endl;
    return 0;
}