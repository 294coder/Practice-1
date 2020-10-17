#include "seqlist.h"

int seqpread() {
	int x;
	scanf_s("%d", &x);
	return x;
}
void seql_init(Seqlist* h) {
	h->length = 0;
}
Seqlist* createseq(Seqlist* h) {
	int x;
	printf_s("INPUT '-1' to End Input!\n");
	x = seqpread();
	while (x != -1) {
		h->data[h->length] = x;
		h->length++;
		x = seqpread();
	}
	return h;
}
int seq_del(Seqlist* h, int pos) {

	if (h->length == 0) {
		printf_s("Underflow! Delete Failed!");
		return false;
	}
	if (pos <= 0 || pos > h->length) {
		printf_s("Wrong postion! Delete Failed!");
		return false;
	}
	for (int i = pos;i < h->length;i++)
		h->data[i - 1] = h->data[i];
	h->length--;
	return true;

}

void print_seql(Seqlist* h) {
	if (h->length == 0) {
		printf_s("Empty SeqenceList!");
		return;
	}
	for (int i = 0;i < h->length;i++) {
		printf_s("%d ", h->data[i]);
	}
	std::cout << std::endl;
	return;
}