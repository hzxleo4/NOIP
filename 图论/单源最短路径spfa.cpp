#include<cstdio>//spfa算法关键在于一个点可以重复入队
#include<cstring>//可以解决存在负边权的图 
#define INF 0x3f3f3f3f
using namespace std;
struct node{
    int a,b,c,n;
}d[500005];
int n,m,s,a,b,c,h[500005],dis[10005],q[1000005],v[10005],head,tail;
int main(){
    scanf("%d%d%d",&n,&m,&s);// n个点 m次操作 s起点 
    for(int i=1;i<=m;++i){//读边 
        scanf("%d%d%d",&a,&b,&c);
        d[i].a = a;	d[i].b = b;	d[i].c = c;
        d[i].n = h[a];	h[a] = i;
    }
    for(int i=1;i<=n;++i){//赋初值无穷大 
        dis[i] = INF;
    }
    dis[s] = 0;//自己到自己的距离为0 
    head = tail = 1;//队列搜索 
    q[1] = s;
    while(head <= tail){
        int x = q[head];//取点 
        for(int i=h[x];i;i=d[i].n){//从点向外搜索 
            b = d[i].b;c = d[i].c;
            if(dis[x]+c < dis[b]){//如果这个点可以更新 
                dis[b] = dis[x]+c;//更新 
                if(!v[b]){//如果不在队列中 就入队 
                    if(dis[b] < dis[q[head+1]]){
                        q[head] = b;
                        head--;
                    }
                    else{
                        q[++tail] = b;
                        v[b] = 1;
                    }	
                }
            }
        }
        head++;
        v[x] = 0;//出队 
    }
    for(int i=1;i<=n;++i){
        printf("%d ",dis[i]);
    }
    return 0;
}
