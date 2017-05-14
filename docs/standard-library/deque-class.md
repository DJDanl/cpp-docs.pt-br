---
title: Classe deque | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- deque
- deque/std::deque
- deque/std::deque::allocator_type
- deque/std::deque::const_iterator
- deque/std::deque::const_pointer
- deque/std::deque::const_reference
- deque/std::deque::const_reverse_iterator
- deque/std::deque::difference_type
- deque/std::deque::iterator
- deque/std::deque::pointer
- deque/std::deque::reference
- deque/std::deque::reverse_iterator
- deque/std::deque::size_type
- deque/std::deque::value_type
- deque/std::deque::assign
- deque/std::deque::at
- deque/std::deque::back
- deque/std::deque::begin
- deque/std::deque::cbegin
- deque/std::deque::cend
- deque/std::deque::clear
- deque/std::deque::crbegin
- deque/std::deque::crend
- deque/std::deque::emplace
- deque/std::deque::emplace_back
- deque/std::deque::emplace_front
- deque/std::deque::empty
- deque/std::deque::end
- deque/std::deque::erase
- deque/std::deque::front
- deque/std::deque::get_allocator
- deque/std::deque::insert
- deque/std::deque::max_size
- deque/std::deque::pop_back
- deque/std::deque::pop_front
- deque/std::deque::push_back
- deque/std::deque::push_front
- deque/std::deque::rbegin
- deque/std::deque::rend
- deque/std::deque::resize
- deque/std::deque::shrink_to_fit
- deque/std::deque::size
- deque/std::deque::swap
dev_langs:
- C++
helpviewer_keywords:
- deque class, about deque class
- deque class
ms.assetid: 64842ee5-057a-4063-8c16-4267a0332584
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 6d3f4d5eee3da48a8503b18695f68db91c22d391
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="deque-class"></a>Classe deque
Organiza os elementos de determinado tipo em uma organização linear e, como um vetor, permite o acesso aleatório rápido a qualquer elemento e uma inserção e exclusão eficientes na parte posterior do contêiner. No entanto, ao contrário de um vetor, a classe `deque` também dá suporte à inserção e exclusão eficientes na frente do contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```unstlib  
template <class Type, class Allocator =allocator<Type>>  
class deque  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Type`  
 O tipo de dados do elemento a ser armazenado no deque.  
  
 `Allocator`  
 O tipo que representa o objeto alocador armazenado que encapsula detalhes sobre a alocação e desalocação de memória do deque. Esse argumento é opcional e o valor padrão é **allocator\<Type>***.*  
  
## <a name="remarks"></a>Comentários  
 A escolha do tipo de contêiner deve se basear, de modo geral, no tipo de pesquisa e inserção exigido pelo aplicativo. [Vetores](../standard-library/vector-class.md) devem ser o contêiner preferencial para gerenciar uma sequência quando o acesso aleatório a qualquer elemento é alto e inserções e exclusões de elementos apenas são necessárias no fim de uma sequência. O desempenho do contêiner de lista é superior quando inserções e exclusões eficientes (em tempo constante) em qualquer local na sequência são altas. Essas operações no meio da sequência exigem cópias de elemento e atribuições proporcionais ao número de elementos na sequência (tempo linear).  
  
 A realocação do deque ocorre quando uma função de membro deve inserir ou apagar elementos da sequência:  
  
