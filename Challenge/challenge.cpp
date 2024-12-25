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
		cout << "                   �۸� �п�" << endl;
	}
};

class Cat : public Animal {
public:
	virtual void makeSound() override {
		cout << "                     �ɳɳ�" << endl;
	}
};

class Cow : public Animal {
public:
	virtual void makeSound() override {
		cout << "                     ����~" << endl;
	}
};

class Zoo {
private:
// Animal** �� : animals�� ����ִ� �ּҸ� ���󰡸� (Animal*) ���� �ִ�
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
// ���� ó�� 1 - (�߰� �ź�)
	//if (animalCount >= capacity) {
	//	cout << "�������� ������ �ʹ� ���ƿ�.. ������ �߰��� �� �����ϴ�" << endl;
	//	return;
	//}

// ���� ó�� 2 - (�迭 �߰�)
	if (animalCount >= capacity) {
		capacity *= 1.5;

		Animal** newAnimals = new Animal*[capacity];

		for (int i = 0; i < animalCount; i++) {
			newAnimals[i] = animals[i];
		}

		delete[] animals;

		animals = newAnimals;
	}

// �� �� �� �ϳ��� nullptr�� �ƴ�
	Dog* isDog = dynamic_cast<Dog*>(animal);
	Cat* isCat = dynamic_cast<Cat*>(animal);
	Cow* isCow = dynamic_cast<Cow*>(animal);
	string species;

	if (isDog != nullptr) species = "dog";
	if (isCat != nullptr) species = "cat";
	if (isCow != nullptr) species = "cow";

	animals[animalCount] = animal;
	animalCount++;
	cout << "        ������ �߰��߾��(" << species << ")" << endl;
}

void Zoo::performActions() {
	cout << "           --------�� �� ��---------- " << endl;
	if (animalCount == 0) {
		cout << "���� ������ �Ѹ����� �����. ������ �߰����ּ���" << endl;
	}
	else {
		for (int i = 0; i < animalCount; i++) {
			animals[i]->makeSound();
		}
		cout << "                           (���� : " << animalCount << "����) " << endl;
	}
	cout << "           -------------------------- " << endl;
}

Animal* createRandomAnimal();

int main() {
	int menu;
	Zoo zoo;
	
	while (1) {
		cout << "=================== �� �� �� ===================" << endl;
		cout << " [1] ���� ���� �� �߰�  [2] ���� ����  [0] ���� " << endl;
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
			cout << "�������� ���� �ݾҽ��ϴ�" << endl;
			break;
		}
		else {
			cout << "�� �𸣰ھ��. �޴��� �ٽ� �������ּ���." << endl;
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