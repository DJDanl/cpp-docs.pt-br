---
title: "Classe de CBasePane | Microsoft Docs"
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
  - "CBasePane::get_accKeyboardShortcut"
  - "CBasePane.get_accKeyboardShortcut"
  - "CBasePane.accSelect"
  - "get_accDefaultAction"
  - "accSelect"
  - "CBasePane.accHitTest"
  - "CBasePane.get_accRole"
  - "get_accKeyboardShortcut"
  - "CBasePane::Serialize"
  - "CBasePane"
  - "CBasePane::get_accDefaultAction"
  - "get_accParent"
  - "CBasePane::accSelect"
  - "accLocation"
  - "CBasePane.get_accDescription"
  - "get_accName"
  - "CBasePane::get_accChildCount"
  - "CBasePane.get_accChild"
  - "CBasePane::accHitTest"
  - "accHitTest"
  - "get_accHelp"
  - "CBasePane.get_accChildCount"
  - "CBasePane.get_accValue"
  - "CBasePane::get_accDescription"
  - "get_accChildCount"
  - "CBasePane.accLocation"
  - "CBasePane.PreTranslateMessage"
  - "CBasePane.get_accName"
  - "PreTranslateMessage"
  - "CBasePane::get_accFocus"
  - "get_accDescription"
  - "CBasePane::get_accRole"
  - "get_accValue"
  - "CBasePane.Serialize"
  - "CBasePane::accLocation"
  - "get_accRole"
  - "CBasePane::get_accChild"
  - "get_accFocus"
  - "CBasePane::get_accHelp"
  - "CBasePane.get_accDefaultAction"
  - "CBasePane.get_accHelp"
  - "CBasePane::PreTranslateMessage"
  - "CBasePane::get_accState"
  - "CBasePane.get_accParent"
  - "CBasePane::get_accParent"
  - "get_accChild"
  - "CBasePane::get_accValue"
  - "Serialize"
  - "get_accState"
  - "CBasePane.get_accState"
  - "CBasePane.get_accFocus"
  - "CBasePane::get_accName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "o método mais accHitTest"
  - "método de accLocation"
  - "método de accSelect"
  - "Classe de CBasePane"
  - "método de get_accChild"
  - "método de get_accChildCount"
  - "método de get_accDefaultAction"
  - "método de get_accDescription"
  - "método de get_accFocus"
  - "método de get_accHelp"
  - "método de get_accKeyboardShortcut"
  - "método de get_accName"
  - "método get_accParent"
  - "método de get_accRole"
  - "método de get_accState"
  - "método de get_accValue"
  - "Método de PreTranslateMessage"
  - "Método serialize"
ms.assetid: 8163dd51-d7c7-4def-9c74-61f8ecdfad82
caps.latest.revision: 43
caps.handback.revision: 32
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CBasePane
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Classe base para todos os painéis no MFC.  
  
## Sintaxe  
  
