#include <iostream>
using namespace std;

class Animal {
public:
	virtual ~Animal() {}

	virtual void makeSound() = 0;

};

class Dog : public Animal {
public:
	virtual void makeSound() override {
		cout << "港港港港港港港港港港港港" << endl;
	}
};

class Cat : public Animal {
public:
	virtual void makeSound() override {
		cout << "成成成成成成成成成成成成" << endl;
	}
};

class Cow : public Animal {
public:
	virtual void makeSound() override {
		cout << "澜皋澜皋澜皋澜皋澜皋澜皋" << endl;
	}
};

int main() {
	Dog dog1;
	Dog dog2;
	Dog dog3;
	Cat cat1;
	Cat cat2;
	Cat cat3;
	Cow cow1;
	Cow cow2;
	Cow cow3;
	Cow cow4;

	Animal* animals[10] = { &dog1, &dog2, &cow1, &cat3, &cat2, &dog3, &cow3, &cat1, &cow2, &cow4 };

	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
	}

	return 0;
}