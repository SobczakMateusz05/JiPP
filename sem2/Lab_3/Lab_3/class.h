#pragma once

class A {
	char* text;
public:
	A() noexcept : text(NULL) { std::cout << "default constructor\n"; };
	A(const char* new_text);
	A(const A& ob);
	A(A&& ob) noexcept;
	~A();
	void disp() { if (text) std::cout << text << std::endl; }
private:
	void alloc(const size_t size);
};