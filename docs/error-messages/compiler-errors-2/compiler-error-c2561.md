---
title: C2561 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2561
dev_langs:
- C++
helpviewer_keywords:
- C2561
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ce30ffb454deb7bc847e736458295d037826a0ad
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2561"></a>C2561 de erro do compilador
'Identificador': função deve retornar um valor  
  
 A função foi declarada como retornar um valor, mas a definição da função não tem um `return` instrução.  
  
 Esse erro pode ser causado por um protótipo de função incorreto:  
  
1.  Se a função não retorna um valor, declare a função com o tipo de retorno [void](../../cpp/void-cpp.md).  
  
2.  Verifique se todas as possíveis ramificações da função retornam um valor do tipo declarado no protótipo.  
  
3.  Funções C++ que contém rotinas de assembly embutido que armazena o valor de retorno de `AX` registro terá uma instrução return. Copie o valor no `AX` em uma variável temporária e variável de retorno da função.  
  
 O exemplo a seguir gera C2561:  
  
```  
// C2561.cpp  
int Test(int x) {  
   if (x) {  
      return;   // C2561  
      // try the following line instead  
      // return 1;  
   }  
   return 0;  
}  
  
int main() {  
   Test(1);  
}  
```
