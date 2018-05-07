---
title: Compilador (nível 1) de aviso C4722 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4722
dev_langs:
- C++
helpviewer_keywords:
- C4722
ms.assetid: d8660710-f67b-4f59-a5fd-59259475529e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 143a902a4d05ab73df96f3f8ab35f52dab244df4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4722"></a>Compilador C4722 de aviso (nível 1)
'function': destruidor nunca retorna, possível perda de memória  
  
 Encerra o fluxo de controle em um destruidor. O thread ou todo o programa será encerrado e não podem ser liberados recursos alocados.  Além disso, se um destruidor será chamado de desenrolamento de pilha durante o processamento de exceção, o comportamento do executável é indefinido.  
  
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