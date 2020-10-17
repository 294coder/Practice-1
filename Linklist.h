#pragma once
#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_
#include "iostream"
#include "malloc.h"

struct Linklist {
	int data;
	Linklist* prior;
	Linklist* next;
};

int linkl_insert_forward(Linklist*, int, int);
int linkl_delete(Linklist*, int);
int linkl_pread(void);
void linkl_printl(Linklist*);
Linklist* linkl_init(Linklist*);
Linklist* Link_create(Linklist*);

#endif 
