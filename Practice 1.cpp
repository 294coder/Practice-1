#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<deque>
#include<forward_list>
#include<list>
#include<cmath>
#include<malloc.h>
#include<complex>
#include<stack>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<cctype>
#include<functional>
#include<iomanip>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<utility>  
#include<memory>
#include<new>
#include<Mylist.h>
#include<seqlist.h>
#include<Linklist.h>
#include<queue.h>
#include<Mystack.h>
#include<Linkstack.h>
#include<paixu.h>
#include<book.h>
#include<iomanip>
#define NUM 10//VS2019数组大小报错
using namespace std;

void check1(void);
void check2(void);
void check3(void);
void check4(void);
void check5(void);
void check6(void);
void check7(int n[]);
void check8(int n[]);
void check9(int n[]);
void check10(int n[]);
void check11(int n[]);
void check12();
int main() {

	int n[NUM] = { 51,38,79,22,91,105,33,52,16,112 };
	int p;
	printf_s("Input a Number From 1 to 12 to Choose a Function!\n");
	printf_s("1.顺序表  2.单链表  3.双链表  4.循环队列  5.栈  6.链栈  \n7.插入排序  8.冒泡排序  9.选择排序  10.顺序查找  11.二分查找  \n12.顺序表操作\n");
	printf_s("Input -1 to End the Experiment!\n");
	while (1) {
		cout << "You Choose Experiment " << flush;
		cin >> p;
		cout << endl;
		if (p == -1) {
			cout << "Experiment End!\n" << endl;
			return 1;
		}
		printf_s("*************EXPERIMENT STARTS!****************\n");
		switch (p) {

		case 1:
			/****上机实验1 顺序表****/
			check1();
			break;
		case 2:
			/****上机实验2 单链表****/
			check2();
			break;
		case 3:
			/****上机实验3 双链表****/
			check3();
			break;
		case 4:
			/****上机实验4 循环队列****/
			check4();
			break;
		case 5:
			/****上机实验5 栈****/
			check5();
			break;
		case 6:
			/****上机实验6 链栈****/
			check6();
		case 7:
			/****上机实验7 插入排序****/
			check7(n);
			break;
		case 8:
			/****上机实验8 插入排序****/
			check8(n);
			break;
		case 9:
			/****上机实验9 插入排序****/
			check9(n);
			break;
		case 10:
			/****上机实验10 顺序查找****/
			check10(n);
			break;
		case 11:
			/****上机实验11 二分查找****/
			check11(n);
			break;
		case 12:
			/****上机实验12 顺序表操作****/
			check12();
			break;
		default:
			break;
		}
		cout << "*************EXPERIMENT OVER***************" << endl;
	}
}

