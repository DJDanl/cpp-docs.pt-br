---
title: "Classe de COleIPFrameWnd | Microsoft Docs"
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
  - "COleIPFrameWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleIPFrameWnd"
  - "edição in-loco"
  - "O OLE, edição"
  - "O OLE, ativação in-loco"
ms.assetid: 24abb2cb-826c-4dda-a287-d8a8900a5763
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleIPFrameWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A base para a janela de edição in\-loco do seu aplicativo.  
  
## Sintaxe  
  
```  
class COleIPFrameWnd : public CFrameWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleIPFrameWnd::COleIPFrameWnd](../Topic/COleIPFrameWnd::COleIPFrameWnd.md)|Constrói um objeto de `COleIPFrameWnd` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleIPFrameWnd::OnCreateControlBars](../Topic/COleIPFrameWnd::OnCreateControlBars.md)|Chamado pela estrutura quando um item é ativado para edição in\-place.|  
|[COleIPFrameWnd::RepositionFrame](../Topic/COleIPFrameWnd::RepositionFrame.md)|Chamado pela estrutura para reposicionar a janela de edição in\-loco.|  
  
## Comentários  
 Esta classe cria e posiciona barras de controle dentro da janela do documento de aplicativo de contêiner.  Também trata as notificações geradas por um objeto inserido de [COleResizeBar](../../mfc/reference/coleresizebar-class.md) quando o usuário redimensiona a janela de edição in\-loco.  
  
 Para obter mais informações sobre como usar `COleIPFrameWnd`, consulte o artigo [ativação](../../mfc/activation-cpp.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `COleIPFrameWnd`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [O MFC exemplos HIERSVR](../../top/visual-cpp-samples.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)