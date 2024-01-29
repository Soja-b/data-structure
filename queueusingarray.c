#include <stdio.h>

int queue[100],rear=-1,front=-1,choice,size,value,i;

void enqueue();
void dequeue();
void display();
void exit();
void main() {
	printf("enter the size of array:");
	scanf("%d",&size);

	printf("select the operation to perform\n");
	do{
		printf("\n1.enqueue\n2.dequeue\n3.display\n");
		scanf("%d",&choice);

			switch(choice){
							case 1: enqueue();
									break;
							case 2: dequeue();
									break;
							case 3: display();
									break;
							case 4:exit();
							        	break;
							default: printf("invalid choice!");
									break;

			}
	}while(choice!=4);

}
void enqueue(){
	if(rear==size-1){
		printf("queue overflow\n");
	}
	else{
		if(front=-1){
			printf("enter the value to be inserted : ");
			scanf("%d",&value);
			front++;
			rear++;
			queue[rear]=value;
		}
		else{
			printf("enter the value to be inserted");
			scanf("%d",&value);
			rear++;
			queue[rear]=value;
		}
	}
}
void dequeue(){
	if(front==-1){
		printf("queue underflow\n");
	}
	else{
	    if(front==rear){
	        printf(" element %d is deleted",queue[front]);
	        queue[front]=NULL;
	        front=rear=-1;
	        
	    }
	    else{
	        printf(" element %d is deleted",queue[front]);
	        queue[front]=NULL;
	        front++;
	        
	    }
	}
}
void display(){
    if(rear==-1){
        printf("queue is empty !!!");
    }
    else{
        printf("the entered elements are: \t");
	    for(i=front;i<=rear;i++){
		    printf("%d \t",queue[i],"\n");
	}
    }
}