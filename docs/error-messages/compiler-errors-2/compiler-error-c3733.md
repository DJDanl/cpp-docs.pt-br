---
title: "Erro do Compilador C3733 | Microsoft Docs"
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
  - "C3733"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3733"
ms.assetid: 0cc1a9fe-1400-4be3-b35a-16435cba7a5a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3733
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“evento”: sintaxe inadequada para especificar um evento COM; você esqueceu o \_\_interface”? “  
  
 A sintaxe incorreta foi usada para um evento COM.  Para corrigir esse erro, altere o tipo de evento ou corrija a sintaxe para obedecer às regras de eventos COM.  
  
 O seguinte exemplo gera C3733:  
  
```  
#define _ATL_ATTRIBUTES 1  
#include "atlbase.h"  
#include "atlcom.h"  
  
[coclass, event_source(com), // change 'com' to 'native' to resolve  
uuid("00000000-0000-0000-0000-000000000001")]  
class A  
{  
   __event void func();   // C3733  
};  
  
int main()  
{  
}  
```