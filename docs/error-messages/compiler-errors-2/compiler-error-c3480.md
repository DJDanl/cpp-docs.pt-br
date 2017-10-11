---
title: C3480 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3480
dev_langs:
- C++
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d84314d20ea00e880981e418c2b5b11008f74229
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

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
