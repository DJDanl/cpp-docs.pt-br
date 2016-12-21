---
title: "Classes de Windows Sockets | Microsoft Docs"
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
  - "vc.classes.net"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de soquetes"
  - "Windows Sockets [C++], Classes "
ms.assetid: 58b9ab8d-9e44-4db3-8265-e04e713d2e9a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de Windows Sockets
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Soquetes do windows fornecem uma maneira independente de rede para comunicação entre dois computadores.  Esses soquetes podem ser síncronas \(seu programa espera até que a comunicação seja feita\) ou assíncronas \(seu programa continua a ser executada quando a comunicação é ativado\).  
  
 [CAsyncSocket](../Topic/CAsyncSocket%20Class.md)  
 Encapsula soquetes apis do windows em um wrapper fino.  
  
 [CSocket](../mfc/reference/csocket-class.md)  
 Abstração de alto nível derivada de `CAsyncSocket`.  Opera de forma síncrona.  
  
 [CSocketFile](../Topic/CSocketFile%20Class.md)  
 Fornece uma interface de `CFile` a um soquete do windows.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)