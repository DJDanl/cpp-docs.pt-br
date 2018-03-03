---
title: "Compilador (nível 1) de aviso C4731 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4731
dev_langs:
- C++
helpviewer_keywords:
- C4731
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9d8c59a22166c3f4f44db3bea43e241a2199009d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4731"></a>Compilador C4731 de aviso (nível 1)
'ponteiro': 'Registrar' modificado por código de assembly embutido de registro de ponteiro de quadro  
  
 Um registro de ponteiro de quadro foi modificado. Você deve salvar e restaurar o registro em seu assembly bloco ou quadro variável embutida (local ou parâmetro, dependendo do registro modificado), ou seu código pode não funcionar corretamente.  
  
 O exemplo a seguir gera C4731:  
  
```  
// C4731.cpp  
// compile with: /W1 /LD  
// processor: x86  
// C4731 expected  
void bad(int p) {  
   __asm  
   {  
      mov ebp, 1  
   }  
  
   if (p == 1)  
   {  
      // ...  
   }  
}  
```  
  
 EBP é o ponteiro de quadro (FPO não é permitido) e ele está sendo modificado. Quando `p` posterior referenciado, ela é referenciada relativo a `EBP`. Mas `EBP` foi substituído pelo código, para que o programa não irá funcionar corretamente e ainda pode falhar.