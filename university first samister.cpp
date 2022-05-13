#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void allFunctionHading(char[]);
void allMainMenuOption();
void insertRecord();
void InsertDataInFile(char[], char[], char[], float, char);
int function_checking(char[], char[]);
void checkingIdNo(char);
void displayAllRecord();
void triversingDataDisplay(char);
void searchRecord();
void searchingAndTriversing(char, char, char[]);
void sectionOption(char[]);
void printAllFileData(char[], char[], char[], float, char[]);
void deleteRecord();
void actualDeleteData(char, char[]);

FILE *insert_and_take_data, *insert_and_take_id_no, *temp_file;

int main()
{
	while (1)
	{ // while loop used to reapeted called the main Menu data
		system("cls");
		char heading[] = "WELCOME TO ATTENDENCE MANEGMENT";
		int option;
		allFunctionHading(heading);
		allMainMenuOption();
		option = getch();
		if (option == '1')
		{
			insertRecord();
		}
		else if (option == '2')
		{
			displayAllRecord();
		}
		else if (option == '3')
		{
			searchRecord();
		}
		else if (option == '4')
		{
			deleteRecord();
		}
		else if (option == '5')
		{
		}
		else if (option == '6')
		{
		}
		else if (option == '7')
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\t\tthanks for using \n\n\n\n\n\n\n\n");
			break;
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\t\t YOU ENTERED INVALID OPTION PRESS ANY KEY ");
			getch();
		}
	} // while loop brecket end //
	return 0;
} // main function (closed)

void deleteRecord()

{ // in tis function user selected section to delete the rcord and send id number to actualDeleteData() function
delete_option:
	int check_back = 0;
	system("cls");
	char heading[] = "DELETE RECORD";
	allFunctionHading(heading);
	printf("\n\tSELECT SECTION (  A  ,  B  ,  C  ,  D  )   ..  E for back ");
	char option;
	option = getch();
	if (option == 'A' || option == 'a' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'D' || option == 'd')
	{
		char nameid[40];
		printf("\n\n\tENTER STUDENT ID NUMBER ");
		scanf("%s", &nameid);

		actualDeleteData(option, nameid);
		getch();
	}
	else if (option == 'E' || option == 'e')
	{
		check_back = 67;
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\tINVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY . ");
		getch();
		goto delete_option;
	}
	if (check_back == 0)
	{
		goto delete_option;
	}

} // in tis function user selected section to delete the rcord and send id number to actualDeleteData() function  (closed function)

