---
title: Aviso do compilador (nível 1) C4566
ms.date: 11/04/2016
f1_keywords:
- C4566
helpviewer_keywords:
- C4566
ms.assetid: 65f40730-e86f-447c-b37b-16caadcfe311
ms.openlocfilehash: 87d610980ffe9d9e5087ddaec0ecb91d813a4d60
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162252"
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
