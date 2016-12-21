---
title: "Classe de CMFCMenuBar | Microsoft Docs"
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
  - "CMFCMenuBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCMenuBar"
ms.assetid: 8a3ce4c7-b012-4dc0-b4f8-53c10b4b86b8
caps.latest.revision: 36
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCMenuBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma barra de menus que implementa o encaixe.  
  
## Sintaxe  
  
```  
class CMFCMenuBar : public CMFCToolbar  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCMenuBar::AdjustLocations](../Topic/CMFCMenuBar::AdjustLocations.md)|Overrides \( `CMFCToolBar::AdjustLocations`.\)|  
|[CMFCMenuBar::AllowChangeTextLabels](../Topic/CMFCMenuBar::AllowChangeTextLabels.md)|Especifica se os rótulos de texto podem ser mostradas em imagens nos botões da barra de ferramentas.  Overrides \( [CMFCToolBar::AllowChangeTextLabels](../Topic/CMFCToolBar::AllowChangeTextLabels.md).\)|  
|[CMFCMenuBar::AllowShowOnPaneMenu](../Topic/CMFCMenuBar::AllowShowOnPaneMenu.md)|Overrides \( `CPane::AllowShowOnPaneMenu`.\)|  
|[CMFCMenuBar::CalcFixedLayout](../Topic/CMFCMenuBar::CalcFixedLayout.md)|Calcula o tamanho horizontal da barra de ferramentas.  Overrides \( [CMFCToolBar::CalcFixedLayout](../Topic/CMFCToolBar::CalcFixedLayout.md).\)|  
|[CMFCMenuBar::CalcLayout](../Topic/CMFCMenuBar::CalcLayout.md)|Overrides \( `CMFCToolBar::CalcLayout`.\)|  
|[CMFCMenuBar::CalcMaxButtonHeight](../Topic/CMFCMenuBar::CalcMaxButtonHeight.md)|Calcula a altura máximo dos botões na barra de ferramentas.  Overrides \( [CMFCToolBar::CalcMaxButtonHeight](../Topic/CMFCToolBar::CalcMaxButtonHeight.md).\)|  
|[CMFCMenuBar::CanBeClosed](../Topic/CMFCMenuBar::CanBeClosed.md)|Especifica se um usuário pode fechar a barra de ferramentas.  Overrides \( [CMFCToolBar::CanBeClosed](../Topic/CMFCToolBar::CanBeClosed.md).\)|  
|[CMFCMenuBar::CanBeRestored](../Topic/CMFCMenuBar::CanBeRestored.md)|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização.  Overrides \( [CMFCToolBar::CanBeRestored](../Topic/CMFCToolBar::CanBeRestored.md).\)|  
|[CMFCMenuBar::Create](../Topic/CMFCMenuBar::Create.md)|Cria um controle de menu e anexá\-la a um objeto de `CMFCMenuBar` .|  
|[CMFCMenuBar::CreateEx](../Topic/CMFCMenuBar::CreateEx.md)|Cria um objeto de `CMFCMenuBar` com as opções adicionais de estilo.|  
|[CMFCMenuBar::CreateFromMenu](../Topic/CMFCMenuBar::CreateFromMenu.md)|Inicializa um objeto de `CMFCMenuBar` .  Aceita um parâmetro de `HMENU` que atua como um modelo para `CMFCMenuBar`preenchido.|  
|[CMFCMenuBar::EnableHelpCombobox](../Topic/CMFCMenuBar::EnableHelpCombobox.md)|Permite que uma caixa combo **Ajuda** que está localizada no lado direito da barra de menus.|  
|[CMFCMenuBar::EnableMenuShadows](../Topic/CMFCMenuBar::EnableMenuShadows.md)|Especifica se shadows para exibir menus pop\-up.|  
|[CMFCMenuBar::GetAvailableExpandSize](../Topic/CMFCMenuBar::GetAvailableExpandSize.md)|Overrides \( [CPane::GetAvailableExpandSize](../Topic/CPane::GetAvailableExpandSize.md).\)|  
|[CMFCMenuBar::GetColumnWidth](../Topic/CMFCMenuBar::GetColumnWidth.md)|Retorna a largura dos botões da barra de ferramentas.  Overrides \( [CMFCToolBar::GetColumnWidth](../Topic/CMFCToolBar::GetColumnWidth.md).\)|  
|[CMFCMenuBar::GetDefaultMenu](../Topic/CMFCMenuBar::GetDefaultMenu.md)|Retorna um identificador para o menu original no arquivo de recurso.|  
|[CMFCMenuBar::GetDefaultMenuResId](../Topic/CMFCMenuBar::GetDefaultMenuResId.md)|Retorna o identificador do recurso original para o menu no arquivo de recurso.|  
|[CMFCMenuBar::GetFloatPopupDirection](../Topic/CMFCMenuBar::GetFloatPopupDirection.md)||  
|[CMFCMenuBar::GetForceDownArrows](../Topic/CMFCMenuBar::GetForceDownArrows.md)||  
|[CMFCMenuBar::GetHelpCombobox](../Topic/CMFCMenuBar::GetHelpCombobox.md)|Retorna um ponteiro para a caixa de combinação de **Ajuda** .|  
|[CMFCMenuBar::GetHMenu](../Topic/CMFCMenuBar::GetHMenu.md)|Retorna a alça o menu que é anexado ao objeto de `CMFCMenuBar` .|  
|[CMFCMenuBar::GetMenuFont](../Topic/CMFCMenuBar::GetMenuFont.md)|Retorna a fonte global atual para objetos do menu.|  
|[CMFCMenuBar::GetMenuItem](../Topic/CMFCMenuBar::GetMenuItem.md)|Retorna o botão da barra de ferramentas associado com o índice do item.|  
|[CMFCMenuBar::GetRowHeight](../Topic/CMFCMenuBar::GetRowHeight.md)|Retorna a altura dos botões da barra de ferramentas.  Overrides \( [CMFCToolBar::GetRowHeight](../Topic/CMFCToolBar::GetRowHeight.md).\)|  
|[CMFCMenuBar::GetSystemButton](../Topic/CMFCMenuBar::GetSystemButton.md)||  
|[CMFCMenuBar::GetSystemButtonsCount](../Topic/CMFCMenuBar::GetSystemButtonsCount.md)||  
|[CMFCMenuBar::GetSystemMenu](../Topic/CMFCMenuBar::GetSystemMenu.md)||  
|[CMFCMenuBar::HighlightDisabledItems](../Topic/CMFCMenuBar::HighlightDisabledItems.md)|Indica se os itens de menu desativados estão realçados.|  
|[CMFCMenuBar::IsButtonExtraSizeAvailable](../Topic/CMFCMenuBar::IsButtonExtraSizeAvailable.md)|Determina se a barra de ferramentas pode exibir botões que estenderam bordas.  Overrides \( [CMFCToolBar::IsButtonExtraSizeAvailable](../Topic/CMFCToolBar::IsButtonExtraSizeAvailable.md).\)|  
|[CMFCMenuBar::IsHighlightDisabledItems](../Topic/CMFCMenuBar::IsHighlightDisabledItems.md)|Indica se os itens estiverem desativados realçadas.|  
|[CMFCMenuBar::IsMenuShadows](../Topic/CMFCMenuBar::IsMenuShadows.md)|Indica se as sombras são desenhadas para menus pop\-up.|  
|[CMFCMenuBar::IsRecentlyUsedMenus](../Topic/CMFCMenuBar::IsRecentlyUsedMenus.md)|Indica se os comandos de menu são exibidos recentemente usados na barra de menus.|  
|[CMFCMenuBar::IsShowAllCommands](../Topic/CMFCMenuBar::IsShowAllCommands.md)|Indica se os menus pop\-up exibe todos os comandos.|  
|[CMFCMenuBar::IsShowAllCommandsDelay](../Topic/CMFCMenuBar::IsShowAllCommandsDelay.md)|Indica se os menus exibe todos os comandos após um pequeno intervalo.|  
|[CMFCMenuBar::LoadState](../Topic/CMFCMenuBar::LoadState.md)|Carrega o estado do objeto de `CMFCMenuBar` do Registro.|  
|[CMFCMenuBar::OnChangeHot](../Topic/CMFCMenuBar::OnChangeHot.md)|Chamado pela estrutura quando um usuário seleciona um botão na barra de ferramentas.  Overrides \( [CMFCToolBar::OnChangeHot](../Topic/CMFCToolBar::OnChangeHot.md).\)|  
|[CMFCMenuBar::OnDefaultMenuLoaded](../Topic/CMFCMenuBar::OnDefaultMenuLoaded.md)|Chamado pela estrutura quando uma janela de quadro carregar o menu padrão do arquivo de recurso.|  
|[CMFCMenuBar::OnSendCommand](../Topic/CMFCMenuBar::OnSendCommand.md)|Overrides \( `CMFCToolBar::OnSendCommand`.\)|  
|[CMFCMenuBar::OnSetDefaultButtonText](../Topic/CMFCMenuBar::OnSetDefaultButtonText.md)|Chamado pela estrutura quando um menu está no modo de personalização e no usuário altera o texto de um item de menu.|  
|[CMFCMenuBar::OnToolHitTest](../Topic/CMFCMenuBar::OnToolHitTest.md)|Overrides \( `CMFCToolBar::OnToolHitTest`.\)|  
|[CMFCMenuBar::PreTranslateMessage](../Topic/CMFCMenuBar::PreTranslateMessage.md)|Overrides \( `CMFCToolBar::PreTranslateMessage`.\)|  
|[CMFCMenuBar::RestoreOriginalstate](../Topic/CMFCMenuBar::RestoreOriginalstate.md)|Chamado pela estrutura quando um menu está no modo de personalização e no usuário seleciona **Redefinir** para uma barra de menus.|  
|[CMFCMenuBar::SaveState](../Topic/CMFCMenuBar::SaveState.md)|Salvar o estado do objeto de `CMFCMenuBar` ao Registro.|  
|[CMFCMenuBar::SetDefaultMenuResId](../Topic/CMFCMenuBar::SetDefaultMenuResId.md)|Define o menu original no arquivo de recurso.|  
|[CMFCMenuBar::SetForceDownArrows](../Topic/CMFCMenuBar::SetForceDownArrows.md)||  
|[CMFCMenuBar::SetMaximizeMode](../Topic/CMFCMenuBar::SetMaximizeMode.md)|Chamado pela estrutura quando uma janela filho MDI alterar o modo de exibição.  Se a janela filho MDI é maximizada recentemente ou não maximizada, atualizações de esse método a barra de menus.|  
|[CMFCMenuBar::SetMenuButtonRTC](../Topic/CMFCMenuBar::SetMenuButtonRTC.md)|Define informações da classe de tempo de execução que é gerada quando o usuário cria dinamicamente os botões de menu.|  
|[CMFCMenuBar::SetMenuFont](../Topic/CMFCMenuBar::SetMenuFont.md)|Define a fonte para todos os menus no aplicativo.|  
|[CMFCMenuBar::SetRecentlyUsedMenus](../Topic/CMFCMenuBar::SetRecentlyUsedMenus.md)|Especifica se uma barra de menu exibe comandos de menu utilizados mais recentemente.|  
|[CMFCMenuBar::SetShowAllCommands](../Topic/CMFCMenuBar::SetShowAllCommands.md)|Especifica se a barra de menus mostra todos os comandos.|  
  
## Comentários  
 A classe de `CMFCMenuBar` é uma barra de menus que implementa a funcionalidade de encaixe.  É semelhante a uma barra de ferramentas, embora não pode ser fechada \- sempre é exibida.  
  
 `CMFCMenuBar` oferece suporte à opção de exibir objetos utilizados mais recentemente de item de menu.  Se esta opção estiver ativada, `CMFCMenuBar` exibe somente um subconjunto dos comandos disponíveis na primeira exibição.  Depois de isso, os comandos usados são exibidos recentemente juntamente com o subconjunto original de comandos.  Além de isso, o usuário pode sempre expanda o menu para exibir todos os comandos disponíveis.  Assim, cada comando disponível está configurado para exibir constantemente, ou exibir somente se ele tiver sido recentemente selecionado.  
  
 Para usar um objeto de `CMFCMenuBar` , incorporar\-lo no objeto de moldura da janela principal.  A o processar a mensagem de `WM_CREATE` , chame `CMFCMenuBar::Create` ou `CMFCMenuBar::CreateEx`.  Independentemente de quais o criar a função que você usa, passe em um ponteiro para a janela de quadro chave.  Ativar no encaixe chamando [CFrameWndEx::EnableDocking](../Topic/CFrameWndEx::EnableDocking.md).  Entre este menu chamando [CFrameWndEx::DockPane](../Topic/CFrameWndEx::DockPane.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCMenuBar` .  O exemplo a seguir mostra como definir o estilo de painel, active o botão personalizar, ativar uma caixa da ajuda, como para ativar menus pop\-up, e atualizar a barra de menus.  Este trecho de código é parte de [Exemplo de demonstração de IE](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo#1](../../mfc/reference/codesnippet/CPP/cmfcmenubar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo#3](../../mfc/reference/codesnippet/CPP/cmfcmenubar-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxmenubar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)