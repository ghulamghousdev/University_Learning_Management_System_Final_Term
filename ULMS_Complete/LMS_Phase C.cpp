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
#include <fstream>
#include <cmath>
using namespace std;
int indexCounter = 0;
int position;
string store;
int foundIndex;
int userIndex = -1;
int foundIndexCounter=0;
int foundCounter=0;
int studentIndexCounter=0;
int arrayCounter[100]={0};

//These are the functions we are using in this program.
bool ifalpha(char a);
bool isdigit(char b);
bool ishyphen(char c);
void inputFailure();
bool isValidCourseCode(string courseCode);
bool isValidCourseName(string courseName);
bool isValidCreditHours(int creditHours);
bool isValidSemester(int semester);
bool isRegNoValid(string regNo);
bool isValidStdName(string studentName);
bool isValidAddCourse(string courseCodeList[],string courseCode , string courseName , int crdHrs, int semester);
bool isValidUpdatedCourse(string courseCode , string courseName , int crdHrs, int semester);
void AddCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], string courseCode, string courseName, int crdHrs, int semester);
void EditCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], string courseCode, string courseName, int crdHrs, int semester);
void DeleteCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], string courseCode);
void ViewCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[]);
void ViewSemesterCourses(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], int semester);
bool loadCourses(string courseCodeList[], string courseList[], int semList[], int crtHrsList[]);
bool saveCourses(string courseCodeList[], string courseList[], int crtHrsList[], int semList[]);
bool Users(string usersList[], string passwordsList[]);
bool login(string userList[], string passwordsList[], string userName, string password);
void addStudent(string stdNamesList[],string stdRegNoList[] , string studentName , string regNo);
void updateStudent(string stdNamesList[],string stdRegNoList[] , string studentName , string regNo);
void deleteStudent(string stdNamesList[] , string stdCourseList[][100] , string stdRegNoList[] , string regNo);
void registerCourse(string stdRegNoList[] , string courseCodeList[] , string regNo, string courseCode , string stdCourseList[][100]);
void unRegister(string stdRegNoList[] , string courseCodeList[] , string regNo, string courseCode , string stdCourseList[][100]);
void viewAllStudents(string stdRegNoList[] , string stdNamesList[] , string stdCourseList[][100]);

//*****************************************************************************************************************************************************************
//Main starts from here.
//*****************************************************************************************************************************************************************

