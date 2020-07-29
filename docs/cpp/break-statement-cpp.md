---
title: Instrução break (C++)
ms.date: 11/04/2016
f1_keywords:
- break_cpp
helpviewer_keywords:
- break keyword [C++]
ms.assetid: 63739928-8985-4b05-93ce-016322e6da3d
ms.openlocfilehash: 30ca602ecc65099adff7300f730c500a31fe0ed5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227602"
---
# <a name="break-statement-c"></a>Instrução break (C++)

A **`break`** instrução encerra a execução do loop delimitador ou da instrução condicional mais próxima na qual ele aparece. O controle passa para a instrução que segue o encerramento da instrução, se houver.

## <a name="syntax"></a>Sintaxe

```
break;
```

## <a name="remarks"></a>Comentários

A **`break`** instrução é usada com a instrução [switch](../cpp/switch-statement-cpp.md) condicional e com as [do](../cpp/do-while-statement-cpp.md)instruções do [for](../cpp/for-statement-cpp.md)loop do as, e [while](../cpp/while-statement-cpp.md) .

Em uma **`switch`** instrução, a **`break`** instrução faz com que o programa execute a próxima instrução fora da **`switch`** instrução. Sem uma **`break`** instrução, cada instrução do rótulo correspondente **`case`** ao final da **`switch`** instrução, incluindo a **`default`** cláusula, é executada.

Em loops, a **`break`** instrução encerra a execução da **`do`** instrução, ou, delimitadora mais próxima **`for`** **`while`** . O controle passa para a instrução que segue a instrução encerrada, se houver.

Em instruções aninhadas, a **`break`** instrução encerra apenas a **`do`** instrução,, **`for`** **`switch`** ou **`while`** que a inclui imediatamente. Você pode usar uma **`return`** **`goto`** instrução or para transferir o controle de estruturas mais profundamente aninhadas.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar a **`break`** instrução em um **`for`** loop.

```cpp
#include <iostream>
using namespace std;

int main()
{
    // An example of a standard for loop
    for (int i = 1; i < 10; i++)
    {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
    }

    // An example of a range-based for loop
int nums []{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i : nums) {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
    }
}
```

```Output
In each case:
1
2
3
```

O código a seguir mostra como usar **`break`** o em um **`while`** loop e um **`do`** loop.

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i < 10) {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
        i++;
    }

    i = 0;
    do {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
        i++;
    } while (i < 10);
}
```

```Output
In each case:
0123
```

O código a seguir mostra como usar **`break`** em uma instrução switch. Você deve usar **`break`** em todos os casos se desejar manipular cada caso separadamente; se você não usar **`break`** , a execução do código passará para o próximo caso.

```cpp
#include <iostream>
using namespace std;

enum Suit{ Diamonds, Hearts, Clubs, Spades };

int main() {

    Suit hand;
    . . .
    // Assume that some enum value is set for hand
    // In this example, each case is handled separately
    switch (hand)
    {
    case Diamonds:
        cout << "got Diamonds \n";
        break;
    case Hearts:
        cout << "got Hearts \n";
        break;
    case Clubs:
        cout << "got Clubs \n";
        break;
    case Spades:
        cout << "got Spades \n";
        break;
    default:
          cout << "didn't get card \n";
    }
    // In this example, Diamonds and Hearts are handled one way, and
    // Clubs, Spades, and the default value are handled another way
    switch (hand)
    {
    case Diamonds:
    case Hearts:
        cout << "got a red card \n";
        break;
    case Clubs:
    case Spades:
    default:
        cout << "didn't get a red card \n";
    }
}
```

## <a name="see-also"></a>Confira também

[Instruções de atalho](../cpp/jump-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução Continue](../cpp/continue-statement-cpp.md)
