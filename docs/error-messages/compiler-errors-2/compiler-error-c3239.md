---
title: C3239 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3239
dev_langs:
- C++
helpviewer_keywords:
- C3239
ms.assetid: 22a518b7-020f-4f3c-9963-a094667fd1ac
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8033c6d9fe0b711eabdd8ce6ab59aff10fc12671
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3239"></a>C3239 de erro do compilador
'type': ponteiro para ponteiro interior/pin não é permitido pelo common language runtime  
  
 O compilador encontrou um tipo inválido.  
  
 O exemplo a seguir gera C3229:  
  
```  
// C3239.cpp  
// compile with: /clr  
int main() {  
   interior_ptr<int>* pip0;   // C3239  
  
   // OK  
   int * pip1;  
   interior_ptr<int> pip2;  
   int ** pip;  
}  
```
