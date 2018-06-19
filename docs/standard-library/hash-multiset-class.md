---
title: Classe hash_multiset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- hash_set/stdext::hash_multiset
- hash_set/stdext::hash_multiset::allocator_type
- hash_set/stdext::hash_multiset::const_iterator
- hash_set/stdext::hash_multiset::const_pointer
- hash_set/stdext::hash_multiset::const_reference
- hash_set/stdext::hash_multiset::const_reverse_iterator
- hash_set/stdext::hash_multiset::difference_type
- hash_set/stdext::hash_multiset::iterator
- hash_set/stdext::hash_multiset::key_compare
- hash_set/stdext::hash_multiset::key_type
- hash_set/stdext::hash_multiset::pointer
- hash_set/stdext::hash_multiset::reference
- hash_set/stdext::hash_multiset::reverse_iterator
- hash_set/stdext::hash_multiset::size_type
- hash_set/stdext::hash_multiset::value_compare
- hash_set/stdext::hash_multiset::value_type
- hash_set/stdext::hash_multiset::begin
- hash_set/stdext::hash_multiset::cbegin
- hash_set/stdext::hash_multiset::cend
- hash_set/stdext::hash_multiset::clear
- hash_set/stdext::hash_multiset::count
- hash_set/stdext::hash_multiset::crbegin
- hash_set/stdext::hash_multiset::crend
- hash_set/stdext::hash_multiset::emplace
- hash_set/stdext::hash_multiset::emplace_hint
- hash_set/stdext::hash_multiset::empty
- hash_set/stdext::hash_multiset::end
- hash_set/stdext::hash_multiset::equal_range
- hash_set/stdext::hash_multiset::erase
- hash_set/stdext::hash_multiset::find
- hash_set/stdext::hash_multiset::get_allocator
- hash_set/stdext::hash_multiset::insert
- hash_set/stdext::hash_multiset::key_comp
- hash_set/stdext::hash_multiset::lower_bound
- hash_set/stdext::hash_multiset::max_size
- hash_set/stdext::hash_multiset::rbegin
- hash_set/stdext::hash_multiset::rend
- hash_set/stdext::hash_multiset::size
- hash_set/stdext::hash_multiset::swap
- hash_set/stdext::hash_multiset::upper_bound
- hash_set/stdext::hash_multiset::value_comp
dev_langs:
- C++
helpviewer_keywords:
- stdext::hash_multiset
- stdext::hash_multiset::allocator_type
- stdext::hash_multiset::const_iterator
- stdext::hash_multiset::const_pointer
- stdext::hash_multiset::const_reference
- stdext::hash_multiset::const_reverse_iterator
- stdext::hash_multiset::difference_type
- stdext::hash_multiset::iterator
- stdext::hash_multiset::key_compare
- stdext::hash_multiset::key_type
- stdext::hash_multiset::pointer
- stdext::hash_multiset::reference
- stdext::hash_multiset::reverse_iterator
- stdext::hash_multiset::size_type
- stdext::hash_multiset::value_compare
- stdext::hash_multiset::value_type
- stdext::hash_multiset::begin
- stdext::hash_multiset::cbegin
- stdext::hash_multiset::cend
- stdext::hash_multiset::clear
- stdext::hash_multiset::count
- stdext::hash_multiset::crbegin
- stdext::hash_multiset::crend
- stdext::hash_multiset::emplace
- stdext::hash_multiset::emplace_hint
- stdext::hash_multiset::empty
- stdext::hash_multiset::end
- stdext::hash_multiset::equal_range
- stdext::hash_multiset::erase
- stdext::hash_multiset::find
- stdext::hash_multiset::get_allocator
- stdext::hash_multiset::insert
- stdext::hash_multiset::key_comp
- stdext::hash_multiset::lower_bound
- stdext::hash_multiset::max_size
- stdext::hash_multiset::rbegin
- stdext::hash_multiset::rend
- stdext::hash_multiset::size
- stdext::hash_multiset::swap
- stdext::hash_multiset::upper_bound
- stdext::hash_multiset::value_comp
ms.assetid: 0580397a-a76e-40ad-aea2-5c6f3a9d0a21
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9baef962ab3a71e9dd350c3429c5b8f85d3adb9a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849009"
---
# <a name="hashmultiset-class"></a>Classe hash_multiset

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

