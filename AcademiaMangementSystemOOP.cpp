#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

class Employee{
	protected:
	char *loginId;
	char *password;
	public:
		Employee()
		{
			loginId=0;
			password=0;
		}

		Employee(char l[],char p[])
		{
			loginId=new char[strlen(l)+1];
			password=new char[strlen(p)+1];
			strcpy(loginId,l);
			strcpy(password,p);
		}
		
		void setLogin(char l[])
			{
				loginId=new char[strlen(l)+1];
				strcpy(loginId,l);
			}
			
			char *Getlogin()
			{
				return loginId;
			}
			
		void setPassw(char p[])
		{
			password=new char[strlen(p)+1];
			strcpy(password,p);	
		}
		
		char *Getpassw()
		{
			return password;
		}
		
		~Employee()
		{
			if(loginId!=NULL)
			delete[] loginId;
			if(password!=NULL)
			delete[] password;
		}

};
int totalCourses;
class Student;
class Course{
	private:
		char *Coursename;
		char *code;
		int creditHours;
		char *PreReq;
		Student *studentList;
		int totalStudents;

		public:
			Course()
			{
				Coursename=NULL;
				code=NULL;
				creditHours=0;
				PreReq=NULL;
			}
			
			
			void setCname(char c[])
			{
				Coursename=new char[strlen(c)+1];
				strcpy(Coursename,c);
			}
			
			char *getCname()
			{
				return Coursename;
			}
			
			void setCode(char cd[])
			{
				code=new char[strlen(cd)+1];
				strcpy(code,cd);
			}
			
			char *getCode()
			{
				return code;
			}
			
			
			void setCredits(int s)
			{
				creditHours=s;
			}
			
			int getCredits()
			{
				return creditHours;
			}
			
			void setPre(char p[])
			{
				PreReq=new char[strlen(p)+1];
				strcpy(PreReq,p);
			}
			
			char *getPre()
			{
				return PreReq;
			}
			
			void setInfo(char c[], char name[], int credithours, char prereq[])
			{
				Coursename=new char[strlen(name)+1];
				code=new char[strlen(c)+1];
				creditHours=credithours;
				PreReq=new char[strlen(prereq)+1];
				strcpy(Coursename,name);
				strcpy(code,c);
				strcpy(PreReq,prereq);
				
			}
			
			char *getcourseinfo()
			{
				return Coursename;
			}
			
			
			void printCourse()
			{
				if(Coursename!=NULL && code!=NULL)
				cout<<code<<"\t"<<Coursename<<endl;
			}
			void fileInput()
			{
				ofstream fout;
				fout.open("assignedCourses.txt",ios::app);
				if(Coursename!=NULL&&code!=NULL)
				fout<<code<<"\t"<<Coursename<<endl;
				
				fout.close();
			}
			void fileInputstudent()
			{
				ofstream fout;
				fout.open("studentAssignCourse.txt",ios::app);
				if(Coursename!=NULL&&code!=NULL)
				fout<<code<<"\t"<<Coursename<<endl;
				
				fout.close();
			}
			
			void printCWCinfo()
			{
				if(Coursename!=NULL && code!=NULL)
				cout<<code<<"\t"<<Coursename<<"\t"<<creditHours<<"\t"<<PreReq<<endl;
			}

};

class Teacher:public Employee{
	private:
		Course *course;
		Student *s;
		public:
			
			Teacher()
			{
				loginId=0;
				password=0;
				s=NULL;
				totalCourses=0;
			}
		
			void uploadMarks();

			void uploadAttend();
			void setTotalCourses(int t)
			{
				totalCourses=t;
			}
			
			int getTotalCourses()
			{
				return totalCourses;
			}
			
			void assignedcourses()
			{
				course=new Course[totalCourses];
				for(int i=0;i<totalCourses;i++)
				{
					course[i].setInfo(course[i].getCode(),course[i].getCname(),course[i].getCredits(),course[i].getPre());
				}
			}
			
