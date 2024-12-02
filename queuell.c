#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
int nodecounter=0;

struct Node *CreateNode(){
	struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
	printf("Enter the data enqueue:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}

void enqueue(){
	struct Node *newnode = CreateNode();
	if(nodecounter<6){
	
    if (rear == NULL) { 
        front = rear = newnode;
        rear->next=front;
    } else {
        rear->next = newnode;
        rear = newnode;  
		rear->next=front;     
    }
    nodecounter++;
}else{
	printf("Queue is full\n");
}
}

void dequeue(){
	if(front==NULL){
		printf("Queue is underflow!!");
	}else{
		printf("->Dequeued element is:%d\n",front->data);
		struct Node *temp=front;
		if(front== rear){
			front=rear=NULL;
		}else{
			front=front->next;
			rear->next=front;
		}
		free(temp);
		nodecounter--;
	}
}


void peek(){
	if(front==NULL){
		printf("Queue is empty\n");
	}else{
		printf("The front is :%d\n",front->data);
	}
}

void display(){
	if(front==NULL){
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements:");
	struct Node *temp=front;
	do{
		printf(" %d ",temp->data);
		temp=temp->next;
	
	} while(temp!=front);
	printf("\n");
}


int main(){
	int ch;
	while(1){
		printf("1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit");
		printf("Enter your choice:");
		scanf("%d", &ch);
        switch (ch) {
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
            default:
                printf("Enter correct choice:\n");
        }
    }
  
	}


