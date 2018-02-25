---
title: Classe numeric_limits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- limits/std::numeric_limits
- limits/std::numeric_limits::denorm_min
- limits/std::numeric_limits::digits
- limits/std::numeric_limits::digits10
- limits/std::numeric_limits::epsilon
- limits/std::numeric_limits::has_denorm
- limits/std::numeric_limits::has_denorm_loss
- limits/std::numeric_limits::has_infinity
- limits/std::numeric_limits::has_quiet_NaN
- limits/std::numeric_limits::has_signaling_NaN
- limits/std::numeric_limits::infinity
- limits/std::numeric_limits::is_bounded
- limits/std::numeric_limits::is_exact
- limits/std::numeric_limits::is_iec559
- limits/std::numeric_limits::is_integer
- limits/std::numeric_limits::is_modulo
- limits/std::numeric_limits::is_signed
- limits/std::numeric_limits::is_specialized
- limits/std::numeric_limits::lowest
- limits/std::numeric_limits::max
- limits/std::numeric_limits::max_digits10
- limits/std::numeric_limits::max_exponent
- limits/std::numeric_limits::max_exponent10
- limits/std::numeric_limits::min
- limits/std::numeric_limits::min_exponent
- limits/std::numeric_limits::min_exponent10
- limits/std::numeric_limits::quiet_NaN
- limits/std::numeric_limits::radix
- limits/std::numeric_limits::round_error
- limits/std::numeric_limits::round_style
- limits/std::numeric_limits::signaling_NaN
- limits/std::numeric_limits::tinyness_before
- limits/std::numeric_limits::traps
dev_langs:
- C++
helpviewer_keywords:
- std::numeric_limits [C++]
- std::numeric_limits [C++], denorm_min
- std::numeric_limits [C++], digits
- std::numeric_limits [C++], digits10
- std::numeric_limits [C++], epsilon
- std::numeric_limits [C++], has_denorm
- std::numeric_limits [C++], has_denorm_loss
- std::numeric_limits [C++], has_infinity
- std::numeric_limits [C++], has_quiet_NaN
- std::numeric_limits [C++], has_signaling_NaN
- std::numeric_limits [C++], infinity
- std::numeric_limits [C++], is_bounded
- std::numeric_limits [C++], is_exact
- std::numeric_limits [C++], is_iec559
- std::numeric_limits [C++], is_integer
- std::numeric_limits [C++], is_modulo
- std::numeric_limits [C++], is_signed
- std::numeric_limits [C++], is_specialized
- std::numeric_limits [C++], lowest
- std::numeric_limits [C++], max
- std::numeric_limits [C++], max_digits10
- std::numeric_limits [C++], max_exponent
- std::numeric_limits [C++], max_exponent10
- std::numeric_limits [C++], min
- std::numeric_limits [C++], min_exponent
- std::numeric_limits [C++], min_exponent10
- std::numeric_limits [C++], quiet_NaN
- std::numeric_limits [C++], radix
- std::numeric_limits [C++], round_error
- std::numeric_limits [C++], round_style
- std::numeric_limits [C++], signaling_NaN
- std::numeric_limits [C++], tinyness_before
- std::numeric_limits [C++], traps
ms.assetid: 9e817177-0e91-48e6-b680-0531c4b26625
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2aa716b9c052611aceb0c4677457fbce91bb743d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="numericlimits-class"></a>Classe numeric_limits
A classe de modelo descreve propriedades aritméticas de tipos numéricos internos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type>  
class numeric_limits  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Type`  
 O tipo de dados do elemento fundamental cujas propriedades estão sendo testadas ou consultadas ou definidas.  
  
## <a name="remarks"></a>Comentários  
 O cabeçalho define as especializações explícitas para os tipos `wchar_t`, `bool`, `char`, `signed char`, `unsigned char`, `short`, `unsigned short`, `int`, `unsigned int`, `long`, `unsigned long`, `float`, `double`, `long double`**,** `long long`, `unsigned long long`, `char16_t` e `char32_t`. Para essas especializações explícitas, o membro [numeric_limits::is_specialized](#is_specialized) é `true` e todos os membros relevantes têm valores significativos. O programa pode fornecer especializações explícitas adicionais. A maioria das funções membro da classe descreve ou testa possíveis implementações de `float`.  
  
 Para uma especialização arbitrária, nenhum membro tem valores significativos. Um objeto membro que não tem um valor significativo armazena zero (ou `false`) e retorna uma função membro que não retorna um valor significativo `Type(0)`.  
  
### <a name="static-functions-and-constants"></a>Constantes e funções estáticas  
  
|||  
|-|-|  
|[denorm_min](#denorm_min)|Retorna o menor valor desnormalizado diferente de zero.|  
|[digits](#digits)|Retorna o número de dígitos de base que o tipo pode representar sem perda de precisão.|  
|[digits10](#digits10)|Retorna o número de dígitos decimais que o tipo pode representar sem perda de precisão.|  
|[epsilon](#epsilon)|Retorna a diferença entre 1 e o menor valor maior que 1 que o tipo de dados pode representar.|  
|[has_denorm](#has_denorm)|Testa se um tipo permite valores desnormalizados.|  
|[has_denorm_loss](#has_denorm_loss)|Testa se a perda de precisão é detectada como uma perda de desnormalização em vez de um resultado inexato.|  
|[has_infinity](#has_infinity)|Testa se um tipo tem uma representação de infinito positivo.|  
|[has_quiet_NaN](#has_quiet_nan)|Testa se um tipo tem uma representação de um silencioso NAN (não é um número), que é sem sinal.|  
|[has_signaling_NaN](#has_signaling_nan)|Testa se um tipo tem uma representação para não sinalizar um número (NAN).|  
|[infinity](#infinity)|A representação de infinito positivo para um tipo, se disponível.|  
|[is_bounded](#is_bounded)|Testa se o conjunto de valores que um tipo pode representar é finito.|  
|[is_exact](#is_exact)|Testa se os cálculos feitos em um tipo estão livres de erros de arredondamento.|  
|[is_iec559](#is_iec559)|Testa se um tipo está em conformidade com os padrões IEC 559.|  
|[is_integer](#is_integer)|Testa se um tipo tem uma representação de inteiro.|  
|[is_modulo](#is_modulo)|Testa se um tipo tem uma representação de módulo.|  
|[is_signed](#is_signed)|Testa se um tipo tem uma representação com sinal.|  
|[is_specialized](#is_specialized)|Testa se um tipo tem uma especialização explícita definida na classe de modelo `numeric_limits`.|  
|[lowest](#lowest)|Retorna o valor finito mais negativo.|  
|[max](#max)|Retorna o valor máximo finito para um tipo.|  
|[max_digits10](#max_digits10)|Retorna o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.|  
|[max_exponent](#max_exponent)|Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.|  
|[max_exponent10](#max_exponent10)|Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.|  
|[min](#min)|Retorna o valor normalizado mínimo para um tipo.|  
|[min_exponent](#min_exponent)|Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.|  
|[min_exponent10](#min_exponent10)|Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.|  
|[quiet_NaN](#quiet_nan)|Retorna a representação de um NAN (não é um número) silencioso para o tipo.|  
|[radix](#radix)|Retorna a base integral, conhecida como base, usada para a representação de um tipo.|  
|[round_error](#round_error)|Retorna o erro de arredondamento máximo para o tipo.|  
|[round_style](#round_style)|Retorna um valor que descreve os vários métodos que uma implementação pode escolher para o arredondamento de um valor de ponto flutuante para um valor inteiro.|  
|[signaling_NaN](#signaling_nan)|Retorna a representação de um sinal NAN (não é um número) para o tipo.|  
|[tinyness_before](#tinyness_before)|Testa se um tipo pode determinar que um valor é muito pequeno para representar como um valor normalizado antes de arredondá-lo.|  
|[traps](#traps)|Testa se o trapping que relata exceções aritméticas é implementada para um tipo.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<limits>  
  
 **Namespace:** std  
  
##  <a name="denorm_min"></a>  numeric_limits::denorm_min  
 Retorna o menor valor desnormalizado diferente de zero.  
  
```  
static Type denorm_min() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O menor valor desnormalizado diferente de zero.  
  
