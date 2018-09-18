---
title: Erro do compilador C3286 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3286
dev_langs:
- C++
helpviewer_keywords:
- C3286
ms.assetid: 554328c8-cf44-4f7d-a8d2-def74d28ecdd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ea2a6dcccd6de6d4fc3081106123f4ab37f71a2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052904"
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