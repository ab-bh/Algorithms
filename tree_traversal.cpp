#include <bits/stdc++.h>
using namespace std;
#define maxs 1001
int top=0;
char tree[maxs];
void insert(){
	char val;
	cout<<"enter value to enter in tree"<<endl;
	cin>>val;
	top++;
	tree[ top ] = val;
}
void preorder(int node){
	if(tree[node]==-1) return ;
	cout<<" "<<tree[node]<<" ";
	preorder(2*node);
	preorder(2*node+1);
}
void inorder(int node){
	if(tree[node]==-1) return ;
	inorder(2*node);
	cout<<" "<<tree[node]<<" ";
	inorder(2*node+1);
}
void postorder(int node){
	if(tree[node]==-1) return ;
	postorder(2*node);
	postorder(2*node+1);
	cout<<" "<<tree[node]<<" ";
}
int main(){
	int a=1;
	memset(tree,-1,sizeof(tree));
	while(a!=5){
		cout<<"\n1.Enter into tree"<<endl;
		cout<<"\n2.perform preorder"<<endl;
		cout<<"\n3.perform inorder"<<endl;
		cout<<"\n4.perform postorder"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>a;
		switch(a){
			case 1: insert();
					break;
			case 2: preorder(1);
					cout<<endl;
					break;
			case 3: inorder(1);
					cout<<endl;
					break;
			case 4: postorder(1);
					cout<<endl;
					break;
			default: cout<<"invalid choice!! exiting..."<<endl;
		}
	}
}