### <a name="remarks"></a>Comentários  
 `long double` é o mesmo que **double** para o compilador C++.  
  
 A função retornará o valor mínimo para o tipo, que é o mesmo que [min](#min) se [has_denorm](#has_denorm) não for igual a **denorm_present**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_denorm_min.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The smallest nonzero denormalized value\n for float "  
        << "objects is: " << numeric_limits<float>::denorm_min( )   
        << endl;  
   cout << "The smallest nonzero denormalized value\n for double "  
        << "objects is: " << numeric_limits<double>::denorm_min( )   
        << endl;  
   cout << "The smallest nonzero denormalized value\n for long double "  
        << "objects is: " << numeric_limits<long double>::denorm_min( )   
        << endl;  
  
   // A smaller value will round to zero  
   cout << numeric_limits<float>::denorm_min( )/2 <<endl;  
   cout << numeric_limits<double>::denorm_min( )/2 <<endl;  
   cout << numeric_limits<long double>::denorm_min( )/2 <<endl;  
}  
```  
  
```Output  
The smallest nonzero denormalized value  
 for float objects is: 1.4013e-045  
The smallest nonzero denormalized value  
 for double objects is: 4.94066e-324  
The smallest nonzero denormalized value  
 for long double objects is: 4.94066e-324  
0  
0  
0  
```  
  
##  <a name="digits"></a>  numeric_limits::digits  
 Retorna o número de dígitos de base que o tipo pode representar sem perda de precisão.  
  
```  
static const int digits = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de dígitos de base que o tipo pode representar sem perda de precisão.  
  
