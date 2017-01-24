---
title: "Depend&#234;ncias cumulativas | Microsoft Docs"
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
  - "dependências cumulativas"
  - "dependências cumulativas em NMAKE"
  - "dependências"
ms.assetid: fa6dd777-80b8-437d-87a7-aec0ed818a49
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Depend&#234;ncias cumulativas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dependências são cumulativas em um bloco de descrição, se um destino for repetido.  
  
 Por exemplo, o conjunto de regras,  
  
```Output  
bounce.exe : jump.obj  
bounce.exe : up.obj  
   echo Building bounce.exe...  
```  
  
 é avaliado como este:  
  
```Output  
bounce.exe : jump.obj up.obj  
   echo Building bounce.exe...  
```  
  
 Vários destinos em várias linhas de dependência em um bloco único descrição são avaliados como se cada foram especificadas em um bloco de descrição separada, mas os destinos que não estão na última linha de dependência não use o bloco de comandos. NMAKE tenta usar uma regra de inferência para esses destinos.  
  
 Por exemplo, o conjunto de regras,  
  
```Output  
leap.exe bounce.exe : jump.obj  
bounce.exe climb.exe : up.obj  
   echo Building bounce.exe...  
```  
  
 é avaliado como este:  
  
```Output  
  
leap.exe : jump.obj  
# invokes an inference rule  
bounce.exe : jump.obj up.obj  
   echo Building bounce.exe...  
climb.exe : up.obj  
   echo Building bounce.exe...  
```  
  
## <a name="see-also"></a>Consulte também  
 [Destinos](../build/targets.md)