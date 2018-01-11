---
title: "Instrução Return no término do programa (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- data types [C++], function return types
- function return types [C++], return statement
- return keyword [C++], syntax
ms.assetid: 66d002ab-5625-4b68-8446-71e1b8fcdbd8
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9a9e97c0ee52094cd3f0ccbb36c0da8b3b04c630
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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