```  
class CBasePane : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CBasePane::CBasePane`|Construtor padrão.|  
|`CBasePane::~CBasePane`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CBasePane::accHitTest`|Chamado pela estrutura para recuperar o elemento filho ou o objeto filho em um determinado ponto na tela.  Overrides \( [CWnd::accHitTest](../Topic/CWnd::accHitTest.md).\)|  
|`CBasePane::accLocation`|Chamado pela estrutura para recuperar o local atual da tela para o objeto especificado.  Overrides \( [CWnd::accLocation](../Topic/CWnd::accLocation.md).\)|  
|[CBasePane::AccNotifyObjectFocusEvent](../Topic/CBasePane::AccNotifyObjectFocusEvent.md)|`CBasePane` não usa esse método.|  
|`CBasePane::accSelect`|Chamado pela estrutura para alterar a seleção ou mover o foco do teclado do objeto especificado.  Overrides \( [CWnd::accSelect](../Topic/CWnd::accSelect.md).\)|  
|[CBasePane::AddPane](../Topic/CBasePane::AddPane.md)|Adiciona um painel para o gerenciador de encaixe.|  
|[CBasePane::AdjustDockingLayout](../Topic/CBasePane::AdjustDockingLayout.md)|Redireciona uma chamada para o gerenciador de encaixe para ajustar o layout de encaixe.|  
|[CBasePane::AdjustLayout](../Topic/CBasePane::AdjustLayout.md)|Chamado pela estrutura quando o painel deve ajustar seu layout interno.|  
|[CBasePane::CalcFixedLayout](../Topic/CBasePane::CalcFixedLayout.md)|Calcula o tamanho horizontal de uma barra de controle.|  
|[CBasePane::CanAcceptPane](../Topic/CBasePane::CanAcceptPane.md)|Determina se outro painel puder ser encaixado no painel.|  
|[CBasePane::CanAutoHide](../Topic/CBasePane::CanAutoHide.md)|Determina se o painel suporta modo automático ocultar de.|  
|[CBasePane::CanBeAttached](../Topic/CBasePane::CanBeAttached.md)|Determina se o painel pode ser conectado a um outro painel.|  
|[CBasePane::CanBeClosed](../Topic/CBasePane::CanBeClosed.md)|Determina se o painel puder ser fechado.|  
|[CBasePane::CanBeDocked](../Topic/CBasePane::CanBeDocked.md)|Determina se o painel pode ser conectado a um outro painel.|  
|[CBasePane::CanBeResized](../Topic/CBasePane::CanBeResized.md)|Determina se o painel pode ser redimensionado.|  
|[CBasePane::CanBeTabbedDocument](../Topic/CBasePane::CanBeTabbedDocument.md)|Especifica se o painel puder ser convertido em um documento listado MDI.|  
|[CBasePane::CanFloat](../Topic/CBasePane::CanFloat.md)|Determina se o painel puder flutuante.|  
|[CBasePane::CanFocus](../Topic/CBasePane::CanFocus.md)|Especifica se o painel pode receber o foco.|  
|[CBasePane::CopyState](../Topic/CBasePane::CopyState.md)|Copia o estado de um determinado painel.|  
|[CBasePane::CreateDefaultMiniframe](../Topic/CBasePane::CreateDefaultMiniframe.md)|Se o painel pode posicioná\-la tanto, cria uma janela de mini\-linguagem quadro.|  
|[CBasePane::CreateEx](../Topic/CBasePane::CreateEx.md)|Cria o painel de controle.|  
|[CBasePane::DockPane](../Topic/CBasePane::DockPane.md)|Insere um painel para outro painel ou a uma janela do quadro.|  
|[CBasePane::DockPaneUsingRTTI](../Topic/CBasePane::DockPaneUsingRTTI.md)|Insere o painel usando informações de tipo em tempo de execução.|  
|[CBasePane::DockToFrameWindow](../Topic/CBasePane::DockToFrameWindow.md)|Insere um painel encaixável a um quadro.|  
|[CBasePane::DoesAllowDynInsertBefore](../Topic/CBasePane::DoesAllowDynInsertBefore.md)|Determina se outro painel dinamicamente pode ser inserido entre esse painel e o elemento pai.|  
|[CBasePane::EnableDocking](../Topic/CBasePane::EnableDocking.md)|Permite que o encaixe do painel para o quadro chave.|  
|[CBasePane::EnableGripper](../Topic/CBasePane::EnableGripper.md)|Habilita ou desabilita a alça.  Se a alça é ativado, o usuário pode arrastá\-lo para reposicionar o painel.|  
|`CBasePane::FillWindowRect`|Usado internamente.|  
|[CBasePane::FloatPane](../Topic/CBasePane::FloatPane.md)|Flutua o painel.|  
|`CBasePane::get_accChild`|Chamado pela estrutura para recuperar o endereço de uma interface de `IDispatch` para o filho especificado.  Overrides \( [CWnd::get\_accChild](../Topic/CWnd::get_accChild.md).\)|  
|`CBasePane::get_accChildCount`|Chamado pela estrutura para recuperar o número de filhos que pertencem a esse objeto.  Overrides \( [CWnd::get\_accChildCount](../Topic/CWnd::get_accChildCount.md).\)|  
|`CBasePane::get_accDefaultAction`|Chamado pela estrutura para recuperar uma cadeia de caracteres que descreve a ação padrão para o objeto.  Overrides \( [CWnd::get\_accDefaultAction](../Topic/CWnd::get_accDefaultAction.md).\)|  
|`CBasePane::get_accDescription`|Chamado pela estrutura para recuperar uma cadeia de caracteres que descreve a aparência visual do objeto especificado.  Overrides \( [CWnd::get\_accDescription](../Topic/CWnd::get_accDescription.md).\)|  
|`CBasePane::get_accFocus`|Chamado pela estrutura para recuperar o objeto que tem o foco do teclado.  Overrides \( [CWnd::get\_accFocus](../Topic/CWnd::get_accFocus.md).\)|  
|`CBasePane::get_accHelp`|Chamado pela estrutura para recuperar uma cadeia de caracteres da propriedade da ajuda para o objeto.  Overrides \( [CWnd::get\_accHelp](../Topic/CWnd::get_accHelp.md).\)|  
|[CBasePane::get\_accHelpTopic](../Topic/CBasePane::get_accHelpTopic.md)|Chamado pela estrutura para recuperar o caminho completo deWinHelpfile que é associado ao objeto especificado e o identificador do tópico apropriado no arquivo.  Overrides \( [CWnd::get\_accHelpTopic](../Topic/CWnd::get_accHelpTopic.md).\)|  
|`CBasePane::get_accKeyboardShortcut`|Chamado pela estrutura para recuperar a tecla de atalho especificada para o objeto.  Overrides \( [CWnd::get\_accKeyboardShortcut](../Topic/CWnd::get_accKeyboardShortcut.md).\)|  
|`CBasePane::get_accName`|Chamado pela estrutura para recuperar o nome do objeto especificado.  Overrides \( [CWnd::get\_accName](../Topic/CWnd::get_accName.md).\)|  
|`CBasePane::get_accParent`|Chamado pela estrutura para recuperar a interface de `IDispatch` para o pai do objeto.  Overrides \( [CWnd::get\_accParent](../Topic/CWnd::get_accParent.md).\)|  
|`CBasePane::get_accRole`|Chamado pela estrutura para recuperar informações que descrevem a função do objeto especificado.  Overrides \( [CWnd::get\_accRole](../Topic/CWnd::get_accRole.md).\)|  
|[CBasePane::get\_accSelection](../Topic/CBasePane::get_accSelection.md)|Chamado pela estrutura para recuperar os filhos de este objeto selecionados.  Overrides \( [CWnd::get\_accSelection](../Topic/CWnd::get_accSelection.md).\)|  
|`CBasePane::get_accState`|Chamado pela estrutura para recuperar o estado atual do objeto especificado.  Overrides \( [CWnd::get\_accState](../Topic/CWnd::get_accState.md).\)|  
|`CBasePane::get_accValue`|Chamado pela estrutura para recuperar o valor do objeto especificado.  Overrides \( [CWnd::get\_accValue](../Topic/CWnd::get_accValue.md).\)|  
|[CBasePane::GetCaptionHeight](../Topic/CBasePane::GetCaptionHeight.md)|Retorna a altura da barra de título.|  
|[CBasePane::GetControlBarStyle](../Topic/CBasePane::GetControlBarStyle.md)|Retorna o estilo da barra de controle.|  
|[CBasePane::GetCurrentAlignment](../Topic/CBasePane::GetCurrentAlignment.md)|Retorna o alinhamento atual do painel.|  
|[CBasePane::GetDockingMode](../Topic/CBasePane::GetDockingMode.md)|Retorna o modo atual de encaixe para o painel.|  
|[CBasePane::GetDockSiteFrameWnd](../Topic/CBasePane::GetDockSiteFrameWnd.md)|Retorna um ponteiro para a janela que é o site de encaixe para o painel.|  
|[CBasePane::GetEnabledAlignment](../Topic/CBasePane::GetEnabledAlignment.md)|Retorna os estilos de CBRS\_ALIGN\_ que são aplicados para o painel.|  
|[CBasePane::GetMFCStyle](../Topic/CBasePane::GetMFCStyle.md)|Retorna os estilos do painel específicos para MFC.|  
|[CBasePane::GetPaneIcon](../Topic/CBasePane::GetPaneIcon.md)|Retorna um identificador para o ícone do painel.|  
|`CBasePane::GetPaneRect`|Usado internamente.|  
|[CBasePane::GetPaneRow](../Topic/CBasePane::GetPaneRow.md)|Retorna um ponteiro para o objeto de [CDockingPanesRow](../../mfc/reference/cdockingpanesrow-class.md)onde o painel é conectado.|  
|[CBasePane::GetPaneStyle](../Topic/CBasePane::GetPaneStyle.md)|Retorna o estilo de painel.|  
|[CBasePane::GetParentDockSite](../Topic/CBasePane::GetParentDockSite.md)|Retorna um ponteiro para o site pai da plataforma.|  
|[CBasePane::GetParentMiniFrame](../Topic/CBasePane::GetParentMiniFrame.md)|Retorna um ponteiro para a janela pai de mini\-linguagem quadro.|  
|[CBasePane::GetParentTabbedPane](../Topic/CBasePane::GetParentTabbedPane.md)|Retorna um ponteiro para o painel pai com guias.|  
|[CBasePane::GetParentTabWnd](../Topic/CBasePane::GetParentTabWnd.md)|Retorna um ponteiro para a janela pai que está dentro de um guia.|  
|[CBasePane::GetRecentVisibleState](../Topic/CBasePane::GetRecentVisibleState.md)|A estrutura chama esse método quando um painel é restaurado de um arquivo neutro.|  
|[CBasePane::HideInPrintPreviewMode](../Topic/CBasePane::HideInPrintPreviewMode.md)|Especifica se o painel está oculto no visualizador de impressão.|  
|[CBasePane::InsertPane](../Topic/CBasePane::InsertPane.md)|Registra o painel especificado com o gerenciador de encaixe.|  
|[CBasePane::IsAccessibilityCompatible](../Topic/CBasePane::IsAccessibilityCompatible.md)|Especifica se o painel oferece suporte a acessibilidade.|  
|[CBasePane::IsAutoHideMode](../Topic/CBasePane::IsAutoHideMode.md)|Determina se um painel está no modo automático ocultar de.|  
|[CBasePane::IsDialogControl](../Topic/CBasePane::IsDialogControl.md)|Especifica se o painel é um controle de caixa de diálogo.|  
|[CBasePane::IsDocked](../Topic/CBasePane::IsDocked.md)|Determina se o painel está conectado.|  
|[CBasePane::IsFloating](../Topic/CBasePane::IsFloating.md)|Determina se o painel é flutuantes.|  
|[CBasePane::IsHorizontal](../Topic/CBasePane::IsHorizontal.md)|Determina se o painel estiver conectado horizontalmente.|  
|[CBasePane::IsInFloatingMultiPaneFrameWnd](../Topic/CBasePane::IsInFloatingMultiPaneFrameWnd.md)|Especifica se o painel em uma janela de quadro chave com multipainéis.|  
|[CBasePane::IsMDITabbed](../Topic/CBasePane::IsMDITabbed.md)|Determina se o painel foi adicionado a uma janela filho MDI como um documento com guias.|  
|[CBasePane::IsPaneVisible](../Topic/CBasePane::IsPaneVisible.md)|Especifica se o sinalizador de `WS_VISIBLE` é definido para o painel.|  
|[CBasePane::IsPointNearDockSite](../Topic/CBasePane::IsPointNearDockSite.md)|Determina se um ponto está especificado pelo site da plataforma.|  
|[CBasePane::IsResizable](../Topic/CBasePane::IsResizable.md)|Determina se o painel pode ser redimensionado.|  
|[CBasePane::IsRestoredFromRegistry](../Topic/CBasePane::IsRestoredFromRegistry.md)|Determina se o painel é restaurado do Registro.|  
|[CBasePane::IsTabbed](../Topic/CBasePane::IsTabbed.md)|Determina se o painel foi inserido no controle de guias de uma janela com guias.|  
|`CBasePane::IsTooltipTopmost`|Usado internamente.|  
|[CBasePane::IsVisible](../Topic/CBasePane::IsVisible.md)|Determina se o painel é visível.|  
|[CBasePane::LoadState](../Topic/CBasePane::LoadState.md)|Carrega o estado do painel do Registro.|  
|[CBasePane::MoveWindow](../Topic/CBasePane::MoveWindow.md)|Move o painel.|  
|[CBasePane::OnAfterChangeParent](../Topic/CBasePane::OnAfterChangeParent.md)|Chamado pela estrutura quando o pai do painel é modificado.|  
|[CBasePane::OnBeforeChangeParent](../Topic/CBasePane::OnBeforeChangeParent.md)|Chamado pela estrutura imediatamente antes do painel muda sua janela pai.|  
|[CBasePane::OnDrawCaption](../Topic/CBasePane::OnDrawCaption.md)|A estrutura chama esse método quando a legenda é desenhada.|  
|[CBasePane::OnMovePaneDivider](../Topic/CBasePane::OnMovePaneDivider.md)|Este método não é usado atualmente.|  
|[CBasePane::OnPaneContextMenu](../Topic/CBasePane::OnPaneContextMenu.md)|Chamado pela estrutura quando criar um menu que tenha uma lista de painéis.|  
|[CBasePane::OnRemoveFromMiniFrame](../Topic/CBasePane::OnRemoveFromMiniFrame.md)|Chamado pela estrutura quando um painel é removido da sua mini janela pai do quadro.|  
|[CBasePane::OnSetAccData](../Topic/CBasePane::OnSetAccData.md)|`CBasePane` não usa esse método.|  
|`CBasePane::OnUpdateCmdUI`|Usado internamente.|  
|[CBasePane::PaneFromPoint](../Topic/CBasePane::PaneFromPoint.md)|Retorna o painel que contém o ponto especificado.|  
|`CBasePane::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) transladar mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).\)|  
|[CBasePane::RecalcLayout](../Topic/CBasePane::RecalcLayout.md)|`CBasePane` não usa esse método.|  
|[CBasePane::RemovePaneFromDockManager](../Topic/CBasePane::RemovePaneFromDockManager.md)|Desregistre um painel e remova\-o da lista no gerenciador de encaixe.|  
|[CBasePane::SaveState](../Topic/CBasePane::SaveState.md)|Salvar o estado do painel no Registro.|  
|[CBasePane::SelectDefaultFont](../Topic/CBasePane::SelectDefaultFont.md)|Seleciona a fonte padrão para um determinado contexto de dispositivo.|  
|`CBasePane::Serialize`|Leitura ou grava este objeto ou um arquivo neutro.  Overrides \( [CObject::Serialize](../Topic/CObject::Serialize.md).\)|  
|[CBasePane::SetControlBarStyle](../Topic/CBasePane::SetControlBarStyle.md)|Defina o estilo da barra de controle.|  
|[CBasePane::SetDockingMode](../Topic/CBasePane::SetDockingMode.md)|Defina o modo de encaixe para o painel.|  
|`CBasePane::SetMDITabbed`|Usado internamente.|  
|[CBasePane::SetPaneAlignment](../Topic/CBasePane::SetPaneAlignment.md)|Define o alinhamento para o painel.|  
|`CBasePane::SetPaneRect`|Usado internamente.|  
|[CBasePane::SetPaneStyle](../Topic/CBasePane::SetPaneStyle.md)|Defina o estilo de painel.|  
|`CBasePane::SetRestoredFromRegistry`|Usado internamente.|  
|[CBasePane::SetWindowPos](../Topic/CBasePane::SetWindowPos.md)|Altera o tamanho, posição, e a ordem z de um painel.|  
|[CBasePane::ShowPane](../Topic/CBasePane::ShowPane.md)|Mostra ou oculta o painel.|  
|[CBasePane::StretchPane](../Topic/CBasePane::StretchPane.md)|Um painel expande horizontalmente ou verticalmente.|  
|[CBasePane::UndockPane](../Topic/CBasePane::UndockPane.md)|Remove o painel do site da plataforma, padrão de controle deslizante, ou da janela de mini\-linguagem quadro onde está conectado no momento.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBasePane::DoPaint](../Topic/CBasePane::DoPaint.md)|Preenche o plano de fundo do painel.|  
  
