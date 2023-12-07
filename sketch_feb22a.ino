



/*
 PROJECT: Ardroid
 CODED BY: Anurag Goel
 PUBLIC Licence Free To Modify
 */

#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define DIV_CMD_CHAR '|'
#define CMD_DIGITALWRITE 10
#define CMD_ANALOGWRITE 11
#define CMD_TEXT 12
#define CMD_READ_ARDROID 13
#define MAX_COMMAND 20  
#define MIN_COMMAND 10  
#define IN_STRING_LENGHT 40
#define MAX_ANALOGWRITE 255
#define PIN_HIGH 3
#define PIN_LOW 2


int r = 11;
int g = 10;
int b = 9;
int pin_num = 0;
int pin_value= 0;
int k = 255;
int c = 0;


String inText;

int d8 = 0;
int d9 = 0;
int d10 = 0;
int d11 = 0;
int d12 = 0;
int d13 = 0;
int d14 = 0;

int p = 0;
int o = 255;
int container = 0;
int m; //Speed of the impulse
int delayOn; // Dealy of the impulse on
int delayOff; // Delay of the impulse down

void setup() {
  Serial.begin(9600);
  Serial.println("Ardroid By : Anurag Goel");
  Serial.flush();
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
}

void loop()
{

  Serial.flush();
  int ard_command = 0;
  
  char get_char = ' ';  //read serial

  // wait for incoming data
  if (Serial.available() > 0) {
    // parse incoming command start flag 
    //Serial.println("<");
    get_char = Serial.read();
    //Serial.println(">");
    if (get_char == START_CMD_CHAR) {
      // parse incoming command type
      ard_command = Serial.parseInt(); // read the command
      // parse incoming pin# and value  
      pin_num = Serial.parseInt(); // read the pin
      pin_value = Serial.parseInt();  // read the value
      // 1) GET TEXT COMMAND FROM ARDROID
      if (ard_command == CMD_TEXT){   
        inText =""; //clears variable for new input   
        while (Serial.available())  {
          char c = Serial.read();

          //gets one byte from serial buffer
          delay(5);
          if (c == END_CMD_CHAR) { // if we the complete string has been read
            // add your code here
            Serial.println(inText);
            break;
          } 
          else {
            if (c !=  DIV_CMD_CHAR) {
              inText += c; 
              delay(5);
            }
          }
        }
      }
    }
  }
  

  // 2) GET digitalWrite DATA FROM ARDROID
  if (ard_command == CMD_DIGITALWRITE){  
    
    if (pin_value == PIN_LOW) { 
      pin_value = LOW; 
    } else {
      if (pin_value == PIN_HIGH) pin_value = HIGH;
      else return; // error in pin value. return. 
    }
    set_digitalwrite( pin_num,  pin_value);  
    
    if(pin_num == 8){
      d8 == pin_value;
    }
    if(pin_num == 9){
      d9 = pin_value;
    }
    if(pin_num == 10){
      d10 = pin_value;
    }
    if(pin_num == 11){
      d11 = pin_value;
    }
    if(pin_num == 12){
      d12 = pin_value;
    }
    if(pin_num==13) {
      d13 = pin_value;
    }
    if(pin_num == 14){
      d14 = pin_value;
    }
    return;  // return from start of loop()
  }

  // 3) GET analogWrite DATA FROM ARDROID
  if (ard_command == CMD_ANALOGWRITE) {  
    //Serial.println("CMD_ANALOGWRITE");
    analogWrite(  pin_num, pin_value ); 
    // add your code hereu
    return;  // Done. return to loop();
  }

  // 4) SEND DATA TO ARDROID
  if (ard_command == CMD_READ_ARDROID) { 
    //    char send_to_android[] = "Place your text here." ;
    //    Serial.println(send_to_android);   // Example: Sending text
    //Serial.print(" Analog 0 = "); 
    //Serial.println(analogRead(A0));  // Example: Read and send Analog pin value to Arduino
    return;  // Done. return to loop();
  }
  if(pin_num == 8 && pin_value == 1){
      m = 30;
      if(c == 0){
        int ha = 254;
         int h = 0;
         while(ha >= 0){
           analogWrite(b,ha);
           analogWrite(r,h);
           ha--;
           h++;
           delay(m);
        }   
    } 
  
    if(c == 1){
      int ha = 254;
      int h = 0;
      while(ha >= 0){
        analogWrite(r,ha);
        analogWrite(g,h);
        ha--;
        h++;
        delay(m);
      } 
    }
  
    if(c == 2){
      int ha = 254;
      int h = 0;
      while(ha >= 0){
        analogWrite(g,ha);
        analogWrite(b,h);
        ha--;
        h++;
        delay(m);
      } 
    }
   reset();
 } 
  if(d9 == 1){ 
    RussianHardBass();
    reset();
  }
  if(d10 == 1){
    impulse();
    reset();
  }
  if(d11 == 1){
    GanstaRap();
    reset();
  }
  if(d12 == 1){
    Thunderstorm();
    reset(); 
  }
  if(d13 == 1) {
    p = 0;
    o = 255;
    func_13(ard_command ,get_char ,pin_num, pin_value);
    reset();   
  }
  if(d14 == 1){
    police();
    reset();
  }
  if (container < 6){
    container++;
  }
  if(container == 6){
    container = 0;
  }
  
  if(c <=2){c++;}
  if(c ==3){c = 0;} 
  
  if(pin_num == 8 && pin_value == 0){
    reset();
  }
}

