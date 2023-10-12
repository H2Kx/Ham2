#include <Arduino.h>

#define BUTTON_PIN 3
float tinh_chu_vi_hinh_tron(float d)
{
  float hinh_tron = d * 3.14;
  return hinh_tron;
}
float dien_tich_hinh_tron(float cv)
{
  float dien_tich = cv / 4 * 3.14;
  return dien_tich;
}
float cv;
float dt;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  cv = tinh_chu_vi_hinh_tron(2);
  Serial.println(cv);
  dt = dien_tich_hinh_tron(cv);
  Serial.println(dt);

  delay(100);
}