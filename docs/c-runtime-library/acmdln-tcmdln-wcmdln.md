---
title: "_acmdln, _tcmdln, _wcmdln | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_wcmdln"
  - "_acmdln"
apilocation: 
  - "msvcrt.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_acmdln"
  - "acmdln"
  - "_wcmdln"
  - "wcmdln"
  - "_tcmdln"
  - "tcmdln"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Variável global _acmdln"
  - "Variável global _tcmdln"
  - "Variável global _wcmdln"
  - "variável global acmdln"
  - "variável global tcmdln"
  - "variável global wcmdln"
ms.assetid: 4fc0a6a0-3f93-420a-a19f-5276061ba539
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _acmdln, _tcmdln, _wcmdln
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Variável interna de CRT global.  A linha de comando.  
  
## Sintaxe  
  
```  
char * _acmdln; wchar_t * _wcmdln;  #ifdef WPRFLAG    #define _tcmdln _wcmdln #else    #define _tcmdln _acmdln  
```  
  
## Comentários  
 Essas variáveis internas de CRT armazenam toda a linha de comando.  Elas ficam expostas nos símbolos exportados para o CRT, mas não devem ser usadas no seu código.  `_acmdln` armazena os dados como uma cadeia de caracteres.  `_wcmdln` armazena os dados como uma cadeia de caracteres larga.  `_tcmdln` pode ser definido como `_acmdln` ou  `_wcmdln`, de acordo com sua finalidade.  
  
## Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)