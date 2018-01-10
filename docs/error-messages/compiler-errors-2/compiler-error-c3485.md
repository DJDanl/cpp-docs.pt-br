---
title: C3485 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3485
dev_langs: C++
helpviewer_keywords: C3485
ms.assetid: d67536f9-67a1-4ad9-9a94-d8bbbca3d0dc
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7fb872161cc82878c7809e6ebcae901db0ba772f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3485"></a>C3485 de erro do compilador
uma definição de lambda não pode ter cv-qualifiers  
  
 Não é possível usar um `const` ou `volatile` qualificador como parte da definição de uma expressão lambda.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `const` ou `volatile` qualificador da definição da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3485 porque ele usa o `const` qualificador como parte da definição de uma expressão lambda:  
  
```  
// C3485.cpp  
  
int main()  
{  
   auto x = []() const mutable {}; // C3485  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)