---
title: Aviso do compilador (nível 4) C4242
ms.date: 11/04/2016
f1_keywords:
- C4242
helpviewer_keywords:
- C4242
ms.assetid: 8df742e1-fbf1-42f3-8e93-c0e1c222dc7e
ms.openlocfilehash: 3123a414dc7a169d2a472dad96d659a9e56c9020
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541744"
---
# <a name="compiler-warning-level-4-c4242"></a>Aviso do compilador (nível 4) C4242

' identifier ': conversão de ' type1 ' para ' type2 ', possível perda de dados

Os tipos são diferentes. A conversão de tipo pode resultar em perda de dados. O compilador faz a conversão de tipo.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Para obter informações adicionais sobre o C4242, consulte [erros comuns do compilador](/windows/win32/WinProg64/common-compiler-errors).

O exemplo a seguir gera C4242:

```cpp
// C4242.cpp
// compile with: /W4
#pragma warning(4:4242)
int func() {
   return 0;
}

int main() {
   char a;
   a = func();   // C4242, return type and variable type do not match
}
```