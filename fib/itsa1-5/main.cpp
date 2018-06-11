#include <iostream>
#include <cstdio>

using namespace std;

/*long long C(int m,int n)
{
    long long ans=1;
    while(n--){
        ans*=m;
        m--;
    }
    return ans;
}

long long exp(int m,int n)
{
    long long ans=1;
    for(int i=0;i<n;i++){
        ans*=m;
    }
    return ans;
}*/


int countP(int M, int N)
{
    // Base cases
    if (M == 0 || N == 0 || N > M)
        return 0;
    if (N == 1 || N == M)
        return 1;
    // S(n+1, k) = k*S(n, k) + S(n, k-1)
    return  N*countP(M-1, N) + countP(M-1, N-1);
}

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int m,n;
        int ans=0;
        scanf("%d,%d",&m,&n);
        ans=countP(m,n);
        cout << ans;
        if(ncase)
            cout << endl;
    }
    return 0;
}
