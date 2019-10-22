---
title: Classe allocator
ms.date: 11/04/2016
f1_keywords:
- memory/std::allocator
- memory/std::allocator::const_pointer
- memory/std::allocator::const_reference
- memory/std::allocator::difference_type
- memory/std::allocator::pointer
- memory/std::allocator::reference
- memory/std::allocator::size_type
- memory/std::allocator::value_type
- memory/std::allocator::address
- memory/std::allocator::allocate
- memory/std::allocator::construct
- memory/std::allocator::deallocate
- memory/std::allocator::destroy
- memory/std::allocator::max_size
- memory/std::allocator::rebind
helpviewer_keywords:
- std::allocator [C++]
- std::allocator [C++], const_pointer
- std::allocator [C++], const_reference
- std::allocator [C++], difference_type
- std::allocator [C++], pointer
- std::allocator [C++], reference
- std::allocator [C++], size_type
- std::allocator [C++], value_type
- std::allocator [C++], address
- std::allocator [C++], allocate
- std::allocator [C++], construct
- std::allocator [C++], deallocate
- std::allocator [C++], destroy
- std::allocator [C++], max_size
- std::allocator [C++], rebind
ms.assetid: 3fd58076-56cc-43bb-ad58-b4b7c9c6b410
ms.openlocfilehash: 8cd49051a25148c1c3289de9f0d7046ad27818c9
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72690079"
---
# <a name="allocator-class"></a>Classe allocator

