---
title: Classe set
ms.date: 11/04/2016
f1_keywords:
- set/std::set
- set/std::set::allocator_type
- set/std::set::const_iterator
- set/std::set::const_pointer
- set/std::set::const_reference
- set/std::set::const_reverse_iterator
- set/std::set::difference_type
- set/std::set::iterator
- set/std::set::key_compare
- set/std::set::key_type
- set/std::set::pointer
- set/std::set::reference
- set/std::set::reverse_iterator
- set/std::set::size_type
- set/std::set::value_compare
- set/std::set::value_type
- set/std::set::begin
- set/std::set::cbegin
- set/std::set::cend
- set/std::set::clear
- set/std::set::count
- set/std::set::crbegin
- set/std::set::crend
- set/std::set::emplace
- set/std::set::emplace_hint
- set/std::set::empty
- set/std::set::end
- set/std::set::equal_range
- set/std::set::erase
- set/std::set::find
- set/std::set::get_allocator
- set/std::set::insert
- set/std::set::key_comp
- set/std::set::lower_bound
- set/std::set::max_size
- set/std::set::rbegin
- set/std::set::rend
- set/std::set::size
- set/std::set::swap
- set/std::set::upper_bound
- set/std::set::value_comp
helpviewer_keywords:
- std::set [C++]
- std::set [C++], allocator_type
- std::set [C++], const_iterator
- std::set [C++], const_pointer
- std::set [C++], const_reference
- std::set [C++], const_reverse_iterator
- std::set [C++], difference_type
- std::set [C++], iterator
- std::set [C++], key_compare
- std::set [C++], key_type
- std::set [C++], pointer
- std::set [C++], reference
- std::set [C++], reverse_iterator
- std::set [C++], size_type
- std::set [C++], value_compare
- std::set [C++], value_type
- std::set [C++], begin
- std::set [C++], cbegin
- std::set [C++], cend
- std::set [C++], clear
- std::set [C++], count
- std::set [C++], crbegin
- std::set [C++], crend
- std::set [C++], emplace
- std::set [C++], emplace_hint
- std::set [C++], empty
- std::set [C++], end
- std::set [C++], equal_range
- std::set [C++], erase
- std::set [C++], find
- std::set [C++], get_allocator
- std::set [C++], insert
- std::set [C++], key_comp
- std::set [C++], lower_bound
- std::set [C++], max_size
- std::set [C++], rbegin
- std::set [C++], rend
- std::set [C++], size
- std::set [C++], swap
- std::set [C++], upper_bound
- std::set [C++], value_comp
ms.assetid: 8991f9aa-5509-4440-adc1-371512d32018
ms.openlocfilehash: 8f4ad77c28b4643a979d7c3fb22e44e4aebd43dd
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694732"
---
# <a name="set-class"></a>Classe set

O conjunto de classes de contêiner da biblioteca padrão C++ é usado para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados. O valor de um elemento em um conjunto não pode ser alterado diretamente. Em vez disso, você deve excluir valores antigos e inserir elementos com novos valores.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key,
    class Traits=less<Key>,
    class Allocator=allocator<Key>>
class set
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
O tipo de dados do elemento a ser armazenado no conjunto.

*Características*<br/>
O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no conjunto. Esse argumento é opcional e o predicado binário **less** *\<Key>* é o valor padrão.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

*Alocador*<br/>
O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e a desalocação do conjunto da memória. Esse argumento é opcional e o valor padrão é `allocator<Key>`.

## <a name="remarks"></a>Comentários

A Biblioteca Padrão C++ é:

- Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado. Além disso, é um contêiner associativo simples, pois seus valores de elemento são seus valores de chave.

- Reversível, pois fornece um iterador bidirecional para acessar seus elementos.

- Classificada, pois seus elementos são ordenados por valores de chave no contêiner, de acordo com uma função de comparação especificada.

- Exclusivo no sentido de que cada um de seus elementos deve ter uma chave exclusiva. Uma vez que o conjunto também é um contêiner associativo simples, seus elementos também são exclusivos.

Um conjunto também é descrito como uma classe de modelo, pois a funcionalidade fornecida por ele é genérica e independente do tipo de dados específico contido como elementos. O tipo de dados a ser usado é especificado como um parâmetro no modelo de classe juntamente com a função de comparação e o alocador.

A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Os contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que oferecem suporte explicitamente a essas operações são eficientes, executando-as em um tempo que está na média proporcional para o logaritmo do número de elementos no contêiner. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.

O conjunto deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo. Os elementos de um conjunto são exclusivos e servem como suas próprias chaves de classificação. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras, por exemplo, na qual as palavras podem ocorrer apenas uma vez. Se não foram permitidas as várias ocorrências das palavras, um multiset seria a estrutura de contêiner apropriada. Se for preciso anexar valores a uma lista de palavras-chave exclusivas, um mapa será uma estrutura apropriada para conter esses dados. Se, em vez disso, as chaves não forem exclusivas, um multimapa será o contêiner ideal.

