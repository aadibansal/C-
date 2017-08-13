
#include<bits/stdc++.h>
using namespace std;

string possibleSum(int arr[], int sum, int length){
  bool check[sum+1][length+1];
  for(int i=0;i<=length;i++){
    check[0][i] = 1;
  }
  for(int i=1;i<=sum;i++){
    check[i][0] = 0;
  }
  for(int i=1;i<=sum;i++){
    for(int j=1;j<=length;j++){
        if(arr[j-1]>i){
            check[i][j]=check[i][j-1];
        }else{
            check[i][j]=check[i][j-1] || check[i-arr[j-1]][j-1];
        }
        }
    }
  if(check[sum][length])
    return "YES";
  else
    return "NO";
}
int main(){
    int tc, N, sum;
    cin>>tc;
    for(int i=0; i<tc;i++){
        cin>>N;
        int *arr = new int[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        cin>>sum;
        cout<<possibleSum(arr, sum, N);
    }
}


