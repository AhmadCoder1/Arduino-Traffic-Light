// Pin assignment for LEDs
const int RED_PIN = 4;
const int YELLOW_PIN = 5;
const int GREEN_PIN = 6;

// Define traffic light states
enum TrafficLightState { RED, RED_YELLOW, GREEN, YELLOW };
TrafficLightState currentState = RED;

// Timing for each state (in milliseconds)
const unsigned long RED_DURATION = 5000;        // 5 sec
const unsigned long RED_YELLOW_DURATION = 2000; // 2 sec
const unsigned long GREEN_DURATION = 5000;      // 5 sec
const unsigned long YELLOW_DURATION = 2000;     // 2 sec

unsigned long stateStartTime = 0; // Tracks when current state started

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  // Start with RED
  currentState = RED;
  stateStartTime = millis();
  updateLights();
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - stateStartTime;

  switch(currentState) {
    case RED:
      if (elapsed >= RED_DURATION) {
        currentState = RED_YELLOW;
        stateStartTime = currentTime;
        updateLights();
      }
      break;

    case RED_YELLOW:
      if (elapsed >= RED_YELLOW_DURATION) {
        currentState = GREEN;
        stateStartTime = currentTime;
        updateLights();
      }
      break;

    case GREEN:
      if (elapsed >= GREEN_DURATION) {
        currentState = YELLOW;
        stateStartTime = currentTime;
        updateLights();
      }
      break;

    case YELLOW:
      if (elapsed >= YELLOW_DURATION) {
        currentState = RED;
        stateStartTime = currentTime;
        updateLights();
      }
      break;
  }
}

// Update LED outputs based on current state
void updateLights() {
  switch(currentState) {
    case RED:
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      break;

    case RED_YELLOW:
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      break;

    case GREEN:
      digitalWrite(RED_PIN, LOW);
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      break;

    case YELLOW:
      digitalWrite(RED_PIN, LOW);
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      break;
  }
}
