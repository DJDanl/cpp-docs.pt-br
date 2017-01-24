---
title: "Aviso D9027 (linha de comando) | Microsoft Docs"
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
  - "D9027"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "D9027"
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso D9027 (linha de comando)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

nome '\<do arquivo de\>' origem ignorado  
  
 CL.exe ignorado o arquivo de fonte de entrada.  
  
 Esse aviso pode ser causado por um espaço entre a opção \/Fo e um nome de arquivo de saída em uma linha de comando com a opção do \/c.  Por exemplo:  
  
```  
cl /c /Fo output.obj input.c   
```  
  
 Como há um espaço entre \/Fo e `output.obj,` CL.exe usa `output.obj` como o nome do arquivo de entrada.  Para corrigir o problema, remova o espaço:  
  
```  
cl /c /Fooutput.obj input.c   
```