
int mtr_AB_en= 5;
int mtr_AB_in1= 6;
int mtr_AB_in2= 7;

int mtr_CD_en= 10;
int mtr_CD_in1= 8;
int mtr_CD_in2= 9;

int ch1= 2;
int ch3= 3;

void setup() {

 
  pinMode(mtr_AB_en,OUTPUT);
  pinMode(mtr_AB_in1,OUTPUT);
  pinMode(mtr_AB_in2,OUTPUT);

  pinMode(mtr_CD_en,OUTPUT);
  pinMode(mtr_CD_in1,OUTPUT);
  pinMode(mtr_CD_in2,OUTPUT);  

  pinMode(ch1,INPUT);
  pinMode(ch3,INPUT);




  
}

void loop() {

  int steer= pulseIn(ch1,HIGH,25000);
  int throttle= pulseIn(ch3,HIGH,25000);

  int speed= map(throttle,1000,2000,25,255);
  analogWrite(mtr_AB_en,speed);
  analogWrite(mtr_CD_en,speed);
  
  

  digitalWrite(mtr_AB_in1,HIGH);
  digitalWrite(mtr_AB_in2,LOW);
  digitalWrite(mtr_CD_in1,HIGH);
  digitalWrite(mtr_CD_in2,LOW);

  if(steer>1700){

    digitalWrite(mtr_AB_in1,LOW);
    digitalWrite(mtr_AB_in2,HIGH);
    digitalWrite(mtr_CD_in1,HIGH);
    digitalWrite(mtr_CD_in2,LOW);
  }

  else if(steer< 1300)
  {
    digitalWrite(mtr_AB_in1,HIGH);
    digitalWrite(mtr_AB_in2,LOW);
    digitalWrite(mtr_CD_in1,LOW);
    digitalWrite(mtr_CD_in2,HIGH);
  }

  

  

}
