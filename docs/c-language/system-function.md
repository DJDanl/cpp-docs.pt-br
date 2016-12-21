---
title: "Fun&#231;&#227;o system | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "Função system"
ms.assetid: 0786ccdc-20cd-4d96-b3d8-3230507c3066
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o system
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 4.10.4.5** O conteúdo e o modo de execução de cadeia de caracteres pela função **system**  
  
 A função **system** executa um comando interno do sistema operacional, ou um arquivo .EXE, .COM \(.CMD no Windows NT\) ou .BAT em um programa C em vez da linha de comando.  
  
 A função system localiza o interpretador de comandos, que normalmente é CMD.EXE no sistema operacional Windows NT ou em COMMAND.COM no Windows.  A função system passará a cadeia de caracteres do argumento ao interpretador de comandos.  
  
 Para obter mais informações, consulte [system, \_wsystem](../c-runtime-library/reference/system-wsystem.md).  
  
## Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)