---
title: "&lt;iterator&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::<iterator>"
  - "std.<iterator>"
  - "<iterator>"
  - "iterator/std::<iterator>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho iterator"
ms.assetid: c61a3962-f3ed-411a-b5a3-e8b3c2b500bd
caps.latest.revision: 27
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;iterator&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define primitivos de iterador, iteradores predefinidos e iteradores de fluxo, bem como vários modelos de suporte.  Os iteradores predefinidos incluem adaptadores de inserção e inversão.  Há três classes de adaptadores de iterador de inserção: anterior, posterior e geral.  Eles fornecem semântica de inserção, no lugar da semântica de substituição fornecida pelos iteradores da função membro de contêiner.  
  
## Sintaxe  
  
```  
  
#include <iterator>  
  
```  
  
## Comentários  
 Os iteradores são uma generalização dos ponteiros, abstraídos dos seus requisitos de uma maneira que permite que o programa C\+\+ funcione com estruturas de dados diferentes de maneira uniforme.  Os iteradores atuam como intermediários entre contêineres e algoritmos genéricos.  Em vez de operar em tipos de dados específicos, os algoritmos são definidos para operar em um intervalo especificado por um tipo de iterador.  Qualquer estrutura de dados que atenda aos requisitos do iterador pode ser operada pelo algoritmo.  Há cinco tipos ou categorias de iterador, cada um com seu próprio conjunto de requisitos e funcionalidade resultante:  
  
-   Saída: movimento para frente, pode armazenar, mas não recuperar valores fornecidos por ostream e inserter.  
  
-   Entrada: movimento para frente, pode recuperar mas não armazenar valores fornecidos por istream.  
  
-   Avançar: movimento para frente, pode armazenar e recuperar valores.  
  
-   Bidirecional: movimento para trás e para frente, pode armazenar e recuperar valores fornecidos por list, set, multiset, map e multimap.  
  
-   Acesso aleatório: os elementos acessados em qualquer ordem podem armazenar e recuperar valores fornecidos por vector, deque, string e array.  
  
 Os iteradores que têm mais requisitos e um acesso mais avançado a elementos podem ser usados no lugar de iteradores com menos requisitos.  Por exemplo, se um iterador de avanço for chamado, um iterador de acesso aleatório poderá usado em seu lugar.  
  
 O Visual Studio adicionou extensões aos iteradores da Biblioteca Padrão do C\+\+ para oferecer suporte a várias situações de modo de depuração para iteradores verificados e não verificados.  Para obter mais informações, consulte [Bibliotecas seguras: Biblioteca Padrão C\+\+](../standard-library/safe-libraries-cpp-standard-library.md).  
  
### Funções  
  
|||  
|-|-|  
|[advance](../Topic/advance.md)|Aumenta um iterador por um número especificado de posições.|  
|[back\_inserter](../Topic/back_inserter.md)|Cria um iterador que pode inserir elementos no fim de um contêiner especificado.|  
|[begin](../Topic/begin.md)|Recupera um iterador para o primeiro elemento em um contêiner especificado.|  
|[cbegin](../Topic/cbegin.md)|Recupera um iterador constante para o primeiro elemento em um contêiner especificado.|  
|[cend](../Topic/cend.md)|Recupera um iterador constante para o elemento que segue o último elemento no contêiner especificado.|  
|[distance](../Topic/distance.md)|Determina o número de incrementos entre as posições tratadas por dois iteradores.|  
|[end](../Topic/end.md)|Recupera um iterador para o elemento que segue o último elemento no contêiner especificado.|  
|[front\_inserter](../Topic/front_inserter.md)|Cria um iterador que pode inserir elementos na frente de um contêiner especificado.|  
|[inserter](../Topic/inserter.md)|Um adaptador de iterador que adiciona um novo elemento a um contêiner em um ponto de inserção especificado.|  
|[make\_checked\_array\_iterator](../Topic/make_checked_array_iterator.md)|Cria um [checked\_array\_iterator](../standard-library/checked-array-iterator-class.md) que pode ser usado por outros algoritmos. **Note:**  Essa função é uma extensão da Biblioteca Padrão do C\+\+ da Microsoft.  O código implementado usando essa função não é portátil para ambientes de criação do C\+\+ Standard que não oferecem suporte a essa extensão da Microsoft.|  
|[make\_move\_iterator](../Topic/make_move_iterator.md)|Retorna um iterador de movimentação que contém o iterador fornecido como o seu iterador de base armazenado.|  
|[make\_unchecked\_array\_iterator](../Topic/make_unchecked_array_iterator.md)|Cria um [unchecked\_array\_iterator](../standard-library/unchecked-array-iterator-class.md) que pode ser usado por outros algoritmos. **Note:**  Essa função é uma extensão da Biblioteca Padrão do C\+\+ da Microsoft.  O código implementado usando essa função não é portátil para ambientes de criação do C\+\+ Standard que não oferecem suporte a essa extensão da Microsoft.|  
|[next](../Topic/next.md)|Itera um número de vezes especificado e retorna a nova posição do iterador.|  
|[prev](../Topic/prev.md)|Itera em ordem inversa um número de vezes especificado e retorna a nova posição do iterador.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\!\=](../Topic/operator!=%20\(%3Citerator%3E\).md)|Testa se o objeto de iterador à esquerda do operador não é igual ao objeto de iterador à direita.|  
|[operator\=\=](../Topic/operator==%20\(%3Citerator%3E\).md)|Testa se o objeto de iterador à esquerda do operador é igual ao objeto de iterador à direita.|  
|[operator\<](../Topic/operator%3C%20\(%3Citerator%3E\).md)|Testa se o objeto de iterador à esquerda do operador é menor que o objeto de iterador à direita.|  
|[operator\<\=](../Topic/operator%3C=%20\(%3Citerator%3E\).md)|Testa se o objeto de iterador à esquerda do operador é menor ou igual ao objeto de iterador à direita.|  
|[operator\>](../Topic/operator%3E%20\(%3Citerator%3E\).md)|Testa se o objeto de iterador à esquerda do operador é maior que o objeto de iterador à direita.|  
|[operator\>\=](../Topic/operator%3E=%20\(%3Citerator%3E\).md)|Testa se o objeto de iterador à esquerda do operador é maior ou igual ao objeto de iterador à direita.|  
|[operator\+](../Topic/operator+%20\(%3Citerator%3E\).md)|Adiciona um deslocamento a um iterador e retorna o novo `reverse_iterator` que trata o elemento inserido na nova posição de deslocamento.|  
|[operator\-](../Topic/operator-%20\(%3Citerator%3E\).md)|Subtrai um iterador de outro e retorna a diferença.|  
  
