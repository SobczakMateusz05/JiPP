#include <iostream>
#include "class.h"

using namespace std;

A::A(const char* new_text) {
	cout << "parametrized constructor\n";
	size_t length = strlen(new_text) + 1;
	alloc(length );
	strcpy_s(text, length * sizeof(char), new_text);	
}

A::A(const A& ob) {
	cout << "copy constructor\n";
	text = NULL;
	if (ob.text) {
		size_t length = _msize((void*)ob.text) / sizeof(char);
		alloc(length);
		strcpy_s(text, length * sizeof(char), ob.text);
	}
}

A::A(A&& ob) noexcept {
	cout << "move constructor\n";
	text = ob.text;
	ob.text = nullptr;
}

A::~A() {
	cout << "destructor\n";
	if (text) {
		free(text);
		text = nullptr;
	}
}

void A::alloc(const size_t size) {
	text = (char*)malloc(size * sizeof(char));
}



