---
title: C3873 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3873
helpviewer_keywords:
- C3873
ms.assetid: e68fd3be-2391-492b-ac3f-d2428901b2e9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bec37b8fb00aedd83d91f1d001d77c42679ec038
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3873"></a>C3873 de erro do compilador
'char': Este caractere não é permitido como primeiro caractere de um identificador  
  
 O compilador do C++ segue o padrão de 11 C + + em caracteres permitidos em um identificador. Somente determinados intervalos de caracteres e nomes de caractere universais são permitidos em um identificador. Restrições adicionais para o caractere inicial de um identificador. Para obter mais informações e uma lista de intervalos de nome de caractere universal e caracteres permitidos, consulte [identificadores](../../cpp/identifiers-cpp.md).  
  
 O intervalo de caracteres permitido em um identificador é menos restritivo quando estiver compilando C + + código. Identificadores no código compilado usando /clr devem seguir [padrão ECMA-335: infra-estrutura de linguagem comum (CLI)](http://www.ecma-international.org/publications/standards/Ecma-335.htm).  
  
 O exemplo a seguir gera C3873:  
  
```  
// C3873.cpp  
int main() {  
   int \u036F_abc;   // C3873, not in allowed range for initial character  
   int abc_\u036F;   // OK, in allowed range for non-initial character  
}  
```