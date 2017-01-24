---
title: "Arquivos .Res como entrada de vinculador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .res como entrada de vinculador"
  - "vinculando [C++], arquivos de recurso"
  - "arquivos RES como entrada de vinculador"
  - "arquivos de recurso, vinculando"
ms.assetid: 9c37ab00-97df-4d9a-91cd-6bf132970683
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos .Res como entrada de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode especificar um arquivo de .res ao vincular um programa.  O arquivo de .res é criado pelo compilador \(RC\) do recurso.  O LINK converte automaticamente arquivos de .res a COFF.  A ferramenta de CVTRES.exe deve estar no mesmo diretório que LINK.exe ou em um diretório especificado na variável de ambiente PATH.  
  
## Consulte também  
 [Arquivos de entrada LINK](../../build/reference/link-input-files.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)