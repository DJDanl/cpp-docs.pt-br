---
title: Classe de pilha
ms.date: 11/04/2016
f1_keywords:
- stack/std::stack::container_type
- stack/std::stack::size_type
- stack/std::stack::value_type
- stack/std::stack::empty
- stack/std::stack::pop
- stack/std::stack::push
- stack/std::stack::size
- stack/std::stack::top
helpviewer_keywords:
- std::stack [C++], container_type
- std::stack [C++], size_type
- std::stack [C++], value_type
- std::stack [C++], empty
- std::stack [C++], pop
- std::stack [C++], push
- std::stack [C++], size
- std::stack [C++], top
ms.assetid: 02151c1e-eab0-41b8-be94-a839ead78ecf
ms.openlocfilehash: 36074f75830f92ba3fb9e5edb4e1507aa5ae1407
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68241061"
---
# <a name="stack-class"></a>Classe de pilha

Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade que limita o acesso ao elemento mais recentemente adicionado a alguns tipos de contêiner subjacentes. A classe stack é usada quando é importante esclarecer que apenas as operações de pilha estão sendo executadas no contêiner.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type, class Container= deque <Type>>
class stack
```

### <a name="parameters"></a>Parâmetros

*Tipo*\
O tipo de dados do elemento a ser armazenado na stack.

*Contêiner*\
O tipo do contêiner subjacente usado para implementar a stack. O valor padrão é a classe `deque` *\<Type>* .

## <a name="remarks"></a>Comentários

Os elementos da classe `Type` estipulados no primeiro modelo de parâmetro de um objeto stack são sinônimo [value_type](#value_type) e deve corresponder ao tipo de elemento na classe de contêiner subjacente `Container` estipulado pela segundo parâmetro de modelo. O `Type` deve ser atribuível, para que seja possível copiar objetos desse tipo e atribuir valores às variáveis desse tipo.

Classes de contêiner subjacente adequadas para pilha incluem [deque](../standard-library/deque-class.md), [classe list](../standard-library/list-class.md), e [classe vector](../standard-library/vector-class.md), ou qualquer outro contêiner de sequência que dá suporte a operações do `back`, `push_back`, e `pop_back`. A classe de contêiner subjacente é encapsulada dentro do adaptador do contêiner, que expõe apenas o conjunto limitado de funções membro de contêiner de sequência como uma interface pública.

A pilha de objetos será igualdade comparável somente se os elementos da classe `Type` são comparáveis a igualdade e são menos-que somente se os elementos da classe `Type` são menores-que comparável.

- A classe stack dá suporte a uma estrutura de dados UEPS (último a entrar, primeiro a sair). Uma boa comparação é pensar em uma pilha de pratos. Os elementos (os pratos) podem inseridos, inspecionados ou removidos somente da parte superior da pilha, que é o último elemento no final do contêiner base. A restrição para acessar apenas o elemento superior é o motivo para usar a classe stack.

- A [classe queue](../standard-library/queue-class.md) dá suporte a uma estrutura de dados PEPS (primeiro a entrar, primeiro a sair). Uma boa comparação é pensar em uma fila de banco. Os elementos (as pessoas) vão sendo adicionados na parte final da fila e são removidos do início dela. Tanto o início quanto o final da fila podem ser inspecionados. A restrição de acessar apenas os elementos inicial e final dessa maneira é o motivo para usar a classe queue.

- A [classe priority_queue](../standard-library/priority-queue-class.md) ordena seus elementos para que o elemento maior sempre esteja na posição superior. Ele dá suporte à inserção de um elemento e a inspeção e remoção do elemento superior. Uma boa comparação é pensar em pessoas em fila organizadas por idade, altura ou algum outro critério.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[stack](#stack)|Constrói um `stack` que é vazio ou que é uma cópia de um objeto de contêiner base.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[container_type](#container_type)|Um tipo que fornece o contêiner base para ser adaptado por um `stack`.|
|[size_type](#size_type)|Um tipo de inteiro sem sinal que pode representar o número de elementos em um `stack`.|
|[value_type](#value_type)|Um tipo que representa o tipo de objeto armazenado como um elemento em um `stack`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[empty](#empty)|Testa se `stack` está vazio.|
|[pop](#pop)|Remove o elemento da parte superior do `stack`.|
|[push](#push)|Adiciona um elemento ao topo do `stack`.|
|[size](#size)|Retorna o número de elementos no `stack`.|
|[top](#top)|Retorna uma referência a um elemento na parte superior do `stack`.|

## <a name="container_type"></a> container_type

Um tipo que fornece o contêiner base a ser adaptado.

```cpp
typedef Container container_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Container`. Todas as três classes de contêiner da sequência da Biblioteca Padrão C++ – a classe vector, a classe list e a classe padrão deque – atendem aos requisitos para serem usadas como o contêiner base para um objeto stack. Tipos definidos pelo usuário que satisfazem esses requisitos também podem ser usados.

Para obter mais informações sobre `Container`, consulte a seção Comentários do tópico [Classe stack](../standard-library/stack-class.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [stack::stack](#stack) para obter um exemplo de como declarar e usar `container_type`.

## <a name="empty"></a> vazio

Testa se uma stack está vazia.

```cpp
bool empty() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se a stack estiver vazia; **false** se a stack não estiver vazia.