O modelo de classe descreve um objeto que gerencia a alocação de armazenamento e a liberação de matrizes de objetos do tipo `Type`. Um objeto da classe `allocator` é o objeto de alocador padrão especificado nos construtores para vários modelos de classe de contêiner C++ na biblioteca padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator
```

### <a name="parameters"></a>Parâmetros

*Tipo* \
O tipo de objeto para o qual o armazenamento está sendo alocado ou desalocado.

## <a name="remarks"></a>Comentários

Todos os C++ contêineres de biblioteca padrão têm um parâmetro de modelo que usa como padrão `allocator`. Construir um contêiner com um alocador personalizado fornece controle sobre a alocação e a liberação dos elementos desse contêiner.

Por exemplo, um objeto alocador pode alocar armazenamento em um heap privado ou na memória compartilhada ou pode otimizar para tamanhos de objeto grandes ou pequenos. Ele também pode especificar, por meio das definições de tipo que fornece, que os elementos sejam acessados por meio de objetos acessadores especiais que gerenciam a memória compartilhada ou executam coleta de lixo automática. Portanto, uma classe que aloca armazenamento usando um objeto alocador deve usar esses tipos para declarar um ponteiro e referenciar objetos, como os contêineres na Biblioteca Padrão do C++.

<strong>(Somente C++ 98/03)</strong> Ao derivar da classe de alocador, você precisa fornecer um [reassociar](#rebind) struct, cujo typedef `_Other` faz referência à sua classe derivada recentemente.

Portanto, um alocador define os seguintes tipos:

- o [ponteiro](#pointer) se comporta como um ponteiro para `Type`.

- [const_pointer](#const_pointer) se comporta como um ponteiro const para `Type`.

- a [referência](#reference) se comporta como uma referência a `Type`.

- [const_reference](#const_reference) se comporta como uma referência const para `Type`.

Essas `Type`s especificam o formulário que os ponteiros e as referências devem levar para os elementos alocados. ( [alocador::p ointer](#pointer) não é necessariamente o mesmo que `Type*` para todos os objetos de alocador, embora tenha essa definição óbvia para a classe `allocator`.)

**C++11 e posterior:** para permitir operações de movimentação em seu alocador, use a interface de alocador mínimo e implemente o construtor de cópia, os operadores == e !=, alocar e desalocar. Para obter mais informações e um exemplo, consulte [Alocadores](../standard-library/allocators.md)

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[allocator](#allocator)|Construtores usados para criar objetos `allocator`.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.|
|[difference_type](#difference_type)|Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.|
|[reference](#reference)|Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.|
|[size_type](#size_type)|Um tipo integral não assinado que pode representar o comprimento de qualquer sequência que um objeto do tipo `allocator` possa alocar.|
|[value_type](#value_type)|Um tipo que é gerenciado pelo alocador.|

### <a name="functions"></a>Funções

|||
|-|-|
|[address](#address)|Localiza o endereço de um objeto cujo valor é especificado.|
|[allocate](#allocate)|Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.|
|[construct](#construct)|Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.|
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[destroy](#destroy)|Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.|
|[max_size](#max_size)|Retorna o número de elementos do tipo `Type` que podem ser alocados por um objeto da classe `allocator` antes que a memória livre seja totalmente usada.|
|[rebind](#rebind)|Uma estrutura que habilita um alocador para que objetos de um tipo aloquem armazenamento para objetos de outro tipo.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator=](#op_eq)|Atribui um objeto `allocator` a outro objeto `allocator`.|

### <a name="address"></a>corrigir

Localiza o endereço de um objeto cujo valor é especificado.

```cpp
pointer address(reference val) const;
const_pointer address(const_reference val) const;
```

#### <a name="parameters"></a>Parâmetros

*valor* \
O valor const ou não const do objeto cujo endereço está sendo pesquisado.

#### <a name="return-value"></a>Valor retornado

Um ponteiro const ou não const para o objeto localizado, de valor const ou não const, respectivamente.

#### <a name="remarks"></a>Comentários

As funções de membro retornam o endereço de *Val*, no formato que os ponteiros devem tomar para elementos alocados.

#### <a name="example"></a>Exemplo

```cpp
// allocator_address.cpp
// compile with: /EHsc
#include <memory>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 1 ; i <= 7 ; i++ )
   {
      v1.push_back( 2 * i );
   }

   cout << "The original vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   allocator<int>::const_pointer v1Ptr;
   const int k = 8;
   v1Ptr = v1Alloc.address( *find(v1.begin( ), v1.end( ), k) );
   // v1Ptr = v1Alloc.address( k );
   cout << "The integer addressed by v1Ptr has a value of: "
        << "*v1Ptr = " << *v1Ptr << "." << endl;
}
```

```Output
The original vector v1 is:
( 2 4 6 8 10 12 14 ).
The integer addressed by v1Ptr has a value of: *v1Ptr = 8.
```

### <a name="allocate"></a>aloca

Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.

```cpp
pointer allocate(size_type count, const void* _Hint);
```

#### <a name="parameters"></a>Parâmetros

*contagem* \
O número de elementos para os quais um armazenamento suficiente deve ser alocado.

@No__t_1 *_Hint*
Um ponteiro const que pode ajudar o objeto alocador a atender à solicitação de armazenamento, localizando o endereço de um objeto alocado antes da solicitação.

#### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado ou nulo se a memória não foi alocada.

#### <a name="remarks"></a>Comentários

A função membro aloca armazenamento para uma matriz de elementos de contagem do tipo `Type`, chamando o operador new (*contagem*). Ela retorna um ponteiro para o objeto alocado. O argumento de dica ajuda alguns alocadores a melhorarem a localização da referência. Uma opção válida é o endereço de um objeto alocado anteriormente pelo mesmo objeto alocador, que ainda não foi desalocado. Para não fornecer nenhuma dica, use um argumento de ponteiro nulo.

#### <a name="example"></a>Exemplo

```cpp
// allocator_allocate.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   allocator<int> v1Alloc;
   allocator<int>::pointer v1aPtr;
   v1aPtr = v1Alloc.allocate ( 10 );

   int i;
   for ( i = 0 ; i < 10 ; i++ )
   {
      v1aPtr[ i ] = i;
   }

   for ( i = 0 ; i < 10 ; i++ )
   {
      cout << v1aPtr[ i ] << " ";
   }
   cout << endl;
   v1Alloc.deallocate( v1aPtr, 10 );
}
```

```Output
0 1 2 3 4 5 6 7 8 9
```

### <a name="allocator"></a>alocador

Construtores usados para criar objetos do alocador.

```cpp
allocator();
allocator(const allocator<Type>& right);
template <class Other>
    allocator(const allocator<Other>& right);
```

#### <a name="parameters"></a>Parâmetros

\ *à direita*
O objeto alocador a ser copiado.

#### <a name="remarks"></a>Comentários

O construtor não fará nada. Em geral, no entanto, um objeto alocador construído usando outro objeto alocador deve ser comparado como igual a ele e permitir a mescla de alocação e liberação de objeto entre os dois objetos alocadores.

#### <a name="example"></a>Exemplo

```cpp
// allocator_allocator.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Int {
public:
   Int( int i )
   {
      cout << "Constructing " << ( void* )this  << endl;
      x = i;
      bIsConstructed = true;
   };
   ~Int( )
   {
      cout << "Destructing " << ( void* )this << endl;
      bIsConstructed = false;
   };
   Int &operator++( )
   {
      x++;
      return *this;
   };
   int x;
