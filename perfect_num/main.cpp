#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        long long i,input,check=1;
        cin>>input;
        for(i=2;i*i<input;i++){
            //printf("input:%d\n",input);
            if(input%i==0){
                check+=i;
                check+=(input/i);
            }
        }
        if(i*i==input)
            check+=i;
        if(check==input)
            printf("perfect\n");
        else
            printf("nonperfect\n");
    }
    return 0;
}
