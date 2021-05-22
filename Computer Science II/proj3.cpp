//************************************  PROGRAM IDENTIFICATION  *************************************** 
//*                                                                                                   * 
//*   PROGRAM FILE NAME:  proj3.cpp          ASSIGNMENT #:  3                                         *
//*                                                                                                   *
//*   PROGRAM AUTHOR:   Nikola Vukic                                                                  *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11            SEMESTER:  Fall 2017              INSTRUCTOR: Dr. Miller     *   
//*                                                                                                   * 
//*   DATE:  October 22, 2018                                                                         *
//*                                                                                                   *
//***************************************************************************************************** 
//***********************************  PROGRAM DESCRIPTION  ******************************************* 
//*                                                                                                   * 
//*   PROCESS: This program is designed to open and read input files which contain                    *
//*   an unknown number of records and process the student data in accordance with the instructions   *
//*   given below.                                                                                    *
//*   numbers and their test averages.  It is then to echo print the original list of students and    *
//*   scores. It is then to find and print the student with the lowest test score along with the      *
//*   student’s identification number.  It is also to find the student with the highest test score    *
//*   and print the student’s information.  Finally the program is to print the average test score    *
//*   for the entire class                                                                            *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*      FUNCTIONS:  Header - print header message                                                    *
//*                  Footer - print footer message                                                    *
//*                  ReadData – reads the student IDs and test scores into an empty array             *
//*                  PrintData – prints a listing of all students with their test scores              *
//*                  PrintData2 - prints all data set with students ID, test scores,                  *
//*                  average score and grade                                                          *
//*                  originalMsg -header for original data set                                        *
//*                  msgSortByID - header for sorted by ID data set                                   *
//*                  msgStudentList - header for data set included average test and grade             *
//*                  msgStdListSorted - header for all data set sorted by avergate test score         *
//*                  msgLast- Prints message with input file name                                     *
//*                  calAverage -  calcualte average test score for every single student              *
//*                  calGrade -  calcualte grades based on student's average score                    *
//*                  swap - swap elements of array scores with cordinate of ID                        *
//*                  swap2 - swap elements of array scores with cordinate of avergae test score       *
//*                  finalSwap -swap elements of array scores with cordinate of ID in ascending order * 
//*                  finalSortByID- sort data set in ascending order, used selection sord             *
//*                  sortByID-sort data set by ID also test scores should sorted, used selection sord *
//*                  sortByAvg - sort data set by average test score, used selection sord             *
//*                  CalcAvg – Calculates the average of all the test scores                          *
//*                                                                                                   * 
//*   INPUT FILES:   data3.txt – holds the original student data to be processed                      * 
//*   OUTPUT FILES:  output3.txt – will hold the final student data after it is processed             * 
//*                                                                                                   * 
//***************************************************************************************************** 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

//************************** FUNCTION HEADER *************************
void Header (ostream &Outfile)
{
      // Receives- the output file
      // Task - Prints the output salutation
      // Returns - Nothing
  Outfile << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << setw(35) << "|     START OF PROGRAM OUTPUT     |" << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;

  return;
}
//********************** END OF FUNCTION HEADER ************************

//************************** FUNCTION FOOTER *************************
void Footer (ostream &Outfile)
{
      // Receives- the output file
      // Task - Prints the output salutation
      // Returns - Nothing
  Outfile << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << endl;
  return;
}
//********************** END OF FUNCTION FOOTER ************************

//****************************************************************************************************
//*  FUNCTION:  printData2                                                                           *
//*                                                                                                  *
//*  Receives - Arrays of ID, test scores, average test score, grade and homy many elements in array *
//*  Task - Prints all set of data                                                                   *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void printData2(int stud[], double tests[][4],double avg[], char grade[], int &num)
{
 
 for(int i=0;i<num;i++)
   {
     cout<<"  "<<right<< setfill('0')<<setw(10)<<stud[i]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][0]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][1]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][2]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][3]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(2)<<setw(7)<<avg[i]<<"  ";
     cout<<right<<setfill(' ')<<setw(5)<<grade[i]<<endl;
   }  
}

