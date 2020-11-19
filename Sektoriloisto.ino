#define LedS1V 10
#define LedS2V 5

void setup(){
  pinMode(LedS1V, OUTPUT); 
  pinMode(LedS2V, OUTPUT); 
  Serial.begin(9600);
  Serial.println("Startup");
}
#define VIIVE 5

byte tehoS1,tehoS2=0; // Muuttujat tehon säätämiseen
bool countUpS1, countUpS2 = true; // Muuttujat suunnan määräämiseen

void breathS1(){
  analogWrite(LedS1V, tehoS1);
  if( countUpS1 == true ){
    tehoS1 = tehoS1 +1;//Kasvata muuttujan arvoa yhdellä
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
  analogWrite(LedS2V, tehoS2);
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
