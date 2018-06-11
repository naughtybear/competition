#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

int graph[1200][1200];
int d[1200][1200];
int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m;
        cin >> n >>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(i==j){
                    graph[i][j]=0;
                    d[i][j]=0;
                }
                else {
                    graph[i][j]=MAX;
                    d[i][j]=MAX;
                }
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u][v]=w;
            d[u][v]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    if(d[i][k]+d[k][j]<d[i][j])
                        d[i][j]=d[i][k]+d[k][j];
            }
        }
        int min=MAX,minpos;
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<n;j++){
                tmp+=d[i][j];
            }
            if(tmp<min){
                min=tmp;
                minpos=i;
            }
        }
        cout << minpos << endl;
    }
    return 0;
}
