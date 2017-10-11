---
title: C2422 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2422
dev_langs:
- C++
helpviewer_keywords:
- C2422
ms.assetid: ef0ec302-4028-4778-b134-0b8cea4bcad9
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 65412576c3c1a5e6b8205652d826d0eca6d222e6
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2422"></a>C2422 de erro do compilador
substituição de segmento inválido em 'operando'  
  
 Código de assembly embutido incorretamente usa um operador de substituição de segmento (dois-pontos) em um operando.  Possíveis causas incluem:  
  
-   O registro anterior o operador não é um registro de segmento.  
  
-   O registro anterior o operador não é um registro do segmento somente o operando.  
  
-   O operador de substituição de segmento aparece dentro de um operador de indireção (colchetes).  
  
-   A expressão a seguir o operador de substituição de segmento não é um operando de memória ou um operando imediato.  
  
 O exemplo a seguir gera C2422:  
  
```  
// C2422.cpp  
// processor: x86  
int main() {  
   _asm {  
      mov AX, [BX:ES]   // C2422  
      mov AX, ES   // OK  
   }  
}  
```
