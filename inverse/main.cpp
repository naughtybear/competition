#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    string input;
    long long p;
    int flag=0;
    while(cin >> input >> p){
        long long ans=1,tmp=0;
        //cout << input << endl;
        if(flag==0)
            flag=1;
        else
            cout << endl;
        int length=input.length();
        for(int i=0;i<length;i++){
            tmp=(tmp*10+(input[i]-'0'))%p;
            //cout << tmp <<" " <<i << endl;
        }
        //cout << tmp << endl;
        long long tmp2=p-2;
        while(tmp2){
            if(tmp2&1){
                ans*=tmp;
                ans%=p;
            }
            tmp*=tmp;
            tmp%=p;
            tmp2>>=1;
        }
        cout << ans;
        /*cin >> ans;
        ans%=p;
        cout << ans << endl;*/
    }
    return 0;
}
