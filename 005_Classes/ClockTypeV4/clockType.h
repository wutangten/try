#include <string>
using namespace std;

class clockType
{
public:
	clockType();
	clockType(int);
	clockType(int, int);
	clockType(int, int, int);
	void incHr();
	void incMin();
	void incSec();
	string getTime() const;
private:
	int hr;
	int min;
	int sec;
};