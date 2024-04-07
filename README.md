# Automação Industrial

O Objectivo deste projecto é criar um sistema automatizado de controle de uma fábrica (projecto proposto por finalistas do Instituto Polietécnico Industrial de Luanda (ex IMIL - Makarenko). Aqui temos um botão que está conectado ao servidor flask e que envia sinais a ele que serão previamente convertidos em acções. PROJECTO AINDA EM DESENVOLVIMENTO

## Funcionalidades
Após concluido corretamente, o sistema deverá ser capaz de:
1. Ligar ou Desligar o ciclo de funcionamento do motor (ou qualquer que seja o dispositivo receptor)
2. Permitir a entrada de sensores pra aprimorar a monitoração do funcionamento do Motor
3. Forneçer uma interface gráfica simples, agradável e legível pra o operador

## Materiais Usados pra o projecto
### ESP-WROOM-32
![Imagem do ESP23](https://github.com/EdAnder32/Automacao_Industrial/blob/main/templates/20240407_113257.jpg)
Esse é o cerebro do projecto! Ele é responsável por logar na rede wifi e reservar um endereço IP possibilitando assim a entrada de visitantes no site. Ele também é quem descodifica os comandos recebidos pela página web nele inbutido e passa os mesmos para o módulo relé. Tem capacidade também de realizar um monte de outras tarefas que poderão ser implementadas no futuro, como a recepção de sinais de sensores nele conectado.
### Arduino Uno
![Imagem do Arduino Uno](https://github.com/EdAnder32/Automacao_Industrial/blob/main/templates/20240407_113240.jpg)
Com uma boa medida e poder de processamento, o Arduino Uno poderia facilmente servir tbm como um dos cerebros! Mas no entanto, neste sistema, ele servirá apenas como fonte de alimentação do Módulo Relé cuja entrada é de 5v, algo que o ESP32 não seria capaz de suportar. Logo, nele serão ligados apenas o GND e VCC.
### Módulo Relé de 4 Canais
![Imagem do Modulo Rele](https://github.com/EdAnder32/Automacao_Industrial/blob/main/templates/20240407_113322.jpg)
Responsável por receber os sinais do ESP e passar ao receptor! A melhor parte deste componente é que ele pode comandar receptores trifásicos!!! Com suas portas NO, NC e COM, o módulo relé Tornou-se um fiel aliado pra a concretização deste projecto. Aqui usamos um de 4 Canais, mas de momento apenas 1 deles é realmente utilizado.
### Jumpers
![Imagem dos Jumpers](https://github.com/EdAnder32/Automacao_Industrial/blob/main/templates/20240407_113336.jpg)
Macho-Fêmea, Fêmea-Macho, Macho-Macho, epa sei lá eu... Eles são responsáveis por fazer a conexão cabelada entre os diferentes dispositivos deste sistema.
### Placa de Ensaios
![Imagem da Placa de Ensaios](https://github.com/EdAnder32/Automacao_Industrial/blob/main/templates/20240407_113309.jpg)
Placa em que alguns dos Jumpers serão conectados. Na real, pode nem usar se não quiser
![Imagem da Placa de Ensaios](https://github.com/EdAnder32/Automacao_Industrial/blob/main/templates/20240407_113309.jpg)
