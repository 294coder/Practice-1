#pragma once
#ifndef __BOOKS_H_
#define __BOOKS_H_
#include "iostream"
#include "paixu.h"
#include "string"
#include "iomanip"
#define MAXNUM 10
struct Book {
	long int num;
	//char bookname[50];
	//char author[20];
	std::string bookname;
	std::string author;
	int price;
	void operator = (Book& a) {
		this->author = a.author;
		this->bookname = a.bookname;
		this->num = a.num;
		this->price = a.price;
	}
};
struct Bookinfo {
	Book data[MAXNUM];
	int num;
	
};	

void book_insert(Bookinfo* b, int pos, int num, /*char*/std::string bookname, /*char*/std::string author, int price);
void book_delete(Bookinfo*, int pos);
void book_init(Bookinfo*);
void book_create(Bookinfo*);
void book_print(Bookinfo*);
void book_paixu(Bookinfo*);

#endif