#include <FastLED.h>
#include <avr/sleep.h>


#define LED_PIN 2
#define NUM_LEDS 300
#define interruptPin 3

CRGB leds[NUM_LEDS];
bool LEDSSET = false;

void setup() 
{
  pinMode(3, INPUT);     
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811,LED_PIN, RGB>(leds,NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
  FastLED.clear();
  FastLED.show();
  attachInterrupt(digitalPinToInterrupt(interruptPin), setLeds, RISING);
}

void setLeds()
{
  if(LEDSSET==false){
    LEDSSET=true;
  //detachInterrupt(digitalPinToInterrupt(interruptPin));
  FastLED.setBrightness(60);
  for (int i=0 ; i<151; i=i+2)
  {
    leds[i] = CRGB(0,255,0); // Red // grb 255,105,180
    leds[300-i] = CRGB(0,255,0); // Red // grb 255,105,180
    delay(5);
    FastLED.show();
    leds[i+1] = CRGB(255,0,0); // Green
    leds[300-i+1] = CRGB(255,0,0); // Red // grb 255,105,180
    delay(5);
    FastLED.show();
  }
  while(digitalRead(3)==HIGH)
  {
      delay(5000);
  }
  delay(5000);

    for(int i=0; i<60; i++)
    { 
      FastLED.setBrightness(60-i);
      FastLED.show();
      delay(10);
    }
     FastLED.clear();
     FastLED.show();
    delay(1000);
  }
  else LEDSSET = false;
  //attachInterrupt(digitalPinToInterrupt(), setLeds, RISING);  
}


//Old_Loop Based code
void old_loop() 
{
//RED GREEN BLUE

//if(digitalRead(3)==HIGH)
//{
//  LEDSSET=true;
//  FastLED.setBrightness(60);
//  for (int i=0 ; i<100; i=i+2)
//  {
//    leds[i] = CRGB(0,255,0); // Red
//    delay(20);
//    FastLED.show();
//    leds[i+1] = CRGB(255,0,0); // Green
//    delay(20);
//    FastLED.show();
//  }
//
//    delay(1000);
// }
//  else
//  {
//    for(int i=0; i<60; i++)
//    { 
//      if(!LEDSSET)break;
//      FastLED.setBrightness(60-i);
//      FastLED.show();
//      delay(10);
//    }
//     FastLED.clear();
//     FastLED.show();
//    if(!LEDSSET) delay(1000);
//    LEDSSET=false;
//  }

//digitalWrite(LED_PIN,HIGH);


}
