#include <iostream>

using namespace std;

long long inverse(long long num,long long p)
{
    long long ans=1,n;
    n=p-2;
    while(n>0){
        if(n&1)
            ans=ans*num%p;
        num=num*num%p;
        n>>=1;
        //cout << ans << "**" << endl;
    }
    return ans;
}

int main()
{
    long long n,k,p;
    bool judge=true;
    while(cin >> n >> k >> p){
        if(judge==true)
            judge=false;
        else
            cout << endl;
        long long ans=1;
        for(int i=0;i<k;i++){
            ans=ans*(n-i)%p;
            //cout << ans << endl;
        }
        for(int i=2;i<=k;i++){
            ans=ans*inverse(i,p)%p;
            //cout << inverse(i,p) << " inv" << endl;
            //cout << ans << endl;
        }
        cout << ans;
    }
    return 0;
}
