#pragma once
#ifndef __SEQLIST_
#define __SEQLIST_
#include "iostream"
#define Maxsize 100
//数组实现
struct Seqlist {
	int data[Maxsize];
	int length;
};

void seqpread(Seqlist*);
void seql_init(Seqlist*);
void print_seql(Seqlist*);
int seq_del(Seqlist*, int);
Seqlist* createseq(Seqlist*);

#endif