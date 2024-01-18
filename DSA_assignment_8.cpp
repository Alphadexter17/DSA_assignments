#include<iostream>
#include<limits.h>
#define V 9
using namespace std;
class djikstra{
    int distance[V];
    bool shortest_path[V];
    int parent[V];
    public:
    void find_spt(int graph[V][V],int src);
    void print_shortest_path(int distance[]);
    int shortest_patht(int distance[],bool shortest_path[]);
};
void djikstra::print_shortest_path(int distance[])
{
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<distance[i]<<" "<<endl;
    }
}
int djikstra::shortest_patht(int distance[],bool shortest_path[])
{
    int mini=INT_MAX;
    int mini_index;
    for(int v=0;v<V;v++)
    {
        if(shortest_path[v]==false && distance[v]<=mini)
        {
            mini=distance[v];
            mini_index=v;
        }
    }
    return mini_index;
}
void djikstra::find_spt(int graph[V][V],int src)
{
    fill(distance,distance+V,INT_MAX);
    fill(shortest_path,shortest_path+V,false);
    distance[0]=0;
    for(int count=0;count<V-1;count++)
    {
        int u=shortest_patht(distance,shortest_path);
        shortest_path[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && graph[u][v]+distance[u]<distance[v] && shortest_path[v]==false && distance[u]!=INT_MAX)
            {
                distance[v]=distance[u]+graph[u][v];
            }
        }
    }
    print_shortest_path(distance);
}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8,0},
                        { 4, 0, 8, 0, 0, 0, 0, 11,0},
                        { 0, 8, 0, 7, 0, 4, 0, 0,2},
                        { 0, 0, 7, 0, 9, 14, 0, 0,0},
                        { 0, 0, 0, 9, 0, 10, 0, 0,0},
                        { 0, 0, 4, 14, 10, 0, 2, 0,0},
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6},
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7},
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    djikstra obj1;
    obj1.find_spt(graph,0);
    return 0;
}