private:
   bool bIsConstructed;
};

int main( )
{
   allocator<double> Alloc;
   vector <Int>:: allocator_type v1Alloc;

   allocator<double> cAlloc(Alloc);
   allocator<Int> cv1Alloc(v1Alloc);

   if ( cv1Alloc == v1Alloc )
      cout << "The allocator objects cv1Alloc & v1Alloc are equal."
           << endl;
   else
      cout << "The allocator objects cv1Alloc & v1Alloc are not equal."
           << endl;

   if ( cAlloc == Alloc )
      cout << "The allocator objects cAlloc & Alloc are equal."
           << endl;
   else
      cout << "The allocator objects cAlloc & Alloc are not equal."
           << endl;
}
```

```Output
The allocator objects cv1Alloc & v1Alloc are equal.
The allocator objects cAlloc & Alloc are equal.
```

### <a name="const_pointer"></a>const_pointer

Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef const value_type *const_pointer;
```

#### <a name="remarks"></a>Comentários

O tipo de ponteiro descreve um `ptr` de objeto que pode designar, por meio da expressão `*ptr`, qualquer objeto const que um objeto do tipo `allocator` possa alocar.

#### <a name="example"></a>Exemplo

```cpp
// allocator_const_ptr.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 1 ; i <= 7 ; i++ )
   {
      v1.push_back( i * 2 );
   }

   cout << "The original vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   allocator<int>::const_pointer v1Ptr;
   const int k = 10;
   v1Ptr = v1Alloc.address( k );

   cout << "The integer's address found has a value of: "
        << *v1Ptr << "." << endl;
}
```

```Output
The original vector v1 is:
( 2 4 6 8 10 12 14 ).
The integer's address found has a value of: 10.
```

### <a name="const_reference"></a>const_reference

Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.

```cpp
typedef const value_type& const_reference;
```

#### <a name="remarks"></a>Comentários

O tipo de referência descreve um objeto que pode designar qualquer objeto const que um objeto do tipo `allocator` possa alocar.

#### <a name="example"></a>Exemplo

```cpp
// allocator_const_ref.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <double> v;
   vector <double> ::iterator vIter, vfIter;
   vector <double> :: allocator_type vAlloc;

   int j;
   for ( j = 1 ; j <= 7 ; j++ )
   {
      v.push_back( 100.0 * j );
   }

   cout << "The original vector v is:\n ( " ;
   for ( vIter = v.begin( ) ; vIter != v.end( ) ; vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   vfIter = v.begin( );
   allocator<double>::const_reference vcref =*vfIter;
   cout << "The value of the element referred to by vref is: "
        << vcref << ",\n the first element in the vector." << endl;

   // const references can have their elements modified,
   // so the following would generate an error:
   // vcref = 150;
   // but the value of the first element could be modified through
   // its nonconst iterator and the const reference would remain valid
*vfIter = 175;
   cout << "The value of the element referred to by vcref,"
        <<"\n after nofication through its nonconst iterator, is: "
        << vcref << "." << endl;
}
```

```Output
The original vector v is:
( 100 200 300 400 500 600 700 ).
The value of the element referred to by vref is: 100,
the first element in the vector.
The value of the element referred to by vcref,
after nofication through its nonconst iterator, is: 175.
```

### <a name="construct"></a>construir

Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.

```cpp
void construct(pointer ptr, const Type& val);
void construct(pointer ptr, Type&& val);
template <class _Other>
    void construct(pointer ptr, _Other&&... val);
```

#### <a name="parameters"></a>Parâmetros

\ *PTR*
Um ponteiro para o local no qual o objeto deve ser construído.

*valor* \
O valor com o qual o objeto que está sendo construído deve ser inicializado.

#### <a name="remarks"></a>Comentários

A primeira função de membro é equivalente ao **tipo** **new** ((`void` \*) `ptr`) (`val`).

#### <a name="example"></a>Exemplo