### <a name="remarks"></a>Comentários  
 O membro armazena o número de dígitos de base que o tipo pode representar sem alteração, que é o número de bits diferente de qualquer bit de sinal para um tipo inteiro predefinido ou o número de dígitos de mantissa para um tipo de ponto flutuante predefinido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_digits_min.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << numeric_limits<float>::digits <<endl;  
   cout << numeric_limits<double>::digits <<endl;  
   cout << numeric_limits<long double>::digits <<endl;  
   cout << numeric_limits<int>::digits <<endl;  
   cout << numeric_limits<__int64>::digits <<endl;  
}  
```  
  
```Output  
24  
53  
53  
31  
63  
```  
  
##  <a name="digits10"></a>  numeric_limits::digits10  
 Retorna o número de dígitos decimais que o tipo pode representar sem perda de precisão.  
  
```  
static const int digits10 = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de dígitos decimais que o tipo pode representar sem perda de precisão.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_digits10.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << numeric_limits<float>::digits10 <<endl;  
   cout << numeric_limits<double>::digits10 <<endl;  
   cout << numeric_limits<long double>::digits10 <<endl;  
   cout << numeric_limits<int>::digits10 <<endl;  
   cout << numeric_limits<__int64>::digits10 <<endl;  
   float f = (float)99999999;  
   cout.precision ( 10 );  
   cout << "The float is; " << f << endl;  
}  
```  
  
```Output  
6  
15  
15  
9  
18  
The float is; 100000000  
```  
  
##  <a name="epsilon"></a>  numeric_limits::epsilon  
 A função retorna a diferença entre 1 e o menor valor maior que 1 que é representável para o tipo de dados.  
  
```  
static Type epsilon() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A diferença entre 1 e o menor valor maior que 1 que é representável para o tipo de dados.  
  
### <a name="remarks"></a>Comentários  
 O valor é FLT_EPSILON para o tipo **float**. `epsilon` para um tipo é o menor número de ponto flutuante positivo *N* que *N* + `epsilon` + *N* é representável.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_epsilon.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The difference between 1 and the smallest "  
        << "value greater than 1\n for float objects is: "   
        << numeric_limits<float>::epsilon( )   
        << endl;  
   cout << "The difference between 1 and the smallest "  
        << "value greater than 1\n for double objects is: "   
        << numeric_limits<double>::epsilon( )   
        << endl;  
   cout << "The difference between 1 and the smallest "  
        << "value greater than 1\n for long double objects is: "   
        << numeric_limits<long double>::epsilon( )   
        << endl;  
}  
```  
  
```Output  
The difference between 1 and the smallest value greater than 1  
 for float objects is: 1.19209e-007  
The difference between 1 and the smallest value greater than 1  
 for double objects is: 2.22045e-016  
The difference between 1 and the smallest value greater than 1  
 for long double objects is: 2.22045e-016  
```  
  
##  <a name="has_denorm"></a>  numeric_limits::has_denorm  
 Testa se um tipo permite valores desnormalizados.  
  
```  
static const float_denorm_style has_denorm = denorm_absent;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de enumeração do tipo **const**`float_denorm_style`, indicando se o tipo permite valores desnormalizados.  
  
### <a name="remarks"></a>Comentários  
 Os repositórios do membro **denorm_present** para um tipo de ponto flutuante com valores desnormalizados, efetivamente um número variável de bits exponenciais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_has_denorm.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects allow denormalized values: "  
        << numeric_limits<float>::has_denorm   
        << endl;  
   cout << "Whether double objects allow denormalized values: "  
        << numeric_limits<double>::has_denorm   
        << endl;  
   cout << "Whether long int objects allow denormalized values: "   
        << numeric_limits<long int>::has_denorm   
        << endl;  
}  
```  
  
```Output  
Whether float objects allow denormalized values: 1  
Whether double objects allow denormalized values: 1  
Whether long int objects allow denormalized values: 0  
```  
  
##  <a name="has_denorm_loss"></a>  numeric_limits::has_denorm_loss  
 Testa se a perda de precisão é detectada como uma perda de desnormalização em vez de um resultado inexato.  
  
```  
static const bool has_denorm_loss = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se a perda de precisão for detectada como uma perda de desnormalização; **false** se não for.  
  
