---
title: Classe allocator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 05a0ac72a689c0f82db1bb4d18169542c0df4bc9
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="allocator-class"></a>Classe allocator
A classe de modelo descreve um objeto que gerencia a alocação de armazenamento e a liberação de matrizes de objetos do tipo **Type**. Um objeto da classe **allocator** é o objeto alocador padrão especificado nos construtores para várias classes de modelo de contêiner na Biblioteca Padrão do C++.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type>  
class allocator  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de objeto para o qual o armazenamento está sendo alocado ou desalocado.  
  
## <a name="remarks"></a>Comentários  
 Todos os contêineres da Biblioteca Padrão do C++ têm um parâmetro de modelo cujo padrão é **allocator**. Construir um contêiner com um alocador personalizado fornece controle sobre a alocação e a liberação dos elementos desse contêiner.  
  
 Por exemplo, um objeto alocador pode alocar armazenamento em um heap privado ou na memória compartilhada ou pode otimizar para tamanhos de objeto grandes ou pequenos. Ele também pode especificar, por meio das definições de tipo que fornece, que os elementos sejam acessados por meio de objetos acessadores especiais que gerenciam a memória compartilhada ou executam coleta de lixo automática. Portanto, uma classe que aloca armazenamento usando um objeto alocador deve usar esses tipos para declarar um ponteiro e referenciar objetos, como os contêineres na Biblioteca Padrão do C++.  
  
 **(Somente C_++98/03)** Ao derivar da classe allocator, você precisa fornecer um struct [rebind](#rebind), cujo typedef `_Other` referencie a classe recém-derivada.  
  
 Portanto, um alocador define os seguintes tipos:  
  
- [pointer](#pointer) comporta-se como um ponteiro para **Type**.  
  
- [const_pointer](#const_pointer) comporta-se como um ponteiro const para **Type**.  
  
- [reference](#reference) comporta-se como uma referência a **Type**.  
  
- [const_reference](#const_reference) comporta-se como uma referência const para **Type**.  
  
 Esses **Type**s especificam o formulário que os ponteiros e as referências devem usar para elementos alocados. ([allocator::pointer](#pointer) não é necessariamente igual a **Type**\* para todos os objetos alocadores, mesmo tendo essa definição óbvia para a classe **allocator**.)  
  
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
|[size_type](#size_type)|Um tipo integral sem sinal que pode representar o comprimento de qualquer sequência que um objeto da classe de modelo `allocator` possa alocar.|  
|[value_type](#value_type)|Um tipo que é gerenciado pelo alocador.|  
  
### <a name="member-functions"></a>Funções membro  
  
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
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<memory>  
  
 **Namespace:** std  
  
##  <a name="address"></a>  allocator::address  
 Localiza o endereço de um objeto cujo valor é especificado.  
  
```  
pointer address(reference val) const;
const_pointer address(const_reference val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 O valor const ou não const do objeto cujo endereço está sendo pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro const ou não const para o objeto localizado, de valor const ou não const, respectivamente.  
  
### <a name="remarks"></a>Comentários  
 As funções de membro retornam o endereço de `val`, no formulário que os ponteiros devem usar para os elementos alocados.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="allocate"></a>  allocator::allocate  
 Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.  
  
```  
pointer allocate(size_type count, const void* _Hint);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de elementos para os quais um armazenamento suficiente deve ser alocado.  
  
 *_Hint*  
 Um ponteiro const que pode ajudar o objeto alocador a atender à solicitação de armazenamento, localizando o endereço de um objeto alocado antes da solicitação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto alocado ou nulo se a memória não foi alocada.  
  
### <a name="remarks"></a>Comentários  
 A função de membro aloca armazenamento para uma matriz de elementos de contagem do tipo **Type**, chamando o operador new( `count`). Ela retorna um ponteiro para o objeto alocado. O argumento de dica ajuda alguns alocadores a melhorarem a localização da referência. Uma opção válida é o endereço de um objeto alocado anteriormente pelo mesmo objeto alocador, que ainda não foi desalocado. Para não fornecer nenhuma dica, use um argumento de ponteiro nulo.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="allocator"></a>  allocator::allocator  
 Construtores usados para criar objetos do alocador.  
  
```  
allocator();
allocator(const allocator<Type>& right);
template <class Other>  
allocator(const allocator<Other>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O objeto alocador a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 O construtor não fará nada. Em geral, no entanto, um objeto alocador construído usando outro objeto alocador deve ser comparado como igual a ele e permitir a mescla de alocação e liberação de objeto entre os dois objetos alocadores.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="const_pointer"></a>  allocator::const_pointer  
 Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.  
  
```  
typedef const value_type *const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo de ponteiro descreve um objeto **ptr** que pode designar, usando a expressão **\*ptr**, qualquer objeto const que um objeto da classe de modelo allocator possa alocar.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="const_reference"></a>  allocator::const_reference  
 Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.  
  
```  
typedef const value_type& const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo de referência descreve um objeto que pode designar qualquer objeto const que um objeto da classe de modelo allocator possa alocar.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="construct"></a>  allocator::construct  
 Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.  
  
```  
void construct(pointer ptr, const Type& val);
void construct(pointer ptr, Type&& val);
template <class _Other>  
void construct(pointer ptr, _Other&&...   val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 Um ponteiro para o local no qual o objeto deve ser construído.  
  
 `val`  
 O valor com o qual o objeto que está sendo construído deve ser inicializado.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro é equivalente a **new** ((`void` \*) `ptr`) **Type** (`val`).  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="deallocate"></a>  allocator::deallocate  
 Libera um número especificado de objetos do armazenamento começando em uma posição especificada.  
  
```  
void deallocate(pointer ptr, size_type count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.  
  
 `count`  
 O número de objetos a serem desalocados do armazenamento.  
  
### <a name="remarks"></a>Comentários  
 A função de membro libera armazenamento para a matriz de contagem de objetos do tipo **tipo** começando no `ptr`, chamando `operator delete(ptr)`. O ponteiro `ptr` deve ter sido retornado anteriormente por uma chamada a [alocar](#allocate) de um objeto alocador que compara como igual a **\*this**, alocando um objeto de matriz dos mesmos tipo e tamanho. `deallocate` nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  Para obter um exemplo que usa a função de membro, consulte [allocator::allocate](#allocate).  
  
##  <a name="destroy"></a>  allocator::destroy  
 Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.  
  
```  
void destroy(pointer ptr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 Um ponteiro que designa o endereço do objeto a ser destruído.  
  
### <a name="remarks"></a>Comentários  
 A função de membro destrói o objeto designado pelo `ptr`, chamando o destruidor `ptr->` **tipo**::**~ tipo**.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="difference_type"></a>  allocator::difference_type  
 Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.  
  
```  
typedef ptrdiff_t difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo de inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer em uma sequência, que um objeto da classe de modelo allocator possa alocar.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="max_size"></a>  allocator::max_size  
 Retorna o número de elementos do tipo **Type** que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos que podem ser alocados.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="op_eq"></a>  allocator::operator=  
 Atribui um objeto alocador a outro objeto alocador.  
  
```  
template <class Other>  
allocator<Type>& operator=(const allocator<Other>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Um objeto alocador a ser atribuído a outro objeto desse.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto alocador  
  
### <a name="remarks"></a>Comentários  
 O operador de atribuição de modelo não faz nada. Em geral, no entanto, um objeto alocador atribuído a outro objeto alocador deve ser comparado como igual a ele e permitir a mescla de alocação e liberação de objeto entre os dois objetos alocadores.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="pointer"></a>  allocator::pointer  
 Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.  
  
```  
typedef value_type *pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo de ponteiro descreve um objeto **ptr** que pode designar, usando a expressão **\*ptr**, qualquer objeto que um objeto da classe de modelo allocator possa alocar.  
  
### <a name="example"></a>Exemplo  
  
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
  
   cout << "The original vector v1 is:\n ( " ;  
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
  
##  <a name="rebind"></a>  allocator::rebind  
 Uma estrutura que habilita um alocador para que objetos de um tipo aloquem armazenamento para objetos de outro tipo.  
```  
struct rebind {    typedef allocator<_Other> other ;    };  
```  
### <a name="parameters"></a>Parâmetros  
 *other*  
 O tipo de elemento para o qual a memória está sendo alocada.  
  
### <a name="remarks"></a>Comentários  
 Essa estrutura é útil para alocar memória para um tipo diferente do tipo de elemento do contêiner que está sendo implementado.  
  
 A classe de modelo de membro define o tipo other. Sua única finalidade é fornecer o nome do tipo **allocator**\<_ **Other**>, dado o nome do tipo **allocator**\< **Type**>.  
  
 Por exemplo, dado um objeto alocador **al** do tipo **A**, você pode alocar um objeto do tipo **_Other** com a expressão:  
  
```  
A::rebind<Other>::other(al).allocate(1, (Other *)0)  
```  
  
 Ou, você pode nomear o tipo de ponteiro dele, escrevendo o tipo:  
  
```  
A::rebind<Other>::other::pointer  
```  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="reference"></a>  allocator::reference  
 Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.  
  
```  
typedef value_type& reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo de referência descreve um objeto que pode designar qualquer objeto que um objeto da classe de modelo allocator possa alocar.  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="size_type"></a>  allocator::size_type  
 Um tipo integral sem sinal que pode representar o comprimento de qualquer sequência que um objeto da classe de modelo allocator possa alocar.  
  
```  
typedef size_t size_type;  
```  
  
### <a name="example"></a>Exemplo  
  
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
  
##  <a name="value_type"></a>  allocator::value_type  
 Um tipo que é gerenciado pelo alocador.  
  
```  
typedef Type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **Type**.  
  
### <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

