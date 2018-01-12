---
title: C2422 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2422
dev_langs: C++
helpviewer_keywords: C2422
ms.assetid: ef0ec302-4028-4778-b134-0b8cea4bcad9
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 852a495406a8baf147fc53262f8fe856fce726b5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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