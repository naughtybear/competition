#include <bits/stdc++.h>

using namespace std;

struct element{
    int index,tag,priority;
    bool valid,dirty;
};


bool miss(element **cache,int index,int tag,int assnum)
//true mean dirty
{
    bool flag=false;
    for(int i=0;i<assnum;i++){
        cache[index][i].priority--;
        if(!cache[index][i].valid){
            cache[index][i].valid=true;
            cache[index][i].dirty=false;
            cache[index][i].index=index;
            cache[index][i].priority=assnum;
            cache[index][i].tag=tag;
            break;
        }
        else if(cache[index][i].priority==0){
            if(cache[index][i].dirty==true)
                flag=true;
            cache[index][i].dirty=false;
            cache[index][i].index=index;
            cache[index][i].priority=assnum;
            cache[index][i].tag=tag;
        }
    }
    return flag;
}

void LRU(element **cache,int index,int pos,int assnum)
{
    for(int i=0;i<assnum;i++){
        if(cache[index][i].priority>cache[index][pos].priority)
            cache[index][i].priority--;
    }
    cache[index][pos].priority=assnum;
}

int findpos(element **cache,int index,int tag,int assnum)
{
    for(int i=0;i<assnum;i++){
        if(cache[index][i].valid&&cache[index][i].tag==tag)
            return i;
    }
    return -1;
}

int main(int argc,char *argv[])
{
    int cache_size=atoi(argv[1])*1024;
    int block_size=atoi(argv[2]);
    char associativity=argv[3][0];
    char replace_policy[5];
    int label,address;
    cache_size/=block_size;
    int assnum=(associativity>='1'&&associativity<='9')?(associativity-48):cache_size;
    int setnum=cache_size/assnum;
    //element cache[256][256];
    //cout << "q";
    element *cache[256*1024];
    int demand_fetch=0,cache_hit=0,cache_miss=0,read_data=0,write_data=0,BFM=0,BTM=0;

    strcpy(replace_policy,argv[4]);
    freopen(argv[5],"r",stdin);
    for(int i=0;i<setnum;i++){
        cache[i]= new element[assnum];
    }
    for(int i=0;i<setnum;i++)
        for(int j=0;j<assnum;j++)
            cache[i][j].valid=false;
    //cout << setnum << "  " << assnum << endl;
    while(scanf("%d%x",&label,&address)!=EOF){
        //cout << a << endl << b << endl;
        address=address/block_size;
        int index=address%setnum;
        int tag=address/setnum;
        int pos=findpos(cache,index,tag,assnum);

        demand_fetch++;
        if(label==0){
            read_data++;
            if(pos<0){
                cache_miss++;
                if(miss(cache,index,tag,assnum)){
                    BTM+=block_size;
                }
                BFM+=block_size;
            }
            else{
                cache_hit++;
                if(strcmp(replace_policy,"LRU")==0){
                    LRU(cache,index,pos,assnum);
                }
            }
        }
        else if(label==1){
            write_data++;
            if(pos<0){
                cache_miss++;
                if(miss(cache,index,tag,assnum)){
                    BTM+=block_size;
                }
                BFM+=block_size;
            }
            else{
                cache_hit++;
                if(strcmp(replace_policy,"LRU")==0){
                    LRU(cache,index,pos,assnum);
                }
            }
            for(int i=0;i<assnum;i++)
                if(cache[index][i].tag==tag){
                    cache[index][i].dirty=true;
                    break;
                }
        }
        else if(label==2){
            if(pos<0){
                cache_miss++;
                if(miss(cache,index,tag,assnum)){
                    BTM+=block_size;
                }
                BFM+=block_size;
            }
            else{
                cache_hit++;
                if(strcmp(replace_policy,"LRU")==0){
                    LRU(cache,index,pos,assnum);
                }
            }
        }
    }
    for(int i=0;i<setnum;i++){
        for(int j=0;j<assnum;j++){
            if(cache[i][j].dirty==true)
                BTM+=block_size;
        }
    }
    cout << "Input file = " << argv[5] << endl
        << "Demand fetch = " << demand_fetch << endl
        << "Cache hit = " << cache_hit << endl
        << "Cache miss = " << cache_miss << endl;
    printf("Miss rate = %.4f\n",cache_miss/(float)demand_fetch);
    cout << "Read data = " << read_data << endl
        << "Write data = " << write_data << endl
        << "Bytes from Memory = " << BFM << endl
        << "Bytes to Memory = " << BTM << endl;
    return 0;
}
