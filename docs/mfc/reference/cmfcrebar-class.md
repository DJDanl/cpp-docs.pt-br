---
title: "Classe de CMFCReBar | Microsoft Docs"
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
  - "CMFCReBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCReBar"
ms.assetid: 02a60e29-6224-49c1-9e74-e0a7d9f8d023
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCReBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um objeto de `CMFCReBar` é uma barra de controle que fornece o layout, a persistência, e as informações do estado de controles do rebar.  
  
## Sintaxe  
  
```  
class CMFCReBar : public CPane  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCReBar::AddBar](../Topic/CMFCReBar::AddBar.md)|Adiciona uma faixa a um rebar.|  
|[CMFCReBar::CalcFixedLayout](../Topic/CMFCReBar::CalcFixedLayout.md)|Overrides \( [CBasePane::CalcFixedLayout](../Topic/CBasePane::CalcFixedLayout.md).\)|  
|[CMFCReBar::CanFloat](../Topic/CMFCReBar::CanFloat.md)|Overrides \( [CBasePane::CanFloat](../Topic/CBasePane::CanFloat.md).\)|  
|[CMFCReBar::Create](../Topic/CMFCReBar::Create.md)|Cria o controle rebar e anexá\-la ao objeto de `CMFCReBar` .|  
|[CMFCReBar::EnableDocking](../Topic/CMFCReBar::EnableDocking.md)|Overrides \( [CBasePane::EnableDocking](../Topic/CBasePane::EnableDocking.md).\)|  
|[CMFCReBar::GetReBarBandInfoSize](../Topic/CMFCReBar::GetReBarBandInfoSize.md)||  
|[CMFCReBar::GetReBarCtrl](../Topic/CMFCReBar::GetReBarCtrl.md)|Fornece acesso direto ao controle comum subjacente de [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) .|  
|[CMFCReBar::OnShowControlBarMenu](../Topic/CMFCReBar::OnShowControlBarMenu.md)|Overrides \( [CPane::OnShowControlBarMenu](../Topic/CPane::OnShowControlBarMenu.md).\)|  
|[CMFCReBar::OnToolHitTest](../Topic/CMFCReBar::OnToolHitTest.md)|Overrides \( [CWnd::OnToolHitTest](../Topic/CWnd::OnToolHitTest.md).\)|  
|[CMFCReBar::OnUpdateCmdUI](../Topic/CMFCReBar::OnUpdateCmdUI.md)|Overrides \( [CBasePane::OnUpdateCmdUI](http://msdn.microsoft.com/pt-br/e139f06a-9793-4ee2-bc3d-517389368c77).\)|  
|[CMFCReBar::SetPaneAlignment](../Topic/CMFCReBar::SetPaneAlignment.md)|Overrides \( [CBasePane::SetPaneAlignment](../Topic/CBasePane::SetPaneAlignment.md).\)|  
  
## Comentários  
 Um objeto de `CMFCReBar` pode conter uma variedade de janelas filho.  Isso inclui caixas de edição, barras de ferramentas, e caixas de listagem.  Você pode redimensionar o rebar programaticamente, ou o usuário pode redimensionar manualmente o rebar arrastando sua barra de alça.  Você também pode definir o plano de fundo de um objeto do rebar em um bitmap de sua escolha.  
  
 Um objeto do rebar se comporta de forma semelhante a um objeto da barra de ferramentas.  Um controle rebar pode conter uma ou mais faixas, e cada faixa pode conter uma barra de alça, um bitmap, um rótulo de texto, e uma janela filho.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCReBar` .  O exemplo a seguir mostra como criar um controle rebar e adicionar uma faixa.  Funções de faixa como uma barra de ferramentas interna.  Este trecho de código é parte de [Exemplo de teste do Rebar](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_RebarTest#1](../../mfc/reference/codesnippet/CPP/cmfcrebar-class_1.h)]  
[!code-cpp[NVC_MFC_RebarTest#2](../../mfc/reference/codesnippet/CPP/cmfcrebar-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md) [CCmdTarget](../Topic/CCmdTarget%20Class.md) [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md) [CPane](../../mfc/reference/cpane-class.md) [CMFCReBar](../../mfc/reference/cmfcrebar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxRebar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CReBarCtrl](../../mfc/reference/crebarctrl-class.md)   
 [Classe de CPane](../../mfc/reference/cpane-class.md)