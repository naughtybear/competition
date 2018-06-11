//40441081 資工三 陳柏諺
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <algorithm>
#include <sys/time.h>
#define size1 8
#define size2 50
#define steps 400000

using namespace std;

void initArray(int *array,int size)
{
    pair<int,int> tmp[size];
    for(int i=0;i<size;i++){
        tmp[i].first=rand();
        tmp[i].second=i;
    }
    sort(tmp,tmp+size);
    for(int i=0;i<size;i++)
        array[i]=tmp[i].second;
}

int countAttack(int *array,int size)
{
    int count=0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]==array[j]||(array[i]-array[j])==i-j||(array[i]-array[j])==j-i){
                count++;
            }
        }
    }
    return count;
}

int hillClimbing(int *array,int size,int step)
{
    int last_attack=countAttack(array,size);
    int min_attack=100000;
    for(int i=0;i<step;i++){
        pair<int,int> min_pos;
        int tmp_attack;
        int tmparray[size];

        min_attack=100000;
        for(int j=0;j<size;j++)
            tmparray[j]=array[j];
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                if(array[j]!=k){
                    tmparray[j]=k;
                    tmp_attack=countAttack(tmparray,size);
                    if(tmp_attack<min_attack){
                        min_pos.first=j;
                        min_pos.second=k;
                        min_attack=tmp_attack;
                    }
                }
            }
            tmparray[j]=array[j];
        }
        //cout << min_attack <<" "<< last_attack << endl;
        if(min_attack>=last_attack){
                //cout << "q";
                return last_attack;
        }
        array[min_pos.first]=min_pos.second;
        last_attack=min_attack;
    }
    return min_attack;
}

int find(int *parent,int size,int current)
{
    while(parent[current]!=-1){
        current=parent[current];
    }
    return current;
}

void crossover(int *array1,int *array2,int size)
{
    int parent[size];
    for(int i=0;i<size;i++)
        parent[i]=-1;
    for(int i=0;i<size;i++){
        int parent1,parent2;
        parent1=find(parent,size,array1[i]);
        parent2=find(parent,size,array2[i]);
        if(parent1>parent2)
            parent[parent1]=parent2;
        else if(parent1<parent2)
            parent[parent2]=parent1;
    }
    vector<int> group;
    for(int i=0;i<size;i++){
        if(parent[i]==-1)
            group.push_back(i);
        else
            parent[i]=find(parent,size,parent[i]);
    }
    for(int i=0;i<group.size();i+=2){
        for(int j=0;j<size;j++){
            if(parent[array1[j]]==group[i]||parent[array2[j]]==group[i]){
                int tmp=array1[j];
                array1[j]=array2[j];
                array2[j]=tmp;
            }
        }
    }
}

void mutation(int *array, int size)
{
    int pos1=rand()%size;
    int pos2=rand()%size;
    int tmp=array[pos1];
    array[pos1]=array[pos2];
    array[pos2]=tmp;
}

