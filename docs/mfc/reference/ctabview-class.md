---
title: "Classe de CTabView | Microsoft Docs"
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
  - "CTabView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTabView"
ms.assetid: 8e6ecd9d-d28d-432b-8ec8-0446f0204d52
caps.latest.revision: 32
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTabView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CTabView` simplifica o uso da classe do controle da guia \([CMFCTabCtrl](../../mfc/reference/ctabview-class.md)\) em aplicativos que usam o documento MFC\/arquitetura de exibição.  
  
## Sintaxe  
  
```  
class CTabbedView : public CView  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTabView::AddView](../Topic/CTabView::AddView.md)|Adiciona um novo modo de exibição para o controle de guia.|  
|[CTabView::FindTab](../Topic/CTabView::FindTab.md)|Retorna o índice de exibição especificada no controle de guias.|  
|[CTabView::GetActiveView](../Topic/CTabView::GetActiveView.md)|Retorna um ponteiro para o modo ativo|  
|[CTabView::GetTabControl](../Topic/CTabView::GetTabControl.md)|Retorna uma referência ao controle da guia associado com a exibição.|  
|[CTabView::RemoveView](../Topic/CTabView::RemoveView.md)|Remove a exibição de controle de guia.|  
|[CTabView::SetActiveView](../Topic/CTabView::SetActiveView.md)|Faz uma exibição ativo.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTabView::IsScrollBar](../Topic/CTabView::IsScrollBar.md)|Chamado pela estrutura para criar um modo de guia para determinar se o modo de exibição de guia possui uma barra de rolagem horizontal compartilhado.|  
|[CTabView::OnActivateView](../Topic/CTabView::OnActivateView.md)|Chamado pela estrutura quando a exibição de guia é feita ativo ou inativo.|  
  
## Comentários  
 Essa classe facilita colocar uma exibição com guias em um aplicativo do documento\/exibição.  `CTabView` é `CView`\- a classe derivada que contém um objeto inserido de `CMFCTabCtrl` .  `CTabView` trata todas as mensagens necessárias para oferecer suporte ao objeto de `CMFCTabCtrl` .  Simplesmente uma classe derivada de `CTabView` e obstrua\-a em seu aplicativo, então adiciona `CView`\- classes derivadas usando o método de `AddView` .  O controle de guias exibirá as visualizações como guias.  
  
 Por exemplo, você pode ter um documento que pode ser representado em diferentes maneiras: como uma planilha, um gráfico, um formulário editável, e assim por diante.  Você pode criar modos de exibição individuais que desenha os dados quando necessário, inserir\-los em seu `CTabView`objeto derivado e tê\-los catalogados sem qualquer codificação adicional.  
  
 [exemplo de TabbedView: Listado aplicativo MFC de exibição](../../top/visual-cpp-samples.md) ilustra o uso de `CTabView`.  
  
## Exemplo  
 O exemplo a seguir mostra como `CTabView` é usado no exemplo de TabbedView.  
  
 [!code-cpp[NVC_MFC_TabbedView#1](../../mfc/reference/codesnippet/CPP/ctabview-class_1.h)]  
  
## Requisitos  
 **Cabeçalho:** afxTabView.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CTabView](../../mfc/reference/ctabview-class.md)   
 [Classe de CView](../Topic/CView%20Class.md)