```cpp
// allocator_construct.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 1 ; i <= 7 ; i++ )
   {
      v1.push_back( 3 * i );
   }

   cout << "The original vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   allocator<int>::pointer v1PtrA;
   int kA = 6, kB = 7;
   v1PtrA = v1Alloc.address( *find( v1.begin( ), v1.end( ), kA ) );
   v1Alloc.destroy ( v1PtrA );
   v1Alloc.construct ( v1PtrA , kB );

   cout << "The modified vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;
}
```

```Output
The original vector v1 is:
( 3 6 9 12 15 18 21 ).
The modified vector v1 is:
( 3 7 9 12 15 18 21 ).
```

### <a name="deallocate"></a>desalocar

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(pointer ptr, size_type count);
```

#### <a name="parameters"></a>Parâmetros

\ *PTR*
Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.

*contagem* \
O número de objetos a serem desalocados do armazenamento.

#### <a name="remarks"></a>Comentários

A função membro libera o armazenamento para a matriz de objetos de contagem do tipo `Type` começando em *PTR*, chamando `operator delete(ptr)`. O ponteiro *PTR* deve ter sido retornado anteriormente por uma chamada para [ALLOCATE](#allocate) para um objeto de alocador que compara igual a **\*this**, alocando um objeto de matriz do mesmo tamanho e tipo. `deallocate` nunca gera uma exceção.

#### <a name="example"></a>Exemplo

Para obter um exemplo que usa a função de membro, consulte [allocator::allocate](#allocate).

### <a name="destroy"></a>destruir

Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.

```cpp
void destroy(pointer ptr);
```

#### <a name="parameters"></a>Parâmetros

\ *PTR*
Um ponteiro que designa o endereço do objeto a ser destruído.

#### <a name="remarks"></a>Comentários

A função membro destrói o objeto designado por *PTR*, chamando o destruidor `ptr->`**tipo**:: **~ Type**.

#### <a name="example"></a>Exemplo

```cpp
// allocator_destroy.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 1 ; i <= 7 ; i++ )
   {
      v1.push_back( 2 * i );
   }

   cout << "The original vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   allocator<int>::pointer v1PtrA;
   int kA = 12, kB = -99;
   v1PtrA = v1Alloc.address( *find(v1.begin( ), v1.end( ), kA) );
   v1Alloc.destroy ( v1PtrA );
   v1Alloc.construct ( v1PtrA , kB );

   cout << "The modified vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;
}
```

```Output
The original vector v1 is:
( 2 4 6 8 10 12 14 ).
The modified vector v1 is:
( 2 4 6 8 10 -99 14 ).
```

### <a name="difference_type"></a>difference_type

Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef ptrdiff_t difference_type;
```

#### <a name="remarks"></a>Comentários

O tipo de inteiro assinado descreve um objeto que pode representar a diferença entre os endereços de quaisquer dois elementos em uma sequência que um objeto do tipo `allocator` pode alocar.

#### <a name="example"></a>Exemplo

```cpp
// allocator_diff_type.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 0 ; i <= 7 ; i++ )
   {
      v1.push_back( i * 2 );
   }

   cout << "The original vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   allocator<int>::const_pointer v1PtrA, v1PtrB;
   const int kA = 4, kB =12;
   v1PtrA = v1Alloc.address( kA );
   v1PtrB = v1Alloc.address( kB );
   allocator<int>::difference_type v1diff = *v1PtrB - *v1PtrA;

   cout << "Pointer v1PtrA addresses " << *v1PtrA << "." << endl;
   cout << "Pointer v1PtrB addresses " << *v1PtrB <<  "." << endl;
   cout << "The difference between the integer's addresses is: "
        << v1diff << "." << endl;
}
```

```Output
The original vector v1 is:
( 0 2 4 6 8 10 12 14 ).
Pointer v1PtrA addresses 4.
Pointer v1PtrB addresses 12.
The difference between the integer's addresses is: 8.
```

### <a name="max_size"></a>max_size

Retorna o número de elementos do tipo `Type` que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.

```cpp
size_type max_size() const;
```

#### <a name="return-value"></a>Valor retornado

O número de elementos que podem ser alocados.

#### <a name="example"></a>Exemplo

