#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct side{
    friend bool operator < (side a,side b)
    {
        return a.risk>b.risk;
    }
    int place;
    ll risk,length;
};

struct cmp{
    bool operator () (const side&a,const side&b){return a.length < b.length;}
};
int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m;
        cin >> n >> m;
        vector<side> graph[n];
        side dis[n];
        bool visit[n];
        for(int i=0;i<n;i++){
            graph[i].resize(n);
            visit[i]=false;
            dis[i].length=dis[i].risk=INT_MAX;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j].length=graph[i][j].risk=INT_MAX;
            }
        }
        for(int i=0;i<m;i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            graph[a][b].risk=c;
            graph[a][b].length=d;
        }
        //cout << "1";
        priority_queue<side> pq;
        dis[0].length=dis[0].risk=0;
        dis[0].place=0;
        pq.push(dis[0]);
        for(int i=0;i<n;i++){
            int a=-1;
            side tmp=pq.top();
            while(!pq.empty()){
                tmp=pq.top();
                if(visit[a=tmp.place])
                    pq.pop();
                else
                    break;
            }
            if(a==-1)
                break;
            visit[a]=true;
            //cout << "+++";
            for(int j=1;j<n;j++){
                if(!visit[j]&&graph[a][j].risk<dis[j].risk){
                    tmp.risk>graph[a][j].risk?dis[j].risk=tmp.risk:dis[j].risk=graph[a][j].risk;
                    dis[j].place=j;
                    //cout << tmp.risk << "******" <<j<< endl;
                    pq.push(dis[j]);
                }
            }
        }
        ll max=dis[n-1].risk;
        //cout << max << "******" << endl;
        if(max>=INT_MAX){
            cout << "-1" << endl;
            continue;
        }
        for(int i=0;i<n;i++)
            visit[i]=false;
        priority_queue<side,vector<side>,cmp> pq2;
        pq2.push(dis[0]);
        for(int i=0;i<n;i++){
            int a=-1;
            while(!pq2.empty()&&visit[a=pq2.top().place])
                pq2.pop();
            if(a==-1){
                break;
            }
            visit[a]=true;
            for(int j=1;j<n;j++){
                if(!visit[j]&&graph[a][j].risk<=max&&graph[a][j].length+dis[a].length<dis[j].length){
                    dis[j].length=graph[a][j].length+dis[a].length;
                    //cout << dis[a].length << endl;
                    pq2.push(dis[j]);
                }
            }
        }
        cout << dis[n-1].risk << " " << dis[n-1].length << endl;
        /*for(int i=0;i<5000;i++)
            delete [] graph[i];*/
    }
    return 0;
}
