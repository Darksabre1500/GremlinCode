#include "vex.h"

//Starting conditions
const double Wl = 7;
const double Wr = 1.625;
const double startRot = degToRadians(90);
const double startX = 0;
const double startY = 0;

//Program variables
static double prevL = 0;
static double prevR = 0;
static double prevRot = startRot - M_PI/2;

double globalX = startX;
double globalY = startY;

double angleDeg = 90;
double angleDegUnwrapped;
double angleRad;
double angleRadUnwrapped;

//Add outfile

//---------------------Odometry Resources---------------------
//https://www.youtube.com/watch?v=_T6KHywSP58
//http://thepilons.ca/wp-content/uploads/2018/10/Tracking.pdf
//https://www.desmos.com/calculator/gdm0tikj1u
//https://www.desmos.com/calculator/kzog7lvqlu

void odometry()
{
  //Finds distance traveled since last check and converts it to inches
  double L = degToIn(EncoderL.position(deg) - prevL, 2.75);
  double R = degToIn(EncoderR.position(deg) - prevR, 2.75);
  //Saves Encoder Values for next check
  prevL = EncoderL.position(deg);
  prevR = EncoderR.position(deg);

  //Finds bot's angle of rotation
  double theta = (L-R)/(Wl+Wr);

  double dChord;

  if (theta != 0)
  {
    //Finds vector at the middle of the bot from starting position to ending position
    dChord = 2 * sin(theta/2) * (R/theta + Wr);    
  }
  else 
  {
    //Distance traveled in each direction
    dChord = (L+R)/2;
  }

  //Converts vectors to local x and y deltas
  double dlocalX = dChord * sin(prevRot + theta/2);
  double dlocalY = dChord * cos(prevRot + theta/2);

  //Adds deltas to previous global coordinates
  globalX += dlocalX;
  globalY += dlocalY;
  //Updates angle of rotation
  prevRot += theta;
}

void angleCalc()
{
  //Converts angle to have 0 on the x-axis and have counterclockwise be positive
  angleRadUnwrapped = -(prevRot - (M_PI/2));
  angleRad = angleWrap(angleRadUnwrapped, RADIANS);
  angleDegUnwrapped = radiansToDeg(angleRadUnwrapped);
  angleDeg = radiansToDeg(angleRad);
}