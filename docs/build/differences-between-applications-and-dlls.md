---
title: "Diferen&#231;as entre aplicativos e DLLs | Microsoft Docs"
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
  - "aplicativos [C++], vs. DLLs"
  - "DLLs [C++], vs. aplicativos"
  - "arquivos executáveis [C++], DLLs vs. aplicativos"
ms.assetid: 8f271523-d8d0-4ad1-84d2-0c5645d7fd5b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diferen&#231;as entre aplicativos e DLLs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Mesmo que as dlls e os aplicativos sejam ambos os módulos de programa executável, diferem em várias maneiras.  Para o usuário final, a diferença mais óbvia é que as dlls não são programas que podem ser executados diretamente.  Do ponto de vista de sistema, há duas diferenças fundamentais entre aplicativos e DLL:  
  
-   Um aplicativo pode ter várias instâncias da execução no sistema simultaneamente, enquanto uma DLL pode ter apenas uma instância do.  
  
-   Um aplicativo pode possuir itens como uma pilha, uma memória global, os identificadores de arquivo, e uma fila de mensagens, mas uma DLL não pode.  
  
## O que você deseja fazer?  
  
-   [Exportar de uma DLL](../build/exporting-from-a-dll.md)  
  
-   [Vincular um executável para uma DLL](../build/linking-an-executable-to-a-dll.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [As vantagens de usar DLL](../build/advantages-of-using-dlls.md)  
  
-   [DLLs não MFC: Visão Geral](../Topic/Non-MFC%20DLLs:%20Overview.md)  
  
-   [DLL normais vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [DLLs de extensão: visão geral](../build/extension-dlls-overview.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)