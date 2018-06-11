#include <bits/stdc++.h>

using namespace std;

struct node
{
    int a,b;
    node *next;
};

node* insert(node *in,node *head)
{
    int last;
    node *lasttmp,*current;
    current=head;
    if(head==NULL){
        head=(node*)malloc(sizeof(node));
        head->a=in->a;
        head->b=in->b;
        head->next=NULL;
        return head;
    }
    if(in->b==head->b){
        head->b+=in->b;
        return head;
    }
    while(current->next!=NULL){
        last=current->b;
        lasttmp=current;
        current=current->next;
        if(in->b>last&&in->b<current->b){
            node *tmp=(node*)malloc(sizeof(node));
            tmp->next=current;
            lasttmp->next=tmp;
            return head;
        }
        else if(in->b==current->b){
            current->a+=in->a;
            return head;
        }
    }
    if(current->b==in->b)
        current->a+=in->a;
    else{
        current->next=(node*)malloc(sizeof(node));
        current->next->a=in->a;
        current->next->b=in->b;
        current->next->next=NULL;
    }
    return head;
}

int main()
{
    freopen("in.txt","r",stdin);
    char buf[50];
    char *delim=" \n";
    node *head1,*head2,*headtmp;
    head1=head2=headtmp=NULL;
    node input;
    while(fgets(buf,50,stdin)!=NULL){
        if(buf[0]==':'){
            head1=headtmp;
            headtmp=NULL;
            continue;
        }
        input.a=atof(strtok(buf,delim));
        input.b=atoi(strtok(NULL,delim));
        headtmp=insert(&input,headtmp);
    }
    head2=headtmp;
    headtmp=NULL;
    node *tmp1,*tmp2;
    tmp1=head1;
    tmp2=head2;
    while(tmp1!=NULL){
        while(tmp2!=NULL){
            input.a=tmp1->a*tmp2->a;
            input.b=tmp1->b+tmp2->b;
            headtmp=insert(&input,headtmp);
            tmp2=tmp2->next;
        }
        tmp1=tmp1->next;
        tmp2=head2;
    }
    while(headtmp!=NULL){
        cout << headtmp->a <<" "<< headtmp->b << endl;
        headtmp=headtmp->next;
    }
    return 0;
}
