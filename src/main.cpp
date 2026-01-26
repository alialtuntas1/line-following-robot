#include <Arduino.h>

// ===== MOTOR PINLERI =====
#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// ===== SENSOR PINLERI =====
#define SOL 2
#define ORTA 3
#define SAG 4

// ===== HIZ AYAR =====
int hiz = 130;
int donusHiz = 180;

// ===== DURUM =====
int aramaYon = 0; // 0 = sag, 1 = sol
int beyazSayac = 0;

// ===== MOTOR FONKSIYONLARI =====
void ileri() {
  analogWrite(ENA, hiz);
  analogWrite(ENB, hiz);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void sagDon() {
  analogWrite(ENA, donusHiz);
  analogWrite(ENB, donusHiz);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void solDon() {
  analogWrite(ENA, donusHiz);
  analogWrite(ENB, donusHiz);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void dur() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// ===== SETUP =====
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SOL, INPUT);
  pinMode(ORTA, INPUT);
  pinMode(SAG, INPUT);
}

// ===== LOOP =====
void loop() {
  int s = digitalRead(SOL);
  int o = digitalRead(ORTA);
  int g = digitalRead(SAG);

  beyazSayac++;

  // ===== ORTA CIZGI =====
  if (o == 0) {
    beyazSayac = 0;
    ileri();
    return;
  }

  // ===== SOL GORDU =====
  if (s == 0 && g == 1) {
    beyazSayac = 0;
    solDon();
    aramaYon = 1;
    return;
  }

  // ===== SAG GORDU =====
  if (g == 0 && s == 1) {
    beyazSayac = 0;
    sagDon();
    aramaYon = 0;
    return;
  }

  // ===== IKISI DE GORDU (KESKIN DONUS) =====
  if (s == 0 && g == 0) {
    beyazSayac = 0;
    sagDon();
    delay(80);
    return;
  }

  // ===== HICBIRI GORMUYOR → SAKIN ZIGZAG =====
  if (s == 1 && o == 1 && g == 1) {

    if (beyazSayac < 6) {   // hemen zigzaga girme
      ileri();
      return;
    }

    if (aramaYon == 0) {
      sagDon();
    } else {
      solDon();
    }
  }
}
