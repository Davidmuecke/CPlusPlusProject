#include "testclass.h"

/*Testing only*/

using namespace std;
int main(void) {
	//Duration
	Duration d = Duration();
	Duration d1 = Duration(2,61,61);
	Duration d2 = Duration(d1);
	Duration d3 = d1;
	cout << "Duration \n" << d1 << " : " << d << endl;
	cout << "Duration (Copy) \n" << d2 << " : " << d3 << "ADD(D3:D1)"<<&d3 <<":"<<&d1 << endl;
	//Process
	Process p = Process();
	Process p1 = Process(12, "MyProcess");
	p1.TimeSpan(d1);
	//Process p2 = Process(p1);
	Process p2 = p1;
	//p2.TimeSpan(d);
	cout << "Process \n" << p1<< p2<< endl;

	return 0;
}
