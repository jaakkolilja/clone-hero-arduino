const int NUM_BUTTONS = 9;
const int buttonPins[NUM_BUTTONS] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const char* labels[NUM_BUTTONS] = {"G", "R", "Y", "B", "O", "U", "D", "S", "X"};

int lastStates[NUM_BUTTONS];
unsigned long lastDebounceTime[NUM_BUTTONS]; // Tallentaa jokaisen napin oman ajan
const unsigned long DEBOUNCE_DELAY = 10;     // 10ms on nyt turvallinen

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT); // Kytkentäkaavion mukaiset ulkoiset vastukset
    lastStates[i] = LOW;
    lastDebounceTime[i] = 0;
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int currentState = digitalRead(buttonPins[i]);

    // Tarkistetaan onko tila muuttunut JA onko edellisestä muutoksesta kulunut tarpeeksi aikaa
    if (currentState != lastStates[i] && (millis() - lastDebounceTime[i] > DEBOUNCE_DELAY)) {
      Serial.print(labels[i]);
      Serial.println(currentState);
      
      lastStates[i] = currentState;
      lastDebounceTime[i] = millis(); // Päivitetään viimeisin muutosajankohta
    }
  }
}