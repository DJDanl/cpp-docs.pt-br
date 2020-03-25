---
title: Instrução break (C++)
ms.date: 11/04/2016
f1_keywords:
- break_cpp
helpviewer_keywords:
- break keyword [C++]
ms.assetid: 63739928-8985-4b05-93ce-016322e6da3d
ms.openlocfilehash: 23d31e1456106d5f82c4a13079c72c231b8477bd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190476"
---
# <a name="break-statement-c"></a>Instrução break (C++)

A instrução **Break** termina a execução do loop de fechamento ou da instrução condicional mais próxima na qual ele aparece. O controle passa para a instrução que segue o encerramento da instrução, se houver.

## <a name="syntax"></a>Sintaxe

```
break;
```

## <a name="remarks"></a>Comentários

A instrução **Break** é usada com a instrução [switch](../cpp/switch-statement-cpp.md) condicional e [com as instruções](../cpp/do-while-statement-cpp.md)do loop do, [for](../cpp/for-statement-cpp.md)e [while](../cpp/while-statement-cpp.md) .

Em uma instrução **switch** , a instrução **Break** faz com que o programa execute a próxima instrução fora da instrução **switch** . Sem uma instrução **Break** , todas as instruções do rótulo **Case** correspondente ao final da instrução **switch** , incluindo a cláusula **Default** , são executadas.

Em loops, a instrução **Break** encerra a execução da instrução do, **for**ou **while** mais próxima de **delimitação.** O controle passa para a instrução que segue a instrução encerrada, se houver.

Em instruções aninhadas, a instrução **Break** encerra apenas a instrução **do**, **for**, **switch**ou **while** que a imediatamente o inclui. Você pode usar uma instrução **Return** ou **goto** para transferir o controle de estruturas mais profundamente aninhadas.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar a instrução **Break** em um loop **for** .

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

O código a seguir mostra como usar **Break** em um loop **while** e um loop **do** .

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

O código a seguir mostra como usar **Break** em uma instrução switch. Você deve usar a **quebra** em todos os casos se desejar manipular cada caso separadamente; Se você não usar **Break**, a execução do código passará para o próximo caso.

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
[Instrução continue](../cpp/continue-statement-cpp.md)