//****************************************************************************************************
//*  FUNCTION:  printData2                                                                           *
//*                                                                                                  *
//*  Receives - Arrays of ID, test scores and homy many elements in array                            *
//*  Task - Prints IDs and test scores                                                               *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void printData(int stud[], double tests[][4], int &num)
{
 
 for(int i=0;i<num;i++)
   {
     cout<<"  "<<right<< setfill('0')<<setw(10)<<stud[i]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][0]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][1]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][2]<<"  ";
     cout<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(6)<<tests[i][3]<<endl;
   }   
}

//****************************************************************************************************
//*  FUNCTION:  originalMsg                                                                          *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints 2 header rows for the student data                                                *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void originalMsg(ostream &Outfile)
{
  cout<< "\nThe original student data is:\n";
  cout<< " Student ID   Test 1  Test 2  Test 3  Test 4  \n";
  cout<< "------------  ------  ------  ------  ------  \n";
}

//****************************************************************************************************
//*  FUNCTION:  msgSortByID                                                                          *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints 2 header rows for the student data sorted by ID from low to high                  *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void msgSortByID(ostream &Outfile)
{
  cout<< "\nThe list of student data sorted by ID number from low to high is:\n";
  cout<< " Student ID   Test 1  Test 2  Test 3  Test 4  \n";
  cout<< "------------  ------  ------  ------  ------  \n";
}

//****************************************************************************************************
//*  FUNCTION:  msgStudentList                                                                       *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints 4 header rows for the student data with thier test average and course grade       *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void msgStudentList(ostream &Outfile)
{
  cout<< "\nThe list of students with their test average and course grade is:\n";
  cout<< "                                              Test     Course\n";
  cout<< " Student ID   Test 1  Test 2  Test 3  Test 4  Average  Grade \n";
  cout<< "------------  ------  ------  ------  ------  -------  ------\n";
}

//****************************************************************************************************
//*  FUNCTION:  msgStdListSorted                                                                     *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints 4 header rows for the student data sorted by test average score from high to low  *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void msgStdListSorted(ostream &Outfile)
{
  cout<< "\nThe list of students sorted by test average high to low is:\n";
  cout<< "                                              Test     Course\n";
  cout<< " Student ID   Test 1  Test 2  Test 3  Test 4  Average  Grade \n";
  cout<< "------------  ------  ------  ------  ------  -------  ------\n";
}
//****************************************************************************************************
//*  FUNCTION:  msgLast                                                                              *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints message with input file name                                                      *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void msgLast(ostream &Outfile)
{
  cout<<"\nOpening output file: outfile.txt\n";
  cout<<"Writing data to output file\n";
}

//****************************************************************************************************
//*  FUNCTION:  calAverage                                                                           *
//*                                                                                                  *
//*  Receives -arrays of test scores, average test scores and how many elements in array              *
//*  Task - calcualte average test score for every single student                                    *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void calAverage(double testAvg[], double arrAvg[][4], int &num)
{
  for(int i=0; i<num;i++)
    {
      double q;
      q=(arrAvg[i][0]+arrAvg[i][1]+arrAvg[i][2]+arrAvg[i][3])/4.0;
      testAvg[i]=q;
    }
}

//****************************************************************************************************
//*  FUNCTION:  calGrade                                                                             *
//*                                                                                                  *
//*  Receives -arrays of grades, average test scores and how many elements in array                  *
//*  Task - calcualte grades based on student's average score                                        *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void calGrade(char grade[], double avg[], int&num)
{
  for(int i=0; i<num; i++)
  {
    if(avg[i]>=89.5 && avg[i]<=100)
      grade[i]='A';
    if(avg[i]>=79.5 && avg[i]<89.5)
      grade[i]='B';
    if(avg[i]>=69.5 && avg[i]<79.5)
      grade[i]='C';
    if(avg[i]>=59.5 && avg[i]<69.5)
      grade[i]='D';
    if(avg[i]>=0 && avg[i]<59.5)
      grade[i]='F'; 
  }
  
}

