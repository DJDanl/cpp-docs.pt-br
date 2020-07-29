---
title: Erro do compilador C3485
ms.date: 11/04/2016
f1_keywords:
- C3485
helpviewer_keywords:
- C3485
ms.assetid: d67536f9-67a1-4ad9-9a94-d8bbbca3d0dc
ms.openlocfilehash: 2117832ffd5a90612e9745a3706f01e3b5d1b18d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197664"
---
# <a name="compiler-error-c3485"></a>Erro do compilador C3485

uma definição de lambda não pode ter nenhum qualificador CV

Você não pode usar **`const`** um **`volatile`** qualificador ou como parte da definição de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova o **`const`** **`volatile`** qualificador ou da definição de sua expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3485 porque ele usa o **`const`** qualificador como parte da definição de uma expressão lambda:

```cpp
// C3485.cpp

int main()
{
   auto x = []() const mutable {}; // C3485
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
