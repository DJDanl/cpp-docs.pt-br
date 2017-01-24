---
title: "Classe de CMFCStatusBar | Microsoft Docs"
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
  - "CMFCStatusBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCStatusBar"
ms.assetid: f2960d1d-f4ed-41e8-bd99-0382b2f8d88e
caps.latest.revision: 36
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCStatusBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCStatusBar` implementa uma barra de status semelhante à classe de `CStatusBar` .  Em o entanto, a classe de `CMFCStatusBar` possui recursos não oferecidos pela classe de `CStatusBar` , como a capacidade para exibir imagens, a animação, e a barra de progresso; e a capacidade de responder ao clique duas vezes em.  
  
## Sintaxe  
  
```  
class CMFCStatusBar : public CPane  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCStatusBar::CalcFixedLayout](../Topic/CMFCStatusBar::CalcFixedLayout.md)|Overrides \( [CBasePane::CalcFixedLayout](../Topic/CBasePane::CalcFixedLayout.md).\)|  
|[CMFCStatusBar::CommandToIndex](../Topic/CMFCStatusBar::CommandToIndex.md)||  
|[CMFCStatusBar::Create](../Topic/CMFCStatusBar::Create.md)|Cria uma barra de controle e anexá\-la ao objeto de [CPane](../../mfc/reference/cpane-class.md) .  Overrides \( [CPane::Create](../Topic/CPane::Create.md).\)|  
|[CMFCStatusBar::CreateEx](../Topic/CMFCStatusBar::CreateEx.md)|Cria uma barra de controle e anexá\-la ao objeto de [CPane](../../mfc/reference/cpane-class.md) .  Overrides \( [CPane::CreateEx](../Topic/CPane::CreateEx.md).\)|  
|[CMFCStatusBar::DoesAllowDynInsertBefore](../Topic/CMFCStatusBar::DoesAllowDynInsertBefore.md)|Determina se outro painel dinamicamente pode ser inserido entre esse painel e o elemento pai.  Overrides \( [CBasePane::DoesAllowDynInsertBefore](../Topic/CBasePane::DoesAllowDynInsertBefore.md).\)|  
|[CMFCStatusBar::EnablePaneDoubleClick](../Topic/CMFCStatusBar::EnablePaneDoubleClick.md)|Habilita ou desativa verificação que o tratamento do mouse clique duas vezes na barra de status.|  
|[CMFCStatusBar::EnablePaneProgressBar](../Topic/CMFCStatusBar::EnablePaneProgressBar.md)|Exibe uma barra de progresso no painel especificado.|  
|[CMFCStatusBar::GetCount](../Topic/CMFCStatusBar::GetCount.md)|Retorna o número de painéis na barra de status.|  
|[CMFCStatusBar::GetDrawExtendedArea](../Topic/CMFCStatusBar::GetDrawExtendedArea.md)||  
|[CMFCStatusBar::GetExtendedArea](../Topic/CMFCStatusBar::GetExtendedArea.md)||  
|[CMFCStatusBar::GetItemID](../Topic/CMFCStatusBar::GetItemID.md)||  
|[CMFCStatusBar::GetItemRect](../Topic/CMFCStatusBar::GetItemRect.md)||  
|[CMFCStatusBar::GetPaneInfo](../Topic/CMFCStatusBar::GetPaneInfo.md)||  
|[CMFCStatusBar::GetPaneProgress](../Topic/CMFCStatusBar::GetPaneProgress.md)||  
|[CMFCStatusBar::GetPaneStyle](../Topic/CMFCStatusBar::GetPaneStyle.md)|Retorna o estilo de painel.  Overrides \( [CBasePane::GetPaneStyle](../Topic/CBasePane::GetPaneStyle.md).\)|  
|[CMFCStatusBar::GetPaneText](../Topic/CMFCStatusBar::GetPaneText.md)||  
|[CMFCStatusBar::GetPaneWidth](../Topic/CMFCStatusBar::GetPaneWidth.md)|Retorna a largura, em pixels, do painel especificado statusbar.|  
|[CMFCStatusBar::GetTipText](../Topic/CMFCStatusBar::GetTipText.md)|Retorna o texto da dica de ferramenta para o painel especificado statusbar.|  
|[CMFCStatusBar::InvalidatePaneContent](../Topic/CMFCStatusBar::InvalidatePaneContent.md)|Invalida o painel especificado e redesenha seu conteúdo.|  
|[CMFCStatusBar::PreCreateWindow](../Topic/CMFCStatusBar::PreCreateWindow.md)|Chamado pela estrutura antes de criação da janela do windows anexada a esse objeto de `CWnd` .  Overrides \( [CWnd::PreCreateWindow](../Topic/CWnd::PreCreateWindow.md).\)|  
|[CMFCStatusBar::SetDrawExtendedArea](../Topic/CMFCStatusBar::SetDrawExtendedArea.md)||  
|[CMFCStatusBar::SetIndicators](../Topic/CMFCStatusBar::SetIndicators.md)||  
|[CMFCStatusBar::SetPaneAnimation](../Topic/CMFCStatusBar::SetPaneAnimation.md)|Atribui uma animação para o painel especificado.|  
|[CMFCStatusBar::SetPaneBackgroundColor](../Topic/CMFCStatusBar::SetPaneBackgroundColor.md)|Define a cor do plano de fundo para o painel especificado statusbar.|  
|[CMFCStatusBar::SetPaneIcon](../Topic/CMFCStatusBar::SetPaneIcon.md)|Define o ícone do indexador para o painel especificado statusbar.|  
|[CMFCStatusBar::SetPaneInfo](../Topic/CMFCStatusBar::SetPaneInfo.md)||  
|[CMFCStatusBar::SetPaneProgress](../Topic/CMFCStatusBar::SetPaneProgress.md)|Define o estado atual de barra de progresso para o painel especificado statusbar.|  
|[CMFCStatusBar::SetPaneStyle](../Topic/CMFCStatusBar::SetPaneStyle.md)|Defina o estilo de painel.  Overrides \( [CBasePane::SetPaneStyle](../Topic/CBasePane::SetPaneStyle.md).\)|  
|[CMFCStatusBar::SetPaneText](../Topic/CMFCStatusBar::SetPaneText.md)||  
|[CMFCStatusBar::SetPaneTextColor](../Topic/CMFCStatusBar::SetPaneTextColor.md)|Define a cor do texto para o painel especificado statusbar.|  
|[CMFCStatusBar::SetPaneWidth](../Topic/CMFCStatusBar::SetPaneWidth.md)|Defina a largura em pixels do painel especificado statusbar.|  
|[CMFCStatusBar::SetTipText](../Topic/CMFCStatusBar::SetTipText.md)|Define o texto da dica de ferramenta para o painel especificado statusbar.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCStatusBar::OnDrawPane](../Topic/CMFCStatusBar::OnDrawPane.md)|Quando chamado pela estrutura de redesenho o painel de barra de status.|  
  