void actualDeleteData(char option, char delet[])
{

	int x = 0, x2 = 0, fazool, condition = 0, empty = 0;
	char name[40], fname[40], date[40], id[40];
	float attendence;
	if (option == 'a' || option == 'A')
	{
		insert_and_take_data = fopen("sectionA.txt", "r");
	}
	else if (option == 'B' || option == 'b')
	{
		insert_and_take_data = fopen("sectionB.txt", "r");
	}
	else if (option == 'c' || option == 'C')
	{
		insert_and_take_data = fopen("sectionC.txt", "r");
	}
	else if (option == 'd' || option == 'D')
	{
		insert_and_take_data = fopen("sectionD.txt", "r");
	}
	temp_file = fopen("tem.txt", "a");
	while (!feof(insert_and_take_data))
	{
		fscanf(insert_and_take_data, "%i", &fazool);
		fscanf(insert_and_take_data, "%s", &name);
		fscanf(insert_and_take_data, "%s", &fname);
		fscanf(insert_and_take_data, "%s", &date);
		fscanf(insert_and_take_data, "%f", &attendence);
		fscanf(insert_and_take_data, "%s", &id);
		x = function_checking(delet, id);
		if (x == 5)
		{
			x2 = 45;
			fazool = 0;
		}
		else
		{
			fprintf(temp_file, "\n%i %s %s %s %f %s", fazool, name, fname, date, attendence, id);
		}
	}
	fclose(temp_file);
	fclose(insert_and_take_data);
	if (x2 != 45)
	{
		temp_file = fopen("tem.txt", "w");
		fprintf(temp_file, "");
		fclose(temp_file);
		system("cls");
		printf("\n\n\n\n\n\tROLL NUMBER NOT MATCHING TRY AGAIN ");
	}
	else
	{
		if (option == 'a' || option == 'A')
		{
			insert_and_take_id_no = fopen("idA.txt", "w");
			fprintf(insert_and_take_id_no, "");
			fclose(insert_and_take_id_no);
			insert_and_take_id_no = fopen("idA.txt", "a");
			insert_and_take_data = fopen("sectionA.txt", "w");
			fprintf(insert_and_take_data, "");
			fclose(insert_and_take_data);
			insert_and_take_data = fopen("sectionA.txt", "a");
			temp_file = fopen("tem.txt", "r");
			fscanf(temp_file, "%i", &condition);
			if (condition == 0)
			{
				empty = 67;
			}
			fclose(temp_file);
		}
		else if (option == 'B' || option == 'b')
		{
			insert_and_take_id_no = fopen("idB.txt", "w");
			fprintf(insert_and_take_id_no, "");
			insert_and_take_id_no = fopen("idB.txt", "a");
			fclose(insert_and_take_id_no);
			insert_and_take_data = fopen("sectionB.txt", "w");
			fprintf(insert_and_take_data, "");
			fclose(insert_and_take_data);
			insert_and_take_data = fopen("sectionB.txt", "a");
			temp_file = fopen("tem.txt", "r");
			fscanf(temp_file, "%i", &condition);
			if (condition == 0)
			{
				empty = 67;
			}
			fclose(temp_file);
		}
		else if (option == 'c' || option == 'C')
		{
			insert_and_take_id_no = fopen("idC.txt", "w");
			fprintf(insert_and_take_id_no, "");
			fclose(insert_and_take_id_no);
			insert_and_take_id_no = fopen("idC.txt", "a");
			insert_and_take_data = fopen("sectionC.txt", "w");
			fprintf(insert_and_take_data, "");
			fclose(insert_and_take_data);
			insert_and_take_data = fopen("sectionC.txt", "a");
			temp_file = fopen("tem.txt", "r");
			fscanf(temp_file, "%i", &condition);
			if (condition == 0)
			{
				empty = 67;
			}
			fclose(temp_file);
		}
		else if (option == 'd' || option == 'D')
		{
			insert_and_take_id_no = fopen("idD.txt", "w");
			fprintf(insert_and_take_id_no, "");
			fclose(insert_and_take_id_no);
			insert_and_take_id_no = fopen("idD.txt", "a");
			insert_and_take_data = fopen("sectionD.txt", "w");
			fprintf(insert_and_take_data, "");
			fclose(insert_and_take_data);
			insert_and_take_data = fopen("sectionD.txt", "a");
			temp_file = fopen("tem.txt", "r");
			fscanf(temp_file, "%i", &condition);
			if (condition == 0)
			{
				empty = 67;
			}
			fclose(temp_file);
		}
		char name1[40], fname1[40], date1[40], id1[40];
		float attendence1;
		temp_file = fopen("tem.txt", "r");
		if (empty == 0)
		{
			while (!feof(temp_file))
			{
				fscanf(temp_file, "%i", &fazool);
				fscanf(temp_file, "%s", &name1);
				fscanf(temp_file, "%s", &fname1);
				fscanf(temp_file, "%s", &date1);
				fscanf(temp_file, "%f", &attendence1);
				fscanf(temp_file, "%s", &id1);
				fprintf(insert_and_take_id_no, "%s", id1);
				fprintf(insert_and_take_data, "\n%i %s %s %s %f %s", fazool, name1, fname1, date1, attendence1, id1);
			}
		}

		fclose(temp_file);
		temp_file = fopen("tem.txt", "w");
		fprintf(temp_file, "");
		fclose(temp_file);

		fclose(insert_and_take_data);
		fclose(insert_and_take_id_no);

		printf("\n\tRECORD DELETED SUCCESSFULLU PRESS ANY KEY ");
	}
}

