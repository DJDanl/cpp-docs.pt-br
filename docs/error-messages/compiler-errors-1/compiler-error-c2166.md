---
title: C2166 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2166
dev_langs:
- C++
helpviewer_keywords:
- C2166
ms.assetid: 12789c3a-cc76-48bb-ae2e-64283e0964ed
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: bde5c3ad0162a5f2cb83397d72a1932736b50955
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2166"></a>C2166 de erro do compilador
l-value Especifica objeto const  
  
 Código de tentativas de modificar um item declarado `const`.  
  
 O exemplo a seguir gera C2166:  
  
```  
// C2166.cpp  
int f();  
int main() {  
   ( (const int&) 1 ) = 5;   // C2166  
}  
```
