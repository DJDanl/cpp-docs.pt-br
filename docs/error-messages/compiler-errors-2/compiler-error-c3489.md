---
title: C3489 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3489
dev_langs:
- C++
helpviewer_keywords:
- C3489
ms.assetid: 47b58d69-459d-4499-abc7-5f0b9303d773
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 4605b0b688cc879f68224442e7df5571cb8d2f7d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3489"></a>C3489 de erro do compilador
'var' é necessária quando o modo de captura padrão é por valor  
  
 Quando você especificar o modo de captura padrão para uma expressão lambda é por valor, você não pode passar uma variável pelo valor para a cláusula de captura dessa expressão.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Não passar explicitamente a variável para a cláusula de captura, ou  
  
-   Não especifique por valor como o modo de captura padrão, ou  
  
-   Especifique por referência como o modo de captura padrão, ou  
  
-   A variável é passada por referência para a cláusula de captura. (Isso pode mudar o comportamento da expressão lambda.)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3489 variável `n` aparece pelo valor na cláusula de captura de uma expressão lambda cujo padrão é por valor:  
  
```  
// C3489a.cpp  
  
int main()  
{  
   int n = 5;  
   [=, n]() { return n; } (); // C3489  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra quatro possíveis resoluções para C3489:  
  
```  
// C3489b.cpp  
  
int main()  
{  
   int n = 5;  
  
   // Possible resolution 1:  
   // Do not explicitly pass n to the capture clause.  
   [=]() { return n; } ();  
  
   // Possible resolution 2:  
   // Do not specify by-value as the default capture mode.  
   [n]() { return n; } ();  
  
   // Possible resolution 3:  
   // Specify by-reference as the default capture mode.  
   [&, n]() { return n; } ();  
  
   // Possible resolution 4:  
   // Pass n by reference to the capture clause.  
   [&n]() { return n; } ();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