void searchRecord()
{ // in tis function user select section then select by name or by id and last send id or name to searchingAndTriversing function
search_option:
	int check_back = 0;
	system("cls");
	char heading[] = "SEARCH RECORD";
	allFunctionHading(heading);
	printf("\n\tSELECT SECTION (  A  ,  B  ,  C  ,  D  )   ..  E for back ");
	char option;
	// scanf("%s",&option);
	option = getch();
	if (option == 'A' || option == 'a' || option == 'b' || option == 'B' || option == 'c' || option == 'C' || option == 'D' || option == 'd')
	{
		char inneroption, nameid[40];
		printf("\n\n\tPRESS 1  BY  ID ");
		printf("\n\n\tPRESS 2  BY  NAME ");
	inner:
		printf("\n\n\tENTER OPTION ..");
		inneroption = getch();
		if (inneroption == '1')
		{
			printf("\n\n\tENTER STUDENT ID NUMBER ");
			scanf("%s", &nameid);
			searchingAndTriversing(option, inneroption, nameid);
		}
		else if (inneroption == '2')
		{
			printf("\n\n\tEnter STUDENT NAME ");
			scanf("%s", &nameid);
			searchingAndTriversing(option, inneroption, nameid);
		}
		else
		{
			printf("\n\n\tYOU ENTER INVALID OPTION ");
			goto inner;
		}
		getch();
	}
	else if (option == 'E' || option == 'e')
	{
		check_back = 67;
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\tINVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY . ");
		getch();
		goto search_option;
	}
	if (check_back == 0)
	{
		goto search_option;
	}

} // in tis function user select section then select by name or by id and last send id or name to searchingAndTriversing function (closed function)

void searchingAndTriversing(char option, char name_id, char search[])
{ // in this function opening all file on reading mode and fetching data to send comparingFunction
	char name[40], fname[40], date[40], id[40];
	float attendence;
	int fazool;
	if (option == 'a' || option == 'A')
	{
		insert_and_take_data = fopen("sectionA.txt", "r");
	}
	else if (option == 'B' || option == 'b')
	{
		insert_and_take_data = fopen("sectionB.txt", "r");
	}
	else if (option == 'c' || option == 'C')
	{
		insert_and_take_data = fopen("sectionC.txt", "r");
	}
	else if (option == 'd' || option == 'D')
	{
		insert_and_take_data = fopen("sectionD.txt", "r");
	}
	int x = 0;
	system("cls");
	char heading[] = "SEARCHING RESULT";
	allFunctionHading(heading);
	int check_name = 0;
	while (!feof(insert_and_take_data))
	{
		fscanf(insert_and_take_data, "%i", &fazool);
		fscanf(insert_and_take_data, "%s", &name);
		fscanf(insert_and_take_data, "%s", &fname);
		fscanf(insert_and_take_data, "%s", &date);
		fscanf(insert_and_take_data, "%f", &attendence);
		fscanf(insert_and_take_data, "%s", &id);
		if (name_id == '1')
		{
			x = function_checking(search, id);
			if (x == 5)
			{
				check_name = 56;
				printAllFileData(name, fname, date, attendence, id);
			}
		} // by id searching if statment brecket
		else
		{
			x = function_checking(search, name);
			if (x == 5)
			{
				printAllFileData(name, fname, date, attendence, id);
				check_name = 56;
			} // if name found

		} // by name checking else brecket here end
	}	  // while brecket end in while loop triversing the file
	fclose(insert_and_take_data);
	if (check_name != 56)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\tID NUMBER NOT FOUND PRESS ANY KEY ");
	}
	else
	{
		printf("\n\n\tPRESS ANY KEY .. ");
	}

} // in this function opening all file on reading mode and fetching data to send comparingFunction (closed function)
void displayAllRecord()
{ // in this function user select selection option then called the triversingDataDisplay() function to triverse the file
displayAllData:
	system("cls");
	char heading[] = "DISPLAY ALL RECORD";
	sectionOption(heading);
	char option;
	option = getch();
	if (option == '1' || option == '2' || option == '3' || option == '4')
	{
		triversingDataDisplay(option);
		printf("\n\n\tPRESS ANY KEY FOR BACK ");
		getch();
		goto displayAllData;
	}
	else if (option == '5')
	{ // cursur return //
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\tINVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY . ");
		getch();
		goto displayAllData;
	}
} // in this function user select selection option then called the triversingDataDisplay() function to triverse the file (closed function)

