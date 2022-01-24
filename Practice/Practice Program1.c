//Stack Practice Program

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int i;
    struct node *ptr;
}*t1,*t2,*temp;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();
void stackcount();

 
int count = 0;
 
void main()
{
    int n, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Dipslay");
    printf("\n 7 - Stack Count");
 
    
 
    while (1)
    {
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (t1 == NULL)
                printf("There is no elements in the stack");
            else
            {
                e = topelement();
                printf("\n Top element : %d", e);
            }
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
            stackcount();
            break;
        
        default :
            printf(" You made a wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 


/* Push data into stack */
void push(int data)
{
    if (t1 == NULL)
    {
        t1 =(struct node *)malloc(1*sizeof(struct node));
        t1->ptr = NULL;
        t1->i = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = t1;
        temp->i = data;
        t1 = temp;
    }
    count++;
}
 
/* Pop Operation on stack */
void pop()
{
    t2 = t1;
 
    if (t2 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        t2 = t2->ptr;
    printf("\n Popped value : %d", t1->i);
    free(t1);
    t1 = t2;
    count--;
}
/* Display stack elements */
void display()
{
    t2 = t1;
 
    if (t2 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (t2 != NULL)
    {
        printf("%d ", t2->i);
        t2 = t2->ptr;
    }
 }
 

/* Count stack elements */
void stackcount()
{
    printf("\n No. of elements in stack : %d", count);
}
 
 
/* Return top element */
int topelement()
{
    return(t1->i);
}
 
/* Check if stack is empty or not */
void empty()
{
    if (t1 == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}
 

