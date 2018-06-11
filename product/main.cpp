#include <bits/stdc++.h>
#define ll long long

using namespace std;

int inverse(ll num,ll p)
{
    ll base=num,ans=1;
    ll tmpp=p-2;
    while(tmpp>0){
        if(tmpp&1){
            ans=ans*base%p;
        }
        base=base*base%p;
        tmpp>>=1;
        //cout << ans << "**" << endl;
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int ncase;
    cin >> ncase;
    while(ncase--){
        vector<ll> group1,group2;
        vector<pair<ll,ll>> newgroup1,newgroup2;
        ll n,p;
        cin >> n >> p;
        int idx=0;
        for(int i=0;i<n/2;i++){
            ll tmp;
            //scanf("%lld",&tmp);
            cin >> tmp;
            tmp%=p;
            tmp=inverse(tmp,p);
            for(int j=0;j<idx;j++){
                group1.push_back(tmp*group1[j]%p);
            }
            group1.push_back(tmp);
            idx=group1.size();
        }
        if(group1.size()==1)
            newgroup1.push_back(pair<ll,ll>(group1[0],1));
        else{
            sort(group1.begin(),group1.end());
            group1.push_back(-1);
            idx=1;
            for(int i=0;i<group1.size()-1;i++){
                if(group1[i]==group1[i+1])
                    idx++;
                else{
                    newgroup1.push_back(pair<ll,ll>(group1[i],idx));
                    idx=1;
                }
            }
            /*if(group1[group1.size()-1]==group1[group1.size()-2])
                    newgroup1.push_back(pair<ll,ll>(group1[group1.size()-1],idx));*/
           /* for(int i=0;i<newgroup1.size();i++)
                cout << newgroup1[i].first << "*" << newgroup1[i].second << endl;*/
        }
        //cout << "qq" << endl;
        idx=0;
        for(int i=n/2;i<n;i++){
            ll tmp;
            //scanf("%lld",&tmp);
            cin >> tmp;
            tmp%=p;
            for(int j=0;j<idx;j++){
                group2.push_back(tmp*group2[j]%p);
            }
            group2.push_back(tmp);
            idx=group2.size();
        }
        if(group2.size()==1)
            newgroup2.push_back(pair<ll,ll>(group2[0],1));
        else{
            sort(group2.begin(),group2.end());
            group2.push_back(-1);
            idx=1;
            for(int i=0;i<group2.size()-1;i++){
                if(group2[i]==group2[i+1])
                    idx++;
                else{
                    newgroup2.push_back(pair<ll,ll>(group2[i],idx));
                    idx=1;
                }
            }
            /*if(group2[group2.size()-1]==group2[group2.size()-2])
                    newgroup2.push_back(pair<ll,ll>(group2[group2.size()-1],idx));*/
            /*for(int i=0;i<newgroup2.size();i++)
                cout << newgroup2[i].first << " " << newgroup2[i].second << endl;*/
        }
        int idx1=0,idx2=0;
        ll ans=0;
        while(idx1!=newgroup1.size()&&idx2!=newgroup2.size()){
            if(newgroup1[idx1].first==newgroup2[idx2].first)
                ans+=newgroup1[idx1++].second*newgroup2[idx2++].second;
            else if(newgroup1[idx1].first>newgroup2[idx2].first)
                idx2++;
            else if(newgroup1[idx1].first<newgroup2[idx2].first)
                idx1++;
        }
        if(newgroup1[0].first==1)
            ans+=newgroup1[0].second;
        if(newgroup2[0].first==1)
            ans+=newgroup2[0].second;
        cout << ans << endl;
    }
    return 0;
}
