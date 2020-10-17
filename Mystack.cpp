#include "Mystack.h"

int stack_pread() {
	int x;
	scanf_s("%d", &x);
	return x;
}
void stack_init(Stack* s) {
	s->top = -1;
}
Stack* stack_create(Stack* s) {
	int x;
	int len = 0;
	printf_s("INPUT '-1' to End Input!\n");
	x = stack_pread();
	while (x != -1 && len <= MAX-1) {
		s->top++;
		s->num[s->top] = x;
		len++;
		x = stack_pread();
	}
	return s;
}
int sta_emp_check(Stack* s) {
	if (s->top == -1) {
		return EMPTY;
	}
	else {
		return NOT_EMPTY;
	}
}
int sta_full_check(Stack* s) {
	if (s->top == MAX - 1) {
		return FULL;
	}
	else {
		return NOT_FULL;
	}
}
int access_top(Stack* s) {
	return s->num[s->top];
}
void stack_pop(Stack* s) {
	if (sta_emp_check(s)) {
		printf_s("Empty Stack, Can't Pop!\n");
		return;
	}
	else {
		s->num[s->top] = 0;
		s->top--;
	}
	printf_s("Pop Successfully!\n");
	return;
}
void stack_push(Stack* s,int d) {
	if (sta_full_check(s)) {
		printf_s("Stack Full, Can't Push!\n");
		return;
	}
	else {
		s->top++;
		s->num[s->top] = d;
	}
	printf_s("Push Successfully!\n");
}
void stack_print(Stack* s) {
	if (sta_emp_check(s)) {
		printf_s("Stack is Empty!");
	}
	else {
		int p = s->top;
		printf_s("stack: ");
		while (p != -1) {
			printf_s("%d ", s->num[p]);
			p--;
		}
	}
	printf_s("\n");
	return;
}