```cpp
// allocator_max_size.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 1 ; i <= 7 ; i++ )
   {
      v1.push_back( i );
   }

   cout << "The original vector v1 is:\n ( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   vector <double> v2;
   vector <double> ::iterator v2Iter;
   vector <double> :: allocator_type v2Alloc;
   allocator<int>::size_type v1size;
   v1size = v1Alloc.max_size( );

   cout << "The number of integers that can be allocated before\n"
        << " the free memory in the vector v1 is used up is: "
        << v1size << "." << endl;

   int ii;
   for ( ii = 1 ; ii <= 7 ; ii++ )
   {
      v2.push_back( ii * 10.0 );
   }

   cout << "The original vector v2 is:\n ( " ;
   for ( v2Iter = v2.begin( ) ; v2Iter != v2.end( ) ; v2Iter++ )
      cout << *v2Iter << " ";
   cout << ")." << endl;
   allocator<double>::size_type v2size;
   v2size = v2Alloc.max_size( );

   cout << "The number of doubles that can be allocated before\n"
        << " the free memory in the vector v2 is used up is: "
        << v2size << "." << endl;
}
```

### <a name="op_eq"></a>operador =

Atribui um objeto alocador a outro objeto alocador.

```cpp
template <class Other>
    allocator<Type>& operator=(const allocator<Other>& right);
```

#### <a name="parameters"></a>Parâmetros

\ *à direita*
Um objeto alocador a ser atribuído a outro objeto desse.

#### <a name="return-value"></a>Valor retornado

Uma referência ao objeto alocador

#### <a name="remarks"></a>Comentários

O operador de atribuição de modelo não faz nada. Em geral, no entanto, um objeto alocador atribuído a outro objeto alocador deve ser comparado como igual a ele e permitir a mescla de alocação e liberação de objeto entre os dois objetos alocadores.

#### <a name="example"></a>Exemplo

```cpp
// allocator_op_assign.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Int {
public:
   Int(int i)
   {
      cout << "Constructing " << ( void* )this  << endl;
      x = i;
      bIsConstructed = true;
   };
   ~Int( ) {
      cout << "Destructing " << ( void* )this << endl;
      bIsConstructed = false;
   };
   Int &operator++( )
   {
      x++;
      return *this;
   };
   int x;
private:
   bool bIsConstructed;
};

int main( )
{
   allocator<Int> Alloc;
   allocator<Int> cAlloc ;
   cAlloc = Alloc;
}
```

