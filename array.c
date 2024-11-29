#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *L;
    struct node *R;

}*start=NULL;
void creat(int k)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("the memory allocation is failed we are sorry we can't continue at this moment\n");
        return;
    }
    temp->data=k;
    temp->L=NULL;
    temp->R=NULL;
    if(start==NULL)
    {
        start=temp;
    }
}
void insertion(struct node *temp,int k)
{
    if (temp==NULL)
    {
        printf("the memory allocation is failed try again\n");
        return;
    }

    if(temp==NULL)
    {
        temp=temp;
    }
    else if(k<temp->data)
    {
        temp->L=insertion(temp->L,k);
    }
    else if(k>temp->data)
    {
        temp->R=insertion(temp->R,k);
    }
    printf("the data %d is succesfully addes to the binary search tree\n",k);
}
void main()
{

}
