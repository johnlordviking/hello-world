void setup() {
  // put your setup code here, to run once:

//PINOS DEFINIDOS COMO LEITURA PARA VERIFICAR SE A CORRENTE NOS FIOS DA "BOMBA"
pinMode(12, INPUT);
pinMode(11, INPUT);
pinMode(10, INPUT);
pinMode(9, INPUT);

//PINO DEFINIDO COMO SAIDA E LIGADO PARA ALIMENTAR PUSH BUTTON (PODE ALIMENTAR COM BARRAMENTO POSITIVO TAMBEM)
pinMode(2, OUTPUT);
digitalWrite(2, HIGH);
  
//LED VERDE
pinMode(4, OUTPUT); 
//LED VERMELHO
pinMode(5, OUTPUT); 
//BOTAO
pinMode(3, INPUT);
//BUZZER
pinMode(7, OUTPUT); 
}
//FUNCAO PARA INICIAR O JOGO "ARMAR A BOMBA"
void startGame(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  //ARRAY COM OS PINOS DA "BOMBA"
  int fios[] = {9, 10, 11,12};
  //ARRAY COM O STATUS DOS PINOS DA "BOMBA"
  int status[] = {1,1,1,1};
  //SORTEIO DE QUAL SERA O PINO MESTRE
  int sort = random(4);
  
  boolean ligado = true;
  //WHILE = Enquanto ligado=true o FOR realiza a leitura de todos os PINO da "bomba", exeto o PINO MESTRE (if x!= sort)
  //Se leitura do PINO da "bomba" for 0, é setado 0 no array de status. Antes do termino do FOR, é somado os valores do array status
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
    
      //SE SOMA FOR IGUAL A 2, ACIONA BIPs E LED MAIS INTENSOS
      //SE NAO, ACIONA BIPs E LED NORMAIS
      if(soma == 2){
        intenso();
      }else{
        vida();
      }
    
    //SE SINAL NO PINO MESTRE FOR 0 = GAME OVER | SE NAO, e SE SOMA FOR MENOR QUE 2 - ESTAMOS SALVOS!
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

//FUNCAO PARA MODO STAND-BY (FORA DO JOGO, "bomba desarmada")
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

  //LEITURA DE BOTAO PARA "ARMAR A BOMBA" Iniciar o jogo foi pressionada
  int botao = digitalRead(3);
  
  //FORA DO JOGO
  standBy();
  
  //INICIA O JOGO
  if(botao == 1){
    startGame();
  }
  
}
