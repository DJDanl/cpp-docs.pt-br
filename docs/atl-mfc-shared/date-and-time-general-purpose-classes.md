---
title: "Data e hora: Classes comumente usadas | Microsoft Docs"
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
  - "classes de data e hora"
  - "classes de tempo"
ms.assetid: b8115d7f-428a-4c41-9970-18502f2caca2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Data e hora: Classes comumente usadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como aproveitar os serviços de uso geral de biblioteca de classes relacionados até agora e de gerenciamento de tempo.  Os procedimentos descritos incluem:  
  
-   [Obtendo a hora atual](../atl-mfc-shared/current-time-general-purpose-classes.md)  
  
-   [O tempo decorrido calculando](../atl-mfc-shared/elapsed-time-general-purpose-classes.md)  
  
-   [Formatando um representação de cadeia de caracteres de uma data\/hora](../atl-mfc-shared/formatting-time-values-general-purpose-classes.md)  
  
 A classe de `CTime` fornece uma maneira para representar facilmente informações de data e hora.  A classe de `CTimeSpan` representa o tempo decorrido, como a diferença entre dois objetos de `CTime` .  
  
> [!NOTE]
>  Os objetos de CTime podem ser usados para representar datas entre o 1º de janeiro de 1970 e. o 18 de janeiro de 2038  Os objetos de`CTime` têm uma resolução de 1 segundo.  `CTime` é baseado no tipo de dados de `time_t` , definido na *referência da biblioteca em tempo de execução*.  
  
## Consulte também  
 [Data e hora](../atl-mfc-shared/date-and-time.md)