### <a name="remarks"></a>Comentários  
 O membro armazena true para um tipo que determina se um valor perdeu a precisão porque foi entregue como um resultado desnormalizado (muito pequeno para ser representado como um valor normalizado) ou porque está inexato (não o mesmo por não estar sujeito a limitações de intervalo exponencial e precisão), uma opção com representações de ponto flutuantes IEC 559 que pode afetar alguns resultados.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_has_denorm_loss.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects can detect denormalized loss: "  
        << numeric_limits<float>::has_denorm_loss  
        << endl;  
   cout << "Whether double objects can detect denormalized loss: "  
        << numeric_limits<double>::has_denorm_loss  
        << endl;  
   cout << "Whether long int objects can detect denormalized loss: "   
        << numeric_limits<long int>::has_denorm_loss  
        << endl;  
}  
```  
  
```Output  
Whether float objects can detect denormalized loss: 1  
Whether double objects can detect denormalized loss: 1  
Whether long int objects can detect denormalized loss: 0  
```  
  
##  <a name="has_infinity"></a>  numeric_limits::has_infinity  
 Testa se um tipo tem uma representação de infinito positivo.  
  
```  
static const bool has_infinity = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo tiver uma representação de infinito positivo; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 O membro retornará **true** se [is_iec559](#is_iec559) for **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_has_infinity.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have infinity: "  
        << numeric_limits<float>::has_infinity  
        << endl;  
   cout << "Whether double objects have infinity: "  
        << numeric_limits<double>::has_infinity  
        << endl;  
   cout << "Whether long int objects have infinity: "   
        << numeric_limits<long int>::has_infinity  
        << endl;  
}  
```  
  
```Output  
Whether float objects have infinity: 1  
Whether double objects have infinity: 1  
Whether long int objects have infinity: 0  
```  
  
##  <a name="has_quiet_nan"></a>  numeric_limits::has_quiet_NaN  
 Testa se um tipo tem uma representação de um silencioso NAN (não é um número), que é sem sinal.  
  
```  
static const bool has_quiet_NaN = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o **tipo** tiver uma representação de NAN silencioso; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 Um NAN silencioso é uma codificação para um não número, o que não indica sua presença em uma expressão. O valor retornado será **true** se [is_iec559](#is_iec559) for true.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_has_quiet_nan.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have quiet_NaN: "  
        << numeric_limits<float>::has_quiet_NaN   
        << endl;  
   cout << "Whether double objects have quiet_NaN: "  
        << numeric_limits<double>::has_quiet_NaN   
        << endl;  
   cout << "Whether long int objects have quiet_NaN: "   
        << numeric_limits<long int>::has_quiet_NaN   
        << endl;  
}  
```  
  
```Output  
Whether float objects have quiet_NaN: 1  
Whether double objects have quiet_NaN: 1  
Whether long int objects have quiet_NaN: 0  
```  
  
##  <a name="has_signaling_nan"></a>  numeric_limits::has_signaling_NaN  
 Testa se um tipo tem uma representação para não sinalizar um número (NAN).  
  
```  
static const bool has_signaling_NaN = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo tiver uma representação de um NAN com sinal; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 Um NAN com sinal é uma codificação para um não número, o que indica sua presença em uma expressão. O valor retornado é **true**[is_iec559](#is_iec559) se for true.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_has_signaling_nan.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have a signaling_NaN: "  
        << numeric_limits<float>::has_signaling_NaN   
        << endl;  
   cout << "Whether double objects have a signaling_NaN: "  
        << numeric_limits<double>::has_signaling_NaN   
        << endl;  
   cout << "Whether long int objects have a signaling_NaN: "   
        << numeric_limits<long int>::has_signaling_NaN   
        << endl;  
}  
```  
  
```Output  
Whether float objects have a signaling_NaN: 1  
Whether double objects have a signaling_NaN: 1  
Whether long int objects have a signaling_NaN: 0  
```  
  
##  <a name="infinity"></a>  numeric_limits::infinity  
 A representação de infinito positivo para um tipo, se disponível.  
  
```  
static Type infinity() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A representação de infinito positivo para um tipo, se disponível.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado será significativo somente se [has_infinity](#has_infinity) for **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_infinity.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << numeric_limits<float>::has_infinity <<endl;  
   cout << numeric_limits<double>::has_infinity<<endl;  
   cout << numeric_limits<long double>::has_infinity <<endl;  
   cout << numeric_limits<int>::has_infinity <<endl;  
   cout << numeric_limits<__int64>::has_infinity <<endl;  
  
   cout << "The representation of infinity for type float is: "  
        << numeric_limits<float>::infinity( ) <<endl;  
   cout << "The representation of infinity for type double is: "  
        << numeric_limits<double>::infinity( ) <<endl;  
   cout << "The representation of infinity for type long double is: "  
        << numeric_limits<long double>::infinity( ) <<endl;  
}  
```  
  
```Output  
1  
1  
1  
0  
0  
The representation of infinity for type float is: 1.#INF  
The representation of infinity for type double is: 1.#INF  
The representation of infinity for type long double is: 1.#INF  
```  
  
##  <a name="is_bounded"></a>  numeric_limits::is_bounded  
 Testa se o conjunto de valores que um tipo pode representar é finito.  
  
```  
static const bool is_bounded = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se o tipo tiver um conjunto limitado de valores representáveis; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 Todos os tipos predefinidos têm um conjunto limitado de valores representáveis e retornam **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_bounded.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have bounded set "  
        << "of representable values: "  
        << numeric_limits<float>::is_bounded  
        << endl;  
   cout << "Whether double objects have bounded set "  
        << "of representable values: "  
        << numeric_limits<double>::is_bounded  
        << endl;  
   cout << "Whether long int objects have bounded set "  
        << "of representable values: "  
        << numeric_limits<long int>::is_bounded  
        << endl;  
   cout << "Whether unsigned char objects have bounded set "  
        << "of representable values: "  
        << numeric_limits<unsigned char>::is_bounded  
        << endl;  
}  
```  
  
```Output  
Whether float objects have bounded set of representable values: 1  
Whether double objects have bounded set of representable values: 1  
Whether long int objects have bounded set of representable values: 1  
Whether unsigned char objects have bounded set of representable values: 1  
```  
  
##  <a name="is_exact"></a>  numeric_limits::is_exact  
 Testa se os cálculos feitos em um tipo estão livres de erros de arredondamento.  
  
```  
static const bool is_exact = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os cálculos estiverem livres de erros de arredondamento; **false** se não estiverem.  
  
