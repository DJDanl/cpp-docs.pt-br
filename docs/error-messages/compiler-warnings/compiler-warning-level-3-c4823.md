---
title: "Compilador aviso (nível 3) C4823 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4823
dev_langs: C++
helpviewer_keywords: C4823
ms.assetid: 8a77560d-dcea-4cae-aebb-8ebf1b4cef85
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 18e041bd9a013779a37dc2460b8e1913b69d734b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
