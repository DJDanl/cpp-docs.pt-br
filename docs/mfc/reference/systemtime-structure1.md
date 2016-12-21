---
title: "Estrutura SYSTEMTIME | Microsoft Docs"
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
  - "SYSTEMTIME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura SYSTEMTIME"
ms.assetid: 9aaef4d6-de79-4fa1-8158-86b245ef5bff
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura SYSTEMTIME
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura `SYSTEMTIME` representa uma data e hora usando membros individuais para o mês, o dia, o ano, o dia da semana, a hora, o minuto, o segundo e o milissegundos.  
  
## Sintaxe  
  
```  
  
      typedef struct _SYSTEMTIME {  
   WORD wYear;  
   WORD wMonth;  
   WORD wDayOfWeek;  
   WORD wDay;  
   WORD wHour;  
   WORD wMinute;  
   WORD wSecond;  
   WORD wMilliseconds;  
} SYSTEMTIME;  
```  
  
#### Parâmetros  
 *wYear*  
 O ano atual.  
  
 *wMonth*  
 O mês atual; Janeiro é 1.  
  
 *wDayOfWeek*  
 O dia atual da semana; Domingo é 0, Segunda\-feira é 1 e assim por diante.  
  
 *wDay*  
 O dia atual do mês.  
  
 *wHour*  
 A hora atual.  
  
 *wMinute*  
 O minuto atual.  
  
 *wSecond*  
 O segundo atual.  
  
 *wMilliseconds*  
 O milissegundo atual.  
  
## Exemplo  
 [!code-cpp[NVC_MFC_Utilities#39](../../mfc/codesnippet/CPP/systemtime-structure1_1.cpp)]  
  
## Requisitos  
 **Cabeçalho:** winbase.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CTime::CTime](../Topic/CTime::CTime.md)