O set ordena a sequência que controla chamando um objeto de função armazenado do tipo [key_compare](#key_compare). Esse objeto armazenado é uma função de comparação que pode ser acessada chamando a função membro [key_comp](#key_comp). De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem, de modo que, considerando dois elementos quaisquer, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário *f*( *x,y*) é um objeto de função que tem dois objetos de argumento *x* e *y* e um valor retornado de **true** ou **false**. Uma ordenação imposta em um conjunto será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo e se a equivalência for transitiva, em que dois objetos *x* e *y* são definidos para serem equivalentes quando ambos *f*( *x,y*) e *f*( *y,x*) são falsos. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

O iterador fornecido pela classe set é um iterador bidirecional, mas as funções membro de classe [insert](#insert) e [set](#set) têm versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que aqueles assegurados pela classe de iteradores bidirecionais. Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador. Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência. Esse é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores [ `First`, `Last`) no contexto de funções membro da classe.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[set](#set)|Constrói um conjunto que está vazio ou que é uma cópia de todo ou parte de algum outro conjunto.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para o objeto de conjunto.|
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no set.|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento **const** em um set.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência para um elemento **const** armazenado numa lista para leitura e execução de operações **const**.|
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no set.|
|[difference_type](#difference_type)|Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um conjunto em um intervalo entre os elementos apontado pelos iteradores.|
|[iterator](#iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar qualquer elemento em um conjunto.|
|[key_compare](#key_compare)|Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no conjunto.|
|[key_type](#key_type)|O tipo descreve um objeto armazenado como um elemento de um conjunto em sua capacidade como chave de classificação.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento em um conjunto.|
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em um conjunto.|
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um conjunto invertido.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um conjunto.|
|[value_compare](#value_compare)|O tipo que fornece um objeto de função que pode comparar dois elementos para determinar sua ordem relativa no conjunto.|
|[value_type](#value_type)|O tipo descreve um objeto armazenado como um elemento de um conjunto em sua capacidade como um valor.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[begin](#begin)|Retorna um iterador que trata o primeiro elemento no conjunto.|
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento no conjunto.|
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em um conjunto.|
|[clear](#clear)|Apaga todos os elementos de um conjunto.|
|[count](#count)|Retorna o número de elementos em um conjunto cuja chave corresponde a uma chave especificada pelo parâmetro.|
|[crbegin](#rbegin)|Retorna um iterador const que trata o primeiro elemento em um conjunto invertido.|
|[crend](#rend)|Retorna um iterador const que trata o local após o último elemento em um conjunto invertido.|
|[emplace](#emplace)|Insere um elemento construído adequadamente em um conjunto.|
|[emplace_hint](#emplace_hint)|Insere um elemento construído adequadamente em um conjunto, com uma dica de posicionamento.|
|[empty](#empty)|Testa se um conjunto está vazio.|
|[end](#end)|Retorna um iterador que trata o local após o último elemento em um conjunto.|
|[equal_range](#equal_range)|Retorna um par de iteradores respectivamente para o primeiro elemento em um conjunto com uma chave que é maior do que uma chave especificada e para o primeiro elemento no conjunto com uma chave igual ou maior que a chave.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um conjunto das posições especificadas ou remove elementos que correspondem a uma chave especificada.|
|[find](#find)|Retorna um iterador que trata o local de um elemento em um conjunto que tem uma chave equivalente a uma chave especificada.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` usada para construir o conjunto.|
|[insert](#insert)|Insere um elemento ou um intervalo de elementos em um conjunto.|
|[key_comp](#key_comp)|Recupera uma cópia do objeto de comparação usada para ordenar chaves em um conjunto.|
|[lower_bound](#lower_bound)|Retorna um iterador para o primeiro elemento em um conjunto com uma chave que é igual ou maior que uma chave especificada.|
|[max_size](#max_size)|Retorna o comprimento máximo do conjunto.|
|[rbegin](#rbegin)|Retorna um iterador que trata o primeiro elemento em um conjunto invertido.|
|[rend](#rend)|Retorna um iterador que trata o local após o último elemento em um conjunto invertido.|
|[size](#size)|Retorna o número de elementos no conjunto.|
|[swap](#swap)|Troca os elementos de dois conjuntos.|
|[upper_bound](#upper_bound)|Retorna um iterador para o primeiro elemento em um conjunto com uma chave que é maior que uma chave especificada.|
|[value_comp](#value_comp)|Recupera uma cópia do objeto de comparação usada para ordenar valores de elemento em um conjunto.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Substitui os elementos de um conjunto por uma cópia de outro conjunto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<set>

**Namespace:** std

## <a name="allocator_type"></a> set::allocator_type

Um tipo que representa a classe allocator do objeto set.

```cpp
typedef Allocator allocator_type;
```

### <a name="remarks"></a>Comentários

`allocator_type` é um sinônimo do parâmetro de modelo [alocador](../standard-library/set-class.md).

Retorna o objeto de função que um multiset usa para ordenar seus elementos, que é o parâmetro de modelo `Allocator`.

Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe set](../standard-library/set-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [get_allocator](#get_allocator) para obter um exemplo que usa `allocator_type`.

## <a name="begin"></a> set::begin

Retorna um iterador que trata o primeiro elemento no conjunto.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata o primeiro elemento no set ou o local após um set vazio.

### <a name="remarks"></a>Comentários

Se o valor de retorno `begin` for atribuído a um `const_iterator`, os elementos no objeto set não podem ser modificados. Se o valor de retorno `begin` for atribuído a um `iterator`, os elementos no objeto de conjunto podem ser modificados.

### <a name="example"></a>Exemplo

```cpp
// set_begin.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int>::iterator s1_Iter;
   set <int>::const_iterator s1_cIter;

   s1.insert( 1 );
   s1.insert( 2 );
   s1.insert( 3 );

   s1_Iter = s1.begin( );
   cout << "The first element of s1 is " << *s1_Iter << endl;

   s1_Iter = s1.begin( );
   s1.erase( s1_Iter );

   // The following 2 lines would err because the iterator is const
   // s1_cIter = s1.begin( );
   // s1.erase( s1_cIter );

   s1_cIter = s1.begin( );
   cout << "The first element of s1 is now " << *s1_cIter << endl;
}
```

```Output
The first element of s1 is 1
The first element of s1 is now 2
```

## <a name="cbegin"></a> set::cbegin

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

## <a name="cend"></a> set::cend

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

## <a name="clear"></a> set::clear

Apaga todos os elementos de um conjunto.

```cpp
void clear();
```

### <a name="example"></a>Exemplo

```cpp
// set_clear.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;

   s1.insert( 1 );
   s1.insert( 2 );

   cout << "The size of the set is initially " << s1.size( )
        << "." << endl;

   s1.clear( );
   cout << "The size of the set after clearing is "
        << s1.size( ) << "." << endl;
}
```

```Output
The size of the set is initially 2.
The size of the set after clearing is 0.
```

## <a name="const_iterator"></a> set::const_iterator

Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no set.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Veja o exemplo de [begin](#begin) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a> set::const_pointer

Um tipo que fornece um ponteiro para um elemento **const** em um set.

```cpp
typedef typename allocator_type::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [const_iterator](#const_iterator) deve ser usado para acessar os elementos em um objeto set const.

## <a name="const_reference"></a> set::const_reference

Um tipo que fornece uma referência para um elemento **const** armazenado numa lista para leitura e execução de operações **const**.

```cpp
typedef typename allocator_type::const_reference const_reference;
```

### <a name="example"></a>Exemplo

```cpp
// set_const_ref.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;

   s1.insert( 10 );
   s1.insert( 20 );

   // Declare and initialize a const_reference &Ref1
   // to the 1st element
   const int &Ref1 = *s1.begin( );

   cout << "The first element in the set is "
        << Ref1 << "." << endl;

   // The following line would cause an error because the
   // const_reference cannot be used to modify the set
   // Ref1 = Ref1 + 5;
}
```

```Output
The first element in the set is 10.
```

## <a name="const_reverse_iterator"></a> set::const_reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no set.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar pelo set em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rend](#rend) para obter um exemplo de como declarar e usar o `const_reverse_iterator`.

## <a name="count"></a> set::count

Retorna o número de elementos em um conjunto cuja chave corresponde a uma chave especificada pelo parâmetro.

```cpp
size_type count(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave dos elementos do set a serem correspondidos.

### <a name="return-value"></a>Valor de retorno

1 se o set contém um elemento cuja chave de classificação corresponde à chave de parâmetro. 0 se o set não contiver um elemento com uma chave correspondente.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos no seguinte intervalo:

\[ lower_bound (*chave*), upper_bound (*chave*)).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro set::count.

```cpp
// set_count.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main()
{
    using namespace std;
    set<int> s1;
    set<int>::size_type i;

    s1.insert(1);
    s1.insert(1);

    // Keys must be unique in set, so duplicates are ignored
    i = s1.count(1);
    cout << "The number of elements in s1 with a sort key of 1 is: "
         << i << "." << endl;

    i = s1.count(2);
    cout << "The number of elements in s1 with a sort key of 2 is: "
         << i << "." << endl;
}
```

```Output
The number of elements in s1 with a sort key of 1 is: 1.
The number of elements in s1 with a sort key of 2 is: 0.
```

## <a name="crbegin"></a>  set::crbegin

Retorna um iterador const que trata o primeiro elemento em um conjunto invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido const que trata do primeiro elemento em um set invertido ou que trata do que foi o último elemento do set não invertido.

### <a name="remarks"></a>Comentários

`crbegin` é usado com um set invertido, assim como [begin](#begin) é usado com um set.

Com o valor retornado `crbegin`, o objeto set não pode ser modificado.

### <a name="example"></a>Exemplo

```cpp
// set_crbegin.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int>::const_reverse_iterator s1_crIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   s1_crIter = s1.crbegin( );
   cout << "The first element in the reversed set is "
        << *s1_crIter << "." << endl;
}
```

```Output
The first element in the reversed set is 30.
```

## <a name="crend"></a>  set::crend

Retorna um iterador const que trata o local após o último elemento em um conjunto invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador const bidirecional inverso que aborda a localização que vem após o último elemento em um set invertido (o local que precedeu o primeiro elemento no set não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um set invertido, assim como [end](#end) é usado com um set.

Com o valor retornado `crend`, o objeto set não pode ser modificado. O valor retornado por `crend` não deve ser desreferenciado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de seu set.

### <a name="example"></a>Exemplo

```cpp
// set_crend.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main() {
   using namespace std;
   set <int> s1;
   set <int>::const_reverse_iterator s1_crIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   s1_crIter = s1.crend( );
   s1_crIter--;
   cout << "The last element in the reversed set is "
        << *s1_crIter << "." << endl;
}
```

## <a name="difference_type"></a>  set::difference_type

Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um conjunto em um intervalo entre os elementos apontado pelos iteradores.

```cpp
typedef typename allocator_type::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

`difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` é geralmente usado para representar o número de elementos no intervalo *[ first, last)* entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte pelos contêineres reversíveis, como conjunto, a subtração entre iteradores só tem suporte pelos iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como vetor.

### <a name="example"></a>Exemplo

```cpp
// set_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <set>
#include <algorithm>

int main( )
{
   using namespace std;

   set <int> s1;
   set <int>::iterator s1_Iter, s1_bIter, s1_eIter;

   s1.insert( 20 );
   s1.insert( 10 );
   s1.insert( 20 );   // won't insert as set elements are unique

   s1_bIter = s1.begin( );
   s1_eIter = s1.end( );

   set <int>::difference_type   df_typ5, df_typ10, df_typ20;

   df_typ5 = count( s1_bIter, s1_eIter, 5 );
   df_typ10 = count( s1_bIter, s1_eIter, 10 );
   df_typ20 = count( s1_bIter, s1_eIter, 20 );

   // the keys, and hence the elements of a set are unique,
   // so there is at most one of a given value
   cout << "The number '5' occurs " << df_typ5
        << " times in set s1.\n";
   cout << "The number '10' occurs " << df_typ10
        << " times in set s1.\n";
   cout << "The number '20' occurs " << df_typ20
        << " times in set s1.\n";

   // count the number of elements in a set
   set <int>::difference_type  df_count = 0;
   s1_Iter = s1.begin( );
   while ( s1_Iter != s1_eIter)
   {
      df_count++;
      s1_Iter++;
   }

   cout << "The number of elements in the set s1 is: "
        << df_count << "." << endl;
}
```

```Output
The number '5' occurs 0 times in set s1.
The number '10' occurs 1 times in set s1.
The number '20' occurs 1 times in set s1.
The number of elements in the set s1 is: 2.
```

## <a name="emplace"></a>  set::emplace

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada).

```cpp
template <class... Args>
pair<iterator, bool>
emplace(
    Args&&... args);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*args*|Os argumentos encaminhados para construir um elemento a ser inserido no set, a menos que ele já contenha um elemento cujo valor seja ordenado de maneira equivalente.|

### <a name="return-value"></a>Valor de retorno

Um [par](../standard-library/pair-structure.md) cujo componente bool retornará true se uma inserção tiver sido feita e false se o map já contiver um elemento cujo valor tinha um valor equivalente na ordenação. O componente de iterador do par de valores retornado retorna o endereço em que um novo elemento foi inserido (se o componente bool é true) ou em que o elemento já estava localizado (se o componente bool é false).

### <a name="remarks"></a>Comentários

Nenhum iterador ou referência será invalidada por essa função.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

### <a name="example"></a>Exemplo

```cpp
// set_emplace.cpp
// compile with: /EHsc
#include <set>
#include <string>
#include <iostream>

using namespace std;

template <typename S> void print(const S& s) {
    cout << s.size() << " elements: ";

    for (const auto& p : s) {
        cout << "(" << p << ") ";
    }

    cout << endl;
}

int main()
{
    set<string> s1;

    auto ret = s1.emplace("ten");

    if (!ret.second){
        cout << "Emplace failed, element with value \"ten\" already exists."
            << endl << "  The existing element is (" << *ret.first << ")"
            << endl;
        cout << "set not modified" << endl;
    }
    else{
        cout << "set modified, now contains ";
        print(s1);
    }
    cout << endl;

    ret = s1.emplace("ten");

    if (!ret.second){
        cout << "Emplace failed, element with value \"ten\" already exists."
            << endl << "  The existing element is (" << *ret.first << ")"
            << endl;
    }
    else{
        cout << "set modified, now contains ";
        print(s1);
    }
    cout << endl;
}
```

## <a name="emplace_hint"></a>  set::emplace_hint

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
|*args*|Os argumentos encaminhados para construir um elemento a ser inserido no set, a menos que o set já contenha esse elemento ou, de modo geral, que ele já contenha um elemento cujo valor seja ordenada de maneira equivalente.|
|*where*|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto preceder imediatamente *onde*, inserção poderá ocorrer em tempo constante amortizado, em vez de no tempo logarítmico.)|

### <a name="return-value"></a>Valor de retorno

Um iterador para o elemento recém-inserido.

Se a inserção tiver falhado porque o elemento já existe, ele retornará um iterador para o elemento existente.

### <a name="remarks"></a>Comentários

Nenhum iterador ou referência será invalidada por essa função.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

### <a name="example"></a>Exemplo

```cpp
// set_emplace.cpp
// compile with: /EHsc
#include <set>
#include <string>
#include <iostream>

using namespace std;

template <typename S> void print(const S& s) {
    cout << s.size() << " elements: " << endl;

    for (const auto& p : s) {
        cout << "(" << p <<  ") ";
    }

    cout << endl;
}

int main()
{
    set<string> s1;

    // Emplace some test data
    s1.emplace("Anna");
    s1.emplace("Bob");
    s1.emplace("Carmine");

    cout << "set starting data: ";
    print(s1);
    cout << endl;

    // Emplace with hint
    // s1.end() should be the "next" element after this emplacement
    s1.emplace_hint(s1.end(), "Doug");

    cout << "set modified, now contains ";
    print(s1);
    cout << endl;
}
```

## <a name="empty"></a>  set::empty

Testa se um conjunto está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o set estiver vazio; **false** se o set não estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// set_empty.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1, s2;
   s1.insert ( 1 );

   if ( s1.empty( ) )
      cout << "The set s1 is empty." << endl;
   else
      cout << "The set s1 is not empty." << endl;

   if ( s2.empty( ) )
      cout << "The set s2 is empty." << endl;
   else
      cout << "The set s2 is not empty." << endl;
}
```

```Output
The set s1 is not empty.
The set s2 is empty.
```

## <a name="end"></a>  set::end

Retorna o iterador que ultrapassa o fim.

```cpp
const_iterator end() const;

iterator end();
```

### <a name="return-value"></a>Valor de retorno

O iterador que ultrapassa o fim. Se o conjunto estiver vazio, então, `set::end() == set::begin()`.

### <a name="remarks"></a>Comentários

**end** é usado para testar se um iterador ultrapassou o fim de seu set.

O valor retornado por **end** não deve ser desreferenciado.

Para obter um exemplo de código, consulte [set::find](#find).

## <a name="equal_range"></a>  set::equal_range

Retorna um par de iteradores respectivamente para o primeiro elemento em um set com uma chave que é maior ou igual a uma chave especificada e para o primeiro elemento no set com uma chave maior que essa mesma chave especificada.

```cpp
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave do argumento a ser comparada com a chave de classificação de um elemento do set que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um par de iteradores em que o primeiro é o [lower_bound](#lower_bound) e o segundo é o [upper_bound](#upper_bound) da chave.

Para acessar o primeiro iterador de um par `pr` retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).

### <a name="example"></a>Exemplo

```cpp
// set_equal_range.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   typedef set<int, less< int > > IntSet;
   IntSet s1;
   set <int, less< int > > :: const_iterator s1_RcIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   pair <IntSet::const_iterator, IntSet::const_iterator> p1, p2;
   p1 = s1.equal_range( 20 );

   cout << "The upper bound of the element with "
        << "a key of 20 in the set s1 is: "
        << *(p1.second) << "." << endl;

   cout << "The lower bound of the element with "
        << "a key of 20 in the set s1 is: "
        << *(p1.first) << "." << endl;

   // Compare the upper_bound called directly
   s1_RcIter = s1.upper_bound( 20 );
   cout << "A direct call of upper_bound( 20 ) gives "
        << *s1_RcIter << "," << endl
        << "matching the 2nd element of the pair"
        << " returned by equal_range( 20 )." << endl;

   p2 = s1.equal_range( 40 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == s1.end( ) ) && ( p2.second == s1.end( ) ) )
      cout << "The set s1 doesn't have an element "
           << "with a key less than 40." << endl;
   else
      cout << "The element of set s1 with a key >= 40 is: "
           << *(p1.first) << "." << endl;
}
```

```Output
The upper bound of the element with a key of 20 in the set s1 is: 30.
The lower bound of the element with a key of 20 in the set s1 is: 20.
A direct call of upper_bound( 20 ) gives 30,
matching the 2nd element of the pair returned by equal_range( 20 ).
The set s1 doesn't have an element with a key less than 40.
```

## <a name="erase"></a>  set::erase

Remove um elemento ou um intervalo de elementos em um conjunto das posições especificadas ou remove elementos que correspondem a uma chave especificada.

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
O valor de chave dos elementos a serem removidos.

### <a name="return-value"></a>Valor de retorno

Para as duas primeiras funções membro, é um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou, se esse elemento não existe, é um elemento que é o final do set.

Para a terceira função membro, ele retorna o número de elementos que foram removidos do set.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

```cpp
// set_erase.cpp
// compile with: /EHsc
#include <set>
#include <string>
#include <iostream>
#include <iterator> // next() and prev() helper functions

using namespace std;

using myset = set<string>;

void printset(const myset& s) {
    for (const auto& iter : s) {
        cout << " [" << iter << "]";
    }
    cout << endl << "size() == " << s.size() << endl << endl;
}

int main()
{
    myset s1;

    // Fill in some data to test with, one at a time
    s1.insert("Bob");
    s1.insert("Robert");
    s1.insert("Bert");
    s1.insert("Rob");
    s1.insert("Bobby");

    cout << "Starting data of set s1 is:" << endl;
    printset(s1);
    // The 1st member function removes an element at a given position
    s1.erase(next(s1.begin()));
    cout << "After the 2nd element is deleted, the set s1 is:" << endl;
    printset(s1);

    // Fill in some data to test with, one at a time, using an initializer list
    myset s2{ "meow", "hiss", "purr", "growl", "yowl" };

    cout << "Starting data of set s2 is:" << endl;
    printset(s2);
    // The 2nd member function removes elements
    // in the range [First, Last)
    s2.erase(next(s2.begin()), prev(s2.end()));
    cout << "After the middle elements are deleted, the set s2 is:" << endl;
    printset(s2);

    myset s3;

    // Fill in some data to test with, one at a time, using emplace
    s3.emplace("C");
    s3.emplace("C#");
    s3.emplace("D");
    s3.emplace("D#");
    s3.emplace("E");
    s3.emplace("E#");
    s3.emplace("F");
    s3.emplace("F#");
    s3.emplace("G");
    s3.emplace("G#");
    s3.emplace("A");
    s3.emplace("A#");
    s3.emplace("B");

    cout << "Starting data of set s3 is:" << endl;
    printset(s3);
    // The 3rd member function removes elements with a given Key
    myset::size_type count = s3.erase("E#");
    // The 3rd member function also returns the number of elements removed
    cout << "The number of elements removed from s3 is: " << count << "." << endl;
    cout << "After the element with a key of \"E#\" is deleted, the set s3 is:" << endl;
    printset(s3);
}
```

## <a name="find"></a>  set::find

Retorna um iterador que aponta para o local de um elemento em um conjunto que tem uma chave igual a uma chave especificada.

```cpp
iterator find(const Key& key);

const_iterator find(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
O valor da chave a ser comparado pela chave de classificação de um elemento do conjunto que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador que se refere ao local de um elemento com uma chave especificada ou o local que substitui o último elemento no conjunto (`set::end()`) se nenhuma correspondência for encontrada para a chave.

### <a name="remarks"></a>Comentários

A função membro retorna um iterador que se refere a um elemento no conjunto cuja chave é equivalente ao argumento *chave* em um predicado binário que induz uma ordenação com base em uma relação de comparação menor.

Se o valor de retorno `find` for atribuído a um `const_iterator`, o objeto set não pode ser modificado. Se o valor de retorno `find` for atribuído a um `iterator`, o objeto de conjunto pode ser modificado

### <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4 /MTd
#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T> void print_elem(const T& t) {
    cout << "(" << t << ") ";
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
    set<int> s1({ 40, 45 });
    cout << "The starting set s1 is: " << endl;
    print_collection(s1);

    vector<int> v;
    v.push_back(43);
    v.push_back(41);
    v.push_back(46);
    v.push_back(42);
    v.push_back(44);
    v.push_back(44); // attempt a duplicate

    cout << "Inserting the following vector data into s1: " << endl;
    print_collection(v);

    s1.insert(v.begin(), v.end());

    cout << "The modified set s1 is: " << endl;
    print_collection(s1);
    cout << endl;
    findit(s1, 45);
    findit(s1, 6);
}
```

## <a name="get_allocator"></a>  set::get_allocator

Retorna uma cópia do objeto alocador usado para construir o set.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

O alocador usado pelo set para gerenciar a memória, que é o parâmetro de modelo `Allocator`.

Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe set](../standard-library/set-class.md).

### <a name="remarks"></a>Comentários

Alocadores para a classe set especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da biblioteca padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>Exemplo

```cpp
// set_get_allocator.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int>::allocator_type s1_Alloc;
   set <int>::allocator_type s2_Alloc;
   set <double>::allocator_type s3_Alloc;
   set <int>::allocator_type s4_Alloc;

   // The following lines declare objects
   // that use the default allocator.
   set <int> s1;
   set <int, allocator<int> > s2;
   set <double, allocator<double> > s3;

   s1_Alloc = s1.get_allocator( );
   s2_Alloc = s2.get_allocator( );
   s3_Alloc = s3.get_allocator( );

   cout << "The number of integers that can be allocated"
        << endl << "before free memory is exhausted: "
        << s2.max_size( ) << "." << endl;

   cout << "\nThe number of doubles that can be allocated"
        << endl << "before free memory is exhausted: "
        << s3.max_size( ) <<  "." << endl;

   // The following line creates a set s4
   // with the allocator of multiset s1.
   set <int> s4( less<int>( ), s1_Alloc );

   s4_Alloc = s4.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated by the other
   if( s1_Alloc == s4_Alloc )
   {
      cout << "\nThe allocators are interchangeable."
           << endl;
   }
   else
   {
      cout << "\nThe allocators are not interchangeable."
           << endl;
   }
}
```

## <a name="insert"></a>  set::insert

Insere um elemento ou um intervalo de elementos em um conjunto.

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
|*Val*|O valor de um elemento a ser inserido no conjunto, a menos que ele já contenha um elemento cujo valor seja ordenado de modo equivalente.|
|*Where*|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto preceder imediatamente *onde*, inserção poderá ocorrer em tempo constante amortizado, em vez de no tempo logarítmico.)|
|*ValTy*|Parâmetro de modelo que especifica o tipo de argumento que o conjunto pode usar para construir um elemento de [value_type](../standard-library/map-class.md#value_type)e perfect-forwards *Val* como um argumento.|
|*Primeiro*|A posição do primeiro elemento a ser copiado.|
|*último*|A posição imediatamente após o último elemento a ser copiado.|
|*InputIterator*|Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](../standard-library/map-class.md#value_type).|
|*IList*|O [initializer_list](../standard-library/initializer-list.md) do qual os elementos serão copiados.|

### <a name="return-value"></a>Valor de retorno

As funções de membro de elemento único, (1) e (2), retornam um [par](../standard-library/pair-structure.md) cuja **bool** componente é verdadeiro se uma inserção tiver sido feita e FALSO se o conjunto já contiver um elemento de valor equivalente no ordenação. O componente do iterador do par de valor de retorno aponta para o elemento recém-inserido, se o **bool** componente é verdadeiro, ou para o elemento existente se o **bool** componente é false.

As funções do membro de elemento único com dica, (3) e (4), retornam um iterador que aponta para a posição em que o novo elemento foi inserido no conjunto ou, se um elemento com chave equivalente já existir, para o elemento existente.

### <a name="remarks"></a>Comentários

Nenhum iterador, ponteiro ou referência é invalidado por essa função.

Durante a inserção de apenas um elemento, se uma exceção for lançada, o estado do contêiner não será modificado. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.

Para acessar o componente do iterador de um `pair` `pr` que é retornado pelas funções do membro de elemento único, consulte `pr.first`; para desreferenciar o iterador dentro do par retornado, use `*pr.first`, que oferece um elemento. Para acessar o **bool** componente, use `pr.second`. Para obter um exemplo, consulte o código de amostra mais adiante neste artigo.

O [value_type](../standard-library/map-class.md#value_type) de um contêiner é um typedef que pertence ao contêiner e, para o conjunto, `set<V>::value_type` é do tipo `const V`.

A função do membro do intervalo (5) insere a sequência de valores de elemento em um conjunto que corresponde a cada elemento abordado por um iterador no intervalo `[First, Last)`; portanto, `Last` não é inserido. A função de membro do contêiner `end()` faz referência à posição imediatamente após o último elemento no contêiner; por exemplo, a instrução `s.insert(v.begin(), v.end());` tenta inserir todos os elementos de `v` em `s`. Apenas elementos com valores únicos no intervalo são inseridos; as duplicatas são ignoradas. Para observar quais elementos são rejeitados, use as versões de elemento único de `insert`.

A função membro da lista do inicializador (6) usa uma [initializer_list](../standard-library/initializer-list.md) para copiar elementos no conjunto.

Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [set::emplace](#emplace) e [set::emplace_hint](#emplace_hint).

### <a name="example"></a>Exemplo

```cpp
// set_insert.cpp
// compile with: /EHsc
#include <set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename S> void print(const S& s) {
    cout << s.size() << " elements: ";

    for (const auto& p : s) {
        cout << "(" << p << ") ";
    }

    cout << endl;
}

int main()
{

    // insert single values
    set<int> s1;
    // call insert(const value_type&) version
    s1.insert({ 1, 10 });
    // call insert(ValTy&&) version
    s1.insert(20);

    cout << "The original set values of s1 are:" << endl;
    print(s1);

    // intentionally attempt a duplicate, single element
    auto ret = s1.insert(1);
    if (!ret.second){
        auto elem = *ret.first;
        cout << "Insert failed, element with value 1 already exists."
            << endl << "  The existing element is (" << elem << ")"
            << endl;
    }
    else{
        cout << "The modified set values of s1 are:" << endl;
        print(s1);
    }
    cout << endl;

    // single element, with hint
    s1.insert(s1.end(), 30);
    cout << "The modified set values of s1 are:" << endl;
    print(s1);
    cout << endl;

    // The templatized version inserting a jumbled range
    set<int> s2;
    vector<int> v;
    v.push_back(43);
    v.push_back(294);
    v.push_back(41);
    v.push_back(330);
    v.push_back(42);
    v.push_back(45);

    cout << "Inserting the following vector data into s2:" << endl;
    print(v);

    s2.insert(v.begin(), v.end());

    cout << "The modified set values of s2 are:" << endl;
    print(s2);
    cout << endl;

    // The templatized versions move-constructing elements
    set<string>  s3;
    string str1("blue"), str2("green");

    // single element
    s3.insert(move(str1));
    cout << "After the first move insertion, s3 contains:" << endl;
    print(s3);

    // single element with hint
    s3.insert(s3.end(), move(str2));
    cout << "After the second move insertion, s3 contains:" << endl;
    print(s3);
    cout << endl;

    set<int> s4;
    // Insert the elements from an initializer_list
    s4.insert({ 4, 44, 2, 22, 3, 33, 1, 11, 5, 55 });
    cout << "After initializer_list insertion, s4 contains:" << endl;
    print(s4);
    cout << endl;
}
```

## <a name="iterator"></a>  set::iterator

Um tipo que fornece um [iterador bidirecional](../standard-library/bidirectional-iterator-tag-struct.md) constante que pode ler qualquer elemento em um set.

```cpp
typedef implementation-defined iterator;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [começar](#begin) para obter um exemplo de como declarar e usar um `iterator`.

## <a name="key_comp"></a>  set::key_comp

Recupera uma cópia do objeto de comparação usada para ordenar chaves em um conjunto.

```cpp
key_compare key_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto de função que um set usa para ordenar seus elementos, que é o parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe set](../standard-library/set-class.md).

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro:

**bool operator()**( **const Key&**`_xVal`, **const Key&**`_yVal`);

que retornará **true** se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.

Observe que [key_compare](#key_compare) e [value_compare](#value_compare) são sinônimos do parâmetro de modelo `Traits`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// set_key_comp.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;

   set <int, less<int> > s1;
   set<int, less<int> >::key_compare kc1 = s1.key_comp( ) ;
   bool result1 = kc1( 2, 3 ) ;
   if( result1 == true )
   {
      cout << "kc1( 2,3 ) returns value of true, "
           << "where kc1 is the function object of s1."
           << endl;
   }
   else
   {
      cout << "kc1( 2,3 ) returns value of false "
           << "where kc1 is the function object of s1."
           << endl;
   }

   set <int, greater<int> > s2;
   set<int, greater<int> >::key_compare kc2 = s2.key_comp( ) ;
   bool result2 = kc2( 2, 3 ) ;
   if(result2 == true)
   {
      cout << "kc2( 2,3 ) returns value of true, "
           << "where kc2 is the function object of s2."
           << endl;
   }
   else
   {
      cout << "kc2( 2,3 ) returns value of false, "
           << "where kc2 is the function object of s2."
           << endl;
   }
}
```

```Output
kc1( 2,3 ) returns value of true, where kc1 is the function object of s1.
kc2( 2,3 ) returns value of false, where kc2 is the function object of s2.
```

## <a name="key_compare"></a>  set::key_compare

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no conjunto.

```cpp
typedef Traits key_compare;
```

### <a name="remarks"></a>Comentários

`key_compare` é um sinônimo do parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe set](../standard-library/set-class.md).

Observe que ambos `key_compare` e [value_compare](#value_compare) são sinônimos do parâmetro de modelo `Traits`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

Veja o exemplo de [key_comp](#key_comp) que demonstra como declarar e usar `key_compare`.

## <a name="key_type"></a>  set::key_type

Um tipo que descreve um objeto armazenado como um elemento de um set em sua capacidade como chave de classificação.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

`key_type` é um sinônimo do parâmetro de modelo `Key`.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe set](../standard-library/set-class.md).

Observe que ambos `key_type` e [value_type](#value_type) são sinônimos do parâmetro de modelo `Key`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="lower_bound"></a>  set::lower_bound

Retorna um iterador para o primeiro elemento em um conjunto com uma chave que é igual ou maior que uma chave especificada.

```cpp
const_iterator lower_bound(const Key& key) const;

iterator lower_bound(const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave do argumento a ser comparada com a chave de classificação de um elemento do set que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador ou `const_iterator` que tratará a localização de um elemento em um set com uma chave, que é igual ou maior que a chave de argumento ou que tratará o local após o último elemento no set se nenhuma correspondência for encontrada para a chave.

### <a name="example"></a>Exemplo

```cpp
// set_lower_bound.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int> :: const_iterator s1_AcIter, s1_RcIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   s1_RcIter = s1.lower_bound( 20 );
   cout << "The element of set s1 with a key of 20 is: "
        << *s1_RcIter << "." << endl;

   s1_RcIter = s1.lower_bound( 40 );

   // If no match is found for the key, end( ) is returned
   if ( s1_RcIter == s1.end( ) )
      cout << "The set s1 doesn't have an element "
           << "with a key of 40." << endl;
   else
      cout << "The element of set s1 with a key of 40 is: "
           << *s1_RcIter << "." << endl;

   // The element at a specific location in the set can be found
   // by using a dereferenced iterator that addresses the location
   s1_AcIter = s1.end( );
   s1_AcIter--;
   s1_RcIter = s1.lower_bound( *s1_AcIter );
   cout << "The element of s1 with a key matching "
        << "that of the last element is: "
        << *s1_RcIter << "." << endl;
}
```

```Output
The element of set s1 with a key of 20 is: 20.
The set s1 doesn't have an element with a key of 40.
The element of s1 with a key matching that of the last element is: 30.
```

## <a name="max_size"></a>  set::max_size

Retorna o comprimento máximo do conjunto.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento máximo possível do set.

### <a name="example"></a>Exemplo

```cpp
// set_max_size.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int>::size_type i;

   i = s1.max_size( );
   cout << "The maximum possible length "
        << "of the set is " << i << "." << endl;
}
```

## <a name="op_eq"></a>  set::operator=

Substitui os elementos desse `set` usando os elementos de outro `set`.

```cpp
set& operator=(const set& right);

set& operator=(set&& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*right*|O `set` fornecendo novos elementos para serem atribuídos a este `set`.|

### <a name="remarks"></a>Comentários

A primeira versão do `operator=` usa um [referência de lvalue](../cpp/lvalue-reference-declarator-amp.md) para *direita*, para copiar elementos *direita* a este `set`.

A segunda versão usa uma [referência rvalue](../cpp/rvalue-reference-declarator-amp-amp.md) para _Right. Ela move elementos de *certa* a este `set`.

Quaisquer elementos neste `set` antes de a função de operador ser executada serão descartados.

### <a name="example"></a>Exemplo

```cpp
// set_operator_as.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
   {
   using namespace std;
   set<int> v1, v2, v3;
   set<int>::iterator iter;

   v1.insert(10);

   cout << "v1 = " ;
   for (iter = v1.begin(); iter != v1.end(); iter++)
      cout << *iter << " ";
   cout << endl;

   v2 = v1;
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;

// move v1 into v2
   v2.clear();
   v2 = move(v1);
   cout << "v2 = ";
   for (iter = v2.begin(); iter != v2.end(); iter++)
      cout << *iter << " ";
   cout << endl;
   }
```

## <a name="pointer"></a>  set::pointer

Um tipo que fornece um ponteiro para um elemento em um conjunto.

```cpp
typedef typename allocator_type::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo **pointer** pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto set.

## <a name="rbegin"></a>  set::rbegin

Retorna um iterador que trata o primeiro elemento em um conjunto invertido.

```cpp
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido que trata do primeiro elemento em um set invertido ou que trata do que foi o último elemento do set não invertido.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um set invertido, assim como [begin](#begin) é usado com um set.

Se o valor retornado de `rbegin` for atribuído a `const_reverse_iterator`, o objeto set não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto set poderá ser modificado.

`rbegin` pode ser usado para iterar por de uma lista para trás.

### <a name="example"></a>Exemplo

```cpp
// set_rbegin.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int>::iterator s1_Iter;
   set <int>::reverse_iterator s1_rIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   s1_rIter = s1.rbegin( );
   cout << "The first element in the reversed set is "
        << *s1_rIter << "." << endl;

   // begin can be used to start an iteration
   // through a set in a forward order
   cout << "The set is:";
   for ( s1_Iter = s1.begin( ) ; s1_Iter != s1.end( ); s1_Iter++ )
      cout << " " << *s1_Iter;
   cout << endl;

   // rbegin can be used to start an iteration
   // through a set in a reverse order
   cout << "The reversed set is:";
   for ( s1_rIter = s1.rbegin( ) ; s1_rIter != s1.rend( ); s1_rIter++ )
      cout << " " << *s1_rIter;
   cout << endl;

   // A set element can be erased by dereferencing to its key
   s1_rIter = s1.rbegin( );
   s1.erase ( *s1_rIter );

   s1_rIter = s1.rbegin( );
   cout << "After the erasure, the first element "
        << "in the reversed set is "<< *s1_rIter << "." << endl;
}
```

```Output
The first element in the reversed set is 30.
The set is: 10 20 30
The reversed set is: 30 20 10
After the erasure, the first element in the reversed set is 20.
```

## <a name="reference"></a>  set::reference

Um tipo que fornece uma referência a um elemento armazenado em um conjunto.

```cpp
typedef typename allocator_type::reference reference;
```

### <a name="example"></a>Exemplo

```cpp
// set_reference.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;

   s1.insert( 10 );
   s1.insert( 20 );

   // Declare and initialize a reference &Ref1 to the 1st element
   const int &Ref1 = *s1.begin( );

   cout << "The first element in the set is "
        << Ref1 << "." << endl;
}
```

```Output
The first element in the set is 10.
```

## <a name="rend"></a>  set::rend

Retorna um iterador que trata o local após o último elemento em um conjunto invertido.

```cpp
const_reverse_iterator rend() const;

reverse_iterator rend();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso que aborda a localização que vem após o último elemento em um set invertido (o local que precedeu o primeiro elemento no set não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um set invertido, assim como [end](#end) é usado com um set.

Se o valor retornado de `rend` for atribuído a `const_reverse_iterator`, o objeto set não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto set poderá ser modificado. O valor retornado por `rend` não deve ser desreferenciado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de seu set.

### <a name="example"></a>Exemplo

```cpp
// set_rend.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main() {
   using namespace std;
   set <int> s1;
   set <int>::iterator s1_Iter;
   set <int>::reverse_iterator s1_rIter;
   set <int>::const_reverse_iterator s1_crIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   s1_rIter = s1.rend( );
   s1_rIter--;
   cout << "The last element in the reversed set is "
        << *s1_rIter << "." << endl;

   // end can be used to terminate an iteration
   // through a set in a forward order
   cout << "The set is: ";
   for ( s1_Iter = s1.begin( ) ; s1_Iter != s1.end( ); s1_Iter++ )
      cout << *s1_Iter << " ";
   cout << "." << endl;

   // rend can be used to terminate an iteration
   // through a set in a reverse order
   cout << "The reversed set is: ";
   for ( s1_rIter = s1.rbegin( ) ; s1_rIter != s1.rend( ); s1_rIter++ )
      cout << *s1_rIter << " ";
   cout << "." << endl;

   s1_rIter = s1.rend( );
   s1_rIter--;
   s1.erase ( *s1_rIter );

   s1_rIter = s1.rend( );
   --s1_rIter;
   cout << "After the erasure, the last element in the "
        << "reversed set is " << *s1_rIter << "." << endl;
}
```

## <a name="reverse_iterator"></a>  set::reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um conjunto invertido.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `reverse_iterator` é usado para iterar pelo set em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.

## <a name="set"></a>  set::set

Constrói um conjunto que está vazio ou que é uma cópia de todo ou parte de algum outro conjunto.

```cpp
set();

explicit set(
    const Traits& Comp);

set(
    const Traits& Comp,
    const Allocator& Al);

set(
    const set& Right);

set(
    set&& Right);

set(
    initializer_list<Type> IList);

set(
    initializer_list<Type> IList,
    const Compare& Comp);

set(
    initializer_list<Type> IList,
    const Compare& Comp,
    const Allocator& Al);

template <class InputIterator>
set(
    InputIterator First,
    InputIterator Last);

template <class InputIterator>
set(
    InputIterator First,
    InputIterator Last,
    const Traits& Comp);

template <class InputIterator>
set(
    InputIterator First,
    InputIterator Last,
    const Traits& Comp,
    const Allocator& Al);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*Al*|A classe de alocador de armazenamento a ser usado neste objeto set, cujo padrão é `Allocator`.|
|*Comp*|A função de comparação do tipo `const Traits` usada para ordenar os elementos no set, cujo padrão é `Compare`.|
|*Rght*|O set do qual o conjunto criado é uma cópia.|
|*Primeiro*|A posição do primeiro elemento no intervalo de elementos a serem copiados.|
|*último*|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|
|*IList*|O initializer_list do qual copiar os elementos.|

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o set e que, posteriormente, pode ser retornado ao chamar [get_allocator](#get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.

Todos os construtores inicializam seu set.

Todos os construtores armazenam um objeto de função do tipo `Traits` que é usado para estabelecer uma ordem entre as chaves do set e que posteriormente pode ser retornado ao chamar [key_comp](#key_comp).

Os primeiros três construtores especificam um set inicial vazio, o segundo Especifica o tipo de função de comparação (`comp`) a ser usado para estabelecer a ordem dos elementos e o terceiro especifica explicitamente o alocador de tipo (`al`) para ser usado. A palavra-chave **explicit** suprime determinados tipos de conversão automática de tipo.

O quarto construtor especifica uma cópia do set `right`.

Os próximos três construtores usam initializer_list para especificar os elementos.

Os próximos três construtores copiam o intervalo [ `first`, `last`) de um conjunto com clareza especificando o tipo de função de comparação da classe crescente `Traits` e **alocador**.

O oitavo construtor especifica uma cópia do set ao mover o `right`.

### <a name="example"></a>Exemplo

```cpp
// set_set.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main()
{
    using namespace std;

    // Create an empty set s0 of key type integer
    set <int> s0;

    // Create an empty set s1 with the key comparison
    // function of less than, then insert 4 elements
    set <int, less<int> > s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    // Create an empty set s2 with the key comparison
    // function of less than, then insert 2 elements
    set <int, less<int> > s2;
    s2.insert(10);
    s2.insert(20);

    // Create a set s3 with the
    // allocator of set s1
    set <int>::allocator_type s1_Alloc;
    s1_Alloc = s1.get_allocator();
    set <int> s3(less<int>(), s1_Alloc);
    s3.insert(30);

    // Create a copy, set s4, of set s1
    set <int> s4(s1);

    // Create a set s5 by copying the range s1[ first,  last)
    set <int>::const_iterator s1_bcIter, s1_ecIter;
    s1_bcIter = s1.begin();
    s1_ecIter = s1.begin();
    s1_ecIter++;
    s1_ecIter++;
    set <int> s5(s1_bcIter, s1_ecIter);

    // Create a set s6 by copying the range s4[ first,  last)
    // and with the allocator of set s2
    set <int>::allocator_type s2_Alloc;
    s2_Alloc = s2.get_allocator();
    set <int> s6(s4.begin(), ++s4.begin(), less<int>(), s2_Alloc);

    cout << "s1 =";
    for (auto i : s1)
        cout << " " << i;
    cout << endl;

    cout << "s2 = " << *s2.begin() << " " << *++s2.begin() << endl;

    cout << "s3 =";
    for (auto i : s3)
        cout << " " << i;
    cout << endl;

    cout << "s4 =";
    for (auto i : s4)
        cout << " " << i;
    cout << endl;

    cout << "s5 =";
    for (auto i : s5)
        cout << " " << i;
    cout << endl;

    cout << "s6 =";
    for (auto i : s6)
        cout << " " << i;
    cout << endl;

    // Create a set by moving s5
    set<int> s7(move(s5));
    cout << "s7 =";
    for (auto i : s7)
        cout << " " << i;
    cout << endl;

    // Create a set with an initializer_list
    cout << "s8 =";
    set<int> s8{ { 1, 2, 3, 4 } };
    for (auto i : s8)
        cout << " " << i;
    cout << endl;

    cout << "s9 =";
    set<int> s9{ { 5, 6, 7, 8 }, less<int>() };
    for (auto i : s9)
        cout << " " << i;
    cout << endl;

    cout << "s10 =";
    set<int> s10{ { 10, 20, 30, 40 }, less<int>(), s9.get_allocator() };
    for (auto i : s10)
        cout << " " << i;
    cout << endl;
}
```

```Output
s1 = 10 20 30 40s2 = 10 20s3 = 30s4 = 10 20 30 40s5 = 10 20s6 = 10s7 = 10 20s8 = 1 2 3 4s9 = 5 6 7 8s10 = 10 20 30 40
```

## <a name="size"></a>  set::size

Retorna o número de elementos no conjunto.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento atual do set.

### <a name="example"></a>Exemplo

```cpp
// set_size.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int> :: size_type i;

   s1.insert( 1 );
   i = s1.size( );
   cout << "The set length is " << i << "." << endl;

   s1.insert( 2 );
   i = s1.size( );
   cout << "The set length is now " << i << "." << endl;
}
```

```Output
The set length is 1.
The set length is now 2.
```

## <a name="size_type"></a>  set::size_type

Um tipo de inteiro sem sinal que pode representar o número de elementos em um conjunto.

```cpp
typedef typename allocator_type::size_type size_type;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) que demonstra como declarar e usar `size_type`

## <a name="swap"></a>  set::swap

Troca os elementos de dois conjuntos.

```cpp
void swap(
    set<Key, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O set de argumentos que fornece os elementos a serem trocados com o set de destino.

### <a name="remarks"></a>Comentários

A função membro não invalida nenhuma referência, ponteiro ou iterador que designa elementos nos dois sets cujos elementos estão sendo trocados.

### <a name="example"></a>Exemplo

```cpp
// set_swap.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1, s2, s3;
   set <int>::iterator s1_Iter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );
   s2.insert( 100 );
   s2.insert( 200 );
   s3.insert( 300 );

   cout << "The original set s1 is:";
   for ( s1_Iter = s1.begin( ); s1_Iter != s1.end( ); s1_Iter++ )
      cout << " " << *s1_Iter;
   cout   << "." << endl;

   // This is the member function version of swap
   s1.swap( s2 );

   cout << "After swapping with s2, list s1 is:";
   for ( s1_Iter = s1.begin( ); s1_Iter != s1.end( ); s1_Iter++ )
      cout << " " << *s1_Iter;
   cout  << "." << endl;

   // This is the specialized template version of swap
   swap( s1, s3 );

   cout << "After swapping with s3, list s1 is:";
   for ( s1_Iter = s1.begin( ); s1_Iter != s1.end( ); s1_Iter++ )
      cout << " " << *s1_Iter;
   cout   << "." << endl;
}
```

```Output
The original set s1 is: 10 20 30.
After swapping with s2, list s1 is: 100 200.
After swapping with s3, list s1 is: 300.
```

## <a name="upper_bound"></a>  set::upper_bound

Retorna um iterador para o primeiro elemento em um set com uma chave que é maior que uma chave especificada.

```cpp
const_iterator upper_bound(const Key& key) const;

iterator upper_bound(const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave do argumento a ser comparada com a chave de classificação de um elemento do set que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Uma `iterator` ou `const_iterator` que tratará o local de um elemento em um conjunto com uma chave que é maior que a chave de argumento ou que trata do local que sucede o último elemento no conjunto, se nenhuma correspondência for encontrado para a chave.

### <a name="example"></a>Exemplo

```cpp
// set_upper_bound.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int> :: const_iterator s1_AcIter, s1_RcIter;

   s1.insert( 10 );
   s1.insert( 20 );
   s1.insert( 30 );

   s1_RcIter = s1.upper_bound( 20 );
   cout << "The first element of set s1 with a key greater "
        << "than 20 is: " << *s1_RcIter << "." << endl;

   s1_RcIter = s1.upper_bound( 30 );

   // If no match is found for the key, end( ) is returned
   if ( s1_RcIter == s1.end( ) )
      cout << "The set s1 doesn't have an element "
           << "with a key greater than 30." << endl;
   else
      cout << "The element of set s1 with a key > 40 is: "
           << *s1_RcIter << "." << endl;

   // The element at a specific location in the set can be found
   // by using a dereferenced iterator addressing the location
   s1_AcIter = s1.begin( );
   s1_RcIter = s1.upper_bound( *s1_AcIter );
   cout << "The first element of s1 with a key greater than"
        << endl << "that of the initial element of s1 is: "
        << *s1_RcIter << "." << endl;
}
```

```Output
The first element of set s1 with a key greater than 20 is: 30.
The set s1 doesn't have an element with a key greater than 30.
The first element of s1 with a key greater than
that of the initial element of s1 is: 20.
```

## <a name="value_comp"></a>  set::value_comp

Recupera uma cópia do objeto de comparação usada para ordenar valores de elemento em um conjunto.

```cpp
value_compare value_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto de função que um set usa para ordenar seus elementos, que é o parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe set](../standard-library/set-class.md).

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro:

**bool operator**( **const Key&**`_xVal`, **const Key&**`_yVal`);

que retornará **true** se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.

Observe que [value_compare](#value_compare) e [key_compare](#key_compare) são sinônimos do parâmetro de modelo `Traits`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// set_value_comp.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;

   set <int, less<int> > s1;
   set <int, less<int> >::value_compare vc1 = s1.value_comp( );
   bool result1 = vc1( 2, 3 );
   if( result1 == true )
   {
      cout << "vc1( 2,3 ) returns value of true, "
           << "where vc1 is the function object of s1."
           << endl;
   }
   else
   {
      cout << "vc1( 2,3 ) returns value of false, "
           << "where vc1 is the function object of s1."
           << endl;
   }

   set <int, greater<int> > s2;
   set<int, greater<int> >::value_compare vc2 = s2.value_comp( );
   bool result2 = vc2( 2, 3 );
   if( result2 == true )
   {
      cout << "vc2( 2,3 ) returns value of true, "
           << "where vc2 is the function object of s2."
           << endl;
   }
   else
   {
      cout << "vc2( 2,3 ) returns value of false, "
           << "where vc2 is the function object of s2."
           << endl;
   }
}
```

```Output
vc1( 2,3 ) returns value of true, where vc1 is the function object of s1.
vc2( 2,3 ) returns value of false, where vc2 is the function object of s2.
```

## <a name="value_compare"></a>  set::value_compare

Um tipo que fornece um objeto de função que pode comparar dois valores de elemento para determinar sua ordem relativa no conjunto.

```cpp
typedef key_compare value_compare;
```

### <a name="remarks"></a>Comentários

`value_compare` é um sinônimo do parâmetro de modelo `Traits`.

Para obter mais informações sobre `Traits`, consulte o tópico [Classe set](../standard-library/set-class.md).

Observe que ambos [key_compare](#key_compare) e `value_compare` são sinônimos do parâmetro de modelo `Traits`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

Consulte o exemplo de [value_comp](#value_comp) para obter um exemplo de como declarar e usar `value_compare`.

## <a name="value_type"></a>  set::value_type

Um tipo que descreve um objeto armazenado como um elemento de um set em sua capacidade como um valor.

```cpp
typedef Key value_type;
```

### <a name="remarks"></a>Comentários

`value_type` é um sinônimo do parâmetro de modelo `Key`.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe set](../standard-library/set-class.md).

Observe que ambos [key_type](#key_type) e `value_type` são sinônimos do parâmetro de modelo `Key`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// set_value_type.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   set <int> s1;
   set <int>::iterator s1_Iter;

   set <int>::value_type svt_Int;   // Declare value_type
   svt_Int = 10;            // Initialize value_type

   set <int> :: key_type skt_Int;   // Declare key_type
   skt_Int = 20;             // Initialize key_type

   s1.insert( svt_Int );         // Insert value into s1
   s1.insert( skt_Int );         // Insert key into s1

   // A set accepts key_types or value_types as elements
   cout << "The set has elements:";
   for ( s1_Iter = s1.begin( ) ; s1_Iter != s1.end( ); s1_Iter++)
      cout << " " << *s1_Iter;
   cout << "." << endl;
}
```

```Output
The set has elements: 10 20.
```

## <a name="see-also"></a>Consulte também

[\<set>](../standard-library/set.md)<br/>
[Contêineres](../cpp/containers-modern-cpp.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
