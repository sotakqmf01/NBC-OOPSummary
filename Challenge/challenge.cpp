#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;

class Animal {
public:
	virtual ~Animal() {}

	virtual void makeSound() = 0;

};

class Dog : public Animal {
public:
	virtual void makeSound() override {
		cout << "                   멍멍 왈왈" << endl;
	}
};

class Cat : public Animal {
public:
	virtual void makeSound() override {
		cout << "                     냥냥냥" << endl;
	}
};

class Cow : public Animal {
public:
	virtual void makeSound() override {
		cout << "                     음메~" << endl;
	}
};

class Zoo {
private:
// Animal** 뜻 : animals에 들어있는 주소를 따라가면 (Animal*) 값이 있다
	Animal** animals;
	int animalCount = 0;
	int capacity = 10;

public:
	Zoo() {
		animals = new Animal*[capacity];
	}
	~Zoo();

	void addAnimal(Animal* animal);

	void performActions();
};

Zoo::~Zoo() {
	for (int i = 0; i < animalCount; i++) {
		delete animals[i];
	}
	animalCount = 0;
}

void Zoo::addAnimal(Animal* animal) {
// 예외 처리 1 - (추가 거부)
	//if (animalCount >= capacity) {
	//	cout << "동물원에 동물이 너무 많아요.. 동물을 추가할 수 없습니다" << endl;
	//	return;
	//}

// 예외 처리 2 - (배열 추가)
	if (animalCount >= capacity) {
		capacity *= 1.5;

		Animal** newAnimals = new Animal*[capacity];

		for (int i = 0; i < animalCount; i++) {
			newAnimals[i] = animals[i];
		}

		delete[] animals;

		animals = newAnimals;
	}

// 이 셋 중 하나는 nullptr이 아님
	Dog* isDog = dynamic_cast<Dog*>(animal);
	Cat* isCat = dynamic_cast<Cat*>(animal);
	Cow* isCow = dynamic_cast<Cow*>(animal);
	string species;

	if (isDog != nullptr) species = "dog";
	if (isCat != nullptr) species = "cat";
	if (isCow != nullptr) species = "cow";

	animals[animalCount] = animal;
	animalCount++;
	cout << "        동물을 추가했어요(" << species << ")" << endl;
}

void Zoo::performActions() {
	cout << "           --------개 조 심---------- " << endl;
	if (animalCount == 0) {
		cout << "아직 동물이 한마리도 없어요. 동물을 추가해주세요" << endl;
	}
	else {
		for (int i = 0; i < animalCount; i++) {
			animals[i]->makeSound();
		}
		cout << "                           (현재 : " << animalCount << "마리) " << endl;
	}
	cout << "           -------------------------- " << endl;
}

Animal* createRandomAnimal();

int main() {
	int menu;
	Zoo zoo;
	
	while (1) {
		cout << "=================== 동 물 원 ===================" << endl;
		cout << " [1] 동물 생성 및 추가  [2] 동물 보기  [0] 종료 " << endl;
		cout << " >> ";
		cin >> menu;

		if (menu == 1) {
			Animal* newAnimal = createRandomAnimal();
			zoo.addAnimal(newAnimal);
			cout << endl;
		}
		else if (menu == 2) {
			zoo.performActions();
			cout << endl;
		}
		else if (menu == 0) {
			cout << "동물원이 문을 닫았습니다" << endl;
			break;
		}
		else {
			cout << "잘 모르겠어요. 메뉴를 다시 선택해주세요." << endl;
		}	
	}

	return 0;
}

Animal* createRandomAnimal() {
	srand(time(NULL));

	int n = rand() % 3;

	switch (n) {
	case 0:
		return new Dog();
	case 1:
		return new Cat();
	case 2:
		return new Cow();
	default:
		break;
	}
	
	return nullptr;
}