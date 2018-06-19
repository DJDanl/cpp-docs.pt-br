---
title: Compilador (nível 1) de aviso C4033 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4033
dev_langs:
- C++
helpviewer_keywords:
- C4033
ms.assetid: 189a9ec3-ff6d-49dd-b9b2-530b28bbb7c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c5df24b6b86bfc07c36b84cd6094515f9aa31f0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33275974"
---
# <a name="compiler-warning-level-1-c4033"></a>Compilador C4033 de aviso (nível 1)
'function' deve retornar um valor  
  
 A função não retorna um valor. Um valor indefinido será retornado.  
  
 Funções que usam `return` sem um valor de retorno deve ser declarado como tipo `void`.  
  
 Esse erro é para código da linguagem C.  
  
 O exemplo a seguir gera C4033:  
  
```  
// C4033.c  
// compile with: /W1 /LD  
int test_1(int x)   // C4033 expected  
{  
   if (x)  
   {  
      return;   // C4033  
   }  
}  
```