---
title: C2362 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2362
dev_langs:
- C++
helpviewer_keywords:
- C2362
ms.assetid: 7aafecbc-b3cf-45a6-9ec3-a17e3f222511
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 53b0b77930acba6ecf2d0f3c6748ba52e9b28e0a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33222170"
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