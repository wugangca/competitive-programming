/*
greedy algorithm. provide units to the morst restricted types first.
*/

int distribute(int& patient, int& unit) {
  int total = 0;
  if (patient >= unit) {
    // more patients than unit
    total = unit;     // use all  units
    patient -= unit;  // remaining patients
    unit = 0;
  } else {
    // more unit than patient
    total = patient;
    unit -= patient;
    patient = 0;
  }
  return total;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int negativeOUnit, positiveOUnit;
  int negativeAUnit, positiveAUnit;
  int negativeBUnit, positiveBUnit;
  int negativeABUnit, positiveABUnit;
  cin >> negativeOUnit >> positiveOUnit >> negativeAUnit >> positiveAUnit >>
      negativeBUnit >> positiveBUnit >> negativeABUnit >> positiveABUnit;

  int negativeO, positiveO;
  int negativeA, positiveA;
  int negativeB, positiveB;
  int negativeAB, positiveAB;
  cin >> negativeO >> positiveO >> negativeA >> positiveA >> negativeB >>
      positiveB >> negativeAB >> positiveAB;

  int total = 0;

  // AB+: accept any type +/=,
  // AB-: accept any - type
  // A+:  accept A+, A-, O+, O-

  // distribute positiveABUnit
  total += distribute(positiveABUnit, positiveAB);

  // distribute negativeABUnit
  total += distribute(negativeABUnit, negativeAB);
  total += distribute(negativeABUnit, positiveAB);


  // distribute positiveBUnit
  total += distribute(positiveBUnit, positiveB);
  total += distribute(positiveBUnit, positiveAB);

  // distribute negativeBUnit
  total += distribute(negativeBUnit, negativeB);
  total += distribute(negativeBUnit, positiveB);
  total += distribute(negativeBUnit, negativeAB);
  total += distribute(negativeBUnit, positiveAB);

  // distribute positiveAUnit
  total += distribute(positiveAUnit, positiveA);
  total += distribute(positiveAUnit, positiveAB);

  // distribute negativeAUnit
  total += distribute(negativeAUnit, negativeA);
  total += distribute(negativeAUnit, positiveA);
  total += distribute(negativeAUnit, negativeAB);
  total += distribute(negativeAUnit, positiveAB);


  // distribute positiveOUnit
  total += distribute(positiveOUnit, positiveO);
  total += distribute(positiveOUnit, positiveB);
  total += distribute(positiveOUnit, positiveA);
  total += distribute(positiveOUnit, positiveAB);

  // distribute negativeOUnit
  total += distribute(negativeOUnit, negativeO);
  total += distribute(negativeOUnit, positiveO);
  total += distribute(negativeOUnit, negativeB);
  total += distribute(negativeOUnit, positiveB);
  total += distribute(negativeOUnit, negativeA);
  total += distribute(negativeOUnit, positiveA);
  total += distribute(negativeOUnit, negativeAB);
  total += distribute(negativeOUnit, positiveAB);

  cout << total;
}