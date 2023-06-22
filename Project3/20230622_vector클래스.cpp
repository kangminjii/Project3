#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

const int NUM = 5;

using namespace std;

int main()
{
	// #1 ���� Ŭ���� ���
	/*vector<int> ratings(NUM);
	vector<string> titles(NUM);

	cout << NUM << "���� å ����� å ���(0-10)�� �Է��Ͻʽÿ�: " << endl;

	for (int i = 0; i < NUM; i++)
	{
		cout << i + 1 << "�� å�� ������ �Է��Ͻʽÿ�: ";
		getline(cin, titles[i]);
		cout << i + 1 << "�� å�� ���(0-10)�� �Է��Ͻʽÿ�: ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�: \n" << "���\t����\n";

	for (int i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}*/

	// #3 STL �Լ� ���
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);

	if (books.size() > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� " << books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n" << "���\t����\n";

		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "å ������ �������� ����:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "å ����� �������� ����:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "������ ������ �ٽ� ��ġ:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "���α׷��� �����մϴ�.\n";


	// #2 ���� �Լ� ���
	//int num = books.size();
	//if (num > 0)
	//{
	//	cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�.\n" << "���\t����\n";
	//	for (int i = 0; i < num; i++)
	//		ShowReview(books[i]);

	//	cout << "\n�ѹ� �� ����Ѵ�:\n" << "���\t����\n";
	//	vector<Review>::iterator pr;
	//	for (pr = books.begin(); pr != books.end(); pr++)
	//		ShowReview(*pr);

	//	vector<Review> oldlist(books);

	//	if (num > 3)
	//	{
	//		// ���� 2�� ����
	//		books.erase(books.begin() + 1, books.begin() + 3);
	//		cout << "\n������ ��:\n";
	//		for (pr = books.begin(); pr != books.end(); pr++)
	//			ShowReview(*pr);

	//		// ���� 1�� ����
	//		books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
	//		cout << "\n������ ��:\n";
	//		for (pr = books.begin(); pr != books.end(); pr++)
	//			ShowReview(*pr);
	//	}

	//	books.swap(oldlist);
	//	cout << "\noldlist�� books�� ��ȯ�� ��:\n";
	//	for (pr = books.begin(); pr != books.end(); pr++)
	//		ShowReview(*pr);
	//}
	//else
	//	cout << "�Է��� ���� ����, ���� ���� �����ϴ�.\n";


	return 0;
}

bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else return false;
}

bool worseThan(const Review& r1, const Review& r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool FillReview(Review& rr)
{
	cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "å ���(0-10)�� �Է��Ͻʽÿ�: ";
	cin >> rr.rating;
	if (!cin)
		return false;

	// ���� �Է��� ����
	while (cin.get() != '\n')
		continue;
	
	return true;
}

void ShowReview(const Review& rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}