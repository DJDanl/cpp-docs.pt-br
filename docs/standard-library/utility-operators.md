---
title: Operadores &lt;utility&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: a6617109-2cec-4a69-948f-6c87116eda5f
caps.latest.revision: 13
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ff42eebac50a016990a26dc358684dd70a33af84
ms.lasthandoff: 02/25/2017

---
# <a name="ltutilitygt-operators"></a>Operadores &lt;utility&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|[operator&gt;=](#operator_gt__eq)|  
|[operator&lt;](#operator_lt_)|[operator&lt;=](#operator_lt__eq)|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_neq"></a>  operator!=  
 Testa se o objeto pair à esquerda do operador é diferente do objeto pair à direita.  
  
```  
template <class Type>  
constexpr bool operator!=(const Type& left, const Type& right);

template <class T, class U>  
constexpr bool operator!=(const pair<T, U>& left, const pair<T, U>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo **pair.**  
  
 ` right`  
 Um objeto do tipo `pair`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os pares forem diferentes; **false** se os pares forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Um par será igual a outro par se cada um dos seus respectivos elementos for igual. Dois pares serão diferentes se o primeiro ou o segundo elemento não for igual ao elemento correspondente do outro par.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// utility_op_ne.cpp  
// compile with: /EHsc  
#include <utility>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   pair <int, double> p1, p2, p3;  
  
   p1 = make_pair ( 10, 1.11e-1 );  
   p2 = make_pair ( 1000, 1.11e-3 );  
   p3 = make_pair ( 10, 1.11e-1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl << endl;  
  
   if ( p1 != p2 )  
      cout << "The pairs p1 and p2 are not equal." << endl;  
   else  
      cout << "The pairs p1 and p2 are equal." << endl;  
  
   if ( p1 != p3 )  
      cout << "The pairs p1 and p3 are not equal." << endl;  
   else  
      cout << "The pairs p1 and p3 are equal." << endl;  
}  
```  
  
```Output  
The pair p1 is: ( 10, 0.111 ).  
The pair p2 is: ( 1000, 0.00111 ).  
The pair p3 is: ( 10, 0.111 ).  
  
The pairs p1 and p2 are not equal.  
The pairs p1 and p3 are equal.  
```  
  
##  <a name="operator_eq_eq"></a>  operator==  
 Testa se o objeto pair à esquerda do operador é igual ao objeto pair à direita.  
  
```  
template <class T, class U>  
constexpr bool operator==(const pair<T, U>& left, const pair<T, U>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo **pair.**  
  
 ` right`  
 Um objeto do tipo `pair`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os pares forem iguais; **false** se os `pair`s não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Um par será igual a outro par se cada um dos seus respectivos elementos for igual. A função retorna ` left`. **first** == ` right`. **first** && ` left`. **second** == ` right`. **second**. Dois pares serão diferentes se o primeiro ou o segundo elemento não for igual ao elemento correspondente do outro par.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// utility_op_eq.cpp  
// compile with: /EHsc  
#include <utility>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   pair <int, double> p1, p2, p3;  
  
   p1 = make_pair ( 10, 1.11e-1 );  
   p2 = make_pair ( 1000, 1.11e-3 );  
   p3 = make_pair ( 10, 1.11e-1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl << endl;  
  
   if ( p1 == p2 )  
      cout << "The pairs p1 and p2 are equal." << endl;  
   else  
      cout << "The pairs p1 and p2 are not equal." << endl;  
  
   if ( p1 == p3 )  
      cout << "The pairs p1 and p3 are equal." << endl;  
   else  
      cout << "The pairs p1 and p3 are not equal." << endl;  
}  
```  
  
##  <a name="operator_lt_"></a>  operator&lt;  
 Testa se o objeto pair à esquerda do operador é menor que o objeto pair à direita.  
  
```  
template <class T, class U>  
constexpr bool operator<(const pair<T, U>& left, const pair<T, U>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `pair` ao lado esquerdo do operador.  
  
 ` right`  
 Um objeto do tipo `pair` ao lado direito do operador.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o `pair` à esquerda do operador for estritamente menor que o `pair` à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 O objeto ` left``pair` deve ser estritamente menor do que o objeto ` right``pair` se ` left` for menor que e não for igual a ` right.`  
  
 Em uma comparação de pares, os primeiros elementos dos valores dos dois pares têm prioridade mais alta. Se eles forem diferentes, o resultado da comparação entre eles será considerado o resultado da comparação do par. Se os valores dos primeiros elementos não forem diferentes, os valores do segundo elemento serão comparados e o resultado dessa comparação será interpretado como o resultado da comparação do par.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// utility_op_lt.cpp  
// compile with: /EHsc  
#include <utility>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   pair <int, double> p1, p2, p3;  
  
   p1 = make_pair ( 10, 2.22e-1 );  
   p2 = make_pair ( 100, 1.11e-1 );  
   p3 = make_pair ( 10, 1.11e-1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl << endl;  
  
   if ( p1 < p2 )  
      cout << "The pair p1 is less than the pair p2." << endl;  
   else  
      cout << "The pair p1 is not less than the pair p2." << endl;  
  
   if ( p1 < p3 )  
      cout << "The pair p1 is less than the pair p3." << endl;  
   else  
      cout << "The pair p1 is not less than the pair p3." << endl;  
}  
```  
  
```Output  
The pair p1 is: ( 10, 0.222 ).  
The pair p2 is: ( 100, 0.111 ).  
The pair p3 is: ( 10, 0.111 ).  
  
The pair p1 is less than the pair p2.  
The pair p1 is not less than the pair p3.  
```  
  
##  <a name="operator_lt__eq"></a>  operator&lt;=  
 Testa se o objeto pair à esquerda do operador é menor que ou igual ao objeto pair à direita.  
  
```  
template <class Type>  
constexpr bool operator<=(const Type& left, const Type& right);

template <class T, class U>  
constexpr bool operator<=(const pair<T, U>& left, const pair<T, U>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `pair` ao lado esquerdo do operador.  
  
 ` right`  
 Um objeto do tipo `pair` ao lado direito do operador.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a `pair` no lado esquerdo do operador for menor que ou igual à `pair` à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Em uma comparação de pares, os primeiros elementos dos valores dos dois pares têm prioridade mais alta. Se eles forem diferentes, o resultado da comparação entre eles será considerado o resultado da comparação do par. Se os valores dos primeiros elementos não forem diferentes, os valores do segundo elemento serão comparados e o resultado dessa comparação será interpretado como o resultado da comparação do par.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// utility_op_le.cpp  
// compile with: /EHsc  
#include <utility>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   pair <int, double> p1, p2, p3, p4;  
  
   p1 = make_pair ( 10, 2.22e-1 );  
   p2 = make_pair ( 100, 1.11e-1 );  
   p3 = make_pair ( 10, 1.11e-1 );  
   p4 = make_pair ( 10, 2.22e-1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl;  
   cout << "The pair p4 is: ( " << p4.first << ", "   
        << p4.second << " )." << endl << endl;  
  
   if ( p1 <= p2 )  
      cout << "The pair p1 is less than or equal to the pair p2." << endl;  
   else  
      cout << "The pair p1 is greater than the pair p2." << endl;  
  
   if ( p1 <= p3 )  
      cout << "The pair p1 is less than or equal to the pair p3." << endl;  
   else  
      cout << "The pair p1 is greater than the pair p3." << endl;  
  
   if ( p1 <= p4 )  
      cout << "The pair p1 is less than or equal to the pair p4." << endl;  
   else  
      cout << "The pair p1 is greater than the pair p4." << endl;  
}  
```  
  
```Output  
The pair p1 is: ( 10, 0.222 ).  
The pair p2 is: ( 100, 0.111 ).  
The pair p3 is: ( 10, 0.111 ).  
The pair p4 is: ( 10, 0.222 ).  
  
The pair p1 is less than or equal to the pair p2.  
The pair p1 is greater than the pair p3.  
The pair p1 is less than or equal to the pair p4.  
```  
  
##  <a name="operator_gt_"></a>  operator&gt;  
 Testa se o objeto pair à esquerda do operador é maior que o objeto pair à direita.  
  
```  
template <class Type>  
constexpr bool operator>(const Type& left, const Type& right);

template <class T, class U>  
constexpr bool operator>(const pair<T, U>& left, const pair<T, U>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `pair` ao lado esquerdo do operador.  
  
 ` right`  
 Um objeto do tipo `pair` ao lado direito do operador.  
  
### <a name="return-value"></a>Valor de retorno  
 **true**, se o `pair` à esquerda do operador for estritamente maior que o `pair` à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 O objeto ` left``pair` deverá ser estritamente maior do que o objeto ` right``pair` se ` left` for maior que e não for igual a ` right.`  
  
 Em uma comparação de pares, os primeiros elementos dos valores dos dois pares têm prioridade mais alta. Se eles forem diferentes, o resultado da comparação entre eles será considerado o resultado da comparação do par. Se os valores dos primeiros elementos não forem diferentes, os valores do segundo elemento serão comparados e o resultado dessa comparação será interpretado como o resultado da comparação do par.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// utility_op_gt.cpp  
// compile with: /EHsc  
#include <utility>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   pair <int, double> p1, p2, p3, p4;  
  
   p1 = make_pair ( 10, 2.22e-1 );  
   p2 = make_pair ( 100, 1.11e-1 );  
   p3 = make_pair ( 10, 1.11e-1 );  
   p4 = make_pair ( 10, 2.22e-1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl;  
   cout << "The pair p4 is: ( " << p4.first << ", "   
        << p4.second << " )." << endl << endl;  
  
   if ( p1 > p2 )  
      cout << "The pair p1 is greater than the pair p2." << endl;  
   else  
      cout << "The pair p1 is not greater than the pair p2." << endl;  
  
   if ( p1 > p3 )  
      cout << "The pair p1 is greater than the pair p3." << endl;  
   else  
      cout << "The pair p1 is not greater than the pair p3." << endl;  
  
   if ( p1 > p4 )  
      cout << "The pair p1 is greater than the pair p4." << endl;  
   else  
      cout << "The pair p1 is not greater than the pair p4." << endl;  
}  
```  
  
```Output  
The pair p1 is: ( 10, 0.222 ).  
The pair p2 is: ( 100, 0.111 ).  
The pair p3 is: ( 10, 0.111 ).  
The pair p4 is: ( 10, 0.222 ).  
  
The pair p1 is not greater than the pair p2.  
The pair p1 is greater than the pair p3.  
The pair p1 is not greater than the pair p4.  
```  
  
##  <a name="operator_gt__eq"></a>  operator&gt;=  
 Testa se o objeto pair à esquerda do operador é maior que ou igual ao objeto pair à direita.  
  
```  
template <class Type>  
constexpr bool operator>=(const Type& left, const Type& right);

template <class T, class U>  
constexpr bool operator>=(const pair<T, U>& left, const pair<T, U>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `pair` ao lado esquerdo do operador.  
  
 ` right`  
 Um objeto do tipo `pair` ao lado direito do operador.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se a `pair` no lado esquerdo do operador for maior que ou igual à `pair` à direita do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Em uma comparação de pares, os primeiros elementos dos valores dos dois pares têm prioridade mais alta. Se eles forem diferentes, o resultado da comparação entre eles será considerado o resultado da comparação do par. Se os valores dos primeiros elementos não forem diferentes, os valores do segundo elemento serão comparados e o resultado dessa comparação será interpretado como o resultado da comparação do par.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// utility_op_ge.cpp  
// compile with: /EHsc  
#include <utility>  
#include <iomanip>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   pair <int, double> p1, p2, p3, p4;  
  
   p1 = make_pair ( 10, 2.22e-1 );  
   p2 = make_pair ( 100, 1.11e-1 );  
   p3 = make_pair ( 10, 1.11e-1 );  
   p4 = make_pair ( 10, 2.22e-1 );  
  
   cout.precision ( 3 );  
   cout << "The pair p1 is: ( " << p1.first << ", "   
        << p1.second << " )." << endl;  
   cout << "The pair p2 is: ( " << p2.first << ", "   
        << p2.second << " )." << endl;  
   cout << "The pair p3 is: ( " << p3.first << ", "   
        << p3.second << " )." << endl;  
   cout << "The pair p4 is: ( " << p4.first << ", "   
        << p4.second << " )." << endl << endl;  
  
   if ( p1 >= p2 )  
      cout << "Pair p1 is greater than or equal to pair p2." << endl;  
   else  
      cout << "The pair p1 is less than the pair p2." << endl;  
  
   if ( p1 >= p3 )  
      cout << "Pair p1 is greater than or equal to pair p3." << endl;  
   else  
      cout << "The pair p1 is less than the pair p3." << endl;  
  
   if ( p1 >= p4 )  
      cout << "Pair p1 is greater than or equal to pair p4." << endl;  
   else  
      cout << "The pair p1 is less than the pair p4." << endl;  
}  
```  
  
```Output  
The pair p1 is: ( 10, 0.222 ).  
The pair p2 is: ( 100, 0.111 ).  
The pair p3 is: ( 10, 0.111 ).  
The pair p4 is: ( 10, 0.222 ).  
  
The pair p1 is less than the pair p2.  
Pair p1 is greater than or equal to pair p3.  
Pair p1 is greater than or equal to pair p4.  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<utility>](../standard-library/utility.md)


