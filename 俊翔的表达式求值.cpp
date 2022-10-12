#include <stdio.h>         
#include <stdlib.h>         
#include<string.h>       
#include<math.h>       
       
   
char pro[9][9]={       
    {'>','>','<','<','<','>','>','<','<'},      
    {'>','>','<','<','<','>','>','<','<'},     
    {'>','>','>','>','<','>','>','<','>'},       
    {'>','>','>','>','<','>','>','<','>'},        
    {'<','<','<','<','<','=',' ','<','<'},         
    {'>','>','>','>',' ','>','>','>','>'},         
    {'<','<','<','<','<',' ','=','<','<'},         
    {'>','>','>','>','<','>','>','<','>'},    
    {'>','>','>','>','<','>','>','<','>'}      
};       
       
int op(int a, int b, char opt)       
{       
    if(opt=='+')       
    {       
        return a+b;       
    }       
    else if(opt=='-')       
    {       
        return a-b;       
    }       
    else if(opt=='*')       
    {       
        return a*b;       
    }       
    else if(opt=='/')       
    {       
        if(b==0)       
        {       
            printf("Divide 0.\n");       
            return 0x3f3f3f3f;       
        }       
        else       
        {       
            return a/b;       
        }       
    }       
    else if(opt=='%')       
    {       
        return a%b;       
    }       
    else if(opt=='^')       
    {       
        if(b>=0)       
        {       
            return pow(a,b);       
        }       
        else       
        {       
            printf("error.\n");       
            return 0x3f3f3f3f;       
        }       
    }       
    else       
    {       
        printf("error.\n");       
        return 0x3f3f3f3f;       
    }       
}       
       
