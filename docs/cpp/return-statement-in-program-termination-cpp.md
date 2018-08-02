---
title: Instrução de Return no término do programa (C++) | Microsoft Docs
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
ms.openlocfilehash: 6c08edff8237462cbc2c55dc5541e3da663ed0a3
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461107"
---
# <a name="return-statement-in-program-termination-c"></a>Instrução return no término do programa (C++)
Emitir uma **retornar** instrução from `main` é funcionalmente equivalente a chamar o `exit` função. Considere o exemplo a seguir:  
  
```cpp 
// return_statement.cpp  
#include <stdlib.h>  
int main()  
{  
    exit( 3 );  
    return 3;  
}  
```  
  
 O `exit` e **retornar** instruções no exemplo anterior são funcionalmente idênticas. No entanto, o C++ requer que funções que têm tipos de retorno diferente de **void** retornam um valor. O **retornar** instrução permite que você retorne um valor de `main`.  
  
## <a name="see-also"></a>Consulte também  
 [Término do programa](../cpp/program-termination.md)