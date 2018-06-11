#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,t;
    //bool judge=false;
    while(1){
        cin >> n >> m >> t;
        if(n==0&&m==0&&t==0)
            break;
        /*if(judge==false)
            judge=true;
        else
            cout << endl;*/
        long long *map[n],value[n],start[t];
        for(int i=0;i<t;i++)
            cin >> start[i];
        for(int i=0;i<n;i++){
            map[i]=new long long[n];
            cin >> value[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                map[i][j]=0;
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            map[a][b]=1;
        }
        long long ans=0;
        queue<int> q;
        bool visit[n];
        for(int j=0;j<n;j++)
            visit[j]=false;
        for(int i=0;i<t;i++){
            if(!visit[start[i]]){
                q.push(start[i]);
                visit[start[i]]=true;
                while(!q.empty()){
                    int tmp;
                    tmp=q.front();
                    q.pop();
                    if(value[tmp]>ans)
                        ans=value[tmp];
                    for(int j=0;j<n;j++){
                        if(map[tmp][j]==1&&!visit[j]){
                            q.push(j);
                            visit[j]=true;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        //cout << ans;
    }
    return 0;
}