int shu[100010];       
char opt[100010];       
char ex[100010];   
int main()   
{       
    int N;       
    int i,j,k,m,n,a,b;       
    int flag=0;       
    int flag1=0;       
    int flag2=0;       
    int flag3=0;       
    int flag4=0;       
    int flag5=0;       
    char Opt[9]={'+','-','*','/','(',')','#','^','%'};       
    memset(ex,'\0',sizeof(ex));       
    int exp=0,shup=-1,optp=-1;       
    scanf("%d",&N);       
    while(N--)       
    {       
        char c;       
        flag=2;       
        flag1=0;       
        flag2=0;       
        flag3=0;       
        flag4=0;       
        flag5=0;       
        k=0;       
        int fuhaoyou=0;       
        scanf("%s",ex);       
        strcat(ex,"#");        
        opt[++optp]='#';           
        for(a=0;a<=strlen(ex)-3;a++)       
        {       
            flag5=0;       
            int fuhao=a;       
            if(ex[fuhao]=='+'||ex[fuhao]=='-'||ex[fuhao]=='*'||ex[fuhao]=='/'||ex[fuhao]=='%'||ex[fuhao]=='^')       
            {       
                flag5++;       
                fuhao++;       
            }       
            if(ex[fuhao]=='+'||ex[fuhao]=='-'||ex[fuhao]=='*'||ex[fuhao]=='/'||ex[fuhao]=='%'||ex[fuhao]=='^')       
            {       
                flag5++;       
                fuhao++;       
            }       
            if(ex[fuhao]=='+'||ex[fuhao]=='-'||ex[fuhao]=='*'||ex[fuhao]=='/'||ex[fuhao]=='%'||ex[fuhao]=='^')       
            {       
                flag5++;       
                fuhao++;       
            }       
            if(flag5>=3)       
            {       
                printf("error.\n");       
                memset(ex,'\0',sizeof(ex));       
                memset(shu,0,sizeof(shu));       
                memset(opt,'\0',sizeof(opt));       
                shup=-1;       
                flag1++;       
                exp=0;       
                flag5=0;       
                optp=-1;       
                fuhaoyou++;       
                break;       
            }       
        }       
        while(ex[exp]!='#'||opt[optp]!='#')       
        {       
            if(fuhaoyou!=0)       
            {       
                break;       
            }       
            if(ex[exp]>='0'&&ex[exp]<='9')       
            {       
                if(flag==0)       
                {       
                    int aaa=0;       
                    aaa=shu[shup--]*10+(ex[exp++]-'0');       
                    shu[++shup]=aaa;       
                    flag=0;       
                }       
                else       
                {       
                    shu[++shup]=ex[exp++]-'0';       
                    flag=0;       
                }       
            }       
            else       
            {       
                if(flag4==1)       
                {       
                    shu[0]*=-1;       
                    flag4=0;       
                }       
                if(flag==1)       
                {       
                    if(ex[exp]=='+'||ex[exp]=='-'||ex[exp]=='*'||ex[exp]=='/'||ex[exp]=='^'||ex[exp]=='%')       
                    {       
                        printf("error.\n");       
                        flag1++;       
                        memset(ex,'\0',sizeof(ex));       
                        memset(shu,0,sizeof(shu));       
                        memset(opt,'\0',sizeof(opt));       
                        shup=-1;       
                        optp=-1;       
                        exp=0;       
                        break;       
                    }       
                }       
                if(ex[exp]=='(')       
                {       
                    flag=1;       
                    int s=exp+1;       
                    int d=s+1;       
                    if(ex[s]=='-'&&ex[d]>='0'&&ex[d]<='9')       
                    {       
                        flag=2;       
                        flag4=1;       
                        exp=s+1;       
                        opt[++optp]='(';       
                        continue;   
                    }       
                }       
                else       
                {       
                    flag=2;       
                }       
                if(optp==-1)       
                {       
                    printf("error.\n");       
                    memset(ex,'\0',sizeof(ex));       
                    memset(shu,0,sizeof(shu));       
                    memset(opt,'\0',sizeof(opt));       
                    flag1++;       
                    shup=-1;       
                    optp=-1;       
                    exp=0;       
                    break;       
                }       
                else       
                {       
                    char com=opt[optp--];       
                    char Ex;       
                    for(i=0;i<9;i++)       
                    {       
                        if(Opt[i]==com)       
                        {       
                            m=i;       
                        }       
                        if(Opt[i]==ex[exp])       
                        {       
                            n=i;       
                        }       
                    }       
                    Ex=pro[m][n];       
                    if(Ex=='<')       
                    {       
                        if(exp==0&&ex[exp]=='-')       
                        {       
                            flag4=1;       
                            exp++;       
                            optp++;       
                            continue;       
                        }       
                        opt[++optp]=com;       
                        opt[++optp]=ex[exp++];       
                               
                        continue;       
                    }       
                    else if(Ex=='=')       
                    {       
                        exp++;       
                        continue;       
                    }       
                    else if(Ex==' ')       
                    {       
                        printf("error.\n");       
                        memset(ex,'\0',sizeof(ex));       
                        memset(shu,0,sizeof(shu));       
                        memset(opt,'\0',sizeof(opt));       
                        shup=-1;       
                        flag1++;       
                        exp=0;       
                        optp=-1;       
                        break;       
                    }       
                    else       
                    {       
                        int q=exp-1;       
                        if(ex[exp]=='-')       
                        {       
                            if(ex[q]=='('||ex[q]=='*'||ex[q]=='/'||ex[q]=='%'||ex[q]=='+'||ex[q]=='-')       
                            {       
                                opt[++optp]=com;       
                                exp++;       
                                flag2=1;       
                                continue;       
                            }       
                        }       
                        if(flag2==1)       
                        {       
                            shu[shup]*=-1;       
                            flag2=0;           
                        }       
                        if(flag3==1)       
                        {       
                            shu[--shup]*=-1;       
                            shup++;       
                            flag3=0;       
                        }       
                        b=shu[shup--];       
                        a=shu[shup--];       
                        k=op(a,b,com);       
                        if(k==0x3f3f3f3f)       
                        {       
                            memset(ex,'\0',sizeof(ex));       
                            shup=-1;       
                            optp=-1;       
                            exp=0;       
                            memset(shu,0,sizeof(shu));       
                            memset(opt,'\0',sizeof(opt));       
                            break;       
                        }       
                        else       
                        {       
                            shu[++shup]=k;       
                        }       
                        continue;       
                    }       
                    exp++;       
                }       
                       
            }       
                   
        }       
        if(shup==0&&optp==0)       
        {       
            if(flag4==1)       
            {       
                printf("%d\n",-shu[shup]);       
                flag4=0;       
            }       
            else       
            {       
                printf("%d\n",shu[shup]);       
            }       
        }       
        else       
        {       
            if(k!=0x3f3f3f3f&&flag1==0)       
            {       
                printf("error.\n");       
            }       
        }       
        memset(ex,'\0',sizeof(ex));       
        memset(shu,0,sizeof(shu));       
        memset(opt,'\0',sizeof(opt));       
        exp=0;       
        fuhaoyou=0;       
        shup=-1;       
        flag1=0;       
        optp=-1;       
    }       
    return 0;       
}  