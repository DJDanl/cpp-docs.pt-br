---
title: "/TLS | Microsoft Docs"
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
  - "/TLS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /TLS (dumpbin)"
  - "opção dumpbin -TLS"
ms.assetid: 2b3f48f9-cac4-4351-b15c-2833b43bc709
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /TLS
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Exibe a estrutura de IMAGE\_TLS\_DIRECTORY de um executável.  
  
## Comentários  
 \/TLS exibe os campos da estrutura do TLS assim como os endereços das funções de retorno de chamada do TLS.  
  
 Se um programa não usa o armazenamento de thread local, a imagem não conterá uma estrutura do TLS.  Consulte [thread](../../cpp/thread.md) para maiores informações.  
  
 IMAGE\_TLS\_DIRECTORY é definido em winnt.h.  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)