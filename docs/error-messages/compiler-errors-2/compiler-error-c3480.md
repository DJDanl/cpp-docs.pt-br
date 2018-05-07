---
title: C3480 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3480
dev_langs:
- C++
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 673eff58b09fe1f2bbfe8a7629594399e8ca6b22
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3480"></a>C3480 de erro do compilador
'var': uma variável de captura de lambda deve ser de um escopo de função delimitadora  
  
 A variável de captura de lambda não é de um escopo delimitador de função.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remova a variável na lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3480 porque a variável `global` não está em um escopo delimitador de função:  
  
```  
// C3480a.cpp  
  
int global = 0;  
int main()  
{  
   [&global] { global = 5; }(); // C3480  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir elimina C3480, removendo a variável `global` na lista da expressão lambda captura:  
  
```  
// C3480b.cpp  
  
int global = 0;  
int main()  
{  
   [] { global = 5; }();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)