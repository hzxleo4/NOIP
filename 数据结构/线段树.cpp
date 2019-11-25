#include<cstdio>
using namespace std;
struct node{
    int  l,r,lc,rc;
	long long d,lazy;
}t[200010];
int   cnt = 1;
long long  a[100010]; 
void update(int  x){//维护 
    t[t[x].lc].d += t[x].lazy * (t[t[x].lc].r - t[t[x].lc].l);//向左下传递 
    t[t[x].lc].lazy += t[x].lazy;
    t[t[x].rc].d += t[x].lazy * (t[t[x].rc].r - t[t[x].rc].l);//向右下传递 
    t[t[x].rc].lazy += t[x].lazy;
    t[x].lazy = 0;//清零 ！ 
}
void build(int  l,int  r,int  x){//左节点 右节点 序号 
    t[x].l = l;    t[x].r = r;
    int  mid  = (l+r)/2;//二分 
    if(l+1 < r){//如果还可以建树 
		t[x].lc = ++cnt;//记录子树 
        build(l,mid,t[x].lc);
		t[x].rc = ++cnt;
        build(mid,r,t[x].rc);
        t[x].d = t[t[x].lc].d + t[t[x].rc].d;//赋值 
    }
    else    t[x].d = a[l];//最下面的值 
}
void insert(int l,int r,int x,int  d){//维护 
    if(l <=t[x].l && r >= t[x].r){//在询问的范围内 
        t[x].d += (t[x].r-t[x].l) * d;//直接加 
        t[x].lazy += d;
        return ;
    }
    if(t[x].lazy)    update(x);//（优化）如果搜索到了才往下传递 
    if(l < (t[x].l+t[x].r)/2){//向下搜索 
        insert(l,r,t[x].lc,d);
    }
    if(r > (t[x].l+t[x].r)/2){
        insert(l,r,t[x].rc,d);
    }
    t[x].d = t[t[x].lc].d + t[t[x].rc].d;//重新赋值 
}
long long query(int l,int r,int x){//询问 
    if (l <= t[x].l && r >= t[x].r) {//在询问的范围内 
        return t[x].d;
    }
    long long ans = 0;
    if(t[x].lazy)    update(x);//（优化）如果搜索到了才往下传递
    if(l < (t[x].l+t[x].r)/2){//向下搜索 累加答案 
        ans += query(l,r,t[x].lc);
    }
    if(r > (t[x].l+t[x].r)/2){
        ans += query(l,r,t[x].rc);
    }
    return ans;
}
int  main(){
    int  n,m,q,x,y,k;
    scanf("%d%d",&n,&m);//n个点 m次操作 
    for(int  i=1;i<=n;++i){//读入 
        scanf("%lld",&a[i]);
    }
    build(1,n+1,1);//建树 
    for(int i=1;i<=m;++i){//操作 
        scanf("%d%d%d",&q,&x,&y);
        if(q == 1){
            scanf("%d",&k);
            insert(x,y+1,1,k);//在[x,y]中，每个数加k 
        }
        else{
            printf("%lld\n",query(x,y+1,1));//[x,y]中所有数的和 
        }
    }
    return 0;
} 
