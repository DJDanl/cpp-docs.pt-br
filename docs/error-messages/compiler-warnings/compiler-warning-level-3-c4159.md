---
title: Compilador aviso (nível 3) C4159
ms.date: 11/04/2016
f1_keywords:
- C4159
helpviewer_keywords:
- C4159
ms.assetid: e2cf964e-f4b8-4b2c-9569-1abb94307232
ms.openlocfilehash: e898af8f109ed23bd1784df7b39c174bbed675f2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552276"
---
# <a name="compiler-warning-level-3-c4159"></a>Compilador aviso (nível 3) C4159

> #<a name="pragma-pragmapop--has-popped-previously-pushed-identifier-identifier"></a>pragma pragma(pop,...): ativou o identificador anteriormente enviado '*identificador*'

## <a name="remarks"></a>Comentários

Seu código-fonte contém um **push** instrução com um identificador para um pragma seguido por um **pop-up** instrução sem um identificador. Como resultado, *identificador* é aparecidos e subsequentes usos da *identificador* pode causar um comportamento inesperado.

## <a name="example"></a>Exemplo

Para evitar esse aviso, dar um identificador do **pop-up** instrução. Por exemplo:

```cpp
// C4159.cpp
// compile with: /W3
#pragma pack(push, f)
#pragma pack(pop)   // C4159

// using the identifier resolves the warning
// #pragma pack(pop, f)

int main()
{
}
```