---
title: C3834 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3834
dev_langs:
- C++
helpviewer_keywords:
- C3834
ms.assetid: 059e0dc4-300b-4e74-b6c2-41a57831fe2a
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8a827b2abe6352f083dbd21bdd9647af9b3b1f5c
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3834"></a>C3834 de erro do compilador
conversão explícita inválida para um ponteiro de fixação; Use uma variável local fixada em vez disso  
  
 Conversões explícitas para um ponteiro fixado não são permitidas.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3834.  
  
```  
// C3834.cpp  
// compile with: /clr  
int main() {  
   int x = 33;  
  
   pin_ptr<int> p = safe_cast<pin_ptr<int> >(&x);   // C3834  
   pin_ptr<int> p2 = &x;   // OK  
}  
```  

