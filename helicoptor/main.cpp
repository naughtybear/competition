#include <bits/stdc++.h>
using namespace std;

struct segment
{
    int S;
    int T;
};

void sol(int N)
{
    multiset<int> tree;
    segment seg[250000];
    tree.clear();
    for(int i=0;i<N;i++) scanf("%d%d",&seg[i].S,&seg[i].T);
    int ans(0);
    for(int i=0;i<N;i++)
    {
        tree.insert(seg[i].S);
        int tr = seg[i].T;
        multiset<int>::iterator it = tree.upper_bound(tr);
        if(it != tree.end()) tree.erase(it);
    }
    cout<<tree.size()<<endl;
}

int main()
{
    int N=0;
    while(scanf("%d",&N))
    {
        if(!N) break;
        sol(N);
    }
    return 0;
}
