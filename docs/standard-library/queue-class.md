---
title: Classe queue
ms.date: 11/04/2016
f1_keywords:
- queue/std::queue::container_type
- queue/std::queue::size_type
- queue/std::queue::value_type
- queue/std::queue::back
- queue/std::queue::empty
- queue/std::queue::front
- queue/std::queue::pop
- queue/std::queue::push
- queue/std::queue::size
helpviewer_keywords:
- std::queue [C++], container_type
- std::queue [C++], size_type
- std::queue [C++], value_type
- std::queue [C++], back
- std::queue [C++], empty
- std::queue [C++], front
- std::queue [C++], pop
- std::queue [C++], push
- std::queue [C++], size
ms.assetid: 28c20ab0-3a72-4185-9e0f-5a44eea0e204
ms.openlocfilehash: 331ca298507e0ebecac0376f660feefdafd9d99d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232931"
---
# <a name="queue-class"></a>Classe queue

Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para algum tipo de contêiner subjacente, limitando o acesso aos elementos inicial e final. Elementos podem ser adicionados na parte final e removidos da parte inicial, bem como podem ser inspecionados em ambas as extremidades da fila.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type, class Container = deque <Type>>
class queue
```

### <a name="parameters"></a>parâmetros

*Escreva*\
O tipo de dados do elemento a ser armazenado na fila

*Container*\
O tipo do contêiner subjacente usado para implementar a fila.

## <a name="remarks"></a>Comentários

Os elementos da classe `Type` estipulados no primeiro parâmetro de modelo de um objeto de fila são sinônimos de [value_type](#value_type) e devem corresponder ao tipo de elemento na classe de contêiner subjacente `Container` estipulada pelo segundo parâmetro de modelo. O `Type` deve ser atribuível, para que seja possível copiar objetos desse tipo e atribuir valores a variáveis desse tipo.

As classes de contêiner subjacentes adequadas para a fila incluem [deque](../standard-library/deque-class.md) e [list](../standard-library/list-class.md), ou qualquer outro contêiner de sequência que ofereça suporte às operações do `front` , `back` , `push_back` e `pop_front` . A classe de contêiner subjacente é encapsulada dentro do adaptador do contêiner, que expõe apenas o conjunto limitado de funções membro de contêiner de sequência como uma interface pública.

Os objetos de fila são comparáveis de igualdade se e somente se os elementos da classe `Type` forem comparáveis de igualdade e forem menores que o comparável se e somente se os elementos da classe `Type` forem menores que o comparável.

Há três tipos de adaptadores de contêiner definidos pela Biblioteca Padrão C++: stack, queue e priority_queue. Cada um deles restringe a funcionalidade de uma classe de contêiner subjacente para fornecer uma interface com precisão controlada a uma estrutura de dados padrão.

- A [classe Stack](../standard-library/stack-class.md) dá suporte a uma estrutura de dados de UEPS (última entrada, primeiro a sair). Uma boa comparação é pensar em uma pilha de pratos. Os elementos (os pratos) podem inseridos, inspecionados ou removidos somente da parte superior da pilha, que é o último elemento no final do contêiner base. A restrição para acessar apenas o elemento superior é o motivo para usar a classe stack.

- A classe queue dá suporte a uma estrutura de dados PEPS (primeiro a entrar, primeiro a sair). Uma boa comparação é pensar em uma fila de banco. Os elementos (as pessoas) vão sendo adicionados na parte final da fila e são removidos do início dela. Tanto o início quanto o final da fila podem ser inspecionados. A restrição de acessar apenas os elementos inicial e final dessa maneira é o motivo para usar a classe queue.

- A [classe priority_queue](../standard-library/priority-queue-class.md) ordena seus elementos para que o elemento maior sempre esteja na posição superior. Ele dá suporte à inserção de um elemento e a inspeção e remoção do elemento superior. Uma boa comparação é pensar em pessoas em fila organizadas por idade, altura ou algum outro critério.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[Espera](#queue)|Constrói um `queue` que é vazio ou que é uma cópia de um objeto de contêiner base.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[container_type](#container_type)|Um tipo que fornece o contêiner base para ser adaptado pelo `queue`.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `queue`.|
|[value_type](#value_type)|Um tipo que representa o tipo de objeto armazenado como um elemento em um `queue`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[Voltar](#back)|Retorna uma referência para o último e recém-adicionado elemento na parte final de `queue`.|
|[empty](#empty)|Testa se `queue` está vazio.|
|[dianteiro](#front)|Retorna uma referência ao primeiro elemento na parte inicial de `queue`.|
|[pop](#pop)|Remove um elemento no início do `queue`.|
|[push](#push)|Adiciona um elemento na parte traseira do `queue`.|
|[size](#size)|Retorna o número de elementos no `queue`.|

## <a name="back"></a><a name="back"></a>Voltar

Retorna uma referência para o último e recém-adicionado elemento na parte final da fila.

```cpp
reference back();

