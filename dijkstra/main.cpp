#include <iostream>
#include <cstdio>
#include <queue>
#define max 9999999

using namespace std;

struct node
{
    int name,dis;
};

struct cmp{
    bool operator ()(const node& n1,const node& n2){return n1.dis>n2.dis;}
};

int main()
{
        int n,m;
        scanf("%d%d",&n,&m);
        int *graph[n];
        priority_queue<node,vector<node> ,cmp> pq;
        bool visit[n];
        int d[n];

        for(int i=0;i<n;i++){
            graph[i]=new int[n];
        }
        for(int i=0;i<n;i++){
            visit[i]=false;
            d[i]=max;
            for(int j=0;j<n;j++)
                graph[i][j]=max;
        }
        for(int i=0;i<m;i++){
            int x,y,r;
            scanf("%d%d%d",&x,&y,&r);
            graph[x][y]=graph[y][x]=r;
        }
        d[0]=0;
        pq.push((node){0,0});
        for(int i=0;i<n;i++){
            int a=-1;
            while(!pq.empty()&&visit[a=pq.top().name])
                pq.pop();
            if(a==-1)
                break;
            visit[a]=true;
            for(int j=0;j<n;j++){
                if(!visit[j]&&d[j]>d[a]+graph[a][j]){
                    d[j]=d[a]+graph[a][j];
                    pq.push((node){j,d[j]});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(ans<d[i])
                ans=d[i];
        }
        cout << ans;

    return 0;
}
