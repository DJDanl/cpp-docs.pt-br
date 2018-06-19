---
title: Classe hash_multimap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- hash_map/stdext::hash_multimap
- hash_map/stdext::hash_multimap::allocator_type
- hash_map/stdext::hash_multimap::const_iterator
- hash_map/stdext::hash_multimap::const_pointer
- hash_map/stdext::hash_multimap::const_reference
- hash_map/stdext::hash_multimap::const_reverse_iterator
- hash_map/stdext::hash_multimap::difference_type
- hash_map/stdext::hash_multimap::iterator
- hash_map/stdext::hash_multimap::key_compare
- hash_map/stdext::hash_multimap::key_type
- hash_map/stdext::hash_multimap::mapped_type
- hash_map/stdext::hash_multimap::pointer
- hash_map/stdext::hash_multimap::reference
- hash_map/stdext::hash_multimap::reverse_iterator
- hash_map/stdext::hash_multimap::size_type
- hash_map/stdext::hash_multimap::value_type
- hash_map/stdext::hash_multimap::begin
- hash_map/stdext::hash_multimap::cbegin
- hash_map/stdext::hash_multimap::cend
- hash_map/stdext::hash_multimap::clear
- hash_map/stdext::hash_multimap::count
- hash_map/stdext::hash_multimap::crbegin
- hash_map/stdext::hash_multimap::crend
- hash_map/stdext::hash_multimap::emplace
- hash_map/stdext::hash_multimap::emplace_hint
- hash_map/stdext::hash_multimap::empty
- hash_map/stdext::hash_multimap::end
- hash_map/stdext::hash_multimap::equal_range
- hash_map/stdext::hash_multimap::erase
- hash_map/stdext::hash_multimap::find
- hash_map/stdext::hash_multimap::get_allocator
- hash_map/stdext::hash_multimap::insert
- hash_map/stdext::hash_multimap::key_comp
- hash_map/stdext::hash_multimap::lower_bound
- hash_map/stdext::hash_multimap::max_size
- hash_map/stdext::hash_multimap::rbegin
- hash_map/stdext::hash_multimap::rend
- hash_map/stdext::hash_multimap::size
- hash_map/stdext::hash_multimap::swap
- hash_map/stdext::hash_multimap::upper_bound
- hash_map/stdext::hash_multimap::value_comp
dev_langs:
- C++
helpviewer_keywords:
- stdext::hash_multimap
- stdext::hash_multimap::allocator_type
- stdext::hash_multimap::const_iterator
- stdext::hash_multimap::const_pointer
- stdext::hash_multimap::const_reference
- stdext::hash_multimap::const_reverse_iterator
- stdext::hash_multimap::difference_type
- stdext::hash_multimap::iterator
- stdext::hash_multimap::key_compare
- stdext::hash_multimap::key_type
- stdext::hash_multimap::mapped_type
- stdext::hash_multimap::pointer
- stdext::hash_multimap::reference
- stdext::hash_multimap::reverse_iterator
- stdext::hash_multimap::size_type
- stdext::hash_multimap::value_type
- stdext::hash_multimap::begin
- stdext::hash_multimap::cbegin
- stdext::hash_multimap::cend
- stdext::hash_multimap::clear
- stdext::hash_multimap::count
- stdext::hash_multimap::crbegin
- stdext::hash_multimap::crend
- stdext::hash_multimap::emplace
- stdext::hash_multimap::emplace_hint
- stdext::hash_multimap::empty
- stdext::hash_multimap::end
- stdext::hash_multimap::equal_range
- stdext::hash_multimap::erase
- stdext::hash_multimap::find
- stdext::hash_multimap::get_allocator
- stdext::hash_multimap::insert
- stdext::hash_multimap::key_comp
- stdext::hash_multimap::lower_bound
- stdext::hash_multimap::max_size
- stdext::hash_multimap::rbegin
- stdext::hash_multimap::rend
- stdext::hash_multimap::size
- stdext::hash_multimap::swap
- stdext::hash_multimap::upper_bound
- stdext::hash_multimap::value_comp
ms.assetid: f41a6db9-67aa-43a3-a3c5-dbfe9ec3ae7d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c3b9e3ba7a7929158adacfab889007cb518c54b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849061"
---
# <a name="hashmultimap-class"></a>Classe hash_multimap

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

A classe de contêiner hash_multimap é uma extensão da Biblioteca Padrão C++ e é usada para o armazenamento e a recuperação rápida de dados de uma coleção em que cada elemento é um par que tem uma chave de classificação cujo valor não precisa ser único e ser um valor de dados associado.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key,
    class Type,
    class Traits=hash_compare <Key, less <Key>>,
    class Allocator=allocator <pair  <const Key, Type>>>
