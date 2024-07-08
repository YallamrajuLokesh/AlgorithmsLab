#include <iostream>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

int knapsnack(int n,int pr[],int wt[],int c){
    if(n==0||c==0){
        return 0;
    }
    if(wt[n-1]>c){
        return knapsnack(n-1,pr,wt,c);
    }
    else
      return max(pr[n-1]+knapsnack(n-1,pr,wt,c-wt[n-1]),knapsnack(n-1,pr,wt,c));
}

int main(){
    int n;
    cout<<"enter number"<<endl;
    cin>>n;

    int *profit=new int[n];
    int *weight=new int[n];

    cout<<"Enter pro"<<endl;
    for(int i=0;i<n;i++){
        cin>>profit[i];
        
    }
    cout<<"enter weight"<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        
    }
    int c;
    cout<<"enter capacity"<<endl;

    cin>>c;

    cout<<"the solu is"<<knapsnack(n,profit,weight,c)<<endl;
}
