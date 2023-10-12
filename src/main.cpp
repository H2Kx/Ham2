#include <Arduino.h>
#define LED_XANH 8
#define LED_DO 7
#define LED_TIM 6
#define NUT_NHAN 2
#define BAT 1
#define TAT 0
void XanhOn()
{
  digitalWrite(LED_XANH, HIGH);
}
void bat_den_sang(int chan_pin_cua_den)
{
  digitalWrite(chan_pin_cua_den, HIGH);
}
void bat_den_sang_hoac_tat_ca_den()
{
  bat_den_sang(LED_XANH);
  bat_den_sang(LED_TIM);
  bat_den_sang(LED_DO);
}
void bat_den_sang_hoac_tat(int chan_pin_cua_den, bool bat_den_sang_hoac_tat)//khi sáng hoặc tắt thì cần biến bool
{
  digitalWrite(chan_pin_cua_den, bat_den_sang_hoac_tat);
}
int doc_tin_hieu_nut_nhan_chan_so_2()
{
  return digitalRead(NUT_NHAN);
}
int doc_tin_hieu_nut_nhan_bat_ky(int chan_pin_cua_nut_nhan)
{
  return digitalRead(chan_pin_cua_nut_nhan);
}
void setup()
{
  pinMode(LED_XANH, OUTPUT);
  pinMode(LED_DO, OUTPUT);
  pinMode(LED_TIM, OUTPUT);
  pinMode(NUT_NHAN, INPUT_PULLUP);
  Serial.begin(9600);
  XanhOn();
}
void loop()
{
  if (doc_tin_hieu_nut_nhan_chan_so_2() == HIGH)
  {
    Serial.println("Khong  nhan");
  }
  else
  {
    Serial.println("nhan");
    XanhOn();
    bat_den_sang_hoac_tat_ca_den();
    bat_den_sang_hoac_tat(LED_XANH, TAT);
  }
}