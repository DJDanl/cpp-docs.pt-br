---
title: C3491 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3491
dev_langs:
- C++
helpviewer_keywords:
- C3491
ms.assetid: 7f0e71b2-46a0-4d25-bd09-6158a280f509
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 58458a1ab0b67eb4fa6d38d0be2fb38f6d7496eb
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3491"></a>C3491 de erro do compilador
'var': uma captura por valor não pode ser modificada em um lambda não mutável  
  
 Uma expressão lambda não mutável não é possível modificar o valor de uma variável que é capturado por valor.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Declarar a expressão lambda com o `mutable` palavra-chave, ou  
  
-   A variável é passada por referência à lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3491 porque o corpo de uma expressão lambda não mutável modifica a variável de captura `m`:  
  
```  
// C3491a.cpp  
  
int main()  
{  
   int m = 55;  
   [m](int n) { m = n; }(99); // C3491  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir elimina C3491 declarando a expressão lambda com o `mutable` palavra-chave:  
  
```  
// C3491b.cpp  
  
int main()  
{  
   int m = 55;  
   [m](int n) mutable { m = n; }(99);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
