---
title: Classe multiset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- set/std::multiset
- set/std::multiset::allocator_type
- set/std::multiset::const_iterator
- set/std::multiset::const_pointer
- set/std::multiset::const_reference
- set/std::multiset::const_reverse_iterator
- set/std::multiset::difference_type
- set/std::multiset::iterator
- set/std::multiset::key_compare
- set/std::multiset::key_type
- set/std::multiset::pointer
- set/std::multiset::reference
- set/std::multiset::reverse_iterator
- set/std::multiset::size_type
- set/std::multiset::value_compare
- set/std::multiset::value_type
- set/std::multiset::begin
- set/std::multiset::cbegin
- set/std::multiset::cend
- set/std::multiset::clear
- set/std::multiset::count
- set/std::multiset::crbegin
- set/std::multiset::crend
- set/std::multiset::emplace
- set/std::multiset::emplace_hint
- set/std::multiset::empty
- set/std::multiset::end
- set/std::multiset::equal_range
- set/std::multiset::erase
- set/std::multiset::find
- set/std::multiset::get_allocator
- set/std::multiset::insert
- set/std::multiset::key_comp
- set/std::multiset::lower_bound
- set/std::multiset::max_size
- set/std::multiset::rbegin
- set/std::multiset::rend
- set/std::multiset::size
- set/std::multiset::swap
- set/std::multiset::upper_bound
- set/std::multiset::value_comp
dev_langs:
- C++
helpviewer_keywords:
- std::multiset [C++]
- std::multiset [C++], allocator_type
- std::multiset [C++], const_iterator
- std::multiset [C++], const_pointer
- std::multiset [C++], const_reference
- std::multiset [C++], const_reverse_iterator
- std::multiset [C++], difference_type
- std::multiset [C++], iterator
- std::multiset [C++], key_compare
- std::multiset [C++], key_type
- std::multiset [C++], pointer
- std::multiset [C++], reference
- std::multiset [C++], reverse_iterator
- std::multiset [C++], size_type
- std::multiset [C++], value_compare
- std::multiset [C++], value_type
- std::multiset [C++], begin
- std::multiset [C++], cbegin
- std::multiset [C++], cend
- std::multiset [C++], clear
- std::multiset [C++], count
- std::multiset [C++], crbegin
- std::multiset [C++], crend
- std::multiset [C++], emplace
- std::multiset [C++], emplace_hint
- std::multiset [C++], empty
- std::multiset [C++], end
- std::multiset [C++], equal_range
- std::multiset [C++], erase
- std::multiset [C++], find
- std::multiset [C++], get_allocator
- std::multiset [C++], insert
- std::multiset [C++], key_comp
- std::multiset [C++], lower_bound
- std::multiset [C++], max_size
- std::multiset [C++], rbegin
- std::multiset [C++], rend
- std::multiset [C++], size
- std::multiset [C++], swap
- std::multiset [C++], upper_bound
- std::multiset [C++], value_comp
ms.assetid: 630e8c10-0ce9-4ad9-8d79-9e91a600713f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d32b6e61ab0dbac6010c6ed233f2cd822e73c2d5
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220969"
---
# <a name="multiset-class"></a>Classe multiset

A classe multiset da biblioteca padrão C++ é usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e na qual eles atuam como valores de chave, de acordo com os quais os dados são automaticamente ordenados. O valor de chave de um elemento em um multiset não pode ser alterado diretamente. Em vez disso, os valores antigos devem ser excluídos e os elementos com novos valores inseridos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Key, class Compare =less <Key>, class Allocator =allocator <Key>>
class multiset
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
 O tipo de dados do elemento a ser armazenado no multiset.

*Compare*<br/>
 O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no multiset. O predicado binário **less**\<Key> é o valor padrão.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

*Alocador*<br/>
 O tipo que representa o objeto de alocador armazenado que encapsula detalhes sobre a alocação e a desalocação do multiset da memória. O valor padrão é `allocator<Key>`.

## <a name="remarks"></a>Comentários

A classe multiset da biblioteca padrão C++ é:

- Um contêiner associativo, que é um contêiner de tamanho variável que oferece suporte à recuperação eficiente dos valores de elemento com base em um valor de chave associado.

- Reversível, pois fornece iteradores bidirecionais para acessar seus elementos.

- Classificada, pois seus elementos são ordenados por valores de chave no contêiner, de acordo com uma função de comparação especificada.

- Múltipla no sentido de que seus elementos não precisam ter chaves exclusivas para que um valor de chave possa ter muitos valores de elemento associados a ele.

- Um contêiner associativo simples, pois seus valores de elemento são seus valores de chave.

- Uma classe de modelo, pois a funcionalidade fornecida por ela é genérica e, portanto, independente do tipo de dados específico contido como elementos. O tipo de dados a ser usado é especificado como um parâmetro no modelo de classe juntamente com a função de comparação e o alocador.

