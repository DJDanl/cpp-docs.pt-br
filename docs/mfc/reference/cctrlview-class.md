---
title: "Classe de CCtrlView | Microsoft Docs"
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
  - "CCtrlView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CCtrlView"
  - "controles [MFC], comuns"
  - "modos de exibição, e controles comuns"
ms.assetid: ff488596-1e71-451f-8fec-b0831a7b44e0
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCtrlView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Adapta a arquitetura da exibição para controles comuns suportados pelas versões 3,51 do Windows 98 e Windows NT e posterior.  
  
## Sintaxe  
  
```  
class CCtrlView : public CView  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCtrlView::CCtrlView](../Topic/CCtrlView::CCtrlView.md)|Constrói um objeto de `CCtrlView` .|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCtrlView::OnDraw](../Topic/CCtrlView::OnDraw.md)|Chamado pela estrutura para desenhar usando o contexto específico de dispositivo.|  
|[CCtrlView::PreCreateWindow](../Topic/CCtrlView::PreCreateWindow.md)|Chamado antes de criação da janela do windows anexada a esse objeto de `CCtrlView` .|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCtrlView::m\_dwDefaultStyle](../Topic/CCtrlView::m_dwDefaultStyle.md)|Contém o estilo padrão para a classe de exibição.|  
|[CCtrlView::m\_strClass](../Topic/CCtrlView::m_strClass.md)|Contém o nome da classe do windows para a classe de exibição.|  
  
## Comentários  
 A classe `CCtrlView` e seus derivados, [CEditView](../Topic/CEditView%20Class.md), [CListView](../../mfc/reference/clistview-class.md), [CTreeView](../../mfc/reference/ctreeview-class.md), e [CRichEditView](../../mfc/reference/cricheditview-class.md), adaptam a arquitetura da exibição para novos controles comuns suportados pelas versões 3,51 \/98 Windows 95 e Windows NT e posterior.  Para obter mais informações sobre a arquitetura da exibição, consulte [Arquitetura do documento\/exibição](../Topic/Document-View%20Architecture.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 `CCtrlView`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CView](../Topic/CView%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CTreeView](../../mfc/reference/ctreeview-class.md)   
 [Classe de CListView](../../mfc/reference/clistview-class.md)   
 [Classe de CRichEditView](../../mfc/reference/cricheditview-class.md)