---
title: C2120 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2120
dev_langs:
- C++
helpviewer_keywords:
- C2120
ms.assetid: b0f3f66c-6cd2-4f48-9ea3-c270b53c2b8c
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 845740c871d13b62dfa91313c136c5f0331deb9c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2120"></a>C2120 de erro do compilador
'void' inválido com todos os tipos  
  
 O `void` tipo é usado em uma declaração com outro tipo.  
  
 O exemplo a seguir gera C2120:  
  
```  
// C2120.cpp  
int main() {  
   void int i;   // C2120  
   int j;   // OK  
}  
```
