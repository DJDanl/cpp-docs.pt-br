---
title: Compilador (nível 1) de aviso C4508 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4508
dev_langs:
- C++
helpviewer_keywords:
- C4508
ms.assetid: c05f113b-b789-4df0-a4ef-78bce4767021
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 53f152c2f3573e5f3bd7b8e9be0603ed6d3f11bb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4508"></a>Compilador C4508 de aviso (nível 1)
'function': função deve retornar um valor. presume-se que tipo de retorno 'void'  
  
 A função não tem nenhum tipo de retorno especificado. Nesse caso, C4430 também deve ser disparada, e o compilador implementa a correção relatada pelo C4430 (o valor padrão é int).  
  
 Para resolver este aviso, declare explicitamente o tipo de retorno de funções.  
  
 O exemplo a seguir gera C4508:  
  
```  
// C4508.cpp  
// compile with: /W1 /c  
#pragma warning (disable : 4430)  
func() {}   // C4508  
void func2() {}   // OK  
```