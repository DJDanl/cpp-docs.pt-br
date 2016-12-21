---
title: "Classe de CFormView | Microsoft Docs"
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
  - "CFormView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFormView"
  - "exibições de formulário"
  - "modos de exibição, contendo controles"
ms.assetid: a99ec313-36f0-4f28-9d2b-de11de14ac19
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFormView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base usada para modos de exibição de formulário.  
  
## Sintaxe  
  
```  
class CFormView : public CScrollView  
```  
  
## Membros  
  
### Construtores Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFormView::CFormView](../Topic/CFormView::CFormView.md)|Constrói um objeto `CFormView`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFormView::IsInitDlgCompleted](../Topic/CFormView::IsInitDlgCompleted.md)|Usado para sincronização durante a inicialização.|  
  
## Comentários  
 Um modo de exibição de formulário é essencialmente uma exibição que contém controles.  Esses controles são dispostos em um recurso de modelo de caixa de diálogo.  Use `CFormView` se quiser formulários em seu aplicativo.  Esses modos de exibição oferecem suporte a rolagem, conforme necessário, usando o [CScrollView](../../mfc/reference/cscrollview-class.md) funcionalidade.  
  
 Quando você estiver [Criando um aplicativo baseado em formulários](../Topic/Creating%20a%20Forms-Based%20MFC%20Application.md), você pode basear sua classe de exibição `CFormView`, tornando\-um aplicativo baseado em formulários.  
  
 Você também pode inserir novos [formulário tópicos](../Topic/Form%20Views%20\(MFC\).md) em aplicativos com base na exibição de documento.  Mesmo que seu aplicativo não oferecia suporte inicialmente forms, Visual C\+\+ adicionará esse suporte quando você insere um novo formulário.  
  
 O Assistente para aplicativo do MFC e o comando Add Class são os métodos preferenciais para a criação de aplicativos baseados em formulários.  Se você precisar criar um aplicativo baseado em formulários sem usar esses métodos, consulte [Criando um aplicativo baseado em formulários](../Topic/Creating%20a%20Forms-Based%20MFC%20Application.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CScrollView](../../mfc/reference/cscrollview-class.md)  
  
 `CFormView`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [MFC exemplo SNAPVW](../../top/visual-cpp-samples.md)   
 [MFC exemplo VIEWEX](../../top/visual-cpp-samples.md)   
 [Classe de CScrollView](../../mfc/reference/cscrollview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)   
 [Classe de CScrollView](../../mfc/reference/cscrollview-class.md)   
 [CView::OnUpdate](../Topic/CView::OnUpdate.md)   
 [CView::OnInitialUpdate](../Topic/CView::OnInitialUpdate.md)   
 [CView::OnPrint](../Topic/CView::OnPrint.md)   
 [CWnd::UpdateData](../Topic/CWnd::UpdateData.md)   
 [CScrollView::ResizeParentToFit](../Topic/CScrollView::ResizeParentToFit.md)