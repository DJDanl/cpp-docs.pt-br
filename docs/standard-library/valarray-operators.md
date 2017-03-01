---
title: Operadores &lt;valarray&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 8a53562c-90ab-4eb3-85d3-ada5259d90b0
caps.latest.revision: 8
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c2d2d523f8085db02336be1efc80f34b5cf62b27
ms.lasthandoff: 02/25/2017

---
# <a name="ltvalarraygt-operators"></a>Operadores &lt;valarray&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator%](#operator_mod)|[operator&amp;](#operator_amp_)|  
|[operator&amp;&amp;](#operator_amp__amp_)|[operator&gt;](#operator_gt_)|[operator&gt;&gt;](#operator_gt__gt_)|  
|[operator&gt;=](#operator_gt__eq)|[operator&lt;](#operator_lt_)|[operator&lt;&lt;](#operator_lt__lt_)|  
|[operator&lt;=](#operator_lt__eq)|[operator*](#operator_star)|[operator+](#operator_add)|  
|[operator-](#operator-)|[operator/](#operator_)|[operator==](#operator_eq_eq)|  
|[operator^](#operator_xor)|[operator|](#operator_or)|[operator||](#operator_lor)|  
  
##  <a name="a-nameoperatorneqa--operator"></a><a name="operator_neq"></a>  operator!=  
 Testa se os elementos correspondentes de duas valarrays de tamanhos iguais são diferentes ou se todos os elementos de uma valarray são diferentes de um valor especificado.  
  
```  
template <class Type>  
valarray<bool>  
operator!=(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator!=(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator!=(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos deverão ser testados em relação à desigualdade.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos deverão ser testados em relação à desigualdade.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray de valores boolianos, sendo cada um deles:  
  
- **true** se os elementos correspondentes forem diferentes.  
  
- **false** se os elementos correspondentes não forem diferentes.  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador de modelo retorna um objeto da classe [valarray\<bool>](../standard-library/valarray-bool-class.md), cujos elementos `I` de cada são ` left`[ `I`] != ` right`[ `I`].  
  
 O segundo operador de modelo armazena no elemento *deixei*[ `I`]! = _ *direita*.  
  
 O terceiro operador de modelo armazena no elemento *deixei* ! = ` right`[ `I`].  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_ne.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaNE ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL != vaR );  
   cout << "The element-by-element result of "  
        << "the not equal comparison test is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 0 1 -2 3 -4 5 -6 7 -8 9 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The element-by-element result of the not equal comparison test is the  
 valarray: ( 0 0 1 0 1 0 1 0 1 0 ).  
*\  
```  
  
##  <a name="a-nameoperatormoda--operator"></a><a name="operator_mod"></a> operator%  
 Obtém o resto da divisão dos elementos correspondentes de duas valarrays de tamanhos iguais, da divisão de uma valarray por um valor especificado ou da divisão de um valor especificado por uma valarray.  
  
```  
template <class Type>  
valarray<Type>  
operator%(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator%(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator%(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um valor ou valarray que serve como o dividendo pelo qual outro valor ou valarray deve ser dividido.  
  
 ` right`  
 Um valor ou valarray que serve como o divisor e que divide outro valor ou valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são os restos elemento a elemento de ` left` divididos por ` right.`  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_rem.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 6 ), vaR ( 6 );  
   valarray<int> vaREM ( 6 );  
   for ( i = 0 ; i < 6 ; i += 2 )  
      vaL [ i ] =  53;  
   for ( i = 1 ; i < 6 ; i += 2 )  
      vaL [ i ] =  -67;  
   for ( i = 0 ; i < 6 ; i++ )  
      vaR [ i ] =  3*i+1;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaREM = ( vaL % vaR );  
   cout << "The remainders from the element-by-element "  
        << "division is the\n valarray: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaREM [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 53 -67 53 -67 53 -67 ).  
The initial Right valarray is: ( 1 4 7 10 13 16 ).  
The remainders from the element-by-element division is the  
 valarray: ( 0 -3 4 -7 1 -3 ).  
*\  
```  
  
##  <a name="a-nameoperatorampa--operatoramp"></a><a name="operator_amp_"></a>  operator&amp;  
 Obtém o **AND** bit a bit entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento.  
  
```  
template <class Type>  
valarray<Type>  
operator&(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator&(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator&(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos respectivos elementos deverão ser combinados com o **AND** bit a bit ou um valor especificado do tipo de elemento que deverá ser combinado bit a bit com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos deverão ser combinados com o **AND** bit a bit ou um valor especificado do tipo de elemento que deverá ser combinado bit a bit com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a combinação em relação ao elemento da operação AND bit a bit de ` left` e` right.`  
  
### <a name="remarks"></a>Comentários  
 Uma operação bit a bit só pode ser usada para manipular bits nos tipos de dados `char` e `int` e variantes e não em **float**, **double**, **longdouble**, `void``bool` ou outros tipos de dados mais complexos.  
  
 O **AND** bit a bit tem a mesma tabela de verdade que o **AND** lógico, mas se aplica ao tipo de dados em nível de bits individuais. O [operator&&](../standard-library/valarray-operators.md#operator_amp__amp_) aplica-se no nível de elemento contando todos os valores diferentes de zero como true e o resultado é uma valarray de valores boolianos. Por outro lado, o **ANDoperator&** bit a bit pode resultar em uma valarray de valores diferentes de 0 ou 1, dependendo do resultado da operação bit a bit.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_bitand.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<int> vaBWA ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i+1;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaBWA = ( vaL & vaR );  
   cout << "The element-by-element result of "  
        << "the bitwise operator & is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaBWA [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is:  ( 0 2 0 4 0 6 0 8 0 10 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The element-by-element result of the bitwise operator & is the  
 valarray: ( 0 0 0 0 0 4 0 0 0 8 ).  
*\  
```  
  
##  <a name="a-nameoperatorampampa--operatorampamp"></a><a name="operator_amp__amp_"></a>  operator&amp;&amp;  
 Obtém o **AND** lógico entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento da valarray.  
  
```  
template <class Type>  
valarray<bool>  
operator&&(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator&&(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator&&(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos respectivos elementos deverão ser combinados com o **AND** lógico ou um valor especificado do tipo de elemento que deverá ser combinado com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos deverão ser combinados com o **AND** lógico ou um valor especificado do tipo de elemento que deverá ser combinado com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são do tipo bool e são a combinação em relação ao elemento da lógica **AND** operação de ` left` e` right.`  
  
### <a name="remarks"></a>Comentários  
 O **ANDoperator&&** lógico aplica-se no nível de elemento contando todos os valores diferentes de zero como true e o resultado é uma valarray de valores boolianos. Por outro lado, a versão bit a bit de **AND**, [operator&, ](../standard-library/valarray-operators.md#operator_amp_), pode resultar em uma valarray de valores diferentes de 0 ou 1, dependendo do resultado da operação bit a bit.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_logand.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaLAA ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i-1;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is:  ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaLAA = ( vaL && vaR );  
   cout << "The element-by-element result of "  
        << "the logical AND operator&& is the\n valarray: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaLAA [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is:  ( 0 0 0 2 0 4 0 6 0 8 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The element-by-element result of the logical AND operator&& is the  
 valarray: ( 0 0 0 1 0 1 0 1 0 1 ).  
*\  
```  
  
##  <a name="a-nameoperatorgta--operatorgt"></a><a name="operator_gt_"></a>  operator&gt;  
 Testa se os elementos de uma valarray são maiores que os elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores ou menores que um valor especificado.  
  
```  
template <class Type>  
valarray<bool>  
operator>(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator>(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator>(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos devem ser comparados ou um valor especificado que deve ser comparado com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos devem ser comparados ou um valor especificado a ser comparado com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray de valores boolianos, sendo cada um deles:  
  
- **true** se o valor ou o elemento ` left` for maior que o valor ou o elemento ` right` correspondente.  
  
- **false** se o valor ou o elemento ` left` não for maior que o valor ou o elemento ` right` correspondente.  
  
### <a name="remarks"></a>Comentários  
 Se o número de elementos em duas valarrays não for igual, o resultado será indefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_gt.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaNE ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i - 1;  
  
   cout << "The initial Left valarray is: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL > vaR );  
   cout << "The element-by-element result of "  
        << "the greater than comparison test is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 0 1 -2 3 -4 5 -6 7 -8 9 ).  
The initial Right valarray is: ( -1 0 1 2 3 4 5 6 7 8 ).  
The element-by-element result of the greater than comparison test is the  
 valarray: ( 1 1 0 1 0 1 0 1 0 1 ).  
*\  
```  
  
##  <a name="a-nameoperatorgteqa--operatorgt"></a><a name="operator_gt__eq"></a>  operator&gt;=  
 Testa se os elementos de uma valarray são maiores ou iguais aos elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores, menores ou iguais a um valor especificado.  
  
```  
template <class Type>  
valarray<bool>  
operator>=(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator>=(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator>=(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos devem ser comparados ou um valor especificado que deve ser comparado com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos devem ser comparados ou um valor especificado a ser comparado com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray de valores boolianos, sendo cada um deles:  
  
- **true** se o valor ou o elemento ` left` for maior ou igual ao valor ou ao elemento ` right` correspondente.  
  
- **false** se o valor ou o elemento ` left` for menor que o valor ou o elemento ` right` correspondente.  
  
### <a name="remarks"></a>Comentários  
 Se o número de elementos em duas valarrays não for igual, o resultado será indefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_ge.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaNE ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i - 1;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL >= vaR );  
   cout << "The element-by-element result of "  
        << "the greater than or equal test is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 0 1 -2 3 -4 5 -6 7 -8 9 ).  
The initial Right valarray is: ( -1 0 1 2 3 4 5 6 7 8 ).  
The element-by-element result of the greater than or equal test is the  
 valarray: ( 1 1 0 1 0 1 0 1 0 1 ).  
*\  
```  
  
##  <a name="a-nameoperatorgtgta--operatorgtgt"></a><a name="operator_gt__gt_"></a>  operator&gt;&gt;  
 Desloca para a direita os bits de cada elemento de uma valarray por um número especificado de posições ou por um valor elemento a elemento especificado por uma segunda valarray.  
  
```  
template <class Type>  
valarray<Type>  
operator>>(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator>>(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator>>(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 O valor que deve ser deslocado ou a valarray cujos elementos deverão ser deslocados.  
  
 ` right`  
 O valor que indica a quantidade de deslocamentos para a direita ou a valarray cujos elementos indicam a quantidade elemento a elemento dos deslocamentos para a direita.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos foram deslocados para a direita conforme o valor especificado.  
  
### <a name="remarks"></a>Comentários  
 Os números com sinais têm seus sinais preservados.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_rs.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   valarray<int> vaNE ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  64;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -64;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL >> vaR );  
   cout << "The element-by-element result of "  
        << "the right shift is the\n valarray: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 64 -64 64 -64 64 -64 64 -64 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the right shift is the  
 valarray: ( 64 -32 16 -8 4 -2 1 -1 ).  
*\  
```  
  
##  <a name="a-nameoperatorlta--operatorlt"></a><a name="operator_lt_"></a>  operator&lt;  
 Testa se os elementos de uma valarray são menores que os elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores ou menores que um valor especificado.  
  
```  
template <class Type>  
valarray<bool>  
operator<(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator<(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator<(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos devem ser comparados ou um valor especificado que deve ser comparado com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos devem ser comparados ou um valor especificado a ser comparado com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray de valores boolianos, sendo cada um deles:  
  
- **true** se o valor ou o elemento ` left` for menor que o valor ou o elemento ` right` correspondente.  
  
- **false** se o valor ou o elemento ` left` não for menor que o valor ou o elemento ` right` correspondente.  
  
### <a name="remarks"></a>Comentários  
 Se o número de elementos em duas valarrays não for igual, o resultado será indefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_lt.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaNE ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL < vaR );  
   cout << "The element-by-element result of "  
        << "the less-than comparson test is the\n valarray: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 0 1 -2 3 -4 5 -6 7 -8 9 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The element-by-element result of the less-than comparson test is the  
 valarray: ( 0 0 1 0 1 0 1 0 1 0 ).  
*\  
```  
  
##  <a name="a-nameoperatorlteqa--operatorlt"></a><a name="operator_lt__eq"></a>  operator&lt;=  
 Testa se os elementos de uma valarray são menores ou iguais aos elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores, menores ou iguais a um valor especificado.  
  
```  
template <class Type>  
valarray<bool>  
operator<=(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator<=(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator<=(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos devem ser comparados ou um valor especificado que deve ser comparado com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos devem ser comparados ou um valor especificado a ser comparado com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray de valores boolianos, sendo cada um deles:  
  
- **true** se o valor ou o elemento ` left` for menor ou igual ao valor ou ao elemento ` right` correspondente.  
  
- **false** se o valor ou o elemento ` left` for maior que o valor ou o elemento ` right` correspondente.  
  
### <a name="remarks"></a>Comentários  
 Se o número de elementos em duas valarrays não for igual, o resultado será indefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_le.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaNE ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i - 1;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL <= vaR );  
   cout << "The element-by-element result of "  
        << "the less than or equal test is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 0 1 -2 3 -4 5 -6 7 -8 9 ).  
The initial Right valarray is: ( -1 0 1 2 3 4 5 6 7 8 ).  
The element-by-element result of the less than or equal test is the  
 valarray: ( 0 0 1 0 1 0 1 0 1 0 ).  
*\  
```  
  
##  <a name="a-nameoperatorltlta--operatorltlt"></a><a name="operator_lt__lt_"></a>  operator&lt;&lt;  
 Desloca para a esquerda os bits de cada elemento de uma valarray por um número especificado de posições ou por um valor elemento a elemento especificado por uma segunda valarray.  
  
```  
template <class Type>  
valarray<Type>  
operator<<(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator<<(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator<<(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 O valor que deve ser deslocado ou a valarray cujos elementos deverão ser deslocados.  
  
 ` right`  
 O valor que indica a quantidade de deslocamentos para a esquerda ou a valarray cujos elementos indicam a quantidade elemento a elemento dos deslocamentos para a esquerda.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos foram deslocados para a esquerda conforme o valor especificado.  
  
### <a name="remarks"></a>Comentários  
 Os números com sinais têm seus sinais preservados.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_ls.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   valarray<int> vaNE ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  1;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -1;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL << vaR );  
   cout << "The element-by-element result of "  
        << "the left shift is the\n valarray: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 1 -1 1 -1 1 -1 1 -1 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the left shift is the  
 valarray: ( 1 -2 4 -8 16 -32 64 -128 ).  
*\  
```  
  
##  <a name="a-nameoperatorstara--operator"></a><a name="operator_star"></a>  operator*  
 Obtém o produto elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado.  
  
```  
template <class Type>  
valarray<Type>  
operator*(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator*(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator*(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos devem ser multiplicados ou um valor especificado que deve ser multiplicado pelos elementos individuais de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos devem ser multiplicados ou um valor especificado que deve ser multiplicado pelos elementos individuais de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são o produto elemento a elemento de ` left` e ` right.`  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_eprod.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   valarray<int> vaNE ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  2;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -1;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL * vaR );  
   cout << "The element-by-element result of "  
        << "the multiplication is the\n valarray: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 2 -1 2 -1 2 -1 2 -1 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the multiplication is the  
 valarray: ( 0 -1 4 -3 8 -5 12 -7 ).  
*\  
```  
  
##  <a name="a-nameoperatoradda--operator"></a><a name="operator_add"></a>  operator+  
 Obtém a soma elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado.  
  
```  
template <class Type>  
valarray<Type>  
operator+(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator+(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator+(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos devem ser adicionados ou um valor especificado que deve ser adicionado a cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos devem ser adicionados ou um valor especificado que deve ser adicionado a cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são a soma elemento a elemento de ` left` e ` right.`  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_esum.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   valarray<int> vaNE ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  2;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -1;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL + vaR );  
   cout << "The element-by-element result of "  
        << "the sum is the\n valarray: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 2 -1 2 -1 2 -1 2 -1 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the sum is the  
 valarray: ( 2 0 4 2 6 4 8 6 ).  
*\  
```  
  
##  <a name="a-nameoperator-a--operator-"></a><a name="operator-"></a>  operator-  
 Obtém a diferença elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado.  
  
```  
template <class Type>  
valarray<Type>  
operator-(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator-(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator-(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um valor ou valarray que serve como o diminuendo do qual devem ser subtraídos os valores ou as valarrays na formação da diferença.  
  
 ` right`  
 Um valor ou valarray que serve como o subtraendo do qual devem ser subtraídos os outros valores ou valarrays na formação da diferença.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são a diferença elemento a elemento de ` left` e ` right.`  
  
### <a name="remarks"></a>Comentários  
 A terminologia aritmética usada na descrição de uma subtração:  
  
 diferença = diminuendo – subtraendo  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_ediff.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   valarray<int> vaNE ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  10;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL - vaR );  
   cout << "The element-by-element result of "  
        << "the difference is the\n valarray: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 10 0 10 0 10 0 10 0 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the difference is the  
 valarray: ( 10 -1 8 -3 6 -5 4 -7 ).  
*\  
```  
  
##  <a name="a-nameoperatora--operator"></a><a name="operator_"></a>  operator/  
 Obtém o quociente elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado.  
  
```  
template <class Type>  
valarray<Type>  
operator/(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator/(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator/(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um valor ou valarray que serve como o dividendo pelo qual outro valor ou valarray deve ser dividido na formação do quociente.  
  
 ` right`  
 Um valor ou valarray que serve como o divisor e que divide outro valor ou valarray na formação do quociente.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são o quociente elemento a elemento de ` left` dividido por ` right.`  
  
### <a name="remarks"></a>Comentários  
 A terminologia aritmética usada na descrição de uma divisão:  
  
 quociente = dividendo/divisor  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_equo.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<double> vaL ( 6 ), vaR ( 6 );  
   valarray<double> vaNE ( 6 );  
   for ( i = 0 ; i < 6 ; i += 2 )  
      vaL [ i ] =  100;  
   for ( i = 1 ; i < 6 ; i += 2 )  
      vaL [ i ] =  -100;  
   for ( i = 0 ; i < 6 ; i++ )  
      vaR [ i ] =  2*i;  
  
   cout << "The initial Left valarray is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL / vaR );  
   cout << "The element-by-element result of "  
        << "the quotient is the\n valarray: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 100 -100 100 -100 100 -100 ).  
The initial Right valarray is: ( 0 2 4 6 8 10 ).  
The element-by-element result of the quotient is the  
 valarray: ( 1.#INF -50 25 -16.6667 12.5 -10 ).  
*\  
```  
  
##  <a name="a-nameoperatoreqeqa--operator"></a><a name="operator_eq_eq"></a>  operator==  
 Testa se os elementos correspondentes de duas valarrays de tamanhos iguais são iguais ou se todos os elementos de uma valarray são iguais a um valor especificado.  
  
```  
template <class Type>  
valarray<bool>  
operator==(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator==(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator==(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos elementos deverão ser testados em relação à igualdade.  
  
 ` right`  
 A segunda das duas valarrays cujos elementos deverão ser testados em relação à igualdade.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray de valores boolianos, sendo cada um deles:  
  
- **true** se os elementos correspondentes forem iguais.  
  
- **false** se os elementos correspondentes não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador de modelo retorna um objeto da classe [valarray\<bool>](../standard-library/valarray-bool-class.md), cujos elementos `I` de cada são _ *Left*[ `I`] == \_ *Right*[ `I`]. O segundo operador de modelo armazena no elemento `I`` left`[ `I`] == \_ *Right*. O terceiro operador de modelo armazena no elemento `I`` left` == ` right`[ `I`].  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_eq.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaNE ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial Left valarray is: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNE = ( vaL == vaR );  
   cout << "The element-by-element result of "  
        << "the equality comparison test is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNE [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is: ( 0 1 -2 3 -4 5 -6 7 -8 9 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The element-by-element result of the equality comparison test is the  
 valarray: ( 1 1 0 1 0 1 0 1 0 1 ).  
*\  
```  
  
##  <a name="a-nameoperatorxora--operator"></a><a name="operator_xor"></a> operator^  
 Obtém o `OR` bit a bit exclusivo (**XOR**) entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento.  
  
```  
template <class Type>  
valarray<Type>  
operator^(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator^(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator^(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos respectivos elementos deverão ser combinados com o **XOR** bit a bit ou um valor especificado do tipo de elemento que deverá ser combinado bit a bit com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos deverão ser combinados com o **XOR** bit a bit ou um valor especificado do tipo de elemento que deverá ser combinado bit a bit com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a combinação em relação ao elemento de bit a bit **XOR** operação de ` left` e` right.`  
  
### <a name="remarks"></a>Comentários  
 Uma operação bit a bit só pode ser usada para manipular bits nos tipos de dados `char` e `int` e variantes e não em **float**, **double**, `long double`, `void``bool` ou outros tipos de dados mais complexos.  
  
 O `OR` bit a bit exclusivo (**XOR**) tem a seguinte semântica: considerando os bits *b*1 e *b*2, *b*1 **XOR** *b*2 será **true** se exatamente um dos bits for true; **false** se ambos os bits forem false ou se ambos os bits forem true.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_xor.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<int> vaLAA ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  1;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
  
   cout << "The initial Left valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaLAA = ( vaL ^ vaR );  
   cout << "The element-by-element result of "  
        << "the bitwise XOR operator^ is the\n valarray: ( ";  
           for ( i = 0 ; i < 10 ; i++ )  
         cout << vaLAA [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is:  ( 1 0 1 0 1 0 1 0 1 0 ).  
The initial Right valarray is: ( 0 0 1 3 3 4 6 6 7 9 ).  
The element-by-element result of the bitwise XOR operator^ is the  
 valarray: ( 1 0 0 3 2 4 7 6 6 9 ).  
*\  
```  
  
##  <a name="a-nameoperatorora--operator124"></a><a name="operator_or"></a> operator&#124;  
 Obtém o `OR` bit a bit entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento.  
  
```  
template <class Type>  
valarray<Type>  
operator|(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
operator|(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<Type>  
operator|(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos respectivos elementos deverão ser combinados com o `OR` bit a bit ou um valor especificado do tipo de elemento que deverá ser combinado bit a bit com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos deverão ser combinados com o `OR` bit a bit ou um valor especificado do tipo de elemento que deverá ser combinado bit a bit com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a combinação em relação ao elemento de bit a bit `OR` operação de ` left` e` right.`  
  
### <a name="remarks"></a>Comentários  
 Uma operação bit a bit só pode ser usada para manipular bits nos tipos de dados `char` e `int` e variantes e não em **float**, **double**, **longdouble**, `void`, `bool` ou outros tipos de dados mais complexos.  
  
 O OR bit a bit tem a mesma tabela de verdade que o `OR` lógico, mas se aplica ao tipo de dados em nível de bits individuais. Considerando os bits *b*1 e *b*2, *b*1 `OR` *b*2 será **true** se pelo menos um dos bits for true ou **false** se ambos os bits forem false. O `OR`[operator&#124;&#124;](../standard-library/valarray-operators.md#operator_lor) lógico aplica-se no nível de elemento contando todos os valores diferentes de zero como **true** e o resultado é uma valarray de valores boolianos. Por outro lado, o OR `operator|` bit a bit pode resultar em uma valarray de valores diferentes de 0 ou 1, dependendo do resultado da operação bit a bit.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_bitor.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<int> vaLAA ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  1;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
  
   cout << "The initial Left valarray is:  ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaLAA = ( vaL | vaR );  
   cout << "The element-by-element result of "  
        << "the bitwise OR operator| is the\n valarray: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaLAA [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is:  ( 1 0 1 0 1 0 1 0 1 0 ).  
The initial Right valarray is: ( 0 0 1 3 3 4 6 6 7 9 ).  
The element-by-element result of the bitwise OR operator| is the  
 valarray: ( 1 0 1 3 3 4 7 6 7 9 ).  
*\  
```  
  
##  <a name="a-nameoperatorlora--operator124124"></a><a name="operator_lor"></a> operator&#124;&#124;  
 Obtém o `OR` lógico entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento da valarray.  
  
```  
template <class Type>  
valarray<bool>  
operator||(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<bool>  
operator||(
    const valarray<Type>& left,  
    const Type& right);

template <class Type>  
valarray<bool>  
operator||(
    const Type& left,  
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 A primeira das duas valarrays cujos respectivos elementos deverão ser combinados com o `OR` lógico ou um valor especificado do tipo de elemento que deverá ser combinado com cada elemento de uma valarray.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos deverão ser combinados com o `OR` lógico ou um valor especificado do tipo de elemento que deverá ser combinado com cada elemento de uma valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são do tipo `bool` e são a combinação em relação ao elemento da operação OR lógica de ` left` e` right.`  
  
### <a name="remarks"></a>Comentários  
 O `OR``operator||` lógico aplica-se no nível de elemento contando todos os valores diferentes de zero como **true** e o resultado é uma valarray de valores boolianos. Por outro lado, a versão bit a bit de `OR`, [operator&#124;](../standard-library/valarray-operators.md#operator_or), pode resultar em uma valarray de valores diferentes de 0 ou 1, dependendo do resultado da operação bit a bit.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_op_logor.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   valarray<bool> vaLOR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i-1;  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  0;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  0;  
  
   cout << "The initial Left valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaLOR = ( vaL || vaR );  
   cout << "The element-by-element result of "  
        << "the logical OR operator|| is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaLOR [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial Left valarray is:  ( 0 0 0 2 0 4 0 6 0 8 ).  
The initial Right valarray is: ( 0 0 0 3 0 0 6 0 0 9 ).  
The element-by-element result of the logical OR operator|| is the  
 valarray: ( 0 0 0 1 0 1 1 1 0 1 ).  
*\  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<valarray>](../standard-library/valarray.md)


