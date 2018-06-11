#include <bits/stdc++.h>
#define P 1000000007

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    long long num,ans=0;
    priority_queue<long long,vector<long long>,greater<long long>> big;
    priority_queue<long long> small;

    cin >> num;
    small.push(num);
    ans=num;
    //cout << big.size() << " "<< small.size() << endl;
    while(cin >> num){
            //cout << big.size() << " "<< small.size() << endl;
        if(num<small.top())
            small.push(num);
        else
            big.push(num);
        //cout << big.size() << " "<< small.size() << endl;
        if(small.size()>=big.size()+2){
            long long tmp=small.top();
            small.pop();
            big.push(tmp);
        }
        else if(big.size()>=small.size()+2){
            long long tmp=big.top();
            big.pop();
            small.push(tmp);
        }
        if((big.size()+small.size())%2){
            if(big.size()>small.size())
                ans=(ans+big.top())%P;
            else
                ans=(ans+small.top())%P;
        }
        else{
            ans=(ans+(big.top()+small.top())/2)%P;
        }
        //cout << big.top() << " "<< small.top() << endl;
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
