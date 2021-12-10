#include "vex.h"

//Add fast pid that slows down fast at the end

double PIDClass::PID(double error, double kP, double kI, double kD, double integral_threshold) 
{
  double maxValue = 200;
  //Save the previous error for the derivative
	previous_error = error;

	//Begin summing the errors into the integral term if the error is below a threshold,
	//and reset it if not. This is to prevent the integral from growing too large.
	if(error < integral_threshold) {
		integral += error;
	}
	else {
		integral = 0;
	}

	//Calculate the derivative by finding the change between the current error and
	//last update's error
	derivative = error - previous_error;

	//Combine all the parts of the PID function into the PID algorithm and return the value.
  proportionalFinal = kP * error;
  integralFinal = kI * integral;
  derivativeFinal = kD * derivative;

  finalSpeed = numCutoff(proportionalFinal + integralFinal + derivativeFinal, maxValue);
  
  return finalSpeed;
}

