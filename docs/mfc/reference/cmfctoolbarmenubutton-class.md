---
title: "Classe de CMFCToolBarMenuButton | Microsoft Docs"
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
  - "CMFCToolBarMenuButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarMenuButton"
ms.assetid: cfa50176-7e4b-4527-9904-86a1b48fc1bc
caps.latest.revision: 31
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarMenuButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um botão na barra de ferramentas que contém um menu pop\-up.  
  
## Sintaxe  
  
```  
class CMFCToolBarMenuButton : public CMFCToolBarButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarMenuButton::CMFCToolBarMenuButton](../Topic/CMFCToolBarMenuButton::CMFCToolBarMenuButton.md)|Constrói um objeto de `CMFCToolBarMenuButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarMenuButton::CompareWith](../Topic/CMFCToolBarMenuButton::CompareWith.md)|Compara com essa instância do objeto fornecido `CMFCToolBarButton` .  Overrides \( [CMFCToolBarButton::CompareWith](../Topic/CMFCToolBarButton::CompareWith.md).\)|  
|[CMFCToolBarMenuButton::CopyFrom](../Topic/CMFCToolBarMenuButton::CopyFrom.md)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual.  Overrides \( [CMFCToolBarButton::CopyFrom](../Topic/CMFCToolBarButton::CopyFrom.md).\)|  
|[CMFCToolBarMenuButton::CreateFromMenu](../Topic/CMFCToolBarMenuButton::CreateFromMenu.md)|Inicializa o menu da barra de ferramentas de um identificador do menu do windows.|  
|[CMFCToolBarMenuButton::CreateMenu](../Topic/CMFCToolBarMenuButton::CreateMenu.md)|Cria um menu do windows que consiste nos comandos no menu da barra de ferramentas.  Retorna um identificador para o menu do windows.|  
|[CMFCToolBarMenuButton::CreatePopupMenu](../Topic/CMFCToolBarMenuButton::CreatePopupMenu.md)|Cria um objeto de menus pop\-up \([Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md)\) para exibir o menu da barra de ferramentas.|  
|[CMFCToolBarMenuButton::EnableQuickCustomize](../Topic/CMFCToolBarMenuButton::EnableQuickCustomize.md)||  
|[CMFCToolBarMenuButton::GetCommands](../Topic/CMFCToolBarMenuButton::GetCommands.md)|Fornece acesso somente leitura à lista de comandos no menu da barra de ferramentas.|  
|[CMFCToolBarMenuButton::GetImageRect](../Topic/CMFCToolBarMenuButton::GetImageRect.md)|Recupera o retângulo delimitador para a imagem do botão.|  
|[CMFCToolBarMenuButton::GetPaletteRows](../Topic/CMFCToolBarMenuButton::GetPaletteRows.md)|Retorna o número de linhas no menu pop\-up quando o menu está no modo de paleta.|  
|[CMFCToolBarMenuButton::GetPopupMenu](../Topic/CMFCToolBarMenuButton::GetPopupMenu.md)|Retorna um ponteiro para o objeto de menus pop\-up que está associado com o botão.|  
|[CMFCToolBarMenuButton::HasButton](../Topic/CMFCToolBarMenuButton::HasButton.md)||  
|[CMFCToolBarMenuButton::HaveHotBorder](../Topic/CMFCToolBarMenuButton::HaveHotBorder.md)|Determina se uma borda do botão é exibida quando um usuário selecione.  Overrides \( [CMFCToolBarButton::HaveHotBorder](../Topic/CMFCToolBarButton::HaveHotBorder.md).\)|  
|[CMFCToolBarMenuButton::IsBorder](../Topic/CMFCToolBarMenuButton::IsBorder.md)||  
|[CMFCToolBarMenuButton::IsClickedOnMenu](../Topic/CMFCToolBarMenuButton::IsClickedOnMenu.md)||  
|[CMFCToolBarMenuButton::IsDroppedDown](../Topic/CMFCToolBarMenuButton::IsDroppedDown.md)|Determina se o menu pop\-up é exibida.|  
|[CMFCToolBarMenuButton::IsEmptyMenuAllowed](../Topic/CMFCToolBarMenuButton::IsEmptyMenuAllowed.md)|Chamado pela estrutura para determinar se um usuário pode abrir um submenu de item de menu selecionado.|  
|[CMFCToolBarMenuButton::IsExclusive](../Topic/CMFCToolBarMenuButton::IsExclusive.md)|Determina se o botão está no modo exclusivo, isto é, se o menu pop\-up permanece aberto mesmo quando o usuário move o ponteiro sobre outra barra de ferramentas ou botão.|  
|[CMFCToolBarMenuButton::IsMenuPaletteMode](../Topic/CMFCToolBarMenuButton::IsMenuPaletteMode.md)|Determina se o menu pop\-up estiver no modo de paleta.|  
|[CMFCToolBarMenuButton::IsQuickMode](../Topic/CMFCToolBarMenuButton::IsQuickMode.md)||  
|[CMFCToolBarMenuButton::IsTearOffMenu](../Topic/CMFCToolBarMenuButton::IsTearOffMenu.md)|Determina se o menu pop\-up tem uma barra de rasgo \- fora.|  
|[CMFCToolBarMenuButton::OnAfterCreatePopupMenu](../Topic/CMFCToolBarMenuButton::OnAfterCreatePopupMenu.md)||  
|[CMFCToolBarMenuButton::OnBeforeDrag](../Topic/CMFCToolBarMenuButton::OnBeforeDrag.md)|Especifica se o botão pode ser arrastado.  Overrides \( [CMFCToolBarButton::OnBeforeDrag](../Topic/CMFCToolBarButton::OnBeforeDrag.md).\)|  
|[CMFCToolBarMenuButton::OnCalculateSize](../Topic/CMFCToolBarMenuButton::OnCalculateSize.md)|Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo e o estado de encaixe especificados.  Overrides \( [CMFCToolBarButton::OnCalculateSize](../Topic/CMFCToolBarButton::OnCalculateSize.md).\)|  
|[CMFCToolBarMenuButton::OnCancelMode](../Topic/CMFCToolBarMenuButton::OnCancelMode.md)|Chamado pela estrutura para manipular a mensagem de [WM\_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) .  Overrides \( [CMFCToolBarButton::OnCancelMode](../Topic/CMFCToolBarButton::OnCancelMode.md).\)|  
|[CMFCToolBarMenuButton::OnChangeParentWnd](../Topic/CMFCToolBarMenuButton::OnChangeParentWnd.md)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.  Overrides \( [CMFCToolBarButton::OnChangeParentWnd](../Topic/CMFCToolBarButton::OnChangeParentWnd.md).\)|  
|[CMFCToolBarMenuButton::OnClick](../Topic/CMFCToolBarMenuButton::OnClick.md)|Chamado pela estrutura quando o usuário clica no botão do mouse.  Overrides \( [CMFCToolBarButton::OnClick](../Topic/CMFCToolBarButton::OnClick.md).\)|  
|[CMFCToolBarMenuButton::OnClickMenuItem](../Topic/CMFCToolBarMenuButton::OnClickMenuItem.md)|Chamado pela estrutura quando o usuário seleciona um item no menu pop\-up.|  
|[CMFCToolBarMenuButton::OnContextHelp](../Topic/CMFCToolBarMenuButton::OnContextHelp.md)|Chamado pela estrutura quando a barra de ferramentas pai manipular uma mensagem de `WM_HELPHITTEST` .  Overrides \( [CMFCToolBarButton::OnContextHelp](../Topic/CMFCToolBarButton::OnContextHelp.md).\)|  
|[CMFCToolBarMenuButton::OnDraw](../Topic/CMFCToolBarMenuButton::OnDraw.md)|Chamado pela estrutura para desenhar o botão usando os estilos e opções especificadas.  Overrides \( [CMFCToolBarButton::OnDraw](../Topic/CMFCToolBarButton::OnDraw.md).\)|  
|[CMFCToolBarMenuButton::OnDrawOnCustomizeList](../Topic/CMFCToolBarMenuButton::OnDrawOnCustomizeList.md)|Chamado pela estrutura para desenhar o botão no painel de **Comandos** da caixa de diálogo de **Personalizar** .  Overrides \( [CMFCToolBarButton::OnDrawOnCustomizeList](../Topic/CMFCToolBarButton::OnDrawOnCustomizeList.md).\)|  
|[CMFCToolBarMenuButton::OpenPopupMenu](../Topic/CMFCToolBarMenuButton::OpenPopupMenu.md)|Chamado pela estrutura quando o usuário abra o menu pop\-up.|  
|[CMFCToolBarMenuButton::ResetImageToDefault](../Topic/CMFCToolBarMenuButton::ResetImageToDefault.md)|Defina o valor padrão a imagem que está associada com o botão.  Overrides \( [CMFCToolBarButton::ResetImageToDefault](../Topic/CMFCToolBarButton::ResetImageToDefault.md).\)|  
|[CMFCToolBarMenuButton::SaveBarState](../Topic/CMFCToolBarMenuButton::SaveBarState.md)|Salvar o estado do botão da barra de ferramentas.  Overrides \( [CMFCToolBarButton::SaveBarState](../Topic/CMFCToolBarButton::SaveBarState.md).\)|  
|[CMFCToolBarMenuButton::Serialize](../Topic/CMFCToolBarMenuButton::Serialize.md)|Este objeto ler de um arquivo ou neutro o grava em um arquivo neutro.  Overrides \( [CMFCToolBarButton::Serialize](../Topic/CMFCToolBarButton::Serialize.md).\)|  
|[CMFCToolBarMenuButton::SetACCData](../Topic/CMFCToolBarMenuButton::SetACCData.md)|Preenche o objeto fornecido de `CAccessibilityData` com dados de acessibilidade do botão da barra de ferramentas.  Overrides \( [CMFCToolBarButton::SetACCData](../Topic/CMFCToolBarButton::SetACCData.md).\)|  
|[CMFCToolBarMenuButton::SetMenuOnly](../Topic/CMFCToolBarMenuButton::SetMenuOnly.md)|Especifica se o botão pode ser adicionado a uma barra de ferramentas.|  
|[CMFCToolBarMenuButton::SetMenuPaletteMode](../Topic/CMFCToolBarMenuButton::SetMenuPaletteMode.md)|Especifica se o menu pop\-up estiver no modo de paleta.|  
|[CMFCToolBarMenuButton::SetMessageWnd](../Topic/CMFCToolBarMenuButton::SetMessageWnd.md)||  
|[CMFCToolBarMenuButton::SetRadio](../Topic/CMFCToolBarMenuButton::SetRadio.md)|Força o botão de menu da barra de ferramentas para exibir um ícone que indica que está selecionado.|  
|[CMFCToolBarMenuButton::SetTearOff](../Topic/CMFCToolBarMenuButton::SetTearOff.md)|Especifica uma identificação de barra de rasgo \- fora do menu pop\-up.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarMenuButton::DrawDocumentIcon](../Topic/CMFCToolBarMenuButton::DrawDocumentIcon.md)|Desenha um ícone no botão de menu.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarMenuButton::m\_bAlwaysCallOwnerDraw](../Topic/CMFCToolBarMenuButton::m_bAlwaysCallOwnerDraw.md)|Se `TRUE`, a estrutura chama sempre [CFrameWndEx::OnDrawMenuImage](../Topic/CFrameWndEx::OnDrawMenuImage.md) quando um botão é desenhado.|  
  
