---
title: Aviso do compilador (nível 3) C4334
ms.date: 11/04/2016
f1_keywords:
- C4334
helpviewer_keywords:
- C4334
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
ms.openlocfilehash: 38b93c83f822bc5b856a46f0dd62ea275d2bf207
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198712"
---
# <a name="compiler-warning-level-3-c4334"></a>Aviso do compilador (nível 3) C4334

' operator ': resultado de 32-bit Shift convertido implicitamente para 64 bits (era 64-bit Shift pretendido?)

O resultado da mudança de 32 bits foi implicitamente convertido em 64 bits, e o compilador suspeita que uma mudança de 64 bits foi pretendida.  Para resolver esse aviso, use Shift de 64 bits ou converta explicitamente o resultado da mudança para 64 bits.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4334.

```cpp
// C4334.cpp
// compile with: /W3 /c
void SetBit(unsigned __int64 *p, int i) {
   *p |= (1 << i);   // C4334
   *p |= (1i64 << i);   // OK
}
```
