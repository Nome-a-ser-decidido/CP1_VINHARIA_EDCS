# CP1_VINHARIA_EDCS

Para nosso primeiro CP1 da matéria de Edge Computing & Computer Systems, foi passado um desafio para solucionarmos para a Vinheria Agnello, que consiste em criar um sistema que possua um sensor de luminosidade, LEDS e um display LCD. O objetivo do desafio, é monitorar a luminosidade do ambiente e no display do LCD msotrar informações do grupo

<h2> Projeto no tinkercad </h2>

O projeto pode ser acessado pelo link https://www.tinkercad.com/things/giGfnG08Ewd-teste-de-luminosidade-com-display
É utilizado os seguintes componentes nesse projeto:
<li> Arduino UNO R3</li>
<li> 3 LEDs</li>
<li> 1 Piezo</li>
<li> 6 resistores </li>
<li> 1 fotorresitor</li>
<li> 1 LCD 16x2 </li>

<h2> Sistema </h2>
O código lê o valor de luminosidade que está sendo exercida no Fotorresistor, fazendo com que, dependendo da quantidade de luz sendo emitida, irá acionar um LED, onde quando acionado o LED vermelho, quer dizer que tem muita luminosidade na adega, o LED amarelo, passa uma sensação de cuidado, e o LED verde quer dizer que está tudo funcionando perfeitamente bem.

É necessário configurar a função map(), pois pode haver uma variação de luminosidade dependendo de qual fotorresistor está sendo utilizado

<h2> Visualização </h2>

![Copy of Teste de luminosidade com display](https://github.com/user-attachments/assets/1b679a9c-2d4b-46fa-88cf-5df584725407)
