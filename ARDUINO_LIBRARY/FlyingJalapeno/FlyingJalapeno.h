
#ifndef FlyingJalapeno_h
#define FlyingJalapeno_h

#include "Arduino.h"

//These are the four LEDs on the test jig
//Setting these pins high turn on a given LED
#define LED_PT_PASS 43 //PT = Pre-test
#define LED_PT_FAIL 42 
#define LED_PASS 41
#define LED_FAIL 40

class FlyingJalapeno
{
  public:
    FlyingJalapeno(int statLED);

	boolean verify_voltage(int pin, float correct_val, float allowance_percent, boolean debug); //Returns true if pin voltage is within a given window of the value we are looking for
	boolean verify_value(int input_value, int correct_val, float allowance_percent);

	boolean powerTest(byte select);

	void setV1(boolean on, float voltage); //Set board voltage 1 (5 or 3.3V)
	void setV2(boolean on, float voltage); //Set board voltage 2 (3.3, 3.7, 4.2, or 5V)

	void enablePCA(void);
	void disablePCA(void);

    void dot();
    void dash();
  private:
    int _statLED;
};

#endif