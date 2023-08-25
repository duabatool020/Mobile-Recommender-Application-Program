#include<iostream>
#include<iomanip>
using namespace std;

class Phone
{
private:
	string name;
	float size;
	int weight;
	int RAM, ROM;
	int FrontCamra;
	int RearCamera;
	int count;
public:
	Phone()
	{
		name = "";
		size = 0.0;
		weight = RAM = ROM = FrontCamra = RearCamera = 0;
	}
	Phone(string n, float s, int w, int ram, int rom, int Fc, int Rc)
	{
		name = n;
		size = s;
		weight = w;
		RAM = ram;
		ROM = rom;
		FrontCamra = Fc;
		RearCamera = Rc;
	}
	void set(string n, float s, int w, int ram, int rom, int Fc, int Rc)
	{
		name = n;
		size = s;
		weight = w;
		RAM = ram;
		ROM = rom;
		FrontCamra = Fc;
		RearCamera = Rc;
	}
	void showName()
	{
		cout << "Name: " << name << endl;
	}
	void showSzie()
	{
		cout << "size: " << size << " inches";
	}
	void showWeight()
	{
		cout << "weight: " << weight << " g";
	}
	void showRAM()
	{
		cout << "RAM: " << RAM << "GB";
	}
	void showROM()
	{
		cout << "ROM: " << ROM << "GB";
	}
	void showFc()
	{
		cout << "Front Camera: " << FrontCamra << "MP";
	}
	void showRc()
	{
		cout << "Rear Camera: " << RearCamera << "MP";
	}
	int counter()
	{
		count++;
		return count;
	}
	bool operator>(Phone p2)
	{
		cout << name << setw(63) << p2.name << endl << endl;
		showSzie();cout << setw(55);p2.showSzie(); cout << endl;
		showWeight();cout << setw(61);p2.showWeight();cout << endl;
		showRAM();cout << setw(63);p2.showRAM();cout << endl;
		if (RAM > p2.RAM)
		{
			counter();
		}
		else if (RAM < p2.RAM)
		{
			p2.counter();
		}
		showROM(); cout << setw(62);p2.showROM();cout << endl;
		if (ROM > p2.ROM)
		{
			counter();
		}
		else if (RAM < p2.RAM)
		{
			p2.counter();
		}
		showFc(); cout << setw(62);p2.showFc();cout << endl;
		if (FrontCamra > p2.FrontCamra)
		{
			counter();
		}
		else if (RAM < p2.RAM)
		{
			p2.counter();
		}

		showRc(); cout << setw(62);p2.showRc();cout << endl;
		if (RearCamera > p2.RearCamera)
		{
			counter();
		}
		else if(RAM < p2.RAM)
		{
			p2.counter();
		}
		if (counter()>p2.counter())
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void Recomendation1(Phone p1)
	{
		cout << "***************Based on the comparision user should buy " <<name  <<"***************"<< endl;
	}
	
};
class Inventory
{
private:
	int N;
	Phone* inventory;
public:
	Inventory()
	{
		N = 2;
		inventory=new Phone[2];
	}

	Inventory(Phone* inven, int size)
	{
		N = size;
		inventory = new Phone[size];
		/*for (int i = 0;i < N;i++)
		{
			inventory[i];
			inventory[i].showName();
			
		}*/
	}
	~Inventory()
	{
		delete[]inventory;
	}
	void setValue(Phone *inven, int size)
	{
		N = size;
		inventory = inven;
		for (int i = 0;i < N;i++)
		{
			inventory[i];
		}
	}
	void ShowMenu()
	{
		cout << "****************************WELCOME TO INFINIX PHONE WORLD****************************" << endl << endl;
			cout << "We have 7 latest Phones for you:" << endl;
			cout << "Infinix note 8" << endl;
			cout << "Infinix zero 8i" << endl;
			cout << "Infinix note 6 pro" << endl;
			cout << "Infinix Hot S3" << endl;
			cout << "Infinix hot 9 pro" << endl;
			cout << "Infinix hot 8 pro" << endl;
			cout << "Infinix hot 7 pro" << endl << endl;
			cout << "Enter the number of phones of in which you are interested: ";
	}
	void SelectPhones()
	{
		cout << "Please Select the Phones in which you are interested: " << endl << endl;
		cout << "Press 0 for Infinix note 8" << endl;
		cout << "Press 1 for Infinix zero 8i" << endl;
		cout << "Press 2 for Infinix note 6 pro " << endl;
		cout << "Press 3 for Infinix Hot S3" << endl;
		cout << "Press 4 for Infinix hot 9 pro" << endl;
		cout << "Press 5 for Infinix hot 8 pro" << endl;
		cout << "Press 6 for Infinix hot 7 pro" << endl;
	}
	
	friend void compare( Inventory in);

};
void compare(Inventory in)
{
	
	cout << endl << endl;
	Phone BestPhone = in.inventory[0];
	for (int i = 1;i<in.N;i++)
	{
		if (in.inventory[i] > BestPhone)
		{
			BestPhone = in.inventory[i];
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	BestPhone.Recomendation1(BestPhone);
}

void main()
{
	Phone p1, p2, p3, p4, p5, p6, p7;
	p1.set("Infinix note 8", 6.95, 214, 8, 128, 18, 64);
	p2.set("Infinix zero 8i", 6.85, 210, 6, 64, 16, 48);
	p3.set("Infinix note 6 pro", 6.01, 173, 4, 32, 13, 20);
	p4.set("Infinix Hot S3", 5.65, 150, 3, 32, 8, 12);
	p5.set("Infinix hot 9 pro", 6.6, 185, 4, 64, 8, 48);
	p6.set("Infinix hot 8 pro", 6.5, 179, 4, 64, 8, 13);
	p7.set("Infinix hot 7 pro", 6.2, 165, 2, 32, 6, 12);
	Inventory i;
	i.ShowMenu();
	int N;
	cin >> N;
	Phone p[7] = { p1,p2,p3,p4,p5,p6,p7 };
	Phone* inv;
	inv = new Phone[7];
	i.SelectPhones();
	int num;
	for (int j = 0;j < N;j++)
	{
		cin >> num;
		inv[j] = p[num];
	}
	i.setValue(inv, N);
	compare(i);
	system("pause");
}
