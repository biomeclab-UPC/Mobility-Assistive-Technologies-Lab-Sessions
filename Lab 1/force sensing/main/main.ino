#define MS2S 0.000001f // from microsecond to seconds

//Time measurements
float delta_time = 0.0;
float current_time = micros();
float past_time = micros();

// Variable to enable control loop
volatile byte enable_force_sensing = false;

void setup() {
  Serial.begin(9600);
  LoadMenuUI(); // Load Serial User Interface
}

void loop() {
  // Update TimeStamp
  current_time = micros();
  delta_time = (current_time - past_time)*MS2S;
  past_time = current_time;

  // Check User Commands
  CheckKeyboard();
  
  // Apply control law if the flag enable_control_loop is enabled
  if(enable_force_sensing){
    // Read Load Cell
   float interaction_torque = ReadLoadCell();

    // Print data in the serial monitor
    Serial.print(delta_time); Serial.print(", ");
    Serial.println(interaction_torque);
  }
}
