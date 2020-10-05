#include<bits/stdc++.h>
using namespace std;
struct node{
	int r,c,dist;
};
int ro,co;
char grid[1001][1001];
bool visited[1001][1001];
struct node lv;
struct node bfs(struct node se){
	visited[se.r][se.c]=true;
	queue<struct node>q;
	q.push(se);
	//cout<<lv.r<<lv.c<<lv.dist<<endl;
	// pairs added
	while(!q.empty()){
		struct node s=q.front();
		lv=s;
		q.pop();
		if(s.r-1>=0&&!visited[s.r-1][s.c]){
			struct node n1;
			n1.r=s.r-1;
			n1.c=s.c;
			n1.dist=s.dist+1;
			visited[n1.r][n1.c]=true;
			//cout<<n1.r<<n1.c<<n1.dist<<endl;
			q.push(n1);
		}
		if(s.c+1<co&&!visited[s.r][s.c+1]){
			struct node n1;
			n1.r=s.r;
			n1.c=s.c+1;
			n1.dist=s.dist+1;
			visited[n1.r][n1.c]=true;
			//cout<<n1.r<<n1.c<<n1.dist<<endl;
			q.push(n1);
		}
		if(s.r+1<ro&&!visited[s.r+1][s.c]){
			struct node n1;
			n1.r=s.r+1;
			n1.c=s.c;
			n1.dist=s.dist+1;
			visited[n1.r][n1.c]=true;
			//cout<<n1.r<<n1.c<<n1.dist<<endl;
			q.push(n1);
		}
		if(s.c-1>=0&&!visited[s.r][s.c-1]){
			struct node n1;
			n1.r=s.r;
			n1.c=s.c-1;
			n1.dist=s.dist+1;
			visited[n1.r][n1.c]=true;
			//cout<<n1.r<<n1.c<<n1.dist<<endl;
			q.push(n1);
		}
	}	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		struct node source;
		cin>>co>>ro;
		for(int i=0;i<ro;i++){
			for(int j=0;j<co;j++){
				cin>>grid[i][j];
				if(grid[i][j]=='.'){
					source.r=i;
					source.c=j;
					source.dist=0;
				}
			}
		}
		for(int i=0;i<ro;i++){
			for(int j=0;j<co;j++){
				if(grid[i][j]=='#')
					visited[i][j]=true;
				else
					visited[i][j]=false;
			}
		}
		bfs(source);
		for(int i=0;i<ro;i++){
			for(int j=0;j<co;j++){
				if(grid[i][j]=='#')
					visited[i][j]=true;
				else
					visited[i][j]=false;
			}
		}
		//cout<<"after first="<<lv.r<<lv.c<<lv.dist<<endl;
		lv.dist=0;
		bfs(lv);
		//cout<<"after second="<<lv.r<<lv.c<<lv.dist<<endl;
		cout<<"Maximum rope length is "<<lv.dist<<"."<<endl;

	}
}
