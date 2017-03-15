---
title: Classe vector | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::vector
- vector
- std.vector
dev_langs:
- C++
helpviewer_keywords:
- vector class
ms.assetid: a3e0a8f8-7565-4fe0-93e4-e4d74ae1b70d
caps.latest.revision: 24
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 2a2235788f548dbe40625999935cdf396107cbd6
ms.lasthandoff: 02/25/2017

---
# <a name="vector-class"></a>Classe vector
A classe vector da Biblioteca Padrão C++ é uma classe de modelo de contêineres de sequências que organiza os elementos de um determinado tipo de maneira linear e permite o acesso aleatório rápido a qualquer elemento. Os contêineres deverão ser os preferenciais para uma sequência quando o desempenho de acesso aleatório for reduzido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type, class Allocator = allocator<Type>>  
class vector  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de dados do elemento a ser armazenado no vetor  
  
 `Allocator`  
 O tipo que representa o objeto allocator armazenado que encapsula detalhes sobre a alocação e a desalocação de memória do vetor. Esse argumento é opcional e o valor padrão é **allocator***\<Type>.*  
  
## <a name="remarks"></a>Comentários  
 Os vetores permitem inserções e exclusões em tempo constante no final da sequência. Inserir ou excluir elementos no meio de um vetor exige tempo linear. O desempenho do contêiner da [Classe deque](../standard-library/deque-class.md) é superior em relação a inserções e exclusões no início e no final de uma sequência. O contêiner da [Classe list](../standard-library/list-class.md) é superior em relação a inserções e exclusões em qualquer local em uma sequência.  
  
 A realocação do vetor ocorre quando uma função membro deve aumentar a sequência contida no objeto vector além da sua capacidade de armazenamento atual. Outras inserções e exclusões podem alterar vários endereços de armazenamento na sequência. Em todos esses casos, iteradores ou referências que apontam para partes alteradas da sequência tornam-se inválidos. Se nenhuma realocação ocorrer, somente os iteradores e as referências antes do ponto de inserção/exclusão permanecerão válidos.  
  
 A [Classe vector\<bool>](../standard-library/vector-bool-class.md) é uma especialização completa do vetor de classe de modelo dos elementos do tipo bool com um alocador para o tipo subjacente usado pela especialização.  
  
 A [Classe vector\<bool> reference](../standard-library/vector-bool-class.md#vector_lt_bool_gt___reference_class) é uma classe aninhada cujos objetos podem fornecer referências aos elementos (bits únicos) em um objeto vector\<bool >.  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[vector](#vector__vector)|Constrói um vetor de tamanho específico com elementos de um valor específico, com um `allocator` específico ou como uma cópia de algum outro vetor.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#vector__allocator_type)|Um tipo que representa a classe `allocator` do objeto vector.|  
|[const_iterator](#vector__const_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler um elemento `const` em um vetor.|  
|[const_pointer](#vector__const_pointer)|Um tipo que fornece um ponteiro para um elemento `const` em um vetor.|  
|[const_reference](#vector__const_reference)|Um tipo que fornece uma referência para um elemento `const` armazenado em um vetor para leitura e execução de operações `const`.|  
|[const_reverse_iterator](#vector__const_reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento `const` no vetor.|  
|[difference_type](#vector__difference_type)|Um tipo que fornece a diferença entre os endereços de dois elementos em um vetor.|  
|[iterator](#vector__iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor.|  
|[pointer](#vector__pointer)|Um tipo que fornece um ponteiro para um elemento em um vetor.|  
|[reference](#vector__reference)|Um tipo que fornece uma referência a um elemento armazenado em um vetor.|  
|[reverse_iterator](#vector__reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor invertido.|  
|[size_type](#vector__size_type)|Um tipo que conta o número de elementos em um vetor.|  
|[value_type](#vector__value_type)|Um tipo que representa o tipo de dados armazenado em um vetor.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[assign](#vector__assign)|Apaga um vetor e copia os elementos especificados para o vetor vazio.|  
|[at](#vector__at)|Retorna uma referência ao elemento em um local especificado no vetor.|  
|[back](#vector__back)|Retorna uma referência ao último elemento do vetor.|  
|[begin](#vector__begin)|Retorna um iterador de acesso aleatório para o primeiro elemento no vetor.|  
|[capacity](#vector__capacity)|Retorna o número de elementos que o vetor pode conter sem alocar mais armazenamento.|  
|[cbegin](#vector__cbegin)|Retorna um iterador de acesso aleatório const para o primeiro elemento no vetor.|  
|[cend](#vector__cend)|Retorna um iterador de acesso aleatório const que aponta para imediatamente após o fim do vetor.|  
|[crbegin](#vector__crbegin)|Retorna um iterador const para o primeiro elemento em um vetor invertido.|  
|[crend](#vector__crend)|Retorna um iterador const para o final de um vetor invertido.|  
|[clear](#vector__clear)|Apaga os elementos do vetor.|  
|[data](#vector__data)|Retorna um ponteiro para o primeiro elemento no vetor.|  
|[emplace](#vector__emplace)|Insere um elemento construído no local no vetor em uma posição especificada.|  
|[emplace_back](#vector__emplace_back)|Adiciona um elemento construído no local ao final do vetor.|  
|[empty](#vector__empty)|Testa se o contêiner do vetor está vazio.|  
|[end](#vector__end)|Retorna um iterador de acesso aleatório que aponta para o final do vetor.|  
|[erase](#vector__erase)|Remove um elemento ou um intervalo de elementos em um vetor das posições especificadas.|  
|[front](#vector__front)|Retorna uma referência ao primeiro elemento em um vetor.|  
|[get_allocator](#vector__get_allocator)|Retorna um objeto para a classe `allocator` usada por um vetor.|  
|[insert](#vector__insert)|Insere um elemento ou uma série de elementos no vetor em uma posição especificada.|  
|[max_size](#vector__max_size)|Retorna o tamanho máximo do vetor.|  
|[pop_back](#vector__pop_back)|Exclui o elemento no final do vetor.|  
|[push_back](#vector__push_back)|Adiciona um elemento ao final do vetor.|  
|[rbegin](#vector__rbegin)|Retorna um iterador para o primeiro elemento em um vetor invertido.|  
|[rend](#vector__rend)|Retorna um iterador para o final de um vetor invertido.|  
|[reserve](#vector__reserve)|Reserva um tamanho mínimo de armazenamento para um objeto vector.|  
|[resize](#vector__resize)|Especifica um novo tamanho para um vetor.|  
|[shrink_to_fit](#vector__shrink_to_fit)|Descarta o excesso de capacidade.|  
|[size](#vector__size)|Retorna o número de elementos no vetor.|  
|[swap](#vector__swap)|Troca os elementos de dois vetores.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator&#91;&#93;](#vector__operator_at)|Retorna uma referência para o elemento de vetor em uma posição especificada.|  
|[operator=](#vector__operator_eq)|Substitui os elementos do vetor por uma cópia de outro vetor.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<vector>  
  
 **Namespace:** std  
  
##  <a name="a-namevectorallocatortypea--vectorallocatortype"></a><a name="vector__allocator_type"></a> vector::allocator_type  
 Um tipo que representa a classe allocator do objeto vector.  
  
```  
typedef Allocator allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `allocator_type` é um sinônimo do parâmetro de modelo **Allocator.**  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [get_allocator](#vector__get_allocator) para obter um exemplo que usa `allocator_type`.  
  
##  <a name="a-namevectorassigna--vectorassign"></a><a name="vector__assign"></a> vector::assign  
 Apaga um vetor e copia os elementos especificados para o vetor vazio.  
  
```  
void assign(size_type Count, const Type& Val);
void assign(initializer_list<Type> IList);

template <class InputIterator>  
void assign(InputIterator First, InputIterator Last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `First`  
 A posição do primeiro elemento no intervalo de elementos a ser copiado.  
  
 `Last`  
 A posição do primeiro elemento após o intervalo de elementos a ser copiado.  
  
 `Count`  
 O número de cópias de um elemento sendo inserido no vetor.  
  
 `Val`  
 O valor do elemento sendo inserido no vetor.  
  
 `IList`  
 A initializer_list que contém os elementos a serem inseridos.  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes em um vetor, a função assign insere um intervalo especificado de elementos do vetor original em um vetor ou insere cópias de um novo elemento de um valor especificado em um vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
/ vector_assign.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector<int> v1, v2, v3;  
  
    v1.push_back(10);  
    v1.push_back(20);  
    v1.push_back(30);  
    v1.push_back(40);  
    v1.push_back(50);  
  
    cout << "v1 = ";  
    for (auto& v : v1){  
        cout << v << " ";  
    }  
    cout << endl;  
  
    v2.assign(v1.begin(), v1.end());  
    cout << "v2 = ";  
    for (auto& v : v2){  
        cout << v << " ";  
    }  
    cout << endl;  
  
    v3.assign(7, 4);  
    cout << "v3 = ";  
    for (auto& v : v3){  
        cout << v << " ";  
    }  
    cout << endl;  
  
    v3.assign({ 5, 6, 7 });  
    for (auto& v : v3){  
        cout << v << " ";  
    }  
    cout << endl;  
}  
  
```  
  
##  <a name="a-namevectorata--vectorat"></a><a name="vector__at"></a> vector::at  
 Retorna uma referência ao elemento em um local especificado no vetor.  
  
```  
reference at(size_type _Pos);

const_reference at(size_type _Pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Pos`  
 O número da posição ou subscrito do elemento para referência no vetor.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao elemento subscrito no argumento. Se `_Off` for maior que o tamanho do vetor, **at** gerará uma exceção.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado de **at** for atribuído a `const_reference`, o objeto vector não poderá ser modificado. Se o valor retornado de **at** for atribuído a **reference**, o objeto vector poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_at.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
  
   const int &i = v1.at( 0 );  
   int &j = v1.at( 1 );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namevectorbacka--vectorback"></a><a name="vector__back"></a> vector::back  
 Retorna uma referência ao último elemento do vetor.  
  
```  
reference back();

const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O último elemento do vetor. Se o vetor estiver vazio, o valor retornado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado de **back** for atribuído a `const_reference`, o objeto vector não poderá ser modificado. Se o valor retornado de **back** for atribuído a **reference**, o objeto vector poderá ser modificado.  
  
 Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro em tempo de execução ocorrerá se você tentar acessar um elemento em um vetor vazio.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_back.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 11 );  
  
   int& i = v1.back( );  
   const int& ii = v1.front( );  
  
   cout << "The last integer of v1 is " << i << endl;  
   i--;  
   cout << "The next-to-last integer of v1 is "<< ii << endl;  
}  
```  
  
##  <a name="a-namevectorbegina--vectorbegin"></a><a name="vector__begin"></a> vector::begin  
 Retorna um iterador de acesso aleatório para o primeiro elemento no vetor.  
  
```  
const_iterator begin() const;

 
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que endereça o primeiro elemento em `vector` ou ao local que vem após um `vector` vazio. Você deve sempre comparar o valor retornado com [vector::end](#vector__end) para garantir que ele é válido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado de `begin` for atribuído a [vector::const_iterator](#vector__const_iterator), o objeto `vector` não poderá ser modificado. Se o valor retornado de `begin` for atribuído a [vector::iterator](#vector__iterator), o objeto `vector` poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_begin.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector<int> c1;  
    vector<int>::iterator c1_Iter;  
    vector<int>::const_iterator c1_cIter;  
  
    c1.push_back(1);  
    c1.push_back(2);  
  
    cout << "The vector c1 contains elements:";  
    c1_Iter = c1.begin();  
    for (; c1_Iter != c1.end(); c1_Iter++)  
    {  
        cout << " " << *c1_Iter;  
    }  
    cout << endl;  
  
    cout << "The vector c1 now contains elements:";  
    c1_Iter = c1.begin();  
 *c1_Iter = 20;  
    for (; c1_Iter != c1.end(); c1_Iter++)  
    {  
        cout << " " << *c1_Iter;  
    }  
    cout << endl;  
  
    // The following line would be an error because iterator is const  
    // *c1_cIter = 200;  
}  
```  
  
```Output  
The vector c1 contains elements: 1 2  
The vector c1 now contains elements: 20 2  
```  
  
##  <a name="a-namevectorcapacitya--vectorcapacity"></a><a name="vector__capacity"></a> vector::capacity  
 Retorna o número de elementos que o vetor pode conter sem alocar mais armazenamento.  
  
```  
size_type capacity() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do armazenamento alocado para o vetor.  
  
### <a name="remarks"></a>Comentários  
 A função membro [resize](#vector__resize) será mais eficiente se houver alocação de memória suficiente para acomodá-la. Use a função membro [reserve](#vector__reserve) para especificar a quantidade de memória alocada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_capacity.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
  
   v1.push_back( 1 );  
   cout << "The length of storage allocated is "  
        << v1.capacity( ) << "." << endl;  
  
   v1.push_back( 2 );  
   cout << "The length of storage allocated is now "  
        << v1.capacity( ) << "." << endl;  
}  
```  
  
```Output  
The length of storage allocated is 1.  
The length of storage allocated is now 2.  
```  
  
##  <a name="a-namevectorcbegina--vectorcbegin"></a><a name="vector__cbegin"></a> vector::cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório `const` que aponta o primeiro elemento do intervalo ou o local logo após o fim de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `cbegin`, os elementos do intervalo não podem ser modificados.  
  
 Você pode usar essa função membro no lugar da função membro `begin()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `begin()` e `cbegin()`.  
  
```cpp  
auto i1 = Container.begin();
// i1 is Container<T>::iterator   
auto i2 = Container.cbegin();

// i2 is Container<T>::const_iterator  
```  
  
##  <a name="a-namevectorcenda--vectorcend"></a><a name="vector__cend"></a> vector::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório `const` que aponta para além do fim do intervalo.  
  
### <a name="remarks"></a>Comentários  
 `cend` é usado para testar se um iterador passou do fim de seu intervalo.  
  
 Você pode usar essa função membro no lugar da função membro `end()`, de modo a garantir que o valor de retorno seja `const_iterator`. Normalmente, é usada juntamente com a palavra-chave de dedução de tipo [auto](../cpp/auto-cpp.md), conforme mostrado no exemplo a seguir. No exemplo, considere `Container` como um contêiner modificável (não `const`) de qualquer tipo, que dá suporte para `end()` e `cend()`.  
  
```cpp  
auto i1 = Container.end();
// i1 is Container<T>::iterator   
auto i2 = Container.cend();

// i2 is Container<T>::const_iterator  
```  
  
 O valor retornado por `cend` não deve ser desreferenciado.  
  
##  <a name="a-namevectorcleara--vectorclear"></a><a name="vector__clear"></a> vector::clear  
 Apaga os elementos do vetor.  
  
```  
void clear();
```  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_clear.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "The size of v1 is " << v1.size( ) << endl;  
   v1.clear( );  
   cout << "The size of v1 after clearing is " << v1.size( ) << endl;  
}  
```  
  
```Output  
The size of v1 is 3  
The size of v1 after clearing is 0  
```  
  
##  <a name="a-namevectorconstiteratora--vectorconstiterator"></a><a name="vector__const_iterator"></a> vector::const_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler um elemento **const** em um vetor.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [back](#vector__back) para obter um exemplo que usa `const_iterator`.  
  
##  <a name="a-namevectorconstpointera--vectorconstpointer"></a><a name="vector__const_pointer"></a> vector::const_pointer  
 Um tipo que fornece um ponteiro para um elemento **const** em um vetor.  
  
```  
typedef typename Allocator::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento.  
  
 Um [iterator](#vector__iterator) é usado com mais frequência para acessar um elemento de vetor.  
  
##  <a name="a-namevectorconstreferencea--vectorconstreference"></a><a name="vector__const_reference"></a> vector::const_reference  
 Um tipo que fornece uma referência para um elemento **const** armazenado em um vetor para leitura e execução de operações **const**.  
  
```  
typedef typename Allocator::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_reference` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_const_ref.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
  
   const vector <int> v2 = v1;  
   const int &i = v2.front( );  
   const int &j = v2.back( );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
  
   // The following line would cause an error as v2 is const  
   // v2.push_back( 30 );  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="a-namevectorconstreverseiteratora--vectorconstreverseiterator"></a><a name="vector__const_reverse_iterator"></a> vector::const_reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento **const** no vetor.  
  
```  
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar no vetor em ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Consulte [rbegin](#vector__rbegin) para obter um exemplo de como declarar e usar um iterador.  
  
##  <a name="a-namevectorcrbegina--vectorcrbegin"></a><a name="vector__crbegin"></a> vector::crbegin  
 Retorna um iterador const para o primeiro elemento em um vetor invertido.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso const que endereça o primeiro elemento em um [vector](../standard-library/vector-class.md) invertido ou que endereça qual foi o último elemento no `vector` não invertido.  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `crbegin`, o objeto `vector` não pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_crbegin.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator v1_Iter;  
   vector <int>::const_reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of vector is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.crbegin( );  
   cout << "The first element of the reversed vector is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of vector is 1.  
The first element of the reversed vector is 2.  
```  
  
##  <a name="a-namevectorcrenda--vectorcrend"></a><a name="vector__crend"></a> vector::crend  
 Retorna um iterador const que endereça o local após o último elemento em um vetor invertido.  
  
```  
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso const que endereça o local após o último elemento em um [vector](../standard-library/vector-class.md) invertido (o local que precedeu o primeiro elemento no `vector` não invertido).  
  
### <a name="remarks"></a>Comentários  
 `crend` é usado com um `vector` invertido, assim como [vector::cend](#vector__cend) é usado com um `vector`.  
  
 Com o valor retornado de `crend` (adequadamente diminuído), o objeto `vector` não poderá ser modificado.  
  
 `crend` pode ser usado para testar se um iterador inverso alcançou o final de sua `vector`.  
  
 O valor retornado por `crend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_crend.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::const_reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )  
      cout << *v1_rIter << endl;  
}  
```  
  
```Output  
2  
1  
```  
  
##  <a name="a-namevectordataa--vectordata"></a><a name="vector__data"></a> vector::data  
 Retorna um ponteiro para o primeiro elemento no vetor.  
  
```  
const_pointer data() const;

 
pointer data();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o primeiro elemento no [vector](../standard-library/vector-class.md) ou para o local após um `vector` vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_data.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector<int> c1;  
    vector<int>::pointer c1 ptr;  
    vector<int>::const_pointer c1_cPtr;  
  
    c1.push_back(1);  
    c1.push_back(2);  
  
    cout << "The vector c1 contains elements:";  
    c1_cPtr = c1.data();  
    for (size_t n = c1.size(); 0 < n; --n, c1_cPtr++)  
    {  
        cout << " " << *c1_cPtr;  
    }  
    cout << endl;  
  
    cout << "The vector c1 now contains elements:";  
    c1 ptr = c1.data();  
 *c1 ptr = 20;  
    for (size_t n = c1.size(); 0 < n; --n, c1 ptr++)  
    {  
        cout << " " << *c1 ptr;  
    }  
    cout << endl;  
}  
```  
  
```Output  
The vector c1 contains elements: 1 2  
The vector c1 now contains elements: 20 2  
```  
  
##  <a name="a-namevectordifferencetypea--vectordifferencetype"></a><a name="vector__difference_type"></a> vector::difference_type  
 Um tipo que fornece a diferença entre dois iteradores que se referem a elementos no mesmo vetor.  
  
```  
typedef typename Allocator::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 Um `difference_type` também pode ser descrito como o número de elementos entre dois ponteiros, uma vez que um ponteiro para um elemento contém o seu endereço.  
  
 Um [iterator](#vector__iterator) é usado com mais frequência para acessar um elemento de vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_diff_type.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <vector>  
#include <algorithm>  
  
int main( )  
{  
   using namespace std;  
  
   vector <int> c1;  
   vector <int>::iterator c1_Iter, c2_Iter;  
  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
   c1.push_back( 10 );  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
  
   c1_Iter = c1.begin( );  
   c2_Iter = c1.end( );  
  
   vector <int>::difference_type   df_typ1, df_typ2, df_typ3;  
  
   df_typ1 = count( c1_Iter, c2_Iter, 10 );  
   df_typ2 = count( c1_Iter, c2_Iter, 20 );  
   df_typ3 = count( c1_Iter, c2_Iter, 30 );  
   cout << "The number '10' is in c1 collection " << df_typ1 << " times.\n";  
   cout << "The number '20' is in c1 collection " << df_typ2 << " times.\n";  
   cout << "The number '30' is in c1 collection " << df_typ3 << " times.\n";  
}  
```  
  
```Output  
The number '10' is in c1 collection 1 times.  
The number '20' is in c1 collection 2 times.  
The number '30' is in c1 collection 3 times.  
```  
  
##  <a name="a-namevectoremplacea--vectoremplace"></a><a name="vector__emplace"></a> vector::emplace  
 Insere um elemento construído no local no vetor em uma posição especificada.  
  
```  
iterator emplace(
    const_iterator _Where,  
    Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|A posição no [vetor](../standard-library/vector-class.md) em que o primeiro elemento é inserido.|  
|` val`|O valor do elemento que está sendo inserido no `vector`.|  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna um iterador que aponta para a posição em que o novo elemento foi inserido no `vector`.  
  
### <a name="remarks"></a>Comentários  
 Qualquer operação de inserção pode ser cara, consulte [Classe vector](../standard-library/vector-class.md) para ver uma discussão sobre o desempenho de `vector`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_emplace.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
// initialize a vector of vectors by moving v1  
   vector < vector <int> > vv1;  
  
   vv1.emplace( vv1.begin(), move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      {  
      cout << "vv1[0] =";  
      for (Iter = vv1[0].begin( ); Iter != vv1[0].end( ); Iter++ )  
         cout << " " << *Iter;  
      cout << endl;  
      }  
}  
```  
  
```Output  
v1 = 10 20 30  
vv1[0] = 10 20 30  
```  
  
##  <a name="a-namevectoremplacebacka--vectoremplaceback"></a><a name="vector__emplace_back"></a> vector::emplace_back  
 Adiciona um elemento construído no local ao final do vetor.  
  
```  
template <class... Types>  
void emplace_back(Types&&... _Args);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Args`|Argumentos de construtor. A função infere qual sobrecarga de construtor deve ser invocada com base nos argumentos fornecidos.|  
  
### <a name="example"></a>Exemplo  
  
```cpp  
#include <vector>  
struct obj  
{  
   obj(int, double) {}  
};  
  
int main()  
{  
   std::vector<obj> v;  
   v.emplace_back(1, 3.14); // obj in created in place in the vector  
}  
  
```  
  
##  <a name="a-namevectoremptya--vectorempty"></a><a name="vector__empty"></a> vector::empty  
 Testa se o vetor está vazio.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o vetor estiver vazio; **false** se o vetor não estiver vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_empty.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
  
   if ( v1.empty( ) )  
      cout << "The vector is empty." << endl;  
   else  
      cout << "The vector is not empty." << endl;  
}  
```  
  
```Output  
The vector is not empty.  
```  
  
##  <a name="a-namevectorenda--vectorend"></a><a name="vector__end"></a> vector::end  
 Retorna o iterador que ultrapassa o fim.  
  
```  
iterator end();

const_iterator end() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O iterador que ultrapassa o fim do vetor. Se o vetor estiver vazio, `vector::end() == vector::begin()`.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado de **end** for atribuído a uma variável de tipo `const_iterator`, o objeto vector não poderá ser modificado. Se o valor retornado de **end** for atribuído a uma variável do tipo **iterator**, o objeto vector poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_end.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
int main( )  
{  
   using namespace std;  
   vector <int> v1;  
   vector <int>::iterator v1_Iter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )  
      cout << *v1_Iter << endl;  
}  
```  
  
```Output  
1  
2  
```  
  
##  <a name="a-namevectorerasea--vectorerase"></a><a name="vector__erase"></a> vector::erase  
 Remove um elemento ou um intervalo de elementos em um vetor das posições especificadas.  
  
```  
iterator erase(
    const_iterator _Where);

iterator erase(
    const_iterator first,  
    const_iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|Posição do elemento a ser removido do vetor.|  
|` first`|Posição do primeiro elemento removido do vetor.|  
|` last`|Posição após o último elemento removido do vetor.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que designará o primeiro elemento restante além de todos os elementos removidos ou um ponteiro para o final do vetor se esse elemento não existir.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_erase.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
   v1.push_back( 40 );  
   v1.push_back( 50 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.erase( v1.begin( ) );  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.erase( v1.begin( ) + 1, v1.begin( ) + 3 );  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
}  
```  
  
```Output  
v1 = 10 20 30 40 50  
v1 = 20 30 40 50  
v1 = 20 50  
```  
  
##  <a name="a-namevectorfronta--vectorfront"></a><a name="vector__front"></a> vector::front  
 Retorna uma referência ao primeiro elemento em um vetor.  
  
```  
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao primeiro elemento no objeto vector. Se o vetor está vazio, o retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `front` for atribuído a `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `front` for atribuído a **reference**, o objeto vector poderá ser modificado.  
  
 Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro em tempo de execução ocorrerá se você tentar acessar um elemento em um vetor vazio.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_front.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 11 );  
  
   int& i = v1.front( );  
   const int& ii = v1.front( );  
  
   cout << "The first integer of v1 is "<< i << endl;  
   // by incrementing i, we move the the front reference to the second element  
   i++;  
   cout << "Now, the first integer of v1 is "<< i << endl;  
}  
```  
  
##  <a name="a-namevectorgetallocatora--vectorgetallocator"></a><a name="vector__get_allocator"></a> vector::get_allocator  
 Retorna uma cópia do objeto allocator usado para construir o vetor.  
  
```  
Allocator get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alocador usado pelo vetor.  
  
### <a name="remarks"></a>Comentários  
 Os alocadores da classe vector especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_get_allocator.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   // The following lines declare objects that use the default allocator.  
   vector<int> v1;  
   vector<int, allocator<int> > v2 = vector<int, allocator<int> >(allocator<int>( )) ;  
  
   // v3 will use the same allocator class as v1  
   vector <int> v3( v1.get_allocator( ) );  
  
   vector<int>::allocator_type xvec = v3.get_allocator( );  
   // You can now call functions on the allocator class used by vec  
}  
```  
  
##  <a name="a-namevectorinserta--vectorinsert"></a><a name="vector__insert"></a> vector::insert  
 Insere um elemento, uma série de elementos ou um intervalo de elementos no vetor em uma posição especificada.  
  
```  
iterator insert(
    const_iterator _Where,  
    const Type& val);

iterator insert(
    const_iterator _Where,  
    Type&& val);

void insert(
    const_iterator _Where,  
    size_type count,  
    const Type& val);

template <class InputIterator>  
void insert(
    const_iterator _Where,  
    InputIterator first,  
    InputIterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|A posição no vetor em que o primeiro elemento é inserido.|  
|`val`|O valor do elemento sendo inserido no vetor.|  
|`count`|O número de elementos sendo inseridos no vetor.|  
|`first`|A posição do primeiro elemento no intervalo de elementos a serem copiados.|  
|`last`|A posição do primeiro elemento além do intervalo de elementos a serem copiados.|  
  
### <a name="return-value"></a>Valor de retorno  
 As duas primeiras funções `insert` retornam um iterador que aponta para a posição na qual o novo elemento foi inserido no vetor.  
  
### <a name="remarks"></a>Comentários  
 Como precondição, `first` e `last` não deverão ser iteradores no vetor ou o comportamento será indefinido. Qualquer operação de inserção pode ser cara, consulte [Classe vector](../standard-library/vector-class.md) para ver uma discussão sobre o desempenho de `vector`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_insert.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.insert( v1.begin( ) + 1, 40 );  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
   v1.insert( v1.begin( ) + 2, 4, 50 );  
  
   cout << "v1 =";  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
   v1.insert( v1.begin( )+1, v1.begin( )+2, v1.begin( )+4 );  
   cout << "v1 =";  
   for (Iter = v1.begin( ); Iter != v1.end( ); Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
// initialize a vector of vectors by moving v1  
   vector < vector <int> > vv1;  
  
   vv1.insert( vv1.begin(), move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      {  
      vector < vector <int> >::iterator Iter;  
      cout << "vv1[0] =";  
      for (Iter = vv1[0].begin( ); Iter != vv1[0].end( ); Iter++ )  
         cout << " " << *Iter;  
      cout << endl;  
      }  
}  
```  
  
```Output  
v1 = 10 20 30  
v1 = 10 40 20 30  
v1 = 10 40 50 50 50 50 20 30  
v1 = 10 50 50 40 50 50 50 50 20 30  
vv1[0] = 10 50 50 40 50 50 50 50 20 30  
```  
  
##  <a name="a-namevectoriteratora--vectoriterator"></a><a name="vector__iterator"></a> vector::iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **iterator** pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [begin](#vector__begin).  
  
##  <a name="a-namevectormaxsizea--vectormaxsize"></a><a name="vector__max_size"></a> vector::max_size  
 Retorna o tamanho máximo do vetor.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho máximo possível do vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_max_size.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::size_type i;  
  
   i = v1.max_size( );     
   cout << "The maximum possible length of the vector is " << i << "." << endl;  
}  
```  
  
##  <a name="a-namevectoroperatorata--vectoroperator"></a><a name="vector__operator_at"></a> vector::operator[]  
 Retorna uma referência para o elemento de vetor em uma posição especificada.  
  
```  
reference operator[](size_type Pos);

const_reference operator[](size_type Pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Pos`|A posição do elemento de vetor.|  
  
### <a name="return-value"></a>Valor de retorno  
 Se a posição especificada for maior ou igual ao tamanho do contêiner, o resultado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `operator[]` for atribuído a `const_reference`, o objeto de vetor não poderá ser modificado. Se o valor de retorno de `operator[]` for atribuído a uma referência, o objeto de vetor poderá ser modificado.  
  
 Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro em tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do vetor.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_op_ref.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
  
   int& i = v1[1];  
   cout << "The second integer of v1 is " << i << endl;  
}  
```  
  
##  <a name="a-namevectoroperatoreqa--vectoroperator"></a><a name="vector__operator_eq"></a> vector::operator=  
 Substitui os elementos do vetor por uma cópia de outro vetor.  
  
```  
vector& operator=(const vector& right);

vector& operator=(vector&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` right`|O [vetor](../standard-library/vector-class.md) sendo copiado para o `vector`.|  
  
### <a name="remarks"></a>Comentários  
 Após apagar os elementos existentes em um `vector`, `operator=` copiará ou moverá o conteúdo de ` right` para `vector`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_operator_as.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector<int> v1, v2, v3;  
   vector<int>::iterator iter;  
  
   v1.push_back(10);  
   v1.push_back(20);  
   v1.push_back(30);  
   v1.push_back(40);  
   v1.push_back(50);  
  
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
  
##  <a name="a-namevectorpointera--vectorpointer"></a><a name="vector__pointer"></a> vector::pointer  
 Um tipo que fornece um ponteiro para um elemento em um vetor.  
  
```  
typedef typename Allocator::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **pointer** pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_pointer.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector<int> v;  
   v.push_back( 11 );  
   v.push_back( 22 );  
  
   vector<int>::pointer ptr = &v[0];  
   cout << *ptr << endl;  
   ptr++;  
   cout << *ptr << endl;  
 *ptr = 44;  
   cout << *ptr << endl;  
}  
```  
  
```Output  
11  
22  
44  
```  
  
##  <a name="a-namevectorpopbacka--vectorpopback"></a><a name="vector__pop_back"></a> vector::pop_back  
 Exclui o elemento no final do vetor.  
  
```  
void pop_back();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo de código, consulte [vector::push_back()](#vector__push_back).  
  
##  <a name="a-namevectorpushbacka--vectorpushback"></a><a name="vector__push_back"></a> vector::push_back  
 Adiciona um elemento ao final do vetor.  
  
```  
void push_back(const T& Val);

 
void push_back(T&& Val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Val`  
 O valor a ser atribuído ao elemento adicionado ao final do vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// compile with: /EHsc /W4  
#include <vector>  
#include <iostream>  
  
using namespace std;  
  
template <typename T> void print_elem(const T& t) {  
    cout << "(" << t << ") ";  
}  
  
template <typename T> void print_collection(const T& t) {  
    cout << "  " << t.size() << " elements: ";  
  
    for (const auto& p : t) {  
        print_elem(p);  
    }  
    cout << endl;  
}  
  
int main()  
{  
    vector<int> v;  
    for (int i = 0; i < 10; ++i) {  
        v.push_back(10 + i);  
    }  
  
    cout << "vector data: " << endl;  
    print_collection(v);  
  
    // pop_back() until it's empty, printing the last element as we go  
    while (v.begin() != v.end()) {   
        cout << "v.back(): "; print_elem(v.back()); cout << endl;  
        v.pop_back();  
    }  
}  
```  
  
##  <a name="a-namevectorrbegina--vectorrbegin"></a><a name="vector__rbegin"></a> vector::rbegin  
 Retorna um iterador para o primeiro elemento em um vetor invertido.  
  
```  
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que endereça o primeiro elemento em um vetor invertido ou que endereça qual foi o último elemento no vetor não invertido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno de `rbegin` for atribuído a `const_reverse_iterator`, o objeto de vetor não poderá ser modificado. Se o valor retornado de `rbegin` for atribuído a `reverse_iterator`, o objeto vector poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_rbegin.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::iterator v1_Iter;  
   vector <int>::reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of vector is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.rbegin( );  
   cout << "The first element of the reversed vector is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of vector is 1.  
The first element of the reversed vector is 2.  
```  
  
##  <a name="a-namevectorreferencea--vectorreference"></a><a name="vector__reference"></a> vector::reference  
 Um tipo que fornece uma referência a um elemento armazenado em um vetor.  
  
```  
typedef typename Allocator::reference reference;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte [at](#vector__at) para obter um exemplo de como usar **reference** na classe vector.  
  
##  <a name="a-namevectorrenda--vectorrend"></a><a name="vector__rend"></a> vector::rend  
 Retorna um iterador que endereça o local após o último elemento em um vetor invertido.  
  
```  
const_reverse_iterator rend() const;
reverse_iterator rend();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que endereça o local após o último elemento em um vetor invertido (o local que precedeu o primeiro elemento no vetor não invertido).  
  
### <a name="remarks"></a>Comentários  
 `rend` é usado com um vetor invertido, assim como [end](#vector__end) é usado com um vetor.  
  
 Se o valor retornado de `rend` for atribuído a `const_reverse_iterator`, o objeto vector não poderá ser modificado. Se o valor retornado de `rend` for atribuído a `reverse_iterator`, o objeto vector poderá ser modificado.  
  
 `rend` pode ser usado para testar se um iterador invertido alcançou o final de seu vetor.  
  
 O valor retornado por `rend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_rend.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )  
      cout << *v1_rIter << endl;  
}  
```  
  
```Output  
2  
1  
```  
  
##  <a name="a-namevectorreservea--vectorreserve"></a><a name="vector__reserve"></a> vector::reserve  
 Reserva um tamanho mínimo de armazenamento para um objeto vector alocando espaço se necessário.  
  
```  
void reserve(size_type count);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 O tamanho mínimo de armazenamento a ser alocado para o vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_reserve.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   //vector <int>::iterator Iter;  
  
   v1.push_back( 1 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
   v1.reserve( 20 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
}  
```  
  
```Output  
Current capacity of v1 = 1  
Current capacity of v1 = 20  
```  
  
##  <a name="a-namevectorresizea--vectorresize"></a><a name="vector__resize"></a> vector::resize  
 Especifica um novo tamanho para um vetor.  
  
```  
void resize(size_type Newsize);
void resize(size_type Newsize, Type Val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Newsize`  
 O novo tamanho do vetor.  
  
 `Val`  
 O valor de inicialização de novos elementos adicionados ao vetor, caso o novo tamanho seja maior que o tamanho original. Se o valor for omitido, os novos objetos usarão o construtor padrão.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho do contêiner for menor que o tamanho solicitado, `Newsize`, são adicionados os elementos ao vetor até ele atingir o tamanho solicitado. Se o tamanho do contêiner for maior que o tamanho solicitado, os elementos mais próximos do final do contêiner são excluídos até o contêiner chegar ao tamanho `Newsize`. Se o tamanho atual do contêiner for igual ao tamanho solicitado, nenhuma ação será realizada.  
  
 [size](#vector__size) reflete o tamanho atual do vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vectorsizing.cpp  
// compile with: /EHsc /W4  
// Illustrates vector::reserve, vector::max_size,  
// vector::resize, vector::resize, and vector::capacity.  
//  
// Functions:  
//  
//    vector::max_size - Returns maximum number of elements vector could  
//                       hold.  
//  
//    vector::capacity - Returns number of elements for which memory has  
//                       been allocated.  
//  
//    vector::size - Returns number of elements in the vector.  
//  
//    vector::resize - Reallocates memory for vector, preserves its  
//                     contents if new size is larger than existing size.  
//  
//    vector::reserve - Allocates elements for vector to ensure a minimum  
//                      size, preserving its contents if the new size is  
//                      larger than existing size.  
//  
//    vector::push_back - Appends (inserts) an element to the end of a  
//                        vector, allocating memory for it if necessary.  
//  
//////////////////////////////////////////////////////////////////////  
  
// The debugger cannot handle symbols more than 255 characters long.  
// The C++ Standard Library often creates symbols longer than that.  
// The warning can be disabled:  
//#pragma warning(disable:4786)  
  
#include <iostream>  
#include <vector>  
#include <string>  
  
using namespace std;  
  
template <typename C> void print(const string& s, const C& c) {  
    cout << s;  
  
    for (const auto& e : c) {  
        cout << e << " ";  
    }  
    cout << endl;  
}  
  
void printvstats(const vector<int>& v) {  
    cout << "   the vector's size is: " << v.size() << endl;  
    cout << "   the vector's capacity is: " << v.capacity() << endl;  
    cout << "   the vector's maximum size is: " << v.max_size() << endl;  
}  
  
int main()  
{  
    // declare a vector that begins with 0 elements.  
    vector<int> v;  
  
    // Show statistics about vector.  
    cout << endl << "After declaring an empty vector:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    // Add one element to the end of the vector.  
    v.push_back(-1);  
    cout << endl << "After adding an element:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    for (int i = 1; i < 10; ++i) {  
        v.push_back(i);  
    }  
    cout << endl << "After adding 10 elements:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    v.resize(6);  
    cout << endl << "After resizing to 6 elements without an initialization value:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    v.resize(9, 999);  
    cout << endl << "After resizing to 9 elements with an initialization value of 999:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    v.resize(12);  
    cout << endl << "After resizing to 12 elements without an initialization value:" << endl;  
    printvstats(v);  
    print("   the vector's contents: ", v);  
  
    // Ensure there's room for at least 1000 elements.  
    v.reserve(1000);  
    cout << endl << "After vector::reserve(1000):" << endl;  
    printvstats(v);  
  
    // Ensure there's room for at least 2000 elements.  
    v.resize(2000);  
    cout << endl << "After vector::resize(2000):" << endl;  
    printvstats(v);  
}  
```  
  
##  <a name="a-namevectorreverseiteratora--vectorreverseiterator"></a><a name="vector__reverse_iterator"></a> vector::reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor invertido.  
  
```  
typedef std::reverse_iterator<iterator> reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `reverse_iterator` é usado para iterar no vetor em ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [rbegin](#vector__rbegin).  
  
##  <a name="a-namevectorshrinktofita--vectorshrinktofit"></a><a name="vector__shrink_to_fit"></a> vector::shrink_to_fit  
 Descarta o excesso de capacidade.  
  
```  
void shrink_to_fit();
```  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_shrink_to_fit.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   //vector <int>::iterator Iter;  
  
   v1.push_back( 1 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
   v1.reserve( 20 );  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
   v1.shrink_to_fit();  
   cout << "Current capacity of v1 = "   
      << v1.capacity( ) << endl;  
}  
```  
  
```Output  
Current capacity of v1 = 1  
Current capacity of v1 = 20  
Current capacity of v1 = 1  
```  
  
##  <a name="a-namevectorsizea--vectorsize"></a><a name="vector__size"></a> vector::size  
 Retorna o número de elementos no vetor.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_size.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1;  
   vector <int>::size_type i;  
  
   v1.push_back( 1 );  
   i = v1.size( );  
   cout << "Vector length is " << i << "." << endl;  
  
   v1.push_back( 2 );  
   i = v1.size( );  
   cout << "Vector length is now " << i << "." << endl;  
}  
```  
  
```Output  
Vector length is 1.  
Vector length is now 2.  
```  
  
##  <a name="a-namevectorsizetypea--vectorsizetype"></a><a name="vector__size_type"></a> vector::size_type  
 Um tipo que conta o número de elementos em um vetor.  
  
```  
typedef typename Allocator::size_type size_type;  
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [capacity](#vector__capacity).  
  
##  <a name="a-namevectorswapa--vectorswap"></a><a name="vector__swap"></a> vector::swap  
 Troca os elementos de dois vetores.  
  
```  
void swap(
    vector<Type, Allocator>& right);

friend void swap(
    vector<Type, Allocator>& left,  
    vector<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Um vetor que fornece os elementos a serem trocados ou um vetor cujos elementos deverão ser trocados por aqueles do vetor ` left`.  
  
 ` left`  
 Um vetor cujos elementos deverão ser trocados por aqueles do vetor ` right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_swap.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   vector <int> v1, v2;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
   v1.push_back( 3 );  
  
   v2.push_back( 10 );  
   v2.push_back( 20 );  
  
   cout << "The number of elements in v1 = " << v1.size( ) << endl;  
   cout << "The number of elements in v2 = " << v2.size( ) << endl;  
   cout << endl;  
  
   v1.swap( v2 );  
  
   cout << "The number of elements in v1 = " << v1.size( ) << endl;  
   cout << "The number of elements in v2 = " << v2.size( ) << endl;  
}  
```  
  
```Output  
The number of elements in v1 = 3  
The number of elements in v2 = 2  
  
The number of elements in v1 = 2  
The number of elements in v2 = 3  
```  
  
##  <a name="a-namevectorvaluetypea--vectorvaluetype"></a><a name="vector__value_type"></a> vector::value_type  
 Um tipo que representa o tipo de dados armazenado em um vetor.  
  
```  
typedef typename Allocator::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `value_type` é um sinônimo do parâmetro de modelo **Type**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_value_type.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   vector<int>::value_type AnInt;  
   AnInt = 44;  
   cout << AnInt << endl;  
}  
```  
  
```Output  
44  
```  
  
##  <a name="a-namevectorvectora--vectorvector"></a><a name="vector__vector"></a> vector::vector  
 Constrói um vetor de tamanho específico com elementos de valor específico, com um alocador específico ou como uma cópia de toda ou parte de algum outro vetor.  
  
```  
vector();
explicit vector(const Allocator& Al);
explicit vector(size_type Count);
vector(size_type Count, const Type& Val);
vector(size_type Count, const Type& Val, const Allocator& Al);

vector(const vector& Right);
vector(vector&& Right);
vector(initializer_list<Type> IList, const _Allocator& Al);

template <class InputIterator>  
vector(InputIterator First, InputIterator Last);
template <class InputIterator>  
vector(InputIterator First, InputIterator Last, const Allocator& Al);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Al`|A classe de alocador a ser usada com esse objeto. [get_allocator](#vector__get_allocator) retorna a classe allocator do objeto.|  
|`Count`|O número de elementos no vetor construído.|  
|`Val`|O valor dos elementos no vetor construído.|  
|`Right`|O vetor do qual o vetor construído deve ser uma cópia.|  
|`First`|A posição do primeiro elemento no intervalo de elementos a ser copiado.|  
|`Last`|A posição do primeiro elemento após o intervalo de elementos a ser copiado.|  
|`IList`|A initializer_list que contém os elementos a serem copiados.|  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto allocator (`Al`) e iniciam o vetor.  
  
 Os primeiros dois construtores especificam um vetor inicial vazio. O segundo especifica explicitamente o tipo allocator (`Al`) a ser usado.  
  
 O terceiro construtor especifica uma repetição de um número especificado (`Count`) de elementos do valor padrão para a classe `Type`.  
  
 O quarto e o quinto construtor especificam a repetição de (`Count`) elementos de valor `Val`.  
  
 O sexto construtor especifica uma cópia do vetor `Right`.  
  
 O sétimo construtor move o vetor `Right`.  
  
 O oitavo construtor usa initializer_list para especificar os elementos.  
  
 Os construtores nono e décimo copiam o intervalo [ `First`, `Last`) de um vetor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// vector_ctor.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    vector <int>::iterator v1_Iter, v2_Iter, v3_Iter, v4_Iter, v5_Iter, v6_Iter;  
  
    // Create an empty vector v0  
    vector <int> v0;  
  
    // Create a vector v1 with 3 elements of default value 0  
    vector <int> v1(3);  
  
    // Create a vector v2 with 5 elements of value 2  
    vector <int> v2(5, 2);  
  
    // Create a vector v3 with 3 elements of value 1 and with the allocator   
    // of vector v2  
    vector <int> v3(3, 1, v2.get_allocator());  
  
    // Create a copy, vector v4, of vector v2  
    vector <int> v4(v2);  
  
    // Create a new temporary vector for demonstrating copying ranges  
    vector <int> v5(5);  
    for (auto i : v5) {  
        v5[i] = i;  
    }  
  
    // Create a vector v6 by copying the range v5[ first,  last)  
    vector <int> v6(v5.begin() + 1, v5.begin() + 3);  
  
    cout << "v1 =";  
    for (auto& v : v1){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v2 =";  
    for (auto& v : v2){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v3 =";  
    for (auto& v : v3){  
        cout << " " << v;  
    }  
    cout << endl;  
    cout << "v4 =";  
    for (auto& v : v4){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v5 =";  
    for (auto& v : v5){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    cout << "v6 =";  
    for (auto& v : v6){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    // Move vector v2 to vector v7  
    vector <int> v7(move(v2));  
    vector <int>::iterator v7_Iter;  
  
    cout << "v7 =";  
    for (auto& v : v7){  
        cout << " " << v;  
    }  
    cout << endl;  
  
    vector<int> v8{ { 1, 2, 3, 4 } };  
    for (auto& v : v8){  
        cout << " " << v ;  
    }  
    cout << endl;  
}  
  
```  
  
```Output  
v1 = 0 0 0v2 = 2 2 2 2 2v3 = 1 1 1v4 = 2 2 2 2 2v5 = 0 1 2 3 4v6 = 1 2v7 = 2 2 2 2 21 2 3 4  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)