int main()
{
	//declaring variables & strings we further use in our function.
	string courseCode, courseName;
	int crdHrs, semester, option,foundIndex;
	string userName, password,regdNo,regNo,studentName;
	//Declaring string arrays to store input.
	string courseCodeList[100], courseList[100], usersList[100], passwordsList[100], nameList[100],stdNamesList[100],stdCourseList[100][100],stdRegNoList[100];
	//Declaring  int arrays to store input.
	int semList[100], crtHrsList[100];
	bool flag;

	//Main menu.
	//Using while loop  to come back into main if user enters wrong value.
	
	cout << "\n\n\t\t\t**Welcome to University Learning Management System**" << endl;
	cout << "Dear User, current software is intended for authorized users only.Login to the system to get access." << endl;
	loadCourses(courseCodeList, courseList, semList, crtHrsList);
	while(option!=13){
	Users(usersList , passwordsList);
	while (userIndex == -1)
	{	
		option=0;
		cout << "Username : ";
		cin >> userName;
		cout << "Password : ";
		cin >> password;
	login(usersList , passwordsList, userName, password);
	}
	while (option != 12 && option != 13)
	{
		cout << "Choose one of the following option: " << endl;
		cout << "1"
			 << "\t"
			 << "Add Course" << endl;
		cout << "2"
			 << "\t"
			 << "Update Course" << endl;
		cout << "3"
			 << "\t"
			 << "Delete Course" << endl;
		cout << "4"
			 << "\t"
			 << "View All Courses" << endl;
		cout << "5"
			 << "\t"
			 << "View Courses of a Semester" << endl;
		cout << "6"
			 << "\t"
			 << "Add new Student" << endl;
		cout << "7"
			 << "\t"
			 << "Update Student" << endl; 
		cout << "8"
			 << "\t"
			 << "Delete course" << endl;
		cout << "9"
			 << "\t"	
		   	 << "View all students" << endl;
		cout << "10"
			 << "\t"
			 << "Register the course for a student" << endl;
		cout << "11"
			 << "\t"
			 << "Un register the course for a student" <<endl;
		cout << "12"
			 << "\t"
			 << "Logout of the system" << endl;
		cout << "13"
			 << "\t"
			 << "Exit Program\n\n"
			 << endl;
		cout << "Please choose one option: ",
			cin >> option;
		if (cin.peek() != '\n')
		{
			option = 0;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		//*************************************************************************************************************************************************************
		//Using Switch statement to call a function.
		//*************************************************************************************************************************************************************
		switch (option)
		{
		case 0:
		{
			cout << "Looks like you have not read the Main Menu.\n" << endl;
		}
		break;

		//Calling function to Add course.
		case 1:
		{
			cout << "Enter the details of the course:";
			cin >> courseCode >> crdHrs >> semester;
			//If user enters wrong input . then following condition will ignore it and program will not go into infinite loop.
			inputFailure();
			cin.ignore(1, ' ');
			getline(cin, courseName);
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if(isValidAddCourse(courseCodeList, courseCode , courseName , crdHrs, semester)){
				AddCourse(courseCodeList, courseList, crtHrsList, semList, courseCode, courseName, crdHrs, semester);
				cin.clear();
			}
		}
		break;
		//Calling function to Update course.
		case 2:
		{
			store="";
			bool flag=false;
			bool found = false;
			cout << "Enter the course code to edit: ";
			cin >> courseCode;
			inputFailure();
			for (int i = 0; i < indexCounter; i++)
			{
				if (courseCode == courseCodeList[i])
				{
					position = i;
					found = true;
				}
			}
			store = courseCode;
			if (found)
			{
				cout << "Enter the new details of the course:";
				cin >> courseCode  >> semester;
				inputFailure();
				cin>> crdHrs;
				inputFailure();
				cin>> semester;
				inputFailure();
				getline(cin, courseName);
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
				
				if(isValidUpdatedCourse(courseCode , courseName , crdHrs, semester)){
					EditCourse(courseCodeList, courseList, crtHrsList, semList, courseCode, courseName, crdHrs, semester);
					cout << "Hit enter";
					cin.clear();
					cin.ignore(15, '\n');	
				}
			}
			else
			{
				cout << "Your new course code is not found code." << endl;
			}
		}
		break;
		//Calling Function to delete course.
		case 3:
		{	
			cout << "Enter course code: ";
			cin >> courseCode;
			inputFailure();
			int flag = -1;


			if (isValidCourseCode(courseCode)){
			DeleteCourse(courseCodeList, courseList, crtHrsList, semList, courseCode);
			}
		}
		break;
		//Calling function to View course that we added.
		case 4:
		{
			ViewCourse(courseCodeList, courseList, crtHrsList, semList);
		}
		break;
		//Calling function to view semester courses.
		case 5:
		{
			
			cout << "Enter the semester: ";
			cin >> semester;
			cin.clear();
			ViewSemesterCourses(courseCodeList, courseList, crtHrsList, semList, semester);
		}
		break;

		case 6:
		{
			cout<<"Enter the details of the Student : ";
			cin>>regNo;
			inputFailure();
			getline(cin , studentName);
			for(int i=0; i<studentIndexCounter;i++){
				if(regNo==stdRegNoList[i]){
					foundCounter++;
				}
			}
			if(isRegNoValid(regNo)){
				if( isValidStdName(studentName)){
					addStudent(stdNamesList,stdRegNoList,studentName,regNo);
		
				}
			}
		}
		break;
		case 7:
		{
			store="";
			position=0;
			bool flag=false;
			bool found = false;
			cout << "Enter the registration number to edit : ";
			cin >> regNo;
			inputFailure();
			for (int i = 0; i < studentIndexCounter; i++){
				if (regNo == stdRegNoList[i]){
					position = i;
					found = true;
				}
			}
			store=regNo;
			if (found){
			cout<<"Enter details of the student : ";
			cin>>regNo;
			inputFailure();
			getline(cin, studentName);
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if(store==regNo){
				if(isRegNoValid(regNo)){
					if(isValidStdName(studentName)){
						updateStudent(stdNamesList,stdRegNoList,studentName ,regNo);
					
					}
				}							
			}
			else{
				cout<<"Registration can not be editted."<<endl;
			}
		}
			else{
				cout<<"Registration number is not found "<<endl;
			}
		}
		break;
		
		case 8:
		{
			int index=0;
			bool flag=false;
			cout<<"Enter the registration number : ";
			cin>>regNo;
			for(int i=0 ; i<studentIndexCounter ; i++){
				if(regNo==stdRegNoList[i]){
					flag=true;
					foundIndex=i;
				}
			}
			if(flag){
				deleteStudent( stdNamesList ,  stdCourseList ,  stdRegNoList ,  regNo);
			}
			else{
				cout<<"Registration number is not found"<<endl<<endl;
			}	
		}
		break;
		
		case 9:
		{
			viewAllStudents(stdRegNoList , stdNamesList , stdCourseList);
		}
		break;
		case 10:
		{
			cout<<"Enter registration number of student for course registration\n";
			cin>>regNo;
			inputFailure();
			cout<<"Enter course code  to register\n";
			cin>>courseCode;
			inputFailure();
			registerCourse(stdRegNoList , courseCodeList , regNo,  courseCode , stdCourseList);	
		}
			break;
		
		case 11:
		{
			cout<<"Enter registration number of student ";
			cin>>regNo;
			inputFailure();
			cout<<"Enter course code to un register ";
			cin>>courseCode;
			inputFailure();
			unRegister(stdRegNoList , courseCodeList ,  regNo, courseCode , stdCourseList);
		}
		break;	
		case 12:
		{
			cout<<"You have successfully log out.\nPlease log in again."<<endl;
			userIndex=-1;
		}
		break;
		//To exit program.
		case 13:
		{
			saveCourses(courseCodeList, courseList, crtHrsList, semList);
			cout << "Your program is terminated...!!!" << endl
				 << endl;
			break;
		}

		//If user enters any digit or alpha which is not in range of digits from 1 to 6.
		default:
		{
			cin.ignore(15, '\n');
			cout << "Please add a input which is in range from 1 to 6.\n";
		}
		}
		continue;
	}
}
	return 0;
}
//Made functions which we further used in our program.
void inputFailure(){
	if (cin.fail()){
		cin.clear();
		cin.ignore(10000, ' ');
	}
}
//Function to check Upper case alphabets.
bool ifalpha(char a)
{
	bool isValid = false;
	if (a >= 'A' && a <= 'Z')
	{
		isValid = true;
	}
	return isValid;
}
//Function to check digits.
bool isdigit(char b)
{
	bool isValid;
	if (b >= '0' && b <= '9')
	{
		isValid = true;
	}
	return isValid;
}

bool ishyphen(char c)
	{
		bool flag;
		if(c=='-')
		{
			flag=true;
		}
		return flag;
	}
//function to check the validity of course that it is has size of 5 and 2 alphabet and 3 digits are used.
bool isValidCourseCode(string courseCode)
{
	bool isValid = false;
	if (courseCode.size() == 5)
	{
		if ((ifalpha(courseCode[0])))
		{
			if ((ifalpha(courseCode[1])))
			{
				if ((isdigit(courseCode[2])))
				{
					if ((isdigit(courseCode[3])))
					{
						if ((isdigit(courseCode[4])))
							isValid = true;
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
	int counter = 0, emptyness = 0;
	bool isValid = false;

	{
		for (int i = 0; i < courseName.size(); i++)
		{
			if (isalpha(courseName[i]) || isspace(courseName[i]) != 0)
			{
				counter += 1;
				if (isspace(courseName[i]) != 0)
				{
					emptyness++;
				}
			}
		}
	}
	if (courseName.size() == counter && emptyness != counter)
	{
		isValid = true;
	}
	return isValid;
}
//Function to check that are credit hours in the range from 1 to 3.
bool isValidCreditHours(int creditHours)
{
	if ((creditHours > 0) && (creditHours <= 3))
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
	if ((semester <= 8) && (semester > 0))
		return true;
	else
		return false;
}



//Function to add course .
void AddCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], string courseCode, string courseName, int crdHrs, int semester)
{
		//To store it in arrays.
	courseList[indexCounter] = courseName;
	courseCodeList[indexCounter] = courseCode;
	crtHrsList[indexCounter] = crdHrs;
	semList[indexCounter] = semester;
	cout << "Course has been added successfully" << endl << endl;
	indexCounter++;
}


//To check validity of course code
bool isValidAddCourse(string courseCodeList[], string courseCode , string courseName , int crdHrs, int semester)
{
	bool flag=false;
	int counter = 0;
	//To check size of course name that is it equal to or less then 50 in characters.
	if (courseName.size() <= 50)
	{
		//To check is it already added or not.
		for (int i = 0; i < indexCounter; i++)
		{
			if (courseCode == courseCodeList[i])
			{
				counter += 1;
			}
		}
		if (counter == 0) //To check its validity.
		{
			if (isValidCourseCode(courseCode))
			{
				if (isValidCreditHours(crdHrs))
				{
					if (isValidSemester(semester))
					{
						if (isValidCourseName(courseName))
						{
							flag=true;
						}
						else
						{
							cout << "\n Course Name is not valid." << endl;
						}
					}
					else
					{
						cout << "\n Semester number is not valid. " << endl;
					}
				}
				else
				{
					cout << "\n Credit hours is not valid." << endl;
				}
			}
			else
			{
				cout << "Your course code is not valid " << endl;
			}
		}
		else
		{
			cout << "Your course code already exists.\nDon't look like you are ok??\nWhy are you entering the course code again & again." << endl;
		}
	}
	else
	{
		cout << "Your course name is more then of 50 characters.\nAre you in dumb.\nPlease enter a course name which is less then or equal to 50 characters." << endl;
	}
	return flag;
}



//Function to update course.
void EditCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], string courseCode, string courseName, int crdHrs, int semester)
{
	courseList[position] = courseName;
	courseCodeList[position] = courseCode;
	crtHrsList[position] = crdHrs;
	semList[position] = semester;
	cout << "Course has been edited successfully\n"
		 << endl;
}
bool isValidUpdatedCourse(string courseCode , string courseName , int crdHrs, int semester)
{
	bool flag=false;

		if (courseCode == store)
		{
			if (isValidCourseCode(courseCode))
			{
				if (isValidCreditHours(crdHrs))
				{
					if (isValidSemester(semester))
					{
						if (isValidCourseName(courseName))
						{
							flag=true;
						}
						else
						{
							cout << "Course name is not valid." << endl;
						}
					}
					else
					{
						cout << "Semester is not valid." << endl;
					}
				}
				else{
					cout << " Credit Hours are not valid." << endl;
				}
			}
			else
			{
				cout << "Your new course is not a valid course." << endl;
			}
		}
		else
		{
			cout << "Your course code can not be editted." << endl;
		}

	return flag;
}

int b = 0;
//Function to delete a course.
void DeleteCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], string courseCode)
{
	int foundIndex;
	bool isValid = false;
	for (int i = 0; i < indexCounter; i++)
		{
			if (courseCodeList[i] == courseCode)
			{
				isValid = true;
				foundIndex = i;
			}
		}
		if(isValid){
		for (int i = foundIndex; i < indexCounter; i++)
		{
			courseCodeList[i] = courseCodeList[i + 1];
			courseList[i] = courseList[i + 1];
			crtHrsList[i] = crtHrsList[i + 1];
			semList[i] = semList[i + 1];
		}
		cout << "Course has been deleted successfully!\n"
			 << indexCounter;
		indexCounter--;
		}
		else{
			cout<<"Course Code is not found that you wanted to delete."<<endl<<endl;
		}
}

