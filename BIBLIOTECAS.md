# Bibliotecas utilizadas na apostila

Este arquivo registra as dependências dos programas do repositório e as versões recomendadas para a apostila 2026/2.

## Bibliotecas externas

### DHT sensor library — Adafruit

- Versão recomendada: **1.4.7**
- Usada nos capítulos: **16 e 20**
- Cabeçalho: `DHT.h`
- Fonte oficial: https://github.com/adafruit/DHT-sensor-library
- Dependência: **Adafruit Unified Sensor**

### Adafruit Unified Sensor

- Versão recomendada: **1.1.15**
- Dependência da biblioteca DHT
- Fonte oficial: https://github.com/adafruit/Adafruit_Sensor

### LiquidCrystal_I2C

- Versão de compatibilidade adotada: **1.1.4**
- Usada nos capítulos: **19 e 20**
- Cabeçalho: `LiquidCrystal_I2C.h`
- Fonte de referência: https://github.com/johnrickman/LiquidCrystal_I2C
- Observação: o repositório de referência está arquivado. A versão foi mantida porque corresponde à API empregada nos programas da apostila e à plataforma Arduino Uno/AVR.

## Bibliotecas Arduino

As seguintes dependências não são distribuídas neste repositório porque pertencem ao ecossistema Arduino ou à biblioteca padrão da plataforma:

- `Wire.h` — comunicação I2C;
- `Servo.h` — controle de servomotores;
- `LiquidCrystal.h` — displays LCD paralelos compatíveis com HD44780;
- `math.h` — funções matemáticas da toolchain C/C++.

## Instalação recomendada

Na Arduino IDE, abra **Sketch > Include Library > Manage Libraries...** e procure pelo nome da biblioteca. Instale as versões indicadas acima quando a IDE permitir selecionar a versão.

Para os capítulos 16 e 20, instale primeiro **DHT sensor library**; a IDE pode oferecer a instalação automática de suas dependências. Confirme também a presença de **Adafruit Unified Sensor**.

Para os capítulos 19 e 20, use uma implementação de `LiquidCrystal_I2C` compatível com a construção empregada nos códigos, por exemplo:

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

## Por que as bibliotecas não são copiadas para este repositório?

O repositório da apostila mantém os programas autorais e registra versões e fontes das dependências. As bibliotecas de terceiros devem ser obtidas de seus projetos oficiais. Isso evita duplicação, facilita atualizações, preserva informações de autoria/licença e reduz o risco de o aluno instalar uma cópia desatualizada sem perceber.
