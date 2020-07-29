---
title: Erro do compilador C2833
ms.date: 11/04/2016
f1_keywords:
- C2833
helpviewer_keywords:
- C2833
ms.assetid: b9418ce1-e2ee-4599-8959-6fde89c27569
ms.openlocfilehash: a6ffcb13d04f3c7c5ac62e147a2b6b2b305e11e1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218163"
---
# <a name="compiler-error-c2833"></a>Erro do compilador C2833

> ' operator *Operator-Name*' não é um operador ou tipo reconhecido

A palavra **`operator`** deve ser seguida por um *nome de operador* que você deseja substituir ou um tipo que você deseja converter.

Para obter uma lista dos operadores que você pode definir em um tipo gerenciado, consulte [operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).

O exemplo a seguir gera C2833:

```cpp
// C2833.cpp
// compile with: /c
class A {};

void operator ::* ();   // C2833
void operator :: ();   // OK
```
