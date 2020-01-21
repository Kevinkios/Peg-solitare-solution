//11020170664 05931701 Œ‚’”Ó
// Data structure Assignment£®2017/2018£©
//Peg Solitaire

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node{
	int board[5][5];
	Node *firstchild;
	Node *nextsibling;
	Node *parent;
	Node *presibling;
};
int canspan(Node *t){
	
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			if(t->board[i][j]==1&&t->board[i+1][j]==1&&t->board[i+2][j]==0){
				return 1;
			}
			
		}
	}
	for(int i=2;i<5;i++){
		for(int j=0;j<5;j++){
			if(t->board[i][j]==1&&t->board[i-1][j]==1&&t->board[i-2][j]==0){
				return 1;
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			if(t->board[i][j]==1&&t->board[i][j+1]==1&&t->board[i][j+2]==0){
				return 1;
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=2;j<5;j++){
			if(t->board[i][j]==1&&t->board[i][j-1]==1&&t->board[i][j-2]==0){
				return 1;
			}	
		}
	}
	return 0;
}
int ifwin(Node *t){
	int count=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(t->board[i][j]==1)
			count++;
		}
	}
	if(count==1&&t->board[2][2]==1)
	return 1;
	else 
	return 0;
}
Node* back(Node *t){
    Node *p=t;
	while(p->nextsibling==NULL&&p->parent!=NULL){
		p=p->parent;
	}
	delete(t);
	t=p;
	return t;
}
void copy(Node *q,Node *t){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			q->board[i][j]=t->board[i][j];
		}
	}
}
void ini(Node *q,int a[5][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			q->board[i][j]=a[i][j];
		}
	}
}

void listpossible(Node *t){
	Node *q=t;
		q->firstchild=new(Node);
		q=q->firstchild;
		q->parent=t;
		q->presibling=NULL;
		q->firstchild=NULL;
		q->nextsibling=NULL;
		int count=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<5;j++){
				if(t->board[i][j]==1&&t->board[i+1][j]==1&&t->board[i+2][j]==0){
					count++;
					if(count==1){
						copy(q,t);
						q->board[i+2][j]=1;
					    q->board[i][j]=0;
					    q->board[i+1][j]=0;
					}
					else{
						q->nextsibling=new(Node);
						Node *p=q;
						q=q->nextsibling;
						q->firstchild=NULL;
						q->parent=NULL;
						q->presibling=p;
						q->nextsibling=NULL; 
						copy(q,t);
						q->board[i+2][j]=1;
					    q->board[i][j]=0;
					    q->board[i+1][j]=0;
					}
				}
			}
	    }
		for(int i=2;i<5;i++){
			for(int j=0;j<5;j++){
				if(t->board[i][j]==1&&t->board[i-1][j]==1&&t->board[i-2][j]==0){
					count++;
					if(count==1){
						copy(q,t);
						q->board[i-2][j]=1;
					    q->board[i][j]=0;
					    q->board[i-1][j]=0;
					}
					else{
						q->nextsibling=new(Node);
						Node *p=q;
						q=q->nextsibling;
						q->firstchild=NULL;
						q->parent=NULL;
						q->presibling=p;
						q->nextsibling=NULL; 
						copy(q,t);
						q->board[i-2][j]=1;
					    q->board[i][j]=0;
					    q->board[i-1][j]=0;
					}
				}
			}
	    }
		for(int i=0;i<5;i++){
			for(int j=0;j<3;j++){
				if(t->board[i][j]==1&&t->board[i][j+1]==1&&t->board[i][j+2]==0){
					count++;
					if(count==1){
						copy(q,t);
						q->board[i][j+2]=1;
					    q->board[i][j]=0;
					    q->board[i][j+1]=0;
					}
					else{
						q->nextsibling=new(Node);
						Node *p=q;
						q=q->nextsibling;
						q->firstchild=NULL;
						q->parent=NULL;
						q->presibling=p;
						q->nextsibling=NULL; 
						copy(q,t);
						q->board[i][j+2]=1;
					    q->board[i][j]=0;
					    q->board[i][j+1]=0;
					}
				}
			}
	    }
		for(int i=0;i<5;i++){
			for(int j=2;j<5;j++){
				if(t->board[i][j]==1&&t->board[i][j-1]==1&&t->board[i][j-2]==0){
					count++;
					if(count==1){
						copy(q,t);
						q->board[i][j-2]=1;
					    q->board[i][j]=0;
					    q->board[i][j-1]=0;
					}
					else{
						q->nextsibling=new(Node);
						Node *p=q;
						q=q->nextsibling;
						q->firstchild=NULL;
						q->parent=NULL;
						q->presibling=p;
						q->nextsibling=NULL; 
						copy(q,t);
						q->board[i][j-2]=1;
					    q->board[i][j]=0;
					    q->board[i][j-1]=0;
					}
				}
			}
        }
}
Node* shift(Node *t){
	Node *parentnode;
	Node *nextnode;
	parentnode=t->parent;
	parentnode->firstchild=nextnode;
	nextnode=t->nextsibling;
	nextnode->parent=parentnode;
	delete(t);
	return nextnode;
}
void print(Node *q){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(q->board[i][j]==1)
			cout<<"O"<<" ";
			else if(q->board[i][j]==0)
			cout<<"."<<" ";
		}
		cout<<endl;
	}
}
Node* span(Node *start){
	Node *t=start;
	do{
		while(canspan(t)){
			listpossible(t);
			t=t->firstchild;
		}
		if(ifwin(t)) {
			return t;
		}
		else if(t->nextsibling==NULL){
			t=back(t);
			if(t==start) break;
			t=shift(t);
		}
		else t=shift(t);
	}while(t->parent!=NULL);
	return NULL;
}

void printstep(Node *t){
	while(t!=NULL){
		print(t);
		cout<<endl;
		t=t->parent;
	}
}
int main(){
	Node *origin=new(Node);
	origin->nextsibling=NULL;
	origin->parent=NULL;
	origin->presibling=NULL;
	origin->firstchild=NULL;
	int chessboard[5][5]={0};
	char temp;
	int count=0;
	int i=0;
	int j=0;
	DWORD init,time;
	
	ifstream test("c.txt");
	while(test>>temp){
		count++;
		
		if(i<5&&j<5){
			if(temp=='o'||temp=='O'){
				chessboard[i][j]=1;
			    if(j<4) j++;
			    else{
				    j=0;
				    i++;
			    }
			}
			else{
				if(j<4) j++;
			    else{
				    j=0;
				    i++;
			    }
			}
		}
	}
	if(count!=25){
		cout<<"Wrong input!"<<endl;
	}
	else{
	    init=::GetTickCount();
		ini(origin,chessboard);
	    Node *t=span(origin);
	    time=::GetTickCount();
	    if(t==NULL)  cout<<"No solutions!"<<endl<<"The running time is:"<<time-init<<"ms"<<endl;
	    else{
	    	cout<<"The reverse solution order is:"<<endl<<"The running time is:"<<time-init<<"ms"<<endl<<endl;
	        printstep(t);
        }
	}
	return 0;
}
