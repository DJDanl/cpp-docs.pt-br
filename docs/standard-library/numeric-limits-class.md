---
title: Classe numeric_limits
ms.date: 11/04/2016
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
ms.openlocfilehash: f0b33404f16df59e2cb73023f3539e87080734a1
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520597"
---
# <a name="numeric_limits-class"></a>Classe numeric_limits

O modelo de classe descreve as propriedades aritméticas de tipos numéricos internos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
    class numeric_limits
```

### <a name="parameters"></a>Parâmetros

*Escreva*\
O tipo de dados do elemento fundamental cujas propriedades estão sendo testadas ou consultadas ou definidas. O *tipo* também pode ser declarado **`const`** , **`volatile`** ou **`const volatile`** .

## <a name="remarks"></a>Comentários

O cabeçalho define especializações explícitas para os tipos,,,,,,, **`wchar_t`** **`bool`** ,,,, **`char`** ,, **`signed char`** **`unsigned char`** **`short`** **`unsigned short`** **`int`** **`unsigned int`** **`long`** **`unsigned long`** **`float`** **`double`** **`long double`** , **`long long`** , **`unsigned long long`** , **`char16_t`** e **`char32_t`** . Para essas especializações explícitas, o membro [numeric_limits:: is_specialized](#is_specialized) é **`true`** , e todos os membros relevantes têm valores significativos. O programa pode fornecer especializações explícitas adicionais. A maioria das funções de membro da classe descreve ou testa possíveis implementações do **`float`** .

Para uma especialização arbitrária, nenhum membro tem valores significativos. Um objeto de membro que não tem um valor significativo armazena zero (ou **`false`** ) e uma função de membro que não retorna um valor significativo retorna `Type(0)` .

## <a name="static-functions-and-constants"></a>Constantes e funções estáticas

|||
|-|-|
|[denorm_min](#denorm_min)|Retorna o menor valor desnormalizado diferente de zero.|
|[dígitos](#digits)|Retorna o número de dígitos de base que o tipo pode representar sem perda de precisão.|
|[digits10](#digits10)|Retorna o número de dígitos decimais que o tipo pode representar sem perda de precisão.|
|[epsilo](#epsilon)|Retorna a diferença entre 1 e o menor valor maior que 1 que o tipo de dados pode representar.|
|[has_denorm](#has_denorm)|Testa se um tipo permite valores desnormalizados.|
|[has_denorm_loss](#has_denorm_loss)|Testa se a perda de precisão é detectada como uma perda de desnormalização em vez de um resultado inexato.|
|[has_infinity](#has_infinity)|Testa se um tipo tem uma representação de infinito positivo.|
|[has_quiet_NaN](#has_quiet_nan)|Testa se um tipo tem uma representação para um número (NAN) silencioso, que não é sinal.|
|[has_signaling_NaN](#has_signaling_nan)|Testa se um tipo tem uma representação para não sinalizar um número (NAN).|
|[infinito](#infinity)|A representação de infinito positivo para um tipo, se disponível.|
|[is_bounded](#is_bounded)|Testa se o conjunto de valores que um tipo pode representar é finito.|
|[is_exact](#is_exact)|Testa se os cálculos feitos em um tipo estão livres de erros de arredondamento.|
|[is_iec559](#is_iec559)|Testa se um tipo está em conformidade com os padrões IEC 559.|
|[is_integer](#is_integer)|Testa se um tipo tem uma representação de inteiro.|
|[is_modulo](#is_modulo)|Testa se um tipo tem uma representação de módulo.|
|[is_signed](#is_signed)|Testa se um tipo tem uma representação com sinal.|
|[is_specialized](#is_specialized)|Testa se um tipo tem uma especialização explícita definida no modelo de classe `numeric_limits` .|
|[máximo](#lowest)|Retorna o valor finito mais negativo.|
|[max](#max)|Retorna o valor máximo finito para um tipo.|
|[max_digits10](#max_digits10)|Retorna o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.|
|[max_exponent](#max_exponent)|Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.|
|[max_exponent10](#max_exponent10)|Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.|
|[min](#min)|Retorna o valor normalizado mínimo para um tipo.|
|[min_exponent](#min_exponent)|Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.|
|[min_exponent10](#min_exponent10)|Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.|
|[quiet_NaN](#quiet_nan)|Retorna a representação de um NAN (não é um número) silencioso para o tipo.|
|[Radix](#radix)|Retorna a base integral, conhecida como base, usada para a representação de um tipo.|
|[round_error](#round_error)|Retorna o erro de arredondamento máximo para o tipo.|
|[round_style](#round_style)|Retorna um valor que descreve os vários métodos que uma implementação pode escolher para o arredondamento de um valor de ponto flutuante para um valor inteiro.|
|[signaling_NaN](#signaling_nan)|Retorna a representação de um sinal NAN (não é um número) para o tipo.|
|[tinyness_before](#tinyness_before)|Testa se um tipo pode determinar que um valor é muito pequeno para representar como um valor normalizado antes de arredondá-lo.|
|[traps](#traps)|Testa se o trapping que relata exceções aritméticas é implementada para um tipo.|

### <a name="denorm_min"></a><a name="denorm_min"></a>denorm_min

Retorna o menor valor desnormalizado diferente de zero.

```cpp
static constexpr Type denorm_min() throw();
```

#### <a name="return-value"></a>Valor retornado

O menor valor desnormalizado diferente de zero.

#### <a name="remarks"></a>Comentários

**`long double`** é o mesmo que **`double`** para o compilador C++.

A função retorna o valor mínimo para o tipo, que é o mesmo que [mín](#min) se [has_denorm](#has_denorm) não for igual a `denorm_present` .

#### <a name="example"></a>Exemplo

```cpp
// numeric_limits_denorm_min.cpp
// compile with: /EHsc
#include <iostream>
#include <limits>