//****************************************************************************************************
//*  FUNCTION:  swap                                                                                 *
//*                                                                                                  *
//*  Receives -arrays of scores and what are current cordinate of arrays                             *
//*  Task - swap elements of array scores with cordinate of ID                                       *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void swap(double test[][4], int &i, int&j)
{
   for(int k =0; k<4; k++)
     {
       double score= test[i][k];
       test[i][k]=test[j][k];
       test[j][k]=score;
     }
}

//****************************************************************************************************
//*  FUNCTION:  swap2                                                                                *
//*                                                                                                  *
//*  Receives -arrays of scores and what are current cordinate of arrays                             *
//*  Task - swap elements of array scores with cordinate of avergae test score                       *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void swap2(int id[], double test[][4], char letter[],int &i, int &j )
{
  
   for(int k =0; k<4; k++)
     {
       double score= test[i][k];
       test[i][k]=test[j][k];
       test[j][k]=score;
     }

       int temp= id[i];
       id[i]= id[j];
       id[j]=temp;

       char temp2= letter[i];
       letter[i]= letter[j];
       letter[j]=temp2;
}

//****************************************************************************************************
//*  FUNCTION:  finalSwap                                                                            *
//*                                                                                                  *
//*  Receives -arrays of scores, average score and grade and what are current cordinate of arrays    *
//*  Task - swap elements of array scores with cordinate of ID in ascending order                    *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void finalSwap( double test[][4],double avg[],  char letter[],int &i, int &j )
{
  
   for(int k =0; k<4; k++)
     {
       double score= test[i][k];
       test[i][k]=test[j][k];
       test[j][k]=score;
     }

       double temp= avg[i];
       avg[i]= avg[j];
       avg[j]=temp;

       char temp2= letter[i];
       letter[i]= letter[j];
       letter[j]=temp2;
}

//****************************************************************************************************
//*  FUNCTION:  finalSortByID                                                                        *
//*                                                                                                  *
//*  Receives -arrays of IDs, average test score, test scores, grade and how many elements in array  *
//*  Task - sort data set in ascending order, used selection sord                                    *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void finalSortByID(int arrIds[], double test[][4],double avg[], char grade[], int &num)
{
 
  for(int i=0; i< num-1;i++)
  {
      int min=i;
      for(int j=i+1; j< num;j++)
      {
	  if(arrIds[j] < arrIds[min])
	    {
	      min=j;
	    }
       }
       if(i != min)
       {
    	  int sw= arrIds[i];
	  arrIds[i]= arrIds[min];
	  arrIds[min]=sw;
	  finalSwap(test,avg, grade,i,min);//swap other elements
       }
     
  } 
}
//****************************************************************************************************
//*  FUNCTION:  sortByID                                                                             *
//*                                                                                                  *
//*  Receives -arrays of IDs, test scores and how many elements in array                             *
//*  Task - sort data set by ID also test scores should sorted, used selection sord                  *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void sortByID(int arrIds[],double test[][4], int &num)
{
 
  for(int i=0; i< num-1;i++)
  {
      int max=i;
      for(int j=i+1; j< num;j++)
      {
	  if(arrIds[j] > arrIds[max])
	    {
	      max=j;
	    }
       }
       if(i != max)
       {
	     
       	 int sw= arrIds[i];
 	 arrIds[i]= arrIds[max];
         arrIds[max]=sw;
	 swap(test,i,max);//swap other elements
       }
     
  } 
}
//****************************************************************************************************
//*  FUNCTION:  sortByAvg                                                                            *
//*                                                                                                  *
//*  Receives -arrays of IDs, average test scores, test scores, grade and how many elements in array *
//*  Task - sort data set by average test score, used selection sord                                 *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void sortByAvg(double avg[], int id[],double test[][4], char letter[], int &num)
{
  for(int i=0; i< num-1;i++)
  {
      int max=i;
      for(int j=i+1; j< num;j++)
      {
	  if(avg[j] > avg[max])
	    {
	      max=j;
	    }
      }
      if(i != max)
      {
	  double swap= avg[i];
	  avg[i]= avg[max];
	  avg[max]=swap;
	  swap2(id, test, letter, i, max);//swap other elements
      }
  } 
}

