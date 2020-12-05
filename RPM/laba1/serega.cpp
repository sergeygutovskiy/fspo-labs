#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// base class
class Pokemon
{
protected:
	string name;
	int hp;
	int attack;
	int defence;
	int speed;
public:
	Pokemon(string name, int hp, int attack, int defence, int speed)
	{
		this->name    = name;
		this->hp      = hp;
		this->attack  = attack;
		this->defence = defence;
		this->speed   = speed;
	}

	// name
	string get_name()
	{
		return this->name;
	}

	void set_name(string new_name)
	{
		this->name = new_name;
	}

	// hp
	int get_hp()
	{
		return this->hp;
	}

	void set_hp(int new_hp)
	{
		this->hp = new_hp;
	}

	// attack
	int get_attack()
	{
		return this->attack;
	}

	void set_attack(int new_attack)
	{
		this->attack = new_attack;
	}

	// defence
	int get_defence()
	{
		return this->defence;
	}

	void set_defence(int new_defence)
	{
		this->defence = new_defence;
	}

	// speed
	int get_speed()
	{
		return this->speed;
	}

	void set_speed(int new_speed)
	{
		this->speed = new_speed;
	}

	virtual void print_special_to_file(ofstream & f) = 0;
};


// first child
class Pikachu : public Pokemon
{
private:
	int special_attack;
	int special_defence;

public:
	Pikachu(string name, int hp, int attack, int defence, int speed) : Pokemon(name, hp, attack, defence, speed) 
	{
		this->special_attack = 1000;
		this->special_defence = 1000;
	}

	// special attack
	int get_special_attack()
	{
		return this->special_attack;
	}

	void set_special_attack(int sa)
	{
		this->special_attack = sa;
	}

	// special defence
	int get_special_defence()
	{
		return this->special_defence;
	}

	void set_special_defence(int sd)
	{
		this->special_defence = sd;
	}

	void print_special_to_file(ofstream & f)
	{
		f << "\t\t" << "<special_attack>"  << this->special_attack  << "</special_attack>"  << endl;
		f << "\t\t" << "<special_defence>" << this->special_defence << "</special_defence>" << endl;
	}
};


// second child
class Bulbasaur : public Pokemon
{
private:
	int special_attack;
	int special_defence;

public:
	Bulbasaur(string name, int hp, int attack, int defence, int speed) : Pokemon(name, hp, attack, defence, speed) 
	{
		this->special_attack = 2;
		this->special_defence = 8;
	}

	// special attack
	int get_special_attack()
	{
		return this->special_attack;
	}

	void set_special_attack(int sa)
	{
		this->special_attack = sa;
	}

	// special defence
	int get_special_defence()
	{
		return this->special_defence;
	}

	void set_special_defence(int sd)
	{
		this->special_defence = sd;
	}

	void print_special_to_file(ofstream & f)
	{
		f << "\t\t" << "<special_attack>"  << this->special_attack  << "</special_attack>"  << endl;
		f << "\t\t" << "<special_defence>" << this->special_defence << "</special_defence>" << endl;
	}
};


// third child
class Aslan : public Pokemon
{
private:
	int special_attack;
	int special_defence;

public:
	Aslan(string name, int hp, int attack, int defence, int speed) : Pokemon(name, hp, attack, defence, speed) 
	{
		this->special_attack = 0;
		this->special_defence = -2;
	}

	// special attack
	int get_special_attack()
	{
		return this->special_attack;
	}

	void set_special_attack(int sa)
	{
		this->special_attack = sa;
	}

	// special defence
	int get_special_defence()
	{
		return this->special_defence;
	}

	void set_special_defence(int sd)
	{
		this->special_defence = sd;
	}

	void print_special_to_file(ofstream & f)
	{
		f << "\t\t" << "<special_attack>"  << this->special_attack  << "</special_attack>"  << endl;
		f << "\t\t" << "<special_defence>" << this->special_defence << "</special_defence>" << endl;
	}
};

void print_pokemon_to_file(ofstream & f, Pokemon * p)
{
	f << "\t"   << "<pokemon name=\"" << p->get_name() << "\">" << endl;
	
	f << "\t\t" << "<hp>" << p->get_hp() << "</hp>" << endl;
	f << "\t\t" << "<attack>" << p->get_attack() << "</attack>" << endl;
	f << "\t\t" << "<defence>" << p->get_defence() << "</defence>" << endl;
	f << "\t\t" << "<speed>" << p->get_speed() << "</speed>" << endl;
	
	p->print_special_to_file(f);

	f << "\t"   << "</pokemon>" << endl;
}

int main()
{
	Pikachu   * p = new Pikachu("Pikachu", 10, 20, 30, 40);
	Bulbasaur * b = new Bulbasaur("Bulbasaur", 6, 23, 32, 12);
	Aslan     * a = new Aslan("Aslan", 1000, 200, 120, 100);

	ofstream myfile;
	myfile.open("save.txt");
	myfile << "<pokemons>\n";

	print_pokemon_to_file(myfile, p);
	print_pokemon_to_file(myfile, b);
	print_pokemon_to_file(myfile, a);

	myfile << "</pokemons>";
	myfile.close();

	return 0;
}
