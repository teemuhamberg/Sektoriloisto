#define LedS1Vi 11
#define LedS1Ke 10
#define LedS1Pu 9
#define LedS2Vi 6
#define LedS2Ke 5
#define LedS2Pu 3

void setup(){
  pinMode(LedS1Vi, OUTPUT); 
  pinMode(LedS1Ke, OUTPUT); 
  pinMode(LedS1Pu, OUTPUT); 
  pinMode(LedS2Vi, OUTPUT); 
  pinMode(LedS2Ke, OUTPUT); 
  pinMode(LedS2Pu, OUTPUT); 
  Serial.begin(9600);
  Serial.println("Startup");
}
#define VIIVE 5

byte tehoS1,tehoS2=0; // Muuttujat tehon säätämiseen
bool countUpS1, countUpS2 = true; // Muuttujat suunnan määräämiseen

void breathS1(){
  analogWrite(LedS1Vi, tehoS1);
  analogWrite(LedS1Ke, tehoS1);
  analogWrite(LedS1Pu, tehoS1);
  if( countUpS1 == true ){
    tehoS1 = tehoS1 +1;//Kaseta muuttujan arvoa yhdellä
  }else{
    tehoS1 = tehoS1 -1;//Pienennä muuttujan arvoa yhdellä
  }
  if( tehoS1 == 255 ){
    countUpS1 = false;
    Serial.println("Count down S1"); 
  }
  if( tehoS1 == 0 ){
    countUpS1 = true;
    Serial.println("Count up S1"); 
  }
}

void breathS2(){
  analogWrite(LedS2Vi, tehoS2);
  analogWrite(LedS2Ke, tehoS2);
  analogWrite(LedS2Pu, tehoS2);
  if( countUpS2 == true ){
    tehoS2 = tehoS2 +2;//Kasvata muuttujan arvoa yhdellä
  }else{
    tehoS2 = tehoS2 -2;//Pienennä muuttujan arvoa yhdellä
  }
  if( tehoS2 == 254 ){
    countUpS2 = false;
    Serial.println("Count down S2"); 
  }
  if( tehoS2 == 0 ){
    countUpS2 = true;
    Serial.println("Count up S2"); 
  }
}


void loop(){
  breathS1();
  breathS2();
  delay(VIIVE);// Ainoa viive ohjelmassa
}
