---
title: C3489 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3489
dev_langs:
- C++
helpviewer_keywords:
- C3489
ms.assetid: 47b58d69-459d-4499-abc7-5f0b9303d773
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fd620c969f89b1889384fe3f4d7f899957ae620b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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