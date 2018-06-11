#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct shape
{
    int x,lower_y,upper_y;
    bool flag;
    shape(int tmp_x,int tmp_y1,int tmp_y2,bool tmp_flag)
    {
        x = tmp_x;
        lower_y = tmp_y1;
        upper_y = tmp_y2;
        flag = tmp_flag;
    }
    bool operator <(const shape& tmp) const { return x < tmp.x; }
};

int ms;
int rec_num;
int *height = NULL;
int *sum = NULL;
int *cnt = NULL;
vector <shape> rect;

void update(int p,int l,int r,int miny,int maxy,bool flag)
{
    if(height[r]<miny || maxy<height[l]) return;
    int c = p<<1 , mid = (l+r)>>1;
    if(miny <= height[l] && height[r] <= maxy)
    {
        if(flag) cnt[p]++;
        else cnt[p]--;
        if(cnt[p]) sum[p] = height[r]- height[l];
        else sum[p] = sum[c] +sum[c+1];
        return;
    }
    if(l+1>=r) return;
    update(c,l,mid,miny,maxy,flag);
    update(c+1,mid,r,miny,maxy,flag);
    if(cnt[p]) sum[p] = height[r] - height[l];
    else sum[p] = sum[c] + sum[c+1];
}

LL cope()
{
    sort(height+1,height+1+ms);
    int k=1;
    for(int i=2; i<=ms; i++)
        if(height[i] != height[k])
            height[++k] = height[i];
    ms = k;
    for(int i=0, lm = rec_num << 4; i<lm; i++)
        { sum[i] = 0; cnt[i] = 0; }
    LL union_area(0);
    sort(rect.begin(),rect.end());
    update(1,1,ms,rect[0].lower_y,rect[0].upper_y,rect[0].flag);
    for(int i=1; i<rect.size(); i++)
    {
        union_area += sum[1] * (rect[i].x - rect[i-1].x);
        update(1,1,ms,rect[i].lower_y,rect[i].upper_y,rect[i].flag);
    }
    return union_area;
}

void sol()
{
    ms = 0;
    int x1,y1,x2,y2;
    scanf("%d",&rec_num);
    height = new int [rec_num*3];
    sum = new int [rec_num*30];
    cnt = new int [rec_num*30];
    for(int i=1; i<=rec_num; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        rect.push_back(shape(x1,y1,y2,true));
        rect.push_back(shape(x2,y1,y2,false));
        height[++ms] = y1; height[++ms] = y2;
    }
    printf("%lld\n",cope());
    delete [] height;
    delete [] sum;
    delete [] cnt;
    rect.clear();
}

int main()
{
    int T; scanf("%d",&T);
    while(T--) sol();
    return 0;
}
