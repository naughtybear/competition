#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        vector<int> num,weight;
        int tmp,count;
        cin >> count;
        for(int i=0;i<count;i++){
            scanf("%d",&tmp);
            num.push_back(tmp);
        }
        for(int i=0;i<count;i++){
            scanf("%d",&tmp);
            weight.push_back(tmp);
        }
        map<int,int> container;
        map<int,int>::iterator lowit;
        container[0]=0;
        for(int i=0;i<count;i++){
            lowit=container.lower_bound(num[i]);
            lowit--;
            pair<int,int> newitem(num[i],weight[i]+lowit->second);
            lowit++;
            bool judge=true;
            while(lowit!=container.end()){
                if(lowit->first==num[i]&&lowit->second>=newitem.second){
                    judge=false;
                    break;
                }
                else if(lowit->second<=newitem.second){
                    auto tmp=(++lowit);
                    lowit--;
                    container.erase(lowit);
                    lowit=tmp;
                }
                else
                    break; //其他的也要insert
            }
            if(judge)
                container.insert(newitem);
        }
        /*lowit=container.end();
        lowit--;
        cout << lowit->second << endl;*/
        cout << container.rbegin()->second << endl; //rbegin is reverse begin
    }
    return 0;
}