//Function to view all courses which we added.
void ViewCourse(string courseCodeList[], string courseList[], int crtHrsList[], int semList[])
{
	//Setting formatting and outputing titles.
	cout << left << setw(16) << "Course Code" << setw(50) << "CourseName" << setw(15) << "Credit Hours" << setw(15) << "Semester" << endl;
	for (int i = 0; i < indexCounter; i++)
	{
		cout << left << setw(16) << courseCodeList[i] << setw(50) << courseList[i] << setw(15) << crtHrsList[i] << setw(15) << semList[i] << endl;
		b = 0;
	}
}

//Function to view the courses of a specific semester.
void ViewSemesterCourses(string courseCodeList[], string courseList[], int crtHrsList[], int semList[], int semester)
{
	cout << left << setw(16) << "Course Code" << setw(50) << "CourseName" << setw(15) << "Credit Hours" << endl;
	for (int i = 0; i < indexCounter; i++){
		if (semester = semList[i]){
			cout << left << setw(16) << courseCodeList[i] << setw(50) << courseList[i] << setw(15) << crtHrsList[i] << endl;
		}
	}
}

bool saveCourses(string courseCodeList[], string courseList[], int crtHrsList[], int semList[]){
	bool flag = false;
	ofstream output;
	output.open("Courses.txt");
	if (output.is_open()){
		for (int i = 0; i < indexCounter; i++){
			output << courseCodeList[i] << "," << courseList[i] << "," << crtHrsList[i] << "," << semList[i] << endl;
		}
		cout << "your data is successfully saved."<<endl << endl;
		flag = true;
	}
	else
	{
		cout << "Error in opening file." << endl<<endl;
	}
	output.close();
	return flag;
}

