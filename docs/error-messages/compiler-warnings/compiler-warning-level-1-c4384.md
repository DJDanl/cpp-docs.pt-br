---
title: Compilador (nível 1) de aviso C4384 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4384
dev_langs:
- C++
helpviewer_keywords:
- C4384
ms.assetid: fafa8eb2-cbfc-4edb-8b0f-511ff5d37ac0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 88d24436270156dc86ad074cf8fee8d0272e83c9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33278077"
---
# <a name="compiler-warning-level-1-c4384"></a>Compilador C4384 de aviso (nível 1)
\#pragma 'make_public' deve ser usada somente no escopo global  
  
 O [make_public](../../preprocessor/make-public.md) pragma foi aplicada corretamente.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4384.  
  
```  
// C4384.cpp  
// compile with: /c /W1  
namespace n {  
   #pragma make_public(N::C)   // C4384  
   namespace N {  
      class C {};  
   }  
}  
```