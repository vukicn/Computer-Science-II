#include <iostream> 
#include <iomanip>
#include <cstdlib>

using namespace std;

void Header (ostream &Outfile)
{
  Outfile << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << setw(35) << "|     START OF PROGRAM OUTPUT     |" << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;

  return;
}

void Footer (ostream &Outfile)
{
  Outfile << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << setw(35) << "|      END OF PROGRAM OUTPUT      |" << endl;
  Outfile << setw(35) << " --------------------------------- " << endl;
  Outfile << endl;
  return;
}

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
void push(double &dis)
{
  cout << "   Push - " << setw(12) << dis << " feet\n";
}

void rescued(ostream &Outfile)
{
	Outfile << "\nI have been rescued by Hercules - I am freed from this eternal punishment!\n\n";
	return;
}

void mustStartOver(ostream &Outfile)
{
	Outfile << "Oh No!  The rock rolled back down the hill!\nI have to walk down the hill and start all over.\nI have reached the bottom of the hill.\n\n";
	return;
}

void reachedTop(ostream &Outfile, int psh, int &cnt)
{
	Outfile << "\nSuccess! I reached the top of the hill for the " << cnt  << "th time! It only took " << psh << " pushes to get the boulder to the top\n\n";
	return;
	
}


void IMustToil(int &x)
{
  int counter=1;
	for(int i=0; i<x; i++)
 	{
	        double distance=0.0;
  		int pushes=0;
  		
  		cout << "I must forever toil to roll this boulder up the hill\n";
     
		while(distance < 100)
  	        {
		  double curr = (double)(rand()/((double)RAND_MAX/3.00));
	
			
			
		  if(distance+curr>100.0)
			{
			  curr= 100.0-distance;  						          //curr = distance - 100.0;
			  //distance = 100.0;
			  // distance= distance-curr;
			  //curr= 100-distance;
			  //distance=100;
			}
			distance+=curr;
			pushes++;
			push(curr);
		}
		
		reachedTop(cout, pushes, counter);
 		counter++;

		mustStartOver(cout);
  	}
	rescued(cout);
}



int main()
{
 
  int some;
  int seed;
  
  Header(cout);
  
  cout << "Enter a non-negative seed value: \n";
  cin >> seed;
  srand(seed);
  
  cout << "How long (enter an integer): \n";
  cin >> some;

  introduction(cout);

  IMustToil(some);

  Footer(cout);
  
}
