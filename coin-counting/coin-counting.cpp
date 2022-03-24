
// trying to practice dynamic programming
// code adapted from https://www.includehelp.com/icp/coin-change.aspx

// #include <bits/stdc++.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

// returns a sum of a vector
int vec_sum(const vector<int> &v){int total = 0;for(vector<int>::const_iterator iter = v.begin();iter != v.end();iter++){total += *iter;}return total;}

// formats a 2d vec
string format_vec_2d(const vector<vector<int> > &v){stringstream stream;for(vector<vector<int> >::const_iterator a=v.begin();a!=v.end();a++){for(vector<int>::const_iterator b=a->begin();b!=a->end();b++){stream<<" "<<*b;}stream<<endl;}return stream.str();}

// formats a vec
string format_vec(const vector<int> &v){stringstream stream;for(vector<int>::const_iterator a=v.begin();a!=v.end();a++){stream<<" "<<*a;}return stream.str();}

// note: does not work (provides invalid output)
string list_ways(vector<int> coins,int n,int amount)
{
	// setup tuples of coins
	vector<vector<int> > coin_table;
	for(int i=0;i<=n;i++){
		coin_table.push_back(vector<int>());
	}
	int table[amount+1]; //DP table
	memset(table,0,sizeof(table));
	table[0]=1;
	//j be the sub-amounts
	for(int i=1;i<=n;i++){
		for(int j=1;j<=amount;j++){
			// cout<<table[j]<<" ";
			if(j>=coins[i]){
				table[j]+=table[j-coins[i]];
				// I have not found a way to simply pull the tuples of coins from this loop
				if(vec_sum(coin_table[i])<amount){
					coin_table[i].push_back(coins[i]);
				}
			}
		}
		cout<<format_vec(coins)<<endl;
	}
	return format_vec_2d(coin_table);
}



int num_ways(vector<int> coins,int n,int amount)
{
	int table[amount+1]; //DP table
	memset(table,0,sizeof(table));
	table[0]=1;
	//j be the sub-amounts
	for(int i=1;i<=n;i++){
		for(int j=1;j<=amount;j++){
			if(j>=coins[i]){
				table[j]+=table[j-coins[i]];
			}
		}
	}
	return table[amount];
}

int main()
{
	int n,item,amount;

	cout<<"Enter the number of coins\n";
	scanf("%d",&n);

	cout<<"Enter value of coins\n";
	vector<int> coins; //coins array
	//we pre add 0-cent coin as coins[0]
	//for sake of 1 indexing
	coins.push_back(0);

	for(int j=0;j<n;j++){
		scanf("%d",&item);
		coins.push_back(item);
	}

	cout<<"Enter total amount\n";
	cin>>amount;
	cout<<"Number of ways to sum the amount is: "<<num_ways(coins,n,amount)<<endl;
	// note: uncomment this line to work on the function that lists sets of coins out
	// cout<<"List: "<<endl<<list_ways(coins,n,amount)<<endl;

	return 0;
}
