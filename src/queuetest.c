/*
 * testing of basic FIFO queue
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char *argv[])
{
	Queue queue = init();
	int i;
	i = 0;
	int *p;
	while (i < 300)
	{
		p = malloc(sizeof(int));
		*p = i++;
		enqueue(queue, p);
	}	
	
	while (!isempty(queue))
	{
		printf("%d ", *(int *)dequeue(queue));
	}
	printf("\n");
	return 0;
}