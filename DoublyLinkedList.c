#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
  struct node* prev;
};

//function to create a node and initialize it to provide value
struct node* createNode(int data)
{
  struct node* newNode= calloc(1,sizeof(struct node));
  newNode->data=data;
  newNode->next=NULL;
  newNode->prev=NULL;
  return newNode;
}

//function to push back a 
struct node* push_back(struct node* head ,int data)
{
  struct node* newNode=createNode(data);
  newNode->next=head;
  head->prev=newNode;
  return newNode;
}