/***
* (a). There are two Diamond Problems at "TeachingAssistant::setName" & "TeachingAssistant::getName"
* (b). As follows.
* (c). The outputs("<name>" meaning the input of 'name'):
```
 Learn method
 Work method
<name>
```
*/
#include <iostream>
#include <string>
using namespace std;
class Member {
protected:
	string name;
public:
	void setName(string n) { name = n; };
	string getName() { return name; };
};
class Student : virtual public Member
{
public:
	void learn() { cout << " Learn method " << endl; }
};
class Worker : virtual public Member
{
public:
	void work() { cout << " Work method " << endl; }
};
class TeachingAssistant : public Student, public Worker
{ };
int main()
{
	string name;
	getline(cin, name);
	TeachingAssistant ta;
	ta.setName(name);
	ta.learn();
	ta.work();
	cout << ta.getName() << endl;
	return 0;
}