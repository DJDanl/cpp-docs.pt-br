---
title: C3873 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3873
helpviewer_keywords:
- C3873
ms.assetid: e68fd3be-2391-492b-ac3f-d2428901b2e9
caps.latest.revision: 5
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ecef5b5628c733217a8dbfdcaf7fafb6b3ae55f4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3873"></a>C3873 de erro do compilador
'char': Este caractere não é permitido como primeiro caractere de um identificador  
  
 O compilador C++ segue o padrão C++&11; caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caracteres universais são permitidos em um identificador. Restrições adicionais para o caractere inicial de um identificador. Para obter mais informações e uma lista de caracteres permitidos e intervalos de nomes de caracteres universais, consulte [identificadores](../../cpp/identifiers-cpp.md).  
  
 O intervalo de caracteres permitidos em um identificador é menos restritivo quando compilar C + + / código CLI. Identificadores no código compilado usando /clr devem seguir [padrão ECMA-335: Common Language Infrastructure (CLI)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).  
  
 O exemplo a seguir gera C3873:  
  
```  
// C3873.cpp  
int main() {  
   int \u036F_abc;   // C3873, not in allowed range for initial character  
   int abc_\u036F;   // OK, in allowed range for non-initial character  
}  
```
