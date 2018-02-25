---
title: '&lt;map&gt; operadores | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- map/std::operator!=
- map/std::operator&gt;
- map/std::operator&gt;=
- map/std::operator&lt;
- map/std::operator&lt;=
- map/std::operator==
dev_langs:
- C++
ms.assetid: 7df02b9f-701c-44ed-834a-a819badc5bd0
caps.latest.revision: 
manager: ghogen
helpviewer_keywords:
- std::operator!= (map)
- std::operator&gt; (map)
- std::operator&gt;= (map)
- std::operator&lt; (map)
- std::operator&lt;= (map)
- std::operator== (map)
ms.openlocfilehash: d98e67ea5a65279a5bb618552bec4358bc48a445
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltmapgt-operators"></a>&lt;map&gt; operadores
||||  
|-|-|-|  
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|  
|[operator&lt;](#op_lt)|[operator&lt;=](#op_lt_eq)|[operator==](#op_eq_eq)|  
|[operator!= (multimap)](#op_neq_multimap)|[operator&gt;](#op_gt_multimap)|[operator&gt;=](#op_gt_eq_multimap)|  
|[operator&lt;](#op_lt_multimap)|[operator&lt;=](#op_lt_eq_multimap)|[operator==](#op_eq_eq_multimap)|  
  
##  <a name="op_neq"></a>  operator!=  
 Testa se o objeto de mapa à esquerda do operador é diferente do objeto de mapa à direita.  
  
```
bool operator!=(
      const map <Key, Type, Traits, Allocator>& left, 
      const map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **mapa**.  
  
 `right`  
 Um objeto do tipo **mapa**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se os mapas forem diferentes; **false** se os mapas forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de mapa baseia-se em uma comparação par de seus elementos. Dois mapas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// map_op_ne.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   map <int, int> m1, m2, m3;  
   int i;  
   typedef pair <int, int> Int_Pair;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 != m2 )  
      cout << "The maps m1 and m2 are not equal." << endl;  
   else  
      cout << "The maps m1 and m2 are equal." << endl;  
  
   if ( m1 != m3 )  
      cout << "The maps m1 and m3 are not equal." << endl;  
   else  
      cout << "The maps m1 and m3 are equal." << endl;  
}  
\* Output:   
The maps m1 and m2 are not equal.  
The maps m1 and m3 are equal.  
*\  
```  
  
##  <a name="op_lt"></a>  operator&lt;  
 Testa se o objeto de mapa à esquerda do operador é menor que o objeto de mapa à direita.  
  
```
bool operator<(
      const map <Key, Type, Traits, Allocator>& left, 
      const map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **mapa**.  
  
 `right`  
 Um objeto do tipo **mapa**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o mapa à esquerda do operador for estritamente menor que o mapa à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de mapa baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos é baseada em uma comparação do primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// map_op_lt.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   map<int, int> m1, m2, m3;  
   int i;  
   typedef pair<int, int> Int_Pair;  
  
   for ( i = 1 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
   }  
  
   if ( m1 < m2 )  
      cout << "The map m1 is less than the map m2." << endl;  
   else  
      cout << "The map m1 is not less than the map m2." << endl;  
  
   if ( m1 < m3 )  
      cout << "The map m1 is less than the map m3." << endl;  
   else  
      cout << "The map m1 is not less than the map m3." << endl;  
}  
\* Output:   
The map m1 is less than the map m2.  
The map m1 is not less than the map m3.  
*\  
```  
  
##  <a name="op_lt_eq"></a>  operator&lt;=  
 Testa se o objeto de mapa à esquerda do operador é menor ou igual ao objeto de mapa à direita.  
  
```
bool operator<=(
      const map <Key, Type, Traits, Allocator>& left, 
      const map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **mapa**.  
  
 `right`  
 Um objeto do tipo **mapa**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o mapa à esquerda do operador for menor ou igual ao mapa à direita do operador; caso contrário, **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// map_op_le.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   map <int, int> m1, m2, m3, m4;  
   int i;  
   typedef pair <int, int> Int_Pair;  
  
   for ( i = 1 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
      m4.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 <= m2 )  
      cout << "The map m1 is less than or equal to the map m2." << endl;  
   else  
      cout << "The map m1 is greater than the map m2." << endl;  
  
   if ( m1 <= m3 )  
      cout << "The map m1 is less than or equal to the map m3." << endl;  
   else  
      cout << "The map m1 is greater than the map m3." << endl;  
  
   if ( m1 <= m4 )  
      cout << "The map m1 is less than or equal to the map m4." << endl;  
   else  
      cout << "The map m1 is greater than the map m4." << endl;  
}  
\* Output:   
The map m1 is less than or equal to the map m2.  
The map m1 is greater than the map m3.  
The map m1 is less than or equal to the map m4.  
*\  
```  
  
##  <a name="op_eq_eq"></a>  operator==  
 Testa se o objeto de mapa à esquerda do operador é igual ao objeto de mapa à direita.  
  
```
bool operator==(
      const map <Key, Type, Traits, Allocator>& left, 
      const map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **mapa**.  
  
 `right`  
 Um objeto do tipo **mapa**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o mapa à esquerda do operador for igual ao mapa à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de mapa baseia-se em uma comparação par de seus elementos. Dois mapas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// map_op_eq.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   map < int, int > m1, m2, m3;  
   int i;  
   typedef pair < int, int > Int_Pair;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 == m2 )  
      cout << "The maps m1 and m2 are equal." << endl;  
   else  
      cout << "The maps m1 and m2 are not equal." << endl;  
  
   if ( m1 == m3 )  
      cout << "The maps m1 and m3 are equal." << endl;  
   else  
      cout << "The maps m1 and m3 are not equal." << endl;  
}  
\* Output:   
The maps m1 and m2 are not equal.  
The maps m1 and m3 are equal.  
*\  
```  
  
##  <a name="op_gt"></a>  operator&gt;  
 Testa se o objeto de mapa à esquerda do operador é maior do que o objeto de mapa à direita.  
  
```
bool operator>(
      const map <Key, Type, Traits, Allocator>& left, 
      const map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **mapa**.  
  
 `right`  
 Um objeto do tipo **mapa**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o mapa à esquerda do operador for maior que o mapa à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de mapa baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// map_op_gt.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   map < int, int > m1, m2, m3;  
   int i;  
   typedef pair < int, int > Int_Pair;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
   }  
  
   if ( m1 > m2 )  
      cout << "The map m1 is greater than the map m2." << endl;  
   else  
      cout << "The map m1 is not greater than the map m2." << endl;  
  
   if ( m1 > m3 )  
      cout << "The map m1 is greater than the map m3." << endl;  
   else  
      cout << "The map m1 is not greater than the map m3." << endl;  
}  
\* Output:   
The map m1 is not greater than the map m2.  
The map m1 is greater than the map m3.  
*\  
```  
  
##  <a name="op_gt_eq"></a>  operator&gt;=  
 Testa se o objeto de mapa à esquerda do operador é maior ou igual ao objeto de mapa à direita.  
  
```
bool operator>=(
      const map <Key, Type, Traits, Allocator>& left, 
      const map <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo **mapa**.  
  
 `right`  
 Um objeto do tipo **mapa**.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o mapa à esquerda do operador for maior ou igual ao mapa à direita da lista; caso contrário, **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// map_op_ge.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   map < int, int > m1, m2, m3, m4;  
   int i;  
   typedef pair < int, int > Int_Pair;  
  
   for ( i = 1 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
      m4.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 >= m2 )  
      cout << "Map m1 is greater than or equal to map m2." << endl;  
   else  
      cout << "The map m1 is less than the map m2." << endl;  
  
   if ( m1 >= m3 )  
      cout << "Map m1 is greater than or equal to map m3." << endl;  
   else  
      cout << "The map m1 is less than the map m3." << endl;  
  
   if ( m1 >= m4 )  
      cout << "Map m1 is greater than or equal to map m4." << endl;  
   else  
      cout << "The map m1 is less than the map m4." << endl;  
}  
\* Output:   
The map m1 is less than the map m2.  
Map m1 is greater than or equal to map m3.  
Map m1 is greater than or equal to map m4.  
*\  
```  
  
##  <a name="op_neq_multimap"></a>  operator!= (multimap)  
 Testa se o objeto multimapa à esquerda do operador é diferente do objeto multimapa à direita.  
  
```
bool operator!=(
      const multimap <Key, Type, Traits, Allocator>& left, 
      const multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo `multimap`.  
  
 `right`  
 Um objeto do tipo `multimap`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os multimapas forem diferentes; **false** se os multimapas forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de multimapa baseia-se em uma comparação par de seus elementos. Dois multimapas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// multimap_op_ne.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   multimap <int, int> m1, m2, m3;  
   int i;  
   typedef pair <int, int> Int_Pair;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 != m2 )  
      cout << "The multimaps m1 and m2 are not equal." << endl;  
   else  
      cout << "The multimaps m1 and m2 are equal." << endl;  
  
   if ( m1 != m3 )  
      cout << "The multimaps m1 and m3 are not equal." << endl;  
   else  
      cout << "The multimaps m1 and m3 are equal." << endl;  
}  
\* Output:   
The multimaps m1 and m2 are not equal.  
The multimaps m1 and m3 are equal.  
*\  
```  
  
##  <a name="op_lt_multimap"></a>  operator&lt;  
 Testa se o objeto multimapa à esquerda do operador é menor que o objeto multimapa à direita.  
  
```
bool operator<(
      const multimap <Key, Type, Traits, Allocator>& left, 
      const multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo `multimap`.  
  
 `right`  
 Um objeto do tipo `multimap`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o multimapa à esquerda do operador for estritamente menor que o multimapa à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de multimapa baseia-se em uma comparação par de seus elementos. A relação menor que entre dois objetos é baseada em uma comparação do primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// multimap_op_lt.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   multimap < int, int > m1, m2, m3;  
   int i;  
   typedef pair < int, int > Int_Pair;  
  
   for ( i = 1 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
   }  
  
   if ( m1 < m2 )  
      cout << "The multimap m1 is less than the multimap m2." << endl;  
   else  
      cout << "The multimap m1 is not less than the multimap m2." << endl;  
  
   if ( m1 < m3 )  
      cout << "The multimap m1 is less than the multimap m3." << endl;  
   else  
      cout << "The multimap m1 is not less than the multimap m3." << endl;  
}  
\* Output:   
The multimap m1 is less than the multimap m2.  
The multimap m1 is not less than the multimap m3.  
*\  
```  
  
##  <a name="eq_multimap"></a>  operator&lt;=  
 Testa se o objeto multimapa à esquerda do operador é menor ou igual ao objeto multimapa à direita.  
  
```
bool operator<=(
      const multimap <Key, Type, Traits, Allocator>& left, 
      const multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo `multimap`.  
  
 `right`  
 Um objeto do tipo `multimap`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o multimapa à esquerda do operador for menor ou igual ao multimapa à direita do operador; caso contrário, **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// multimap_op_le.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   multimap <int, int> m1, m2, m3, m4;  
   int i;  
   typedef pair <int, int> Int_Pair;  
  
   for ( i = 1 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
      m4.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 <= m2 )  
      cout << "m1 is less than or equal to m2" << endl;  
   else  
      cout << "m1 is greater than m2" << endl;  
  
   if ( m1 <= m3 )  
      cout << "m1 is less than or equal to m3" << endl;  
   else  
      cout << "m1 is greater than m3" << endl;  
  
   if ( m1 <= m4 )  
      cout << "m1 is less than or equal to m4" << endl;  
   else  
      cout << "m1 is greater than m4" << endl;  
}  
\* Output:   
m1 is less than or equal to m2  
m1 is greater than m3  
m1 is less than or equal to m4  
*\  
```  
  
##  <a name="op_eq_eq_multimap"></a>  operator==  
 Testa se o objeto multimapa à esquerda do operador é igual ao objeto multimapa à direita.  
  
```
bool operator==(
      const multimap <Key, Type, Traits, Allocator>& left, 
      const multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo `multimap`.  
  
 `right`  
 Um objeto do tipo `multimap`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o multimapa à esquerda do operador é igual ao multimapa à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de multimapa baseia-se em uma comparação par de seus elementos. Dois multimapas serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// multimap_op_eq.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   multimap<int, int> m1, m2, m3;  
   int i;  
   typedef pair<int, int> Int_Pair;  
  
   for (i = 0; i < 3; i++)  
   {  
      m1.insert(Int_Pair(i, i));  
      m2.insert(Int_Pair(i, i*i));  
      m3.insert(Int_Pair(i, i));  
   }  
  
   if ( m1 == m2 )  
      cout << "m1 and m2 are equal" << endl;  
   else  
      cout << "m1 and m2 are not equal" << endl;  
  
   if ( m1 == m3 )  
      cout << "m1 and m3 are equal" << endl;  
   else  
      cout << "m1 and m3 are not equal" << endl;  
}  
\* Output:   
m1 and m2 are not equal  
m1 and m3 are equal  
*\  
```  
  
##  <a name="op_gt_multimap"></a>  operator&gt;  
 Testa se o objeto multimapa à esquerda do operador é maior que o objeto multimapa à direita.  
  
```
bool operator>(
      const multimap <Key, Type, Traits, Allocator>& left, 
      const multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo `multimap`.  
  
 `right`  
 Um objeto do tipo `multimap`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o multimapa à esquerda do operador for maior que o multimapa à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos de multimapa baseia-se em uma comparação par de seus elementos. A relação maior que entre dois objetos é baseada em uma comparação entre o primeiro par de elementos desiguais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// multimap_op_gt.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   multimap < int, int > m1, m2, m3;  
   int i;  
   typedef pair < int, int > Int_Pair;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
   }  
  
   if ( m1 > m2 )  
      cout << "The multimap m1 is greater than the multimap m2." << endl;  
   else  
      cout << "Multimap m1 is not greater than multimap m2." << endl;  
  
   if ( m1 > m3 )  
      cout << "The multimap m1 is greater than the multimap m3." << endl;  
   else  
      cout << "The multimap m1 is not greater than the multimap m3." << endl;  
}  
\* Output:   
Multimap m1 is not greater than multimap m2.  
The multimap m1 is greater than the multimap m3.  
*\  
```  
  
##  <a name="op_gt_eq_multimap"></a>  operator&gt;=  
 Testa se o objeto multimapa à esquerda do operador é maior ou igual ao objeto multimapa à direita.  
  
```
bool operator>=(
      const multimap <Key, Type, Traits, Allocator>& left, 
      const multimap <Key, Type, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Um objeto do tipo `multimap`.  
  
 `right`  
 Um objeto do tipo `multimap`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o multimapa à esquerda do operador for maior que ou igual ao multimapa à direita da lista; caso contrário, **false**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// multimap_op_ge.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   multimap < int, int > m1, m2, m3, m4;  
   int i;  
   typedef pair < int, int > Int_Pair;  
  
   for ( i = 1 ; i < 3 ; i++ )  
   {  
      m1.insert ( Int_Pair ( i, i ) );  
      m2.insert ( Int_Pair ( i, i * i ) );  
      m3.insert ( Int_Pair ( i, i - 1 ) );  
      m4.insert ( Int_Pair ( i, i ) );  
   }  
  
   if ( m1 >= m2 )  
      cout << "The multimap m1 is greater than or equal to the multimap m2." << endl;  
   else  
      cout << "The multimap m1 is less than the multimap m2." << endl;  
  
   if ( m1 >= m3 )  
      cout << "The multimap m1 is greater than or equal to the multimap m3." << endl;  
   else  
      cout << "The multimap m1 is less than the multimap m3." << endl;  
  
   if ( m1 >= m4 )  
      cout << "The multimap m1 is greater than or equal to the multimap m4." << endl;  
   else  
      cout << "The multimap m1 is less than the multimap m4." << endl;  
}  
\* Output:   
The multimap m1 is less than the multimap m2.  
The multimap m1 is greater than or equal to the multimap m3.  
The multimap m1 is greater than or equal to the multimap m4.  
*\  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<map>](../standard-library/map.md)



