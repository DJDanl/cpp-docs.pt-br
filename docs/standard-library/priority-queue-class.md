---
title: Classe priority_queue
ms.date: 11/04/2016
f1_keywords:
- queue/std::priority_queue::container_type
- queue/std::priority_queue::size_type
- queue/std::priority_queue::value_type
- queue/std::priority_queue::empty
- queue/std::priority_queue::pop
- queue/std::priority_queue::push
- queue/std::priority_queue::size
- queue/std::priority_queue::top
helpviewer_keywords:
- std::priority_queue [C++], container_type
- std::priority_queue [C++], size_type
- std::priority_queue [C++], value_type
- std::priority_queue [C++], empty
- std::priority_queue [C++], pop
- std::priority_queue [C++], push
- std::priority_queue [C++], size
- std::priority_queue [C++], top
ms.assetid: 69fca9cc-a449-4be4-97b7-02ca5db9cbb2
ms.openlocfilehash: 8a1b33e45d066082a0f225067db84a6240e8fc53
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232944"
---
# <a name="priority_queue-class"></a>Classe priority_queue

Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para limitar o acesso ao elemento superior de algum tipo de contêiner subjacente, que sempre é o maior ou a prioridade mais alta. Novos elementos podem ser adicionados ao priority_queue e o elemento superior do priority_queue pode ser inspecionado ou removido.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type, class Container= vector <Type>, class Compare= less <typename Container ::value_type>>
class priority_queue
```

### <a name="parameters"></a>parâmetros

*Escreva*\
O tipo de dados do elemento a ser armazenado no priority_queue.

*Container*\
O tipo do contêiner subjacente usado para implementar o priority_queue.

*Comparar*\
O tipo que fornece um objeto de função que pode comparar dois valores de elemento como chaves de classificação para determinar sua ordem relativa no priority_queue. Esse argumento é opcional e o predicado binário `less<typename Container::value_type>` é o valor padrão.

## <a name="remarks"></a>Comentários

Os elementos da classe `Type` estipulados no primeiro parâmetro de modelo de um objeto de fila são sinônimos de [value_type](#value_type) e devem corresponder ao tipo de elemento na classe de contêiner subjacente `Container` estipulada pelo segundo parâmetro de modelo. O `Type` deve ser atribuível, para que seja possível copiar objetos desse tipo e atribuir valores a variáveis desse tipo.

O priority_queue ordena a sequência que ele controla chamando um objeto de função armazenado da classe `Traits` . De modo geral, os elementos precisam ser simplesmente menores que os comparáveis para estabelecer essa ordem: desse modo, considerando dois elementos, pode ser determinado que, ou eles são equivalentes (no sentido de que nenhum deles é menor que o outro), ou que um é menor que o outro. Isso resulta em uma ordenação entre os elementos não equivalentes. Fazendo uma observação mais técnica, a função de comparação é um predicado binário que induz a uma ordenação fraca restrita no sentido matemático padrão.

As classes de contêiner subjacentes adequadas para priority_queue incluem a [Classe deque](../standard-library/deque-class.md) e a [Classe vector](../standard-library/vector-class.md) padrão ou qualquer outro contêiner de sequência que dá suporte às operações de `front`, `push_back` e `pop_back`, e um iterador de acesso aleatório. A classe de contêiner subjacente é encapsulada dentro do adaptador do contêiner, que expõe apenas o conjunto limitado de funções membro de contêiner de sequência como uma interface pública.

Adicionar e remover elementos de um `priority_queue` apresenta complexidade logarítmica. Acessar elementos em um `priority_queue` apresenta uma complexidade constante.

Há três tipos de adaptadores de contêiner definidos pela Biblioteca Padrão C++: stack, queue e priority_queue. Cada um deles restringe a funcionalidade de uma classe de contêiner subjacente para fornecer uma interface com precisão controlada a uma estrutura de dados padrão.

- A [classe Stack](../standard-library/stack-class.md) dá suporte a uma estrutura de dados de UEPS (última entrada, primeiro a sair). Uma boa comparação é pensar em uma pilha de pratos. Os elementos (os pratos) podem inseridos, inspecionados ou removidos somente da parte superior da pilha, que é o último elemento no final do contêiner base. A restrição para acessar apenas o elemento superior é o motivo para usar a classe stack.

- A [classe Queue](../standard-library/queue-class.md) dá suporte a uma estrutura de dados FIFO (primeiro a entrar, primeiro a sair). Uma boa comparação é pensar em uma fila de banco. Os elementos (as pessoas) vão sendo adicionados na parte final da fila e são removidos do início dela. Tanto o início quanto o final da fila podem ser inspecionados. A restrição de acessar apenas os elementos inicial e final dessa maneira é o motivo para usar a classe queue.

- A classe priority_queue ordena seus elementos para que o elemento maior sempre esteja na posição superior. Ele dá suporte à inserção de um elemento e a inspeção e remoção do elemento superior. Uma boa comparação é pensar em pessoas em fila organizadas por idade, altura ou algum outro critério.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[priority_queue](#priority_queue)|Constrói um `priority_queue` que é vazio ou que é uma cópia de um intervalo de um objeto de contêiner base ou de outro `priority_queue`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[container_type](#container_type)|Um tipo que fornece o contêiner base para ser adaptado por um `priority_queue`.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `priority_queue`.|
|[value_type](#value_type)|Um tipo que representa o tipo de objeto armazenado como um elemento em um `priority_queue`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[empty](#empty)|Testa se `priority_queue` está vazio.|
|[pop](#pop)|Remove o maior elemento de `priority_queue` da posição superior.|
|[push](#push)|Adiciona um elemento à fila de prioridade com base na prioridade do elemento de operator<.|
|[size](#size)|Retorna o número de elementos no `priority_queue`.|
|[início](#top)|Retorna uma referência const ao maior elemento na parte superior de `priority_queue`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<queue>

**Namespace:** std

## <a name="priority_queuecontainer_type"></a><a name="container_type"></a>priority_queue:: container_type

Um tipo que fornece o contêiner base a ser adaptado.

```cpp
typedef Container container_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Container`. A classe de contêiner da sequência da Biblioteca Padrão C++ `deque` e a classe `vector` padrão atendem aos requisitos para serem usadas como o contêiner base para um objeto priority_queue. Tipos definidos pelo usuário que satisfazem os requisitos também podem ser usados.

Para obter mais informações sobre `Container`, consulte a seção Comentários do tópico [Classe priority_queue](../standard-library/priority-queue-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [priority_queue](#priority_queue) para saber como declarar e usar `container_type`.

## <a name="priority_queueempty"></a><a name="empty"></a>priority_queue:: Empty

Testa se um priority_queue está vazio.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o priority_queue estiver vazio; **`false`** se o priority_queue não estiver vazio.

### <a name="example"></a>Exemplo

```cpp
// pqueue_empty.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares priority_queues with default deque base container
   priority_queue <int> q1, s2;

   q1.push( 1 );

   if ( q1.empty( ) )
      cout << "The priority_queue q1 is empty." << endl;
   else
      cout << "The priority_queue q1 is not empty." << endl;

   if ( s2.empty( ) )
      cout << "The priority_queue s2 is empty." << endl;
   else
      cout << "The priority_queue s2 is not empty." << endl;
}
```

```Output
The priority_queue q1 is not empty.
The priority_queue s2 is empty.
```

## <a name="priority_queuepop"></a><a name="pop"></a>priority_queue::p op

Remove o maior elemento da priority_queue da posição superior.

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

A priority_queue deve ser não vazia para aplicar a função membro. A parte superior do priority_queue sempre está ocupada pelo maior elemento no contêiner.

### <a name="example"></a>Exemplo

```cpp
// pqueue_pop.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   priority_queue <int> q1, s2;

   q1.push( 10 );
   q1.push( 20 );
   q1.push( 30 );

   priority_queue <int>::size_type i, iii;
   i = q1.size( );
   cout << "The priority_queue length is " << i << "." << endl;

   const int& ii = q1.top( );
   cout << "The element at the top of the priority_queue is "
        << ii << "." << endl;

   q1.pop( );

   iii = q1.size( );
   cout << "After a pop, the priority_queue length is "
        << iii << "." << endl;

   const int& iv = q1.top( );
   cout << "After a pop, the element at the top of the "
        << "priority_queue is " << iv << "." << endl;
}
```

```Output
The priority_queue length is 3.
The element at the top of the priority_queue is 30.
After a pop, the priority_queue length is 2.
After a pop, the element at the top of the priority_queue is 20.
```

## <a name="priority_queuepriority_queue"></a><a name="priority_queue"></a>priority_queue::p riority_queue

Constrói um priority_queue que é vazio ou que é uma cópia de um intervalo de um objeto de contêiner base ou de outro priority_queue.

```cpp
priority_queue();

