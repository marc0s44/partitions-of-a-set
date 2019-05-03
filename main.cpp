#include <iostream>
#include <fstream>
using namespace std;
void printarr(int tab[], int n);
void part_gen(int tab[], int n);
bool check(int tab[], int n);
fstream file;
int main() {
	cout << "Program that counts possible partitions of a set" << endl;
	int n;
	cout << "\nPlease give n: ";
	cin >> n;
	int *tab = new int[n];
	for (int i = 0; i < n; i++) {
		tab[i] = 1;
	}
	file.open("MP_L2.txt", fstream::out);
	printarr(tab, n);
	int counter = 1;
	while (tab[n - 1] != n) {
		part_gen(tab, n);
		printarr(tab, n);
		counter++;
	}
	cout << endl <<"There are "<< counter<<" possible partitions of a set"<<endl;
	file<< endl << "There are " << counter << " possible partitions of a set" << endl;
	delete[]tab;
	file.close();
	system("pause");
	return 0;
}
void part_gen(int tab[], int n)
{
	if (check(tab, n)) {
		tab[n - 1]++;
	}
	else
	{
		part_gen(tab, n - 1);
		for (int i = n - 1; i < n; i++)
			tab[i] = 1;

	}

}
void printarr(int tab[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << tab[i] << " ";
		file << tab[i] << " ";
	}
	file << "\n";
	cout << endl;
}
bool check(int tab[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		if (tab[i] == tab[n - 1])
			return true;

	}
	return false;
}
