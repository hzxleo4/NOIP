#include<cstdio>
using namespace std;
struct node{
    int  l,r,lc,rc;
	long long d,lazy;
}t[200010];
int   cnt = 1;
long long  a[100010]; 
void update(int  x){//ά�� 
    t[t[x].lc].d += t[x].lazy * (t[t[x].lc].r - t[t[x].lc].l);//�����´��� 
    t[t[x].lc].lazy += t[x].lazy;
    t[t[x].rc].d += t[x].lazy * (t[t[x].rc].r - t[t[x].rc].l);//�����´��� 
    t[t[x].rc].lazy += t[x].lazy;
    t[x].lazy = 0;//���� �� 
}
void build(int  l,int  r,int  x){//��ڵ� �ҽڵ� ��� 
    t[x].l = l;    t[x].r = r;
    int  mid  = (l+r)/2;//���� 
    if(l+1 < r){//��������Խ��� 
		t[x].lc = ++cnt;//��¼���� 
        build(l,mid,t[x].lc);
		t[x].rc = ++cnt;
        build(mid,r,t[x].rc);
        t[x].d = t[t[x].lc].d + t[t[x].rc].d;//��ֵ 
    }
    else    t[x].d = a[l];//�������ֵ 
}
void insert(int l,int r,int x,int  d){//ά�� 
    if(l <=t[x].l && r >= t[x].r){//��ѯ�ʵķ�Χ�� 
        t[x].d += (t[x].r-t[x].l) * d;//ֱ�Ӽ� 
        t[x].lazy += d;
        return ;
    }
    if(t[x].lazy)    update(x);//���Ż�������������˲����´��� 
    if(l < (t[x].l+t[x].r)/2){//�������� 
        insert(l,r,t[x].lc,d);
    }
    if(r > (t[x].l+t[x].r)/2){
        insert(l,r,t[x].rc,d);
    }
    t[x].d = t[t[x].lc].d + t[t[x].rc].d;//���¸�ֵ 
}
long long query(int l,int r,int x){//ѯ�� 
    if (l <= t[x].l && r >= t[x].r) {//��ѯ�ʵķ�Χ�� 
        return t[x].d;
    }
    long long ans = 0;
    if(t[x].lazy)    update(x);//���Ż�������������˲����´���
    if(l < (t[x].l+t[x].r)/2){//�������� �ۼӴ� 
        ans += query(l,r,t[x].lc);
    }
    if(r > (t[x].l+t[x].r)/2){
        ans += query(l,r,t[x].rc);
    }
    return ans;
}
int  main(){
    int  n,m,q,x,y,k;
    scanf("%d%d",&n,&m);//n���� m�β��� 
    for(int  i=1;i<=n;++i){//���� 
        scanf("%lld",&a[i]);
    }
    build(1,n+1,1);//���� 
    for(int i=1;i<=m;++i){//���� 
        scanf("%d%d%d",&q,&x,&y);
        if(q == 1){
            scanf("%d",&k);
            insert(x,y+1,1,k);//��[x,y]�У�ÿ������k 
        }
        else{
            printf("%lld\n",query(x,y+1,1));//[x,y]���������ĺ� 
        }
    }
    return 0;
} 
