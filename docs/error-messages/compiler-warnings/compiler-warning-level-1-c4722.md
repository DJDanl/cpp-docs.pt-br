---
title: "Compilador aviso (nível 1) C4722 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4722
dev_langs:
- C++
helpviewer_keywords:
- C4722
ms.assetid: d8660710-f67b-4f59-a5fd-59259475529e
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4f479a8bfecb7b1b61878589150e3320e12a222a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4722"></a>Compilador C4722 de aviso (nível 1)
'function': destruidor nunca retorna, potencial perda de memória  
  
 Encerra o fluxo de controle em um destruidor. O thread ou todo o programa será encerrado e recursos alocados não podem ser liberados.  Além disso, se um destruidor será chamado para desenrolamento de pilha durante o processamento de exceção, o comportamento do executável é indefinido.  
  
 Para resolver, remova a chamada de função que faz com que o destruidor não retornar.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4722:  
  
```  
// C4722.cpp  
// compile with: /O1 /W1 /c  
#include <stdlib.h>  
class C {  
public:  
   C();  
   ~C() { exit(1); };   // C4722  
};  
  
extern void func (C*);  
  
void Test(){  
   C x;  
   func(&x);  
   // control will not leave Test because destructor will exit  
}  
```
