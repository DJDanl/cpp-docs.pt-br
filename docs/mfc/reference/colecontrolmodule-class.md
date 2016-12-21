---
title: "Classe de COleControlModule | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleControlModule"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleControlModule"
  - "módulos de controle"
  - "Controles ActiveX MFC, Módulos controlador do OLE"
  - "Módulos controlador do OLE"
ms.assetid: 0721724d-d4af-4eda-ad34-5a2b27810dd4
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleControlModule
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base que você deriva de um objeto de módulo controlador do OLE.  
  
## Sintaxe  
  
```  
class COleControlModule : public CWinApp  
```  
  
## Comentários  
 Essa classe fornece funções de membro para inicializar seu módulo de controle.  Cada módulo do OLE controlador que usa as classes de base da Microsoft pode conter somente um objeto derivado de `COleControlModule`.  Este objeto é construído quando outros objetos globais C\+\+ são construídos.  Declare o objeto derivado de `COleControlModule` no nível global.  
  
 Para obter mais informações sobre como usar a classe de `COleControlModule` , consulte a classe de [CWinApp](../../mfc/reference/cwinapp-class.md) e o artigo [Controles do ActiveX](../../mfc/mfc-activex-controls.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWinThread](../../mfc/reference/cwinthread-class.md)  
  
 [CWinApp](../../mfc/reference/cwinapp-class.md)  
  
 `COleControlModule`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [Exemplo TESTHELP MFC](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)