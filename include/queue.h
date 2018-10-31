/*
 * basic FIFO queue
 * the queue can be used in single-thread program.
 * if used in multi-thread program, must be  ensure 
 * thread safety by other methods.
 */
#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

extern struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef void *Qnode;


/*
 * initialize the queue
 * the initial capacity is 2 << DEF_BASE
 */
Queue init();

/*
 * free the space of the queue
 */
void destroy(Queue queue);

/*
 * enqueue a data to the queue
 */
void  enqueue(Queue queue, Qnode p);

/*
 * dequeue a data from the queue
 */
Qnode dequeue(Queue queue);

/* 
 * get the first data of the queue
 */
Qnode front(Queue queue);

/*
 * get the size of the queue
 */
int   size(Queue queue);

int isempty(Queue queue);

// static void expand(void *Q);
// static void reduct(void *Q);

#endif