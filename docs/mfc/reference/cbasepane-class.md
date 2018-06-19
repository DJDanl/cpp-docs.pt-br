---
title: Classe CBasePane | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CBasePane
- AFXBASEPANE/CBasePane
- AFXBASEPANE/CBasePane::AccNotifyObjectFocusEvent
- AFXBASEPANE/CBasePane::AddPane
- AFXBASEPANE/CBasePane::AdjustDockingLayout
- AFXBASEPANE/CBasePane::AdjustLayout
- AFXBASEPANE/CBasePane::CalcFixedLayout
- AFXBASEPANE/CBasePane::CanAcceptPane
- AFXBASEPANE/CBasePane::CanAutoHide
- AFXBASEPANE/CBasePane::CanBeAttached
- AFXBASEPANE/CBasePane::CanBeClosed
- AFXBASEPANE/CBasePane::CanBeDocked
- AFXBASEPANE/CBasePane::CanBeResized
- AFXBASEPANE/CBasePane::CanBeTabbedDocument
- AFXBASEPANE/CBasePane::CanFloat
- AFXBASEPANE/CBasePane::CanFocus
- AFXBASEPANE/CBasePane::CopyState
- AFXBASEPANE/CBasePane::CreateDefaultMiniframe
- AFXBASEPANE/CBasePane::CreateEx
- AFXBASEPANE/CBasePane::DockPane
- AFXBASEPANE/CBasePane::DockPaneUsingRTTI
- AFXBASEPANE/CBasePane::DockToFrameWindow
- AFXBASEPANE/CBasePane::DoesAllowDynInsertBefore
- AFXBASEPANE/CBasePane::EnableDocking
- AFXBASEPANE/CBasePane::EnableGripper
- AFXBASEPANE/CBasePane::FloatPane
- AFXBASEPANE/CBasePane::get_accHelpTopic
- AFXBASEPANE/CBasePane::get_accSelection
- AFXBASEPANE/CBasePane::GetCaptionHeight
- AFXBASEPANE/CBasePane::GetControlBarStyle
- AFXBASEPANE/CBasePane::GetCurrentAlignment
- AFXBASEPANE/CBasePane::GetDockingMode
- AFXBASEPANE/CBasePane::GetDockSiteFrameWnd
- AFXBASEPANE/CBasePane::GetEnabledAlignment
- AFXBASEPANE/CBasePane::GetMFCStyle
- AFXBASEPANE/CBasePane::GetPaneIcon
- AFXBASEPANE/CBasePane::GetPaneRow
- AFXBASEPANE/CBasePane::GetPaneStyle
- AFXBASEPANE/CBasePane::GetParentDockSite
- AFXBASEPANE/CBasePane::GetParentMiniFrame
- AFXBASEPANE/CBasePane::GetParentTabbedPane
- AFXBASEPANE/CBasePane::GetParentTabWnd
- AFXBASEPANE/CBasePane::GetRecentVisibleState
- AFXBASEPANE/CBasePane::HideInPrintPreviewMode
- AFXBASEPANE/CBasePane::InsertPane
- AFXBASEPANE/CBasePane::IsAccessibilityCompatible
- AFXBASEPANE/CBasePane::IsAutoHideMode
- AFXBASEPANE/CBasePane::IsDialogControl
- AFXBASEPANE/CBasePane::IsDocked
- AFXBASEPANE/CBasePane::IsFloating
- AFXBASEPANE/CBasePane::IsHorizontal
- AFXBASEPANE/CBasePane::IsInFloatingMultiPaneFrameWnd
- AFXBASEPANE/CBasePane::IsMDITabbed
- AFXBASEPANE/CBasePane::IsPaneVisible
- AFXBASEPANE/CBasePane::IsPointNearDockSite
- AFXBASEPANE/CBasePane::IsResizable
- AFXBASEPANE/CBasePane::IsRestoredFromRegistry
- AFXBASEPANE/CBasePane::IsTabbed
- AFXBASEPANE/CBasePane::IsVisible
- AFXBASEPANE/CBasePane::LoadState
- AFXBASEPANE/CBasePane::MoveWindow
- AFXBASEPANE/CBasePane::OnAfterChangeParent
- AFXBASEPANE/CBasePane::OnBeforeChangeParent
- AFXBASEPANE/CBasePane::OnDrawCaption
- AFXBASEPANE/CBasePane::OnMovePaneDivider
- AFXBASEPANE/CBasePane::OnPaneContextMenu
- AFXBASEPANE/CBasePane::OnRemoveFromMiniFrame
- AFXBASEPANE/CBasePane::OnSetAccData
- AFXBASEPANE/CBasePane::PaneFromPoint
- AFXBASEPANE/CBasePane::RecalcLayout
- AFXBASEPANE/CBasePane::RemovePaneFromDockManager
- AFXBASEPANE/CBasePane::SaveState
- AFXBASEPANE/CBasePane::SelectDefaultFont
- AFXBASEPANE/CBasePane::SetControlBarStyle
- AFXBASEPANE/CBasePane::SetDockingMode
- AFXBASEPANE/CBasePane::SetPaneAlignment
- AFXBASEPANE/CBasePane::SetPaneStyle
- AFXBASEPANE/CBasePane::SetWindowPos
- AFXBASEPANE/CBasePane::ShowPane
- AFXBASEPANE/CBasePane::StretchPane
- AFXBASEPANE/CBasePane::UndockPane
- AFXBASEPANE/CBasePane::DoPaint
dev_langs:
- C++
helpviewer_keywords:
- CBasePane [MFC], AccNotifyObjectFocusEvent
- CBasePane [MFC], AddPane
- CBasePane [MFC], AdjustDockingLayout
- CBasePane [MFC], AdjustLayout
- CBasePane [MFC], CalcFixedLayout
- CBasePane [MFC], CanAcceptPane
- CBasePane [MFC], CanAutoHide
- CBasePane [MFC], CanBeAttached
- CBasePane [MFC], CanBeClosed
- CBasePane [MFC], CanBeDocked
- CBasePane [MFC], CanBeResized
- CBasePane [MFC], CanBeTabbedDocument
- CBasePane [MFC], CanFloat
- CBasePane [MFC], CanFocus
- CBasePane [MFC], CopyState
- CBasePane [MFC], CreateDefaultMiniframe
- CBasePane [MFC], CreateEx
- CBasePane [MFC], DockPane
- CBasePane [MFC], DockPaneUsingRTTI
- CBasePane [MFC], DockToFrameWindow
- CBasePane [MFC], DoesAllowDynInsertBefore
- CBasePane [MFC], EnableDocking
- CBasePane [MFC], EnableGripper
- CBasePane [MFC], FloatPane
- CBasePane [MFC], get_accHelpTopic
- CBasePane [MFC], get_accSelection
- CBasePane [MFC], GetCaptionHeight
- CBasePane [MFC], GetControlBarStyle
- CBasePane [MFC], GetCurrentAlignment
- CBasePane [MFC], GetDockingMode
- CBasePane [MFC], GetDockSiteFrameWnd
- CBasePane [MFC], GetEnabledAlignment
- CBasePane [MFC], GetMFCStyle
- CBasePane [MFC], GetPaneIcon
- CBasePane [MFC], GetPaneRow
- CBasePane [MFC], GetPaneStyle
- CBasePane [MFC], GetParentDockSite
- CBasePane [MFC], GetParentMiniFrame
- CBasePane [MFC], GetParentTabbedPane
- CBasePane [MFC], GetParentTabWnd
- CBasePane [MFC], GetRecentVisibleState
- CBasePane [MFC], HideInPrintPreviewMode
- CBasePane [MFC], InsertPane
- CBasePane [MFC], IsAccessibilityCompatible
- CBasePane [MFC], IsAutoHideMode
- CBasePane [MFC], IsDialogControl
- CBasePane [MFC], IsDocked
- CBasePane [MFC], IsFloating
- CBasePane [MFC], IsHorizontal
- CBasePane [MFC], IsInFloatingMultiPaneFrameWnd
- CBasePane [MFC], IsMDITabbed
- CBasePane [MFC], IsPaneVisible
- CBasePane [MFC], IsPointNearDockSite
- CBasePane [MFC], IsResizable
- CBasePane [MFC], IsRestoredFromRegistry
- CBasePane [MFC], IsTabbed
- CBasePane [MFC], IsVisible
- CBasePane [MFC], LoadState
- CBasePane [MFC], MoveWindow
- CBasePane [MFC], OnAfterChangeParent
- CBasePane [MFC], OnBeforeChangeParent
- CBasePane [MFC], OnDrawCaption
- CBasePane [MFC], OnMovePaneDivider
- CBasePane [MFC], OnPaneContextMenu
- CBasePane [MFC], OnRemoveFromMiniFrame
- CBasePane [MFC], OnSetAccData
- CBasePane [MFC], PaneFromPoint
- CBasePane [MFC], RecalcLayout
- CBasePane [MFC], RemovePaneFromDockManager
- CBasePane [MFC], SaveState
- CBasePane [MFC], SelectDefaultFont
- CBasePane [MFC], SetControlBarStyle
- CBasePane [MFC], SetDockingMode
- CBasePane [MFC], SetPaneAlignment
- CBasePane [MFC], SetPaneStyle
- CBasePane [MFC], SetWindowPos
- CBasePane [MFC], ShowPane
- CBasePane [MFC], StretchPane
- CBasePane [MFC], UndockPane
- CBasePane [MFC], DoPaint
ms.assetid: 8163dd51-d7c7-4def-9c74-61f8ecdfad82
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5cbd24042e7f309a28cea5e72b6a134f3205e541
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33357953"
---
# <a name="cbasepane-class"></a>Classe CBasePane
Classe base para todos os painéis no MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBasePane : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CBasePane::CBasePane`|Construtor padrão.|  
|`CBasePane::~CBasePane`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CBasePane::accHitTest`|Chamado pelo framework para recuperar o elemento filho ou objeto filho em um determinado ponto na tela. (Substitui [CWnd::accHitTest](../../mfc/reference/cwnd-class.md#acchittest).)|  
|`CBasePane::accLocation`|Chamado pelo framework para recuperar o local da tela atual para o objeto especificado. (Substitui [CWnd::accLocation](../../mfc/reference/cwnd-class.md#acclocation).)|  
|[CBasePane::AccNotifyObjectFocusEvent](#accnotifyobjectfocusevent)|`CBasePane` Não use esse método.|  
|`CBasePane::accSelect`|Chamado pelo framework para modificar a seleção ou mover o foco do teclado do objeto especificado. (Substitui [CWnd::accSelect](../../mfc/reference/cwnd-class.md#accselect).)|  
|[CBasePane::AddPane](#addpane)|Adiciona um painel no Gerenciador de encaixe.|  
|[CBasePane::AdjustDockingLayout](#adjustdockinglayout)|Redireciona uma chamada para o Gerenciador de encaixe para ajustar o layout de encaixe.|  
|[CBasePane::AdjustLayout](#adjustlayout)|Chamado pelo framework quando o painel deve ajustar seu layout interno.|  
|[CBasePane::CalcFixedLayout](#calcfixedlayout)|Calcula o tamanho horizontal de uma barra de controle.|  
|[CBasePane::CanAcceptPane](#canacceptpane)|Determina se o outro painel pode ser encaixado para o painel.|  
|[CBasePane::CanAutoHide](#canautohide)|Determina se o painel oferece suporte ao modo de ocultar automaticamente.|  
|[CBasePane::CanBeAttached](#canbeattached)|Determina se o painel pode ser encaixado para outro painel.|  
|[CBasePane::CanBeClosed](#canbeclosed)|Determina se o painel pode ser fechado.|  
|[CBasePane::CanBeDocked](#canbedocked)|Determina se o painel pode ser encaixado para outro painel.|  
|[CBasePane::CanBeResized](#canberesized)|Determina se o painel pode ser redimensionado.|  
|[CBasePane::CanBeTabbedDocument](#canbetabbeddocument)|Especifica se o painel pode ser convertido em um documento com guias MDI.|  
|[CBasePane::CanFloat](#canfloat)|Determina se o painel pode flutuar.|  
|[CBasePane::CanFocus](#canfocus)|Especifica se o painel pode receber foco.|  
|[CBasePane::CopyState](#copystate)|Copia o estado de um determinado painel.|  
|[CBasePane::CreateDefaultMiniframe](#createdefaultminiframe)|Se o painel pode float, cria uma janela do mini quadro.|  
|[CBasePane::CreateEx](#createex)|Cria o painel de controle.|  
|[CBasePane::DockPane](#dockpane)|Encaixa um painel para outro painel, ou para uma janela do quadro.|  
|[CBasePane::DockPaneUsingRTTI](#dockpaneusingrtti)|Encaixa painel usando as informações de tipo de tempo de execução.|  
|[CBasePane::DockToFrameWindow](#docktoframewindow)|Encaixa um painel encaixável a um quadro.|  
|[CBasePane::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Determina se outro painel pode ser inserido dinamicamente entre esse painel e o quadro do pai.|  
|[CBasePane::EnableDocking](#enabledocking)|Permite que se encaixe do painel para o quadro principal.|  
|[CBasePane::EnableGripper](#enablegripper)|Habilita ou desabilita a garra. Se a garra estiver habilitada, o usuário pode arrastar para reposicionar o painel.|  
|`CBasePane::FillWindowRect`|Usado internamente.|  
|[CBasePane::FloatPane](#floatpane)|Flutua o painel.|  
|`CBasePane::get_accChild`|Chamado pelo framework para recuperar o endereço de um `IDispatch` interface para o filho especificado. (Substitui [CWnd::get_accChild](../../mfc/reference/cwnd-class.md#get_accchild).)|  
|`CBasePane::get_accChildCount`|Chamado pelo framework para recuperar o número de filhos que pertence a este objeto. (Substitui [CWnd::get_accChildCount](../../mfc/reference/cwnd-class.md#get_accchildcount).)|  
|`CBasePane::get_accDefaultAction`|Chamado pelo framework para recuperar uma cadeia de caracteres que descreve a ação padrão para o objeto. (Substitui [CWnd::get_accDefaultAction](../../mfc/reference/cwnd-class.md#get_accdefaultaction).)|  
|`CBasePane::get_accDescription`|Chamado pelo framework para recuperar uma cadeia de caracteres que descreve a aparência visual do objeto especificado. (Substitui [CWnd::get_accDescription](../../mfc/reference/cwnd-class.md#get_accdescription).)|  
|`CBasePane::get_accFocus`|Chamado pelo framework para recuperar o objeto que tem o foco do teclado. (Substitui [CWnd::get_accFocus](../../mfc/reference/cwnd-class.md#get_accfocus).)|  
|`CBasePane::get_accHelp`|Chamado pelo framework para recuperar uma cadeia de caracteres de propriedade de ajuda para o objeto. (Substitui [CWnd::get_accHelp](../../mfc/reference/cwnd-class.md#get_acchelp).)|  
|[CBasePane::get_accHelpTopic](#get_acchelptopic)|Chamado pelo framework para recuperar o caminho completo do arquivo WinHelp associado ao objeto especificado e o identificador do tópico apropriado no arquivo. (Substitui [CWnd::get_accHelpTopic](../../mfc/reference/cwnd-class.md#get_acchelptopic).)|  
|`CBasePane::get_accKeyboardShortcut`|Chamado pelo framework para recuperar a tecla de atalho especificada para o objeto. (Substitui [CWnd::get_accKeyboardShortcut](../../mfc/reference/cwnd-class.md#get_acckeyboardshortcut).)|  
|`CBasePane::get_accName`|Chamado pelo framework para recuperar o nome do objeto especificado. (Substitui [CWnd::get_accName](../../mfc/reference/cwnd-class.md#get_accname).)|  
|`CBasePane::get_accParent`|Chamado pelo framework para recuperar o `IDispatch` interface para o pai do objeto. (Substitui [CWnd::get_accParent](../../mfc/reference/cwnd-class.md#get_accparent).)|  
|`CBasePane::get_accRole`|Chamado pelo framework para recuperar as informações que descrevem a função do objeto especificado. (Substitui [CWnd::get_accRole](../../mfc/reference/cwnd-class.md#get_accrole).)|  
|[CBasePane::get_accSelection](#get_accselection)|Chamado pelo framework para recuperar o filho selecionado deste objeto. (Substitui [CWnd::get_accSelection](../../mfc/reference/cwnd-class.md#get_accselection).)|  
|`CBasePane::get_accState`|Chamado pelo framework para recuperar o estado atual do objeto especificado. (Substitui [CWnd::get_accState](../../mfc/reference/cwnd-class.md#get_accstate).)|  
|`CBasePane::get_accValue`|Chamado pelo framework para recuperar o valor do objeto especificado. (Substitui [CWnd::get_accValue](../../mfc/reference/cwnd-class.md#get_accvalue).)|  
|[CBasePane::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda.|  
|[CBasePane::GetControlBarStyle](#getcontrolbarstyle)|Retorna o estilo de barra de controle.|  
|[CBasePane::GetCurrentAlignment](#getcurrentalignment)|Retorna o alinhamento do painel atual.|  
|[CBasePane::GetDockingMode](#getdockingmode)|Retorna o modo de encaixe atual para o painel.|  
|[CBasePane::GetDockSiteFrameWnd](#getdocksiteframewnd)|Retorna um ponteiro para a janela que é o site de encaixe do painel.|  
|[CBasePane::GetEnabledAlignment](#getenabledalignment)|Retorna os estilos CBRS_ALIGN_ que são aplicados ao painel.|  
|[CBasePane::GetMFCStyle](#getmfcstyle)|Retorna os estilos de painel específico a MFC.|  
|[CBasePane::GetPaneIcon](#getpaneicon)|Retorna um identificador para o ícone do painel.|  
|`CBasePane::GetPaneRect`|Usado internamente.|  
|[CBasePane::GetPaneRow](#getpanerow)|Retorna um ponteiro para o [CDockingPanesRow](../../mfc/reference/cdockingpanesrow-class.md)objeto onde o painel está encaixado.|  
|[CBasePane::GetPaneStyle](#getpanestyle)|Retorna o estilo de painel.|  
|[CBasePane::GetParentDockSite](#getparentdocksite)|Retorna um ponteiro para o site de encaixe do pai.|  
|[CBasePane::GetParentMiniFrame](#getparentminiframe)|Retorna um ponteiro para a janela do minipai quadro.|  
|[CBasePane::GetParentTabbedPane](#getparenttabbedpane)|Retorna um ponteiro para o painel com guias do pai.|  
|[CBasePane::GetParentTabWnd](#getparenttabwnd)|Retorna um ponteiro para a janela pai que está dentro de uma guia.|  
|[CBasePane::GetRecentVisibleState](#getrecentvisiblestate)|O framework chama este método quando um painel é restaurado a partir de um arquivo morto.|  
|[CBasePane::HideInPrintPreviewMode](#hideinprintpreviewmode)|Especifica se o painel está oculto na visualização de impressão.|  
|[CBasePane::InsertPane](#insertpane)|Registra o painel especificado com o Gerenciador de encaixe.|  
|[CBasePane::IsAccessibilityCompatible](#isaccessibilitycompatible)|Especifica se o painel oferece suporte a acessibilidade ativa.|  
|[CBasePane::IsAutoHideMode](#isautohidemode)|Determina se um painel está no modo de ocultar automaticamente.|  
|[CBasePane::IsDialogControl](#isdialogcontrol)|Especifica se o painel é um controle de caixa de diálogo.|  
|[CBasePane::IsDocked](#isdocked)|Determina se o painel está encaixado.|  
|[CBasePane::IsFloating](#isfloating)|Determina se o painel é flutuante.|  
|[CBasePane::IsHorizontal](#ishorizontal)|Determina se o painel está encaixado na horizontal.|  
|[CBasePane::IsInFloatingMultiPaneFrameWnd](#isinfloatingmultipaneframewnd)|Especifica se o painel estiver em uma janela do quadro de vários painéis.|  
|[CBasePane::IsMDITabbed](#ismditabbed)|Determina se o painel foi adicionado a uma janela de filho MDI como um documento com guias.|  
|[CBasePane::IsPaneVisible](#ispanevisible)|Especifica se o `WS_VISIBLE` sinalizador é definido para o painel.|  
|[CBasePane::IsPointNearDockSite](#ispointneardocksite)|Determina se um ponto especificado é o local de encaixe próximo.|  
|[CBasePane::IsResizable](#isresizable)|Determina se o painel pode ser redimensionado.|  
|[CBasePane::IsRestoredFromRegistry](#isrestoredfromregistry)|Determina se o painel é restaurado a partir do registro.|  
|[CBasePane::IsTabbed](#istabbed)|Determina se o painel foi inserido no controle de guia de uma janela com guias.|  
|`CBasePane::IsTooltipTopmost`|Usado internamente.|  
|[CBasePane::IsVisible](#isvisible)|Determina se o painel estiver visível.|  
|[CBasePane::LoadState](#loadstate)|Carrega o estado do painel do registro.|  
|[CBasePane::MoveWindow](#movewindow)|Move o painel.|  
|[CBasePane::OnAfterChangeParent](#onafterchangeparent)|Chamado pelo framework quando o pai do painel é alterado.|  
|[CBasePane::OnBeforeChangeParent](#onbeforechangeparent)|Chamado pelo framework antes do painel altera sua janela pai.|  
|[CBasePane::OnDrawCaption](#ondrawcaption)|O framework chama este método quando a legenda é desenhada.|  
|[CBasePane::OnMovePaneDivider](#onmovepanedivider)|Esse método não é usado atualmente.|  
|[CBasePane::OnPaneContextMenu](#onpanecontextmenu)|Chamado pelo framework quando ele cria um menu que tem uma lista de painéis.|  
|[CBasePane::OnRemoveFromMiniFrame](#onremovefromminiframe)|Chamado pelo framework quando um painel é removido de sua janela do quadro mini pai.|  
|[CBasePane::OnSetAccData](#onsetaccdata)|`CBasePane` Não use esse método.|  
|`CBasePane::OnUpdateCmdUI`|Usado internamente.|  
|[CBasePane::PaneFromPoint](#panefrompoint)|Retorna o painel que contém o ponto especificado.|  
|`CBasePane::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|  
|[CBasePane::RecalcLayout](#recalclayout)|`CBasePane` Não use esse método.|  
|[CBasePane::RemovePaneFromDockManager](#removepanefromdockmanager)|Cancela o registro de um painel e remove-o da lista no Gerenciador de encaixe.|  
|[CBasePane::SaveState](#savestate)|Salva o estado do painel no registro.|  
|[CBasePane::SelectDefaultFont](#selectdefaultfont)|Seleciona a fonte padrão para um determinado contexto de dispositivo.|  
|`CBasePane::Serialize`|Lê ou grava este objeto de ou para um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|  
|[CBasePane::SetControlBarStyle](#setcontrolbarstyle)|Define o estilo de barra de controle.|  
|[CBasePane::SetDockingMode](#setdockingmode)|Define o modo de encaixe do painel.|  
|`CBasePane::SetMDITabbed`|Usado internamente.|  
|[CBasePane::SetPaneAlignment](#setpanealignment)|Define o alinhamento para o painel.|  
|`CBasePane::SetPaneRect`|Usado internamente.|  
|[CBasePane::SetPaneStyle](#setpanestyle)|Define o estilo do painel.|  
|`CBasePane::SetRestoredFromRegistry`|Usado internamente.|  
|[CBasePane::SetWindowPos](#setwindowpos)|Altera o tamanho, posição e a ordem Z de um painel.|  
|[CBasePane::ShowPane](#showpane)|Mostra ou oculta o painel.|  
|[CBasePane::StretchPane](#stretchpane)|Expande um painel vertical ou horizontalmente.|  
|[CBasePane::UndockPane](#undockpane)|Remove o painel do local de encaixe, controle deslizante do padrão ou janela do quadro mini onde ela estiver encaixada.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBasePane::DoPaint](#dopaint)|Preenche o plano de fundo do painel.|  
  
## <a name="remarks"></a>Comentários  
 Se você quiser criar uma classe de painel que oferece suporte os recursos estendidos de encaixe disponíveis no MFC, você deve derivar de `CBasePane` ou [CPane classe](../../mfc/reference/cpane-class.md).  
  
## <a name="customization-tips"></a>Dicas de personalização  
 As seguintes dicas de personalização pertencem à `CBasePane Class` e todas as classes que herdam a ela:  
  
-   Quando você cria um painel, você pode aplicar vários novos estilos:  
  
    - `AFX_CBRS_FLOAT` faz com que o valor de float de painel.  
  
    - `AFX_CBRS_AUTOHIDE` Permite oculta automaticamente modo.  
  
    - `AFX_CBRS_CLOSE` permite que o painel a ser fechado (oculto).  
  
     Esses são os sinalizadores que você pode combinar com uma operação OR bit a bit.  
  
 `CBasePane` implementa os seguintes métodos de boolianos virtuais para refletir esses sinalizadores: [CBasePane::CanBeClosed](#canbeclosed), [CBasePane::CanAutoHide](#canautohide), [CBasePane::CanFloat](#canfloat). Você pode substituí-los em classes derivadas para personalizar seu comportamento.  
  
-   Você pode personalizar o comportamento de encaixe, substituindo [CBasePane::CanAcceptPane](#canacceptpane). Tem seu painel de retorno `FALSE` deste método para impedir que o outro painel encaixe a ele.  
  
-   Se você quiser criar um painel estático que não é possível flutuar e que impede que qualquer outro painel encaixe antes dele (semelhante a barra do Outlook no exemplo OutlookDemo), crie-o como não flutuante e substituir [CBasePane::DoesAllowDynInsertBefore](#doesallowdyninsertbefore) para retornar `FALSE`. A implementação padrão retorna `FALSE` se o painel for criado sem o `AFX_CBRS_FLOAT` estilo.  
  
-   Crie todos os painéis com IDs diferentes -1.  
  
-   Para determinar a visibilidade do painel, use [CBasePane::IsVisible](#isvisible). Ele trata corretamente o estado de visibilidade em com guias e modos de ocultar automaticamente.  
  
-   Se você quiser criar um painel redimensionável não flutuante, criá-lo sem a `AFX_CBRS_FLOAT` estilo e chame [CFrameWnd::DockControlBar](../../mfc/reference/cframewnd-class.md#dockcontrolbar).  
  
-   Para excluir um painel de um layout de encaixe ou para remover uma barra de ferramentas da sua barra de encaixe, chame [CBasePane::UndockPane](#undockpane). Não chame este método para painéis no modo de ocultar automaticamente ou painéis que residem nas guias do windows com guias.  
  
-   Se você quiser float ou desencaixar um painel que está no modo de ocultar automaticamente, você deve chamar [CDockablePane::SetAutoHideMode](../../mfc/reference/cdockablepane-class.md#setautohidemode) com `FALSE` como o primeiro argumento antes de chamar [CBasePane::FloatPane](#floatpane) ou [ CBasePane::UndockPane](#undockpane).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CBasePane` classe. O exemplo demonstra como recuperar um painel a partir de `CFrameWndEx` classe e como definir o modo de encaixe, o alinhamento do painel e o estilo de painel. O código é do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#2](../../mfc/reference/codesnippet/cpp/cbasepane-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxbasepane.h  
  
##  <a name="accnotifyobjectfocusevent"></a>  CBasePane::AccNotifyObjectFocusEvent  
 `CBasePane` Não use esse método.  
  
```  
virtual void AccNotifyObjectFocusEvent(int);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `int`  
 Não usado.  
  
##  <a name="addpane"></a>  CBasePane::AddPane  
 Adiciona um painel no Gerenciador de encaixe.  
  
```  
void AddPane(CBasePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para um painel para adicionar.  
  
### <a name="remarks"></a>Comentários  
 Este é um método prático que adiciona um painel em um Gerenciador de encaixe. Usando esse método, você não precisa escrever código que analisa o tipo do quadro pai.  
  
 Para obter mais informações, consulte [CDockingManager classe](../../mfc/reference/cdockingmanager-class.md) e [CMDIFrameWndEx::AddPane](../../mfc/reference/cmdiframewndex-class.md#addpane).  
  
##  <a name="adjustdockinglayout"></a>  CBasePane::AdjustDockingLayout  
 Redireciona uma chamada para o Gerenciador de encaixe para ajustar o layout de encaixe.  
  
```  
virtual void AdjustDockingLayout(HDWP hdwp=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `hdwp`  
 Um identificador para uma estrutura que contém várias posições de janela.  
  
### <a name="remarks"></a>Comentários  
 Este é um método prático que ajusta o layout de encaixe. Usando esse método, você não precisa escrever código que analisa o tipo do quadro pai.  
  
 Para obter mais informações, consulte [CDockingManager::AdjustDockingLayout](../../mfc/reference/cdockingmanager-class.md#adjustdockinglayout)  
  
##  <a name="adjustlayout"></a>  CBasePane::AdjustLayout  
 Chamado pelo framework para ajustar o layout interno de um painel.  
  
```  
virtual void AdjustLayout();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando tiver um painel ajustar seu layout interno. A implementação base não fará nada.  
  
##  <a name="calcfixedlayout"></a>  CBasePane::CalcFixedLayout  
 Calcula o tamanho horizontal de uma barra de controle.  
  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bStretch`  
 Indica se a barra deve ser estendida para o tamanho do quadro. O `bStretch` parâmetro é diferente de zero quando a barra não é uma barra de encaixe (não disponível para encaixar) e é 0 quando ele está encaixado ou flutuante (disponível para encaixar).  
  
 [in] `bHorz`  
 Indica que a barra é orientada horizontal ou verticalmente. O `bHorz` parâmetro é diferente de zero se a barra é orientada horizontal e é 0 se for orientação vertical.  
  
### <a name="return-value"></a>Valor de retorno  
 A barra de controle de tamanho, em pixels, de um `CSize` objeto.  
  
### <a name="remarks"></a>Comentários  
 Consulte a seção comentários [CControlBar::CalcFixedLayout](../../mfc/reference/ccontrolbar-class.md#calcfixedlayout)  
  
##  <a name="canacceptpane"></a>  CBasePane::CanAcceptPane  
 Determina se o outro painel pode ser encaixado para o painel.  
  
```  
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para encaixar o painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se outro painel pode ser aceita; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método antes de ele encaixa painel especificado por `pBar` para o painel atual.  
  
 Use este método e o [CBasePane::CanBeDocked](#canbedocked) método para controlar como os painéis encaixar outros painéis em seu aplicativo.  
  
 A implementação padrão retorna `FALSE`.  
  
##  <a name="canautohide"></a>  CBasePane::CanAutoHide  
 Determina se o painel oferece suporte ao modo de ocultar automaticamente.  
  
```  
virtual BOOL CanAutoHide() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse painel oferece suporte ao modo de ocultar automaticamente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esta função para determinar se o painel oferece suporte ao modo de ocultar automaticamente.  
  
 Durante a construção, você pode definir essa capacidade, passando o `AFX_CBRS_AUTOHIDE` sinalizador como [CBasePane::CreateEx](#createex).  
  
 A implementação padrão verifica o `AFX_CBRS_AUTOHIDE` sinalizador. Substitua este método em uma classe derivada para personalizar esse comportamento.  
  
##  <a name="canbeattached"></a>  CBasePane::CanBeAttached  
 Determina se o painel pode ser encaixado outra janela do painel ou quadro.  
  
```  
virtual BOOL CanBeAttached() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser encaixado outra janela do painel ou quadro; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão retorna `FALSE`. Substitua este método em uma classe derivada para habilitar ou desabilitar a capacidade de encaixe sem chamar [CBasePane::EnableDocking](#enabledocking).  
  
##  <a name="canbeclosed"></a>  CBasePane::CanBeClosed  
 Determina se o painel pode ser fechado.  
  
```  
virtual BOOL CanBeClosed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser fechado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se o painel pode ser fechado. Se o método retornar `TRUE`, um **fechar** botão é adicionado à barra de título do painel ou, se o painel estiver flutuando, a barra de título da janela de miniquadros do painel.  
  
 Durante a construção, você pode definir essa capacidade, passando o `AFX_CBRS_CLOSE` sinalizador como [CBasePane::CreateEx](#createex).  
  
 A implementação padrão verifica o `AFX_CBRS_CLOSE` sinalizador.  
  
##  <a name="canbedocked"></a>  CBasePane::CanBeDocked  
 Determina se o painel pode ser encaixado para outro painel.  
  
```  
virtual BOOL CanBeDocked(CBasePane* pDockBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockBar`  
 Um ponteiro para outro painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse painel pode ser encaixado para outro painel; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método antes de ele encaixa painel especificado por `pDockBar` para o painel atual.  
  
 Use este método e o [CBasePane::CanAcceptPane](#canacceptpane) método para controlar como os painéis encaixar outros painéis em seu aplicativo.  
  
 A implementação padrão retorna `FALSE`.  
  
##  <a name="canberesized"></a>  CBasePane::CanBeResized  
 Determina se o painel pode ser redimensionado.  
  
```  
virtual BOOL CanBeResized() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser redimensionado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método verifica a `AFX_CBRS_RESIZE` sinalizador, que é especificada por padrão em `CBasePane::OnCreate`. Se este sinalizador não for especificado, o Gerenciador de encaixe sinaliza o internamente como estático, em vez de encaixe do painel.  
  
##  <a name="canbetabbeddocument"></a>  CBasePane::CanBeTabbedDocument  
 Especifica se o painel pode ser convertido em um documento com guias MDI.  
  
```  
virtual BOOL CanBeTabbedDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser convertido em um documento com guias. Caso contrário, `FALSE`. `CBasePane::CanBeTabbedDocument` sempre retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Somente os objetos de determinadas `CBasePane`-derivados tipos, como o [CDockablePane classe](../../mfc/reference/cdockablepane-class.md), pode ser convertido em documentos com guias.  
  
##  <a name="canfloat"></a>  CBasePane::CanFloat  
 Determina se o painel pode flutuar.  
  
```  
virtual BOOL CanFloat() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode flutuar; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se o painel pode flutuar.  
  
 Durante a construção, você pode definir essa capacidade, passando o `AFX_CBRS_FLOAT` sinalizador como [CBasePane::CreateEx](#createex).  
  
> [!NOTE]
>  A estrutura pressupõe que não flutuante painéis são estáticos e que seu estado de encaixe não pode alterar. Portanto, a estrutura não salva o estado de encaixe dos painéis não flutuante.  
  
 A implementação padrão verifica o `AFX_CBRS_FLOAT` estilo.  
  
##  <a name="canfocus"></a>  CBasePane::CanFocus  
 Especifica se o painel pode receber foco.  
  
```  
virtual BOOL CanFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode receber foco. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada para controlar o foco. Por exemplo, como barras de ferramentas não podem receber o foco, esse método retorna `FALSE` quando ela é chamada em objetos de barra de ferramentas.  
  
 A estrutura tenta definir o foco de entrada quando um painel estiver encaixado ou flutuante.  
  
##  <a name="copystate"></a>  CBasePane::CopyState  
 Copia o estado de um determinado painel.  
  
```  
virtual void CopyState(CBasePane* pOrgBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pOrgBar`  
 Um ponteiro para outro painel.  
  
### <a name="remarks"></a>Comentários  
 Esse método copia o estado de `pOrgBar` para esse painel.  
  
##  <a name="createdefaultminiframe"></a>  CBasePane::CreateDefaultMiniframe  
 Se o painel pode float, esse método cria uma janela do quadro simplificado para ele.  
  
```  
virtual CPaneFrameWnd* CreateDefaultMiniframe(CRect rectInitial);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectInitial`  
 Especifica as coordenadas inicias da janela do quadro simplificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova janela do quadro mini ou `NULL` se a falha na criação.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando um painel muda para um estado flutuante. O método cria uma janela do quadro simplificado e anexa o painel a esta janela.  
  
 A implementação padrão retorna `NULL`.  
  
##  <a name="createex"></a>  CBasePane::CreateEx  
 Cria o painel de controle.  
  
```  
virtual BOOL CreateEx(
    DWORD dwStyleEx,  
    LPCTSTR lpszClassName,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    DWORD dwControlBarStyle=0,  
    CCreateContext* pContext=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwStyleEx`  
 Os estilos estendidos (consulte [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex) para obter mais informações).  
  
 [in] `lpszClassName`  
 O nome da classe de janela.  
  
 [in] `lpszWindowName`  
 O nome da janela.  
  
 [in] `dwStyle`  
 O estilo de janela (consulte [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex)).  
  
 [in] `rect`  
 O retângulo inicial.  
  
 [in] `pParentWnd`  
 Um ponteiro para a janela pai.  
  
 [in] `nID`  
 Especifica a ID do painel. Deve ser exclusivo.  
  
 [in] `dwControlBarStyle`  
 Sinalizadores de estilo para painéis.  
  
 [in] `pContext`  
 Um ponteiro para `CcreateContext`  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel for criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Cria uma janela da classe `lpszClassName`. Se você especificar `WS_CAPTION`, esse método limpa o `WS_CAPTION` bit de estilo e conjuntos de `CBasePane::m_bHasCaption` para `TRUE`, porque a biblioteca não oferece suporte a painéis com legendas.  
  
 Você pode usar qualquer combinação de estilos de janela filho e controle MFC barra estilos (CBRS_).  
  
 A biblioteca adiciona vários novos estilos de painéis. A tabela a seguir descreve os novos estilos:  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`AFX_CBRS_FLOAT`|O painel pode flutuar.|  
|`AFX_CBRS_AUTOHIDE`|O painel oferece suporte ao modo de ocultar automaticamente|  
|`AFX_CBRS_RESIZE`|O painel pode ser redimensionado. **Importante:** esse estilo não está implementado.|  
|`AFX_CBRS_CLOSE`|O painel pode ser fechado.|  
|`AFX_CBRS_AUTO_ROLLUP`|O painel pode ser acumulado quando ele flutua.|  
|`AFX_CBRS_REGULAR_TABS`|Quando um painel encaixa para outro painel que tiver esse estilo, uma janela com guias regular é criada. (Para obter mais informações, consulte [CTabbedPane classe](../../mfc/reference/ctabbedpane-class.md).)|  
|`AFX_CBRS_OUTLOOK_TABS`|Quando um painel encaixa para outro painel que tiver esse estilo, uma janela com guias de estilo do Outlook é criada. (Para obter mais informações, consulte [CMFCOutlookBar classe](../../mfc/reference/cmfcoutlookbar-class.md).)|  
  
 Para usar os novos estilos, especifique-os no `dwControlBarStyle`.  
  
##  <a name="dockpane"></a>  CBasePane::DockPane  
 Encaixa um painel para outro painel, ou para uma janela do quadro.  
  
```  
virtual BOOL DockPane(
    CBasePane* pDockBar,  
    LPCRECT lpRect,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockBar`  
 Um ponteiro para outro painel.  
  
 [in] `lpRect`  
 Especifica o retângulo de destino.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a barra de controle foi encaixada com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para ancorar um painel para outro painel ou uma barra de encaixe ( [CDockSite classe](../../mfc/reference/cdocksite-class.md)) que é especificado pela `pDockBar`, ou para um quadro principal se `pDockBar` é `NULL`.  
  
 `dockMethod` Especifica como o painel está encaixado. Consulte [CPane::DockPane](../../mfc/reference/cpane-class.md#dockpane) para obter uma lista de valores possíveis.  
  
##  <a name="dockpaneusingrtti"></a>  CBasePane::DockPaneUsingRTTI  
 Encaixa painel usando as informações de tipo de tempo de execução.  
  
```  
void DockPaneUsingRTTI(BOOL bUseDockSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bUseDockSite`  
 Se `TRUE`, encaixe para o site de encaixe. Se `FALSE`, encaixar o quadro do pai.  
  
##  <a name="docktoframewindow"></a>  CBasePane::DockToFrameWindow  
 Encaixa um painel encaixável a um quadro.  
  
```  
virtual BOOL DockToFrameWindow(
    DWORD dwAlignment,  
    LPCRECT lpRect = NULL,  
    DWORD dwDockFlags = DT_DOCK_LAST,  
    CBasePane* pRelativeBar = NULL,  
    int nRelativeIndex = -1,  
    BOOL bOuterEdge = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
 O lado do quadro pai que você deseja encaixar o painel para.  
  
 [in] `lpRect`  
 O tamanho desejado.  
  
 [in] `dwDockFlags`  
 Ignorado.  
  
 [in] `pRelativeBar`  
 Ignorado.  
  
 [in] `nRelativeIndex`  
 Ignorado.  
  
 [in] `bOuterEdge`  
 Se `TRUE` e há outros painéis encaixáveis no lado especificado por `dwAlignment`, o painel estiver encaixado fora os painéis, a borda do quadro pai mais próximo. Se `FALSE`, o painel está encaixado aproximando-se para o centro da área do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método falhar se um divisor de painel ( [CPaneDivider classe](../../mfc/reference/cpanedivider-class.md)) não pode ser criado. Caso contrário, ele sempre retornará `TRUE`.  
  
##  <a name="doesallowdyninsertbefore"></a>  CBasePane::DoesAllowDynInsertBefore  
 Determina se outro painel pode ser inserido dinamicamente entre esse painel e o quadro do pai.  
  
```  
virtual BOOL DoesAllowDynInsertBefore() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se um usuário pode inserir outro painel; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se um usuário pode inserir dinamicamente um painel antes deste painel.  
  
 Por exemplo, suponha que seu aplicativo cria um painel encaixado à esquerda do quadro (como a barra do Outlook). Para impedir que o usuário encaixe outro painel à esquerda do primeiro painel, substitua este método e retornar `FALSE`.  
  
 Recomendamos que você substitua este método e retorna `FALSE` para painéis não flutuante derivam da [CDockablePane classe](../../mfc/reference/cdockablepane-class.md).  
  
 A implementação padrão retorna `TRUE`.  
  
##  <a name="dopaint"></a>  CBasePane::DoPaint  
 Preenche o plano de fundo do painel.  
  
```  
virtual void DoPaint(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama o Gerenciador de visual atual para preencher o plano de fundo ( [CMFCVisualManager::OnFillBarBackground](../../mfc/reference/cmfcvisualmanager-class.md#onfillbarbackground)).  
  
##  <a name="enabledocking"></a>  CBasePane::EnableDocking  
 Permite que se encaixe do painel para o quadro principal.  
  
```  
virtual void EnableDocking(DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
 Especifica o alinhamento de encaixe para habilitar.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para habilitar o alinhamento de encaixe para o quadro principal. Você pode passar uma combinação de `CBRS_ALIGN_` sinalizadores (para obter mais informações, consulte [CControlBar::EnableDocking](../../mfc/reference/ccontrolbar-class.md#enabledocking)).  
  
 `EnableDocking` Define o sinalizador interno `CBasePane::m_dwEnabledAlignment` e o framework verifica esse sinalizador quando um painel está encaixado.  
  
 Chamar [CBasePane::GetEnabledAlignment](#getenabledalignment) para determinar o alinhamento de encaixe de um painel.  
  
##  <a name="enablegripper"></a>  CBasePane::EnableGripper  
 Habilita ou desabilita a garra. Se a garra estiver habilitada, o usuário pode arrastar para reposicionar o painel.  
  
```  
virtual void EnableGripper(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE` Para habilitar a garra; `FALSE` para desabilitá-lo.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa esse método para habilitar uma garra em vez de usar o `WS_CAPTION` estilo.  
  
##  <a name="floatpane"></a>  CBasePane::FloatPane  
 Flutua o painel.  
  
```  
virtual BOOL FloatPane(
    CRect rectFloat,  
    AFX_DOCK_METHOD dockMethod=DM_UNKNOWN,  
    bool bShow=true);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectFloat`  
 Especifica as coordenadas de tela em que o painel flutuante será exibido.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe para float, o painel.  
  
 [in] `bShow`  
 Especifica se o painel flutuante é visível ( `TRUE`) ou oculto ( `FALSE`).  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi flutuante com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para flutuar um painel na tela posição especificada pelo `rectFloat`.  
  
##  <a name="get_acchelptopic"></a>  CBasePane::get_accHelpTopic  
 O framework chama esse método para recuperar o caminho completo do `WinHelp` arquivo que está associado ao objeto especificado e o identificador do tópico apropriado no arquivo.  
  
```  
virtual HRESULT get_accHelpTopic(
    BSTR* pszHelpFile,  
    VARIANT varChild,  
    long* pidTopic);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pszHelpFile`  
 Endereço de um `BSTR` que recebe o caminho completo do `WinHelp` arquivo que está associado ao objeto especificado, se houver.  
  
 [in] `varChild`  
 Especifica se o tópico da ajuda a ser recuperado do objeto ou em um dos elementos filho do objeto. Esse parâmetro pode ser `CHILDID_SELF` (para obter um tópico da Ajuda para o objeto) ou uma ID de filho (para obter um tópico da Ajuda para um dos filhos de elementos do objeto).  
  
 [in] `pidTopic`  
 Identifica o `Help` tópico do arquivo que está associado ao objeto especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 `CBasePane` não é implementam este método. Portanto, `CBasePane::get_accHelpTopic` sempre retorna `S_FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Essa função é parte do suporte acessibilidade ativa do MFC. Substitua essa função em uma classe derivada para fornecer informações de ajuda sobre o objeto.  
  
##  <a name="get_accselection"></a>  CBasePane::get_accSelection  
 O framework chama esse método para recuperar o filho selecionado deste objeto.  
  
```  
virtual HRESULT get_accSelection(VARIANT* pvarChildren);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pvarChildren`  
 Recebe informações que identificam o filho selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 `CBasePane` não é implementam este método. Se `pvarChildren` for `NULL`, esse método retornará `E_INVALIDARG`. Do contrário, esse método retorna `DISP_E_MEMBERNOTFOUND`.  
  
### <a name="remarks"></a>Comentários  
 Essa função é parte do suporte acessibilidade ativa do MFC. Substitua essa função em uma classe derivada, se você tiver elementos de interface do usuário não está em janelas diferentes controles ActiveX sem janelas.  
  
##  <a name="getcaptionheight"></a>  CBasePane::GetCaptionHeight  
 Retorna a altura da legenda.  
  
```  
virtual int GetCaptionHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura da legenda.  
  
##  <a name="getcontrolbarstyle"></a>  CBasePane::GetControlBarStyle  
 Retorna o estilo de barra de controle.  
  
```  
virtual DWORD GetControlBarStyle() const 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de OR bit a bit dos sinalizadores AFX_CBRS_.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno é uma combinação dos seguintes valores possíveis.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`AFX_CBRS_FLOAT`|Faz com que o valor de float de barra de controle.|  
|`AFX_CBRS_AUTOHIDE`|Permite oculta automaticamente modo.|  
|`AFX_CBRS_RESIZE`|Habilita o redimensionamento da barra de controle. Quando esse sinalizador é definido, a barra de controle pode ser colocada em um painel encaixável.|  
|`AFX_CBRS_CLOSE`|Permite ocultar a barra de controle.|  
  
##  <a name="getcurrentalignment"></a>  CBasePane::GetCurrentAlignment  
 Retorna o alinhamento do painel atual.  
  
```  
virtual DWORD GetCurrentAlignment() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O alinhamento atual da barra de controle. A tabela a seguir mostra os valores possíveis:  
  
|Valor|Alinhamento|  
|-----------|---------------|  
|`CBRS_ALIGN_LEFT`|Alinhamento à esquerda.|  
|`CBRS_ALIGN_RIGHT`|Alinhamento à direita.|  
|`CBRS_ALIGN_TOP`|Alinhamento superior.|  
|`CBRS_ALIGN_BOTTOM`|Alinhamento da parte inferior.|  
  
##  <a name="getdockingmode"></a>  CBasePane::GetDockingMode  
 Retorna o modo de encaixe atual para o painel.  
  
```  
virtual AFX_DOCK_TYPE GetDockingMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 DT_STANDARD se arrastando o painel é indicado na tela por um retângulo de arrastar. DT_IMMEDIATE se o conteúdo do painel é arrastado.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar o modo atual de encaixe do painel.  
  
 Se `CBasePane::m_dockMode` é indefinido (DT_UNDEFINED), o modo de encaixe é obtido do modo de encaixe global ( `AFX_GLOBAL_DATA::m_dockModeGlobal`).  
  
 Definindo `m_dockMode` ou substituindo `GetDockingMode` você pode controlar o modo de encaixe para cada painel.  
  
##  <a name="getdocksiteframewnd"></a>  CBasePane::GetDockSiteFrameWnd  
 Retorna um ponteiro para o [CDockingPanesRow](../../mfc/reference/cdockingpanesrow-class.md)objeto onde o painel está encaixado.  
  
```  
virtual CWnd* GetDockSiteFrameWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o site de encaixe do painel.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para recuperar um ponteiro para o site de encaixe do painel. O site de encaixe pode ser uma janela do quadro principal se o painel estiver encaixado o quadro principal ou uma janela do minise quadro o painel é flutuante.  
  
##  <a name="getenabledalignment"></a>  CBasePane::GetEnabledAlignment  
 Retorna os estilos CBRS_ALIGN_ que são aplicados ao painel.  
  
```  
virtual DWORD GetEnabledAlignment() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos CBRS_ALIGN_. A tabela a seguir mostra os estilos possíveis:  
  
|Sinalizador|Alinhamento habilitado|  
|----------|-----------------------|  
|`CBRS_ALIGN_LEFT`|À esquerda.|  
|`CBRS_ALIGN_RIGHT`|Certo.|  
|`CBRS_ALIGN_TOP`|Início.|  
|`CBRS_ALIGN_BOTTOM`|Inferior.|  
|`CBRS_ALIGN_ANY`|Combinação de todos os sinalizadores.|  
  
### <a name="remarks"></a>Comentários  
 Chame este método para determinar o alinhamento habilitado para o painel. Alinhamento habilitado significa que os lados da janela do quadro principal que um painel pode ser encaixado.  
  
 Habilitar o alinhamento de encaixe usando [CBasePane::EnableDocking](#enabledocking).  
  
##  <a name="getmfcstyle"></a>  CBasePane::GetMFCStyle  
 Retorna os estilos de painel que são específicos para MFC.  
  
```  
virtual DWORD GetMFCStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos de painel (AFX_CBRS_) específicas da biblioteca.  
  
##  <a name="getpaneicon"></a>  CBasePane::GetPaneIcon  
 Retorna um identificador para o ícone do painel.  
  
```  
virtual HICON GetPaneIcon(BOOL bBigIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bBigIcon`  
 Especifica um 32 pixels por um ícone de 32 pixels se `TRUE`; Especifica um pixel 16 pelo ícone de pixel 16 se `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o ícone do painel. Se for bem-sucedido, retornará `NULL`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama [CWnd::GetIcon](../../mfc/reference/cwnd-class.md#geticon).  
  
##  <a name="getpanerow"></a>  CBasePane::GetPaneRow  
 Retorna um ponteiro para o [CDockingPanesRow](../../mfc/reference/cdockingpanesrow-class.md)objeto onde o painel está encaixado.  
  
```  
CDockingPanesRow* GetPaneRow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para `CDockingPanesRow` se o painel está encaixado, ou `NULL` se ele é flutuante.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para acessar a linha em que um painel está encaixado. Por exemplo, para organizar os painéis em uma linha específica, chamada `GetPaneRow` e, em seguida, chame [CDockingPanesRow::ArrangePanes](../../mfc/reference/cdockingpanesrow-class.md#arrangepanes).  
  
##  <a name="getpanestyle"></a>  CBasePane::GetPaneStyle  
 Retorna o estilo de painel.  
  
```  
virtual DWORD GetPaneStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos de barra de controle (incluindo estilos CBRS_) que foi definido pelo [CBasePane::SetPaneStyle](#setpanestyle) método no momento da criação.  
  
##  <a name="getparentdocksite"></a>  CBasePane::GetParentDockSite  
 Retorna um ponteiro para o site de encaixe do pai.  
  
```  
virtual CDockSite* GetParentDockSite() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O local de encaixe do pai.  
  
##  <a name="getparentminiframe"></a>  CBasePane::GetParentMiniFrame  
 Retorna um ponteiro para a janela do minipai quadro.  
  
```  
virtual CPaneFrameWnd* GetParentMiniFrame(BOOL bNoAssert=FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bNoAssert`  
 Se `TRUE`, este método não verifica os ponteiros não válido. Se você chamar esse método quando sai de seu aplicativo, defina este parâmetro como `TRUE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para a janela do minipai quadro se o painel estiver flutuando; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar um ponteiro para a janela do minipai quadro. Esse método itera em todos os pais e procura um objeto derivado de [CPaneFrameWnd classe](../../mfc/reference/cpaneframewnd-class.md).  
  
 Use `GetParentMiniFrame` para determinar se o painel é flutuante.  
  
##  <a name="getparenttabbedpane"></a>  CBasePane::GetParentTabbedPane  
 Retorna um ponteiro para o painel com guias do pai.  
  
```  
CBaseTabbedPane* GetParentTabbedPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o painel com guias pai se ele existir. Caso contrário, `NULL`.  
  
##  <a name="getparenttabwnd"></a>  CBasePane::GetParentTabWnd  
 Retorna um ponteiro para a janela pai que está dentro de uma guia.  
  
```  
CMFCBaseTabCtrl* GetParentTabWnd(HWND& hWndTab) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `hWndTab`  
 Se o valor de retorno não é `NULL`, este parâmetro contém o identificador para a janela com guias do pai.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para o pai de janela com guias ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para recuperar um ponteiro para a janela com guias do pai. Às vezes, não é suficiente chamar `GetParent`, pois um painel pode estar dentro de um wrapper de encaixe ( [CDockablePaneAdapter classe](../../mfc/reference/cdockablepaneadapter-class.md)) ou dentro de um adaptador de painel ( [CDockablePaneAdapter classe](../../mfc/reference/cdockablepaneadapter-class.md)). Usando `GetParentTabWnd` você poderá recuperar um ponteiro válido nesses casos (supondo que o pai é uma janela com guias).  
  
##  <a name="getrecentvisiblestate"></a>  CBasePane::GetRecentVisibleState  
 O framework chama este método quando um painel é restaurado a partir de um arquivo morto.  
  
```  
virtual BOOL GetRecentVisibleState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `BOOL` que especifica o estado de visibilidade recente. Se `TRUE`, o painel foi visível quando serializada e deve ser visível quando restaurado. Se `FALSE`, o painel foi oculto quando serializada e deve ser ocultado quando restaurado.  
  
##  <a name="hideinprintpreviewmode"></a>  CBasePane::HideInPrintPreviewMode  
 Especifica se o painel está oculto na visualização de impressão.  
  
```  
virtual BOOL HideInPrintPreviewMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel não for exibido na visualização da impressão. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Painéis de base não são mostradas na visualização de impressão. Portanto, esse método sempre retornará `TRUE`.  
  
##  <a name="insertpane"></a>  CBasePane::InsertPane  
 Registra o painel especificado com o Gerenciador de encaixe.  
  
```  
BOOL InsertPane(
    CBasePane* pControlBar,  
    CBasePane* pTarget,  
    BOOL bAfter = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 Um ponteiro para o painel para inserir.  
  
 [in] `pTarget`  
 Um ponteiro para o painel adjacente.  
  
 [in] `bAfter`  
 Se `TRUE`, `pControlBar` é inserida depois `pTarget`. Se `FALSE`, `pControlBar` é inserida antes `pTarget`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o método for bem-sucedido, `FALSE` caso contrário.  
  
##  <a name="isaccessibilitycompatible"></a>  CBasePane::IsAccessibilityCompatible  
 Especifica se o painel oferece suporte a acessibilidade ativa.  
  
```  
virtual BOOL IsAccessibilityCompatible();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel oferece suporte a acessibilidade ativa; Caso contrário, `FALSE`.  
  
##  <a name="isautohidemode"></a>  CBasePane::IsAutoHideMode  
 Determina se um painel está no modo de ocultar automaticamente.  
  
```  
virtual BOOL IsAutoHideMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel estiver no modo de ocultar automaticamente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Painéis de base não é possível ocultar automaticamente. Esse método sempre retorna `FALSE`.  
  
##  <a name="isdialogcontrol"></a>  CBasePane::IsDialogControl  
 Especifica se o painel é um controle de caixa de diálogo.  
  
```  
BOOL IsDialogControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel é um controle de caixa de diálogo; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa esse método para garantir a consistência de layout para todos os painéis.  
  
##  <a name="isdocked"></a>  CBasePane::IsDocked  
 Determina se o painel está encaixado.  
  
```  
virtual BOOL IsDocked() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o pai do painel não é um miniou quadro se o painel estiver flutuando em um quadro simplificado com outro painel; Caso contrário, `FALSE`.  
  
##  <a name="isfloating"></a>  CBasePane::IsFloating  
 Determina se o painel é flutuante.  
  
```  
virtual BOOL IsFloating() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel estiver flutuando; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna o valor contrário [CBasePane::IsDocked](#isdocked).  
  
##  <a name="ishorizontal"></a>  CBasePane::IsHorizontal  
 Determina se o painel está encaixado na horizontal.  
  
```  
virtual BOOL IsHorizontal() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel está encaixado horizontalmente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão verifica o alinhamento de encaixe atual para `CBRS_ORIENT_HORZ`.  
  
##  <a name="isinfloatingmultipaneframewnd"></a>  CBasePane::IsInFloatingMultiPaneFrameWnd  
 Especifica se o painel estiver em uma janela do quadro de vários painéis ( [CMultiPaneFrameWnd classe](../../mfc/reference/cmultipaneframewnd-class.md)).  
  
```  
virtual BOOL IsInFloatingMultiPaneFrameWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel estiver em uma janela do quadro de vários painéis; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Somente os painéis encaixáveis podem flutuar em uma janela do quadro de vários painéis. Portanto, `CBasePane::IsInFloatingMultiPaneFrameWnd` sempre retorna `FALSE`.  
  
##  <a name="ismditabbed"></a>  CBasePane::IsMDITabbed  
 Determina se o painel foi adicionado a uma janela de filho MDI como um documento com guias.  
  
```  
virtual BOOL IsMDITabbed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi adicionado a uma janela de filho MDI como um documento com guias. Caso contrário, `FALSE`.  
  
##  <a name="ispanevisible"></a>  CBasePane::IsPaneVisible  
 Especifica se o `WS_VISIBLE` sinalizador é definido para o painel.  
  
```  
BOOL IsPaneVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se `WS_VISIBLE` estiver definida; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use [CBasePane::IsVisible](#isvisible) para determinar a visibilidade do painel.  
  
##  <a name="ispointneardocksite"></a>  CBasePane::IsPointNearDockSite  
 Determina se um ponto especificado é o local de encaixe próximo.  
  
```  
BOOL IsPointNearDockSite(
    CPoint point,  
    DWORD& dwBarAlignment,  
    BOOL& bOuterEdge) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto especificado.  
  
 [out] `dwBarAlignment`  
 Especifica que o ponto está próximo de borda. Os valores possíveis são `CBRS_ALIGN_LEFT`, `CBRS_ALIGN_RIGHT`, `CBRS_ALIGN_TOP`, e `CBRS_ALIGN_BOTTOM`  
  
 [out] `bOuterEdge`  
 `TRUE` Se o ponto está próximo a borda externa do site do encaixe; `FALSE` caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o ponto está próximo do site de encaixe; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O ponto é o local de encaixe próximo quando ele está dentro da sensibilidade definida no Gerenciador de encaixe. A sensibilidade de padrão é 15 pixels.  
  
##  <a name="isresizable"></a>  CBasePane::IsResizable  
 Determina se o painel pode ser redimensionado.  
  
```  
virtual BOOL IsResizable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser redimensionado pelo usuário; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Painéis de [CDockablePane classe](../../mfc/reference/cdockablepane-class.md) pode ser redimensionado.  
  
 A barra de status ( [CMFCStatusBar classe](../../mfc/reference/cmfcstatusbar-class.md)) e a barra de encaixe ( [CDockSite classe](../../mfc/reference/cdocksite-class.md)) não pode ser redimensionado.  
  
##  <a name="isrestoredfromregistry"></a>  CBasePane::IsRestoredFromRegistry  
 Determina se o painel é restaurado a partir do registro.  
  
```  
virtual BOOL IsRestoredFromRegistry() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel é restaurado a partir do registro. Caso contrário, `FALSE`.  
  
##  <a name="istabbed"></a>  CBasePane::IsTabbed  
 Determina se o painel foi inserido no controle de guia de uma janela com guias.  
  
```  
virtual BOOL IsTabbed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a barra de controle é inserida em uma guia de uma janela com guias; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera um ponteiro para o pai imediato e determina se a classe de tempo de execução do pai é [CMFCBaseTabCtrl classe](../../mfc/reference/cmfcbasetabctrl-class.md).  
  
##  <a name="isvisible"></a>  CBasePane::IsVisible  
 Determina se o painel estiver visível.  
  
```  
virtual BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel estiver visível; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para determinar a visibilidade de um painel. Não use `::IsWindowVisible`.  
  
 Se o painel não será tabulado (consulte [CBasePane::IsTabbed](#istabbed)), esse método verifica o `WS_VISIBLE` estilo. Se o painel está com guias, este método verifica a visibilidade da janela com guias do pai. Se a janela pai estiver visível, a função verifica a visibilidade do painel Guia usando [CMFCBaseTabCtrl::IsTabVisible](../../mfc/reference/cmfcbasetabctrl-class.md#istabvisible).  
  
##  <a name="loadstate"></a>  CBasePane::LoadState  
 Carrega o estado do painel do registro.  
  
```  
virtual BOOL LoadState(
    LPCTSTR lpszProfileName=NULL,  
    int nIndex=-1,  
    UINT uiID=(UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Nome do perfil.  
  
 [in] `nIndex`  
 Índice de perfil.  
  
 [in] `uiID`  
 ID do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o estado do painel foi carregado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para carregar o estado do painel do registro. Substituí-la em uma classe derivada para carregar informações adicionais, salvas por [CBasePane::SaveState](#savestate).  
  
##  <a name="movewindow"></a>  CBasePane::MoveWindow  
 Move o painel.  
  
```  
virtual HDWP MoveWindow(
    CRect& rect,  
    BOOL bRepaint = TRUE,  
    HDWP hdwp = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rect`  
 Um retângulo, especificando o novo local e o tamanho do painel.  
  
 [in] `bRepaint`  
 Se `TRUE`, o painel é redesenhado. Se `FALSE`, o painel não é redesenhado.  
  
 [in] `hdwp`  
 Identificador para uma estrutura de posição de janela adiada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para uma estrutura de posição de janela adiada, ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Se você passar `NULL` como o `hdwp` parâmetro, esse método Move a janela normalmente. Se você passar um identificador, esse método executa uma movimentação de janela adiada. Você pode obter um identificador chamando [BeginDeferWindowPos](http://msdn.microsoft.com/library/windows/desktop/ms632672) ou ao armazenar o valor de retorno de uma chamada anterior para esse método.  
  
##  <a name="onafterchangeparent"></a>  CBasePane::OnAfterChangeParent  
 Chamado pelo framework depois das alterações do pai do painel.  
  
```  
virtual void OnAfterChangeParent(CWnd* pWndOldParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndOldParent`  
 Um ponteiro para o pai anterior.  
  
### <a name="remarks"></a>Comentários  
 O framework chama este método depois pai do painel for alterado, normalmente devido a uma operação de encaixe ou flutuante.  
  
 A implementação padrão não fará nada.  
  
##  <a name="onbeforechangeparent"></a>  CBasePane::OnBeforeChangeParent  
 Chamado pelo framework antes do painel altera sua janela pai.  
  
```  
virtual void OnBeforeChangeParent(
    CWnd* pWndNewParent,  
    BOOL bDelay=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndNewParent`  
 Um ponteiro para uma nova janela pai.  
  
 [in] `bDelay`  
 Especifica se devem ser atrasadas ajustes de layout.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método antes de alterações do pai do painel, normalmente devido a um encaixe, flutuante ou operação de ocultar automaticamente.  
  
 A implementação padrão não fará nada.  
  
##  <a name="ondrawcaption"></a>  CBasePane::OnDrawCaption  
 O framework chama este método quando a legenda é desenhada.  
  
```  
virtual void OnDrawCaption();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método não tem nenhuma funcionalidade para o `CBasePane` classe.  
  
##  <a name="onmovepanedivider"></a>  CBasePane::OnMovePaneDivider  
 Esse método não é usado atualmente.  
  
```  
virtual void OnMovePaneDivider(CPaneDivider*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CPaneDivider*`  
 Não usado.  
  
##  <a name="onpanecontextmenu"></a>  CBasePane::OnPaneContextMenu  
 Chamado pelo framework quando ele cria um menu que tem uma lista de painéis.  
  
```  
virtual void OnPaneContextMenu(
    CWnd* pParentFrame,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentFrame`  
 Um ponteiro para o quadro do pai.  
  
 [in] `point`  
 Especifica o local do menu de atalho.  
  
### <a name="remarks"></a>Comentários  
 `OnPaneContextMenu` chama o Gerenciador de encaixe, que mantém a lista de painéis que pertencem à janela do quadro atual. Este método adiciona os nomes dos painéis a um menu de atalho e o exibe. Os comandos no menu mostram ou ocultar painéis individuais.  
  
 Substitua este método para personalizar esse comportamento.  
  
##  <a name="onremovefromminiframe"></a>  CBasePane::OnRemoveFromMiniFrame  
 Chamado pelo framework quando um painel é removido de sua janela do quadro mini pai.  
  
```  
virtual void OnRemoveFromMiniFrame(CPaneFrameWnd* pMiniFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMiniFrame`  
 Um ponteiro para uma janela do quadro simplificado da qual painel está sendo removido.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando um painel é removido de sua janela do minipai quadro (como resultado de encaixe, por exemplo).  
  
 A implementação padrão não fará nada.  
  
##  <a name="onsetaccdata"></a>  CBasePane::OnSetAccData  
 `CBasePane` Não use esse método.  
  
```  
virtual BOOL OnSetAccData(long lVal);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lVal`  
 Não usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="panefrompoint"></a>  CBasePane::PaneFromPoint  
 Retorna o painel que contém o ponto especificado.  
  
```  
CBasePane* PaneFromPoint(
    CPoint point,  
    int nSensitivity,  
    bool bExactBar = false,  
    CRuntimeClass* pRTCBarType = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Especifica o ponto em coordenadas da tela, para verificar.  
  
 [in] `nSensitivity`  
 Aumente a área de pesquisa, esse valor. Um painel atenderá aos critérios de pesquisa se determinado ponto estiver na área de trabalho maior.  
  
 [in] `bExactBar`  
 `TRUE` para ignorar o `nSensitivity` parâmetro; caso contrário, `FALSE`.  
  
 [in] `pRTCBarType`  
 Se não for `NULL`, o método pesquisa somente os painéis do tipo especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O `CBasePane`-derivados do objeto que contém o ponto específico, ou `NULL` se nenhum painel foi encontrado.  
  
##  <a name="recalclayout"></a>  CBasePane::RecalcLayout  
 `CBasePane` Não use esse método.  
  
```  
virtual void RecalcLayout();
```  
  
##  <a name="removepanefromdockmanager"></a>  CBasePane::RemovePaneFromDockManager  
 Cancela o registro de um painel e remove-o da lista no Gerenciador de encaixe.  
  
```  
void RemovePaneFromDockManager(
    CBasePane* pBar,  
    BOOL bDestroy = TRUE,  
    BOOL bAdjustLayout = FALSE,  
    BOOL bAutoHide = FALSE,  
    CBasePane* pBarReplacement = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para um painel a ser removido.  
  
 [in] `bDestroy`  
 Se `TRUE`, o painel removido é destruído.  
  
 [in] `bAdjustLayout`  
 Se `TRUE`, ajustar o layout de encaixe imediatamente.  
  
 [in] `bAutoHide`  
 Se `TRUE`, o layout de encaixe está relacionado à lista de barras de ocultar automaticamente. Se `FALSE`, o layout de encaixe está relacionado à lista de painéis regulares.  
  
 [in] `pBarReplacement`  
 Um ponteiro para um painel que substitui o painel removido.  
  
##  <a name="savestate"></a>  CBasePane::SaveState  
 Salva o estado do painel no registro.  
  
```  
virtual BOOL SaveState(
    LPCTSTR lpszProfileName=NULL,  
    int nIndex=-1,  
    UINT uiID=(UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Nome do perfil.  
  
 [in] `nIndex`  
 Índice de perfil.  
  
 [in] `uiID`  
 ID do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o estado salvo com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama este método quando ele salva o estado do painel no registro. Substituir `SaveState` em uma classe derivada para armazenar informações adicionais.  
  
##  <a name="selectdefaultfont"></a>  CBasePane::SelectDefaultFont  
 Seleciona a fonte padrão para um determinado contexto de dispositivo.  
  
```  
CFont* SelectDefaultFont(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um contexto de dispositivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o padrão [classe CFont](../../mfc/reference/cfont-class.md) objeto.  
  
##  <a name="setcontrolbarstyle"></a>  CBasePane::SetControlBarStyle  
 Define o estilo de barra de controle.  
  
```  
virtual void SetControlBarStyle(DWORD dwNewStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwNewStyle`  
 Uma combinação de OR bit a bit dos valores possíveis a seguir.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`AFX_CBRS_FLOAT`|Faz com que o valor de float de barra de controle.|  
|`AFX_CBRS_AUTOHIDE`|Permite oculta automaticamente modo.|  
|`AFX_CBRS_RESIZE`|Habilita o redimensionamento da barra de controle. Quando esse sinalizador é definido, a barra de controle pode ser colocada em um painel encaixável.|  
|`AFX_CBRS_CLOSE`|Permite ocultar a barra de controle.|  
  
##  <a name="setdockingmode"></a>  CBasePane::SetDockingMode  
 Define o modo de encaixe do painel.  
  
```  
void SetDockingMode(AFX_DOCK_TYPE dockModeNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dockModeNew`  
 Especifica o novo modo de encaixe para o painel.  
  
### <a name="remarks"></a>Comentários  
 A estrutura oferece suporte a dois modos de encaixe: padrão e imediata.  
  
 O modo padrão de encaixe, painéis e janelas com moldura mini são movidas usando um retângulo de arrastar. No modo de encaixe imediato, barras de controle e janelas com moldura mini são movidas imediatamente com seu contexto.  
  
 Inicialmente, o modo de encaixe está definido globalmente por [CDockingManager::m_dockModeGlobal](../../mfc/reference/cdockingmanager-class.md#m_dockmodeglobal). Você pode definir o modo de encaixe para cada painel individualmente usando o `SetDockingMode` método.  
  
##  <a name="setpanealignment"></a>  CBasePane::SetPaneAlignment  
 Define o alinhamento para o painel.  
  
```  
virtual void SetPaneAlignment(DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
 Especifica o alinhamento de novo.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, o framework chama esse método quando um painel é encaixado em um lado do quadro principal para outro.  
  
 A tabela a seguir mostra os valores possíveis para `dwAlignment`:  
  
|Valor|Alinhamento|  
|-----------|---------------|  
|`CBRS_ALIGN_LEFT`|Alinhamento à esquerda.|  
|`CBRS_ALIGN_RIGHT`|Alinhamento à direita.|  
|`CBRS_ALIGN_TOP`|Alinhamento superior.|  
|`CBRS_ALIGN_BOTTOM`|Alinhamento da parte inferior.|  
  
##  <a name="setpanestyle"></a>  CBasePane::SetPaneStyle  
 Define o estilo do painel.  
  
```  
virtual void SetPaneStyle(DWORD dwNewStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwNewStyle`  
 Especifica o novo estilo seja definido.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser usado para definir qualquer um dos estilos CBRS_ que são definidos em afxres.h. Como o estilo de painel e o alinhamento do painel são armazenados juntos, defina o novo estilo combinando-a com o alinhamento atual da seguinte maneira.  
  
 `pPane->SetPaneStyle (pPane->GetCurrentAlignment() | CBRS_TOOLTIPS);`  
  
##  <a name="setwindowpos"></a>  CBasePane::SetWindowPos  
 Altera o tamanho, posição e a ordem Z de um painel.  
  
```  
virtual HDWP SetWindowPos(
    const CWnd* pWndInsertAfter,  
    int x,  
    int y,  
    int cx,  
    int cy,  
    UINT nFlags,  
    HDWP hdwp = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndInsertAfter`  
 Identifica o `CWnd` que vem antes que este objeto `CWnd` objeto na ordem Z. Para obter mais informações, consulte [CWnd::SetWindowPos](../../mfc/reference/cwnd-class.md#setwindowpos).  
  
 [in] `x`  
 Especifica a posição do lado esquerdo da janela.  
  
 [in] `y`  
 Especifica a posição na parte superior da janela.  
  
 [in] `cx`  
 Especifica a largura da janela.  
  
 [in] `cy`  
 Especifica a altura da janela.  
  
 [in] `nFlags`  
 Especifica as opções de tamanho e posição. Para obter mais informações, consulte [CWnd::SetWindowPos](../../mfc/reference/cwnd-class.md#setwindowpos).  
  
 [in] `hdwp`  
 Identificador para uma estrutura que contém informações de tamanho e posição de uma ou mais janelas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para uma estrutura de posição de janela adiada atualizado, ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Se `pWndInsertAfter` é `NULL`, este método chama [CWnd::SetWindowPos](../../mfc/reference/cwnd-class.md#setwindowpos). Se `pWndInsertAfter` é não - `NULL`, este método chama `DeferWindowPos`.  
  
##  <a name="showpane"></a>  CBasePane::ShowPane  
 Mostra ou oculta o painel.  
  
```  
virtual void ShowPane(
    BOOL bShow,  
    BOOL bDelay,  
    BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Especifica se deve mostrar ( `TRUE`) ou ocultar ( `FALSE`) um painel.  
  
 [in] `bDelay`  
 Se `TRUE`, recalcular o layout de encaixe está atrasada.  
  
 [in] `bActivate`  
 Se `TRUE`, o painel está ativo quando mostrado.  
  
### <a name="remarks"></a>Comentários  
 Esse método mostra ou oculta um painel. Use esse método em vez de `ShowWindow` porque este método notifica os gerenciadores de encaixe relevantes sobre alterações na visibilidade do painel.  
  
 Use [CBasePane::IsVisible](#isvisible) para determinar a visibilidade atual de um painel.  
  
##  <a name="stretchpane"></a>  CBasePane::StretchPane  
 Expande um painel vertical ou horizontalmente.  
  
```  
virtual CSize StretchPane(
    int nLength,  
    BOOL bVert);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nLength`  
 O comprimento pelo qual ampliar o painel.  
  
 [in] `bVert`  
 Se `TRUE`, ampliar o painel na vertical. Se `FALSE`, estender o painel horizontal.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do painel ampliado.  
  
##  <a name="undockpane"></a>  CBasePane::UndockPane  
 Remove o painel do local de encaixe, controle deslizante do padrão ou janela do quadro mini onde ela estiver encaixada.  
  
```  
virtual void UndockPane(BOOL bDelay=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDelay`  
 Se for TRUE, o layout de encaixe não é recalculado imediatamente.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para manipular o estado do painel ou excluir o painel de layout do encaixe.  
  
 Se você quiser continuar a usar esse painel, chame o [CBasePane::DockPane](#dockpane) ou [CBasePane::FloatPane](#floatpane) antes de chamar esse método.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [CPane](../../mfc/reference/cbasepane-class.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)
