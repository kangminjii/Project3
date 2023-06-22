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
	// #1 벡터 클래스 사용
	/*vector<int> ratings(NUM);
	vector<string> titles(NUM);

	cout << NUM << "개의 책 제목과 책 등급(0-10)을 입력하십시오: " << endl;

	for (int i = 0; i < NUM; i++)
	{
		cout << i + 1 << "번 책의 제목을 입력하십시오: ";
		getline(cin, titles[i]);
		cout << i + 1 << "번 책의 등급(0-10)을 입력하십시오: ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "감사합니다. 당신은 다음과 같이 입력하셨습니다: \n" << "등급\t제목\n";

	for (int i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}*/

	// #3 STL 함수 사용
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);

	if (books.size() > 0)
	{
		cout << "감사합니다. 당신은 다음과 같이 " << books.size() << "개의 책 등급을 입력하셨습니다.\n" << "등급\t제목\n";

		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "책 제목을 기준으로 정렬:\n등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "책 등급을 기준으로 정렬:\n등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "무작위 순서로 다시 배치:\n등급\t제목\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "프로그램을 종료합니다.\n";


	// #2 벡터 함수 사용
	//int num = books.size();
	//if (num > 0)
	//{
	//	cout << "감사합니다. 당신은 다음과 같이 입력하셨습니다.\n" << "등급\t제목\n";
	//	for (int i = 0; i < num; i++)
	//		ShowReview(books[i]);

	//	cout << "\n한번 더 출력한다:\n" << "등급\t제목\n";
	//	vector<Review>::iterator pr;
	//	for (pr = books.begin(); pr != books.end(); pr++)
	//		ShowReview(*pr);

	//	vector<Review> oldlist(books);

	//	if (num > 3)
	//	{
	//		// 원소 2개 삭제
	//		books.erase(books.begin() + 1, books.begin() + 3);
	//		cout << "\n삭제한 후:\n";
	//		for (pr = books.begin(); pr != books.end(); pr++)
	//			ShowReview(*pr);

	//		// 원소 1개 삽입
	//		books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
	//		cout << "\n삽입한 후:\n";
	//		for (pr = books.begin(); pr != books.end(); pr++)
	//			ShowReview(*pr);
	//	}

	//	books.swap(oldlist);
	//	cout << "\noldlist와 books를 교환한 후:\n";
	//	for (pr = books.begin(); pr != books.end(); pr++)
	//		ShowReview(*pr);
	//}
	//else
	//	cout << "입력한 것이 없어, 얻은 것이 없습니다.\n";


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
	cout << "책 제목을 입력하십시오(끝내려면 quit를 입력): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "책 등급(0-10)을 입력하십시오: ";
	cin >> rr.rating;
	if (!cin)
		return false;

	// 남은 입력줄 제거
	while (cin.get() != '\n')
		continue;
	
	return true;
}

void ShowReview(const Review& rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}