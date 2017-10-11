---
title: C3488 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3488
dev_langs:
- C++
helpviewer_keywords:
- C3488
ms.assetid: 0a6fcd76-dd3b-48d7-abb3-22eccda96034
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5006ca7cb3477730a4234a8e058acdae520a59c8
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3488"></a>C3488 de erro do compilador
'var' não é permitida quando o modo de captura padrão é por referência  
  
 Quando você especificar o modo de captura padrão para uma expressão lambda é por referência, você não pode passar uma variável por referência à cláusula captura dessa expressão.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Não passar explicitamente a variável para a cláusula de captura, ou  
  
-   Não especifique por referência como o modo de captura padrão, ou  
  
-   Especifique por valor como o modo de captura padrão, ou  
  
-   Passe a variável pelo valor para a cláusula de captura. (Isso pode mudar o comportamento da expressão lambda.)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3488 porque uma referência à variável `n` aparece na cláusula de captura de uma expressão lambda cujo padrão é por referência:  
  
```  
// C3488a.cpp  
  
int main()  
{  
   int n = 5;  
   [&, &n]() { return n; } (); // C3488  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra quatro possíveis resoluções para C3488:  
  
```  
// C3488b.cpp  
  
int main()  
{  
   int n = 5;  
  
   // Possible resolution 1:  
   // Do not explicitly pass &n to the capture clause.  
   [&]() { return n; } ();  
  
   // Possible resolution 2:  
   // Do not specify by-reference as the default capture mode.  
   [&n]() { return n; } ();  
  
   // Possible resolution 3:  
   // Specify by-value as the default capture mode.  
   [=, &n]() { return n; } ();  
  
   // Possible resolution 4:  
   // Pass n by value to the capture clause.  
   [n]() { return n; } ();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
