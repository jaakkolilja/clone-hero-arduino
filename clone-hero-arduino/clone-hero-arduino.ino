// Define the number of buttons and their pins
const int NUM_BUTTONS = 9;
const int buttonPins[NUM_BUTTONS] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

// Labels for the Python script (G=Green, R=Red, Y=Yellow, B=Blue, O=Orange, U=StrumUp, D=StrumDown, S=StarPower, X=Start)
const char* labels[NUM_BUTTONS] = {"G", "R", "Y", "B", "O", "U", "D", "S", "X"};

// Store the previous state of each button
int lastStates[NUM_BUTTONS];

void setup() {
  Serial.begin(115200);
  
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT);
    lastStates[i] = LOW;
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int currentState = digitalRead(buttonPins[i]);

    // Check if the button state has changed
    if (currentState != lastStates[i]) {
      // Send message, e.g., "G1" (Pressed) or "G0" (Released)
      Serial.print(labels[i]);
      if (currentState == HIGH) {
        Serial.println("1");
      } else {
        Serial.println("0");
      }
      
      lastStates[i] = currentState;
    }
  }
}