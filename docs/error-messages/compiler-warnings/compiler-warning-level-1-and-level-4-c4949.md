---
title: "Aviso C4949 (compilador) (n&#237;vel 1 e n&#237;vel 4) | Microsoft Docs"
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
  - "C4949"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4949"
ms.assetid: 34f45a05-c115-49cb-9f67-0bd4f0735d9b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso C4949 (compilador) (n&#237;vel 1 e n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

os pragmas gerenciados” e “não” gerenciado são significativos somente quando criado com “\/clr \[: opção\]”  
  
 O compilador ignora [gerenciado](../../preprocessor/managed-unmanaged.md) e os pragmas não gerenciados se o código\-fonte não é criado com [\/clr](../../build/reference/clr-common-language-runtime-compilation.md).  Esse aviso é informativo.  
  
 O seguinte exemplo gera C4949:  
  
```  
// C4949.cpp  
// compile with: /LD /W1  
#pragma managed   // C4949  
```  
  
 Quando **\#pragma unmanaged** for usado sem **\/clr**, C4949 é um nível 4 que a direita.  
  
 O seguinte exemplo gera C4949:  
  
```  
// C4949b.cpp  
// compile with: /LD /W4  
#pragma unmanaged   // C4949  
```