## Comentários  
 Se você desejar criar uma classe de painel que suporta os recursos estendidos de encaixe disponíveis no MFC, você deve derivá\-lo de `CBasePane` ou de [Classe de CPane](../../mfc/reference/cpane-class.md).  
  
## Dicas de personalização  
 As dicas a seguir de personalização são pertinentes a [CBasePane Class](../../mfc/reference/cbasepane-class.md) e as classes que herdarem de ele:  
  
-   Quando você cria um painel, você pode aplicar vários novos estilos:  
  
    -   `AFX_CBRS_FLOAT` faz o painel flutuante.  
  
    -   `AFX_CBRS_AUTOHIDE` ativar o modo automático ocultar de.  
  
    -   `AFX_CBRS_CLOSE` permite que o painel seja fechada \(oculto\).  
  
     Esses são os sinalizadores que você pode combinar com um OU bit a bits a operação.  
  
     `CBasePane` implementa os seguintes métodos virtuais booleanas para refletir essas sinalizações: [CBasePane::CanBeClosed](../Topic/CBasePane::CanBeClosed.md), [CBasePane::CanAutoHide](../Topic/CBasePane::CanAutoHide.md), [CBasePane::CanFloat](../Topic/CBasePane::CanFloat.md).  Você pode substituí\-los em classes derivadas para personalizar seu comportamento.  
  
