---
title: C2040 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2040
dev_langs:
- C++
helpviewer_keywords:
- C2040
ms.assetid: 74ca3592-1469-4965-ab34-a4815e2fbefe
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 3504c8e18637ef907d5ab9c941ef7ad550daedf0
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2040"></a>C2040 de erro do compilador
'operator': 'identifier1' difere em níveis de indireção de 'identifier2'  
  
 Uma expressão que envolve os operandos especificados tem tipos de operando incompatível ou convertido implicitamente os tipos de operando. Se ambos os operandos forem aritméticos ou ambos são nonarithmetic (como ponteiro ou matriz), eles são usados sem alterações. Se um operando for aritmético e outros não, o operando aritmético é convertido para o tipo do operando nonarithmetic.  
  
 Este exemplo gera C2040 e mostra como corrigi-lo.  
  
```  
// C2040.cpp  
// Compile by using: cl /c /W3 C2040.cpp  
bool test() {  
   char c = '3';  
   return c == "3"; // C2446, C2040  
   // return c == '3'; // OK  
}  
```
