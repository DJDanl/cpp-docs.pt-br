---
title: Compilador aviso (nível 3) C4823 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4823
dev_langs:
- C++
helpviewer_keywords:
- C4823
ms.assetid: 8a77560d-dcea-4cae-aebb-8ebf1b4cef85
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c29499a82601dcf653ff2f003441935f1d6841a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4823"></a>Compilador C4823 de aviso (nível 3)
'function': usa ponteiros de fixação mas desenrolar semântica não está habilitada. Considere o uso de /EHa  
  
Para remover um objeto no heap gerenciado apontada para um ponteiro de fixação declarado em um escopo de bloco, o compilador simula o comportamento de destruidores de classes locais, "simulando" o ponteiro de fixação tenha um destruidor que anula o ponteiro. Para habilitar uma chamada para um destruidor após gerar uma exceção, você deve habilitar liberação de objeto, que pode ser feito usando [/EHsc](../../build/reference/eh-exception-handling-model.md).  
  
Manualmente, você pode remover o objeto e ignorar o aviso.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C4823.  
  
```  
// C4823.cpp  
// compile with: /clr /W3 /EHa-  
using namespace System;  
  
ref struct G {  
   int m;  
};  
  
void f(G ^ pG) {  
   try {  
      pin_ptr<int> p = &pG->m;  
      // manually unpin, ignore warning  
      // p = nullptr;  
      throw gcnew Exception;  
   }  
   catch(Exception ^) {}  
}   // C4823 warning  
  
int main() {  
   f( gcnew G );  
}  
```  