bool loadCourses(string courseCodeList[], string courseList[], int semList[], int crtHrsList[])
{
	bool flag = false;
	ifstream input;
	string temp;
	
	input.open("Courses.txt");
	if (input.is_open())
	{
		while (getline(input, temp))
		{
			string courseCode, name;
			int creditHours, semester;
			int i;
			for (i = 0; temp[i] != ','; i++)
			{
				courseCode += temp[i];
			}
			i += 1;
			for (i; temp[i] != ','; i++)
			{
				name += temp[i];
			}
			i += 1;
			for (i; temp[i] != ','; i++)
			{
				creditHours = temp[i] - '0';
			}
			i += 1;
			for ( i; i<temp.length(); i++) {
				semester = temp[i] - '0';
			}

			courseCodeList[indexCounter] = courseCode;
			courseList[indexCounter] = name;
			crtHrsList[indexCounter] = creditHours;
			semList[indexCounter] = semester;
			indexCounter++;
		}

		flag = true;
		input.close();

	}
	else
	{
		cout << "Sorry, we are unable to run the program, as user data does not exist." << endl;
	}
	return flag;
}

int userCounter = 0;

bool Users(string usersList[], string passwordsList[])
{
	bool flag = false;
	ifstream user;
	string file, userName, userPass;
	user.open("Users.txt");
	if (user.is_open())
	{
		while (getline(user, file))
		{
			int i = 0;
			while (file[i] != ',')
			{
				userName += file[i];
				i++;
			}
			usersList[userCounter] = userName;
			i++;
			while (i < file.length())
			{
				userPass += file[i];
				i++;
			}
			passwordsList[userCounter] = userPass;
			userCounter++;
			cout << endl;
		}
		flag = true;
		user.close();
	}
	else
	{
		cout << "Sorry, we are unable to run the program, as user data does not exist."<<endl << endl;
	}

	return flag;
}

