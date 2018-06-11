#include <bits/stdc++.h>
#define MAX 2000000

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m,q;
        cin >> n >> m >> q;
        vector<pair<int,int>> graph[n];
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(pair<int,int>(w,v));
        }
        for(int i=0;i<q;i++){
            int r;
            cin >> r;
            priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
            bool visit[n];
            int d[n];
            int parent[n];
            int ans=0;
            for(int j=0;j<n;j++){
                visit[j]=false;
                d[j]=MAX;
            }
            pq.push(tuple<int,int,int>(0,r,0));
            d[r]=0;
            parent[r]=r;
            while(!pq.empty()){
                tuple<int,int,int> tmp=pq.top();
                int b=get<1>(tmp);
                //cout << "second:" << tmp.second << endl;
                pq.pop();
                if(visit[b])
                    continue;
                visit[b]=true;
                ans+=get<2>(tmp);
                for(int j=0;j<graph[b].size();j++){
                    int next=graph[b][j].second;
                    if(!visit[next]&&graph[b][j].first+d[b]<=d[next]){
                        d[next]=graph[b][j].first+d[b];
                        //parent[graph[tmp.second][j].second]=tmp.second;
                        pq.push(tuple<int,int,int>(d[next],next,graph[b][j].first));
                    }
                }
            }
            bool flag=false;
            //int ans=0;
            for(int j=0;j<n;j++){
                //cout << d[j] << " ";
                if(d[j]==MAX){
                    flag=true;
                    break;
                }
            }
            //cout << endl;
            if(flag)
                cout << "NO\n";
            else
                cout << ans << endl;
        }
    }
    return 0;
}
