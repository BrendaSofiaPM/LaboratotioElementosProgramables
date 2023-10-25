int temp=0;

void setup(){
 pinMode(A3, INPUT);
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
}
void loop()
{
 temp= -40+0.488155*(analogRead(A3)-20);
 if(temp<=30){
  digitalWrite(2, HIGH);
}
else{
  digitalWrite(2, LOW);
}
}