#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node *node;
         node head;
         node Newnode;
       	node tmp;
void create_link(int ele){       //  Create a linked list
	 Newnode = (node)malloc(sizeof(node));
	Newnode->data=ele;
	Newnode->next=0;   //0==NULL
      if(head==0){
      	head=Newnode;
      }
	else{
		tmp=head;
		while(tmp->next!=0){
			tmp=tmp->next;
		}
		tmp->next=Newnode;

	}

}

void AddBegin(int ele){  // function to insert a linked list at the begining
Newnode=(node*)malloc(sizeof(node));
	Newnode->data=ele;
	if(head==0){
		Newnode->next=0;
	}
	else
   Newnode->next=head;
   head=Newnode;
 printf("The element add at the begining sucessfully\n\n");
}
void AddEnd(int ele){ // insert at the end
 Newnode=(node*)malloc(sizeof(node));
 Newnode->data=ele;
 Newnode->next=0;
 if(head==0){
 	head=Newnode;
 }
 else{
 	tmp=head;
 	while(tmp->next!=0)
 		tmp=tmp->next;
 	}
 	tmp->next=Newnode;
 	printf("node added at the end sucessfully\n\n");

}
void anyPosition(int ele,int y){
	int x=1;
	Newnode=(node*)malloc(sizeof(node));
     Newnode->data=ele;
     Newnode->next=0;
     tmp=head;
     while(tmp->next!=0){
     	if(x==y-1)
     	break;
     	else{

     	tmp=tmp->next;
     	x=x+1;
     }
     }
     Newnode->next=tmp->next;
     tmp->next=Newnode;
     printf("The element inserted\n\n");
}

void search(int ele){
	int x=1;
	if(head==0){
		printf("There is no linked list\n");
	}
	else{
		tmp=head;
		while(tmp!=0){
			if(tmp->data==ele){
			printf("found in location %d\n",x);
			}
			tmp=tmp->next;
			x=x+1;
		}
	}
}
void display(){
	printf("\t The linked list\n");
	if(head==0)
		printf("\n list is empty\n");
		else{
			tmp=head;
			while(tmp!=0){
				printf("%d\n",tmp->data);
				tmp=tmp->next;
			}
		}
	}
void Delete(int ele){
	  node hold;
if (head->data ==ele)
{
tmp=head;
head=head->next; // delete at the beginning
free(tmp);
return;
}
hold=head;
while(hold->next->next != 0)
{
if(hold->next->data == ele) //element delete in between
{
tmp=hold->next;
hold->next=tmp->next;
free(tmp);
return;
}
hold=hold->next;
}   // end of while loop
if(hold->next->data==ele)    //end element deleted
{
tmp=hold->next;
free(tmp);
hold->next=0;
return;
}
printf ("\n\nElement %d not found",ele);
getch();
}

int main(){
	int choice,poss,a,num,elem;
	while(1){

		printf("\n\t\tCHOOSE THE NUMBER THAT YOU WANT TO OPRATE\n");

		printf("\t\t1,Create a linked list\n");
		printf("\t\t2,Put an element at the begining\n");
		printf("\t\t3,Put an element at the end\n");
		printf("\t\t4,Put an element any position\n");
		printf("\t\t5,Delete\n");
		printf("\t\t6,Search\n");
		printf("\t\t7,Display\n");
		printf("\t\t8,Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
				printf("How many nodes you want to create\n");
				scanf("%d",&num);
				printf("Enter the elements\n");
				for(a=0;a<num;a++){
					scanf("%d",&elem);
					create_link(elem);

				}
				display();
				printf("Linked list sucessfully created\n\n");
				break;
		case 2:
					printf("Enter an element to insert at the begining\n");
					scanf("%d",&elem);
					AddBegin(elem);
					display();
					break;
		case 3:
			         printf("Enter an element to insert at the end\n");
					scanf("%d",&elem);
					AddEnd(elem);
					display();
					break;
	    case 4:
	    	printf("the position you want to insert\n");
	    	scanf("%d",&poss);
	    	printf("Enter an element to insert at any position\n");
	    	scanf("%d",&elem);
	    	anyPosition(elem,poss);
	    	display();
	    	break;
		case 5:
			printf("Enter the the number to delete\n");
			scanf("%d",&num);
			Delete(num);
			display();
			break;
		case 6:
	     	printf("Enter an element to search at any position\n");
	    	scanf("%d",&elem);
	    	search(elem);
	    	display();
	    	break;
	  case 7:
	  	 display();
	  	 break;

	case 8:
		exit(0);
		break;
    default:
		printf("No more option\n");
	    }
	}
}
