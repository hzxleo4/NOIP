//bilibili KMP�㷨 
#include<cstdio>
#include<cstring>
using namespace std;
char s1[1000005],s2[1005]; 
int ans1[1000005],l1,l2,next1[1000005],t;
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	int j = 0;
	for(int i=1;i<l2;++i){	
		while(j && s2[i] != s2[j]){//�Ҳ�����һֱ��ǰ�� 
				j = next1[j-1];
		}
 		if(s2[i] == s2[j]){//�����ͬ��i++��j++һ����ǰ�� 
			next1[i] = ++j;
		}
	}
	j = 0;//��ֵ 
	for(int i=0;i<l1;++i){
		while(j && s1[i] != s2[j]){//��������ַ�����ƥ�����ǰ�� 
			j = next1[j-1];
		}
		if(s1[i] == s2[j]){//�ҵ��˾�i++��j++һ�������� 
			++j;
		}
		if(j == l2){
			printf("%d\n",i+2-j);
			j = next1[j-1];//�ҵ�����ǰ�� 
		}	
		
	}
	for(int i=0;i<l2;++i){
		printf("%d ",next1[i]);
	}
	return 0;
}
