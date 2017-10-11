---
title: C3872 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3872
dev_langs:
- C++
helpviewer_keywords:
- C3872
ms.assetid: 519e95be-5641-40cc-894c-da4819506604
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e42ebb3e1fc286e40662eb7fcce83893b1e4007f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3872"></a>C3872 de erro do compilador
'char': Este caractere não é permitido em um identificador  
  
 O compilador do C++ segue o padrão de 11 C + + em caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caractere universais são permitidos em um identificador. Restrições adicionais para o caractere inicial de um identificador. Para obter mais informações e uma lista de intervalos de nome de caractere universal e caracteres permitidos, consulte [identificadores](../../cpp/identifiers-cpp.md).  
  
 O intervalo de caracteres permitido em um identificador é menos restritivo quando estiver compilando C + + código. Identificadores no código compilado usando /clr devem seguir [padrão ECMA-335: infra-estrutura de linguagem comum (CLI)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).  
  
 O exemplo a seguir gera C3872:  
  
```  
// C3872.cpp  
int main() {  
   int abc_\u0040;   // C3872, U+0040 is in base char set  
   int abc_\u3001;   // C3872, U+3001 is not in allowed range  
   int \u30A2_abc_\u3042;   // OK, UCNs in allowed range  
}  
```
