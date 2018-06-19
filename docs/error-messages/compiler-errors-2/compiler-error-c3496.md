---
title: C3496 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3496
dev_langs:
- C++
helpviewer_keywords:
- C3496
ms.assetid: e19885f2-677f-4c1e-bc69-e35852262dc3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dbc128c1e9a80c61ad42514827bbf8d47b693e84
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33256981"
---
# <a name="compiler-error-c3496"></a>C3496 de erro do compilador
'this' sempre é capturado por valor: '&' ignorado  
  
 Não é possível capturar a `this` ponteiro por referência.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Capturar o `this` ponteiro por valor.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3496 porque uma referência para o `this` ponteiro aparece na lista de captura de uma expressão lambda:  
  
```  
// C3496.cpp  
// compile with: /c  
  
class C  
{  
   void f()  
   {  
      [&this] {}(); // C3496  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)