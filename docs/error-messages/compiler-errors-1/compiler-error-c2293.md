---
title: C2293 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2293
dev_langs:
- C++
helpviewer_keywords:
- C2293
ms.assetid: 17e7b4e2-368b-4dd7-a01b-d82be60f8e56
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0b57daead4d355c81d0d411e37665e453d8f76c1
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2293"></a>C2293 de erro do compilador
'Identificador': inválido ter uma variável de membro como um especificador based  
  
 Especificadores de `__based` modificador deve ser ponteiros não membro.  
  
 O exemplo a seguir gera C2293:  
  
```  
// C2293.cpp  
// compile with: /c  
class A {  
   static int *i;  
   void __based(i) *bp;   // C2293  
   void *bp2;   // OK  
};  
```
