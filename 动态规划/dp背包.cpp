#include<cstdio>
#include<algorithm>
using namespace std;
int w[10005],v[10005],dp[10005],n,m;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&w[i],&v[i]);//���� ��ֵ 
    }
    //01���� 
     	for(int i=1;i<=n;++i){
            for(int j=m;j>=w[i];--j){//ÿ����Ʒֻ����һ�� 
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    //��ȫ����
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){//ÿ����Ʒ���������޴� 
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    //���鱳��
        for(int i=1;i<=n;++i){
            for(int j=m;j>=1;--i){//ÿ����ֻѡһ�� 
                for(int k=1;k<=h[q];++k)
                if(j >= w[q][k])
                    dp[j] = max(dp[j],dp[j-w[q][k]]+v[q][k]);
                    
            }
        } 
    printf("%d",dp[m]);
    return 0;
}
