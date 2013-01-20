#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include "random.h"

using namespace std;

int main(int argc,char *argv[])
{
  //Read number of random numbers to generate and number of bins from
  //command line.
  if (argc!=4) {
    cout << "Usage: metrop seed step_size N_iter\n";
    return 1;
  }
  double seed=atof(argv[1]);
  double step=atof(argv[2]);
  int N=atoi(argv[3]);

  double x=seed;
  double y;
  ofstream fout("output.txt");
  for (int i=0; i<N; i++) {
    fout << x << "\n";
    //Let y be a random variable in [x-step,x+step).
    y=x+step*(2.0*ran3()-1.0);
    //If |y|<=|x| then accept (i.e. update x to be equal to y).
    if (fabs(y)<=fabs(x)) {
      x=y;
      continue;
    }
    //If |y|>|x| then accept with probability exp(-y^2/2)/exp(-x^2/2).
    if ( ran3()<exp(-(y*y-x*x)/2.0) )
      x=y;
  }
  fout.close();
  
  return 0;
}
