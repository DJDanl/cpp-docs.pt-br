---
title: "Data e hora | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "datas, MFC"
  - "MFC, data e hora"
  - "time"
  - "time, Programação MFC"
ms.assetid: ecf56dc5-d418-4603-ad3e-af7e205a6403
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Data e hora
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O MFC suporta várias maneiras diferentes para trabalhar com datas e horas.  Eles incluem:  
  
-   Classes comumente usadas de tempo.  As classes de [CTime](../Topic/CTime%20Class.md) e de [CTimeSpan](../atl-mfc-shared/reference/ctimespan-class.md) encapsulam a maioria das funcionalidades associada com a biblioteca de tempo de ANSI padrão, que é declarada em. TIME.H.  
  
-   Suporte para o relógio do sistema.  Com a versão 3,0 do MFC, o suporte foi adicionado a `CTime` para o Win32 `SYSTEMTIME` e tipos de dados de `FILETIME` .  
  
-   Suporte a automação [Tipo de dados de DATA](../Topic/DATE%20Type.md).  O oferece suporte de**DATE** datam, multiplicado por, e valores de data\/hora.  As classes de [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) e de [COleDateTimeSpan](../Topic/COleDateTimeSpan%20Class.md) encapsulam essa funcionalidade.  Funcionam com a classe de [COleVariant](../mfc/reference/colevariant-class.md) que usa o suporte de automação.  
  
## Que você deseja saber mais?  
  
-   [Data e hora: Classes comumente usadas](../atl-mfc-shared/date-and-time-general-purpose-classes.md)  
  
-   [Data e hora: suporte de SYSTEMTIME](../atl-mfc-shared/date-and-time-systemtime-support.md)  
  
-   [Data e hora: Suporte de automação](../Topic/Date%20and%20Time:%20Automation%20Support.md)  
  
-   [Data e hora: Suporte a banco de dados](../atl-mfc-shared/date-and-time-database-support.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)