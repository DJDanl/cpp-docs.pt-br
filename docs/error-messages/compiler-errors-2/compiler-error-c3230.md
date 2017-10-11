---
title: C3230 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3230
dev_langs:
- C++
helpviewer_keywords:
- C3230
ms.assetid: 5ec53f25-59f6-4801-81e7-7b68bf04994d
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 76cd091e910015b2d6df8bd476f40f663c9f681b
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3230"></a>C3230 de erro do compilador
'function': argumento de tipo de modelo para 'template' não pode conter um parâmetro de tipo genérico: 'param'  
  
 Modelos são instanciados no tempo de compilação, mas são instanciados genéricos em tempo de execução. Portanto, não é possível gerar o código genérico que pode chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico é conhecido por último.  
  
 O exemplo a seguir gera C3230:  
  
```  
// C3230.cpp  
// compile with: /clr /LD  
template <class S>   
void f(S t);  
  
generic <class U>  
ref class C {  
   void f1(U x) {  
      f(x);   // C3230  
   }  
};  
```
