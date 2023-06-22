#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s)
	{
		std::cout << "��ü�� �����Ǿ����ϴ�!\n";
	}
	~Report()
	{
		std::cout << "��ü�� �����Ǿ����ϴ�!\n";
	}
	void comment() const 
	{
		std::cout << str << "\n";
	}
};
int main()
{
	{
		std::auto_ptr<Report> ps(new Report("auto+ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("unique_ptr"));
		ps->comment();
	}


	using namespace std;

	// string Ŭ������ ���ǵ� ������ ����
	string one("Lottery Winner!");
	cout << one << endl;
	
	string two(20, '$');
	cout << two << endl;

	string three(one);
	cout << three << endl;
	
	one += " Oops!";
	cout << one << endl;
	
	two = "Sorry! That was ";
	three[0] = 'P';
	string four = two + three;
	cout << four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout << five << "!" << endl;

	string six(alls + 6, alls + 10);
	cout << six << ", ";

	string seven(&five[6], &five[10]);
	cout << seven << "..." << endl;

	string eight(four, 7, 17);
	cout << eight << "in motion!" << endl;


	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "ũ��:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "�뷮:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;

	empty.reserve(50);
	cout << "empty.reserve(50) ���� �뷮: " << empty.capacity() << endl;

	return 0;
}