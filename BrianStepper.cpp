/*  
  Step C0 C1 C2 C3
     1  1  0  1  0
     2  0  1  1  0
     3  0  1  0  1
     4  1  0  0  1
 */

#include "Arduino.h"
#include "BrianStepper.h"

BrianStepper::BrianStepper(int A, int Anot, int B, int Bnot) // BrianStepper constructor
{
  //assigning values in class to given parameters. 
  this->A = A;			
  this->Anot = Anot;
  this->B = B;
  this->Bnot = Bnot;

  // setting up pins for stepper control.
  pinMode(this->A, OUTPUT);
  pinMode(this->Anot, OUTPUT);
  pinMode(this->B, OUTPUT);
  pinMode(this->Bnot, OUTPUT);
  
  this->stepDelay = 5; // 5 is default value.
}

void BrianStepper::setDelay(long stepDelay) // modifies stepDelay.
{
  this->stepDelay = stepDelay;
}

void BrianStepper::step(int steps) // drives motor specified number of steps in certain direction. + = CW, - = CCW. 
{  
	this->steps = steps; //assigning value in class to given parameter.
	int direction = 1; // assume cw
	if(this->steps < 0) // if not, then backwards
		direction = -1; // direction = ccw
	
	if(direction == 1) // cw
	{
		int i;
		for(i=0;i<=this->steps;i++) // step until # of steps is reached.
		{
			setStep(1,0,1,0);
    		delay(this->stepDelay);
    		setStep(0,1,1,0);
    		delay(this->stepDelay);
    		setStep(0,1,0,1);
    		delay(this->stepDelay);
    		setStep(1,0,0,1);
    		delay(this->stepDelay);
		}
	}
	if(direction == -1) // ccw
	{
		int i;
		for(i=0;i<=abs(this->steps);i++) // step until # of steps is reached. use abs() because in this case the number of steps would be negative.
		{
			setStep(1,0,0,1);
    		delay(this->stepDelay);
    		setStep(0,1,0,1);
    		delay(this->stepDelay);
    		setStep(0,1,1,0);
    		delay(this->stepDelay);
    		setStep(1,0,1,0);
    		delay(this->stepDelay);
		}
	}
}

void BrianStepper::setStep(int state_A, int  state_Anot, int state_B, int state_Bnot) // set step helper function used by BrianStepper::step.
{
	digitalWrite(this->A, state_A);
  	digitalWrite(this->Anot, state_Anot);
  	digitalWrite(this->B, state_B);
  	digitalWrite(this->Bnot, state_Bnot);
}
