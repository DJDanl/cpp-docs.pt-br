---
title: 'Operador de conversão de tipo explícito: ()'
ms.date: 11/04/2016
helpviewer_keywords:
- explicit data type conversion operator
- conversions [C++], explicit
- operators [C++], explicit type conversion
- data type conversion [C++], explicit
- type conversion [C++], explicit conversions
ms.assetid: 54272006-5ffb-45ed-8283-27152ab97529
ms.openlocfilehash: c168653a82b4d4c5023de1f76a1e6269625c74d8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354855"
---
# <a name="explicit-type-conversion-operator-"></a>Operador de conversão de tipo explícito: ()

O C++ permite a conversão de tipos explícita usando uma sintaxe semelhante à sintaxe de chamada de função.

## <a name="syntax"></a>Sintaxe

```
simple-type-name ( expression-list )
```

## <a name="remarks"></a>Comentários

Um *nome de tipo simples* seguido de uma lista de *expressões* incluída entre parênteses constrói um objeto do tipo especificado usando as expressões especificadas. O exemplo a seguir mostra uma conversão de tipo explícita para o tipo int:

```cpp
int i = int( d );
```

O exemplo a `Point` seguir mostra uma classe.

## <a name="example"></a>Exemplo

```cpp
// expre_Explicit_Type_Conversion_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class Point
{
public:
    // Define default constructor.
    Point() { _x = _y = 0; }
    // Define another constructor.
    Point( int X, int Y ) { _x = X; _y = Y; }

    // Define "accessor" functions as
    // reference types.
    unsigned& x() { return _x; }
    unsigned& y() { return _y; }
    void Show()   { cout << "x = " << _x << ", "
                         << "y = " << _y << "\n"; }
private:
    unsigned _x;
    unsigned _y;
};

int main()
{
    Point Point1, Point2;

    // Assign Point1 the explicit conversion
    //  of ( 10, 10 ).
    Point1 = Point( 10, 10 );

    // Use x() as an l-value by assigning an explicit
    //  conversion of 20 to type unsigned.
    Point1.x() = unsigned( 20 );
    Point1.Show();

    // Assign Point2 the default Point object.
    Point2 = Point();
    Point2.Show();
}
```

## <a name="output"></a>Saída

```Output
x = 20, y = 10
x = 0, y = 0
```

Embora o exemplo acima demonstre a conversão de tipos explícita usando constantes, a mesma técnica funciona para executar essas conversões em objetos. O fragmento de código a seguir demonstra isso:

```cpp
int i = 7;
float d;

d = float( i );
```

As conversões de tipos explícitas também podem ser especificadas usando a sintaxe em estilo "cast". O exemplo anterior, reescrito usando a sintaxe "cast", fica assim:

```cpp
d = (float)i;
```

As conversões em estilo "cast" e em estilo de função têm os mesmos resultados na conversão de valores únicos. Porém, na sintaxe em estilo de função, você pode especificar mais de um argumento para a conversão. Essa diferença é importante para os tipos definidos pelo usuário. Considere uma classe `Point` e as respectivas conversões:

```cpp
struct Point
{
    Point( short x, short y ) { _x = x; _y = y; }
    ...
    short _x, _y;
};
...
Point pt = Point( 3, 10 );
```

O exemplo anterior, que usa a conversão no estilo de função, mostra como converter dois `Point`valores (um para *x* e um para *y*) para o tipo definido pelo usuário .

> [!CAUTION]
> Use as conversões de tipos explícitas com cuidado, já que elas substituem a verificação de tipos interna do compilador do C++.

A notação [do elenco](../cpp/cast-operator-parens.md) deve ser usada para conversões para tipos que não tenham um nome de tipo simples (ponteiro ou tipos *de* referência, por exemplo). A conversão para tipos que podem ser expressos com um *nome de tipo simples* pode ser escrita em qualquer forma.

A definição de tipo nas conversões em estilo "cast" é ilegal.

## <a name="see-also"></a>Confira também

[Expressões pós-fixadas](../cpp/postfix-expressions.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
