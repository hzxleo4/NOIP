#include<cstdio>//spfa�㷨�ؼ�����һ��������ظ����
#include<cstring>//���Խ�����ڸ���Ȩ��ͼ 
#define INF 0x3f3f3f3f
using namespace std;
struct node{
    int a,b,c,n;
}d[500005];
int n,m,s,a,b,c,h[500005],dis[10005],q[1000005],v[10005],head,tail;
int main(){
    scanf("%d%d%d",&n,&m,&s);// n���� m�β��� s��� 
    for(int i=1;i<=m;++i){//���� 
        scanf("%d%d%d",&a,&b,&c);
        d[i].a = a;	d[i].b = b;	d[i].c = c;
        d[i].n = h[a];	h[a] = i;
    }
    for(int i=1;i<=n;++i){//����ֵ����� 
        dis[i] = INF;
    }
    dis[s] = 0;//�Լ����Լ��ľ���Ϊ0 
    head = tail = 1;//�������� 
    q[1] = s;
    while(head <= tail){
        int x = q[head];//ȡ�� 
        for(int i=h[x];i;i=d[i].n){//�ӵ��������� 
            b = d[i].b;c = d[i].c;
            if(dis[x]+c < dis[b]){//����������Ը��� 
                dis[b] = dis[x]+c;//���� 
                if(!v[b]){//������ڶ����� ����� 
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
        v[x] = 0;//���� 
    }
    for(int i=1;i<=n;++i){
        printf("%d ",dis[i]);
    }
    return 0;
}