### <a name="example"></a>Exemplo

```cpp
// stack_empty.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   // Declares stacks with default deque base container
   stack <int> s1, s2;

   s1.push( 1 );

   if ( s1.empty( ) )
      cout << "The stack s1 is empty." << endl;
   else
      cout << "The stack s1 is not empty." << endl;

   if ( s2.empty( ) )
      cout << "The stack s2 is empty." << endl;
   else
      cout << "The stack s2 is not empty." << endl;
}
```

```Output
The stack s1 is not empty.
The stack s2 is empty.
```

## <a name="pop"></a> pop

Remove o elemento da parte superior da stack.

```cpp
void pop();
```

### <a name="remarks"></a>Comentários

A stack não pode estar vazia para que seja possível aplicar a função membro. O início da stack é a posição ocupada pelo elemento adicionado mais recentemente e é o último elemento no fim do contêiner.

### <a name="example"></a>Exemplo

```cpp
// stack_pop.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   stack <int> s1, s2;

   s1.push( 10 );
   s1.push( 20 );
   s1.push( 30 );

   stack <int>::size_type i;
   i = s1.size( );
   cout << "The stack length is " << i << "." << endl;

   i = s1.top( );
   cout << "The element at the top of the stack is "
        << i << "." << endl;

   s1.pop( );

   i = s1.size( );
   cout << "After a pop, the stack length is "
        << i << "." << endl;

   i = s1.top( );
   cout << "After a pop, the element at the top of the stack is "
        << i << "." << endl;
}
```

```Output
The stack length is 3.
The element at the top of the stack is 30.
After a pop, the stack length is 2.
After a pop, the element at the top of the stack is 20.
```

## <a name="push"></a> envio por push

Adiciona um elemento na parte superior da pilha.

```cpp
void push(const Type& val);
```

### <a name="parameters"></a>Parâmetros

*Val*\
O elemento adicionado à parte superior da stack.

### <a name="remarks"></a>Comentários

O início da stack é a posição ocupada pelo elemento adicionado mais recentemente e é o último elemento no fim do contêiner.

### <a name="example"></a>Exemplo

```cpp
// stack_push.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   stack <int> s1;

   s1.push( 10 );
   s1.push( 20 );
   s1.push( 30 );

   stack <int>::size_type i;
   i = s1.size( );
   cout << "The stack length is " << i << "." << endl;

   i = s1.top( );
   cout << "The element at the top of the stack is "
        << i << "." << endl;
}
```

