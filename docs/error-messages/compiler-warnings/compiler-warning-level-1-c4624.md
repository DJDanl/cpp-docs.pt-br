---
title: "Compilador aviso (nível 1) C4624 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4624
dev_langs:
- C++
helpviewer_keywords:
- C4624
ms.assetid: 14f61769-d92e-482b-9515-debd87b30a66
caps.latest.revision: 8
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f8bc4f6d803743a9419311a9e2e56445ee8f84ff
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4624"></a>Compilador C4624 de aviso (nível 1)
'derived class': destruidor foi definido implicitamente como excluído porque um destruidor de classe base está inacessível ou excluídos  
  
 Um destruidor não estava acessível ou excluídos em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de criar um objeto desse tipo na pilha causará um erro do compilador.  
  
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
