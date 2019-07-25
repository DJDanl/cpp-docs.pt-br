---
title: complex&lt;long double&gt;
ms.date: 11/04/2016
f1_keywords:
- std::complex<long double>
- complex<long double>
- std.complex<long double>
helpviewer_keywords:
- complex<long double> function
ms.assetid: 37591991-b385-46e9-b727-d534dbc10432
ms.openlocfilehash: 280fb4c15219b11d2325ff37a296e133810bf2b5
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68449486"
---
# <a name="complexltlong-doublegt"></a>complex&lt;long double&gt;

Essa classe de modelo explicitamente especializada descreve um objeto que armazena um par ordenado de objetos, ambos os dois tipos duplos, o primeiro que representa a parte real de um número complexo e o segundo que representa a parte imaginária.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class complex<long double> {
public:
    constexpr complex(
    long double _RealVal = 0,
    long double _ImagVal = 0);

complex(
    constexpr complex<long double>& complexNum);

// rest same as template class complex
};
```

### <a name="parameters"></a>Parâmetros

*_RealVal*\
O valor do tipo **long double** da parte real do número complexo que está sendo construído.

*_ImagVal*\
O valor do tipo **Long double** para a parte imaginário do número complexo que está sendo construído.

*complexNum*\
O número complexo do tipo **Double** ou do tipo **float** cujas partes reais e imaginários são usadas para inicializar um número complexo de tipo **Long duplo** que está sendo construído.

## <a name="return-value"></a>Valor de retorno

Um número complexo de tipo **longo Duplo**.

## <a name="remarks"></a>Comentários

A especialização explícita da classe `complex` template para uma classe complexa do tipo **Long** difere da classe template somente nos construtores que ele define. A conversão de **longa dupla** para **flutuante** pode ser implícita, mas a conversão de **duplo** para **longo Duplo** é necessária para ser **explícita**. O uso de **explícito** exclui a iniciação com conversão de tipo usando a sintaxe de atribuição.

Para obter mais informações sobre a classe `complex` de modelo e seus membros, consulte [classe complexa](../standard-library/complex-class.md).

**Específico da Microsoft**: Os tipos **longos duplos** e **duplos** têm a mesma representação, mas são tipos distintos. Para obter mais informações, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).

## <a name="example"></a>Exemplo

```cpp
// complex_comp_ld.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
    using namespace std;
    double pi = 3.14159265359;

    // The first constructor specifies real & imaginary parts
    complex<long double> c1( 4.0 , 5.0 );
    cout << "Specifying initial real & imaginary parts,\n"
        << " as type float gives c1 = " << c1 << endl;

    // The second constructor initializes values of the real &
    // imaginary parts using those of complex number of type float
    complex<float> c2float( 1.0 , 3.0 );
    complex<long double> c2longdouble ( c2float );
    cout << "Implicit conversion from type float to type long double,"
        << "\n gives c2longdouble = " << c2longdouble << endl;

    // The third constructor initializes values of the real &
    // imaginary parts using those of a complex number
    // of type double
    complex<double> c3double( 3.0 , 4.0 );
    complex<long double> c3longdouble( c3double );
    cout << "Implicit conversion from type long double to type float,"
        << "\n gives c3longdouble = " << c3longdouble << endl;

    // The modulus and argument of a complex number can be recovered
    double absc3 = abs( c3longdouble );
    double argc3 = arg( c3longdouble );
    cout << "The modulus of c3 is recovered from c3 using: abs( c3 ) = "
        << absc3 << endl;
    cout << "Argument of c3 is recovered from c3 using:\n arg( c3 ) = "
        << argc3 << " radians, which is " << argc3 * 180 / pi
        << " degrees." << endl;
}
```

```Output
Specifying initial real & imaginary parts,
as type float gives c1 = (4,5)
Implicit conversion from type float to type long double,
gives c2longdouble = (1,3)
Implicit conversion from type long double to type float,
gives c3longdouble = (3,4)
The modulus of c3 is recovered from c3 using: abs( c3 ) = 5
Argument of c3 is recovered from c3 using:
arg( c3 ) = 0.927295 radians, which is 53.1301 degrees.
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<complexo>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe complex](../standard-library/complex-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
