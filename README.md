# Volvo DIM Tester

## K čemu je DIM Tester dobrý?
Tester lze použít pro ověření funkčnosti či úspěšnosti opravy (např: technologické chyba pájení). Tento tester vám umožní vyzkoušet vše potřebné přímo na vašem stole bez nutnosti přítomnosti vozu.

## Z čeho se zařízení skládá?
Tester je postaven na volně prodejných komponentech, Arduino + CAN Bus modul.

## Seznam komponentů
1x Arduino UNO
1x CAN-Bus modul (POZOR!! Čínské moduly obsahují krystal 8MHz, nutností pro funkčnost je 16MHz)
1x Krystal 16MHz (V případě zakoupení CAN-Bus modulu s krystalem 8MHz)

## Postup
1. Pokud máte CAN-Bus modul s krystalem 8MHz nejprve jej vyměňte za správný 16MHz.
2. Propojte CAN-Bus modul s arduinem.
3. Pokud je arduino klon s usb převodníkem CH340G. Nainstalujte ovladače https://arduino-shop.cz/docs/produkty/0/142/driver_ch341ser.ZIP
4. Stáhněte Arduino IDE https://www.arduino.cc/en/main/software
5. Importujte tuto knihovnu do IDE https://github.com/sparkfun/SparkFun_CAN-Bus_Arduino_Library
6. Nahrajte soubor .ino do arduina.
7. Stáhněte soubor .exe pro ovládání.
8. Připojte DIM

## Kde zakoupit komponenty?
Arduino UNO
https://laskarduino.cz/arduino/100002-arduino-uno-r3-atmega328p-microusb-klon.html?gclid=CjwKCAjwgqbpBRAREiwAF046JZlEPZXIrUeiov4SQ0kHsKP_vOa4cAQ6ztr5eisD-obi6rtyzkadNhoC-0EQAvD_BwE

CAN-Bus modul
https://laskarduino.cz/prenos-dat-dratovy/161002-mcp2515-can-bus-modul-tja1050-8mhz-spi.html?gclid=CjwKCAjwgqbpBRAREiwAF046JVcxMdJrDjKR0OT3qXDBGFFIbbBmRUUIVffXEI_eRiXKK0oMrnOlYRoCTxgQAvD_BwE

Krystal 16MHz
https://www.gme.cz/krystal-hc49-us-qm-16-000mhz
