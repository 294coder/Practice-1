#pragma once
#include "iostream"

#ifndef __MYSTACK_H
#define __MYSTACK_H
#define MAX 4
#define FULL 1
#define NOT_FULL 0
#define EMPTY 1
#define NOT_EMPTY 0

struct Stack{
	char num[MAX];
	int top;
};
void stack_init(Stack*);
int sta_emp_check(Stack*);
int sta_full_check(Stack* s);
void stack_push(Stack*, int);
void stack_pop(Stack*);
int access_top(Stack*);
int stack_pread(void);
Stack* stack_create(Stack*);
void stack_print(Stack*);
#endif