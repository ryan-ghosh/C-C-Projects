#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INFINITY = 100000*10000;

bool isIn(vector<int> inputvector, int value){
    for(int i : inputvector){
        if(i == value){
            return true;
        }
    }return false;
}

class Vertex{
public:
    char name;
    Vertex(char aname){
        name = aname;
    }
};

class Graph{
public:
    vector<Vertex> vertexList;
    vector<vector<int>> adjMtx;
    Graph(vector<Vertex> avertexList={}, vector<vector<int>> aadjMtx={}){
        vertexList = avertexList;
        adjMtx = aadjMtx;
    }
    void add_vertex(Vertex v){
        vertexList.push_back(v);
        adjMtx.push_back({});
        for(int i=0; i<vertexList.size(); i++){
            if(i!=vertexList.size()-1){
                adjMtx[i].push_back(0);
            }else if(i==vertexList.size()-1){
                for(int j=0; j<vertexList.size(); j++){
                    adjMtx[vertexList.size()-1].push_back(0);
                }
            }
        }
    }
    void add_edge(Vertex v1, Vertex v2, int weight){
        int index1 = 0;
        while(vertexList[index1].name != v1.name){
            index1++;
        }
        int index2=0;
        while(vertexList[index2].name != v2.name){
            index2++;
        }
        adjMtx[index1][index2] = weight;
        adjMtx[index2][index1] = weight;
    }
    vector<char> djikstra(Vertex start, Vertex end){
        vector<int> visited;
        vector<int> unvisited;
        vector<int> previous;
        vector<int> distances;
        int currentIndex = 0;
        while(vertexList[currentIndex].name != start.name){
            currentIndex++;
        }
        int endIndex = 0;
        while(vertexList[endIndex].name != end.name){
            endIndex++;
        }
        for(int i=0; i<adjMtx.size(); i++){
            distances.push_back(100000);  // setting huge distance
        }distances[currentIndex] = 0;
        for(int i=0; i<adjMtx.size(); i++){
            previous.push_back(-1);  // unreachable
        }
        for(auto & i : vertexList){
            int uvIndex = 0;
            char k = i.name;
            while(vertexList[uvIndex].name != i.name){
                uvIndex++;
            }unvisited.push_back(uvIndex);
        }
        while(isIn(unvisited, currentIndex) && !unvisited.empty()){
            int min_dist = 100;
            visited.push_back(currentIndex);
            int currentIndexIndex = 0;
            while(unvisited[currentIndexIndex] != currentIndex){
                currentIndexIndex++;
            }
            unvisited.erase(unvisited.begin()+currentIndexIndex);
            for(int j : unvisited){
                if(adjMtx[currentIndex][j] != 0 && distances[currentIndex] + adjMtx[currentIndex][j] < distances[j]){
                    distances[j] = distances[currentIndex] + adjMtx[currentIndex][j];
                    previous[j] = currentIndex;
                }
            }int min_node = -2;
            for(int k : unvisited){
                if(distances[k] < min_dist){
                    min_node = k;
                    min_dist = distances[k];
                }
            }if(min_node!=-2){
                currentIndex = min_node;
            }
        }
        if(previous[endIndex] == -1){
            cout<<"fucko"<<endl;
            vector<char> result = {'!'};
            return result;
        }else{
            cout<<distances[endIndex]<<endl;
            vector<char> path;
            int end = endIndex;
            path.push_back(vertexList[endIndex].name);
            while(previous[end] != -1){
                end = previous[end];
                path.push_back(vertexList[end].name);
            }reverse(path.begin(), path.end());
            return path;
        }
    }
};

int main(){
    Graph G = Graph();
    Vertex a = Vertex('a');
    Vertex b = Vertex('b');
    Vertex c = Vertex('c');
    Vertex d = Vertex('d');
    Vertex e = Vertex('e');
    Vertex f = Vertex('f');
    Vertex g = Vertex('g');
    Vertex h = Vertex('h');
    Vertex i = Vertex('i');
    Vertex j = Vertex('j');
    Vertex k = Vertex('k');
    Vertex l = Vertex('l');
    Vertex m = Vertex('m');

    G.add_vertex(a);
    G.add_vertex(b);
    G.add_vertex(c);
    G.add_vertex(d);
    G.add_vertex(e);
    G.add_vertex(f);
    G.add_vertex(g);
    G.add_vertex(h);
    G.add_vertex(i);
    G.add_vertex(j);
    G.add_vertex(k);
    G.add_vertex(l);
    G.add_vertex(m);

    G.add_edge(c, b, 10);
    G.add_edge(c, e, 5);
    G.add_edge(e, a, 6);
    G.add_edge(e, m, 8);
    G.add_edge(e, h, 3);
    G.add_edge(a, b, 26);
    G.add_edge(a, d, 8);
    G.add_edge(c, f, 15);
    G.add_edge(h, i, 7);
    G.add_edge(h, l, 10);
    G.add_edge(h, j, 5);
    G.add_edge(l, g, 11);
    G.add_edge(i, g, 3);
    G.add_edge(i, m, 1);
    G.add_edge(b, k, 14);
    G.add_edge(f, k, 4);
    G.add_edge(d, f, 8);
    G.add_edge(g, j, 9);
    vector<char> path = G.djikstra(b,j);
    for(int i=0;i<path.size()-1;i++){
        cout << path[i] << "->";
    }
    cout<<path[path.size()-1]<<endl;
}