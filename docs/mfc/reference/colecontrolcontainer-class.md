---
title: "Classe de COleControlContainer | Microsoft Docs"
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
  - "COleControlContainer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Recipiente de controles ActiveX [C++], controle ao site"
  - "Classe de COleControlContainer"
  - "controles personalizados [MFC], sites"
ms.assetid: f7ce9246-0fb7-4f07-a83a-6c2390d0fdf8
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleControlContainer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Atua como um recipiente de controle para controles ActiveX.  
  
## Sintaxe  
  
```  
class COleControlContainer : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlContainer::COleControlContainer](../Topic/COleControlContainer::COleControlContainer.md)|Constrói um objeto de `COleControlContainer` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlContainer::AttachControlSite](../Topic/COleControlContainer::AttachControlSite.md)|Cria um site do controle, hospedado pelo recipiente.|  
|[COleControlContainer::BroadcastAmbientPropertyChange](../Topic/COleControlContainer::BroadcastAmbientPropertyChange.md)|Informa todos os controles hospedados que uma propriedade de ambiente foi alterado.|  
|[COleControlContainer::CheckDlgButton](../Topic/COleControlContainer::CheckDlgButton.md)|Altera o controle específico do botão.|  
|[COleControlContainer::CheckRadioButton](../Topic/COleControlContainer::CheckRadioButton.md)|Seleciona o botão de opção especificado de um grupo.|  
|[COleControlContainer::CreateControl](../Topic/COleControlContainer::CreateControl.md)|Cria um controle ActiveX hospedado.|  
|[COleControlContainer::CreateOleFont](../Topic/COleControlContainer::CreateOleFont.md)|Cria uma fonte OLE.|  
|[COleControlContainer::FindItem](../Topic/COleControlContainer::FindItem.md)|Retorna o site personalizado de controle específico.|  
|[COleControlContainer::FreezeAllEvents](../Topic/COleControlContainer::FreezeAllEvents.md)|Determina se o site do controle estiver retornando eventos.|  
|[COleControlContainer::GetAmbientProp](../Topic/COleControlContainer::GetAmbientProp.md)|Recupera a propriedade de ambiente especificada.|  
|[COleControlContainer::GetDlgItem](../Topic/COleControlContainer::GetDlgItem.md)|Recupera o controle específico da caixa de diálogo.|  
|[COleControlContainer::GetDlgItemInt](../Topic/COleControlContainer::GetDlgItemInt.md)|Recupera o valor do controle específico da caixa de diálogo.|  
|[COleControlContainer::GetDlgItemText](../Topic/COleControlContainer::GetDlgItemText.md)|Recupera a legenda do controle específico da caixa de diálogo.|  
|[COleControlContainer::HandleSetFocus](../Topic/COleControlContainer::HandleSetFocus.md)|Determina se o contêiner trata mensagens de `WM_SETFOCUS` .|  
|[COleControlContainer::HandleWindowlessMessage](../Topic/COleControlContainer::HandleWindowlessMessage.md)|Manipula as mensagens enviadas em um controle sem o windows.|  
|[COleControlContainer::IsDlgButtonChecked](../Topic/COleControlContainer::IsDlgButtonChecked.md)|Determina o estado do botão especificado.|  
|[COleControlContainer::OnPaint](../Topic/COleControlContainer::OnPaint.md)|Chamado para redesenhar uma parte do contêiner.|  
|[COleControlContainer::OnUIActivate](../Topic/COleControlContainer::OnUIActivate.md)|Chamado quando um controle está prestes a ser ativado no lugar.|  
|[COleControlContainer::OnUIDeactivate](../Topic/COleControlContainer::OnUIDeactivate.md)|Chamado quando um controle está prestes a ser desativada.|  
|[COleControlContainer::ScrollChildren](../Topic/COleControlContainer::ScrollChildren.md)|Chamado pela estrutura quando as mensagens de rolagem são recebidas de uma janela filho.|  
|[COleControlContainer::SendDlgItemMessage](../Topic/COleControlContainer::SendDlgItemMessage.md)|Enviar uma mensagem para o controle especificado.|  
|[COleControlContainer::SetDlgItemInt](../Topic/COleControlContainer::SetDlgItemInt.md)|Defina o valor do controle especificado.|  
|[COleControlContainer::SetDlgItemText](../Topic/COleControlContainer::SetDlgItemText.md)|Define o texto do controle específico.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlContainer::m\_crBack](../Topic/COleControlContainer::m_crBack.md)|A cor do plano de fundo do contêiner.|  
|[COleControlContainer::m\_crFore](../Topic/COleControlContainer::m_crFore.md)|A cor do plano de fundo do recipiente.|  
|[COleControlContainer::m\_listSitesOrWnds](../Topic/COleControlContainer::m_listSitesOrWnds.md)|Uma lista de sites de controle suportados.|  
|[COleControlContainer::m\_nWindowlessControls](../Topic/COleControlContainer::m_nWindowlessControls.md)|O número de controles sem o windows hospedados.|  
|[COleControlContainer::m\_pOleFont](../Topic/COleControlContainer::m_pOleFont.md)|Um ponteiro para a fonte OLE do site do controle personalizado.|  
|[COleControlContainer::m\_pSiteCapture](../Topic/COleControlContainer::m_pSiteCapture.md)|Ponteiro para o site de controle de captura.|  
|[COleControlContainer::m\_pSiteFocus](../Topic/COleControlContainer::m_pSiteFocus.md)|Ponteiro para o controle que tem o foco atualmente conectado.|  
|[COleControlContainer::m\_pSiteUIActive](../Topic/COleControlContainer::m_pSiteUIActive.md)|Ponteiro para o controle que estiver no lugar ativado.|  
|[COleControlContainer::m\_pWnd](../Topic/COleControlContainer::m_pWnd.md)|Ponteiro para a janela que implementa o contêiner do controle.|  
|[COleControlContainer::m\_siteMap](../Topic/COleControlContainer::m_siteMap.md)|O mapa do site.|  
  
## Comentários  
 Isso é feito fornecendo suporte para um ou mais sites do controle ActiveX \(implementadas por `COleControlSite`\).  `COleControlContainer` implementa totalmente [IOleInPlaceFrame](http://msdn.microsoft.com/library/windows/desktop/ms692770) e [IOleContainer](http://msdn.microsoft.com/library/windows/desktop/ms690103) interfaces, permitindo que os controles ActiveX contidos atendem às suas qualificações como itens no lugar.  
  
 Normalmente, essa classe é usada em conjunto com `COccManager` e `COleControlSite` para implementar um contêiner personalizado de controle ActiveX, com sites personalizados para um ou mais controles ActiveX.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `COleControlContainer`  
  
## Requisitos  
 **Cabeçalho:** afxocc.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleControlSite](../../mfc/reference/colecontrolsite-class.md)   
 [Classe de COccManager](../../mfc/reference/coccmanager-class.md)