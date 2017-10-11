---
title: C2153 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2153
dev_langs:
- C++
helpviewer_keywords:
- C2153
ms.assetid: cfc50cb7-9a0f-4b5b-879a-d419c99f7be1
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a1370e665708db783cf030c226de9de32c6c6b3f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2153"></a>C2153 de erro do compilador
Constantes hexadecimais devem ter pelo menos um dígito hexadecimal  
  
 Constantes hexadecimais 0 x, 0x e \x não são válidos. Pelo menos um dígito hexadecimal deve seguir x ou X.  
  
 O exemplo a seguir gera C2153:  
  
```  
// C2153.cpp  
int main() {  
   int a= 0x;    // C2153  
   int b= 0xA;   // OK  
}  
```
