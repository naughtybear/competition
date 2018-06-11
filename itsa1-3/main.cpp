#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node{
    char name[5];
    int weight;
};

int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--){
        int c,count=2;
        char array[200],*tmp;
        char *delim="(),";
        node tree[100];

        scanf("%d",&c);
        scanf("%s",array);
        strcpy(tree[1].name,strtok(array,delim));
        tree[1].weight=atoi(strtok(NULL,delim));
        while(tmp=strtok(NULL,delim)){
            strcpy(tree[count].name,tmp);
            tree[count].weight=atoi(strtok(NULL,delim));
            count++;
        }
        /*cout << count << "*****" << endl;
        for(int i=1;i<count;i++){
            cout << tree[i].name << " " << tree[i].weight << endl;
        }*/
        bool judge=false;
        for(int i=2;i<count;i++){
            if(tree[i/2].weight-tree[i].weight>=0){
                if(tree[i/2].weight-tree[i].weight<=c){
                    if(judge==false)
                        judge=true;
                    else
                        cout << " ";
                    cout << tree[i/2].name << tree[i].name;
                }
            }
            else{
                if(tree[i/2].weight-tree[i].weight>=-c){
                    if(judge==false)
                        judge=true;
                    else
                        cout << " ";
                    cout << tree[i/2].name << tree[i].name;
                }
            }
        }
       // cout << "1***";
        if(ncase){
            cout << endl;
        }
    }
    return 0;
}