## Comentários  
 `CMFCToolBarMenuButton` pode aparecer como um menu, um item de menu que tenha um submenu, um botão que executa um comando ou exibir um menu, ou um botão que exibe somente um menu.  Você determina o comportamento e a aparência do botão de menu especificando parâmetros como a imagem, texto, o identificador do menu, e a identificação de comando que está associado com o botão no construtor `CMFCToolbarMenuButton::CMFCToolbarMenuButton`.  
  
 Uma classe personalizada derivada da classe de `CMFCToolbarMenuButton` deve usar a macro de [DECLARE\_SERIAL](../Topic/DECLARE_SERIAL.md) .  A macro de [DECLARE\_DYNCREATE](../Topic/DECLARE_DYNCREATE.md) gera um erro quando o aplicativo for fechado.  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um objeto de `CMFCToolBarMenuButton` .  O código a seguir ilustra como especificar que o menu drop\-down estiver no modo de paleta, e especificar a identificação para a barra de rasgo \- fora que é criado quando o usuário arrasta o botão de menu fora de uma barra de menus.  Este trecho de código é parte de [Exemplo de preenchimento da palavra](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#10](../../mfc/reference/codesnippet/CPP/cmfctoolbarmenubutton-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtoolbarmenubutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCPopupMenu](../Topic/CMFCPopupMenu%20Class.md)