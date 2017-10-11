---
title: C3285 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3285
dev_langs:
- C++
helpviewer_keywords:
- C3285
ms.assetid: 04e8f210-d67e-4810-b153-e1efe2986c8f
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a517ec1b163f3092b8dd161bee6cb348ab0129c1
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3285"></a>C3285 de erro do compilador
para cada instrução não pode operar em variáveis do tipo 'type'  
  
 O `for each` repete um grupo de instruções inseridos para cada elemento em uma matriz ou uma coleção de objetos.  
  
 Consulte [para cada um, no](../../dotnet/for-each-in.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3285.  
  
```  
// C3285.cpp  
// compile with: /clr  
int main() {  
   for each (int i in 0) {}   // C3285   
  
   array<int> ^p = { 1, 2, 3 };  
   for each (int j in p) {}   // OK  
}  
```
