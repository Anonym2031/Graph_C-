#include <iostream>
#include <map>
using namespace std;
void InPut(int inPut[2][100], int& n);
void Print(int** x, int n);
int InItems(int inPut[2][100], int n);
int OutItems(int inPut[2][100], int n);
int IntermediateItems(int inPut[2][100], int n);
void Generic(int inPut[2][100], int n, int** matrix);
void Multiply(int** a, int** b, int n);
int LongStump(int** a, int** hasanelutyan, int n);
bool CheckOfNull(int** a, int n);
bool CheckOfCycle(int** a, int n);
double Km(int inPut[2][100], int n, int t2);
double Knk(int inPut[2][100], int n);
int main()
{
	int inPut[2][100]
		= {
			{ 1,1,1,1,2,2,2,2,3,3,3,4,4,4,5,5,6,6,6,7,7,8,9,10,11,12,14,15,16,17,18,19,20,20 },
			{ 3,4,5,6,5,6,7,8,13,14,15,12,13,16,11,12,10,11,20,9,10,9,19,18,16,18,17,0,0,0,0,0,16,0}
	};
	int n = 34;
	//InPut(inPut, n);
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (count < inPut[0][i])
			count = inPut[0][i];
		if (count < inPut[1][i])
			count = inPut[1][i];
	}
	int** matrix;
	matrix = new int*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = 0;
		}
	}
	int** hasanelutyan;
	hasanelutyan = new int*[n];
	for (int i = 0; i < n; ++i) {
		hasanelutyan[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			hasanelutyan[i][j] = 0;
		}
	}
	Generic(inPut, n, matrix);
	Print(matrix, count);
	int longStump = LongStump(matrix, hasanelutyan, count);
	cout << "Hasaneliutyan matrix" << endl;
	Print(hasanelutyan, count);
	cout << "erkar qanakap : " << longStump << endl;
	cout << "mutqi oxakner : " << InItems(inPut, n) << endl;
	int t2 = IntermediateItems(inPut, n);
	cout << "Mijankyal oxakner : " << t2 << endl;
	cout << "elqi oxakner : " << OutItems(inPut, n) << endl;
	cout << "Kn = " << Km(inPut, n, t2) << endl;
	cout << "Knk = " << Knk(inPut, n) << endl;
	delete[] matrix;
	matrix = NULL;
	system("pause");
	return 0;
}
double Km(int inPut[2][100], int n, int t4) {
	map<int, int> myMap;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			myMap[inPut[i][j]] = inPut[i][j];
		}
	}
	int m = 0;
	for (auto p = myMap.begin(); p != myMap.end(); ++p) {
		if (p->first != 0)
			++m;
	}
	cout << "t4 = " << t4 << " m = " << m << endl;
	return t4 * 1.0 / m;
}
double Knk(int inPut[2][100], int n) {
	map<int, int> myMap;
	for (int i = 0; i < n; ++i) {
		myMap[inPut[0][i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		myMap[inPut[1][i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (inPut[1][i] == 0)
			myMap[inPut[0][i]] = 0;
	}
	int t4 = 0;
	for (int i = 0; i < n; ++i) {
		if ((myMap[inPut[0][i]] > 1) && (myMap[inPut[1][i]] > 1)) {
			++t4;
		}
	}
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (inPut[1][i] != 0)
			++m;
	}
	cout << "t2 = " << t4 << " r = " << m << endl;
	return t4 * 1.0 / m;
}
void InPut(int inPut[2][100], int& n)
{
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ")i , j ";
		cin >> inPut[0][i] >> inPut[1][i];
	}
}
void Print(int** const x, int n)
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << x[i][j] << ' ';
		}
		cout << endl;
	}
}
//հաշվում է մուտքային օղակները
int InItems(int inPut[2][100], int n)
{
	int exit = 0;
	map<int, bool> map;
	for (int i = 0; i < n; ++i) {
		map[inPut[0][i]] = true;
		for (int j = 0; j < n; ++j) {
			if (inPut[0][i] == inPut[1][j]) {
				map[inPut[0][i]] = false;
				break;
			}
		}
	}
	for (auto p = map.begin(); p != map.end(); ++p) {
		if (p->second) {
			++exit;
		}
	}
	return exit;
}
//ելքային օղակների քանակ
int OutItems(int inPut[2][100], int n)
{
	int exit = 0;
	for (int i = 0; i < n; ++i) {
		if (inPut[1][i] == 0) {
			exit++;
		}
	}
	return exit;
}
int IntermediateItems(int inPut[2][100], int n)
{
	int exit = 0;
	map<int, int> map;
	for (int i = 0; i < n; ++i) {
		if (inPut[1][i] != 0)
			map[inPut[0][i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (map[inPut[1][i]] == 1) {
			map[inPut[1][i]] = 2;
		}
	}
	for (auto p = map.begin(); p != map.end(); ++p) {
		if (p->second == 2) {
			cout << p->first << ' ';
			++exit;
		}
	}
	return exit;
}
void Generic(int inPut[2][100], int n, int** matrix)
{
	for (int i = 0; i < n; ++i) {
		matrix[inPut[0][i]][inPut[1][i]] = 1;
	}
}
void Multiply(int** a, int** const b, const int n)
{
	int** exit = new int*[n];
	for (int i = 0; i < n; ++i) {
		exit[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			exit[i][j] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				exit[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = exit[i][j];
		}
	}
	delete[] exit;
	exit = NULL;
}
void Add(int** a, int** const b, const int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] += b[i][j];

}
int LongStump(int ** a, int** hasanelutyan, int n)
{
	int exit = 0;
	int** A;
	A = new int*[n];
	for (int i = 0; i < n; ++i) {
		A[i] = new int[n];
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			A[i][j] = a[i][j];
		}
	}
	while (!CheckOfNull(a, n)) {
		++exit;
		if (CheckOfCycle(a, n)) {
			cout << "Ciklik graf " << endl;
			return 0;
		}

		Multiply(a, A, n);
		Print(a, n);
		Add(hasanelutyan, a, n);
		cout << " " << endl;
	}
	delete[] A;
	A = NULL;
	return exit;
}
bool CheckOfNull(int ** a, int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}
bool CheckOfCycle(int ** a, int n)
{
	for (int i = 0; i < n; ++i) {
		if (a[i][i] != 0) {
			return true;
		}
	}
	return false;
}