### <a name="pointer"></a>refere

Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef value_type *pointer;
```

#### <a name="remarks"></a>Comentários

O tipo de ponteiro descreve um `ptr` de objeto que pode designar, por meio da expressão **\*ptr**, qualquer objeto que um objeto do tipo `allocator` possa alocar.

#### <a name="example"></a>Exemplo

```cpp
// allocator_ptr.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <int> v1;
   vector <int>::iterator v1Iter;
   vector <int>:: allocator_type v1Alloc;

   int i;
   for ( i = 1 ; i <= 7 ; i++ )
   {
      v1.push_back( 3 * i );
   }

   cout << "The original vector v1 is:\n( " ;
   for ( v1Iter = v1.begin( ) ; v1Iter != v1.end( ) ; v1Iter++ )
      cout << *v1Iter << " ";
   cout << ")." << endl;

   allocator<int>::const_pointer v1Ptr;
   const int k = 12;
   v1Ptr = v1Alloc.address( k );

   cout << "The integer addressed by v1Ptr has a value of: "
        << "*v1Ptr = " << *v1Ptr << "." << endl;
}
```

```Output
The original vector v1 is:
( 3 6 9 12 15 18 21 ).
The integer addressed by v1Ptr has a value of: *v1Ptr = 12.
```

### <a name="rebind"></a>reassociar

Uma estrutura que habilita um alocador para que objetos de um tipo aloquem armazenamento para objetos de outro tipo.

```cpp
struct rebind { typedef allocator<_Other> other; };
```

#### <a name="parameters"></a>Parâmetros

*outros* \
O tipo de elemento para o qual a memória está sendo alocada.

#### <a name="remarks"></a>Comentários

Essa estrutura é útil para alocar memória para um tipo diferente do tipo de elemento do contêiner que está sendo implementado.

O modelo de classe de membro define o tipo outro. Sua única finalidade é fornecer o nome do tipo **allocator**\<_ **Other**>, dado o nome do tipo **allocator**\< **Type**>.

Por exemplo, dado um objeto de alocador `al` do tipo `A`, você pode alocar um objeto do tipo `_Other` com a expressão:

```cpp
A::rebind<Other>::other(al).allocate(1, (Other *)0)
```

Ou, você pode nomear o tipo de ponteiro dele, escrevendo o tipo:

```cpp
A::rebind<Other>::other::pointer
```

#### <a name="example"></a>Exemplo

```cpp
// allocator_rebind.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int>::allocator_type IntAlloc;
int main( )
{
   IntAlloc v1Iter;
   vector<int> v1;

   IntAlloc::rebind<char>::other::pointer pszC =
      IntAlloc::rebind<char>::other(v1.get_allocator()).allocate(1, (void *)0);

   int * pInt = v1Iter.allocate(10);
}
```

### <a name="reference"></a>referência

Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.

```cpp
typedef value_type& reference;
```

#### <a name="remarks"></a>Comentários

O tipo de referência descreve um objeto que pode designar qualquer objeto que um objeto do tipo `allocator` possa alocar.

#### <a name="example"></a>Exemplo

```cpp
// allocator_reference.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <double> v;
   vector <double> ::iterator vIter, vfIter;
   vector <double> :: allocator_type vAlloc;

   int j;
   for ( j = 1 ; j <= 7 ; j++ )
   {
      v.push_back( 100.0 * j );
   }

   cout << "The original vector v is:\n ( " ;
   for ( vIter = v.begin( ) ; vIter != v.end( ) ; vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   vfIter = v.begin( );
   allocator<double>::reference vref =*vfIter;
   cout << "The value of the element referred to by vref is: "
        << vref << ",\n the first element in the vector." << endl;

   // nonconst references can have their elements modified
   vref = 150;
   cout << "The element referred to by vref after being modified is: "
        << vref << "." << endl;
}
```

```Output
The original vector v is:
( 100 200 300 400 500 600 700 ).
The value of the element referred to by vref is: 100,
the first element in the vector.
The element referred to by vref after being modified is: 150.
```

### <a name="size_type"></a>size_type

Um tipo integral não assinado que pode representar o comprimento de qualquer sequência que um objeto do tipo `allocator` possa alocar.

```cpp
typedef size_t size_type;
```

#### <a name="example"></a>Exemplo

```cpp
// allocator_size_type.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   vector <double> v;
   vector <double> ::iterator vIter;
   vector <double> :: allocator_type vAlloc;

   int j;
   for ( j = 1 ; j <= 7 ; j++ )
   {
      v.push_back( 100.0 * j );
   }

   cout << "The original vector v is:\n ( " ;
   for ( vIter = v.begin( ) ; vIter != v.end( ) ; vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   allocator<double>::size_type vsize;
   vsize = vAlloc.max_size( );

   cout << "The number of doubles that can be allocated before\n"
        << " the free memory in the vector v is used up is: "
        << vsize << "." << endl;
}
```

### <a name="value_type"></a>value_type

Um tipo que é gerenciado pelo alocador.

```cpp
typedef Type value_type;
```

#### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Type`.

#### <a name="example"></a>Exemplo

```cpp
// allocator_value_type.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

int main( )
{
   vector <double> v;
   vector <double> ::iterator vIter, vfIter;
   vector <double> :: allocator_type vAlloc;

   int j;
   for ( j = 1 ; j <= 7 ; j++ )
   {
      v.push_back( 100.0 * j );
   }

   cout << "The original vector v is:\n ( " ;
   for ( vIter = v.begin( ) ; vIter != v.end( ) ; vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;

   vfIter = v.begin( );
   allocator<double>::value_type vecVal = 150.0;
*vfIter = vecVal;
   cout << "The value of the element addressed by vfIter is: "
        << *vfIter << ",\n the first element in the vector." << endl;

   cout << "The modified vector v is:\n ( " ;
   for ( vIter = v.begin( ) ; vIter != v.end( ) ; vIter++ )
      cout << *vIter << " ";
   cout << ")." << endl;
}
```

```Output
The original vector v is:
( 100 200 300 400 500 600 700 ).
The value of the element addressed by vfIter is: 150,
the first element in the vector.
The modified vector v is:
( 150 200 300 400 500 600 700 ).
```

## <a name="helpers"></a>Auxiliares

### <a name="allocator_arg_t"></a>allocator_arg_t

```cpp
struct allocator_arg_t { explicit allocator_arg_t() = default; };
inline constexpr allocator_arg_t allocator_arg{};
```

### <a name="uses_allocator"></a>uses_allocator

```cpp
template <class T, class Alloc> struct uses_allocator;
```
