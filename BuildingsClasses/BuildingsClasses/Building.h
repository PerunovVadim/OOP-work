#pragma once
//����� - ������� �a���

enum class Specialization{None, Sawmill, Quarry, Goldmine, Ironmine, Farm};//������������� ��� ��� ��������� ����� �����������. ������

class Building
{
	protected:
		unsigned int HealthPoints; //���� �������� ������
		unsigned short int level; //������� ������
	public:
		///����������� �������� ������ Building ��� ���. ����������
		Building();
		///����������� �������� ������ Building � ���. �����������
		Building(unsigned int HP);
		///������ ��� ���� HP
		int GetHP() const;
		///������ ��� ���� level
		int GetLevel() const;
		///����������� ����� ��������� ������
		virtual void  Upgrade(unsigned int Up) = 0;
		///����� ��������� � ������ �������� ����� ������
		virtual std::string ToString() = 0;

};

class Defense : public Building {
	private:
		unsigned int Damage; // ����, ��������� ������. �������
	public:
		///����������� ������������ ������ Defense ��� ���. ����������
		Defense();
		///����������� ������������ ������ Defense � ���. �����������
		Defense(unsigned int HP, unsigned int dmg);
		///����� �����
		void Attack() const;
		/// ������ ��� ���� Damage
		void SetDamage(unsigned int dmg);
		///������ ��� ���� Damage
		unsigned int GetDamage() const;
		///����������� ������ ��������� ������ ��� ����� ������
		void Upgrade(unsigned int Up) override;
		//��������������� ������ ToString �������� ������
		std::string ToString() override;
};

class Storage : public Building {
	private:
		unsigned int Capacity; // ����� ���������(� ��.)
	public:
		unsigned int Wood; //���-�� ������, ����������� � ������ ������
		unsigned int Stone;//���-�� �����, ����������� � ������ ������
		unsigned int Iron;//���-�� ������, ����������� � ������ ������
		unsigned int Gold;//���-�� ������, ����������� � ������ ������
		unsigned int Food;//���-�� ���, ���������� � ������ ������

		///����������� ������������ ������ Storage ��� ���. ����������
		Storage();
		///����������� ������������ ������ Storage � ���. �����������
		Storage(unsigned int HP,unsigned int Cap);
		///������ ��� ���� Capacity
		void SetCapacity(unsigned int Cap);
		///������ ��� ���� Capacity
		unsigned int GetCapacity() const;
		///����������� ������ ��������� ������ ��� ����� ������
		void Upgrade(unsigned int Up) override;
		///���������� ������ ���-�� ��������, ����������� � ������ ������
		unsigned CurrentRes() const;
		//��������������� ������ ToString �������� ������
		std::string ToString() override;
};


//
class Manifacture : public Building {
	private:
		unsigned int Production; //������������������ ������
		Specialization spec; // ��� ������
	public:
		///����������� ������������ ������ Manifacture ��� ���. ����������
		Manifacture();
		///����������� ������������ ������ Manifacture � ���. �����������
		Manifacture(unsigned int HP, unsigned int prod, Specialization sp);
		///������������ �������
		void Produce(Storage &stor) const;
		///����������� ������ ��������� ������ ��� ����� ������
		void Upgrade(unsigned int Up = 5) override;
		///������ ��� ���� Production
		void SetProduction(unsigned int prod);
		///������ ��� ���� Production
		unsigned int GetProduction() const;
		///������ ��� ���� spec
		Specialization GetSpec() const;
		//��������������� ������ ToString �������� ������
		std::string ToString() override;

};

void testing();