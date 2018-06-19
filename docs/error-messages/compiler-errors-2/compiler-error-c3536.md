---
title: C3536 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3536
dev_langs:
- C++
helpviewer_keywords:
- C3536
ms.assetid: 8d866075-866b-49eb-9979-ee27b308f7e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0f88e656b0d63b6a7a4d60ace2f4cd5e2347d188
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33250281"
---
# <a name="compiler-error-c3536"></a>C3536 de erro do compilador
'symbol': não pode ser usado antes de ser inicializada  
  
 O símbolo indicado não pode ser usado antes de ser inicializada. Na prática, isso significa que uma variável não pode ser usada para se inicializar.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não inicialize uma variável com ele mesmo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3536 porque cada variável é inicializada com ele mesmo.  
  
```  
// C3536.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto a = a;     //C3536  
   auto b = &b;    //C3536  
   auto c = c + 1; //C3536  
   auto* d = &d;   //C3536  
   auto& e = e;    //C3536  
   return 0;  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavra-chave auto](../../cpp/auto-keyword.md)