---
title: Aviso do compilador (nível 1) C4566
ms.date: 11/04/2016
f1_keywords:
- C4566
helpviewer_keywords:
- C4566
ms.assetid: 65f40730-e86f-447c-b37b-16caadcfe311
ms.openlocfilehash: c6a62b399aa32ec6caf2e5a9ee6d4c5836601ba4
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73965966"
---
# <a name="compiler-warning-level-1-c4566"></a>Aviso do compilador (nível 1) C4566

o caractere representado pelo nome de caractere universal ' char ' não pode ser representado na página de código atual (página)

Nem todo caractere Unicode pode ser representado em sua página de código ANSI atual.

Cadeias restritas (caracteres de um byte) são convertidas em caracteres de byte múltiplo, ao passo que as cadeias de caracteres de dois bytes não são.

O exemplo a seguir gera C4566:

```cpp
// C4566.cpp
// compile with: /W1
int main() {
   char c1 = '\u03a0';   // C4566
   char c2 = '\u0642';   // C4566

   wchar_t c3 = L'\u03a0';   // OK
   wchar_t c4 = L'\u0642';   // OK
}
```