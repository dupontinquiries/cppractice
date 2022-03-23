#include <bits/stdc++.h>
using namespace std;

void findway(vector<int> a,int n,int amount){
	int table[amount+1]; //DP table
	memset(table,0,sizeof(table));
	table[0]=1;
	//j be the sub-amounts
	for(int i=1;i<=n;i++){
		for(int j=1;j<=amount;j++){
		if(j>=a[i])
			table[j]+=table[j-a[i]];
		}
	}
	cout<<table[amount]<<endl; //final result
}

int main()
{
	int n,item,amount;

	cout<<"Enter the number of coins\n";
	scanf("%d",&n);

	cout<<"Enter value of coins\n";
	vector<int> a; //coins array
	//we pre add 0-cent coin as coins[0]
	//for sake of 1 indexing
	a.push_back(0);

	for(int j=0;j<n;j++){
		scanf("%d",&item);
		a.push_back(item);
	}

	cout<<"Enter total amount\n";
	cin>>amount;
	cout<<"Number of ways to sum the amount is: ";
	findway(a,n,amount);

	return 0;
}
