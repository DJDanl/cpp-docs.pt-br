---
title: "Erro fatal C1094 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1094"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1094"
ms.assetid: 9e1193b2-cb95-44f9-bf6f-019e0d41dd97
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1094
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Zmval1 “\-”: a opção de linha de comando é inconsistente com o valor usado para criar o cabeçalho pré\-compilado \(“\-” Zmval2\)  
  
 O valor que é passado para [\/Yc](../../build/reference/yc-create-precompiled-header-file.md) deve ser igual ao valor passado para [\/Yu](../../build/reference/yu-use-precompiled-header-file.md) \(valores de**\/Zm** deve ser o mesmo em todas as compilações que usam ou criar o mesmo arquivo de cabeçalho pré\-compilado\).  
  
 O seguinte exemplo gera C1094:  
  
```  
// C1094.h  
int func1();  
```  
  
 Em seguida, e  
  
```  
// C1094.cpp  
// compile with: /Yc"C1094.h" /Zm200  
int u;  
int main() {  
   int sd = 32;  
}  
#include "C1094.h"  
```  
  
 Em seguida, e  
  
```  
// C1094b.cpp  
// compile with: /Yu"C1094.h" /Zm300 /c  
#include "C1094.h"   // C1094 compile with /Zm200  
void Test() {}  
```