-   Você pode personalizar o comportamento de encaixe substituindo [CBasePane::CanAcceptPane](../Topic/CBasePane::CanAcceptPane.md).  Tem o retorno `FALSE` do painel de esse método para evitar outro painel de encaixe a ele.  
  
-   Se você deseja criar um painel estático que não possam flutuante e que evita qualquer outro painel de encaixe antes de ele \(semelhante à barra do Outlook no exemplo de OutlookDemo\), criar como não flutuante e substituição [CBasePane::DoesAllowDynInsertBefore](../Topic/CBasePane::DoesAllowDynInsertBefore.md) para retornar `FALSE`.  A implementação padrão `FALSE` retorna se o painel é criado sem o estilo de `AFX_CBRS_FLOAT` .  
  
-   Crie todos os painéis com os diferentes identificações de \-1.  
  
-   Para determinar a visibilidade do, use [CBasePane::IsVisible](../Topic/CBasePane::IsVisible.md).  Trata corretamente o estado de visibilidade nos modos com guias de incrementos ocultar e.  
  
-   Se você deseja criar um painel redimensionável flutuante, criar sem o estilo de `AFX_CBRS_FLOAT` e chame [CFrameWnd::DockControlBar](../Topic/CFrameWnd::DockControlBar.md).  
  
-   Para excluir um painel de um layout de encaixe ou remover uma barra de ferramentas de sua barra da plataforma, chame [CBasePane::UndockPane](../Topic/CBasePane::UndockPane.md).  Não chamar esse método para os painéis no modo de incrementos ocultar para ou painéis que residem nos guias do windows com guias.  
  
-   Se você deseja flutuante ou desencaixar um painel que se está em modo de incrementos ocultar [CDockablePane::SetAutoHideMode](../Topic/CDockablePane::SetAutoHideMode.md) , você deve chamar com `FALSE` como o primeiro argumento antes de chamar [CBasePane::FloatPane](../Topic/CBasePane::FloatPane.md) ou [CBasePane::UndockPane](../Topic/CBasePane::UndockPane.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CBasePane` .  O exemplo demonstra como recuperar um painel de classe de `CFrameWndEx` e como definir o modo de encaixe, o alinhamento do, e estilo de painel.  o código é de [Exemplo de preenchimento da palavra](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#2](../../mfc/reference/codesnippet/CPP/cbasepane-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxbasepane.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [CPane](../../mfc/reference/cbasepane-class.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)