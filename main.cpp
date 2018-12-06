#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <string>

const int MAXSUBJECT = 3;
const int MAXSTUDENT = 100;

using namespace std;
class Student
{
    int studentId;
    int mark;

  public:
    char getAverage();
    int getStudentMark();
    void setStudent(int index, int mark);
    int getStudentId();
    

    // void displayStudent();
};

int Student::getStudentId()
{
    return this->studentId;
}
void Student::setStudent(int index, int mark)
{
    
    this->studentId = index;
    this->mark = mark;
}

class Subject
{
    string subjectID;
    int noOfStudents;
    Student arrayOfStudent[MAXSTUDENT];

  public:
    Subject()
    {
        subjectID = "";
        noOfStudents = 0;
    }
    void displaySubject();
    friend int getStudentMark();
    void setSubject(string subjectID, int noOfStudents);
    friend char getAverage();
    void setData(int index, int studentId, int mark);
    void displayStudent(int id);
    int getNoOfStudent();
    string getSubjectId();
    int getSummary();
    float getAvgGrade(char grade);
};
float Subject::getAvgGrade(char grade){
    int count=0;
    
    for(int i=0;i<this->getNoOfStudent();i++){
        if(this->arrayOfStudent[i].getAverage()==grade){
            // cout << this->arrayOfStudent[i].getStudentId()<<"\t"<<this->arrayOfStudent[i].getAverage()<<endl;
            count++;    
        }
    }

    return (count / (float)this->getNoOfStudent()) * 100;
}
int Subject::getSummary()
{
    int total = 0;
    for (int i = 0; i < this->noOfStudents; i++)
    {
        total += this->arrayOfStudent[i].getStudentMark();
    }
    return total / this->noOfStudents;
}
string Subject::getSubjectId()
{
    return this->subjectID;
}
void Subject::displayStudent(int id)
{
    // int flag=0;
    for (int i = 0; i < this->getNoOfStudent(); i++)
    {

        if (this->arrayOfStudent[i].getStudentId() == id)
        {
            // flag=1;
            cout << this->subjectID << "\t\t\t" << this->arrayOfStudent[i].getStudentMark() << endl;
            break;
        }
    }
    //   if(flag==0) cout<<"Wrong Subject ID"<<endl;
}
int Subject::getNoOfStudent()
{
    return this->noOfStudents;
}
void Subject::setData(int index, int studentId, int mark)
{
    // for(int i=0;i<this->getNoOfStudent();i++){
    //     this->arrayOfStudent[i].setStudent(17+i,69-i);
    // }
    this->arrayOfStudent[index].setStudent(studentId, mark);
}
void Subject::setSubject(string subjectID, int noOfStudents)
{
    this->subjectID = subjectID;
    this->noOfStudents = noOfStudents;
}

void Subject::displaySubject()
{
    cout << "Id\t\tStudent ID\t\tMark\t\tGrade" << endl;
    for (int i = 0; i < this->noOfStudents; i++)
    {
        cout << i + 1 << "\t\t" << this->arrayOfStudent[i].getStudentId() << "\t\t" << this->arrayOfStudent[i].getStudentMark() << "\t\t" << this->arrayOfStudent[i].getAverage() << endl;
    }
}

char Student::getAverage()
{

    if (this->mark > 70)
        return 'A';
    else if (this->mark > 55)
        return 'B';
    else if (this->mark > 40)
        return 'C';
    else if (this->mark > 30)
        return 'D';
    else
        return 'F';
}

int Student::getStudentMark()
{
    return this->mark;
}

void displaySubject(Subject array[])
{
    int flag=0;
    system("cls");
    string id;
    cout << "Enter Subject Code   :" << endl;
    cin >> id;

    // array.displaySubject();

    for (int i = 0; i < MAXSUBJECT; i++)
    {
        if (id == array[i].getSubjectId())
        {
            flag=1;
            array[i].displaySubject();
            break;
        }
    }
    if(flag==0) cout<<"Wrong Subject ID"<<endl;
}

void displayStudent(Subject array[])
{
    system("cls");
    int id;
    cout << "Enter Student Id   :" << endl;
    cin >> id;
    cout << "Subject ID\t\tMarks" << endl;
    for (int i = 0; i < MAXSUBJECT; i++)
    {
        if (array[i].getNoOfStudent() > 0)
        {
            array[i].displayStudent(id);
        }
        else
            return;
        
    }

    
}

void displaySubjectSummary(Subject array[])
{
    system("cls");
    cout << "Subject ID\t\tAverage" << endl;
    for (int i = 0; i < MAXSUBJECT; i++)
    {
        if (array[i].getNoOfStudent() > 0)
        {
            cout << array[i].getSubjectId() << "\t\t\t" << array[i].getSummary() << endl;
        }
        else
            return;
        // array[i].getSummary();
    }
}
void readFile(Subject array[])
{

    ifstream file("subjdata.txt");
    // file.open();
    if (!file.is_open())
    {
        cout << "CANNOT OPEN FILE" << endl;
        exit(1);
    }
    else
    {


        int noOfStudents;
        string subjectId;
        int mark, studentId;
        int j = 0;
        while (!file.eof())
        {
            file >> subjectId >> noOfStudents;
            array[j].setSubject(subjectId, noOfStudents);

            for (int i = 0; i < noOfStudents; i++)
            {
                file >> studentId >> mark;
                array[j].setData(i, studentId, mark);
            }
            j++;
        }
    }
}

void saveSummaries(Subject array[]){

    ofstream file("summdata.txt");

    if (!file.is_open())
    {
        cout << "CANNOT CREATE FILE" << endl;
        exit(1);
    }
    else{
        // char temp[5];
            for (int i = 0; i < MAXSUBJECT; i++){

                if (array[i].getNoOfStudent() > 0)
                {
                    file << array[i].getSubjectId() << "\t" << array[i].getNoOfStudent()<< " A " << array[i].getAvgGrade('A') <<"% "
                         << " B " << array[i].getAvgGrade('B') << "% "
                         << " C " << array[i].getAvgGrade('C') << "% "
                         << " D " << array[i].getAvgGrade('D') << "% "
                         << " E " << array[i].getAvgGrade('E')<<"% "<<endl;
                }
                else
                   return;
            // array[i].getSummary();
        }
    }
}
int main()
{

    Subject array[MAXSUBJECT];

    // array[0].setSubject("SCS1",60);
    // array[0].setData();
    // array[1].setSubject("SCS2", 40);
    // array[1].setData();
    // array[2].setSubject("SCS3", 20);
    // array[2].setData();

    readFile(array);

    int input;

    while (input != 5)
    {
        cout << "*************MENU***************\n1.Display Subject\n2.Display Student\n3.Display Subject Summary\n4.Save Summaries \n5.Exit Program" << endl;
        cin >> input;
        switch (input)
        {
        case 1:
            displaySubject(array);
            system("pause");
            system("cls");
            break;
        case 2:
            displayStudent(array);
            system("pause");
            system("cls");
            break;
        case 3:
            displaySubjectSummary(array);
            system("pause");
            system("cls");
            break;
        case    4:  saveSummaries(array);
            system("cls");
        cout<<"\nSucessfully created the summary file"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