void triversingDataDisplay(char option)
{ // in this function display all saved data in file mean fetch the data from the file according to user selection section
	char name[40], fname[40], date[40], id_number[40];
	float attendence;
	int fazool, condition = 0, emptycheck = 0;

	system("cls");
	if (option == '1')
	{
		char heading[] = "SECTION A STUDENT DATA";
		allFunctionHading(heading);
		insert_and_take_data = fopen("sectionA.txt", "r");
		fscanf(insert_and_take_data, "%i", &condition);
		fclose(insert_and_take_data);
		insert_and_take_data = fopen("sectionA.txt", "r");
		if (condition == 0)
		{
			printf("\n\n\n\t<--( EMPTY RECORD NO DATA AVAIBLE )-->");

			emptycheck = 1;
		}
	}

	else if (option == '2')
	{
		char heading[] = "SECTION B STUDENT DATA";
		allFunctionHading(heading);
		insert_and_take_data = fopen("sectionB.txt", "r");
		fscanf(insert_and_take_data, "%i", &condition);
		fclose(insert_and_take_data);
		insert_and_take_data = fopen("sectionB.txt", "r");
		if (condition == 0)
		{
			printf("\n\n\n\t<--( EMPTY RECORD NO DATA AVAIBLE )-->");

			emptycheck = 1;
		}
	}

	else if (option == '3')
	{
		char heading[] = "SECTION C STUDENT DATA";
		allFunctionHading(heading);
		insert_and_take_data = fopen("sectionC.txt", "r");
		fscanf(insert_and_take_data, "%i", &condition);
		fclose(insert_and_take_data);
		insert_and_take_data = fopen("sectionC.txt", "r");
		if (condition == 0)
		{
			printf("\n\n\n\t<--( EMPTY RECORD NO DATA AVAIBLE )-->");

			emptycheck = 1;
		}
	}

	else if (option == '4')
	{
		char heading[] = "SECTION D STUDENT DATA";
		allFunctionHading(heading);
		insert_and_take_data = fopen("sectionD.txt", "r");
		fscanf(insert_and_take_data, "%i", &condition);
		fclose(insert_and_take_data);
		insert_and_take_data = fopen("sectionD.txt", "r");
		if (condition == 0)
		{
			printf("\n\n\n\t<--( EMPTY RECORD NO DATA AVAIBLE )-->");

			emptycheck = 1;
		}
	}
	if (emptycheck == 0)
	{
		while (!feof(insert_and_take_data))
		{
			fscanf(insert_and_take_data, "%i", &fazool);
			fscanf(insert_and_take_data, "%s", &name);
			fscanf(insert_and_take_data, "%s", &fname);
			fscanf(insert_and_take_data, "%s", &date);
			fscanf(insert_and_take_data, "%f", &attendence);
			fscanf(insert_and_take_data, "%s", &id_number);
			printAllFileData(name, fname, date, attendence, id_number);
		}
	}

} // in this function display all saved data in file mean fetch the data from the file according to user selection section (closed function)
void insertRecord()
{ // this function is used to take data from student and  send the data to InsertDetailFile that will be store in file
insertOption:
	int check = 0;
	system("cls");
	char heading[] = "INSERT RECORD", name[40], fname[40], date[40], id[40];
	float attendence;
	sectionOption(heading);
	char option;
	// scanf("%i", &option);
	option = getch();
	if (option == '1' || option == '2' || option == '3' || option == '4')
	{
		printf("\n");
		printf("\tENTER NAME OF STUDENT . ");
		scanf("%s", &name);
		printf("\tENTER FATHER NAME OF STUDENT . ");
		scanf("%s", &fname);
		printf("\tENTER STUDENT DATE OF BIRTH . ");
		scanf("%s", &date);
		printf("\tTOTAL CLASSES = 100 . ");
	invalid:
		printf("\n\tENTER STUDENT ATTEND CLASSES . ");

		scanf("%f", &attendence);
		if (attendence >= 0 && attendence <= 100)
		{
			attendence = (attendence * 100) / 100;
		}
		else
		{
			printf("\n\tYOU ENTERED INVALID ENTRY ");
			goto invalid;
		}
		InsertDataInFile(name, fname, date, attendence, option);
	}
	else if (option == '5')
	{
		check = 1;
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\tINVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY . ");
		getch();
		goto insertOption;
	}
	if (check != 1)
	{

		goto insertOption;
	}
} // this function is used to take data from student and  send the data to InsertDetailFile that will be store in file  (closed function)