### Classes  
  
|||  
|-|-|  
|[back\_insert\_iterator](../standard-library/back-insert-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída.  Insere elementos em um contêiner do tipo **Container**, que acessa por meio do objeto **pointer** protegido que é armazenado no contêiner chamado.|  
|[bidirectional\_iterator\_tag](../Topic/bidirectional_iterator_tag%20Struct.md)|Uma classe que fornece um tipo de retorno para uma função **iterator\_category**, que representa um iterador bidirecional.|  
|[checked\_array\_iterator](../standard-library/checked-array-iterator-class.md)|Uma classe que acessa uma matriz usando um iterador verificado de acesso aleatório. **Note:**  Essa classe é uma extensão da Biblioteca Padrão do C\+\+ da Microsoft.  O código implementado usando essa função não é portátil para ambientes de criação do C\+\+ Standard que não oferecem suporte a essa extensão da Microsoft.|  
|[forward\_iterator\_tag](../standard-library/forward-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para uma função **iterator\_category**, que representa um iterador de avanço.|  
|[front\_insert\_iterator](../standard-library/front-insert-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída.  Insere elementos em um contêiner do tipo **Container**, que acessa por meio do objeto **pointer** protegido que é armazenado no contêiner chamado.|  
|[input\_iterator\_tag](../standard-library/input-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para uma função **iterator\_category**, que representa um iterador de entrada.|  
|[insert\_iterator](../standard-library/insert-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída.  Insere elementos em um contêiner do tipo **Container**, que acessa por meio do objeto **pointer** protegido que é armazenado no contêiner chamado.  Também armazena o objeto **iterator** protegido, da classe **Container::iterator**, chamada **iter**.|  
|[istream\_iterator](../standard-library/istream-iterator-class.md)|A classe de modelo descreve um objeto de iterador de entrada.  Extrai os objetos da classe **Ty** de um fluxo de entrada, que acessa por meio de um objeto que armazena, do tipo pointer para `basic_istream`\<**Elem**, **Tr**\>.|  
|[istreambuf\_iterator](../standard-library/istreambuf-iterator-class.md)|A classe de modelo descreve um objeto de iterador de entrada.  Insere elementos da classe **Elem** em um buffer de fluxo de saída, que acessa por meio de um objeto que armazena, do tipo **pointer** para `basic_streambuf`\<**Elem**, **Tr**\>.|  
|[iterator](../Topic/iterator%20Struct.md)|A classe de modelo é usada como um tipo base para todos os iteradores.|  
|[iterator\_traits](../standard-library/iterator-traits-struct.md)|Uma classe auxiliar de modelo que fornece os tipos importantes associados aos diferentes tipos de iterador, de modo que eles possam ser referenciados da mesma forma.|  
|[move\_iterator](../standard-library/move-iterator-class.md)|Um objeto `move_iterator` armazena um iterador de acesso aleatório do tipo `RandomIterator`.  Comporta\-se como um iterador de acesso aleatório, exceto quando desreferenciado.  O resultado de `operator*` é implicitamente convertido em `value_type&&:` para criar uma `rvalue reference`.|  
|[ostream\_iterator](../standard-library/ostream-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída.  Insere objetos da classe **Type** em um fluxo de saída, o qual ela acessa por meio de um objeto armazenado por ele, do tipo **pointer** para `basic_ostream`\<**Elem**, **Tr**\>.|  
|[Classe ostreambuf\_iterator](../standard-library/ostreambuf-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída.  Insere elementos da classe **Elem** em um buffer de fluxo de saída, que acessa por meio de um objeto que armazena, do tipo pointer para `basic_streambuf`\<**Elem**, **Tr**\>.|  
|[output\_iterator\_tag](../standard-library/output-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para a função **iterator\_category**, que representa um iterador de saída.|  
|[random\_access\_iterator\_tag](../standard-library/random-access-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para a função **iterator\_category**, que representa um iterador de acesso aleatório.|  
|[reverse\_iterator](../standard-library/reverse-iterator-class.md)|A classe de modelo descreve um objeto que se comporta como um iterador de acesso aleatório, somente em ordem inversa.|  
|[unchecked\_array\_iterator](../standard-library/unchecked-array-iterator-class.md)|Uma classe que acessa uma matriz usando um iterador não verificado de acesso aleatório. **Note:**  Essa classe é uma extensão da Biblioteca Padrão do C\+\+ da Microsoft.  O código implementado usando essa função não é portátil para ambientes de criação do C\+\+ Standard que não oferecem suporte a essa extensão da Microsoft.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)