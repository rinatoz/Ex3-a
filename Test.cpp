#include "doctest.h"
#include "solver.hpp"
#include <stdexcept>
using namespace std;
using namespace solver;



TEST_CASE("Test cases for equations with degree of 1") {
    RealVariable x;
    CHECK(solve(2*x-4 == 10) == 7);
    CHECK(solve(0*x==0) == 0);
    CHECK(solve(5*x==10) == 2);
    CHECK(solve(x*2==10) == 5);   
    CHECK(solve(2*3*5*x==10+2) == 0.4);
    CHECK(solve(2*3*5*x*0==0) == 0);
    CHECK(solve(0*x==0) == 0);
    CHECK(solve(3*(2*x-1)==15) == 3);
    CHECK(solve(-2*(5*x-5)==20) == 10);
    CHECK(solve((3*x/3)==6) == 2);
    CHECK(solve((6*x/12)==12) == 24);
    CHECK(solve((8*x/4)==4)==8);
    CHECK(solve((32*x/8)==8) == 2);
    CHECK(solve(5*x-2==3) == 1);
    CHECK(solve(18*x-20+5==3) == 1);
    CHECK(solve(1*x-1+1==0) == 0);
    CHECK(solve(-15*x+13*x==2) == -1);
    CHECK(solve(9*x==90) == 10);
    CHECK(solve(7*x-2*x==30) == 6);
    CHECK(solve(1*x-12*x+3*x==16) == 2);
    CHECK(solve(x+3*x-2==0) == 0.5);
    CHECK(solve(x-2*x==10) == -10);
    CHECK(solve(13*x-x==13-13+12) == 1);
    CHECK(solve(x+15==-8) == -23 );
    CHECK(solve(1+x=-2-2*x) == -1);
    CHECK(solve(19*x==0) == 0);
    CHECK(solve(-1*x==5) == -5);
    CHECK(solve(4*(5-1*x)-4*(1*x+2)==10-9*x) == -2);
    CHECK(solve(x*(x+5)==3+x*(x+6)) == -3);
    CHECK(solve(x/3==54) == 162);
    CHECK(solve(x/10==1/8*(x+1)) == -5);
    CHECK(solve(x+x+x==9) == 3);
    CHECK(solve(3*x==9) == 3);
    CHECK(solve(7*x==28) == 4);
    CHECK(solve(-115*x+44-x+21==-4+13*x+8-9*x+1) == 0.5);
    CHECK(solve(-45*x+30+31*x==32+6*x+28) == -1);
    CHECK(solve(22+6*x+2==3*x+14+5*x) == 5);
    CHECK(solve(-10*x+5+x==6*x-9+29) == -1);
    CHECK(solve(10*x+8==4*x+44) == 6);
}
TEST_CASE("Test cases for equations with degree of 2") {
    RealVariable x;
    CHECK(solve((x^2)-36==0) == 6);
    CHECK(solve((x^2)==0) == 0);
    CHECK(solve((x^2)-16==0) == 4);
    CHECK(solve((x^2)-4==0) == 2);
    CHECK(solve((x^2)==0) == 0);
    CHECK(solve(2*(x^2)-8*x+2==-4) == 3);
    CHECK(solve((x^2)-7*x-13==-4*x-3) == -5);
    CHECK(solve((x^2)-6*x+27==4*x+2) == 5);
    CHECK(solve((x^2)==1) == 1);
    CHECK(solve((x^2)+8*x-45==-1*(x^2)+4*x+3) == -6);
    CHECK(solve((x^2)-6*x+5==-3) == 2);
    CHECK(solve(2*(x^2)-5==3) == 2);
    CHECK(solve((x^2)-x-5==1) == -2);
    CHECK(solve(2*(x^2)-33==-1) == 4);
    CHECK(solve(2*(x^2)-8*x+8==2) == 3);
    CHECK(solve(2*(x^2)-17*x+35==x-1) == 6);   
    
}

TEST_CASE("Testing for verious exceptions on equasions of degree 1: ")
{
    RealVariable x;    
    CHECK_THROWS(solve(0*x==5));
    CHECK_THROWS(solve(12*x-12*x==3));
    CHECK_THROWS(solve(19*x-20*x==100));
    CHECK_THROWS(solve(0*x==2));
    CHECK_THROWS(solve(x*0==2));
    CHECK_THROWS(solve(x*x==-5));
    CHECK_THROWS(solve(0*x+x*0==20));
    CHECK_THROWS(solve((x^2)-1==-20));
    CHECK_THROWS(solve(0*x==-5));
    CHECK_THROWS(solve(18*x-18*x==20));
    CHECK_THROWS(solve(0*x==0.20));
    CHECK_THROWS(solve(0*x==-19));
    CHECK_THROWS(solve(0*x==233464563455));
    CHECK_THROWS(solve(0*x==11.12));
    CHECK_THROWS(solve(0*x==1161719));
    CHECK_THROWS(solve(0*x==1+3));
    CHECK_THROWS(solve(0*x==-1-4-6+8));
    CHECK_THROWS(solve(0*x==-5*3));
    CHECK_THROWS(solve(0*x==3/3));
    CHECK_THROWS(solve(0*x==-3/(9*5)));
    CHECK_THROWS(solve(0*x==(-3/6*5)+(-3/6*5)));
    CHECK_THROWS(solve(0*x==5*5));
    CHECK_THROWS(solve(0*x==2-(-3)));    
    CHECK_THROWS(solve((0*x+0*x)==(-3/6*5)+(-3/6*5)));
    CHECK_THROWS(solve((0*x+0*x)==(-3/6*5)+(-3/2*5)));
}

TEST_CASE("Testing for verious exceptions on equasions of degree 1: ")
{
    RealVariable x;
    CHECK_THROWS(solve(0*(x^2)-36==0));
    CHECK_THROWS(solve((x^2)*0==1));
    CHECK_THROWS(solve(2*(x^2)-2*(x^2)==8));
    CHECK_THROWS(solve(2*(x^2)-2*(x^2)==(-3/6*5)+(-3/6*5)));
    CHECK_THROWS(solve(0*(x^2)-36==(-3/6*5)+(-3/6*5)));
    CHECK_THROWS(solve((x^2)*0==-1));
    CHECK_THROWS(solve((x^2)==-3/(9*5)));
    CHECK_THROWS(solve((x^2)==233464563455));
    CHECK_THROWS(solve((x^2)==-23345345));
    CHECK_THROWS(solve((x^2)==3/3));
}

TEST_CASE("Testing for verious occourences on equasions with complex numbers:")
{
ComplexVariable x;
CHECK(solve((x^4)==-16)==complex<double>(0,4));
CHECK(solve((x^4)==-16)==complex<double>(0,-4));
CHECK(solve((x^3)==-9)==complex<double>(0,3));
CHECK(solve((x^3)==-9)==complex<double>(0,-3));
CHECK(solve((x^5)==-25)==complex<double>(0,5));
CHECK(solve((x^5)==-25)==complex<double>(0,-5));
CHECK(solve((x^6)==-36)==complex<double>(0,6));
CHECK(solve((x^6)==-36)==complex<double>(0,-6));
CHECK(solve((x^7)==-49)==complex<double>(0,7));
CHECK(solve((x^7)==-49)==complex<double>(0,-7));
}