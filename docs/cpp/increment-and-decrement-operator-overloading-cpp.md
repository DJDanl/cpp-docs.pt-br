---
title: Sobrecarga dos operadores de incremento e decremento (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- increment operators [C++]
- increment operators [C++], types of
- decrement operators [C++]
- decrement operators [C++], types of
ms.assetid: 5423c6ce-3999-4a77-92f6-ad540add1b1d
ms.openlocfilehash: 4413c2bba600d1118870faca9a15b20398ec4dd4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50557257"
---
# <a name="increment-and-decrement-operator-overloading-c"></a>Sobrecarga dos operadores de incremento e decremento (C++)

Os operadores de incremento e decremento formam uma categoria especial porque há duas variantes de cada um:

- Pré-incremento e pós-incremento

- Pré-decremento e pós-decremento

Ao escrever funções de operador sobrecarregado, pode ser útil implementar versões separadas para as versões pré-fixada e pós-fixada desses operadores. Para distinguir entre os dois, a seguinte regra é observada: A forma de prefixo do operador é declarada exatamente da mesma maneira que qualquer outro operador unário; a forma pós-fixada aceita um argumento adicional do tipo **int**.

> [!NOTE]
>  Ao especificar um operador sobrecarregado para a forma pós-fixada do operador de incremento ou decremento, o argumento adicional deve ser do tipo **int**; especificar qualquer outro tipo gera um erro.

O exemplo a seguir mostra como definir operadores de incremento e decremento pré-fixados e pós-fixados para a classe `Point`:

```cpp
// increment_and_decrement1.cpp
class Point
{
public:
   // Declare prefix and postfix increment operators.
   Point& operator++();       // Prefix increment operator.
   Point operator++(int);     // Postfix increment operator.

   // Declare prefix and postfix decrement operators.
   Point& operator--();       // Prefix decrement operator.
   Point operator--(int);     // Postfix decrement operator.

   // Define default constructor.
   Point() { _x = _y = 0; }

   // Define accessor functions.
   int x() { return _x; }
   int y() { return _y; }
private:
   int _x, _y;
};

// Define prefix increment operator.
Point& Point::operator++()
{
   _x++;
   _y++;
   return *this;
}

// Define postfix increment operator.
Point Point::operator++(int)
{
   Point temp = *this;
   ++*this;
   return temp;
}

// Define prefix decrement operator.
Point& Point::operator--()
{
   _x--;
   _y--;
   return *this;
}

// Define postfix decrement operator.
Point Point::operator--(int)
{
   Point temp = *this;
   --*this;
   return temp;
}
int main()
{
}
```

Os mesmos operadores podem ser definidos no escopo do arquivo (globalmente) usando os seguintes cabeçalhos de função:

```cpp
friend Point& operator++( Point& )      // Prefix increment
friend Point& operator++( Point&, int ) // Postfix increment
friend Point& operator--( Point& )      // Prefix decrement
friend Point& operator--( Point&, int ) // Postfix decrement
```

O argumento do tipo **int** que denota a forma de pós-fixo de incremento ou decremento operador não é comumente usado para passar argumentos. Em geral, ele contém o valor 0. No entanto, pode ser usado como se segue:

```cpp
// increment_and_decrement2.cpp
class Int
{
public:
    Int &operator++( int n );
private:
    int _i;
};

Int& Int::operator++( int n )
{
    if( n != 0 )    // Handle case where an argument is passed.
        _i += n;
    else
        _i++;       // Handle case where no argument is passed.
    return *this;
}
int main()
{
   Int i;
   i.operator++( 25 ); // Increment by 25.
}
```

Não há nenhuma outra sintaxe para usar os operadores de incremento ou decremento para passar esses valores que não seja a invocação explícita, conforme mostrado no código acima. Uma maneira mais simples de implementar essa funcionalidade é sobrecarregar o operador de adição/atribuição (**+=**).

## <a name="see-also"></a>Consulte também

[Sobrecarga de Operador](../cpp/operator-overloading.md)