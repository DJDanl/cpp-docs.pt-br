---
title: Classe CDockingManager
ms.date: 11/04/2016
f1_keywords:
- CDockingManager
- AFXDOCKINGMANAGER/CDockingManager
- AFXDOCKINGMANAGER/CDockingManager::AddDockSite
- AFXDOCKINGMANAGER/CDockingManager::AddHiddenMDITabbedBar
- AFXDOCKINGMANAGER/CDockingManager::AddMiniFrame
- AFXDOCKINGMANAGER/CDockingManager::AddPane
- AFXDOCKINGMANAGER/CDockingManager::AdjustDockingLayout
- AFXDOCKINGMANAGER/CDockingManager::AdjustPaneFrames
- AFXDOCKINGMANAGER/CDockingManager::AdjustRectToClientArea
- AFXDOCKINGMANAGER/CDockingManager::AlignAutoHidePane
- AFXDOCKINGMANAGER/CDockingManager::AutoHidePane
- AFXDOCKINGMANAGER/CDockingManager::BringBarsToTop
- AFXDOCKINGMANAGER/CDockingManager::BuildPanesMenu
- AFXDOCKINGMANAGER/CDockingManager::CalcExpectedDockedRect
- AFXDOCKINGMANAGER/CDockingManager::Create
- AFXDOCKINGMANAGER/CDockingManager::DeterminePaneAndStatus
- AFXDOCKINGMANAGER/CDockingManager::DisableRestoreDockState
- AFXDOCKINGMANAGER/CDockingManager::DockPane
- AFXDOCKINGMANAGER/CDockingManager::DockPaneLeftOf
- AFXDOCKINGMANAGER/CDockingManager::EnableAutoHidePanes
- AFXDOCKINGMANAGER/CDockingManager::EnableDocking
- AFXDOCKINGMANAGER/CDockingManager::EnableDockSiteMenu
- AFXDOCKINGMANAGER/CDockingManager::EnablePaneContextMenu
- AFXDOCKINGMANAGER/CDockingManager::FindDockSite
- AFXDOCKINGMANAGER/CDockingManager::FindDockSiteByPane
- AFXDOCKINGMANAGER/CDockingManager::FindPaneByID
- AFXDOCKINGMANAGER/CDockingManager::FixupVirtualRects
- AFXDOCKINGMANAGER/CDockingManager::FrameFromPoint
- AFXDOCKINGMANAGER/CDockingManager::GetClientAreaBounds
- AFXDOCKINGMANAGER/CDockingManager::GetDockingMode
- AFXDOCKINGMANAGER/CDockingManager::GetDockSiteFrameWnd
- AFXDOCKINGMANAGER/CDockingManager::GetEnabledAutoHideAlignment
- AFXDOCKINGMANAGER/CDockingManager::GetMiniFrames
- AFXDOCKINGMANAGER/CDockingManager::GetOuterEdgeBounds
- AFXDOCKINGMANAGER/CDockingManager::GetPaneList
- AFXDOCKINGMANAGER/CDockingManager::GetSmartDockingManager
- AFXDOCKINGMANAGER/CDockingManager::GetSmartDockingManagerPermanent
- AFXDOCKINGMANAGER/CDockingManager::GetSmartDockingParams
- AFXDOCKINGMANAGER/CDockingManager::GetSmartDockingTheme
- AFXDOCKINGMANAGER/CDockingManager::HideAutoHidePanes
- AFXDOCKINGMANAGER/CDockingManager::InsertDockSite
- AFXDOCKINGMANAGER/CDockingManager::InsertPane
- AFXDOCKINGMANAGER/CDockingManager::IsDockSiteMenu
- AFXDOCKINGMANAGER/CDockingManager::IsInAdjustLayout
- AFXDOCKINGMANAGER/CDockingManager::IsOLEContainerMode
- AFXDOCKINGMANAGER/CDockingManager::IsPointNearDockSite
- AFXDOCKINGMANAGER/CDockingManager::IsPrintPreviewValid
- AFXDOCKINGMANAGER/CDockingManager::LoadState
- AFXDOCKINGMANAGER/CDockingManager::LockUpdate
- AFXDOCKINGMANAGER/CDockingManager::OnActivateFrame
- AFXDOCKINGMANAGER/CDockingManager::OnClosePopupMenu
- AFXDOCKINGMANAGER/CDockingManager::OnMoveMiniFrame
- AFXDOCKINGMANAGER/CDockingManager::OnPaneContextMenu
- AFXDOCKINGMANAGER/CDockingManager::PaneFromPoint
- AFXDOCKINGMANAGER/CDockingManager::ProcessPaneContextMenuCommand
- AFXDOCKINGMANAGER/CDockingManager::RecalcLayout
- AFXDOCKINGMANAGER/CDockingManager::ReleaseEmptyPaneContainers
- AFXDOCKINGMANAGER/CDockingManager::RemoveHiddenMDITabbedBar
- AFXDOCKINGMANAGER/CDockingManager::RemoveMiniFrame
- AFXDOCKINGMANAGER/CDockingManager::RemovePaneFromDockManager
- AFXDOCKINGMANAGER/CDockingManager::ReplacePane
- AFXDOCKINGMANAGER/CDockingManager::ResortMiniFramesForZOrder
- AFXDOCKINGMANAGER/CDockingManager::SaveState
- AFXDOCKINGMANAGER/CDockingManager::SendMessageToMiniFrames
- AFXDOCKINGMANAGER/CDockingManager::Serialize
- AFXDOCKINGMANAGER/CDockingManager::SetAutohideZOrder
- AFXDOCKINGMANAGER/CDockingManager::SetDockingMode
- AFXDOCKINGMANAGER/CDockingManager::SetDockState
- AFXDOCKINGMANAGER/CDockingManager::SetPrintPreviewMode
- AFXDOCKINGMANAGER/CDockingManager::SetSmartDockingParams
- AFXDOCKINGMANAGER/CDockingManager::ShowDelayShowMiniFrames
- AFXDOCKINGMANAGER/CDockingManager::ShowPanes
- AFXDOCKINGMANAGER/CDockingManager::StartSDocking
- AFXDOCKINGMANAGER/CDockingManager::StopSDocking
- AFXDOCKINGMANAGER/CDockingManager::m_bHideDockingBarsInContainerMode
- AFXDOCKINGMANAGER/CDockingManager::m_dockModeGlobal
- AFXDOCKINGMANAGER/CDockingManager::m_nDockSensitivity
- AFXDOCKINGMANAGER/CDockingManager::m_nTimeOutBeforeDockingBarDock
- AFXDOCKINGMANAGER/CDockingManager::m_nTimeOutBeforeToolBarDock
helpviewer_keywords:
- CDockingManager [MFC], AddDockSite
- CDockingManager [MFC], AddHiddenMDITabbedBar
- CDockingManager [MFC], AddMiniFrame
- CDockingManager [MFC], AddPane
- CDockingManager [MFC], AdjustDockingLayout
- CDockingManager [MFC], AdjustPaneFrames
- CDockingManager [MFC], AdjustRectToClientArea
- CDockingManager [MFC], AlignAutoHidePane
- CDockingManager [MFC], AutoHidePane
- CDockingManager [MFC], BringBarsToTop
- CDockingManager [MFC], BuildPanesMenu
- CDockingManager [MFC], CalcExpectedDockedRect
- CDockingManager [MFC], Create
- CDockingManager [MFC], DeterminePaneAndStatus
- CDockingManager [MFC], DisableRestoreDockState
- CDockingManager [MFC], DockPane
- CDockingManager [MFC], DockPaneLeftOf
- CDockingManager [MFC], EnableAutoHidePanes
- CDockingManager [MFC], EnableDocking
- CDockingManager [MFC], EnableDockSiteMenu
- CDockingManager [MFC], EnablePaneContextMenu
- CDockingManager [MFC], FindDockSite
- CDockingManager [MFC], FindDockSiteByPane
- CDockingManager [MFC], FindPaneByID
- CDockingManager [MFC], FixupVirtualRects
- CDockingManager [MFC], FrameFromPoint
- CDockingManager [MFC], GetClientAreaBounds
- CDockingManager [MFC], GetDockingMode
- CDockingManager [MFC], GetDockSiteFrameWnd
- CDockingManager [MFC], GetEnabledAutoHideAlignment
- CDockingManager [MFC], GetMiniFrames
- CDockingManager [MFC], GetOuterEdgeBounds
- CDockingManager [MFC], GetPaneList
- CDockingManager [MFC], GetSmartDockingManager
- CDockingManager [MFC], GetSmartDockingManagerPermanent
- CDockingManager [MFC], GetSmartDockingParams
- CDockingManager [MFC], GetSmartDockingTheme
- CDockingManager [MFC], HideAutoHidePanes
- CDockingManager [MFC], InsertDockSite
- CDockingManager [MFC], InsertPane
- CDockingManager [MFC], IsDockSiteMenu
- CDockingManager [MFC], IsInAdjustLayout
- CDockingManager [MFC], IsOLEContainerMode
- CDockingManager [MFC], IsPointNearDockSite
- CDockingManager [MFC], IsPrintPreviewValid
- CDockingManager [MFC], LoadState
- CDockingManager [MFC], LockUpdate
- CDockingManager [MFC], OnActivateFrame
- CDockingManager [MFC], OnClosePopupMenu
- CDockingManager [MFC], OnMoveMiniFrame
- CDockingManager [MFC], OnPaneContextMenu
- CDockingManager [MFC], PaneFromPoint
- CDockingManager [MFC], ProcessPaneContextMenuCommand
- CDockingManager [MFC], RecalcLayout
- CDockingManager [MFC], ReleaseEmptyPaneContainers
- CDockingManager [MFC], RemoveHiddenMDITabbedBar
- CDockingManager [MFC], RemoveMiniFrame
- CDockingManager [MFC], RemovePaneFromDockManager
- CDockingManager [MFC], ReplacePane
- CDockingManager [MFC], ResortMiniFramesForZOrder
- CDockingManager [MFC], SaveState
- CDockingManager [MFC], SendMessageToMiniFrames
- CDockingManager [MFC], Serialize
- CDockingManager [MFC], SetAutohideZOrder
- CDockingManager [MFC], SetDockingMode
- CDockingManager [MFC], SetDockState
- CDockingManager [MFC], SetPrintPreviewMode
- CDockingManager [MFC], SetSmartDockingParams
- CDockingManager [MFC], ShowDelayShowMiniFrames
- CDockingManager [MFC], ShowPanes
- CDockingManager [MFC], StartSDocking
- CDockingManager [MFC], StopSDocking
- CDockingManager [MFC], m_bHideDockingBarsInContainerMode
- CDockingManager [MFC], m_dockModeGlobal
- CDockingManager [MFC], m_nDockSensitivity
- CDockingManager [MFC], m_nTimeOutBeforeDockingBarDock
- CDockingManager [MFC], m_nTimeOutBeforeToolBarDock
ms.assetid: 98e69c43-55d8-4f43-b861-4fda80ec1e32
ms.openlocfilehash: 76fd12b0817c99d0d08327f9d9156eadf3559dc5
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753329"
---
# <a name="cdockingmanager-class"></a>Classe CDockingManager

