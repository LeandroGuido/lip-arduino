// C++ code
//
/*
  Semaforo Inteligente
   Leandro Guido Lorenzini Santos
*/

int Estado_atual_do_botao = 0;

int Ultimo_estado_do_botao = 0;

int Vezes_que_o_botao_foi_apertado = 0;

int i = 0;

int counter;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  // lê o pino 2 (botao)
  Estado_atual_do_botao = digitalRead(2);
  // Compara o estado atual do botao com o ultimo
  // estado do botao
  if (Estado_atual_do_botao != Ultimo_estado_do_botao) {
    // Se o estado mudar adiciona 1 nas vezes que o
    // botao foi apertado
    if (Estado_atual_do_botao == HIGH) {
      Vezes_que_o_botao_foi_apertado += 1;
      // Mostra quando comeca a ler e a quantidade de
      // vezes que foi apertado
      Serial.println("on");
      Serial.print("Vezes que o botao foi apertado: ");
      Serial.println(Vezes_que_o_botao_foi_apertado);
    } else {
      // Mostra quando foi finalizado
      Serial.println("off");
    }
    delay(5); // Wait for 5 millisecond(s)
  }
  // Salva o ultimo estado do botao
  Ultimo_estado_do_botao = Estado_atual_do_botao;
  // Quando um numero for par executa o semaforo de
  // carros, quando for impar executa o semaforo de
  // pedestres
  if (Vezes_que_o_botao_foi_apertado % 2 == 0) {
    if (Estado_atual_do_botao == Ultimo_estado_do_botao) {
      // Verde
      digitalWrite(10, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    }
  } else {
    delay(7000); // Wait for 7000 millisecond(s)
    // Amarelo
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    delay(3000); // Wait for 3000 millisecond(s)
    // Vermelho
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    // Semaforo de pedestre
    // VerdeP
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    delay(7000); // Wait for 7000 millisecond(s)
    digitalWrite(9, LOW);
    // Pisca 3 vezes e mantem VermelhoP
    for (counter = 0; counter < 3; ++counter) {
      digitalWrite(10, LOW);
      delay(500); // Wait for 500 millisecond(s)
      digitalWrite(10, HIGH);
      delay(500); // Wait for 500 millisecond(s)
    }
    // Soma 1 na quantidade de vezes que o botao foi
    // apertado (para recomecar o ciclo))
    Vezes_que_o_botao_foi_apertado += 1;
    // Mostra quando comeca a ler e a quantidade de
    // vezes que foi apertado
    Serial.println("on");
    Serial.print("Vezes que o botao foi apertado: ");
    Serial.println(Vezes_que_o_botao_foi_apertado);
  }
}