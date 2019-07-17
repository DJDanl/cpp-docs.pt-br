---
title: '&lt;iterator&gt;'
ms.date: 11/04/2016
f1_keywords:
- <iterator>
- iterator/std::<iterator>
helpviewer_keywords:
- iterator header
ms.assetid: c61a3962-f3ed-411a-b5a3-e8b3c2b500bd
ms.openlocfilehash: f859c2e11d8a800c44b93e69e4b862300c6d3a13
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68245777"
---
# <a name="ltiteratorgt"></a>&lt;iterator&gt;

Define primitivos de iterador, iteradores predefinidos e iteradores de fluxo, bem como vários modelos de suporte. Os iteradores predefinidos incluem adaptadores de inserção e inversão. Há três classes de adaptadores de iterador de inserção: anterior, posterior e geral. Eles fornecem semântica de inserção, no lugar da semântica de substituição fornecida pelos iteradores da função membro de contêiner.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="remarks"></a>Comentários

Os iteradores são uma generalização dos ponteiros, abstraídos dos seus requisitos de uma maneira que permite que o programa C++ funcione com estruturas de dados diferentes de maneira uniforme. Os iteradores atuam como intermediários entre contêineres e algoritmos genéricos. Em vez de operar em tipos de dados específicos, os algoritmos são definidos para operar em um intervalo especificado por um tipo de iterador. Qualquer estrutura de dados que atenda aos requisitos do iterador pode ser operada pelo algoritmo. Há cinco tipos ou categorias de iterador, cada um com seu próprio conjunto de requisitos e funcionalidade resultante:

- Saída: movimento para frente, pode armazenar, mas não recuperar valores fornecidos por ostream e inserter.

- Entrada: movimento para frente, pode recuperar mas não armazenar valores fornecidos por istream.

- Avançar: movimento para frente, pode armazenar e recuperar valores.

- Bidirecional: movimento para trás e para frente, pode armazenar e recuperar valores fornecidos por list, set, multiset, map e multimap.

- Acesso aleatório: os elementos acessados em qualquer ordem podem armazenar e recuperar valores fornecidos por vector, deque, string e array.

Os iteradores que têm mais requisitos e um acesso mais avançado a elementos podem ser usados no lugar de iteradores com menos requisitos. Por exemplo, se um iterador de avanço for chamado, um iterador de acesso aleatório poderá usado em seu lugar.

O Visual Studio adicionou extensões aos iteradores da Biblioteca Padrão do C++ para oferecer suporte a várias situações de modo de depuração para iteradores verificados e não verificados. Para obter mais informações, consulte [bibliotecas seguras: C++Biblioteca padrão](../standard-library/safe-libraries-cpp-standard-library.md).

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

