#include<iostream>






void foo1(int iA) {}

void foo2(int& i) {}

void foo3(const int& iC) {}


int main() {

	int test1 = 0;

	foo1(test1);
	foo2(test1);
	foo3(test1);

	foo1(test1 + 1);
	foo2(test1 + 1);
	foo3(test1 + 1);

	foo1(test1++);
	foo2(test1++);
	foo3(test1++);

	foo1(++test1);
	foo2(++test1);
	foo3(++test1);




	return 0;
}


