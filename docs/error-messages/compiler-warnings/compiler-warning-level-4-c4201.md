---
title: Aviso do compilador (nível 4) C4201
ms.date: 11/04/2016
f1_keywords:
- C4201
helpviewer_keywords:
- C4201
ms.assetid: 6156f508-9393-4d77-9e73-1ec3e1c32d0d
ms.openlocfilehash: 1f029d7717f99e55a977ad9cb80dacbfa1485086
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541208"
---
# <a name="compiler-warning-level-4-c4201"></a>Aviso do compilador (nível 4) C4201

extensão não padrão usada: struct/Union de sem nome

Em extensões da Microsoft (/Ze), você pode especificar uma estrutura sem um Declarador como membros de outra estrutura ou União. Essas estruturas geram um erro em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).

## <a name="example"></a>Exemplo

```cpp
// C4201.cpp
// compile with: /W4
struct S
{
   float y;
   struct
   {
      int a, b, c;  // C4201
   };
} *p_s;

int main()
{
}
```