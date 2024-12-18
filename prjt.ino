int i = 1 ; // étage initiale de la cabine 

//Les bouttons 
int b1 = 11 ; 
int b2 = 12 ; 
int b3 = 13 ; 

//Etat des boutons 
int but_st1 = 0 ; 
int but_st2 = 0 ;
int but_st3 = 0 ;

//Le moteur 
int pM1 = 4 ; 
int pM2 = 5 ; 
int pM3 = 6 ; 
int pM4 = 7 ; 

//buzzer
int buzzer = 2 ;

//7 segment 
int b = 3 ; 
int a_g_d = 10 ; 
int c = 9; 
int e = 8; 


void setup() {
  // put your setup code here, to run once:
  
  pinMode(b1, INPUT); 
  pinMode(b2, INPUT);
  pinMode(b3, INPUT); 
   

  Serial.begin(9600); 

  pinMode(pM1, OUTPUT); 
  pinMode(pM2, OUTPUT); 
  pinMode(pM3, OUTPUT); 
  pinMode(pM4, OUTPUT); 

  pinMode(a_g_d, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(e, OUTPUT); 

  pinMode(buzzer , OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("You are on the ");
  Serial.print(i);
  Serial.println("floor");
  show(i); 
  noTone(buzzer); 

  but_st1 = digitalRead(b1); 
  but_st2 = digitalRead(b2); 
  but_st3 = digitalRead(b3); 

  if (but_st3 == HIGH){

    if(i < 3){
      while(i < 3){  
        show(i); 
        i++;
        up();
    
        Serial.print("You are on the ");
        Serial.print(i);
        Serial.println("floor");
      }
    }
    i=3;
    tone(buzzer, 2000); 
    delay(1000); 
  }

  if (but_st2 == HIGH){
    if( i < 2){
      while(i < 2){
        show(i); 
        i++;
        up(); 

        Serial.print("You are on the 2");
        Serial.print(i);
        Serial.println("floor");
      }
    }
    if ( i > 2){
      while(i > 2){
        show(i); 
        i++; 
        down(); 

        Serial.print("You are on the ");
        Serial.print(i);
        Serial.println("floor");
      }
    }
    i = 2 ; 
    tone(buzzer, 2000); 
    delay(1000); 
  }

  if (but_st1 == HIGH){
    if(i>1){
      while(i > 1){
        show(i); 
        i--; 
        down(); 

        Serial.print("You are on the1 ");
        Serial.print(i);
        Serial.println("floor");
      }
    }
    i = 1; 
    tone(buzzer, 2000); 
    delay(1000); 
  }
}

void up(){
  for(int j = 0 ; j < 1200; j++){
    digitalWrite(pM1, HIGH);
    digitalWrite(pM2, LOW);
    digitalWrite(pM3, LOW); 
    digitalWrite(pM4, LOW); 
    delay(5); 

    digitalWrite(pM1, LOW);
    digitalWrite(pM2, HIGH);
    digitalWrite(pM3, LOW); 
    digitalWrite(pM4, LOW); 
    delay(5); 

    digitalWrite(pM1, LOW);
    digitalWrite(pM2, LOW);
    digitalWrite(pM3, HIGH); 
    digitalWrite(pM4, LOW); 
    delay(5); 

    digitalWrite(pM1, LOW);
    digitalWrite(pM2, LOW);
    digitalWrite(pM3, LOW); 
    digitalWrite(pM4, HIGH); 
    delay(5); 
  }
}

void down(){
  for (int k = 0 ; k < 1200; k++)
  {
    digitalWrite( pM4, HIGH); 
    digitalWrite( pM3, LOW);
    digitalWrite( pM2, LOW);
    digitalWrite( pM1, LOW);
    delay(5); 

    digitalWrite( pM4, LOW); 
    digitalWrite( pM3, HIGH);
    digitalWrite( pM2, LOW);
    digitalWrite( pM1, LOW);
    delay(5); 

    digitalWrite( pM4, LOW); 
    digitalWrite( pM3, LOW);
    digitalWrite( pM2, HIGH);
    digitalWrite( pM1, LOW);
    delay(5); 

    digitalWrite( pM4, LOW); 
    digitalWrite( pM3, LOW);
    digitalWrite( pM2, LOW);
    digitalWrite( pM1, HIGH);
    delay(5); 
  }
}

void show(int a){
  digitalWrite(b, HIGH);   
  if (a == 1 ){
    digitalWrite(a_g_d, LOW);
    digitalWrite(c , HIGH); 
    digitalWrite(e, LOW); 
  }
  else if(a == 2){
    digitalWrite(a_g_d, HIGH);
    digitalWrite(c , LOW); 
    digitalWrite(e,HIGH);
  }
  else if(a == 3){
    digitalWrite(a_g_d, HIGH);
    digitalWrite(c , HIGH); 
    digitalWrite(e, LOW);
  }
}
