#include<stdio.h>
int arr[100],size,choice,top=-1,value,i;
void push();
void pop();
void display();
void main(){
    
    printf("Stack using array\n");
    printf("enter the size of array: \n");
    scanf("%d",&size);
    printf("1.push\n2.pop\n3.display\n");
    do{
        printf("enter the operation to perform");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default: printf("invalid choice !");
                    break;
        }
    }while(choice!=4); 
}
void push(){
    if(top==size-1){
        printf("stack overflow ");
    }
    else{
        printf("enter the value to insert :");
        scanf("%d",&value);
        top++;
        arr[top]=value;
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow");
    }
    else{
        top--;
    }
}
void display(){
    if(top>=0){
        for(i=top;i>=0;i--){
            printf("%d\n",arr[i]);
        }
    }
    else{
        printf("empty");
    }
}