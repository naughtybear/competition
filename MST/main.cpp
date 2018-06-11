#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> graph[n];
        bool visit[n];
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(pair<int,int>(w,v));
            graph[v].push_back(pair<int,int>(w,u));
        }
        for(int i=0;i<n;i++)
            visit[i]=false;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        /*for(int i=0;i<graph[0].size();i++)
            pq.push(graph[0][i]);
        visit[0]=true;*/
        pq.push(pair<int,int>(0,0));
        int ans=0;
        while(!pq.empty()){
            pair<int,int> tmp=pq.top();
            pq.pop();
            if(visit[tmp.second])
                continue;
            ans+=tmp.first;
            visit[tmp.second]=true;
            for(int i=0;i<graph[tmp.second].size();i++){
                if(!visit[graph[tmp.second][i].second]){
                    pq.push(graph[tmp.second][i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
