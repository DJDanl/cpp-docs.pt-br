---
title: C2040 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2040
dev_langs:
- C++
helpviewer_keywords:
- C2040
ms.assetid: 74ca3592-1469-4965-ab34-a4815e2fbefe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d6b19a5dd647e51efb46ef9798b7f7cdff5339b9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33167535"
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