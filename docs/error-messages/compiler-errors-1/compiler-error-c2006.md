---
title: "Erro do Compilador C2006 | Microsoft Docs"
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
  - "C2006"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2006"
ms.assetid: caaed6f7-ceb9-4742-8820-d66657c0b04d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2006
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a política “” esperou um nome de arquivo, “encontrou o token”  
  
 As políticas como [\#include](../../preprocessor/hash-include-directive-c-cpp.md) ou [\#import](../Topic/%23import%20Directive%20\(C++\).md) exigem um nome de arquivo.  Para resolver o erro, verifique se *o token* é um nome de arquivo válido.  Além disso, coloque o nome de arquivo entre aspas duplas ou em colchetes angulares.  
  
 O seguinte exemplo gera C2006:  
  
```  
// C2006.cpp  
#include stdio.h   // C2006  
```  
  
 Solução possível:  
  
```  
// C2006b.cpp  
// compile with: /c  
#include <stdio.h>  
```