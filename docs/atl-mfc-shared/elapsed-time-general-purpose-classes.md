---
title: "O tempo decorrido: Classes comumente usadas | Microsoft Docs"
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
  - "adicionando datas"
  - "datas e horas calculadoras"
  - "cálculos, data e hora"
  - "datas, intervalos calculando"
  - "o tempo decorrido"
  - "o tempo decorrido, cálculo"
  - "intervalos, data e hora"
  - "time, decorrido"
ms.assetid: e5c5d3d2-ce1d-409e-875c-98848434e716
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O tempo decorrido: Classes comumente usadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O procedimento a seguir mostra como calcula a diferença entre dois objetos de `CTime` e obter um resultado de `CTimeSpan` .  
  
#### Para calcular o tempo decorrido  
  
1.  Use os objetos de `CTime` e de `CTimeSpan` para calcular o tempo decorrido, a seguinte maneira:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#174](../atl-mfc-shared/codesnippet/CPP/elapsed-time-general-purpose-classes_1.cpp)]  
  
     Uma vez que você calculou `elapsedTime`, você pode usar as funções de membro de `CTimeSpan` para extrair os componentes de valor de tempo decorrido.  
  
## Consulte também  
 [Data e hora: Classes comumente usadas](../atl-mfc-shared/date-and-time-general-purpose-classes.md)