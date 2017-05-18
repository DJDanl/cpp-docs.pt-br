---
title: "Compilador aviso (nível 4) C4208 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4208
dev_langs:
- C++
helpviewer_keywords:
- C4208
ms.assetid: 5cb0a36e-3fb5-422f-a5f9-e40b70776c27
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
ms.openlocfilehash: 6e59be220d8461563cde6ca22037460146e213a2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4208"></a>Compilador C4208 de aviso (nível 4)
extensão não padrão usada: delete [exp] - exp avaliadas mas ignorado  
  
 Com as extensões da Microsoft (/Ze), você pode excluir uma matriz usando um valor entre colchetes com o [operador delete](../../cpp/delete-operator-cpp.md). O valor será ignorado.  
  
```  
// C4208.cpp  
// compile with: /W4  
int main()  
{  
   int * MyArray = new int[18];  
   delete [18] MyArray;      // C4208  
   MyArray = new int[18];  
   delete [] MyArray;        // ok  
}  
```  
  
 Esses valores são inválidos em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
