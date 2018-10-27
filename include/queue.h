/*
 * basic queue
 * the queue can be used in single-thread program.
 * if used in multi-thread program, must be  ensure 
 * thread safety by other methods.
 */
#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H
#define T Queue_T

typedef T *Q;
typedef void *QNODE;

struct T 
{
	int head;
	int tail;
	QNODE data[];
};

/*
 * initialize the queue
 * the initial capacity is 2 << DEF_BASE
 */
Q init();

/*
 * free the space of the queue
 */
void destroy(Q queue);

/*
 * enqueue a data to the queue
 */
void  enqueue(Q queue, QNODE p);

/*
 * dequeue a data from the queue
 */
QNODE dequeue(Q queue);

/* 
 * get the first data of the queue
 */
QNODE front(Q queue);

/*
 * get the size of the queue
 */
int   size(Q queue);

// static void expand(void *Q);
// static void reduct(void *Q);

#undef T
#endif