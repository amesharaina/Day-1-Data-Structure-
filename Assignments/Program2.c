#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int n1;                    
    struct node *nextptr;           
}*stnode;

void createNodeList(int n2); 
void displayList();         

int main()
{
    
    int n2;
	printf(" Enter the number of nodes : ");
    scanf("%d", &n2);
    createNodeList(n2);
    printf("\n Data entered in the list : \n");
    displayList();
    return 0;
}
void createNodeList(int n2)
{
    struct node *fnNode, *tmp;
    int n1, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {


        printf(" Enter data for node 1 : ");
        scanf("%d", &n1);
        stnode->n1 = n1;      
        stnode->nextptr = NULL; 
        tmp = stnode;

        for(i=2; i<=n2; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Enter  data for node %d : ", i);
                scanf(" %d", &n1);
 
                fnNode->n1 = n1;      
                fnNode->nextptr = NULL; 
 
                tmp->nextptr = fnNode; 
                tmp = tmp->nextptr; 
            }
        }
    }
}
void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->n1);       
            tmp = tmp->nextptr;         
        }
    }
} 
