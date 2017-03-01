---
title: "Compilador aviso (nível 3) C4823 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4823
dev_langs:
- C++
helpviewer_keywords:
- C4823
ms.assetid: 8a77560d-dcea-4cae-aebb-8ebf1b4cef85
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: ea03723f9ccae2348a47ae4894097f5cd9f8b5a1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4823"></a>Compilador C4823 de aviso (nível 3)
'function': usa ponteiros de fixação de desenrolamento mas semântica não está habilitada. Considere o uso de /EHa  
  
Para excluir um objeto no heap gerenciado apontado por um ponteiro de fixação declarado em um escopo de bloco, o compilador simula o comportamento de destruidores de classes locais, "simulando" o ponteiro de fixação tem um destruidor que anula o ponteiro. Para habilitar uma chamada para um destruidor após lançar uma exceção, você deve habilitar desenrolamento de objeto, que pode ser feito usando [/EHsc](../../build/reference/eh-exception-handling-model.md).  
  
Você pode também manualmente desafixar o objeto e ignorar o aviso.  
  
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

