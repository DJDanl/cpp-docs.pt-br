---
title: Classe multimap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- map/std::multimap
- map/std::multimap::allocator_type
- map/std::multimap::const_iterator
- map/std::multimap::const_pointer
- map/std::multimap::const_reference
- map/std::multimap::const_reverse_iterator
- map/std::multimap::difference_type
- map/std::multimap::iterator
- map/std::multimap::key_compare
- map/std::multimap::key_type
- map/std::multimap::mapped_type
- map/std::multimap::pointer
- map/std::multimap::reference
- map/std::multimap::reverse_iterator
- map/std::multimap::size_type
- map/std::multimap::value_type
- map/std::multimap::begin
- map/std::multimap::cbegin
- map/std::multimap::cend
- map/std::multimap::clear
- map/std::multimap::count
- map/std::multimap::crbegin
- map/std::multimap::crend
- map/std::multimap::emplace
- map/std::multimap::emplace_hint
- map/std::multimap::empty
- map/std::multimap::end
- map/std::multimap::equal_range
- map/std::multimap::erase
- map/std::multimap::find
- map/std::multimap::get_allocator
- map/std::multimap::insert
- map/std::multimap::key_comp
- map/std::multimap::lower_bound
- map/std::multimap::max_size
- map/std::multimap::rbegin
- map/std::multimap::rend
- map/std::multimap::size
- map/std::multimap::swap
- map/std::multimap::upper_bound
- map/std::multimap::value_comp
dev_langs:
- C++
helpviewer_keywords:
- std::multimap [C++]
- std::multimap [C++], allocator_type
- std::multimap [C++], const_iterator
- std::multimap [C++], const_pointer
- std::multimap [C++], const_reference
- std::multimap [C++], const_reverse_iterator
- std::multimap [C++], difference_type
- std::multimap [C++], iterator
- std::multimap [C++], key_compare
- std::multimap [C++], key_type
- std::multimap [C++], mapped_type
- std::multimap [C++], pointer
- std::multimap [C++], reference
- std::multimap [C++], reverse_iterator
- std::multimap [C++], size_type
- std::multimap [C++], value_type
- std::multimap [C++], begin
- std::multimap [C++], cbegin
- std::multimap [C++], cend
- std::multimap [C++], clear
- std::multimap [C++], count
- std::multimap [C++], crbegin
- std::multimap [C++], crend
- std::multimap [C++], emplace
- std::multimap [C++], emplace_hint
- std::multimap [C++], empty
- std::multimap [C++], end
- std::multimap [C++], equal_range
- std::multimap [C++], erase
- std::multimap [C++], find
- std::multimap [C++], get_allocator
- std::multimap [C++], insert
- std::multimap [C++], key_comp
- std::multimap [C++], lower_bound
- std::multimap [C++], max_size
- std::multimap [C++], rbegin
- std::multimap [C++], rend
- std::multimap [C++], size
- std::multimap [C++], swap
- std::multimap [C++], upper_bound
- std::multimap [C++], value_comp
ms.assetid: 8796ae05-37c4-475a-9e61-75fde9d4a463
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 29e94acf4b8fad401077a5530d4b6296c30c2740
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220102"
---
# <a name="multimap-class"></a>Classe multimap

A classe de multimap da biblioteca padrão C++ é usada para o armazenamento e a recuperação de dados de uma coleção em que cada elemento é um par que contém um valor de dados e uma chave de classificação. O valor da chave não precisa ser exclusivo e é usado para ordenar os dados automaticamente. O valor de um elemento em um multimapa, mas não seu valor de chave associado, pode ser alterado diretamente. Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave associados aos novos elementos inseridos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key,
    class Type,
    class Traits=less <Key>,
    class Allocator=allocator <pair  <const Key, Type>>>
class multimap;
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
 O tipo de dados da chave a ser armazenado no multimapa.

*Tipo*<br/>
 O tipo de dados do elemento a ser armazenado no multimapa.

*Características*<br/>
 O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no multimapa. O predicado binário `less<Key>` é o valor padrão.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#heterogeneous-lookup-in-associative-containers-c14)

*Alocador*<br/>
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e a desalocação do mapa da memória. Esse argumento é opcional e o valor padrão é `allocator<pair <const Key, Type> >`.

## <a name="remarks"></a>Comentários

A classe de multimap da biblioteca padrão C++ é

- Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.

- Reversível, pois fornece iteradores bidirecionais para acessar seus elementos.

- Classificada, pois seus elementos são ordenados por valores de chave no contêiner, de acordo com uma função de comparação especificada.

- Múltipla, pois seus elementos não precisam ter chaves exclusivas para que um valor de chave possa ter muitos valores de dados de elemento associados a ele.

- Um contêiner de par associativo, pois seus valores de dados de elemento são distintos de seus valores de chave.

- Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos ou chaves. Os tipos de dados a serem usados para elementos e chaves são especificados como parâmetros no modelo de classe juntamente com o alocador e a função de comparação.

