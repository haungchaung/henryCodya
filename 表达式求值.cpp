#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    int N=0;
    scanf("%d",&N);
    getchar();
    string *expression;
    expression=(string*)malloc(sizeof(string)*N);
    

    // cout<<expression[0]<<endl;
    
    for(int i=0;i<N;++i){
        getline(cin,expression[i]);
        cout<<expression[i]<<endl;
    }
    // for(int i=0;i<N;++i){
    //     cout<<expression[i]<<endl;
    // }
    return 0;
}