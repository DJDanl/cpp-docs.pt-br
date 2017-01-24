---
title: "Fun&#231;&#245;es de Retorno de Chamada Usadas pelo MFC | Microsoft Docs"
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
  - "vc.mfc.functions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções de retorno de chamada"
  - "funções de retorno de chamada, MFC"
  - "funções [C++], retorno de chamada"
  - "MFC, funções de retorno de chamada"
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de Retorno de Chamada Usadas pelo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Três funções de retorno de chamada aparecem na biblioteca de classes do Microsoft.  Uma descrição das funções de retorno de chamada que são transmitidas a [CDC::EnumObjects](../Topic/CDC::EnumObjects.md), de [CDC::GrayString](../Topic/CDC::GrayString.md), e de [CDC::SetAbortProc](../Topic/CDC::SetAbortProc.md) segue este tópico.  Para uso geral das funções de retorno de chamada, consulte a seção comentários dessas funções de membro.  Observe que todas as funções de retorno de chamada deve interceptar as exceções de MFC antes de retornar ao windows, desde que as exceções não podem ser geradas nos limites de retorno de chamada.  Para obter mais informações sobre as exceções, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)