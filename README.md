# MCLAB2
# Autor: Bruno Pires Lourenço

1. INTRODUÇÃO

   Os microprocessadores fazem parte do cotidiano das pessoas em tarefas consideradas básicas, como acordar, dirigir, entre outras. Também, são utilizados em grande escala, como em operações nas indústrias. Por isso, é necessário entender um sistema micro processado para, então, aprender a programa-lo para executar uma
determinada tarefa. O presente trabalho se utilizou do PIC16F877A para o desenvolvimento do projeto que exibe a quantidade de vezes no qual o botão S1 da placa MClab2 foi pressionado. Quando esse contador chega ao valor 9, ele zera a contagem.

2. O PROJETO

   Como supracitado, deve ser exibida a quantidade de vezes no qual o botão S1 foi pressionado. Para isso, foi, primeiramente, desenvolvido o código em linguagem C. A partir das aulas mencionadas pelo professor Júlio Ruzicki, foram deixadas algumas opções de configuração desabilitadas. Assim, selecionou-se a opção em configuration bits (bits de configuração) e marcou-se a opção OFF para todas as opções, exceto a opção Oscillator Selection bits, na qual marcou-se a opção HS. Após, foi definida a frequência como 8MHz. Para a execução do programa, deixou-se o comando while sempre verdadeiro fazendo, assim, que o programa nunca pare de ser executado (enquanto ele não for fechado). Depois, foi inserido o comando If que informa que se o botão S1 for pressionado, o trecho de código após ele é executado. Com isso, foi utilizado o comando switch-case, que se baseia na variável auxiliar “var”. Quando essa variável é uma das opções entre 1 e 9, o display de sete segmentos acende, referenciando o número de vezes no qual o botão S1 foi pressionado. Para a visualização correta de quais led’s acenderiam, foi utilizado o diagrama que se encontra em anexo a este trabalho, cujo recorte pode ser visto na figura 1.
   ![Recorte do diagrama da placa]()
   A cada execução do comando case, a variável era incrementada em 1, fazendo com que o na próxima vez que fosse pressionado, fosse representado o número correto. Foi inserido, também, um delay de 250ms após cada pressionamento para que fosse possível de se visualizar corretamente os dígitos. A figura 2 representa o momento após o terceiro pressionamento de S1, no qual o dígito 3 aparece no display.
   ![Representação do dígito quando o botão S1 foi pressionado 3 vezes]()
