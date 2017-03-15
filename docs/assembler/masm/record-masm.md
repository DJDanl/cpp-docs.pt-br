---
title: "RECORD (MASM) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "RECORD"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RECORD directive"
ms.assetid: c83db394-0fe3-468f-813f-13302cdc862d
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# RECORD (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Declara um tipo de registro que consiste de campos especificados.  *nome do campo* nomeia o campo,  *largura* Especifica o número de bits, e  *expressão* fornece seu valor inicial.  
  
## Sintaxe  
  
```  
  
   recordname RECORD fieldname:width [[= expression]]   
[[, fieldname:width [[= expression]]]]...  
```  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)