explicit priority_queue(const Traits& _comp);

priority_queue(const Traits& _comp, const container_type& _Cont);

priority_queue(const priority_queue& right);

template <class InputIterator>
priority_queue(InputIterator first, InputIterator last);

template <class InputIterator>
priority_queue(InputIterator first, InputIterator last, const Traits& _comp);

template <class InputIterator>
priority_queue(InputIterator first, InputIterator last, const Traits& _comp, const container_type& _Cont);
```

### <a name="parameters"></a>parâmetros

*_comp*\
A função de comparação do tipo **constTraits** usado para ordenar os elementos no priority_queue, cujo padrão é a função de comparação do contêiner base.

*_Cont*\
O contêiner base do qual o priority_queue construído será uma cópia.

*Certo*\
A priority_queue da qual o conjunto construído será uma cópia.

*primeiro*\
A posição do primeiro elemento no intervalo de elementos a serem copiados.

*última*\
A posição do primeiro elemento além do intervalo de elementos a serem copiados.

### <a name="remarks"></a>Comentários

Cada um dos três primeiros construtores especifica um priority_queue inicial vazio, o segundo também especifica o tipo de função de comparação ( `comp` ) a ser usado no estabelecimento da ordem dos elementos e o terceiro que especificam explicitamente o `container_type` ( `_Cont` ) a ser usado. A palavra-chave **`explicit`** suprime determinados tipos de conversão automática de tipo.

O quarto construtor Especifica uma cópia do priority_queue *direito*.

Os últimos três construtores copiam o intervalo \[ *primeiro*, o *último*) de algum contêiner e usam os valores para inicializar um priority_queue com maior explícito ao especificar o tipo de função de comparação da classe `Traits` e `container_type` .

### <a name="example"></a>Exemplo

```cpp
// pqueue_ctor.cpp
// compile with: /EHsc
#include <queue>
#include <vector>
#include <deque>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // The first member function declares priority_queue
   // with a default vector base container
   priority_queue <int> q1;
   cout << "q1 = ( ";
   while ( !q1.empty( ) )
   {
      cout << q1.top( ) << " ";
      q1.pop( );
   }
   cout << ")" << endl;

   // Explicitly declares a priority_queue with nondefault
   // deque base container
   priority_queue <int, deque <int> > q2;
   q2.push( 5 );
   q2.push( 15 );
   q2.push( 10 );
   cout << "q2 = ( ";
   while ( !q2.empty( ) )
   {
      cout << q2.top( ) << " ";
      q2.pop( );
   }
   cout << ")" << endl;

   // This method of printing out the elements of a priority_queue
   // removes the elements from the priority queue, leaving it empty
   cout << "After printing, q2 has " << q2.size( ) << " elements." << endl;

   // The third member function declares a priority_queue
   // with a vector base container and specifies that the comparison
   // function greater is to be used for ordering elements
   priority_queue <int, vector<int>, greater<int> > q3;
   q3.push( 2 );
   q3.push( 1 );
   q3.push( 3 );
   cout << "q3 = ( ";
   while ( !q3.empty( ) )
   {
      cout << q3.top( ) << " ";
      q3.pop( );
   }
   cout << ")" << endl;

   // The fourth member function declares a priority_queue and
   // initializes it with elements copied from another container:
   // first, inserting elements into q1, then copying q1 elements into q4
   q1.push( 100 );
   q1.push( 200 );
   priority_queue <int> q4( q1 );
   cout << "q4 = ( ";
   while ( !q4.empty( ) )
   {
      cout << q4.top( ) << " ";
      q4.pop( );
   }
   cout << ")" << endl;

   // Creates an auxiliary vector object v5 to be used to initialize q5
   vector <int> v5;
   vector <int>::iterator v5_Iter;
   v5.push_back( 10 );
   v5.push_back( 30 );
   v5.push_back( 20 );
   cout << "v5 = ( " ;
   for ( v5_Iter = v5.begin( ) ; v5_Iter != v5.end( ) ; v5_Iter++ )
      cout << *v5_Iter << " ";
   cout << ")" << endl;

   // The fifth member function declares and
   // initializes a priority_queue q5 by copying the
   // range v5[ first,  last) from vector v5
   priority_queue <int> q5( v5.begin( ), v5.begin( ) + 2 );
   cout << "q5 = ( ";
   while ( !q5.empty( ) )
   {
      cout << q5.top( ) << " ";
      q5.pop( );
   }
   cout << ")" << endl;

   // The sixth member function declares a priority_queue q6
   // with a comparison function greater and initializes q6
   // by copying the range v5[ first,  last) from vector v5
   priority_queue <int, vector<int>, greater<int> >
      q6( v5.begin( ), v5.begin( ) + 2 );
   cout << "q6 = ( ";
   while ( !q6.empty( ) )
   {
      cout << q6.top( ) << " ";
      q6.pop( );
   }
   cout << ")" << endl;
}
```

## <a name="priority_queuepush"></a><a name="push"></a>priority_queue::p USH

Adiciona um elemento à fila de prioridade com base na prioridade do elemento de operator<.

```cpp
void push(const Type& val);
```

### <a name="parameters"></a>parâmetros

*Val*\
O elemento adicionado à parte superior da priority_queue.

### <a name="remarks"></a>Comentários

A parte superior do priority_queue é a posição ocupada pelo maior elemento no contêiner.

### <a name="example"></a>Exemplo

```cpp
// pqueue_push.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   priority_queue<int> q1;

   q1.push( 10 );
   q1.push( 30 );
   q1.push( 20 );

   priority_queue<int>::size_type i;
   i = q1.size( );
   cout << "The priority_queue length is " << i << "." << endl;

   const int& ii = q1.top( );
   cout << "The element at the top of the priority_queue is "
        << ii << "." << endl;
}
```

```Output
The priority_queue length is 3.
The element at the top of the priority_queue is 30.
```

## <a name="priority_queuesize"></a><a name="size"></a>priority_queue:: tamanho

Retorna o número de elementos na priority_queue.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho atual do priority_queue.

### <a name="example"></a>Exemplo

```cpp
// pqueue_size.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   priority_queue <int> q1, q2;
   priority_queue <int>::size_type i;

   q1.push( 1 );
   i = q1.size( );
   cout << "The priority_queue length is " << i << "." << endl;

   q1.push( 2 );
   i = q1.size( );
   cout << "The priority_queue length is now " << i << "." << endl;
}
```

```Output
The priority_queue length is 1.
The priority_queue length is now 2.
```

## <a name="priority_queuesize_type"></a><a name="size_type"></a>priority_queue:: size_type

Um tipo de inteiro sem sinal que pode representar o número de elementos em um priority_queue.

```cpp
typedef typename Container::size_type size_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do `size_type` do contêiner base adaptado pelo priority_queue.

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) que demonstra como declarar e usar `size_type`.

