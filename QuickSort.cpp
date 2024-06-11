#include<bits/stdc++.h>
using namespace std;


void gallivanter(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

int partition(int ar[],int low,int high){
	int i=low;
	int j=high;
	int p=ar[low];

	while(i<j){
		while(ar[i]<=p) i++;
		while(ar[j]>p) j--;

		if(i<j){
			int temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}
	int temp=ar[low];
	ar[low]=ar[j];
	ar[j]=temp;

	return j;

}

void quick_sort(int ar[],int low,int high){

	if(low>high) return;

	int pivot=partition(ar,low,high);

	quick_sort(ar,low,pivot-1);
	quick_sort(ar,pivot+1,high);
}


int main(){
		gallivanter();
		int tc;cin>>tc;
		while(tc--){

		int n;cin>>n;
		int ar[n];

		for(int i=0;i<n;i++) cin>>ar[i];

		quick_sort(ar,0,n-1);

		for(int i=0;i<n;i++) cout<<ar[i]<<" ";
		cout<<endl;
	}


}
