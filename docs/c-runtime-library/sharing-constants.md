---
title: "Compartilhando constantes | Microsoft Docs"
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
  - "_SH_DENYNO"
  - "_SH_DENYRD"
  - "_SH_DENYRW"
  - "_SH_DENYWR"
  - "_SH_COMPAT"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _SH_COMPAT"
  - "Constante _SH_DENYNO"
  - "Constante _SH_DENYRD"
  - "Constante _SH_DENYRW"
  - "Constante _SH_DENYWR"
  - "Constante SH_COMPAT"
  - "Constante SH_DENYNO"
  - "Constante SH_DENYRD"
  - "Constante SH_DENYRW"
  - "Constante SH_DENYWR"
  - "compartilhando constantes"
ms.assetid: 95fadc3a-55dc-473d-98b5-e8211900465d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compartilhando constantes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Constantes para modos de compartilhamento de arquivos.  
  
## Sintaxe  
  
```  
  
#include <share.h>  
  
```  
  
## Comentários  
 O argumento *de shflag* determina o modo de compartilhamento, que consiste em uma ou mais manifestas constantes.  Eles podem ser combinados com os argumentos *de oflag* \(consulte [Constantes de Arquivo](../c-runtime-library/file-constants.md)\).  
  
 A tabela a seguir lista as constantes e seus significados:  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_SH_DENYRW`|Nega o acesso de leitura e gravação no arquivo|  
|`_SH_DENYWR`|Nega o acesso de gravação no arquivo|  
|`_SH_DENYRD`|Nega o acesso de leitura ao arquivo|  
|`_SH_DENYNO`|Permite acesso de leitura e gravação|  
|`_SH_SECURE`|Os conjuntos evitar que o modo \(shared read, acesso de gravação exclusivo\).|  
  
## Consulte também  
 [\_sopen, \_wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [\_fsopen, \_wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)