// 2a) select the requested pin# for DigitalWrite action
void set_digitalwrite(int pin_num, int pin_value){
  

  switch (pin_num) {
  
  case 7:  //white
       
    digitalWrite(r,pin_value);
    digitalWrite(g,pin_value);
    digitalWrite(b,pin_value); 
    break;
  case 6: //cyan
    
    digitalWrite(b,pin_value);
    digitalWrite(g,pin_value); 
    break;
  case 5: //magenta
 
    digitalWrite(r,pin_value);
    digitalWrite(b,pin_value);
    break;
  case 4: //gelb
  
    digitalWrite(r,pin_value);
    digitalWrite(g,pin_value);
    break;
   case 3: //blau
     digitalWrite(b,pin_value);
     break;
  case 2: //gruen
    
    digitalWrite(g,pin_value);
    break;
  case 1: //rot
   
    digitalWrite(r,pin_value);
    break;
  }
} 

void func_13(int ard_command ,char get_char ,int pin_num,int pin_value){
  
  for(p;p<255;p++){
    analogWrite(11,p);
    delay(3);
  } 
  
  for(o;o>=0;o--){
    analogWrite(11,o);        
    delay(3);
  }

  delay(50);
} 

void RussianHardBass(){
  if (container == 0){
    digitalWrite(r,HIGH);
    delay(500);
    reset();
    
  }
  if (container == 1){
    digitalWrite(g,HIGH);
    delay(500);
    reset();
  }
  if (container == 2){
    digitalWrite(b,HIGH);
    delay(500);
    reset();
  }
  if (container == 3){
    digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    delay(500);
    reset();
  }
  if (container == 4){
    digitalWrite(r,HIGH);
    digitalWrite(b,HIGH);
    delay(500);
    reset();
  }
  if (container == 5){
    digitalWrite(r,HIGH);
    digitalWrite(g,HIGH);
    delay(500);
    reset();
  }
}

void impulse_red(int m,int delayOn,int delayOff){
  for(int i = 0; i<=255; i++){
    analogWrite(r,i);  
    delay(m);
  }
  delay(delayOn);
  
  for (int kk = 255; kk>= 0; kk--){  
    analogWrite(r,kk);
    delay(m);
  }
  delay(delayOff);
}

void impulse_blue(int m,int delayOn,int delayOff){
  for(int i = 0; i<=255; i++){
    analogWrite(b,i);
    delay(m);  
  }
  delay(delayOn);
  
  for (int kk = 255; kk >= 0; kk--){  
    analogWrite(b,kk);
    delay(m);
  }
  delay(delayOff);
}

void impulse_green(int m,int delayOn,int delayOff){
  for(int i = 0; i<=255; i++){
    analogWrite(g,i);
    delay(m);  
  }
  delay(delayOn);
  
  for (int kk = 255; kk >= 0; kk--){  
    analogWrite(g,kk);
    delay(m);
  }
  delay(delayOff);
}

