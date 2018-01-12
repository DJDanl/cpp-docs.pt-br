---
title: C3483 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3483
dev_langs: C++
helpviewer_keywords: C3483
ms.assetid: 18b3a2c5-dfc9-4661-9653-08a5798474cf
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9e2ea5c703e9617bd419a3e390f143c0defd7ca9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3483"></a>C3483 de erro do compilador
'var' já é parte da lista de captura de lambda  
  
 Você passou a mesma variável à lista de captura de uma expressão lambda mais de uma vez.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remova todas as instâncias adicionais da variável na lista de captura.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3483 porque a variável `n` aparece mais de uma vez na lista de captura da expressão lambda:  
  
```  
// C3483.cpp  
  
int main()  
{  
   int m = 6, n = 5;  
   [m,n,n] { return n + m; }(); // C3483  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)