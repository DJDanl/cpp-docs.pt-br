---
title: Aviso do compilador (nível 1) C4162
ms.date: 11/04/2016
f1_keywords:
- C4162
helpviewer_keywords:
- C4162
ms.assetid: 21ae3c92-501d-4689-ad7d-13753cb65eff
ms.openlocfilehash: 68e3a752f2aa039f4a2aba24d6433dc9fe2372f6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200051"
---
# <a name="compiler-warning-level-1-c4162"></a>Aviso do compilador (nível 1) C4162

' identifier ': nenhuma função com vínculo de C foi encontrada

Uma função com vínculo de C é declarada, mas não pode ser encontrada.

Para resolver esse aviso, compile em um arquivo. c (invocar o compilador C).  Se você precisar invocar C++ o compilador, coloque "C" externo antes da declaração da função.

O exemplo a seguir gera C4162

```cpp
// C4162.cpp
// compile with: /c /W1
unsigned char _bittest(long* a, long b);
#pragma intrinsic (_bittest)   // C4162

int main() {
   bool bit;
   long num = 78002;
   bit = _bittest(&num, 5);
}
```

Resolução possível:

```cpp
// C4162b.cpp
// compile with: /c
extern "C"
unsigned char _bittest(long* a, long b);
#pragma intrinsic (_bittest)

int main() {
   bool bit;
   long num = 78002;
   bit = _bittest(&num, 5);
}
```
