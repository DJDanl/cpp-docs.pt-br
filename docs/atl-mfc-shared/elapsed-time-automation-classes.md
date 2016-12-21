---
title: "O tempo decorrido: Classes de automa&#231;&#227;o | Microsoft Docs"
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
  - "Classes de automação, o tempo decorrido"
  - "datas e horas calculadoras"
  - "cálculos, data e hora"
  - "datas, intervalos calculando"
  - "o tempo decorrido, cálculo na automação"
  - "intervalos, data e hora"
  - "time, decorrido"
ms.assetid: 26b34b37-c10e-4b91-82c3-1dc5ffb5361f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O tempo decorrido: Classes de automa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este procedimento mostra como calcula a diferença entre dois objetos de `CTime` e obter um resultado de `CTimeSpan` .  
  
#### Para calcular o tempo decorrido  
  
1.  Crie dois objetos de `COleDateTime` .  
  
2.  Definir um dos objetos de `COleDateTime` para a hora atual.  
  
3.  Execute alguma tarefa demorada.  
  
4.  Defina o outro objeto de `COleDateTime` para a hora atual.  
  
5.  Leva a diferença entre os dois tempo.  
  
     [!code-cpp[NVC_ATLMFC_Utilities#178](../atl-mfc-shared/codesnippet/CPP/elapsed-time-automation-classes_1.cpp)]  
  
## Consulte também  
 [Data e hora: Suporte de automação](../Topic/Date%20and%20Time:%20Automation%20Support.md)