#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_GAMEPAD, 12, 0,
  true, true, false, false, false, false,
  false, false, false, false, false);

class Button
{
  public:
  int buttonPin = NULL;
  int lastButtonState = 0;
  
  Button(int pin)
  {
    buttonPin = pin;
  }
  
};

void setup() {
 
 Serial.begin(9600);
 
 int pins[12] = {2,3,4,5,6,7,8,9,10,16,14,15};
 for(int i=0 ; i<12 ;i++)
 {
  pinMode(pins[i], INPUT_PULLUP);
 }

 Joystick.begin();
 Joystick.setXAxisRange(-512, 512);
 Joystick.setYAxisRange(-512, 512);
}

Button gumbi[12] ={2,3,4,5,6,7,8,9,10,16,14,15};

int joyPinX = 3;
int joyPinY = 2;




void loop() {

  Joystick.setXAxis(analogRead(joyPinX) - 512);
  Joystick.setYAxis(analogRead(joyPinY) - 512);


  // Read pin values
  for (int index = 0; index < 12; index++)
  {
    int currentButtonState = !digitalRead(gumbi[index].buttonPin);
    
    if (currentButtonState != gumbi[index].lastButtonState)
    {
      Joystick.setButton(index, currentButtonState);
      gumbi[index].lastButtonState = currentButtonState;
    }
  }
}