Implementa a funcionalidade principal que controla o layout de encaixe em uma janela de quadro principal.

## <a name="syntax"></a>Sintaxe

```
class CDockingManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDockingManager::AddDockSite](#adddocksite)|Cria um painel de doca e adiciona-o à lista de barras de controle.|
|[CDockingManager::AddHiddenMDI'TtabbedBar](#addhiddenmditabbedbar)|Adiciona uma alça a um painel de barras à lista de painéis de barra mdi escondidos.|
|[CDockingManager::AddMiniFrame](#addminiframe)|Adiciona um quadro à lista de mini quadros.|
|[CDockingManager::AddPane](#addpane)|Registra um painel com o gerente de acoplamento.|
|[CDockingManager::AdjustDockingLayout](#adjustdockinglayout)|Recalcula e ajusta o layout de todos os painéis em uma janela de quadro.|
|[CDockingManager::AdjustPaneFrames](#adjustpaneframes)|Faz com que a mensagem WM_NCCALCSIZE `CPaneFrameWnd` seja enviada para todos os painéis e janelas.|
|[CDockingManager::AdjustRectToClientArea](#adjustrecttoclientarea)|Ajusta o alinhamento de um retângulo.|
|[CDockingManager::AlignAutoHidePane](#alignautohidepane)|Redimensiona um painel de encaixe no modo de ocultação automática para que ele leve toda a largura ou altura da área cliente do quadro cercada por locais de doca.|
|[CDockingManager::AutoHidePane](#autohidepane)|Cria uma barra de ferramentas de ocultação automática.|
|[CDockingManager::BringBarsToTop](#bringbarstotop)|Traz as barras ancoradas que têm o alinhamento especificado para o topo.|
|[CDockingManager::BuildPanesMenu](#buildpanesmenu)|Adiciona nomes de painéis de encaixe e barras de ferramentas a um menu.|
|[CDockingManager::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcula o retângulo esperado de uma janela ancorada.|
|[CDockingManager::Criar](#create)|Cria um gerente de acoplamento.|
|[CDockingManager::DeterminePaneAndStatus](#determinepaneandstatus)|Determina o painel que contém um determinado ponto e seu status de acoplamento.|
|[CDockingManager::DisableRestoreDockState](#disablerestoredockstate)|Habilita ou desativa o carregamento do layout de acoplamento do registro.|
|[CDockingManager::DockPane](#dockpane)|Docas um painel para outro painel ou para uma janela de moldura.|
|[CDockingManager::DockPaneLeftOf](#dockpaneleftof)|Acopla um painel à esquerda de outro painel.|
|[CDockingManager::EnableAutoHidePanes](#enableautohidepanes)|Permite o encaixe do painel para o quadro principal, cria um painel de doca e adiciona-o à lista de barras de controle.|
|[CDockingManager::Habilitar docking](#enabledocking)|Cria um painel de doca e permite o encaixe do painel para o quadro principal.|
|[CDockingManager::AtivarMenu site do Dock](#enabledocksitemenu)|Exibe um botão adicional que abre um menu pop-up nas legendas de todos os painéis de encaixe.|
|[CDockingManager::EnablePaneContextMenu](#enablepanecontextmenu)|Diz à biblioteca para exibir um menu de contexto especial que tenha uma lista de barras de ferramentas de aplicativos e painéis de encaixe quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem WM_CONTEXTMENU.|
|[CDockingManager::FindDockSite](#finddocksite)|Recupera o painel de barras que está na posição especificada e que tem o alinhamento especificado.|
|[CDockingManager::FindDockSiteByPane](#finddocksitebypane)|Devolve o painel de barras que tem a id do painel da barra de destino.|
|[CDockingManager::FindPaneByID](#findpanebyid)|Encontra um painel pelo ID de controle especificado.|
|[CDockingManager::FixupVirtualRects](#fixupvirtualrects)|Compromete todas as posições atuais da barra de ferramentas em retângulos virtuais.|
|[CDockingManager::FrameFromPoint](#framefrompoint)|Retorna o quadro que contém o ponto dado.|
|[CDockingManager::GetClientAreaBounds](#getclientareabounds)|Obtém o retângulo que contém os limites da área do cliente.|
|[CDockingManager::GetDockingMode](#getdockingmode)|Retorna o modo de acoplamento atual.|
|[CDockingManager::GetDockSiteFrameWnd](#getdocksiteframewnd)|Recebe um ponteiro para a janela dos pais.|
|[CDockingManager::GetEnabledAuto'HideAlignment](#getenabledautohidealignment)|Retorna o alinhamento ativado dos painéis.|
|[CDockingManager::GetMiniFrames](#getminiframes)|Recebe uma lista de miniquadros.|
|[CDockingManager::GetOuterEdgeBounds](#getouteredgebounds)|Obtém um retângulo que contém as bordas externas do quadro.|
|[CDockingManager::GetPaneList](#getpanelist)|Retorna uma lista de painéis que pertencem ao gerente de acoplamento. Isso inclui todos os painéis flutuantes.|
|[CDockingManager::GetSmartDockingManager](#getsmartdockingmanager)|Recupera um ponteiro para o gerenciador de acoplamento inteligente.|
|[CDockingManager::GetSmartDockingManagerPermanent](#getsmartdockingmanagerpermanent)|Recupera um ponteiro para o gerenciador de acoplamento inteligente.|
|[CDockingManager::GetSmartDockingParams](#getsmartdockingparams)|Retorna os parâmetros de acoplamento inteligente satisumido para o gerenciador de acoplamento.|
|[CDockingManager::GetSmartDockingTheme](#getsmartdockingtheme)|Um método estático que retorna um tema usado para exibir marcadores de encaixe inteligentes.|
|[CDockingManager::HideAutoHidePanes](#hideautohidepanes)|Esconde um painel que está no modo de ocultação automática.|
|[CDockingManager::InsertDockSite](#insertdocksite)|Cria um painel de doca e insere-o na lista de barras de controle.|
|[CDockingManager::InsertPane](#insertpane)|Insere um painel de controle na lista de barras de controle.|
|[CDockingManager::IsDockSiteMenu](#isdocksitemenu)|Especifica se um menu pop-up é exibido nas legendas de todos os painéis.|
|[CDockingManager::IsInAdjustLayout](#isinadjustlayout)|Determina se os layouts de todos os painéis estão ajustados.|
|[CDockingManager::IsOLEContainerMode](#isolecontainermode)|Especifica se o gerenciador de encaixe está no modo de contêiner OLE.|
|[CDockingManager::IsPointNearDockSite](#ispointneardocksite)|Determina se um ponto especificado está perto do local das docas.|
|[CDockingManager::IsPrintPreviewValid](#isprintpreviewvalid)|Determina se o modo de visualização de impressão está definido.|
|[CDockingManager::LoadState](#loadstate)|Carrega o estado do gerente de acoplamento do registro.|
|[CDockingManager::LockUpdate](#lockupdate)|Bloqueia a janela dada.|
|[CDockingManager::OnActivateFrame](#onactivateframe)|Chamado pela estrutura quando a janela do quadro é ativa ou é desativada.|
|[CDockingManager::OnClosePopupMenu](#onclosepopupmenu)|Chamado pelo framework quando um menu pop-up ativo processa uma mensagem WM_DESTROY.|
|[CDockingManager::OnMoveMiniFrame](#onmoveminiframe)|Chamado pela estrutura para mover uma janela de mini-quadro.|
|[CDockingManager::OnPaneContextMenu](#onpanecontextmenu)|Chamado pela estrutura quando constrói um menu que tem uma lista de painéis.|
|[CDockingManager::PaneFromPoint](#panefrompoint)|Devolve o painel que contém o ponto dado.|
|[CDockingManager::ProcessPaneContextMenuCommandCommand](#processpanecontextmenucommand)|Chamado pela estrutura para selecionar ou limpar uma caixa de seleção para o comando especificado e recalcular o layout de um painel mostrado.|
|[CDockingManager::RecalcLayout](#recalclayout)|Recalcula o layout interno dos controles presentes na lista de controles.|
|[CDockingManager::ReleaseEmptyPaneContainers](#releaseemptypanecontainers)|Libera os recipientes vazios do painel.|
|[CDockingManager::RemoveHiddenMDI'T'Cotode](#removehiddenmditabbedbar)|Remove o painel de barra escondido especificado.|
|[CDockingManager::RemoveMiniFrame](#removeminiframe)|Remove um quadro especificado da lista de mini quadros.|
|[CDockingManager::RemovePaneFromDockManager](#removepanefromdockmanager)|Desregistra um painel e remove-o da lista no gerenciador de acoplamento.|
|[CDockingManager::ReplacePane](#replacepane)|Substitui um painel por outro.|
|[CDockingManager::ResortMiniFramesForZOrder](#resortminiframesforzorder)|Recorre os quadros na lista de mini quadros.|
|[CDockingManager::SaveState](#savestate)|Salva o estado do gerente de acoplamento para o registro.|
|[CDockingManager::SendMessageToMiniFrames](#sendmessagetominiframes)|Envia a mensagem especificada para todos os mini quadros.|
|[CDockingManager::Serialize](#serialize)|Escreve o gerente de ancoragem para um arquivo. (Substitui [cobject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CDockingManager::SetAutohideZOrder](#setautohidezorder)|Define o tamanho, largura e altura das barras de controle e do painel especificado.|
|[CDockingManager::SetDockingMode](#setdockingmode)|Define o modo de acoplamento.|
|[CDockingManager::SetDockState](#setdockstate)|Define o estado de acoplamento das barras de controle, dos mini quadros e das barras de auto-ocultamento.|
|[CDockingManager::SetPrintPreviewMode](#setprintpreviewmode)|Define o modo de visualização de impressão das barras exibidas na visualização de impressão.|
|[CDockingManager::SetSmartDockingParams](#setsmartdockingparams)|Define os parâmetros que definem o comportamento do encaixe inteligente.|
|[CDockingManager::ShowDelayShowMiniFrames](#showdelayshowminiframes)|Mostra ou esconde as janelas dos mini quadros.|
|[CDockingManager::ShowPanes](#showpanes)|Mostra ou esconde os painéis do controle e das barras de auto-ocultação.|
|[CDockingManager::StartSDocking](#startsdocking)|Inicia o acoplamento inteligente da janela especificada de acordo com o alinhamento do gerenciador de acoplamento inteligente.|
|[CDockingManager::StopSDocking](#stopsdocking)|Impede o acoplamento inteligente.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CDockingManager::m_bHideDockingBarsInContainerMode](#m_bhidedockingbarsincontainermode)|Especifica se o gerenciador de encaixe esconde painéis no modo de contêiner OLE.|
|[CDockingManager::m_dockModeGlobal](#m_dockmodeglobal)|Especifica o modo de acoplamento global.|
|[CDockingManager::m_nDockSensitivity](#m_ndocksensitivity)|Especifica a sensibilidade de acoplamento.|
|[CDockingManager::m_nTimeOutBeforeDockingBarDock](#m_ntimeoutbeforedockingbardock)|Especifica a hora, em milissegundos, antes que um painel de acoplamento seja encaixado no modo de acoplamento imediato.|
|[CDockingManager::m_nTimeOutBeforeToolBarDock](#m_ntimeoutbeforetoolbardock)|Especifica a hora, em milissegundos, antes que uma barra de ferramentas seja encaixada na janela principal do quadro.|

## <a name="remarks"></a>Comentários

A janela do quadro principal cria e inicializa essa classe automaticamente.

O objeto gerenciador de encaixe contém uma lista de todos os painéis que estão no layout de encaixe, e também uma lista de todas as janelas [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) que pertencem à janela principal do quadro.

A `CDockingManager` classe implementa alguns serviços que você `CPaneFrameWnd` pode usar para encontrar um painel ou uma janela. Você geralmente não liga diretamente para esses serviços porque eles estão enrolados no objeto da janela da moldura principal. Para obter mais informações, consulte [CPaneFrameWnd Class](../../mfc/reference/cpaneframewnd-class.md).

## <a name="customization-tips"></a>Dicas de personalização

As seguintes `CDockingManager` dicas se aplicam aos objetos:

- [O CDockingManager Class](../../mfc/reference/cdockingmanager-class.md) suporta esses modos de acoplamento:

  - `AFX_DOCK_TYPE::DT_IMMEDIATE`

  - `AFX_DOCK_TYPE::DT_STANDARD`

  - `AFX_DOCK_TYPE::DT_SMART`

  Esses modos de encaixe são definidos pelo [CDockingManager::m_dockModeGlobal](#m_dockmodeglobal) e são definidos ligando para [CDockingManager::SetDockingMode](#setdockingmode).

- Se você quiser criar um painel não flutuante e não resizável, ligue para o método [CDockingManager:::AddPane.](#addpane) Este método registra o painel com o gerente de acoplamento, que é responsável pelo layout do painel.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CDockingManager` usar vários métodos na classe para configurar um `CDockingManager` objeto. O exemplo mostra como exibir um botão adicional que abre um menu pop-up nas legendas de todos os painéis de encaixe e como definir o modo de encaixe do objeto. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#24](../../mfc/codesnippet/cpp/cdockingmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cdockingmanager](../../mfc/reference/cdockingmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDockingManager.h

