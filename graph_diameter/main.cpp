#include <bits/stdc++.h>

using namespace std;

struct node
{
    int first,second,parent,offset;
};

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n;
        cin >> n;
        node tree[n];
        for(int i=0;i<n;i++){
            tree[i].first=tree[i].second=tree[i].offset=0;
            tree[i].parent=-1;
        }
        for(int i=0;i<n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            tree[b].parent=a;
            tree[a].offset++;
        }
        queue<int> que;
        for(int i=0;i<n;i++)
            if(!tree[i].offset)
                que.push(i);
        while(!que.empty()){
            int tmp=que.front();
            int parent=tree[tmp].parent;
            que.pop();
            if(tree[tmp].first+1>=tree[parent].first){
                tree[parent].second=tree[parent].first;
                tree[parent].first=tree[tmp].first+1;
            }
            else if(tree[tmp].first+1>tree[parent].second&&tree[tmp].first<tree[parent].first){
                tree[parent].second=tree[tmp].first+1;
            }
            tree[parent].offset--;
            if(!tree[parent].offset)
                que.push(parent);
        }
        //cout << "qq";
        int ans=0;
        //cout <<"i"<<'\t'<< "first" <<'\t'<< "second" << endl;
        for(int i=0;i<n;i++){
            ans=max(ans,tree[i].first+tree[i].second);
            //cout << i<<'\t'<<tree[i].first <<'\t'<< tree[i].second << endl;
        }
        cout << ans << endl;

    }
    return 0;
}
