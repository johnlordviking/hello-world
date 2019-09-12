void intenso(){
  tone(7, 440);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(5, LOW);
  noTone(7);
  delay(200);
}
void vida(){
  tone(7, 440);
  delay(500);
  noTone(7);
  delay(500);
}
void venceu(){
  digitalWrite(4, HIGH);
  tone(7, 440);
  delay(150);
  digitalWrite(4, LOW);
  noTone(7);
  digitalWrite(4, HIGH);
  tone(7, 440);
  delay(150);
  digitalWrite(4, LOW);
  noTone(7);
  digitalWrite(4, HIGH);
  tone(7, 440);
  delay(150);
  digitalWrite(4, LOW);
  noTone(7);
}

void morreu(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  tone(7, 440);
  delay(5000);
  noTone(7);
}