void InsertDataInFile(char name[], char fname[], char date[], float atten, char option)
{ // this function recive the data which we want to insert file and option variable is used to check the section A,B,C and D//
repeated:
	
	if (option == '1')
	{

		insert_and_take_data = fopen("sectionA.txt", "a");
		fprintf(insert_and_take_data, "\n%i %s %s %s %f", 45, name, fname, date, atten);
		fclose(insert_and_take_data);
		checkingIdNo(option);
	}
	else if (option == '2')
	{
		insert_and_take_data = fopen("sectionB.txt", "a");
		fprintf(insert_and_take_data, "\n%i %s %s %s %f", 45, name, fname, date, atten);
		fclose(insert_and_take_data);
		checkingIdNo(option);
	}
	else if (option == '3')
	{

		insert_and_take_data = fopen("sectionC.txt", "a");
		fprintf(insert_and_take_data, "\n%i %s %s %s %f", 45, name, fname, date, atten);
		fclose(insert_and_take_data);
		checkingIdNo(option);
	}
	else if (option == '4')
	{

		insert_and_take_data = fopen("sectionD.txt", "a");
		fprintf(insert_and_take_data, "\n%i %s %s %s %f", 45, name, fname, date, atten);
		fclose(insert_and_take_data);
		checkingIdNo(option);
	}
	printf("\n\n\tNUMBER ADDED SUCCESSFULLY PRESS ANY KEY ");
	getch();
} // this function recive the data which we want to insert file and option variable is used to check the section A,B,C and D (closed function)

void checkingIdNo(char section_option)
{ // this function is used to triversing the id file and avery repeatation function_checking called to compare the string
	char id_number[40], fetch[40];
checking:
	if (section_option == '1')
	{
		insert_and_take_id_no = fopen("idA.txt", "r");
	}
	else if (section_option == '2')
	{
		insert_and_take_id_no = fopen("idB.txt", "r");
	}
	else if (section_option == '3')
	{
		insert_and_take_id_no = fopen("idC.txt", "r");
	}
	else if (section_option == '4')
	{
		insert_and_take_id_no = fopen("idD.txt", "r");
	}
	int recive_value = 0;
	printf("\tENTER ID NUMBER . ");
	scanf("%s", &id_number);

	while (!feof(insert_and_take_id_no))
	{
		fscanf(insert_and_take_id_no, "%s", &fetch);
		recive_value = function_checking(fetch, id_number);
		if (recive_value == 5)
		{
			break;
		}
		else
		{
			// recive_value=4;
		}
	}
	if (recive_value == 5)
	{
		fclose(insert_and_take_id_no);
		printf("\tplease change the number \n");
		goto checking;
	}
	else
	{
		fclose(insert_and_take_id_no);
		if (section_option == '1')
		{
			insert_and_take_data = fopen("sectionA.txt", "a");
			fprintf(insert_and_take_data, " %s", id_number);
			fclose(insert_and_take_data);
			insert_and_take_id_no = fopen("idA.txt", "a");
		}
		else if (section_option == '2')
		{
			insert_and_take_data = fopen("sectionB.txt", "a");
			fprintf(insert_and_take_data, " %s", id_number);
			fclose(insert_and_take_data);
			insert_and_take_id_no = fopen("idB.txt", "a");
		}
		else if (section_option == '3')
		{
			insert_and_take_data = fopen("sectionC.txt", "a");
			fprintf(insert_and_take_data, " %s", id_number);
			fclose(insert_and_take_data);
			insert_and_take_id_no = fopen("idC.txt", "a");
		}
		else if (section_option == '4')
		{
			insert_and_take_data = fopen("sectionD.txt", "a");
			fprintf(insert_and_take_data, " %s", id_number);
			fclose(insert_and_take_data);
			insert_and_take_id_no = fopen("idD.txt", "a");
		}
		fprintf(insert_and_take_id_no, "\n%s", id_number);
		fclose(insert_and_take_id_no);
	}
} // this function is used to triversing the id file and avery repeatation function_checking called to compare the string (closed function)