void impulse_margenta(int m,int delayOn,int delayOff){
  for(int i = 0; i<=255; i++){
    analogWrite(r,i);
    analogWrite(b,i);
    delay(m);  
  }
  delay(delayOn);
  
  for (int kk = 255; kk >= 0; kk--){  
    analogWrite(r,kk);
    analogWrite(b,kk);
    delay(m);
  }
  delay(delayOff);
}

void impulse_yellow(int m,int delayOn,int delayOff){
  for(int i = 0; i<=255; i++){
    analogWrite(r,i);
    analogWrite(g,i);
    delay(m);  
  }
  delay(delayOn);
  
  for (int kk = 255; kk>= 0; kk--){  
    analogWrite(r,kk);
    analogWrite(g,kk);
    delay(m);
  }
  delay(delayOff);
}

void impulse_cyan(int m,int delayOn,int delayOff){
  for(int i = 0; i<=255; i++){
    analogWrite(b,i);
    analogWrite(g,i);
    delay(m);  
  }
  delay(delayOn);
  
  for (int kk = 255; kk >= 0; kk--){  
    analogWrite(b,kk);
    analogWrite(g,kk);
    delay(m);
  }
  delay(delayOff);
}

void impulse(){
  if(container == 0){
    impulse_blue(5,50,100);
  }
  if(container == 1){
    impulse_margenta(5,50,100);
  }
  if(container == 2){
    impulse_red(5,50,100);
  }
  if(container == 3){
    impulse_yellow(5,50,100);
  }
  if(container == 4){
    impulse_green(5,50,100);
  }
  if(container == 5){
    impulse_cyan(5,50,100);
  }
}

void GanstaRap(){
 if(container == 0 || container == 1){
    for(int JJJ = 255; JJJ >50; JJJ--){
      analogWrite(b,JJJ);
      delay(4);
    }   
    digitalWrite(b,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    delay(100);
    digitalWrite(b,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    delay(100);
 }
 if(container == 2 || container == 3){
    for(int JJJ = 255; JJJ >50; JJJ--){
      analogWrite(b,JJJ);
      analogWrite(r,JJJ);
      delay(4);
    }   
    digitalWrite(b,HIGH);
    digitalWrite(r,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    digitalWrite(r,LOW);
    delay(100);
    digitalWrite(b,HIGH);
    digitalWrite(r,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    digitalWrite(r,LOW);
    delay(100);
 }
 if(container == 4 || container == 5){
  for(int JJJ = 255; JJJ >50; JJJ--){
      analogWrite(r,JJJ);
      delay(4);
    }   
    digitalWrite(r,HIGH);
    delay(100);
    digitalWrite(r,LOW);
    delay(100);
    digitalWrite(r,HIGH);
    delay(100);
    digitalWrite(r,LOW);
    delay(100);
 }
}
void police(){
  digitalWrite(b,HIGH);
  delay(100);
  digitalWrite(b,LOW);
  delay(100);
  digitalWrite(b,HIGH);
  delay(100);
  digitalWrite(b,LOW);
  delay(200);
  digitalWrite(r,HIGH);
  delay(100);
  digitalWrite(r,LOW);
  delay(100);
  digitalWrite(r,HIGH);
  delay(100);
  digitalWrite(r,LOW);
  delay(200);
}
void Thunderstorm(){
for(int i = 127; i <= 255; i++){
      analogWrite(b, i);
      delay(25);
    }
    if(c == 0){
      digitalWrite(b,LOW);
      delay(100);
      digitalWrite(b,HIGH);
      delay(100);
      digitalWrite(b,LOW);
      delay(100);
      for(int hhhh = 255; hhhh >= 127; hhhh--){
        analogWrite(b, hhhh);
        delay(25);
      }
    }
    if(c == 1){
      digitalWrite(b, LOW);
      delay(100);
      digitalWrite(b, HIGH);
      delay(1000);
      digitalWrite(b,LOW);
      delay(100);
      for(int hhhh = 255; hhhh >= 127; hhhh--){
        analogWrite(b, hhhh);
        delay(25);
      }
    }
    if(c == 2){
      for(int hhhh = 255; hhhh >= 127; hhhh--){
        analogWrite(b, hhhh);
        delay(25);
      }
    }
  digitalWrite(b,LOW); 
}
void reset(){
  digitalWrite(r,LOW);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);
}

