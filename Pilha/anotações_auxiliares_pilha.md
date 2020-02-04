# Anotações auxiliares Pilha

- Existe a possibilidade de implementar uma pilha ou qualquer estrutura sem definir o tipo do elemento que será armazenado, int, float, short e etc.

- Podemos usar macros, que são funções que são interpretadas em tempo de compilação.

- Compilamos na seguinte maneira:

        $ gcc -o exex codigo.c -Dtipo=0;

- No código fazemos isso:

    No preambulo, depois dos includes.

        #if tipo == 0
        #define item char
        #elif tipo == 1
        #define item int
        #elif tipo == 2
        #endif

<strong>OBS : #if é a macro condicional e #define define constantes seguidas de valores</strong>

- Alteramos entao a struct dessa forma

        typedef struct pilha{
            item *dados;
            int topo;
            int N;
        }pilha;
