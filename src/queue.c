/*
 * the implemention of the queue
 */
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#define DEF_BASE 7
#define DEF_LOAD 0.2

struct QueueRecord
{
	int head;
	int tail;
	int capacity;
	Qnode *data;	
};

static void expand(Queue queue);

Queue init()
{
	Queue queue = (Queue) malloc(sizeof(struct QueueRecord));
	if (!queue)
	{
		printf("can not init the queue\n");
		exit(1);
	}
	queue->head = 0;
	queue->tail = 0;
	queue->capacity = 2 << (DEF_BASE - 1);
	queue->data = (Qnode *) malloc(sizeof(Qnode) * queue->capacity);
	return queue;
}



static void destroydata(Queue queue)
{
	if (queue->data)
	{
		int len = sizeof(queue->data) / sizeof(Qnode);
		while (len--)
		{
			free(queue->data[len]);
		}
		
		free(queue->data);
	}
}

void destroy(Queue queue)
{
	if (queue)
	{
		destroydata(queue);
		free(queue);
	}
}

inline int size(Queue queue)
{
	return queue->tail - queue->head;
}

inline int isempty(Queue queue)
{
	return queue->tail == queue->head;
}

void enqueue(Queue queue, Qnode p)
{
	if (queue && queue->data)
	{
		if (size(queue) == queue->capacity)
		{
			expand(queue);
		}
		queue->data[queue->tail++ & (queue->capacity - 1)] = p;
	}
}

Qnode dequeue(Queue queue)
{
	if (!queue || !queue->data || isempty(queue))
	{
		return NULL;
	}
	return queue->data[queue->head++ & (queue->capacity - 1)];
}

Qnode front(Queue queue)
{
	if (!queue || !queue->data || isempty(queue))
	{
		return NULL;
	}
	return queue->data[queue->head & (queue->capacity - 1)];
}

static void expand(Queue queue)
{
	int oldcap = queue->capacity;
	int h = queue->head;
	int t = queue->tail;
	queue->capacity <<= 1;
	Qnode *newdata = (Qnode *) malloc(sizeof(Qnode) * queue->capacity);
	int i, len;
	i = 0;
	len = t - h;
	while (h < t)
	{
		newdata[(queue->capacity - len + i++) & (queue->capacity - 1)] = queue->data[h++ & (oldcap - 1)];
	}
	destroydata(queue);
	queue->data = newdata;
	queue->head = queue->capacity - len;
	queue->tail = queue->capacity;
}

static void reduce(Queue queue)
{
	int oldcap = queue->capacity;
	int h = queue->head;
	int t = queue->tail;
	queue->capacity >>= 1;
	Qnode *newdata = (Qnode *) malloc(sizeof(Qnode) * queue->capacity);
	int i, len;
	i = 0;
	len = t - h;
	while (h < t)
	{
		newdata[(queue->capacity - len + i++) & (queue->capacity - 1)] = queue->data[h++ & (oldcap - 1)];
	}
	destroydata(queue);
	queue->data = newdata;
	queue->head = queue->capacity - len;
	queue->tail = queue->capacity;
}