## Comentários  
 O diagrama a seguir mostra uma figura statusbar de aplicativo de [Exemplo de demonstração statusbar](../../top/visual-cpp-samples.md) .  
  
 ![Imagem de CMFCStatusBar](../../mfc/reference/media/cmfcstatusbar.png "CMFCStatusBar")  
  
## Exemplo  
 O exemplo a seguir demonstra as variáveis locais que o aplicativo usa para chamar diversos métodos na classe de `CMFCStatusBar` .  Essas variáveis são declaradas em StatusBarDemoView.h.  O quadro chave é declarado em MainFrm.h, o documento é declarado em StatusBarDemoDoc.h, e a exibição é declarada em StatusBarDemoView.h.  Este trecho de código é parte de [Exemplo de demonstração statusbar](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StatusBarDemo#9](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_1.h)]  
  
## Exemplo  
 O exemplo a seguir demonstra como obter uma referência ao objeto de `CMFCStatusBar` apresentando o método de `GetStatusBar` em MainFrm.h e em seguida chamar esse método do método de `GetStatusBar` em StatusBarDemoView.h.  Este trecho de código é parte de [Exemplo de demonstração statusbar](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StatusBarDemo#7](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_2.h)]  
[!code-cpp[NVC_MFC_StatusBarDemo#8](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_3.h)]  
  
## Exemplo  
 O exemplo a seguir demonstra como chamar diversos métodos na classe de `CMFCStatusBar` em StatusBarDemoView.cpp.  Constantes são declaradas em MainFrm.h.  O exemplo a seguir mostra como definir o ícone, define o texto de dica do painel statusbar, exibe uma barra de progresso no painel especificado, atribui uma animação para o painel especificado, define o texto e a largura do painel de barra de status, e defina o indicador de progresso atual de barra de progresso para o painel statusbar.  Este trecho de código é parte de [Exemplo de demonstração statusbar](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StatusBarDemo#6](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_4.h)]  
[!code-cpp[NVC_MFC_StatusBarDemo#1](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_5.cpp)]  
[!code-cpp[NVC_MFC_StatusBarDemo#2](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_6.cpp)]  
[!code-cpp[NVC_MFC_StatusBarDemo#3](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_7.cpp)]  
[!code-cpp[NVC_MFC_StatusBarDemo#4](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_8.cpp)]  
[!code-cpp[NVC_MFC_StatusBarDemo#5](../../mfc/reference/codesnippet/CPP/cmfcstatusbar-class_9.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxstatusbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CPane](../../mfc/reference/cpane-class.md)   
 [Classe de CStatusBar](../../mfc/reference/cstatusbar-class.md)