#include "book.h"

void book_init(Bookinfo* b) {
	b->num = 0;
}
void book_create(Bookinfo* b) {
	//char bookname1[10] = "Basic";
	//char bookname2[10] = "VB";
	//char bookname3[10] = "C";
	//char bookname4[10] = "dephi";

	std::string bookname1 = "Basic";
	std::string bookname2 = "VB";
	std::string bookname3 = "C";
	std::string bookname4 = "dephi";

	//char author1[10] = "Zhang";
	//char author2[10] = "Li";
	//char author3[10] = "Wang";
	//char author4[10] = "Zhao";
	std::string author1 = "Zhang";
	std::string author2 = "Li";
	std::string author3 = "Wang";
	std::string author4 = "Zhao";

	int price1 = 15;
	int price2 = 20;
	int price3 = 18;
	int price4 = 23;

	for (int i = 0;i < MAXNUM;i++) {
		switch (i) {
		case 0:
			b->data[i].num = i + 1;
			b->data[i].bookname = bookname1;
			b->data[i].author = author1;
			b->data[i].price = price1;
			break;
		case 1:
			b->data[i].num = i + 1;
			b->data[i].bookname = bookname2;
			b->data[i].author = author2;
			b->data[i].price = price2;
			break;
		case 2:
			b->data[i].num = i + 1;
			b->data[i].bookname = bookname3;
			b->data[i].author = author3;
			b->data[i].price = price3;
			break;
		case 3:
			b->data[i].num = i + 1;
			b->data[i].bookname = bookname4;
			b->data[i].author = author4;
			b->data[i].price = price4;
			break;
		default:
			b->data[i].num = 0;
			b->data[i].bookname = "\0";
			b->data[i].author = "\0";
			b->data[i].price = 0;
			break;

		}
	}
	b->num = 4;
	return;

}
void book_print(Bookinfo* b) {
	std::cout << std::left << std::setw(10) << "编号" << std::left << std::setw(10) << "书名" << std::left << std::setw(10) << "作者" << std::left << std::setw(10) << "价格" << std::endl;
	for (int i = 0;i < b->num;i++) {
		//printf_s("%3d", b->data[i].num);
		//printf_s("%7s", b->data[i].bookname);
		//printf_s("%7s", b->data[i].bookname);
		//printf_s("%3d", b->data[i].price);
		if (b->data[i].num != 0) {
			
			std::cout << std::left << std::setw(10) << b->data[i].num << std::left << std::setw(10) << b->data[i].bookname << std::left << std::setw(10) << b->data[i].author << std::left << std::setw(10) << b->data[i].price << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
}
//向后插入
void book_insert(Bookinfo* b, int pos, int num, /*char*/std::string bookname, /*char*/std::string author, int price) {
	if (pos > b->num || pos < 0) {
		std::cout << "Wrong Position, Can't Insert!" << std::endl;
	}
	else {
		int i = b->num - 1;
		for (;i >= pos;i--) {
			b->data[i + 1] = b->data[i];
		}
		Book* temp = new(Book);
		temp->author = author;
		temp->bookname = bookname;
		temp->price = price;
		temp->num = num;
		b->data[pos] = *temp;
		b->num++;
	}
	return;
}
void book_delete(Bookinfo* b, int pos) {
	if (pos > b->num || pos < 0) {
		std::cout << "Wrong Position, Can't Delete!" << std::endl;
	}
	else {
		int i = b->num - 1;
		for (;i >= pos;i--) {
			b->data[i + 1] = b->data[i];
		}
	}
}