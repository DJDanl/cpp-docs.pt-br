---
title: C2040 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6adc045066c20dbba79835ab28c8c5000cae608a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2040"></a>C2040 de erro do compilador
'operator': 'identifier1' é diferente nos níveis de indireção de 'identifier2'  
  
 Uma expressão que envolva os operandos especificados tem tipos de operando incompatível ou convertido implicitamente tipos de operando. Se ambos os operandos forem aritméticos ou ambos são nonarithmetic (como matriz ou ponteiro), eles são usados sem alterações. Se um operando for aritmético e o outro não, o operando aritmético é convertido para o tipo do operando nonarithmetic.  
  
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
