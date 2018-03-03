---
title: "Compilador (nível 1) de aviso C4077 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4077
dev_langs:
- C++
helpviewer_keywords:
- C4077
ms.assetid: c2d28805-b33f-41ad-afba-33b3f788c649
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2301e1ee077adee35706a4f80d8b2a738743851e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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