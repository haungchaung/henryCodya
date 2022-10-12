#include<iostream>
#include<cstring>

using namespace std;

struct Node{
    int data;
    Node* next;
};

int main()
{
    Node a[10][2];
    memset(a,'\0',sizeof(a));
    printf("第一行第一个%p\n第一行最后一个%p\n第二行第一个%p\n",&a[0][0],&a[0][1],&a[1][0]);
    return 0; 
}