O iterador fornecido pela classe de mapa é um iterador bidirecional, mas as funções membro de classe [insert](#insert) e [multimap](#multimap) têm versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais. Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador. Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência. Esse é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores `[First, Last)` no contexto de funções membro da classe.

A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Os contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que oferecem suporte explicitamente a essas operações são eficientes, executando-as em um tempo que está na média proporcional para o logaritmo do número de elementos no contêiner. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.

O multimapa deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras-chave com valores de cadeia de caracteres associados que fornecem, por exemplo, definições, em que as palavras nem sempre foram definidas exclusivamente. Se, em vez disso, as palavras-chave foram definidas exclusivamente para que essas chaves fossem exclusivas, um mapa seria o contêiner ideal. Se, por outro lado, apenas as listas de palavras foram sendo armazenadas, um conjunto seria o contêiner correto. Se não foram permitidas as várias ocorrências das palavras, um multiset seria a estrutura de contêiner apropriada.

O multimap ordena a sequência que controla chamando um objeto de função armazenado do tipo [key_compare](#key_compare). Esse objeto armazenado é uma função de comparação que pode ser acessada chamando a função membro [key_comp](#key_comp). De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário `f(x,y)` é um objeto de função que possui dois objetos de argumento, `x` e `y`, e um valor de retorno de true ou false. Uma ordenação imposta em um conjunto será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo, e se a equivalência for transitiva, onde dois objetos `x` e `y` são definidos para serem equivalentes quando ambos, `f(x,y)` e `f(y,x)` são false. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[multimap](#multimap)|Constrói um `multimap` que está vazio ou que é uma cópia de todo ou parte de algum outro `multimap`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para o objeto `multimap`.|
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador bidirecional que pode ler um **const** elemento o `multimap`.|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um **const** elemento em um `multimap`.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência a um **const** elemento armazenado em um `multimap` para leitura e execução **const** operações.|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer **const** elemento o `multimap`.|
|[difference_type](#difference_type)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um `multimap` em um intervalo entre os elementos apontado pelos iteradores.|
|[iterator](#iterator)|Um tipo que fornece a diferença entre dois iteradores que se referem a elementos no mesmo `multimap`.|
|[key_compare](#key_compare)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `multimap`.|
|[key_type](#key_type)|Um tipo que descreve o objeto de chave de classificação que constitui cada elemento do `multimap`.|
|[mapped_type](#mapped_type)|Um tipo que representa o tipo de dados armazenado em um `multimap`.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um **const** elemento em um `multimap`.|
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em um `multimap`.|
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um `multimap` invertido.|
|[size_type](#size_type)|Um tipo inteiro sem sinal que fornece um ponteiro para um **const** elemento em um `multimap`.|
|[value_type](#value_type)|Um tipo que fornece um objeto de função que pode comparar dois elementos como chaves de classificação para determinar sua ordem relativa no `multimap`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[begin](#begin)|Retorna um iterador que trata o primeiro elemento no `multimap`.|
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento no `multimap`.|
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em um `multimap`.|
|[clear](#clear)|Apaga todos os elementos de um `multimap`.|
|[count](#count)|Retorna o número de elementos em um `multimap` cuja chave corresponde a uma chave especificada pelo parâmetro.|
|[crbegin](#crbegin)|Retorna um iterador const que trata o primeiro elemento em um `multimap` invertido.|
|[crend](#crend)|Retorna um iterador const que trata o local após o último elemento em um `multimap` invertido.|
|[emplace](#emplace)|Insere um elemento construído adequadamente em um `multimap`.|
|[emplace_hint](#emplace_hint)|Insere um elemento construído adequadamente em um `multimap`, com uma dica de posicionamento|
|[empty](#empty)|Testa se `multimap` está vazio.|
|[end](#end)|Retorna um iterador que trata o local após o último elemento em um `multimap`.|
|[equal_range](#equal_range)|Localiza o intervalo de elementos em que a chave do elemento corresponde a um valor especificado.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um `multimap` das posições especificadas ou remove elementos que correspondem a uma chave especificada.|
|[find](#find)|Retorna um iterador que trata o primeiro local de um elemento em um `multimap` que tem uma chave equivalente a uma chave especificada.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` usada para construir o `multimap`.|
|[insert](#insert)|Insere um elemento ou um intervalo de elementos em um `multimap`.|
|[key_comp](#key_comp)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um `multimap`.|
|[lower_bound](#lower_bound)|Retorna um iterador para o primeiro elemento em um `multimap` com uma chave que é igual ou maior que uma chave especificada.|
|[max_size](#max_size)|Retorna o comprimento máximo do `multimap`.|
|[rbegin](#rbegin)|Retorna um iterador que trata o primeiro elemento em um `multimap` invertido.|
|[rend](#rend)|Retorna um iterador que trata o local após o último elemento em um `multimap` invertido.|
|[size](#size)|Retorna o número de elementos no `multimap`.|
|[swap](#swap)|Troca os elementos de dois `multimap`s.|
|[upper_bound](#upper_bound)|Retorna um iterador para o primeiro elemento em um `multimap` com uma chave que é maior que uma chave especificada.|
|[value_comp](#value_comp)|A função membro retorna um objeto de função que determina a ordem dos elementos em um `multimap` comparando os respectivos valores de chave.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Substitui os elementos de um `multimap` por uma cópia de outro `multimap`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<map>

**Namespace:** std

Os pares (**key**, **value**) são armazenados em um multimap como objetos do tipo `pair`. A classe de par exige o cabeçalho \<utility>, que é automaticamente incluído por \<map>.

## <a name="allocator_type"></a>  multimap::allocator_type

Um tipo que representa a classe allocator do objeto multimap.

```cpp
typedef Allocator allocator_type;
```

### <a name="example"></a>Exemplo

Consulte o exemplo para [get_allocator](#get_allocator) para obter um exemplo do uso de `allocator_type`.

## <a name="begin"></a>  multimap::begin

Retorna um iterador que trata o primeiro elemento no multimap.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata do primeiro elemento no multimap ou do local que sucede um multimap vazio.

### <a name="example"></a>Exemplo

```cpp
// multimap_begin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;

   multimap <int, int> :: iterator m1_Iter;
   multimap <int, int> :: const_iterator m1_cIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 0, 0 ) );
   m1.insert ( Int_Pair ( 1, 1 ) );
   m1.insert ( Int_Pair ( 2, 4 ) );

   m1_cIter = m1.begin ( );
   cout << "The first element of m1 is " << m1_cIter -> first << endl;

   m1_Iter = m1.begin ( );
   m1.erase ( m1_Iter );

   // The following 2 lines would err as the iterator is const
   // m1_cIter = m1.begin ( );
   // m1.erase ( m1_cIter );

   m1_cIter = m1.begin( );
   cout << "First element of m1 is now " << m1_cIter -> first << endl;
}
```

```Output
The first element of m1 is 0
First element of m1 is now 1
```

## <a name="cbegin"></a>  multimap::cbegin

Retorna um **const** iterador que trata o primeiro elemento no intervalo.

```cpp
const_iterator cbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um **const** iterador de acesso bidirecional que aponta para o primeiro elemento do intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).

### <a name="remarks"></a>Comentários

Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.

Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` seja um modificáveis (não - **const**) o contêiner de qualquer tipo que dá suporte à `begin()` e `cbegin()`.

```cpp
auto i1 = Container.begin();
// i1 is Container<T>::iterator
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator
```

## <a name="cend"></a>  multimap::cend

Retorna um **const** iterador que trata o local logo após o último elemento em um intervalo.

```cpp
const_iterator cend() const;
```

### <a name="return-value"></a>Valor de retorno

Um **const** iterador de acesso bidirecional que aponta para além do final do intervalo.

### <a name="remarks"></a>Comentários

`cend` é usado para testar se um iterador passou do fim de seu intervalo.

Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` seja um modificáveis (não - **const**) o contêiner de qualquer tipo que dá suporte à `end()` e `cend()`.

```cpp
auto i1 = Container.end();
// i1 is Container<T>::iterator
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator
```

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="clear"></a>  multimap::clear

Apaga todos os elementos de um multimap.

```cpp
void clear();
```

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro multimap::clear.

```cpp
// multimap_clear.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap<int, int> m1;
   multimap<int, int>::size_type i;
   typedef pair<int, int> Int_Pair;

   m1.insert(Int_Pair(1, 1));
   m1.insert(Int_Pair(2, 4));

   i = m1.size();
   cout << "The size of the multimap is initially "
        << i << "." << endl;

   m1.clear();
   i = m1.size();
   cout << "The size of the multimap after clearing is "
        << i << "." << endl;
}
```

```Output
The size of the multimap is initially 2.
The size of the multimap after clearing is 0.
```

## <a name="const_iterator"></a>  multimap::const_iterator

Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no multimap.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

O `const_iterator` definido pelo multimap aponta para objetos do [value_type](#value_type), que são do tipo `pair<const Key, Type>`. O valor da chave está disponível por meio do primeiro par de membros e o valor do elemento mapeado está disponível por meio do segundo membro do par.

A referência a um `const_iterator` *cIter* que aponta para um elemento em um multimap, use o **->** operador.

Para acessar o valor da chave do elemento, use `cIter->first`, que é equivalente a `(*cIter).first`. Para acessar o valor dos dados mapeados para o elemento, use `cIter->second`, que é equivalente a `(*cIter).second`.

### <a name="example"></a>Exemplo

Consulte o exemplo para [begin](#begin) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a>  multimap::const_pointer

Um tipo que fornece um ponteiro para um elemento **const** em um multimap.

```cpp
typedef typename allocator_type::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto multimap.

## <a name="const_reference"></a>  multimap::const_reference

Um tipo que fornece uma referência a um elemento **const** armazenado em um multimap para leitura e execução de operações **const**.

```cpp
typedef typename allocator_type::const_reference const_reference;
```

### <a name="example"></a>Exemplo

```cpp
// multimap_const_ref.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );

   // Declare and initialize a const_reference &Ref1
   // to the key of the first element
   const int &Ref1 = ( m1.begin( ) -> first );

   // The following line would cause an error because the
   // non-const_reference cannot be used to access the key
   // int &Ref1 = ( m1.begin( ) -> first );

   cout << "The key of the first element in the multimap is "
        << Ref1 << "." << endl;

   // Declare and initialize a reference &Ref2
   // to the data value of the first element
   int &Ref2 = ( m1.begin( ) -> second );

   cout << "The data value of the first element in the multimap is "
        << Ref2 << "." << endl;
}
```

```Output
The key of the first element in the multimap is 1.
The data value of the first element in the multimap is 10.
```

## <a name="const_reverse_iterator"></a>  multimap::const_reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no multimap.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar no multimap em ordem inversa.

O `const_reverse_iterator` definido pelo multimap aponta para objetos do [value_type](#value_type), que são do tipo `pair<const Key, Type>`. O valor da chave está disponível por meio do primeiro par de membros e o valor do elemento mapeado está disponível por meio do segundo membro do par.

A referência a um `const_reverse_iterator` *crIter* que aponta para um elemento em um multimap, use o **->** operador.

Para acessar o valor da chave do elemento, use `crIter->first`, que é equivalente a `(*crIter).first`. Para acessar o valor dos dados mapeados para o elemento, use `crIter->second`, que é equivalente a `(*crIter).first`.

### <a name="example"></a>Exemplo

Veja o exemplo de [rend](#rend) para obter uma demonstração de como declarar e usar o `const_reverse_iterator`.

## <a name="count"></a>  multimap::count

Retorna o número de elementos em um multimap cuja chave corresponde a uma chave especificada pelo parâmetro.

```cpp
size_type count(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave dos elementos a serem correspondidos do multimap.

### <a name="return-value"></a>Valor de retorno

O número de elementos cujas chaves de classificação correspondem à chave de parâmetro; 0 se o multimap não contiver um elemento com uma chave correspondente.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos no intervalo

[ `lower_bound` (_ *Key* ), `upper_bound` (\_ *Key* ) )

que têm um valor de chave *chave*.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro multimap::count.

```cpp
// multimap_count.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
    using namespace std;
    multimap<int, int> m1;
    multimap<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    m1.insert(Int_Pair(1, 1));
    m1.insert(Int_Pair(2, 1));
    m1.insert(Int_Pair(1, 4));
    m1.insert(Int_Pair(2, 1));

    // Elements do not need to have unique keys in multimap,
    // so duplicates are allowed and counted
    i = m1.count(1);
    cout << "The number of elements in m1 with a sort key of 1 is: "
         << i << "." << endl;

    i = m1.count(2);
    cout << "The number of elements in m1 with a sort key of 2 is: "
         << i << "." << endl;

    i = m1.count(3);
    cout << "The number of elements in m1 with a sort key of 3 is: "
         << i << "." << endl;
}
```

```Output
The number of elements in m1 with a sort key of 1 is: 2.
The number of elements in m1 with a sort key of 2 is: 2.
The number of elements in m1 with a sort key of 3 is: 0.
```

## <a name="crbegin"></a>  multimap::crbegin

Retorna um iterador const que trata o primeiro elemento em um multimap invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido const que trata do primeiro elemento em um [multimap](../standard-library/multimap-class.md) invertido ou que trata do que foi o último elemento do `multimap` não invertido.

### <a name="remarks"></a>Comentários

`crbegin` é usado com um `multimap` invertido, assim como [begin](#begin) é usado com um `multimap`.

Com o valor de retorno `crbegin`, o objeto `multimap` não pode ser modificado.

`crbegin` pode ser usado para iterar em um `multimap` no sentido inverso.

### <a name="example"></a>Exemplo

```cpp
// multimap_crbegin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;

   multimap <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_crIter = m1.crbegin( );
   cout << "The first element of the reversed multimap m1 is "
        << m1_crIter -> first << "." << endl;
}
```

```Output
The first element of the reversed multimap m1 is 3.
```

## <a name="crend"></a>  multimap::crend

Retorna um iterador const que trata o local após o último elemento em um multimap invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso const que trata da localização que vem após o último elemento em um [multimap](../standard-library/multimap-class.md) invertido (o local que precedeu o primeiro elemento no `multimap` não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um `multimap` invertido, assim como [multimap::end](#end) é usado com um `multimap`.

Com o valor de retorno `crend`, o objeto `multimap` não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `multimap`.

O valor retornado por `crend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// multimap_crend.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;

   multimap <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_crIter = m1.crend( );
   m1_crIter--;
   cout << "The last element of the reversed multimap m1 is "
        << m1_crIter -> first << "." << endl;
}
```

```Output
The last element of the reversed multimap m1 is 1.
```

## <a name="difference_type"></a>  multimap::difference_type

Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um multimap em um intervalo entre os elementos apontados pelos iteradores.

```cpp
typedef typename allocator_type::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

`difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. O `difference_type` normalmente é usado para representar o número de elementos no intervalo [*primeiro*, *último*) entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte pelos contêineres reversíveis, como conjunto, a subtração entre iteradores só tem suporte pelos iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como vetor.

### <a name="example"></a>Exemplo

```cpp
// multimap_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <map>
#include <algorithm>

int main( )
{
   using namespace std;
   multimap <int, int> m1;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 3, 20 ) );

   // The following will insert as multimap keys are not unique
   m1.insert ( Int_Pair ( 2, 30 ) );

   multimap <int, int>::iterator m1_Iter, m1_bIter, m1_eIter;
   m1_bIter = m1.begin( );
   m1_eIter = m1.end( );

   // Count the number of elements in a multimap
   multimap <int, int>::difference_type  df_count = 0;
   m1_Iter = m1.begin( );
   while ( m1_Iter != m1_eIter )
   {
      df_count++;
      m1_Iter++;
   }

   cout << "The number of elements in the multimap m1 is: "
        << df_count << "." << endl;
}
```

```Output
The number of elements in the multimap m1 is: 4.
```

## <a name="emplace"></a>  multimap::emplace

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada).

```cpp
template <class... Args>
iterator emplace(Args&&... args);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*args*|Os argumentos encaminhados para construir um elemento a ser inserido no multimap.|

### <a name="return-value"></a>Valor de retorno

Um iterador para o elemento recém-inserido.

### <a name="remarks"></a>Comentários

Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.

Se uma exceção for gerada durante a inserção, o contêiner permanecerá inalterado e a exceção será gerada novamente.

O [value_type](../standard-library/map-class.md#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

### <a name="example"></a>Exemplo

```cpp
// multimap_emplace.cpp
// compile with: /EHsc
#include <map>
#include <string>
#include <iostream>

using namespace std;

template <typename M> void print(const M& m) {
    cout << m.size() << " elements: " << endl;

    for (const auto& p : m) {
        cout << "(" << p.first <<  "," << p.second << ") ";
    }

    cout << endl;
}

int main()
{
    multimap<string, string> m1;

    m1.emplace("Anna", "Accounting");
    m1.emplace("Bob", "Accounting");
    m1.emplace("Carmine", "Engineering");

    cout << "multimap modified, now contains ";
    print(m1);
    cout << endl;

    m1.emplace("Bob", "Engineering");

    cout << "multimap modified, now contains ";
    print(m1);
    cout << endl;
}

```

## <a name="emplace_hint"></a>  multimap::emplace_hint

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.

```cpp
template <class... Args>
iterator emplace_hint(
    const_iterator where,
    Args&&... args);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*args*|Os argumentos encaminhados para construir um elemento a ser inserido no multimap.|
|*where*|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto preceder imediatamente *onde*, inserção poderá ocorrer em tempo constante amortizado, em vez de no tempo logarítmico.)|

### <a name="return-value"></a>Valor de retorno

Um iterador para o elemento recém-inserido.

### <a name="remarks"></a>Comentários

Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

O [value_type](../standard-library/map-class.md#value_type) de um elemento é um par, de forma que o valor de um elemento será um par ordenado com o primeiro componente igual ao valor de chave e o segundo componente igual ao valor dos dados do elemento.

Para obter um exemplo de código, consulte [map::emplace_hint](../standard-library/map-class.md#emplace_hint).

## <a name="empty"></a>  multimap::empty

Testa se um multimap está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o multimap estiver vazio; **false** se o multimap não estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// multimap_empty.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1, m2;

   typedef pair <int, int> Int_Pair;
   m1.insert ( Int_Pair ( 1, 1 ) );

   if ( m1.empty( ) )
      cout << "The multimap m1 is empty." << endl;
   else
      cout << "The multimap m1 is not empty." << endl;

   if ( m2.empty( ) )
      cout << "The multimap m2 is empty." << endl;
   else
      cout << "The multimap m2 is not empty." << endl;
}
```

```Output
The multimap m1 is not empty.
The multimap m2 is empty.
```

## <a name="end"></a>  multimap::end

Retorna o iterador que ultrapassa o fim.

```cpp
const_iterator end() const;


iterator end();
```

### <a name="return-value"></a>Valor de retorno

O iterador que ultrapassa o fim. Se o multimap estiver vazio, então, `multimap::end() == multimap::begin()`.

### <a name="remarks"></a>Comentários

**end** será usado para testar se um iterador passou do fim de seu multimap.

O valor retornado por **end** não deve ser desreferenciado.

Para obter um exemplo de código, consulte [multimap::find](#find).

## <a name="equal_range"></a>  multimap::equal_range

Localiza o intervalo de elementos em que a chave do elemento corresponde a um valor especificado.

```cpp
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave do argumento a ser comparada com a chave de classificação de um elemento do multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um par de iteradores em que o primeiro é o [lower_bound](#lower_bound) da chave e o segundo é o [upper_bound](#upper_bound) da chave.

Para acessar o primeiro iterador de um par `pr` retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).

### <a name="example"></a>Exemplo

```cpp
// multimap_equal_range.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef multimap <int, int, less<int> > IntMMap;
   IntMMap m1;
   multimap <int, int> :: const_iterator m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   pair <IntMMap::const_iterator, IntMMap::const_iterator> p1, p2;
   p1 = m1.equal_range( 2 );

   cout << "The lower bound of the element with "
        << "a key of 2 in the multimap m1 is: "
        << p1.first -> second << "." << endl;

   cout << "The upper bound of the element with "
        << "a key of 2 in the multimap m1 is: "
        << p1.second -> second << "." << endl;

   // Compare the upper_bound called directly
   m1_RcIter = m1.upper_bound( 2 );

   cout << "A direct call of upper_bound( 2 ) gives "
        << m1_RcIter -> second << "," << endl
        << " matching the 2nd element of the pair"
        << " returned by equal_range( 2 )." << endl;

   p2 = m1.equal_range( 4 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == m1.end( ) ) && ( p2.second == m1.end( ) ) )
      cout << "The multimap m1 doesn't have an element "
           << "with a key less than 4." << endl;
   else
      cout << "The element of multimap m1 with a key >= 40 is: "
           << p1.first -> first << "." << endl;
}
```

```Output
The lower bound of the element with a key of 2 in the multimap m1 is: 20.
The upper bound of the element with a key of 2 in the multimap m1 is: 30.
A direct call of upper_bound( 2 ) gives 30,
 matching the 2nd element of the pair returned by equal_range( 2 ).
The multimap m1 doesn't have an element with a key less than 4.
```

## <a name="erase"></a>  multimap::erase

Remove um elemento ou um intervalo de elementos em multimap das posições especificadas ou remove elementos que correspondem a uma chave especificada.

```cpp
iterator erase(
    const_iterator Where);

iterator erase(
    const_iterator First,
    const_iterator Last);

size_type erase(
    const key_type& Key);
```

### <a name="parameters"></a>Parâmetros

*Where*<br/>
 A posição do elemento a ser removido.

*Primeiro*<br/>
 A posição do primeiro elemento a ser removido.

*último*<br/>
 A posição logo após o último elemento a ser removido.

*Chave*<br/>
 A chave de elementos a serem removidos.

### <a name="return-value"></a>Valor de retorno

Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um elemento que será o final do mapa, se esse elemento não existir.

Para a terceira função membro, ele retorna o número de elementos que foram removidos do multimap.

### <a name="remarks"></a>Comentários

Para obter um exemplo de código, consulte [map::erase](../standard-library/map-class.md#erase).

## <a name="find"></a>  multimap::find

Retorna um iterador que aponta para o primeiro local de um elemento em um multimap que tem uma chave equivalente a uma chave especificada.

```cpp
iterator find(const Key& key);


const_iterator find(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 O valor da chave a ser comparado pela chave de classificação de um elemento do multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador que se refere ao local de um elemento com uma chave especificada ou o local seguinte ao último elemento no multimap (`multimap::end()`) se nenhuma correspondência for encontrada para a chave.

### <a name="remarks"></a>Comentários

A função de membro retorna um iterador que se refere a um elemento no multimap, cuja chave é equivalente à chave de argumento em um predicado binário que induz uma ordenação com base em uma relação de comparação menor.

Se o valor retornado de `find` for atribuído a um `const_iterator`, o objeto multimap não poderá ser modificado. Se o valor de retorno `find` for atribuído a um `iterator`, o objeto multimap poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4 /MTd
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <utility>  // make_pair()

using namespace std;

template <typename A, typename B> void print_elem(const pair<A, B>& p) {
    cout << "(" << p.first << ", " << p.second << ") ";
}

template <typename T> void print_collection(const T& t) {
    cout << t.size() << " elements: ";

    for (const auto& p : t) {
        print_elem(p);
    }
    cout << endl;
}

template <typename C, class T> void findit(const C& c, T val) {
    cout << "Trying find() on value " << val << endl;
    auto result = c.find(val);
    if (result != c.end()) {
        cout << "Element found: "; print_elem(*result); cout << endl;
    } else {
        cout << "Element not found." << endl;
    }
}

int main()
{
    multimap<int, string> m1({ { 40, "Zr" }, { 45, "Rh" } });
    cout << "The starting multimap m1 is (key, value):" << endl;
    print_collection(m1);

    vector<pair<int, string>> v;
    v.push_back(make_pair(43, "Tc"));
    v.push_back(make_pair(41, "Nb"));
    v.push_back(make_pair(46, "Pd"));
    v.push_back(make_pair(42, "Mo"));
    v.push_back(make_pair(44, "Ru"));
    v.push_back(make_pair(44, "Ru")); // attempt a duplicate

    cout << "Inserting the following vector data into m1:" << endl;
    print_collection(v);

    m1.insert(v.begin(), v.end());

    cout << "The modified multimap m1 is (key, value):" << endl;
    print_collection(m1);
    cout << endl;
    findit(m1, 45);
    findit(m1, 6);
}

```

## <a name="get_allocator"></a>  multimap::get_allocator

Retorna uma cópia do objeto alocador usado para construir o multimap.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

O alocador usado pelo multimap.

### <a name="remarks"></a>Comentários

Alocadores para a classe multimap especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>Exemplo

```cpp
// multimap_get_allocator.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int>::allocator_type m1_Alloc;
   multimap <int, int>::allocator_type m2_Alloc;
   multimap <int, double>::allocator_type m3_Alloc;
   multimap <int, int>::allocator_type m4_Alloc;

   // The following lines declare objects
   // that use the default allocator.
   multimap <int, int> m1;
   multimap <int, int, allocator<int> > m2;
   multimap <int, double, allocator<double> > m3;

   m1_Alloc = m1.get_allocator( );
   m2_Alloc = m2.get_allocator( );
   m3_Alloc = m3.get_allocator( );

   cout << "The number of integers that can be allocated"
        << endl << "before free memory is exhausted: "
        << m2.max_size( ) << ".\n" << endl;

   cout << "The number of doubles that can be allocated"
        << endl << "before free memory is exhausted: "
        << m3.max_size( ) <<  ".\n" << endl;

   // The following line creates a multimap m4
   // with the allocator of multimap m1.
   map <int, int> m4( less<int>( ), m1_Alloc );

   m4_Alloc = m4.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated via the other
   if( m1_Alloc == m4_Alloc )
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

## <a name="insert"></a>  multimap::insert

Insere um elemento ou um intervalo de elementos em um multimapa.

```cpp
// (1) single element
pair<iterator, bool> insert(
    const value_type& Val);


// (2) single element, perfect forwarded
template <class ValTy>
pair<iterator, bool>
insert(
    ValTy&& Val);


// (3) single element with hint
iterator insert(
    const_iterator Where,
    const value_type& Val);


// (4) single element, perfect forwarded, with hint
template <class ValTy>
iterator insert(
    const_iterator Where,
    ValTy&& Val);


// (5) range
template <class InputIterator>
void insert(
    InputIterator First,
    InputIterator Last);


// (6) initializer list
void insert(
    initializer_list<value_type>
IList);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*Val*|O valor de um elemento a ser inserido no multimapa.|
|*Where*|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto preceder imediatamente *onde*, inserção poderá ocorrer em tempo constante amortizado, em vez de no tempo logarítmico.)|
|*ValTy*|Parâmetro de modelo que especifica o tipo de argumento que o mapa pode usar para construir um elemento de [value_type](../standard-library/map-class.md#value_type)e perfect-forwards *Val* como um argumento.|
|*Primeiro*|A posição do primeiro elemento a ser copiado.|
|*último*|A posição imediatamente após o último elemento a ser copiado.|
|*InputIterator*|Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](../standard-library/map-class.md#value_type).|
|*IList*|O [initializer_list](../standard-library/initializer-list.md) do qual os elementos serão copiados.|

### <a name="return-value"></a>Valor de retorno

As funções do membro de inserir elemento único, (1) e (2), retornam um iterador para a posição em que o novo elemento foi inserido no multimapa.

As funções do membro de inserir elemento único, (3) e (4), retornam um iterador para a posição em que o novo elemento foi inserido no multimapa.

### <a name="remarks"></a>Comentários

Nenhum ponteiro ou referência é invalidado por esta função, mas ela pode invalidar todos os iteradores para o contêiner.

Durante a inserção de apenas um elemento, se uma exceção for lançada, o estado do contêiner não será modificado. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.

O [value_type](../standard-library/map-class.md#value_type) de um contêiner é um typedef que pertence ao contêiner e para o mapa, `multimap<K, V>::value_type` é `pair<const K, V>`. O valor de um elemento é um par ordenado no qual o primeiro componente é igual ao valor chave e o segundo componente é igual ao valor dos dados do elemento.

A função de membro de intervalo (5) insere a sequência de valores de elemento em um multimapa que corresponde a cada elemento tratado por um iterador no intervalo `[First, Last)`; portanto, *última* não é inserido. A função de membro do contêiner `end()` refere-se à posição logo após o último elemento no contêiner, por exemplo, a instrução `m.insert(v.begin(), v.end());` insere todos os elementos de `v` em `m`.

A função membro da lista do inicializador (6) usa um [initializer_list](../standard-library/initializer-list.md) para copiar elementos para um mapa.

Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [multimap::emplace](#emplace) e [multimap::emplace_hint](#emplace_hint).

### <a name="example"></a>Exemplo

```cpp
// multimap_insert.cpp
// compile with: /EHsc
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>  // make_pair()

using namespace std;

template <typename M> void print(const M& m) {
    cout << m.size() << " elements: ";

    for (const auto& p : m) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
}

int main()
{

    // insert single values
    multimap<int, int> m1;
    // call insert(const value_type&) version
    m1.insert({ 1, 10 });
    // call insert(ValTy&&) version
    m1.insert(make_pair(2, 20));

    cout << "The original key and mapped values of m1 are:" << endl;
    print(m1);

    // intentionally attempt a duplicate, single element
    m1.insert(make_pair(1, 111));

    cout << "The modified key and mapped values of m1 are:" << endl;
    print(m1);

    // single element, with hint
    m1.insert(m1.end(), make_pair(3, 30));
    cout << "The modified key and mapped values of m1 are:" << endl;
    print(m1);
    cout << endl;

    // The templatized version inserting a jumbled range
    multimap<int, int> m2;
    vector<pair<int, int>> v;
    v.push_back(make_pair(43, 294));
    v.push_back(make_pair(41, 262));
    v.push_back(make_pair(45, 330));
    v.push_back(make_pair(42, 277));
    v.push_back(make_pair(44, 311));

    cout << "Inserting the following vector data into m2:" << endl;
    print(v);

    m2.insert(v.begin(), v.end());

    cout << "The modified key and mapped values of m2 are:" << endl;
    print(m2);
    cout << endl;

    // The templatized versions move-constructing elements
    multimap<int, string>  m3;
    pair<int, string> ip1(475, "blue"), ip2(510, "green");

    // single element
    m3.insert(move(ip1));
    cout << "After the first move insertion, m3 contains:" << endl;
    print(m3);

    // single element with hint
    m3.insert(m3.end(), move(ip2));
    cout << "After the second move insertion, m3 contains:" << endl;
    print(m3);
    cout << endl;

    multimap<int, int> m4;
    // Insert the elements from an initializer_list
    m4.insert({ { 4, 44 }, { 2, 22 }, { 3, 33 }, { 1, 11 }, { 5, 55 } });
    cout << "After initializer_list insertion, m4 contains:" << endl;
    print(m4);
    cout << endl;
}

```

## <a name="iterator"></a>  multimap::iterator

Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um multimap.

```cpp
typedef implementation-defined iterator;
```

### <a name="remarks"></a>Comentários

O `iterator` definido pelo multimap aponta para objetos do [value_type](#value_type), que são do tipo `pair<const Key, Type>`. O valor da chave está disponível por meio do primeiro par de membros e o valor do elemento mapeado está disponível por meio do segundo membro do par.

A referência a um `iterator` *Iter* que aponta para um elemento em um multimap, use o **->** operador.

Para acessar o valor da chave do elemento, use `Iter->first`, que é equivalente a `(*Iter).first`. Para acessar o valor dos dados mapeados para o elemento, use `Iter->second`, que é equivalente a `(*Iter).second`.

Um tipo `iterator` pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Veja o exemplo de [begin](#begin) para obter um exemplo de como declarar e usar `iterator`.

## <a name="key_comp"></a>  multimap::key_comp

Recupera uma cópia do objeto de comparação usada para ordenar chaves em um multimap.

```cpp
key_compare key_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto de função que um multimap usa para ordenar seus elementos.

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro

`bool operator( const Key& x, const Key& y);`

que retornará true se *x* preceder estritamente *y* na ordem de classificação.

### <a name="example"></a>Exemplo

```cpp
// multimap_key_comp.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;

   multimap <int, int, less<int> > m1;
   multimap <int, int, less<int> >::key_compare kc1 = m1.key_comp( ) ;
   bool result1 = kc1( 2, 3 ) ;
   if( result1 == true )
   {
      cout << "kc1( 2,3 ) returns value of true, "
           << "where kc1 is the function object of m1."
           << endl;
   }
   else
   {
      cout << "kc1( 2,3 ) returns value of false "
           << "where kc1 is the function object of m1."
           << endl;
   }

   multimap <int, int, greater<int> > m2;
   multimap <int, int, greater<int> >::key_compare kc2 = m2.key_comp( );
   bool result2 = kc2( 2, 3 ) ;
   if( result2 == true )
   {
      cout << "kc2( 2,3 ) returns value of true, "
           << "where kc2 is the function object of m2."
           << endl;
   }
   else
   {
      cout << "kc2( 2,3 ) returns value of false, "
           << "where kc2 is the function object of m2."
           << endl;
   }
}
```

```Output
kc1( 2,3 ) returns value of true, where kc1 is the function object of m1.
kc2( 2,3 ) returns value of false, where kc2 is the function object of m2.
```

## <a name="key_compare"></a>  multimap::key_compare

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no multimap.

```cpp
typedef Traits key_compare;
```

### <a name="remarks"></a>Comentários

`key_compare` é um sinônimo do parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe multimap](../standard-library/multimap-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [key_comp](#key_comp) que demonstra como declarar e usar `key_compare`.

## <a name="key_type"></a>  multimap::key_type

Um tipo que descreve o objeto de chave de classificação que constitui cada elemento do multimap.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

`key_type` é um sinônimo do parâmetro de modelo `Key`.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe multimap](../standard-library/multimap-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="lower_bound"></a>  multimap::lower_bound

Retorna um iterador para o primeiro elemento em um multimap com uma chave que é igual ou maior que uma chave especificada.

```cpp
iterator lower_bound(const Key& key);

const_iterator lower_bound(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave do argumento a ser comparada com a chave de classificação de um elemento do multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador ou `const_iterator` que tratará a localização de um elemento em um multimap com uma chave, que é igual ou maior que a chave de argumento ou que tratará o local após o último elemento no multimap se nenhuma correspondência for encontrada para a chave.

Se o valor retornado de `lower_bound` for atribuído a um `const_iterator`, o objeto multimap não poderá ser modificado. Se o valor retornado de `lower_bound` for atribuído a um **iterador**, o objeto multimap poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// multimap_lower_bound.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;
   multimap <int, int> :: const_iterator m1_AcIter, m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_RcIter = m1.lower_bound( 2 );
   cout << "The element of multimap m1 with a key of 2 is: "
        << m1_RcIter -> second << "." << endl;

   m1_RcIter = m1.lower_bound( 3 );
   cout << "The first element of multimap m1 with a key of 3 is: "
        << m1_RcIter -> second << "." << endl;

   // If no match is found for the key, end( ) is returned
   m1_RcIter = m1.lower_bound( 4 );

   if ( m1_RcIter == m1.end( ) )
      cout << "The multimap m1 doesn't have an element "
              << "with a key of 4." << endl;
   else
      cout << "The element of multimap m1 with a key of 4 is: "
                << m1_RcIter -> second << "." << endl;

   // The element at a specific location in the multimap can be
   // found using a dereferenced iterator addressing the location
   m1_AcIter = m1.end( );
   m1_AcIter--;
   m1_RcIter = m1.lower_bound( m1_AcIter -> first );
   cout << "The first element of m1 with a key matching\n"
        << "that of the last element is: "
        << m1_RcIter -> second << "." << endl;

   // Note that the first element with a key equal to
   // the key of the last element is not the last element
   if ( m1_RcIter == --m1.end( ) )
      cout << "This is the last element of multimap m1."
           << endl;
   else
      cout << "This is not the last element of multimap m1."
           << endl;
}
```

```Output
The element of multimap m1 with a key of 2 is: 20.
The first element of multimap m1 with a key of 3 is: 20.
The multimap m1 doesn't have an element with a key of 4.
The first element of m1 with a key matching
that of the last element is: 20.
This is not the last element of multimap m1.
```

## <a name="mapped_type"></a>  multimap::mapped_type

Um tipo que representa o tipo de dados armazenado em um multimap.

```cpp
typedef Type mapped_type;
```

### <a name="remarks"></a>Comentários

`mapped_type` é um sinônimo do parâmetro de modelo `Type`.

Para obter mais informações sobre `Type`, consulte o tópico [Classe multimap](../standard-library/multimap-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="max_size"></a>  multimap::max_size

Retorna o comprimento máximo do multimap.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento máximo possível do multimap.

### <a name="example"></a>Exemplo

```cpp
// multimap_max_size.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;
   multimap <int, int> :: size_type i;

   i = m1.max_size( );
   cout << "The maximum possible length "
        << "of the multimap is " << i << "." << endl;
}
```

## <a name="multimap"></a>  multimap::multimap

Cria um multimap que está vazio ou que é uma cópia de todo ou parte de algum outro multimap.

```cpp
multimap();

explicit multimap(
    const Traits& Comp);

multimap(
    const Traits& Comp,
    const Allocator& Al);

map(
    const multimap& Right);

multimap(
    multimap&& Right);

multimap(
    initializer_list<value_type> IList);

multimap(
    initializer_list<value_type> IList,
    const Compare& Comp);

multimap(
    initializer_list<value_type> IList,
    const Compare& Comp,
    const Allocator& Al);

template <class InputIterator>
multimap(
 InputIterator First,
    InputIterator Last);

template <class InputIterator>
multimap(
 InputIterator First,
    InputIterator Last,
    const Traits& Comp);

template <class InputIterator>
multimap(
 InputIterator First,
    InputIterator Last,
    const Traits& Comp,
    const Allocator& Al);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*Al*|A classe do alocador de armazenamento a ser usado neste objeto multimap, cujo padrão é Allocator.|
|*Comp*|A função de comparação do tipo `constTraits` usada para ordenar os elementos no mapa, cujo padrão é `Traits`.|
|*Direita*|O mapa do qual o conjunto criado é uma cópia.|
|*Primeiro*|A posição do primeiro elemento no intervalo de elementos a serem copiados.|
|*último*|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|
|*IList*|O initializer_list do qual copiar os elementos.|

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o multimap e que, posteriormente, pode ser retornado ao chamar [get_allocator](#get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.

Todos os construtores inicializam seu multimap.

Todos os construtores armazenam um objeto de função do tipo `Traits`, que é usado para estabelecer uma ordem entre as chaves do multimap e que posteriormente pode ser retornado ao chamar [key_comp](#key_comp).

Os primeiros três construtores especificam um mapa inicial vazio, o segundo Especifica o tipo de função de comparação (*Comp*) para ser utilizado para estabelecer explicitamente a ordem dos elementos e o terceiro Especifica o tipo de alocador (*Al*) a ser usado. A palavra-chave **explícita** suprime determinados tipos de conversão de tipo automática.

O quarto construtor Especifica uma cópia do multimap *direita*.

O quinto construtor Especifica uma cópia do multimap ao mover *direita*.

O sexto, sétimo e oitavo construtores usam um initializer_list do qual os membros são copiados.

Os próximos três construtores copiam o intervalo `[First, Last)` de um mapa com clareza crescente para especificar o tipo de função de comparação da classe `Traits` e do alocador.

### <a name="example"></a>Exemplo

```cpp
// multimap_ctor.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    typedef pair <int, int> Int_Pair;

    // Create an empty multimap m0 of key type integer
    multimap <int, int> m0;

    // Create an empty multimap m1 with the key comparison
    // function of less than, then insert 4 elements
    multimap <int, int, less<int> > m1;
    m1.insert(Int_Pair(1, 10));
    m1.insert(Int_Pair(2, 20));
    m1.insert(Int_Pair(3, 30));
    m1.insert(Int_Pair(4, 40));

    // Create an empty multimap m2 with the key comparison
    // function of geater than, then insert 2 elements
    multimap <int, int, less<int> > m2;
    m2.insert(Int_Pair(1, 10));
    m2.insert(Int_Pair(2, 20));

    // Create a multimap m3 with the
    // allocator of multimap m1
    multimap <int, int>::allocator_type m1_Alloc;
    m1_Alloc = m1.get_allocator();
    multimap <int, int> m3(less<int>(), m1_Alloc);
    m3.insert(Int_Pair(3, 30));

    // Create a copy, multimap m4, of multimap m1
    multimap <int, int> m4(m1);

    // Create a multimap m5 by copying the range m1[ first,  last)
    multimap <int, int>::const_iterator m1_bcIter, m1_ecIter;
    m1_bcIter = m1.begin();
    m1_ecIter = m1.begin();
    m1_ecIter++;
    m1_ecIter++;
    multimap <int, int> m5(m1_bcIter, m1_ecIter);

    // Create a multimap m6 by copying the range m4[ first,  last)
    // and with the allocator of multimap m2
    multimap <int, int>::allocator_type m2_Alloc;
    m2_Alloc = m2.get_allocator();
    multimap <int, int> m6(m4.begin(), ++m4.begin(), less<int>(), m2_Alloc);

    cout << "m1 =";
    for (auto i : m1)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m2 =";
    for (auto i : m2)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m3 =";
    for (auto i : m3)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m4 =";
    for (auto i : m4)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m5 =";
    for (auto i : m5)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    cout << "m6 =";
    for (auto i : m6)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a multimap m8 by copying in an initializer_list
    multimap<int, int> m8{ { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 } } };
    cout << "m8: = ";
    for (auto i : m8)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a multimap m9 with an initializer_list and a comparator
    multimap<int, int> m9({ { 5, 5 }, { 6, 6 }, { 7, 7 }, { 8, 8 } }, less<int>());
    cout << "m9: = ";
    for (auto i : m9)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

    // Create a multimap m10 with an initializer_list, a comparator, and an allocator
    multimap<int, int> m10({ { 9, 9 }, { 10, 10 }, { 11, 11 }, { 12, 12 } }, less<int>(), m9.get_allocator());
    cout << "m10: = ";
    for (auto i : m10)
        cout << i.first << " " << i.second << ", ";
    cout << endl;

}

```

## <a name="op_eq"></a>  multimap::operator=

Substitui os elementos de um multimap por uma cópia de outro multimap.

```cpp
multimap& operator=(const multimap& right);

multimap& operator=(multimap&& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*right*|O [multimap](../standard-library/multimap-class.md) que está sendo copiado em `multimap`.|

### <a name="remarks"></a>Comentários

Depois de apagar os elementos existentes em uma `multimap`, `operator=` copiará ou moverá o conteúdo do *à direita* para o `multimap`.

### <a name="example"></a>Exemplo

```cpp
// multimap_operator_as.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
   {
   using namespace std;
   multimap<int, int> v1, v2, v3;
   multimap<int, int>::iterator iter;

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

## <a name="pointer"></a>  multimap::pointer

Um tipo que fornece um ponteiro para um elemento em um multimap.

```cpp
typedef typename allocator_type::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo `pointer` pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto multimap.

## <a name="rbegin"></a>  multimap::rbegin

Retorna um iterador que trata o primeiro elemento em um multimap inverso.

```cpp
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido que trata do primeiro elemento em um multimap invertido ou que trata do que foi o último elemento do multimap não invertido.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um multimap invertido, assim como [begin](#begin) é usado com um multimap.

Se o valor retornado de `rbegin` for atribuído a um `const_reverse_iterator`, o objeto multimap não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a um `reverse_iterator`, o objeto multimap poderá ser modificado.

`rbegin` pode ser usado para iterar em um multimap no sentido reverso.

### <a name="example"></a>Exemplo

```cpp
// multimap_rbegin.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;

   multimap <int, int> :: iterator m1_Iter;
   multimap <int, int> :: reverse_iterator m1_rIter;
   multimap <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_rIter = m1.rbegin( );
   cout << "The first element of the reversed multimap m1 is "
        << m1_rIter -> first << "." << endl;

   // begin can be used to start an iteration
   // throught a multimap in a forward order
   cout << "The multimap is: ";
   for ( m1_Iter = m1.begin( ) ; m1_Iter != m1.end( ); m1_Iter++)
      cout << m1_Iter -> first << " ";
      cout << "." << endl;

   // rbegin can be used to start an iteration
   // throught a multimap in a reverse order
   cout << "The reversed multimap is: ";
   for ( m1_rIter = m1.rbegin( ) ; m1_rIter != m1.rend( ); m1_rIter++)
      cout << m1_rIter -> first << " ";
      cout << "." << endl;

   // A multimap element can be erased by dereferencing its key
   m1_rIter = m1.rbegin( );
   m1.erase ( m1_rIter -> first );

   m1_rIter = m1.rbegin( );
   cout << "After the erasure, the first element "
        << "in the reversed multimap is "
        << m1_rIter -> first << "." << endl;
}
```

```Output
The first element of the reversed multimap m1 is 3.
The multimap is: 1 2 3 .
The reversed multimap is: 3 2 1 .
After the erasure, the first element in the reversed multimap is 2.
```

## <a name="reference"></a>  multimap::reference

Um tipo que fornece uma referência a um elemento armazenado em um multimap.

```cpp
typedef typename allocator_type::reference reference;
```

### <a name="example"></a>Exemplo

```cpp
// multimap_ref.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );

   // Declare and initialize a const_reference &Ref1
   // to the key of the first element
   const int &Ref1 = ( m1.begin( ) -> first );

   // The following line would cause an error because the
   // non-const_reference cannot be used to access the key
   // int &Ref1 = ( m1.begin( ) -> first );

   cout << "The key of first element in the multimap is "
        << Ref1 << "." << endl;

   // Declare and initialize a reference &Ref2
   // to the data value of the first element
   int &Ref2 = ( m1.begin( ) -> second );

   cout << "The data value of first element in the multimap is "
        << Ref2 << "." << endl;

   // The non-const_reference can be used to modify the
   // data value of the first element
   Ref2 = Ref2 + 5;
   cout << "The modified data value of first element is "
        << Ref2 << "." << endl;
}
```

```Output
The key of first element in the multimap is 1.
The data value of first element in the multimap is 10.
The modified data value of first element is 15.
```

## <a name="rend"></a>  multimap::rend

Retorna um iterador que trata o local após o último elemento em um multimap invertido.

```cpp
const_reverse_iterator rend() const;

reverse_iterator rend();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso que trata da localização que vem após o último elemento em um multimap invertido (o local que precedeu o primeiro elemento no multimap não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um multimap invertido, assim como [end](../standard-library/map-class.md#end) é usado com um multimap.

Se o valor retornado de `rend` for atribuído a um `const_reverse_iterator`, o objeto multimap não poderá ser modificado. Se o valor retornado de `rend` for atribuído a um `reverse_iterator`, o objeto multimap poderá ser modificado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de seu multimap.

O valor retornado por `rend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// multimap_rend.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;

   multimap <int, int> :: iterator m1_Iter;
   multimap <int, int> :: reverse_iterator m1_rIter;
   multimap <int, int> :: const_reverse_iterator m1_crIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );

   m1_rIter = m1.rend( );
   m1_rIter--;
   cout << "The last element of the reversed multimap m1 is "
        << m1_rIter -> first << "." << endl;

   // begin can be used to start an iteration
   // throught a multimap in a forward order
   cout << "The multimap is: ";
   for ( m1_Iter = m1.begin( ) ; m1_Iter != m1.end( ); m1_Iter++)
      cout << m1_Iter -> first << " ";
      cout << "." << endl;

   // rbegin can be used to start an iteration
   // throught a multimap in a reverse order
   cout << "The reversed multimap is: ";
   for ( m1_rIter = m1.rbegin( ) ; m1_rIter != m1.rend( ); m1_rIter++)
      cout << m1_rIter -> first << " ";
      cout << "." << endl;

   // A multimap element can be erased by dereferencing to its key
   m1_rIter = --m1.rend( );
   m1.erase ( m1_rIter -> first );

   m1_rIter = m1.rend( );
   m1_rIter--;
   cout << "After the erasure, the last element "
        << "in the reversed multimap is "
        << m1_rIter -> first << "." << endl;
}
```

```Output
The last element of the reversed multimap m1 is 1.
The multimap is: 1 2 3 .
The reversed multimap is: 3 2 1 .
After the erasure, the last element in the reversed multimap is 2.
```

## <a name="reverse_iterator"></a>  multimap::reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um multimap invertido.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `reverse_iterator` é usado para iterar pelo multimap em ordem inversa.

O `reverse_iterator` definido pelo multimap aponta para objetos do [value_type](#value_type), que são do tipo `pair<const Key, Type>`. O valor da chave está disponível por meio do primeiro par de membros e o valor do elemento mapeado está disponível por meio do segundo membro do par.

A referência a um `reverse_iterator` *rIter* que aponta para um elemento em um multimap, use o **->** operador.

Para acessar o valor da chave do elemento, use `rIter->first`, que é equivalente a `(*rIter).first`. Para acessar o valor dos dados mapeados para o elemento, use `rIter->second`, que é equivalente a `(*rIter).second`.

### <a name="example"></a>Exemplo

Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.

## <a name="size"></a>  multimap::size

Retorna o número de elementos no multimap.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento atual do multimap.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro multimap::size.

```cpp
// multimap_size.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main()
{
    using namespace std;
    multimap<int, int> m1, m2;
    multimap<int, int>::size_type i;
    typedef pair<int, int> Int_Pair;

    m1.insert(Int_Pair(1, 1));
    i = m1.size();
    cout << "The multimap length is " << i << "." << endl;

    m1.insert(Int_Pair(2, 4));
    i = m1.size();
    cout << "The multimap length is now " << i << "." << endl;
}
```

```Output
The multimap length is 1.
The multimap length is now 2.
```

## <a name="size_type"></a>  multimap::size_type

Um tipo inteiro sem sinal que conta o número de elementos em um multimap.

```cpp
typedef typename allocator_type::size_type size_type;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) que demonstra como declarar e usar `size_type`

## <a name="swap"></a>  multimap::swap

Troca os elementos de dois multimaps.

```cpp
void swap(
    multimap<Key, Type, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
 O multimap que fornece os elementos que serão trocados ou o multimap cujos elementos deverão ser trocados com aqueles do multimap `left`.

### <a name="remarks"></a>Comentários

A função membro não invalida referências, ponteiros ou iteradores que designam elementos nos dois multimaps cujos elementos são trocados.

### <a name="example"></a>Exemplo

```cpp
// multimap_swap.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1, m2, m3;
   multimap <int, int>::iterator m1_Iter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );
   m2.insert ( Int_Pair ( 10, 100 ) );
   m2.insert ( Int_Pair ( 20, 200 ) );
   m3.insert ( Int_Pair ( 30, 300 ) );

   cout << "The original multimap m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
   cout   << "." << endl;

   // This is the member function version of swap
   m1.swap( m2 );

   cout << "After swapping with m2, multimap m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
   cout  << "." << endl;

   // This is the specialized template version of swap
   swap( m1, m3 );

   cout << "After swapping with m3, multimap m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
   cout   << "." << endl;
}
```

```Output
The original multimap m1 is: 10 20 30.
After swapping with m2, multimap m1 is: 100 200.
After swapping with m3, multimap m1 is: 300.
```

## <a name="upper_bound"></a>  multimap::upper_bound

Retorna um iterador para o primeiro elemento em um multimap com uma chave que é maior que uma chave especificada.

```cpp
iterator upper_bound(const Key& key);

const_iterator upper_bound(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave do argumento a ser comparada com a chave de classificação de um elemento do multimap que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador ou `const_iterator` que tratará a localização de um elemento em um multimap com uma chave, que é maior que a chave de argumento ou que tratará o local após o último elemento no multimap se nenhuma correspondência for encontrada para a chave.

Se o valor retornado for atribuído a um `const_iterator`, o objeto multimap não poderá ser modificado. Se o valor retornado for atribuído a um `iterator`, o objeto multimap poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// multimap_upper_bound.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   multimap <int, int> m1;
   multimap <int, int> :: const_iterator m1_AcIter, m1_RcIter;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );
   m1.insert ( Int_Pair ( 3, 40 ) );

   m1_RcIter = m1.upper_bound( 1 );
   cout << "The 1st element of multimap m1 with "
        << "a key greater than 1 is: "
        << m1_RcIter -> second << "." << endl;

   m1_RcIter = m1.upper_bound( 2 );
   cout << "The first element of multimap m1 with a key "
        << " greater than 2 is: "
        << m1_RcIter -> second << "." << endl;

   // If no match is found for the key, end( ) is returned
   m1_RcIter = m1.lower_bound( 4 );

   if ( m1_RcIter == m1.end( ) )
      cout << "The multimap m1 doesn't have an element "
           << "with a key of 4." << endl;
   else
      cout << "The element of multimap m1 with a key of 4 is: "
           << m1_RcIter -> second << "." << endl;

   // The element at a specific location in the multimap can be
   // found using a derefenced iterator addressing the location
   m1_AcIter = m1.begin( );
   m1_RcIter = m1.upper_bound( m1_AcIter -> first );
   cout << "The first element of m1 with a key greater than\n"
        << "that of the initial element of m1 is: "
        << m1_RcIter -> second << "." << endl;
}
```

```Output
The 1st element of multimap m1 with a key greater than 1 is: 20.
The first element of multimap m1 with a key  greater than 2 is: 30.
The multimap m1 doesn't have an element with a key of 4.
The first element of m1 with a key greater than
that of the initial element of m1 is: 20.
```

## <a name="value_comp"></a>  multimap::value_comp

A função membro retorna um objeto de função que determina a ordem dos elementos em um multimap comparando os respectivos valores de chave.

```cpp
value_compare value_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto da função de comparação que um multimap usa para ordenar seus elementos.

### <a name="remarks"></a>Comentários

Para um multimap *m*, se dois elementos *e*1( *k*1, *d*1) e *e*2( *k*2, `d`2) forem objetos do tipo `value_type`, nos quais *k*1 e *k*2 forem suas chaves do tipo `key_type` e `d`1 e `d`2 forem seus dados do tipo `mapped_type`, então *m.*`value_comp`( *e*1, *e*2) será equivalente a *m.*`key_comp`( *k*1, *k*2).

### <a name="example"></a>Exemplo

```cpp
// multimap_value_comp.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;

   multimap <int, int, less<int> > m1;
   multimap <int, int, less<int> >::value_compare vc1 = m1.value_comp( );
   multimap<int,int>::iterator Iter1, Iter2;

   Iter1= m1.insert ( multimap <int, int> :: value_type ( 1, 10 ) );
   Iter2= m1.insert ( multimap <int, int> :: value_type ( 2, 5 ) );

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

```Output
The element ( 1,10 ) precedes the element ( 2,5 ).
The element ( 2,5 ) does not precede the element ( 1,10 ).
```

## <a name="value_type"></a>  multimap::value_type

Um tipo que representa o tipo de objeto armazenado como um elemento em um mapa.

```cpp
typedef pair<const Key, Type> value_type;
```

### <a name="example"></a>Exemplo

```cpp
// multimap_value_type.cpp
// compile with: /EHsc
#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef pair <const int, int> cInt2Int;
   multimap <int, int> m1;
   multimap <int, int> :: key_type key1;
   multimap <int, int> :: mapped_type mapped1;
   multimap <int, int> :: value_type value1;
   multimap <int, int> :: iterator pIter;

   // value_type can be used to pass the correct type
   // explicitely to avoid implicit type conversion
   m1.insert ( multimap <int, int> :: value_type ( 1, 10 ) );

   // Compare another way to insert objects into a hash_multimap
   m1.insert ( cInt2Int ( 2, 20 ) );

   // Initializing key1 and mapped1
   key1 = ( m1.begin( ) -> first );
   mapped1 = ( m1.begin( ) -> second );

   cout << "The key of first element in the multimap is "
        << key1 << "." << endl;

   cout << "The data value of first element in the multimap is "
        << mapped1 << "." << endl;

   // The following line would cause an error because
   // the value_type is not assignable
   // value1 = cInt2Int ( 4, 40 );

   cout  << "The keys of the mapped elements are:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> first;
   cout << "." << endl;

   cout  << "The values of the mapped elements are:";
   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> second;
   cout << "." << endl;
}
```

```Output
The key of first element in the multimap is 1.
The data value of first element in the multimap is 10.
The keys of the mapped elements are: 1 2.
The values of the mapped elements are: 10 20.
```

## <a name="see-also"></a>Consulte também

[\<Map > membros](https://msdn.microsoft.com/7e8f0bc2-6034-40f6-9d14-76d4cef86308)<br/>
[Contêineres](../cpp/containers-modern-cpp.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
