#include<stdio.h>
#include<malloc.h>
struct Node{
	float cof;
	int deg;
	struct Node *next;
};
typedef struct Node *node;
	node newnode;
	node  tmp;
	node insert(node start,float cof,int expo){
		newnode=(node)malloc(sizeof(node));
		newnode->cof=cof;
		newnode->deg=expo;
		if(start==NULL||expo>start->deg){
			start=newnode;
			newnode->next=NULL;
		}
		else{
			tmp=start;
			while(tmp->next!=NULL&&tmp->next->deg>expo){
				tmp=tmp->next;
			}
				newnode->next=tmp->next;
				tmp->next=newnode;
			if(tmp->next==NULL)
			  newnode->next=NULL;

		}
		return start;
	}
node enter(node start){
		int i,n,expo;
		float coef;
		printf("Enter how many terms you want to enter\n");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			printf("Enter the coefficient:\t\n");
			scanf("%f",&coef);
			printf("Enter the degree of the coffecient %f :\t\n",coef);
			scanf("%d",&expo);
			start =insert( start, coef, expo);
		}
		return start;
	}
node add_poly(node p1,node p2){
	node p3_start=NULL,tmp,p3;
	if(p1==NULL&& p2==NULL){
		return p3_start;
	}
	while(p1!=NULL&& p2!=NULL){
		newnode=(node)malloc(sizeof(node));
		if(p3_start==NULL){
			p3_start=newnode;
			p3=p3_start;
		}
		else{
			p3->next==newnode;
			p3=p3->next;
		}
		if(p1->deg>p2->deg){
			newnode->deg=p1->deg;
			newnode->cof=p1->cof;
			p1=p1->next;
		}
		else if(p2->deg>p1->deg){
			newnode->deg=p2->deg;
			newnode->cof=p2->cof;
			p1=p2->next;
		}
		else if(p1->deg==p2->deg){
			newnode->deg=p1->deg;
			newnode->cof=p1->cof+p2->cof;
			p1=p1->next;
			p2=p1->next;
		}
		}
		while(p1!=NULL){
			newnode=(node)malloc(sizeof(node));
			newnode->deg=p1->deg;
			newnode->cof=p1->cof;
		if(p3_start==NULL){
			p3_start=newnode;
			p3=p3_start;
		}
		else{
			p3->next==newnode;
			p3=p3->next;
		}
		p1=p1->next;
		}
			while(p2!=NULL){
			newnode=(node)malloc(sizeof(node));
				newnode->deg=p2->deg;
			newnode->cof=p2->cof;
		if(p3_start==NULL){
			p3_start=newnode;
			p3=p3_start;
		}
		else{
			p3->next==newnode;
			p3=p3->next;
		}
		p2=p2->next;
		}
		p3->next=NULL;
		return p3_start;
	}
	display(node dis){
		if(dis==NULL){
			printf("\n Empty");

		}
		while(dis!=NULL){
			printf("(%.1f^%d)+",dis->cof,dis->deg);
			dis=dis->next;
		}
	}
int main(){
	node p1_start=NULL;
	node p2_start=NULL;
	node p3_start=NULL;
	printf("Enter Polynomial 1:\n");
	  p1_start=enter(p1_start);
	  printf("Enter Polynomial 2:\n");
	  p2_start=enter(p2_start);
	  printf("addtion of the two polynomial in the linked list\n");
	  p3_start=add_poly(p1_start,p2_start);
	  printf("display polynomial 1\n");
	  display(p1_start);
	   printf("display polynomial 2\n");
	  display(p2_start);
	   printf("display the addition of the two polynomials\n");
	  display(p3_start);
	}
