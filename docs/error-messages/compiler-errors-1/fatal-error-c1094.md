---
title: Erro fatal C1094 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1094
dev_langs:
- C++
helpviewer_keywords:
- C1094
ms.assetid: 9e1193b2-cb95-44f9-bf6f-019e0d41dd97
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 032eee2edf1570e46359d22379843157c6889b4b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
