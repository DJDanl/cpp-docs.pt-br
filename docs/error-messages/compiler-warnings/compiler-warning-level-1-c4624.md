---
title: Compilador (nível 1) de aviso C4624 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4624
dev_langs:
- C++
helpviewer_keywords:
- C4624
ms.assetid: 14f61769-d92e-482b-9515-debd87b30a66
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8d11bc5c8b5034fa305a22ba893c62faff18cc38
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4624"></a>Compilador C4624 de aviso (nível 1)
'classe derivada': destrutor foi implicitamente definido como excluído porque um destruidor de classe base é inacessível ou excluídos  
  
 Um destruidor não estava acessível ou excluídas em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de criar um objeto deste tipo na pilha causará um erro do compilador.  
  
 O exemplo a seguir gera C4624 e mostra como corrigi-lo:  
  
```  
// C4624.cpp  
// compile with: /W1 /c  
class B {  
// Uncomment the following line to fix.  
// public:  
   ~B();  
};  
  
class D : public B {};   // C4624 B's destructor not public  
```