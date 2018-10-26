---
title: Class complex | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- complex/std::complex::value_type
- complex/std::complex::imag
- complex/std::complex::real
dev_langs:
- C++
helpviewer_keywords:
- std::complex [C++], value_type
- std::complex [C++], imag
- std::complex [C++], real
ms.assetid: d6492e1c-5eba-4bc5-835b-2a88001a5868
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f31d2e0fe0a58d2b1de4196bd1125c842731fb42
ms.sourcegitcommit: 8c2de32e96c84d0147af3cce1e89e4f28707ff12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/26/2018
ms.locfileid: "50143699"
---
# <a name="complex-class"></a>Classe complex

A classe de modelo descreve um objeto que armazena dois objetos do tipo `Type`, um que representa a parte real de um número complexo e outro que representa a parte imaginária.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class complex
```

## <a name="remarks"></a>Comentários

Um objeto da classe `Type`:

- Tem um construtor padrão público, um destruidor, um construtor de cópia e um operador de atribuição com comportamento convencional.

- Pode receber valores inteiros ou de ponto flutuante ou uma conversão de tipo para esses valores com comportamento convencional.

- Define os operadores aritméticos e funções matemáticas, conforme necessário, definidos para os tipos de ponto flutuante com comportamento convencional.

Em particular, talvez não exista nenhuma diferença sutil entre a construção da cópia e a construção padrão seguida pela atribuição. Nenhuma das operações em objetos da classe `Type` pode lançar exceções.

Existem especializações explícitas do complexo de classe de modelo para os três tipos de ponto flutuante. Nessa implementação, um valor de qualquer outro tipo `Type` é estereotipado para **duplo** para cálculos reais, com o **double** atribuído de volta ao objeto armazenado do tipo de resultado `Type`.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[complex](#complex)|Constrói um número complexo com partes reais e imaginárias especificadas ou como uma cópia de algum outro número complexo.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[value_type](#value_type)|Um tipo que representa o tipo de dados usado para representar as partes reais e imaginárias de um número complexo.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[imag](#imag)|Extrai o componente imaginário de um número complexo.|
|[real](#real)|Extrai o componente real de um número complexo.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator*=](#op_star_eq)|Multiplica um número complexo de destino por um fator, que pode ser complexo ou ser do mesmo tipo que as partes reais e imaginárias do número complexo.|
|[operator+=](#op_add_eq)|Adiciona um número a um número complexo de destino, em que o número adicionado pode ser complexo ou do mesmo tipo que as partes reais e imaginárias do número complexo ao qual ele é adicionado.|
|[operator-=](#operator-_eq)|Subtrai um número de um número complexo de destino, em que o número subtraído pode ser complexo ou do mesmo tipo que as partes reais e imaginárias do número complexo ao qual ele é adicionado.|
|[operator/=](#op_div_eq)|Divide um número complexo de destino por um divisor, que pode ser complexo ou ser do mesmo tipo que as partes reais e imaginárias do número complexo.|
|[operator=](#op_eq)|Atribui um número a um número complexo de destino, em que o número atribuído pode ser complexo ou do mesmo tipo que as partes reais e imaginárias do número complexo ao qual ele está sendo atribuído.|

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<complexo>

**Namespace:** std

## <a name="complex"></a>  complex::complex

Constrói um número complexo com partes reais e imaginárias especificadas ou como uma cópia de algum outro número complexo.

```cpp
constexpr complex(
    const T& _RealVal = 0,
    const T& _ImagVal = 0);

template <class Other>
constexpr complex(
    const complex<Other>& complexNum);
