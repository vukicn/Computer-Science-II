//************************************  PROGRAM IDENTIFICATION  *************************************** 
//*                                                                                                   * 
//*   PROGRAM FILE NAME:  prog2.cpp          ASSIGNMENT #:  2                                         *
//*                                                                                                   *
//*   PROGRAM AUTHOR:   Nikola Vukic                                                                  *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11            SEMESTER:  Fall 2017              INSTRUCTOR: Dr. Miller     *
//*                                                                                                   * 
//*   DATE:  September 22, 2017                                                                       *
//*                                                                                                   *
//***************************************************************************************************** 
//***********************************  PROGRAM DESCRIPTION  ******************************************* 
//*                                                                                                   * 
//*   PROCESS: This program prompt for an integer n, and the generate output to simulate Sisyphus’    *
//*   eternal toil in the underworld until Hercules rescues him from his fate , after n rounds        *
//*   have elapsed.  Each time Sisyphus must push the boulder up the hill, he must move it            *
//*   a total distance of 100 feet. Each push of the boulder will move it a random distance           *
//*   between 0 and 3 feet.  Once the top of the hill is reached, the total number of pushes          *
//*   needed to reach the top should be printed out.                                                  *
//*   CLASSES DEFINED:  rectangle – stored Euclidean space coordinate for a point in 3D space         *
//*                                                                                                   *
//*   USER DEFINED                                                                                    *
//*      FUNCTIONS:  srand() - take seed value as input and generate the random number                *
//*                  rand() - give us any random number                                               *
//*                                                                                                   *
//*****************************************************************************************************
#include <iostream> 
#include <iomanip>
#include <cstdlib>

using namespace std;

//****************************************************************************************************
//*  FUNCTION:  Header                                                                               *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints the output preamble                                                               *
//*  Returns- nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void Header (ostream &Outfile)
{
  Outfile << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << setw(35) << "|     START OF PROGRAM OUTPUT     |" << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;

  return;
}

//****************************************************************************************************
//*  FUNCTION:  Footer                                                                               *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints the output preamble                                                               *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void Footer (ostream &Outfile)
{
  Outfile << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << endl;
  return;
}

//****************************************************************************************************
//*  FUNCTION:  introduction                                                                         *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints the introduction message                                                          *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void introduction(ostream &Outfile)
{
  Outfile << "\n               Hello Cruel UnderWorld\n";
  Outfile << "               ======================\n";
  Outfile << "\n";
  Outfile << "Hello Sisyphus!\n";
  Outfile << "I am Hades! God of the Underworld!\n";
  Outfile << "\n";
  Outfile << "You have offended the gods!  Your punishment, for all eternity, will be to roll\n";
  Outfile << "this 200 pound boulder up that 100 foot high hill, whereupon reaching the top,\n";
  Outfile << "you will watch it roll back down to the bottom again, only to begin again to roll\n";
  Outfile << "it up that hill!\n\n";
  return;
}

//****************************************************************************************************
//*  FUNCTION:  push                                                                                 *
//*                                                                                                  *
//*  Receives - distance how far is pushed                                                           *
//*  Task - Prints the output message how far is pushed                                              *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void push(double &dis)
{
  cout << "   Push - " << setw(12) << dis << " feet\n";
}

//****************************************************************************************************
//*  FUNCTION:  rescued                                                                              *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints the output message at the end of the program                                      *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void rescued(ostream &Outfile)
{
	Outfile << "\nI have been rescued by Hercules - I am freed from this eternal punishment!\n\n";
	return;
}

//****************************************************************************************************
//*  FUNCTION:  mustStartOver                                                                        *
//*                                                                                                  *
//*  Receives - the output file                                                                      *
//*  Task - Prints the output message that need to start again                                       *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void mustStartOver(ostream &Outfile)
{
	Outfile << "Oh No!  The rock rolled back down the hill!\nI have to walk down the hill and start all over.\nI have reached the bottom of the hill.\n\n";
	return;
}

//****************************************************************************************************
//*  FUNCTION:  reachedTop                                                                           *
//*                                                                                                  *
//*  Receives - the output file, numbers of pushes and how many times he attempt                     *
//*  Task - Prints the output text with numbers of pushes and what time he tried                     *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void reachedTop(ostream &Outfile, int psh, int &cnt)
{
	Outfile << "\nSuccess! I reached the top of the hill for the " << cnt  << "th time! It only took " << psh << " pushes to get the boulder to the top\n\n";
	return;
	
}

//****************************************************************************************************
//*  FUNCTION:  IMustToil                                                                            *
//*                                                                                                  *
//*  Receives - number of how many time should execue                                                *
//*  Task - Prints the all pushes and how many times attempted                                       *
//*  Returns- Nothing                                                                                *
//*                                                                                                  *
//****************************************************************************************************
void IMustToil(int &x)
{
  int counter=1;//counts how many times is reached top of the hill
  for(int i=0; i<x; i++)
  {
	  double distance=0.0;//cound total tistance passes
	  int pushes=0;// count how many times is pushed

        //print message between every single try  
  	cout << "I must forever toil to roll this boulder up the hill\n";

	//execute until he reached the top of the hill
	while(distance < 100)
        {
	  //calculates the push distance for the current push 
	  double curr = (double)(rand()/((double)RAND_MAX/3.00));
	  
	  //checks if he reached the top
	  if(distance+curr>100.0)
	  {
	    //push only remainding distance till 100, we don't wanna overreached
	    curr= 100.0-distance;
    	  }
		  
          distance+=curr;//counting total distance
	  pushes++;//increment number of pushes
          push(curr);//prints current push
	}

	//print message when he reached the top with total pushes and what attempt is this
	reachedTop(cout, pushes, counter);
       	counter++;//increment attempt

	//calls function that need to attempt again
	mustStartOver(cout);
  }
  //writes final message when he finishe all attempts
  rescued(cout);
}


//****************************************************************************************************
//*  FUNCTION:  main                                                                                 *
//*                                                                                                  *
//*  This will program execte                                                                        *
//*                                                                                                  *
//****************************************************************************************************
int main()
{
 
  int some;//hold how many times will endure the toil
  int seed;//holds seed value

  Header(cout);//calls function header

  //prompt text message
  cout << "Enter a non-negative seed value: \n";
  cin >> seed; //take value from the user
  srand(seed); //calls library function for random number generator

  //prompt text message
  cout << "How long (enter an integer): \n";
  cin >> some; //take value from the user

  introduction(cout);//prints introduction message

  IMustToil(some);//calls function with how many times will exexute

  Footer(cout);//calls function footer
  
}