## <a name="priority_queuetop"></a><a name="top"></a>priority_queue:: Top

Retorna uma referência const para o maior elemento na parte superior do priority_queue.

```cpp
const_reference top() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao elemento maior, conforme determinado pela `Traits` função, objeto do priority_queue.

### <a name="remarks"></a>Comentários

A priority_queue deve ser não vazia para aplicar a função membro.

### <a name="example"></a>Exemplo

```cpp
// pqueue_top.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;
   priority_queue<int> q1;

   q1.push( 10 );
   q1.push( 30 );
   q1.push( 20 );

   priority_queue<int>::size_type i;
   i = q1.size( );
   cout << "The priority_queue length is " << i << "." << endl;

   const int& ii = q1.top( );
   cout << "The element at the top of the priority_queue is "
        << ii << "." << endl;
}
```

```Output
The priority_queue length is 3.
The element at the top of the priority_queue is 30.
```

## <a name="priority_queuevalue_type"></a><a name="value_type"></a>priority_queue:: value_type

Um tipo que representa o tipo de objeto armazenado como um elemento em um priority_queue.

```cpp
typedef typename Container::value_type value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do `value_type` do contêiner base adaptado pelo priority_queue.

### <a name="example"></a>Exemplo

```cpp
// pqueue_value_type.cpp
// compile with: /EHsc
#include <queue>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares priority_queues with default deque base container
   priority_queue<int>::value_type AnInt;

   AnInt = 69;
   cout << "The value_type is AnInt = " << AnInt << endl;

   priority_queue<int> q1;
   q1.push( AnInt );
   cout << "The element at the top of the priority_queue is "
        << q1.top( ) << "." << endl;
}
```

```Output
The value_type is AnInt = 69
The element at the top of the priority_queue is 69.
```

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
