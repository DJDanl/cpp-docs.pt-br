---
title: Compilador aviso (nível 4) C4242
ms.date: 11/04/2016
f1_keywords:
- C4242
helpviewer_keywords:
- C4242
ms.assetid: 8df742e1-fbf1-42f3-8e93-c0e1c222dc7e
ms.openlocfilehash: e0582f3dfdd223b4571e361dc69fae1990aeea1c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498209"
---
# <a name="compiler-warning-level-4-c4242"></a>Compilador aviso (nível 4) C4242

'identifier': conversão de 'type1' em 'type2', possível perda de dados

Os tipos forem diferentes. Conversão de tipo pode resultar em perda de dados. O compilador faz a conversão de tipo.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

Para obter informações adicionais sobre C4242, consulte [comuns de erros de compilador](/windows/desktop/WinProg64/common-compiler-errors).

O exemplo a seguir gera C4242:

```
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