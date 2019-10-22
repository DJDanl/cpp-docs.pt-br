---
title: complex&lt;double&gt;
ms.date: 11/04/2016
f1_keywords:
- complex/std::complex<double>
helpviewer_keywords:
- complex<double> function
ms.assetid: 0d0b9d2a-9b9b-410b-82a0-86b6df127e47
ms.openlocfilehash: 8955669f4bc6fd7b3b373751e0e5134205dd1657
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689786"
---
# <a name="complexltdoublegt"></a>complex&lt;double&gt;

Descreve um objeto que armazena um par ordenado de objetos do tipo **Double**, o primeiro que representa a parte real de um número complexo e o segundo que representa a parte imaginária.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class complex<double> {
public:
    constexpr complex(
    double RealVal = 0,
    double ImagVal = 0);

constexpr complex(const complex<double>& complexNum);

constexpr explicit complex(const complex<long double>& complexNum);
// rest same as class template complex
};
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *RealVal*
O valor do tipo **double** da parte real do número complexo que está sendo construído.

@No__t_1 *ImagVal*
O valor do tipo **double** da parte imaginária do número complexo que está sendo construído.

\ *complexNum*
O número complexo do tipo **float** ou do tipo **Long double** cujas partes reais e imaginários são usadas para inicializar um número complexo de tipo **Double** que está sendo construído.

## <a name="return-value"></a>Valor retornado

Um número complexo do tipo **double**.

## <a name="remarks"></a>Comentários

A especialização explícita do modelo de classe complexo para uma classe complexa do tipo **Double** difere do modelo de classe somente nos construtores que ele define. A conversão de **float** para **Double** pode ser implícita, mas a conversão de **Long duplo** para **Double** é necessária para ser **explícita**. O uso de **explícito** exclui a iniciação com conversão de tipo usando a sintaxe de atribuição.

Para obter mais informações sobre o modelo de classe `complex`, consulte [classe complexa](../standard-library/complex-class.md). Para obter uma lista de membros do modelo de classe `complex`, consulte.

## <a name="example"></a>Exemplo

```cpp
// complex_comp_dbl.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;
   double pi = 3.14159265359;

   // The first constructor specifies real & imaginary parts
   complex <double> c1 ( 4.0 , 5.0 );
   cout << "Specifying initial real & imaginary parts,\n"
        << "as type double gives c1 = " << c1 << endl;

   // The second constructor initializes values of the real &
   // imaginary parts using those of complex number of type float
   complex <float> c2float ( 4.0 , 5.0 );
   complex <double> c2double ( c2float );
   cout << "Implicit conversion from type float to type double,"
        << endl << "gives c2double = " << c2double << endl;

   // The third constructor initializes values of the real &
   // imaginary parts using those of a complex number
   // of type long double
   complex <long double> c3longdouble ( 4.0 , 5.0 );
   complex <double> c3double ( c3longdouble );
   cout << "Explicit conversion from type float to type double,"
        << endl << "gives c3longdouble = " << c3longdouble << endl;

   // The modulus and argument of a complex number can be recovered
   double absc3 = abs ( c3longdouble );
   double argc3 = arg ( c3longdouble );
   cout << "The modulus of c3 is recovered from c3 using: abs ( c3 ) = "
        << absc3 << endl;
   cout << "Argument of c3 is recovered from c3 using:" << endl
        << "arg ( c3 ) = " << argc3 << " radians, which is "
        << argc3 * 180 / pi << " degrees." << endl;
}
/* Output:
Specifying initial real & imaginary parts,
as type double gives c1 = (4,5)
Implicit conversion from type float to type double,
gives c2double = (4,5)
Explicit conversion from type float to type double,
gives c3longdouble = (4,5)
The modulus of c3 is recovered from c3 using: abs ( c3 ) = 6.40312
Argument of c3 is recovered from c3 using:
arg ( c3 ) = 0.896055 radians, which is 51.3402 degrees.
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<complexo>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe complex](../standard-library/complex-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
