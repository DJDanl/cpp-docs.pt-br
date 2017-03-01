---
title: "Compilador aviso (nível 3) C4334 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4334
dev_langs:
- C++
helpviewer_keywords:
- C4334
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 46ccabca181e1d195f3e86ae82c5a71ef76edf47
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4334"></a>Compilador C4334 de aviso (nível 3)
'operator': resultados de 32-bit shift implicitamente convertido em 64 bits (era shift de 64 bits se destina?)  
  
 O resultado do deslocamento de 32 bits foi convertido implicitamente para 64 bits e o suspeita de compilador que pretendia uma mudança de 64 bits.  Para resolver esse aviso, use shift de 64 bits, ou converter explicitamente o resultado shift para 64 bits.  
  
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
