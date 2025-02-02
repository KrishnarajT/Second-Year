// Queue thing
#include <stdio.h>
#define MAX_SIZE 5
int front = -1, rear = -1;

int queue[MAX_SIZE];

int isFull(void)
{
	if (rear == MAX_SIZE - 1)
		return (1);
	else
		return (0);
}

int isEmpty(void)
{
	if (rear == front)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int enqueue(int item)
{
	if (!isFull())
	{
		queue[++rear] = item;
	}
	else
	{
		printf("\nQUEUE OVERFLOW!\n");
	}
}

int dequeue(void)
{
	if (isEmpty())
	{
		printf("Queue is Empty \n\n QUEUE UNDERFLOW!!\n\n");
		return (-1);
	}
	else
	{
		// printf("Removed this thing %c\n", stack[top]);
		return (queue[++front]);
	}
}
void display_queue(void)
{
	int i;

	if (isEmpty())
	{
		printf("\n\nQueue is empty\n\n");
	}
	else
	{
		printf("Queue is: \n");
		for (i = front + 1; i <= rear; i++)
		{
			printf("%d \n", queue[i]);
		}
	}
}
int main(void)
{
	int choice;
	int temp;

	choice = 0;
	while (choice != 6)
	{
		printf("Enter what you want to do: \n\
    1. Add Job to the Ready Queue\n\
    2. Kill or Terminate Job from the Queue\n\
    3. See the Queue\n\
    4. Check if Ready Queue is Empty and Processor is free\n\
    5. Check if Ready Queue is full\n\
    6. Exit\n\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the Process Number of the Job you want to add. \n");
			scanf(" %d", &temp);
			enqueue(temp);
			display_queue();
			break;
		case 2:
			printf("Killing or Terminating Job from the Queue\n");
			dequeue();
			display_queue();
			break;
		case 3:
			display_queue();
			break;
		case 4:
			if (isEmpty())
			{
				printf("Yup, Queue is empty\n");
			}
			else
			{
				printf("Nope Queue isnt empty\n");
				display_queue();
			}
			break;
		case 5:
			if (isFull())
			{
				printf("\nYes the Queue is full!\n");
			}
			else
			{
				printf("No Queue isnt full!\n");
			}
			break;
		default:
			printf("\nThank You\n");
			break;
		}
	}
	return 0;
}