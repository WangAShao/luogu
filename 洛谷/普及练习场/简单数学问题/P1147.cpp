#include<bits/stdc++.h>
using namespace std;

//真就纯数论, 刷题时还是要注意数学思维, 蛮干不可取
int M;
int main(){
    cin>>M;
    for(int k1=sqrt(2*M);k1>1;k1--)//枚举k1(注意是k1>1而不是k1>=1)
        if(2*M%k1==0 && (k1+2*M/k1)%2){//如果K2是整数而且与K1一奇一偶
            int k2=2*M/k1;
                cout<<(k2-k1+1)/2<<" "<<(k1+k2-1)/2<<endl;//输出答案
        }
    return 0;
}