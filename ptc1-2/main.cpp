#include <bits/stdc++.h>
#define LL long long
#define oo 1<<60
#define len 100100

using namespace std;
vector<int> graph[len],weight[len];
LL dist[len];
bool visit[len];

struct node{
    int b;
    LL d;
    bool operator < (const node& a)const{return d>a.d;}
};

void dijkstra(int n)
{
    for(int i=0;i<len;i++){
        dist[i]=9223372036854775807;
        visit[i]=false;
    }
    priority_queue<node> pq;


    dist[1]=0;
    pq.push((node){1,dist[1]});
    for(int i=0;i<n;i++){
        int a=-1;
        while(!pq.empty()&&visit[a=pq.top().b])
            pq.pop();
        if(a==-1)
            break;
        //cout << "a:" << a << endl;
        visit[a]=true;
        for(int b=0;b<graph[a].size();b++){
            int dest=graph[a][b];
            //cout << a << graph[a][b] << visit[graph[a][b]]<<endl;
            if(!visit[dest]&&dist[a]+weight[a][b]<dist[dest]){
                //cout << "wight:" << weight[a][b] << endl;
                dist[dest]=dist[a]+weight[a][b];
                pq.push((node){dest,dist[dest]});
            }
        }
    }
}

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m,k;
        cin >> n >> m >> k;
        pair<int,int> railway[k];

        for(int i=0;i<len;i++){
            graph[i].clear();
            weight[i].clear();
        }

        for(int i=0;i<m;i++){
            int c,d,x;
            cin >> c >> d >> x;
            graph[c].push_back(d);
            weight[c].push_back(x);
            graph[d].push_back(c);
            weight[d].push_back(x);
        }
        for(int i=0;i<k;i++){
            int a,b;
            cin >> a >> b;
            railway[i].first=a;
            railway[i].second=b;
        }
        //cout << "qq";
        dijkstra(n);
        int count=0;
        for(int i=0;i<k;i++){
            int node=railway[i].first;
            int weight=railway[i].second;
            if(dist[node]<=weight){
                //cout << node << " "<< weight << endl;
                count++;
            }
        }
        /*for(int i=1;i<=n;i++)
            cout << dist[i] << endl;*/
        cout << count;
        if(ncase)
            cout << endl;
    }
    return 0;
}
