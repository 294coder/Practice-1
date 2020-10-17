#include "Linkstack.h"
int lsta_pread() {
	int x;
	scanf_s("%d", &x);
	return x;
}
void lsta_init(Linkstack** t) {
	*t = NULL;
	return;
}
Linkstack* lsta_create(Linkstack** t) {
	int x;
	printf_s("INPUT '-1' to End Input!\n");
	x = lsta_pread();
	while (x != -1) {
	Linkstack* s = (Linkstack*)malloc(sizeof(Linkstack));
	if (!s)
	{
		printf("Memory out !\n");
		return *t;
	}
		s->data = x;
		s->next = *t;
		*t = s;
		x = lsta_pread();
	}
	return *t;
}
int lsta_emp_check(Linkstack* t) {
	if (t == NULL) {
		return EMPTY;
	}
	else {
		return NOT_EMPTY;
	}
}
void lsta_push(Linkstack** t, int d) {
	Linkstack* s = (Linkstack*)malloc(sizeof(Linkstack));
	if (!s)
	{
		printf("Memory out !\n");
		return;
	}
	s->data = d;
	s->next = *t;
	(*t) = s;
	printf_s("Push Successfully!\n");
}
void lsta_pop(Linkstack** t) {
	Linkstack* p;
	if (lsta_emp_check(*t)) {
		printf_s("Linkstack is Empty, Can't Pop!\n");
		return;
	}
	else {
		p = (*t);
		(*t) = (*t)->next;
		free(p);
		printf_s("Pop Successfully!\n");
	}
}
void lsta_print(Linkstack* t) {
	if (lsta_emp_check(t)) {
		printf_s("Linkstack is Empty!\n");
		return;
	}
	else {
		Linkstack* p = t;
		printf_s("Linkstack: ");
		while (p!= NULL) {
			printf_s("%d ", p->data);
			p = p->next;
		}
	}
	printf_s("\n");
}

