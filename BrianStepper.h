/*
  The sequence of control signals for 4 control wires is as follows:

  Step C0 C1 C2 C3
     1  1  0  1  0
     2  0  1  1  0
     3  0  1  0  1
     4  1  0  0  1
*/
#ifndef BrianStepper_h
#define BrianStepper_h

class BrianStepper 
{
  public:
    BrianStepper(int A, int Anot, int B, int Bnot); // BrianStepper constructor.
    void setDelay(long stepDelay); // modifies stepDelay.
    void step(int steps); // drives motor specified number of steps in certain direction. + = CW, - = CCW. 
	void setStep(int state_A, int  state_Anot, int state_B, int state_Bnot); // set step helper function used by BrianStepper::step.
  private:
    int steps;       // # of steps for call.
	long stepDelay;  // step delay inbetween each step.
	
    int A;	// coil A
    int Anot; // coil A not
    int B; // coil B
    int Bnot; // coil B not
};

#endif

