---
title: Instrução Return no término do programa (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- data types [C++], function return types
- function return types [C++], return statement
- return keyword [C++], syntax
ms.assetid: 66d002ab-5625-4b68-8446-71e1b8fcdbd8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 61d09c1b3aaea799c227686436486efa48fc7857
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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