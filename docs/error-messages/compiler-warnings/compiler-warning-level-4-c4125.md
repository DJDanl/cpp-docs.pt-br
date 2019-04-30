---
title: Compilador aviso (nível 4) C4125
ms.date: 11/04/2016
f1_keywords:
- C4125
helpviewer_keywords:
- C4125
ms.assetid: a081d1f4-0789-4915-91df-7ff0b28ca245
ms.openlocfilehash: 3b82bfd1a1acff07a0fd47bbd2abfb08178a74c6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401352"
---
# <a name="compiler-warning-level-4-c4125"></a>Compilador aviso (nível 4) C4125

dígito decimal encerra sequência de escape octal

O compilador avalia o número octal sem o dígito decimal e pressupõe que o dígito decimal é um caractere.

## <a name="example"></a>Exemplo

```
// C4125a.cpp
// compile with: /W4
char array1[] = "\709"; // C4125
int main()
{
}
```

Se o dígito 9 destina-se como um caractere, o exemplo correto da seguinte maneira:

```
// C4125b.cpp
// compile with: /W4
char array[] = "\0709";  // C4125 String containing "89"
int main()
{
}
```