### <a name="remarks"></a>Comentários  
 Todos os tipos de inteiro predefinidos têm representações exatas para seus valores e retornam **false**. Uma representação de ponto fixo ou racional também é considerada exata, mas uma representação de ponto flutuante não é.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_exact.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have calculations "  
        << "free of rounding errors: "  
        << numeric_limits<float>::is_exact  
        << endl;  
   cout << "Whether double objects have calculations "  
        << "free of rounding errors: "  
        << numeric_limits<double>::is_exact  
        << endl;  
   cout << "Whether long int objects have calculations "  
        << "free of rounding errors: "  
        << numeric_limits<long int>::is_exact  
        << endl;  
   cout << "Whether unsigned char objects have calculations "  
        << "free of rounding errors: "  
        << numeric_limits<unsigned char>::is_exact  
        << endl;  
}  
```  
  
```Output  
Whether float objects have calculations free of rounding errors: 0  
Whether double objects have calculations free of rounding errors: 0  
Whether long int objects have calculations free of rounding errors: 1  
Whether unsigned char objects have calculations free of rounding errors: 1  
```  
  
##  <a name="is_iec559"></a>  numeric_limits::is_iec559  
 Testa se um tipo está em conformidade com os padrões IEC 559.  
  
```  
static const bool is_iec559 = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo estiver em conformidade com os padrões IEC 559; **false** se não estiver.  
  
### <a name="remarks"></a>Comentários  
 O IEC 559 é um padrão internacional que representa valores de ponto flutuante e também é conhecido como IEEE 754 nos EUA.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_iec559.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects conform to iec559 standards: "  
        << numeric_limits<float>::is_iec559  
        << endl;  
   cout << "Whether double objects conform to iec559 standards: "  
        << numeric_limits<double>::is_iec559  
        << endl;  
   cout << "Whether int objects conform to iec559 standards: "  
        << numeric_limits<int>::is_iec559  
        << endl;  
   cout << "Whether unsigned char objects conform to iec559 standards: "  
        << numeric_limits<unsigned char>::is_iec559  
        << endl;  
}  
```  
  
```Output  
Whether float objects conform to iec559 standards: 1  
Whether double objects conform to iec559 standards: 1  
Whether int objects conform to iec559 standards: 0  
Whether unsigned char objects conform to iec559 standards: 0  
```  
  
##  <a name="is_integer"></a>  numeric_limits::is_integer  
 Testa se um tipo tem uma representação de inteiro.  
  
```  
static const bool is_integer = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo tiver uma representação de inteiro; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 Todos os tipos de inteiro predefinidos têm uma representação de inteiro.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_integer.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have an integral representation: "  
        << numeric_limits<float>::is_integer  
        << endl;  
   cout << "Whether double objects have an integral representation: "  
        << numeric_limits<double>::is_integer  
        << endl;  
   cout << "Whether int objects have an integral representation: "  
        << numeric_limits<int>::is_integer  
        << endl;  
   cout << "Whether unsigned char objects have an integral representation: "  
        << numeric_limits<unsigned char>::is_integer  
        << endl;  
}  
```  
  
```Output  
Whether float objects have an integral representation: 0  
Whether double objects have an integral representation: 0  
Whether int objects have an integral representation: 1  
Whether unsigned char objects have an integral representation: 1  
```  
  
##  <a name="is_modulo"></a>  numeric_limits::is_modulo  
 Testa se um **tipo** tem uma representação de módulo.  
  
```  
static const bool is_modulo = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo tiver uma representação de módulo; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 Uma representação de módulo é uma representação na qual todos os resultados são reduzidos a um módulo de algum valor. Todos os tipos de inteiro sem sinal predefinidos têm uma representação de módulo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_modulo.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have a modulo representation: "  
        << numeric_limits<float>::is_modulo  
        << endl;  
   cout << "Whether double objects have a modulo representation: "  
        << numeric_limits<double>::is_modulo  
        << endl;  
   cout << "Whether signed char objects have a modulo representation: "  
        << numeric_limits<signed char>::is_modulo  
        << endl;  
   cout << "Whether unsigned char objects have a modulo representation: "  
        << numeric_limits<unsigned char>::is_modulo  
        << endl;  
}  
```  
  
```Output  
Whether float objects have a modulo representation: 0  
Whether double objects have a modulo representation: 0  
Whether signed char objects have a modulo representation: 1  
Whether unsigned char objects have a modulo representation: 1  
```  
  
##  <a name="is_signed"></a>  numeric_limits::is_signed  
 Testa se um tipo tem uma representação com sinal.  
  
```  
static const bool is_signed = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo tiver uma representação com sinal; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 O membro armazena true para um tipo que tem uma representação com sinal, que é o caso para todos os tipos de inteiros com sinal e de ponto flutuante predefinidos.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_signaled.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have a signed representation: "  
        << numeric_limits<float>::is_signed  
        << endl;  
   cout << "Whether double objects have a signed representation: "  
        << numeric_limits<double>::is_signed  
        << endl;  
   cout << "Whether signed char objects have a signed representation: "  
        << numeric_limits<signed char>::is_signed  
        << endl;  
   cout << "Whether unsigned char objects have a signed representation: "  
        << numeric_limits<unsigned char>::is_signed  
        << endl;  
}  
```  
  
```Output  
Whether float objects have a signed representation: 1  
Whether double objects have a signed representation: 1  
Whether signed char objects have a signed representation: 1  
Whether unsigned char objects have a signed representation: 0  
```  
  
##  <a name="is_specialized"></a>  numeric_limits::is_specialized  
 Testa se um tipo tem uma especialização explícita definida na classe de modelo `numeric_limits`.  
  
```  
static const bool is_specialized = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o tipo tiver uma especialização explícita definida na classe de modelo; **false** se não tiver.  
  
