//inconvenient trigonometry solution file
#define dn 0.0001

#include <math.h>
#include <iostream>
#include <unordered_map>
double helpfun(int argc,char**argv,bool printout) {
    std::cout << "Available Arguments:\n"
    "HELP -> Displays this menu\n"
    "SIN <VAL(double)> -> Displays the sine of the second argument\n"
    "COS <VAL(double)> -> Displays the cosine of the second argument\n"
    "TAN <VAL(double)> -> Displays the tangent of the second argument\n"
    "ATAN <VAL(double)> -> Displays the arc tangent of the second argument\n"
    "SEC <VAL(double)> -> Displays the secant of the second argument\n";
    return 0;
}
//void sinfun(int argc,char**argv) {
//    std::exit(0);
//}
double sinfun(int argc,char**argv,bool printout) {
    double val = sin(std::stod(argv[2]));
    if(printout) {
    std::cout << val;
    }
    return val;
}
double cosfun(int argc,char**argv,bool printout) {
  double val = cos(std::stod(argv[2]));
  if(printout) {
  std::cout << val;
  }
  return val;
}
double tanfun(int argc,char**argv,bool printout) {
  double val = tan(std::stod(argv[2]));
  if(printout) {
  std::cout << val;
  }
  return val;
}
double arctanfun(int argc,char**argv,bool printout) {
    double x = (std::stod(argv[2]));
    double sum = 0;
    for(double n = 0; n < x; n+=dn) {
      sum += (1/(1+n*n)) * dn;
    }
    if(printout) {
    std::cout << sum;
    }
    return sum;
}
double secfun(int argc,char**argv,bool printout) {
  double val = 1/cosfun(argc,argv,false);  
  if(printout) {
  std::cout << val;
  }
  return val;
}
int main(int argc,char**argv) {
  if(argc < 2) {
    std::cout << "at least a single argument needs to be specified\nFor more information run this program with the \"HELP\" command."<< argc  <<"\n";
    return 0;
  }
  std::unordered_map<std::string, double(*)(int argc,char**argv,bool printout)> cmdfun = {
    {"HELP",helpfun},
    {"SIN",sinfun},
    {"COS",cosfun},
    {"TAN",tanfun},
    {"ATAN",arctanfun},
    {"SEC",secfun}
  };
  cmdfun[argv[1]](argc,argv,true);


  return 0;
}