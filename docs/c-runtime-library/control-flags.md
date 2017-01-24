---
title: "Sinalizadores de controle | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.flags"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "heap de depuração, sinalizadores de controle"
  - "sinalizadores, Controle "
  - "alocação de heap, sinalizadores de controle"
ms.assetid: 8dbd24a5-0633-42d1-9771-776db338465f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sinalizadores de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A versão de depuração da biblioteca de tempo de execução Microsoft C usa os seguintes sinalizadores para controlar a alocação de heap e o processo de relatório.  Para obter mais informações, consulte [Técnicas de depuração do CRT](../Topic/CRT%20Debugging%20Techniques.md).  
  
|Sinalizador|Descrição|  
|-----------------|---------------|  
|[\_CRTDBG\_MAP\_ALLOC](../c-runtime-library/crtdbg-map-alloc.md)|Mapeia as funções de base de heap para suas contrapartes de versão de depuração|  
|[\_DEBUG](../Topic/_DEBUG.md)|Habilita o uso de versões de depuração das funções de tempo de execução|  
|[\_crtDbgFlag](../Topic/_crtDbgFlag.md)|Controla como o gerenciador de heap de depuração rastreia alocações|  
  
 Esses sinalizadores podem ser definidos com uma opção de linha de comando \/D ou com uma política de `#define` .  Quando o sinalizador é definido com `#define`, a política deve aparecer antes que o arquivo de cabeçalho inclui a instrução para as declarações de rotina.  
  
## Consulte também  
 [Variáveis globais e tipos padrão](../c-runtime-library/global-variables-and-standard-types.md)