int main()
{
  Header(cout); //print the header on the screen

  int xls;//holds integers
  double d;//holds doubles
  int ids[100];//holds ID number
  double scores[100][4];//holds students scores
  double average[100];//holds student average score
  char grade[100];//holds students letter grade
  int count=0;//counts how many students

  //set all arrays to -1
  for(int k=0; k<100;k++)
    {
      ids[k]=-1;
      scores[k][0]=-1;
      scores[k][1]=-1;
      scores[k][2]=-1;
      scores[k][3]=-1;
      average[k]=-1;
      
    }
  
  ifstream data("data3.txt");//open input file
  ofstream ofile("output3.txt");

  //check if data file is open
  if(!data)
    {
      cout << "File data3.txt failed to open" << endl;
      exit(1);   //exit with non-zero code
      
    }
  //checks if output file is open
  if(!data)
    {
      cout << "File outfile.txt failed to open" << endl;
      exit(1);   //exit with non-zero code
      
    }

  //read data from the file and store in arrays of IDs and Test scores
  while(data>>xls && xls>=0)
    {
      ids[count]=xls;
      data>>d;
      scores[count][0]=d;
      data>>d;
      scores[count][1]=d;
      data>>d;
      scores[count][2]=d;
      data>>d;
      scores[count][3]=d;
      count++;
          
    }
  
  originalMsg(cout);//print header for original data set
  printData(ids, scores, count);//print data set
  
  msgSortByID(cout);//print header for data set sorted by ID
  sortByID(ids,scores, count);//sort by ID
  printData(ids, scores, count);//print data set
  
  msgStudentList(cout);//print header for data set with average score and grade
  calAverage(average, scores, count);// calculate average score
  calGrade(grade, average, count);//calcualate grade
  printData2(ids, scores, average, grade, count);//print all data set
  
  msgStdListSorted(cout);//print header for data set with average score and grade sorted by average score
  sortByAvg(average, ids, scores, grade, count);//sort by average score
  printData2(ids, scores, average, grade, count);//print all data set sorted
 
  finalSortByID(ids,scores, average, grade, count);//sort ascending order
  msgLast(cout);//print opening output file message
  
  //put data in output file
  for(int m=0;m < count;m++)
    {
     ofile<<right<< setfill('0')<<setw(10)<<ids[m]<<endl;//right justified within 10 places and '0' before
     ofile<<right<<setfill(' ')<<fixed<<setprecision(1)<<setw(4)<<scores[m][0]<<" ";// right justified within 4 places
     ofile<<right<<setfill(' ')<<fixed<<setprecision(1)<<scores[m][1]<<" ";   //and spaces before and one decimal place
     ofile<<right<<setfill(' ')<<fixed<<setprecision(1)<<scores[m][2]<<" ";
     ofile<<right<<setfill(' ')<<fixed<<setprecision(1)<<scores[m][3]<<" ";
     ofile<<right<<setfill(' ')<<fixed<<setprecision(2)<<average[m]<<" ";//right justified with two decimal places
     ofile<<right<<setfill(' ')<<grade[m]<<endl;
    }
  
  cout<<"Closing output file: outfile.txt\n";//closing output message
  cout<<endl;//new line
  
  Footer(cout);  //print the footer
}
