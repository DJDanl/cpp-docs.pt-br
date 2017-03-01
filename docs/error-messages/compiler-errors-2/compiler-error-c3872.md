---
title: C3872 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: cdc8048cb8cf50faeefb43b5fb166fc2f3fd2c1c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3872"></a>C3872 de erro do compilador
'char': Este caractere não é permitido em um identificador  
  
 O compilador C++ segue o padrão C++&11; caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caracteres universais são permitidos em um identificador. Restrições adicionais para o caractere inicial de um identificador. Para obter mais informações e uma lista de caracteres permitidos e intervalos de nomes de caracteres universais, consulte [identificadores](../../cpp/identifiers-cpp.md).  
  
 O intervalo de caracteres permitidos em um identificador é menos restritivo quando compilar C + + / código CLI. Identificadores no código compilado usando /clr devem seguir [padrão ECMA-335: Common Language Infrastructure (CLI)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).  
  
 O exemplo a seguir gera C3872:  
  
```  
// C3872.cpp  
int main() {  
   int abc_\u0040;   // C3872, U+0040 is in base char set  
   int abc_\u3001;   // C3872, U+3001 is not in allowed range  
   int \u30A2_abc_\u3042;   // OK, UCNs in allowed range  
}  
```
