---
title: "Compilador aviso (nível 1) C4508 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4508
dev_langs:
- C++
helpviewer_keywords:
- C4508
ms.assetid: c05f113b-b789-4df0-a4ef-78bce4767021
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
ms.openlocfilehash: a2d54a87565c3217168dc077f5aa79614fee080b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4508"></a>Compilador C4508 de aviso (nível 1)
'function': função deve retornar um valor. 'void' assumido de tipo de retorno  
  
 A função não tem nenhum tipo de retorno especificado. Nesse caso, C4430 também deve ser disparada, e o compilador implementa a correção relatada pelo C4430 (o valor padrão é int).  
  
 Para resolver esse aviso, declare explicitamente o tipo de retorno das funções.  
  
 O exemplo a seguir gera C4508:  
  
```  
// C4508.cpp  
// compile with: /W1 /c  
#pragma warning (disable : 4430)  
func() {}   // C4508  
void func2() {}   // OK  
```
