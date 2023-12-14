//Автор - Перунов ВАдим
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include "Building.h"


using namespace std;
///Конструктор базового класса Building без нач. параметров
Building::Building() {
	HealthPoints = 0;
	level = 1;
}
///Конструктор базового класса Building с нач. параметрами
Building::Building(unsigned HP) {
	HealthPoints = HP;
	level = 1;
}
///геттер для поля HP
int Building::GetHP() const {
	return HealthPoints;
}
///геттер для поля level
int Building::GetLevel() const {
	return level;
}

///Конструктор производного класса Defense без нач. параметров
Defense::Defense(): Building() {
	Damage = 0;
}
////Конструктор производного класса Defense c нач. параметрами
Defense::Defense(unsigned int HP, unsigned int dmg) : Building(HP) {
	Damage = dmg;
}
///метод атаки
void Defense::Attack() const {
	std::cout << "Башня нанесла " << Damage << " урона \n";
}

///сеттер для поля Damage
void Defense::SetDamage(unsigned int dmg){
	Damage = dmg;
}
///геттер для поля Damage
unsigned int Defense::GetDamage() const {
	return Damage;
}
///определение метода улучшения здания для этого класса
void Defense::Upgrade(unsigned int Up) {
	Damage += Up;
	level++;
}

std::string Defense::ToString() {
	std::stringstream ss;
	ss << "HP - " << HealthPoints << " уровень - " << level << " Урон - " << Damage;
	return ss.str();
}
///Конструктор производного класса Storage без нач. параметров
Storage::Storage(): Building() {
	Capacity = 0;
	Wood = 0;
	Stone = 0;
	Food = 0;
	Gold = 0;
	Iron = 0;
}
///Конструктор производного класса Storage с нач. параметрами
Storage::Storage(unsigned int HP, unsigned int Cap): Building(HP){
	Capacity = Cap;
	Wood = 0;
	Stone = 0;
	Food = 0;
	Gold = 0;
	Iron = 0;
}
///сеттер для поля Capacity
void Storage::SetCapacity(unsigned int Cap) {
	Capacity = Cap;
}
///геттер для поля Capacity
unsigned int Storage::GetCapacity() const {
	return Capacity;
}
///определение метода улучшения здания для этого класса
void Storage::Upgrade(unsigned int Up) {
	Capacity += Up;
	level++;
}
///нахождение общего кол-ва ресурсов, хранящегося в данный момент
unsigned Storage::CurrentRes() const {
	return Wood + Food + Gold + Stone + Iron;
}
std::string Storage::ToString() {
	std::stringstream ss;
	ss << "HP - " << HealthPoints << " уровень - " << level << "\t Вместимость - " << Capacity << "\t Дерево - " << Wood << "\t Камень - " << Stone << "\t Железо - " << Iron << "\t Золото - " << Gold << "\t Еда - " << Food;
	return ss.str();
}

///Конструктор производного класса Manifacture без нач. параметров
Manifacture::Manifacture() : Building() {
	Production = 0;
	spec = Specialization::None;
}
///Конструктор производного класса Manifacture с нач. параметрами
Manifacture::Manifacture(unsigned int HP,unsigned int prod,Specialization sp) : Building(HP) {
	Production = prod;
	spec = sp;
}
///производство ресурса
void Manifacture::Produce(Storage& stor) const {
	if ((stor.CurrentRes() + Production) <= stor.GetCapacity()) { //если прозведенное полностью вмещается в хранилище
		switch (spec)
		{
		case Specialization::Sawmill:
			stor.Wood += Production;
			break;
		case Specialization::Quarry:
			stor.Stone += Production;
			break;
		case Specialization::Goldmine:
			stor.Gold += Production;
			break;
		case Specialization::Ironmine:
			stor.Iron += Production;
			break;
		case Specialization::Farm:
			stor.Food += Production;
			break;
		}
	}
	else if ((stor.CurrentRes()) == stor.GetCapacity()) {} //если  хранилище заполнено, то ничего не производится
	else{ // если хранилище не полностью вмещает произведенное, то заполняется оставшееся пространство
		switch (spec)
		{
		case Specialization::Sawmill:
			stor.Wood += stor.GetCapacity() - stor.CurrentRes();
			break;
		case Specialization::Quarry:
			stor.Stone += stor.GetCapacity() - stor.CurrentRes();
			break;
		case Specialization::Goldmine:
			stor.Gold += stor.GetCapacity() - stor.CurrentRes();
			break;
		case Specialization::Ironmine:
			stor.Iron += stor.GetCapacity() - stor.CurrentRes();
			break;
		case Specialization::Farm:
			stor.Food += stor.GetCapacity() - stor.CurrentRes();
			break;
		}
	}
}

///определение метода улучшения здания для этого класса
void Manifacture::Upgrade(unsigned int Up) {
	Production += Up;
	level++;
}
///сеттер для поля Production
void Manifacture::SetProduction(unsigned int prod) {
	Production = prod;
}
///геттер для поля Production
unsigned int Manifacture::GetProduction() const {
	return Production;
}
///геттер для поля spec
Specialization Manifacture::GetSpec() const {
	return spec;
}

std::string Manifacture::ToString() {
	std::stringstream ss;
	ss << "HP - " << HealthPoints << " уровень - " << level << " Производительность - " << Production;
	switch (spec)
	{
	case Specialization::Sawmill:
		ss << " Тип здания - Лесопилка";
		break;
	case Specialization::Quarry:
		ss << " Тип здания - Каменоломня";
		break;
	case Specialization::Goldmine:
		ss << " Тип здания - Золоторудная шахта";
		break;
	case Specialization::Ironmine:
		ss << " Тип здания - Железноркдная шахта";
		break;
	case Specialization::Farm:
		ss << " Тип здания - Ферма";
		break;
	}
	return ss.str();
}

void testing() {
	Manifacture a(500,3,Specialization::Sawmill),b(500,5,Specialization::Farm);
	Storage st(500, 1000);
	Defense def(300, 6);
	a.Produce(st);
	b.Produce(st);
	assert(st.Wood == 3);
	assert(st.Food == 5);
	assert(st.CurrentRes() == 8);
	def.Upgrade(3);
	assert(def.GetDamage() == 9);
}