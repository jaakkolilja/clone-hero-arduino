// Tallennetaan nappien edelliset tilat
int lastStateG = LOW;
int lastStateR = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT); 
  pinMode(3, INPUT);
}

void loop() {
  // LUE VIHREÄ NAPPI (D2)
  int currentStateG = digitalRead(2);
  if (currentStateG != lastStateG) {
    if (currentStateG == HIGH) {
      Serial.println("G1"); // Painettu alas
    } else {
      Serial.println("G0"); // Päästetty ylös
    }
    lastStateG = currentStateG;
  }

  // LUE PUNAINEN NAPPI (D3)
  int currentStateR = digitalRead(3);
  if (currentStateR != lastStateR) {
    if (currentStateR == HIGH) {
      Serial.println("R1"); // Painettu alas
    } else {
      Serial.println("R0"); // Päästetty ylös
    }
    lastStateR = currentStateR;
  }
}