// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// vector<int>grp[10001];
// int dp[10001];
// #define MOD 1000000007
// bool visited[10001];
// void explore(int s){
// 	queue<int>q;
// 	q.push(s);
// 	while(!q.empty()){
// 		int p=q.front();
// 		q.pop();
// 		visited[p]=true;
// 		cout<<p<<endl;
// 		for(int i=0;i<grp[p].size();i++){
// 			q.push(grp[p][i]);
// 			dp[grp[p][i]]=(dp[grp[p][i]]+(dp[p]%MOD))%MOD;
// 			cout<<"pushing"<<grp[p][i]<<"value= "<<dp[grp[p][i]]<<endl;
// 		}
// 	}
// }
// int main(){
// 	int t;
// 	scanf("%d",&t);
// 	while(t--){
// 		for(int i=0;i<10001;i++){
// 			grp[i].clear();
// 			visited[i]=false;
// 			dp[i]=0;
// 		}
// 		int S,T;
// 		scanf("%d%d%d%d",&n,&m,&S,&T);
// 		//cin>>n>>m>>S>>T;
// 		for(int i=0;i<m;i++){
// 			int u,v;
// 			scanf("%d%d",&u,&v);
// 			grp[u].push_back(v);
// 		}
// 		dp[S]=1;
// 		explore(S);
// 		printf("%d\n",dp[T]);
// 	}
	
// }
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>grp[10001];
int dp[10001];
#define MOD 1000000007
int frq[10001];
vector<int>topol;
void topo(){
	queue<int>q;
	// create queue
	for(int i=0;i<=n;i++){
		if(!frq[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int s=q.front();
		q.pop();
		topol.push_back(s);
		for(int i=0;i<grp[s].size();i++){
			frq[grp[s][i]]--;
			if(!frq[grp[s][i]])
				q.push(grp[s][i]);
		}

	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		topol.clear();
		for(int i=0;i<10001;i++){
			grp[i].clear();
			frq[i]=0;
			dp[i]=0;
		}
		int S,T;
		scanf("%d%d%d%d",&n,&m,&S,&T);
		//cin>>n>>m>>S>>T;
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			frq[v]++;
			grp[u].push_back(v);
		}
		if(S==T){
			printf("1\n");
			continue;
		}
		dp[T]=1;
		topo();
		for(int i=topol.size()-1;i>=0;i--){
			for(int j=0;j<grp[topol[i]].size();j++)
				dp[topol[i]]=((dp[topol[i]]%MOD)+(dp[grp[topol[i]][j]]%MOD))%MOD;
		}
		printf("%d\n",dp[S]);
	}
}
