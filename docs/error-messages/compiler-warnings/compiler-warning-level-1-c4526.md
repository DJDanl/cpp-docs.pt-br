---
title: Compilador (nível 1) de aviso C4526 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4526
dev_langs:
- C++
helpviewer_keywords:
- C4526
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c5a38d629d61e16b038701522d4bb27a4de7391d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282893"
---
# <a name="compiler-warning-level-1-c4526"></a>Compilador C4526 de aviso (nível 1)
'function': função membro static não pode substituir função virtual ' function'override virtual ignorada, função virtual será ocultada  
  
 A função de membro estático atende aos critérios para substituir a função virtual, o que torna a função de membro virtual e estáticos.  
  
 O código a seguir gera C4526:  
  
```  
// C4526.cpp  
// compile with: /W1 /c  
// C4526 expected  
struct myStruct1 {  
   virtual void __stdcall func( int ) = 0;  
};  
  
struct myStruct2: public myStruct1 {  
   static void __stdcall func( int );  
};  
```  
  
 Estas são as soluções possíveis:  
  
-   Se a função foi criada para substituir a função de classe base virtual, remova o especificador estático.  
  
-   Se a função foi criada para ser uma função de membro estático, renomeie-o para que ele não entra em conflito com a função virtual de classe base.