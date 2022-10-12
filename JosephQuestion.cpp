#include<iostream>
#include<cstdlib>

int cnt=0;
struct CircleLnode{
    int data;
    CircleLnode* next;
};

CircleLnode* CreateCircleNode(CircleLnode** head, int element){
    CircleLnode* NewNode=(CircleLnode*)malloc(sizeof(CircleLnode));
    NewNode->data=element;
    NewNode->next=*head;//指向头节点
    return NewNode;
}

int DeleteNode(CircleLnode** head,int index){
    CircleLnode *p=*head,*q;
    int i=1;
    while(i<index-1){
        p=p->next;
        i++;
    }
    q=p->next;
    p->next=q->next;
    // getchar();
    printf("%d",q->data);
    cnt++;
    if(cnt==10){
        printf("\n");
        cnt=0;
    }
    else printf(" ");
    *head=q->next;
    free(q);
    return 1;
}
int main()
{
    int n=0,k=0,m=0;
    scanf("%d,%d,%d",&n,&k,&m);
    if(n<1||k<1||m<1){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    else if(k>n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    else{
        CircleLnode *head,*p=CreateCircleNode(&p,1),*q=NULL;
        head=p;
        for(int i=2;i<=n;++i){
            q=CreateCircleNode(&head,i);
            p->next=q;
            p=p->next;
        }
        p->next=head;//达成循环
        //找到编号为k的人
        int i=1;
        p=head;
        while(p&&i<k){
            p=p->next;
            i++;
        }
        head=p;//转移head指针位置
        while(head){
            
            if(head->next==head){
                printf("%d\n",head->data);
                free(head);
                head=NULL;
            }
            else{
                DeleteNode(&head,m);
            }
            // if(head) printf(" ");
            // else printf("\n");
        }
        return 0;
    }
}