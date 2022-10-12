#include<iostream>
#define STACK_MIN_SIZE 100000

using namespace std;
typedef struct{
    int *base;
    int *top;
    int stack_size;
}Stack;

bool initStack(Stack& stack){
    stack.base=(int *)malloc(STACK_MIN_SIZE*sizeof(int));
    if(stack.base==NULL) return false;
    stack.top=stack.base;
    stack.stack_size;
    return true;
}

int main()
{
    Stack *stack_test=(Stack*)malloc(sizeof(Stack));

    return 0;
}