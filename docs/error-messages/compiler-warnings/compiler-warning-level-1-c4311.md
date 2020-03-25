---
title: Aviso do compilador (nível 1) C4311
ms.date: 11/04/2016
f1_keywords:
- C4311
helpviewer_keywords:
- C4311
ms.assetid: ddc579d0-d051-47bc-915d-71ffb32323c9
ms.openlocfilehash: 52f8338423b5e3366b85207477b3b1ee5e9c399f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163096"
---
# <a name="compiler-warning-level-1-c4311"></a>Aviso do compilador (nível 1) C4311

'variable': truncamento de ponteiro de 'type' para 'type'

Esse aviso detecta problemas de truncamento de ponteiro de 64 bits. Por exemplo, se o código for compilado para uma arquitetura de 64 bits, o valor de um ponteiro (64 bits) será truncado se for atribuído a um `int` (32 bits). Para obter mais informações, consulte [regras para usar ponteiros](/windows/win32/WinProg64/rules-for-using-pointers).

Para obter informações adicionais sobre as causas comuns de aviso C4311, consulte [erros comuns do compilador](/windows/win32/WinProg64/common-compiler-errors).

O exemplo de código a seguir gera C4311 quando compilado para um destino de 64 bits e, em seguida, demonstra como corrigi-lo:

```cpp
// C4311.cpp
// compile by using: cl /W1 C4311.cpp
int main() {
   void* p = &p;
   unsigned int i = (unsigned int) p;   // C4311 for 64-bit targets
   unsigned long long j = (unsigned long long) p;   // OK
}
```
