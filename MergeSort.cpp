#include<bits/stdc++.h>
using namespace std;


void gallivanter(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}
void jora(int ar[],int bam,int mid,int dan){
	int n1=mid-bam+1;
	int n2=dan-mid;
	int l[n1],r[n2];

	for(int ii=0;ii<n1;ii++) l[ii]=ar[bam+ii];

	for(int ii=0;ii<n2;ii++) r[ii]=ar[mid+ii+1];

	int i=0,j=0,k=bam;
	
	while(i<n1 && j<n2){
		if(l[i]<=r[j]) ar[k++]=l[i++];
		else ar[k++]=r[j++];
	}

	while(i<n1) ar[k++]=l[i++];
	while(j<n2) ar[k++]=r[j++];
}

void mersort(int ar[],int bam,int dan){

	if(bam>=dan) return;

	int mid=(bam+dan)/2;

	mersort(ar,bam,mid);
	mersort(ar,mid+1,dan);
	jora(ar,bam,mid,dan);
}


int main(){
		gallivanter();
		int tc;cin>>tc;
		while(tc--){

		int n;cin>>n;
		int ar[n];

		for(int i=0;i<n;i++) cin>>ar[i];

		mersort(ar,0,n-1);
		
		for(int i=0;i<n;i++) cout<<ar[i]<<" ";
		cout<<endl;
	} 


}