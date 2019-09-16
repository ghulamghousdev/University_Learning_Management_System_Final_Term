//**************************************************************************************************************************************************************
//University Learning Management System.
//***************************************************************************************************************************************************************
//GHULAM GHOUS
//2018-CS-31
//SECTION A
//UNIVERSITY OF ENGINEERING & TEHNOLOGY LAHORE
//***************************************************************************************************************************************************************
//Header Files
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int indexCounter=0;
//These are the functions we are using in this program.
bool ifalpha(char a);
bool isdigit(char b);
bool isValidCourse(string courseCode);
bool isValidCourseName(string courseName);
bool isValidCreditHours(int creditHours);
bool isValidSemester(int semester);
void AddCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , string courseCode ,string courseName , int crdHrs ,int semester  );
void EditCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , string courseCode ,string courseName , int crdHrs ,int semester );
void DeleteCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , string courseCode);
void ViewCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[]);
void ViewSemesterCourses(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , int semester);
//*****************************************************************************************************************************************************************
//Main starts from here.
//*****************************************************************************************************************************************************************
int main ()
{	
	//declaring variables & strings we further use in our function. 
	string courseCode , courseName;
	int crdHrs  , semester, option;
	//Declaring string arrays to store input.
	string codeList[100],courseList[100]; 
	//Declaring  int arrays to store input.
	int semList[100],crtHrsList[100];   
    //Main menu.
    //Using while loop  to come back into main if user enters wrong value.
	while(option!=6){
	cout<<"\n\n\t\t\t**Welcome to University Learning Management System**"<<endl;
	cout<<"Choose one of the following option: "<<endl;
	cout<<"1"<<"\t"<<"Add Course"<<endl;
	cout<<"2"<<"\t"<<"Update Course"<<endl;
	cout<<"3"<<"\t"<<"Delete Course"<<endl;
	cout<<"4"<<"\t"<<"View All Courses"<<endl;
	cout<<"5"<<"\t"<<"View Courses of a Semester"<<endl;
	cout<<"6"<<"\t"<<"Exit Program\n\n"<<endl;
	cout<<"Please choose one option: ",
	cin>>option;
	if(cin.peek()!='\n')
	{	
		option=0;
		cin.clear();
		cin.ignore(1000 , '\n');
	}
	
	//*************************************************************************************************************************************************************
	//Using Switch statement to call a function.
	//*************************************************************************************************************************************************************	
	switch(option)
	{
		case 0:
			{
				cout<<"Are you in your senses?? \nYou fool....!!\nYour mind is filled with emptiness!!\nLooks like you have not read the Main Menu."<<endl;
				
			}
			break;
			
		//Calling function to Add course.
		case 1:
		    {	
			cout<<"Enter the details of the course:";
			cin>>courseCode>>crdHrs>>semester;
			//If user enters wrong input . then following condition will ignore it and program will not go into infinite loop.
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(10000, ' ');	
			}
				getline(cin,courseName);
				if(cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');	
				}		    	
		        	AddCourse(codeList, courseList ,crtHrsList ,semList , courseCode ,courseName , crdHrs ,semester  );
		        	cin.clear();
		        	
		    	}
		    	break;
		//Calling function to Update course.
        case 2:
            {
                EditCourse(codeList, courseList , crtHrsList , semList, courseCode ,courseName , crdHrs ,semester );
                cout<<"Hit enter";
                cin.clear();
                cin.ignore(15 , '\n');

            }
            break;
        //Calling Function to delete course.
        case 3:
        	{
        		DeleteCourse(codeList, courseList , crtHrsList , semList , courseCode);
			}
			break;
		//Calling function to View course that we added.
		case 4:
			{
				ViewCourse(codeList, courseList , crtHrsList , semList);
			}
			break;
		//Calling function to view semester courses.
		case 5:
			{
				ViewSemesterCourses(codeList, courseList , crtHrsList , semList , semester);	
			}
			break;
		//To exit program.
		case 6:
			{
				cout<<"Your program is terminated...!!!"<<endl<<endl;
				break;
			}
		
		
		//If user enters any digit or alpha which is not in range of digits from 1 to 6.
		default:
			{
				cin.ignore(15 , '\n');
				cout<<"Are you Crazy?? \nWhy are you entering the wrong value.\nAs you already told to input a digit which is in range from 1 to 6.\n";
			}
		
		}
		continue;
	}
	return 0;
	}
	//Made functions which we further used in our program.
//Function to check Upper case alphabets.
bool ifalpha(char a)
	{	
		bool isValid=false;
		if(a>='A'  &&  a<='Z')
		{
			isValid=true;
		}
		return isValid;
	}
//Function to check digits.
bool isdigit(char b)
	{
		bool isValid;
		if(b>='0' && b<='9')
		{
			isValid=true;
		}
		return isValid;
	}
//function to check the validity of course that it is has size of 5 and 2 alphabet and 3 digits are used.
bool isValidCourseCode(string courseCode)
	{
		bool isValid=false;
		if (courseCode.size()==5)
		{
			if((ifalpha(courseCode[0])))
			{
				if((ifalpha(courseCode[1])))
				{
					if((isdigit(courseCode[2])))
					{
						if((isdigit(courseCode[3])))
						{
							if((isdigit(courseCode[4])))
						 		isValid=true;
						}
					}
				}
			}
		}
			return isValid;
	}
//Function to check the validity of course name.
bool isValidCourseName(string courseName)
	{
		int counter=0, emptyness=0;
		bool isValid=false;
	
		{
			for(int i=0; i<courseName.size() ; i++)
			{
				if(isalpha(courseName[i]) || isspace(courseName[i])!=0)
				{
					counter+=1;
					if(isspace(courseName[i])!=0)
					{
						 emptyness++;
					}
				
				}
			}
		
		}
		if(courseName.size()==counter && emptyness!=counter)
		{
			isValid=true;
		}
			return isValid;
	}
