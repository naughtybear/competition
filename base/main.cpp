#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(ll base[],int n,int k,ll mid)
{
    int count=0;
    for(int i=0;i<n;){
        ll tmp=base[i]+mid;
        count++;
        if(count>k)
            return false;
        if(tmp>=base[n-1])
            return true;
        while(base[i]<=tmp)
            i++;
    }
    return false;
}

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n,k;
        cin >> n >> k;
        ll base[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&base[i]);
        }
        sort(base,base+n);
        if(k==1){
            cout << base[n-1]-base[0] << endl;
            continue;
        }
        ll left=1,right=(base[n-1]-base[0])/k;
        while(left<=right){
            ll mid=(left+right)/2;
            if(left==right)
                break;
            if(check(base,n,k,mid))
                right=mid;
            else
                left=mid+1;
        }
        cout << left << endl;
    }
    return 0;
}
