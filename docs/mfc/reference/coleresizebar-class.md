---
title: "Classe de COleResizeBar | Microsoft Docs"
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
  - "COleResizeBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleResizeBar"
  - "barras de controle, redimensionar"
  - "itens no lugar"
  - "itens no lugar, redimensionar"
  - "Itens VELHOS, redimensionar"
  - "redimensionando itens VELHOS no lugar"
ms.assetid: 56a708d9-28c5-4eb0-9404-77b688d91c63
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleResizeBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um tipo de controle toolbar que suporta redimensionamento de itens VELHOS no lugar.  
  
## Sintaxe  
  
```  
class COleResizeBar : public CControlBar  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleResizeBar::COleResizeBar](../Topic/COleResizeBar::COleResizeBar.md)|Constrói um objeto de `COleResizeBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleResizeBar::Create](../Topic/COleResizeBar::Create.md)|Cria e inicializa uma janela filho do windows e associá\-lo ao objeto de `COleResizeBar` .|  
  
## Comentários  
 Os objetos de`COleResizeBar` aparecem como [CRectTracker](../../mfc/reference/crecttracker-class.md) com uma borda chocada e um left alças de redimensionamento.  
  
 Os objetos de`COleResizeBar` geralmente são membros de objetos inseridos de quadro\- janela derivados da classe de [COleIPFrameWnd](../../mfc/reference/coleipframewnd-class.md) .  
  
 Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `COleResizeBar`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [O MFC exemplos SUPERPAD](../../top/visual-cpp-samples.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleServerDoc](../Topic/COleServerDoc%20Class.md)