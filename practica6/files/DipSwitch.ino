/* Simple Switch code designed to serial print the state of the switch
*/ 
int switchState = 0; 

void setup()
{
  pinMode(0, INPUT); 

 
}

void loop()
{
  switchState = digitalRead(7);
  
    delay(500); 
}