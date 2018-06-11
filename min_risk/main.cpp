#include <iostream>
#include <queue>
#define max 999999

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
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m;
        cin >> n >> m;
        int *graph[n];
        priority_queue<node,vector<node>,cmp> pq;
        bool visit[n];
        int parent[n];
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
            cin >> x >> y >> r;
            graph[x][y]=r;
        }
        d[0]=0;
        parent[0]=0;
        pq.push((node){0,0});
        for(int i=0;i<n;i++){
            int a=-1;
            while(!pq.empty()&&visit[a=pq.top().name])
                pq.pop();
            if(a==-1)
                break;
            visit[a]=true;
            for(int b=0;b<n;b++){
                if(!visit[b]&&d[b]>graph[a][b]){
                    d[b]=graph[a][b];
                    parent[b]=a;
                    pq.push((node){b,d[b]});
                }
            }
        }
        int tmp=n-1,ans=0;
        if(d[tmp]==max)
            cout << "-1";
        else{
            while(tmp!=0){
                if(ans<d[tmp])
                    ans=d[tmp];
                tmp=parent[tmp];
            }
            cout << ans;
        }
        if(ncase)
            cout << endl;
        for(int i=0;i<n;i++){
            delete [] graph[i];
        }
    }
    return 0;
}
