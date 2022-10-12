#include <iostream>  
#include <stack>  
#include <string>  
using namespace std;  
  
stack<char> s, ans;  
  
int comp(char a, char b)//a为目前正在遍历的，b为操作符栈顶元素  
{  
    int x = 0, y = 0;  
    switch (a)  
    {  
    case '^':  //遍历元素是指数和栈顶元素是指数是不同级别的
    {  
        x = 7;  
        break;  
    }  
    case '*':  
    {  
        x = 4;  
        break;  
    }  
    case '/':  
    {  
        x = 4;  
        break;  
    }  
    case '+':  
    {  
        x = 2;  
        break;  
    }  
    case '-':  
    {  
        x = 2;  
        break;  
    }  
    }  
    
    
    
    switch (b)  
    {  
    case '^':  
    {  
        y = 6;  
        break;  
    }  
    case '*':  
    {  
        y = 5;  
        break;  
    }  
    case '/':  
    {  
        y = 5;  
        break;  
    }  
    case '(':  
    {  
        y = 1;  
        break;  
    }  
    case '+':  
    {  
        y = 3;  
        break;  
    }  
    case '-':  
    {  
        y = 3;  
        break;  
    }  
    }  
    if (y >= x)  //若栈顶元素优先级高于或等于遍历元素
    {  
        return 1;  
    }  
    else  //栈顶元素优先级低于遍历元素
    {  
        return 0;  
    }  
}  
  
char in[1001], aa[1001];  
int main()  
{  
    int n;  
    cin >> n;  
    while (n--)  
    {  
        cin >> in;  
  
        for (int t = 0; in[t] != '#'; t++)  
        {  
            if (t == 0 && in[t] == '-')  
            {  
             
                ans.push(in[t]);  
            }  
            else if (isalnum(in[t]))  
            {  
                 
                ans.push(in[t]);  
            }  
            else if (in[t] == '(')  
            {  
                s.push(in[t]);  
            }  
            else if (in[t] == ')')  
            {  
                while (s.top() != '(')  
                {  
                   
                    ans.push(s.top());  
                    s.pop();  
                }  
                s.pop();  
            }  
            else if (in[t] == '-' && (in[t - 1] == '(' || in[t - 1] == '*' || in[t - 1] == '/' || in[t - 1] == '%' || in[t - 1] == '+' || in[t - 1] == '-'))  
            {  
     
                ans.push(in[t]);  
            }  
            else  
            {  
                if (s.empty())  
                {  
                    s.push(in[t]);  
                }  
                else  
                {  
                    while (1)  
                    {  
                        if (s.empty())  
                        {  
                            s.push(in[t]);  
                            break;  
                        }  
  
                        if (comp(in[t], s.top()))  
                        {  
  
                            ans.push(s.top());  
                            s.pop();  
                            continue;  
                        }  
                        else  
                        {  
                            s.push(in[t]);  
                            break;  
                        }  
                    }  
                }  
            }  
        }  
        while (!s.empty())  
        {  
            ans.push(s.top());  
            s.pop();  
        }  
        int i = 0;  
        while (!ans.empty())  
        {  
            aa[i++] = ans.top();  
            ans.pop();  
        }  
        i--;  
        for (; i >=0; i--)  
        {  
            printf("%c",aa[i]);  
        }  
        cout << endl;  
    }  
}