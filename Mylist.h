#pragma once
#include "stdio.h"
#include "iostream"
#include "memory"
#include "string"

#ifndef _Mylist_h
#define _Mylist_h


struct mylist {
	mylist* next;
	//char data;
	int data;
};
struct error_check {
	bool error_check_insert_back;
	bool error_check_insert_forward;
	bool error_check_delete;
	int error_check_find_error_or_pos;
};
bool myinsert_back(mylist*,int ,/*char*/int);
bool myinsert_forward(mylist*, int, /*char*/int);
bool mydelete(mylist*, int);
void mylist_out(mylist*);
int myfind(mylist*, /*char*/int);
int mycount(mylist*, /*char*/int);
int	list_len(mylist*);
mylist list_init();
mylist* list_init(mylist*);
int pread(void);
void print_l(mylist*);
void len_check(mylist*);
#endif 