			void printAssignedCourses()
			{
				cout<<"t";
				for(int i=0;i<totalCourses;i++)
				{
					course[i].printCourse();
				}
			}
			
};

class Student:public Employee{
	private:
		double cgpa;
		double sgpa;
		int totalCredits;
		int feedback[10];

		public:
			Student()
			{
				cgpa=0;
				sgpa=0;
				loginId=0;
				password=0;
				totalCredits=0;
			}
			
			Student(double c,double s,int t,char l[],char p[])
			{
				cgpa=c;
				sgpa=s;
				totalCredits=t;
				loginId=new char[strlen(l)+1];
				password=new char[strlen(p)+1];
				strcpy(loginId,l);
				strcpy(password,p);

			}
			
			void setCgpa(double c)
			{
				cgpa=c;
			}
			double GetCgpa()
			{
				return cgpa;
			}
			
			void setSgpa(double s)
			{
				sgpa=s;
			}
			
			double GetSgpa()
			{
				return sgpa;
			}
			
			void setTotalcredits(int t)
			{
				totalCredits=t;
			}
			
			int GetTotalCrhs()
			{
				return totalCredits;
			}
			
			void feedBack()
			{
				cout<<"1 Teacher was well prepared for lecture\n";
				cout<<"2 Teacher has the knowledge of subject\n";
				cout<<"3 Enviroment of the class room was satisfy\n";
				cout<<"4 Teacher give the answers to questions thoroughly\n";
				cout<<"5 Behaiour of the teacher was polite with students\n";
				cout<<"1 TA was well prepared for lecture\n";
				cout<<"2 TA has the knowledge of subject\n";
				cout<<"3 Enviroment of the class room was satisfy\n";
				cout<<"4 TA give the answers to questions thoroughly\n";
				cout<<"5 Behaiour of the TA was polite with students\n";
			}
			
			void enterfeedback()
			{
				cout<<"enter 1 for agree and 2 for disagree\n";
				cout<<"1 Teacher was well prepared for lecture\n";
				cin>>feedback[0];
				cout<<"2 Teacher has the knowledge of subject\n";
				cin>>feedback[1];
				cout<<"3 Enviroment of the class room was satisfy\n";
				cin>>feedback[2];
				cout<<"4 Teacher give the answers to questions thoroughly\n";
				cin>>feedback[3];
				cout<<"5 Behaiour of the teacher was polite with students\n";
				cin>>feedback[4];
				cout<<"6 TA was well prepared for lecture\n";
				cin>>feedback[5];
				cout<<"7 TA has the knowledge of subject\n";
				cin>>feedback[6];
				cout<<"8 Enviroment of the class room was satisfy\n";
				cin>>feedback[7];
				cout<<"9 TA give the answers to questions thoroughly\n";
				cin>>feedback[8];
				cout<<"10 Behaiour of the TA was polite with students\n";
				cin>>feedback[9];
				
			}
			void viewfeedBack()
			{
				ofstream fout;
				fout.open("studentFeedBack.txt");
				fout<<" Teacher was well prepared for lecture\n"<<feedback[0];
				fout<<" Teacher has the knowledge of subject\n"<<feedback[1];
				fout<<" Enviroment of the class room was satisfy\n"<<feedback[2];
				fout<<" Teacher give the answers to questions thoroughly\n"<<feedback[3];
				fout<<" Behaiour of the teacher was polite with students\n"<<feedback[4];
				fout<<" TA was well prepared for lecture\n"<<feedback[5];
				fout<<" TA has the knowledge of subject\n"<<feedback[6];
				fout<<" Enviroment of the class room was satisfy\n"<<feedback[7];
				fout<<" TA give the answers to questions thoroughly\n"<<feedback[8];
				fout<<" Behaiour of the TA was polite with students\n"<<feedback[9];
				fout.close();
			} 
			

};

