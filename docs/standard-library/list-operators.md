---
title: Operadores &lt;lista&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: []
ms.assetid: 8103d8f2-c30f-49ad-ac50-b3ba6a907ebe
caps.latest.revision: 7
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 617ac2187ec3cd6d46cec6076fa72cc437803714
ms.lasthandoff: 02/25/2017

---
# <a name="ltlistgt-operators"></a>Operadores &lt;lista&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|[operator&gt;=](#operator_gt__eq)|  
|[operator&lt;](#operator_lt_)|[operator&lt;=](#operator_lt__eq)|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_neq"></a>  operator!=  
 Testa se o objeto da lista à esquerda do operador é diferente do objeto da lista à direita.  
  
```
bool operator!=(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **lista**.  
  
 `right`  
 Um objeto do tipo **lista**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se as listas não forem iguais; **false** se as listas forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. Duas listas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// list_op_ne.cpp  
// compile with: /EHsc  
#include <list>  
#include <iostream>  
  
int main( )  
{  
using namespace std;  
list <int> c1, c2;  
c1.push_back( 1 );  
c2.push_back( 2 );  
  
if ( c1 != c2 )  
cout << "Lists not equal." << endl;  
else  
cout << "Lists equal." << endl;  
}  
\* Output:  
Lists not equal.  
*\  
```  
  
##  <a name="operator_lt_"></a>  operator&lt;  
 Testa se o objeto da lista à esquerda do operador é menor que o objeto da lista à direita.  
  
```
bool operator<(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **lista**.  
  
 `right`  
 Um objeto do tipo **lista**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a lista no lado esquerdo do operador for menor que ou diferente da lista à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos é baseada em uma comparação do primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// list_op_lt.cpp  
// compile with: /EHsc  
#include <list>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;   
   list <int> c1, c2;  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   c1.push_back( 4 );  
  
   c2.push_back( 1 );  
   c2.push_back( 3 );  
  
   if ( c1 < c2 )  
      cout << "List c1 is less than list c2." << endl;  
   else  
      cout << "List c1 is not less than list c2." << endl;  
}  
\* Output:   
List c1 is less than list c2.  
*\   
```  
  
##  <a name="operator_lt__eq"></a>  operator&lt;=  
 Testa se o objeto da lista à esquerda do operador é menor que ou igual ao objeto da lista à direita.  
  
```
bool operator<=(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **lista**.  
  
 `right`  
 Um objeto do tipo **lista**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a lista no lado esquerdo do operador for menor que ou igual à lista à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação menor que ou igual a entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// list_op_le.cpp  
// compile with: /EHsc  
#include <list>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;   
   list <int> c1, c2;  
   c1.push_back( 1 );  
   c1.push_back( 2 );  
   c1.push_back( 4 );  
  
   c2.push_back( 1 );  
   c2.push_back( 3 );  
  
   if ( c1 <= c2 )  
      cout << "List c1 is less than or equal to list c2." << endl;  
   else  
      cout << "List c1 is greater than list c2." << endl;  
}  
\* Output:   
List c1 is less than or equal to list c2.  
*\  
```  
  
##  <a name="operator_eq_eq"></a>  operator==  
 Testa se o objeto da lista à esquerda do operador é igual ao objeto da lista à direita.  
  
```
bool operator==(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **lista**.  
  
 `right`  
 Um objeto do tipo **lista**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a lista no lado esquerdo do operador for igual à lista à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. Duas listas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// list_op_eq.cpp  
// compile with: /EHsc  
#include <list>  
#include <iostream>  
int main( )   
{  
   using namespace std;   
  
   list <int> c1, c2;  
   c1.push_back( 1 );  
   c2.push_back( 1 );  
  
   if ( c1 == c2 )  
      cout << "The lists are equal." << endl;  
   else  
      cout << "The lists are not equal." << endl;  
}  
\* Output:   
The lists are equal.  
*\  
```  
  
##  <a name="operator_gt_"></a>  operator&gt;  
 Testa se o objeto da lista à esquerda do operador é maior que o objeto da lista à direita.  
  
```
bool operator>(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **lista**.  
  
 `right`  
 Um objeto do tipo **lista**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a lista no lado esquerdo do operador for maior que a lista à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// list_op_gt.cpp  
// compile with: /EHsc  
#include <list>  
#include <iostream>  
int main( )   
{  
   using namespace std;   
   list <int> c1, c2;  
   c1.push_back( 1 );  
   c1.push_back( 3 );  
   c1.push_back( 1 );  
  
   c2.push_back( 1 );  
   c2.push_back( 2 );  
   c2.push_back( 2 );  
  
   if ( c1 > c2 )  
      cout << "List c1 is greater than list c2." << endl;  
   else  
      cout << "List c1 is not greater than list c2." << endl;  
}  
\* Output:   
List c1 is greater than list c2.  
*\  
```  
  
##  <a name="operator_gt__eq"></a>  operator&gt;=  
 Testa se o objeto da lista à esquerda do operador é maior que ou igual ao objeto da lista à direita.  
  
```
bool operator>=(
    const list<Type, Allocator>& left,
    const list<Type, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **lista**.  
  
 `right`  
 Um objeto do tipo **lista**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a lista no lado esquerdo do operador for maior que ou igual à lista à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de lista baseia-se em uma comparação par de seus elementos. A relação maior que ou igual entre dois objetos é baseada em uma comparação entre o primeiro par de elementos diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// list_op_ge.cpp  
// compile with: /EHsc  
#include <list>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;   
   list <int> c1, c2;  
   c1.push_back( 1 );  
   c1.push_back( 3 );  
   c1.push_back( 1 );  
  
   c2.push_back( 1 );  
   c2.push_back( 2 );  
   c2.push_back( 2 );  
  
   if ( c1 >= c2 )  
      cout << "List c1 is greater than or equal to list c2." << endl;  
   else  
      cout << "List c1 is less than list c2." << endl;  
}  
\* Output:   
List c1 is greater than or equal to list c2.  
*\  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<list>](../standard-library/list.md)