```Output
The stack length is 3.
The element at the top of the stack is 30.
```

## <a name="size"></a> Tamanho

Retorna o número de elementos na stack.

```cpp
size_type size() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento atual da stack.

### <a name="example"></a>Exemplo

```cpp
// stack_size.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   stack <int> s1, s2;
   stack <int>::size_type i;

   s1.push( 1 );
   i = s1.size( );
   cout << "The stack length is " << i << "." << endl;

   s1.push( 2 );
   i = s1.size( );
   cout << "The stack length is now " << i << "." << endl;
}
```

```Output
The stack length is 1.
The stack length is now 2.
```

## <a name="size_type"></a> size_type

Um tipo de inteiro sem sinal que pode representar o número de elementos em uma stack.

```cpp
typedef typename Container::size_type size_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `size_type` do contêiner base adaptado pela stack.

### <a name="example"></a>Exemplo

Veja o exemplo de [size](#size) que demonstra como declarar e usar `size_type`.

## <a name="stack"></a> Pilha

Constrói uma stack que é vazia ou que é uma cópia de uma classe de contêiner base.

```cpp
stack();

explicit stack(const container_type& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O contêiner do qual a stack construída será uma cópia.

### <a name="example"></a>Exemplo

```cpp
// stack_stack.cpp
// compile with: /EHsc
#include <stack>
#include <vector>
#include <list>
#include <iostream>

int main( )
{
   using namespace std;

   // Declares stack with default deque base container
   stack <char> dsc1;

   //Explicitly declares a stack with deque base container
   stack <char, deque<char> > dsc2;

   // Declares a stack with vector base containers
   stack <int, vector<int> > vsi1;

   // Declares a stack with list base container
   stack <int, list<int> > lsi;

   // The second member function copies elements from a container
   vector<int> v1;
   v1.push_back( 1 );
   stack <int, vector<int> > vsi2( v1 );
   cout << "The element at the top of stack vsi2 is "
        << vsi2.top( ) << "." << endl;
}
```

```Output
The element at the top of stack vsi2 is 1.
```

## <a name="top"></a> Início

Retorna uma referência a um elemento na parte superior da stack.

```cpp
reference top();

const_reference top() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao último elemento no contêiner na parte superior da stack.

### <a name="remarks"></a>Comentários

A stack não pode estar vazia para que seja possível aplicar a função membro. O início da stack é a posição ocupada pelo elemento adicionado mais recentemente e é o último elemento no fim do contêiner.

Se o valor de retorno `top` for atribuído a um `const_reference`, o objeto stack não pode ser modificado. Se o valor de retorno `top` for atribuído a um `reference`, o objeto stack poderá ser modificado.

### <a name="example"></a>Exemplo

```cpp
// stack_top.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   stack <int> s1;

   s1.push( 1 );
   s1.push( 2 );

   int& i = s1.top( );
   const int& ii = s1.top( );

   cout << "The top integer of the stack s1 is "
        << i << "." << endl;
   i--;
   cout << "The next integer down is "<< ii << "." << endl;
}
```

```Output
The top integer of the stack s1 is 2.
The next integer down is 1.
```

## <a name="value_type"></a> value_type

Um tipo que representa o tipo de objeto armazenado como um elemento em uma stack.

```cpp
typedef typename Container::value_type value_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `value_type` do contêiner base adaptado pela stack.

### <a name="example"></a>Exemplo

```cpp
// stack_value_type.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   // Declares stacks with default deque base container
   stack<int>::value_type AnInt;

   AnInt = 69;
   cout << "The value_type is AnInt = " << AnInt << endl;

   stack<int> s1;
   s1.push( AnInt );
   cout << "The element at the top of the stack is "
        << s1.top( ) << "." << endl;
}
```

```Output
The value_type is AnInt = 69
The element at the top of the stack is 69.
```

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