```

### <a name="parameters"></a>Parâmetros

*_RealVal*<br/>
O valor da parte real usada para inicializar o número complexo que está sendo construído.

*_ImagVal*<br/>
O valor da parte imaginária usada para inicializar o número complexo que está sendo construído.

*complexNum*<br/>
O número complexo cujas partes reais e imaginárias são usadas para inicializar o número complexo que está sendo construído.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa o armazenado parte real para  *\_RealVal* e a parte imaginária armazenada  *\_Imagval*. O segundo construtor inicializa o armazenado parte real para `complexNum.real()` e a parte imaginária armazenada para `complexNum.imag()`.

Nessa implementação, se um tradutor não dá suporte a funções membro de modelo, o modelo:

```cpp
template <class Other>
complex(const complex<Other>& right);
```

é substituído por:

```
complex(const complex& right);
```

que é o construtor de cópia.

### <a name="example"></a>Exemplo

```cpp
// complex_complex.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
    using namespace std;
    double pi = 3.14159265359;

    // The first constructor specifies real & imaginary parts
    complex<double> c1( 4.0 , 5.0 );
    cout << "Specifying initial real & imaginary parts,"
        << "c1 = " << c1 << endl;

    // The second constructor initializes values of the real &
    // imaginary parts using those of another complex number
    complex<double> c2( c1 );
    cout << "Initializing with the real and imaginary parts of c1,"
        << " c2 = " << c2 << endl;

    // Complex numbers can be initialized in polar form
    // but will be stored in Cartesian form
    complex<double> c3( polar( sqrt( (double)8 ) , pi / 4 ) );
    cout << "c3 = polar( sqrt( 8 ) , pi / 4 ) = " << c3 << endl;

    // The modulus and argument of a complex number can be recovered
    double absc3 = abs( c3 );
    double argc3 = arg( c3 );
    cout << "The modulus of c3 is recovered from c3 using: abs( c3 ) = "
        << absc3 << endl;
    cout << "Argument of c3 is recovered from c3 using:\n arg( c3 ) = "
        << argc3 << " radians, which is " << argc3 * 180 / pi
        << " degrees." << endl;
}
```

## <a name="imag"></a>  complex::imag

Extrai o componente imaginário de um número complexo.

```cpp
T imag() const;

