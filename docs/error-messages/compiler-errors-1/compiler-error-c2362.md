---
title: C2362 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2362
dev_langs:
- C++
helpviewer_keywords:
- C2362
ms.assetid: 7aafecbc-b3cf-45a6-9ec3-a17e3f222511
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e3a921084d696e6cf7abebc75d02d403cbcda2be
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2362"></a>C2362 de erro do compilador
inicialização de 'Identificador' é ignorada por 'goto rótulo'  
  
 Ao compilar com [/Za](../../build/reference/za-ze-disable-language-extensions.md), saltar para o rótulo impede que o identificador está sendo inicializado.  
  
 Não é possível saltar após uma declaração com um inicializador, a menos que a declaração é incluída em um bloco que não for inserido ou a variável já foi inicializada.  
  
 O exemplo a seguir gera C2326:  
  
```  
// C2362.cpp  
// compile with: /Za  
int main() {  
   goto label1;  
   int i = 1;      // C2362, initialization skipped  
label1:;  
}  
```  
  
 Possível solução:  
  
```  
// C2362b.cpp  
// compile with: /Za  
int main() {  
   goto label1;  
   {  
      int j = 1;   // OK, this block is never entered  
   }  
label1:;  
}  
```
