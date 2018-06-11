#include <iostream>
#define ll long long

using namespace std;

int main()
{
    string inx,inn;
    ll p;
    while(cin >> inx >> inn >> p){
        ll x=0,n=0,ans=1,base;
        for(int i=0;i<inx.length();i++){
            x=(x*10+inx[i]-'0')%p;
            //cout << inx[i] << endl;
        }
        for(int i=0;i<inn.length();i++){
            n=(n*10+inn[i]-'0')%(p-1);
        }
        //cout << inx.length() << " " << inn.length() <<endl;
        base=x;
        while(n>0){
            if(n&1){
                ans=ans*base%p;
            }
            base=base*base%p;
            n >>= 1;
        }
        cout << ans << endl;
    }
    return 0;
}