### <a name="remarks"></a>Comentários  
 Todos os tipos escalares, exceto ponteiros, têm uma especialização explícita definida para a classe de modelo `numeric_limits`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_is_specialized.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float objects have an explicit "  
        << "specialization in the class: "  
        << numeric_limits<float>::is_specialized  
        << endl;  
   cout << "Whether float* objects have an explicit "  
        << "specialization in the class: "  
        << numeric_limits<float*>::is_specialized  
        << endl;  
   cout << "Whether int objects have an explicit "  
        << "specialization in the class: "  
        << numeric_limits<int>::is_specialized  
        << endl;  
   cout << "Whether int* objects have an explicit "  
        << "specialization in the class: "  
        << numeric_limits<int*>::is_specialized  
        << endl;  
}  
```  
  
```Output  
Whether float objects have an explicit specialization in the class: 1  
Whether float* objects have an explicit specialization in the class: 0  
Whether int objects have an explicit specialization in the class: 1  
Whether int* objects have an explicit specialization in the class: 0  
```  
  
##  <a name="lowest"></a>  numeric_limits::lowest  
 Retorna o valor finito mais negativo.  
  
```  
static Type lowest() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor finito mais negativo.  
  
### <a name="remarks"></a>Comentários  
 Retorna o valor mais negativo finito para o tipo (que normalmente é `min()` para tipos de inteiro e `-max()` para tipos de ponto flutuante). O valor de retorno será significativo se `is_bounded` for `true`.  
  
##  <a name="max"></a>  numeric_limits::max  
 Retorna o valor máximo finito para um tipo.  
  
```  
static Type max() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor máximo finito para um tipo.  
  
### <a name="remarks"></a>Comentários  
 O valor máximo finito é INT_MAX para o tipo `int` e FLT_MAX para o tipo **float**. O valor retornado será significativo se [is_bounded](#is_bounded) for **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_max.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main() {  
   cout << "The maximum value for type float is:  "  
        << numeric_limits<float>::max( )  
        << endl;  
   cout << "The maximum value for type double is:  "  
        << numeric_limits<double>::max( )  
        << endl;  
   cout << "The maximum value for type int is:  "  
        << numeric_limits<int>::max( )  
        << endl;  
   cout << "The maximum value for type short int is:  "  
        << numeric_limits<short int>::max( )  
        << endl;  
}  
```  
  
##  <a name="max_digits10"></a>  numeric_limits::max_digits10  
 Retorna o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.  
  
```  
static int max_digits10 = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.  
  
### <a name="remarks"></a>Comentários  
 O membro armazena o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.  
  
##  <a name="max_exponent"></a>  numeric_limits::max_exponent  
 Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.  
  
```  
static const int max_exponent = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O expoente com base integral máximo representável pelo tipo.  
  
### <a name="remarks"></a>Comentários  
 O retorno da função membro é significativo apenas para os tipos de ponto flutuante. O `max_exponent` é o valor FLT_MAX_EXP para o tipo **float**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_max_exponent.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The maximum radix-based exponent for type float is:  "  
        << numeric_limits<float>::max_exponent  
        << endl;  
   cout << "The maximum radix-based exponent for type double is:  "  
        << numeric_limits<double>::max_exponent  
        << endl;  
   cout << "The maximum radix-based exponent for type long double is:  "  
        << numeric_limits<long double>::max_exponent  
        << endl;  
}  
```  
  
```Output  
The maximum radix-based exponent for type float is:  128  
The maximum radix-based exponent for type double is:  1024  
The maximum radix-based exponent for type long double is:  1024  
```  
  
##  <a name="max_exponent10"></a>  numeric_limits::max_exponent10  
 Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.  
  
```  
static const int max_exponent10 = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O expoente de base 10 integral máxima representável pelo tipo.  
  
### <a name="remarks"></a>Comentários  
 O retorno da função membro é significativo apenas para os tipos de ponto flutuante. O `max_exponent` é o valor FLT_MAX_10 para o tipo **float**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_max_exponent10.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The maximum base 10 exponent for type float is:  "  
           << numeric_limits<float>::max_exponent10  
           << endl;  
   cout << "The maximum base 10 exponent for type double is:  "  
           << numeric_limits<double>::max_exponent10  
           << endl;  
   cout << "The maximum base 10 exponent for type long double is:  "  
           << numeric_limits<long double>::max_exponent10  
           << endl;  
}  
```  
  
```Output  
The maximum base 10 exponent for type float is:  38  
The maximum base 10 exponent for type double is:  308  
The maximum base 10 exponent for type long double is:  308  
```  
  
##  <a name="min"></a>  numeric_limits::min  
 Retorna o valor normalizado mínimo para um tipo.  
  
```  
static Type min() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor normalizado mínimo para o tipo.  
  
