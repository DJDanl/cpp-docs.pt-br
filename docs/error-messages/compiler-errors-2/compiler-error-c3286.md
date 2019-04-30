---
title: Erro do compilador C3286
ms.date: 11/04/2016
f1_keywords:
- C3286
helpviewer_keywords:
- C3286
ms.assetid: 554328c8-cf44-4f7d-a8d2-def74d28ecdd
ms.openlocfilehash: 8c09ea34c7dabf2cadecad7c76d766c9496f5a5a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62381339"
---
# <a name="compiler-error-c3286"></a>Erro do compilador C3286

> '*especificador*': uma variável de iteração não pode ter qualquer especificadores de classe de armazenamento

Uma classe de armazenamento não pode ser especificada em uma variável de iteração. Para obter mais informações, consulte [classes de armazenamento (C++)](../../cpp/storage-classes-cpp.md) e [para cada um, no](../../dotnet/for-each-in.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3286 e também mostra o uso correto.

```cpp
// C3286.cpp
// compile with: /clr
int main() {
   array<int> ^p = { 1, 2, 3 };
   for each (static int i in p) {}   // C3286
   for each (int j in p) {}   // OK
}
```