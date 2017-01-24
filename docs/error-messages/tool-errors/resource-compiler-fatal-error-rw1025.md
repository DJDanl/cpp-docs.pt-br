---
title: "Erro fatal RW1025 (compilador de recurso) | Microsoft Docs"
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
  - "RW1025"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RW1025"
ms.assetid: 561a02af-e7e0-442a-8ad3-a00b2ca1b62e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal RW1025 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fora de memória muito do heap  
  
 Verificar o software de memória residente que pode demorar muito acima de espaço.  Use o programa de CHKDSK para descobrir a quantidade de memória você tiver.  
  
 Se você estiver criando um arquivo grande de recurso, divida o script de recursos em dois arquivos.  Depois de criar dois arquivos de .res, use a linha de comando MS\-DOS para adicioná\-los juntos:  
  
```  
copy first.res /b + second.res /b full.res  
```