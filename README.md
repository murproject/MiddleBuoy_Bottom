 
# Прошивка для платы буя MiddleBuoy

Подробнее о наборе [MiddleBuoy](https://wiki.murproject.com/ru/MiddleBuoy/buoy-instruction).

Данная прошивка предназначена для платы находящейся в буе MiddleBuoy. Буй представляет собой герметичную колбу с движителем.

> Если нужна прошивка для платы пульта, то вам нужен репозиторий [MiddleBuoy_Surface](https://github.com/murproject/MiddleBuoy_Surface).

Для прошивки, подключите USB-кабель к плате и воспользуйтесь [Arduino IDE](https://www.arduino.cc/en/Main/Software). Выберите нужный последовательный порт и плату Arduino Leonardo. Обратите внимание на необходимые библиотеки.

## Установка библиотек
Для успешной прошивки вам понадобятся следующие библиотеки:
- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
- [BlueRobotics MS5837 Library](https://github.com/bluerobotics/BlueRobotics_MS5837_Library)

Чтобы установить эти библиотеки откройте менеджер библиотек в Arduino IDE: Скетч / Покдлючить библиотеку / Управлять библиотеками. Введите в поиск **Adafruit NeoPixel** и установите библиотеку. Аналогичным образом установите **BlueRobotics MS5837 Library**.