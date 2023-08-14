#define ONBOARD_KEY 47  // 板载按钮
#define ONBOARD_LED 21  // 板载 LED

volatile bool buttonPressed = false;  // 按钮下降沿中断标志位

void setup() {
  pinMode(ONBOARD_LED, OUTPUT);
  pinMode(ONBOARD_KEY, INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(ONBOARD_KEY), buttonInterrupt, FALLING);
}

void loop() {
  if (buttonPressed) {
    digitalWrite(ONBOARD_LED, HIGH);
    delay(500);
    digitalWrite(ONBOARD_LED, LOW);
    Serial.println("buttonPressed");
    buttonPressed = false;  // 重置中断标志位
  }
}

void buttonInterrupt() {
  buttonPressed = true;  // 设置下降沿中断标志位
}
