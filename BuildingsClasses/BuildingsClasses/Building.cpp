//����� - ������� �����
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include "Building.h"


using namespace std;
///����������� �������� ������ Building ��� ���. ����������
Building::Building() {
	HealthPoints = 0;
	level = 1;
}
///����������� �������� ������ Building � ���. �����������
Building::Building(unsigned HP) {
	HealthPoints = HP;
	level = 1;
}
///������ ��� ���� HP
int Building::GetHP() const {
	return HealthPoints;
}
///������ ��� ���� level
int Building::GetLevel() const {
	return level;
}

///����������� ������������ ������ Defense ��� ���. ����������
Defense::Defense(): Building() {
	Damage = 0;
}
////����������� ������������ ������ Defense c ���. �����������
Defense::Defense(unsigned int HP, unsigned int dmg) : Building(HP) {
	Damage = dmg;
}
///����� �����
void Defense::Attack() const {
	std::cout << "����� ������� " << Damage << " ����� \n";
}

///������ ��� ���� Damage
void Defense::SetDamage(unsigned int dmg){
	Damage = dmg;
}
///������ ��� ���� Damage
unsigned int Defense::GetDamage() const {
	return Damage;
}
///����������� ������ ��������� ������ ��� ����� ������
void Defense::Upgrade(unsigned int Up) {
	Damage += Up;
	level++;
}

std::string Defense::ToString() {
	std::stringstream ss;
	ss << "HP - " << HealthPoints << " ������� - " << level << " ���� - " << Damage;
	return ss.str();
}
///����������� ������������ ������ Storage ��� ���. ����������
Storage::Storage(): Building() {
	Capacity = 0;
	Wood = 0;
	Stone = 0;
	Food = 0;
	Gold = 0;
	Iron = 0;
}
///����������� ������������ ������ Storage � ���. �����������
Storage::Storage(unsigned int HP, unsigned int Cap): Building(HP){
	Capacity = Cap;
	Wood = 0;
	Stone = 0;
	Food = 0;
	Gold = 0;
	Iron = 0;
}
///������ ��� ���� Capacity
void Storage::SetCapacity(unsigned int Cap) {
	Capacity = Cap;
}
///������ ��� ���� Capacity
unsigned int Storage::GetCapacity() const {
	return Capacity;
}
///����������� ������ ��������� ������ ��� ����� ������
void Storage::Upgrade(unsigned int Up) {
	Capacity += Up;
	level++;
}
///���������� ������ ���-�� ��������, ����������� � ������ ������
unsigned Storage::CurrentRes() const {
	return Wood + Food + Gold + Stone + Iron;
}
std::string Storage::ToString() {
	std::stringstream ss;
	ss << "HP - " << HealthPoints << " ������� - " << level << "\t ����������� - " << Capacity << "\t ������ - " << Wood << "\t ������ - " << Stone << "\t ������ - " << Iron << "\t ������ - " << Gold << "\t ��� - " << Food;
	return ss.str();
}

///����������� ������������ ������ Manifacture ��� ���. ����������
Manifacture::Manifacture() : Building() {
	Production = 0;
	spec = Specialization::None;
}
///����������� ������������ ������ Manifacture � ���. �����������
Manifacture::Manifacture(unsigned int HP,unsigned int prod,Specialization sp) : Building(HP) {
	Production = prod;
	spec = sp;
}
///������������ �������
void Manifacture::Produce(Storage& stor) const {
	if ((stor.CurrentRes() + Production) <= stor.GetCapacity()) { //���� ������������ ��������� ��������� � ���������
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
	else if ((stor.CurrentRes()) == stor.GetCapacity()) {} //����  ��������� ���������, �� ������ �� ������������
	else{ // ���� ��������� �� ��������� ������� �������������, �� ����������� ���������� ������������
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

///����������� ������ ��������� ������ ��� ����� ������
void Manifacture::Upgrade(unsigned int Up) {
	Production += Up;
	level++;
}
///������ ��� ���� Production
void Manifacture::SetProduction(unsigned int prod) {
	Production = prod;
}
///������ ��� ���� Production
unsigned int Manifacture::GetProduction() const {
	return Production;
}
///������ ��� ���� spec
Specialization Manifacture::GetSpec() const {
	return spec;
}

std::string Manifacture::ToString() {
	std::stringstream ss;
	ss << "HP - " << HealthPoints << " ������� - " << level << " ������������������ - " << Production;
	switch (spec)
	{
	case Specialization::Sawmill:
		ss << " ��� ������ - ���������";
		break;
	case Specialization::Quarry:
		ss << " ��� ������ - �����������";
		break;
	case Specialization::Goldmine:
		ss << " ��� ������ - ������������ �����";
		break;
	case Specialization::Ironmine:
		ss << " ��� ������ - ������������� �����";
		break;
	case Specialization::Farm:
		ss << " ��� ������ - �����";
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