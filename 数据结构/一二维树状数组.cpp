#include<cstdio>
#include<cstring>
using namespace std;
int n,m,f[1005][1005],x1,x2,y1,y2,k,v[10005];
int lowbit(int x){
    return (-x) & x;
}
void push1(int x,int k){
    while(x <= n){
        v[x] += k;
        x += lowbit(x);
    }
}
int query1(int x){
    int s = 0;
    while(x){
        s += v[x];
    }
    return s;
}
void push2(int x1,int y1,int k){//二维 
    for(int x=x1;x<=n;x+= lowbit(x)){//x1 ——n 
        for(int y=y1;y<=n;y+= lowbit(y)){//y1——n 
            f[x][y]+=k;
        }
    }
}
int query2(int x1,int y1){//二维 
    int ans = 0;
    for(int x=x1;x;x -= lowbit(x)){// x1 ——0 
        for(int y=y1;y;y -=lowbit(y)){// y1 ——0 
            ans +=f[x][y];
        }
    }
    return ans;
}
int main(){
    int T=0;
    char w;
    scanf("%d",&T);//T组测试数据 
    while(T--){//二维 
        memset(f,0,sizeof f);// 记得初始化 
        scanf("%d%d",&n,&m);//n*n的图表，m次操作 
        for(int i=1;i<=m;++i){
            scanf("%*c%c",&w);
            if(w == 'C'){//	区间修改 
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
                push2(x1,y1,1);//自己画图证明 
                push2(x2+1,y2+1,1);
                push2(x1,y2+1,-1);
                push2(x2+1,y1,-1);
            }
            else{
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);//查询求和
                int ans = query2(x2,y2)+query2(x1-1,y1-1)-query2(x2,y1-1)-query2(x1-1,y2);
                printf("%d\n",ans); 
            }
        }
    }
    while(T--){
        memset(f,0,sizeof f);// 记得初始化 
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            scanf("%*c%c",&w);
            if(w == 'C'){
                scanf("%d%d",&x1,&k);
                push1(x1,k);
            }
            else{
                scanf("%d%d",&x1,&x2);
                printf("%d",query1(x2)-query1(x1-1));
            }
        }
    }
    return 0;
}
