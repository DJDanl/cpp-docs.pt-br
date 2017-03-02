---
title: Erro fatal C1094 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: a8833f090dac44e080874ac90d7f40012397b99f
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1094"></a>Erro fatal C1094
'-Zmval1': opção de linha de comando é inconsistente com o valor usado para criar o cabeçalho pré-compilado ('-Zmval2')  
  
 O valor é passado para [/Yc](../../build/reference/yc-create-precompiled-header-file.md) deve ser o mesmo valor que é passado para [/Yu](../../build/reference/yu-use-precompiled-header-file.md) (**/Zm** valores devem ser iguais em todas as compilações que usam ou criar o mesmo arquivo de cabeçalho pré-compilado).  
  
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
