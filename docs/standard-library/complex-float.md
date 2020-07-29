---
title: complex&lt;float&gt;
ms.date: 11/04/2016
f1_keywords:
- complex/std::complex<float>
helpviewer_keywords:
- complex<float> function
ms.assetid: 1178eb1e-39bd-4017-89cd-aea95f813939
ms.openlocfilehash: 441006c977b4a4249270d0f4809da0fba0163395
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230059"
---
# <a name="complexltfloatgt"></a>complex&lt;float&gt;

Descreve um objeto que armazena um par ordenado de objetos do tipo **`float`** , o primeiro que representa a parte real de um número complexo e o segundo que representa a parte imaginária.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class complex<float> {
public:
    constexpr complex(
    float _RealVal = 0,
    float _ImagVal = 0);

constexpr complex(
    const complex<float>& complexNum);

constexpr complex(
    const complex<double>& complexNum);

constexpr complex(
    const complex<long double>& complexNum);
// rest same as class template complex
};
```

### <a name="parameters"></a>parâmetros

*_RealVal*\
O valor do tipo **`float`** para a parte real do número complexo que está sendo construído.

*_ImagVal*\
O valor do tipo **`float`** para a parte imaginário do número complexo que está sendo construído.

*complexNum*\
O número complexo do tipo **`double`** ou do tipo **`long double`** cujas partes reais e imaginários são usadas para inicializar um número complexo de tipo **`float`** que está sendo construído.

## <a name="return-value"></a>Valor retornado

Um número complexo de tipo **`float`** .

## <a name="remarks"></a>Comentários

A especialização explícita do modelo de classe complexa para uma classe complexa de tipo **`float`** difere do modelo de classe somente nos construtores que ele define. A conversão de **`float`** para pode **`double`** ser implícita, mas a conversão menos segura de **`float`** para **`long double`** é necessária para ser **`explicit`** . O uso de **`explicit`** regras para a inicialização com a conversão de tipo usando a sintaxe de atribuição.

Para obter mais informações sobre o modelo de classe `complex` , consulte [classe complexa](../standard-library/complex-class.md). Para obter uma lista de membros do modelo de classe `complex` , consulte.

## <a name="example"></a>Exemplo

```cpp
// complex_comp_flt.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;
   double pi = 3.14159265359;

   // The first constructor specifies real & imaginary parts
   complex <float> c1 ( 4.0 , 5.0 );
   cout << "Specifying initial real & imaginary parts,\n"
        << " as type float gives c1 = " << c1 << endl;

   // The second constructor initializes values of the real &
   // imaginary parts using those of complex number of type double
   complex <double> c2double ( 1.0 , 3.0 );
   complex <float> c2float ( c2double );
   cout << "Implicit conversion from type double to type float,"
        << endl << "gives c2float = " << c2float << endl;

   // The third constructor initializes values of the real &
   // imaginary parts using those of a complex number
   // of type long double
   complex <long double> c3longdouble ( 3.0 , 4.0 );
   complex <float> c3float ( c3longdouble );
   cout << "Explicit conversion from type long double to type float,"
        << endl << "gives c3float = " << c3float << endl;

   // The modulus and argument of a complex number can be recovered
   double absc3 = abs ( c3float);
   double argc3 = arg ( c3float);
   cout << "The modulus of c3 is recovered from c3 using: abs ( c3 ) = "
        << absc3 << endl;
   cout << "Argument of c3 is recovered from c3 using:"
        << endl << "arg ( c3 ) = "
        << argc3 << " radians, which is " << argc3 * 180 / pi
        << " degrees." << endl;
}
/* Output:
Specifying initial real & imaginary parts,
as type float gives c1 = (4,5)
Implicit conversion from type double to type float,
gives c2float = (1,3)
Explicit conversion from type long double to type float,
gives c3float = (3,4)
The modulus of c3 is recovered from c3 using: abs ( c3 ) = 5
Argument of c3 is recovered from c3 using:
arg ( c3 ) = 0.927295 radians, which is 53.1301 degrees.
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**:\<complex>

**Namespace:** std

## <a name="see-also"></a>Confira também

[Classe complexa](../standard-library/complex-class.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
