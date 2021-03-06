#include <iostream>
#include "tmat3.h"
#include "tmat4.h"

using namespace std;
//using namespace idwTest;
using namespace lwtv;

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void
tvecTest()
{
  cout<<"*************** test tvec3 *********************"<<endl;
  cout<<"\nconstructors:"<<endl;
  tvec3<double> A;
  tvec3<double> B(.1,.2,.3);
  tvec3<double> C(.4);
  tvec3<double> D(B);
  cout <<A<<", "<<B<<", "<<C<<", "<<D<<endl;
 //-------------------------------------
   cout<<"\nAssignment operators:"<<endl;
  A = 1.2345;
  B = C;
  cout <<A<<", "<<B<<", "<<C<<endl;
  A = 1;
  B= .1;
  A += B;
  cout <<A<<", "<<B<<endl;
  A -= B;
  cout <<A<<", "<<B<<endl;
  A *= 2;
  B /= 2;
  C = 3;
  C[1] = .3;
  D.set(10,9,8);
  cout <<A<<", "<<B<<", "<<C<<", "<<D<<endl;
 //-------------------------------------
   cout<<"\nvector to vector operators:"<<endl;
  A = B = C = D = .25;
  A = B + C;
  B = A - D;
  C = A * B;
  D = A / B;
  tvec3<double> E;
  E = -D;
  cout <<A<<", "<<B<<", "<<C<<", "<<D<<", "<<E<<endl;
 //-------------------------------------
   cout<<"\nvector to digit operators:"<<endl;
  A = B = C = D = E =1.5;
  A = C + .1;
  B = .1 + C;
  C = A - -1;
  D = .1 - A;
  cout <<A<<", "<<B<<", "<<C<<", "<<D<<endl;
  A = B = C = D = E =1.5;
  A = C * 2;
  B = 2 * C;
  C = E / 2;
  D = 2 / E;
  cout <<A<<", "<<B<<", "<<C<<", "<<D<<endl;
  //-------------------------------------
  cout<<"\nequality:"<<endl;
  A = B = C = 1;
  D = E = 2;
  if(A==B)cout<<"a == b"<<endl;
  if(A==E)cout<<"SHOULD NOT PRINT"<<endl;
  if(A!=E)cout<<"a != e"<<endl;
  if(A!=B)cout<<"SHOULD NOT PRINT"<<endl;
  //-------------------------------------
  cout<<"\nutility functions:"<<endl;
  A = 1;
  B = A.normalized() * 2;
  cout<<A<<" "<< B.length2()<<" and "<<B.length()<<endl;
  A.normalize();
  cout<<A<<endl;
  A = 1;
  B = 1;
  B[1] = .5;
  C = A.cross(B);
  // dot should be 2.5, cross should be (.5,0,-.5)
  cout <<"dot: "<<A.dot(B)<<" cross:"<<C<<endl;
}

void
tmat3Test(){
  cout<<"\n\n*************** test tmat3 *********************"<<endl;
  tmat3<double> A;
  tmat3<double> B;
  tmat3<double> C;
  tmat3<double> D;
  //-------------------------------------
  cout<<"\nAssignment operators:"<<endl;
  A[7] = 3.141;
  A(1,2) = 2.718;
  tmat3<double> E(A);
  B = A;
  C -= A;
  D += A;
  cout <<A<<", \n"<<B<<", \n"<<C<<", \n"<<D<<", \n"<<E<<endl;
  A *= 2;
  B /= 2;
  cout <<"m/s:"<<A<<", \n"<<B<<endl;
  //-------------------------------------
  cout<<"\nmatrix3 scalar operators:"<<endl;
  B = A * .5;
  C = A / 2;
  cout <<A<<", \n"<<B<<", \n"<<C<<endl;
  //-------------------------------------
  cout<<"\nmatrix3 vector operators:"<<endl;
  A.identity();
  A(0,0)= .7071;
  A(0,2)=-.7071;
  A(2,0)= .7071;
  A(2,2)= .7071;
  tvec3<double> VA(1,0,0);
  tvec3<double> VB, VC;
  VB = A * VA;// A is a 45 degree turn around the Y axis
  cout <<A<<",\n"<<VA<<" "<<VB<<endl;
  //-------------------------------------
  cout<<"\nmatrix3 matrix3 operators:"<<endl;
  cout <<"starts off: "<<B<<C<<D<<endl;
  A = B + C;
  B = C + D;
  E = A * B;
  cout <<"results:\n"<<A<<", \n"<<B<<", \n"<<C<<", \n"<<D<<", \n"<<E<<endl;
  //-------------------------------------
  cout<<"\nequality functions:"<<endl;
  A.identity();
  B.identity();
  if(A==B)cout<<"good result"<<endl;
  if(A==C)cout<<"bad result"<<endl;
  if(A!=B)cout<<"bad result"<<endl;
  if(A!=C)cout<<"good result"<<endl;
  //-------------------------------------
  cout<<"\naccessor functions:"<<endl;
  VA.set(1,2,3);
  VB.set(4,5,6);
  VC.set(7,8,9);
  A.set(VA,VB,VC);
  B.setRow(1, VB);
  VA = A.getRow(2);
  cout <<"results:"<<A<<", \n"<<B<<",  "<<VA<<endl;
  //-------------------------------------
  cout<<"\nutility functions:"<<endl;
  B.identity();
  C.identity();
  tvec3<double> axis(0,1,0);
  C.rotate(axis, (45.0*M_PI/180.0));
  A.transpose();
  double det =  D.determinant();
  cout <<"results:\n"<<A<<", \n"<<B<<", \n"<<C<<", \n"<<D<<", \n"<<det<<endl;
}

