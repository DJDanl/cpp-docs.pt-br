---
title: C2381 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2381
dev_langs:
- C++
helpviewer_keywords:
- C2381
ms.assetid: cc765f67-64ac-406f-93ef-ae7d548d58d7
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0442b94b1151dbee006a0d3ee71b1076d7afe7df
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2381"></a>C2381 de erro do compilador
'function': redefinição; difere de __declspec(noreturn)  
  
 Uma função foi declarada e, em seguida, definida mas a definição usada a [noreturn](../../cpp/noreturn.md) `__declspec` modificador. O uso de `noreturn` constitui uma redefinição da função; a declaração e definição precisam concordar com o uso de `noreturn`.  
  
 O exemplo a seguir gera C2381:  
  
```  
// C2381.cpp  
// compile with: /c  
void f1();  
void __declspec(noreturn) f1() {}   // C2381  
void __declspec(noreturn) f2() {}   // OK  
```
