---
title: "Funções &lt;valarray&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- valarray/std::abs
- valarray/std::acos
- valarray/std::asin
- valarray/std::atan
- valarray/std::atan2
- valarray/std::cos
- valarray/std::cosh
- valarray/std::exp
- valarray/std::log
- valarray/std::log10
- valarray/std::pow
- valarray/std::sin
- valarray/std::sinh
- valarray/std::sqrt
- valarray/std::swap
- valarray/std::tan
- valarray/std::tanh
ms.assetid: 109778fc-440e-4239-b23e-bafda2b165c2
caps.latest.revision: 12
manager: ghogen
helpviewer_keywords:
- std::abs [C++]
- std::acos [C++]
- std::asin [C++]
- std::atan [C++]
- std::atan2
- std::cos [C++]
- std::cosh [C++]
- std::exp [C++]
- std::log [C++]
- std::log10
- std::pow [C++]
- std::sin [C++]
- std::sinh [C++]
- std::sqrt [C++]
- std::swap [C++]
- std::tan [C++]
- std::tanh [C++]
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: b15c90c9346ae490e51f6b28cc508164ead395b4
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="ltvalarraygt-functions"></a>Funções &lt;valarray&gt;
||||  
|-|-|-|  
|[abs](#abs)|[acos](#acos)|[asin](#asin)|  
|[atan](#atan)|[atan2](#atan2)|[cos](#cos)|  
|[cosh](#cosh)|[exp](#exp)|[log](#log)|  
|[log10](#log10)|[pow](#pow)|[sin](#sin)|  
|[sinh](#sinh)|[sqrt](#sqrt)|[swap](#swap)|  
|[tan](#tan)|[tanh](#tanh)|  
  
##  <a name="abs"></a>  abs  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao valor absoluto dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> abs(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao valor absoluto dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_abs.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> va1 ( 9 ), va2 ( 9 );  
   for ( i = 0 ; i < 4 ; i++ )  
      va1 [ i ] =  -i;  
   for ( i = 4 ; i < 9 ; i++ )  
      va1 [ i ] =  i;  
  
   cout << "The initial valarray is: ";  
      for (i = 0 ; i < 9 ; i++ )  
         cout << va1 [ i ] << " ";  
   cout << "." << endl;  
  
   va2 = abs ( va1 );  
   cout << "The absolute value of the initial valarray is: ";  
      for (i = 0 ; i < 9 ; i++ )  
         cout << va2 [ i ] << " ";  
   cout << "." << endl;  
}  
```  
  
```Output  
The initial valarray is: 0 -1 -2 -3 4 5 6 7 8 .  
The absolute value of the initial valarray is: 0 1 2 3 4 5 6 7 8 .  
```  
  
##  <a name="acos"></a> acos  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao arco cosseno dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> acos(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao arco cosseno dos elementos da valarray de entrada.  
  
### <a name="remarks"></a>Comentários  
 As unidades dos elementos retornados estão em radianos.  
  
 O valor retornado é um valor de entidade de segurança entre 0 e +pi consistente com a entrada do valor de cosseno.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_acos.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  0.25 * i - 1;  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:";  
   for (i = 0 ; i < 9 ; i++ )  
      cout << " " << va1 [ i ];  
   cout << endl;  
  
   va2 = acos ( va1 );  
   cout << "The arccosine of the initial valarray is:\n";  
   for (i = 0 ; i < 9 ; i++ )  
      cout << setw(10) << va2 [ i ]  
         << "  radians, which is  "  
         << setw(11) << (180/pi) * va2 [ i ]  
         << "  degrees" << endl;  
}  
```  
  
```Output  
The initial valarray is: -1 -0.75 -0.5 -0.25 0 0.25 0.5 0.75 1  
The arccosine of the initial valarray is:  
   3.14159  radians, which is          180  degrees  
   2.41886  radians, which is       138.59  degrees  
    2.0944  radians, which is          120  degrees  
   1.82348  radians, which is      104.478  degrees  
    1.5708  radians, which is           90  degrees  
   1.31812  radians, which is      75.5225  degrees  
    1.0472  radians, which is           60  degrees  
  0.722734  radians, which is      41.4096  degrees  
         0  radians, which is            0  degrees  
```  
  
##  <a name="asin"></a> asin  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao arco seno dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> asin(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao arco seno dos elementos da valarray de entrada.  
  
### <a name="remarks"></a>Comentários  
 As unidades dos elementos retornados estão em radianos.  
  
 O valor de retorno é um objeto de valor entre + pi/2 e - pi/2 que é consistente com o seno de entrada de valor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_asin.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  0.25 * i - 1;  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:";  
   for (i = 0 ; i < 9 ; i++ )  
      cout << " " << va1 [ i ];  
   cout << endl;  
  
   va2 = asin ( va1 );  
   cout << "The arcsine of the initial valarray is:\n";  
   for (i = 0 ; i < 9 ; i++ )  
      cout << setw(10) << va2 [ i ]  
           << "  radians, which is  "  
           << setw(11) << (180/pi) * va2 [ i ]  
           << "  degrees" << endl;  
}  
```  
  
```Output  
The initial valarray is: -1 -0.75 -0.5 -0.25 0 0.25 0.5 0.75 1  
The arcsine of the initial valarray is:  
   -1.5708  radians, which is          -90  degrees  
 -0.848062  radians, which is     -48.5904  degrees  
 -0.523599  radians, which is          -30  degrees  
  -0.25268  radians, which is     -14.4775  degrees  
         0  radians, which is            0  degrees  
   0.25268  radians, which is      14.4775  degrees  
  0.523599  radians, which is           30  degrees  
  0.848062  radians, which is      48.5904  degrees  
    1.5708  radians, which is           90  degrees  
```  
  
##  <a name="atan"></a> atan  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao valor de entidade de segurança do arco tangente dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> atan(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao arco tangente dos elementos da valarray de entrada.  
  
### <a name="remarks"></a>Comentários  
 As unidades dos elementos retornados estão em radianos.  
  
 O valor de retorno é um objeto de valor entre + pi/2 e - pi/2 que é consistente com a tangente do valor de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_atan.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   va1 [ 0 ] = -100;  
   for ( i = 1 ; i < 8 ; i++ )  
      va1 [ i ] =  5 * ( 0.25 * i - 1 );  
   va1 [ 8 ] = 100;  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is: ";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va1 [ i ] << " ";  
   cout << "." << endl;  
  
   va2 = atan ( va1 );  
   cout << "The arcsine of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << setw(10) << va2 [ i ]  
           << "  radians, which is  "  
           << setw(11) << (180/pi) * va2 [ i ]  
           << "  degrees" << endl;  
   cout << endl;  
}  
```  
  
```Output  
The initial valarray is: -100 -3.75 -2.5 -1.25 0 1.25 2.5 3.75 100 .  
The arcsine of the initial valarray is:  
   -1.5608  radians, which is     -89.4271  degrees  
  -1.31019  radians, which is     -75.0686  degrees  
  -1.19029  radians, which is     -68.1986  degrees  
 -0.896055  radians, which is     -51.3402  degrees  
         0  radians, which is            0  degrees  
  0.896055  radians, which is      51.3402  degrees  
   1.19029  radians, which is      68.1986  degrees  
   1.31019  radians, which is      75.0686  degrees  
    1.5608  radians, which is      89.4271  degrees  
```  
  
##  <a name="atan2"></a> atan2  
 Retorna uma valarray cujos elementos são iguais ao arco tangente dos componentes cartesianos especificados por uma combinação de constantes e de elementos de valarrays.  
  
```  
template <class Type>  
valarray<Type> atan2(const valarray<Type>& left, const valarray<Type>& right);

template <class Type>  
valarray<Type> atan2(const valarray<Type> left, const Type& right);

template <class Type>  
valarray<Type> atan2(const Type& left, const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 O tipo de dados numéricos constantes ou a valarray de entrada cujos elementos fornecem os valores da coordenada Y do argumento do arco tangente.  
  
 `right`  
 O tipo de dados numéricos constantes ou a valarray de entrada cujos elementos fornecem os valores da coordenada X do argumento do arco tangente.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos `I` são iguais ao arco tangente de:  
  
- `left` [ *I* ] / *_Righ*t [ *I* ] da primeira função de modelo.  
  
- `left` [ *I* ] / `right` da segunda função de modelo.  
  
- `left` / `right` [ *I* ] da terceira função de modelo.  
  
### <a name="remarks"></a>Comentários  
 As unidades dos elementos retornados estão em radianos.  
  
 Essa função preserva informações sobre os sinais dos componentes no argumento perdido pela função tangente padrão, e esse conhecimento do quadrante permite que o valor de retorno a ser atribuído um ângulo exclusivo entre + pi e - pi.  
  
 Se `left` e `right` tiverem um número diferente de elementos, o resultado será indefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_atan2.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1y ( 1 , 4 ), va1x ( 1 , 4 );  
   va1x [ 1 ] = -1;  
   va1x [ 2 ] = -1;  
   va1y [ 2 ] = -1;  
   va1y [ 3 ] = -1;  
   valarray<double> va2 ( 4 );  
  
   cout << "The initial valarray for the x coordinate is: ( ";  
   for ( i = 0 ; i < 4 ; i++ )  
      cout << va1x [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial valarray for the y coordinate is: ( ";  
   for ( i = 0 ; i < 4 ; i++ )  
      cout << va1y [ i ] << " ";  
   cout << ")." << endl;  
  
   va2 = atan2 ( va1y , va1x );  
   cout << "The atan2 ( y / x ) of the initial valarrays is:\n";  
   for ( i = 0 ; i < 4 ; i++ )  
      cout << setw( 10 ) << va2 [ i ]  
           << "  radians, which is  "  
           << setw( 11 ) << ( 180/pi ) * va2 [ i ]  
           << "degrees" << endl;  
   cout << endl;  
}  
```  
  
```Output  
The initial valarray for the x coordinate is: ( 1 -1 -1 1 ).  
The initial valarray for the y coordinate is: ( 1 1 -1 -1 ).  
The atan2 ( y / x ) of the initial valarrays is:  
  0.785398  radians, which is           45degrees  
   2.35619  radians, which is          135degrees  
  -2.35619  radians, which is         -135degrees  
 -0.785398  radians, which is          -45degrees  
```  
  
##  <a name="cos"></a>  cos  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao cosseno dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> cos(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao valor absoluto dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_cos.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )  
      va1 [ i ] =  ( pi ) * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << setw( 10 ) << va1 [ i ]  
      << "  radians, which is  "  
      << setw( 5 ) << ( 180/pi ) * va1 [ i ]  
      << "  degrees" << endl;  
   cout << endl;  
  
   va2 = cos ( va1 );  
   cout << "The cosine of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray is:  
  -3.14159  radians, which is   -180  degrees  
  -2.35619  radians, which is   -135  degrees  
   -1.5708  radians, which is    -90  degrees  
 -0.785398  radians, which is    -45  degrees  
         0  radians, which is      0  degrees  
  0.785398  radians, which is     45  degrees  
    1.5708  radians, which is     90  degrees  
   2.35619  radians, which is    135  degrees  
   3.14159  radians, which is    180  degrees  
  
The cosine of the initial valarray is:  
-1  
-0.707107  
-1.03412e-013  
0.707107  
1  
0.707107  
-1.03412e-013  
-0.707107  
-1  
```  
  
##  <a name="cosh"></a>  cosh  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao cosseno hiperbólico dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> cosh(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao cosseno hiperbólico dos elementos da valarray de entrada.  
  
### <a name="remarks"></a>Comentários  
 Identidades que definem o cosseno hiperbólico em termos da função exponencial:  
  
 cosh ( *z* ) = ( exp ( *z* ) + exp ( – *z* ) ) / 2  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_cosh.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  pi * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:\n";  
   for (i = 0 ; i < 9 ; i++ )  
      cout << setw( 10 ) << va1 [ i ]  
      << "  radians, which is  "  
      << setw( 5 ) << ( 180/pi ) * va1 [ i ]  
      << "  degrees" << endl;  
   cout << endl;  
  
   va2 = cosh ( va1 );  
   cout << "The hyperbolic cosine of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray is:  
  -3.14159  radians, which is   -180  degrees  
  -2.35619  radians, which is   -135  degrees  
   -1.5708  radians, which is    -90  degrees  
 -0.785398  radians, which is    -45  degrees  
         0  radians, which is      0  degrees  
  0.785398  radians, which is     45  degrees  
    1.5708  radians, which is     90  degrees  
   2.35619  radians, which is    135  degrees  
   3.14159  radians, which is    180  degrees  
  
The hyperbolic cosine of the initial valarray is:  
11.592  
5.32275  
2.50918  
1.32461  
1  
1.32461  
2.50918  
5.32275  
11.592  
```  
  
##  <a name="exp"></a>  exp  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao exponencial natural dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> exp(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao exponencial natural dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_exp.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  10 * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "Initial valarray:";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << " " << va1 [ i ];  
   cout << endl;  
  
   va2 = exp ( va1 );  
   cout << "The natural exponential of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
Initial valarray: -10 -7.5 -5 -2.5 0 2.5 5 7.5 10  
The natural exponential of the initial valarray is:  
4.53999e-005  
0.000553084  
0.00673795  
0.082085  
1  
12.1825  
148.413  
1808.04  
22026.5  
```  
  
##  <a name="log"></a>  log  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao logaritmo natural dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> log(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao valor absoluto dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_log.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for (i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  10 * i;  
   valarray<double> va2 ( 9 );  
  
   cout << "Initial valarray:";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << " " << va1 [ i ];  
   cout << endl;  
  
   va2 = log ( va1 );  
   cout << "The natural logarithm of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
Initial valarray: 0 10 20 30 40 50 60 70 80  
The natural logarithm of the initial valarray is:  
-1.#INF  
2.30259  
2.99573  
3.4012  
3.68888  
3.91202  
4.09434  
4.2485  
4.38203  
```  
  
##  <a name="log10"></a>  log10  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao logaritmo de base 10 ou comum dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> log10(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao logaritmo comum dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_log10.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<double> va1 ( 11 );  
   for ( i = 0 ; i < 11 ; i++ )   
      va1 [ i ] =  10 * i;  
   valarray<double> va2 ( 9 );  
  
   cout << "Initial valarray:";  
   for (i = 0 ; i < 11 ; i++ )  
      cout << " " << va1 [ i ];  
   cout << endl;  
  
   va2 = log10 ( va1 );  
   cout << "The common logarithm of the initial valarray is:\n";  
   for (i = 0 ; i < 11 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
Initial valarray: 0 10 20 30 40 50 60 70 80 90 100  
The common logarithm of the initial valarray is:  
-1.#INF  
1  
1.30103  
1.47712  
1.60206  
1.69897  
1.77815  
1.8451  
1.90309  
1.95424  
2  
```  
  
##  <a name="pow"></a>  pow  
 Opera nos elementos de constantes e de valarrays de entrada retornando uma valarray cujos elementos são iguais a uma base especificada pelos elementos de uma valarray de entrada ou uma constante elevada a um expoente especificado pelos elementos de uma constante ou de uma valarray de entrada.  
  
```  
template <class Type>  
valarray<Type>  
pow(
    const valarray<Type>& left,  
    const valarray<Type>& right);

template <class Type>  
valarray<Type>  
pow(
    const valarray<Type>& left,   
    const Type& right);

template <class Type>  
valarray<Type>  
pow(
    const Type& left,   
    const valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos fornecem a base para cada elemento a ser submetido à exponenciação.  
  
 `right`  
 A valarray de entrada cujos elementos fornecem a potência para cada elemento a submetido à exponenciação.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos `I` são iguais a:  
  
- `left` [ *I* ] elevado à potência de `right` [ *I* ] da primeira função de modelo.  
  
- `left` [ *I* ] elevado à potência de `right` da segunda função de modelo.  
  
- `left` elevado à potência de `right` [ *I* ] da terceira função de modelo.  
  
### <a name="remarks"></a>Comentários  
 Se `left` e `right` tiverem um número diferente de elementos, o resultado será indefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> vabase ( 6 );  
   for ( i = 0 ; i < 6 ; i++ )  
      vabase [ i ] =  i/2;  
   valarray<double> vaexp ( 6 );  
   for ( i = 0 ; i < 6 ; i++ )  
      vaexp [ i ] =  2 * i;  
  
   valarray<double> va2 ( 6 );  
  
   cout << "The initial valarray for the base is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vabase [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial valarray for the exponent is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaexp[ i ] << " ";  
   cout << ")." << endl;  
  
   va2 = pow ( vabase , vaexp );  
   cout << "The power of (n/2) * exp (2n) for n = 0 to n = 5 is: \n";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout <<  "n = " << i << "\tgives " << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray for the base is: ( 0 0 1 1 2 2 ).  
The initial valarray for the exponent is: ( 0 2 4 6 8 10 ).  
The power of (n/2) * exp (2n) for n = 0 to n = 5 is:  
n = 0   gives 1  
n = 1   gives 0  
n = 2   gives 1  
n = 3   gives 1  
n = 4   gives 256  
n = 5   gives 1024  
```  
  
##  <a name="sin"></a>  sin  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao seno dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> sin(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao seno dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_sin.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  pi * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << setw(10) << va1 [ i ]  
      << "   radians, which is   "   
      << setw(5) << ( 180/pi ) * va1 [ i ]  
      << "   degrees" << endl;  
   cout << endl;  
  
   va2 = sin ( va1 );  
   cout << "The sine of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray is:  
  -3.14159   radians, which is    -180   degrees  
  -2.35619   radians, which is    -135   degrees  
   -1.5708   radians, which is     -90   degrees  
 -0.785398   radians, which is     -45   degrees  
         0   radians, which is       0   degrees  
  0.785398   radians, which is      45   degrees  
    1.5708   radians, which is      90   degrees  
   2.35619   radians, which is     135   degrees  
   3.14159   radians, which is     180   degrees  
  
The sine of the initial valarray is:  
2.06823e-013  
-0.707107  
-1  
-0.707107  
0  
0.707107  
1  
0.707107  
-2.06823e-013  
```  
  
##  <a name="sinh"></a>  sinh  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao seno hiperbólico dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> sinh(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao seno hiperbólico dos elementos da valarray de entrada.  
  
### <a name="remarks"></a>Comentários  
 Identidades que definem o seno hiperbólico em termos da função exponencial:  
  
 SINH ( *z* ) = (exp ( *z* )-exp (- *z* )) / 2  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_sinh.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for (i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  pi * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:\n";  
   for (i = 0 ; i < 9 ; i++ )  
      cout << setw( 10 ) << va1 [ i ]  
      << "   radians, which is   "  
      << setw( 5 ) << ( 180/pi ) * va1 [ i ]  
      << "  degrees" << endl;  
   cout << endl;  
  
   va2 = sinh ( va1 );  
   cout << "The hyperbolic sine of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray is:  
  -3.14159   radians, which is    -180  degrees  
  -2.35619   radians, which is    -135  degrees  
   -1.5708   radians, which is     -90  degrees  
 -0.785398   radians, which is     -45  degrees  
         0   radians, which is       0  degrees  
  0.785398   radians, which is      45  degrees  
    1.5708   radians, which is      90  degrees  
   2.35619   radians, which is     135  degrees  
   3.14159   radians, which is     180  degrees  
  
The hyperbolic sine of the initial valarray is:  
-11.5487  
-5.22797  
-2.3013  
-0.868671  
0  
0.868671  
2.3013  
5.22797  
11.5487  
```  
  
##  <a name="sqrt"></a>  sqrt  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais à raiz quadrada dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> sqrt(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais à raiz quadrada dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_sqrt.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <cmath>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<double> va1 ( 6 );  
   for ( i = 0 ; i < 5 ; i++ )  
      va1 [ i ] = i * i;  
  
   cout << "The initial valarray is: ( ";  
      for ( i = 0 ; i < 5 ; i++ )  
         cout << va1 [ i ] << " ";  
   cout << ")." << endl;  
  
   valarray<double> va2 = sqrt ( va1 );  
   cout << "The square root of the initial valarray is: ( ";  
      for ( i = 0 ; i < 5 ; i++ )  
         cout << va2 [ i ] << " ";  
   cout << ")." << endl;  
}  
```  
  
```Output  
The initial valarray is: ( 0 1 4 9 16 ).  
The square root of the initial valarray is: ( 0 1 2 3 4 ).  
```  
  
##  <a name="swap"></a>  swap  
 Troca os elementos de duas valarrays.  
  
```  
template <class Type>  
void swap(
    valarray<Type>& left,  
    valarray<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|Um objeto do tipo `valarray`.|  
|`right`|Um objeto do tipo `valarray`.|  
  
### <a name="remarks"></a>Comentários  
 A função de modelo executa ` left.swap( right)`.  
  
##  <a name="tan"></a> tan  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais à tangente dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> tan(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais à tangente dos elementos da valarray de entrada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_tan.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  ( pi/2 ) * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << setw( 10 ) << va1 [ i ]  
      << "     radians, which is   "  
      << setw( 5 ) << ( 180/pi ) * va1 [ i ]  
      << "   degrees" << endl;  
   cout << endl;  
  
   va2 = tan ( va1 );  
   cout << "The tangent of the initial valarray is:\n ";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray is:  
   -1.5708     radians, which is     -90   degrees  
   -1.1781     radians, which is   -67.5   degrees  
 -0.785398     radians, which is     -45   degrees  
 -0.392699     radians, which is   -22.5   degrees  
         0     radians, which is       0   degrees  
  0.392699     radians, which is    22.5   degrees  
  0.785398     radians, which is      45   degrees  
    1.1781     radians, which is    67.5   degrees  
    1.5708     radians, which is      90   degrees  
  
The tangent of the initial valarray is:  
 9.6701e+012  
-2.41421  
-1  
-0.414214  
0  
0.414214  
1  
2.41421  
-9.6701e+012  
```  
  
##  <a name="tanh"></a>  tanh  
 Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais à tangente hiperbólica dos elementos da valarray de entrada.  
  
```  
template <class Type>  
valarray<Type> tanh(const valarray<Type>& left);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 A valarray de entrada cujos elementos devem ser operados pela função membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma valarray cujos elementos são iguais ao cosseno hiperbólico dos elementos da valarray de entrada.  
  
### <a name="remarks"></a>Comentários  
 Identidades que definem a tangente hiperbólica em termos da função exponencial:  
  
 TANH ( *z* ) = sinh ( *z* ) / cosh ( *z* ) = (exp ( *z* )-exp (- *z* )) / (exp ( *z* ) + exp (- *z* ))  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// valarray_tanh.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
#include <iomanip>  
  
int main( )  
{  
   using namespace std;  
   double pi = 3.14159265359;  
   int i;  
  
   valarray<double> va1 ( 9 );  
   for ( i = 0 ; i < 9 ; i++ )   
      va1 [ i ] =  pi * ( 0.25 * i - 1 );  
   valarray<double> va2 ( 9 );  
  
   cout << "The initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
      cout << setw( 10 ) << va1 [ i ]  
      << "   radians, which is     "  
                    << setw( 5 ) << ( 180/pi ) * va1 [ i ]  
                    << "  degrees" << endl;  
   cout << endl;  
  
   va2 = tanh ( va1 );  
   cout << "The hyperbolic tangent of the initial valarray is:\n";  
   for ( i = 0 ; i < 9 ; i++ )  
     cout << va2 [ i ] << endl;  
}  
```  
  
```Output  
The initial valarray is:  
  -3.14159   radians, which is      -180  degrees  
  -2.35619   radians, which is      -135  degrees  
   -1.5708   radians, which is       -90  degrees  
 -0.785398   radians, which is       -45  degrees  
         0   radians, which is         0  degrees  
  0.785398   radians, which is        45  degrees  
    1.5708   radians, which is        90  degrees  
   2.35619   radians, which is       135  degrees  
   3.14159   radians, which is       180  degrees  
  
The hyperbolic tangent of the initial valarray is:  
-0.996272  
-0.982193  
-0.917152  
-0.655794  
0  
0.655794  
0.917152  
0.982193  
0.996272  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<valarray>](../standard-library/valarray.md)


