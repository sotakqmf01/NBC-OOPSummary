#include <iostream>
#include <string>
using namespace std;

class A {
public:
	virtual ~A() {}
};

class B : public A {

};

class C : public A {

};

class D : public A {

};

int main() {
	A** ppA;

	ppA = new A*[5];

	//---------------------------

	A* b = new B();
	int i = 10;

	B* isB = reinterpret_cast<B*>(i);
	C* isC = reinterpret_cast<C*>(i);
	D* isD = reinterpret_cast<D*>(i);

	isB = dynamic_cast<B*>(b);
	isC = dynamic_cast<C*>(b);
	isD = dynamic_cast<D*>(b);

	return 0;
}
