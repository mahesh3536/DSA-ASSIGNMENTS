#include <iostream>
using namespace std;

struct data {
	int Rengn_no ;
	string Name;
	string Branch;
	float CGPA ;
};


void show_one(struct data d) {
	cout << endl << "		Rengn_no : " << d.Rengn_no << "\n		Name : " << d.Name << "\n		Branch : " << d.Branch << "\n		CGPA : " << d.CGPA << endl;
}

void show(struct data list[]) {

	for (int i = 0; i < 10; ++i)
	{
		cout << "Data of student " << i + 1 << " : ";
		show_one(list[i]);
	}
}

void a(struct data list[]) {
	int no;
	cout << "Enter Rengn_no : ";
	cin >> no;

	for (int i = 0; i < 10; ++i)
	{
		if (list[i].Rengn_no == no) {
			show_one(list[i]);
			return;
		}
	}
	cout << "Not Found !!!\n";
}

void b(struct data list[]) {

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < (10 - i - 1); ++j)
		{
			if (list[j].Rengn_no > list[j + 1].Rengn_no) {
				struct data temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}

		}
	}
}

void c(struct data list[]) {
	int no;
	cout << "Enter Rengn_no : ";
	cin >> no;

	int s = 0 , l = 9 , m;

	while (s <= l) {
		m = (s + l) / 2;

		if (list[m].Rengn_no > no) l = m - 1;
		else if (list[m].Rengn_no < no) s = m + 1;

		else {show_one(list[m]); return;}

	}

	cout << "Not Found !!!\n";
}

void d(struct data list[]) {

	struct data temp;

	for (int i = 1; i < 10; ++i)
	{
		temp = list[i];

		int j = i;

		while (j > 0 && list[j - 1].CGPA < temp.CGPA ) {
			list[j] = list[j - 1];
			j--;
		}

		list[j] = temp;

	}

}

int main() {

	struct data list[10];
	int ch ;

	cout << "0. User input\n" << "1. defualt input\n" << "Enter your ans : ";
	cin >> ch;

	// user input
	if (ch == 0) {
		cout << "Order : Rangn_no Name Branch CGPA \n";

		for (int i = 0; i < 10; ++i)
		{
			cout << "Enter data of student " << i + 1 << " : ";
			cin >> list[i].Rengn_no >> list[i].Name >> list[i].Branch >> list[i].CGPA;
		}
	}
	// defualt
	else {
		int Rengn_no_list[] = {1, 6, 24, 574, 124, 82, 325, 32, 978, 234};
		float CGPA_list[] = {9.12 , 4.1, 3.5, 9, 1.9 , 1.23, 9.99 , 7.89 , 6.5 , 5 } ;
		string name_list[] = {"dumi1" , "dumi2" , "dumi3", "dumi4", "dumi5", "dumi6", "dumi7", "dumi8", "dumi9", "dumi10"};

		for (int i = 0; i < 10; ++i)
		{
			list[i].Rengn_no = Rengn_no_list[i];
			list[i].Name = name_list[i];
			list[i].Branch = "CSE";
			list[i].CGPA = CGPA_list[i];
		}
		show(list);
	}
	int ans;

	do
	{
		cout << "1. OP a\n" << "2. OP b\n" << "3. OP c\n" << "4. OP d\n" << "5. OP show list\n" << "0. Exit\n\n";
		cout << "Enter ans : ";
		cin >> ans;

		switch (ans) {
		case 1:
			a(list);
			break;

		case 2:
			b(list);
			break;

		case 3:
			c(list);
			break;

		case 4:
			d(list);
			break;

		case 5:
			show(list);
			break;
		}


	} while (ans != 0);






	return 0;
}