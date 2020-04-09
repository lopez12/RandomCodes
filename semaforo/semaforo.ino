double MachineCounter = 300000;
double Timer1 = 0;
double Timer2 = 0;
double Timer3 = 0;
double Timer4 = 0;
double Timer5 = 0;

void setup() {
  
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Timer1 = MachineCounter / 5;
  Timer2 = (MachineCounter / 5) * 2;
  Timer3 = (MachineCounter / 5) * 3;
  Timer4 = (MachineCounter / 5) * 4;
  Timer5 = MachineCounter;
  attachInterrupt(digitalPinToInterrupt(2), Cambiar, FALLING);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  if(MachineCounter < Timer1)
  {  
      EncenderRojo1();
      ApagarAmarillo1();
      ApagarVerde1();
      ApagarRojo2();
      ApagarAmarillo2();
      EncenderVerde2();  
  }
  else if (MachineCounter < Timer2 && MachineCounter > Timer1)
  {
      ApagarRojo1();
      EncenderAmarillo1();
      ApagarVerde1();
      EncenderRojo2();
      ApagarAmarillo2();
      ApagarVerde2();
  }
  else if (MachineCounter < Timer3 && MachineCounter > Timer2)
  {
      ApagarRojo1();
      ApagarAmarillo1();
      EncenderVerde1();
      EncenderRojo2();
      ApagarAmarillo2();
      ApagarVerde2();
  }
  else if (MachineCounter < Timer4 && MachineCounter > Timer3)
  {
      EncenderRojo1();
      ApagarAmarillo1();
      ApagarVerde1();
      ApagarRojo2();
      EncenderAmarillo2();
      ApagarVerde2();
  }
  else
  {
      EncenderRojo1();
      ApagarAmarillo1();
      ApagarVerde1();
      ApagarRojo2();
      ApagarAmarillo2();
      EncenderVerde2();
  }
 
  if(MachineCounter == 0)
  {
    MachineCounter = Timer5;
  }
  else
  {
    MachineCounter--;
  }

}

void EncenderRojo1 (void)
{
  digitalWrite(0,HIGH);
}

void ApagarRojo1 (void)
{
  digitalWrite(0,LOW);
}

void EncenderRojo2 (void)
{
  digitalWrite(3,HIGH);
}

void ApagarRojo2 (void)
{
  digitalWrite(3,LOW);
}

void EncenderAmarillo1 (void)
{
  digitalWrite(1,HIGH);
}

void ApagarAmarillo1 (void)
{
  digitalWrite(1,LOW);
}

void EncenderAmarillo2 (void)
{
  digitalWrite(4,HIGH);
}

void ApagarAmarillo2 (void)
{
  digitalWrite(4,LOW);
}


void EncenderVerde1 (void)
{
  digitalWrite(6,HIGH);
}

void ApagarVerde1 (void)
{
  digitalWrite(6,LOW);
}

void EncenderVerde2 (void)
{
  digitalWrite(5,HIGH);
}

void ApagarVerde2 (void)
{
  digitalWrite(5,LOW);
}

void Cambiar (void)
{
  MachineCounter = 0;
}