### <a name="remarks"></a>Comentários  
 O valor normalizado mínimo é INT_MIN para o tipo `int` e FLT_MIN para o tipo `float`. O valor retornado será significativo se [is_bounded](#is_bounded) for `true` ou se [is_signed](#is_signed) for `false`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_min.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The minimum value for type float is:  "  
        << numeric_limits<float>::min( )  
        << endl;  
   cout << "The minimum value for type double is:  "  
        << numeric_limits<double>::min( )  
        << endl;  
   cout << "The minimum value for type int is:  "  
        << numeric_limits<int>::min( )  
        << endl;  
   cout << "The minimum value for type short int is:  "  
        << numeric_limits<short int>::min( )  
        << endl;  
}  
```  
  
```Output  
The minimum value for type float is:  1.17549e-038  
The minimum value for type double is:  2.22507e-308  
The minimum value for type int is:  -2147483648  
The minimum value for type short int is:  -32768  
```  
  
##  <a name="min_exponent"></a>  numeric_limits::min_exponent  
 Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.  
  
```  
static const int min_exponent = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O expoente com base integral mínima representável pelo tipo.  
  
### <a name="remarks"></a>Comentários  
 A função membro é significativa apenas para os tipos de ponto flutuante. O `min_exponent` é o valor FLT_MIN_EXP para o tipo **float**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_min_exponent.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The minimum radix-based exponent for type float is:  "  
        << numeric_limits<float>::min_exponent  
        << endl;  
   cout << "The minimum radix-based exponent for type double is:  "  
        << numeric_limits<double>::min_exponent  
        << endl;  
   cout << "The minimum radix-based exponent for type long double is:  "  
         << numeric_limits<long double>::min_exponent  
        << endl;  
}  
```  
  
```Output  
The minimum radix-based exponent for type float is:  -125  
The minimum radix-based exponent for type double is:  -1021  
The minimum radix-based exponent for type long double is:  -1021  
```  
  
##  <a name="min_exponent10"></a>  numeric_limits::min_exponent10  
 Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.  
  
```  
static const int min_exponent10 = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O expoente de base 10 integral mínimo representável pelo tipo.  
  
### <a name="remarks"></a>Comentários  
 A função membro é significativa apenas para os tipos de ponto flutuante. O `min_exponent10` é o valor FLT_MIN_10_EXP para o tipo **float**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_min_exponent10.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The minimum base 10 exponent for type float is:  "  
        << numeric_limits<float>::min_exponent10  
        << endl;  
   cout << "The minimum base 10 exponent for type double is:  "  
        << numeric_limits<double>::min_exponent10  
        << endl;  
   cout << "The minimum base 10 exponent for type long double is:  "  
        << numeric_limits<long double>::min_exponent10  
        << endl;  
}  
```  
  
```Output  
The minimum base 10 exponent for type float is:  -37  
The minimum base 10 exponent for type double is:  -307  
The minimum base 10 exponent for type long double is:  -307  
```  
  
##  <a name="quiet_nan"></a>  numeric_limits::quiet_NaN  
 Retorna a representação de um NAN (não é um número) silencioso para o tipo.  
  
```  
static Type quiet_NaN() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A representação de um NAN silencioso para o tipo.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado será significativo somente se [has_quiet_NaN](#has_quiet_nan) for **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_quiet_nan.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The quiet NaN for type float is:  "  
        << numeric_limits<float>::quiet_NaN( )  
        << endl;  
   cout << "The quiet NaN for type int is:  "  
        << numeric_limits<int>::quiet_NaN( )  
        << endl;  
   cout << "The quiet NaN for type long double is:  "  
        << numeric_limits<long double>::quiet_NaN( )  
        << endl;  
}  
```  
  
```Output  
The quiet NaN for type float is:  1.#QNAN  
The quiet NaN for type int is:  0  
The quiet NaN for type long double is:  1.#QNAN  
```  
  
##  <a name="radix"></a>  numeric_limits::radix  
 Retorna a base integral, conhecida como base, usada para a representação de um tipo.  
  
```  
static const int radix = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A base integral para a representação do tipo.  
  