class hash_multimap
```

### <a name="parameters"></a>Parâmetros

`Key` O tipo de dados de chave a ser armazenado na hash_multimap.

`Type` O tipo de dados do elemento a ser armazenado na hash_multimap.

`Traits` O tipo que inclui dois objetos de função, uma classe `Traits` que é possível comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa e uma função de hash que é um unário valores de chave de predicado mapeamento dos elementos a serem inteiros sem sinal de tipo **size_t**. Esse argumento é opcional e o `hash_compare<Key, less<Key>>` é o valor padrão.

`Allocator` O tipo que representa o objeto de alocador armazenados que encapsula os detalhes sobre o hash_multimap alocação e desalocação de memória. Esse argumento é opcional e o valor padrão é `allocator<pair <const Key, Type>>`.

## <a name="remarks"></a>Comentários

O hash_multimap é:

- Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.

- Reversível, pois fornece um iterador bidirecional para acessar seus elementos.

- Com hash, pois seus elementos são agrupados em buckets com base no valor de uma função de hash aplicada aos valores chave dos elementos.

- Múltipla, pois seus elementos não precisam ter chaves exclusivas para que um valor de chave possa ter muitos valores de dados de elemento associados a ele.

- Um contêiner de par associativo, pois seus valores de elemento são distintos de seus valores de chave.

- Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos ou chaves. Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.

A principal vantagem do uso de hash em vez da classificação é a maior eficiência: um hash bem-sucedido executa inserções, exclusões e localizações em tempos médios constantes, em comparação com um tempo proporcional ao logaritmo do número de elementos no contêiner para técnicas de classificação. O valor de um elemento em um hash_multimap, mas não seu valor de chave associado, pode ser alterado diretamente. Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave associados aos novos elementos inseridos.

A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Contêineres associativos com hash são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que dão suporte explicitamente a essas operações são eficientes quando usadas com uma função de hash bem elaborada, executando-as em um tempo que é, em média, constante e não dependente do número de elementos no contêiner. Uma função de hash bem elaborada produz uma distribuição uniforme de valores em hash e minimiza o número de colisões, em que uma colisão deve ocorrer quando valores de chave distintos são mapeados para o mesmo valor em hash. No pior caso, com a pior função de hash possível, o número de operações será proporcional ao número de elementos na sequência (tempo linear).

O hash_multimap deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras-chave com valores de cadeia de caracteres associados que fornecem, por exemplo, definições, em que as palavras nem sempre foram definidas exclusivamente. Se, em vez disso, as palavras-chave foram definidas exclusivamente para que essas chaves fossem exclusivas, um hash_multimap seria o contêiner ideal. Se, por outro lado, apenas as listas de palavras estavam sendo armazenadas, um hash_set seria o contêiner correto. Se forem permitidas várias ocorrências das palavras, um hash_multiset seria a estrutura de contêiner apropriada.

O hash_multimap ordena a sequência que controla chamando um objeto `Traits` de hash armazenado do tipo [value_compare](../standard-library/value-compare-class.md). Esse objeto armazenado pode ser acessado chamando a função membro [key_comp](../standard-library/hash-map-class.md#key_comp). Um objeto de função deve se comportar da mesma forma que um objeto da classe [hash_compare](../standard-library/hash-compare-class.md)`<Key, less<Key>>`. Especificamente, para todos os valores de `Key` do tipo `Key`, a chamada `Traits (Key)` produz uma distribuição de valores do tipo `size_t`.

De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário f(x,y) é um objeto de função que tem dois objetos de argumento `x` e `y` e um valor retornado de `true` ou `false`. Uma ordenação imposta a um hash_multimap será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo e se a equivalência for transitiva, em que dois objetos `x` e `y` são definidos para serem equivalentes quando f( x, y) e f( y, x) forem `false`. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.

A ordem real dos elementos na sequência controlada depende da função de hash, da função de ordenação e do tamanho atual da tabela de hash armazenada no objeto de contêiner. Não é possível determinar o tamanho atual da tabela de hash, portanto, de modo geral, não é possível prever a ordem dos elementos na sequência controlada. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.

O iterador fornecido pela classe hash_multimap é um iterador bidirecional, mas as funções membro de classe [insert](#insert) e [hash_multimap](#hash_multimap) têm versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais reduzidos do que aqueles garantidos pela classe de iteradores bidirecionais. Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio hash_multimap de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições aos requisitos fornecidos por esse tipo de iterador. Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência. Esse é um hash_multimap mínimo de funcionalidades, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores `[First, Last)` no contexto de funções membro da classe.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[hash_multimap](#hash_multimap)|Constrói uma lista de um tamanho específico ou com elementos de um valor específico ou com um `allocator` específico ou como uma cópia de algum outro `hash_multimap`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para o objeto `hash_multimap`.|
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no `hash_multimap`.|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento `const` em um `hash_multimap`.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência para um elemento `const` armazenado em um `hash_multimap` para leitura e execução de operações `const`.|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no `hash_multimap`.|
|[difference_type](#difference_type)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um `hash_multimap` em um intervalo entre os elementos apontado pelos iteradores.|
|[iterator](#iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um `hash_multimap`.|
|[key_compare](#key_compare)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `hash_multimap`.|
|[key_type](#key_type)|Um tipo que descreve o objeto de chave de classificação que constitui cada elemento do `hash_multimap`.|
|[mapped_type](#mapped_type)|Um tipo que representa o tipo de dados armazenado em um `hash_multimap`.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento em um `hash_multimap`.|
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em um `hash_multimap`.|
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `hash_multimap` invertido.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `hash_multimap`.|
|[value_type](#value_type)|Um tipo que fornece um objeto de função que pode comparar dois elementos como chaves de classificação para determinar sua ordem relativa no `hash_multimap`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[begin](#begin)|Retorna um iterador que trata o primeiro elemento no `hash_multimap`.|
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento no `hash_multimap`.|
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em um `hash_multimap`.|
|[clear](#clear)|Apaga todos os elementos de um `hash_multimap`.|
|[count](#count)|Retorna o número de elementos em um `hash_multimap` cuja chave corresponde a uma chave especificada pelo parâmetro.|
|[crbegin](#crbegin)|Retorna um iterador const que trata o primeiro elemento em um `hash_multimap` invertido.|
|[crend](#crend)|Retorna um iterador const que trata o local após o último elemento em um `hash_multimap` invertido.|
|[emplace](#emplace)|Insere um elemento construído adequadamente em um `hash_multimap`.|
|[emplace_hint](#emplace_hint)|Insere um elemento construído adequadamente em um `hash_multimap`, com uma dica de posicionamento.|
|[empty](#empty)|Testa se `hash_multimap` está vazio.|
|[end](#end)|Retorna um iterador que trata o local após o último elemento em um `hash_multimap`.|
|[equal_range](#equal_range)|Retorna um iterador que trata o local após o último elemento em um `hash_multimap`.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um `hash_multimap` das posições especificadas|
|[find](#find)|Retorna um iterador que trata do local de um elemento em um `hash_multimap` que tem uma chave equivalente a uma chave especificada.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` usada para construir o `hash_multimap`.|
|[insert](#insert)|Insere um elemento ou um intervalo de elementos no `hash_multimap` na posição especificada.|
|[key_comp](#key_comp)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um `hash_multimap`.|
|[lower_bound](#lower_bound)|Retorna um iterador para o primeiro elemento em um `hash_multimap` com um valor de chave que é igual ou maior que uma chave especificada.|
|[max_size](#max_size)|Retorna o comprimento máximo do `hash_multimap`.|
|[rbegin](#rbegin)|Retorna um iterador que trata o primeiro elemento em um `hash_multimap` invertido.|
|[rend](#rend)|Retorna um iterador que trata o local após o último elemento em um `hash_multimap` invertido.|
|[size](#size)|Especifica um novo tamanho para um `hash_multimap`.|
|[swap](#swap)|Troca os elementos de dois `hash_multimap`s.|
|[upper_bound](#upper_bound)|Retorna um iterador para o primeiro elemento em um `hash_multimap` que tem um valor de chave que é maior que uma chave especificada.|
|[value_comp](#value_comp)|Recupera uma cópia do objeto de comparação usado para ordenar valores de elemento em um `hash_multimap`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[hash_multimap::operator=](#op_eq)|Substitui os elementos de um `hash_multimap` por uma cópia de outro `hash_multimap`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<hash_map>

**Namespace:** stdext

## <a name="allocator_type"></a>  hash_multimap::allocator_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que representa a classe allocator do objeto hash_multimap.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::allocator_type allocator_type;
```

### <a name="remarks"></a>Comentários

`allocator_type` é um sinônimo do parâmetro de modelo `Allocator`.

Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe hash_multimap](../standard-library/hash-multimap-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [get_allocator](#get_allocator) para obter um exemplo do uso de `allocator_type`.

## <a name="begin"></a>  hash_multimap::begin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador que trata do primeiro elemento no hash_multimap.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata do primeiro elemento no hash_multimap ou no local que sucede um hash_multimap vazio.

### <a name="remarks"></a>Comentários

Se o valor retornado de **begin** for atribuído a um `const_iterator`, os elementos no objeto hash_multimap não poderão ser modificados. Se o valor retornado de **begin** for atribuído a um **iterador**, os elementos no objeto hash_multimap poderão ser modificados.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_begin.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: iterator hm1_Iter;
   hash_multimap <int, int> :: const_iterator hm1_cIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 0, 0 ) );
   hm1.insert ( Int_Pair ( 1, 1 ) );
   hm1.insert ( Int_Pair ( 2, 4 ) );

   hm1_cIter = hm1.begin ( );
   cout << "The first element of hm1 is " << hm1_cIter -> first
        << "." << endl;

   hm1_Iter = hm1.begin ( );
   hm1.erase ( hm1_Iter );

   // The following 2 lines would err because the iterator is const
   // hm1_cIter = hm1.begin ( );
   // hm1.erase ( hm1_cIter );

   hm1_cIter = hm1.begin( );
   cout << "The first element of hm1 is now " << hm1_cIter -> first
        << "." << endl;
}
```

```Output
The first element of hm1 is 0.
The first element of hm1 is now 1.
```

## <a name="cbegin"></a>  hash_multimap::cbegin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador const que trata do primeiro elemento no hash_multimap.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional const que trata do primeiro elemento no [hash_multimap](../standard-library/hash-multimap-class.md) ou do local que sucede um `hash_multimap` vazio.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_cbegin.cpp
// compile with: /EHsc
#include <hash_multimap>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: const_iterator hm1_cIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 2, 4 ) );

   hm1_cIter = hm1.cbegin ( );
   cout << "The first element of hm1 is "
        << hm1_cIter -> first << "." << endl;
   }
```

```Output
The first element of hm1 is 2.
```

## <a name="cend"></a>  hash_multimap::cend

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador const que trata do local após o último elemento em um hash_multimap.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional const que trata do local após o último elemento em um [hash_multimap](../standard-library/hash-multimap-class.md). Se o `hash_multimap` estiver vazio, então `hash_multimap::cend == hash_multimap::begin`.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador atingiu o fim de seu hash_multimap.

O valor retornado por `cend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_cend.cpp
// compile with: /EHsc
#include <hash_multimap>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: const_iterator hm1_cIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_cIter = hm1.cend( );
   hm1_cIter--;
   cout << "The value of last element of hm1 is "
        << hm1_cIter -> second << "." << endl;
   }
```

```Output
The value of last element of hm1 is 30.
```

## <a name="clear"></a>  hash_multimap::clear

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Apaga todos os elementos de um hash_multimap.

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro hash_multimap::clear.

```cpp
// hash_multimap_clear.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, int> hm1;
    hash_multimap<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    hm1.insert(Int_Pair(1, 1));
    hm1.insert(Int_Pair(2, 4));

    i = hm1.size();
    cout << "The size of the hash_multimap is initially "
         << i  << "." << endl;

    hm1.clear();
    i = hm1.size();
    cout << "The size of the hash_multimap after clearing is "
         << i << "." << endl;
}
```

```Output
The size of the hash_multimap is initially 2.
The size of the hash_multimap after clearing is 0.
```

## <a name="const_iterator"></a>  hash_multimap::const_iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no hash_multimap.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_iterator const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

O `const_iterator` definido pelos pontos de hash_multimap para objetos de [value_type](#value_type), que são do tipo `pair` *\< ***constKey, tipo*** >*. O valor da chave está disponível por meio do primeiro par de membros e o valor do elemento mapeado está disponível por meio do segundo membro do par.

A referência a um `const_iterator` `cIter` apontando para um elemento em um hash_multimap, use o **->** operador.

Para acessar o valor de chave do elemento, use `cIter` -> **first**, que é equivalente a (\* `cIter`). **first**. Para acessar o valor dos dados mapeados do elemento, use `cIter` -> **second**, que é equivalente a (\* `cIter`). **first**.

### <a name="example"></a>Exemplo

Consulte o exemplo para [begin](#begin) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a>  hash_multimap::const_pointer

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um ponteiro para um elemento **const** em um hash_multimap.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto hash_multimap.

## <a name="const_reference"></a>  hash_multimap::const_reference

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece uma referência a um elemento **const** armazenado em um hash_multimap para leitura e execução de operações **const**.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::const_reference const_reference;
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_const_ref.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap<int, int> hm1;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );

   // Declare and initialize a const_reference &Ref1
   // to the key of the first element
   const int &Ref1 = ( hm1.begin( ) -> first );

   // The following line would cause an error because the
   // non-const_reference cannot be used to access the key
   // int &Ref1 = ( hm1.begin( ) -> first );

   cout << "The key of first element in the hash_multimap is "
        << Ref1 << "." << endl;

   // Declare and initialize a reference &Ref2
   // to the data value of the first element
   int &Ref2 = ( hm1.begin() -> second );

   cout << "The data value of 1st element in the hash_multimap is "
        << Ref2 << "." << endl;
}
```

```Output
The key of first element in the hash_multimap is 1.
The data value of 1st element in the hash_multimap is 10.
```

## <a name="const_reverse_iterator"></a>  hash_multimap::const_reverse_iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no hash_multimap.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_reverse_iterator const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar no hash_multimap em ordem inversa.

O `const_reverse_iterator` definido por hash_multimap aponta para objetos de [value_type](#value_type), que são do tipo `pair`*\<***const Key, Type>**, cujo primeiro membro é a chave do elemento e cujo segundo membro é a referência mapeada mantida pelo elemento.

A referência a um `const_reverse_iterator` `crIter` apontando para um elemento em um hash_multimap, use o **->** operador.

Para acessar o valor de chave do elemento, use `crIter` -> **first**, que é equivalente a (\* `crIter`). **first**. Para acessar o valor dos dados mapeados do elemento, use `crIter` -> **second**, que é equivalente a (\* `crIter`). **first**.

### <a name="example"></a>Exemplo

Veja o exemplo de [rend](#rend) para obter um exemplo de como declarar e usar o `const_reverse_iterator`.

## <a name="count"></a>  hash_multimap::count

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna o número de elementos em um hash_multimap cuja chave corresponde a uma chave especificada pelo parâmetro.

```cpp
size_type count(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

`key` A chave de elementos a serem correspondidos do hash_multimap.

### <a name="return-value"></a>Valor de retorno

1 se o hash_multimap tiver um elemento cuja chave de classificação corresponde à chave de parâmetro; 0 se o hash_multimap não tiver um elemento com uma chave correspondente.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos no intervalo

**[lower_bound (** `key` **), upper_bound (** `key` **) )**

com um valor de chave `key`.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro hash_multimap::count.

```cpp
// hash_multimap_count.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, int> hm1;
    hash_multimap<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    hm1.insert(Int_Pair(1, 1));
    hm1.insert(Int_Pair(2, 1));
    hm1.insert(Int_Pair(1, 4));
    hm1.insert(Int_Pair(2, 1));

    // Elements do not need to have unique keys in hash_multimap,
    // so duplicates are allowed and counted
    i = hm1.count(1);
    cout << "The number of elements in hm1 with a sort key of 1 is: "
         << i << "." << endl;

    i = hm1.count(2);
    cout << "The number of elements in hm1 with a sort key of 2 is: "
         << i << "." << endl;

    i = hm1.count(3);
    cout << "The number of elements in hm1 with a sort key of 3 is: "
         << i << "." << endl;
}
```

```Output
The number of elements in hm1 with a sort key of 1 is: 2.
The number of elements in hm1 with a sort key of 2 is: 2.
The number of elements in hm1 with a sort key of 3 is: 0.
```

## <a name="crbegin"></a>  hash_multimap::crbegin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador const que trata do primeiro elemento em um hash_multimap invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido const que trata do primeiro elemento em um [hash_multimap](../standard-library/hash-multimap-class.md) invertido ou que trata do que foi o último elemento do `hash_multimap` não invertido.

### <a name="remarks"></a>Comentários

`crbegin` é usado com um hash_multimap invertido, assim como [hash_multimap::begin](#begin) é usado com um `hash_multimap`.

Com o valor de retorno `crbegin`, o objeto `hash_multimap` não pode ser modificado.

`crbegin` pode ser usado para iterar em um `hash_multimap` no sentido inverso.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_crbegin.cpp
// compile with: /EHsc
#include <hash_multimap>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: const_reverse_iterator hm1_crIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_crIter = hm1.crbegin( );
   cout << "The first element of the reversed hash_multimap hm1 is "
        << hm1_crIter -> first << "." << endl;
}
```

```Output
The first element of the reversed hash_multimap hm1 is 3.
```

## <a name="crend"></a>  hash_multimap::crend

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador const que trata do local após o último elemento em um hash_multimap invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso const que trata da localização que vem após o último elemento em um [hash_multimap](../standard-library/hash-multimap-class.md) invertido (o local que precedeu o primeiro elemento no `hash_multimap` não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um hash_multimap invertido, assim como [hash_multimap::end](#end) é usado com um hash_multimap.

Com o valor de retorno `crend`, o objeto `hash_multimap` não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de seu hash_multimap.

O valor retornado por `crend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_crend.cpp
// compile with: /EHsc
#include <hash_multimap>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: const_reverse_iterator hm1_crIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_crIter = hm1.crend( );
   hm1_crIter--;
   cout << "The last element of the reversed hash_multimap hm1 is "
        << hm1_crIter -> first << "." << endl;
}
```

```Output
The last element of the reversed hash_multimap hm1 is 3.
```

## <a name="difference_type"></a>  hash_multimap::difference_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um hash_multimap em um intervalo entre os elementos apontado pelos iteradores.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::difference_type difference_type;
```

### <a name="remarks"></a>Comentários


          `difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` é geralmente usado para representar o número de elementos no intervalo *[ first, last)* entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte pelos contêineres reversíveis, como conjunto, a subtração entre iteradores só tem suporte pelos iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como vetor.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_difference_type.cpp
// compile with: /EHsc
#include <iostream>
#include <hash_map>
#include <algorithm>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, int> hm1;
    typedef pair<int, int> Int_Pair;

    hm1.insert(Int_Pair(2, 20));
    hm1.insert(Int_Pair(1, 10));
    hm1.insert(Int_Pair(3, 20));

    // The following will insert, because map keys
    // do not need to be unique
    hm1.insert(Int_Pair(2, 30));

    hash_multimap<int, int>::iterator hm1_Iter, hm1_bIter, hm1_eIter;
    hm1_bIter = hm1.begin();
    hm1_eIter = hm1.end();

    // Count the number of elements in a hash_multimap
    hash_multimap<int, int>::difference_type df_count = 0;
    hm1_Iter = hm1.begin();
    while (hm1_Iter != hm1_eIter)
    {
        df_count++;
        hm1_Iter++;
    }

    cout << "The number of elements in the hash_multimap hm1 is: "
         << df_count << "." << endl;

    cout << "The keys of the mapped elements are:";
    for (hm1_Iter= hm1.begin() ; hm1_Iter!= hm1.end();
        hm1_Iter++)
        cout << " " << hm1_Iter-> first;
    cout << "." << endl;

    cout << "The values of the mapped elements are:";
    for (hm1_Iter= hm1.begin() ; hm1_Iter!= hm1.end();
        hm1_Iter++)
        cout << " " << hm1_Iter-> second;
    cout << "." << endl;
}
```

```Output
The number of elements in the hash_multimap hm1 is: 4.
The keys of the mapped elements are: 1 2 2 3.
The values of the mapped elements are: 10 20 30 20.
```

## <a name="emplace"></a>  hash_multimap::emplace

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Insere um elemento construído em um hash_multimap.

```cpp
template <class ValTy>
iterator emplace(ValTy&& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`val`|O valor usado para construir um elemento a ser inserido no [hash_multimap](../standard-library/hash-multimap-class.md).|

### <a name="return-value"></a>Valor de retorno

A função membro `emplace` retorna um iterador que aponta para a posição em que o novo elemento foi inserido.

### <a name="remarks"></a>Comentários

O [hash_multimap::value_type](#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_emplace.cpp
// compile with: /EHsc
#include<hash_multimap>
#include<iostream>
#include <string>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, string> hm1;
    typedef pair<int, string> is1(1, "a");

    hm1.emplace(move(is1));
    cout << "After the emplace, hm1 contains:" << endl
      << " " << hm1.begin()->first
      << " => " << hm1.begin()->second
      << endl;
}
```

```Output
After the emplace insertion, hm1 contains:
 1 => a
```

## <a name="emplace_hint"></a>  hash_multimap::emplace_hint

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Insere um elemento construído em um hash_multimap, com uma dica de posicionamento.

```cpp
template <class ValTy>
iterator emplace_hint(
    const_iterator _Where,
    ValTy&& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`val`|O valor usado para construir um elemento a ser inserido no [hash_multimap](../standard-library/hash-multimap-class.md), a menos que o `hash_multimap` já contenha o elemento (ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente).|
|`_Where`|Uma dica relacionada ao local do qual se começa a procurar pelo ponto de inserção correto.|

### <a name="return-value"></a>Valor de retorno

A função membro [hash_multimap::emplace](#emplace) retorna um iterador que aponta para a posição em que o novo elemento foi inserido no `hash_multimap`.

### <a name="remarks"></a>Comentários

O [hash_multimap::value_type](#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_emplace_hint.cpp
// compile with: /EHsc
#include<hash_multimap>
#include<iostream>
#include <string>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, string> hm1;
    typedef pair<int, string> is1(1, "a");

    hm1.emplace(hm1.begin(), move(is1));
    cout << "After the emplace insertion, hm1 contains:" << endl
      << " " << hm1.begin()->first
      << " => " << hm1.begin()->second
      << endl;
}
```

```Output
After the emplace insertion, hm1 contains:
 1 => a
```

## <a name="empty"></a>  hash_multimap::empty

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Testa se um hash_multimap está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o hash_multimap estiver vazio; **false** se o hash_multimap não estiver vazio.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_empty.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1, hm2;

   typedef pair <int, int> Int_Pair;
   hm1.insert ( Int_Pair ( 1, 1 ) );

   if ( hm1.empty( ) )
      cout << "The hash_multimap hm1 is empty." << endl;
   else
      cout << "The hash_multimap hm1 is not empty." << endl;

   if ( hm2.empty( ) )
      cout << "The hash_multimap hm2 is empty." << endl;
   else
      cout << "The hash_multimap hm2 is not empty." << endl;
}
```

```Output
The hash_multimap hm1 is not empty.
The hash_multimap hm2 is empty.
```

## <a name="end"></a>  hash_multimap::end

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador que trata do local após o último elemento em um hash_multimap.

```cpp
const_iterator end() const;

iterator end();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata do local após o último elemento em um hash_multimap. Se o hash_multimap estiver vazio, hash_multimap::end == hash_multimap::begin.

### <a name="remarks"></a>Comentários

**end** é usado para testar se um iterador atingir o fim de seu hash_multimap.

O valor retornado por **end** não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_end.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: iterator hm1_Iter;
   hash_multimap <int, int> :: const_iterator hm1_cIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_cIter = hm1.end( );
   hm1_cIter--;
   cout << "The value of last element of hm1 is "
        << hm1_cIter -> second << "." << endl;

   hm1_Iter = hm1.end( );
   hm1_Iter--;
   hm1.erase ( hm1_Iter );

   // The following 2 lines would err because the iterator is const
   // hm1_cIter = hm1.end ( );
   // hm1_cIter--;
   // hm1.erase ( hm1_cIter );

   hm1_cIter = hm1.end( );
   hm1_cIter--;
   cout << "The value of last element of hm1 is now "
        << hm1_cIter -> second << "." << endl;
}
```

```Output
The value of last element of hm1 is 30.
The value of last element of hm1 is now 20.
```

## <a name="equal_range"></a>  hash_multimap::equal_range

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um par de iteradores, respectivamente, para o primeiro elemento em um hash_multimap com uma chave que é maior do que uma chave especificada e para o primeiro elemento no hash_multimap com uma chave igual ou maior que a chave.

```cpp
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento a ser comparada com a chave de classificação de um elemento do hash_multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um par de iteradores em que o primeiro é o [lower_bound](#lower_bound) da chave e o segundo é o [upper_bound](#upper_bound) da chave.

Para acessar o primeiro iterador de um par `pr` retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_equal_range.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   typedef hash_multimap <int, int> IntMMap;
   IntMMap hm1;
   hash_multimap <int, int> :: const_iterator hm1_RcIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );

   pair <IntMMap::const_iterator, IntMMap::const_iterator> p1, p2;
   p1 = hm1.equal_range( 2 );

   cout << "The lower bound of the element with "
        << "a key of 2\n in the hash_multimap hm1 is: "
        << p1.first -> second << "." << endl;

   cout << "The upper bound of the element with "
        << "a key of 2\n in the hash_multimap hm1 is: "
        << p1.second -> second << "." << endl;

   // Compare the upper_bound called directly
   hm1_RcIter = hm1.upper_bound( 2 );

   cout << "A direct call of upper_bound( 2 ) gives "
        << hm1_RcIter -> second << "," << endl
        << " matching the 2nd element of the pair"
        << " returned by equal_range( 2 )." << endl;

   p2 = hm1.equal_range( 4 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == hm1.end( ) ) && ( p2.second == hm1.end( ) ) )
      cout << "The hash_multimap hm1 doesn't have an element "
           << "with a key less than 4." << endl;
   else
      cout << "The element of hash_multimap hm1 with a key >= 40 is: "
           << p1.first -> first << "." << endl;
}
```

```Output
The lower bound of the element with a key of 2
 in the hash_multimap hm1 is: 20.
The upper bound of the element with a key of 2
 in the hash_multimap hm1 is: 30.
A direct call of upper_bound( 2 ) gives 30,
 matching the 2nd element of the pair returned by equal_range( 2 ).
The hash_multimap hm1 doesn't have an element with a key less than 4.
```

## <a name="erase"></a>  hash_multimap::erase

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Remove um elemento ou um intervalo de elementos em um hash_multimap das posições especificadas ou remove elementos que correspondem a uma chave especificada.

```cpp
iterator erase(iterator _Where);

iterator erase(iterator first, iterator last);

size_type erase(const key_type& key);
```

### <a name="parameters"></a>Parâmetros

`_Where` Posição do elemento a ser removido do hash_multimap.

`first` Posição do primeiro elemento removido o hash_multimap.

`last` Posição logo após o último elemento removido o hash_multimap.

`key` A chave de elementos a serem removidos do hash_multimap.

### <a name="return-value"></a>Valor de retorno

Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de qualquer elemento removido ou um ponteiro para o final do hash_multimap, se não houver tal elemento.

Para a terceira função membro, ele retorna o número de elementos que foram removidos do hash_multimap.

### <a name="remarks"></a>Comentários

As funções membro nunca geram uma exceção.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro hash_multimap::erase.

```cpp
// hash_multimap_erase.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, int> hm1, hm2, hm3;
    hash_multimap<int, int> :: iterator pIter, Iter1, Iter2;
    int i;
    hash_multimap<int, int>::size_type n;
    typedef pair<int, int> Int_Pair;

    for (i = 1; i < 5; i++)
    {
        hm1.insert(Int_Pair (i, i) );
        hm2.insert(Int_Pair (i, i*i) );
        hm3.insert(Int_Pair (i, i-1) );
    }

    // The 1st member function removes an element at a given position
    Iter1 = ++hm1.begin();
    hm1.erase(Iter1);

    cout << "After the 2nd element is deleted, "
         << "the hash_multimap hm1 is:";
    for (pIter = hm1.begin(); pIter != hm1.end(); pIter++)
        cout << " " << pIter -> second;
    cout << "." << endl;

    // The 2nd member function removes elements
    // in the range [ first,  last)
    Iter1 = ++hm2.begin();
    Iter2 = --hm2.end();
    hm2.erase(Iter1, Iter2);

    cout << "After the middle two elements are deleted, "
         << "the hash_multimap hm2 is:";
    for (pIter = hm2.begin(); pIter != hm2.end(); pIter++)
        cout << " " << pIter -> second;
    cout << "." << endl;

    // The 3rd member function removes elements with a given  key
    hm3.insert(Int_Pair (2, 5));
    n = hm3.erase(2);

    cout << "After the element with a key of 2 is deleted,\n"
         << " the hash_multimap hm3 is:";
    for (pIter = hm3.begin(); pIter != hm3.end(); pIter++)
        cout << " " << pIter -> second;
    cout << "." << endl;

    // The 3rd member function returns the number of elements removed
    cout << "The number of elements removed from hm3 is: "
         << n << "." << endl;

    // The dereferenced iterator can also be used to specify a key
    Iter1 = ++hm3.begin();
    hm3.erase(Iter1);

    cout << "After another element with a key equal to that of the"
         << endl;
    cout  << " 2nd element is deleted, "
          << "the hash_multimap hm3 is:";
    for (pIter = hm3.begin(); pIter != hm3.end(); pIter++)
        cout << " " << pIter -> second;
    cout << "." << endl;
}
```

```Output
After the 2nd element is deleted, the hash_multimap hm1 is: 1 3 4.
After the middle two elements are deleted, the hash_multimap hm2 is: 1 16.
After the element with a key of 2 is deleted,
 the hash_multimap hm3 is: 0 2 3.
The number of elements removed from hm3 is: 2.
After another element with a key equal to that of the
 2nd element is deleted, the hash_multimap hm3 is: 0 3.
```

## <a name="find"></a>  hash_multimap::find

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador que trata o primeiro local de um elemento em um hash_multimap que tem uma chave equivalente a uma chave especificada.

```cpp
iterator find(const Key& key);

const_iterator find(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

`key` A chave para correspondência com a chave de classificação de um elemento do hash_multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador que trata do primeiro local de um elemento com uma chave especificada ou do local que sucede o último elemento no hash_multimap se nenhuma correspondência for encontrada para a chave.

### <a name="remarks"></a>Comentários

A função membro retorna um iterador que trata de um elemento no hash_multimap, cuja chave de classificação é **equivalente** à chave de argumento em um predicado binário que induz uma ordenação com base em uma relação de comparação do tipo "menor que".

Se o valor retornado de **find** for atribuído a `const_iterator`, o objeto hash_multimap não poderá ser modificado. Se o valor retornado de **find** for atribuído a um **iterador**, o objeto do hash_multimap poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_find.cpp
// compile with: /EHsc
#include <iostream>
#include <hash_map>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, int> hm1;
    hash_multimap<int, int> :: const_iterator hm1_AcIter, hm1_RcIter;
    typedef pair<int, int> Int_Pair;

    hm1.insert(Int_Pair(1, 10));
    hm1.insert(Int_Pair(2, 20));
    hm1.insert(Int_Pair(3, 20));
    hm1.insert(Int_Pair(3, 30));

    hm1_RcIter = hm1.find(2);
    cout << "The element of hash_multimap hm1 with a key of 2 is: "
          << hm1_RcIter -> second << "." << endl;

    hm1_RcIter = hm1.find(3);
    cout << "The first element of hash_multimap hm1 with a key of 3 is: "
          << hm1_RcIter -> second << "." << endl;

    // If no match is found for the key, end() is returned
    hm1_RcIter = hm1.find(4);

    if (hm1_RcIter == hm1.end())
        cout << "The hash_multimap hm1 doesn't have an element "
             << "with a key of 4." << endl;
    else
        cout << "The element of hash_multimap hm1 with a key of 4 is: "
             << hm1_RcIter -> second << "." << endl;

    // The element at a specific location in the hash_multimap can be
    // found using a dereferenced iterator addressing the location
    hm1_AcIter = hm1.end();
    hm1_AcIter--;
    hm1_RcIter = hm1.find(hm1_AcIter -> first);
    cout << "The first element of hm1 with a key matching"
         << endl << "that of the last element is: "
         << hm1_RcIter -> second << "." << endl;

    // Note that the first element with a key equal to
    // the key of the last element is not the last element
    if (hm1_RcIter == --hm1.end())
        cout << "This is the last element of hash_multimap hm1."
             << endl;
    else
        cout << "This is not the last element of hash_multimap hm1."
             << endl;
}
```

```Output
The element of hash_multimap hm1 with a key of 2 is: 20.
The first element of hash_multimap hm1 with a key of 3 is: 20.
The hash_multimap hm1 doesn't have an element with a key of 4.
The first element of hm1 with a key matching
that of the last element is: 20.
This is not the last element of hash_multimap hm1.
```

## <a name="get_allocator"></a>  hash_multimap::get_allocator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna uma cópia do objeto alocador usado para construir o hash_multimap.

```cpp
Allocator get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

O alocador usado pelo hash_multimap.

### <a name="remarks"></a>Comentários

Alocadores para a classe hash_multimap especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_get_allocator.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int>::allocator_type hm1_Alloc;
   hash_multimap <int, int>::allocator_type hm2_Alloc;
   hash_multimap <int, double>::allocator_type hm3_Alloc;
   hash_multimap <int, int>::allocator_type hm4_Alloc;

   // The following lines declare objects
   // that use the default allocator.
   hash_multimap <int, int> hm1;
   hash_multimap <int, int> hm2;
   hash_multimap <int, double> hm3;

   hm1_Alloc = hm1.get_allocator( );
   hm2_Alloc = hm2.get_allocator( );
   hm3_Alloc = hm3.get_allocator( );

   cout << "The number of integers that can be allocated"
        << endl << " before free memory is exhausted: "
        << hm2.max_size( ) << "." << endl;

   cout << "The number of doubles that can be allocated"
        << endl << " before free memory is exhausted: "
        << hm3.max_size( ) <<  "." << endl;

   // The following line creates a hash_multimap hm4
   // with the allocator of hash_multimap hm1.
   hash_multimap <int, int> hm4( less<int>( ), hm1_Alloc );

   hm4_Alloc = hm4.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated by the other
   if( hm1_Alloc == hm4_Alloc )
   {
      cout << "The allocators are interchangeable."
           << endl;
   }
   else
   {
      cout << "The allocators are not interchangeable."
           << endl;
   }
}
```

## <a name="hash_multimap"></a>  hash_multimap::hash_multimap

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Cria um hash_multimap que está vazio ou que é uma cópia de todo ou de parte de algum outro hash_multimap.

```cpp
hash_multimap();

explicit hash_multimap(
    const Compare& Comp);

hash_multimap(
    const Compare& Comp,
    const Allocator& Al);

hash_multimap(
    const hash_multimap& Right);

hash_multimap(
    hash_multimap&& Right);

hash_multimap(
    initializer_list<Type> IList);

hash_multimap(
    initializer_list<Type> IList,
    const Compare& Comp);


hash_multimap(
    initializer_list<Type> IList,
    const Compare& Comp,
    const Allocator& Al);

template <class InputIterator>
hash_multimap(
 InputIterator First,
    InputIterator Last);

template <class InputIterator>
hash_multimap(
 InputIterator First,
    InputIterator Last,
    const Compare& Comp);

template <class InputIterator>
hash_multimap(
 InputIterator First,
    InputIterator Last,
    const Compare& Comp,
    const Allocator& Al);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`Al`|A classe do alocador de armazenamento a ser usado neste objeto de hash_multimap, cujo padrão é `Allocator`.|
|`Comp`|A função de comparação do tipo `const Traits` usada para ordenar os elementos no mapa, cujo padrão é `Traits`.|
|`Right`|O mapa do qual o conjunto criado é uma cópia.|
|`First`|A posição do primeiro elemento no intervalo de elementos a serem copiados.|
|`Last`|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|
|`IList`|A initializer_list da qual fazer a cópia.|

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o hash_multimap e que, posteriormente, pode ser retornado ao chamar [get_allocator](#get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.

Todos os construtores inicializam seus hash_multimaps.

Todos os construtores armazenam um objeto de função do tipo `Traits`, que é usado para estabelecer uma ordem entre as chaves do hash_multimap e que posteriormente pode ser retornado ao chamar [key_comp](#key_comp).

Os primeiros três construtores especificam um hash_multimap inicial vazio, o segundo especifica o tipo de função de comparação (`Comp`) a ser usada para estabelecer a ordem dos elementos e o terceiro especifica explicitamente o tipo de alocador (`_Al`) a ser usado. A palavra-chave `explicit` suprime determinados tipos de conversão de tipo automática.

O quarto construtor especifica uma cópia do hash_multimap `Right`.

Os próximos três construtores copiam o intervalo `First, Last)` de um mapa com clareza crescente para especificar o tipo de função de comparação da classe **Traits** e do alocador.

O oitavo construtor move o hash_multimap `Right`.

Os três construtores finais usam um initializer_list.

## <a name="insert"></a>  hash_multimap::insert

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Insere um elemento ou um intervalo de elementos em um hash_multimap.

```cpp
iterator insert(
    const value_type& Val);

iterator insert(
    const_iterator Where,
    const value_type& Val);void insert(
    initializer_list<value_type> IList);

template <class InputIterator>
void insert(
    InputIterator First,
    InputIterator Last);

template <class ValTy>
iterator insert(
    ValTy&& Val);

template <class ValTy>
iterator insert(
    const_iterator Where,
    ValTy&& Val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`Val`|O valor de um elemento a ser inserido no hash_multimap, a menos que ele já contenha o elemento ou, de modo geral, a menos que ele já contenha um elemento cuja chave seja ordenada de maneira equivalente.|
|`Where`|Uma dica de onde começar a procurar pelo ponto de inserção correto.|
|`First`|A posição do primeiro elemento a ser copiado de um mapa.|
|`Last`|A posição logo após o último elemento a ser copiado de um mapa.|

### <a name="return-value"></a>Valor de retorno

As duas primeiras funções membro `insert` retornam um iterador que aponta para a posição em que o novo elemento foi inserido.

A terceira função membro usa uma initializer_list para os elementos a serem inseridos.

A quarta função membro insere a sequência de valores de elemento em um mapa que corresponde a cada elemento tratado por um iterador no intervalo `[First, Last)` de um conjunto especificado.

As duas últimas funções membro `insert` se comportam da mesma forma que as duas primeiras, mas elas constroem o valor inserido.

### <a name="remarks"></a>Comentários

O [value_type](#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

A inserção poderá ocorrer em um tempo constante amortizado para a versão de dica de `insert`, em vez de no tempo logarítmico, se o ponto de inserção seguir `Where` imediatamente.

## <a name="iterator"></a>  hash_multimap::iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um hash_multimap.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::iterator iterator;
```

### <a name="remarks"></a>Comentários

O **iterador** definido por hash_multimap aponta para objetos de [value_type](#value_type), que são do tipo `pair`\< **const Key, Type**>, cujo primeiro membro é a chave do elemento e cujo segundo membro é a referência mapeada mantida pelo elemento.

Para desreferenciar um **iterador**`Iter` que aponta para um elemento em um hash_multimap, use o operador **->**.

Para acessar o valor de chave do elemento, use `Iter` -> **first**, que é equivalente a (\* `Iter`). **first**. Para acessar o valor dos dados mapeados do elemento, use `Iter` -> **second**, que é equivalente a (\* `Iter`). **first**.

Um tipo **iterator** pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Veja o exemplo de [begin](#begin) que demonstra como declarar e usar o **iterator**.

## <a name="key_comp"></a>  hash_multimap::key_comp

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Recupera uma cópia do objeto de comparação usado para ordenar chaves em um hash_multimap.

```cpp
key_compare key_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto de função que um hash_multimap usa para ordenar seus elementos.

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro

**operador booliano(const Key&** `left` **, const Key&** `right` **);**

que retornará **true** se `left` preceder e não for igual a `right` na ordem de classificação.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_key_comp.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;

   hash_multimap <int, int, hash_compare<int, less<int>>> hm1;
   hash_multimap <int, int, hash_compare<int, less<int>>
      >::key_compare kc1 = hm1.key_comp( ) ;
   bool result1 = kc1( 2, 3 ) ;
   if( result1 == true )
   {
      cout << "kc1( 2,3 ) returns value of true,\n"
           << "where kc1 is the function object of hm1.\n"
           << endl;
   }
   else
   {
      cout << "kc1( 2,3 ) returns value of false,\n"
           << "where kc1 is the function object of hm1.\n"
           << endl;
   }

   hash_multimap <int, int, hash_compare<int, greater<int>>> hm2;
   hash_multimap <int, int, hash_compare<int, greater<int>>
      >::key_compare kc2 = hm2.key_comp( );
   bool result2 = kc2( 2, 3 ) ;
   if( result2 == true )
   {
      cout << "kc2( 2,3 ) returns value of true,\n"
           << "where kc2 is the function object of hm2."
           << endl;
   }
   else
   {
      cout << "kc2( 2,3 ) returns value of false,\n"
           << "where kc2 is the function object of hm2."
           << endl;
   }
}
```

## <a name="key_compare"></a>  hash_multimap::key_compare

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no hash_multimap.

```cpp
typedef Traits key_compare;
```

### <a name="remarks"></a>Comentários

**key_compare** é um sinônimo do parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_multimap](../standard-library/hash-multimap-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [key_comp](#key_comp) que demonstra como declarar e usar `key_compare`.

## <a name="key_type"></a>  hash_multimap::key_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que descreve o objeto de chave de classificação que constitui cada elemento do hash_multimap.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

`key_type` é um sinônimo do parâmetro de modelo `Key`.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe hash_multimap](../standard-library/hash-multimap-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_compare`.

## <a name="lower_bound"></a>  hash_multimap::lower_bound

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador para o primeiro elemento em um hash_multimap com uma chave que é igual ou maior que uma chave especificada.

```cpp
iterator lower_bound(const Key& key);

const_iterator lower_bound(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento a ser comparada com a chave de classificação de um elemento do hash_multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um [iterador](#iterator) ou [const_iterator](#const_iterator) que trata da localização de um elemento em um hash_multimap com uma chave que é maior ou igual à chave de argumento ou que trata do local que sucede o último elemento no hash_multimap, se nenhuma correspondência for encontrada para a chave.

Se o valor retornado de `lower_bound` for atribuído a um `const_iterator`, o objeto hash_multimap não poderá ser modificado. Se o valor retornado de `lower_bound` for atribuído a um **iterador**, o objeto hash_multimap poderá ser modificado.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_lower_bound.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;
   hash_multimap <int, int> :: const_iterator hm1_AcIter,
      hm1_RcIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_RcIter = hm1.lower_bound( 2 );
   cout << "The element of hash_multimap hm1 with a key of 2 is: "
        << hm1_RcIter -> second << "." << endl;

   hm1_RcIter = hm1.lower_bound( 3 );
   cout << "The first element of hash_multimap hm1 with a key of 3 is: "
        << hm1_RcIter -> second << "." << endl;

   // If no match is found for the key, end( ) is returned
   hm1_RcIter = hm1.lower_bound( 4 );

   if ( hm1_RcIter == hm1.end( ) )
      cout << "The hash_multimap hm1 doesn't have an element "
           << "with a key of 4." << endl;
   else
      cout << "The element of hash_multimap hm1 with a key of 4 is: "
           << hm1_RcIter -> second << "." << endl;

   // The element at a specific location in the hash_multimap can be
   // found using a dereferenced iterator addressing the location
   hm1_AcIter = hm1.end( );
   hm1_AcIter--;
   hm1_RcIter = hm1.lower_bound( hm1_AcIter -> first );
   cout << "The first element of hm1 with a key matching"
        << endl << " that of the last element is: "
        << hm1_RcIter -> second << "." << endl;

   // Note that the first element with a key equal to
   // the key of the last element is not the last element
   if ( hm1_RcIter == --hm1.end( ) )
      cout << "This is the last element of hash_multimap hm1."
           << endl;
   else
      cout << "This is not the last element of hash_multimap hm1."
           << endl;
}
```

```Output
The element of hash_multimap hm1 with a key of 2 is: 20.
The first element of hash_multimap hm1 with a key of 3 is: 20.
The hash_multimap hm1 doesn't have an element with a key of 4.
The first element of hm1 with a key matching
 that of the last element is: 20.
This is not the last element of hash_multimap hm1.
```

## <a name="mapped_type"></a>  hash_multimap::mapped_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que representa o tipo de dados armazenado em um hash_multimap.

```cpp
typedef Type mapped_type;
```

### <a name="remarks"></a>Comentários

`mapped_type` é um sinônimo do parâmetro de modelo `Type`.

Para obter mais informações sobre `Type`, consulte o tópico [Classe hash_multimap](../standard-library/hash-multimap-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="max_size"></a>  hash_multimap::max_size

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna o tamanho máximo do hash_multimap.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho máximo possível do hash_multimap.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_max_size.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;
   hash_multimap <int, int> :: size_type i;

   i = hm1.max_size( );
   cout << "The maximum possible length "
        << "of the hash_multimap is " << i << "." << endl;
}
```

## <a name="op_eq"></a>  hash_multimap::operator=

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Substitui os elementos de hash_multimap por uma cópia de outro hash_multimap.

```cpp
hash_multimap& operator=(const hash_multimap& right);

hash_multimap& operator=(hash_multimap&& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`right`|O [hash_multimap](../standard-library/hash-multimap-class.md) que está sendo copiado para o `hash_multimap`.|

### <a name="remarks"></a>Comentários

Após apagar os elementos existentes em um `hash_multimap`, `operator=` copiará ou moverá o conteúdo de `right` para `hash_multimap`.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_operator_as.cpp
// compile with: /EHsc
#include <hash_multimap>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap<int, int> v1, v2, v3;
   hash_multimap<int, int>::iterator iter;

   v1.insert(pair<int, int>(1, 10));

   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << iter->second << " ";
   cout << endl;

   v2 = v1;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << iter->second << " ";
   cout << endl;

// move v1 into v2
   v2.clear();
   v2 = move(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << iter->second << " ";
   cout << endl;
}
```

## <a name="pointer"></a>  hash_multimap::pointer

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um ponteiro para um elemento em um hash_multimap.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo **pointer** pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto hash_multimap.

## <a name="rbegin"></a>  hash_multimap::rbegin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador que trata o primeiro elemento em um hash_multimap invertido.

```cpp
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido que trata do primeiro elemento em um hash_multimap invertido ou que trata do que foi o último elemento do hash_multimap não invertido.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um hash_multimap invertido, assim como [begin](#begin) é usado com um hash_multimap.

Se o valor retornado de `rbegin` for atribuído a um `const_reverse_iterator`, o objeto hash_multimap não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a um `reverse_iterator`, o objeto hash_multimap poderá ser modificado.

`rbegin` pode ser usado para iterar em um hash_multimap no sentido reverso.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_rbegin.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: iterator hm1_Iter;
   hash_multimap <int, int> :: reverse_iterator hm1_rIter;
   hash_multimap <int, int> :: const_reverse_iterator hm1_crIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_rIter = hm1.rbegin( );
   cout << "The first element of the reversed hash_multimap hm1 is "
        << hm1_rIter -> first << "." << endl;

   // begin can be used to start an iteration
   // through a hash_multimap in a forward order
   cout << "The hash_multimap is: ";
   for ( hm1_Iter = hm1.begin( ) ; hm1_Iter != hm1.end( ); hm1_Iter++)
      cout << hm1_Iter -> first << " ";
      cout << "." << endl;

   // rbegin can be used to start an iteration
   // through a hash_multimap in a reverse order
   cout << "The reversed hash_multimap is: ";
   for ( hm1_rIter = hm1.rbegin( ) ; hm1_rIter != hm1.rend( ); hm1_rIter++)
      cout << hm1_rIter -> first << " ";
      cout << "." << endl;

   // A hash_multimap element can be erased by dereferencing its key
   hm1_rIter = hm1.rbegin( );
   hm1.erase ( hm1_rIter -> first );

   hm1_rIter = hm1.rbegin( );
   cout << "After the erasure, the first element"
        << "\n in the reversed hash_multimap is "
        << hm1_rIter -> first << "." << endl;
}
```

```Output
The first element of the reversed hash_multimap hm1 is 3.
The hash_multimap is: 1 2 3 .
The reversed hash_multimap is: 3 2 1 .
After the erasure, the first element
 in the reversed hash_multimap is 2.
```

## <a name="reference"></a>  hash_multimap::reference

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece uma referência a um elemento armazenado em um hash_multimap.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::reference reference;
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_reference.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );

   // Declare and initialize a const_reference &Ref1
   // to the key of the first element
   const int &Ref1 = ( hm1.begin( ) -> first );

   // The following line would cause an error as the
   // non-const_reference cannot be used to access the key
   // int &Ref1 = ( hm1.begin( ) -> first );

   cout << "The key of first element in the hash_multimap is "
        << Ref1 << "." << endl;

   // Declare and initialize a reference &Ref2
   // to the data value of the first element
   int &Ref2 = ( hm1.begin( ) -> second );

   cout << "The data value of first element in the hash_multimap is "
        << Ref2 << "." << endl;

   //The non-const_reference can be used to modify the
   //data value of the first element
   Ref2 = Ref2 + 5;
   cout << "The modified data value of first element is "
        << Ref2 << "." << endl;
}
```

```Output
The key of first element in the hash_multimap is 1.
The data value of first element in the hash_multimap is 10.
The modified data value of first element is 15.
```

## <a name="rend"></a>  hash_multimap::rend

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador que trata do local após o último elemento em um hash_multimap invertido.

```cpp
const_reverse_iterator rend() const;

reverse_iterator rend();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso que trata do local que vem após o último elemento em um hash_multimap invertido (o local que precedeu o primeiro elemento no hash_multimap não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um hash_multimap invertido, assim como [end](#end) é usado com um hash_multimap.

Se o valor retornado de `rend` for atribuído a um [const_reverse_iterator](#const_reverse_iterator), o objeto hash_multimap não poderá ser modificado. Se o valor retornado de `rend` for atribuído a um [reverse_iterator](#reverse_iterator), o objeto hash_multimap poderá ser modificado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de seu hash_multimap.

O valor retornado por `rend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_rend.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;

   hash_multimap <int, int> :: iterator hm1_Iter;
   hash_multimap <int, int> :: reverse_iterator hm1_rIter;
   hash_multimap <int, int> :: const_reverse_iterator hm1_crIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );

   hm1_rIter = hm1.rend( );
   hm1_rIter--;
   cout << "The last element of the reversed hash_multimap hm1 is "
        << hm1_rIter -> first << "." << endl;

   // begin can be used to start an iteration
   // through a hash_multimap in a forward order
   cout << "The hash_multimap is: ";
   for ( hm1_Iter = hm1.begin( ) ; hm1_Iter != hm1.end( ); hm1_Iter++)
      cout << hm1_Iter -> first << " ";
      cout << "." << endl;

   // rbegin can be used to start an iteration
   // through a hash_multimap in a reverse order
   cout << "The reversed hash_multimap is: ";
   for ( hm1_rIter = hm1.rbegin( ) ; hm1_rIter != hm1.rend( ); hm1_rIter++)
      cout << hm1_rIter -> first << " ";
      cout << "." << endl;

   // A hash_multimap element can be erased by dereferencing its key
   hm1_rIter = --hm1.rend( );
   hm1.erase ( hm1_rIter -> first );

   hm1_rIter = hm1.rend( );
   hm1_rIter--;
   cout << "After the erasure, the last element "
        << "in the reversed hash_multimap is "
        << hm1_rIter -> first << "." << endl;
}
```

```Output
The last element of the reversed hash_multimap hm1 is 1.
The hash_multimap is: 1 2 3 .
The reversed hash_multimap is: 3 2 1 .
After the erasure, the last element in the reversed hash_multimap is 2.
```

## <a name="reverse_iterator"></a>  hash_multimap::reverse_iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um hash_multimap invertido.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::reverse_iterator reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `reverse_iterator` é usado para iterar pelo hash_multimap em ordem inversa.

O `reverse_iterator` definido pelo hash_multimap aponta para objetos de [value_type](#value_type), que são do tipo `pair`\< **const Key, Type**>. O valor da chave está disponível por meio do primeiro par de membros e o valor do elemento mapeado está disponível por meio do segundo membro do par.

### <a name="example"></a>Exemplo

Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.

## <a name="size"></a>  hash_multimap::size

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna o número de elementos no hash_multimap.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho atual do hash_multimap.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro hash_multimap::size.

```cpp
// hash_multimap_size.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
    using namespace std;
    using namespace stdext;
    hash_multimap<int, int> hm1, hm2;
    hash_multimap<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    hm1.insert(Int_Pair(1, 1));
    i = hm1.size();
    cout << "The hash_multimap length is " << i << "." << endl;

    hm1.insert(Int_Pair(2, 4));
    i = hm1.size();
    cout << "The hash_multimap length is now " << i << "." << endl;
}
```

```Output
The hash_multimap length is 1.
The hash_multimap length is now 2.
```

## <a name="size_type"></a>  hash_multimap::size_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo inteiro sem sinal que conta o número de elementos em um hash_multimap.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::size_type size_type;
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) que demonstra como declarar e usar `size_type`

## <a name="swap"></a>  hash_multimap::swap

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Troca os elementos de dois hash_multimaps.

```cpp
void swap(hash_multimap& right);
```

### <a name="parameters"></a>Parâmetros

`right` O hash_multimap fornecendo os elementos a ser trocado ou o hash_multimap cujos elementos são sejam trocadas com aqueles o hash_multimap.

### <a name="remarks"></a>Comentários

A função membro não invalida referências, ponteiros ou iteradores que designam elementos nos dois hash_multimaps cujos elementos são trocados.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_swap.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1, hm2, hm3;
   hash_multimap <int, int>::iterator hm1_Iter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );
   hm2.insert ( Int_Pair ( 10, 100 ) );
   hm2.insert ( Int_Pair ( 20, 200 ) );
   hm3.insert ( Int_Pair ( 30, 300 ) );

   cout << "The original hash_multimap hm1 is:";
   for ( hm1_Iter = hm1.begin( ); hm1_Iter != hm1.end( ); hm1_Iter++ )
      cout << " " << hm1_Iter -> second;
   cout   << "." << endl;

   // This is the member function version of swap
   hm1.swap( hm2 );

   cout << "After swapping with hm2, hash_multimap hm1 is:";
   for ( hm1_Iter = hm1.begin( ); hm1_Iter != hm1.end( ); hm1_Iter++ )
      cout << " " << hm1_Iter -> second;
   cout  << "." << endl;

   // This is the specialized template version of swap
   swap( hm1, hm3 );

   cout << "After swapping with hm3, hash_multimap hm1 is:";
   for ( hm1_Iter = hm1.begin( ); hm1_Iter != hm1.end( ); hm1_Iter++ )
      cout << " " << hm1_Iter -> second;
   cout   << "." << endl;
}
```

```Output
The original hash_multimap hm1 is: 10 20 30.
After swapping with hm2, hash_multimap hm1 is: 100 200.
After swapping with hm3, hash_multimap hm1 is: 300.
```

## <a name="upper_bound"></a>  hash_multimap::upper_bound

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Retorna um iterador para o primeiro elemento em um hash_multimaps com uma chave que é maior que uma chave especificada.

```cpp
iterator upper_bound(const Key& key);

const_iterator upper_bound(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento a ser comparada com a chave de classificação de um elemento do hash_multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um [iterador](#iterator) ou [const_iterator](#const_iterator) que trata da localização de um elemento em um hash_multimap com uma chave que é maior que a chave de argumento ou que trata do local que sucede o último elemento no hash_multimap, se nenhuma correspondência for encontrada para a chave.

Se o valor retornado de `upper_bound` for atribuído a um `const_iterator`, o objeto hash_multimap não poderá ser modificado. Se o valor retornado de `upper_bound` for atribuído a um **iterador**, o objeto hash_multimap poderá ser modificado.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_upper_bound.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multimap <int, int> hm1;
   hash_multimap <int, int> :: const_iterator hm1_AcIter, hm1_RcIter;
   typedef pair <int, int> Int_Pair;

   hm1.insert ( Int_Pair ( 1, 10 ) );
   hm1.insert ( Int_Pair ( 2, 20 ) );
   hm1.insert ( Int_Pair ( 3, 30 ) );
   hm1.insert ( Int_Pair ( 3, 40 ) );

   hm1_RcIter = hm1.upper_bound( 1 );
   cout << "The 1st element of hash_multimap hm1 with "
        << "a key greater than 1 is: "
        << hm1_RcIter -> second << "." << endl;

   hm1_RcIter = hm1.upper_bound( 2 );
   cout << "The first element of hash_multimap hm1\n with a key "
        << " greater than 2 is: "
        << hm1_RcIter -> second << "." << endl;

   // If no match is found for the key, end( ) is returned
   hm1_RcIter = hm1.lower_bound( 4 );

   if ( hm1_RcIter == hm1.end( ) )
      cout << "The hash_multimap hm1 doesn't have an element "
           << "with a key of 4." << endl;
   else
      cout << "The element of hash_multimap hm1 with a key of 4 is: "
           << hm1_RcIter -> second << "." << endl;

   // The element at a specific location in the hash_multimap can be
   // found using a dereferenced iterator addressing the location
   hm1_AcIter = hm1.begin( );
   hm1_RcIter = hm1.upper_bound( hm1_AcIter -> first );
   cout << "The first element of hm1 with a key greater than"
        << endl << " that of the initial element of hm1 is: "
        << hm1_RcIter -> second << "." << endl;
}
```

```Output
The 1st element of hash_multimap hm1 with a key greater than 1 is: 20.
The first element of hash_multimap hm1
 with a key  greater than 2 is: 30.
The hash_multimap hm1 doesn't have an element with a key of 4.
The first element of hm1 with a key greater than
 that of the initial element of hm1 is: 20.
```

## <a name="value_comp"></a>  hash_multimap::value_comp

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

A função membro retorna um objeto de função que determina a ordem dos elementos em um hash_multimap comparando os respectivos valores de chave.

```cpp
value_compare value_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto da função de comparação que um hash_multimap usa para ordenar seus elementos.

### <a name="remarks"></a>Comentários

Para um hash_multimap *m*, se dois elementos *e*1( *k*1 *, d*1) e *e*2( *k*2 *, d*2) forem objetos o tipo [value_type](#value_type), em que *k*1 e *k*2 forem suas chaves do tipo [key_type](#key_type) e `d`1 e `d`2 forem seus dados do tipo [mapped_type](#mapped_type), então *m.*`value_comp`( )( *e*1 *, e*2) será equivalente a *m.*`key_comp`( ) ( *k*1 *, k*2). Um objeto armazenado define a função de membro

**operador booliano**( **value_type&**`left`, **value_type&** `right`);

que retornará **true** se o valor de chave `left` preceder e for diferente do valor de chave de `right` na ordem de classificação.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_value_comp.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;

   hash_multimap <int, int, hash_compare<int, less<int>>> hm1;
   hash_multimap <int, int, hash_compare<int, less<int>>
      >::value_compare vc1 = hm1.value_comp( );
   hash_multimap <int,int>::iterator Iter1, Iter2;

   Iter1= hm1.insert ( hash_multimap <int, int> :: value_type ( 1, 10 ) );
   Iter2= hm1.insert ( hash_multimap <int, int> :: value_type ( 2, 5 ) );

   if( vc1( *Iter1, *Iter2 ) == true )
   {
      cout << "The element ( 1,10 ) precedes the element ( 2,5 )."
           << endl;
   }
   else
   {
      cout << "The element ( 1,10 ) does "
           << "not precede the element ( 2,5 )."
           << endl;
   }

   if( vc1( *Iter2, *Iter1 ) == true )
   {
      cout << "The element ( 2,5 ) precedes the element ( 1,10 )."
           << endl;
   }
   else
   {
      cout << "The element ( 2,5 ) does "
           << "not precede the element ( 1,10 )."
           << endl;
   }
}
```

## <a name="value_type"></a>  hash_multimap::value_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multimap](../standard-library/unordered-multimap-class.md).

Um tipo que representa o tipo do objeto armazenado em um hash_multimap.

```cpp
typedef pair<const Key, Type> value_type;
```

### <a name="remarks"></a>Comentários

`value_type` é declarado como par\<const [key_type](#key_type), [mapped_type](#mapped_type)> e não emparelhados\<key_type, mapped_type > porque as chaves de um contêiner de associação não podem ser alteradas usando um iterador não constante ou uma referência.

### <a name="example"></a>Exemplo

```cpp
// hash_multimap_value_type.cpp
// compile with: /EHsc
#include <hash_map>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   typedef pair <const int, int> cInt2Int;
   hash_multimap <int, int> hm1;
   hash_multimap <int, int> :: key_type key1;
   hash_multimap <int, int> :: mapped_type mapped1;
   hash_multimap <int, int> :: value_type value1;
   hash_multimap <int, int> :: iterator pIter;

   // value_type can be used to pass the correct type
   // explicitely to avoid implicit type conversion
   hm1.insert ( hash_multimap <int, int> :: value_type ( 1, 10 ) );

   // Compare another way to insert objects into a hash_multimap
   hm1.insert ( cInt2Int ( 2, 20 ) );

   // Initializing key1 and mapped1
   key1 = ( hm1.begin( ) -> first );
   mapped1 = ( hm1.begin( ) -> second );

   cout << "The key of first element in the hash_multimap is "
        << key1 << "." << endl;

   cout << "The data value of first element in the hash_multimap is "
        << mapped1 << "." << endl;

   // The following line would cause an error because
   // the value_type is not assignable
   // value1 = cInt2Int ( 4, 40 );

   cout  << "The keys of the mapped elements are:";
   for ( pIter = hm1.begin( ) ; pIter != hm1.end( ) ; pIter++ )
      cout << " " << pIter -> first;
   cout << "." << endl;

   cout  << "The values of the mapped elements are:";
   for ( pIter = hm1.begin( ) ; pIter != hm1.end( ) ; pIter++ )
      cout << " " << pIter -> second;
   cout << "." << endl;
}
```

```Output
The key of first element in the hash_multimap is 1.
The data value of first element in the hash_multimap is 10.
The keys of the mapped elements are: 1 2.
The values of the mapped elements are: 10 20.
```

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
