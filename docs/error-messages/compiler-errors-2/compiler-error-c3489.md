---
title: C3489 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: 173f9294db52db21f4b6205be7b6ae3f4c9bd329
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3489"></a>C3489 de erro do compilador
'var' é necessário quando o modo de captura padrão é por valor  
  
 Quando você especifica o modo de captura padrão para uma expressão lambda é por valor, você não pode passar uma variável pelo valor para a cláusula capture dessa expressão.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Não passar explicitamente a variável para a cláusula de captura, ou  
  
-   Não especifique por valor como o modo de captura padrão, ou  
  
-   Especifique por referência como o modo de captura padrão, ou  
  
-   A variável é passada por referência para a cláusula de captura. (Isso pode mudar o comportamento da expressão lambda).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera a variável C3489 `n` é exibida pelo valor na cláusula de captura de uma expressão lambda cujo modo padrão é por valor:  
  
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
