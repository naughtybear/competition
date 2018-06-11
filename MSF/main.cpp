#include <bits/stdc++.h>

using namespace std;

int parent[20000];

int find(int num)
{
    //cout << "1\n";
    int tmp=num;
    while(parent[tmp]>-1){
       // cout << "tmp:" << tmp << endl;
       tmp=parent[tmp];
       //getchar();
    }
    return tmp;
}

void unionparent(int a,int b)
{
    if(a>b){
        parent[b]+=parent[a];
        //cout << a << " " << b << endl;
        //cout << "val1:"<<parent[b] << endl;
        parent[a]=b;
    }
    else if(a<b){
        parent[a]+=parent[b];
        //cout << a << " " << b << endl;
        //cout << "val2:"<<parent[a] << endl;
        parent[b]=a;
    }
}

int main()
{
    //freopen("MSF.in","r",stdin);
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m,k;
        cin >> n >> m >> k;
        vector<tuple<int,int,int>> graph;
        for(int i=0;i<n;i++){
            //visit[i]=false;
            parent[i]=-1;
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph.push_back(tuple<int,int,int>(w,u,v));
            graph.push_back(tuple<int,int,int>(w,v,u));
        }
        sort(graph.begin(),graph.end());
        //cout << "qq\n";
        int ans=0;
        for(int i=0,j=0;i<n-k;i++){
            int tmpa,tmpb;
            while((tmpa=find(get<1>(graph[j])))==(tmpb=find(get<2>(graph[j])))){
                j++;
                //cout << "j:" << j << endl;
            }
            unionparent(tmpa,tmpb);
            ans+=get<0>(graph[j]);
        }
        cout << ans << endl;
    }
    return 0;
}
