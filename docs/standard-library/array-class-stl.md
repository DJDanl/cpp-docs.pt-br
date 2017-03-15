---
title: "Classe array (Biblioteca Padrão C++)| Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "array"
  - "std::array"
  - "array/std::array"
  - "std::array::const_iterator"
  - "array/std::array::const_iterator"
  - "std::array::const_pointer"
  - "array/std::array::const_pointer"
  - "std::array::const_reference"
  - "array/std::array::const_reference"
  - "std::array::const_reverse_iterator"
  - "array/std::array::const_reverse_iterator"
  - "std::array::difference_type"
  - "array/std::array::difference_type"
  - "std::array::iterator"
  - "array/std::array::iterator"
  - "std::array::pointer"
  - "array/std::array::pointer"
  - "std::array::reference"
  - "array/std::array::reference"
  - "std::array::reverse_iterator"
  - "array/std::array::reverse_iterator"
  - "std::array::size_type"
  - "array/std::array::size_type"
  - "std::array::value_type"
  - "array/std::array::value_type"
  - "std::array::assign"
  - "array/std::array::assign"
  - "std::array::at"
  - "array/std::array::at"
  - "std::array::back"
  - "array/std::array::back"
  - "std::array::begin"
  - "array/std::array::begin"
  - "std::array::cbegin"
  - "array/std::array::cbegin"
  - "std::array::cend"
  - "array/std::array::cend"
  - "std::array::crbegin"
  - "array/std::array::crbegin"
  - "std::array::crend"
  - "array/std::array::crend"
  - "std::array::data"
  - "array/std::array::data"
  - "std::array::empty"
  - "array/std::array::empty"
  - "std::array::end"
  - "array/std::array::end"
  - "std::array::fill"
  - "array/std::array::fill"
  - "std::array::front"
  - "array/std::array::front"
  - "std::array::max_size"
  - "array/std::array::max_size"
  - "std::array::rbegin"
  - "array/std::array::rbegin"
  - "std::array::rend"
  - "array/std::array::rend"
  - "std::array::size"
  - "array/std::array::size"
  - "std::array::swap"
  - "array/std::array::swap"
  - "std::array::operator="
  - "array/std::array::operator="
  - "std::array::operator[]"
  - "array/std::array::operator[]"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "array class"
ms.assetid: fdfd43a5-b2b5-4b9e-991f-93bf10fb4293
caps.latest.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
---
# <a name="array-class-c-standard-library"></a>Classe array (Biblioteca padrão C++)
Descreve um objeto que controla uma sequência de tamanho `N` de elementos do tipo `Ty`. A sequência é armazenada como uma matriz de `Ty`, contida no objeto `array<Ty, N>`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty, std::size_t N>  
class array;  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|`Ty`|O tipo de um elemento.|  
|`N`|O número de elementos.|  
  
## <a name="members"></a>Membros  
  
