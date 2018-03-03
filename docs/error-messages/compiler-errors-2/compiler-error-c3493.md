---
title: C3493 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3493
dev_langs:
- C++
helpviewer_keywords:
- C3493
ms.assetid: 734b4257-12a3-436f-8488-c8c55ec81634
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8094b3b03f06dcc799b6bdfeea2b57399f92b852
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3493"></a>C3493 de erro do compilador
'var' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado  
  
 A captura de expressão lambda vazio, `[]`, especifica que a expressão lambda não não explicitamente ou implicitamente capturar todas as variáveis.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Fornecer um modo de captura padrão, ou  
  
-   Capture explicitamente uma ou mais variáveis.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3493 porque ela modifica uma variável externa, mas Especifica a cláusula de captura vazia:  
  
```  
// C3493a.cpp  
  
int main()  
{  
   int m = 55;  
   [](int n) { m = n; }(99); // C3493  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir elimina C3493 especificando por referência como o modo de captura padrão.  
  
```  
// C3493b.cpp  
  
int main()  
{  
   int m = 55;  
   [&](int n) { m = n; }(99);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)