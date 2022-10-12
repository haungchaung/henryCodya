/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  

//判断此处是否为循环节
int isloop(NODE *oldhead,NODE *newhead,int n,int m){
    NODE *p,*q;
    p=newhead;
    while(oldhead!=newhead){
        q=(NODE*)malloc(sizeof(NODE));
        q->data=n/m;
        p->next=q;
        n%=m;
        n*=10;


        oldhead=oldhead->next;
        p=p->next;
        if(p->data!=oldhead->data) break;//若相应位置的两个数不相同则，直接break    

    }
    if(oldhead==newhead) return 1;
    else return 0;
}
// void change( int n, int m, NODE *head ){
//     // 找到循环链为止
//     NODE *p=head,*q=(NODE*)malloc(sizeof(NODE));
//     n*=10;//目前的n比m小，因此*10相当于进一位。
//     p->next=q;
//     q->data=n/m;
//     n%=m;
//     n*=10;//上面两步都是对位数的操作，非常容易理解
//     NODE *oldhead=q;
//     while(n){//这个过程中n有可能归零
//         //创建接下来的节点
//         NODE *r=(NODE*)malloc(sizeof(NODE));
//         r->data=n/m;
//         r->next=NULL;
//         q->next=r;
//         n%=m;
//         n*=10;
//         q=oldhead;
//         while(q!=r){
//             if(q->data==r->data){
//                 if(!isloop(q,r,n,m)) q=q->next;/
//                 else{
//                     r->next=q->next;
//                     return;
//                 }
//             }
//             else q=q->next;
//         }
//     }
// }
void change(int n,int m,NODE *head)  
{  
    NODE *p,*q;  
    int i = 0, x = 0, computate = 1;  
    n *= 10;  
    x = n/m;  
    p = head;  
    q = (NODE *)malloc(sizeof(NODE));  
    q->data = x;  
    p->next = q;  
    p = q;  
    while(computate && i < 5000000)  
    {  
        n -= x*m;  
        n *= 10;  
        x = n/m;  
        q = (NODE *)malloc(sizeof(NODE));  
        q->data = x;  
        p->next = q;  
        p = q;  
        i++;  
        computate = n % m;  
    }  
    p->next = NULL;  
}  


void output( NODE * head, int kk )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  