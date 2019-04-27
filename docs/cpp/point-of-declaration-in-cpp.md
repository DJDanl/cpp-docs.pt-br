---
title: Ponto de declaração em C++
ms.date: 11/04/2016
helpviewer_keywords:
- point of declaration
ms.assetid: 92ea8707-80cb-497c-b479-f907b8401859
ms.openlocfilehash: d6cb4c3813d88c8b29fbcb2e0827805f406e6c81
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62183395"
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