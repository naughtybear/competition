#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    bool judge=false;
    while(1){
        if(judge==false)
            judge=true;
        else
            cout << endl;
        cin >> n;
        if(n==0)
            break;
        long long a[n],ans=0;//remember to use long long
        stack<int> buf;

        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        buf.push(a[0]);
        for(int i=1;i<n;i++){
            while(!buf.empty()){
                //cout << ans << "/*/*/" << endl;
                if(a[i]>buf.top()){
                    ans+=a[i]-buf.top();
                    //cout << ans <<"**"<< endl;
                    break;
                }
                else
                    buf.pop();
            }
            buf.push(a[i]);
        }
        cout << ans;
    }
    return 0;
}
