#include "queue.h"

int que_pread() {
	int x;
	scanf_s("%d", &x);
	return x;
}
Queue* queue_init(Queue* q) {
	//输入不超过4个元素
	q->rear = 0;
	q->front = 0;
	int len = 0;
	int x;
	printf_s("INPUT '-1' to End Input!\n");
	x = que_pread();
	while (x != -1 && len!=MAX-1) {
		q->data[q->rear+1] = x;
		q->rear = (q->rear+1) % MAX;
		len++;
		x = que_pread();
	}
	return q;
}

int que_full_check(Queue* q) {
	if (q->front == (q->rear + 1) % MAX) {
		return FULL;
	}
	else {
		return NOTFULL;
	}
}
int que_emp_check(Queue* q) {
	int p = q->front;
	if (p == q->rear) {
		return EMPTY;
	}
	else {
		return NOTEMPTY;
	}
}
Queue* que_push(Queue* q, int d) {
	
	if (que_full_check(q)) {
		printf_s("Queue is Full, Can't Push a Element in\n");
		return q;
	}
	else {
		
		q->data[(q->rear+1)%MAX] = d;
		printf_s("Push Successful!\n");
		q->rear = (q->rear+1) % MAX;
		return q;
	}
}
Queue* que_pop(Queue* q) {
	if (que_emp_check(q)) {
		printf_s("Queque is Empty, Can't Pop a Element out!\n");
		return q;
	}
	else {
		q->data[(q->front + 1) % MAX] = 0;
		q->front = (q->front+1) % MAX;
		printf_s("Pop Successful!\n");
		return q;
	}	
}
void que_print(Queue* q) {
	int p = q->front;
	if (que_emp_check(q)) {
		printf_s("Empty Queue!\n");
		return;
	}
	printf_s("queue: ");
	while (p != q->rear) {
		printf_s("%d ", q->data[(p+1)%MAX]);
		p = (p+1) % MAX;
	}
	std::cout << std::endl;
	return;
}

int que_len(Queue* q) {
	int p = q->front;
	int len = 0;
	if (que_emp_check(q)) {
		return 0;
	}
	while (p != q->rear) {
		p = (p+1) % MAX;
		len++;
	}
	return len;
}

