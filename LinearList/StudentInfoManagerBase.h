#include<student.h>
#include<vector>
#include<iostream>
using std::vector;
using namespace std;
class StudentIMbase
{
private:
	vector<Student> a;
public:
	Student QueryByName(string Name);
	Student QueryById(string ID);
	Student QueryBySchoolId(string SchoolID);
	void erase(Student student);
	void insert(Student student);
	void readFromFile(string fileName);
	void saveToFile(string fileName);
	StudentIMbase(){ }
};
StudentIMbase::QueryByName(string A)
{

}