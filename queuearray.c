#include <stdio.h>
#include <stdlib.h>


#define SIZE 6
int queue[SIZE];
int front=-1;
int rear=-1;

void enqueue() {
    int item;
    if (rear == SIZE - 1) {
        printf("!!!Queue is overflow!!!\n");
    } else {
        printf("Enter element to enqueue: ");
        scanf("%d", &item);
        if (front == -1) { 
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}


void dequeue(){
	if(front==-1){
		printf("Queue is underflow!\n");
	}else{
		printf("Dequeued element is %d\n",queue[front]);
		if(front==rear){
			front=rear=-1;
		}else{
			front++;
		}
	}
}

void peek(){
	if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The front is: %d\n",queue[front]);
    }
}

void display(){
	int i;
	if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main(){
	int ch;
	
	while(1){
		printf("1. Enqueue\n2.dequeue\n3.peek\n4.display\n5.exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			 		enqueue();
			 		break;
			case 2:
					dequeue();
					break;
			case 3:
					peek();
					break;
			case 4:
					display();
					break;
			case 5:
					return 0;
					
			default:
					printf("enter correct choice:");						 		
		}
	}
}




