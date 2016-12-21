---
title: "Constantes spawn | Microsoft Docs"
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
  - "_P_NOWAIT"
  - "_P_OVERLAY"
  - "_P_WAIT"
  - "_P_DETACH"
  - "_P_NOWAITO"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _P_DETACH"
  - "Constante _P_NOWAIT"
  - "Constante _P_NOWAITO"
  - "Constante _P_OVERLAY"
  - "Constante _P_WAIT"
  - "Constante P_DETACH"
  - "Constante P_NOWAIT"
  - "Constante P_NOWAITO"
  - "Constante P_OVERLAY"
  - "Constante P_WAIT"
  - "constantes spawn"
ms.assetid: e0533e88-d362-46fc-b53c-5f193226d879
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes spawn
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
#include <process.h>  
```  
  
## Comentários  
 O argumento de `mode` determina a ação tomada pelo processo de chamada antes e durante uma operação de ova.  Os seguintes valores para `mode` são possíveis:  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_P_OVERLAY`|Cobre o processo de chamada com o novo processo, destruindo o processo de chamada \(mesmo efeito que chamadas de `_exec` \).|  
|`_P_WAIT`|Suspende o thread de chamada até que a execução do novo processo está completo `_spawn`\(síncrono\).|  
|`_P_NOWAIT`, `_P_NOWAITO`|Continua executando o processo de chamada simultaneamente com o novo processo `_spawn`\(assíncrono\).|  
|`_P_DETACH`|Continua executando o processo de chamada; o novo processo é executado em segundo plano sem acesso ao console ou ao teclado.  As chamadas a `_cwait` no novo processo falhará.  Este é `_spawn`assíncrona.|  
  
## Consulte também  
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)