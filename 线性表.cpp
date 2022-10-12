#include<iostream>
#include<cstring>
using namespace std;
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int len;
}LNode,*List;//一般结构都需要一个指示它的指针类型，以方便创建空顺序表
//初始化线性表
List InitList(){
    List PList;
    PList=(List)malloc(sizeof(LNode));
    PList->len=0;
    return PList;
}
//查找线性表是否含有指定元素
bool Find(List PList,int x){
    int i=0;
    while(i<PList->len&&PList->data[i]!=x)
        i++;
    if(i>=PList->len) return false;
    else return true;
}
//线性表的插入和存储
//index代表第几个（1<=index<=MAXSIZE）
bool Insert(List PList,int index,int x){
    if(PList->len==MAXSIZE){
        printf("表满\n");
        return false;
    }
    if(index<1||index>MAXSIZE-1){//位置不合法，在线性表之前或者之后
        printf("不合法\n");
        return false;
    }
    //不考虑边界时，也就是确定插入元素后的元素一定也要后移
    int i=PList->len;
    for(i=PList->len;i>index;--i)
        PList->data[i]=PList->data[i-1];
    PList->data[index-1]=x;
    if(PList->len+1<=MAXSIZE) PList->len++;
    return true;
}
//线性表的删除
//index代表第几个（1<=index<=MAXSIZE）
bool Delete(List PList,int index,int x){
    
}
int main()
{

    return 0;
}