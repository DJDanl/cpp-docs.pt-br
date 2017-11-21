---
title: "Compilador aviso (nível 3) C4334 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4334
dev_langs: C++
helpviewer_keywords: C4334
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: dba8fe25bc6401c0b823205bcc163dced466d4b9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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