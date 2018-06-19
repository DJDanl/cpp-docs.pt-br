---
title: Compilador (nível 1) de aviso C4731 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4731
dev_langs:
- C++
helpviewer_keywords:
- C4731
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 31bdf972ef3791760469251dc4d0bf19627bded2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33283875"
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