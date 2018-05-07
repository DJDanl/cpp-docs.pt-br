---
title: Erro fatal C1094 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1094
dev_langs:
- C++
helpviewer_keywords:
- C1094
ms.assetid: 9e1193b2-cb95-44f9-bf6f-019e0d41dd97
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e227cbfaf46eb7616ae63eda02816e7d274ab85b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1094"></a>Erro fatal C1094
'-Zmval1': opção de linha de comando é inconsistente com o valor usado para compilar cabeçalho pré-compilado ('-Zmval2')  
  
 O valor que é passado para [/Yc](../../build/reference/yc-create-precompiled-header-file.md) deve ser o mesmo valor que é passado para [/Yu](../../build/reference/yu-use-precompiled-header-file.md) (**/Zm** valores devem ser o mesmo em todas as compilações que usam ou criar o mesmo pré-compilados arquivo de cabeçalho).  
  
 O exemplo a seguir gera C1094:  
  
```  
// C1094.h  
int func1();  
```  
  
 E, em seguida,  
  
```  
// C1094.cpp  
// compile with: /Yc"C1094.h" /Zm200  
int u;  
int main() {  
   int sd = 32;  
}  
#include "C1094.h"  
```  
  
 E, em seguida,  
  
```  
// C1094b.cpp  
// compile with: /Yu"C1094.h" /Zm300 /c  
#include "C1094.h"   // C1094 compile with /Zm200  
void Test() {}  
```