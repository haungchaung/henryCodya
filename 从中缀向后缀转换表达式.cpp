/*
首先确定两个栈，数字栈和符号栈，
1\ 从字符串读入为数字，
2\ 读入字符，
    */
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;
string rank_1="^",rank_2="*/",rank_3="+-";
int isRank(char c){
    if(rank_1.find(c)<1&&rank_1.find(c)>=0) return 1;
    else if(rank_2.find(c)<2&&rank_2.find(c)>=0) return 2;
    else if(rank_3.find(c)<2&&rank_3.find(c)>=0) return 3;
    else return -1;
    // else if(c=='('||c==')') return 4;
}
int main()
{
    int T=0;
    scanf("%d",&T);
    getchar();
    while(T--){
        stack<char> ans,signs;
        string str="";
        getline(cin,str);
        int len=str.length();
        for(int i=0;i<len;++i){
            if(str[i]=='#') break;
            if((str[i]<='Z'&&str[i]>='A')||(str[i]<='z'&&str[i]>='a'))
                ans.push(str[i]);
            
            
            else{
                if(str[i]=='(') signs.push(str[i]);//若遇到左括号，直接压入栈
                else if(str[i]==')'){//若遇到右括号，将操作符栈所有操作符均出栈并逐次压入表达式
                    while(!signs.empty()&&signs.top()!='('){//上述操作遇到左括号停止
                        ans.push(signs.top());
                        signs.pop();
                    }
                    if(signs.top()=='('){
                        signs.pop();
                    } //将左括号pop出去
                }

                
                else if(isRank(str[i])==1){//遇到最高级别的^符号
                    if(signs.empty()||signs.top()=='(') signs.push(str[i]);

                    else if(isRank(signs.top())>=1){//栈顶元素不论是什么，都要把指数^符号压入
                        signs.push(str[i]);
                    }

                    // else if(isRank(signs.top())==1){
                    //     while(!signs.empty()&&isRank(signs.top())==1&&signs.top()!='('){
                    //         ans.push(signs.top());
                    //         signs.pop();
                    //     }
                    //     signs.push(str[i]);
                    // }
                }


                else if(isRank(str[i])==2){//遇到第二等级的*/符号
                    if(signs.empty()||signs.top()=='(') signs.push(str[i]);

                    else if(isRank(signs.top())>2){
                        // printf("现在的栈顶是%c\n",signs.top());
                        signs.push(str[i]);//对于低等级栈顶操作符，可以直接压入栈
                    }

                    else if(isRank(signs.top())<=2){
                        while(!signs.empty()&&isRank(signs.top())<=2&&signs.top()!='('){
                            ans.push(signs.top());
                            signs.pop();
                        }
                        signs.push(str[i]);
                    }


                }
                else if(isRank(str[i])==3){//第三等级的+-符号
                    if(signs.empty()||signs.top()=='(') signs.push(str[i]);

                    else{
                        while(!signs.empty()&&signs.top()!='('){
                            ans.push(signs.top());
                            // printf("现在的栈顶是%c\n",ans.top());
                            signs.pop();
                        }
                        signs.push(str[i]);
                    }
                }
            }
        }
        while(!signs.empty()){
            ans.push(signs.top());
            signs.pop();
        }
        string Ans="";
        while(!ans.empty()){
            Ans+=ans.top();
            ans.pop();
        }
        reverse(Ans.begin(),Ans.end());
        cout<<Ans<<endl;
    }
    return 0;
}
