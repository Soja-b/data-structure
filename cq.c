#include<stdio.h>
int queue[100];
int size,choice,front=-1,rear=-1,value;



int isfull(){
    if ((front == 0 && rear == size - 1) || (front == rear + 1)){
         return 1;
    }
    else{
        return 0;
    }
}



int isempty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(){
    if(isfull()){
        printf("queue is full");
    }
    else{
        printf("enter item to insert : ");
        scanf("%d",&value);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}
void dequeue(){
    if(isempty()){
        printf("queue is empty");
    }
    else{
        printf("Dequeued %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
}

void display(){
    int i;
    if (isempty()){
        printf("Queue is empty.\n");
    } 
    else {
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i +1) % size)
            printf("%d, ", queue[i]);
        printf("%d\n", queue[i]);
    }
}

int main() {
    printf("\nenter the size of the queue: ");
	scanf("%d",&size);
    do
	{
		printf("\n\nEnter the operation to perform:\n1.enqueue\n2.dequeue\n3.display");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					enqueue();
					break;
				}
			case 2:
				{
					dequeue();
					break;
				}
			case 3:
				{	
					display();
					break;
				}
			default:printf("\ninvalid choice!");
		};
	}while(choice!=4);
    return 0;
}