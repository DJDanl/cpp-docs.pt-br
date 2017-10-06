---
title: "Instrução Return no término do programa (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- data types [C++], function return types
- function return types [C++], return statement
- return keyword [C++], syntax
ms.assetid: 66d002ab-5625-4b68-8446-71e1b8fcdbd8
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: f5ba078ef364a046a9e635d8b2632558e426f4b8
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="return-statement-in-program-termination-c"></a>Instrução return no término do programa (C++)
Emitir um `return` instrução do **principal** é funcionalmente equivalente a chamar o **sair** função. Considere o exemplo a seguir:  
  
```  
// return_statement.cpp  
#include <stdlib.h>  
int main()  
{  
    exit( 3 );  
    return 3;  
}  
```  
  
 O **sair** e `return` instruções no exemplo anterior são funcionalmente idênticas. No entanto, o C++ requer que as funções que têm tipos de retorno diferentes de `void` retornem um valor. O `return` instrução permite que você retorne um valor de **principal**.  
  
## <a name="see-also"></a>Consulte também  
 [Término do programa](../cpp/program-termination.md)
