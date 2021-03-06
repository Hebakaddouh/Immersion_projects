#include <Adafruit_NeoPixel.h>

/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com
*********/

// TCS230 or TCS3200 pins wiring to Arduino
#define S0 6
#define S1 5
#define S2 4
#define S3 3
#define sensorOut 2
#define LED 13
#define BLED 12


// Stores frequency read by the photodiodes
/*int W1 = 0;
int W2 = 0;
int W3 = 0;
int B1 = 0;
int B2 = 0;
int B3 = 0;*/
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int white = 0;
int blue = 0;
int red = 0;
int green = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, BLED, NEO_GRB + NEO_KHZ800);


void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(LED, OUTPUT);


  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  strip.begin();
  strip.show();
  // Begins serial communication
  Serial.begin(9600);

}

void loop() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  //red = map(redFrequency,607 ,B1 ,255 ,0);
  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  //green = map(redFrequency,W2 ,B2 ,255 ,0);

  // Printing the GREEN (G) value
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  //blue = map(redFrequency, W3 ,B3 ,255 ,0);
  // Printing the BLUE (B) value
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  delay(100);


  for (int j = 0; j<60;j++)
  {
    strip.setPixelColor(j,redFrequency , greenFrequency ,blueFrequency);
  }
  strip.show();

  if (redFrequency < greenFrequency && redFrequency < blueFrequency) {
    Serial.println(" - RED detected!");
  }
  if (greenFrequency < redFrequency && greenFrequency < blueFrequency) {
    Serial.println(" - GREEN detected!");
  }
  if (blueFrequency < redFrequency && blueFrequency < greenFrequency) {
    Serial.println(" - BLUE detected!");
  }
}
