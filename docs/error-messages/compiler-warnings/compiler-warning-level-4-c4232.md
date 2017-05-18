---
title: "Compilador aviso (nível 4) C4232 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4232
dev_langs:
- C++
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 349ea8eb0612d9f6a1f8035a1395b950cb5403af
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4232"></a>Compilador C4232 de aviso (nível 4)
extensão não padrão usada: 'identifier': endereço do dllimport 'dllimport' não é estático, não a garantia de identidade  
  
 Em extensões da Microsoft (/Ze), você pode fornecer um valor não estático como o endereço de uma função declarada com o **dllimport** modificador. Em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), isso causará um erro.  
  
 O exemplo a seguir gera C4232:  
  
```  
// C4232.c  
// compile with: /W4 /Ze /c  
int __declspec(dllimport) f();  
int (*pfunc)() = &f;   // C4232  
```
