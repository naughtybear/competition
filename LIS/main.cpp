#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        vector<int> array;
        int tmp,count;
        cin >> count;
        for(int i=0;i<count;i++){
            scanf("%d",&tmp);
            array.push_back(tmp);
        }
        int ans[count+1];
        for(int i=0;i<count+1;i++)
            ans[i]=INT_MAX;
        ans[0]=array[0];
        for(int i=1;i<array.size();i++){
            int pos=lower_bound(ans,ans+count,array[i])-ans;
            ans[pos]=array[i];
        }
        tmp=0;
        for(int i=0;i<=count;i++){
            if(ans[i]==INT_MAX)
                break;
            else
                tmp++;
        }
        cout << tmp << endl;
    }
    return 0;
}
