#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
	int data;
	struct node*link;
}*top,*top1,*temp;
void main(){
	int choice,element;
	printf("enter the operation to perform\n");
	while(choice!=4){
		printf("\n1.push\n2.pop\n3.display\n");
		scanf("%d",&choice);

		switch(choice){
			case 1: printf("enter the element to be inserted : ");
				scanf("%d",&element);
				push(element);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default : printf("invalid choice");
		}
	}
	
}


//void push

void push(int element){
	if(top==NULL){
		
		top=(struct node*)malloc(1*sizeof(struct node));
		top->link=NULL;
		top->data=element;
		printf("%d inserted\n",element);
	}
	else{
		temp=(struct node*)malloc(1*sizeof(struct node));
		temp->link=top;
		temp->data=element;
		top=temp;
		printf("%d inserted\n",element);
	}
}
//pop

void pop(){
	top1=top;
	if(top1==NULL){
		printf("it is empty nothing to pop!");
	}
	else{                                                                                                      
		top1=top1->link;
		printf("poped element is %d \n",top->data);
		free(top);
		top=top1;
	}
}

//display
void display(){
	top1=top;
	if(top1==NULL){
		printf("empty, nothing to display!");
	}
	while(top1!=NULL){
		printf("%d ->",top1->data);
		top1=top1->link;
	}
	printf("NULL");
}