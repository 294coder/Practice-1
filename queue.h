#pragma once
#ifndef __QUEUE_H_
#define __QUEUE_H_
#include "iostream"
#define MAX 5
#define FULL 1
#define NOTFULL 0
#define EMPTY 1
#define NOTEMPTY 0

//—≠ª∑∂”¡–
struct Queue {
	int data[MAX];
	int front;
	int rear;
};
int que_pread(void);

int que_full_check(Queue*);
int que_emp_check(Queue*);


Queue* queue_init(Queue*);
Queue* que_push(Queue*, int);
Queue* que_pop(Queue*);
void que_print(Queue*);
int que_len(Queue*);

#endif