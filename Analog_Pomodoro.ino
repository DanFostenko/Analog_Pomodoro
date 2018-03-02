/*
 * Pomodoro timer. Have a rest for 5 minutes after 20 minutes of work.
 * Analog fade of external LED.
 */

#define LED_PIN 9 // Define LED on 9th PWM pin
long int workTime = 1200000; // 20 Minutes = 1200000 Milliseconds, Time of work
const byte delayTime = 1; // 1 second = 1000 Milliseconds, Time of blink
int k = 0; // unsigned char k = 0; LED will work faster

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, LOW);
  delay(workTime); // Work

  long finishTime = 300000; // 5 Minutes = 300000 Milliseconds, declare local variable, time of rest
  for (long i = 0; i <= finishTime; i++) { // Rest
    for (k; k <=255; k++) { // Increase brightness
      analogWrite(LED_PIN, k);
      delay(delayTime);
    }
    for (k; k >= 0; k--) { // Decrease brightness
      analogWrite(LED_PIN, k);
      delay(delayTime);
    }
  finishTime = finishTime - (delayTime * 2 * 256);
  }
}