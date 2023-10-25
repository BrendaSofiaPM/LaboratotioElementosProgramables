#define sensor A3 
int valor = 0;
void setup()
{
   
}
void loop()
{
    int valor = map(analogRead(sensor), 0, 1023, 100, 0);
    if(valor<=30){
  digitalWrite(2, HIGH);
}
else{
  digitalWrite(2, LOW);
}

}