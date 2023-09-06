#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

// function to create a node and assign it the provided value, return pointer to created node
struct node *createNode(int data)
{
  struct node *tmp = calloc(1, sizeof(struct node));
  tmp->data = data;
  tmp->next = NULL;
  return tmp;
}

// function to add a new element at the head of a linked list;
struct node *push_back(struct node *head, int x)
{
  struct node *newNode = createNode(x);
  newNode->next = head;
  return newNode;
}

// function to convert an array to a singly linked list(forward list)
struct node *arraytoList(int *arr, int len)
{
  struct node *ptr = createNode(arr[len - 1]);
  for (int i = (len - 2); i > -1; i--)
  {
    ptr = push_back(ptr, arr[i]);
  }
  return ptr;
}

// function to print the list.
void printList(struct node *ptr)
{
  struct node *curr = ptr;
  while (curr != NULL)
  {
    printf("[ %d ]-->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

// function to check if a given value is present in a linked list;
int present(struct node *head, int value)
{
  struct node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == value)
    {
      return +1;
    }
    curr= curr->next;
  }
  return 0;
}

//returns address of first instance of provided data, otherwise returns NULL
struct node* findValue(struct node* head, int value)
{
  struct node* curr= head;
  while (curr != NULL)
  {
    if (curr->data == value)
    {
      return curr;
    }
    curr= curr->next;
  }
  return NULL;
}

//deletes the first node in the liked list and return an updated linked list back
struct node* deleteElement(struct node *head)
{
  struct node* ptr = head->next;
  free(head);
  return ptr;
}

//code to completely delete a list, freeing all allocated memory
void destroyList(struct node* ptr)
{
  struct node *curr= ptr->next;
  free(ptr);
  while(curr!=NULL)
  {
    struct node* nxt = curr->next;
    free(curr);
    curr=nxt;
  }
}

//function to check if list has any elements
int isEmpty(struct node* head)
{
  if(head==NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//function to count number of elements
int length(struct node *head)
{
  int length=0;
  struct node* curr=head;
  while(curr != NULL)
  {
    length++;
    curr=curr->next;
  }
  return length;
}

//function to reverse an Linked Lists
struct node* reverseArray(struct node* ptr)
{
  struct node* newList = createNode(ptr->data);
  struct node* curr=ptr->next;
  while(curr!=NULL)
  {
    newList=push_back(newList,curr->data);
    curr=curr->next;
  }
  destroyList(ptr);
  return newList;
}  

void main()
{
  int arr[5] = {1, 20, 3, 4, 50};
  struct node *head = arraytoList(arr, 5);
  printList(head);
  head = push_back(head, 55);
  head = push_back(head, 101);
  printList(head);
  int l=length(head);
  printf("%d \n",l);
  head=reverseArray(head);
  printList(head);
}