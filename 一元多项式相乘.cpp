#include <stdio.h>  
#include<iostream>
#include <stdlib.h>  
using namespace std;
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
// #define N 100000
// int Coep[N];

void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
            sum = sum*10 + c - '0';  
        else if ( c == ',' )  
        {    
            if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
            sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}

void multiplication( NODE *h1, NODE *h2 , NODE *h3 ){  
    NODE *p1=h1,*p2=h2;  
  
  
  
    int Coef=0,Exp=0;   
    p1=h1->next,p2=h2->next;  
    NODE *index_prior,*index_cur;//index_prior->next指向当前计算出的节点应该存储的位置  
    while(p1!=NULL){  
        while(p2!=NULL){  
            Coef=(p1->coef)*(p2->coef);  
            // cout<<Coef<<endl;  
            if(Coef==0){  
                p2=p2->next;  
                continue;  
            }  
  
            Exp=p1->exp+p2->exp;  
            // cout<<"Exp="<<Exp<<endl;  
            if(h3->next==NULL){//第一个节点被创建  
                NODE *creat=(NODE*)malloc(sizeof(NODE));  
                creat->coef=Coef;  
                // cout<<"Coef="<<creat->coef<<endl;  
                creat->exp=Exp;  
                // cout<<"Exp="<<creat->exp<<endl;  
                creat->next=NULL;  
                h3->next=creat;  
  
                index_prior=h3;  
                index_cur=h3->next;  
                p2=p2->next;  
                continue;  
            }  
  
            //寻找应当插入的位置  
            else{  
                if(index_prior->exp<Exp){
                    index_cur=index_prior->next;
                    while(index_prior->next!=NULL&&index_prior->next->exp<Exp){
                        index_prior=index_prior->next;
                        index_cur=index_prior->next;
                    }
                }
                else if(index_prior->exp>=Exp){
                    index_prior=h3;
                    while(index_prior->next!=NULL&&index_prior->next->exp<Exp){
                        index_prior=index_prior->next;
                        index_cur=index_prior->next;
                    }
                }
            }  
              
            if(index_cur==NULL){//若插入位置为空  
                NODE *creat=(NODE*)malloc(sizeof(NODE));  
                creat->coef=Coef;  
                creat->exp=Exp;  
                creat->next=NULL;  
                index_cur=creat;  
                index_prior->next=creat;  
            }  
            else{//插入位置非空  
                if(index_cur->exp==Exp){//指数相同，需要合并  
                    index_cur->coef=index_cur->coef+Coef;  
                    if(index_cur->coef==0){  
                        NODE *dele=index_cur;  
                        index_prior->next=dele->next;  
                        index_cur=index_prior->next;  
                        free(dele);  
                    }  
                }  
                else if(index_cur->exp>Exp){  
                    //因为之前已经考虑过最后一个节点是否为空的情况，实际上已经包含，当前节点指数最大，因此只考虑当前节点比前面的小  
                    NODE *creat=(NODE*)malloc(sizeof(NODE));  
                    creat->coef=Coef;  
                    creat->exp=Exp;  
                    index_prior->next=creat;  
                    creat->next=index_cur;  
                }  
            }  
            index_cur=h3->next;  
            p2=p2->next;  
        }  
        p1=p1->next;  
        p2=h2->next;  
    }  
  
      
  
    if(h3->next==NULL){  
        NODE* n=(NODE*)malloc(sizeof(NODE));  
        n->coef=0;  
        n->exp=0;  
        n->next=NULL;  
        h3->next=n;  
    }  
    return;  
}  