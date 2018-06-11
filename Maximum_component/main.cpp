#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("graph_maxComponent.in","r",stdin);
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,m,ans=0;
        cin >> n >> m;
        int value[n],group[n];
        for(int i=0;i<n;i++){
            cin >> value[i];
            group[i]=-1;
        }
        if(m==0){
            for(int i=0;i<n;i++){
                if(ans<value[i])
                    ans=value[i];
            }
        }
        else{
            for(int i=0;i<m;i++){
                int a,b;
                scanf("%d%d",&a,&b); //need to use scanf, cannot use cin
                while(group[a]>0)
                    a=group[a];
                while(group[b]>0)
                    b=group[b];
                if(a>b){
                    value[a]+=value[b];
                    if(value[a]>ans)
                        ans=value[a];
                    group[a]+=group[b];
                    group[b]=a;
                }
                else if(a<b){
                    value[b]+=value[a];
                    if(value[b]>ans)
                        ans=value[b];
                    group[b]+=group[a];
                    group[a]=b;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
