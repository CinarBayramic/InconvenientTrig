//inconvenient trigonometry solution file
#define dn 0.0001

#include <math.h>
#include <iostream>
#include <unordered_map>
void helpfun(int argc,char**argv) {
    std::cout << "Available Arguments:\n"
    "HELP -> Displays this menu\n"
    "SIN <VAL(double)> -> Displays the sine of the second argument";
    "COS <VAL(double)> -> Displays the cosine of the second argument";
    "TAN <VAL(double)> -> Displays the tangent of the second argument";
    "ATAN <VAL(double)> -> Displays the arc tangent of the second argument";
    std::exit(0);
}
//void sinfun(int argc,char**argv) {
//    std::exit(0);
//}
void sinfun(int argc,char**argv) {
    std::cout << sin(std::stod(argv[2]));
    std::exit(0);
}
void cosfun(int argc,char**argv) {
    std::cout << cos(std::stod(argv[2]));
    std::exit(0);
}
void tanfun(int argc,char**argv) {
    std::cout << tan(std::stod(argv[2]));
    std::exit(0);
}
void arctanfun(int argc,char**argv) {
    double x = (std::stod(argv[2]));
    double sum = 0;
    for(double n = 0; n < x; n+=dn) {
      sum += (1/(1+n*n)) * dn;
    }
    std::cout << sum;
    std::exit(0);
}
int main(int argc,char**argv) {
  if(argc < 2) {
    std::cout << "at least a single argument needs to be specified\nFor more information run this program with the \"HELP\" command."<< argc  <<"\n";
    return 0;
  }
  std::unordered_map<std::string, void(*)(int argc,char**argv)> cmdfun = {
    {"HELP",helpfun},
    {"SIN",sinfun},
    {"COS",cosfun},
    {"TAN",tanfun},
    {"ATAN",arctanfun},
  };
  cmdfun[argv[1]](argc,argv);


  return 0;
}