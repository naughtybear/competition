#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007.0
struct shoot
{
    double min,max;
    bool operator < (const shoot& tmp) const
    { return max < tmp.max; }
};
void sol()
{
    int N=0;
    int x1,x2,y1,y2;
    vector<shoot> F,S;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(y1 >= 0)
        {
            if(x1 == 0)
                F.push_back( {(double)y1/x2,oo} );
            else
            {
                F.push_back( {(double) y1/x2,(double) y2/x1} );
                S.push_back( {(double) y1/x2,(double) y2/x1} );
            }
        }
        else if(0 > y1 && 0 < y2)
        {
            if(x1 == 0)
                F.push_back({-oo,oo});
            else
            {
                F.push_back( {(double) y1/x1,(double) y2/x1} );
                S.push_back( {(double) y1/x1,(double) y2/x1} );
            }
        }
        else if(0 >= y2)
        {
            if(x1 == 0)
                F.push_back({-oo,(double)y2/x2});
            else
            {
                F.push_back( {(double) y1/x1,(double) y2/x2} );
                S.push_back( {(double) y1/x1,(double) y2/x2} );
            }
        }
    }
    sort(F.begin(),F.end());
    int a(0),b(1);
    for(int i=0; i<F.size();)
    {
        a++;
        double tmp=F[i].max;
        while(i < F.size() && tmp >= F[i].min) i++;
    }
    sort(S.begin(),S.end());
    for(int i=0; i<S.size();)
    {
        b++;
        double tmp=S[i].max;
        while(i < S.size() && tmp >= S[i].min) i++;
    }
    cout << min(a,b) << endl;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) sol();
    return 0;
}
