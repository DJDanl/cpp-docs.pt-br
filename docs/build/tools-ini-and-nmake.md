---
title: "Tools.ini e NMAKE | Microsoft Docs"
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
  - "programa NMAKE, lendo arquivos"
  - "Tools.ini e NMake"
ms.assetid: ebd5eab6-ddf4-430e-bf4a-1db5bb84e344
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tools.ini e NMAKE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

NMAKE ler Tools.ini antes de ler makefiles, a menos que \/R é usado.  Procura Tools.ini primeiro no diretório atual e no diretório especificado pela variável de ambiente INIT.  A seção para configurações de NMAKE no arquivo de inicialização começa com `[NMAKE]` e pode conter todas as informações de makefile.  Especifique um comentário em uma linha separada começam com um sinal de número \(\#\).  
  
## Consulte também  
 [Executando NMAKE](../build/running-nmake.md)