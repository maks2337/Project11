#include <iostream>

using namespace std;

int main() {
	int n;
	
	cout << "Введите кол-во элементов: ";
	cin >> n;
	float *arr = new float[n];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " элемент ";
		cin >> arr[i];
	}
	//вычисление минимального элемента
	float min = arr[0];
	for (int i = 1; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	cout << "Минимальный элемент массива: " << min << endl;
	//Сумму элементов расположенных до последнего положительного элемента
	float sum = 0;
	int stat = n;
	bool flag = false; ;
	while (!flag) {
		flag = true;
		if (arr[stat] > 0) {
			for (int i = 0; i < stat; i++) {
				sum += arr[i];
			}
			break;
		}
		else {
			stat -= 1;
			flag = false;
		}
	}
	cout << "Сумму элементов расположенных до последнего положительного элемента равна: " << sum << endl;
	//Сжать массив, удалив из него все элементы, модуль которых находится в интервале [а, Ь]. Освободившиеся в конце массива элементы заполнить нулям.
	int j = 0;
	float a, b;
	cout << "Введите интервал (a, b) через пробел = ";
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		if (arr[i] < a || arr[i] > b)
			arr[i - j] = arr[i];
		else
			j++;
	}
	for (int i = n - j; i < n; i++)
		arr[i] = 0;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	free(arr);
	return 0;
}