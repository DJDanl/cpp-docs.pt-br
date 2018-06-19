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
ms.openlocfilehash: f26749c968c3cac18b509046633ba3d91d15a4be
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292679"
---
# <a name="compiler-warning-level-3-c4334"></a>Compilador C4334 de aviso (nível 3)
'operator': resultado de 32-bit shift convertido implicitamente para 64 bits (foi 64-bit shift era pretendido?)  
  
 O resultado de 32-bit shift foi convertido implicitamente para 64 bits e a suspeita de compilador deveria uma mudança de 64 bits.  Para resolver este aviso, use 64-bit shift ou converter explicitamente o resultado de shift para 64 bits.  
  
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