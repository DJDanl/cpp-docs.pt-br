---
title: "Compilador aviso (nível 1) C4215 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4215
dev_langs:
- C++
helpviewer_keywords:
- C4215
ms.assetid: f2aab64d-1bab-4f75-95ee-89e1263047b1
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b6a0df081a7fd85ea2e69bdd29158999dd119a2b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4215"></a>Compilador C4215 de aviso (nível 1)
extensão não padrão usada : long float  
  
 Tratam as extensões padrão da Microsoft (/Ze) **longos flutuantes** como **duplo**. Compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), não. Use **duplo** para manter a compatibilidade.  
  
 O exemplo a seguir gera C4215:  
  
```  
// C4215.cpp  
// compile with: /W1 /LD  
long float a;   // C4215  
  
// use the line below to resolve the warning  
// double a;  
```
