//Queue Practice Program

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int i;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontelement();
void enque(int data);
void deque();
void empty();
void display();
void queuesize();
 
int count = 0;
 
void main()
{
    int n, ch, e;
 
    printf("\n 1 :- Enque");
    printf("\n 2 :- Deque");
    printf("\n 3 :- Front element");
    printf("\n 4 :- Empty");
    printf("\n 5 :- Exit");
    printf("\n 6 :- Display");
    printf("\n 7 :- Queue size");
    while (1)
    {
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &n);
            enq(n);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("You have made a wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 

 

void enque(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->i = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->i = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
 
/* Deleting elements from  the queue */
void deque()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Deleted value : %d", front->i);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Deleted value : %d", front->i);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->i);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->i);
}

/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Filling  the queue */
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->i);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue is empty");
    else
       printf("Queue is not empty");
}
