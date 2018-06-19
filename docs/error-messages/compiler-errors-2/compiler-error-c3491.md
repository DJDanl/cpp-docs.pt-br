---
title: C3491 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3491
dev_langs:
- C++
helpviewer_keywords:
- C3491
ms.assetid: 7f0e71b2-46a0-4d25-bd09-6158a280f509
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6bd856f50f3528b3895e4495215b2e479d8a424b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33257287"
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