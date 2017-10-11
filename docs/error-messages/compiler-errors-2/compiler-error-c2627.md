---
title: C2627 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2627
dev_langs:
- C++
helpviewer_keywords:
- C2627
ms.assetid: 7fc6c5ac-c7c9-4f0b-ad52-f52252526458
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2af1b475fb6eff2a37f333aa0ef5ed07eae791e2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2627"></a>C2627 de erro do compilador
'function': função membro não permitida em union anônima  
  
 Um [união anônima](../../cpp/unions.md#anonymous_unions) não pode ter funções de membro.  
  
 O exemplo a seguir gera C2627:  
  
```  
// C2627.cpp  
int main() {  
   union { void f(){} };   // C2627  
   union X { void f(){} };  
}  
```
