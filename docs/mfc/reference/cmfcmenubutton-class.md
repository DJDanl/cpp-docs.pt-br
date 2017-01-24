---
title: "Classe CMFCMenuButton | Microsoft Docs"
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
  - "CMFCMenuButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMFCMenuButton"
ms.assetid: 53d3d459-1e5a-47c5-8b7f-2e61f6af5187
caps.latest.revision: 32
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CMFCMenuButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um botão que exibe um menu pop\-up e o reportar as seleções de menu do usuário.  
  
## Sintaxe  
  
```  
class CMFCMenuButton : public CMFCButton  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCMenuButton::CMFCMenuButton](../Topic/CMFCMenuButton::CMFCMenuButton.md)|Constrói um objeto de `CMFCMenuButton` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCMenuButton::PreTranslateMessage](../Topic/CMFCMenuButton::PreTranslateMessage.md)|Chamado pela estrutura para converter mensagens de janela antes que são distribuídos.  Overrides \( `CMFCButton::PreTranslateMessage`.\)|  
|[CMFCMenuButton::SizeToContent](../Topic/CMFCMenuButton::SizeToContent.md)|Altera o tamanho do botão de acordo com o tamanho do texto e da imagem.|  
  
### Membros de Dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCMenuButton::m\_bOSMenu](../Topic/CMFCMenuButton::m_bOSMenu.md)|Especifica se exibir o menu pop\-up padrão do sistema ou usar [CContextMenuManager::TrackPopupMenu](../Topic/CContextMenuManager::TrackPopupMenu.md).|  
|[CMFCMenuButton::m\_bRightArrow](../Topic/CMFCMenuButton::m_bRightArrow.md)|Especifica se do menu pop\-up aparecerá sob ou à direita do botão.|  
|[CMFCMenuButton::m\_bStayPressed](../Topic/CMFCMenuButton::m_bStayPressed.md)|Especifica se o botão de menu altera o estado após o usuário solta o botão.|  
|[CMFCMenuButton::m\_hMenu](../Topic/CMFCMenuButton::m_hMenu.md)|Um identificador para o menu do Windows anexado.|  
|[CMFCMenuButton::m\_nMenuResult](../Topic/CMFCMenuButton::m_nMenuResult.md)|Um identificador que indica que o usuário selecionou item de menu pop\-up.|  
  
## Comentários  
 A classe de `CMFCMenuButton` é derivada de [Classe de CMFCButton](../../mfc/reference/cmfcbutton-class.md) , que, por sua vez é derivada de [Classe de CButton](../../mfc/reference/cbutton-class.md).  Como consequência, você pode usar `CMFCMenuButton` no seu código da mesma maneira que você usaria `CButton`.  
  
 Quando você cria `CMFCMenuButton`, você deve passar em um identificador para o menu pop\-up associado.  Em seguida, chama a função `CMFCMenuButton::SizeToContent`.  verificações de`CMFCMenuButton::SizeToContent` que o tamanho do botão é suficiente para incluir uma seta que aponta para o local onde a janela pop\-up aparecerá \- isto, sob ou à direita do botão.  
  
## Exemplo  
 O exemplo a seguir demonstra como definir a alça de menu anexado ao botão, redimensionar o botão de acordo com o tamanho do texto e da imagem, e defina o menu pop\-up que é exibido pela estrutura.  Este trecho de código é parte de [Novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#38](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#38)]  
[!CODE [NVC_MFC_NewControls#39](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#39)]  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCButton](../../mfc/reference/cmfcbutton-class.md)  
  
 [CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxmenubutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCButton](../../mfc/reference/cmfcbutton-class.md)