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
ms.openlocfilehash: eb594eb10e8068d5f5b3ed124d5e77b48ced728e
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942116"
---
# <a name="return-statement-in-program-termination-c"></a>Instrução return no término do programa (C++)
Emitir uma `return` instrução from **principal** é funcionalmente equivalente a chamar o **sair** função. Considere o exemplo a seguir:  
  
```cpp 
// return_statement.cpp  
#include <stdlib.h>  
int main()  
{  
    exit( 3 );  
    return 3;  
}  
```  
  
 O **saia** e **retornar** instruções no exemplo anterior são funcionalmente idênticas. No entanto, o C++ requer que funções que têm tipos de retorno diferente de **void** retornam um valor. O **retornar** instrução permite que você retorne um valor de `main`.  
  
## <a name="see-also"></a>Consulte também  
 [Término do programa](../cpp/program-termination.md)