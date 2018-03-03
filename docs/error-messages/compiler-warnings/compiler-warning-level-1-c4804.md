---
title: "Compilador (nível 1) de aviso C4804 | Microsoft Docs"
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 08ca44f1d272207f287cca2d1e9bb147b0591fe1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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