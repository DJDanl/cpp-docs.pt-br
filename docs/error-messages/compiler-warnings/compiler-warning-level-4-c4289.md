---
title: Aviso do compilador (nível 4) C4289
ms.date: 11/04/2016
f1_keywords:
- C4289
helpviewer_keywords:
- C4289
ms.assetid: 0dbd2863-4cde-4e16-894b-104a2d5fa724
ms.openlocfilehash: b9083670465d68493d90a8e96ff7ee5db34c1978
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991318"
---
# <a name="compiler-warning-level-4-c4289"></a>Aviso do compilador (nível 4) C4289

extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo do loop for

Ao compilar com [/ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc: forScope-** , uma variável declarada em um loop [for](../../cpp/for-statement-cpp.md) é usada após o escopo **do loop for**.

Consulte [/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar o comportamento padrão nos loops **for** com **/ze**.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4289:

```cpp
// C4289.cpp
// compile with: /W4 /Zc:forScope-
#pragma warning(default:4289)
int main() {
   for (int i = 0 ; ; )   // C4289
      break;
   i++;
}
```
