---
title: "V&#225;rios destinos | Microsoft Docs"
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
  - "makefiles, destinos"
  - "vários destinos em NMAKE"
  - "destinos, múltiplo em NMAKE"
  - "Programa NMAKE, destinos"
ms.assetid: b609a179-0b9f-4b08-9930-998047588ae0
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# V&#225;rios destinos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

NMAKE avalia vários destinos em uma única dependência como se cada foram especificada em um bloco de descrição separada.  
  
 Por exemplo, isso...  
  
```Output  
bounce.exe leap.exe : jump.obj  
   echo Building...  
```  
  
 ... são avaliadas como este:  
  
```Output  
bounce.exe : jump.obj  
   echo Building...  
leap.exe : jump.obj  
   echo Building...  
```  
  
## <a name="see-also"></a>Consulte também  
 [Destinos](../build/targets.md)