-   Se um elemento for inserido em uma sequência vazia ou se um elemento for apagado para deixar uma sequência vazia, os iteradores retornados anteriormente por [begin](#begin) e [end](#end) se tornarão inválidos.  
  
-   Se um elemento for inserido na primeira posição do deque, todos os iteradores, mas nenhuma referência, que designam os elementos existentes se tornarão inválidos.  
  
-   Se um elemento for inserido ao final do deque, [end](#end) e todos os iteradores, mas nenhuma referência, que designam os elementos existentes se tornarão inválidos.  
  
-   Se um elemento for apagado na frente do deque, somente esse iterador e as referências ao elemento apagado se tornarão inválidas.  
  
-   Se o último elemento for apagado do final do deque, somente esse iterador do elemento final e as referências ao elemento apagado se tornarão inválidos.  
  
 Caso contrário, inserir ou apagar um elemento invalidará todos os iteradores e todas as referências.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[deque](#deque)|Constrói um `deque.` vários construtores são fornecidos para configurar o conteúdo do novo `deque` maneiras diferentes: vazio; carregado com um número especificado de elementos vazios; conteúdo movidos ou copiados de outra `deque`; conteúdo copiado ou movido por meio de um iterador; e um elemento é copiado para o `deque` `count` vezes. Alguns dos construtores habilitam usando um `allocator` personalizado para criar elementos.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[allocator_type](#allocator_type)|Um tipo que representa a classe `allocator` para o objeto `deque`.|  
|[const_iterator](#const_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler elementos no `deque` como `const`|  
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro para um elemento em um `deque` como um `const.`|  
|[const_reference](#const_reference)|Um tipo que fornece uma referência a um elemento em um `deque` para leitura e outras operações como um `const.`|  
|[const_reverse_iterator](#const_reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler elementos no `deque` como `const`. O deque é exibido na ordem inversa. Para obter mais informações, consulte [Classe reverse_iterator](../standard-library/reverse-iterator-class.md)|  
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre dois iteradores de acesso aleatório que se referem a elementos no mesmo `deque`.|  
|[iterator](#iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um `deque`.|  
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento em um `deque`.|  
|[reference](#reference)|Um tipo que fornece uma referência a um elemento armazenado em um `deque`.|  
|[reverse_iterator](#reverse_iterator)|Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar um elemento em um `deque`. O deque é exibido na ordem inversa.|  
|[size_type](#size_type)|Um tipo que conta o número de elementos em um `deque`.|  
|[value_type](#value_type)|Um tipo que representa o tipo de dados armazenado em um `deque`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[assign](#assign)|Apaga os elementos de um `deque` e copia uma nova sequência de elementos no `deque` de destino.|  
|[at](#at)|Retorna uma referência para o elemento em um local especificado no `deque`.|  
|[back](#back)|Retorna uma referência para o último elemento do `deque`.|  
|[begin](#begin)|Retorna um iterador de acesso aleatório que trata o primeiro elemento no `deque`.|  
|[cbegin](#cbegin)|Retorna um iterador const para o primeiro elemento no `deque`.|  
|[cend](#cend)|Retorna um iterador `const` de acesso aleatório que aponta para imediatamente após o fim do `deque`.|  
|[clear](#clear)|Apaga todos os elementos de um `deque`.|  
|[crbegin](#crbegin)|Retorna um iterador const de acesso aleatório para o primeiro elemento em um `deque` exibido na ordem inversa.|  
|[crend](#crend)|Retorna um iterador const de acesso aleatório para o primeiro elemento em um `deque` exibido na ordem inversa.|  
|[emplace](#emplace)|Insere um elemento construído in-loco no `deque` em uma posição especificada.|  
|[emplace_back](#emplace_back)|Adiciona um elemento construído no local ao final do `deque`.|  
|[emplace_front](#emplace_front)|Adiciona um elemento construído no local ao início do `deque`.|  
|[empty](#empty)|Retornará `true` se o `deque` contiver zero elementos e `false` se ele contiver um ou mais elementos.|  
|[end](#end)|Retorna um iterador de acesso aleatório que aponta para imediatamente após o fim do `deque`.|  
|[erase](#erase)|Remove um elemento ou um intervalo de elementos em um `deque` das posições especificadas.|  
|[front](#front)|Retorna uma referência para o primeiro elemento em um `deque`.|  
|[get_allocator](#get_allocator)|Retorna uma cópia do objeto `allocator` que é usada para construir o `deque`.|  
|[insert](#insert)|Insere um elemento, vários elementos ou um intervalo de elementos no `deque` em uma posição especificada.|  
|[max_size](#max_size)|Retorna o tamanho máximo possível do `deque`.|  
|[pop_back](#pop_back)|Apaga o elemento no final do `deque`.|  
|[pop_front](#pop_front)|Apaga o elemento no início do `deque`.|  
|[push_back](#push_back)|Adiciona um elemento ao final do `deque`.|  
|[push_front](#push_front)|Adiciona um elemento ao início do `deque`.|  
|[rbegin](#rbegin)|Retorna um iterador de acesso aleatório para o primeiro elemento em um `deque` inverso.|  
|[rend](#rend)|Retorna um iterador de acesso aleatório que aponta para imediatamente após o último elemento em uma `deque` inversa.|  
|[resize](#resize)|Especifica um novo tamanho para um `deque`.|  
|[shrink_to_fit](#shrink_to_fit)|Descarta o excesso de capacidade.|  
|[size](#size)|Retorna o número de elementos no `deque`.|  
|[swap](#swap)|Troca os elementos de dois `deque`s.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator&#91;&#93;](#op_at)|Retorna uma referência para o elemento `deque` em uma posição especificada.|  
|[operator=](#op_eq)|Substitui os elementos do `deque` por uma cópia de outro `deque`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: \<deque>  
  
##  <a name="allocator_type"></a>  deque::allocator_type  
 Um tipo que representa a classe de alocador para o objeto do deque.  
  
```  
typedef Allocator allocator_type;  
```  
  
### <a name="remarks"></a>Comentários  
 **allocator_type** é um sinônimo do parâmetro de modelo **Allocator**.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [get_allocator](#get_allocator).  
  
##  <a name="assign"></a>  deque::assign  
 Apaga os elementos de um deque e copia um novo conjunto de elementos para o deque de destino.  
  
```  
template <class InputIterator>  
void assign(
    InputIterator First,  
    InputIterator Last);

void assign(
    size_type Count,  
    const Type& Val);

void assign(initializer_list<Type> IList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `First`  
 Posição do elemento primeiro no intervalo de elementos a ser copiado do deque de argumentos.  
  
 `Last`  
 Posição do primeiro elemento após o intervalo de elementos a ser copiado do deque de argumentos.  
  
 `Count`  
 O número de cópias de um elemento que está sendo inserido no deque.  
  
 `Val`  
 O valor do elemento que está sendo inserido no deque.  
  
 `IList`  
 A initializer_list que está sendo inserida no deque.  
  
### <a name="remarks"></a>Comentários  
 Depois de apagar os elementos existentes do deque de destino, `assign` insere um intervalo especificado de elementos do deque original ou de algum outro deque no deque de destino ou insere cópias de um novo elemento de um valor especificado no deque de destino.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_assign.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
#include <initializer_list>  
  
int main()  
{  
    using namespace std;  
    deque <int> c1, c2;  
    deque <int>::const_iterator cIter;  
  
    c1.push_back(10);  
    c1.push_back(20);  
    c1.push_back(30);  
    c2.push_back(40);  
    c2.push_back(50);  
    c2.push_back(60);  
  
    deque<int> d1{ 1, 2, 3, 4 };  
    initializer_list<int> iList{ 5, 6, 7, 8 };  
    d1.assign(iList);  
  
    cout << "d1 = ";  
    for (int i : d1)  
        cout << i;  
    cout << endl;  
  
    cout << "c1 =";  
    for (int i : c1)  
        cout << i;  
    cout << endl;  
  
    c1.assign(++c2.begin(), c2.end());  
    cout << "c1 =";  
    for (int i : c1)  
        cout << i;  
    cout << endl;  
  
    c1.assign(7, 4);  
    cout << "c1 =";  
    for (int i : c1)  
        cout << i;  
    cout << endl;  
  
}  
  
```  
  
```Output  
d1 = 5678c1 =102030c1 =5060c1 =4444444  
```  
  
##  <a name="at"></a>  deque::at  
 Retorna uma referência para o elemento em um local especificado no deque.  
  
```  
reference at(size_type pos);

const_reference at(size_type pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 O subscrito (ou o número da posição) do elemento a ser referenciado no deque.  
  
### <a name="return-value"></a>Valor de retorno  
 Se `pos` for maior que o tamanho do deque, **at** gerará uma exceção.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor retornado **at** for atribuído a um `const_reference`, o objeto do deque não poderá ser modificado. Se o valor retornado **at** for atribuído a uma **reference**, o objeto do deque poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_at.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
  
   const int& i = c1.at( 0 );  
   int& j = c1.at( 1 );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="back"></a>  deque::back  
 Retorna uma referência para o último elemento do deque.  
  
```  
reference back();
const_reference back() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O último elemento do deque. Se o deque estiver vazio, o valor retornado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado **back** for atribuído a uma `const_reference`, o objeto do deque não poderá ser modificado. Se o valor retornado **back** for atribuído a uma **reference**, o objeto do deque poderá ser modificado.  
  
 Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro em tempo de execução ocorrerá se você tentar acessar um elemento em um deque vazio.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_back.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 11 );  
  
   int& i = c1.back( );  
   const int& ii = c1.front( );  
  
   cout << "The last integer of c1 is " << i << endl;  
   i--;  
   cout << "The next-to-last integer of c1 is " << ii << endl;  
}  
```  
  
```Output  
The last integer of c1 is 11  
The next-to-last integer of c1 is 10  
```  
  
##  <a name="begin"></a>  deque::begin  
 Retorna um iterador que trata o primeiro elemento no deque.  
  
```  
const_iterator begin() const;
iterator begin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que trata o primeiro elemento no deque ou o local após um deque vazio.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado **begin** for atribuído a uma `const_iterator`, o objeto do deque não poderá ser modificado. Se o valor retornado **begin** for atribuído a um **iterator**, o objeto do deque poderá ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// deque_begin.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
   deque <int>::const_iterator c1_cIter;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
  
   c1_Iter = c1.begin( );  
   cout << "The first element of c1 is " << *c1_Iter << endl;  
  
 *c1_Iter = 20;  
   c1_Iter = c1.begin( );  
   cout << "The first element of c1 is now " << *c1_Iter << endl;  
  
   // The following line would be an error because iterator is const  
   // *c1_cIter = 200;  
}  
```  
  
```Output  
The first element of c1 is 1  
The first element of c1 is now 20  
```  
  
##  <a name="cbegin"></a>  deque::cbegin  
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
  
##  <a name="cend"></a>  deque::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que aponta para além do fim do intervalo.  
  
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
  
##  <a name="clear"></a>  deque::clear  
 Apaga todos os elementos de um deque.  
  
```  
void clear();
```  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_clear.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   cout << "The size of the deque is initially " << c1.size( ) << endl;  
   c1.clear( );  
   cout << "The size of the deque after clearing is " << c1.size( ) << endl;  
}  
```  
  
```Output  
The size of the deque is initially 3  
The size of the deque after clearing is 0  
```  
  
##  <a name="const_iterator"></a>  deque::const_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode acessar e ler um elemento **const** no deque.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_iterator` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [back](#back).  
  
##  <a name="const_pointer"></a>  deque::const_pointer  
 Fornece um ponteiro para um elemento `const` em um deque.  
  
```
typedef typename Allocator::const_pointer const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_pointer` não pode ser usado para modificar o valor de um elemento. Um [iterator](#iterator) é usado com mais frequência para acessar um elemento do deque.  
  
##  <a name="const_reference"></a>  deque::const_reference  
 Um tipo que fornece uma referência a um elemento **const** armazenado em um deque para leitura e execução de operações **const**.  
  
```  
typedef typename Allocator::const_reference const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo de `const_reference` não pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// deque_const_ref.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
  
   const deque <int> c2 = c1;  
   const int &i = c2.front( );  
   const int &j = c2.back( );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
  
   // The following line would cause an error as c2 is const  
   // c2.push_back( 30 );  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="const_reverse_iterator"></a>  deque::const_reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler qualquer elemento **const** no deque.  
  
```  
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `const_reverse_iterator` não pode modificar o valor de um elemento e é usado para iterar pelo deque na ordem inversa.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [rbegin](#rbegin) para obter um exemplo de como declarar e usar um iterador.  
  
##  <a name="crbegin"></a>  deque::crbegin  
 Retorna um iterador const para o primeiro elemento em um deque inverso.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso const que trata o primeiro elemento em um [deque](../standard-library/deque-class.md) inverso ou que trata aquele que foi o último elemento no `deque` não inverso.  
  
### <a name="remarks"></a>Comentários  
 Com o valor de retorno `crbegin`, o objeto `deque` não pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_crbegin.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   deque <int>::iterator v1_Iter;  
   deque <int>::const_reverse_iterator v1_rIter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of deque is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.crbegin( );  
   cout << "The first element of the reversed deque is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of deque is 1.  
The first element of the reversed deque is 2.  
```  
  
##  <a name="crend"></a>  deque::crend  
 Retorna um iterador const que trata o local após o último elemento em um deque inverso.  
  
```  
const_reverse_iterator crend() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso const que trata o local após o último elemento em um [deque](../standard-library/deque-class.md) inverso (o local que precedeu o primeiro elemento no deque não inverso).  
  
### <a name="remarks"></a>Comentários  
 `crend` é usado com um `deque` inverso, assim como [array::cend](../standard-library/array-class-stl.md#cend) é usado com um `deque`.  
  
 Com o valor retornado de `crend` (adequadamente diminuído), o objeto `deque` não poderá ser modificado.  
  
 `crend` pode ser usado para testar se um iterador inverso chegou ao final de seu deque.  
  
 O valor retornado por `crend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_crend.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   deque <int>::const_reverse_iterator v1_rIter;  
  
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
  
##  <a name="deque"></a>  deque::deque  
 Constrói um deque de um tamanho específico ou com elementos de um valor específico ou com um alocador específico ou como uma cópia de toda ou parte de algum outro deque.  
  
```  
deque();

explicit deque(const Allocator& Al);
explicit deque(size_type Count);
deque(size_type Count, const Type& Val);

deque(
    size_type Count,  
    const Type& Val,  
    const Allocator& Al);

deque(const deque& Right);

template <class InputIterator>  
deque(InputIterator First,  InputIterator Last);

template <class InputIterator>  
deque(
   InputIterator First,  
   InputIterator Last,  
   const Allocator& Al);

deque(initializer_list<value_type> IList, const Allocator& Al);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Al`|A classe de alocador a ser usada com esse objeto.|  
|`Count`|O número de elementos no deque construído.|  
|`Val`|O valor dos elementos no deque construído.|  
|`Right`|O deque dos quais o deque construído deve ser uma cópia.|  
|`First`|A posição do primeiro elemento no intervalo de elementos a ser copiado.|  
|`Last`|A posição do primeiro elemento após o intervalo de elementos a ser copiado.|  
|`IList`|A initializer_list a ser copiada.|  
  
### <a name="remarks"></a>Comentários  
 Todos os construtores armazenam um objeto do alocador (`Al`) e inicializam o deque.  
  
 Os dois primeiros construtores especificam um deque inicial vazio; o segundo também especifica o tipo de alocador (`_Al`) a ser usado.  
  
 O terceiro construtor especifica uma repetição de um número especificado (`count`) de elementos do valor padrão para a classe `Type`.  
  
 O quarto e o quinto construtor especificam a repetição de (`Count`) elementos de valor `val`.  
  
 O sexto construtor especifica uma cópia do deque `Right`.  
  
 Os sétimo e oitavo construtores copiam o intervalo `[First, Last)` de um deque.  
  
 O sétimo construtor move o deque `Right`.  
  
 O oitavo construtor copia o conteúdo de uma initializer_list.  
  
 Nenhum dos construtores executa realocações provisórias.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
/ compile with: /EHsc  
#include <deque>  
#include <iostream>  
#include <forward_list>  
  
int main()  
{  
    using namespace std;  
  
    forward_list<int> f1{ 1, 2, 3, 4 };  
  
    f1.insert_after(f1.begin(), { 5, 6, 7, 8 });  
  
    deque <int>::iterator c1_Iter, c2_Iter, c3_Iter, c4_Iter, c5_Iter, c6_Iter;  
  
    // Create an empty deque c0  
    deque <int> c0;  
  
    // Create a deque c1 with 3 elements of default value 0  
    deque <int> c1(3);  
  
    // Create a deque c2 with 5 elements of value 2  
    deque <int> c2(5, 2);  
  
    // Create a deque c3 with 3 elements of value 1 and with the   
    // allocator of deque c2  
    deque <int> c3(3, 1, c2.get_allocator());  
  
    // Create a copy, deque c4, of deque c2  
    deque <int> c4(c2);  
  
    // Create a deque c5 by copying the range c4[ first,  last)  
    c4_Iter = c4.begin();  
    c4_Iter++;  
    c4_Iter++;  
    deque <int> c5(c4.begin(), c4_Iter);  
  
    // Create a deque c6 by copying the range c4[ first,  last) and   
    // c2 with the allocator of deque  
    c4_Iter = c4.begin();  
    c4_Iter++;  
    c4_Iter++;  
    c4_Iter++;  
    deque <int> c6(c4.begin(), c4_Iter, c2.get_allocator());  
  
    // Create a deque c8 by copying the contents of an initializer_list  
    // using brace initialization  
    deque<int> c8({ 1, 2, 3, 4 });  
  
    initializer_list<int> iList{ 5, 6, 7, 8 };  
    deque<int> c9( iList);  
  
    cout << "c1 = ";  
    for (int i : c1)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c2 = ";  
    for (int i : c2)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c3 = ";  
    for (int i : c3)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c4 = ";  
    for (int i : c4)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c5 = ";  
    for (int i : c5)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c6 = ";  
    for (int i : c6)  
        cout << i << " ";  
    cout << endl;  
  
    // Move deque c6 to deque c7  
    deque <int> c7(move(c6));  
    deque <int>::iterator c7_Iter;  
  
    cout << "c7 =";  
    for (int i : c7)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c8 = ";  
    for (int i : c8)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c9 = ";  
    for (int i : c9)  
        cout << i << " ";  
    cout << endl;  
  
    int x = 3;  
}  
// deque_deque.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
    using namespace std;  
   deque <int>::iterator c1_Iter, c2_Iter, c3_Iter, c4_Iter, c5_Iter, c6_Iter;  
  
    // Create an empty deque c0  
    deque <int> c0;  
  
    // Create a deque c1 with 3 elements of default value 0  
    deque <int> c1( 3 );  
  
    // Create a deque c2 with 5 elements of value 2  
    deque <int> c2( 5, 2 );  
  
    // Create a deque c3 with 3 elements of value 1 and with the   
    // allocator of deque c2  
    deque <int> c3( 3, 1, c2.get_allocator( ) );  
  
    // Create a copy, deque c4, of deque c2  
    deque <int> c4( c2 );  
  
    // Create a deque c5 by copying the range c4[ first,  last)  
    c4_Iter = c4.begin( );  
    c4_Iter++;  
    c4_Iter++;  
    deque <int> c5( c4.begin( ), c4_Iter );  
  
    // Create a deque c6 by copying the range c4[ first,  last) and   
    // c2 with the allocator of deque  
    c4_Iter = c4.begin( );  
   c4_Iter++;  
   c4_Iter++;  
   c4_Iter++;  
   deque <int> c6( c4.begin( ), c4_Iter, c2.get_allocator( ) );  
  
    // Create a deque c8 by copying the contents of an initializer_list  
    // using brace initialization  
    deque<int> c8({ 1, 2, 3, 4 });  
  
        initializer_list<int> iList{ 5, 6, 7, 8 };  
    deque<int> c9( iList);  
  
    cout << "c1 = ";  
    for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
        cout << *c1_Iter << " ";  
    cout << endl;  
  
    cout << "c2 = ";  
    for ( c2_Iter = c2.begin( ); c2_Iter != c2.end( ); c2_Iter++ )  
        cout << *c2_Iter << " ";  
    cout << endl;  
  
    cout << "c3 = ";  
    for ( c3_Iter = c3.begin( ); c3_Iter != c3.end( ); c3_Iter++ )  
        cout << *c3_Iter << " ";  
    cout << endl;  
  
    cout << "c4 = ";  
    for ( c4_Iter = c4.begin( ); c4_Iter != c4.end( ); c4_Iter++ )  
        cout << *c4_Iter << " ";  
    cout << endl;  
  
    cout << "c5 = ";  
    for ( c5_Iter = c5.begin( ); c5_Iter != c5.end( ); c5_Iter++ )  
        cout << *c5_Iter << " ";  
    cout << endl;  
  
    cout << "c6 = ";  
    for ( c6_Iter = c6.begin( ); c6_Iter != c6.end( ); c6_Iter++ )  
        cout << *c6_Iter << " ";  
    cout << endl;  
  
    // Move deque c6 to deque c7  
    deque <int> c7( move(c6) );  
    deque <int>::iterator c7_Iter;  
  
    cout << "c7 =" ;  
    for ( c7_Iter = c7.begin( ) ; c7_Iter != c7.end( ) ; c7_Iter++ )  
        cout << " " << *c7_Iter;  
    cout << endl;  
  
    cout << "c8 = ";  
    for (int i : c8)  
        cout << i << " ";  
    cout << endl;  
  
    cout << "c9 = ";  
    or (int i : c9)  
        cout << i << " ";  
    cout << endl;  
}  
```  
  
##  <a name="difference_type"></a>  deque::difference_type  
 Um tipo que fornece a diferença entre dois iteradores que se referem a elementos no mesmo deque.  
  
```  
typedef typename Allocator::difference_type difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 Um `difference_type` também pode ser descrito como o número de elementos entre dois ponteiros.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_diff_type.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <deque>  
#include <algorithm>  
  
int main( )   
{  
   using namespace std;  
  
   deque <int> c1;  
   deque <int>::iterator c1_Iter, c2_Iter;  
  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
   c1.push_back( 10 );  
   c1.push_back( 30 );  
   c1.push_back( 20 );  
  
   c1_Iter = c1.begin( );  
   c2_Iter = c1.end( );  
  
   deque <int>::difference_type df_typ1, df_typ2, df_typ3;  
  
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
  
##  <a name="emplace"></a>  deque::emplace  
 Insere um elemento construído in-loco no deque em uma posição especificada.  
  
```  
iterator emplace(
    const_iterator _Where,  
    Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`_Where`|A posição no [deque](../standard-library/deque-class.md) em que o primeiro elemento é inserido.|  
|`val`|O valor do elemento que está sendo inserido no `deque`.|  
  
### <a name="return-value"></a>Valor de retorno  
 A função retorna um iterador que aponta para a posição em que o novo elemento foi inserido no deque.  
  
### <a name="remarks"></a>Comentários  
 Uma operação de inserção pode ser cara; consulte `deque` para ver uma discussão sobre o desempenho de `deque`.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_emplace.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   deque <int>::iterator Iter;  
  
   v1.push_back( 10 );  
   v1.push_back( 20 );  
   v1.push_back( 30 );  
  
   cout << "v1 =" ;  
   for ( Iter = v1.begin( ) ; Iter != v1.end( ) ; Iter++ )  
      cout << " " << *Iter;  
   cout << endl;  
  
// initialize a deque of deques by moving v1  
   deque < deque <int> > vv1;  
  
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
  
##  <a name="emplace_back"></a>  deque::emplace_back  
 Adiciona um elemento construído no local ao final do deque.  
  
```  
void emplace_back(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`val`|O elemento adicionado ao final do [deque](../standard-library/deque-class.md).|  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_emplace_back.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
  
   v1.push_back( 1 );  
   if ( v1.size( ) != 0 )  
      cout << "Last element: " << v1.back( ) << endl;  
  
   v1.push_back( 2 );  
   if ( v1.size( ) != 0 )  
      cout << "New last element: " << v1.back( ) << endl;  
  
// initialize a deque of deques by moving v1  
   deque < deque <int> > vv1;  
  
   vv1.emplace_back( move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      cout << "Moved last element: " << vv1[0].back( ) << endl;  
}  
```  
  
```Output  
Last element: 1  
New last element: 2  
Moved last element: 2  
```  
  
##  <a name="emplace_front"></a>  deque::emplace_front  
 Adiciona um elemento construído no local ao final do deque.  
  
```  
void emplace_front(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`val`|O elemento adicionado ao início do [deque](../standard-library/deque-class.md).|  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_emplace_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
  
   v1.push_back( 1 );  
   if ( v1.size( ) != 0 )  
      cout << "Last element: " << v1.back( ) << endl;  
  
   v1.push_back( 2 );  
   if ( v1.size( ) != 0 )  
      cout << "New last element: " << v1.back( ) << endl;  
  
// initialize a deque of deques by moving v1  
   deque < deque <int> > vv1;  
  
   vv1.emplace_front( move( v1 ) );  
   if ( vv1.size( ) != 0 && vv1[0].size( ) != 0 )  
      cout << "Moved last element: " << vv1[0].back( ) << endl;  
}  
```  
  
```Output  
Last element: 1  
New last element: 2  
Moved last element: 2  
```  
  
##  <a name="empty"></a>  deque::empty  
 Testa se um deque está vazio.  
  
```  
bool empty() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o deque estiver vazio; **false** se o deque não estiver vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_empty.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   if ( c1.empty( ) )  
      cout << "The deque is empty." << endl;  
   else  
      cout << "The deque is not empty." << endl;  
}  
```  
  
```Output  
The deque is not empty.  
```  
  
##  <a name="end"></a>  deque::end  
 Retorna um iterador que trata o local após o último elemento em um deque.  
  
```  
const_iterator end() const;

iterator end();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que trata o local após o último elemento em um deque. Se o deque estiver vazio, deque::end == deque::begin.  
  
### <a name="remarks"></a>Comentários  
 **end** é usado para testar se um iterador chegou ao final de seu deque.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_end.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1_Iter = c1.end( );  
   c1_Iter--;  
   cout << "The last integer of c1 is " << *c1_Iter << endl;  
  
   c1_Iter--;  
 *c1_Iter = 400;  
   cout << "The new next-to-last integer of c1 is " << *c1_Iter << endl;  
  
   // If a const iterator had been declared instead with the line:  
   // deque <int>::const_iterator c1_Iter;  
   // an error would have resulted when inserting the 400  
  
   cout << "The deque is now:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
}  
```  
  
```Output  
The last integer of c1 is 30  
The new next-to-last integer of c1 is 400  
The deque is now: 10 400 30  
```  
  
##  <a name="erase"></a>  deque::erase  
 Remove um elemento ou um intervalo de elementos em um deque das posições especificadas.  
  
```  
iterator erase(iterator _Where);

iterator erase(iterator first, iterator last);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Where`  
 Posição do elemento a ser removido do deque.  
  
 `first`  
 Posição do primeiro elemento removido do deque.  
  
 `last`  
 Posição imediatamente após o último elemento removido do deque.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório que designa o primeiro elemento restante além de todos os elementos removidos ou um ponteiro para o fim do deque se não houver um elemento desse tipo.  
  
### <a name="remarks"></a>Comentários  
 **erase** nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_erase.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator Iter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
   c1.push_back( 40 );  
   c1.push_back( 50 );  
   cout << "The initial deque is: ";  
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )  
      cout << *Iter << " ";  
   cout << endl;  
   c1.erase( c1.begin( ) );  
   cout << "After erasing the first element, the deque becomes:  ";  
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )  
      cout << *Iter << " ";  
   cout << endl;  
   Iter = c1.begin( );  
   Iter++;  
   c1.erase( Iter, c1.end( ) );  
   cout << "After erasing all elements but the first, deque becomes: ";  
   for ( Iter = c1.begin( ); Iter != c1.end( ); Iter++ )  
      cout << *Iter << " ";  
   cout << endl;  
}  
```  
  
```Output  
The initial deque is: 10 20 30 40 50   
After erasing the first element, the deque becomes:  20 30 40 50   
After erasing all elements but the first, deque becomes: 20   
```  
  
##  <a name="front"></a>  deque::front  
 Retorna uma referência para o primeiro elemento em um deque.  
  
```  
reference front();

const_reference front() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o deque estiver vazio, o retorno será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado `front` for atribuído a um `const_reference`, o objeto do deque não poderá ser modificado. Se o valor retornado `front` for atribuído a uma **reference**, o objeto do deque poderá ser modificado.  
  
 Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro em tempo de execução ocorrerá se você tentar acessar um elemento em um deque vazio.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 11 );  
  
   int& i = c1.front( );  
   const int& ii = c1.front( );  
  
   cout << "The first integer of c1 is " << i << endl;  
   i++;  
   cout << "The second integer of c1 is " << ii << endl;  
}  
```  
  
```Output  
The first integer of c1 is 10  
The second integer of c1 is 11  
```  
  
##  <a name="get_allocator"></a>  deque::get_allocator  
 Retorna uma cópia do objeto alocador usado para construir o deque.  
  
```  
Allocator get_allocator() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alocador usado pelo deque.  
  
### <a name="remarks"></a>Comentários  
 Alocadores da classe de deque especificam como a classe gerencia o armazenamento. Os alocadores padrão fornecidos com as classes de contêiner da Biblioteca Padrão C++ são suficientes para a maioria das necessidades de programação. Gravando e usando sua própria classe de alocador é um tópico avançado do C++.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_get_allocator.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   // The following lines declare objects that use the default allocator.  
   deque <int> c1;  
   deque <int, allocator<int> > c2 = deque <int, allocator<int> >( allocator<int>( ) );  
  
   // c3 will use the same allocator class as c1  
   deque <int> c3( c1.get_allocator( ) );  
  
   deque <int>::allocator_type xlst = c1.get_allocator( );  
   // You can now call functions on the allocator class used by c1  
}  
```  
  
##  <a name="insert"></a>  deque::insert  
 Insere um elemento, um número de elementos ou um intervalo de elementos no deque em uma posição especificada.  
  
```  
iterator insert(
    const_iterator Where,  
    const Type& Val);

iterator insert(
    const_iterator Where,  
    Type&& Val);

void insert(
    iterator Where,  
    size_type Count,  
    const Type& Val);

template <class InputIterator>  
void insert(
    iterator Where,  
    InputIterator First,  
    InputIterator Last);

iterator insert(
    iterator Where,initializer_list<Type>  
IList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Where`|A posição no deque de destino em que o primeiro elemento é inserido.|  
|`Val`|O valor do elemento que está sendo inserido no deque.|  
|`Count`|O número de elementos que estão sendo inseridos no deque.|  
|`First`|A posição do primeiro elemento no intervalo de elementos no deque de argumentos a ser copiada.|  
|`Last`|A posição do primeiro elemento após o intervalo de elementos no deque de argumentos a ser copiada.|  
|`IList`|A initializer_list de elementos a ser inserida.|  
  
### <a name="return-value"></a>Valor de retorno  
 As duas primeiras funções de inserção retornam um iterador que aponta para a posição em que o novo elemento foi inserido no deque.  
  
### <a name="remarks"></a>Comentários  
 Uma operação de inserção pode ser cara.  
  
##  <a name="iterator"></a>  deque::iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar qualquer elemento em um deque.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **iterator** pode ser usado para modificar o valor de um elemento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [begin](#begin).  
  
##  <a name="max_size"></a>  deque::max_size  
 Retorna o tamanho máximo do deque.  
  
```  
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho máximo possível do deque.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_max_size.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::size_type i;  
  
   i = c1.max_size( );  
   cout << "The maximum possible length of the deque is " << i << "." << endl;  
}  
```  
  
##  <a name="op_at"></a>  deque::operator[]  
 Retorna uma referência para o elemento do deque em uma posição especificada.  
  
```  
reference operator[](size_type pos);

const_reference operator[](size_type pos) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 A posição do elemento de deque a ser referenciada.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao elemento cuja posição é especificada no argumento. Se a posição especificada for maior que o tamanho do deque, o resultado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o valor retornado `operator[]` for atribuído a um `const_reference`, o objeto do deque não poderá ser modificado. Se o valor retornado `operator[]` for atribuído a uma **reference**, o objeto do deque poderá ser modificado.  
  
 Quando compilado usando [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro em tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do deque.  Consulte [Iteradores Verificados](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_op_ref.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   cout << "The first integer of c1 is " << c1[0] << endl;  
   int& i = c1[1];  
   cout << "The second integer of c1 is " << i << endl;  
  
}  
```  
  
```Output  
The first integer of c1 is 10  
The second integer of c1 is 20  
```  
  
##  <a name="op_eq"></a>  deque::operator=  
 Substitui os elementos desse deque usando os elementos de outro deque.  
  
```  
deque& operator=(const deque& right);

deque& operator=(deque&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`right`|O deque que fornece o novo conteúdo.|  
  
### <a name="remarks"></a>Comentários  
 A primeira substituição copia elementos para esse deque de `right`, a origem da atribuição. A segunda substituição move elementos para esse deque de `right`.  
  
 Os elementos contidos nesse deque antes das execuções do operador são removidos.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_operator_as.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
using namespace std;  
  
typedef deque<int> MyDeque;  
  
template<typename MyDeque> struct S;  
  
template<typename MyDeque> struct S<MyDeque&> {  
  static void show( MyDeque& d ) {  
    MyDeque::const_iterator iter;  
    for (iter = d.cbegin(); iter != d.cend(); iter++)  
       cout << *iter << " ";  
    cout << endl;  
  }  
};  
  
template<typename MyDeque> struct S<MyDeque&&> {  
  static void show( MyDeque&& d ) {  
    MyDeque::const_iterator iter;  
    for (iter = d.cbegin(); iter != d.cend(); iter++)  
       cout << *iter << " ";  
cout << " via unnamed rvalue reference " << endl;  
  }  
};  
  
int main( )  
{  
   MyDeque d1, d2;  
  
   d1.push_back(10);  
   d1.push_back(20);  
   d1.push_back(30);  
   d1.push_back(40);  
   d1.push_back(50);  
  
   cout << "d1 = " ;  
   S<MyDeque&>::show( d1 );  
  
   d2 = d1;  
   cout << "d2 = ";  
   S<MyDeque&>::show( d2 );  
  
   cout << "     ";  
   S<MyDeque&&>::show ( move< MyDeque& > (d1) );  
 }  
```  
  
##  <a name="pointer"></a>  deque::pointer  
 Fornece um ponteiro para um elemento em um [deque](../standard-library/deque-class.md).  
  
```unstlib  
typedef typename Allocator::pointer pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo **pointer** pode ser usado para modificar o valor de um elemento. Um [iterator](#iterator) é usado com mais frequência para acessar um elemento do deque.  
  
##  <a name="pop_back"></a>  deque::pop_back  
 Exclui o elemento no final do deque.  
  
```  
void pop_back();
```  
  
### <a name="remarks"></a>Comentários  
 O último elemento não deve estar vazio. `pop_back` nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_pop_back.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   cout << "The first element is: " << c1.front( ) << endl;  
   cout << "The last element is: " << c1.back( ) << endl;  
  
   c1.pop_back( );  
   cout << "After deleting the element at the end of the deque, the "  
      "last element is: " << c1.back( ) << endl;  
}  
```  
  
```Output  
The first element is: 1  
The last element is: 2  
After deleting the element at the end of the deque, the last element is: 1  
```  
  
##  <a name="pop_front"></a>  deque::pop_front  
 Exclui o elemento no início do deque.  
  
```  
void pop_front();
```  
  
### <a name="remarks"></a>Comentários  
 O primeiro elemento não deve estar vazio. `pop_front` nunca gera uma exceção.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_pop_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   cout << "The first element is: " << c1.front( ) << endl;  
   cout << "The second element is: " << c1.back( ) << endl;  
  
   c1.pop_front( );  
   cout << "After deleting the element at the beginning of the "  
      "deque, the first element is: " << c1.front( ) << endl;  
}  
```  
  
```Output  
The first element is: 1  
The second element is: 2  
After deleting the element at the beginning of the deque, the first element is: 2  
```  
  
##  <a name="push_back"></a>  deque::push_back  
 Adiciona um elemento ao final do deque.  
  
```  
void push_back(const Type& val);

void push_back(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`val`|O elemento adicionado ao final do deque.|  
  
### <a name="remarks"></a>Comentários  
 Se uma exceção for gerada, o deque permanecerá inalterado e a exceção será gerada novamente.  
  
##  <a name="push_front"></a>  deque::push_front  
 Adiciona um elemento ao início do deque.  
  
```  
    void push_front(const Type& val);

void push_front(Type&& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`val`|O elemento adicionado ao início do deque.|  
  
### <a name="remarks"></a>Comentários  
 Se uma exceção for gerada, o deque permanecerá inalterado e a exceção será gerada novamente.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_push_front.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
#include <string>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_front( 1 );  
   if ( c1.size( ) != 0 )  
      cout << "First element: " << c1.front( ) << endl;  
  
   c1.push_front( 2 );  
   if ( c1.size( ) != 0 )  
      cout << "New first element: " << c1.front( ) << endl;  
  
// move initialize a deque of strings  
   deque <string> c2;  
   string str("a");  
  
   c2.push_front( move( str ) );  
   cout << "Moved first element: " << c2.front( ) << endl;  
}  
```  
  
```Output  
First element: 1  
New first element: 2  
Moved first element: a  
```  
  
##  <a name="rbegin"></a>  deque::rbegin  
 Retorna um iterador para o primeiro elemento em um deque inverso.  
  
```  
const_reverse_iterator rbegin() const;

reverse_iterator rbegin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que trata o primeiro elemento em um deque inverso ou que trata aquele que foi o último elemento no deque não inverso.  
  
### <a name="remarks"></a>Comentários  
 `rbegin` é usado com um deque inverso, assim como [begin](#begin) é usado com um deque.  
  
 Se o valor retornado `rbegin` for atribuído a um `const_reverse_iterator`, o objeto do deque não poderá ser modificado. Se o valor retornado `rbegin` for atribuído a um `reverse_iterator`, o objeto do deque poderá ser modificado.  
  
 `rbegin` pode ser usado para iterar por um deque na ordem inversa.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_rbegin.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
   deque <int>::reverse_iterator c1_rIter;  
  
   // If the following line had replaced the line above, an error   
   // would have resulted in the line modifying an element   
   // (commented below) because the iterator would have been const  
   // deque <int>::const_reverse_iterator c1_rIter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1_rIter = c1.rbegin( );  
   cout << "Last element in the deque is " << *c1_rIter << "." << endl;  
  
   cout << "The deque contains the elements: ";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << *c1_Iter << " ";  
   cout << "in that order.";  
   cout << endl;  
  
   // rbegin can be used to iterate through a deque in reverse order  
   cout << "The reversed deque is: ";  
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )  
      cout << *c1_rIter << " ";  
   cout << endl;  
  
   c1_rIter = c1.rbegin( );  
 *c1_rIter = 40;  // This would have caused an error if a   
                    // const_reverse iterator had been declared as   
                    // noted above  
   cout << "Last element in deque is now " << *c1_rIter << "." << endl;  
}  
```  
  
```Output  
Last element in the deque is 30.  
The deque contains the elements: 10 20 30 in that order.  
The reversed deque is: 30 20 10   
Last element in deque is now 40.  
```  
  
##  <a name="reference"></a>  deque::reference  
 Um tipo que fornece uma referência a um elemento armazenado em um deque.  
  
```  
typedef typename Allocator::reference reference;  
```  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_reference.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
  
   const int &i = c1.front( );  
   int &j = c1.back( );  
   cout << "The first element is " << i << endl;  
   cout << "The second element is " << j << endl;  
}  
```  
  
```Output  
The first element is 10  
The second element is 20  
```  
  
##  <a name="rend"></a>  deque::rend  
 Retorna um iterador que trata o local após o último elemento em um deque inverso.  
  
```  
const_reverse_iterator rend() const;

reverse_iterator rend();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso que trata o local após o último elemento em um deque inverso (o local que precedeu o primeiro elemento no deque não inverso).  
  
### <a name="remarks"></a>Comentários  
 `rend` é usado com um deque inverso, assim como [end](#end) é usado com um deque.  
  
 Se o valor retornado `rend` for atribuído a um `const_reverse_iterator`, o objeto do deque não poderá ser modificado. Se o valor retornado `rend` for atribuído a um `reverse_iterator`, o objeto do deque poderá ser modificado.  
  
 `rend` pode ser usado para testar se um iterador inverso chegou ao final de seu deque.  
  
 O valor retornado por `rend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_rend.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   deque <int> c1;  
   deque <int>::iterator c1_Iter;  
   deque <int>::reverse_iterator c1_rIter;  
   // If the following line had replaced the line above, an error  
   // would have resulted in the line modifying an element  
   // (commented below) because the iterator would have been const  
   // deque <int>::const_reverse_iterator c1_rIter;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1_rIter = c1.rend( );  
   c1_rIter --; // Decrementing a reverse iterator moves it forward   
                // in the deque (to point to the first element here)  
   cout << "The first element in the deque is: " << *c1_rIter << endl;  
  
   cout << "The deque is: ";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << *c1_Iter << " ";  
   cout << endl;  
  
   // rend can be used to test if an iteration is through all of   
   // the elements of a reversed deque  
   cout << "The reversed deque is: ";  
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )  
      cout << *c1_rIter << " ";  
   cout << endl;  
  
   c1_rIter = c1.rend( );  
   c1_rIter--; // Decrementing the reverse iterator moves it backward   
               // in the reversed deque (to the last element here)  
 *c1_rIter = 40; // This modification of the last element would   
                   // have caused an error if a const_reverse   
                   // iterator had been declared (as noted above)  
   cout << "The modified reversed deque is: ";  
   for ( c1_rIter = c1.rbegin( ); c1_rIter != c1.rend( ); c1_rIter++ )  
      cout << *c1_rIter << " ";  
   cout << endl;  
}  
```  
  
```Output  
The first element in the deque is: 10  
The deque is: 10 20 30   
The reversed deque is: 30 20 10   
The modified reversed deque is: 30 20 40   
```  
  
##  <a name="resize"></a>  deque::resize  
 Especifica um novo tamanho para um deque.  
  
```  
void resize(size_type _Newsize);

void resize(size_type _Newsize, Type val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Newsize`  
 O novo tamanho do deque.  
  
 `val`  
 O valor dos novos elementos a serem adicionados ao deque se o novo tamanho for maior que o tamanho original. Se o valor for omitido, os novos elementos receberão o valor padrão para a classe.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho do deque for menor que o tamanho solicitado, `_Newsize`, elementos serão adicionados ao deque até ele atingir o tamanho solicitado.  
  
 Se o tamanho do deque for maior que o tamanho solicitado, os elementos mais próximos do final do deque serão excluídos até o deque atingir o tamanho `_Newsize`.  
  
 Se o tamanho atual do deque for igual ao tamanho solicitado, nenhuma ação será realizada.  
  
 [size](#size) reflete o tamanho atual do deque.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_resize.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{   
   using namespace std;  
   deque <int> c1;  
  
   c1.push_back( 10 );  
   c1.push_back( 20 );  
   c1.push_back( 30 );  
  
   c1.resize( 4,40 );  
   cout << "The size of c1 is: " << c1.size( ) << endl;  
   cout << "The value of the last element is " << c1.back( ) << endl;  
  
   c1.resize( 5 );  
   cout << "The size of c1 is now: " << c1.size( ) << endl;  
   cout << "The value of the last element is now " << c1.back( ) << endl;  
  
   c1.resize( 2 );  
   cout << "The reduced size of c1 is: " << c1.size( ) << endl;  
   cout << "The value of the last element is now " << c1.back( ) << endl;  
}  
```  
  
```Output  
The size of c1 is: 4  
The value of the last element is 40  
The size of c1 is now: 5  
The value of the last element is now 0  
The reduced size of c1 is: 2  
The value of the last element is now 20  
```  
  
##  <a name="reverse_iterator"></a>  deque::reverse_iterator  
 Um tipo que fornece um iterador de acesso aleatório que pode ler ou modificar um elemento em um deque inverso.  
  
```  
typedef std::reverse_iterator<iterator> reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 Um tipo `reverse_iterator` é usado para iterar pelo deque.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de rbegin.  
  
##  <a name="shrink_to_fit"></a>  deque::shrink_to_fit  
 Descarta o excesso de capacidade.  
  
```  
void shrink_to_fit();
```  
  
### <a name="remarks"></a>Comentários  
 Não há uma maneira portável de determinar se `shrink_to_fit` reduz o armazenamento usado por um [deque](../standard-library/deque-class.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_shrink_to_fit.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   deque <int> v1;  
   //deque <int>::iterator Iter;  
  
   v1.push_back( 1 );  
   v1.push_back( 2 );  
   cout << "Current size of v1 = "   
      << v1.size( ) << endl;  
   v1.shrink_to_fit();  
   cout << "Current size of v1 = "   
      << v1.size( ) << endl;  
}  
```  
  
```Output  
Current size of v1 = 1  
Current size of v1 = 1  
```  
  
##  <a name="size"></a>  deque::size  
 Retorna o número de elementos no deque.  
  
```  
size_type size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do deque.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_size.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1;  
   deque <int>::size_type i;  
  
   c1.push_back( 1 );  
   i = c1.size( );  
   cout << "The deque length is " << i << "." << endl;  
  
   c1.push_back( 2 );  
   i = c1.size( );  
   cout << "The deque length is now " << i << "." << endl;  
}  
```  
  
```Output  
The deque length is 1.  
The deque length is now 2.  
```  
  
##  <a name="size_type"></a>  deque::size_type  
 Um tipo que conta o número de elementos em um deque.  
  
```  
typedef typename Allocator::size_type size_type;  
```  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [size](#size).  
  
##  <a name="swap"></a>  deque::swap  
 Troca os elementos dos dois deques.  
  
```  
void swap(deque<Type, Allocator>& right);

friend void swap(deque<Type, Allocator>& left, deque<Type, Allocator>& right) template <class Type, class Allocator>  
void swap(deque<Type, Allocator>& left, deque<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O deque que fornece os elementos a serem trocados ou o deque cujos elementos deverão ser trocados com aqueles do deque `left`.  
  
 `left`  
 Um deque cujos elementos devem ser trocados por aqueles do deque `right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_swap.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   deque <int> c1, c2, c3;  
   deque <int>::iterator c1_Iter;  
  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   c1.push_back( 3 );  
   c2.push_back( 10 );  
   c2.push_back( 20 );  
   c3.push_back( 100 );  
  
   cout << "The original deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
  
   c1.swap( c2 );  
  
   cout << "After swapping with c2, deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
  
   swap( c1,c3 );  
  
   cout << "After swapping with c3, deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
  
   swap<>(c1, c2);  
   cout << "After swapping with c2, deque c1 is:";  
   for ( c1_Iter = c1.begin( ); c1_Iter != c1.end( ); c1_Iter++ )  
      cout << " " << *c1_Iter;  
   cout << endl;  
}  
```  
  
```Output  
The original deque c1 is: 1 2 3  
After swapping with c2, deque c1 is: 10 20  
After swapping with c3, deque c1 is: 100  
After swapping with c2, deque c1 is: 1 2 3  
```  
  
##  <a name="value_type"></a>  deque::value_type  
 Um tipo que representa o tipo de dados armazenado em um deque.  
  
```  
typedef typename Allocator::value_type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 `value_type` é um sinônimo do parâmetro de modelo **Type**.  
  
### <a name="example"></a>Exemplo  
  
```cpp 
// deque_value_type.cpp  
// compile with: /EHsc  
#include <deque>  
#include <iostream>  
int main( )   
{  
   using namespace std;  
   deque<int>::value_type AnInt;  
   AnInt = 44;  
   cout << AnInt << endl;  
}  
```  
  
```Output  
44  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)


