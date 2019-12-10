---
title: Aviso do compilador (nível 4) C4201
ms.date: 11/04/2016
f1_keywords:
- C4201
helpviewer_keywords:
- C4201
ms.assetid: 6156f508-9393-4d77-9e73-1ec3e1c32d0d
ms.openlocfilehash: 4bbbc8987c3ae4157d5f8133978a46a004988bce
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991617"
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
