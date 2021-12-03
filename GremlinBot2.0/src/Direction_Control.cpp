#include "vex.h"

double Mfl;
double Mfr;
double Mbl;
double Mbr;

//https://www.desmos.com/calculator/dadgckbr1z

void Omni_Controller(double relativeAngle, double speed, double startAngle)
{
  //T finds Direction to move, R finds how much to prioritize rotation, and S finds speed
  double T = relativeAngle + M_PI/2;
  double R = angleDiffDir(angleDeg, startAngle) / 360;
  double S = speed/200;

  //Power of each diagonal
  double P1 = -cos(T + (M_PI/4));
  double P2 = sin(T + (M_PI/4));

  //Ratio for speed
  double Sr = std::max(std::abs(P1), std::abs(P2)) / S;

  //Motor power calculations
  Mfl = P2/Sr * (1-std::abs(R)) + R*S;
  Mfr = P1/Sr * (1-std::abs(R)) - R*S;
  Mbl = P1/Sr * (1-std::abs(R)) + R*S;
  Mbr = P2/Sr * (1-std::abs(R)) - R*S;

  //Scales power for motor rpm
  Mfl *= 200;
  Mfr *= 200;
  Mbl *= 200;
  Mbr *= 200;

}

double Omni_Rotation(double targetAngle)
{
  double dir = -1;
  if(sin(degToRadians(targetAngle) - angleRad) < 0)
    dir = 1;
  return dir * PIDcontrol.PID(angleDiff(angleDeg, targetAngle), 3, 0, 0, 0);
}

/*void XDrive_Correction()
{
  double prevL = 0;
  double prevR = 0;
  double prevS = 0;
  if(Controller1.Axis1.position() == 0)
  {
    double L = EncoderL.position(deg) - prevL;
    double R = EncoderR.position(deg) - prevR;
    double S = EncoderS.position(deg) - prevS;
    //Saves Encoder Values for next check
    prevL = EncoderL.position(deg);
    prevR = EncoderR.position(deg);
    prevS = EncoderS.position(deg);
    

  }


}*/