// Namespace que contém as constantes globais do programa
namespace Constante
{
  // Pino em que foi atribuído o botão que interage
  // com o sistema.
  constexpr byte BOTAO = 13;

  // São os pinos do CI 4511, juntos formam um número
  // binário que é convertido pelo CI para o display 7
  // segmentos. A é o pino do dígito menos significativo.
  // D é o mais significativo, lê-se, portanto, DCBA.
  // e.g.: Dada a entrada 0b0111(D = 0; C = 1; B = 1; A = 1)
  // será mostrado no display o número 7
  constexpr byte A = 4, B = 5, C = 6, D = 7;
  
  // Valor mínimo(inclusive) e máximo(inclusive) a ser gerado pela função random()
  constexpr byte VALOR_MINIMO = 0, VALOR_MAXIMO = 9;

  // Delay máximo entre cada geração e atribuição 
  // de bits ao CI, em milissegundos.
  constexpr long DELAY_MAXIMO_GERACOES = 500; 

  // Número de vezes que será repetido o processo de
  // geração e atribuição dos números ao CI 4511
  constexpr byte REPETICOES = 20;
}

// Namespace que contém as variáveis globais do programa
namespace Variavel
{
  // É o vetor de quatro posições que armazena os 
  // bits a serem escritos no CI 4511
  byte bits[4];
}

void setup() 
{
  // Gera uma semente aleatória de randomização
  // para que os números gerados sejam diferentes
  // a cada execução do programa  
  randomSeed(analogRead(0));

  // Definição dos pinos
  pinMode(Constante::BOTAO, INPUT_PULLUP);
  pinMode(Constante::A, OUTPUT);
  pinMode(Constante::B, OUTPUT);
  pinMode(Constante::C, OUTPUT);
  pinMode(Constante::D, OUTPUT);
}

void loop() 
{
  // Faz a leitura do estado do botão a cada ciclo do loop 
  bool botaoPressionado = digitalRead(Constante::BOTAO);

  // Se o botão não estiver pressionado, o loop não continuará
  if(not botaoPressionado)
  { return; }

  // Senão...
  for(byte i = 1; i <= Constante::REPETICOES; ++i)
  {
    // Inicializando ou limpando os bits que serão 
    // atribuídos aos pinos do CI
    limpaBits(Variavel::bits);

    // O valor mínimo é Constante::VALOR_MINIMO e o máximo é Constante::VALOR_MAXIMO.
    // Adiciona-se uma unidade a Constante::VALOR_MAXIMO pela propriedade exclusiva
    // do número máximo recebido pela função random. Note que valores menores que 0
    // e maiores que 9 geram comportamento indefinido.
    byte numeroGerado = random(Constante::VALOR_MINIMO, Constante::VALOR_MAXIMO + 1);

    // Realizar a geração e atribuição dos bits várias vezes
    // dará um efeito visual satisfatório no display
    decimalParaBinario(numeroGerado, Variavel::bits);

    // Os bits convertidos são escritos nos pinos do CI 4511
    escritaNosPinos(Variavel::bits);

    // Mapeia da porcentagem de conclusão do loop for para um delay entre 0 e DELAY_MAXIMO_GERACOES, o valor mapeado
    // aumentará conforme o loop vai chegando ao fim, isso gera um efeito de animação interessante no display.
    long delayAtual = map(i, 0, Constante::REPETICOES, 0, Constante::DELAY_MAXIMO_GERACOES);

    delay(delayAtual);
  }
}

/// Define todos os bits do vetor como zero
void limpaBits(byte* bits)
{
  bits[0] = 0;
  bits[1] = 0;
  bits[2] = 0;
  bits[3] = 0;
}

/// Recebe um número na base decimal e um vetor como entrada.
/// Cada posição do vetor receberá um bit do número resultante.
/// Nota-se que o vetor estará invertido, isto é, o dígito mais
/// significativo estará na posição 0, e os demais, nas que se sucedem.
/// Leia o arquivo README.md para mais informações sobre a conversão.
void decimalParaBinario(byte decimal, byte* vetorBinario)
{
  byte posicao = 0;

  while(decimal > 1)
  {
    vetorBinario[posicao] = decimal % 2;

    decimal /= 2;

    ++posicao;
  }

  vetorBinario[posicao] = decimal;
}

/// Escreve nos pinos DCBA do CI 4511 os valores dos bits do vetor 
void escritaNosPinos(const byte* bits)
{
  // No caso da conversão realizada, o vetor resultante está em ordem
  // direta, i.e., a posição 0 contém o bit menos significativo. 
  digitalWrite(Constante::A, bits[0]);
  digitalWrite(Constante::B, bits[1]);
  digitalWrite(Constante::C, bits[2]);
  digitalWrite(Constante::D, bits[3]);
}
