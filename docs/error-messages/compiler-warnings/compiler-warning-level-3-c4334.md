---
title: Aviso do compilador (nível 3) C4334
ms.date: 11/04/2016
f1_keywords:
- C4334
helpviewer_keywords:
- C4334
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
ms.openlocfilehash: ebebfe9994be3dd136e3924cb2aea60c0c901926
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051629"
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