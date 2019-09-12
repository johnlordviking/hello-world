void setup() {
  // put your setup code here, to run once:

pinMode(12, INPUT);
pinMode(11, INPUT);
pinMode(10, INPUT);
pinMode(9, INPUT);

pinMode(2, OUTPUT);
digitalWrite(2, HIGH);

pinMode(4, OUTPUT); //LED VERDE
pinMode(5, OUTPUT); //LED VERMELHO

pinMode(3, INPUT); //BOTAO
pinMode(7, OUTPUT); //BUZZER
}

void startGame(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  int fios[] = {9, 10, 11,12};
  int status[] = {1,1,1,1};
  int sort = random(4);
  
  boolean ligado = true;
  while(ligado){     
    int soma = 0;
      for(int x = 0; x <= 3; x++){
          if(x != sort){
            if(digitalRead(fios[x]) == 0){
              status[x] = 0;
            }
          } 
          soma += status[x];
      }
      if(soma == 2){
        intenso();
      }else{
        vida();
      }
          if(digitalRead(fios[sort]) == 0){            
            morreu();
            ligado = false;
          }else{
              if(soma < 2){
                venceu();
                ligado = false;
              }
          }
  }
}

void standBy(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  //teste();

  int botao = digitalRead(3);
  Serial.println(botao);
  
  //FORA DO JOGO
  standBy();
  
  //INICIA O JOGO
  if(botao == 1){
    startGame();
  }
  
}
