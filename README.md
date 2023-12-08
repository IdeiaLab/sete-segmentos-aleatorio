# Gerador de número aleatório para display de 7 segmentos 
### Informações
  <div align='left'>
    Ferramentas utilizadas: 
    <ul>
      <li>Arduino IDE</li>
      <li>Arduino C</li>
    </ul>
    Componentes: 
    <ul>
      <li>Arduino UNO</li>
      <li>Botão de contato momentâneo</li>
      <li>Display de sete segmentos</li>
      <li>Circuito Integrado 4511</li>
      <li>2x Resistor de 300 ohms</li>
    </ul>
    <p>
      <a href='https://byjus.com/maths/decimal-to-binary/'>LEIA SOBRE A CONVERSÃO INCORPORADA NO PROGRAMA</a><br/>
    </p>  
    <p>
      Para a montagem do circuito, você pode seguir o diagrama encontrado
      <a href='https://www.arduinoecia.com.br/como-usar-decodificador-cd4511-arduino-display-7-segmentos/'>aqui</a>
      e depois basta ligar o botão de contato momentâneo a um pino de sua placa Arduino. Lembre-se de definir o pino
      no programa também.
    </p>
    <p>
      <strong>Note que atribuir um valor máximo maior que 9 a ser gerado pode findar em comportamento indefinido de todo o sistema.</strong>
    </p>
  </div>
  <hr/>
<h3>Funcionamento</h3>
<div align='left'>
  O funcionamento do sistema é extremamente simples: basta apertar o botão de contato momentâneo<br/> e o programa gerará
  N números de X a Y, com intervalos entre as gerações para que haja uma "animação" no display.
</div>
