---
title: "Compilador aviso (nível 1) C4804 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4804
dev_langs:
- C++
helpviewer_keywords:
- C4804
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f8da9580eaefb47d0d8ddb660b5f53f6041ff988
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4804"></a>Compilador C4804 de aviso (nível 1)
'operation': uso não seguro do tipo bool em operação  
  
 Esse aviso é para quando você usou um `bool` variável ou valor de forma inesperada. Por exemplo, C4804 é gerado se você usar operadores como o operador unário negativo (**-**) ou o operador de complemento (`~`). O compilador avalia a expressão.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4804:  
  
```  
// C4804.cpp  
// compile with: /W1  
  
int main()  
{  
   bool i = true;  
   if (-i)   // C4804, remove the '-' to resolve  
   {  
      i = false;  
   }  
}  
```