int genetic(int size,int step)
{
    int pool[100][size];
    int pool_attack[100];
    int tmp_new1[size],tmp_new2[size],tmp_attack1,tmp_attack2;

    for(int i=0;i<100;i++){
        initArray(pool[i],size);
        pool_attack[i]=countAttack(pool[i],size);
    }
    for(int i=0;i<step;i++){
        int minpos1=0,minpos2=1;
        int maxpos1=0,maxpos2=1;
        if(pool_attack[0]>pool_attack[1]){
            minpos1=1;
            minpos2=0;
        }
        else if(pool_attack[0]<pool_attack[1]){
            maxpos1=1;
            maxpos2=0;
        }
        for(int j=2;j<100;j++){
            if(pool_attack[j]<pool_attack[minpos1])
                minpos1=j;
            else if(pool_attack[j]<pool_attack[minpos2])
                minpos2=j;
            if(pool_attack[j]>pool_attack[maxpos1])
                maxpos1=j;
            else if(pool_attack[j]>pool_attack[maxpos2])
                maxpos2=j;
        }
        for(int j=0;j<size;j++){
            tmp_new1[j]=pool[minpos1][j];
            tmp_new2[j]=pool[minpos2][j];
        }
        crossover(tmp_new1,tmp_new2,size);
        mutation(tmp_new1,size);
        mutation(tmp_new2,size);
        tmp_attack1=countAttack(tmp_new1,size);
        tmp_attack2=countAttack(tmp_new2,size);
        if(pool_attack[maxpos2]>min(tmp_attack1,tmp_attack2)&&pool_attack[maxpos1]>max(tmp_attack1,tmp_attack2)){
            pool_attack[maxpos2]=tmp_attack1;
            pool_attack[maxpos1]=tmp_attack2;
            for(int j=0;j<size;j++){
                pool[maxpos1][j]=tmp_new1[j];
                pool[maxpos2][j]=tmp_new2[j];
            }
        }
        else if(pool_attack[maxpos2]<min(tmp_attack1,tmp_attack2)&&pool_attack[maxpos1]>min(tmp_attack1,tmp_attack2)){
            pool_attack[maxpos1]=min(tmp_attack1,tmp_attack2);
            if(tmp_attack1>tmp_attack2){
                pool_attack[maxpos1]=tmp_attack2;
                for(int j=0;j<size;j++)
                    pool[maxpos1][j]=tmp_new2[j];
            }
            else{
                pool_attack[maxpos1]=tmp_attack1;
                for(int j=0;j<size;j++)
                    pool[maxpos1][j]=tmp_new1[j];
            }
        }
    }
    int result=10000;
    for(int i=0;i<100;i++){
        if(pool_attack[i]<result)
            result=pool_attack[i];
    }
    return result;
}

int main()
{
    int array[size2];
    int attacks=0;
    struct timeval start;
    struct timeval end;
    int success=0,tmp;

    srand(time(NULL));
    gettimeofday(&start,NULL);
    for(int i=0;i<30;i++){
        initArray(array,size1);
        tmp=hillClimbing(array,size1,steps);
        if(tmp==0)
            success++;
        attacks+=tmp;
    }
    gettimeofday(&end,NULL);
    cout << "8*8 hillclimbing:\n\taverange attacks: " << attacks/30.0 << endl;
    double time=((end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0 )/30 ;
    cout << "\taverange running time: "<< time << endl;
    cout << "\tsuccess rate: "<< success/30.0 << endl;
    attacks=success=0;
    gettimeofday(&start,NULL);
    for(int i=0;i<30;i++){
        tmp=genetic(size1,steps);
        if(tmp==0)
            success++;
        attacks+=tmp;
    }
    gettimeofday(&end,NULL);
    cout << "8*8 genatic:\n\taverange attacks: " << attacks/30.0 << endl;
    time=((end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0 )/30 ;
    cout << "\taverange running time: "<< time << endl;
    cout << "\tsuccess rate: "<< success/30.0 << endl;

    attacks=success=0;
    gettimeofday(&start,NULL);
    for(int i=0;i<30;i++){
        initArray(array,size2);
        tmp=hillClimbing(array,size2,steps);
        if(tmp==0)
            success++;
        attacks+=tmp;
    }
    gettimeofday(&end,NULL);
    cout << "50*50 hillclimbing:\n\taverange attacks: " << attacks/30.0 << endl;
    time=((end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0 )/30 ;
    cout << "\taverange running time: "<< time << endl;
    cout << "\tsuccess rate: "<< success/30.0 << endl;
    attacks=success=0;
    gettimeofday(&start,NULL);
    for(int i=0;i<30;i++){
        tmp=genetic(size2,steps);
        if(tmp==0)
            success++;
        attacks+=tmp;
    }
    gettimeofday(&end,NULL);
    cout << "50*50 genatic:\n\taverange attacks: " << attacks/30.0 << endl;
    time=((end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0 )/30 ;
    cout << "\taverange running time: "<< time << endl;
    cout << "\tsuccess rate: "<< success/30.0 << endl;
    return 0;
}
