#pragma once
#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_
#include "iostream"
#define EMPTY 1
#define NOT_EMPTY 0

struct Linkstack {
	int data;
	Linkstack* next;
};
void lsta_init(Linkstack**);
Linkstack* lsta_create(Linkstack**);
int lsta_pread(void);
void lsta_push(Linkstack**, int);
void lsta_pop(Linkstack**);
void lsta_print(Linkstack*);
int lsta_emp_check(Linkstack*);
#endif