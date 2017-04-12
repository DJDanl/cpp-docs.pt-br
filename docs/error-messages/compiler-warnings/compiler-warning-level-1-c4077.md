---
title: "Compilador aviso (nível 1) C4077 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4077
dev_langs:
- C++
helpviewer_keywords:
- C4077
ms.assetid: c2d28805-b33f-41ad-afba-33b3f788c649
caps.latest.revision: 7
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0e31028ad61a03caa2cf97a4b17c78225e386adf
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4077"></a>Compilador C4077 de aviso (nível 1)
opção de check_stack desconhecida  
  
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
