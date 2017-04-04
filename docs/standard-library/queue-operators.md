---
title: Operadores &lt;queue&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 7c435b48-175c-45b0-88eb-24561044019c
caps.latest.revision: 13
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3160c7fb3965bc05ceace5722a9c502e60f89442
ms.lasthandoff: 02/25/2017

---
# <a name="ltqueuegt-operators"></a>Operadores &lt;queue&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|[operator&gt;=](#operator_gt__eq)|  
|[operator&lt;](#operator_lt_)|[operator&lt;=](#operator_lt__eq)|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_neq"></a>  operator!=  
 Testa se o objeto da fila do lado esquerdo do operador não é igual ao do lado direito.  
  
```  
bool operator!=(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **fila**.  
  
 `right`  
 Um objeto do tipo **fila**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se as filas não forem iguais; **false** se forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. Duas filas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// queue_op_ne.cpp  
// compile with: /EHsc  
#include <queue>  
#include <list>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares queues with list base containers  
   queue <int, list<int> > q1, q2, q3;  
  
   // The following line would have caused an error because vector   
   // does not support pop_front( ) and so cannot be adapted  
   // by queue as a base container  
   // queue <int, vector<int> > q1, q2, q3;  
  
   q1.push( 1 );  
   q2.push( 1 );  
   q2.push( 2 );  
   q3.push( 1 );  
  
   if ( q1 != q2 )  
      cout << "The queues q1 and q2 are not equal." << endl;  
   else  
      cout << "The queues q1 and q2 are equal." << endl;  
  
   if ( q1 != q3 )  
      cout << "The queues q1 and q3 are not equal." << endl;  
   else  
      cout << "The queues q1 and q3 are equal." << endl;  
}  
```  
  
```Output  
The queues q1 and q2 are not equal.  
The queues q1 and q3 are equal.  
```  
  
##  <a name="operator_lt_"></a>  operator&lt;  
 Testa se o objeto da fila do lado esquerdo do operador é menor que o do lado direito.  
  
```  
bool operator<(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **fila**.  
  
 `right`  
 Um objeto do tipo **fila**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a fila do lado esquerdo do operador for menor ou não for igual a do lado direito do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos de fila é baseada em uma comparação do primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// queue_op_lt.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares queues with default deque base container  
   queue <int> q1, q2, q3;  
  
   q1.push( 1 );  
   q1.push( 2 );  
   q2.push( 5 );  
   q2.push( 10 );  
   q3.push( 1 );  
   q3.push( 2 );  
  
   if ( q1 < q2 )  
      cout << "The queue q1 is less than the queue q2." << endl;  
   else  
      cout << "The queue q1 is not less than the queue q2." << endl;  
  
   if ( q1 < q3 )  
      cout << "The queue q1 is less than the queue q3." << endl;  
   else  
      cout << "The queue q1 is not less than the queue q3." << endl;  
}  
```  
  
```Output  
The queue q1 is less than the queue q2.  
The queue q1 is not less than the queue q3.  
```  
  
##  <a name="operator_lt__eq"></a>  operator&lt;=  
 Testa se o objeto da fila do lado esquerdo do operador é menor ou igual ao do lado direito.  
  
```  
bool operator<=(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **fila**.  
  
 `right`  
 Um objeto do tipo **fila**.  
  
### <a name="return-value"></a>Valor de retorno  
 **verdadeiro**, se a fila no lado esquerdo do operador for estritamente menor que o aquela à direita do operador; caso contrário, **falso**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. A relação menor ou igual a entre dois objetos de fila é baseado em uma comparação entre o primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// queue_op_le.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   queue <int> q1, q2, q3;  
  
   q1.push( 5 );  
   q1.push( 10 );  
   q2.push( 1 );  
   q2.push( 2 );  
   q3.push( 5 );  
   q3.push( 10 );  
  
   if ( q1 <= q2 )  
      cout << "The queue q1 is less than or equal to "  
           << "the queue q2." << endl;  
   else  
      cout << "The queue q1 is greater than "  
           << "the queue q2." << endl;  
  
   if ( q1 <= q3 )  
      cout << "The queue q1 is less than or equal to "  
           << "the queue q3." << endl;  
   else  
      cout << "The queue q1 is greater than "  
           << "the queue q3." << endl;  
}  
```  
  
```Output  
The queue q1 is greater than the queue q2.  
The queue q1 is less than or equal to the queue q3.  
```  
  
##  <a name="operator_eq_eq"></a>  operator==  
 Testa se o objeto da fila do lado esquerdo do operador é igual ao do lado direito.  
  
```  
bool operator==(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **fila**.  
  
 `right`  
 Um objeto do tipo **fila**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se as filas não forem iguais; **false** se forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. Duas filas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// queue_op_eq.cpp  
// compile with: /EHsc  
#include <queue>  
#include <list>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Declares queues with list base containers  
   queue <int, list<int> > q1, q2, q3;  
  
   // The following line would have caused an error because vector   
   // does not support pop_front( ) and so cannot be adapted  
   // by queue as a base container  
   // queue <int, vector<int> > q1, q2, q3;  
  
   q1.push( 1 );  
   q2.push( 2 );  
   q3.push( 1 );  
  
   if ( q1 != q2 )  
      cout << "The queues q1 and q2 are not equal." << endl;  
   else  
      cout << "The queues q1 and q2 are equal." << endl;  
  
   if ( q1 != q3 )  
      cout << "The queues q1 and q3 are not equal." << endl;  
   else  
      cout << "The queues q1 and q3 are equal." << endl;  
}  
```  
  
```Output  
The queues q1 and q2 are not equal.  
The queues q1 and q3 are equal.  
```  
  
##  <a name="operator_gt_"></a>  operator&gt;  
 Testa se o objeto da fila do lado esquerdo do operador é maior que o do lado direito.  
  
```  
bool operator>(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **fila**.  
  
 `right`  
 Um objeto do tipo **fila**.  
  
### <a name="return-value"></a>Valor de retorno  
 **verdadeiro**, se a fila no lado esquerdo do operador for estritamente menor que o aquela à direita do operador; caso contrário, **falso**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos de fila é baseada em uma comparação entre o primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// queue_op_gt.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   queue <int> q1, q2, q3;  
  
   q1.push( 1 );  
   q1.push( 2 );  
   q1.push( 3 );  
   q2.push( 5 );  
   q2.push( 10 );  
   q3.push( 1 );  
   q3.push( 2 );  
  
   if ( q1 > q2 )  
      cout << "The queue q1 is greater than "  
           << "the queue q2." << endl;  
   else  
      cout << "The queue q1 is not greater than "  
           << "the queue q2." << endl;  
  
   if ( q1> q3 )  
      cout << "The queue q1 is greater than "  
           << "the queue q3." << endl;  
   else  
      cout << "The queue q1 is not greater than "  
           << "the queue q3." << endl;  
}  
```  
  
```Output  
The queue q1 is not greater than the queue q2.  
The queue q1 is greater than the queue q3.  
```  
  
##  <a name="operator_gt__eq"></a>  operator&gt;=  
 Testa se o objeto de fila do lado esquerdo do operador é maior ou igual ao do lado direito.  
  
```  
bool operator>=(const queue <Type, Container>& left, const queue <Type, Container>& right,);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **fila**.  
  
 `right`  
 Um objeto do tipo **fila**.  
  
### <a name="return-value"></a>Valor de retorno  
 **verdadeiro**, se a fila no lado esquerdo do operador for estritamente menor que o aquela à direita do operador; caso contrário, **falso**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de fila baseia-se em uma comparação par de seus elementos. Duas filas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// queue_op_ge.cpp  
// compile with: /EHsc  
#include <queue>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   queue <int> q1, q2, q3;  
  
   q1.push( 1 );  
   q1.push( 2 );  
   q2.push( 5 );  
   q2.push( 10 );  
   q3.push( 1 );  
   q3.push( 2 );  
  
   if ( q1 >= q2 )  
      cout << "The queue q1 is greater than or equal to "  
           << "the queue q2." << endl;  
   else  
      cout << "The queue q1 is less than "  
           << "the queue q2." << endl;  
  
   if ( q1>= q3 )  
      cout << "The queue q1 is greater than or equal to "  
           << "the queue q3." << endl;  
   else  
      cout << "The queue q1 is less than "  
           << "the queue q3." << endl;  
}  
```  
  
```Output  
The queue q1 is less than the queue q2.  
The queue q1 is greater than or equal to the queue q3.  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<queue>](../standard-library/queue.md)