class Admin : public Employee,public Student{
	private:
		Student *s1;
		Course *courseList[7];
		Teacher *teacherList;
		int totalStudents;
		int totalTeachers;
		int semesterNum;
		int count;
		public:
			
			Admin()
			{
				s1=NULL;
				for(int i=0;i<7;i++)
				{
					courseList[i]=NULL;
				}
				teacherList=NULL;
			}
			
			~Admin()
			{
				if(s1!=NULL)
				delete[] s1;
				
				if(teacherList!=NULL)
				delete[] teacherList;
				
				for(int i=0;i<7;i++)
				{
					if(courseList[i]!=NULL)
					{
						delete courseList[i];
						courseList[i]=NULL;
					}
				}
			}
			void setSemNum(int s)
			{
				semesterNum=s;
			}
			
			int getSemNum()
			{
				return semesterNum;
			}
			
			void AssignLoginToStudent()
			{
				char login[10];
				char passw[10];
				cout<<"enter number of students :";
				cin>>totalStudents;
				s1=new Student[totalStudents];
				ofstream fout;
				fout.open("info.txt",ios::app);
				
				for(int i=0;i<totalStudents;i++)
				{
					
					cout<<"enter login id\n";
					cin>>login;
					s1[i].setLogin(login);
					fout<<s1[i].Getlogin()<<"\t";
					
					cout<<"enter password of student :";
					cin>>passw;
					s1[i].setPassw(passw);
					fout<<s1[i].Getpassw()<<endl;
					
					
				}
				
				fout.close();
			}
			
			
			void AssignLoginidTeacher()
			{
				ofstream fout;
				fout.open("teacherList.txt",ios::app);
				char l[10];
				char p[10];
				cout<<"enter number of teacher you want to assign login info\n";
				cin>>totalTeachers;
				teacherList=new Teacher[totalTeachers];
				for(int i=0;i<totalTeachers;i++)
				{
					cout<<"enter login id of the teacher\n";
					cin>>l;
					teacherList[i].setLogin(l);
					teacherList[i].Getlogin();
					fout<<l<<"\t";
					
					
					cout<<"enter password to assign teacher\n";
					cin>>p;
					fout<<p<<endl;
					teacherList[i].setPassw(p);
					teacherList[i].Getpassw();
					
				}
				fout.close();
				
			}
			
			bool searchCourse(string c)
			{
				ifstream fin;
				string usercode;
				fin.open("studentAssignCourse.txt");
				while(fin)
				{
					if(!fin)
					break;
					fin>>usercode;
					if(usercode==c)
					{
						cout<<"match";
						return true;
					}
				}
				fin.close();
				return false;
			}
			