|||  
|-|-|  
|Definição do tipo|Descrição|  
|[array::const_iterator](#array__const_iterator)|O tipo de um iterador de constante para a sequência controlada.|  
|[array::const_pointer](#array__const_pointer)|O tipo de um ponteiro de constante para um elemento.|  
|[array::const_reference](#array__const_reference)|O tipo de uma referência de constante para um elemento.|  
|[array::const_reverse_iterator](#array__const_reverse_iterator)|O tipo de um iterador reverso de constante para a sequência controlada.|  
|[array::difference_type](#array__difference_type)|O tipo de uma distância com sinal entre dois elementos.|  
|[array::iterator](#array__iterator)|O tipo de um iterador para a sequência controlada.|  
|[array::pointer](#array__pointer)|O tipo de um ponteiro para um elemento.|  
|[array::reference](#array__reference)|O tipo de uma referência para um elemento.|  
|[array::reverse_iterator](#array__reverse_iterator)|O tipo de um iterador inverso para a sequência controlada.|  
|[array::size_type](#array__size_type)|O tipo de uma distância sem sinal entre dois elementos.|  
|[array::value_type](#array__value_type)|O tipo de um elemento.|  
  
|||  
|-|-|  
|Função membro|Descrição|  
|[array::array](#array__array)|Constrói um objeto de matriz.|  
|[array::assign](#array__assign)|Substitui todos os elementos.|  
|[array::at](#array__at)|Acessa um elemento em uma posição especificada.|  
|[array::back](#array__back)|Acessa o último elemento.|  
|[array::begin](#array__begin)|Designa o início da sequência controlada.|  
|[array::cbegin](#array__cbegin)|Retorna um iterador const de acesso aleatório para o primeiro elemento na matriz.|  
|[array::cend](#array__cend)|Retorna um iterador const de acesso aleatório que aponta para imediatamente após o fim da matriz.|  
|[array::crbegin](#array__crbegin)|Retorna um iterador const para o primeiro elemento em uma matriz invertida.|  
|[array::crend](#array__crend)|Retorna um iterador const ao final de uma matriz invertido.|  
|[array::data](#array__data)|Obtém o endereço do primeiro elemento.|  
|[array::empty](#array__empty)|Testa se há elementos presentes.|  
|[array::end](#array__end)|Designa o fim da sequência controlada.|  
|[array::fill](#array__fill)|Substitui todos os elementos por um valor especificado.|  
|[array::front](#array__front)|Acessa o primeiro elemento.|  
|[array::max_size](#array__max_size)|Conta o número de elementos.|  
|[array::rbegin](#array__rbegin)|Designa o início da sequência controlada invertida.|  
|[array::rend](#array__rend)|Designa o fim da sequência controlada invertida.|  
|[array::size](#array__size)|Conta o número de elementos.|  
|[array::swap](#array__swap)|Alterna o conteúdo de dois contêineres.|  
  
|||  
|-|-|  
|Operador|Descrição|  
|[array::operator=](#array__operator_eq)|Substitui a sequência controlada.|  
|[array::operator[]](#array__operator_at)|Acessa um elemento em uma posição especificada.|  
  
## <a name="remarks"></a>Comentários  
 O tipo tem um construtor padrão `array()` e um operador de atribuição padrão `operator=` e atende aos requisitos para um `aggregate`. Portanto, os objetos do tipo `array<Ty, N>` podem ser inicializados usando um inicializador agregado. Por exemplo,  
  
```  
array<int, 4> ai = { 1, 2, 3 };  
```  
  
 cria o objeto `ai` que contém quatro valores inteiros, inicializa os três primeiros elementos para os valores 1, 2 e 3, respectivamente, e inicializa o quarto elemento para 0.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<array>  
  
 **Namespace:** std  
  
##  <a name="a-namearrayarraya--arrayarray"></a><a name="array__array"></a>  array::array  
 Constrói um objeto de matriz.  
  
```  
array();

array(const array& right);
```  
  
### <a name="parameters"></a>Parâmetros  
*right*  
 Objeto ou intervalo a inserir.  
  
### <a name="remarks"></a>Comentários  
O construtor padrão `array()` deixa a sequência não inicializada controlada (ou padrão inicializado). Você pode usá-lo para especificar uma sequência controlada não inicializada.  
  
O construtor de cópia `array(const array& right)` inicializa a sequência controlada com a sequência [*direita*`.begin()`, *direita*`.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto de matriz *direita*.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_array.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    Myarray c1(c0);   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0 1 2 3  
```  
  
##  <a name="a-namearrayassigna--arrayassign"></a><a name="array__assign"></a>  array::assign  
Obsoleto no C++&11;, substituído por [preenchimento](#array__fill). Substitui todos os elementos.  
  
```  
void assign(const Ty& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 O valor a atribuir.  
  
### <a name="remarks"></a>Comentários  
 A função membro substitui a sequência controlada por `*this` por uma repetição de elementos `N` de valor `val`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_assign.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    Myarray c1;   
    c1.assign(4);   
  
// display contents " 4 4 4 4"   
    for (Myarray::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
4 4 4 4  
```  
  
##  <a name="a-namearrayata--arrayat"></a><a name="array__at"></a>  array::at  
 Acessa um elemento em uma posição especificada.  
  
```  
reference at(size_type off);

constexpr const_reference at(size_type off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `off`  
 Posição do elemento a acessar.  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam uma referência ao elemento da sequência controlada na posição `off`. Se a posição for inválida, a função lançará um objeto da classe `out_of_range`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_at.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display odd elements " 1 3"   
    std::cout << " " << c0.at(1);   
    std::cout << " " << c0.at(3);   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
##  <a name="a-namearraybacka--arrayback"></a><a name="array__back"></a>  array::back  
 Acessa o último elemento.  
  
```  
reference back();

constexpr const_reference back() const;
```  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam uma referência ao último elemento da sequência controlada, que deve ser não vazio.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_back.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display last element " 3"   
    std::cout << " " << c0.back();   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
3  
```  
  
##  <a name="a-namearraybegina--arraybegin"></a><a name="array__begin"></a>  array::begin  
 Designa o início da sequência controlada.  
  
```  
iterator begin() noexcept;  
const_iterator begin() const noexcept;  
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna um iterador de acesso aleatório que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_begin.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::iterator it2 = c0.begin();   
    std::cout << " " << *it2;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearraycbegina--arraycbegin"></a><a name="array__cbegin"></a>  array::cbegin  
 Retorna um iterador `const` que trata o primeiro elemento no intervalo.  
  
```  
const_iterator cbegin() const noexcept;  
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
  
##  <a name="a-namearraycenda--arraycend"></a><a name="array__cend"></a>  array::cend  
 Retorna um iterador `const` que trata o local logo após o último elemento em um intervalo.  
  
```  
const_iterator cend() const noexcept;  
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
  
##  <a name="a-namearrayconstiteratora--arrayconstiterator"></a><a name="array__const_iterator"></a>  array::const_iterator  
 O tipo de um iterador de constante para a sequência controlada.  
  
```  
typedef implementation-defined const_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de acesso aleatório constante para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_const_iterator.cpp  
// compile with: /EHsc /W4  
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> MyArray;   
  
int main()   
{   
    MyArray c0 = {0, 1, 2, 3};   
  
    // display contents " 0 1 2 3"   
    std::cout << "it1:";  
    for ( MyArray::const_iterator it1 = c0.begin();   
          it1 != c0.end();   
          ++it1 ) {  
       std::cout << " " << *it1;   
    }  
    std::cout << std::endl;   
  
    // display first element " 0"   
    MyArray::const_iterator it2 = c0.begin();   
    std::cout << "it2:";  
    std::cout << " " << *it2;   
    std::cout << std::endl;   
  
    return (0);   
}  
  
```  
  
```Output  
it1: 0 1 2 3                                  
  
it2: 0  
  
```  
  
##  <a name="a-namearrayconstpointera--arrayconstpointer"></a><a name="array__const_pointer"></a>  array::const_pointer  
 O tipo de um ponteiro de constante para um elemento.  
  
```  
typedef const Ty *const_pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um ponteiro de constante para elementos da sequência.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_const_pointer.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::const_pointer ptr = &*c0.begin();   
    std::cout << " " << *ptr;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearrayconstreferencea--arrayconstreference"></a><a name="array__const_reference"></a>  array::const_reference  
 O tipo de uma referência de constante para um elemento.  
  
```  
typedef const Ty& const_reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como uma referência constante para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_const_reference.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::const_reference ref = *c0.begin();   
    std::cout << " " << ref;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearrayconstreverseiteratora--arrayconstreverseiterator"></a><a name="array__const_reverse_iterator"></a>  array::const_reverse_iterator  
 O tipo de um iterador reverso de constante para a sequência controlada.  
  
```  
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador inverso constante para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_const_reverse_iterator.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display last element " 3"   
    Myarray::const_reverse_iterator it2 = c0.rbegin();   
    std::cout << " " << *it2;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
3  
```  
  
##  <a name="a-namearraycrbegina--arraycrbegin"></a><a name="array__crbegin"></a>  array::crbegin  
 Retorna um iterador const para o primeiro elemento em uma matriz invertida.  
  
```  
const_reverse_iterator crbegin() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório invertido const que trata do primeiro elemento em uma matriz invertida ou que trata de qual foi o último elemento na matriz não invertida.  
  
### <a name="remarks"></a>Comentários  
 Com o valor retornado de `crbegin`, o objeto de matriz não pode ser modificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// array_crbegin.cpp  
// compile with: /EHsc  
#include <array>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   array<int, 2> v1 = {1, 2};  
   array<int, 2>::iterator v1_Iter;  
   array<int, 2>::const_reverse_iterator v1_rIter;  
  
   v1_Iter = v1.begin( );  
   cout << "The first element of array is "  
        << *v1_Iter << "." << endl;  
  
   v1_rIter = v1.crbegin( );  
   cout << "The first element of the reversed array is "  
        << *v1_rIter << "." << endl;  
}  
```  
  
```Output  
The first element of array is 1.  
The first element of the reversed array is 2.  
```  
  
##  <a name="a-namearraycrenda--arraycrend"></a><a name="array__crend"></a>  array::crend  
 Retorna um iterador const que trata o local após o último elemento em uma matriz invertida.  
  
```  
const_reverse_iterator crend() const noexcept;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de acesso aleatório inverso const que trata o local após o último elemento em uma matriz invertida (o local que precedeu o primeiro elemento na matriz não invertida).  
  
### <a name="remarks"></a>Comentários  
 `crend` é usado com uma matriz invertida assim como [array::cend](#array__cend) é usado com uma matriz.  
  
 Com o valor retornado de `crend` (adequadamente diminuído), o objeto de matriz não pode ser modificado.  
  
 `crend` pode ser usado para testar se um iterador invertido alcançou o final de sua matriz.  
  
 O valor retornado por `crend` não deve ser desreferenciado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// array_crend.cpp  
// compile with: /EHsc  
#include <array>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;     
   array<int, 2> v1 = {1, 2};  
   array<int, 2>::const_reverse_iterator v1_rIter;  
  
   for ( v1_rIter = v1.rbegin( ) ; v1_rIter != v1.rend( ) ; v1_rIter++ )  
      cout << *v1_rIter << endl;  
}  
```  
  
```Output  
2  
1  
```  
  
##  <a name="a-namearraydataa--arraydata"></a><a name="array__data"></a>  array::data  
 Obtém o endereço do primeiro elemento.  
  
```  
Ty *data();

const Ty *data() const;
```  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam o endereço do primeiro elemento na sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_data.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::pointer ptr = c0.data();   
    std::cout << " " << *ptr;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearraydifferencetypea--arraydifferencetype"></a><a name="array__difference_type"></a>  array::difference_type  
 O tipo de uma distância com sinal entre dois elementos.  
  
```  
typedef std::ptrdiff_t difference_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro com sinal descreve um objeto que pode representar a diferença entre os endereços de dois elementos quaisquer na sequência controlada. É um sinônimo para o tipo `std::ptrdiff_t`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_difference_type.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display distance first-last " -4"   
    Myarray::difference_type diff = c0.begin() - c0.end();   
    std::cout << " " << diff;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
-4  
```  
  
##  <a name="a-namearrayemptya--arrayempty"></a><a name="array__empty"></a>  array::empty  
 Testa se nenhum elemento está presente.  
  
```  
constexpr bool empty() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retornará true somente se `N == 0`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_empty.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display whether c0 is empty " false"   
    std::cout << std::boolalpha << " " << c0.empty();   
    std::cout << std::endl;   
  
    std::array<int, 0> c1;   
  
// display whether c1 is empty " true"   
    std::cout << std::boolalpha << " " << c1.empty();   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
false  
true  
```  
  
##  <a name="a-namearrayenda--arrayend"></a><a name="array__end"></a>  array::end  
 Designa o fim da sequência controlada.  
  
```  
reference end();

const_reference end() const;
```  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam um iterador de acesso aleatório que aponta para logo além do fim da sequência.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_end.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display last element " 3"   
    Myarray::iterator it2 = c0.end();   
    std::cout << " " << *--it2;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
3  
```  
  
##  <a name="a-namearrayfilla--arrayfill"></a><a name="array__fill"></a>  array::fill  
 Apaga uma matriz e copia os elementos especificados para a matriz vazia.  
  
```  
void fill(const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|` val`|O valor do elemento sendo inserido na matriz.|  
  
### <a name="remarks"></a>Comentários  
 `fill` substitui cada elemento da matriz pelo valor especificado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// array_fill.cpp  
// compile with: /EHsc  
#include <array>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   array<int, 2> v1 = {1, 2};  
   array<int, 2>::iterator iter;  
  
   cout << "v1 = " ;  
   for (iter = v1.begin(); iter != v1.end(); iter++)  
      cout << *iter << " ";  
   cout << endl;  
  
   v1.fill(3);  
   cout << "v1 = " ;  
   for (iter = v1.begin(); iter != v1.end(); iter++)  
      cout << *iter << " ";  
   cout << endl;  
}  
```  
  
##  <a name="a-namearrayfronta--arrayfront"></a><a name="array__front"></a>  array::front  
 Acessa o primeiro elemento.  
  
```  
reference front();

constexpr const_reference front() const;
```  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam uma referência ao primeiro elemento da sequência controlada, que deve ser não vazia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_front.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    std::cout << " " << c0.front();   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearrayiteratora--arrayiterator"></a><a name="array__iterator"></a>  array::iterator  
 O tipo de um iterador para a sequência controlada.  
  
```  
typedef implementation-defined iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador de acesso aleatório para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_iterator.cpp   
// compile with: /EHsc /W4  
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> MyArray;   
  
int main()   
{   
    MyArray c0 = {0, 1, 2, 3};   
  
    // display contents " 0 1 2 3"   
    std::cout << "it1:";  
    for ( MyArray::iterator it1 = c0.begin();   
          it1 != c0.end();   
          ++it1 ) {  
       std::cout << " " << *it1;   
    }  
    std::cout << std::endl;   
  
    // display first element " 0"   
    MyArray::iterator it2 = c0.begin();   
    std::cout << "it2:";  
    std::cout << " " << *it2;   
    std::cout << std::endl;   
  
    return (0);   
}  
  
```  
  
```Output  
it1: 0 1 2 3                                  
  
it2: 0  
  
```  
  
##  <a name="a-namearraymaxsizea--arraymaxsize"></a><a name="array__max_size"></a>  array::max_size  
 Conta o número de elementos.  
  
```  
constexpr size_type max_size() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `N`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_max_size.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display (maximum) size " 4"   
    std::cout << " " << c0.max_size();   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
4  
```  
  
##  <a name="a-namearrayoperatorata--arrayoperator"></a><a name="array__operator_at"></a>  array::operator[]  
 Acessa um elemento em uma posição especificada.  
  
```  
reference operator[](size_type off);

constexpr const_reference operator[](size_type off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `off`  
 Posição do elemento a acessar.  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam uma referência ao elemento da sequência controlada na posição `off`. Se a posição for inválida, o comportamento será indefinido.  
  
Também há uma função [get](array-functions.md#get_function) não membro disponível para obter uma referência a um elemento de um `array`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_operator_sub.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display odd elements " 1 3"   
    std::cout << " " << c0[1];   
    std::cout << " " << c0[3];   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
1 3  
```  
  
##  <a name="a-namearrayoperatoreqa--arrayoperator"></a><a name="array__operator_eq"></a>  array::operator=  
 Substitui a sequência controlada.  
  
```  
array <Value>%  operator=(array <Value>% right);
```  
  
### <a name="parameters"></a>Parâmetros  
 direita  
 O contêiner a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 O operador membro atribui cada elemento de `right` ao elemento correspondente da sequência controlada e, em seguida, retorna `*this`. Você pode usá-lo para substituir a sequência controlada por uma cópia da sequência controlada em `right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_operator_as.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    Myarray c1;   
    c1 = c0;   
  
// display copied contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c1.begin();   
        it != c1.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0 1 2 3  
```  
  
##  <a name="a-namearraypointera--arraypointer"></a><a name="array__pointer"></a>  array::pointer  
 O tipo de um ponteiro para um elemento.  
  
```  
typedef Ty *pointer;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um ponteiro para elementos da sequência.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_pointer.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::pointer ptr = &*c0.begin();   
    std::cout << " " << *ptr;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearrayrbegina--arrayrbegin"></a><a name="array__rbegin"></a>  array::rbegin  
 Designa o início da sequência controlada invertida.  
  
```  
reverse_iterator rbegin()noexcept;  
const_reverse_iterator rbegin() const noexcept;  
```  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam um iterador invertido que aponta pra logo além do fim da sequência controlada. Assim, ele designa o início da sequência invertida.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_rbegin.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display last element " 3"   
    Myarray::const_reverse_iterator it2 = c0.rbegin();   
    std::cout << " " << *it2;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
3  
```  
  
##  <a name="a-namearrayreferencea--arrayreference"></a><a name="array__reference"></a>  array::reference  
 O tipo de uma referência para um elemento.  
  
```  
typedef Ty& reference;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como uma referência para um elemento da sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_reference.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::reference ref = *c0.begin();   
    std::cout << " " << ref;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearrayrenda--arrayrend"></a><a name="array__rend"></a>  array::rend  
 Designa o fim da sequência controlada invertida.  
  
```  
reverse_iterator rend()noexcept;  
const_reverse_iterator rend() const noexcept;  
```  
  
### <a name="remarks"></a>Comentários  
 As funções membro retornam um iterador invertido que aponta para o primeiro elemento da sequência (ou imediatamente após o fim de uma sequência vazia). Portanto, ele designa o fim da sequência invertida.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_rend.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display first element " 0"   
    Myarray::const_reverse_iterator it2 = c0.rend();   
    std::cout << " " << *--it2;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0  
```  
  
##  <a name="a-namearrayreverseiteratora--arrayreverseiterator"></a><a name="array__reverse_iterator"></a>  array::reverse_iterator  
 O tipo de um iterador inverso para a sequência controlada.  
  
```  
typedef std::reverse_iterator<iterator> reverse_iterator;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve um objeto que pode servir como um iterador invertido para a sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_reverse_iterator.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display last element " 3"   
    Myarray::reverse_iterator it2 = c0.rbegin();   
    std::cout << " " << *it2;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
3  
```  
  
##  <a name="a-namearraysizea--arraysize"></a><a name="array__size"></a>  array::size  
 Conta o número de elementos.  
  
```  
constexpr size_type size() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna `N`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_size.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display size " 4"   
    std::cout << " " << c0.size();   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
4  
```  
  
##  <a name="a-namearraysizetypea--arraysizetype"></a><a name="array__size_type"></a>  array::size_type  
 O tipo de uma distância sem sinal entre dois elementos.  
  
```  
typedef std::size_t size_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo inteiro sem sinal descreve um objeto que pode representar o tamanho de qualquer sequência controlada. É um sinônimo para o tipo `std::size_t`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_size_type.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display distance last-first " 4"   
    Myarray::size_type diff = c0.end() - c0.begin();   
    std::cout << " " << diff;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
4  
```  
  
##  <a name="a-namearrayswapa--arrayswap"></a><a name="array__swap"></a>  array::swap  
Troca o conteúdo dessa matriz com outra matriz.  
  
```  
void swap(array& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Matriz com a qual trocar conteúdo.  
  
### <a name="remarks"></a>Comentários  
A função membro troca as sequências controladas entre `*this` e `right`. Realiza uma série de atribuições de elemento e chamadas do construtor proporcionais a `N`.  

Também há uma função [swap](array-functions.md#swap_function) não membro disponível para trocar duas instâncias do `array`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_swap.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    Myarray c1 = {4, 5, 6, 7};   
    c0.swap(c1);   
  
// display swapped contents " 4 5 6 7"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    swap(c0, c1);   
  
// display swapped contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
4 5 6 7  
0 1 2 3  
```  
  
##  <a name="a-namearrayvaluetypea--arrayvaluetype"></a><a name="array__value_type"></a>  array::value_type  
 O tipo de um elemento.  
  
```  
typedef Ty value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `Ty`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__array__array_value_type.cpp   
// compile with: /EHsc   
#include <array>   
#include <iostream>   
  
typedef std::array<int, 4> Myarray;   
int main()   
    {   
    Myarray c0 = {0, 1, 2, 3};   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        std::cout << " " << *it;   
    std::cout << std::endl;   
  
// display contents " 0 1 2 3"   
    for (Myarray::const_iterator it = c0.begin();   
        it != c0.end(); ++it)   
        {   
        Myarray::value_type val = *it;   
        std::cout << " " << val;   
        }   
    std::cout << std::endl;   
  
    return (0);   
    }  
  
```  
  
```Output  
0 1 2 3  
0 1 2 3  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<array>](../standard-library/array.md)

