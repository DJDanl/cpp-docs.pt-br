---
title: "Hora atual: Classes comumente usadas | Microsoft Docs"
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
  - "hora atual, Objeto de CTime"
  - "inicializando objetos, com a hora atual"
  - "procedimentos, obtendo hora atual"
  - "time, obtendo a atual"
  - "time, atual de configuração"
ms.assetid: c39e6775-6a92-4b27-95a7-5c86ed371d8a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Hora atual: Classes comumente usadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O procedimento a seguir mostra como criar um objeto de `CTime` e inicializá\-la com a hora atual.  
  
#### Para obter a hora atual  
  
1.  Atribua um objeto de `CTime` , como segue:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#171](../atl-mfc-shared/codesnippet/CPP/current-time-general-purpose-classes_1.cpp)]  
  
    > [!NOTE]
    >  Os objetos não inicializado de `CTime` não são inicializadas para um horário válidos.  
  
2.  Chame a função de `CTime::GetCurrentTime` para obter a hora atual do sistema operacional.  Essa função retorna um objeto de `CTime` que pode ser usado para definir o valor de `CTime`, como segue:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#172](../atl-mfc-shared/codesnippet/CPP/current-time-general-purpose-classes_2.cpp)]  
  
     Desde que `GetCurrentTime` é uma função de membro estático da classe de `CTime` , você deve qualificar seu nome com o nome da classe e o operador de resolução de escopo \(`::`\), `CTime::GetCurrentTime()`.  
  
 Naturalmente, as duas etapas descritas anteriormente podem ser combinados em uma única instrução de programa como segue:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#173](../atl-mfc-shared/codesnippet/CPP/current-time-general-purpose-classes_3.cpp)]  
  
## Consulte também  
 [Data e hora: Classes comumente usadas](../atl-mfc-shared/date-and-time-general-purpose-classes.md)