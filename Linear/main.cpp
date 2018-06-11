#include <bits/stdc++.h>

using namespace std;

struct node{
    long long x,a,b;
};

int cmp(const void* a,const void*b)
{
    pair<long long,long long> *tmpa=(pair<long long,long long>*)a;
    pair<long long,long long> *tmpb=(pair<long long,long long>*)b;
    if(tmpa->first!=tmpb->first)
        return tmpa->first-tmpb->first;
    else
        return tmpb->second-tmpa->second;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(1){
        int n,m;
        cin >> n >> m;
        if(n==0&&m==0)
            break;
        pair<long long,long long> line[n];
        long long c[m];
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&line[i].first,&line[i].second);
        }
        for(int i=0;i<m;i++)
            scanf("%lld",&c[i]);
        qsort(line,n,sizeof(line[0]),cmp);
        stack<node> stk;
        stk.push((node){-INT_MAX,line[0].first,line[0].second});
        for(int i=1;i<n;i++){
            if(line[i].first==line[i-1].first)
                continue;
            long long x;
            while(1){
                node tmp=stk.top();
                x=(tmp.b-line[i].second)/(line[i].first-tmp.a)+1;
                if(x<=tmp.x&&!stk.empty()) //remember x'<='tmp.x
                    stk.pop();
                else{
                    break;
                }
            }
            stk.push((node){x,line[i].first,line[i].second});//put outside of while loop
        }
        sort(c,c+m);
        reverse(c,c+m);
        /*long long ans=0;
        for(int i=0;i<m;i++){
            while(1){
                node tmp=stk.top();
                if(c[i]>=tmp.x){
                        //cout << stk.top().x << " " << stk.top().a<<" "<<stk.top().b<<" "<<c[i]<<endl;
                    ans+=tmp.a*c[i]+tmp.b;
                    break;
                }
                else{
                    if(!stk.empty())
                        stk.pop();
                }
            }
        }
        cout << ans << endl;*/
        long long ans(0);
        node lst=stk.top();
        stk.pop();
        for(int i=0;i<m;i++)
        {
            while(!stk.empty())
            {
                if(c[i]*lst.a+lst.b<c[i]*stk.top().a+stk.top().b)
                {
                    lst=stk.top();
                    stk.pop();
                }
                else
                    break;
            }
            ans+=(lst.a*c[i]+lst.b);
        }
        cout<<ans<<endl;
    }
    return 0;
}
