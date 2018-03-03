---
title: "Compilador (nível 1) de aviso C4526 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4526
dev_langs:
- C++
helpviewer_keywords:
- C4526
ms.assetid: 490f8916-5fdc-4cad-b412-76c3382a5976
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a74d7d2e2c745a4c8e29736c1e3a7fc38892d5f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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