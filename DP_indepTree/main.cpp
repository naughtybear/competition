#include <bits/stdc++.h>

using namespace std;

struct node
{
    int parent,offset,choice,notchoice;
};

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n;
        cin >> n;
        node tree[n+1];
        for(int i=0;i<=n;i++)
            tree[i].offset=0;
        cin >>tree[1].choice;
        tree[1].parent=-1;
        tree[1].notchoice=0;
        for(int i=2;i<=n;i++){
            cin >> tree[i].parent >> tree[i].choice;
            tree[tree[i].parent].offset++;
            tree[i].notchoice=0;
        }
        queue<int> que;
        for(int i=1;i<=n;i++){
            if(!tree[i].offset)
                que.push(i);
        }
        while(!que.empty()){
            int num=que.front();
            //cout << tree[num].choice <<" "<<tree[num].notchoice<<endl;
            que.pop();
            tree[tree[num].parent].offset--;
            if(!tree[tree[num].parent].offset)
                que.push(tree[num].parent);
            tree[tree[num].parent].choice+=tree[num].notchoice;
            tree[tree[num].parent].notchoice+=max(tree[num].choice,tree[num].notchoice);
        }
        cout << max(tree[1].choice,tree[1].notchoice) << endl;
    }
    return 0;
}