bool login(string userList[], string passwordsList[], string userName, string password)
{
	bool flag = false;
		for (int i = 0; i < userCounter; i++)
		{
			if (userList[i] == userName)
			{
				userIndex = i;
			}
		}

		if ((userList[userIndex] == userName) && (passwordsList[userIndex] == password))
		{
			cout << "You are successfully logged in" <<endl <<endl;
			flag = true;
		}
		else
		{
			cout << "Dear User, Username/password is incorrect. Enter the username/password again to get access to the system" <<endl<< endl;
		}
	
	return flag;
}

void addStudent(string stdNamesList[],string stdRegNoList[] , string studentName , string regNo){
	stdNamesList[studentIndexCounter]=studentName;
	stdRegNoList[studentIndexCounter]=regNo;
	cout<<"Student has been added successfully."<<endl<<endl;
	studentIndexCounter++;	
}

bool isRegNoValid(string regNo){
	bool flag=false;
	if(foundCounter==0){
	if(regNo.length()==11){
		if(regNo[0]=='2'){
			if(regNo[1]=='0'){
				if(regNo[2]=='1'){
					if(isdigit(regNo[3])){
							if(ishyphen(regNo[4])){
								if(ifalpha(regNo[5])){
									if(ifalpha(regNo[6])){
										if(ishyphen(regNo[7])){
											if(isdigit(regNo[8])){
												if(isdigit(regNo[9])){
													if(isdigit(regNo[10])){
														flag=true;
										
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}	
	if(flag!=true){
		cout<<"Your registraion number is not valid "<<endl<<endl;
	}
	}
	else{
		cout<<"Student already exists."<<endl<<endl;
	}
	return flag;
}

bool isValidStdName(string studentName){
	int counter = 0, emptyness = 0;
	bool flag = false;
	{
		for (int i = 0; i < studentName.size(); i++)
		{
			if (isalpha(studentName[i]) || isspace(studentName[i]) != 0)
			{
				counter += 1;
				if (isspace(studentName[i]) != 0)
				{
					emptyness++;
				}
			}
		}
	}
	if (studentName.size() == counter && emptyness != counter)
	{
		flag = true;
	}
	else{
		cout<<"Student name is not valid"<<endl<<endl;
	}
	return flag;
}

void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo) {
	stdNamesList[position] = studentName;
	cout << "Student has been updated successfully" << endl;
}

void deleteStudent(string stdNamesList[], string stdCourseList[][100], string stdRegNoList[], string regNo) {
	for (int k = position ; k < studentIndexCounter; k++) {
		stdRegNoList[k] = stdRegNoList[k + 1];
		stdNamesList[k] = stdNamesList[k + 1];
		
	stdCourseList[position][arrayCounter[position]]= stdCourseList[position][arrayCounter[0]];
	}
	cout << "Student has been deleted." << endl;
	studentIndexCounter--;
}

void viewAllStudents(string stdRegList[], string stdNamesList[], string stdCourseList[][100]) {
	cout << left << setw(15) << "Reg No" << setw(20) << "Student Name" << setw(20) << "Course Code" << endl;
	for (int i = 0; i < studentIndexCounter; i++) {
		cout << left << setw(15) << stdRegList[i] << setw(20) << stdNamesList[i];
		for (int k = 0; k < arrayCounter[i]; k++) {
			cout << stdCourseList[i][k];
			cout << " ";
		}
		cout << endl;

	}
}

void registerCourse(string stdRegNoList[], string courseCodeList[], string regNo, string courseCode, string stdCourseList[][100]) {
	int counter1 = 0, counter2 = 0;
	for (int j = 0; j < studentIndexCounter; j++) {
		if (regNo == stdRegNoList[j]) {
			counter1++;
			foundIndex = j;
		}
	}
	for (int i = 0; i < indexCounter; i++) {
		if (courseCode == courseCodeList[i]) {
			counter2++;
		}
	}

	if (counter1 != 0) {
		if (counter2 != 0) {
			stdCourseList[foundIndex][arrayCounter[foundIndex]] = courseCode;
			cout << "Course has been registered successfully " << endl;
			arrayCounter[foundIndex]++;
		}
		else {
			cout << "Course code is invalid " << endl;
		}
	}
	else {
		cout << "Registration number is invalid " << endl;
	}
}

void unRegister(string stdRegNoList[], string courseCodeList[], string regNo, string courseCode, string stdCourseList[][100]) {
	int b;
	for (int i = 0; i < studentIndexCounter; i++) {
		if (regNo == stdRegNoList[i]) {

			foundIndex = i;
		}
	}
	for (int j = 0; j < arrayCounter[foundIndex]; j++) {
		if (stdCourseList[foundIndex][j] == courseCode) {
			b = j;
		}
	}
	for (int k = b; k < arrayCounter[foundIndex]; k++) {
		stdCourseList[foundIndex][k] = stdCourseList[foundIndex][k + 1];
	}

	arrayCounter[foundIndex]--;
	cout << "Course has been unregistered" << endl;
}
