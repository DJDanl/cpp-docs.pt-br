---
title: C2422 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2422
dev_langs:
- C++
helpviewer_keywords:
- C2422
ms.assetid: ef0ec302-4028-4778-b134-0b8cea4bcad9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 89a808e4b324b11c88be38ae7d8815bee4e232cd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33196341"
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