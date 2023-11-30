#pragma once
//Автор - Перунов Вaдим

enum class Specialization{None, Sawmill, Quarry, Goldmine, Ironmine, Farm};//перечисляемый тип для множества типов производств. зданий

class Building
{
	protected:
		unsigned int HealthPoints; //очки здоровья здания
		unsigned short int level; //уровень здания
	public:
		///Конструктор базового класса Building без нач. параметров
		Building();
		///Конструктор базового класса Building с нач. параметрами
		Building(unsigned int HP);
		///геттер для поля HP
		int GetHP();
		///геттер для поля level
		int GetLevel();
		///абстрактный метод улучшения здания
		virtual void  Upgrade(unsigned int Up) = 0;
		///Метод выводящий в строку значения полей класса
		virtual std::string ToString() = 0;

};

class Defense : public Building {
	private:
		unsigned int Damage; // урон, наносимый оборон. зданием
	public:
		///Конструктор производного класса Defense без нач. параметров
		Defense();
		///Конструктор производного класса Defense с нач. параметрами
		Defense(unsigned int HP, unsigned int dmg);
		///метод атаки
		void Attack();
		/// сеттер для поля Damage
		void SetDamage(unsigned int dmg);
		///геттер для поля Damage
		unsigned int GetDamage();
		///определение метода улучшения здания для этого класса
		void Upgrade(unsigned int Up) override;
		//переопределение метода ToString базового класса
		std::string ToString() override;
};

class Storage : public Building {
	private:
		unsigned int Capacity; // обьем хранилища(в ед.)
	public:
		unsigned int Wood; //кол-во дерева, хранящегося в данный момент
		unsigned int Stone;//кол-во камня, хранящегося в данный момент
		unsigned int Iron;//кол-во железа, хранящегося в данный момент
		unsigned int Gold;//кол-во золота, хранящегося в данный момент
		unsigned int Food;//кол-во еды, хранящейся в данный момент

		///Конструктор производного класса Storage без нач. параметров
		Storage();
		///Конструктор производного класса Storage с нач. параметрами
		Storage(unsigned int HP,unsigned int Cap);
		///сеттер для поля Capacity
		void SetCapacity(unsigned int Cap);
		///геттер для поля Capacity
		unsigned int GetCapacity();
		///определение метода улучшения здания для этого класса
		void Upgrade(unsigned int Up) override;
		///нахождение общего кол-ва ресурсов, хранящегося в данный момент
		unsigned CurrentRes();
		//переопределение метода ToString базового класса
		std::string ToString() override;
};


//
class Manifacture : public Building {
	private:
		unsigned int Production; //производительность здания
		Specialization spec; // тип здания
	public:
		///Конструктор производного класса Manifacture без нач. параметров
		Manifacture();
		///Конструктор производного класса Manifacture с нач. параметрами
		Manifacture(unsigned int HP, unsigned int prod, Specialization sp);
		///производство ресурса
		void Produce(Storage &stor);
		///определение метода улучшения здания для этого класса
		void Upgrade(unsigned int Up = 5) override;
		///сеттер для поля Production
		void SetProduction(unsigned int prod);
		///геттер для поля Production
		unsigned int GetProduction();
		///геттер для поля spec
		Specialization GetSpec();
		//переопределение метода ToString базового класса
		std::string ToString() override;

};

