#define VRx A0 
#define SW 3

const int portas[4]={4,5,6,7};
int tex_play[4]={206,28,238,118}, tex_sub[4]={182,124,254,1};
int tex_add[4]={238,255,255,1};
int segmento[10]={252,96,218,242,102,182,190,224,254,246};
int randomica[2] {}, operacao, aux=1, digito=0, resposta;

int eixo_x, clique;

String escolha[4]={}, juncao;

bool lose=false;

void sorteio() {
  if(aux<=5) {
    for (int i=0; i<=1;i++){
    randomica[i] = random(0,10);
  }
 }
  else if (aux>5 and aux<=15){
  for (int i=0;i<=1;i++){
     randomica[i] = random(10,10);
   }
 }
  else{
  for(int i=0;i<=1;i++){
    randomica[i] = random(100,10);
    }
  }

 operacao = random(0,2);
 bool teste = randomica[1]>randomica[0] and operacao==1;
 if(teste==true){
  int swip = randomica [0];
  randomica[0] = randomica [1];
  randomica[1] = swip;
 }
 if(operacao==1){
  resposta = randomica[0] - randomica[1];
 }
 else {
  resposta = randomica[0] + randomica[1];
 }
}

void joystick(int j){
  int tempo;
  bool teste;
  eixo_x = analogRead (VRx);
  clique = digitalRead (SW);
    if (clique==0){
      escolha[j]=digito;
      Serial.println('\n');
      Serial.println("VALOR ESCOLHIDO");
      Serial.println(escolha[j]);
      delay(400);
    }
    if(eixo_x<=450 or eixo_x>=600){
      tempo = millis();
      teste = eixo_x <=450;
      while(eixo_x<=450 or eixo_x>=600){
        eixo_x = analogRead(VRx);
      }
    if ((millis()-tempo)> 600){
      if (teste==true and digito>0){
          digito--;
          Serial.print('\n');
          Serial.println(digito);
          apagar();
          digitalWrite(portas[j], LOW);
          segmentos (digito);
        }
    else if (teste==false and digito<9){
      digito++;
      Serial.print('\n');
      Serial.println(digito);
      apagar();
      digitalWrite(portas[j],LOW);
      segmentos (digito);
    }
  }
 }
}

void apagar(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  delay(5);
}

void play (){
  int tempo=100;
  for(int i=0; i<20;i++){
    for(int i=0;i<4;i++){
      apagar();
      digitalWrite(portas[i], LOW);
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,tex_play[i]);
      digitalWrite(9,HIGH);
      delay(tempo);
    }
  }
}

void add(){
  int tempo=100;
  for(int i=0; i<20;i++){
    for(int i=0;i<4;i++){
      apagar();
      digitalWrite(portas[i], LOW);
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,tex_add[i]);
      digitalWrite(9,HIGH);
      delay(tempo);
    }
  }
}

void sub(){
  int tempo=100;
  for(int i=0; i<20;i++){
    for(int i=0;i<4;i++){
      apagar();
      digitalWrite(portas[i], LOW);
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,tex_sub[i]);
      digitalWrite(9,HIGH);
      delay(tempo);
    }
   i++;
  }
}

void segmentos(int unidade){
  switch (unidade){
    case 0:
    digitalWrite(9,LOW);
    shiftOut (10,8,LSBFIRST,segmento[0]);
      digitalWrite(9,HIGH);
      delay(100);
    
    break;
      case 1:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[1]);
      digitalWrite(9,HIGH);
      delay(100);

    break;
      case 2:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[2]);
     digitalWrite(9,HIGH);
      delay(100);
    break;
      case 3:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[3]);
      digitalWrite(9,HIGH);
      delay(100);

    break;
      case 4:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[4]);
     digitalWrite(9,HIGH);
      delay(100);
    break;
      case 5:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[5]);
      digitalWrite(9,HIGH);
      delay(100);

    break;
      case 6:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[6]);
     digitalWrite(9,HIGH);
      delay(100);

    break;
      case 7:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[7]);
      digitalWrite(9,HIGH);
      delay(100);

    break;
      case 8:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[8]);
     digitalWrite(9,HIGH);
      delay(100);
    
    break;
      case 9:
      digitalWrite(9, LOW);
      shiftOut(10,8,LSBFIRST,segmento[9]);
      digitalWrite(9,HIGH);
      delay(100);
    
    break;
  }
}

void show_s01(){
  String v1 = String (randomica[0]);
  int t_v1 = v1.length();
  int x = 0;

  for (int i=t_v1; i>0;i--){
    apagar();
    int y =-i+3;
    digitalWrite(portas[(i-x)+y], LOW);
    String dg = v1.substring(i,i-1);
    x++;
    segmentos(dg.toInt());
  }
}

void show_s02(){
  String v2 = String (randomica[1]);
  int t_v2 = v2.length();
  int x = 0;

  for (int i=t_v2; i>0;i--){
    apagar();
    int y =-i+3;
    digitalWrite(portas[(i-x)+y], LOW);
    String dg = v2.substring(i,i-1);
    x++;
    segmentos(dg.toInt());
  }
}

void setup (){
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(VRx, OUTPUT);
  pinMode(SW, OUTPUT);

  randomSeed(analogRead(A5));
  Serial.begin(9600);
}

void loop() {
  play();
  lose=false;
  while (lose==false){
    sorteio();
    for(int i=0; i<20;i++){
      show_s01();
    }
  if (operacao==1){
    sub();
    }
  else{
    add();
  }
  for(int i=0; i<20;i++){
    show_s02();
  }
  apagar();
 for (int i=3;i>=0;i--){
  escolha[i]="\0";
 }
 for (int i=4;i>=0;i--){
  while (escolha[i]="\0");
  joystick(i);
  }
  }
juncao = escolha[0] + escolha [1] + escolha [2] + escolha[3];
Serial.print('\n');
Serial.print(juncao);
  if (resposta==juncao.toInt()){
    aux++;
    Serial.print('\n');
    Serial.println("GANHOU");
  }
  else {
    lose = true;
    aux=1;
  }
}