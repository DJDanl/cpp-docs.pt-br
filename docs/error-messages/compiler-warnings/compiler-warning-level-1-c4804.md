---
title: Compilador (nível 1) de aviso C4804 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4804
dev_langs:
- C++
helpviewer_keywords:
- C4804
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 677899230b2475c80f9bdd461a0c79740c4d3bec
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33286975"
---
# <a name="compiler-warning-level-1-c4804"></a>Compilador C4804 de aviso (nível 1)
'operação de ': uso não seguro de tipo 'bool' em operação  
  
 Esse aviso é para quando você tiver usado um `bool` variável ou valor de forma inesperada. Por exemplo, C4804 será gerado se você usar operadores, como o operador unário negativo (**-**) ou o operador de complemento (`~`). O compilador avalia a expressão.  
  
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