#include <bits/stdc++.h>
#define MAX 7000000

using namespace std;

int main()
{
    //freopen("bellman_ford.in","r",stdin);
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m,q;
        cin >> n >> m >> q;
        vector<tuple<int,int,int>> graph;
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph.push_back(tuple<int,int,int>(u,v,w));
        }
        for(int i=0;i<q;i++){
            int s,e;
            scanf("%d%d",&s,&e);
            int d[n];
            bool cycle[n];
            for(int j=0;j<n;j++){
                d[j]=MAX;
                cycle[j]=false;
            }
            d[s]=0;
            for(int a=0;a<n-1;a++){
                for(int b=0;b<graph.size();b++){
                    if(d[get<1>(graph[b])]>d[get<0>(graph[b])]+get<2>(graph[b]))
                        d[get<1>(graph[b])]=d[get<0>(graph[b])]+get<2>(graph[b]);
                }
            }
            //bool flag=false;
            for(int a=0;a<n-1;a++){
                bool flag=false;
                for(int b=0;b<graph.size();b++){
                    if(d[get<1>(graph[b])]>d[get<0>(graph[b])]+get<2>(graph[b])){
                        d[get<1>(graph[b])]=d[get<0>(graph[b])]+get<2>(graph[b]);
                        flag=true;
                        cycle[get<1>(graph[b])]=true;
                    }
                }
                if(!flag)
                    break;
            }
            if(cycle[e])
                cout << "No\n";
            else if(d[e]==MAX)
                cout << "No\n";
            else
                cout << d[e] << endl;
        }
    }
    return 0;
}
