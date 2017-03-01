---
title: "Compilador aviso (nível 1) C4561 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4561
dev_langs:
- C++
helpviewer_keywords:
- C4561
ms.assetid: 3a10c12c-601b-4b6c-9861-331fd022e021
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 411eda983973e842f0e664cfb3e19028ef287f60
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4561"></a>Compilador C4561 de aviso (nível 1)
fastcall' incompatível com o ' / clr' opção: conversão em '\_stdcall '  
  
 O [fastcall](../../cpp/fastcall.md) convenção de chamada de função não pode ser usada com o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção de compilador. O compilador ignora as chamadas para `__fastcall`. Para corrigir esse aviso, remova as chamadas para **fastcall** ou compilar sem **/clr**.  
  
 O exemplo a seguir gera C4561:  
  
```  
// C4561.cpp  
// compile with: /clr /W1 /c  
// processor: x86  
void __fastcall Func(void *p);   // C4561, remove __fastcall to resolve  
```