void check1() {
	printf_s("********EXPERIMENT1 STARTS!********\n");
	Seqlist* h;
	h = (Seqlist*)malloc(sizeof(Seqlist));
	if (!h)
	{
		printf("Memory out !\n");
		return;
	}
	seql_init(h);
	createseq(h);
	seq_del(h, 4);
	print_seql(h);
	cout << "********EXPERIMENT1 OVER!********\n" << endl;
}
void check2() {

	printf_s("*******EXPERIMENT2 STARTS!******\n");
	mylist* head = (mylist*)malloc(sizeof(mylist));
	if (!head)
	{
		printf("Memory out !\n");
		return;
	}
	head = list_init(head);//初始化单链表
	int pos1,pos2;
	


	len_check(head);
	pos1 = myfind(head, 3);
	pos2 = myfind(head, 7);
	cout << "element 3's position is " << pos1 << " in list" << endl;
	if (pos2 == -1)	
		cout << "pos2 = -1, can't find this element in list!" << endl;

	mydelete(head, 2);
	mydelete(head, 5);

	print_l(head);
	cout << "*******EXPERIMENT2 OVER!*******\n" << endl;
}
void check3() {
	int num, pos1, pos2;
	printf_s("*******EXPERIMENT3 STARTS!******\n");
	Linklist* h = (Linklist*)malloc(sizeof(Linklist));
	if (!h)
	{
		printf("Memory out !\n");
		return;
	}
	linkl_init(h);
	Link_create(h);
	//打印
	linkl_printl(h);
	//输入num, pos
	printf_s("**Input num and pos with 'ONE SPACE'**\n");
	scanf_s("%d %d", &num, &pos1);
	//插入
	linkl_insert_forward(h, pos1, num);
	//打印
	linkl_printl(h);
	//删除
	printf_s("**Input a position to delete a element**\n");
	scanf_s("%d", &pos2);
	linkl_delete(h, pos2);
	//打印
	linkl_printl(h);
	cout << "*******EXPERIMENT3 OVER!*******\n" << endl;
}
void check4() {
	printf_s("*******EXPERIMENT4 STARTS!******\n");
	Queue *q;
	q = (Queue*)malloc(sizeof(Queue));
	if (!q)
	{
		printf("Memory out !\n");
		return;
	}
	queue_init(q);
	que_print(q);
	printf_s("%d\n", que_len(q));

	que_pop(q);
	que_pop(q);
	que_print(q);
	que_push(q, 4);
	que_push(q, 5);
	que_push(q, 6);
	que_print(q);
	que_push(q, 7);
	cout << "*******EXPERIMENT4 OVER!*******\n" << endl;
}
void check5() {
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	if (!s)
	{
		printf("Memory out !\n");
		return;
	}
	printf_s("*******EXPERIMENT5 STARTS!******\n");
	stack_init(s);
	stack_create(s);
	stack_print(s);

	stack_pop(s);
	stack_pop(s);
	stack_print(s);

	stack_push(s, 4);
	stack_push(s, 5);
	stack_push(s, 6);
	stack_print(s);

	//入栈不成功
	stack_push(s, 7);

	cout << "*******EXPERIMENT5 OVER!*******\n" << endl;
}
void check6() {
	Linkstack* top = (Linkstack*)malloc(sizeof(Linkstack));
	if (!top)
	{
		printf("Memory out !\n");
		return;
	}
	printf_s("*******EXPERIMENT6 STARTS!******\n");
	lsta_init(&top);
	lsta_create(&top);
	lsta_print(top);
	lsta_push(&top, 6);
	lsta_pop(&top);
	lsta_print(top);
	cout << "*******EXPERIMENT6 OVER!*******\n" << endl;
}
void check7(int n[]) {
	printf_s("*******EXPERIMENT7 STARTS!******\n");
	p_insert(n);
	cout << "*******EXPERIMENT7 OVER!*******\n" << endl;
}
void check8(int n[]) {
	printf_s("*******EXPERIMENT8 STARTS!******\n");
	bubble(n);
	cout << "*******EXPERIMENT8 OVER!*******\n" << endl;
}
void check9(int n[]) {
	printf_s("*******EXPERIMENT9 STARTS!******\n");
	xuanze(n);
	cout << "*******EXPERIMENT9 OVER!*******\n" << endl;
}
void check10(int n[]) {
	printf_s("*******EXPERIMENT10 STARTS!******\n");
	int* pn = xuanze(n);
	int pos1, pos2;
	pos1 = seq_find_first(pn, 52);
	pos2 = seq_find_first(pn, 36);
	if (pos1 > 0) {
		printf_s("Element 52 is in Position %d\n", pos1);
	}
	else {
		printf_s("Element 52 is Not in This Array!\n");
	}
	if (pos2 > 0) {
		printf_s("Element 36 is in Position %d\n", pos2);
	}
	else {
		printf_s("Element 36 is Not in This Array!\n");
	}
	cout << "*******EXPERIMENT10 OVER!*******\n" << endl;
}
void check11(int n[]) {
	printf_s("*******EXPERIMENT11 STARTS!******\n");
	int* pn = xuanze(n);
	int pos1 = half_find_first(n, 22);
	if (pos1 > 0) {
		printf_s("Element 22 is in Position %d\n", pos1);
	}
	else {
		printf_s("Element 22 is Not in This Array!\n");
	}
	cout << "*******EXPERIMENT11 OVER!*******\n" << endl;
}
void check12() {
	printf_s("*******EXPERIMENT12 STARTS!******\n");
	//Bookinfo* b = (Bookinfo*)malloc(sizeof(Bookinfo));
	Bookinfo* b = new(Bookinfo);//malloc不能为string构造，必须用new

	if (!b) 
	{
		printf("Memory out !\n");
		return;
	}
	book_init(b);
	book_create(b);
	book_print(b);
	book_insert(b, 4, 123, "程豪的养殖", "xhl", 1);
	book_print(b);
	book_delete(b, 4);
	book_print(b);
	book_paixu(b);
	printf_s("*******EXPERIMENT12 STARTS!******\n");
}
