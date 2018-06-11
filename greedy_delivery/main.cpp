#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n;
        cin >> n;
        int time[n];
        int total[n];
        for(int i=0;i<n;i++){
            scanf("%d",&time[i]);
        }
        sort(time,time+n);
        total[0]=time[0]*2;
        int ans=time[0];
        //cout << ans << ' ' << total[0] << endl;
        for(int i=1;i<n;i++){
            total[i]=time[i]*2+total[i-1];
            ans+=total[i-1]+time[i];
            //cout << ans << ' ' << total[i] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
