#include<bits/stdc++.h>
using namespace std;

#define infinity INT_MAX;

class SGTree{
	vector<int> seg;

public:
	SGTree(int n){
		seg.resize(4*n);
	}

	void build(int index,int L,int R,vector<int> a){
		if(L == R){
			//single element range
			seg[index] = a[L];
			return;
		}

		int mid = L + (R-L)/2;

		build(2*index+1,L,mid,a);
		build(2*index+2,mid+1,R,a);

		seg[index] = min(seg[2*index+1],seg[2*index+2]); 
	}

	int query(int index,int L,int R,int l,int r){
		if(r<L || l>R){
			// no overlap
			return infinity;
		}

		if(l<=L && r>=R){
			//complete overlap
			return seg[index];
		}

		//partial overlap
		int mid = L + (R-L)/2;
		int left = query(2*index+1,L,mid,l,r);
		int right = query(2*index+2,mid+1,R,l,r);

		return min(left,right);
	};

	void update(int index,int L,int R,int i,int val){
		if(L==R){
			seg[index] = val;
			return;
		}

		int mid = L + (R-L)/2;

		if(i<=mid){
			update(2*index+1,L,mid,i,val);
		}
		else{
			update(2*index+2,mid+1,R,i,val);
		}

		seg[index] = min(seg[2*index+1],seg[2*index+2]);
	}
};
