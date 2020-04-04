#include <iostream>
#include <vector>
using namespace std;
void build();
void update(int,int);
int query(int);

vector<int> BIT(1,0);
vector<int> arr;
 
main(){
	for(int i=1;i<=5;i++)
		BIT.push_back(2);

	build();

	for(int i=0;i<6;i++)
		cout<<BIT[i]<<",";

	cout<<endl<<"Suma total = "<<query(5)<<endl;
}

//Tiempo O(n log N)
void build(){
	for(int i=1;i<BIT.size();i++){
		int j=i + (i&-i);
		if(j<BIT.size())
			BIT[j]=BIT[j]+BIT[i];
	}
}

//Tiempo O(log N)
void update(int i, int val){
	for(i++;i<BIT.size();i+= i&-i)
		BIT[i]=BIT[i]+val;
}

//Tiempo O(log N)
int query(int i){
	int ans=0;
	for(i;i;i-= i &-i){
		ans+=BIT[i];
	}
	return ans;
}