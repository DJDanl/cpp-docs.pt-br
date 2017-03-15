---
title: C2362 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: c01867500f6d5716da6c616fa74e0470cbc6f262
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2362"></a>C2362 de erro do compilador
inicialização de 'identifier' é ignorada por 'rótulo goto'  
  
 Ao compilar com [/Za](../../build/reference/za-ze-disable-language-extensions.md), saltar para o rótulo impede que o identificador que está sendo inicializado.  
  
 Não é possível ir após uma declaração com um inicializador, a menos que a declaração é colocada em um bloco não for inserido ou a variável já foi inicializada.  
  
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
  
 Resolução possível:  
  
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
