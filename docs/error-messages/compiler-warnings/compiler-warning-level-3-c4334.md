---
title: Compilador aviso (nível 3) C4334 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4334
dev_langs:
- C++
helpviewer_keywords:
- C4334
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b7bb16ea38b2c2112c12c561398341a7d1adbfc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044009"
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