#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int key;
  struct node *next;
  struct node *prev;
}node;

typedef struct dll
{
  node *front;
  node *rear;
}dll;

dll *init_dll()
{
  dll *d = (dll *)malloc(sizeof(dll));
  d->front = NULL;
  d->rear = NULL;
  return d;
}

node *create_node(int key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

int is_empty(dll *d)
{
  return d->front == NULL;
}

int is_full(dll *d)
{
  return d->rear->next == d->front;
}

void enqueue(dll *d, int key, int is_ready)
{
  node *new_node = create_node(key);
  if(is_empty(d))
  {
    d->front = new_node;
    d->rear = d->front;
  }
  else if((is_full(d))&&(is_ready))
  {
    printf("\nQueue full. Delete some elements.\n");
  }
  else
  {
    d->rear->next = new_node;
    new_node->prev = d->rear;
    d->rear = new_node;
    d->rear->next = d->front;
    d->front->prev = d->rear;
  }
}

int dequeue(dll *d)
{
  node *temp;
  int key;
  if(is_empty(d))
  {
    printf("\nQueue empty. Enqueue first.\n");
    return -1;
  }
  else
  {
    temp = d->front;
    d->front = d->front->next;
    d->front->prev = d->rear;
    d->rear->next = d->front;
    key = temp->key;
    free(temp);
  }
  return key;
}

void traverse(dll *d)
{
  node *curr_node = d->front;
  printf("\n");
  printf("%d->", curr_node->key);
  curr_node = curr_node->next;
  while(curr_node != d->front)
  {
    printf("%d->", curr_node->key);
    curr_node = curr_node->next;
  }
  printf("\n");
}

int main()
{
  int choice, size, key, is_ready, utilized;
  dll *d = init_dll();

  printf("Enter number of elements to be inserted: ");
  scanf("%d", &size);
  utilized = is_ready = 0;

  do
  {
    printf("\nEnter\n1. To Enqueue\n2. To Dequeue\n3. Traverse\n4. Exit\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
      if(utilized == size)
      {
        is_ready = 1;
      }
      printf("Enter value to enqueue: ");
      scanf("%d", &key);
      enqueue(d, key, is_ready);
      if(!is_ready)
      {
        utilized += 1;
      }
    }
    else if(choice == 2)
    {
      key = dequeue(d);
      if(key != -1)
      {
        printf("Dequeued value: %d\n", key);
        utilized -= 1;
      }
      if(utilized < size)
      {
        is_ready = 0;
      }
    }
    else if(choice == 3)
    {
      traverse(d);
    }
    else
    {
      choice = -1;
    }
  }while(choice != -1);
}