A classe de contêiner hash_multiset é uma extensão da Biblioteca Padrão C++ e é usado para o armazenamento e a recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos servem como valores chave e não precisam ser exclusivos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key, class Traits =hash_compare<Key, less <Key>>, class Allocator =allocator <Key>>
class hash_multiset
```

### <a name="parameters"></a>Parâmetros

*Chave* o elemento tipo de dados a ser armazenado na hash_multiset.

`Traits` O tipo que inclui dois objetos de função, uma classe comparar que é um predicado binário pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa e uma função de hash que é um valores de chave de mapeamento de predicado unário dos elementos em não assinado números inteiros de tipo **size_t**. Esse argumento é opcional e o `hash_compare` *< chave,* **menos *\<chave >>* é o valor padrão.

`Allocator` O tipo que representa o objeto de alocador armazenados que encapsula os detalhes sobre o hash_multiset alocação e desalocação de memória. Esse argumento é opcional e o valor padrão é **alocador *\<chave >.*

## <a name="remarks"></a>Comentários

O hash_multiset é:

- Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado. Além disso, é um contêiner associativo simples, pois seus valores de elemento são seus valores de chave.

- Reversível, pois fornece um iterador bidirecional para acessar seus elementos.

- Com hash, pois seus elementos são agrupados em buckets com base no valor de uma função de hash aplicada aos valores chave dos elementos.

- Exclusivo no sentido de que cada um de seus elementos deve ter uma chave exclusiva. Uma vez que hash_multiser também é um contêiner associativo simples, seus elementos também são exclusivos.

- Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos ou chaves. Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.

A principal vantagem do uso de hash em vez da classificação é a maior eficiência: um hash bem-sucedido executa inserções, exclusões e localizações em tempos médios constantes, em comparação com um tempo proporcional ao logaritmo do número de elementos no contêiner para técnicas de classificação. O valor de um elemento em um conjunto não pode ser alterado diretamente. Em vez disso, você deve excluir valores antigos e inserir elementos com novos valores.

A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Contêineres associativos com hash são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que dão suporte explicitamente a essas operações são eficientes quando usadas com uma função de hash bem elaborada, executando-as em um tempo que é, em média, constante e não dependente do número de elementos no contêiner. Uma função de hash bem elaborada produz uma distribuição uniforme de valores em hash e minimiza o número de colisões, em que uma colisão deve ocorrer quando valores de chave distintos são mapeados para o mesmo valor em hash. No pior caso, com a pior função de hash possível, o número de operações será proporcional ao número de elementos na sequência (tempo linear).

O hash_multiset deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo. Os elementos de um hash_multiset podem ser múltiplos e atuar como suas próprias chaves de classificação, de modo que as chaves não são exclusivas. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras, por exemplo, na qual as palavras podem ocorrer mais de uma vez. Não tendo sido permitidas várias ocorrências das palavras, um hash_multiser seria a estrutura de contêiner apropriada. Se definições exclusivas fossem anexadas como valores à lista de palavras-chave exclusivas, um hash_map seria uma estrutura apropriada para conter esses dados. Se, em vez disso, as definições não fossem exclusivas, um hash_multimap seria o contêiner ideal.

O hash_multiset ordena a sequência que controla chamando um objeto de características de hash armazenado do tipo [value_compare](#value_compare). Esse objeto armazenado pode ser acessado chamando a função membro [key_comp](#key_comp). Esse é um objeto de função deve se comportar da mesma como um objeto da classe `hash_compare` *< chave,* **menos *\<chave >>.* Especificamente, para todos os valores de *Key* do tipo **Key**, a chamada **Trait**( *Key*) produz uma distribuição de valores do tipo **size_t**.

De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário *f*( *x*, *y*) é um objeto de função que tem dois objetos de argumento x e y e um valor retornado de true ou false. Uma ordenação imposta a um hash_multiset será uma ordenação fraca estrita se o predicado binário for irreflexivo, antissimétrico e transitivo, e se a equivalência for transitiva, em que dois objetos x e y serão definidos para serem equivalentes quando *f*( *x*, *y*) e *f*( *y*, *x*) forem falsos. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.

A ordem real dos elementos na sequência controlada depende da função de hash, da função de ordenação e do tamanho atual da tabela de hash armazenada no objeto de contêiner. Não é possível determinar o tamanho atual da tabela de hash, portanto, de modo geral, não é possível prever a ordem dos elementos na sequência controlada. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.

O iterador fornecido pela classe hash_multiset é um iterador bidirecional, mas as funções membro de classe insert e hash_multiset têm versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais reduzidos do que aqueles garantidos pela classe de iteradores bidirecionais. Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio hash_multiset de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições aos requisitos fornecidos por esse tipo de iterador. Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência. Esse é um hash_multiset mínimo de funcionalidades, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores [`first`, `last`) no contexto de funções membro da classe.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[hash_multiset](#hash_multiset)|Constrói um `hash_multiset` que está vazio ou que é uma cópia de todo ou parte de algum outro `hash_multiset`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para o objeto `hash_multiset`.|
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador bidirecional que pode ler um elemento `const` no `hash_multiset`.|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento `const` em um `hash_multiset`.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência para um elemento `const` armazenado em um `hash_multiset` para leitura e execução de operações `const`.|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento `const` no `hash_multiset`.|
|[difference_type](#difference_type)|Um tipo inteiro com sinal que indica a diferença entre dois iteradores que se referem a elementos no mesmo `hash_multiset`.|
|[iterator](#iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um `hash_multiset`.|
|[key_compare](#key_compare)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `hash_multiset`.|
|[key_type](#key_type)|Um tipo que descreve um objeto armazenado como um elemento de um `hash_set` em sua capacidade como chave de classificação.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento em um `hash_multiset`.|
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em um `hash_multiset`.|
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `hash_multiset` invertido.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `hash_multiset`.|
|[value_compare](#value_compare)|Um tipo que fornece dois objetos de função, um predicado binário da classe compare que pode comparar dois valores de elemento de um `hash_multiset` para determinar sua ordem relativa, bem como um predicado unário que faz o hash dos elementos.|
|[value_type](#value_type)|Um tipo que descreve um objeto armazenado como um elemento de um `hash_multiset` em sua capacidade como um valor.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[begin](#begin)|Retorna um iterador que trata do primeiro elemento no `hash_multiset`.|
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento no `hash_multiset`.|
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em um `hash_multiset`.|
|[clear](#clear)|Apaga todos os elementos de um `hash_multiset`.|
|[count](#count)|Retorna o número de elementos em um `hash_multiset` cuja chave corresponde a uma chave especificada pelo parâmetro|
|[crbegin](#crbegin)|Retorna um iterador const que trata o primeiro elemento em um `hash_multiset` invertido.|
|[crend](#crend)|Retorna um iterador const que trata o local após o último elemento em um `hash_multiset` invertido.|
|[emplace](#emplace)|Insere um elemento construído adequadamente em um `hash_multiset`.|
|[emplace_hint](#emplace_hint)|Insere um elemento construído adequadamente em um `hash_multiset`, com uma dica de posicionamento.|
|[empty](#empty)|Testa se `hash_multiset` está vazio.|
|[end](#end)|Retorna um iterador que trata o local após o último elemento em um `hash_multiset`.|
|[equal_range](#equal_range)|Retorna um par de iteradores, respectivamente, para o primeiro elemento em um `hash_multiset` com uma chave que é maior do que uma chave especificada e para o primeiro elemento no `hash_multiset` com uma chave igual ou maior que a chave.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um `hash_multiset` das posições especificadas ou remove elementos que correspondem a uma chave especificada.|
|[find](#find)|Retorna um iterador que trata do local de um elemento em um `hash_multiset` que tem uma chave equivalente a uma chave especificada.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` usada para construir o `hash_multiset`.|
|[insert](#insert)|Insere um elemento ou um intervalo de elementos em um `hash_multiset`.|
|[key_comp](#key_compare)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um `hash_multiset`.|
|[lower_bound](#lower_bound)|Retorna um iterador para o primeiro elemento em um `hash_multiset` com uma chave que é igual ou maior que uma chave especificada.|
|[max_size](#max_size)|Retorna o comprimento máximo do `hash_multiset`.|
|[rbegin](#rbegin)|Retorna um iterador que trata o primeiro elemento em um `hash_multiset` invertido.|
|[rend](#rend)|Retorna um iterador que trata o local após o último elemento em um `hash_multiset` invertido.|
|[size](#size)|Retorna o número de elementos no `hash_multiset`.|
|[swap](#swap)|Troca os elementos de dois `hash_multiset`s.|
|[upper_bound](#upper_bound)|Retorna um iterador para o primeiro elemento em um `hash_multiset` com uma chave que é igual ou maior que uma chave especificada.|
|[value_comp](#value_comp)|Recupera uma cópia do objeto de características de hash usado para fazer o hash e ordenar valores chave de elementos em um `hash_multiset`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[hash_multiset::operator=](#op_eq)|Substitui os elementos de hash_multiset por uma cópia de outro hash_multiset.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<hash_set>

**Namespace:** stdext

## <a name="allocator_type"></a>  hash_multiset::allocator_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que representa a classe allocator do objeto hash_multiset.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::allocator_type allocator_type;
```

### <a name="example"></a>Exemplo

Consulte o exemplo para [get_allocator](#get_allocator) para obter um exemplo do uso de `allocator_type`

## <a name="begin"></a>  hash_multiset::begin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador que trata do primeiro elemento no hash_multiset.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata do primeiro elemento no hash_multiset ou no local que sucede um has_multiset vazio.

### <a name="remarks"></a>Comentários

Se o valor retornado de **begin** for atribuído a um `const_iterator`, os elementos no objeto hash_multiset não poderão ser modificados. Se o valor retornado de **begin** for atribuído a um **iterador**, os elementos no objeto hash_multiset poderão ser modificados.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_begin.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int>::iterator hms1_Iter;
   hash_multiset <int>::const_iterator hms1_cIter;

   hms1.insert( 1 );
   hms1.insert( 2 );
   hms1.insert( 3 );

   hms1_Iter = hms1.begin( );
   cout << "The first element of hms1 is " << *hms1_Iter << endl;

   hms1_Iter = hms1.begin( );
   hms1.erase( hms1_Iter );

   // The following 2 lines would err because the iterator is const
   // hms1_cIter = hms1.begin( );
   // hms1.erase( hms1_cIter );

   hms1_cIter = hms1.begin( );
   cout << "The first element of hms1 is now " << *hms1_cIter << endl;
}
```

```Output
The first element of hms1 is 1
The first element of hms1 is now 2
```

## <a name="cbegin"></a>  hash_multiset::cbegin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador const que trata do primeiro elemento no hash_multiset.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional const que trata do primeiro elemento no [hash_multiset](../standard-library/hash-multiset-class.md) ou do local que sucede um `hash_multiset` vazio.

### <a name="remarks"></a>Comentários

Com o valor retornado de `cbegin`, os elementos no objeto `hash_multiset` não podem ser modificados.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_cbegin.cpp
// compile with: /EHsc
#include <hash_multiset>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hs1;
   hash_multiset <int>::const_iterator hs1_cIter;

   hs1.insert( 1 );
   hs1.insert( 2 );
   hs1.insert( 3 );

   hs1_cIter = hs1.cbegin( );
   cout << "The first element of hs1 is " << *hs1_cIter << endl;
}
```

```Output
The first element of hs1 is 1
```

## <a name="cend"></a>  hash_multiset::cend

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador const que trata do local após o último elemento em um hash_multiset.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional const que trata do local após o último elemento em um [hash_multiset](../standard-library/hash-multiset-class.md). Se o `hash_multiset` estiver vazio, então `hash_multiset::cend == hash_multiset::begin`.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador atingiu o fim de seu `hash_multiset`. O valor retornado por `cend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_cend.cpp
// compile with: /EHsc
#include <hash_multiset>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hs1;
   hash_multiset <int> :: const_iterator hs1_cIter;

   hs1.insert( 1 );
   hs1.insert( 2 );
   hs1.insert( 3 );

   hs1_cIter = hs1.cend( );
   hs1_cIter--;
   cout << "The last element of hs1 is " << *hs1_cIter << endl;
}
```

```Output
The last element of hs1 is 3
```

## <a name="clear"></a>  hash_multiset::clear

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Apaga todos os elementos de um hash_multiset.

```cpp
void clear();
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_clear.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;

   hms1.insert( 1 );
   hms1.insert( 2 );

   cout << "The size of the hash_multiset is initially " << hms1.size( )
        << "." << endl;

   hms1.clear( );
   cout << "The size of the hash_multiset after clearing is "
        << hms1.size( ) << "." << endl;
}
```

```Output
The size of the hash_multiset is initially 2.
The size of the hash_multiset after clearing is 0.
```

## <a name="const_iterator"></a>  hash_multiset::const_iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no hash_multiset.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_iterator const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Consulte o exemplo para [begin](#begin) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a>  hash_multiset::const_pointer

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um ponteiro para um elemento **const** em um hash_multiset.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [const_iterador](#const_iterator) deve ser usado para acessar os elementos em um objeto de hash_multiset **const**.

## <a name="const_reference"></a>  hash_multiset::const_reference

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece uma referência a um elemento **const** armazenado em um hash_multiset para leitura e execução de operações **const**.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::const_reference const_reference;
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_const_reference.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;

   hms1.insert( 10 );
   hms1.insert( 20 );

   // Declare and initialize a const_reference &Ref1
   // to the 1st element
   const int &Ref1 = *hms1.begin( );

   cout << "The first element in the hash_multiset is "
        << Ref1 << "." << endl;

   // The following line would cause an error because the
   // const_reference cannot be used to modify the hash_multiset
   // Ref1 = Ref1 + 5;
}
```

```Output
The first element in the hash_multiset is 10.
```

## <a name="const_reverse_iterator"></a>  hash_multiset::const_reverse_iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no hash_multiset.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::const_reverse_iterator const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar no hash_multiset em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rend](#rend) para obter um exemplo de como declarar e usar o `const_reverse_iterator`.

## <a name="count"></a>  hash_multiset::count

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna o número de elementos em um hash_multiset cuja chave corresponde a uma chave especificada pelo parâmetro.

```cpp
size_type count(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

`key` A chave de elementos a serem correspondidos do hash_multiset.

### <a name="return-value"></a>Valor de retorno

O número de elementos no hash_multiset com a chave especificada pelo parâmetro.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos no seguinte intervalo:

[ `lower_bound` (_ `Key` ), `upper_bound` (\_ `Key` ) ).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro hash_multiset::count.

```cpp
// hash_multiset_count.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
    using namespace std;
    using namespace stdext;
    hash_multiset<int> hms1;
    hash_multiset<int>::size_type i;

    hms1.insert(1);
    hms1.insert(1);

    // Keys do not need to be unique in hash_multiset,
    // so duplicates may exist.
    i = hms1.count(1);
    cout << "The number of elements in hms1 with a sort key of 1 is: "
         << i << "." << endl;

    i = hms1.count(2);
    cout << "The number of elements in hms1 with a sort key of 2 is: "
         << i << "." << endl;
}
```

```Output
The number of elements in hms1 with a sort key of 1 is: 2.
The number of elements in hms1 with a sort key of 2 is: 0.
```

## <a name="crbegin"></a>  hash_multiset::crbegin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador const que trata do primeiro elemento em um hash_multiset invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido const que trata do primeiro elemento em um [hash_multiset](../standard-library/hash-multiset-class.md) invertido ou que trata do que foi o último elemento do `hash_multiset` não invertido.

### <a name="remarks"></a>Comentários

`crbegin` é usado com um `hash_multiset` invertido, assim como [hash_multiset::begin](#begin) é usado com um `hash_multiset`.

Com o valor de retorno `crbegin`, o objeto `hash_multiset` não pode ser modificado.

`crbegin` pode ser usado para iterar em um `hash_multiset` no sentido inverso.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_crbegin.cpp
// compile with: /EHsc
#include <hash_multiset>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hs1;
   hash_multiset <int>::const_reverse_iterator hs1_crIter;

   hs1.insert( 10 );
   hs1.insert( 20 );
   hs1.insert( 30 );

   hs1_crIter = hs1.crbegin( );
   cout << "The first element in the reversed hash_multiset is "
        << *hs1_crIter << "." << endl;
}
```

```Output
The first element in the reversed hash_multiset is 30.
```

## <a name="crend"></a>  hash_multiset::crend

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador const que trata do local após o último elemento em um hash_multiset invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso const que trata da localização que vem após o último elemento em um [hash_multiset](../standard-library/hash-multiset-class.md) invertido (o local que precedeu o primeiro elemento no `hash_multiset` não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um `hash_multiset` invertido, assim como [hash_multiset::end](#end) é usado com um `hash_multiset`.

Com o valor de retorno `crend`, o objeto `hash_multiset` não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de seu hash_multiset.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_crend.cpp
// compile with: /EHsc
#include <hash_multiset>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hs1;
   hash_multiset <int>::const_reverse_iterator hs1_crIter;

   hs1.insert( 10 );
   hs1.insert( 20 );
   hs1.insert( 30 );

   hs1_crIter = hs1.crend( );
   hs1_crIter--;
   cout << "The last element in the reversed hash_multiset is "
        << *hs1_crIter << "." << endl;
}
```

```Output
The last element in the reversed hash_multiset is 10.
```

## <a name="difference_type"></a>  hash_multiset::difference_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo inteiro com sinal que indica a diferença entre dois iteradores que se referem a elementos no mesmo hash_multiset.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::difference_type difference_type;
```

### <a name="remarks"></a>Comentários


          `difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` geralmente é usado para representar o número de elementos no intervalo [`first`, `last`) entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, o que inclui a classe de iteradores bidirecionais com suporte de contêineres reversíveis, como conjuntos. a subtração entre iteradores tem suporte apenas de iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório como vetor ou deque.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <hash_set>
#include <algorithm>

int main( )
{
   using namespace std;
   using namespace stdext;

   hash_multiset <int> hms1;
   hash_multiset <int>::iterator hms1_Iter, hms1_bIter, hms1_eIter;

   hms1.insert( 20 );
   hms1.insert( 10 );

   // hash_multiset elements need not be unique
   hms1.insert( 20 );

   hms1_bIter = hms1.begin( );
   hms1_eIter = hms1.end( );

   hash_multiset <int>::difference_type   df_typ5, df_typ10,
        df_typ20;

   df_typ5 = count( hms1_bIter, hms1_eIter, 5 );
   df_typ10 = count( hms1_bIter, hms1_eIter, 10 );
   df_typ20 = count( hms1_bIter, hms1_eIter, 20 );

   // The keys & hence the elements of a hash_multiset
   // need not be unique and may occur multiple times
   cout << "The number '5' occurs " << df_typ5
        << " times in hash_multiset hms1.\n";
   cout << "The number '10' occurs " << df_typ10
        << " times in hash_multiset hms1.\n";
   cout << "The number '20' occurs " << df_typ20
        << " times in hash_multiset hms1.\n";

   // Count the number of elements in a hash_multiset
   hash_multiset <int>::difference_type  df_count = 0;
   hms1_Iter = hms1.begin( );
   while ( hms1_Iter != hms1_eIter)
   {
      df_count++;
      hms1_Iter++;
   }

   cout << "The number of elements in the hash_multiset hms1 is "
        << df_count << "." << endl;
}
```

```Output
The number '5' occurs 0 times in hash_multiset hms1.
The number '10' occurs 1 times in hash_multiset hms1.
The number '20' occurs 2 times in hash_multiset hms1.
The number of elements in the hash_multiset hms1 is 3.
```

## <a name="emplace"></a>  hash_multiset::emplace

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Insere um elemento construído em um hash_multiset.

```cpp
template <class ValTy>
iterator insert(ValTy&& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`val`|O valor de um elemento a ser inserido no [hash_multiset](../standard-library/hash-multiset-class.md), a menos que o `hash_multiset` já contenha o elemento ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente.|

### <a name="return-value"></a>Valor de retorno

A função membro `emplace` retorna um iterador que aponta para a posição em que o novo elemento foi inserido.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_emplace.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset<string> hms3;
   string str1("a");

   hms3.emplace(move(str1));
   cout << "After the emplace insertion, hms3 contains "
      << *hms3.begin() << "." << endl;
}
```

```Output
After the emplace insertion, hms3 contains a.
```

## <a name="emplace_hint"></a>  hash_multiset::emplace_hint

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Insere um elemento construído em um hash_multiset, com uma dica de posicionamento.

```cpp
template <class ValTy>
iterator insert(
    const_iterator _Where,
    ValTy&& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`val`|O valor de um elemento a ser inserido no [hash_multiset](../standard-library/hash-multiset-class.md), a menos que o `hash_multiset` já contenha o elemento ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente.|
|`_Where`|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.)|

### <a name="return-value"></a>Valor de retorno

A função membro [hash_multiset::emplace](#emplace) retorna um iterador que aponta para a posição em que o novo elemento foi inserido no `hash_multiset`.

### <a name="remarks"></a>Comentários

A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_emplace_hint.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset<string> hms1;
   string str1("a");

   hms1.insert(hms1.begin(), move(str1));
   cout << "After the emplace insertion, hms1 contains "
      << *hms1.begin() << "." << endl;
}
```

```Output
After the emplace insertion, hms1 contains a.
```

## <a name="empty"></a>  hash_multiset::empty

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Testa se um hash_multiset está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o hash_multiset estiver vazio; **false** se o hash_multiset não estiver vazio.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_empty.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1, hms2;
   hms1.insert ( 1 );

   if ( hms1.empty( ) )
      cout << "The hash_multiset hms1 is empty." << endl;
   else
      cout << "The hash_multiset hms1 is not empty." << endl;

   if ( hms2.empty( ) )
      cout << "The hash_multiset hms2 is empty." << endl;
   else
      cout << "The hash_multiset hms2 is not empty." << endl;
}
```

```Output
The hash_multiset hms1 is not empty.
The hash_multiset hms2 is empty.
```

## <a name="end"></a>  hash_multiset::end

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador que trata do local após o último elemento em um hash_multiset.

```cpp
const_iterator end() const;

iterator end();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata do local após o último elemento em um hash_multiset. Se o hash_multiset estiver vazio, hash_multiset::end == hash_multiset::begin.

### <a name="remarks"></a>Comentários

**end** é usado para testar se um iterador atingir o fim de seu hash_multiset. O valor retornado por **end** não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_end.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int> :: iterator hms1_Iter;
   hash_multiset <int> :: const_iterator hms1_cIter;

   hms1.insert( 1 );
   hms1.insert( 2 );
   hms1.insert( 3 );

   hms1_Iter = hms1.end( );
   hms1_Iter--;
   cout << "The last element of hms1 is " << *hms1_Iter << endl;

   hms1.erase( hms1_Iter );

   // The following 3 lines would err because the iterator is const
   // hms1_cIter = hms1.end( );
   // hms1_cIter--;
   // hms1.erase( hms1_cIter );

   hms1_cIter = hms1.end( );
   hms1_cIter--;
   cout << "The last element of hms1 is now " << *hms1_cIter << endl;
}
```

```Output
The last element of hms1 is 3
The last element of hms1 is now 2
```

## <a name="equal_range"></a>  hash_multiset::equal_range

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um par de iteradores, respectivamente, para o primeiro elemento em um hash_multiset com uma chave que é maior do que uma chave especificada e para o primeiro elemento no hash_multiset com uma chave igual ou maior que a chave.

```cpp
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento a ser comparada com a chave de classificação de um elemento do hash_multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um par de iteradores em que o primeiro é o [lower_bound](#lower_bound) e o segundo é o [upper_bound](#upper_bound) da chave.

Para acessar o primeiro iterador de um par `pr` retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_equal_range.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   typedef hash_multiset<int> IntHSet;
   IntHSet hms1;
   hash_multiset <int> :: const_iterator hms1_RcIter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );

   pair <IntHSet::const_iterator, IntHSet::const_iterator> p1, p2;
   p1 = hms1.equal_range( 20 );

   cout << "The upper bound of the element with "
        << "a key of 20\nin the hash_multiset hms1 is: "
        << *(p1.second) << "." << endl;

   cout << "The lower bound of the element with "
        << "a key of 20\nin the hash_multiset hms1 is: "
        << *(p1.first) << "." << endl;

   // Compare the upper_bound called directly
   hms1_RcIter = hms1.upper_bound( 20 );
   cout << "A direct call of upper_bound( 20 ) gives "
        << *hms1_RcIter << "," << endl
        << "matching the 2nd element of the pair"
        << " returned by equal_range( 20 )." << endl;

   p2 = hms1.equal_range( 40 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == hms1.end( ) )
      && ( p2.second == hms1.end( ) ) )
      cout << "The hash_multiset hms1 doesn't have an element "
           << "with a key less than 40." << endl;
   else
      cout << "The element of hash_multiset hms1"
           << "with a key >= 40 is: "
           << *(p1.first) << "." << endl;
}
```

```Output
The upper bound of the element with a key of 20
in the hash_multiset hms1 is: 30.
The lower bound of the element with a key of 20
in the hash_multiset hms1 is: 20.
A direct call of upper_bound( 20 ) gives 30,
matching the 2nd element of the pair returned by equal_range( 20 ).
The hash_multiset hms1 doesn't have an element with a key less than 40.
```

## <a name="erase"></a>  hash_multiset::erase

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Remove um elemento ou um intervalo de elementos em um hash_multiset das posições especificadas ou remove elementos que correspondem a uma chave especificada.

```cpp
iterator erase(iterator _Where);

iterator erase(iterator first, iterator last);

size_type erase(const key_type& key);
```

### <a name="parameters"></a>Parâmetros

`_Where` Posição do elemento a ser removido do hash_multiset.

`first` Posição do primeiro elemento removido o hash_multiset.

`last` Posição logo após o último elemento removido o hash_multiset.

`key` A chave de elementos a serem removidos do hash_multiset.

### <a name="return-value"></a>Valor de retorno

Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de qualquer elemento removido ou um ponteiro para o final do hash_multiset, se não houver tal elemento. Para a terceira função membro, o número de elementos que foram removidos do hash_multiset.

### <a name="remarks"></a>Comentários

As funções membro nunca geram uma exceção.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro hash_multiset::erase.

```cpp
// hash_multiset_erase.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main()
{
    using namespace std;
    using namespace stdext;
    hash_multiset<int> hms1, hms2, hms3;
    hash_multiset<int> :: iterator pIter, Iter1, Iter2;
    int i;
    hash_multiset<int>::size_type n;

    for (i = 1; i < 5; i++)
    {
        hms1.insert(i);
        hms2.insert(i * i);
        hms3.insert(i - 1);
    }

    // The 1st member function removes an element at a given position
    Iter1 = ++hms1.begin();
    hms1.erase(Iter1);

    cout << "After the 2nd element is deleted,\n "
         << "the hash_multiset hms1 is:" ;
    for (pIter = hms1.begin(); pIter != hms1.end(); pIter++)
        cout << " " << *pIter;
    cout << "." << endl;

    // The 2nd member function removes elements
    // in the range [ first,  last)
    Iter1 = ++hms2.begin();
    Iter2 = --hms2.end();
    hms2.erase(Iter1, Iter2);

    cout << "After the middle two elements are deleted,\n "
         << "the hash_multiset hms2 is:" ;
    for (pIter = hms2.begin(); pIter != hms2.end(); pIter++)
        cout << " " << *pIter;
    cout << "." << endl;

    // The 3rd member function removes elements with a given  key
    n = hms3.erase(2);

    cout << "After the element with a key of 2 is deleted,\n "
         << "the hash_multiset hms3 is:" ;
    for (pIter = hms3.begin(); pIter != hms3.end(); pIter++)
        cout << " " << *pIter;
    cout << "." << endl;

    // The 3rd member function returns the number of elements removed
    cout << "The number of elements removed from hms3 is: "
         << n << "." << endl;

    // The dereferenced iterator can also be used to specify a key
    Iter1 = ++hms3.begin();
    hms3.erase(Iter1);

    cout << "After another element with a key "
         << "equal to that of the 2nd element\n is deleted, "
         << "the hash_multiset hms3 is:" ;
    for (pIter = hms3.begin(); pIter != hms3.end(); pIter++)
        cout << " " << *pIter;
    cout << "." << endl;
}
```

```Output
After the 2nd element is deleted,
 the hash_multiset hms1 is: 1 3 4.
After the middle two elements are deleted,
 the hash_multiset hms2 is: 16 4.
After the element with a key of 2 is deleted,
 the hash_multiset hms3 is: 0 1 3.
The number of elements removed from hms3 is: 1.
After another element with a key equal to that of the 2nd element
 is deleted, the hash_multiset hms3 is: 0 3.
```

## <a name="find"></a>  hash_multiset::find

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador que trata do local de um elemento em um hash_multiset que tem uma chave equivalente a uma chave especificada.

```cpp
iterator find(const Key& key);

const_iterator find(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento para correspondência com a chave de classificação de um elemento do hash_multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um [iterador](#iterator) ou [const_iterator](#const_iterator) que trata do local de um elemento equivalente à chave especificada ou que trata do local que sucede o último elemento em hash_multiset se nenhuma correspondência para a chave for encontrada.

### <a name="remarks"></a>Comentários

A função membro retorna um iterador que trata de um elemento no hash_multiset, cuja chave de classificação é **equivalente** à chave de argumento em um predicado binário que induz uma ordenação com base em uma relação de comparação do tipo "menor que".

Se o valor retornado de **find** for atribuído a `const_iterator`, o objeto hash_multiset não poderá ser modificado. Se o valor retornado de **find** for atribuído a um **iterador**, o objeto do hash_multiset poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_find.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int> :: const_iterator hms1_AcIter, hms1_RcIter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );

   hms1_RcIter = hms1.find( 20 );
   cout << "The element of hash_multiset hms1 with a key of 20 is: "
        << *hms1_RcIter << "." << endl;

   hms1_RcIter = hms1.find( 40 );

   // If no match is found for the key, end( ) is returned
   if ( hms1_RcIter == hms1.end( ) )
      cout << "The hash_multiset hms1 doesn't have an element "
           << "with a key of 40." << endl;
   else
      cout << "The element of hash_multiset hms1 with a key of 40 is: "
           << *hms1_RcIter << "." << endl;

   // The element at a specific location in the hash_multiset can be found
   // by using a dereferenced iterator addressing the location
   hms1_AcIter = hms1.end( );
   hms1_AcIter--;
   hms1_RcIter = hms1.find( *hms1_AcIter );
   cout << "The element of hms1 with a key matching "
        << "that of the last element is: "
        << *hms1_RcIter << "." << endl;
}
```

```Output
The element of hash_multiset hms1 with a key of 20 is: 20.
The hash_multiset hms1 doesn't have an element with a key of 40.
The element of hms1 with a key matching that of the last element is: 30.
```

## <a name="get_allocator"></a>  hash_multiset::get_allocator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna uma cópia do objeto alocador usado para construir o hash_multiset.

```cpp
Allocator get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

O alocador usado pelo hash_multiset para gerenciar a memória, que é o parâmetro de modelo da classe `Allocator`.

Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

### <a name="remarks"></a>Comentários

Alocadores para a classe hash_multiset especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_get_allocator.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;

   // The following lines declare objects
   // that use the default allocator.
   hash_multiset <int, hash_compare <int, less<int> > > hms1;
   hash_multiset <int, hash_compare <int, greater<int> > > hms2;
   hash_multiset <double, hash_compare <double,
      less<double> >, allocator<double> > hms3;

   hash_multiset <int, hash_compare <int,
      greater<int> > >::allocator_type hms2_Alloc;
   hash_multiset <double>::allocator_type hms3_Alloc;
   hms2_Alloc = hms2.get_allocator( );

   cout << "The number of integers that can be allocated"
        << endl << "before free memory is exhausted: "
        << hms1.max_size( ) << "." << endl;

   cout << "The number of doubles that can be allocated"
        << endl << "before free memory is exhausted: "
        << hms3.max_size( ) <<  "." << endl;

   // The following lines create a hash_multiset hms4
   // with the allocator of hash_multiset hms1.
   hash_multiset <int>::allocator_type hms4_Alloc;
   hash_multiset <int> hms4;
   hms4_Alloc = hms2.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated by the other
   if( hms2_Alloc == hms4_Alloc )
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

## <a name="hash_multiset"></a>  hash_multiset::hash_multiset

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Constrói um `hash_multiset` que está vazio ou que é uma cópia de todo ou parte de algum outro `hash_multiset`.

```cpp
hash_multiset();

explicit hash_multiset(
    const Traits& Comp);

hash_multiset(
    const Traits& Comp,
    const Allocator& Al);

hash_multiset(
    const hash_multiset<Key, Traits, Allocator>& Right);

hash_multiset(
    hash_multiset&& Right
};
hash_multiset (initializer_list<Type> IList);

hash_multiset(
    initializer_list<Tu[e> IList, const Compare& Comp):
hash_multiset(
    initializer_list<Type> IList, const Compare& Comp, const Allocator& Al);

template <class InputIterator>
hash_multiset(
 InputIterator First,
    InputIterator Last);

template <class InputIterator>
hash_multiset(
 InputIterator First,
    InputIterator Last,
    const Traits& Comp);

template <class InputIterator>
hash_multiset(
 InputIterator First,
    InputIterator Last,
    const Traits& Comp,
    const Allocator& Al);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`Al`|A classe do alocador de armazenamento a ser usado para este objeto `hash_multiset`, cujo padrão é `Allocator`.|
|`Comp`|A função de comparação do tipo `const Traits` usada para ordenar os elementos no `hash_multiset`, cujo padrão é `hash_compare`.|
|`Right`|O `hash_multiset` do qual o `hash_multiset` construído é uma cópia.|
|`First`|A posição do primeiro elemento no intervalo de elementos a serem copiados.|
|`Last`|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|
|`IList`|O initializer_list que contém os elementos a serem copiados.|

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o `hash_multiset` e que, posteriormente, pode ser retornado ao chamar [hash_multiset::get_allocator](#get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.

Todos os construtores inicializam seus hash_multisets.

Todos os construtores armazenam um objeto de função do tipo `Traits`, que é usado para estabelecer uma ordem entre as chaves do `hash_multiset` e que, posteriormente, pode ser retornado ao chamar [hash_multiset::key_comp](#key_comp). Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

Os primeiros três construtores especificam um `hash_multiset` inicial vazio, com o segundo especificando o tipo de função de comparação (`Comp`) a ser usada para estabelecer a ordem dos elementos e a terceira especificando explicitamente o tipo de alocador (`Al`) a ser usado. A palavra-chave `explicit` suprime determinados tipos de conversão de tipo automática.

O quarto construtor move o `hash_multiset` `Right`.

A quinto, o sexto e o sétimo construtor usam um initializer_list.

Os três últimos construtores copiam o intervalo (`First`, `Last`) de um `hash_multiset` com clareza crescente para especificar o tipo de função de comparação da classe Compare e do alocador.

A ordem real dos elementos de um contêiner de conjunto de hash depende da função de hash, da função de ordenação e do tamanho atual da tabela de hash e não pode, de modo geral, ser prevista como era possível com o contêiner do conjunto, em que foi determinada somente pela função de ordenação.

## <a name="insert"></a>  hash_multiset::insert

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Insere um elemento ou um intervalo de elementos em um hash_multiset.

```cpp
iterator insert(
    const Type& Val);

iterator insert(
    iterator Where,
    const Type& Al);

void insert(
    initializer_list<Type> IList);

iterator insert(
    const Type& Val);

iterator insert(
    Iterator Where,
    const Type& Val);

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
|`Val`|O valor de um elemento a ser inserido no hash_multiset, a menos que hash_multiset já contenha o elemento ou, de modo geral, um elemento cuja chave seja ordenada de maneira equivalente.|
|`Where`|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (A inserção poderá ocorrer em um tempo constante amortizado, em vez de no tempo logarítmico, se o ponto de inserção seguir `_Where` imediatamente.)|
|`First`|A posição do primeiro elemento a ser copiado de um hash_multiset.|
|`Last`|A posição logo após o último elemento a ser copiado de um hash_multiset.|
|`IList`|A initializer_list que contém os elementos a serem copiados.|

### <a name="return-value"></a>Valor de retorno

As duas primeiras funções membro de inserção retornam um iterador que aponta para a posição em que o novo elemento foi inserido.

As três funções membro seguintes usam uma initializer_list.

A terceira função membro insere a sequência de valores de elemento em um hash_multiset que corresponde a cada elemento tratado por um iterador no intervalo (`First`,`Last`) de um hash_multiset especificado.

### <a name="remarks"></a>Comentários

A inserção poderá ocorrer em um tempo constante amortizado para a versão de dica da inserção, em vez de no tempo logarítmico, se o ponto de inserção seguir `Where` imediatamente.

## <a name="iterator"></a>  hash_multiset::iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um hash_multiset.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::iterator iterator;
```

### <a name="remarks"></a>Comentários

Um tipo **iterator** pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Consulte o exemplo de [begin](#begin) para obter um exemplo de como declarar e usar um **iterador**.

## <a name="key_comp"></a>  hash_multiset::key_comp

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Recupera uma cópia do objeto de comparação usado para ordenar chaves em um hash_multiset.

```cpp
key_compare key_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o parâmetro de modelo hash_multiset `Traits`, que contém objetos de função usados para fazer o hash e para ordenar elementos do contêiner.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

### <a name="remarks"></a>Comentários

O objeto armazenado define uma função membro:

**operador booliano**( **const Key&** *_xVal,* **const Key&** _ `yVal`);

que retornará **true** se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.

Observe que [key_compare](#key_compare) e [value_compare](#value_compare) são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes hash_multiset e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_key_comp.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;

   hash_multiset <int, hash_compare < int, less<int> > >hms1;
   hash_multiset<int, hash_compare < int, less<int> > >::key_compare kc1
          = hms1.key_comp( ) ;
   bool result1 = kc1( 2, 3 ) ;
   if( result1 == true )
   {
      cout << "kc1( 2,3 ) returns value of true, "
           << "where kc1 is the function object of hms1."
           << endl;
   }
   else
   {
      cout << "kc1( 2,3 ) returns value of false "
           << "where kc1 is the function object of hms1."
        << endl;
   }

   hash_multiset <int, hash_compare < int, greater<int> > > hms2;
   hash_multiset<int, hash_compare < int, greater<int> > >::key_compare
         kc2 = hms2.key_comp( ) ;
   bool result2 = kc2( 2, 3 ) ;
   if( result2 == true )
   {
      cout << "kc2( 2,3 ) returns value of true, "
           << "where kc2 is the function object of hms2."
           << endl;
   }
   else
   {
      cout << "kc2( 2,3 ) returns value of false, "
           << "where kc2 is the function object of hms2."
           << endl;
   }
}
```

## <a name="key_compare"></a>  hash_multiset::key_compare

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece dois objetos de função, um predicado binário da classe compare que pode comparar dois valores de elemento de um hash_multiset para determinar sua ordem relativa, bem como um predicado unário que faz o hash dos elementos.

```cpp
typedef Traits key_compare;
```

### <a name="remarks"></a>Comentários

**key_compare** é um sinônimo do parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

Observe que `key_compare` e value_compare são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes hash_set e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.

### <a name="example"></a>Exemplo

Consulte o exemplo de [key_comp](#key_comp) para obter um exemplo de como declarar e usar `key_compare`.

## <a name="key_type"></a>  hash_multiset::key_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no hash_multiset.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

**key_type** é um sinônimo do parâmetro de modelo `Key`.

Observe que `key_type` e [value_type](../standard-library/hash-set-class.md#value_type) são sinônimos do parâmetro de modelo **Key**. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="lower_bound"></a>  hash_multiset::lower_bound

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador para o primeiro elemento em um hash_multiset com uma chave que é igual ou maior que uma chave especificada.

```cpp
const_iterator lower_bound(const Key& key) const;

iterator lower_bound(const Key& key);
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento a ser comparada com a chave de classificação de um elemento do hash_multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um [iterador](#iterator) ou [const_iterator](#const_iterator) que trata do local do primeiro elemento em um hash_multiset com uma chave igual ou maior que a chave de argumento ou que trata do local que sucede o último elemento em hash_multiset se nenhuma correspondência para a chave for encontrada.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_lower_bound.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main() {
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int> :: const_iterator hms1_AcIter, hms1_RcIter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );

   hms1_RcIter = hms1.lower_bound( 20 );
   cout << "The element of hash_multiset hms1 with a key of 20 is: "
        << *hms1_RcIter << "." << endl;

   hms1_RcIter = hms1.lower_bound( 40 );

   // If no match is found for the key, end( ) is returned
   if ( hms1_RcIter == hms1.end( ) )
      cout << "The hash_multiset hms1 doesn't have an element "
           << "with a key of 40." << endl;
   else
      cout << "The element of hash_multiset hms1 with a key of 40 is: "
           << *hms1_RcIter << "." << endl;

   // An element at a specific location in the hash_multiset can be found
   // by using a dereferenced iterator that addresses the location
   hms1_AcIter = hms1.end( );
   hms1_AcIter--;
   hms1_RcIter = hms1.lower_bound( *hms1_AcIter );
   cout << "The element of hms1 with a key matching "
        << "that of the last element is: "
        << *hms1_RcIter << "." << endl;
}
```

## <a name="max_size"></a>  hash_multiset::max_size

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna o tamanho máximo do hash_multiset.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho máximo possível do hash_multiset.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_max_size.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int>::size_type i;

   i = hms1.max_size( );
   cout << "The maximum possible length "
        << "of the hash_multiset is " << i << "." << endl;
}
```

## <a name="op_eq"></a>  hash_multiset::operator=

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Substitui os elementos de hash_multiset por uma cópia de outro hash_multiset.

```cpp
hash_multiset& operator=(const hash_multiset& right);

hash_multiset& operator=(hash_multiset&& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|`right`|O [hash_multiset](../standard-library/hash-multiset-class.md) que está sendo copiado para o `hash_multiset`.|

### <a name="remarks"></a>Comentários

Após apagar os elementos existentes em um `hash_multiset`, `operator=` copiará ou moverá o conteúdo de `right` para `hash_multiset`.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_operator_as.cpp
// compile with: /EHsc
#include <hash_multiset>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset<int> v1, v2, v3;
   hash_multiset<int>::iterator iter;

   v1.insert(10);

   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << iter << " ";
   cout << endl;

   v2 = v1;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << iter << " ";
   cout << endl;

// move v1 into v2
   v2.clear();
   v2 = move(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << iter << " ";
   cout << endl;
}
```

## <a name="pointer"></a>  hash_multiset::pointer

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um ponteiro para um elemento em um hash_multiset.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo **pointer** pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto multiset.

## <a name="rbegin"></a>  hash_multiset::rbegin

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador que trata o primeiro elemento em um hash_multiset invertido.

```cpp
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido que trata do primeiro elemento em um hash_multiset invertido ou que trata do que foi o último elemento do hash_multiset não invertido.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um hash_multiset invertido, assim como [begin](#begin) é usado com um hash_multiset.

Se o valor retornado de `rbegin` for atribuído a `const_reverse_iterator`, o objeto hash_multiset não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto hash_multiset poderá ser modificado.

`rbegin` pode ser usado para iterar em um hash_multiset no sentido reverso.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_rbegin.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int>::iterator hms1_Iter;
   hash_multiset <int>::reverse_iterator hms1_rIter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );

   hms1_rIter = hms1.rbegin( );
   cout << "The first element in the reversed hash_multiset is "
        << *hms1_rIter << "." << endl;

   // begin can be used to start an iteration
   // throught a hash_multiset in a forward order
   cout << "The hash_multiset is: ";
   for ( hms1_Iter = hms1.begin( ) ; hms1_Iter != hms1.end( );
         hms1_Iter++ )
      cout << *hms1_Iter << " ";
   cout << endl;

   // rbegin can be used to start an iteration
   // throught a hash_multiset in a reverse order
   cout << "The reversed hash_multiset is: ";
   for ( hms1_rIter = hms1.rbegin( ) ; hms1_rIter != hms1.rend( );
         hms1_rIter++ )
      cout << *hms1_rIter << " ";
   cout << endl;

   // A hash_multiset element can be erased by dereferencing to its key
   hms1_rIter = hms1.rbegin( );
   hms1.erase ( *hms1_rIter );

   hms1_rIter = hms1.rbegin( );
   cout << "After the erasure, the first element "
        << "in the reversed hash_multiset is "<< *hms1_rIter << "."
        << endl;
}
```

```Output
The first element in the reversed hash_multiset is 30.
The hash_multiset is: 10 20 30
The reversed hash_multiset is: 30 20 10
After the erasure, the first element in the reversed hash_multiset is 20.
```

## <a name="reference"></a>  hash_multiset::reference

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece uma referência a um elemento armazenado em um hash_multiset.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::reference reference;
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_reference.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;

   hms1.insert( 10 );
   hms1.insert( 20 );

   // Declare and initialize a reference &Ref1 to the 1st element
   int &Ref1 = *hms1.begin( );

   cout << "The first element in the hash_multiset is "
        << Ref1 << "." << endl;

   // The value of the 1st element of the hash_multiset can be
   // changed by operating on its (non const) reference
   Ref1 = Ref1 + 5;

   cout << "The first element in the hash_multiset is now "
        << *hms1.begin() << "." << endl;
}
```

```Output
The first element in the hash_multiset is 10.
The first element in the hash_multiset is now 15.
```

## <a name="rend"></a>  hash_multiset::rend

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador que trata do local após o último elemento em um hash_multiset invertido.

```cpp
const_reverse_iterator rend() const;

reverse_iterator rend();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso que trata do local que vem após o último elemento em um hash_multiset invertido (o local que precedeu o primeiro elemento no hash_multiset não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um hash_multiset invertido, assim como [end](#end) é usado com um hash_multiset.

Se o valor retornado de `rend` for atribuído a `const_reverse_iterator`, o objeto hash_multiset não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto hash_multiset poderá ser modificado. O valor retornado por `rend` não deve ser desreferenciado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de seu hash_multiset.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_rend.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int>::iterator hms1_Iter;
   hash_multiset <int>::reverse_iterator hms1_rIter;
   hash_multiset <int>::const_reverse_iterator hms1_crIter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );

   hms1_rIter = hms1.rend( );
   hms1_rIter--;
   cout << "The last element in the reversed hash_multiset is "
        << *hms1_rIter << "." << endl;

   // end can be used to terminate an iteration
   // through a hash_multiset in a forward order
   cout << "The hash_multiset is: ";
   for ( hms1_Iter = hms1.begin( ) ; hms1_Iter != hms1.end( );
         hms1_Iter++ )
      cout << *hms1_Iter << " ";
   cout << "." << endl;

   // rend can be used to terminate an iteration
   // throught a hash_multiset in a reverse order
   cout << "The reversed hash_multiset is: ";
   for ( hms1_rIter = hms1.rbegin( ) ; hms1_rIter != hms1.rend( );
         hms1_rIter++ )
      cout << *hms1_rIter << " ";
   cout << "." << endl;

   hms1_rIter = hms1.rend( );
   hms1_rIter--;
   hms1.erase ( *hms1_rIter );

   hms1_rIter = hms1.rend( );
   hms1_rIter--;
   cout << "After the erasure, the last element in the "
        << "reversed hash_multiset is " << *hms1_rIter << "."
        << endl;
}
```

```Output
The last element in the reversed hash_multiset is 10.
The hash_multiset is: 10 20 30 .
The reversed hash_multiset is: 30 20 10 .
After the erasure, the last element in the reversed hash_multiset is 20.
```

## <a name="reverse_iterator"></a>  hash_multiset::reverse_iterator

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um hash_multiset invertido.

```cpp
typedef list<typename Traits::value_type, typename Traits::allocator_type>::reverse_iterator reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `reverse_iterator` é usado para iterar pelo hash_multiset em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.

## <a name="size"></a>  hash_multiset::size

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna o número de elementos no hash_multiset.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho atual do hash_multiset.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_size.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int> :: size_type i;

   hms1.insert( 1 );
   i = hms1.size( );
   cout << "The hash_multiset length is " << i << "." << endl;

   hms1.insert( 2 );
   i = hms1.size( );
   cout << "The hash_multiset length is now " << i << "." << endl;
}
```

```Output
The hash_multiset length is 1.
The hash_multiset length is now 2.
```

## <a name="size_type"></a>  hash_multiset::size_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo inteiro sem sinal que pode representar o número de elementos em um hash_multiset.

```cpp
typedef list<typename _Traits::value_type, typename _Traits::allocator_type>::size_type size_type;
```

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) para obter um exemplo de como declarar e usar `size_type`

## <a name="swap"></a>  hash_multiset::swap

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Troca os elementos de dois hash_multisets.

```cpp
void swap(hash_multiset& right);
```

### <a name="parameters"></a>Parâmetros

`right` O hash_multiset argumento fornecendo os elementos a ser trocado com o hash_multiset de destino.

### <a name="remarks"></a>Comentários

A função membro não invalida referências, ponteiros ou iteradores que designam elementos nos dois hash_multisets cujos elementos são trocados.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_swap.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1, hms2, hms3;
   hash_multiset <int>::iterator hms1_Iter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );
   hms2.insert( 100 );
   hms2.insert( 200 );
   hms3.insert( 300 );

   cout << "The original hash_multiset hms1 is:";
   for ( hms1_Iter = hms1.begin( ); hms1_Iter != hms1.end( );
         hms1_Iter++ )
         cout << " " << *hms1_Iter;
   cout   << "." << endl;

   // This is the member function version of swap
   hms1.swap( hms2 );

   cout << "After swapping with hms2, list hms1 is:";
   for ( hms1_Iter = hms1.begin( ); hms1_Iter != hms1.end( );
         hms1_Iter++ )
         cout << " " << *hms1_Iter;
   cout  << "." << endl;

   // This is the specialized template version of swap
   swap( hms1, hms3 );

   cout << "After swapping with hms3, list hms1 is:";
   for ( hms1_Iter = hms1.begin( ); hms1_Iter != hms1.end( );
         hms1_Iter++ )
         cout << " " << *hms1_Iter;
   cout   << "." << endl;
}
```

```Output
The original hash_multiset hms1 is: 10 20 30.
After swapping with hms2, list hms1 is: 200 100.
After swapping with hms3, list hms1 is: 300.
```

## <a name="upper_bound"></a>  hash_multiset::upper_bound

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Retorna um iterador para o primeiro elemento em um hash_multisets com uma chave que é maior que uma chave especificada.

```cpp
const_iterator upper_bound(const Key& key) const;

iterator upper_bound(const Key& key);
```

### <a name="parameters"></a>Parâmetros

`key` A chave de argumento a ser comparada com a chave de classificação de um elemento do hash_multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um [iterador](#iterator) ou [const_iterator](#const_iterator) que trata do local do primeiro elemento em um hash_multiset com uma chave maior que a chave de argumento ou que trata do local que sucede o último elemento em hash_multiset se nenhuma correspondência para a chave for encontrada.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_upper_bound.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int> :: const_iterator hms1_AcIter, hms1_RcIter;

   hms1.insert( 10 );
   hms1.insert( 20 );
   hms1.insert( 30 );

   hms1_RcIter = hms1.upper_bound( 20 );
   cout << "The first element of hash_multiset hms1" << endl
        << " with a key greater than 20 is: "
        << *hms1_RcIter << "." << endl;

   hms1_RcIter = hms1.upper_bound( 30 );

   // If no match is found for the key, end( ) is returned
   if ( hms1_RcIter == hms1.end( ) )
      cout << "The hash_multiset hms1 doesn't have an element "
           << "\n with a key greater than 30." << endl;
   else
      cout << "The element of hash_multiset hms1"
           << "with a key > 40 is: "
           << *hms1_RcIter << "." << endl;

   // An element at a specific location in the hash_multiset can be
   // found by using a dereferenced iterator addressing the location
   hms1_AcIter = hms1.begin( );
   hms1_RcIter = hms1.upper_bound( *hms1_AcIter );
   cout << "The first element of hms1\n with a key greater than "
        << endl << "that of the initial element of hms1 is: "
        << *hms1_RcIter << "." << endl;
}
```

```Output
The first element of hash_multiset hms1
 with a key greater than 20 is: 30.
The hash_multiset hms1 doesn't have an element
 with a key greater than 30.
The first element of hms1
 with a key greater than
that of the initial element of hms1 is: 20.
```

## <a name="value_comp"></a>  hash_multiset::value_comp

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Recupera uma cópia do objeto de comparação usado para ordenar valores de elemento em um hash_multiset.

```cpp
value_compare value_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o parâmetro de modelo hash_multiset `Traits`, que contém objetos de função usados para fazer o hash e para ordenar elementos do contêiner.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

### <a name="remarks"></a>Comentários

O objeto armazenado define uma função membro:

**operador booliano**( **constKey&**`_xVal`, **const Key&** *_yVal*);

que retornará **true** se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.

Observe que [key_compare](#key_compare) e [value_compare](#value_compare) são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes hash_multiset e hash_multiset, em que são idênticos, para compatibilidade com as classes hash_map e hash_multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_value_comp.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;

   hash_multiset <int, hash_compare < int, less<int> > > hms1;
   hash_multiset <int, hash_compare < int, less<int> > >::value_compare
      vc1 = hms1.value_comp( );
   bool result1 = vc1( 2, 3 );
   if( result1 == true )
   {
      cout << "vc1( 2,3 ) returns value of true, "
           << "where vc1 is the function object of hms1."
           << endl;
   }
   else
   {
      cout << "vc1( 2,3 ) returns value of false, "
           << "where vc1 is the function object of hms1."
           << endl;
   }

   hash_multiset <int, hash_compare < int, greater<int> > > hms2;
   hash_multiset<int, hash_compare < int, greater<int> > >::
           value_compare vc2 = hms2.value_comp( );
   bool result2 = vc2( 2, 3 );
   if( result2 == true )
   {
      cout << "vc2( 2,3 ) returns value of true, "
           << "where vc2 is the function object of hms2."
           << endl;
   }
   else
   {
      cout << "vc2( 2,3 ) returns value of false, "
           << "where vc2 is the function object of hms2."
           << endl;
   }
}
```

```Output
vc1( 2,3 ) returns value of true, where vc1 is the function object of hms1.
vc2( 2,3 ) returns value of false, where vc2 is the function object of hms2.
```

## <a name="value_compare"></a>  hash_multiset::value_compare

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que fornece dois objetos de função, um predicado binário da classe compare que pode comparar dois valores de elemento de um hash_multiset para determinar sua ordem relativa, bem como um predicado unário que faz o hash dos elementos.

```cpp
typedef key_compare value_compare;
```

### <a name="remarks"></a>Comentários

**value_compare** é um sinônimo do parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe hash_multiset](../standard-library/hash-multiset-class.md).

Observe que [key_compare](#key_compare) e **value_compare** são sinônimos do parâmetro de modelo **Traits**. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

Consulte o exemplo de [value_comp](#value_comp) para obter um exemplo de como declarar e usar `value_compare`.

## <a name="value_type"></a>  hash_multiset::value_type

> [!NOTE]
> Esta API está obsoleta. A alternativa é a [Classe unordered_multiset](../standard-library/unordered-multiset-class.md).

Um tipo que descreve um objeto armazenado como elemento como um hash_multiset em sua capacidade como um valor.

```cpp
typedef Key value_type;
```

### <a name="example"></a>Exemplo

```cpp
// hash_multiset_value_type.cpp
// compile with: /EHsc
#include <hash_set>
#include <iostream>

int main( )
{
   using namespace std;
   using namespace stdext;
   hash_multiset <int> hms1;
   hash_multiset <int>::iterator hms1_Iter;

   // Declare value_type
   hash_multiset <int> :: value_type hmsvt_Int;

   hmsvt_Int = 10;   // Initialize value_type

   // Declare key_type
   hash_multiset <int> :: key_type hmskt_Int;
   hmskt_Int = 20;             // Initialize key_type

   hms1.insert( hmsvt_Int );         // Insert value into s1
   hms1.insert( hmskt_Int );         // Insert key into s1

   // A hash_multiset accepts key_types or value_types as elements
   cout << "The hash_multiset has elements:";
   for ( hms1_Iter = hms1.begin() ; hms1_Iter != hms1.end( );
         hms1_Iter++)
      cout << " " << *hms1_Iter;
      cout << "." << endl;
}
```

```Output
The hash_multiset has elements: 10 20.
```

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