|||
|-|-|
|[advance](../standard-library/iterator-functions.md#advance)|Aumenta um iterador por um número especificado de posições.|
|[back_inserter](../standard-library/iterator-functions.md#back_inserter)|Cria um iterador que pode inserir elementos no fim de um contêiner especificado.|
|[begin](../standard-library/iterator-functions.md#begin)|Recupera um iterador para o primeiro elemento em um contêiner especificado.|
|[cbegin](../standard-library/iterator-functions.md#cbegin)|Recupera um iterador constante para o primeiro elemento em um contêiner especificado.|
|[cend](../standard-library/iterator-functions.md#cend)|Recupera um iterador constante para o elemento que segue o último elemento no contêiner especificado.|
|[crbegin](../standard-library/iterator-functions.md#crbegin)||
|[crend](../standard-library/iterator-functions.md#crend)||
|[data](../standard-library/iterator-functions.md#data)||
|[distance](../standard-library/iterator-functions.md#distance)|Determina o número de incrementos entre as posições tratadas por dois iteradores.|
|[end](../standard-library/iterator-functions.md#end)|Recupera um iterador para o elemento que segue o último elemento no contêiner especificado.|
|[empty](../standard-library/iterator-functions.md#empty)||
|[front_inserter](../standard-library/iterator-functions.md#front_inserter)|Cria um iterador que pode inserir elementos na frente de um contêiner especificado.|
|[inserter](../standard-library/iterator-functions.md#inserter)|Um adaptador de iterador que adiciona um novo elemento a um contêiner em um ponto de inserção especificado.|
|[make_checked_array_iterator](../standard-library/iterator-functions.md#make_checked_array_iterator)|Cria um [checked_array_iterator](../standard-library/checked-array-iterator-class.md) que pode ser usado por outros algoritmos. **Observação:**  Essa função é uma extensão da Biblioteca Padrão do C++ da Microsoft. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.|
|[make_move_iterator](../standard-library/iterator-functions.md#make_move_iterator)|Retorna um iterador de movimentação que contém o iterador fornecido como o seu iterador de base armazenado.|
|[make_unchecked_array_iterator](../standard-library/iterator-functions.md#make_unchecked_array_iterator)|Cria um [unchecked_array_iterator](../standard-library/unchecked-array-iterator-class.md) que pode ser usado por outros algoritmos. **Observação:**  Essa função é uma extensão da Biblioteca Padrão do C++ da Microsoft. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.|
|[next](../standard-library/iterator-functions.md#next)|Itera um número de vezes especificado e retorna a nova posição do iterador.|
|[prev](../standard-library/iterator-functions.md#prev)|Itera em ordem inversa um número de vezes especificado e retorna a nova posição do iterador.|
|[rbegin](../standard-library/iterator-functions.md#rbegin)||
|[rend](../standard-library/iterator-functions.md#rend)||
|[size](../standard-library/iterator-functions.md#size)||

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/iterator-operators.md#op_neq)|Testa se o objeto de iterador à esquerda do operador não é igual ao objeto de iterador à direita.|
|[operator==](../standard-library/iterator-operators.md#op_eq_eq)|Testa se o objeto de iterador à esquerda do operador é igual ao objeto de iterador à direita.|
|[operator<](../standard-library/iterator-operators.md#op_lt)|Testa se o objeto de iterador à esquerda do operador é menor que o objeto de iterador à direita.|
|[operator\<=](../standard-library/iterator-operators.md#op_gt_eq)|Testa se o objeto de iterador à esquerda do operador é menor ou igual ao objeto de iterador à direita.|
|[operator>](../standard-library/iterator-operators.md#op_gt)|Testa se o objeto de iterador à esquerda do operador é maior que o objeto de iterador à direita.|
|[operator>=](../standard-library/iterator-operators.md#op_gt_eq)|Testa se o objeto de iterador à esquerda do operador é maior ou igual ao objeto de iterador à direita.|
|[operator+](../standard-library/iterator-operators.md#op_add)|Adiciona um deslocamento a um iterador e retorna o novo `reverse_iterator` que trata o elemento inserido na nova posição de deslocamento.|
|[operator-](../standard-library/iterator-operators.md#operator-)|Subtrai um iterador de outro e retorna a diferença.|

### <a name="classes"></a>Classes

|||
|-|-|
|[back_insert_iterator](../standard-library/back-insert-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída. Insere elementos em um contêiner do tipo `Container`, que acessa por meio de protegido `pointer` contêiner chamado de objeto que armazena.|
|[bidirectional_iterator_tag](../standard-library/bidirectional-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para um `iterator_category` função que representa um iterador bidirecional.|
|[checked_array_iterator](../standard-library/checked-array-iterator-class.md)|Uma classe que acessa uma matriz usando um iterador verificado de acesso aleatório. **Observação:**  Essa classe é uma extensão da Microsoft da Biblioteca Padrão C++. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.|
|[forward_iterator_tag](../standard-library/forward-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para um `iterator_category` função que representa um iterador de avanço.|
|[front_insert_iterator](../standard-library/front-insert-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída. Insere elementos em um contêiner do tipo `Container`, que acessa por meio de protegido `pointer` contêiner chamado de objeto que armazena.|
|[input_iterator_tag](../standard-library/input-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para um `iterator_category` função que representa um iterador de entrada.|
|[insert_iterator](../standard-library/insert-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída. Insere elementos em um contêiner do tipo `Container`, que acessa por meio de protegido `pointer` contêiner chamado de objeto que armazena. Ele também armazena protegido `iterator` objeto da classe `Container::iterator`, chamado `iter`.|
|[istream_iterator](../standard-library/istream-iterator-class.md)|A classe de modelo descreve um objeto de iterador de entrada. Ele extrai objetos da classe `Ty` de um fluxo de entrada, que acessa por meio de um objeto que armazena, do tipo pointer para `basic_istream` \< **Elem**, **Tr**>.|
|[istreambuf_iterator](../standard-library/istreambuf-iterator-class.md)|A classe de modelo descreve um objeto de iterador de entrada. Insere elementos da classe `Elem` em um buffer de fluxo de saída, que acessa por meio de um objeto que armazena, do tipo `pointer` à `basic_streambuf` \< **Elem**, **Tr** >.|
|[iterator](../standard-library/iterator-struct.md)|A classe de modelo é usada como um tipo base para todos os iteradores.|
|[iterator_traits](../standard-library/iterator-traits-struct.md)|Uma classe auxiliar de modelo que fornece os tipos importantes associados aos diferentes tipos de iterador, de modo que eles possam ser referenciados da mesma forma.|
|[move_iterator](../standard-library/move-iterator-class.md)|Um objeto `move_iterator` armazena um iterador de acesso aleatório do tipo `RandomIterator`. Comporta-se como um iterador de acesso aleatório, exceto quando desreferenciado. O resultado de `operator*` é implicitamente convertido em `value_type&&:` para criar uma `rvalue reference`.|
|[ostream_iterator](../standard-library/ostream-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída. Insere objetos da classe `Type` em um fluxo de saída, que acessa por meio de um objeto que armazena, do tipo `pointer` à `basic_ostream` \< **Elem**, **Tr**>.|
|[Classe ostreambuf_iterator](../standard-library/ostreambuf-iterator-class.md)|A classe de modelo descreve um objeto de iterador de saída. Insere elementos da classe `Elem` em um buffer de fluxo de saída, que acessa por meio de um objeto que armazena, do tipo pointer para `basic_streambuf` \< **Elem**, **Tr**>.|
|[output_iterator_tag](../standard-library/output-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para `iterator_category` função que representa um iterador de saída.|
|[random_access_iterator_tag](../standard-library/random-access-iterator-tag-struct.md)|Uma classe que fornece um tipo de retorno para `iterator_category` função que representa um iterador de acesso aleatório.|
|[reverse_iterator](../standard-library/reverse-iterator-class.md)|A classe de modelo descreve um objeto que se comporta como um iterador de acesso aleatório, somente em ordem inversa.|
|[unchecked_array_iterator](../standard-library/unchecked-array-iterator-class.md)|Uma classe que acessa uma matriz usando um iterador não verificado de acesso aleatório. **Observação:**  Essa classe é uma extensão da Microsoft da Biblioteca Padrão C++. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
