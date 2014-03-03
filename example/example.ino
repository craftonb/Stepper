#include <BrianStepper.h>
BrianStepper motor(0,1,2,3);

void setup()
{
  motor.setDelay(4);
}

void loop()
{
  motor.step(300);
  motor.step(-300);
}
