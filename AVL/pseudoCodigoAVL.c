funcao de insercao -> recebe a arvore, elemento a ser inserido
verifica se não existem mais filhos (direito ou esquerdo)
  se sim
    insere o elemento
    nó balanceamento = 0



  verifica se o tamanho da arvore é 0
    se sim
      insere o elemento e faz o inicio da arvore apontar para ele
    se não
      verifica se o elemento > que a raiz
        se sim
          funcao de insercao -> recebe raiz->direita, elemento a ser inserido
        se nao
          funcao de insercao -> recebe raiz->esquerda, elemento e ser inserido





funcao de balanceamento -> recebe o nó
  verifica se tamanho da sub direita - tamanho da sub esquerda > 1
    se sim
      verifica se o tamanho da sub direita do filho for maior que o da esquerda
        se sim
          realiza rotacao simples para a esquerda
        se não
          realiza rotacao dupla para a esquerda
    se nao, se a diferença for < 2
      se sim
        verifica se o tamanho da sub direita do filho for menor que o da esquerda
          se sim
            rotacao dupla para a direita
          se nao
            rotacao simples para direita