void
tmat4Test(){
  cout<<"\n\n*************** test tmat4 *********************"<<endl;
  tmat4<double> A;
  tmat4<double> B(3.14);
  tmat4<double> C(B);
  tmat4<double> D, E, F, G, H;
  //-------------------------------------
  cout<<"\nAssignment operators:"<<endl;
  A[3] = 3.141;
  A(1,3) = 2.718;
  D = A;
  E -= A;
  F += A;
  G *= 2;
  H /= 2;
  cout <<A<<", \n"<<B<<", \n"<<C<<", \n"<<D<<", \n"<<E<<", \n"<<F<<", \n"<<G<<", \n"<<H<<endl;
  //-------------------------------------
  cout<<"\nmatrix4 scalar operators:"<<endl;
  B = A * .5;
  C = A / 2;
  cout <<A<<", \n"<<B<<", \n"<<C<<endl;
  //-------------------------------------
  cout<<"\nmatrix4 vector operators:"<<endl;
  A.identity();
  A(0,0)= .7071;
  A(0,2)=-.7071;
  A(2,0)= .7071;
  A(2,2)= .7071;
  H = A;
  tvec3<double> VA(1,0,0);
  tvec3<double> VB;
  VB = A * VA;// A is a 45 degree turn around the Y axis
  cout <<A<<",\n"<<VA<<" "<<VB<<endl;
  //-------------------------------------
  cout<<"\nmatrix4 matrix4 operators:"<<endl;
  cout <<"starts off: "<<B<<C<<D<<endl;
  A = B + C;
  B = C - D;
  E = A * B;
  cout <<"results:\n"<<A<<", \n"<<B<<", \n"<<C<<", \n"<<D<<", \n"<<E<<endl;
  //-------------------------------------
  cout<<"\nequality functions:"<<endl;
  A.identity();
  B.identity();
  if(A==B)cout<<"good result"<<endl;
  if(A==C)cout<<"bad result"<<endl;
  if(A!=B)cout<<"bad result"<<endl;
  if(A!=C)cout<<"good result"<<endl;
  //-------------------------------------
  cout<<"\naccessor functions:"<<endl;
  A.set(C);
  VA.set(1.2,2.3,3.4);
  B.setVecRow(2,VA);
  cout <<"results:\n"<<A<<" \n"<<B<<endl;
  //-------------------------------------
  cout<<"\nutility functions:"<<endl;
  A.identity();
  F.identity();
  G.identity();
  H.identity();
  VA.set(0,1,0);
  F.rotate(VA, (45.0*M_PI/180.0));
  VA.set(1.2,2.3,3.4);
  G.translate(VA);
  H=F;
  VA.set(2,4,6);
  H.scale(VA);
  B(0,2) = .12345;
  B.transpose();
  double det = C.determinant();
  D.identity();
  D(0,0)= .7071;
  D(0,2)=-.7071;
  D(2,0)= .7071;
  D(2,2)= .7071;
  E = D.inverse();// WAAA!!!! this looks broken. :'(
  cout <<"results:\n"<<A<<", \n"<<B<<", \n"<<det<<", \n"<<D<<", \n"<<E<<", \n"<<F<<", \n"<<G<<", \n"<<H<<endl;
  cout<<"\n\nand:\n"<<endl;
  A.identity();
  A.rotate(tvec3<double>(1,0,0),(5.0*M_PI/180.0));
  //cout<<"\nA!"<<A<<endl;
  //B.setRotation(tvec3<double>(1,0,0),(5.0*M_PI/180.0));
  //C.identity();
  //D = C *B;
  //cout<<"\nD"<<D<<endl;
  A.rotate(tvec3<double>(0,1,0),(10.0*M_PI/180.0));
  //A.rotate(tvec3<double>(0,0,1),(3.0*M_PI/180.0));
  tvec3<double> Trans, Rot, Scl;
  A.extract(Trans,Rot,Scl);
  cout<<"extracted:"<<A<<"\n\n"<<Trans<<", "<<Rot*(180/M_PI)<<", "<<Scl<<endl;
  B.identity();
  B.rotate(tvec3<double>((5.0*M_PI/180.0),(10.0*M_PI/180.0),(20.0*M_PI/180.0)));
  B.scale(tvec3<double>(2,3,4));
  B.extract(Trans,Rot,Scl);
  cout<<"B extracted:"<<B<<"\n\n"<<Trans<<", "<<Rot*(180/M_PI)<<", "<<Scl<<endl;

  C.identity();
  C.scale(tvec3<double>(2,3,4));
  C.rotate(tvec3<double>((-5.0*M_PI/180.0),(-10.0*M_PI/180.0),(-20.0*M_PI/180.0)));
  //C.scale(tvec3<double>(2,3,4));
  C.extract(Trans,Rot,Scl);
  cout<<"C extracted:"<<C<<"\n\n"<<Trans<<", "<<Rot*(180/M_PI)<<", "<<Scl<<endl;

  D.identity();
  D.rotate(tvec3<double>((0*M_PI/180.0),(0.0*M_PI/180.0),(-90.0*M_PI/180.0)));
  D.scale(tvec3<double>(2,3,4));
  D.extract(Trans,Rot,Scl);
  cout<<"D extracted:"<<D<<"\n\n"<<Trans<<", "<<Rot*(180/M_PI)<<", "<<Scl<<endl;

}

int main()
{
  tvecTest();
  tmat3Test();
  tmat4Test();
  return 0;
}

//Copyright 2019 Ivan DeWolf
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