			bool searchStudent(string id,string pass)
			{
				string iduser;
				string passuser;
				ifstream fin;
				fin.open("info.txt");
				
				while(fin)
				{
					if(!fin)
					break;
					fin>>iduser;
					fin>>passuser;
					
						if(iduser == id && passuser==pass)
						{
						cout<<"match"<<endl;
						return true;
						}
						
				}
				fin.close();
						return false;
					
			}
					
				
		
			
			bool searcht(string id,string pass)
			{
				string iduser;
				string passuser;
				ifstream fin;
				fin.open("teacherList.txt");
			
			
				while(fin)
				{
					if(!fin) break;
					fin>>iduser;
					fin>>passuser;
					
						if(iduser == id && passuser==pass)
						{
						cout<<"match"<<endl;
						return true;
						}
						
				}
				fin.close();
						return false;
					
			}
			
			
				void loadCourses()
			{
				
				int number;
				ifstream fin;
				fin.open("ListOfCourses.txt");
				char word[50];
				char line[20];

				int z = 0;
				char sem[10] = "Semester";
				char readFullLine[100];
				int k = 0;

				while (fin)
				{
					fin >> word;

					if (strcmp(word, "Semester") == 0)
					{
						fin >> number;
						if (number == semesterNum)
						{
							fin.ignore(200, ':');
							while (z < 10) 
							{
								fin.getline(line, 20, ' ');     //line reads the first word of each line of file.
								fin.getline(readFullLine, 100);
								if (strcmp(line, sem) == 0)
								{
					 				break;  //If word 'semester' is found this loop terminates.Count measures that 'semester' word occurs after how many lines.
								}
								else
									count++; //here count will decide how many courses are there in a semester.

								z++;
							}
						}
					}
				}
				fin.close();
				int y = 0;
				int x = 0;
				char courseCode[10], courseName[50], coursePreReq[20];
				int courseCrHrs;
				k = 0;
				fin.open("ListOfCourses.txt");
				while (fin)
				{
					fin >> word;
					if (strcmp(word, "Semester") == 0)
					{
						fin >> number;
						if (number == semesterNum)
						{
							fin.ignore(200, ':');
							while (y < count)    //count contains no. of courses in a semester.
							{
								courseList[x] = new Course;   //Memory allocation. 
								fin >> courseCode;
								fin.ignore();
								fin.ignore();

								fin.getline(courseName, 50, '.');
								fin >> courseCrHrs;
								fin.getline(coursePreReq, 20);

								courseList[x]->setInfo(courseCode, courseName, courseCrHrs, coursePreReq);
								

								y++; 
								x++;
							}
						}
					}
				}
				fin.close();

				}
				
				void assignCourse()
				{
					int a,t;
					int j=0;
					int count=0;
					char arr[10];
					string l;
					string p;
					cout<<"enter number of teachers\n";
					cin>>t;
					
					//teacherList=new Teacher[t];
					for(int i=0;i<t;i++)
					{
						ofstream fout;
						fout.open("assignedCourses.txt",ios::app);
							
						cout<<"enter login id \n";
						cin>>l;
						
						cout<<"enter password\n";
						cin>>p;
						
						if(searcht(l,p)==1)
						{
							fout<<l<<"\t";
							fout<<p<<endl;
						cout<<"enter number of courses you want to assign\n";
						cin>>a;
						totalCourses=a;
						fout.close();
						for(int k=0;k<a;k++)
						{
						cout<<"enter course code you want to assign\n";
						cin>>arr;
						for(j=0;j<7;j++)
						{
							if(courseList[i]!=NULL)
							{
							
								if(strcmp(courseList[j]->getCode(),arr)==0)
								{
								count++;
								break;
								}
							}
						
						}
						
					//teacherList[i]=courseList[j];
					courseList[j]->fileInput();
					}
				}
				else
				{
					cout<<"teacher not found\n";
				}
			}
			}
			
			void printCourseInfo()
			{
				for(int i=0;i<count;i++)
				{
					cout<<i+1<<"- ";
					courseList[i]->printCourse();
				}
			}
			
			void getCourseWithCode(char a[])
			{
				int count=0;
				int i=0;
				for(i=0;i<7;i++)
				{
					if(courseList[i]!=NULL)
					{
						if(strcmp(courseList[i]->getCode(),a)==0)
						{
							count++;
							break;
						}
					}
					
				}
				if(count==0)
					{
						cout<<"No subject found with this code\n";
					}
					else
					courseList[i]->printCWCinfo();
			}
			
			void registerCourse()
			{	
					int a,t;
					int j=0;
					int count=0;
					char arr[10];
					string l;
					string p;
					cout<<"enter number of students\n";
					cin>>t;
					for(int i=0;i<t;i++)
					{
						ofstream fout;
						fout.open("info.txt",ios::app);
							
						cout<<"enter login id \n";
						cin>>l;
						
						cout<<"enter password\n";
						cin>>p;
						
						if(searchStudent(l,p)==1)
						{
							fout<<l<<"\t";
							fout<<p<<endl;
						cout<<"enter number of courses you want to register\n";
						cin>>a;
						fout.close();
						fout.open("studentAssignCourse.txt");
						for(int k=0;k<a;k++)
						{
						
						cout<<"enter course code you want to register\n";
						cin>>arr;
						if(searchCourse(arr)==1)
						{
						cout<<"match\n";
							for(j=0;j<7;j++)
							{
							if(courseList[i]!=NULL)
							{
							
								if(strcmp(courseList[j]->getCode(),arr)==0)
								{
								count++;
								break;
								}
							}
						
						}
						
					courseList[j]->fileInputstudent();
					}
				}}
				else
				{
					cout<<"teacher not found\n";
				}
						fout.close();	
						}
						
			}

};





