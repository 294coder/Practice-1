#include "iostream"
#include "Mylist.h"
#include "memory"
#include "new"
#include "malloc.h"
#include "string"

int pread()
{
	int x;
	std::cin >> x;
	//printf("%c",&x);
	return(x);
}
mylist* createsl(mylist* h)
{
	mylist* p, * s;
	//int j;
	int x;
	x = pread();
	p = h;
	while (x != -1)
	{
		s = (mylist*)malloc(sizeof(mylist));
		if (!s)
		{
			printf("Memory out !\n");
			return 0;
		}
		s->data = x;
		p->next = s;
		p = s;
		x = pread();
	}
	p->next = NULL;
	return(h);
}
mylist* initiatesl(mylist* h)
{
	h->next = NULL;
	return(h);
}
void print_l(mylist* h) {
	mylist* p = h;
	//printf_s("**********show content**********\n");
	if (p->next != NULL) {
		p = p->next;
		printf_s("head->(%d)", p->data);
	}
	else {
		return;
	}
	while (p->next != NULL) {
		printf_s("->(%d)", p->next->data);
		p = p->next;
	}
	printf_s("\n");
	//printf_s("*********show completely*********\n");
	return;
}
mylist* list_init(mylist *h) {
	printf_s("INPUT '-1' to End Input!\n");
	h = initiatesl(h);
	h = createsl(h);
	print_l(h);
	return h;
}
mylist list_init() {
	//只能使用一次
	//测试使用
	static mylist head;//头结点
	head.next = NULL;

	static mylist* LIST, * LIST2, * LIST3;

	LIST = (mylist*)malloc(sizeof(mylist));
	LIST->data = 1;

	LIST2 = (mylist*)malloc(sizeof(mylist));
	LIST2->data = 2;
	LIST->next = LIST2;

	LIST3 = (mylist*)malloc(sizeof(mylist));
	LIST3->data = 3;
	LIST2->next = LIST3;

	LIST3->next = NULL;
	head.next = LIST;

	return head;
};
void mylist_out(mylist* head) {
	mylist* p = head;
	while (p->next != NULL) {
		std::cout << p->next->data << std::endl;  
		p = p->next;
	}
	std::cout << "Output Completely!" << std::endl;
}
bool myinsert_back(mylist* head, int pos, /*char ch*/int ch) {
	int now_pos = 0;
	mylist* j;
	mylist* create_list = (mylist*)malloc(sizeof(mylist));

	for (j = head;j->next != NULL;j = j->next, now_pos++) {
		if (now_pos == pos - 1 && j->next->next == NULL) {
			create_list->data = ch;
			j->next->next = create_list;
			create_list->next = NULL;
			std::cout << "Insert Successfully!" << std::endl;
			return true;
		}
		if (now_pos == pos - 1 && j->next->next != NULL) {
			create_list->data = ch;
			create_list->next = j->next->next;
			j->next->next = create_list;
			std::cout << "Insert Successfully!" << std::endl;
			return true;
		}
	}
	if (j->next == NULL && now_pos < pos) {
		std::cout << "Can not Insert!" << std::endl;
		return false;
	}
}
bool myinsert_forward(mylist* head, int pos, /*char ch*/int ch) {
	int now_pos = 0;
	mylist* j;
	mylist* create_list = (mylist*)malloc(sizeof(mylist));

	for (j = head;j->next != NULL;j = j->next, now_pos++) {
		if (now_pos == pos - 1) {
			create_list->data = ch;
			create_list->next = j->next;
			j->next = create_list;
			std::cout << "Insert Successfully!" << std::endl;
			return true;
		}
	}
	//if (j->next == NULL && now_pos == pos) {
	//	create_list->data = ch;
	//	j->next = create_list;
	//	create_list->next = j->next->next;
	//	std::cout << "Insert Successfully!" << std::endl;
	//	return true;
	//}
//	else {
		std::cout << "Can not Insert!" << std::endl;
		return false;
//	}
}
bool mydelete(mylist* head,int pos) {
	//printf_s("**********Delete starts!**********\n");
	if(pos <= 0)	std::cout << "Can not Delete" << std::endl;
	mylist* j;
	
	int now_pos = 0;
	for (j = head;j->next != NULL ;j = j->next, now_pos++) {
		//找到要删除的结点的前一个结点
		if (now_pos == pos-1) {
			if (j->next->next != NULL) {
				mylist* del = j->next;

				//重新连接
				j->next = j->next->next;

				free(del);

				std::cout << "Delete Successfully!" << std::endl;
				return true;
			}
			else {
				free(j->next);
				j->next = NULL;
				//std::cout << "**********Delete Successfully!**********" << std::endl;
				return true;
			}
		}
	
	}
	if (j->next == NULL && now_pos < pos) {
			std::cout << "Can not Delete" << std::endl;
			return false;
		}
}
int myfind(mylist* head, /*char ch*/int ch) {
	mylist* j;
	int pos = 0;
	for (j = head->next;j != NULL;j = j->next, pos++) {
		if (j->data == ch)
			return pos+1;
	}
	return -1;
}
int mycount(mylist* head, /*char ch*/int ch) {
	mylist* j;
	int count = 0;
	for (j = head->next;j != NULL;j = j->next) {
		if (j->data == ch)
			count++;
	}
	if (count == 0) {
		std::cout << "Can not Find the Element!" << std::endl;
		return false;
	}
	else {
		return count;
	}
}
int	list_len(mylist* head) {
	mylist* p = head;
	int len = 0;
	while (p->next != NULL) {
		len++;
		p = p->next;
	}
	return len;
}
void len_check(mylist* head) {
	int length;
	length = list_len(head);
	printf_s("list's length = %d\n", length);
}