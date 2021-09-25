/*
   Juniper Robotics - Grow Tower Controller
*/

//define constants
#define pump_on_time 1  //on time in seconds
#define pump_off_time 3 //off time in seconds

//define varaibles
long currentMillis = 0, secondsMillis = 0, secondsCount = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  //configure LED on circuit board
}

void loop () {
  currentMillis = millis();
  if (currentMillis - secondsMillis >= 1000) {
    secondsMillis = currentMillis;
    if (secondsCount >= pump_off_time) {
      secondsCount = 0; //reset minute count to restart pump
    }
    if (secondsCount < pump_on_time) {
      digitalWrite(LED_BUILTIN, HIGH);  //turn pump on
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);  //turn pump off
    }
    secondsCount++;
  }
}
