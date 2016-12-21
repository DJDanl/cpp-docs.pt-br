---
title: "Erro fatal U1051 (NMAKE) | Microsoft Docs"
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
  - "U1051"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1051"
ms.assetid: fede5cd5-dac3-47b7-b86d-e1acfb78699f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1051 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

sem memória  
  
 NMAKE ficou sem memória, incluindo memória virtual, porque o makefile era muito grande ou complexo.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Liberar espaço no disco.  
  
2.  Aumente o tamanho do arquivo de paginação do Windows NT ou arquivo de permuta do windows.  
  
3.  Se apenas parte do makefile está sendo usada, divida o makefile em arquivos separados ou use **\!IF** que eles políticas para limitar a quantidade que NMAKE deve processar.  As políticas de **\!IF** incluem **\!IF**, `!IFDEF`, **\!IFNDEF**, **\!ELSE IF**, **\!ELSE** `IFDEF`, e **\!ELSE** `IFNDEF`.