---
title: Aviso do compilador (nível 4) C4125
ms.date: 11/04/2016
f1_keywords:
- C4125
helpviewer_keywords:
- C4125
ms.assetid: a081d1f4-0789-4915-91df-7ff0b28ca245
ms.openlocfilehash: b1e4da53c1f4e109e56c6fe734bc65786ad6cf75
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541600"
---
# <a name="compiler-warning-level-4-c4125"></a>Aviso do compilador (nível 4) C4125

dígito decimal encerra sequência de escape octal

O compilador avalia o número octal sem o dígito decimal e assume que o dígito decimal é um caractere.

## <a name="example"></a>Exemplo

```cpp
// C4125a.cpp
// compile with: /W4
char array1[] = "\709"; // C4125
int main()
{
}
```

Se o dígito 9 for destinado a um caractere, corrija o exemplo da seguinte maneira:

```cpp
// C4125b.cpp
// compile with: /W4
char array[] = "\0709";  // C4125 String containing "89"
int main()
{
}
```