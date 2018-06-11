#include <bits/stdc++.h>

using namespace std;

struct node
{
    int left,right,weight;
    bool operator <(const node& b)const{return right<b.right;}
};

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int n;
        cin >> n;
        node input[n+1];
        input[0].left=input[0].right=input[0].weight=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&input[i].left,&input[i].right,&input[i].weight);
        }
        sort(input,input+n+1);
        /*for(int i=0;i<=n;i++)
            printf("%d %d %d\n",input[i].left,input[i].right,input[i].weight);*/
    }
    return 0;
}
