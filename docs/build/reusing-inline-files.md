---
title: "Reutilizando arquivos embutidos | Microsoft Docs"
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
  - "arquivos embutidos, reutilizando NMAKE"
  - "programa NMAKE, arquivos embutidos"
  - "revisando arquivos embutidos"
ms.assetid: d42dbffb-2cef-4ccb-9a1f-20b8ef81481c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Reutilizando arquivos embutidos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para reutilizar um arquivo embutido, especifique \<\<*o nome de arquivo* onde o arquivo está definido e usado basicamente, *o nome de arquivo* sem \<\< reutilização posterior na mesma ou em outra comando.  O comando criar o arquivo embutido deve executar antes de todos os comandos que usam o arquivo.  
  
## Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)