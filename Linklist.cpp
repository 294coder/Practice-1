#include "Linklist.h"


Linklist* linkl_init(Linklist* h) {
	h->next = NULL;
	h->prior = NULL;
	return h;
}
int linkl_pread(void) {
	int x;
	scanf_s("%d", &x);
	return x;
}
void linkl_printl(Linklist* h) {
	Linklist* p = h->next;
	if (h->next != NULL) {
		printf_s("head");
	}
	else {
		printf_s("Empty Linklist!");
		return;
	}
	while (p != NULL) {
		printf_s("->(%d)", p->data);
		p = p->next;
	}
	std::cout << std::endl;
	return;
}
Linklist* Link_create(Linklist* h) {
	Linklist* p, * s;
	int x;
	printf_s("INPUT '-1' to End Input!\n");
	x = linkl_pread();
	p = h;
	while (x != -1)
	{
		s = (Linklist*)malloc(sizeof(Linklist));
		if (!s)
		{
			printf("Memory out !\n");
			return 0;
		}
		s->data = x;
		s->prior = p;
		p->next = s;
		p = s;
		
		x = linkl_pread();
	}
	p->next = NULL;
	return(h);
}
int linkl_insert_forward(Linklist* h, int pos, int d) {
	int now_pos = 0;
	Linklist* j;
	Linklist* create_list = (Linklist*)malloc(sizeof(Linklist));

	for (j = h;j->next != NULL;j = j->next, now_pos++) {
		if (now_pos == pos - 1) {
			create_list->data = d;
			create_list->prior = j;
			create_list->next = j->next;
			j->next->prior = create_list;
			j->next = create_list;
			std::cout << "Insert Successfully!" << std::endl;
			return true;
		}
	}

	std::cout << "Can not Insert!" << std::endl;
	return false;
}
int linkl_delete(Linklist* h, int pos) {
	if (pos <= 0)	std::cout << "Can not Delete" << std::endl;
	Linklist* j;
	int now_pos = 0;
	for (j = h;j->next != NULL;j = j->next, now_pos++) {

		if (now_pos == pos - 1) {

			if (j->next->next != NULL) {
				//free(j->next);
				j->next->next->prior = j;
				j->next = j->next->next;
				std::cout << "Delete Successfully!" << std::endl;
				return true;
			}
			else {
				j->next = NULL;
				return true;
			}
		}

	}
}
