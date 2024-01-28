#include<iostream>
#include<string>
#include<vector>


class Human {
	
public:
	std::string name;
	int age;

	Human() {};

	~Human() {};
};
	



class Flat {
	
private:
	std::vector<Human*> obj_human;

public:
	int number;
	int room_number;
	Flat() {};
	
	void add_human(std::string name_,int age_) {
		Human* new_hum = new Human;
		new_hum -> name = name_;
		new_hum -> age = age_;

		obj_human.push_back(new_hum);
	}
	~Flat() {};
	
	void print_flat_parametrs() {
		std::cout << "Номер квартиры -> " << number << " Количество комнат -> "\
			<< room_number << "\n\n";
	}
		
	void print_flat() {
		std::cout << "Жильцы\n";
		for (int i = 0; i < obj_human.size(); i++) {
			std::cout <<"Имя: " << obj_human[i]->name << " Возраст: " << obj_human[i]->age  << std::endl;
		}
		std::cout << '\n';
}
		
	
};



class House {
	int number_house;
	int quntity_flat;
private:
	std::vector<Flat*>obj_flat;
public:
	House(int num_house) {
		number_house = num_house;
	};

	void add_flat(int number_, int room_number_) {
		Flat* new_flat = new Flat;
		new_flat->number = number_;
		new_flat->room_number = room_number_;

		obj_flat.push_back(new_flat);
		quntity_flat++;
	}
	
	void print_house_num() {
		std::cout << "Номер дома: " << number_house 
			<< " Количество квартир: " << quntity_flat << "\n\n";
	}
	void print_house() {
		
			for (int i=0; i < obj_flat.size(); i++) {
				std::cout << "Номер квартиры: " << obj_flat[i]->number <<
					" Количество комнат: " << obj_flat[i]->room_number << std::endl;
		}
	}
	~House() {};
	
		

};
int main() {
	setlocale(LC_ALL, "ru");
	
	House house1(33);
	
	Flat flat1;
	flat1.number = 1;
	flat1.room_number = 2;
	Flat flat2;
	flat2.number = 2;
	flat2.room_number = 3;
	house1.add_flat(1, 2);

	flat1.print_flat_parametrs();
	
	flat1.add_human("Ира", 23);
	flat1.add_human("Петя", 45);
	flat1.print_flat();

	house1.add_flat(2, 3);
	flat2.print_flat_parametrs();
	flat2.add_human("Вова", 12);
	flat2.add_human("Вика", 33);
	flat2.print_flat();

	house1.print_house_num();
	house1.print_house();
	
	
	

	return 0;
}