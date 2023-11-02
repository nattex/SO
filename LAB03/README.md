## Atividade Lab03
1. Criar arquivos na linguagem c Através do vi usando o comando vi nome_do_arquivo.c
2. Compilar o codigo através do gcc utilizando o comando gcc -o "nome_do_executavel_a_ser_criado" "nome_do_arquivo.c"
3. Executar o arquivo compilado com o comando ./"nome_arquivo_executavel". 

## Atividade Lab03b
1. Criar arquivos na linguagem c Através do vi usando o comando vi nome_do_arquivo.c
2. Compilar o codigo através do gcc utilizando o comando gcc -o "nome_do_executavel_a_ser_criado" "nome_do_arquivo.c"
3. Executar o arquivo compilado com o comando ./"nome_arquivo_executavel".

Execicios Lab03b
1-
a) A principal diferença entre essa implementação e a anterior é a adição do Mutex para proteger a variável compartilhada sum. Isso é necessário porque várias threads podem tentar atualizar sum ao mesmo tempo, levando a uma condição de corrida. O Mutex garante que apenas uma thread possa atualizar sum de cada vez.
b) As divergências nos valores calculados de pi podem ser causadas por erros de arredondamento e pela ordem na qual as threads atualizam a variável sum. Como cada thread calcula uma parte da série e as atualizações em sum não são necessariamente feitas na ordem correta da série, isso pode levar a pequenas variações no valor final de pi. A adição do Mutex ajuda a mitigar esse problema garantindo que as atualizações em sum sejam feitas uma de cada vez, mas ainda pode haver variações devido à ordem das atualizações.