## <a name="cdockingmanageradddocksite"></a><a name="adddocksite"></a>CDockingManager::AddDockSite

Cria um painel de doca e adiciona-o à lista de barras de controle.

```
BOOL AddDockSite(
    const AFX_DOCKSITE_INFO& info,
    CDockSite** ppDockBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*Informação*<br/>
[em] Uma referência a uma estrutura de informações que contém alinhamento do painel de doca.

*ppDockBar*<br/>
[fora] Um ponteiro para um ponteiro para o novo painel de doca.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel de doca foi criado com sucesso; FALSO de outra forma.

## <a name="cdockingmanageraddhiddenmditabbedbar"></a><a name="addhiddenmditabbedbar"></a>CDockingManager::AddHiddenMDI'TtabbedBar

Adiciona uma alça a um painel de barras à lista de painéis de barra mdi escondidos.

```cpp
void AddHiddenMDITabbedBar(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para um painel de barras

## <a name="cdockingmanageraddpane"></a><a name="addpane"></a>CDockingManager::AddPane

Registra um painel com o gerente de acoplamento.

```
BOOL AddPane(
    CBasePane* pWnd,
    BOOL bTail = TRUE,
    BOOL bAutoHide = FALSE,
    BOOL bInsertForOuterEdge = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[dentro, fora] Especifica o painel para adicionar ao gerenciador de encaixe.

*bTail*<br/>
[em] TRUE para adicionar o painel ao final da lista de painéis para o gerente de encaixe; caso contrário, FALSE.

*bAutoHide*<br/>
[em] Somente para uso interno. Use sempre o valor padrão FALSE.

*bInsertForOuterEdge*<br/>
[em] Somente para uso interno. Use sempre o valor padrão FALSE.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel foi registrado com sucesso com o gerente de acoplamento; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame este método para registrar painéis não flutuantes e não resizáveis com o gerenciador de acoplamento. Se você não registrar os painéis, eles não aparecerão corretamente quando o gerente de acoplamento for colocado.

## <a name="cdockingmanageradjustdockinglayout"></a><a name="adjustdockinglayout"></a>CDockingManager::AdjustDockingLayout

Recalcula e ajusta o layout de todos os painéis em uma janela de quadro.

```
virtual void AdjustDockingLayout(HDWP hdwp = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hdwp*<br/>
[em] Especifica a estrutura de posição da janela diferida. Para obter mais informações, consulte [Os Tipos de Dados do Windows](/windows/win32/WinProg/windows-data-types).

### <a name="remarks"></a>Comentários

## <a name="cdockingmanageraddminiframe"></a><a name="addminiframe"></a>CDockingManager::AddMiniFrame

Adiciona um quadro à lista de mini quadros.

```
virtual BOOL AddMiniFrame(CPaneFrameWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Um ponteiro para um quadro.

### <a name="return-value"></a>Valor retornado

TRUE se o quadro não estiver na lista de mini quadros e for adicionado com sucesso; FALSO de outra forma.

## <a name="cdockingmanageradjustpaneframes"></a><a name="adjustpaneframes"></a>CDockingManager::AdjustPaneFrames

Faz com que a mensagem WM_NCCALCSIZE `CPaneFrameWnd` seja enviada para todos os painéis e janelas.

```
virtual void AdjustPaneFrames();
```

### <a name="remarks"></a>Comentários

## <a name="cdockingmanageradjustrecttoclientarea"></a><a name="adjustrecttoclientarea"></a>CDockingManager::AdjustRectToClientArea

Ajusta o alinhamento de um retângulo.

```
virtual BOOL AdjustRectToClientArea(
    CRect& rectResult,
    DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

*rectResult*<br/>
[em] Uma referência `CRect` a um objeto

*Dwalignment*<br/>
[em] O alinhamento `CRect` do objeto

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o `CRect` alinhamento do objeto foi ajustado; FALSO de outra forma.

### <a name="remarks"></a>Comentários

O parâmetro *dwAlignment* pode ter um dos seguintes valores:

- Cbrs_align_top

- Cbrs_align_bottom

- Cbrs_align_left

- Cbrs_align_right

## <a name="cdockingmanageralignautohidepane"></a><a name="alignautohidepane"></a>CDockingManager::AlignAutoHidePane

Redimensiona um painel de encaixe no modo de ocultação automática para que ele leve toda a largura ou altura da área cliente do quadro cercada por locais de doca.

```cpp
void AlignAutoHidePane(
    CPaneDivider* pDefaultSlider,
    BOOL bIsVisible = TRUE);
```

### <a name="parameters"></a>Parâmetros

*controle deslizante pDefault*<br/>
[em] O painel de controle deslizante de acoplamento.

*bIsVisible*<br/>
[em] VERDADE se o painel de acoplamento for visível; FALSO de outra forma.

## <a name="cdockingmanagerautohidepane"></a><a name="autohidepane"></a>CDockingManager::AutoHidePane

Cria uma barra de ferramentas de ocultação automática.

```
CMFCAutoHideToolBar* AutoHidePane(
    CDockablePane* pBar,
    CMFCAutoHideToolBar* pCurrAutoHideToolBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para o painel da barra.

*pCurrAutoHideToolBar*<br/>
[em] Um ponteiro para uma barra de ferramentas de ocultação automática.

### <a name="return-value"></a>Valor retornado

NULA SE a barra de ferramentas de ocultação automática não for criada; caso contrário, um ponteiro para a nova barra de ferramentas.

## <a name="cdockingmanagerbringbarstotop"></a><a name="bringbarstotop"></a>CDockingManager::BringBarsToTop

Traz as barras ancoradas que têm o alinhamento especificado para o topo.

```cpp
void BringBarsToTop(
    DWORD dwAlignment = 0,
    BOOL bExcludeDockedBars = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Dwalignment*<br/>
[em] O alinhamento das barras de doca que são trazidas para o topo de outras janelas.

*bExcluDockedBars*<br/>
[em] VERDADE para excluir as barras ancoradas de estar em cima; caso contrário, FALSO.

## <a name="cdockingmanagerbuildpanesmenu"></a><a name="buildpanesmenu"></a>CDockingManager::BuildPanesMenu

Adiciona nomes de painéis de encaixe e barras de ferramentas a um menu.

```cpp
void BuildPanesMenu(
    CMenu& menu,
    BOOL bToolbarsOnly);
```

### <a name="parameters"></a>Parâmetros

*Menu*<br/>
[em] Um menu para adicionar os nomes de painéis de encaixe e barras de ferramentas.

*bBarras de ferramentassomente*<br/>
[em] TRUE para adicionar apenas nomes de barra de ferramentas ao menu; FALSO de outra forma.

## <a name="cdockingmanagercalcexpecteddockedrect"></a><a name="calcexpecteddockedrect"></a>CDockingManager::CalcExpectedDockedRect

Calcula o retângulo esperado de uma janela ancorada.

```cpp
void CalcExpectedDockedRect(
    CWnd* pWnd,
    CPoint ptMouse,
    CRect& rectResult,
    BOOL& bDrawTab,
    CDockablePane** ppTargetBar);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Um ponteiro para a janela para acoplar.

*ptMouse*<br/>
[em] A localização do rato.

*rectResult*<br/>
[fora] O retângulo calculado.

*bDrawTab*<br/>
[em] TRUE para desenhar uma guia; caso contrário, FALSO.

*ppTargetBar*<br/>
[fora] Um ponteiro para um ponteiro para o painel alvo.

### <a name="remarks"></a>Comentários

Este método calcula o retângulo que uma janela ocuparia se um usuário arrastasse a janela até o ponto especificado pelo *ptMouse* e a encaixasse lá.

## <a name="cdockingmanagercreate"></a><a name="create"></a>CDockingManager::Criar

Cria um gerente de acoplamento.

```
BOOL Create(CFrameWnd* pParentWnd);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
[em] Um ponteiro para o quadro pai do gerente de acoplamento. Este valor não deve ser NULO.

### <a name="return-value"></a>Valor retornado

VERDADE sempre.

## <a name="cdockingmanagerdeterminepaneandstatus"></a><a name="determinepaneandstatus"></a>CDockingManager::DeterminePaneAndStatus

Determina o painel que contém um determinado ponto e seu status de acoplamento.

```
virtual AFX_CS_STATUS DeterminePaneAndStatus(
    CPoint pt,
    int nSensitivity,
    DWORD dwEnabledAlignment,
    CBasePane** ppTargetBar,
    const CBasePane* pBarToIgnore,
    const CBasePane* pBarToDock);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
[em] A localização do painel para verificar.

*nSensibilidade*<br/>
[em] O valor para aumentar o retângulo da janela de cada painel verificado. Um painel satisfaz os critérios de busca se o ponto dado estiver nesta região aumentada.

*dwEnabledAlignment*<br/>
[em] O alinhamento do painel de acoplamento.

*ppTargetBar*<br/>
[fora] Um ponteiro para um ponteiro para o painel alvo.

*pBarToIgnore*<br/>
[em] O painel que o método ignora.

*pBarToDock*<br/>
[em] O painel que está ancorado.

### <a name="return-value"></a>Valor retornado

O status de acoplamento.

### <a name="remarks"></a>Comentários

O status de acoplamento pode ser um dos seguintes valores:

|AFX_CS_STATUS valor|Significado|
|---------------------------|-------------|
|CS_NOTHING|O ponteiro não é sobre um local de doca. Portanto, mantenha o painel flutuando.|
|CS_DOCK_IMMEDIATELY|O ponteiro está sobre o local de doca no modo imediato (DT_IMMEDIATE estilo está ativado), então o painel deve ser encaixado imediatamente.|
|CS_DELAY_DOCK|O ponteiro é sobre um local de doca que é outro painel de acoplamento ou é uma borda do quadro principal.|
|CS_DELAY_DOCK_TO_TAB|O ponteiro está sobre um local de doca que faz com que o painel seja ancorado em uma janela com guias. Isso ocorre quando o mouse está sobre uma legenda de outro painel de encaixe ou sobre uma área de guia de um painel com guias.|

## <a name="cdockingmanagerdisablerestoredockstate"></a><a name="disablerestoredockstate"></a>CDockingManager::DisableRestoreDockState

Habilita ou desativa o carregamento do layout de acoplamento do registro.

```cpp
void DisableRestoreDockState(BOOL bDisable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bDisable*<br/>
[em] TRUE desabilitar o carregamento do layout de acoplamento do registro; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame este método quando você deve preservar o layout atual de painéis de encaixe e barras de ferramentas quando o estado de aplicação estiver carregando.

## <a name="cdockingmanagerdockpane"></a><a name="dockpane"></a>CDockingManager::DockPane

Docas um painel para outro painel ou para uma janela de moldura.

```cpp
void DockPane(
    CBasePane* pBar,
    UINT nDockBarID = 0,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para um painel de barras para atracar.

*nDockBarID*<br/>
[em] A id do bar para atracar.

*Lprect*<br/>
[em] O retângulo de destino.

## <a name="cdockingmanagerdockpaneleftof"></a><a name="dockpaneleftof"></a>CDockingManager::DockPaneLeftOf

Acopla um painel à esquerda de outro painel.

```
BOOL DockPaneLeftOf(
    CPane* pBarToDock,
    CPane* pTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pBarToDock*<br/>
[em] Um ponteiro para o painel a ser ancorado à esquerda de *pTargetBar*.

*pTargetBar*<br/>
[em] Um ponteiro para o painel alvo.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel foi ancorado com sucesso; caso contrário, FALSE.

## <a name="cdockingmanagerenableautohidepanes"></a><a name="enableautohidepanes"></a>CDockingManager::EnableAutoHidePanes

Permite o encaixe do painel para o quadro principal, cria um painel de doca e adiciona-o à lista de barras de controle.

```
BOOL EnableAutoHidePanes(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
[em] O alinhamento de acoplamento.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel de doca foi criado com sucesso; FALSO de outra forma.

## <a name="cdockingmanagerenabledocking"></a><a name="enabledocking"></a>CDockingManager::Habilitar docking

Cria um painel de doca e permite o encaixe do painel para o quadro principal.

```
BOOL EnableDocking(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
[em] O alinhamento de acoplamento.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel de doca foi criado com sucesso; FALSO de outra forma.

## <a name="cdockingmanagerenabledocksitemenu"></a><a name="enabledocksitemenu"></a>CDockingManager::AtivarMenu site do Dock

Exibe um botão adicional que abre um menu pop-up nas legendas de todos os painéis de encaixe.

```
static void EnableDockSiteMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para habilitar o menu do site de docas; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O menu dock site exibe as seguintes opções para alterar o estado de acoplamento do painel:

- `Floating`- Flutua um painel

- `Docking`- Docas um painel no quadro principal no local onde o painel foi ancorado pela última vez

- `AutoHide`- Muda o painel para o modo de ocultação automática

- `Hide`- Esconde um painel

Por padrão, este menu não é exibido.

## <a name="cdockingmanagerenablepanecontextmenu"></a><a name="enablepanecontextmenu"></a>CDockingManager::EnablePaneContextMenu

Diz à biblioteca para exibir um menu de contexto especial que tenha uma lista de barras de ferramentas de aplicativos e painéis de encaixe quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem WM_CONTEXTMENU.

```cpp
void EnablePaneContextMenu(
    BOOL bEnable,
    UINT uiCustomizeCmd,
    const CString& strCustomizeText,
    BOOL bToolbarsOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Se TRUE, a biblioteca ativa o suporte para menu de contexto automático; se FALSE a biblioteca desligar o suporte para menu de contexto automático.

*uiCustomizeCmd*<br/>
[em] Um id de comando para o item **Personalizar** no menu.

*strPersonalizeText*<br/>
[em] O texto do item **Personalizar.**

*bBarras de ferramentassomente*<br/>
[em] Se TRUE, o menu exibe apenas uma lista de barras de ferramentas de aplicativos; se FALSE, a biblioteca adiciona painéis de encaixe de aplicativos a esta lista.

## <a name="cdockingmanagerfinddocksite"></a><a name="finddocksite"></a>CDockingManager::FindDockSite

Recupera o painel de barras que está na posição especificada e que tem o alinhamento especificado.

```
virtual CDockSite* FindDockSite(
    DWORD dwAlignment,
    BOOL bOuter);
```

### <a name="parameters"></a>Parâmetros

*Dwalignment*<br/>
[em] O alinhamento do painel da barra.

*bOuter*<br/>
[em] Se TRUE, recupere a barra na posição principal na lista de barras de controle. Caso contrário, recupere a barra na posição da cauda na lista de barras de controle.

### <a name="return-value"></a>Valor retornado

O painel de acoplamento que tem o alinhamento especificado; NULL de outra forma.

## <a name="cdockingmanagerfindpanebyid"></a><a name="findpanebyid"></a>CDockingManager::FindPaneByID

Encontra um painel pelo ID de controle especificado.

```
virtual CBasePane* FindPaneByID(
    UINT uBarID,
    BOOL bSearchMiniFrames = FALSE);
```

### <a name="parameters"></a>Parâmetros

*uBarID*<br/>
[em] Especifica o ID de controle do painel para encontrar.

*bSearchMiniFrames*<br/>
[em] VERDADE para incluir todos os painéis flutuantes na busca. FALSO para incluir apenas os painéis ancorados.

### <a name="return-value"></a>Valor retornado

O objeto [CBasePane](../../mfc/reference/cbasepane-class.md) que tem o ID de controle especificado ou NULL se o painel especificado não puder ser encontrado.

### <a name="remarks"></a>Comentários

## <a name="cdockingmanagerfinddocksitebypane"></a><a name="finddocksitebypane"></a>CDockingManager::FindDockSiteByPane

Devolve o painel de barras que tem a id do painel da barra de destino.

```
virtual CDockSite* FindDockSiteByPane(CPane* pTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pTargetBar*<br/>
[em] Um ponteiro para o painel da barra alvo.

### <a name="return-value"></a>Valor retornado

O painel de barras que tem a id do painel da barra alvo; NULL se não existir tal painel de barras.

## <a name="cdockingmanagerfixupvirtualrects"></a><a name="fixupvirtualrects"></a>CDockingManager::FixupVirtualRects

Compromete todas as posições atuais da barra de ferramentas em retângulos virtuais.

```
virtual void FixupVirtualRects();
```

### <a name="remarks"></a>Comentários

Quando o usuário começa a arrastar uma barra de ferramentas, o aplicativo lembra sua posição original no *retângulo virtual*. Quando o usuário move uma barra de ferramentas através de seu site de doca, a barra de ferramentas pode mudar outras barras de ferramentas. As posições originais das outras barras de ferramentas são armazenadas nos retângulos virtuais correspondentes.

## <a name="cdockingmanagerframefrompoint"></a><a name="framefrompoint"></a>CDockingManager::FrameFromPoint

Retorna o quadro que contém o ponto dado.

```
virtual CPaneFrameWnd* FrameFromPoint(
    CPoint pt,
    CPaneFrameWnd* pFrameToExclude,
    BOOL bFloatMultiOnly) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
[em] Especifica o ponto, nas coordenadas da tela, para verificar.

*pFrameParaexcluir*<br/>
[em] Um ponteiro para um quadro para excluir.

*bFloatMultiOnly*<br/>
[em] VERDADEIRO para excluir quadros que `CMultiPaneFrameWnd`não são instâncias de; FALSO de outra forma.

### <a name="return-value"></a>Valor retornado

O quadro que contém o ponto dado; NULL de outra forma.

## <a name="cdockingmanagergetclientareabounds"></a><a name="getclientareabounds"></a>CDockingManager::GetClientAreaBounds

Obtém o retângulo que contém os limites da área do cliente.

```
CRect GetClientAreaBounds() const;

void GetClientAreaBounds(CRect& rcClient);
```

### <a name="parameters"></a>Parâmetros

*rcClient*<br/>
[fora] Uma referência ao retângulo que contém os limites da área do cliente.

### <a name="return-value"></a>Valor retornado

O retângulo que contém os limites da área do cliente.

## <a name="cdockingmanagergetdockingmode"></a><a name="getdockingmode"></a>CDockingManager::GetDockingMode

Retorna o modo de acoplamento atual.

```
static AFX_DOCK_TYPE GetDockingMode();
```

### <a name="return-value"></a>Valor retornado

Um valor enumerador que representa o modo de acoplamento atual. Pode ser um dos seguintes valores:

- DT_STANDARD

- DT_IMMEDIATE

- DT_SMART

### <a name="remarks"></a>Comentários

Para definir o modo de acoplamento, ligue para [CDockingManager::SetDockingMode](#setdockingmode).

## <a name="cdockingmanagergetdocksiteframewnd"></a><a name="getdocksiteframewnd"></a>CDockingManager::GetDockSiteFrameWnd

Recebe um ponteiro para a janela dos pais.

```
CFrameWnd* GetDockSiteFrameWnd() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela dos pais.

## <a name="cdockingmanagergetenabledautohidealignment"></a><a name="getenabledautohidealignment"></a>CDockingManager::GetEnabledAuto'HideAlignment

Retorna o alinhamento ativado dos painéis.

```
DWORD GetEnabledAutoHideAlignment() const;
```

### <a name="return-value"></a>Valor retornado

Uma combinação bitwise de bandeiras CBRS_ALIGN_ ou 0 se os painéis de couro automático não estiverem habilitados. Para obter mais informações, consulte [CFrameWnd::EnableDocking](../../mfc/reference/cframewnd-class.md#enabledocking).

### <a name="remarks"></a>Comentários

O método retorna o alinhamento ativado para barras de controle de ocultação automática. Para ativar barras de ocultação automática, ligue [para CFrameWndEx::EnableAutoHidePanes](../../mfc/reference/cframewndex-class.md#enableautohidepanes).

## <a name="cdockingmanagergetminiframes"></a><a name="getminiframes"></a>CDockingManager::GetMiniFrames

Recebe uma lista de miniquadros.

```
const CObList& GetMiniFrames() const;
```

### <a name="return-value"></a>Valor retornado

Uma lista de miniquadros que contêm as barras de controle que pertencem ao gerente de acoplamento.

## <a name="cdockingmanagergetouteredgebounds"></a><a name="getouteredgebounds"></a>CDockingManager::GetOuterEdgeBounds

Obtém um retângulo que contém as bordas externas do quadro.

```
CRect GetOuterEdgeBounds() const;
```

### <a name="return-value"></a>Valor retornado

Um retângulo que contém as bordas externas do quadro.

## <a name="cdockingmanagergetpanelist"></a><a name="getpanelist"></a>CDockingManager::GetPaneList

Retorna uma lista de painéis que pertencem ao gerente de acoplamento. Isso inclui todos os painéis flutuantes.

```cpp
void GetPaneList(
    CObList& lstBars,
    BOOL bIncludeAutohide = FALSE,
    CRuntimeClass* pRTCFilter = NULL,
    BOOL bIncludeTabs = FALSE);
```

### <a name="parameters"></a>Parâmetros

*LstBars*<br/>
[dentro, fora] Contém todos os painéis do atual gerente de acoplamento.

*bIncludeAutohide*<br/>
[em] VERDADEIRO para incluir os painéis que estão no modo de ocultação automática; caso contrário, FALSE.

*pRTCFilter*<br/>
[em] Se não FOR NULO, a lista retornada contém painéis apenas da classe de tempo de execução especificada.

*bIncludeTabs*<br/>
[em] VERDADEIRO para incluir guias; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se houver algum painel com guias no gerenciador de encaixe, o método retorna ponteiros para objetos [cbasetabbedPane class](../../mfc/reference/cbasetabbedpane-class.md) e você deve enumerar as guias explicitamente.

Use *pRTCFilter* para obter uma classe específica de painéis. Por exemplo, você só pode obter barras de ferramentas definindo esse valor apropriadamente.

## <a name="cdockingmanagergetsmartdockingmanager"></a><a name="getsmartdockingmanager"></a>CDockingManager::GetSmartDockingManager

Recupera um ponteiro para o gerenciador de acoplamento inteligente.

```
CSmartDockingManager* GetSmartDockingManager();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o gerente de acoplamento inteligente.

## <a name="cdockingmanagergetsmartdockingmanagerpermanent"></a><a name="getsmartdockingmanagerpermanent"></a>CDockingManager::GetSmartDockingManagerPermanent

Recupera um ponteiro para o gerenciador de acoplamento inteligente.

```
CSmartDockingManager* GetSmartDockingManagerPermanent() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o gerente de acoplamento inteligente.

## <a name="cdockingmanagergetsmartdockingparams"></a><a name="getsmartdockingparams"></a>CDockingManager::GetSmartDockingParams

Retorna os parâmetros de acoplamento inteligente satisumido para o gerenciador de acoplamento.

```
static CSmartDockingInfo& GetSmartDockingParams();
```

### <a name="return-value"></a>Valor retornado

A classe que contém os parâmetros de acoplamento inteligentes para o atual gerenciador de acoplamento. Para obter mais informações, consulte [CSmartDockingInfo Class](../../mfc/reference/csmartdockinginfo-class.md).

### <a name="remarks"></a>Comentários

## <a name="cdockingmanagerhideautohidepanes"></a><a name="hideautohidepanes"></a>CDockingManager::HideAutoHidePanes

Esconde um painel que está no modo de ocultação automática.

```cpp
void HideAutoHidePanes(
    CDockablePane* pBarToExclude = NULL,
    BOOL bImmediately = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pBarToExcluir*<br/>
[em] Um ponteiro para um bar para excluir de se esconder.

*bImediatamente*<br/>
[em] VERDADE para esconder o painel imediatamente; FALSE para esconder o painel com o efeito autohide.

## <a name="cdockingmanagerinsertdocksite"></a><a name="insertdocksite"></a>CDockingManager::InsertDockSite

Cria um painel de doca e insere-o na lista de barras de controle.

```
BOOL InsertDockSite(
    const AFX_DOCKSITE_INFO& info,
    DWORD dwAlignToInsertAfter,
    CDockSite** ppDockBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*Informação*<br/>
[em] Uma estrutura que contém as informações de alinhamento sobre o painel das docas.

*dwAlignToInsertAfter*<br/>
[em] Alinhamento do painel de doca.

*ppDockBar*<br/>
[fora] Um ponteiro para um ponteiro para um painel de doca.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel de doca foi criado com sucesso; FALSO de outra forma.

## <a name="cdockingmanagerinsertpane"></a><a name="insertpane"></a>CDockingManager::InsertPane

Insere um painel de controle na lista de barras de controle.

```
BOOL InsertPane(
    CBasePane* pControlBar,
    CBasePane* pTarget,
    BOOL bAfter = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pcontrolbar*<br/>
[em] Um ponteiro para um painel de controle.

*Ptarget*<br/>
[em] Um ponteiro para um painel de alvo.

*bDepois*<br/>
[em] FIEL para inserir o painel após a posição do painel de destino; FALSO de outra forma.

### <a name="return-value"></a>Valor retornado

TRUE se o painel de controle for adicionado com sucesso à lista de barras de controle; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Este método retorna falso se o painel de controle já estiver na lista de barras de controle ou se o painel de destino não existir na lista de barras de controle.

## <a name="cdockingmanagerisdocksitemenu"></a><a name="isdocksitemenu"></a>CDockingManager::IsDockSiteMenu

Especifica se um menu pop-up é exibido nas legendas de todos os painéis.

```
static BOOL IsDockSiteMenu();
```

### <a name="return-value"></a>Valor retornado

TRUE se um menu do site de doca for exibido nas legendas de todos os painéis de encaixe; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Você pode ativar o menu do site do dock chamando [CDockingManager::EnableDockSiteMenu](#enabledocksitemenu).

## <a name="cdockingmanagerisinadjustlayout"></a><a name="isinadjustlayout"></a>CDockingManager::IsInAdjustLayout

Determina se os layouts de todos os painéis estão ajustados.

```
BOOL IsInAdjustLayout() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se os layouts de todos os painéis forem ajustados; FALSO de outra forma.

## <a name="cdockingmanagerisolecontainermode"></a><a name="isolecontainermode"></a>CDockingManager::IsOLEContainerMode

Especifica se o gerenciador de encaixe está no modo de contêiner OLE.

```
BOOL IsOLEContainerMode() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se o gerenciador de encaixe estiver no modo de contêiner OLE; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

No modo de contêiner OLE, todos os painéis de encaixe e barras de ferramentas de aplicação estão escondidos. Os painéis também estão escondidos neste modo se você tiver definido [CDockingManager::m_bHideDockingBarsInContainerMode](#m_bhidedockingbarsincontainermode) para TRUE.

## <a name="cdockingmanagerispointneardocksite"></a><a name="ispointneardocksite"></a>CDockingManager::IsPointNearDockSite

Determina se um ponto especificado está perto do local das docas.

```
BOOL IsPointNearDockSite(
    CPoint point,
    DWORD& dwBarAlignment,
    BOOL& bOuterEdge) const;
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] O ponto especificado.

*dwBarAlignment*<br/>
[fora] Especifica qual borda o ponto está próximo. Os valores possíveis são CBRS_ALIGN_LEFT, CBRS_ALIGN_RIGHT, CBRS_ALIGN_TOP e CBRS_ALIGN_BOTTOM.

*bOuterEdge*<br/>
[fora] VERDADE se o ponto estiver perto da borda externa do local das docas; FALSO de outra forma.

### <a name="return-value"></a>Valor retornado

VERDADE se o ponto estiver perto do local das docas; caso contrário, FALSO.

## <a name="cdockingmanagerisprintpreviewvalid"></a><a name="isprintpreviewvalid"></a>CDockingManager::IsPrintPreviewValid

Determina se o modo de visualização de impressão está definido.

```
BOOL IsPrintPreviewValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o modo de visualização de impressão estiver definido; FALSO de outra forma.

## <a name="cdockingmanagerloadstate"></a><a name="loadstate"></a>CDockingManager::LoadState

Carrega o estado do gerente de acoplamento do registro.

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Nome do perfil.

*Uiid*<br/>
[em] A id do gerente de acoplamento.

### <a name="return-value"></a>Valor retornado

VERDADE se o estado do gerente de acoplamento foi carregado com sucesso; caso contrário, FALSO.

## <a name="cdockingmanagerlockupdate"></a><a name="lockupdate"></a>CDockingManager::LockUpdate

Bloqueia a janela dada.

```cpp
void LockUpdate(BOOL bLock);
```

### <a name="parameters"></a>Parâmetros

*Bloco*<br/>
[em] VERDADE se a janela estiver bloqueada; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Quando uma janela está bloqueada, ela não pode ser movida e não pode ser redesenhada.

## <a name="cdockingmanagerm_bhidedockingbarsincontainermode"></a><a name="m_bhidedockingbarsincontainermode"></a>CDockingManager::m_bHideDockingBarsInContainerMode

Especifica se o gerenciador de encaixe esconde painéis no modo de contêiner OLE.

```
AFX_IMPORT_DATA static BOOL m_bHideDockingBarsInContainerMode;
```

### <a name="remarks"></a>Comentários

Defina esse valor como FALSO se quiser manter todos os painéis ancorados no quadro principal visíveis quando a aplicação estiver no modo de contêiner OLE. Por padrão, este valor é TRUE.

## <a name="cdockingmanagerm_dockmodeglobal"></a><a name="m_dockmodeglobal"></a>CDockingManager::m_dockModeGlobal

Especifica o modo de acoplamento global.

```
AFX_IMPORT_DATA static AFX_DOCK_TYPE m_dockModeGlobal;
```

### <a name="remarks"></a>Comentários

Por padrão, cada painel de encaixe usa este modo de acoplamento. Para obter mais informações sobre os valores para os quais este campo pode ser definido, consulte [CBasePane::GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).

## <a name="cdockingmanagerm_ndocksensitivity"></a><a name="m_ndocksensitivity"></a>CDockingManager::m_nDockSensitivity

Especifica a sensibilidade de acoplamento.

```
AFX_IMPORT_DATA static int m_nDockSensitivity;
```

### <a name="remarks"></a>Comentários

A sensibilidade de acoplamento define o quão perto um painel flutuante pode se aproximar de um painel de acoplamento, local de acoplamento ou outro painel antes que a estrutura mude seu estado para ancorada.

## <a name="cdockingmanagerm_ntimeoutbeforedockingbardock"></a><a name="m_ntimeoutbeforedockingbardock"></a>CDockingManager::m_nTimeOutBeforeDockingBarDock

Especifica a hora, em milissegundos, antes que um painel de acoplamento seja encaixado no modo de acoplamento imediato.

```
static UINT m_nTimeOutBeforeDockingBarDock;
```

### <a name="remarks"></a>Comentários

Antes de um painel ser ancorado, a estrutura aguarda o período de tempo especificado. Isso evita que o painel seja acidentalmente ancorado em um local enquanto o usuário ainda o está arrastando.

## <a name="cdockingmanagerm_ntimeoutbeforetoolbardock"></a><a name="m_ntimeoutbeforetoolbardock"></a>CDockingManager::m_nTimeOutBeforeToolBarDock

Especifica a hora, em milissegundos, antes que uma barra de ferramentas seja encaixada na janela principal do quadro.

```
static UINT m_nTimeOutBeforeToolBarDock;
```

### <a name="remarks"></a>Comentários

Antes de uma barra de ferramentas ser encaixada, a estrutura aguarda o período de tempo especificado. Isso evita que a barra de ferramentas seja acidentalmente encaixada em um local enquanto o usuário ainda a arrasta.

## <a name="cdockingmanageronactivateframe"></a><a name="onactivateframe"></a>CDockingManager::OnActivateFrame

Chamado pela estrutura quando a janela do quadro é ativa ou é desativada.

```
virtual void OnActivateFrame(BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[em] Se TRUE, a janela do quadro é ativa; se FALSE, a janela do quadro é desativada.

## <a name="cdockingmanageronclosepopupmenu"></a><a name="onclosepopupmenu"></a>CDockingManager::OnClosePopupMenu

Chamado pelo framework quando um menu pop-up ativo processa uma mensagem WM_DESTROY.

```cpp
void OnClosePopupMenu();
```

### <a name="remarks"></a>Comentários

O framework envia uma mensagem WM_DESTROY quando está prestes a fechar a janela principal atual. Substituir este método para `CMFCPopupMenu` lidar com notificações de `CMFCPopupMenu` objetos que pertencem à janela do quadro quando um objeto processa uma mensagem WM_DESTROY.

## <a name="cdockingmanageronmoveminiframe"></a><a name="onmoveminiframe"></a>CDockingManager::OnMoveMiniFrame

Chamado pela estrutura para mover uma janela de mini-quadro.

```
virtual BOOL OnMoveMiniFrame(CWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
[em] Um ponteiro para uma janela de mini-quadro.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSO.

## <a name="cdockingmanageronpanecontextmenu"></a><a name="onpanecontextmenu"></a>CDockingManager::OnPaneContextMenu

Chamado pela estrutura quando constrói um menu que tem uma lista de painéis.

```cpp
void OnPaneContextMenu(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] Especifica a localização do menu.

## <a name="cdockingmanagerpanefrompoint"></a><a name="panefrompoint"></a>CDockingManager::PaneFromPoint

Devolve o painel que contém o ponto dado.

```
virtual CBasePane* PaneFromPoint(
    CPoint point,
    int nSensitivity,
    bool bExactBar = false,
    CRuntimeClass* pRTCBarType = NULL,
    BOOL bCheckVisibility = FALSE,
    const CBasePane* pBarToIgnore = NULL) const;

virtual CBasePane* PaneFromPoint(
    CPoint point,
    int nSensitivity,
    DWORD& dwAlignment,
    CRuntimeClass* pRTCBarType = NULL,
    const CBasePane* pBarToIgnore = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] Especifica o ponto, nas coordenadas da tela, para verificar.

*nSensibilidade*<br/>
[em] O valor para inflar o retângulo da janela de cada painel verificado. Um painel satisfaz os critérios de busca se o ponto dado estiver nesta região inflada.

*bExactBar*<br/>
[em] VERDADEIRO ignorar o parâmetro *nSensitivity;* caso contrário, FALSE.

*pRTCBarType*<br/>
[em] Se não FOR NULO, o método pesquisa apenas os painéis do tipo especificado.

*bCheckVisibility*<br/>
[em] TRUE para verificar apenas painéis visíveis; caso contrário, FALSE.

*Dwalignment*<br/>
[fora] Se um painel for encontrado no ponto especificado, este parâmetro contém o lado do painel mais próximo do ponto especificado. Para obter mais informações, consulte a seção Comentários.

*pBarToIgnore*<br/>
[em] Se não for NULO, o método ignora os painéis especificados por este parâmetro.

### <a name="return-value"></a>Valor retornado

O objeto derivado do [CBasePane](../../mfc/reference/cbasepane-class.md)que contém o ponto dado ou NULL se nenhum painel foi encontrado.

### <a name="remarks"></a>Comentários

Quando a função retorna e um painel foi encontrado, *dwAlignment* contém o alinhamento do ponto especificado. Por exemplo, se o ponto estiver mais próximo do topo do painel, *dwAlignment* está definido para CBRS_ALIGN_TOP.

## <a name="cdockingmanagerprocesspanecontextmenucommand"></a><a name="processpanecontextmenucommand"></a>CDockingManager::ProcessPaneContextMenuCommandCommand

Chamado pela estrutura para selecionar ou limpar uma caixa de seleção para o comando especificado e recalcular o layout de um painel mostrado.

```
BOOL ProcessPaneContextMenuCommand(
    UINT nID,
    int nCode,
    void* pExtra,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] A id de uma barra de controle no menu.

*Ncode*<br/>
[em] O código de notificação de comando.

*Pextra*<br/>
[em] Um ponteiro para anular que é `CCmdUI` lançado a um ponteiro para se *nCode* for CN_UPDATE_COMMAND_UI.

*pHandlerInfo*<br/>
[em] Um ponteiro para uma estrutura de informações. Este parâmetro não é usado.

### <a name="return-value"></a>Valor retornado

TRUE se *pEXtra* não for NULL e *nCode* for igual a CN_UPDATE_COMMAND_UI, ou se houver uma barra de controle com o *nID*especificado .

## <a name="cdockingmanagerrecalclayout"></a><a name="recalclayout"></a>CDockingManager::RecalcLayout

Recalcula o layout interno dos controles presentes na lista de controles.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bNotificar*<br/>
[em] Este parâmetro não é usado.

## <a name="cdockingmanagerreleaseemptypanecontainers"></a><a name="releaseemptypanecontainers"></a>CDockingManager::ReleaseEmptyPaneContainers

Libera os recipientes vazios do painel.

```cpp
void ReleaseEmptyPaneContainers();
```

## <a name="cdockingmanagerremovehiddenmditabbedbar"></a><a name="removehiddenmditabbedbar"></a>CDockingManager::RemoveHiddenMDI'T'Cotode

Remove o painel de barra escondido especificado.

```cpp
void RemoveHiddenMDITabbedBar(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para um painel de barras para remover.

## <a name="cdockingmanagerremoveminiframe"></a><a name="removeminiframe"></a>CDockingManager::RemoveMiniFrame

Remove um quadro especificado da lista de mini quadros.

```
virtual BOOL RemoveMiniFrame(CPaneFrameWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Um ponteiro para um quadro para remover.

### <a name="return-value"></a>Valor retornado

TRUE se o quadro especificado for removido; FALSO de outra forma.

## <a name="cdockingmanagerremovepanefromdockmanager"></a><a name="removepanefromdockmanager"></a>CDockingManager::RemovePaneFromDockManager

Desregistra um painel e remove-o da lista no gerenciador de acoplamento.

```cpp
void RemovePaneFromDockManager(
    CBasePane* pWnd,
    BOOL bDestroy,
    BOOL bAdjustLayout,
    BOOL bAutoHide = FALSE,
    CBasePane* pBarReplacement = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Um ponteiro para um painel a ser removido.

*bDestruir*<br/>
[em] Se VERDADE, o painel removido é destruído.

*bAdjustLayout*<br/>
[em] Se TRUE, ajuste o layout de acoplamento imediatamente.

*bAutoHide*<br/>
[em] Se TRUE, o painel é removido da lista de barras de ocultação automática. Se FALSO, o painel é removido da lista de painéis regulares.

*pBarReplacement*<br/>
[em] Um ponteiro para um painel que substitui o painel removido.

## <a name="cdockingmanagerreplacepane"></a><a name="replacepane"></a>CDockingManager::ReplacePane

Substitui um painel por outro.

```
BOOL ReplacePane(
    CDockablePane* pOriginalBar,
    CDockablePane* pNewBar);
```

### <a name="parameters"></a>Parâmetros

*pOriginalBar*<br/>
[em] Um ponteiro para o painel original.

*Pnewbar*<br/>
[em] Um ponteiro para o painel que substitui o painel original.

### <a name="return-value"></a>Valor retornado

VERDADE se o painel for substituído com sucesso; FALSO de outra forma.

## <a name="cdockingmanagerresortminiframesforzorder"></a><a name="resortminiframesforzorder"></a>CDockingManager::ResortMiniFramesForZOrder

Recorre os quadros na lista de mini quadros.

```cpp
void ResortMiniFramesForZOrder();
```

## <a name="cdockingmanagersavestate"></a><a name="savestate"></a>CDockingManager::SaveState

Salva o estado do gerente de acoplamento para o registro.

```
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] Um caminho para uma chave de registro.

*Uiid*<br/>
[em] A porta de ida do gerente de acoplamento.

### <a name="return-value"></a>Valor retornado

VERDADE se o estado foi salvo com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Salvar o estado do gerente de acoplamento para o registro envolve salvar os estados das barras de controle, os estados das barras de auto-ocultamento e os estados dos mini quadros presentes no gerente de acoplamento.

## <a name="cdockingmanagersendmessagetominiframes"></a><a name="sendmessagetominiframes"></a>CDockingManager::SendMessageToMiniFrames

Envia a mensagem especificada para todos os mini quadros.

```
BOOL SendMessageToMiniFrames(
    UINT uMessage,
    WPARAM wParam = 0,
    LPARAM lParam = 0);
```

### <a name="parameters"></a>Parâmetros

*uMessage*<br/>
[em] A mensagem a ser enviada.

*wParam*<br/>
[em] Informações adicionais dependentes de mensagens.

*lParam*<br/>
[em] Informações adicionais dependentes de mensagens.

### <a name="return-value"></a>Valor retornado

VERDADE sempre.

## <a name="cdockingmanagerserialize"></a><a name="serialize"></a>CDockingManager::Serialize

Escreve o gerente de ancoragem para um arquivo.

```cpp
void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
[em] Uma referência a um objeto de arquivo.

### <a name="remarks"></a>Comentários

Escrever o gerenciador de encaixe em um arquivo envolve determinar o número de barras de controle de encaixe e controles deslizantes, e escrever as barras de controle, os mini quadros, as barras de autoocultação e as barras de mDI para o arquivo.

## <a name="cdockingmanagersetautohidezorder"></a><a name="setautohidezorder"></a>CDockingManager::SetAutohideZOrder

Define o tamanho, largura e altura das barras de controle e do painel especificado.

```cpp
void SetAutohideZOrder(CDockablePane* pAHDockingBar);
```

### <a name="parameters"></a>Parâmetros

*pAHDockingBar*<br/>
[em] Um ponteiro para um painel dockable.

## <a name="cdockingmanagersetdockingmode"></a><a name="setdockingmode"></a>CDockingManager::SetDockingMode

Define o modo de acoplamento.

```
static void SetDockingMode(
    AFX_DOCK_TYPE dockMode,
    AFX_SMARTDOCK_THEME theme = AFX_SDT_DEFAULT);
```

### <a name="parameters"></a>Parâmetros

*dockMode*<br/>
Especifica o novo modo de acoplamento. Para obter mais informações, consulte a seção Comentários.

*Tema*<br/>
Especifica o tema a ser usado para marcadores de encaixe inteligentes. Pode ser um dos seguintes valores enumerados: AFX_SDT_DEFAULT, AFX_SDT_VS2005, AFX_SDT_VS2008.

### <a name="remarks"></a>Comentários

Chame este método estático para definir o modo de acoplamento.

*dockMode* pode ser um dos seguintes valores:

- DT_STANDARD - Modo de acoplamento padrão implementado no Visual Studio .NET 2003. Painéis são arrastados sem um contexto de arrasto.

- DT_IMMEDIATE - Modo de acoplamento imediato conforme implementado no Microsoft Visio. Os painéis são arrastados com um contexto de arrasto, mas nenhum marcador é exibido.

- DT_SMART - Modo de acoplamento inteligente implementado no Visual Studio 2005. Os painéis são arrastados com um contexto de arrasto e marcadores inteligentes são exibidos que mostram onde o painel pode ser encaixado.

## <a name="cdockingmanagersetdockstate"></a><a name="setdockstate"></a>CDockingManager::SetDockState

Define o estado de acoplamento das barras de controle, dos mini quadros e das barras de auto-ocultamento.

```
virtual void SetDockState();
```

## <a name="cdockingmanagersetprintpreviewmode"></a><a name="setprintpreviewmode"></a>CDockingManager::SetPrintPreviewMode

Define o modo de visualização de impressão das barras exibidas na visualização de impressão.

```cpp
void SetPrintPreviewMode(
    BOOL bPreview,
    CPrintPreviewState* pState);
```

### <a name="parameters"></a>Parâmetros

*bPreview*<br/>
[em] TRUE se o modo de visualização de impressão estiver definido; FALSO de outra forma.

*Pstate*<br/>
[em] Um ponteiro para um estado de visualização. Este parâmetro não é usado.

## <a name="cdockingmanagersetsmartdockingparams"></a><a name="setsmartdockingparams"></a>CDockingManager::SetSmartDockingParams

Define os parâmetros que definem o comportamento do encaixe inteligente.

```
static void SetSmartDockingParams(CSmartDockingInfo& params);
```

### <a name="parameters"></a>Parâmetros

*params*<br/>
[dentro, fora] Define os parâmetros para acoplamento inteligente.

### <a name="remarks"></a>Comentários

Chame este método se quiser personalizar a aparência, a cor ou a forma dos marcadores de encaixe inteligentes.

Para usar a aparência padrão de marcadores de encaixe inteligentes, passe uma instância não inicializada da [CSmartDockingInfo Class](../../mfc/reference/csmartdockinginfo-class.md) para *params*.

## <a name="cdockingmanagershowdelayshowminiframes"></a><a name="showdelayshowminiframes"></a>CDockingManager::ShowDelayShowMiniFrames

Mostra ou esconde as janelas dos mini quadros.

```cpp
void ShowDelayShowMiniFrames(BOOL bshow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] TRUE para tornar ativa a janela do quadro mostrado; FALSO para esconder a janela da moldura.

## <a name="cdockingmanagershowpanes"></a><a name="showpanes"></a>CDockingManager::ShowPanes

Mostra ou esconde os painéis do controle e das barras de auto-ocultação.

```
virtual BOOL ShowPanes(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] VERDADE para mostrar os painéis; FALSO para esconder os painéis.

### <a name="return-value"></a>Valor retornado

Sempre FALSE.

## <a name="cdockingmanagerstartsdocking"></a><a name="startsdocking"></a>CDockingManager::StartSDocking

Inicia o acoplamento inteligente da janela especificada de acordo com o alinhamento do gerenciador de acoplamento inteligente.

```cpp
void StartSDocking(CWnd* pDockingWnd);
```

### <a name="parameters"></a>Parâmetros

*pDockingWnd*<br/>
[em] Um ponteiro para uma janela para atracar.

## <a name="cdockingmanagerstopsdocking"></a><a name="stopsdocking"></a>CDockingManager::StopSDocking

Impede o acoplamento inteligente.

```cpp
void StopSDocking();
```

## <a name="cdockingmanagergetsmartdockingtheme"></a><a name="getsmartdockingtheme"></a>CDockingManager::GetSmartDockingTheme

Um método estático que retorna um tema usado para exibir marcadores de encaixe inteligentes.

```
static AFX_SMARTDOCK_THEME __stdcall GetSmartDockingTheme();
```

### <a name="return-value"></a>Valor retornado

Retorna um dos seguintes valores enumerados: AFX_SDT_DEFAULT, AFX_SDT_VS2005, AFX_SDT_VS2008.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Classe CFrameWndEx](../../mfc/reference/cframewndex-class.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)<br/>
[Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)
