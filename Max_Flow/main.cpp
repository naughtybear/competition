#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL graph[600][600];
LL F[600][600],R[600][600];
bool visit[600];
int path[600];
LL flow[600];

int BFS(int s,int t,int n)
{
    for(int i=0;i<n;i++)
        visit[i]=false;
    queue<int> q;
    path[s]=s;
    visit[s]=true;
    flow[s]=999999999999;
    q.push(s);

    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int j=0;j<n;j++){
            if(!visit[j]&&R[tmp][j]>0){
                visit[j] = true;
                path[j] = tmp;
                flow[j] = min(flow[tmp], R[tmp][j]);
                q.push(j);
                if (j == t) return flow[t];
            }
        }
    }
    return 0;
}

int Edmonds_Krap(int s,int t,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            F[i][j]=0;
            R[i][j]=graph[i][j];
        }
    }
    int f,df;
    for(f=0;df=BFS(s,t,n);f+=df){
        for(int i=path[t],j=t;i!=j;i=path[j=i]){
            F[i][j]=F[i][j]+df;
            F[j][i]=-F[i][j];
            R[i][j] = graph[i][j] - F[i][j];
            R[j][i] = graph[j][i] - F[j][i];
        }
    }
    return f;
}

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m;
        cin >> n >>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                graph[i][j]=0;
        }
        for(int i=0;i<m;i++){
            int u,v;
            LL c;
            cin >> u >> v >> c;
            graph[u][v]=c;
        }
        cout << Edmonds_Krap(0,n-1,n) << endl;
    }
    return 0;
}