const_reference back() const;
```

### <a name="return-value"></a>Valor retornado

O último elemento da fila. Se a fila estiver vazia, o valor retornado será indefinido.

### <a name="remarks"></a>Comentários

Se o valor retornado de `back` for atribuído a um `const_reference`, o objeto da fila não poderá ser modificado. Se o valor de retorno de `back` for atribuído a um `reference` , o objeto de fila poderá ser modificado.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento em uma fila vazia.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.

### <a name="example"></a>Exemplo

```cpp
// queue_back.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1;

   q1.push( 10 );
   q1.push( 11 );

   int& i = q1.back( );
   const int& ii = q1.front( );

   cout << "The integer at the back of queue q1 is " << i
        << "." << endl;
   cout << "The integer at the front of queue q1 is " << ii
        << "." << endl;
}
```

## <a name="container_type"></a><a name="container_type"></a>container_type

Um tipo que fornece o contêiner base a ser adaptado.

```cpp
typedef Container container_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Container`. Duas classes de contêiner da sequência da Biblioteca Padrão C++ — a classe list e a classe deque — atendem aos requisitos para serem usadas como o contêiner base para um objeto de fila. Tipos definidos pelo usuário que satisfazem os requisitos também podem ser usados.

Para obter mais informações sobre `Container`, consulte a seção Comentários do tópico [Classe queue](../standard-library/queue-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [queue](#queue) para saber como declarar e usar `container_type`.

## <a name="empty"></a><a name="empty"></a>esvaziá

Testa se uma fila está vazia.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** se a fila estiver vazia; **`false`** se a fila não estiver vazia.

### <a name="example"></a>Exemplo

```cpp
// queue_empty.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
using namespace std;

   // Declares queues with default deque base container
   queue <int> q1, q2;

   q1.push( 1 );

   if ( q1.empty( ) )
      cout << "The queue q1 is empty." << endl;
   else
      cout << "The queue q1 is not empty." << endl;

   if ( q2.empty( ) )
      cout << "The queue q2 is empty." << endl;
   else
      cout << "The queue q2 is not empty." << endl;
}
```

```Output
The queue q1 is not empty.
The queue q2 is empty.
```

## <a name="front"></a><a name="front"></a>dianteiro

Retorna uma referência ao primeiro elemento na parte inicial da fila.

```cpp
reference front();

