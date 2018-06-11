#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("out.txt","r",stdin);
    int num,range;
    while(cin >> num >> range){
        if(num==0&&range==0)
            break;
        int input;
        long long ans=0;
        deque<pair<int,int>> max,min;
        max.push_back(pair<int,int>{-999999999,-1});
        min.push_back(pair<int,int>{999999999,-1});
        for(int i=0;i<num;i++){
            scanf("%d",&input);
            //cout << input << endl;
            while(!max.empty()){
                if(input>max.back().first)
                    max.pop_back();
                else
                    break;
            }
            max.push_back(pair<int,int>{input,i});
            while(max.front().second<i-range){
                //cout << "qqqq";
                max.pop_front();
            }

            while(!min.empty()){
                if(input<min.back().first)
                    min.pop_back();
                else
                    break;
            }
            min.push_back(pair<int,int>{input,i});
            while(min.front().second<i-range){
                //cout << "aaa";
                min.pop_front();
            }
            if(max.front().first-min.front().first>ans)
                ans=max.front().first-min.front().first;
        }
        cout << ans << endl;
    }
    return 0;
}
