---
title: C2470 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2470
dev_langs:
- C++
helpviewer_keywords:
- C2470
ms.assetid: e17d2cb8-b84c-447c-976a-625f0c96f3fe
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b55813f0945bc1445cf956b153a2f72f09b35ba2
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2470"></a>C2470 de erro do compilador
'function': parece com uma definição de função, mas não há nenhuma lista de parâmetros; Ignorando corpo aparente  
  
 Uma definição de função está faltando a lista de argumentos.  
  
 O exemplo a seguir gera C2470:  
  
```  
// C2470.cpp  
int MyFunc {};  // C2470  
void MyFunc2() {};  //OK  
  
int main(){  
   MyFunc();  
   MyFunc2();  
}  
```
