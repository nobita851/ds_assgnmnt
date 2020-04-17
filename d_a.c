#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
  int front;
  int rear;
  int length;
  int *arr;
}queue;

queue *init_queue(int size)
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = q->rear = -1;
  q->length = size;
  q->arr = (int *)malloc(sizeof(int)*size);
  return q;
}

int is_empty(queue *q)
{
  return q->front == -1;
}

int is_full(queue *q)
{
  return q->front == (q->rear+1) % q->length;
}

void enqueue(queue *q, int key)
{
  if(is_empty(q))
  {
    q->arr[++q->rear] = key;
    q->front += 1;
  }
  else if(!is_full(q))
  {
    q->rear = (q->rear+1) % q->length;
    q->arr[q->rear] = key;
  }
  else
  {
    printf("\nError queue full. Initialize queue with more space "
           "or delete some elements.\n");
  }
}

int dequeue(queue *q)
{
  int dequeued = -1;
  if(!is_empty(q))
  {
    dequeued = q->arr[q->front];
    q->front = (q->front+1)%q->length;
    if(q->front == q->rear)
    {
      q->front = q->rear = -1;
    }
  }
  else
  {
    printf("\nError queue empty. Initialize queue first.\n");
  }
  return dequeued;
}

void traverse(queue *q)
{
  int print_till = q->rear;
  printf("\nQueue: ");
  if(q->rear < q->front)
  {
    print_till = q->length-1;
  }
  for(int i=q->front; i<=print_till; i++)
  {
    printf("%d->", q->arr[i]);
  }
  if(print_till != q->rear)
  {
    for(int i=0; i<= q->rear; i++)
    {
      printf("%d->", q->arr[i]);
    }
  }
  printf("\n");
}

int main()
{
  int choice, size, key;
  printf("Enter size of queue to initialize: ");
  scanf("%d", &size);
  queue *q = init_queue(size);
  do
  {
    printf("\nEnter\n1. To Enqueue\n2. To Dequeue\n3. Traverse\n4. Exit\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
      printf("Enter value to enqueue: ");
      scanf("%d", &key);
      enqueue(q, key);
    }
    else if(choice == 2)
    {
      key = dequeue(q);
      if(key != -1)
      {
        printf("Dequeued value: %d\n", key);
      }
    }
    else if(choice == 3)
    {
      traverse(q);
    }
    else
    {
      choice = -1;
    }
  }while(choice != -1);
}