const_reference front() const;
```

### <a name="return-value"></a>Valor retornado

O primeiro elemento da fila. Se a fila estiver vazia, o valor retornado será indefinido.

### <a name="remarks"></a>Comentários

Se o valor retornado de `front` for atribuído a um `const_reference`, o objeto da fila não poderá ser modificado. Se o valor de retorno de `front` for atribuído a um `reference` , o objeto de fila poderá ser modificado.

A função membro retorna um `reference` para o primeiro elemento da sequência controlada, que deve ser não vazio.

Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de runtime ocorrerá se você tentar acessar um elemento em uma fila vazia.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.

### <a name="example"></a>Exemplo

```cpp
// queue_front.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main() {
   using namespace std;
   queue <int> q1;

   q1.push( 10 );
   q1.push( 20 );
   q1.push( 30 );

   queue <int>::size_type i;
   i = q1.size( );
   cout << "The queue length is " << i << "." << endl;

   int& ii = q1.back( );
   int& iii = q1.front( );

   cout << "The integer at the back of queue q1 is " << ii
        << "." << endl;
   cout << "The integer at the front of queue q1 is " << iii
        << "." << endl;
}
```

## <a name="pop"></a><a name="pop"></a>pop

Remove um elemento no início da fila.

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

A fila não pode ser vazia para aplicar a função membro. O início da fila é a posição ocupada pelo elemento adicionado mais recentemente e é o último elemento no fim do contêiner.

### <a name="example"></a>Exemplo

```cpp
// queue_pop.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1, s2;

   q1.push( 10 );
   q1.push( 20 );
   q1.push( 30 );

   queue <int>::size_type i;
   i = q1.size( );
   cout << "The queue length is " << i << "." << endl;

   i = q1.front( );
   cout << "The element at the front of the queue is "
        << i << "." << endl;

   q1.pop( );

   i = q1.size( );
   cout << "After a pop the queue length is "
        << i << "." << endl;

   i = q1. front ( );
   cout << "After a pop, the element at the front of the queue is "
        << i << "." << endl;
}
```

```Output
The queue length is 3.
The element at the front of the queue is 10.
After a pop the queue length is 2.
After a pop, the element at the front of the queue is 20.
```

## <a name="push"></a><a name="push"></a>pressionado

Adiciona um elemento na parte final da fila.

```cpp
void push(const Type& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O elemento adicionado na parte final da fila.

### <a name="remarks"></a>Comentários

O fim da fila é a posição ocupada pelo elemento adicionado mais recentemente e é o último elemento no fim do contêiner.

### <a name="example"></a>Exemplo

```cpp
// queue_push.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1;

   q1.push( 10 );
   q1.push( 20 );
   q1.push( 30 );

   queue <int>::size_type i;
   i = q1.size( );
   cout << "The queue length is " << i << "." << endl;

   i = q1.front( );
   cout << "The element at the front of the queue is "
        << i << "." << endl;
}
```

```Output
The queue length is 3.
The element at the front of the queue is 10.
```

## <a name="queue"></a>Fila do <a name="queue"></a>

Constrói uma fila que é vazia ou que é uma cópia de um objeto de contêiner base.

```cpp
queue();

explicit queue(const container_type& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O **`const`** contêiner do qual a fila construída é uma cópia.

### <a name="remarks"></a>Comentários

O contêiner base padrão da fila é deque. Você também pode especificar a lista como um contêiner base, mas não é possível especificar o vetor, porque ele não tem a função membro `pop_front` necessária.

### <a name="example"></a>Exemplo

```cpp
// queue_queue.cpp
// compile with: /EHsc
#include <queue>
#include <vector>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares queue with default deque base container
   queue <char> q1;

   // Explicitly declares a queue with deque base container
   queue <char, deque<char> > q2;

   // These lines don't cause an error, even though they
   // declares a queue with a vector base container
   queue <int, vector<int> > q3;
   q3.push( 10 );
   // but the following would cause an error because vector has
   // no pop_front member function
   // q3.pop( );

   // Declares a queue with list base container
   queue <int, list<int> > q4;

   // The second member function copies elements from a container
   list<int> li1;
   li1.push_back( 1 );
   li1.push_back( 2 );
   queue <int, list<int> > q5( li1 );
   cout << "The element at the front of queue q5 is "
        << q5.front( ) << "." << endl;
   cout << "The element at the back of queue q5 is "
        << q5.back( ) << "." << endl;
}
```

```Output
The element at the front of queue q5 is 1.
The element at the back of queue q5 is 2.
```

## <a name="size"></a><a name="size"></a>tamanho

Retorna o número de elementos na fila.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho atual da fila.

### <a name="example"></a>Exemplo

```cpp
// queue_size.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   queue <int> q1, q2;
   queue <int>::size_type i;

   q1.push( 1 );
   i = q1.size( );
   cout << "The queue length is " << i << "." << endl;

   q1.push( 2 );
   i = q1.size( );
   cout << "The queue length is now " << i << "." << endl;
}
```

```Output
The queue length is 1.
The queue length is now 2.
```

## <a name="size_type"></a><a name="size_type"></a>size_type

Um tipo de inteiro sem sinal que pode representar o número de elementos em uma fila.

```cpp
typedef typename Container::size_type size_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do `size_type` do contêiner base adaptado pela fila.

### <a name="example"></a>Exemplo

Veja o exemplo de [queue::front](#front) para saber como declarar e usar `size_type`.

## <a name="value_type"></a><a name="value_type"></a>value_type

Um tipo que representa o tipo de objeto armazenado como um elemento em uma fila.

```cpp
typedef typename Container::value_type value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do `value_type` do contêiner base adaptado pela fila.

### <a name="example"></a>Exemplo

```cpp
// queue_value_type.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
using namespace std;

   // Declares queues with default deque base container
   queue<int>::value_type AnInt;

   AnInt = 69;
   cout << "The value_type is AnInt = " << AnInt << endl;

   queue<int> q1;
   q1.push(AnInt);
   cout << "The element at the front of the queue is "
        << q1.front( ) << "." << endl;
}
```

```Output
The value_type is AnInt = 69
The element at the front of the queue is 69.
```

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
