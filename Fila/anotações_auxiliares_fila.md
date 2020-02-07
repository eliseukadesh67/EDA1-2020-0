## Fila circular

- É como uma fila normal, porem o final da fila pode ser colocado no inicio se for implementada como um vetor.

### Estados da fila circular:

1. Vazia, quando o primeiro for igual ao ultimo.
2. Cheia, quando o primeiro for igual ao ultimo.

Podemos observar uma ambiguidade.

Para resolvermos, redefinimos o conceito de fila cheia de duas maneiras:

1. A fila está cheia quando primeiro = 0, e quando o ultimo = N-1; 

2. A fila está cheia quando o primeiro>0, e o utlimo = primeiro-1;

Ou seja: (ultimo+1)%N = P;