int main()
{
	cout<<"enter 1 for admin\nenter 2 for student\nenter 3 for teacher\n";
	int b,c,sem;
	cin>>c;
	while(c<=0 ||c>3)
	{
		cout<<"enter again\n";
		cin>>c;
	}
	char scode[10];
	Teacher t;
	Student s;
	Admin a;
	
	cout<<"enter semester number"<<endl;
	cin>>sem;
	while(sem<=0 || sem>8)
	{
		cout<<"enter again!!\n";
		cin>>sem;
	}
	a.setSemNum(sem);
	a.getSemNum();
	a.loadCourses();
	if(c==1)
	{
		cout<<"enter 1 to show course\n";
		cout<<"enter 2 to search course with code\n";
		cout<<"enter 3 to assign login id to teacher\n";
		cout<<"enter 4 to assign login id to student\n";
		cout<<"enter 5 to assign course to teacher\n";
		cout<<"enter 6 to search teacher\n";
		cout<<"enter 7 to search student\n";
		cin>>b;
		while(b<=0 || b>7)
		{
			cout<<"enter again!!\n";
			cin>>b;
		}
		
		if(b==1)
	{
		a.printCourseInfo();
	}
	else if(b==2)
	{
		cout<<"enter code\n";
		cin>>scode;
		a.getCourseWithCode(scode);
	}
	else if(b==3)
	{
		a.AssignLoginidTeacher();
		
		
	}
	else if(b==4)
	{
		a.AssignLoginToStudent();
	}
	
	else if(b==5)
	{
		a.assignCourse();
		
	}
	
	else if(b==6)
	{
		string l;
		string p;
		cout<<"enter login id\n";
		cin>>l;
		cout<<"enter password\n";
		cin>>p;
		a.searcht(l,p);
	}
	
	else if(b==7)
	{
		string l;
		string p;
		cout<<"enter login id\n";
		cin>>l;
		cout<<"enter password\n";
		cin>>p;
		a.searchStudent(l,p);
	}	
	}
	else if(c==2)
	{
	cout<<"enter 1 to register course\n";
	cout<<"enter 2 to give feed back\n";
	cout<<"enter 3 to show courses\n";
	cout<<"enter 4 to search course with code\n";
	cin>>b;
	while(b<=0 || b>4)
	{
		cout<<"enter again!!\n";
		cin>>b;
	}

	
	if(b==1)
	{
		a.registerCourse();
	}
	
	else if(b==2)
	{
		s.feedBack();
		s.enterfeedback();
		s.viewfeedBack();
		
	}
	
	else if(b==3)
	{
		a.printCourseInfo();
	}
	
	else if(b==4)
	{
		cout<<"enter code\n";
		cin>>scode;
		a.getCourseWithCode(scode);
	}
	
	else if(c==3)
	{
		cout<<"enter 1 to show courses\n";
		cout<<"enter 2 to search course with code\n";
		cin>>b;
		while(b<=0 || b>2)
		{
			cout<<"enter again!!"<<endl;
			cin>>b;
		}
		
		if(b==1)
	{
		a.printCourseInfo();
	}
	
	else if(b==2)
	{
		cout<<"enter code\n";
		cin>>scode;
		a.getCourseWithCode(scode);
		
	}
		
		
	}
}
	return 0;
}