### <a name="remarks"></a>Comentários  
 A base é 2 para os tipos de inteiro predefinidos e para a base para a qual o expoente é elevado ou FLT_RADIX, para os tipos de pontos flutuantes predefinidos.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_radix.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The base for type float is:  "  
        << numeric_limits<float>::radix  
        << endl;  
   cout << "The base for type int is:  "  
        << numeric_limits<int>::radix  
        << endl;  
   cout << "The base for type long double is:  "  
        << numeric_limits<long double>::radix  
        << endl;  
}  
```  
  
```Output  
The base for type float is:  2  
The base for type int is:  2  
The base for type long double is:  2  
```  
  
##  <a name="round_error"></a>  numeric_limits::round_error  
 Retorna o erro de arredondamento máximo para o tipo.  
  
```  
static Type round_error() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O erro de arredondamento máximo para o tipo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_round_error.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The maximum rounding error for type float is:  "  
        << numeric_limits<float>::round_error( )  
        << endl;  
   cout << "The maximum rounding error for type int is:  "  
        << numeric_limits<int>::round_error( )  
        << endl;  
   cout << "The maximum rounding error for type long double is:  "  
        << numeric_limits<long double>::round_error( )  
        << endl;  
}  
```  
  
```Output  
The maximum rounding error for type float is:  0.5  
The maximum rounding error for type int is:  0  
The maximum rounding error for type long double is:  0.5  
```  
  
##  <a name="round_style"></a>  numeric_limits::round_style  
 Retorna um valor que descreve os vários métodos que uma implementação pode escolher para o arredondamento de um valor de ponto flutuante para um valor inteiro.  
  
```  
static const float_round_style round_style = round_toward_zero;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor da enumeração `float_round_style` que descreve o estilo de arredondamento.  
  
### <a name="remarks"></a>Comentários  
 O membro armazena um valor que descreve os vários métodos que uma implementação pode escolher para o arredondamento de um valor de ponto flutuante para um valor inteiro.  
  
 O estilo de arredondamento fixo é nessa implementação. Mesmo que se o programa for iniciado com um modo de arredondamento diferente, esse valor não será alterado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_round_style.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <float.h>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The rounding style for a double type is: "   
        << numeric_limits<double>::round_style << endl;  
   _controlfp_s(NULL,_RC_DOWN,_MCW_RC );  
   cout << "The rounding style for a double type is now: "   
        << numeric_limits<double>::round_style << endl;  
   cout << "The rounding style for an int type is: "   
        << numeric_limits<int>::round_style << endl;  
}  
```  
  
```Output  
The rounding style for a double type is: 1  
The rounding style for a double type is now: 1  
The rounding style for an int type is: 0  
```  
  
##  <a name="signaling_nan"></a>  numeric_limits::signaling_NaN  
 Retorna a representação de um sinal NAN (não é um número) para o tipo.  
  
```  
static Type signaling_NaN() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A representação de um NAN com sinal para o tipo.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado será significativo somente se [has_signaling_NaN](#has_signaling_nan) for **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_signaling_nan.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "The signaling NaN for type float is:  "  
        << numeric_limits<float>::signaling_NaN( )  
        << endl;  
   cout << "The signaling NaN for type int is:  "  
        << numeric_limits<int>::signaling_NaN( )  
        << endl;  
   cout << "The signaling NaN for type long double is:  "  
        << numeric_limits<long double>::signaling_NaN( )  
        << endl;  
}  
```  
  
##  <a name="tinyness_before"></a>  numeric_limits::tinyness_before  
 Testa se um tipo pode determinar que um valor é muito pequeno para representar como um valor normalizado antes de arredondá-lo.  
  
```  
static const bool tinyness_before = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o tipo puder detectar valores pequenos antes do arredondamento; `false` se não puder.  
  
### <a name="remarks"></a>Comentários  
 Tipos que podem detectar pequenez foram incluídos como uma opção com representações de pontos flutuantes IEC 559 e sua implementação pode afetar alguns resultados.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_tinyness_before.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float types can detect tinyness before rounding: "  
        << numeric_limits<float>::tinyness_before  
        << endl;  
   cout << "Whether double types can detect tinyness before rounding: "  
        << numeric_limits<double>::tinyness_before  
        << endl;  
   cout << "Whether long int types can detect tinyness before rounding: "  
        << numeric_limits<long int>::tinyness_before  
        << endl;  
   cout << "Whether unsigned char types can detect tinyness before rounding: "  
        << numeric_limits<unsigned char>::tinyness_before  
        << endl;  
}  
```  
  
```Output  
Whether float types can detect tinyness before rounding: 1  
Whether double types can detect tinyness before rounding: 1  
Whether long int types can detect tinyness before rounding: 0  
Whether unsigned char types can detect tinyness before rounding: 0  
```  
  
##  <a name="traps"></a>  numeric_limits::traps  
 Testa se o trapping que relata exceções aritméticas é implementada para um tipo.  
  
```  
static const bool traps = false;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o trapping for implementada para o tipo; **false** se não for.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_limits_traps.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <limits>  
  
using namespace std;  
  
int main( )  
{  
   cout << "Whether float types have implemented trapping: "  
        << numeric_limits<float>::traps  
        << endl;  
   cout << "Whether double types have implemented trapping: "  
        << numeric_limits<double>::traps  
        << endl;  
   cout << "Whether long int types have implemented trapping: "  
        << numeric_limits<long int>::traps  
        << endl;  
   cout << "Whether unsigned char types have implemented trapping: "  
        << numeric_limits<unsigned char>::traps  
        << endl;  
}  
```  
  
```Output  
Whether float types have implemented trapping: 1  
Whether double types have implemented trapping: 1  
Whether long int types have implemented trapping: 0  
Whether unsigned char types have implemented trapping: 0  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

