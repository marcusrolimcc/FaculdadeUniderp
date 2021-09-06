# criptogramadecesar

Um programa de criptografia, onde se registra uma mensagem até 30 caracteres, de letras e números, e se exibe criptografia da mensagem, ou a mensagem original.

As opções do programa são:
0 - SAIR
1 - ADICIONAR MENSAGEM
2 - EXIBIR CRIPTOGRAFIA DA MENSAGEM
3 - EXIBIR A MENSAGEM ORIGINAL

Descrição:

A implementação desse sistema pode ser criada com base na troca de caracteres, usando a ideia do criptograma de César, com base no vocabulário. É passada uma chave (um número) e a letra digitada é alterada pela letra que se situa na posição indicada pela chave. 

A chave do algoritmo será a seguinte: Para cada letra digitada, você deverá incrementar as letras cinco caracteres para frente, por exemplo: a criptografia da letra 'a' será a letra 'f', para a letra 'b' a criptografia será a letra 'g' e assim sucessivamente. Para a letra 'v' a criptografia será a letra 'a', para a letra '' será a letra 'b' e assim por diante. 

Considere também letras maiúsculas e minúsculas, por exemplo, a criptografia da letra 'a' corresponde a letra 'f' e a criptografia da ltra 'A' corresponde a letra 'F'.

No caso dos números eles deverão ser decrementados em três dígitos. Por exemplo o número '1' será criptografado para '8', o número '2' para '9'. No caso do número '8' ele será criptografado para '5', o número '9' para '6'. Lembrando que a ordem dos números segue: de 0 até 9.

Programa foi construido para trabalho da matéria algoritmo e estrutura de dados do terceiro semestre de ciência da computação.

Entregue dia 28/05/2020

Explicação passo a passo em meu blog: https://www.marcusrolim.com.br/criptograma-de-cesar-algoritmo-criptografia/
