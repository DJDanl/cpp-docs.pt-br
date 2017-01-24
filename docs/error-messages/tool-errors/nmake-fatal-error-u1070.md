---
title: "Erro fatal U1070 (NMAKE) | Microsoft Docs"
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
  - "U1070"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1070"
ms.assetid: 8639fc39-b4b1-48f5-ac91-0e9fb61680fd
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1070 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

ciclo na definição macro “macroname”  
  
 A definição macro determinada continha uma macro cuja definição contém a macro determinado.  As definições macro circulares são inválidos.  
  
## Exemplo  
 As seguintes definições macro  
  
```  
ONE=$(TWO)  
TWO=$(ONE)  
```  
  
 fazer o seguinte erro:  
  
```  
cycle in macro definition 'TWO'  
```