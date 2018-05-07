---
title: Compilador (nível 1) de aviso C4077 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4077
dev_langs:
- C++
helpviewer_keywords:
- C4077
ms.assetid: c2d28805-b33f-41ad-afba-33b3f788c649
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a558ff0ae3c33f25c4f07dc642607fd8a840c70c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4077"></a>Compilador C4077 de aviso (nível 1)
opção de check_stack desconhecido  
  
 A forma antiga de **check_stack** pragma é usado com um argumento desconhecido. O argumento deve ser `+`, `-`, `(on)`, `(off)`, ou vazio.  
  
 O compilador ignora o pragma e deixa a verificação da pilha inalterado.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4077.cpp  
// compile with: /W1 /LD  
#pragma check_stack yes // C4077  
#pragma check_stack +    // Correct old form  
#pragma check_stack (on) // Correct new form  
```