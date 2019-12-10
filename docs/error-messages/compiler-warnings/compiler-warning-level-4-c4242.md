---
title: Aviso do compilador (nível 4) C4242
ms.date: 11/04/2016
f1_keywords:
- C4242
helpviewer_keywords:
- C4242
ms.assetid: 8df742e1-fbf1-42f3-8e93-c0e1c222dc7e
ms.openlocfilehash: 2f457b5424cbca071e047f4375aaa85962e52210
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991479"
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
