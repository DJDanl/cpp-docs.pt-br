---
title: Compilador aviso (nível 3) C4334
ms.date: 11/04/2016
f1_keywords:
- C4334
helpviewer_keywords:
- C4334
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
ms.openlocfilehash: 55512bf28c8c20512d0d245810d3e5c1fec36939
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402028"
---
# <a name="compiler-warning-level-3-c4334"></a>Compilador aviso (nível 3) C4334

'operator': o resultado de 32-bit shift convertido implicitamente para 64 bits (foi a mudança de 64 bits se destina?)

O resultado do deslocamento de 32 bits foi convertido implicitamente para 64 bits e a suspeita de compilador que uma mudança de 64 bits foi intencional.  Para resolver este aviso, use 64-bit shift, ou converter explicitamente o resultado de shift para 64 bits.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4334.

```
// C4334.cpp
// compile with: /W3 /c
void SetBit(unsigned __int64 *p, int i) {
   *p |= (1 << i);   // C4334
   *p |= (1i64 << i);   // OK
}
```