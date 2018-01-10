---
title: Operadores &lt;iterator&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xutility/std::operator!=
- xutility/std::operator&gt;
- xutility/std::operator&gt;=
- xutility/std::operator&lt;
- xutility/std::operator&lt;=
- xutility/std::operator+
- xutility/std::operator-
- xutility/std::operator==
dev_langs: C++
ms.assetid: b7c664f0-49d4-4993-b5d1-9ac4859fdddc
caps.latest.revision: "10"
manager: ghogen
helpviewer_keywords:
- std::operator!= (iterator)
- std::operator&gt; (iterator)
- std::operator&gt;= (iterator)
- std::operator&lt; (iterator)
- std::operator&lt;= (iterator), std::operator== (iterator)
ms.openlocfilehash: a6e5d30b970c3887c9ac7641ec39275acd9cd79d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltiteratorgt-operators"></a>Operadores &lt;iterator&gt;
||||  
|-|-|-|  
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|  
|[operator&lt;](#op_lt)|[operator&lt;=](#op_lt_eq)|[operator+](#op_add)|  
|[operator-](#operator-)|[operator==](#op_eq_eq)|  
  
##  <a name="op_neq"></a>  operator!=  
 Testa se o objeto de iterador à esquerda do operador não é igual ao objeto de iterador à direita.  
  
```  
template <class RandomIterator>  
bool operator!=(const reverse_iterator<RandomIterator>& left, const reverse_iterator<RandomIterator>& right);

template <class Type, class CharType, class Traits, class Distance>  
bool operator!=(const istream_iterator<Type, CharType, Traits, Distance>& left, const istream_iterator<Type, CharType, Traits, Distance>& right);

template <class CharType, class Tr>  
bool operator!=(const istreambuf_iterator<CharType, Traits>& left, const istreambuf_iterator<CharType, Traits>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **iterator**.  
  
 `right`  
 Um objeto do tipo **iterator**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os objetos de iterador não forem iguais, **false** se forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de iterador será igual a outro se eles lidarem com os mesmos elementos em um contêiner. Se dois iteradores apontarem para elementos diferentes em um contêiner, então eles não serão iguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_ne.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for ( i = 1 ; i < 9 ; ++i )    
   {  
      vec.push_back ( i );  
   }  
  
   vector <int>::iterator vIter;  
  
   cout << "The vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++ )  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   // Initializing reverse_iterators to the last element  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ),   
           rVPOS2 = vec.rbegin ( );  
  
   cout << "The iterator rVPOS1 initially points to the first "  
        << "element\n in the reversed sequence: "  
        << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 != rVPOS2 )  
      cout << "The iterators are not equal." << endl;  
   else  
      cout << "The iterators are equal." << endl;  
  
   rVPOS1++;  
   cout << "The iterator rVPOS1 now points to the second "  
        << "element\n in the reversed sequence: "  
        << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 != rVPOS2 )  
      cout << "The iterators are not equal." << endl;  
   else  
      cout << "The iterators are equal." << endl;  
}  
```  
  
```Output  
The vector vec is: ( 1 2 3 4 5 6 7 8 ).  
The iterator rVPOS1 initially points to the first element  
 in the reversed sequence: 8.  
The iterators are equal.  
The iterator rVPOS1 now points to the second element  
 in the reversed sequence: 7.  
The iterators are not equal.  
```  
  
##  <a name="op_eq_eq"></a>  operator==  
 Testa se o objeto de iterador à esquerda do operador é igual ao objeto de iterador à direita.  
  
```  
template <class RandomIterator1, class RandomIterator2>  
bool operator==(
    const move_iterator<RandomIterator1>& left,  
    const move_iterator<RandomIterator2>& right);

template <class RandomIterator1, class RandomIterator2>  
bool operator==(
    const reverse_iterator<RandomIterator1>& left,  
    const reverse_iterator<RandomIterator2>& right);

template <class Type, class CharType, class Traits, class Distance>  
bool operator==(
    const istream_iterator<Type, CharType, Traits, Distance>& left,  
    const istream_iterator<Type, CharType, Traits, Distance>& right);

template <class CharType, class Tr>  
bool operator==(
    const istreambuf_iterator<CharType, Traits>& left,  
    const istreambuf_iterator<CharType, Traits>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo iterator.  
  
 `right`  
 Um objeto do tipo iterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os objetos de iterador forem iguais, `false` se eles não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de iterador será igual a outro se eles lidarem com os mesmos elementos em um contêiner. Se dois iteradores apontarem para elementos diferentes em um contêiner, então eles não serão iguais.  
  
 Os primeiros dois operadores de modelo retornam true somente se `left` e `right` armazenarem o mesmo iterador. Os terceiro operador de modelo retorna true somente se `left` e `right` armazenarem o mesmo ponteiro de fluxo. O quarto operador de modelo retorna ` left.equal ( right)`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_eq.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for ( i = 1 ; i < 6 ; ++i )  
   {  
      vec.push_back ( 2 * i );  
   }  
  
   vector <int>::iterator vIter;  
  
   cout << "The vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   // Initializing reverse_iterators to the last element  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ),   
           rVPOS2 = vec.rbegin ( );  
  
   cout << "The iterator rVPOS1 initially points to the first "  
        << "element\n in the reversed sequence: "  
        << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 == rVPOS2 )  
      cout << "The iterators are equal." << endl;  
   else  
      cout << "The iterators are not equal." << endl;  
  
   rVPOS1++;  
   cout << "The iterator rVPOS1 now points to the second "  
        << "element\n in the reversed sequence: "  
        << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 == rVPOS2 )  
      cout << "The iterators are equal." << endl;  
   else  
      cout << "The iterators are not equal." << endl;  
}  
```  
  
```Output  
The vector vec is: ( 2 4 6 8 10 ).  
The iterator rVPOS1 initially points to the first element  
 in the reversed sequence: 10.  
The iterators are equal.  
The iterator rVPOS1 now points to the second element  
 in the reversed sequence: 8.  
The iterators are not equal.  
```  
  
##  <a name="op_lt"></a>  operator&lt;  
 Testa se o objeto de iterador à esquerda do operador é menor que o objeto de iterador à direita.  
  
```  
template <class RandomIterator>  
bool operator<(const reverse_iterator<RandomIterator>& left, const reverse_iterator<RandomIterator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **iterator**.  
  
 `right`  
 Um objeto do tipo **iterator**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o iterador no lado esquerdo da expressão for menor que o iterador no lado direito da expressão; **false** se ele for maior ou igual ao iterador à direita.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de iterador será menor que outro se ele tratar de um elemento que ocorre mais no início do contêiner do que o elemento de que o outro objeto de iterador trata. Um objeto de iterador não será menor que outro se ele tratar do mesmo elemento que o outro objeto de iterador ou de um elemento que ocorre mais adiante no contêiner do que o elemento de que o outro objeto de iterador trata.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_lt.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for ( i = 0 ; i < 6 ; ++i )  
   {  
      vec.push_back ( 2 * i );  
   }  
  
   vector <int>::iterator vIter;  
  
   cout << "The initial vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   // Initializing reverse_iterators to the last element  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ),   
           rVPOS2 = vec.rbegin ( );  
  
   cout << "The iterators rVPOS1& rVPOS2 initially point to the "  
           << "first element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 < rVPOS2 )  
      cout << "The iterator rVPOS1 is less than"  
              << " the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is not less than"  
              << " the iterator rVPOS2." << endl;  
  
   rVPOS2++;  
   cout << "The iterator rVPOS2 now points to the second "  
           << "element\n in the reversed sequence: "  
           << *rVPOS2 << "." << endl;  
  
   if ( rVPOS1 < rVPOS2 )  
      cout << "The iterator rVPOS1 is less than"  
              << " the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is not less than"  
              << " the iterator rVPOS2." << endl;  
}  
```  
  
```Output  
The initial vector vec is: ( 0 2 4 6 8 10 ).  
The iterators rVPOS1& rVPOS2 initially point to the first element  
 in the reversed sequence: 10.  
The iterator rVPOS1 is not less than the iterator rVPOS2.  
The iterator rVPOS2 now points to the second element  
 in the reversed sequence: 8.  
The iterator rVPOS1 is less than the iterator rVPOS2.  
```  
  
##  <a name="op_lt_eq"></a>  operator&lt;=  
 Testa se o objeto de iterador à esquerda do operador é menor ou igual ao objeto de iterador à direita.  
  
```  
template <class RandomIterator>  
bool operator<=(const reverse_iterator<RandomIterator>& left, const reverse_iterator<RandomIterator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo iterator.  
  
 `right`  
 Um objeto do tipo iterator.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o iterador no lado esquerdo da expressão for menor ou igual ao iterador no lado direito da expressão; **false** se ele for maior que o iterador à direita.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de iterador será menor ou igual a outro se ele tratar do mesmo elemento ou deu um elemento que ocorre mais no início do contêiner do que o elemento de que o outro objeto de iterador trata. Um objeto de iterador será maior que outro se ele tratar de um elemento que ocorre mais adiante no contêiner do que o elemento de que o outro objeto de iterador trata.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_le.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for (i = 0 ; i < 6 ; ++i )  {  
      vec.push_back ( 2 * i );  
      }  
  
   vector <int>::iterator vIter;  
  
   cout << "The initial vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ) + 1,   
           rVPOS2 = vec.rbegin ( );  
  
   cout << "The iterator rVPOS1 initially points to the "  
           << "second element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   cout << "The iterator rVPOS2 initially points to the "  
           << "first element\n in the reversed sequence: "  
           << *rVPOS2 << "." << endl;  
  
   if ( rVPOS1 <= rVPOS2 )  
      cout << "The iterator rVPOS1 is less than or "  
              << "equal to the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is greater than "  
              << "the iterator rVPOS2." << endl;  
  
   rVPOS2++;  
   cout << "The iterator rVPOS2 now points to the second "  
           << "element\n in the reversed sequence: "  
           << *rVPOS2 << "." << endl;  
  
   if ( rVPOS1 <= rVPOS2 )  
      cout << "The iterator rVPOS1 is less than or "  
              << "equal to the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is greater than "  
              << "the iterator rVPOS2." << endl;  
}  
```  
  
```Output  
The initial vector vec is: ( 0 2 4 6 8 10 ).  
The iterator rVPOS1 initially points to the second element  
 in the reversed sequence: 8.  
The iterator rVPOS2 initially points to the first element  
 in the reversed sequence: 10.  
The iterator rVPOS1 is greater than the iterator rVPOS2.  
The iterator rVPOS2 now points to the second element  
 in the reversed sequence: 8.  
The iterator rVPOS1 is less than or equal to the iterator rVPOS2.  
```  
  
##  <a name="op_gt"></a>  operator&gt;  
 Testa se o objeto de iterador à esquerda do operador é maior que o objeto de iterador à direita.  
  
```  
template <class RandomIterator>  
bool operator>(const reverse_iterator<RandomIterator>& left, const reverse_iterator<RandomIterator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo iterator.  
  
 `right`  
 Um objeto do tipo iterator.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o iterador no lado esquerdo da expressão for maior que o iterador no lado direito da expressão; **false** se ele for menor ou igual ao iterador à direita.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de iterador será maior que outro se ele tratar de um elemento que ocorre mais adiante no contêiner do que o elemento de que o outro objeto de iterador trata. Um objeto de iterador não será maior que outro se ele tratar do mesmo elemento que o outro objeto de iterador ou de um elemento que ocorre mais no início do contêiner do que o elemento de que o outro objeto de iterador trata.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_gt.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for (i = 0 ; i < 6 ; ++i )  {  
      vec.push_back ( 2 * i );  
      }  
  
   vector <int>::iterator vIter;  
  
   cout << "The initial vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ),   
           rVPOS2 = vec.rbegin ( );  
  
   cout << "The iterators rVPOS1 & rVPOS2 initially point to "  
           << "the first element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 > rVPOS2 )  
      cout << "The iterator rVPOS1 is greater than "  
              << "the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is less than or "  
              << "equal to the iterator rVPOS2." << endl;  
  
   rVPOS1++;  
   cout << "The iterator rVPOS1 now points to the second "  
           << "element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 > rVPOS2 )  
      cout << "The iterator rVPOS1 is greater than "  
              << "the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is less than or "  
              << "equal to the iterator rVPOS2." << endl;  
}  
```  
  
```Output  
The initial vector vec is: ( 0 2 4 6 8 10 ).  
The iterators rVPOS1 & rVPOS2 initially point to the first element  
 in the reversed sequence: 10.  
The iterator rVPOS1 is less than or equal to the iterator rVPOS2.  
The iterator rVPOS1 now points to the second element  
 in the reversed sequence: 8.  
The iterator rVPOS1 is greater than the iterator rVPOS2.  
```  
  
##  <a name="op_gt_eq"></a>  operator&gt;=  
 Testa se o objeto de iterador à esquerda do operador é maior ou igual ao objeto de iterador à direita.  
  
```  
template <class RandomIterator>  
bool operator>=(const reverse_iterator<RandomIterator>& left, const reverse_iterator<RandomIterator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo iterator.  
  
 `right`  
 Um objeto do tipo iterator.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o iterador no lado esquerdo da expressão for maior ou igual ao iterador no lado direito da expressão; **false** se ele for menor que o iterador à direita.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de iterador será maior ou igual a outro se ele tratar do mesmo elemento ou deu um elemento que ocorre mais adiante no contêiner do que o elemento de que o outro objeto de iterador trata. Um objeto de iterador será menor que outro se ele tratar de um elemento que ocorre mais no início do contêiner do que o elemento de que o outro objeto de iterador trata.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_ge.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for (i = 0 ; i < 6 ; ++i )  {  
      vec.push_back ( 2 * i );  
      }  
  
   vector <int>::iterator vIter;  
  
   cout << "The initial vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ),   
           rVPOS2 = vec.rbegin ( ) + 1;  
  
   cout << "The iterator rVPOS1 initially points to the "  
           << "first element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   cout << "The iterator rVPOS2 initially points to the "  
           << "second element\n in the reversed sequence: "  
           << *rVPOS2 << "." << endl;  
  
   if ( rVPOS1 >= rVPOS2 )  
      cout << "The iterator rVPOS1 is greater than or "  
              << "equal to the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is less than "  
              << "the iterator rVPOS2." << endl;  
  
   rVPOS1++;  
   cout << "The iterator rVPOS1 now points to the second "  
           << "element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   if ( rVPOS1 >= rVPOS2 )  
      cout << "The iterator rVPOS1 is greater than or "  
              << "equal to the iterator rVPOS2." << endl;  
   else  
      cout << "The iterator rVPOS1 is less than "  
              << "the iterator rVPOS2." << endl;  
}  
```  
  
```Output  
The initial vector vec is: ( 0 2 4 6 8 10 ).  
The iterator rVPOS1 initially points to the first element  
 in the reversed sequence: 10.  
The iterator rVPOS2 initially points to the second element  
 in the reversed sequence: 8.  
The iterator rVPOS1 is less than the iterator rVPOS2.  
The iterator rVPOS1 now points to the second element  
 in the reversed sequence: 8.  
The iterator rVPOS1 is greater than or equal to the iterator rVPOS2.  
```  
  
##  <a name="op_add"></a>  operator+  
 Adiciona um deslocamento a um iterador e retorna um `move_iterator` ou um `reverse_iterator` que trata do elemento inserido na nova posição de deslocamento.  
  
```  
template <class RandomIterator, class Diff>  
move_iterator<RandomIterator>  
operator+(
    Diff _Off,  
    const move_iterator<RandomIterator>& right);

template <class RandomIterator>  
reverse_iterator<RandomIterator>  
operator+(
    Diff _Off,  
    const reverse_iterator<RandomIterator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O número de posições na constante move_iterator ou na constante reverse_iterator deve sofrer um deslocamento.  
  
 `right`  
 O iterador a ser deslocado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a soma `right` + `_Off`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_insert.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for (i = 0 ; i < 6 ; ++i )  {  
      vec.push_back ( 2 * i );  
      }  
  
   vector <int>::iterator vIter;  
  
   cout << "The initial vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( );  
  
   cout << "The iterator rVPOS1 initially points to "  
           << "the first element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
  
   vector<int>::difference_type diff = 4;  
   rVPOS1 = diff +rVPOS1;  
  
   cout << "The iterator rVPOS1 now points to the fifth "  
           << "element\n in the reversed sequence: "  
           << *rVPOS1 << "." << endl;  
}  
```  
  
```Output  
The initial vector vec is: ( 0 2 4 6 8 10 ).  
The iterator rVPOS1 initially points to the first element  
 in the reversed sequence: 10.  
The iterator rVPOS1 now points to the fifth element  
 in the reversed sequence: 2.  
```  
  
##  <a name="operator-"></a>  operator-  
 Subtrai um iterador de outro e retorna a diferença.  
  
```  
template <class RandomIterator1, class RandomIterator2>  
Tdiff operator-(
    const move_iterator<RandomIterator1>& left,  
    const move_iterator<RandomIterator2>& right);

template <class RandomIterator1, class RandomIterator2>  
Tdiff operator-(
    const reverse_iterator<RandomIterator1>& left,  
    const reverse_iterator<RandomIterator2>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um iterador.  
  
 `right`  
 Um iterador.  
  
### <a name="return-value"></a>Valor de retorno  
 A diferença entre dois iteradores `.`  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador de modelo retorna `left.base() - right.base()`.  
  
 O segundo operador de modelo retorna `right.current - left.current`.  
  
 `Tdiff` é determinado pelo tipo da expressão retornada. Caso contrário, será `RandomIterator1::difference_type`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// iterator_op_sub.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   vector<int> vec;  
   for (i = 0 ; i < 6 ; ++i )    
   {  
      vec.push_back ( 2 * i );  
   }  
  
   vector <int>::iterator vIter;  
  
   cout << "The initial vector vec is: ( ";  
   for ( vIter = vec.begin( ) ; vIter != vec.end( ); vIter++)  
      cout << *vIter << " ";  
   cout << ")." << endl;  
  
   vector <int>::reverse_iterator rVPOS1 = vec.rbegin ( ),   
          rVPOS2 = vec.rbegin ( );  
  
   cout << "The iterators rVPOS1 & rVPOS2 initially point to "  
        << "the first element\n in the reversed sequence: "  
        << *rVPOS1 << "." << endl;  
  
   for (i = 1; i < 5; ++i)    
   {  
      rVPOS2++;  
   }  
   cout << "The iterator rVPOS2 now points to the fifth "  
        << "element\n in the reversed sequence: "  
        << *rVPOS2 << "." << endl;  
  
   vector<int>::difference_type diff = rVPOS2 - rVPOS1;  
   cout << "The difference: rVPOS2 - rVPOS1= "  
        << diff << "." << endl;  
}  
```  
  
```Output  
The initial vector vec is: ( 0 2 4 6 8 10 ).  
The iterators rVPOS1 & rVPOS2 initially point to the first element  
 in the reversed sequence: 10.  
The iterator rVPOS2 now points to the fifth element  
 in the reversed sequence: 2.  
The difference: rVPOS2 - rVPOS1= 4.  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<iterator>](../standard-library/iterator.md)

