---
title: "Classe de CMFCRibbonStatusBar | Microsoft Docs"
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
  - "CMFCRibbonStatusBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonStatusBar"
ms.assetid: 921eb57f-3b40-49fa-a38c-3f2fb6dc2893
caps.latest.revision: 37
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonStatusBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCRibbonStatusBar` implementa um controle statusbar que pode exibir os elementos de fita.  
  
## Sintaxe  
  
```  
class CMFCRibbonStatusBar : public CMFCRibbonBar  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonStatusBar::AddDynamicElement](../Topic/CMFCRibbonStatusBar::AddDynamicElement.md)|Adiciona um elemento dinâmico para a barra de status de fita.|  
|[CMFCRibbonStatusBar::AddElement](../Topic/CMFCRibbonStatusBar::AddElement.md)|Adiciona um novo elemento de fita a barra de status de fita.|  
|[CMFCRibbonStatusBar::AddExtendedElement](../Topic/CMFCRibbonStatusBar::AddExtendedElement.md)|Adiciona um elemento de fita estendido para a área de barra de status de fita.|  
|[CMFCRibbonStatusBar::AddSeparator](../Topic/CMFCRibbonStatusBar::AddSeparator.md)|Adiciona um separador para a barra de status de fita.|  
|[CMFCRibbonStatusBar::Create](../Topic/CMFCRibbonStatusBar::Create.md)|Cria uma barra de status de fita.|  
|[CMFCRibbonStatusBar::CreateEx](../Topic/CMFCRibbonStatusBar::CreateEx.md)|Cria uma barra de status de fita com um estilo estendido.|  
|[CMFCRibbonStatusBar::FindByID](../Topic/CMFCRibbonStatusBar::FindByID.md)||  
|[CMFCRibbonStatusBar::FindElement](../Topic/CMFCRibbonStatusBar::FindElement.md)|Retorna um ponteiro para o elemento que possui um certo ID de comando|  
|[CMFCRibbonStatusBar::GetCount](../Topic/CMFCRibbonStatusBar::GetCount.md)|Retorna o número de elementos que estão localizados na área principal da barra de status de fita.|  
|[CMFCRibbonStatusBar::GetElement](../Topic/CMFCRibbonStatusBar::GetElement.md)|Retorna um ponteiro para o elemento que está localizado em um índice especificado.|  
|[CMFCRibbonStatusBar::GetExCount](../Topic/CMFCRibbonStatusBar::GetExCount.md)|Retorna o número de elementos que estão localizados na área controle statusbar de fita.|  
|[CMFCRibbonStatusBar::GetExElement](../Topic/CMFCRibbonStatusBar::GetExElement.md)|Retorna um ponteiro para o elemento que está localizado em um índice especificado na área controle statusbar de fita.|  
|[CMFCRibbonStatusBar::GetExtendedArea](../Topic/CMFCRibbonStatusBar::GetExtendedArea.md)||  
|[CMFCRibbonStatusBar::GetSpace](../Topic/CMFCRibbonStatusBar::GetSpace.md)||  
|[CMFCRibbonStatusBar::IsBottomFrame](../Topic/CMFCRibbonStatusBar::IsBottomFrame.md)||  
|[CMFCRibbonStatusBar::IsExtendedElement](../Topic/CMFCRibbonStatusBar::IsExtendedElement.md)||  
|[CMFCRibbonStatusBar::IsInformationMode](../Topic/CMFCRibbonStatusBar::IsInformationMode.md)|Determina se o modo de informações é habilitado para a barra de status de fita.|  
|[CMFCRibbonStatusBar::RecalcLayout](../Topic/CMFCRibbonStatusBar::RecalcLayout.md)|Overrides \( [CMFCRibbonBar::RecalcLayout](../Topic/CMFCRibbonBar::RecalcLayout.md).\)|  
|[CMFCRibbonStatusBar::RemoveAll](../Topic/CMFCRibbonStatusBar::RemoveAll.md)|Remove todos os elementos da barra de status de fita.|  
|[CMFCRibbonStatusBar::RemoveElement](../Topic/CMFCRibbonStatusBar::RemoveElement.md)|Remove o elemento que tenha especificado uma identificação de comando statusbar de fita.|  
|[CMFCRibbonStatusBar::SetInformation](../Topic/CMFCRibbonStatusBar::SetInformation.md)|Habilita ou desabilita o modo de informações para a barra de status de fita.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonStatusBar::OnDrawInformation](../Topic/CMFCRibbonStatusBar::OnDrawInformation.md)|Exibe a cadeia de caracteres de informações que aparece na barra de status de fita quando o modo de informações é ativado.|  
  
## Comentários  
 Os usuários podem modificar a visibilidade dos elementos de fita em uma barra de status de fita usando o menu de contexto interno para a barra de status de fita.  Você pode adicionar ou remover os elementos dinamicamente.  
  
 Uma barra de status de fita tem duas áreas: uma área principal e uma área estendido.  A área estendido é exibida no lado direito da barra de status de fita e aparecem em uma cor diferente do que a área principal faz.  
  
 Normalmente, a área principal statusbar exibe notificações de status, e exibe estendidos da área exibe controles.  A área estendido permanece visível o tempo todo possível quando o usuário redimensiona a barra de status de fita.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCRibbonStatusBar` .  O exemplo a seguir mostra como adicionar um novo elemento de fita a barra de status de fita, adicione um elemento de fita estendido para a área de barra de status de fita, adicione um separador, e ativar o modo normal para a barra de status de fita.  
  
 [!code-cpp[NVC_MFC_RibbonApp#15](../../mfc/reference/codesnippet/CPP/cmfcribbonstatusbar-class_1.cpp)]  
[!code-cpp[NVC_MFC_RibbonApp#16](../../mfc/reference/codesnippet/CPP/cmfcribbonstatusbar-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)  
  
 [CMFCRibbonStatusBar](../../mfc/reference/cmfcribbonstatusbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribbonstatusbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)   
 [Classe de CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)   
 [Classe de CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)