//Function to check that are credit hours in the range from 1 to 3.
bool isValidCreditHours(int creditHours)
	{
		if((creditHours>0) && (creditHours<=3))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
//Function to check whether semester is in range from 1 to 8.
bool isValidSemester(int semester)
	{
		if((semester<=8) && (semester>0))
		return true;
		else
		return false;
	}
//Function to add course .
void AddCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , string courseCode ,string courseName , int crdHrs ,int semester  )
	{
		int counter=0;
			//To check size of course name that is it equal to or less then 50 in characters.
			if(courseName.size() <= 50){
			//To check is it already added or not.
			for(int i=0 ; i<indexCounter ; i++)
			{
				if(courseCode==codeList[i])
				{
					counter+=1;
				}
			}
				if(counter == 0) //To check its validity.
				{
					if(isValidCourseCode(courseCode))
					{
						if(isValidCreditHours(crdHrs))
						{
							if(isValidSemester(semester))
							{
								if(isValidCourseName(courseName))
								{
									//To store it in arrays.
									courseList[indexCounter]=courseName;
									codeList[indexCounter]=courseCode;
									crtHrsList[indexCounter]=crdHrs;
									semList[indexCounter]=semester;
									cout<<"Course has been added successfully"<<endl<<endl;
									indexCounter++;
								}
								else
								{
									cout<<"\n Course Name is not valid."<<endl;
								}
							}
							else
							{
								cout<<"\n Semester number is not valid. "<<endl;
							}
						}
						else
						{
							cout<<"\n Credit hours is not valid."<<endl;
						}
					}
					else
					{
						cout<<"Your course code is not valid "<<endl;
					}
			}
			else
			{
				cout<<"Your course code already exists.\nDon't look like you are ok??\nWhy are you entering the course code again & again."<<endl;
			}	
		}
		else
		{
			cout<<"Your course name is more then of 50 characters.\nAre you in dumb.\nPlease enter a course name which is less then or equal to 50 characters."<<endl;
		}
	}
//Function to update course.
void EditCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , string courseCode ,string courseName , int crdHrs ,int semester )
	{
		int position;
		bool found=false;
		cout<<"Enter the course code to edit: ";
		cin>>courseCode;
		for(int i=0 ; i<indexCounter ; i++)
		{
			if(courseCode==codeList[i])
			{
			   position=i;
			   found=true;
			}
		}
		
		if(found)
			{
				cout<<"Enter the new details of the course:";
				cin>>courseCode>>crdHrs>>semester;
				getline(cin ,  courseName);
				if(isValidCourseCode(courseCode))
				{
					if(isValidCreditHours(crdHrs))
					{
						if(isValidSemester(semester))
						{
							if(isValidCourseName(courseName))
                            {
                                courseList[position]=courseName;
                                codeList[position]=courseCode;
                                crtHrsList[position]=crdHrs;
                                semList[position]=semester;
								cout<<"Course has been edited successfully\n"<<endl;
                            }
                            else
                            {
                            	cout<<"Course name is not valid."<<endl;
							}
						}
						else
						{	
							cout<<"Semester is not valid."<<endl;	
						}
					}
					else
					{
						cout<<" Credit Hours are not valid."<<endl;
					}
				}
				else
				{
					cout<<"Your new course is not a valid course."<<endl;
				}
			}
			else
			{
				cout<<"Your new course code is not found code."<<endl;
			}
	}
	
	int b=0;
//Function to delete a course.
void DeleteCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , string courseCode)
	{
		int flag=-1;
		
		int foundIndex;
		bool isValid=false;
		cout<<"Enter course code: ";
		cin>>courseCode;
		cin.clear();
		if(isValidCourseCode(courseCode)==1){		
			for(int i=0 ; i<indexCounter ; i++){
				if(codeList[i]==courseCode) 
				{
					isValid=true;
					foundIndex=i;
				}
			}
			for(int i=foundIndex; i<indexCounter; i++) 
			{
				codeList[i]=codeList[i+1];
				courseList[i]=courseList[i+1];
				crtHrsList[i]=crtHrsList[i+1];
				semList[i]=semList[i+1];		
			}
			cout<<"Course has been deleted successfully!\n" << indexCounter;
			indexCounter--;
		}
	}


	//Function to view all courses which we added.
	void ViewCourse(string codeList[], string courseList[] , int crtHrsList[] , int semList[])
	{
		//Setting formatting and outputing titles.	
		cout<<left<<setw(16)<<"Course Code"<<setw(50)<<"CourseName"<<setw(15)<<"Credit Hours"<<setw(15)<<"Semester"<<endl;
		for(int i=0 ; i<indexCounter ; i++)
		{
			cout<<left<<setw(16)<<codeList[i]<<setw(50)<<courseList[i]<<setw(15)<<crtHrsList[i]<<setw(15)<<semList[i] << endl;
			b=0;		
		}
		
	}

	//Function to view the courses of a specific semester.
	void ViewSemesterCourses(string codeList[], string courseList[] , int crtHrsList[] , int semList[] , int semester)
	{	
		cout<<"Enter the semester: ";
		cin>>semester;
		cin.clear();
		cout<<"Course Code"<<"\tCourse Name "<<"\t\tCredit Hours"<<endl;
		for(int i=0 ; i<indexCounter ; i++)
		{
			if (semester=semList[i])
			{
		 		cout<<codeList[i]<<"\t"<<courseList[i]<<"\t\t"<<crtHrsList[i]<< "\t\t" <<endl;
        	}
		}
	}
