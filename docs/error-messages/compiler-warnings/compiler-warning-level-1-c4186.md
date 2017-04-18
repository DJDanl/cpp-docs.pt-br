---
title: "Compilador aviso (nível 1) C4186 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4186
dev_langs:
- C++
helpviewer_keywords:
- C4186
ms.assetid: caf3f7d8-f305-426b-8d4e-2b96f5c269ea
caps.latest.revision: 8
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
ms.openlocfilehash: 9f3f1610f89844e73cb57916b9fb260301125b6f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4186"></a>Compilador C4186 de aviso (nível 1)
\#atributo de importação 'attribute' requer argumentos de contagem; ignorado  
  
 Um `#import` atributo tem um número incorreto de argumentos.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4186.cpp  
// compile with: /W1 /c  
#import "stdole2.tlb" no_namespace("abc") rename("a","b","c")  // C4186  
```  
  
 O `no_namespace` atributo não utiliza argumentos. O **Renomear** atributo leva apenas dois argumentos.
