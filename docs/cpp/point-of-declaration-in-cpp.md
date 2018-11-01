---
title: Ponto de declaração em C++
ms.date: 11/04/2016
helpviewer_keywords:
- point of declaration
ms.assetid: 92ea8707-80cb-497c-b479-f907b8401859
ms.openlocfilehash: d6cb4c3813d88c8b29fbcb2e0827805f406e6c81
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50560648"
---
# <a name="point-of-declaration-in-c"></a>Ponto de declaração em C++

Um nome é considerado declarado imediatamente após seu declarator, mas antes de seu inicializador (opcional). (Para obter mais informações sobre os declaradores, consulte [declarações e definições](declarations-and-definitions-cpp.md).)

Considere este exemplo:

```cpp
// point_of_declaration1.cpp
// compile with: /W1
double dVar = 7.0;
int main()
{
   double dVar = dVar;   // C4700
}
```

Se o ponto de declaração fosse *após* a inicialização e, em seguida, o local `dVar` seria inicializado como 7.0, o valor da variável global `dVar`. No entanto, como não é esse o caso, `dVar` é inicializado como um valor indefinido.

## <a name="see-also"></a>Consulte também

[Escopo](../cpp/scope-visual-cpp.md)