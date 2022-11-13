#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int nodes;
    unordered_map<int,list<int>> adj;
    graph(){
        this->nodes = 0;
    }
    graph(int n){
        this->nodes = n;
    }
    void addEdge(int u, int v, bool direction)
    {
        // direction 0 undirected
        // direction 1 directed graph
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first<< "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void bfs();
    void dfs();
    void dfs(int,int []);
};
void graph ::  bfs(){
     int src;
     cout << "Enter Source node : " ;
     cin >> src;
     int vis[nodes] = {0};
     vis[src] = 1;
     queue<int> q;
     q.push(src);
     while(!q.empty()){
        int front = q.front();
        cout << front << " ";
        q.pop();
        for(auto it : this->adj[front]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
     }
   cout << endl;
   cout << endl;
}
void graph ::  dfs(){
    cout << "Enter source node : " ;
    int src;
    cin >> src;
    int vis[nodes]={0};
    dfs(src,vis);

    cout << endl ;
    cout << endl;
}
void graph ::  dfs(int src,int vis[]){
    vis[src] = 1;
    cout << src << " ";
    for(auto it : this->adj[src]){
        if(!vis[it]){
            dfs(it,vis);
        }
    }

    
}
int main()
{   
    int ch ;
    graph g;
	cout << "0. User input\n" << "1. defualt input\n" << "Enter your ans : ";
	cin >> ch;
    //user input 
    cout << endl;
    if(ch==0){
       int n;
       cout << "Enter the number of nodes : ";
       cin >> n;
       g.nodes = n;
       cout << "Enter the number of edges : ";
       int m;
       cin>>m;
       cout << "Enter 1 for directed graph and Enter 0 for undirected : ";
       int d;
       cin >> d;
       for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,d);
       } 
    }
    //default 
    else {
       g.nodes = 4;
       vector<pair<int,int>> v = {{2,0},{0,2},{2,3},{3,3},{1,2},{0,1}};
       int d = 1;
       for(int i = 0;i<v.size();i++){
          g.addEdge(v[i].first,v[i].second,d);
       }
    }
    int ans ;
    do{
      cout << "1.BFS" << endl;
      cout << "2.DFS" << endl;
      cout << "3.Print" << endl;
      cout << "0.Exit" << endl;
      cout << "Enter ans : ";
      cin >> ans;
      cout << endl;
      switch(ans){
        case 1:
        {
            g.bfs();
        }
        break;
        case 2:
        {
            g.dfs();
        }
        break;
        case 3: 
        {
           g.print();
        }
       
      }
    }while(ans!=0); 

}