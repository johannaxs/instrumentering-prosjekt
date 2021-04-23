int red = 9;
int yellow = 10;
int green = 11;
int orange = 8;
int poeng=2;


//analog pins
int ORANGE_IN = 2;
int RED_IN = 3;
int YELLOW_IN = 4;
int GREEN_IN = 5;

int val_orange;
int val_green;
int val_yellow;
int val_red;

int dig_poeng=0; 
int dig_orange=0;
int dig_red=0;
int dig_green=0;
int dig_yellow=0;

int button = 12;
int button_read = 0;

const int seq=99;

int sequence[seq];

int points;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(ORANGE_IN, INPUT);
  pinMode(RED_IN, INPUT);
  pinMode(YELLOW_IN, INPUT);
  pinMode(GREEN_IN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button, INPUT);
  pinMode(poeng, OUTPUT);
  digitalWrite(poeng,LOW);

  randomSeed(analogRead(0));

 
  
  Serial.begin(9600); 
  
  
}

void loop(){



  
  if (button_read){
  
  
   points = 0;
   Serial.println("ON");

    digitalWrite(LED_BUILTIN, LOW);
  int guess[seq];
  for (int i=0; i<seq; i++) {
    guess[i]=5;

  Serial.print(guess[i]);
  
  }
  
  
 
   for (int i=0; i<seq; i++) {
    sequence[i]=random(4);
    Serial.print(sequence[i]);
    }


  delay(5000);


  
  
  for (int i = 0; i < seq; i++){

    
    val_orange = 0;
    val_green = 0;
    val_yellow = 0;
    val_red = 0;

  

    
    if (sequence[i] == 0){
      digitalWrite(orange, HIGH);
      delay(300);
      digitalWrite(orange, LOW);
    }
    if (sequence[i] == 1){
      digitalWrite(green, HIGH);
      delay(300);
      digitalWrite(green, LOW);
    }
    if (sequence[i] == 2){
      digitalWrite(yellow, HIGH);
      delay(300);
      digitalWrite(yellow, LOW);
    }
   if (sequence[i] == 3){
      digitalWrite(red, HIGH);
      delay(300);
      digitalWrite(red, LOW);
    }


    delay(600);
    
    /*val_orange = analogRead(ORANGE_IN);
    val_green =analogRead(GREEN_IN);
    val_yellow = analogRead(YELLOW_IN);
    val_red = analogRead(RED_IN);*/

    //delay(3000);
    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(300);
    //digitalWrite(LED_BUILTIN, LOW);

    val_orange = analogRead(ORANGE_IN); //
  if (val_orange>=1000) {
    dig_orange=1;
   }
  else {
    dig_orange=0; 
    //Serial.println("LOW"); 
  }

  val_green = analogRead(GREEN_IN); //
  if (val_green>=1000) {
    dig_green=1;
   }
  else {
    dig_green=0; 
    //Serial.println("LOW"); 
  }

  val_yellow = analogRead(YELLOW_IN); //
  if (val_yellow>=1000) {
    dig_yellow=1;
   }
  else {
    dig_yellow=0; 
    //Serial.println("LOW"); 
  }

  val_red = analogRead(RED_IN); //
  if (val_red>=1000) {
    dig_red=1;
   }
  else {
    dig_red=0; 
    //Serial.println("LOW"); 
  }



    if (dig_orange==1){
    guess[i] = 0;
    Serial.println("ORANGE");
    dig_orange == 0;
    }
    else if (dig_green==1){
    guess[i] = 1;
    Serial.println("GREEN");
    dig_green == 0;
    }
    else if (dig_yellow==1){
    guess[i] = 2;
    Serial.println("YELLOW");
    dig_yellow == 0;
    }
    else if (dig_red==1){
    guess[i] = 3;
    Serial.println("RED");
    dig_red == 0;
    }
    else {
    dig_orange = 0;
    dig_green = 0;
    dig_yellow = 0;
    dig_red = 0;};



    if (sequence[i] == guess[i]) {digitalWrite(poeng, HIGH);
      //points++;
      delay(500);
      digitalWrite(poeng, LOW);
      delay(500);
      }
      
    //else {points=points;
          //digitalWrite(poeng, LOW);};
    

}
    

Serial.print("Check results: ");
for (int i=0; i<seq; i++) {
  Serial.print(guess[i]);
}


  for (int i = 0; i < seq; i++){
    if (guess[i] == 0){
      analogWrite(orange, HIGH);
      delay(300);
      analogWrite(orange, LOW);
    }
    if (guess[i] == 1){
      analogWrite(green, HIGH);
      delay(300);
      analogWrite(green, LOW);
    }
    if (guess[i] == 2){
      analogWrite(yellow, HIGH);
      delay(300);
      analogWrite(yellow, LOW);
    }
    if (guess[i] == 3){
      analogWrite(red, HIGH);
      delay(300);
      analogWrite(red, LOW);
    }
    delay(500);

  }
  Serial.println("Points: ");
  Serial.print(points);
  
  
  }
  else Serial.println("OFF");
  button_read = digitalRead(button);
  delay(300);
}