using namespace std;

int main( )
{
   cout << "The smallest nonzero denormalized value" << endl
        << "for float objects is: "
        << numeric_limits<float>::denorm_min( ) << endl;
   cout << "The smallest nonzero denormalized value" << endl
        << "for double objects is: "
        << numeric_limits<double>::denorm_min( ) << endl;
   cout << "The smallest nonzero denormalized value" << endl
        << "for long double objects is: "
        << numeric_limits<long double>::denorm_min( ) << endl;

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

### <a name="digits"></a><a name="digits"></a>números

Retorna o número de dígitos de base que o tipo pode representar sem perda de precisão.

```cpp
static constexpr int digits = 0;
```

#### <a name="return-value"></a>Valor retornado

O número de dígitos de base que o tipo pode representar sem perda de precisão.

#### <a name="remarks"></a>Comentários

O membro armazena o número de dígitos de base que o tipo pode representar sem alteração, que é o número de bits diferente de qualquer bit de sinal para um tipo inteiro predefinido ou o número de dígitos de mantissa para um tipo de ponto flutuante predefinido.

#### <a name="example"></a>Exemplo

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

### <a name="digits10"></a><a name="digits10"></a>digits10

Retorna o número de dígitos decimais que o tipo pode representar sem perda de precisão.

```cpp
static constexpr int digits10 = 0;
```

#### <a name="return-value"></a>Valor retornado

O número de dígitos decimais que o tipo pode representar sem perda de precisão.

#### <a name="example"></a>Exemplo

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

### <a name="epsilon"></a><a name="epsilon"></a>epsilo

A função retorna a diferença entre 1 e o menor valor maior que 1 que é representável para o tipo de dados.

```cpp
static constexpr Type epsilon() throw();
```

#### <a name="return-value"></a>Valor retornado

A diferença entre 1 e o menor valor maior que 1 que é representável para o tipo de dados.

#### <a name="remarks"></a>Comentários

O valor é FLT_EPSILON para o tipo **`float`** . `epsilon`para um tipo é o menor número de ponto flutuante positivo *n* , de modo que *n*  +  `epsilon`  +  *n* é representável.

#### <a name="example"></a>Exemplo

```cpp
// numeric_limits_epsilon.cpp
// compile with: /EHsc
#include <iostream>
#include <limits>

using namespace std;

int main( )
{
   cout << "The difference between 1 and the smallest "
        << "value greater than 1" << endl
        << "for float objects is: "
        << numeric_limits<float>::epsilon( ) << endl;
   cout << "The difference between 1 and the smallest "
        << "value greater than 1" << endl
        << "for double objects is: "
        << numeric_limits<double>::epsilon( ) << endl;
   cout << "The difference between 1 and the smallest "
        << "value greater than 1" << endl
        << "for long double objects is: "
        << numeric_limits<long double>::epsilon( ) << endl;
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

### <a name="has_denorm"></a><a name="has_denorm"></a>has_denorm

Testa se um tipo permite valores desnormalizados.

```cpp
static constexpr float_denorm_style has_denorm = denorm_absent;
```

#### <a name="return-value"></a>Valor retornado

Um valor de enumeração do tipo `const float_denorm_style` , indicando se o tipo permite valores desnormalizados.

#### <a name="remarks"></a>Comentários

O membro armazena `denorm_present` um tipo de ponto flutuante que tem valores desnormalizados, efetivamente um número variável de bits de expoente.

#### <a name="example"></a>Exemplo

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

### <a name="has_denorm_loss"></a><a name="has_denorm_loss"></a>has_denorm_loss

Testa se a perda de precisão é detectada como uma perda de desnormalização em vez de um resultado inexato.

```cpp
static constexpr bool has_denorm_loss = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** se a perda de precisão for detectada como uma perda de desnormalização; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

O membro armazena true para um tipo que determina se um valor perdeu a precisão porque foi entregue como um resultado desnormalizado (muito pequeno para ser representado como um valor normalizado) ou porque está inexato (não o mesmo por não estar sujeito a limitações de intervalo exponencial e precisão), uma opção com representações de ponto flutuantes IEC 559 que pode afetar alguns resultados.

#### <a name="example"></a>Exemplo

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

### <a name="has_infinity"></a><a name="has_infinity"></a>has_infinity

Testa se um tipo tem uma representação de infinito positivo.

```cpp
static constexpr bool has_infinity = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver uma representação para infinito positivo; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

O membro retornará **`true`** se [is_iec559](#is_iec559) for **`true`** .

#### <a name="example"></a>Exemplo

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

### <a name="has_quiet_nan"></a><a name="has_quiet_nan"></a>has_quiet_NaN

Testa se um tipo tem uma representação de um silencioso NAN (não é um número), que é sem sinal.

```cpp
static constexpr bool has_quiet_NaN = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o **tipo** tiver uma representação para um NaN silencioso; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Um NAN silencioso é uma codificação para um não número, o que não indica sua presença em uma expressão. O valor de retorno será **`true`** se [is_iec559](#is_iec559) for true.

#### <a name="example"></a>Exemplo

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

### <a name="has_signaling_nan"></a><a name="has_signaling_nan"></a>has_signaling_NaN

Testa se um tipo tem uma representação para não sinalizar um número (NAN).

```cpp
static constexpr bool has_signaling_NaN = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver uma representação para uma sinalização NAN; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Um NAN com sinal é uma codificação para um não número, o que indica sua presença em uma expressão. O valor de retorno será **`true`** se [is_iec559](#is_iec559) for true.

#### <a name="example"></a>Exemplo

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

### <a name="infinity"></a><a name="infinity"></a>infinito

A representação de infinito positivo para um tipo, se disponível.

```cpp
static constexpr Type infinity() throw();
```

#### <a name="return-value"></a>Valor retornado

A representação de infinito positivo para um tipo, se disponível.

#### <a name="remarks"></a>Comentários

O valor de retorno será significativo somente se [has_infinity](#has_infinity) for **`true`** .

#### <a name="example"></a>Exemplo

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
The representation of infinity for type float is: inf
The representation of infinity for type double is: inf
The representation of infinity for type long double is: inf
```

### <a name="is_bounded"></a><a name="is_bounded"></a>is_bounded

Testa se o conjunto de valores que um tipo pode representar é finito.

```cpp
static constexpr bool is_bounded = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver um conjunto limitado de valores representáveis; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Todos os tipos predefinidos têm um conjunto limitado de valores representáveis e retornam **`true`** .

#### <a name="example"></a>Exemplo

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

### <a name="is_exact"></a><a name="is_exact"></a>is_exact

Testa se os cálculos feitos em um tipo estão livres de erros de arredondamento.

```cpp
static constexpr bool is_exact = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se os cálculos estiverem livres de erros de arredondamento; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Todos os tipos inteiros predefinidos têm representações exatas para seus valores e retorno **`false`** . Uma representação de ponto fixo ou racional também é considerada exata, mas uma representação de ponto flutuante não é.

#### <a name="example"></a>Exemplo

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

### <a name="is_iec559"></a><a name="is_iec559"></a>is_iec559

Testa se um tipo está em conformidade com os padrões IEC 559.

```cpp
static constexpr bool is_iec559 = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo estiver em conformidade com os padrões IEC 559; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

O IEC 559 é um padrão internacional que representa valores de ponto flutuante e também é conhecido como IEEE 754 nos EUA.

#### <a name="example"></a>Exemplo

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

### <a name="is_integer"></a><a name="is_integer"></a>is_integer

Testa se um tipo tem uma representação de inteiro.

```cpp
static constexpr bool is_integer = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver uma representação de inteiro; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Todos os tipos de inteiro predefinidos têm uma representação de inteiro.

#### <a name="example"></a>Exemplo

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

### <a name="is_modulo"></a><a name="is_modulo"></a>is_modulo

Testa se um **tipo** tem uma representação de módulo.

```cpp
static constexpr bool is_modulo = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver uma representação de módulo; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Uma representação de módulo é uma representação na qual todos os resultados são reduzidos a um módulo de algum valor. Todos os tipos de inteiro sem sinal predefinidos têm uma representação de módulo.

#### <a name="example"></a>Exemplo

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

### <a name="is_signed"></a><a name="is_signed"></a>is_signed

Testa se um tipo tem uma representação com sinal.

```cpp
static constexpr bool is_signed = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver uma representação assinada; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

O membro armazena true para um tipo que tem uma representação com sinal, que é o caso para todos os tipos de inteiros com sinal e de ponto flutuante predefinidos.

#### <a name="example"></a>Exemplo

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

### <a name="is_specialized"></a><a name="is_specialized"></a>is_specialized

Testa se um tipo tem uma especialização explícita definida no modelo de classe `numeric_limits` .

```cpp
static constexpr bool is_specialized = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo tiver uma especialização explícita definida no modelo de classe; **`false`** se não estiver.

#### <a name="remarks"></a>Comentários

Todos os tipos escalares diferentes de ponteiros têm uma especialização explícita definida para o modelo de classe `numeric_limits` .

#### <a name="example"></a>Exemplo

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

### <a name="lowest"></a><a name="lowest"></a>máximo

Retorna o valor finito mais negativo.

```cpp
static constexpr Type lowest() throw();
```

#### <a name="return-value"></a>Valor retornado

Retorna o valor finito mais negativo.

#### <a name="remarks"></a>Comentários

Retorna o valor finito mais negativo para o tipo (que geralmente é `min()` para tipos de inteiro e `-max()` para tipos de ponto flutuante). O valor de retorno será significativo se `is_bounded` for **`true`** .

### <a name="max"></a><a name="max"></a>maximizar

Retorna o valor máximo finito para um tipo.

```cpp
static constexpr Type max() throw();
```

#### <a name="return-value"></a>Valor retornado

O valor máximo finito para um tipo.

#### <a name="remarks"></a>Comentários

O valor finito máximo é INT_MAX para o tipo **`int`** e FLT_MAX para o tipo **`float`** . O valor de retorno será significativo se [is_bounded](#is_bounded) for **`true`** .

#### <a name="example"></a>Exemplo

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

### <a name="max_digits10"></a><a name="max_digits10"></a>max_digits10

Retorna o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.

```cpp
static constexpr int max_digits10 = 0;
```

#### <a name="return-value"></a>Valor retornado

Retorna o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.

#### <a name="remarks"></a>Comentários

O membro armazena o número de dígitos decimais necessários para garantir que dois valores distintos do tipo tenham diferentes representações decimais.

### <a name="max_exponent"></a><a name="max_exponent"></a>max_exponent

Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.

```cpp
static constexpr int max_exponent = 0;
```

#### <a name="return-value"></a>Valor retornado

O expoente com base integral máximo representável pelo tipo.

#### <a name="remarks"></a>Comentários

O retorno da função membro é significativo apenas para os tipos de ponto flutuante. O `max_exponent` é o valor FLT_MAX_EXP para o tipo **`float`** .

#### <a name="example"></a>Exemplo

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

### <a name="max_exponent10"></a><a name="max_exponent10"></a>max_exponent10

Retorna o expoente integral positivo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.

```cpp
static constexpr int max_exponent10 = 0;
```

#### <a name="return-value"></a>Valor retornado

O expoente de base 10 integral máxima representável pelo tipo.

#### <a name="remarks"></a>Comentários

O retorno da função membro é significativo apenas para os tipos de ponto flutuante. O `max_exponent` é o valor FLT_MAX_10 para o tipo **`float`** .

#### <a name="example"></a>Exemplo

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

### <a name="min"></a><a name="min"></a> min

Retorna o valor normalizado mínimo para um tipo.

```cpp
static constexpr Type min() throw();
```

#### <a name="return-value"></a>Valor retornado

O valor normalizado mínimo para o tipo.

#### <a name="remarks"></a>Comentários

O valor normalizado mínimo é INT_MIN para o tipo **`int`** e FLT_MIN para o tipo **`float`** . O valor de retorno será significativo se [is_bounded](#is_bounded) for **`true`** ou se [is_signed](#is_signed) for **`false`** .

#### <a name="example"></a>Exemplo

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

### <a name="min_exponent"></a><a name="min_exponent"></a>min_exponent

Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de base é elevada a essa potência.

```cpp
static constexpr int min_exponent = 0;
```

#### <a name="return-value"></a>Valor retornado

O expoente com base integral mínima representável pelo tipo.

#### <a name="remarks"></a>Comentários

A função membro é significativa apenas para os tipos de ponto flutuante. O `min_exponent` é o valor FLT_MIN_EXP para o tipo **`float`** .

#### <a name="example"></a>Exemplo

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

### <a name="min_exponent10"></a><a name="min_exponent10"></a>min_exponent10

Retorna o expoente integral negativo máximo que o tipo de ponto flutuante pode representar como um valor finito quando uma base de dez é elevada a essa potência.

```cpp
static constexpr int min_exponent10 = 0;
```

#### <a name="return-value"></a>Valor retornado

O expoente de base 10 integral mínimo representável pelo tipo.

#### <a name="remarks"></a>Comentários

A função membro é significativa apenas para os tipos de ponto flutuante. O `min_exponent10` é o valor FLT_MIN_10_EXP para o tipo **`float`** .

#### <a name="example"></a>Exemplo

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

### <a name="quiet_nan"></a><a name="quiet_nan"></a>quiet_NaN

Retorna a representação de um NAN (não é um número) silencioso para o tipo.

```cpp
static constexpr Type quiet_NaN() throw();
```

#### <a name="return-value"></a>Valor retornado

A representação de um NAN silencioso para o tipo.

#### <a name="remarks"></a>Comentários

O valor de retorno será significativo somente se [has_quiet_NaN](#has_quiet_nan) for **`true`** .

#### <a name="example"></a>Exemplo

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

### <a name="radix"></a><a name="radix"></a>Radix

Retorna a base integral, conhecida como base, usada para a representação de um tipo.

```cpp
static constexpr int radix = 0;
```

#### <a name="return-value"></a>Valor retornado

A base integral para a representação do tipo.

#### <a name="remarks"></a>Comentários

A base é 2 para os tipos de inteiro predefinidos e para a base para a qual o expoente é elevado ou FLT_RADIX, para os tipos de pontos flutuantes predefinidos.

#### <a name="example"></a>Exemplo

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

### <a name="round_error"></a><a name="round_error"></a>round_error

Retorna o erro de arredondamento máximo para o tipo.

```cpp
static constexpr Type round_error() throw();
```

#### <a name="return-value"></a>Valor retornado

O erro de arredondamento máximo para o tipo.

#### <a name="example"></a>Exemplo

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

### <a name="round_style"></a><a name="round_style"></a>round_style

Retorna um valor que descreve os vários métodos que uma implementação pode escolher para o arredondamento de um valor de ponto flutuante para um valor inteiro.

```cpp
static constexpr float_round_style round_style = round_toward_zero;
```

#### <a name="return-value"></a>Valor retornado

Um valor da enumeração `float_round_style` que descreve o estilo de arredondamento.

#### <a name="remarks"></a>Comentários

O membro armazena um valor que descreve os vários métodos que uma implementação pode escolher para o arredondamento de um valor de ponto flutuante para um valor inteiro.

O estilo de arredondamento fixo é nessa implementação. Mesmo que se o programa for iniciado com um modo de arredondamento diferente, esse valor não será alterado.

#### <a name="example"></a>Exemplo

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

### <a name="signaling_nan"></a><a name="signaling_nan"></a>signaling_NaN

Retorna a representação de um sinal NAN (não é um número) para o tipo.

```cpp
static constexpr Type signaling_NaN() throw();
```

#### <a name="return-value"></a>Valor retornado

A representação de um NAN com sinal para o tipo.

#### <a name="remarks"></a>Comentários

O valor de retorno será significativo somente se [has_signaling_NaN](#has_signaling_nan) for **`true`** .

#### <a name="example"></a>Exemplo

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

### <a name="tinyness_before"></a><a name="tinyness_before"></a>tinyness_before

Testa se um tipo pode determinar que um valor é muito pequeno para representar como um valor normalizado antes de arredondá-lo.

```cpp
static constexpr bool tinyness_before = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o tipo puder detectar valores minúsculos antes do arredondamento; **`false`** se não puder.

#### <a name="remarks"></a>Comentários

Tipos que podem detectar pequenez foram incluídos como uma opção com representações de pontos flutuantes IEC 559 e sua implementação pode afetar alguns resultados.

#### <a name="example"></a>Exemplo

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

### <a name="traps"></a><a name="traps"></a>interceptações

Testa se o trapping que relata exceções aritméticas é implementada para um tipo.

```cpp
static constexpr bool traps = false;
```

#### <a name="return-value"></a>Valor retornado

**`true`** Se o ajuste de texto for implementado para o tipo; **`false`** se não for.

#### <a name="example"></a>Exemplo

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