void printAllFileData(char name[], char fname[], char date[], float attendence, char id[])
{ // print all data from file can be called from many place

	printf("\n\tName is        %s", name);
	printf("\n\tFather name    %s", fname);
	printf("\n\tBirth is       %s", date);
	printf("\n\tId number is   %s ", id);
	if (attendence >= 70)
	{
		printf("\n\n\tAble to take the final exam attendence is %i per", (int)attendence);
	}
	else
	{
		printf("\n\n\tNot able to take the final exam total attendence is %i%%  less then 70%% ", (int)attendence);
	}
	printf("\n\t*********************************************************************\n\n");
} // print all data from file can be called from many place (closed function)
int function_checking(char fetch[], char orignal[])
{ // this function is used to check the id number of all student if match that return 5 and not match that return 2
	int x = 0;
	for (int i = 0; fetch[i] != '\0' || orignal[i] != '\0'; i++)
	{
		if (fetch[i] == orignal[i])
		{
			x = 5;
		}
		else
		{
			x = 2;
		}
	}
	return x;
} // this function is used to check the id number of all student if match that return 5 and not match that return 2  (closed function)

void sectionOption(char heading[])
{ // this function is also used many place because 4 sections many line of code

	allFunctionHading(heading);
	printf("\tPRESS 1 --->  SECTION A\n");
	printf("\tPRESS 2 --->  SECTION B\n");
	printf("\tPRESS 3 --->  SECTION C\n");
	printf("\tPRESS 4 --->  SECTION D\n");
	printf("\tPRESS 5 --->  BACK MENU\n");
	printf("\n\tSELECT OPTION ( 1 to 5 )... ");
} // this function is also used many place because 4 sections many line of code (function end)

void allMainMenuOption()
{ // in this function only printed data that will be used by many time through many function
	printf("\t_____________________________________\n\n");
	printf("\n\t1: Insert Student Record\n");
	printf("\t2: Display Student Record\n");
	printf("\t3: Search Student Record\n");
	printf("\t4: Delete Student Record\n");
	printf("\t5: Update Student Record\n");
	printf("\t6: attendence Record\n");
	printf("\t7: Exit\n");
	printf("\t_____________________________________\n\n");
	printf("\tEnter option..");
} // in this function only printed data that will be used by many time through many function  (closed function)
void allFunctionHading(char heading[])
{ // this function is only for heading this is also used by many function and many time
	printf("\t\t");
	for (int i = 0; heading[i] != '\0'; i++)
	{
		printf("*");
	}
	printf("\n\t\t%s\n\t\t", heading);
	for (int j = 0; heading[j] != '\0'; j++)
	{
		printf("*");
	}
	printf("\n\n");
} // this function is only for heading this is also used by many function and many time  (closed function)