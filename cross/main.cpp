#include <bits/stdc++.h>
#define LL long long

using namespace std;

struct rect{
    LL x,y1,y2,w;
    bool start;
    bool operator <(const rect& b)const{return x<b.x;};
    rect(LL a,LL b,LL c,LL d,LL e)
        :x(a),y1(b),y2(c),w(d),start(e){}
};

struct node{
    LL left,right,maxV,change;
};

node seg_tree[100000];

void buildTree(LL root,LL left,LL right)
{
    seg_tree[root].left=left;
    seg_tree[root].right=right;
    seg_tree[root].maxV=0;
    seg_tree[root].change=0;
    if(left!=right){
        LL mid=(left+right)/2;
        buildTree(2*root,left,mid);
        buildTree(2*root+1,mid+1,right);
    }
}

void update(LL pos,LL left,LL right,LL weight)
{
    if(seg_tree[pos].left>right||seg_tree[pos].right<left)
        return;
    if(seg_tree[pos].left==left&&seg_tree[pos].right==right){
        seg_tree[pos].change+=weight;
        seg_tree[pos].maxV+=weight;
        return;
    }
    LL mid=(seg_tree[pos].left+seg_tree[pos].right)/2;
    if(right<=mid)
        update(2*pos,left,right,weight);
    else if(left>mid)
        update(2*pos+1,left,right,weight);
    else{
        //cout << "qq\n";
        update(2*pos,left,mid,weight);
        update(2*pos+1,mid+1,right,weight);
    }
    seg_tree[pos].maxV=max(seg_tree[2*pos].maxV,seg_tree[2*pos+1].maxV)+seg_tree[pos].change;
    /*cout << "pos:" << pos << " posmax:" << seg_tree[pos].maxV << endl;
    cout << "seg left:" << seg_tree[pos].left << " seg right:" << seg_tree[pos].right << endl;
    cout << "left:" << left << " right:" << right << " mid:" << mid<<endl;*/
    return;
}

//int query(int pos,int left,int right,)

int main()
{
    freopen("cross_03.in","r",stdin);
    int ncase;
    cin >> ncase;
    while(ncase--){
        LL num,seg_size=1;
        cin >> num;
        vector<LL> change,tmp;
        vector<rect> x_value;
        //int change[2*num];
        for(int i=0;i<num;i++){
            LL x1,x2,y1,y2,w;
            //scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&w);
            cin >> x1>>y1>>x2>>y2>>w;
            tmp.push_back(y1);
            tmp.push_back(y2);
            x_value.push_back(rect(x1,y1,y2,w,true));
            x_value.push_back(rect(x2+1,y1,y2,w,false));
        }
        sort(tmp.begin(),tmp.end());
        sort(x_value.begin(),x_value.end());
        change.push_back(tmp[0]);
        for(int i=1;i<tmp.size();i++){
            if(tmp[i]!=tmp[i-1])
                change.push_back(tmp[i]);
        }
        tmp.erase(tmp.begin(),tmp.end());
        //for(int i=0;i<change.size();i++)
        //    cout << change[i] << endl;
        //cout << "change:" << change.size() << endl;
        while(seg_size<=change.size()*2)
            seg_size<<=1;
        //cout << "size:"<<seg_size<<endl;
        buildTree(1,0,change.size()-1);
        for(int i=0;i<x_value.size();i++){
            if(x_value[i].start){
                int a=lower_bound(change.begin(),change.end(),x_value[i].y1)-change.begin();
                int b=lower_bound(change.begin(),change.end(),x_value[i].y2)-change.begin();
                update(1,a,b,x_value[i].w);
                /*cout << "ori:" << seg_tree[1].maxV << endl;
                cout << a<<" "<<b<<" "<<x_value[i].w << endl;*/
            }
        }
        //cout << "ori:" << seg_tree[1].maxV << endl;
        LL result=0;
        LL x_sum=0;
        for(int i=0;i<x_value.size();i++){
            int a=lower_bound(change.begin(),change.end(),x_value[i].y1)-change.begin();
            int b=lower_bound(change.begin(),change.end(),x_value[i].y2)-change.begin();
            if(x_value[i].start){
                x_sum+=x_value[i].w;
                update(1,a,b,-x_value[i].w);
                /*cout << "x:" << x_value[i].x <<endl;
                cout << "a:" << change[a] << " b:" << change[b]<<endl;
                cout << x_sum << " "<< seg_tree[1].maxV << endl;*/
                if(result<x_sum+seg_tree[1].maxV)
                    result=x_sum+seg_tree[1].maxV;
            }
            else{
                x_sum-=x_value[i].w;
                update(1,a,b,x_value[i].w);
                if(result<x_sum+seg_tree[1].maxV)
                    result=x_sum+seg_tree[1].maxV;
            }
        }
        cout << result << endl;
    }
    return 0;
}