O iterador fornecido pela classe multiset é um iterador bidirecional, mas as funções membro de classe [insert](#insert) e [multiset](#multiset) têm versões que usam como parâmetros de modelo um iterador de entrada mais fraco, cujos requisitos de funcionalidade são mais minimalistas do que os garantidos pela classe de iteradores bidirecionais. Os conceitos de iterador diferente formam uma família relacionada por refinamentos em sua funcionalidade. Cada conceito de iterador tem seu próprio conjunto de requisitos e os algoritmos que funcionam com eles devem limitar suas suposições para os requisitos fornecidos por esse tipo de iterador. Pode ser pressuposto que um iterador de entrada possa ser desreferenciado para fazer referência a algum objeto e que possa ser incrementado para o próximo iterador na sequência. Esse é um conjunto mínimo de funcionalidade, mas é suficiente para poder expressar de forma significativa um intervalo de iteradores [ `First`, `Last`) no contexto de funções membro da classe.

A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. Os contêineres associativos são otimizados para as operações de pesquisa, inserção e remoção. As funções membro que oferecem suporte explicitamente a essas operações são eficientes, executando-as em um tempo que está na média proporcional para o logaritmo do número de elementos no contêiner. A inserção de elementos não invalida iteradores e a remoção de elementos invalida apenas os iteradores que apontavam especificamente os elementos removidos.

O multiset deve ser o contêiner associativo escolhido quando as condições que associam os valores às respectivas chaves forem atendidas pelo aplicativo. Os elementos de um multiset podem ser múltiplos e atuar como suas próprias chaves de classificação, de modo que as chaves não são exclusivas. Um modelo para esse tipo de estrutura é uma lista ordenada de palavras, por exemplo, na qual as palavras podem ocorrer mais de uma vez. Não tendo sido permitidas as várias ocorrências das palavras, um conjunto seria a estrutura de contêiner apropriada. Se as definições exclusivas fossem anexadas como valores à lista de palavras-chave exclusivas, um mapa seria uma estrutura apropriada para conter esses dados. Se, em vez disso, as definições não fossem exclusivas, um multimapa seria o contêiner ideal.

O multiset ordena a sequência que controla chamando um objeto de função armazenado do tipo *comparar*. Esse objeto armazenado é uma função de comparação que pode ser acessada chamando a função membro [key_comp](#key_comp). De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão. Um predicado binário *f*( *x*, *y*) é um objeto de função que tem dois objetos de argumento *x* e *y* e um valor retornado de **true** ou **false**. Uma ordenação imposta em um conjunto será uma ordenação fraca restrita se o predicado binário for irreflexivo, antissimétrico e transitivo e se a equivalência for transitiva, em que dois objetos x e y são definidos para serem equivalentes quando ambos *f*( *x,y*) e *f*( *y,x*) são falsos. Se a condição mais forte de igualdade entre as chaves substituir essa equivalência, a ordenação será total (no sentido de que todos os elementos serão ordenados um em relação ao outro) e as chaves correspondentes não poderão ser diferenciadas uma da outra.

No C++ 14, você pode habilitar a pesquisa heterogênea ao especificar o predicado `std::less<>` ou o `std::greater<>`, que não tem nenhum parâmetro de tipo. Para obter mais informações, consulte [Pesquisa heterogênea em contêineres associativos](../standard-library/stl-containers.md#sequence_containers)

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[multiset](#multiset)|Constrói um `multiset` que está vazio ou que é uma cópia de todo ou parte de um `multiset` especificado.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|Um typedef para a classe `allocator` do objeto `multiset`.|
|[const_iterator](#const_iterator)|Um typedef para um iterador bidirecional que pode ler um **const** elemento o `multiset`.|
|[const_pointer](#const_pointer)|Um typedef para um ponteiro para um **const** elemento em um `multiset`.|
|[const_reference](#const_reference)|Um typedef de uma referência a um **const** elemento armazenado em um `multiset` para leitura e execução **const** operações.|
|[const_reverse_iterator](#const_reverse_iterator)|Um typedef para um iterador bidirecional que pode ler qualquer **const** elemento o `multiset`.|
|[difference_type](#difference_type)|Um typedef de inteiro com sinal para o número de elementos de um `multiset` em um intervalo entre os elementos apontado pelos iteradores.|
|[iterator](#iterator)|Um typedef para um iterador bidirecional que pode ler ou modificar qualquer elemento em um `multiset`.|
|[key_compare](#key_compare)|Um typedef de um objeto de função que pode comparar duas chaves para determinar a ordem relativa de dois elementos no `multiset`.|
|[key_type](#key_type)|Um typedef de um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `multiset`.|
|[pointer](#pointer)|Um typedef de um ponteiro para um elemento em um `multiset`.|
|[reference](#reference)|Um typedef de uma referência para um elemento armazenado em um `multiset`.|
|[reverse_iterator](#reverse_iterator)|Um typedef para um iterador bidirecional que pode ler ou modificar um elemento em um `multiset` invertido.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `multiset`.|
|[value_compare](#value_compare)|O typedef de um objeto de função que pode comparar dois elementos como chaves de classificação para determinar sua ordem relativa no `multiset`.|
|[value_type](#value_type)|Um typedef que descreve um objeto armazenado como um elemento enquanto um `multiset` em sua capacidade como um valor.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[begin](#begin)|Retorna um iterador que aponta para o primeiro elemento no `multiset`.|
|[cbegin](#cbegin)|Retorna um iterador const que trata o primeiro elemento no `multiset`.|
|[cend](#cend)|Retorna um iterador const que trata o local após o último elemento em um `multiset`.|
|[clear](#clear)|Apaga todos os elementos de um `multiset`.|
|[count](#count)|Retorna o número de elementos em um `multiset` cuja chave corresponde à chave especificada como um parâmetro.|
|[crbegin](#crbegin)|Retorna um iterador const que trata o primeiro elemento em um conjunto invertido.|
|[crend](#crend)|Retorna um iterador const que trata o local após o último elemento em um conjunto invertido.|
|[emplace](#emplace)|Insere um elemento construído adequadamente em um `multiset`.|
|[emplace_hint](#emplace_hint)|Insere um elemento construído adequadamente em um `multiset`, com uma dica de posicionamento.|
|[empty](#empty)|Testa se `multiset` está vazio.|
|[end](#end)|Retorna um iterador que aponta para o local após o último elemento em um `multiset`.|
|[equal_range](#equal_range)|Retorna um par de iteradores. O primeiro iterador no par aponta para o primeiro elemento em um `multiset` com uma chave que é maior que uma chave especificada. O segundo iterador no par aponta para o primeiro elemento no `multiset` com uma chave que é igual ou maior que a chave.|
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um `multiset` das posições especificadas ou remove elementos que correspondem a uma chave especificada.|
|[find](#find)|Retorna um iterador que aponta para o primeiro local de um elemento em um `multiset` que tem uma chave igual a uma chave especificada.|
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` que é usada para construir o `multiset`.|
|[insert](#insert)|Insere um elemento ou um intervalo de elementos em um `multiset`.|
|[key_comp](#key_comp)|Fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no `multiset`.|
|[lower_bound](#lower_bound)|Retorna um iterador para o primeiro elemento em um `multiset` com uma chave que é igual ou maior que uma chave especificada.|
|[max_size](#max_size)|Retorna o comprimento máximo do `multiset`.|
|[rbegin](#rbegin)|Retorna um iterador que aponta para o primeiro elemento em um `multiset` invertido.|
|[rend](#rend)|Retorna um iterador que aponta para o local após o último elemento em um `multiset` invertido.|
|[size](#size)|Retorna o número de elementos em um `multiset`.|
|[swap](#swap)|Troca os elementos de dois `multiset`s.|
|[upper_bound](#upper_bound)|Retorna um iterador para o primeiro elemento em um `multiset` com uma chave que é maior que uma chave especificada.|
|[value_comp](#value_comp)|Recupera uma cópia do objeto de comparação que é usada para ordenar valores de elemento em um `multiset`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Substitui os elementos de um `multiset` por uma cópia de outro `multiset`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<set>

**Namespace:** std

## <a name="allocator_type"></a>  multiset::allocator_type

Um tipo que representa a classe allocator do objeto multiset

```cpp
typedef Allocator allocator_type;
```

### <a name="remarks"></a>Comentários

`allocator_type` é um sinônimo do parâmetro de modelo `Allocator`.

Para obter mais informações sobre `Allocator`, consulte a seção Comentários do tópico [Classe multiset](../standard-library/multiset-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [get_allocator](#get_allocator) para obter um exemplo do uso de `allocator_type`

## <a name="begin"></a>  multiset::begin

Retorna um iterador que trata o primeiro elemento no multiset.

```cpp
const_iterator begin() const;

iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional que trata do primeiro elemento no multiset ou do local que sucede um multiset vazio.

### <a name="example"></a>Exemplo

```cpp
// multiset_begin.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int>::iterator ms1_Iter;
   multiset <int>::const_iterator ms1_cIter;

   ms1.insert( 1 );
   ms1.insert( 2 );
   ms1.insert( 3 );

   ms1_Iter = ms1.begin( );
   cout << "The first element of ms1 is " << *ms1_Iter << endl;

   ms1_Iter = ms1.begin( );
   ms1.erase( ms1_Iter );

   // The following 2 lines would err as the iterator is const
   // ms1_cIter = ms1.begin( );
   // ms1.erase( ms1_cIter );

   ms1_cIter = ms1.begin( );
   cout << "The first element of ms1 is now " << *ms1_cIter << endl;
}
```

```Output
The first element of ms1 is 1
The first element of ms1 is now 2
```

## <a name="cbegin"></a>  multiset::cbegin

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

## <a name="cend"></a>  multiset::cend

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

## <a name="clear"></a>  multiset::clear

Apaga todos os elementos de um multiset.

```cpp
void clear();
```

### <a name="example"></a>Exemplo

```cpp
// multiset_clear.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;

   ms1.insert( 1 );
   ms1.insert( 2 );

   cout << "The size of the multiset is initially "
        << ms1.size( ) << "." << endl;

   ms1.clear( );
   cout << "The size of the multiset after clearing is "
        << ms1.size( ) << "." << endl;
}
```

```Output
The size of the multiset is initially 2.
The size of the multiset after clearing is 0.
```

## <a name="const_iterator"></a>  multiset::const_iterator

Um tipo que fornece um iterador bidirecional que pode ler um elemento **const** no multiset.

```cpp
typedef implementation-defined const_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.

### <a name="example"></a>Exemplo

Consulte o exemplo para [begin](#begin) para obter um exemplo que usa `const_iterator`.

## <a name="const_pointer"></a>  multiset::const_pointer

Um tipo que fornece um ponteiro para um elemento **const** em um multiset.

```cpp
typedef typename allocator_type::const_pointer const_pointer;
```

### <a name="remarks"></a>Comentários

Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto multiset.

## <a name="const_reference"></a>  multiset::const_reference

Um tipo que fornece uma referência a um elemento **const** armazenado em um multiset para leitura e execução de operações **const**.

```cpp
typedef typename allocator_type::const_reference const_reference;
```

### <a name="example"></a>Exemplo

```cpp
// multiset_const_ref.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;

   ms1.insert( 10 );
   ms1.insert( 20 );

   // Declare and initialize a const_reference &Ref1
   // to the 1st element
   const int &Ref1 = *ms1.begin( );

   cout << "The first element in the multiset is "
        << Ref1 << "." << endl;

   // The following line would cause an error because the
   // const_reference cannot be used to modify the multiset
   // Ref1 = Ref1 + 5;
}
```

```Output
The first element in the multiset is 10.
```

## <a name="const_reverse_iterator"></a>  multiset::const_reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler qualquer elemento **const** no multiset.

```cpp
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar no multiset em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rend](#rend) para obter um exemplo de como declarar e usar o `const_reverse_iterator`.

## <a name="count"></a>  multiset::count

Retorna o número de elementos em um multiset cuja chave corresponde a uma chave especificada pelo parâmetro.

```cpp
size_type count(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave dos elementos a serem correspondidos do multiset.

### <a name="return-value"></a>Valor de retorno

O número de elementos no multiset cuja chave de classificação corresponde à chave de parâmetro.

### <a name="remarks"></a>Comentários

A função membro retorna o número de elementos *x* no intervalo

[ `lower_bound` (_ *Key* ), `upper_bound` (\_ *Key* ) ).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o uso da função membro multiset::count.

```cpp
// multiset_count.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main()
{
    using namespace std;
    multiset<int> ms1;
    multiset<int>::size_type i;

    ms1.insert(1);
    ms1.insert(1);
    ms1.insert(2);

    // Elements do not need to be unique in multiset,
    // so duplicates are allowed and counted.
    i = ms1.count(1);
    cout << "The number of elements in ms1 with a sort key of 1 is: "
         << i << "." << endl;

    i = ms1.count(2);
    cout << "The number of elements in ms1 with a sort key of 2 is: "
         << i << "." << endl;

    i = ms1.count(3);
    cout << "The number of elements in ms1 with a sort key of 3 is: "
         << i << "." << endl;
}
```

```Output
The number of elements in ms1 with a sort key of 1 is: 2.
The number of elements in ms1 with a sort key of 2 is: 1.
The number of elements in ms1 with a sort key of 3 is: 0.
```

## <a name="crbegin"></a>  multiset::crbegin

Retorna um iterador const que trata o primeiro elemento em um multiset invertido.

```cpp
const_reverse_iterator crbegin() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido const que trata do primeiro elemento em um multiset invertido ou que trata do que foi o último elemento do multiset não invertido.

### <a name="remarks"></a>Comentários

`crbegin` é usado com um multiset invertido, assim como begin é usado com um multiset.

Com o valor retornado de `crbegin`, o objeto multiset não pode ser modificado.

`crbegin` pode ser usado para iterar em um multiset no sentido reverso.

### <a name="example"></a>Exemplo

```cpp
// multiset_crbegin.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int>::const_reverse_iterator ms1_crIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   ms1_crIter = ms1.crbegin( );
   cout << "The first element in the reversed multiset is "
        << *ms1_crIter << "." << endl;
}
```

```Output
The first element in the reversed multiset is 30.
```

## <a name="crend"></a>  multiset::crend

Retorna um iterador const que trata o local após o último elemento em um multiset invertido.

```cpp
const_reverse_iterator crend() const;
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso const que trata da localização que vem após o último elemento em um multiset invertido (o local que precedeu o primeiro elemento no multiset não invertido).

### <a name="remarks"></a>Comentários

`crend` é usado com um multiset invertido, assim como [end](#end) é usado com um multiset.

Com o valor retornado de `crend`, o objeto multiset não pode ser modificado.

`crend` pode ser usado para testar se um iterador inverso alcançou o final de seu multiset.

O valor retornado por `crend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// multiset_crend.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main() {
   using namespace std;
   multiset <int> ms1;
   multiset <int>::const_reverse_iterator ms1_crIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   ms1_crIter = ms1.crend( ) ;
   ms1_crIter--;
   cout << "The last element in the reversed multiset is "
        << *ms1_crIter << "." << endl;
}
```

## <a name="difference_type"></a>  multiset::difference_type

Um tipo de inteiro com sinal que pode ser usado para representar o número de elementos de um multiset em um intervalo entre os elementos apontados pelos iteradores.

```cpp
typedef typename allocator_type::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

`difference_type` é o tipo retornado ao subtrair ou incrementar por meio de iteradores do contêiner. `difference_type` geralmente é usado para representar o número de elementos no intervalo [`first`, `last`) entre os iteradores `first` e `last`, inclui o elemento apontado por `first` e o intervalo de elementos até, mas sem incluir, o elemento apontado por `last`.

Observe que, embora `difference_type` esteja disponível para todos os iteradores que atendem aos requisitos de um iterador de entrada, que inclui a classe de iteradores bidirecionais com suporte dos contêineres reversíveis, como um conjunto, a subtração entre iteradores só tem suporte dos iteradores de acesso aleatório fornecidos por um contêiner de acesso aleatório, como um vetor.

### <a name="example"></a>Exemplo

```cpp
// multiset_diff_type.cpp
// compile with: /EHsc
#include <iostream>
#include <set>
#include <algorithm>

int main( )
{
   using namespace std;

   multiset <int> ms1;
   multiset <int>::iterator ms1_Iter, ms1_bIter, ms1_eIter;

   ms1.insert( 20 );
   ms1.insert( 10 );
   ms1.insert( 20 );

   ms1_bIter = ms1.begin( );
   ms1_eIter = ms1.end( );

   multiset <int>::difference_type   df_typ5, df_typ10, df_typ20;

   df_typ5 = count( ms1_bIter, ms1_eIter, 5 );
   df_typ10 = count( ms1_bIter, ms1_eIter, 10 );
   df_typ20 = count( ms1_bIter, ms1_eIter, 20 );

   // The keys, and hence the elements, of a multiset are not unique
   cout << "The number '5' occurs " << df_typ5
        << " times in multiset ms1.\n";
   cout << "The number '10' occurs " << df_typ10
        << " times in multiset ms1.\n";
   cout << "The number '20' occurs " << df_typ20
        << " times in multiset ms1.\n";

   // Count the number of elements in a multiset
   multiset <int>::difference_type  df_count = 0;
   ms1_Iter = ms1.begin( );
   while ( ms1_Iter != ms1_eIter)
   {
      df_count++;
      ms1_Iter++;
   }

   cout << "The number of elements in the multiset ms1 is: "
        << df_count << "." << endl;
}
```

```Output
The number '5' occurs 0 times in multiset ms1.
The number '10' occurs 1 times in multiset ms1.
The number '20' occurs 2 times in multiset ms1.
The number of elements in the multiset ms1 is: 3.
```

## <a name="emplace"></a>  multiset::emplace

Insere um elemento criado no local (nenhuma operação de cópia ou movimentação é realizada), com uma dica de posicionamento.

```cpp
template <class... Args>
iterator emplace(Args&&... args);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*args*|Os argumentos encaminhados para construir um elemento a ser inserido no multiset.|

### <a name="return-value"></a>Valor de retorno

Um iterador para o elemento recém-inserido.

### <a name="remarks"></a>Comentários

Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

### <a name="example"></a>Exemplo

```cpp
// multiset_emplace.cpp
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
    multiset<string> s1;

    s1.emplace("Anna");
    s1.emplace("Bob");
    s1.emplace("Carmine");

    cout << "multiset modified, now contains ";
    print(s1);
    cout << endl;

    s1.emplace("Bob");

    cout << "multiset modified, now contains ";
    print(s1);
    cout << endl;
}

```

## <a name="emplace_hint"></a>  multiset::emplace_hint

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
|*args*|Os argumentos encaminhados para construir um elemento a ser inserido no multiset.|
|*where*|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto preceder imediatamente *onde*, inserção poderá ocorrer em tempo constante amortizado, em vez de no tempo logarítmico.)|

### <a name="return-value"></a>Valor de retorno

Um iterador para o elemento recém-inserido.

### <a name="remarks"></a>Comentários

Nenhuma referência a elementos de contêiner é invalidada por essa função, mas ela pode invalidar todos os iteradores no contêiner.

Durante o posicionamento, se uma exceção for lançada, o estado do contêiner não será modificado.

Para obter um exemplo de código, consulte [set::emplace_hint](../standard-library/set-class.md#emplace_hint).

## <a name="empty"></a>  multiset::empty

Testa se um multiset está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o multiset estiver vazio; **false** se o multiset não estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// multiset_empty.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1, ms2;
   ms1.insert ( 1 );

   if ( ms1.empty( ) )
      cout << "The multiset ms1 is empty." << endl;
   else
      cout << "The multiset ms1 is not empty." << endl;

   if ( ms2.empty( ) )
      cout << "The multiset ms2 is empty." << endl;
   else
      cout << "The multiset ms2 is not empty." << endl;
}
```

```Output
The multiset ms1 is not empty.
The multiset ms2 is empty.
```

## <a name="end"></a>  multiset::end

Retorna o iterador que ultrapassa o fim.

```cpp
const_iterator end() const;


iterator end();
```

### <a name="return-value"></a>Valor de retorno

O iterador que ultrapassa o fim. Se o multiconjunto estiver vazio, então, `multiset::end() == multiset::begin()`.

### <a name="remarks"></a>Comentários

**end** é usado para testar se um iterador passou do fim de seu multiset.

O valor retornado por **end** não deve ser desreferenciado.

Para obter um exemplo de código, consulte [multiset::find](#find).

## <a name="equal_range"></a>  multiset::equal_range

Retorna um par de iteradores respectivamente para o primeiro elemento em um multiset com uma chave que é maior do que uma chave especificada e para o primeiro elemento no multiset com uma chave igual ou maior que a chave.

```cpp
pair <const_iterator, const_iterator> equal_range (const Key& key) const;

pair <iterator, iterator> equal_range (const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave do argumento a ser comparada com a chave de classificação de um elemento do multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um par de iteradores em que o primeiro é o [lower_bound](#lower_bound) da chave e o segundo é o [upper_bound](#upper_bound) da chave.

Para acessar o primeiro iterador de um par `pr` retornado pela função membro, use `pr`. **first** e para desreferenciar o iterador de limite inferior, use \*( `pr`. **first**). Para acessar o segundo iterador de um par `pr` retornado pela função membro, use `pr`. **second** e para desreferenciar o iterador de limite superior, use \*( `pr`. **second**).

### <a name="example"></a>Exemplo

```cpp
// multiset_equal_range.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   typedef multiset<int, less<int> > IntSet;
   IntSet ms1;
   multiset <int> :: const_iterator ms1_RcIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   pair <IntSet::const_iterator, IntSet::const_iterator> p1, p2;
   p1 = ms1.equal_range( 20 );

   cout << "The upper bound of the element with "
        << "a key of 20 in the multiset ms1 is: "
        << *( p1.second ) << "." << endl;

   cout << "The lower bound of the element with "
        << "a key of 20 in the multiset ms1 is: "
        << *( p1.first ) << "." << endl;

   // Compare the upper_bound called directly
   ms1_RcIter = ms1.upper_bound( 20 );
   cout << "A direct call of upper_bound( 20 ) gives "
        << *ms1_RcIter << "," << endl
        << "matching the 2nd element of the pair"
        << " returned by equal_range( 20 )." << endl;

   p2 = ms1.equal_range( 40 );

   // If no match is found for the key,
   // both elements of the pair return end( )
   if ( ( p2.first == ms1.end( ) ) && ( p2.second == ms1.end( ) ) )
      cout << "The multiset ms1 doesn't have an element "
              << "with a key less than 40." << endl;
   else
      cout << "The element of multiset ms1 with a key >= 40 is: "
                << *( p1.first ) << "." << endl;
}
```

```Output
The upper bound of the element with a key of 20 in the multiset ms1 is: 30.
The lower bound of the element with a key of 20 in the multiset ms1 is: 20.
A direct call of upper_bound( 20 ) gives 30,
matching the 2nd element of the pair returned by equal_range( 20 ).
The multiset ms1 doesn't have an element with a key less than 40.
```

## <a name="erase"></a>  multiset::erase

Remove um elemento ou um intervalo de elementos em um multiset das posições especificadas ou remove elementos que correspondem a uma chave especificada.

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

Para as duas primeiras funções membro, um iterador bidirecional que designa o primeiro elemento restante além de quaisquer elementos removidos ou um elemento que será o final do multiset, se esse elemento não existir.

Para a terceira função membro, ele retorna o número de elementos que foram removidos do multiset.

### <a name="remarks"></a>Comentários

Para obter um exemplo de código, consulte [set::erase](../standard-library/set-class.md#erase).

## <a name="find"></a>  multiset::find

Retorna um iterador que aponta para o local de um elemento em um multiconjunto que tem uma chave igual a uma chave especificada.

```cpp
iterator find(const Key& key);


const_iterator find(const Key& key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 O valor da chave a ser comparado pela chave de classificação de um elemento do multiconjunto que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um iterador que se refere ao local de um elemento com uma chave especificada ou o local após o último elemento no multiset (`multiset::end()`) se nenhuma correspondência for encontrada para a chave.

### <a name="remarks"></a>Comentários

A função membro retorna um iterador que se refere a um elemento no multiset cuja chave é equivalente ao argumento *chave* em um predicado binário que induz uma ordenação com base em uma relação de comparação menor.

Se o valor de retorno `find` for atribuído a um `const_iterator`, o objeto multiset não pode ser modificado. Se o valor de retorno `find` for atribuído a um `iterator`, o objeto multiset poderá ser modificado

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
    multiset<int> s1({ 40, 45 });
    cout << "The starting multiset s1 is: " << endl;
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

    cout << "The modified multiset s1 is: " << endl;
    print_collection(s1);
    cout << endl;
    findit(s1, 45);
    findit(s1, 6);
}
```

## <a name="get_allocator"></a>  multiset::get_allocator

Retorna uma cópia do objeto alocador usado para construir o multiset.

```cpp
allocator_type get_allocator() const;
```

### <a name="return-value"></a>Valor de retorno

O alocador usado pelo multiset.

### <a name="remarks"></a>Comentários

Alocadores para a classe multiset especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.

### <a name="example"></a>Exemplo

```cpp
// multiset_get_allocator.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int>::allocator_type ms1_Alloc;
   multiset <int>::allocator_type ms2_Alloc;
   multiset <double>::allocator_type ms3_Alloc;
   multiset <int>::allocator_type ms4_Alloc;

   // The following lines declare objects
   // that use the default allocator.
   multiset <int> ms1;
   multiset <int, allocator<int> > ms2;
   multiset <double, allocator<double> > ms3;

   cout << "The number of integers that can be allocated"
        << endl << "before free memory is exhausted: "
        << ms2.max_size( ) << "." << endl;

   cout << "The number of doubles that can be allocated"
        << endl << "before free memory is exhausted: "
        << ms3.max_size( ) <<  "." << endl;

   // The following lines create a multiset ms4
   // with the allocator of multiset ms1
   ms1_Alloc = ms1.get_allocator( );
   multiset <int> ms4( less<int>( ), ms1_Alloc );
   ms4_Alloc = ms4.get_allocator( );

   // Two allocators are interchangeable if
   // storage allocated from each can be
   // deallocated with the other
   if( ms1_Alloc == ms4_Alloc )
   {
      cout << "Allocators are interchangeable."
           << endl;
   }
   else
   {
      cout << "Allocators are not interchangeable."
           << endl;
   }
}
```

## <a name="insert"></a>  multiset::insert

Insere um elemento ou um intervalo de elementos em um multiset.

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
|*Val*|O valor de um elemento a ser inserido no multiset.|
|*Where*|O local a partir do qual se começa a procurar pelo ponto de inserção correto. (Se esse ponto preceder imediatamente *onde*, inserção poderá ocorrer em tempo constante amortizado, em vez de no tempo logarítmico.)|
|*ValTy*|Parâmetro de modelo que especifica o tipo de argumento que o multiset pode usar para construir um elemento de [value_type](../standard-library/map-class.md#value_type)e perfect-forwards *Val* como um argumento.|
|*Primeiro*|A posição do primeiro elemento a ser copiado.|
|*último*|A posição imediatamente após o último elemento a ser copiado.|
|*InputIterator*|Argumento da função de modelo que atende aos requisitos de um [iterador de entrada](../standard-library/input-iterator-tag-struct.md) que aponta para elementos de um tipo que pode ser usado para construir objetos [value_type](../standard-library/map-class.md#value_type).|
|*IList*|O [initializer_list](../standard-library/initializer-list.md) do qual os elementos serão copiados.|

### <a name="return-value"></a>Valor de retorno

As funções do membro de inserir elemento único, (1) e (2), retornam um iterador para a posição em que o novo elemento foi inserido no multiset.

As funções do membro de inserir elemento único, (3) e (4), retornam um iterador para a posição em que o novo elemento foi inserido no multiset.

### <a name="remarks"></a>Comentários

Nenhum ponteiro ou referência é invalidado por esta função, mas ela pode invalidar todos os iteradores para o contêiner.

Durante a inserção de apenas um elemento, se uma exceção for lançada, o estado do contêiner não será modificado. Durante a inserção de vários elementos, se uma exceção for lançada, o contêiner será deixado em um estado não especificado, mas válido.

O [value_type](../standard-library/map-class.md#value_type) de um contêiner é um typedef que pertence ao contêiner e, para o conjunto, `multiset<V>::value_type` é do tipo `const V`.

A função do membro de intervalo (5) insere a sequência de valores de elemento em um multiset que corresponde a cada elemento tratado por um iterador no intervalo `[First, Last)`; portanto, `Last` não é inserido. A função de membro do contêiner `end()` refere-se à posição logo após o último elemento no contêiner, por exemplo, a instrução `s.insert(v.begin(), v.end());` insere todos os elementos de `v` em `s`.

A função membro da lista do inicializador (6) usa um [initializer_list](../standard-library/initializer-list.md) para copiar elementos no multiset.

Para inserir um elemento criado no local, ou seja, sem a realização de operações de cópia ou movimentação, consulte [multiset::emplace](#emplace) e [multiset::emplace_hint](#emplace_hint).

### <a name="example"></a>Exemplo

```cpp
// multiset_insert.cpp
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
    multiset<int> s1;
    // call insert(const value_type&) version
    s1.insert({ 1, 10 });
    // call insert(ValTy&&) version
    s1.insert(20);

    cout << "The original multiset values of s1 are:" << endl;
    print(s1);

    // intentionally attempt a duplicate, single element
    s1.insert(1);
    cout << "The modified multiset values of s1 are:" << endl;
    print(s1);
    cout << endl;

    // single element, with hint
    s1.insert(s1.end(), 30);
    cout << "The modified multiset values of s1 are:" << endl;
    print(s1);
    cout << endl;

    // The templatized version inserting a jumbled range
    multiset<int> s2;
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

    cout << "The modified multiset values of s2 are:" << endl;
    print(s2);
    cout << endl;

    // The templatized versions move-constructing elements
    multiset<string>  s3;
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

    multiset<int> s4;
    // Insert the elements from an initializer_list
    s4.insert({ 4, 44, 2, 22, 3, 33, 1, 11, 5, 55 });
    cout << "After initializer_list insertion, s4 contains:" << endl;
    print(s4);
    cout << endl;
}

```

## <a name="iterator"></a>  multiset::iterator

Um tipo que fornece um [iterador bidirecional](../standard-library/bidirectional-iterator-tag-struct.md) constante que pode ler qualquer elemento em um multiset.

```cpp
typedef implementation-defined iterator;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [começar](#begin) para obter um exemplo de como declarar e usar um `iterator`.

## <a name="key_comp"></a>  multiset::key_comp

Recupera uma cópia do objeto de comparação usada para ordenar chaves em um multiset.

```cpp
key_compare key_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto de função que um multiset usa para ordenar seus elementos, que é o parâmetro de modelo `Compare`.

Para obter mais informações sobre `Compare`, consulte a seção Comentários do tópico [Classe multiset](../standard-library/multiset-class.md).

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro:

**operador booliano**( **const Key&** *x*, **const Key&** *y*);

que retornará true se *x* preceder estritamente *y* na ordem de classificação.

Observe que [key_compare](#key_compare) e [value_compare](#value_compare) são sinônimos do parâmetro de modelo `Compare`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// multiset_key_comp.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;

   multiset <int, less<int> > ms1;
   multiset <int, less<int> >::key_compare kc1 = ms1.key_comp( ) ;
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
           << "where kc1 is the function object of ms1."
           << endl;
   }

   multiset <int, greater<int> > ms2;
   multiset <int, greater<int> >::key_compare kc2 = ms2.key_comp( ) ;
   bool result2 = kc2( 2, 3 ) ;
   if( result2 == true )
   {
      cout << "kc2( 2,3 ) returns value of true, "
           << "where kc2 is the function object of ms2."
           << endl;
   }
   else
   {
      cout << "kc2( 2,3 ) returns value of false, "
           << "where kc2 is the function object of ms2."
           << endl;
   }
}
```

```Output
kc1( 2,3 ) returns value of true, where kc1 is the function object of s1.
kc2( 2,3 ) returns value of false, where kc2 is the function object of ms2.
```

## <a name="key_compare"></a>  multiset::key_compare

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar a ordem relativa de dois elementos no multiset.

```cpp
typedef Compare key_compare;
```

### <a name="remarks"></a>Comentários

`key_compare` é um sinônimo do parâmetro de modelo `Compare`.

Para obter mais informações sobre `Compare`, consulte a seção Comentários do tópico [Classe multiset](../standard-library/multiset-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [key_comp](#key_comp) que demonstra como declarar e usar `key_compare`.

## <a name="key_type"></a>  multiset::key_type

Um tipo que fornece um objeto de função que pode comparar chaves de classificação para determinar a ordem relativa de dois elementos no multiset.

```cpp
typedef Key key_type;
```

### <a name="remarks"></a>Comentários

`key_type` é um sinônimo do parâmetro de modelo `Key`.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico [Classe multiset](../standard-library/multiset-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo para [value_type](#value_type) para obter uma amostra de como declarar e usar `key_type`.

## <a name="lower_bound"></a>  multiset::lower_bound

Retorna um iterador para o primeiro elemento em um conjunto com uma chave que é igual ou maior que uma chave especificada.

```cpp
const_iterator lower_bound(const Key& key) const;

iterator lower_bound(const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave do argumento a ser comparada com a chave de classificação de um elemento do multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Uma `iterator` ou `const_iterator` que tratará o local de um elemento em um multiset com uma chave que é igual ou maior que a chave de argumento ou que trata do local que sucede o último elemento no multiset se nenhuma correspondência for encontrado para a chave.

### <a name="example"></a>Exemplo

```cpp
// multiset_lower_bound.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int> :: const_iterator ms1_AcIter, ms1_RcIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   ms1_RcIter = ms1.lower_bound( 20 );
   cout << "The element of multiset ms1 with a key of 20 is: "
        << *ms1_RcIter << "." << endl;

   ms1_RcIter = ms1.lower_bound( 40 );

   // If no match is found for the key, end( ) is returned
   if ( ms1_RcIter == ms1.end( ) )
      cout << "The multiset ms1 doesn't have an element "
           << "with a key of 40." << endl;
   else
      cout << "The element of multiset ms1 with a key of 40 is: "
           << *ms1_RcIter << "." << endl;

   // The element at a specific location in the multiset can be
   // found using a derefenced iterator addressing the location
   ms1_AcIter = ms1.end( );
   ms1_AcIter--;
   ms1_RcIter = ms1.lower_bound( *ms1_AcIter );
   cout << "The element of ms1 with a key matching "
        << "that of the last element is: "
        << *ms1_RcIter << "." << endl;
}
```

```Output
The element of multiset ms1 with a key of 20 is: 20.
The multiset ms1 doesn't have an element with a key of 40.
The element of ms1 with a key matching that of the last element is: 30.
```

## <a name="max_size"></a>  multiset::max_size

Retorna o comprimento máximo do multiset.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento máximo possível do multiset.

### <a name="example"></a>Exemplo

```cpp
// multiset_max_size.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int>::size_type i;

   i = ms1.max_size( );
   cout << "The maximum possible length "
        << "of the multiset is " << i << "." << endl;
}
```

## <a name="multiset"></a>  multiset::multiset

Cria um multiset que está vazio ou que é uma cópia de todo ou parte de algum outro multiset.

```cpp
multiset();

explicit multiset (
    const Compare& Comp);

multiset (
    const Compare& Comp,
    const Allocator& Al);

multiset(
    const multiset& Right);

multiset(
    multiset&& Right);

multiset(
    initializer_list<Type> IList);

multiset(
    initializer_list<Type> IList,
    const Compare& Comp);

multiset(
    initializer_list<Type> IList,
    const Compare& Comp,
    const Allocator& Al);


template <class InputIterator>
multiset (
    InputIterator First,
    InputIterator Last);

template <class InputIterator>
multiset (
    InputIterator First,
    InputIterator Last,
    const Compare& Comp);

template <class InputIterator>
multiset (
    InputIterator First,
    InputIterator Last,
    const Compare& Comp,
    const Allocator& Al);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*Al*|A classe do alocador de armazenamento a ser usado neste objeto multiset, cujo padrão é `Allocator`.|
|*Comp*|A função de comparação do tipo `const Compare` usada para ordenar os elementos no multiset, cujo padrão é `Compare`.|
|*Direita*|O multiset da qual o multiset criado é uma cópia.|
|*Primeiro*|A posição do primeiro elemento no intervalo de elementos a serem copiados.|
|*último*|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|
|*IList*|O initializer_list do qual copiar os elementos.|

### <a name="remarks"></a>Comentários

Todos os construtores armazenam um tipo de objeto de alocador que gerencia o armazenamento de memória para o multiset e que, posteriormente, pode ser retornado ao chamar [get_allocator](#get_allocator). O parâmetro do alocador muitas vezes é omitido nas declarações de classe e nas macros de pré-processamento usadas para substituir os alocadores alternativos.

Todos os construtores inicializam seu multiset.

Todos os construtores armazenam um objeto de função do tipo Compare, que é usado para estabelecer uma ordem entre as chaves do multiset e que posteriormente pode ser retornado ao chamar [key_comp](#key_comp).

Os primeiros três construtores especificam um multiset inicial vazio, o segundo Especifica o tipo de função de comparação (*Comp*) para ser utilizado para estabelecer explicitamente a ordem dos elementos e o terceiro Especifica o tipo de alocador (*Al*) a ser usado. A palavra-chave **explicit** suprime determinados tipos de conversão automática de tipo.

O quarto construtor Especifica uma cópia do multiset *direita*.

O quinto construtor Especifica uma cópia do multiset ao mover *direita*.

O sexto, sétimo e oitavo construtores especificam um initializer_list da qual os elementos são copiados.

Os próximos três construtores copiam o intervalo `[First, Last)` de um multiset com clareza crescente para especificar o tipo de função de comparação e do alocador.

### <a name="example"></a>Exemplo

```cpp
// multiset_ctor.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main()
{
    using namespace std;
    //multiset <int>::iterator ms1_Iter, ms2_Iter, ms3_Iter;
    multiset <int>::iterator ms4_Iter, ms5_Iter, ms6_Iter, ms7_Iter;

    // Create an empty multiset ms0 of key type integer
    multiset <int> ms0;

    // Create an empty multiset ms1 with the key comparison
    // function of less than, then insert 4 elements
    multiset <int, less<int> > ms1;
    ms1.insert(10);
    ms1.insert(20);
    ms1.insert(20);
    ms1.insert(40);

    // Create an empty multiset ms2 with the key comparison
    // function of geater than, then insert 2 elements
    multiset <int, less<int> > ms2;
    ms2.insert(10);
    ms2.insert(20);

    // Create a multiset ms3 with the
    // allocator of multiset ms1
    multiset <int>::allocator_type ms1_Alloc;
    ms1_Alloc = ms1.get_allocator();
    multiset <int> ms3(less<int>(), ms1_Alloc);
    ms3.insert(30);

    // Create a copy, multiset ms4, of multiset ms1
    multiset <int> ms4(ms1);

    // Create a multiset ms5 by copying the range ms1[ first,  last)
    multiset <int>::const_iterator ms1_bcIter, ms1_ecIter;
    ms1_bcIter = ms1.begin();
    ms1_ecIter = ms1.begin();
    ms1_ecIter++;
    ms1_ecIter++;
    multiset <int> ms5(ms1_bcIter, ms1_ecIter);

    // Create a multiset ms6 by copying the range ms4[ first,  last)
    // and with the allocator of multiset ms2
    multiset <int>::allocator_type ms2_Alloc;
    ms2_Alloc = ms2.get_allocator();
    multiset <int> ms6(ms4.begin(), ++ms4.begin(), less<int>(), ms2_Alloc);

    cout << "ms1 =";
    for (auto i : ms1)
        cout << " " << i;
    cout << endl;

    cout << "ms2 =";
    for (auto i : ms2)
        cout << " " << i;
   cout << endl;

   cout << "ms3 =";
   for (auto i : ms3)
       cout << " " << i;
    cout << endl;

    cout << "ms4 =";
    for (auto i : ms4)
        cout << " " << i;
    cout << endl;

    cout << "ms5 =";
    for (auto i : ms5)
        cout << " " << i;
    cout << endl;

    cout << "ms6 =";
    for (auto i : ms6)
        cout << " " << i;
    cout << endl;

    // Create a multiset by moving ms5
    multiset<int> ms7(move(ms5));
    cout << "ms7 =";
    for (auto i : ms7)
        cout << " " << i;
    cout << endl;

    // Create a multiset with an initializer_list
    multiset<int> ms8({1, 2, 3, 4});
    cout << "ms8=";
    for (auto i : ms8)
        cout << " " << i;
    cout << endl;
}
```

## <a name="op_eq"></a>  multiset::operator=

Substitui os elementos desse `multiset` usando os elementos de outro `multiset`.

```cpp
multiset& operator=(const multiset& right);

multiset& operator=(multiset&& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*right*|O `multiset` do qual os elementos são copiados ou movidos.|

### <a name="remarks"></a>Comentários

`operator=` copia ou move os elementos *certa* nesta `multiset`, dependendo do tipo de referência (lvalue ou rvalue) usado. Elementos que estão neste `multiset` antes de execuções `operator=` são descartados.

### <a name="example"></a>Exemplo

```cpp
// multiset_operator_as.cpp
// compile with: /EHsc
#include <multiset>
#include <iostream>

int main( )
   {
   using namespace std;
   multiset<int> v1, v2, v3;
   multiset<int>::iterator iter;

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

## <a name="pointer"></a>  multiset::pointer

Um tipo que fornece um ponteiro para um elemento em um multiset.

```cpp
typedef typename allocator_type::pointer pointer;
```

### <a name="remarks"></a>Comentários

Um tipo **pointer** pode ser usado para modificar o valor de um elemento.

Na maioria dos casos, um [iterador](#iterator) deve ser usado para acessar os elementos em um objeto multiset.

## <a name="rbegin"></a>  multiset::rbegin

Retorna um iterador que trata o primeiro elemento em um multiset inverso.

```cpp
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional invertido que trata do primeiro elemento em um multiset invertido ou que trata do que foi o último elemento do multiset não invertido.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um multiset invertido, assim como rbegin é usado com um multiset.

Se o valor retornado de `rbegin` for atribuído a `const_reverse_iterator`, o objeto multiset não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto multiset poderá ser modificado.

`rbegin` pode ser usado para iterar em um multiset no sentido reverso.

### <a name="example"></a>Exemplo

```cpp
// multiset_rbegin.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int>::iterator ms1_Iter;
   multiset <int>::reverse_iterator ms1_rIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   ms1_rIter = ms1.rbegin( );
   cout << "The first element in the reversed multiset is "
        << *ms1_rIter << "." << endl;

   // begin can be used to start an interation
   // throught a multiset in a forward order
   cout << "The multiset is:";
   for ( ms1_Iter = ms1.begin( ) ; ms1_Iter != ms1.end( ); ms1_Iter++ )
      cout << " " << *ms1_Iter;
   cout << endl;

   // rbegin can be used to start an interation
   // throught a multiset in a reverse order
   cout << "The reversed multiset is:";
   for ( ms1_rIter = ms1.rbegin( ) ; ms1_rIter != ms1.rend( ); ms1_rIter++ )
      cout << " " << *ms1_rIter;
   cout << endl;

   // A multiset element can be erased by dereferencing to its key
   ms1_rIter = ms1.rbegin( );
   ms1.erase ( *ms1_rIter );

   ms1_rIter = ms1.rbegin( );
   cout << "After the erasure, the first element "
        << "in the reversed multiset is "<< *ms1_rIter << "."
        << endl;
}
```

```Output
The first element in the reversed multiset is 30.
The multiset is: 10 20 30
The reversed multiset is: 30 20 10
After the erasure, the first element in the reversed multiset is 20.
```

## <a name="reference"></a>  multiset::reference

Um tipo que fornece uma referência a um elemento armazenado em um multiset.

```cpp
typedef typename allocator_type::reference reference;
```

### <a name="example"></a>Exemplo

```cpp
// multiset_ref.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;

   ms1.insert( 10 );
   ms1.insert( 20 );

   // Declare and initialize a reference &Ref1 to the 1st element
   const int &Ref1 = *ms1.begin( );

   cout << "The first element in the multiset is "
        << Ref1 << "." << endl;
}
```

```Output
The first element in the multiset is 10.
```

## <a name="rend"></a>  multiset::rend

Retorna um iterador que trata o local após o último elemento em um multiset invertido.

```cpp
const_reverse_iterator rend() const;

reverse_iterator rend();
```

### <a name="return-value"></a>Valor de retorno

Um iterador bidirecional inverso que trata da localização que vem após o último elemento em um multiset invertido (o local que precedeu o primeiro elemento no multiset não invertido).

### <a name="remarks"></a>Comentários

`rend` é usado com um multiset invertido, assim como [end](#end) é usado com um multiset.

Se o valor retornado de `rend` for atribuído a `const_reverse_iterator`, o objeto multiset não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto multiset poderá ser modificado.

`rend` pode ser usado para testar se um iterador inverso alcançou o final de seu multiset.

O valor retornado por `rend` não deve ser desreferenciado.

### <a name="example"></a>Exemplo

```cpp
// multiset_rend.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main() {
   using namespace std;
   multiset <int> ms1;
   multiset <int>::iterator ms1_Iter;
   multiset <int>::reverse_iterator ms1_rIter;
   multiset <int>::const_reverse_iterator ms1_crIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   ms1_rIter = ms1.rend( ) ;
   ms1_rIter--;
   cout << "The last element in the reversed multiset is "
        << *ms1_rIter << "." << endl;

   // end can be used to terminate an interation
   // throught a multiset in a forward order
   cout << "The multiset is: ";
   for ( ms1_Iter = ms1.begin( ) ; ms1_Iter != ms1.end( ); ms1_Iter++ )
      cout << *ms1_Iter << " ";
   cout << "." << endl;

   // rend can be used to terminate an interation
   // throught a multiset in a reverse order
   cout << "The reversed multiset is: ";
   for ( ms1_rIter = ms1.rbegin( ) ; ms1_rIter != ms1.rend( ); ms1_rIter++ )
      cout << *ms1_rIter << " ";
   cout << "." << endl;

   ms1_rIter = ms1.rend( );
   ms1_rIter--;
   ms1.erase ( *ms1_rIter );

   ms1_rIter = ms1.rend( );
   --ms1_rIter;
   cout << "After the erasure, the last element in the "
        << "reversed multiset is " << *ms1_rIter << "." << endl;
}
```

## <a name="reverse_iterator"></a>  multiset::reverse_iterator

Um tipo que fornece um iterador bidirecional que pode ler ou modificar um elemento em um multiset invertido.

```cpp
typedef std::reverse_iterator<iterator> reverse_iterator;
```

### <a name="remarks"></a>Comentários

Um tipo `reverse_iterator` é usado para iterar pelo multiset em ordem inversa.

### <a name="example"></a>Exemplo

Veja o exemplo de [rbegin](#rbegin) que demonstra como declarar e usar `reverse_iterator`.

## <a name="size"></a>  multiset::size

Retorna o número de elementos no multiset.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento atual do multiset.

### <a name="example"></a>Exemplo

```cpp
// multiset_size.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int> :: size_type i;

   ms1.insert( 1 );
   i = ms1.size( );
   cout << "The multiset length is " << i << "." << endl;

   ms1.insert( 2 );
   i = ms1.size( );
   cout << "The multiset length is now " << i << "." << endl;
}
```

```Output
The multiset length is 1.
The multiset length is now 2.
```

## <a name="size_type"></a>  multiset::size_type

Um tipo de inteiro sem sinal que pode representar o número de elementos em um multiset.

```cpp
typedef typename allocator_type::size_type size_type;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) para obter um exemplo de como declarar e usar `size_type`

## <a name="swap"></a>  multiset::swap

Troca os elementos de dois multisets.

```cpp
void swap(
    multiset<Key, Compare, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
 O multiset do argumento que fornece os elementos a serem trocados com o multiset de destino.

### <a name="remarks"></a>Comentários

A função membro não invalida referências, ponteiros ou iteradores que designam elementos nos dois multisets cujos elementos são trocados.

### <a name="example"></a>Exemplo

```cpp
// multiset_swap.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1, ms2, ms3;
   multiset <int>::iterator ms1_Iter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );
   ms2.insert( 100 );
   ms2.insert( 200 );
   ms3.insert( 300 );

   cout << "The original multiset ms1 is:";
   for ( ms1_Iter = ms1.begin( ); ms1_Iter != ms1.end( ); ms1_Iter++ )
      cout << " " << *ms1_Iter;
   cout << "." << endl;

   // This is the member function version of swap
   ms1.swap( ms2 );

   cout << "After swapping with ms2, list ms1 is:";
   for ( ms1_Iter = ms1.begin( ); ms1_Iter != ms1.end( ); ms1_Iter++ )
      cout << " " << *ms1_Iter;
   cout << "." << endl;

   // This is the specialized template version of swap
   swap( ms1, ms3 );

   cout << "After swapping with ms3, list ms1 is:";
   for ( ms1_Iter = ms1.begin( ); ms1_Iter != ms1.end( ); ms1_Iter++ )
      cout << " " << *ms1_Iter;
   cout   << "." << endl;
}
```

```Output
The original multiset ms1 is: 10 20 30.
After swapping with ms2, list ms1 is: 100 200.
After swapping with ms3, list ms1 is: 300.
```

## <a name="upper_bound"></a>  multiset::upper_bound

Retorna um iterador para o primeiro elemento em um multiset com uma chave que é maior que uma chave especificada.

```cpp
const_iterator upper_bound(const Key& key) const;

iterator upper_bound(const Key& key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
 A chave do argumento a ser comparada com a chave de classificação de um elemento do multiset que está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um **iterador** ou `const_iterator` que tratará a localização de um elemento em um multiset com uma chave, que é maior que a chave de argumento ou que tratará o local após o último elemento no multiset se nenhuma correspondência for encontrada para a chave.

### <a name="example"></a>Exemplo

```cpp
// multiset_upper_bound.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int> :: const_iterator ms1_AcIter, ms1_RcIter;

   ms1.insert( 10 );
   ms1.insert( 20 );
   ms1.insert( 30 );

   ms1_RcIter = ms1.upper_bound( 20 );
   cout << "The first element of multiset ms1 with a key greater "
           << "than 20 is: " << *ms1_RcIter << "." << endl;

   ms1_RcIter = ms1.upper_bound( 30 );

   // If no match is found for the key, end( ) is returned
   if ( ms1_RcIter == ms1.end( ) )
      cout << "The multiset ms1 doesn't have an element "
              << "with a key greater than 30." << endl;
   else
      cout << "The element of multiset ms1 with a key > 40 is: "
           << *ms1_RcIter << "." << endl;

   // The element at a specific location in the multiset can be
   // found using a dereferenced iterator addressing the location
   ms1_AcIter = ms1.begin( );
   ms1_RcIter = ms1.upper_bound( *ms1_AcIter );
   cout << "The first element of ms1 with a key greater than"
        << endl << "that of the initial element of ms1 is: "
        << *ms1_RcIter << "." << endl;
}
```

```Output
The first element of multiset ms1 with a key greater than 20 is: 30.
The multiset ms1 doesn't have an element with a key greater than 30.
The first element of ms1 with a key greater than
that of the initial element of ms1 is: 20.
```

## <a name="value_comp"></a>  multiset::value_comp

Recupera uma cópia do objeto de comparação usada para ordenar valores de elemento em um multiset.

```cpp
value_compare value_comp() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o objeto de função que um multiset usa para ordenar seus elementos, que é o parâmetro de modelo `Compare`.

Para obter mais informações sobre `Compare`, consulte a seção Comentários do tópico [Classe multiset](../standard-library/multiset-class.md).

### <a name="remarks"></a>Comentários

O objeto armazenado define a função membro:

**bool operator**( **const Key&**`_xVal`, **const Key&**`_yVal`);

que retornará true se `_xVal` preceder e não for igual a `_yVal` na ordem de classificação.

Observe que [key_compare](#key_compare) e [value_compare](#value_compare) são sinônimos do parâmetro de modelo `Compare`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

### <a name="example"></a>Exemplo

```cpp
// multiset_value_comp.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;

   multiset <int, less<int> > ms1;
   multiset <int, less<int> >::value_compare vc1 = ms1.value_comp( );
   bool result1 = vc1( 2, 3 );
   if( result1 == true )
   {
      cout << "vc1( 2,3 ) returns value of true, "
           << "where vc1 is the function object of ms1."
           << endl;
   }
   else
   {
      cout << "vc1( 2,3 ) returns value of false, "
           << "where vc1 is the function object of ms1."
           << endl;
   }

   set <int, greater<int> > ms2;
   set<int, greater<int> >::value_compare vc2 = ms2.value_comp( );
   bool result2 = vc2( 2, 3 );
   if( result2 == true )
   {
      cout << "vc2( 2,3 ) returns value of true, "
           << "where vc2 is the function object of ms2."
           << endl;
   }
   else
   {
      cout << "vc2( 2,3 ) returns value of false, "
           << "where vc2 is the function object of ms2."
           << endl;
   }
}
```

```Output
vc1( 2,3 ) returns value of true, where vc1 is the function object of ms1.
vc2( 2,3 ) returns value of false, where vc2 is the function object of ms2.
```

## <a name="value_compare"></a>  multiset::value_compare

Um tipo que fornece um objeto de função que pode comparar duas chaves de classificação para determinar sua ordem relativa no multiset.

```cpp
typedef key_compare value_compare;
```

### <a name="remarks"></a>Comentários

`value_compare` é um sinônimo do parâmetro de modelo `Compare`.

Observe que ambos [key_compare](#key_compare) e `value_compare` são sinônimos do parâmetro de modelo `Compare`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

Para obter mais informações sobre `Compare`, consulte a seção Comentários do tópico [Classe multiset](../standard-library/multiset-class.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [value_comp](#value_comp) para obter um exemplo de como declarar e usar `value_compare`.

## <a name="value_type"></a>  multiset::value_type

Um tipo que descreve um objeto armazenado como um elemento como um multiset em sua capacidade como um valor.

```cpp
typedef Key value_type;
```

### <a name="remarks"></a>Comentários

`value_type` é um sinônimo do parâmetro de modelo `Key`.

Observe que ambos [key_type](#key_type) e `value_type` são sinônimos do parâmetro de modelo `Key`. Os dois tipos são fornecidos para as classes set e multiset, em que são idênticos, para compatibilidade com as classes map e multimap, em que são diferentes.

Para obter mais informações sobre `Key`, consulte a seção Comentários do tópico.

### <a name="example"></a>Exemplo

```cpp
// multiset_value_type.cpp
// compile with: /EHsc
#include <set>
#include <iostream>

int main( )
{
   using namespace std;
   multiset <int> ms1;
   multiset <int>::iterator ms1_Iter;

   multiset <int> :: value_type svt_Int;   // Declare value_type
   svt_Int = 10;             // Initialize value_type

   multiset <int> :: key_type skt_Int;   // Declare key_type
   skt_Int = 20;             // Initialize key_type

   ms1.insert( svt_Int );         // Insert value into s1
   ms1.insert( skt_Int );         // Insert key into s1

   // A multiset accepts key_types or value_types as elements
   cout << "The multiset has elements:";
   for ( ms1_Iter = ms1.begin( ) ; ms1_Iter != ms1.end( ); ms1_Iter++ )
      cout << " " << *ms1_Iter;
   cout << "." << endl;
}
```

```Output
The multiset has elements: 10 20.
```

## <a name="see-also"></a>Consulte também

[\<Definir > membros](https://msdn.microsoft.com/0c2d57c0-173f-4204-b579-c5f06aad8b95)<br/>
[Contêineres](../cpp/containers-modern-cpp.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