T imag(const T& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Um número complexo cujo valor imaginário deve ser extraído.

### <a name="return-value"></a>Valor de retorno

A parte imaginária do número complexo.

### <a name="remarks"></a>Comentários

Para um número complexo *a + bi*, é a parte ou componente imaginário *Im(a + BI) = b*.

### <a name="example"></a>Exemplo

```cpp
// complex_imag.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
    using namespace std;

    complex<double> c1( 4.0 , 3.0 );
    cout << "The complex number c1 = " << c1 << endl;

    double dr1 = c1.real();
    cout << "The real part of c1 is c1.real() = "
        << dr1 << "." << endl;

    double di1 = c1.imag();
    cout << "The imaginary part of c1 is c1.imag() = "
        << di1 << "." << endl;
}
```

```Output
The complex number c1 = (4,3)
The real part of c1 is c1.real() = 4.
The imaginary part of c1 is c1.imag() = 3.
```

## <a name="op_star_eq"></a>  complex::operator*=

Multiplica um número complexo de destino por um fator, que pode ser complexo ou ser do mesmo tipo que as partes reais e imaginárias do número complexo.

```cpp
template <class Other>
complex& operator*=(const complex<Other>& right);

complex<Type>& operator*=(const Type& right);

complex<Type>& operator*=(const complex<Type>& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Um número complexo ou um número que é do mesmo tipo que o parâmetro do número complexo de destino.

### <a name="return-value"></a>Valor de retorno

Um número complexo multiplicado pelo número especificado como um parâmetro.

### <a name="remarks"></a>Comentários

A operação está sobrecarregada para que operações aritméticas simples possam ser executadas sem a conversão dos dados em um formato específico.

### <a name="example"></a>Exemplo

```cpp
// complex_op_me.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main()
{
    using namespace std;
    double pi = 3.14159265359;

    // Example of the first member function
    // type complex<double> multiplied by type complex<double>
    complex<double> cl1( polar ( 3.0 , pi / 6 ) );
    complex<double> cr1( polar ( 2.0 , pi / 3 ) );
    cout << "The left-side complex number is cl1 = " << cl1 << endl;
    cout << "The right-side complex number is cr1 = " << cr1 << endl;

    complex<double> cs1 = cl1 * cr1;
    cout << "Quotient of two complex numbers is: cs1 = cl1 * cr1 = "
        << cs1 << endl;

    // This is equivalent to the following operation
    cl1 *= cr1;
    cout << "Quotient of two complex numbers is also: cl1 *= cr1 = "
        << cl1 << endl;

    double abscl1 = abs ( cl1 );
    double argcl1 = arg ( cl1 );
    cout << "The modulus of cl1 is: " << abscl1 << endl;
    cout << "The argument of cl1 is: "<< argcl1 << " radians, which is "
        << argcl1 * 180 / pi << " degrees." << endl << endl;

    // Example of the second member function
    // type complex<double> multiplied by type double
    complex<double> cl2 ( polar ( 3.0 , pi / 6 ) );
    double cr2 = 5.0;
    cout << "The left-side complex number is cl2 = " << cl2 << endl;
    cout << "The right-side complex number is cr2 = " << cr2 << endl;

    complex<double> cs2 = cl2 * cr2;
    cout << "Quotient of two complex numbers is: cs2 = cl2 * cr2 = "
        << cs2 << endl;

    // This is equivalent to the following operation
    cl2 *= cr2;
    cout << "Quotient of two complex numbers is also: cl2 *= cr2 = "
        << cl2 << endl;

    double abscl2 = abs ( cl2 );
    double argcl2 = arg ( cl2 );
    cout << "The modulus of cl2 is: " << abscl2 << endl;
    cout << "The argument of cl2 is: "<< argcl2 << " radians, which is "
        << argcl2 * 180 / pi << " degrees." << endl;
}
```

## <a name="op_add_eq"></a>  complex::operator+=

Adiciona um número a um número complexo de destino, em que o número adicionado pode ser complexo ou do mesmo tipo que as partes reais e imaginárias do número complexo ao qual ele é adicionado.

```cpp
template <class Other>
complex<Type>& operator+=(const complex<Other>& right);

complex<Type>& operator+=(const Type& right);

complex<Type>& operator+=(const complex<Type>& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Um número complexo ou um número que é do mesmo tipo que o parâmetro do número complexo de destino.

### <a name="return-value"></a>Valor de retorno

Um número complexo que tem o número especificado como um parâmetro adicionado.

### <a name="remarks"></a>Comentários

A operação está sobrecarregada para que operações aritméticas simples possam ser executadas sem a conversão dos dados em um formato específico.

### <a name="example"></a>Exemplo

```cpp
// complex_op_pe.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;
   double pi = 3.14159265359;

   // Example of the first member function
   // type complex<double> added to type complex<double>
   complex<double> cl1( 3.0 , 4.0 );
   complex<double> cr1( 2.0 , -1.0 );
   cout << "The left-side complex number is cl1 = " << cl1 << endl;
   cout << "The right-side complex number is cr1 = " << cr1 << endl;

   complex<double> cs1 = cl1 + cr1;
   cout << "The sum of the two complex numbers is: cs1 = cl1 + cr1 = "
        << cs1 << endl;

   // This is equivalent to the following operation
   cl1 += cr1;
   cout << "The complex number cr1 added to the complex number cl1 is:"
        << "\n cl1 += cr1 = " << cl1 << endl;

   double abscl1 = abs( cl1 );
   double argcl1 = arg( cl1 );
   cout << "The modulus of cl1 is: " << abscl1 << endl;
   cout << "The argument of cl1 is: "<< argcl1 << " radians, which is "
        << argcl1 * 180 / pi << " degrees." << endl << endl;

   // Example of the second member function
   // type double added to type complex<double>
   complex<double> cl2( -2 , 4 );
   double cr2 =5.0;
   cout << "The left-side complex number is cl2 = " << cl2 << endl;
   cout << "The right-side complex number is cr2 = " << cr2 << endl;

   complex<double> cs2 = cl2 + cr2;
   cout << "The sum of the two complex numbers is: cs2 = cl2 + cr2 = "
        << cs2 << endl;

   // This is equivalent to the following operation
   cl2 += cr2;
   cout << "The complex number cr2 added to the complex number cl2 is:"
        << "\n cl2 += cr2 = " << cl2 << endl;

   double abscl2 = abs( cl2 );
   double argcl2 = arg( cl2 );
   cout << "The modulus of cl2 is: " << abscl2 << endl;
   cout << "The argument of cl2 is: "<< argcl2 << " radians, which is "
        << argcl2 * 180 / pi << " degrees." << endl << endl;
}
```

```Output
The left-side complex number is cl1 = (3,4)
The right-side complex number is cr1 = (2,-1)
The sum of the two complex numbers is: cs1 = cl1 + cr1 = (5,3)
The complex number cr1 added to the complex number cl1 is:
cl1 += cr1 = (5,3)
The modulus of cl1 is: 5.83095
The argument of cl1 is: 0.54042 radians, which is 30.9638 degrees.

The left-side complex number is cl2 = (-2,4)
The right-side complex number is cr2 = 5
The sum of the two complex numbers is: cs2 = cl2 + cr2 = (3,4)
The complex number cr2 added to the complex number cl2 is:
cl2 += cr2 = (3,4)
The modulus of cl2 is: 5
The argument of cl2 is: 0.927295 radians, which is 53.1301 degrees.
```

## <a name="complex__operator-_eq"></a>  complex::operator-=

Subtrai um número de um número complexo de destino, em que o número subtraído pode ser complexo ou do mesmo tipo que as partes reais e imaginárias do número complexo ao qual ele é adicionado.

```cpp
template <class Other>
complex<Type>& operator-=(const complex<Other>& complexNum);

complex<Type>& operator-=(const Type& _RealPart);

complex<Type>& operator-=(const complex<Type>& complexNum);
```

### <a name="parameters"></a>Parâmetros

*complexNum*<br/>
Um número complexo a ser subtraído do número complexo de destino.

*_RealPart*<br/>
Um número real a ser subtraído do número complexo de destino.

### <a name="return-value"></a>Valor de retorno

Um número complexo que tem o número especificado como um parâmetro subtraído dele.

### <a name="remarks"></a>Comentários

A operação está sobrecarregada para que operações aritméticas simples possam ser executadas sem a conversão dos dados em um formato específico.

### <a name="example"></a>Exemplo

```cpp
// complex_op_se.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;
   double pi = 3.14159265359;

   // Example of the first member function
   // type complex<double> subtracted from type complex<double>
   complex<double> cl1( 3.0 , 4.0 );
   complex<double> cr1( 2.0 , -1.0 );
   cout << "The left-side complex number is cl1 = " << cl1 << endl;
   cout << "The right-side complex number is cr1 = " << cr1 << endl;

   complex<double> cs1 = cl1 - cr1;
   cout << "The difference between the two complex numbers is:"
        << "\n cs1 = cl1 - cr1 = " << cs1 << endl;

   // This is equivalent to the following operation
   cl1 -= cr1;
   cout << "Complex number cr1 subtracted from complex number cl1 is:"
        << "\n cl1 -= cr1 = " << cl1 << endl;

   double abscl1 = abs( cl1 );
   double argcl1 = arg( cl1 );
   cout << "The modulus of cl1 is: " << abscl1 << endl;
   cout << "The argument of cl1 is: "<< argcl1 << " radians, which is "
        << argcl1 * 180 / pi << " degrees." << endl << endl;

   // Example of the second member function
   // type double subtracted from type complex<double>
   complex<double> cl2( 2.0 , 4.0 );
   double cr2 = 5.0;
   cout << "The left-side complex number is cl2 = " << cl2 << endl;
   cout << "The right-side complex number is cr2 = " << cr2 << endl;

   complex<double> cs2 = cl2 - cr2;
   cout << "The difference between the two complex numbers is:"
        << "\n cs2 = cl2 - cr2 = " << cs2 << endl;

   // This is equivalent to the following operation
   cl2  -= cr2;
   cout << "Complex number cr2 subtracted from complex number cl2 is:"
        << "\n cl2 -= cr2 = " << cl2 << endl;

   double abscl2 = abs( cl2 );
   double argcl2 = arg( cl2 );
   cout << "The modulus of cl2 is: " << abscl2 << endl;
   cout << "The argument of cl2 is: "<< argcl2 << " radians, which is "
        << argcl2 * 180 / pi << " degrees." << endl << endl;
}
```

```Output
The left-side complex number is cl1 = (3,4)
The right-side complex number is cr1 = (2,-1)
The difference between the two complex numbers is:
cs1 = cl1 - cr1 = (1,5)
Complex number cr1 subtracted from complex number cl1 is:
cl1 -= cr1 = (1,5)
The modulus of cl1 is: 5.09902
The argument of cl1 is: 1.3734 radians, which is 78.6901 degrees.

The left-side complex number is cl2 = (2,4)
The right-side complex number is cr2 = 5
The difference between the two complex numbers is:
cs2 = cl2 - cr2 = (-3,4)
Complex number cr2 subtracted from complex number cl2 is:
cl2 -= cr2 = (-3,4)
The modulus of cl2 is: 5
The argument of cl2 is: 2.2143 radians, which is 126.87 degrees.
```

## <a name="op_div_eq"></a>  complex::operator/=

Divide um número complexo de destino por um divisor, que pode ser complexo ou ser do mesmo tipo que as partes reais e imaginárias do número complexo.

```cpp
template <class Other>
complex<Type>& operator/=(const complex<Other>& complexNum);

complex<Type>& operator/=(const Type& _RealPart);

complex<Type>& operator/=(const complex<Type>& complexNum);
```

### <a name="parameters"></a>Parâmetros

*complexNum*<br/>
Um número complexo a ser subtraído do número complexo de destino.

*_RealPart*<br/>
Um número real a ser subtraído do número complexo de destino.

### <a name="return-value"></a>Valor de retorno

Um número complexo dividido pelo número especificado como um parâmetro.

### <a name="remarks"></a>Comentários

A operação está sobrecarregada para que operações aritméticas simples possam ser executadas sem a conversão dos dados em um formato específico.

### <a name="example"></a>Exemplo

```cpp
// complex_op_de.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;
   double pi = 3.14159265359;

   // Example of the first member function
   // type complex<double> divided by type complex<double>
   complex<double> cl1( polar (3.0 , pi / 6 ) );
   complex<double> cr1( polar (2.0 , pi / 3 ) );
   cout << "The left-side complex number is cl1 = " << cl1 << endl;
   cout << "The right-side complex number is cr1 = " << cr1 << endl;

   complex<double> cs1 = cl1 / cr1;
   cout << "The quotient of the two complex numbers is: cs1 = cl1 /cr1 = "
        << cs1 << endl;

   // This is equivalent to the following operation
   cl1 /= cr1;
   cout << "Quotient of two complex numbers is also: cl1 /= cr1 = "
        << cl1 << endl;

   double abscl1 = abs( cl1 );
   double argcl1 = arg( cl1 );
   cout << "The modulus of cl1 is: " << abscl1 << endl;
   cout << "The argument of cl1 is: "<< argcl1 << " radians, which is "
        << argcl1 * 180 / pi << " degrees." << endl << endl;

   // Example of the second member function
   // type complex<double> divided by type double
   complex<double> cl2( polar(3.0 , pi / 6 ) );
   double cr2 =5;
   cout << "The left-side complex number is cl2 = " << cl2 << endl;
   cout << "The right-side complex number is cr2 = " << cr2 << endl;

   complex<double> cs2 = cl2 / cr2;
   cout << "The quotient of the two complex numbers is: cs2 /= cl2 cr2 = "
        << cs2 << endl;

   // This is equivalent to the following operation
   cl2 /= cr2;
   cout << "Quotient of two complex numbers is also: cl2 = /cr2 = "
        << cl2 << endl;

   double abscl2 = abs( cl2 );
   double argcl2 = arg( cl2 );
   cout << "The modulus of cl2 is: " << abscl2 << endl;
   cout << "The argument of cl2 is: "<< argcl2 << " radians, which is "
        << argcl2 * 180 / pi << " degrees." << endl << endl;
}
```

```Output
The left-side complex number is cl1 = (2.59808,1.5)
The right-side complex number is cr1 = (1,1.73205)
The quotient of the two complex numbers is: cs1 = cl1 /cr1 = (1.29904,-0.75)
Quotient of two complex numbers is also: cl1 /= cr1 = (1.29904,-0.75)
The modulus of cl1 is: 1.5
The argument of cl1 is: -0.523599 radians, which is -30 degrees.

The left-side complex number is cl2 = (2.59808,1.5)
The right-side complex number is cr2 = 5
The quotient of the two complex numbers is: cs2 /= cl2 cr2 = (0.519615,0.3)
Quotient of two complex numbers is also: cl2 = /cr2 = (0.519615,0.3)
The modulus of cl2 is: 0.6
The argument of cl2 is: 0.523599 radians, which is 30 degrees.
```

## <a name="op_eq"></a>  complex::operator=

Atribui um número a um número complexo de destino, em que o número atribuído pode ser complexo ou do mesmo tipo que as partes reais e imaginárias do número complexo ao qual ele está sendo atribuído.

```cpp
template <class Other>
complex<Type>& operator=(const complex<Other>& right);

complex<Type>& operator=(const Type& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Um número complexo ou um número que é do mesmo tipo que o parâmetro do número complexo de destino.

### <a name="return-value"></a>Valor de retorno

Um número complexo que recebeu o número especificado como um parâmetro.

### <a name="remarks"></a>Comentários

A operação está sobrecarregada para que operações aritméticas simples possam ser executadas sem a conversão dos dados em um formato específico.

### <a name="example"></a>Exemplo

```cpp
// complex_op_as.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;
   double pi = 3.14159265359;

   // Example of the first member function
   // type complex<double> assigned to type complex<double>
   complex<double> cl1( 3.0 , 4.0 );
   complex<double> cr1( 2.0 , -1.0 );
   cout << "The left-side complex number is cl1 = " << cl1 << endl;
   cout << "The right-side complex number is cr1 = " << cr1 << endl;

   cl1  = cr1;
   cout << "The complex number cr1 assigned to the complex number cl1 is:"
        << "\ncl1 = cr1 = " << cl1 << endl;

   // Example of the second member function
   // type double assigned to type complex<double>
   complex<double> cl2( -2 , 4 );
   double cr2 =5.0;
   cout << "The left-side complex number is cl2 = " << cl2 << endl;
   cout << "The right-side complex number is cr2 = " << cr2 << endl;

   cl2 = cr2;
   cout << "The complex number cr2 assigned to the complex number cl2 is:"
        << "\ncl2 = cr2 = " << cl2 << endl;

   cl2 = complex<double>(3.0, 4.0);
   cout << "The complex number (3, 4) assigned to the complex number cl2 is:"
        << "\ncl2 = " << cl2 << endl;
}
```

```Output
The left-side complex number is cl1 = (3,4)
The right-side complex number is cr1 = (2,-1)
The complex number cr1 assigned to the complex number cl1 is:
cl1 = cr1 = (2,-1)
The left-side complex number is cl2 = (-2,4)
The right-side complex number is cr2 = 5
The complex number cr2 assigned to the complex number cl2 is:
cl2 = cr2 = (5,0)
The complex number (3, 4) assigned to the complex number cl2 is:
cl2 = (3,4)
```

## <a name="real"></a>  complex::real

Obtém ou define o componente real de um número complexo.

```cpp
constexpr T real() const;

T real(const T& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Um número complexo cujo valor real deve ser extraído.

### <a name="return-value"></a>Valor de retorno

A parte real do número complexo.

### <a name="remarks"></a>Comentários

Para um número complexo *a + bi*, a parte real ou o componente é *Re(a + BI) = um*.

### <a name="example"></a>Exemplo

```cpp
// complex_class_real.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
   using namespace std;

   complex<double> c1( 4.0 , 3.0 );
   cout << "The complex number c1 = " << c1 << endl;

   double dr1 = c1.real();
   cout << "The real part of c1 is c1.real() = "
        << dr1 << "." << endl;

   double di1 = c1.imag();
   cout << "The imaginary part of c1 is c1.imag() = "
        << di1 << "." << endl;
}
```

```Output
The complex number c1 = (4,3)
The real part of c1 is c1.real() = 4.
The imaginary part of c1 is c1.imag() = 3.
```

## <a name="value_type"></a>  complex::value_type

Um tipo que representa o tipo de dados usado para representar as partes reais e imaginárias de um número complexo.

```
typedef Type value_type;
```

### <a name="remarks"></a>Comentários

`value_type` é um sinônimo para a classe complexa `Type` parâmetro de modelo.

### <a name="example"></a>Exemplo

```cpp
// complex_valuetype.cpp
// compile with: /EHsc
#include <complex>
#include <iostream>

int main( )
{
    using namespace std;
    complex<double>::value_type a = 3, b = 4;

    complex<double> c1 ( a , b );
    cout << "Specifying initial real & imaginary parts"
        << "\nof type value_type: "
        << "c1 = " << c1 << "." << endl;
}
```

```Output
Specifying initial real & imaginary parts
of type value_type: c1 = (3,4).
```

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
