#include<cstdio>
using namespace std;
struct node{
	int l,r;
}d[100005];
int n,a,p,h[100005],l,r,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){//���ڲ��������� 
		h[i] = 1;
	}
	for(int i=2;i<=n;++i){//�ӵ�
		scanf("%d%d",&a,&p); 
		if(!p){//��i����a����� 
			l = d[a].l;
			d[a].l = i;		d[l].r = i;
			d[i].r = a;		d[i].l = l;
		}
		else{//�ұ� 
			r = d[a].r;
			d[a].r = i;		d[r].l = i;
			d[i].l = a;		d[i].r = r;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){//ɾ�� 
		scanf("%d",&a);
		if(!h[a])	continue;
		h[a] = 0;
		if(d[a].l)	l = d[a].l;
		if(d[a].r)	r = d[a].r;
		if(d[a].l)	d[l].r = d[a].r;
		if(d[a].r)	d[r].l = d[a].l;
			
	}
	for(int i=1;i<=n;++i){
		if(h[i]){
			if(!d[i].l){
				while(d[i].r){
					printf("%d ",i);
					i = d[i].r; 
				}
				printf("%d",i);
				return 0;
			}
			else	continue;
		}
	}
	return 0;
}
