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
ms.openlocfilehash: 8709b3a4eb3f57a3d2700ad7aaed16df994245c5
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78883911"
---
# <a name="cdockingmanager-class"></a>Classe CDockingManager

Implementa a funcionalidade básica que controla o layout de encaixe em uma janela de quadro principal.

## <a name="syntax"></a>Sintaxe

```
class CDockingManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDockingManager::AddDockSite](#adddocksite)|Cria um painel de encaixe e o adiciona à lista de barras de controle.|
|[CDockingManager::AddHiddenMDITabbedBar](#addhiddenmditabbedbar)|Adiciona um identificador a um painel de barras à lista de painéis de barras com guias MDI ocultos.|
|[CDockingManager::AddMiniFrame](#addminiframe)|Adiciona um quadro à lista de mini quadros.|
|[CDockingManager:: AddPane](#addpane)|Registra um painel com o Gerenciador de encaixe.|
|[CDockingManager::AdjustDockingLayout](#adjustdockinglayout)|Recalcula e ajusta o layout de todos os painéis em uma janela do quadro.|
|[CDockingManager::AdjustPaneFrames](#adjustpaneframes)|Faz com que a mensagem de WM_NCCALCSIZE seja enviada a todos os painéis e `CPaneFrameWnd` janelas.|
|[CDockingManager::AdjustRectToClientArea](#adjustrecttoclientarea)|Ajusta o alinhamento de um retângulo.|
|[CDockingManager::AlignAutoHidePane](#alignautohidepane)|Redimensiona um painel de encaixe no modo de AutoOcultar para que ele ocupe a largura completa ou a altura da área do cliente do quadro envolvida por sites de encaixe.|
|[CDockingManager::AutoHidePane](#autohidepane)|Cria uma barra de ferramentas de AutoOcultar.|
|[CDockingManager::BringBarsToTop](#bringbarstotop)|Coloca as barras encaixadas que têm o alinhamento especificado na parte superior.|
|[CDockingManager::BuildPanesMenu](#buildpanesmenu)|Adiciona nomes de painéis de encaixe e barras de ferramentas a um menu.|
|[CDockingManager::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcula o retângulo esperado de uma janela encaixada.|
|[CDockingManager:: criar](#create)|Cria um Gerenciador de encaixe.|
|[CDockingManager::D eterminePaneAndStatus](#determinepaneandstatus)|Determina o painel que contém um determinado ponto e seu status de encaixe.|
|[CDockingManager::D isableRestoreDockState](#disablerestoredockstate)|Habilita ou desabilita o carregamento do layout de encaixe do registro.|
|[CDockingManager::D ockPane](#dockpane)|Encaixa um painel em outro painel ou em uma janela do quadro.|
|[CDockingManager::D ockPaneLeftOf](#dockpaneleftof)|Encaixa um painel à esquerda de outro painel.|
|[CDockingManager::EnableAutoHidePanes](#enableautohidepanes)|Habilita o encaixe do painel no quadro principal, cria um painel de encaixe e o adiciona à lista de barras de controle.|
|[CDockingManager::EnableDocking](#enabledocking)|Cria um painel de encaixe e habilita o encaixe do painel no quadro principal.|
|[CDockingManager::EnableDockSiteMenu](#enabledocksitemenu)|Exibe um botão adicional que abre um menu pop-up nas legendas de todos os painéis de encaixe.|
|[CDockingManager::EnablePaneContextMenu](#enablepanecontextmenu)|Informa à biblioteca para exibir um menu de contexto especial que tem uma lista de barras de ferramentas do aplicativo e painéis de encaixe quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem de WM_CONTEXTMENU.|
|[CDockingManager::FindDockSite](#finddocksite)|Recupera o painel de barras que está na posição especificada e que tem o alinhamento especificado.|
|[CDockingManager::FindDockSiteByPane](#finddocksitebypane)|Retorna o painel de barras que tem a ID do painel da barra de destino.|
|[CDockingManager::FindPaneByID](#findpanebyid)|Localiza um painel pela ID de controle especificada.|
|[CDockingManager::FixupVirtualRects](#fixupvirtualrects)|Confirma todas as posições da barra de ferramentas atual para retângulos virtuais.|
|[CDockingManager::FrameFromPoint](#framefrompoint)|Retorna o quadro que contém o ponto determinado.|
|[CDockingManager::GetClientAreaBounds](#getclientareabounds)|Obtém o retângulo que contém os limites da área do cliente.|
|[CDockingManager::GetDockingMode](#getdockingmode)|Retorna o modo de encaixe atual.|
|[CDockingManager::GetDockSiteFrameWnd](#getdocksiteframewnd)|Obtém um ponteiro para o quadro da janela pai.|
|[CDockingManager::GetEnabledAutoHideAlignment](#getenabledautohidealignment)|Retorna o alinhamento habilitado dos painéis.|
|[CDockingManager::GetMiniFrames](#getminiframes)|Obtém uma lista de miniframes.|
|[CDockingManager::GetOuterEdgeBounds](#getouteredgebounds)|Obtém um retângulo que contém as bordas externas do quadro.|
|[CDockingManager:: getpanelista](#getpanelist)|Retorna uma lista de painéis que pertencem ao Gerenciador de encaixe. Isso inclui todos os painéis flutuantes.|
|[CDockingManager::GetSmartDockingManager](#getsmartdockingmanager)|Recupera um ponteiro para o Gerenciador de encaixe inteligente.|
|[CDockingManager::GetSmartDockingManagerPermanent](#getsmartdockingmanagerpermanent)|Recupera um ponteiro para o Gerenciador de encaixe inteligente.|
|[CDockingManager::GetSmartDockingParams](#getsmartdockingparams)|Retorna os parâmetros de encaixe inteligente para o Gerenciador de encaixe.|
|[CDockingManager::GetSmartDockingTheme](#getsmartdockingtheme)|Um método estático que retorna um tema usado para exibir marcadores de encaixe inteligente.|
|[CDockingManager::HideAutoHidePanes](#hideautohidepanes)|Oculta um painel que está no modo de AutoOcultar.|
|[CDockingManager::InsertDockSite](#insertdocksite)|Cria um painel de encaixe e o insere na lista de barras de controle.|
|[CDockingManager::InsertPane](#insertpane)|Insere um painel de controle na lista de barras de controle.|
|[CDockingManager::IsDockSiteMenu](#isdocksitemenu)|Especifica se um menu pop-up é exibido nas legendas de todos os painéis.|
|[CDockingManager::IsInAdjustLayout](#isinadjustlayout)|Determina se os layouts de todos os painéis são ajustados.|
|[CDockingManager::IsOLEContainerMode](#isolecontainermode)|Especifica se o Gerenciador de encaixe está no modo de contêiner OLE.|
|[CDockingManager::IsPointNearDockSite](#ispointneardocksite)|Determina se um ponto especificado está próximo ao site de encaixe.|
|[CDockingManager::IsPrintPreviewValid](#isprintpreviewvalid)|Determina se o modo de visualização de impressão está definido.|
|[CDockingManager:: LoadState](#loadstate)|Carrega o estado do Gerenciador de encaixe do registro.|
|[CDockingManager::LockUpdate](#lockupdate)|Bloqueia a janela especificada.|
|[CDockingManager::OnActivateFrame](#onactivateframe)|Chamado pelo Framework quando a janela do quadro é ativada ou desativada.|
|[CDockingManager::OnClosePopupMenu](#onclosepopupmenu)|Chamado pelo Framework quando um menu pop-up ativo processa uma mensagem de WM_DESTROY.|
|[CDockingManager::OnMoveMiniFrame](#onmoveminiframe)|Chamado pelo Framework para mover uma janela de mini-quadro.|
|[CDockingManager::OnPaneContextMenu](#onpanecontextmenu)|Chamado pelo Framework quando ele cria um menu que tem uma lista de painéis.|
|[CDockingManager::P aneFromPoint](#panefrompoint)|Retorna o painel que contém o ponto determinado.|
|[CDockingManager::P rocessPaneContextMenuCommand](#processpanecontextmenucommand)|Chamado pelo Framework para marcar ou desmarcar uma caixa de seleção para o comando especificado e recalcular o layout de um painel mostrado.|
|[CDockingManager::RecalcLayout](#recalclayout)|Recalcula o layout interno dos controles presentes na lista de controles.|
|[CDockingManager::ReleaseEmptyPaneContainers](#releaseemptypanecontainers)|Libera os contêineres de painel vazios.|
|[CDockingManager::RemoveHiddenMDITabbedBar](#removehiddenmditabbedbar)|Remove o painel de barras ocultos especificado.|
|[CDockingManager::RemoveMiniFrame](#removeminiframe)|Remove um quadro especificado da lista de mini quadros.|
|[CDockingManager::RemovePaneFromDockManager](#removepanefromdockmanager)|Cancela o registro de um painel e o Remove da lista no Gerenciador de encaixe.|
|[CDockingManager::ReplacePane](#replacepane)|Substitui um painel por outro.|
|[CDockingManager::ResortMiniFramesForZOrder](#resortminiframesforzorder)|Resort os quadros na lista de mini quadros.|
|[CDockingManager:: SaveState](#savestate)|Salva o estado do Gerenciador de encaixe no registro.|
|[CDockingManager::SendMessageToMiniFrames](#sendmessagetominiframes)|Envia a mensagem especificada para todos os mini quadros.|
|[CDockingManager:: Serialize](#serialize)|Grava o Gerenciador de encaixe em um arquivo morto. (Substitui [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize).)|
|[CDockingManager::SetAutohideZOrder](#setautohidezorder)|Define o tamanho, a largura e a altura das barras de controle e o painel especificado.|
|[CDockingManager::SetDockingMode](#setdockingmode)|Define o modo de encaixe.|
|[CDockingManager:: SetDockState](#setdockstate)|Define o estado de encaixe das barras de controle, os mini quadros e as barras de AutoOcultar.|
|[CDockingManager::SetPrintPreviewMode](#setprintpreviewmode)|Define o modo de visualização de impressão das barras exibidas na visualização de impressão.|
|[CDockingManager::SetSmartDockingParams](#setsmartdockingparams)|Define os parâmetros que definem o comportamento do encaixe inteligente.|
|[CDockingManager::ShowDelayShowMiniFrames](#showdelayshowminiframes)|Mostra ou oculta as janelas dos mini quadros.|
|[CDockingManager:: os painéis](#showpanes)|Mostra ou oculta os painéis do controle e as barras de AutoOcultar.|
|[CDockingManager::StartSDocking](#startsdocking)|Inicia o encaixe inteligente da janela especificada de acordo com o alinhamento do Gerenciador de encaixe inteligente.|
|[CDockingManager::StopSDocking](#stopsdocking)|Para o encaixe inteligente.|

### <a name="data-members"></a>Membros de Dados

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDockingManager:: m_bHideDockingBarsInContainerMode](#m_bhidedockingbarsincontainermode)|Especifica se o Gerenciador de encaixe oculta painéis no modo de contêiner OLE.|
|[CDockingManager:: m_dockModeGlobal](#m_dockmodeglobal)|Especifica o modo de encaixe global.|
|[CDockingManager:: m_nDockSensitivity](#m_ndocksensitivity)|Especifica a sensibilidade de encaixe.|
|[CDockingManager:: m_nTimeOutBeforeDockingBarDock](#m_ntimeoutbeforedockingbardock)|Especifica o tempo, em milissegundos, antes que um painel de encaixe seja encaixado no modo de encaixe imediato.|
|[CDockingManager:: m_nTimeOutBeforeToolBarDock](#m_ntimeoutbeforetoolbardock)|Especifica o tempo, em milissegundos, antes que uma barra de ferramentas seja encaixada na janela do quadro principal.|

## <a name="remarks"></a>Comentários

A janela do quadro principal cria e inicializa essa classe automaticamente.

O objeto do Gerenciador de encaixe contém uma lista de todos os painéis que estão no layout de encaixe e também uma lista de todas as janelas [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) que pertencem à janela do quadro principal.

A classe `CDockingManager` implementa alguns serviços que você pode usar para localizar um painel ou uma janela de `CPaneFrameWnd`. Normalmente, você não chama esses serviços diretamente porque eles são encapsulados no objeto de janela do quadro principal. Para obter mais informações, consulte [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).

## <a name="customization-tips"></a>Dicas de personalização

As dicas a seguir se aplicam a objetos `CDockingManager`:

- A [classe CDockingManager](../../mfc/reference/cdockingmanager-class.md) dá suporte a esses modos de encaixe:

  - `AFX_DOCK_TYPE::DT_IMMEDIATE`

  - `AFX_DOCK_TYPE::DT_STANDARD`

  - `AFX_DOCK_TYPE::DT_SMART`

  Esses modos de encaixe são definidos por [CDockingManager:: m_dockModeGlobal](#m_dockmodeglobal) e são definidos chamando [CDockingManager:: SetDockingMode](#setdockingmode).

- Se você quiser criar um painel não flutuante e não redimensionável, chame o método [CDockingManager:: AddPane](#addpane) . Esse método registra o painel com o Gerenciador de encaixe, que é responsável pelo layout do painel.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra como usar vários métodos na classe `CDockingManager` para configurar um objeto `CDockingManager`. O exemplo mostra como exibir um botão adicional que abre um menu pop-up nas legendas de todos os painéis de encaixe e como definir o modo de encaixe do objeto. Este trecho de código faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#24](../../mfc/codesnippet/cpp/cdockingmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDockingManager](../../mfc/reference/cdockingmanager-class.md)

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxDockingManager. h

##  <a name="adddocksite"></a>CDockingManager::AddDockSite

Cria um painel de encaixe e o adiciona à lista de barras de controle.

```
BOOL AddDockSite(
    const AFX_DOCKSITE_INFO& info,
    CDockSite** ppDockBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*info*<br/>
no Uma referência a uma estrutura de informações que contém alinhamento de painel de encaixe.

*ppDockBar*<br/>
fora Um ponteiro para um ponteiro para o novo painel de encaixe.

### <a name="return-value"></a>Valor retornado

TRUE se o painel de encaixe tiver sido criado com êxito; Caso contrário, FALSE.

##  <a name="addhiddenmditabbedbar"></a>CDockingManager::AddHiddenMDITabbedBar

Adiciona um identificador a um painel de barras à lista de painéis de barras com guias MDI ocultos.

```
void AddHiddenMDITabbedBar(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
no Um ponteiro para um painel de barras

##  <a name="addpane"></a>CDockingManager:: AddPane

Registra um painel com o Gerenciador de encaixe.

```
BOOL AddPane(
    CBasePane* pWnd,
    BOOL bTail = TRUE,
    BOOL bAutoHide = FALSE,
    BOOL bInsertForOuterEdge = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
[entrada, saída] Especifica o painel a ser adicionado ao Gerenciador de encaixe.

*bTail*<br/>
no TRUE para adicionar o painel ao final da lista de painéis para o Gerenciador de encaixe; caso contrário, FALSE.

*bAutoHide*<br/>
no Somente para uso interno. Sempre use o valor padrão FALSE.

*bInsertForOuterEdge*<br/>
no Somente para uso interno. Sempre use o valor padrão FALSE.

### <a name="return-value"></a>Valor retornado

TRUE se o painel tiver sido registrado com êxito com o Gerenciador de encaixe; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame esse método para registrar painéis não flutuantes e não-redimensionáveis com o Gerenciador de encaixe. Se você não registrar os painéis, eles não serão exibidos corretamente quando o Gerenciador de encaixe for disposto.

##  <a name="adjustdockinglayout"></a>CDockingManager::AdjustDockingLayout

Recalcula e ajusta o layout de todos os painéis em uma janela do quadro.

```
virtual void AdjustDockingLayout(HDWP hdwp = NULL);
```

### <a name="parameters"></a>Parâmetros

*hdwp*<br/>
no Especifica a estrutura de posição da janela adiada. Para obter mais informações, consulte [tipos de dados do Windows](/windows/win32/WinProg/windows-data-types).

### <a name="remarks"></a>Comentários

##  <a name="addminiframe"></a>CDockingManager::AddMiniFrame

Adiciona um quadro à lista de mini quadros.

```
virtual BOOL AddMiniFrame(CPaneFrameWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para um quadro.

### <a name="return-value"></a>Valor retornado

TRUE se o quadro não estiver na lista de mini quadros e tiver sido adicionado com êxito; Caso contrário, FALSE.

##  <a name="adjustpaneframes"></a>CDockingManager::AdjustPaneFrames

Faz com que a mensagem de WM_NCCALCSIZE seja enviada a todos os painéis e `CPaneFrameWnd` janelas.

```
virtual void AdjustPaneFrames();
```

### <a name="remarks"></a>Comentários

##  <a name="adjustrecttoclientarea"></a>CDockingManager::AdjustRectToClientArea

Ajusta o alinhamento de um retângulo.

```
virtual BOOL AdjustRectToClientArea(
    CRect& rectResult,
    DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

*rectResult*<br/>
no Uma referência a um objeto `CRect`

*dwAlignment*<br/>
no O alinhamento do objeto `CRect`

### <a name="return-value"></a>Valor retornado

TRUE se o alinhamento do objeto de `CRect` foi ajustado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O parâmetro *dwAlignment* pode ter um dos seguintes valores:

- CBRS_ALIGN_TOP

- CBRS_ALIGN_BOTTOM

- CBRS_ALIGN_LEFT

- CBRS_ALIGN_RIGHT

##  <a name="alignautohidepane"></a>CDockingManager::AlignAutoHidePane

Redimensiona um painel de encaixe no modo de AutoOcultar para que ele ocupe a largura completa ou a altura da área do cliente do quadro envolvida por sites de encaixe.

```
void AlignAutoHidePane(
    CPaneDivider* pDefaultSlider,
    BOOL bIsVisible = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pDefaultSlider*<br/>
no O painel deslizante de encaixe.

*bIsVisible*<br/>
no TRUE se o painel de encaixe estiver visível; Caso contrário, FALSE.

##  <a name="autohidepane"></a>CDockingManager::AutoHidePane

Cria uma barra de ferramentas de AutoOcultar.

```
CMFCAutoHideToolBar* AutoHidePane(
    CDockablePane* pBar,
    CMFCAutoHideToolBar* pCurrAutoHideToolBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
no Um ponteiro para o painel de barras.

*pCurrAutoHideToolBar*<br/>
no Um ponteiro para uma barra de ferramentas de ocultar automaticamente.

### <a name="return-value"></a>Valor retornado

NULL se a barra de ferramentas de ocultar automaticamente não tiver sido criada; caso contrário, um ponteiro para a nova barra de ferramentas.

##  <a name="bringbarstotop"></a>CDockingManager::BringBarsToTop

Coloca as barras encaixadas que têm o alinhamento especificado na parte superior.

```
void BringBarsToTop(
    DWORD dwAlignment = 0,
    BOOL bExcludeDockedBars = TRUE);
```

### <a name="parameters"></a>Parâmetros

*dwAlignment*<br/>
no O alinhamento das barras de encaixe que são trazidas para a parte superior de outras janelas.

*bExcludeDockedBars*<br/>
no TRUE para excluir as barras encaixadas da parte superior; caso contrário, FALSE.

##  <a name="buildpanesmenu"></a>CDockingManager::BuildPanesMenu

Adiciona nomes de painéis de encaixe e barras de ferramentas a um menu.

```
void BuildPanesMenu(
    CMenu& menu,
    BOOL bToolbarsOnly);
```

### <a name="parameters"></a>Parâmetros

*AdicionarMenu*<br/>
no Um menu para adicionar os nomes dos painéis e barras de ferramentas de encaixe ao.

*bToolbarsOnly*<br/>
no TRUE para adicionar apenas os nomes da barra de ferramentas ao menu; Caso contrário, FALSE.

##  <a name="calcexpecteddockedrect"></a>CDockingManager::CalcExpectedDockedRect

Calcula o retângulo esperado de uma janela encaixada.

```
void CalcExpectedDockedRect(
    CWnd* pWnd,
    CPoint ptMouse,
    CRect& rectResult,
    BOOL& bDrawTab,
    CDockablePane** ppTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para a janela a ser encaixada.

*ptMouse*<br/>
no O local do mouse.

*rectResult*<br/>
fora O retângulo calculado.

*bDrawTab*<br/>
no TRUE para desenhar uma guia; caso contrário, FALSE.

*ppTargetBar*<br/>
fora Um ponteiro para um ponteiro para o painel de destino.

### <a name="remarks"></a>Comentários

Esse método calcula o retângulo que uma janela ocuparia se um usuário arrastasse a janela para o ponto especificado por *ptMouse* e o encaixava lá.

##  <a name="create"></a>CDockingManager:: criar

Cria um Gerenciador de encaixe.

```
BOOL Create(CFrameWnd* pParentWnd);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
no Um ponteiro para o quadro pai do Gerenciador de encaixe. Esse valor não deve ser nulo.

### <a name="return-value"></a>Valor retornado

Sempre verdadeiro.

##  <a name="determinepaneandstatus"></a>CDockingManager::D eterminePaneAndStatus

Determina o painel que contém um determinado ponto e seu status de encaixe.

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
no O local do painel a ser verificado.

*nSensitivity*<br/>
no O valor para aumentar o retângulo da janela de cada painel selecionado. Um painel satisfaz os critérios de pesquisa se o ponto determinado estiver nessa região aumentada.

*dwEnabledAlignment*<br/>
no O alinhamento do painel de encaixe.

*ppTargetBar*<br/>
fora Um ponteiro para um ponteiro para o painel de destino.

*pBarToIgnore*<br/>
no O painel que o método ignora.

*pBarToDock*<br/>
no O painel que está encaixado.

### <a name="return-value"></a>Valor retornado

O status de encaixe.

### <a name="remarks"></a>Comentários

O status de encaixe pode ser um dos seguintes valores:

|Valor AFX_CS_STATUS|Significado|
|---------------------------|-------------|
|CS_NOTHING|O ponteiro não está sobre um site de encaixe. Portanto, mantenha o painel flutuante.|
|CS_DOCK_IMMEDIATELY|O ponteiro está sobre o site de encaixe no modo imediato (DT_IMMEDIATE estilo está habilitado), portanto, o painel deve ser encaixado imediatamente.|
|CS_DELAY_DOCK|O ponteiro é sobre um site de encaixe que é outro painel de encaixe ou é uma borda do quadro principal.|
|CS_DELAY_DOCK_TO_TAB|O ponteiro é sobre um site de encaixe que faz com que o painel seja encaixado em uma janela com guias. Isso ocorre quando o mouse está sobre uma legenda de outro painel de encaixe ou sobre uma área de tabulação de um painel com guias.|

##  <a name="disablerestoredockstate"></a>CDockingManager::D isableRestoreDockState

Habilita ou desabilita o carregamento do layout de encaixe do registro.

```
void DisableRestoreDockState(BOOL bDisable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bDesativar*<br/>
no TRUE para desabilitar o carregamento do layout de encaixe do registro; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame esse método quando for necessário preservar o layout atual de painéis de encaixe e barras de ferramentas quando o estado do aplicativo estiver sendo carregado.

##  <a name="dockpane"></a>CDockingManager::D ockPane

Encaixa um painel em outro painel ou em uma janela do quadro.

```
void DockPane(
    CBasePane* pBar,
    UINT nDockBarID = 0,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
no Um ponteiro para um painel de barras para encaixar.

*nDockBarID*<br/>
no A ID da barra a ser encaixada.

*lpRect*<br/>
no O retângulo de destino.

##  <a name="dockpaneleftof"></a>CDockingManager::D ockPaneLeftOf

Encaixa um painel à esquerda de outro painel.

```
BOOL DockPaneLeftOf(
    CPane* pBarToDock,
    CPane* pTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pBarToDock*<br/>
no Um ponteiro para o painel a ser encaixado à esquerda de *pTargetBar*.

*pTargetBar*<br/>
no Um ponteiro para o painel de destino.

### <a name="return-value"></a>Valor retornado

TRUE se o painel foi encaixado com êxito; caso contrário, FALSE.

##  <a name="enableautohidepanes"></a>CDockingManager::EnableAutoHidePanes

Habilita o encaixe do painel no quadro principal, cria um painel de encaixe e o adiciona à lista de barras de controle.

```
BOOL EnableAutoHidePanes(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
no O alinhamento de encaixe.

### <a name="return-value"></a>Valor retornado

TRUE se o painel de encaixe tiver sido criado com êxito; Caso contrário, FALSE.

##  <a name="enabledocking"></a>CDockingManager::EnableDocking

Cria um painel de encaixe e habilita o encaixe do painel no quadro principal.

```
BOOL EnableDocking(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
no O alinhamento de encaixe.

### <a name="return-value"></a>Valor retornado

TRUE se o painel de encaixe tiver sido criado com êxito; Caso contrário, FALSE.

##  <a name="enabledocksitemenu"></a>CDockingManager::EnableDockSiteMenu

Exibe um botão adicional que abre um menu pop-up nas legendas de todos os painéis de encaixe.

```
static void EnableDockSiteMenu(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no TRUE para habilitar o menu do site de encaixe; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O menu encaixar site exibe as seguintes opções para alterar o estado de encaixe do painel:

- `Floating`-flutua um painel

- `Docking`-encaixa um painel no quadro principal no local em que o painel foi encaixado pela última vez

- `AutoHide`-alterna o painel para o modo de AutoOcultar

- `Hide`-oculta um painel

Por padrão, esse menu não é exibido.

##  <a name="enablepanecontextmenu"></a>CDockingManager::EnablePaneContextMenu

Informa à biblioteca para exibir um menu de contexto especial que tem uma lista de barras de ferramentas do aplicativo e painéis de encaixe quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem de WM_CONTEXTMENU.

```
void EnablePaneContextMenu(
    BOOL bEnable,
    UINT uiCustomizeCmd,
    const CString& strCustomizeText,
    BOOL bToolbarsOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no Se for TRUE, a biblioteca ativará o suporte para o menu de contexto automático; Se FALSE, a biblioteca desativa o suporte para o menu de contexto automático.

*uiCustomizeCmd*<br/>
no Uma ID de comando para o item de **personalização** no menu.

*strCustomizeText*<br/>
no O texto do item de **personalização** .

*bToolbarsOnly*<br/>
no Se for TRUE, o menu exibirá apenas uma lista de barras de ferramentas do aplicativo; Se for FALSE, a biblioteca adicionará painéis de encaixe de aplicativo a essa lista.

##  <a name="finddocksite"></a>CDockingManager::FindDockSite

Recupera o painel de barras que está na posição especificada e que tem o alinhamento especificado.

```
virtual CDockSite* FindDockSite(
    DWORD dwAlignment,
    BOOL bOuter);
```

### <a name="parameters"></a>Parâmetros

*dwAlignment*<br/>
no O alinhamento do painel de barras.

*bOuter*<br/>
no Se for TRUE, recupere a barra na posição de cabeçalho na lista de barras de controle. Caso contrário, recupere a barra na posição da parte final na lista de barras de controle.

### <a name="return-value"></a>Valor retornado

O painel de encaixe que tem o alinhamento especificado; Caso contrário, nulo.

##  <a name="findpanebyid"></a>CDockingManager::FindPaneByID

Localiza um painel pela ID de controle especificada.

```
virtual CBasePane* FindPaneByID(
    UINT uBarID,
    BOOL bSearchMiniFrames = FALSE);
```

### <a name="parameters"></a>Parâmetros

*uBarID*<br/>
no Especifica a ID de controle do painel a ser localizado.

*bSearchMiniFrames*<br/>
no TRUE para incluir todos os painéis flutuantes na pesquisa. FALSE para incluir apenas os painéis encaixados.

### <a name="return-value"></a>Valor retornado

O objeto [CBasePane](../../mfc/reference/cbasepane-class.md) que tem a ID de controle especificada ou NULL se o painel especificado não puder ser encontrado.

### <a name="remarks"></a>Comentários

##  <a name="finddocksitebypane"></a>CDockingManager::FindDockSiteByPane

Retorna o painel de barras que tem a ID do painel da barra de destino.

```
virtual CDockSite* FindDockSiteByPane(CPane* pTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pTargetBar*<br/>
no Um ponteiro para o painel da barra de destino.

### <a name="return-value"></a>Valor retornado

O painel de barras que tem a ID do painel da barra de destino; NULL se não existir esse painel de barras.

##  <a name="fixupvirtualrects"></a>CDockingManager::FixupVirtualRects

Confirma todas as posições da barra de ferramentas atual para retângulos virtuais.

```
virtual void FixupVirtualRects();
```

### <a name="remarks"></a>Comentários

Quando o usuário começa a arrastar uma barra de ferramentas, o aplicativo lembra sua posição original no *retângulo virtual*. Quando o usuário move uma barra de ferramentas pelo site de encaixe, a barra de ferramentas pode mudar outras barras de ferramentas. As posições originais das outras barras de ferramentas são armazenadas nos retângulos virtuais correspondentes.

##  <a name="framefrompoint"></a>CDockingManager::FrameFromPoint

Retorna o quadro que contém o ponto determinado.

```
virtual CPaneFrameWnd* FrameFromPoint(
    CPoint pt,
    CPaneFrameWnd* pFrameToExclude,
    BOOL bFloatMultiOnly) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
no Especifica o ponto, em coordenadas da tela, para verificar.

*pFrameToExclude*<br/>
no Um ponteiro para um quadro a ser excluído.

*bFloatMultiOnly*<br/>
no TRUE para excluir quadros que não são instâncias de `CMultiPaneFrameWnd`; Caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

O quadro que contém o ponto determinado; Caso contrário, nulo.

##  <a name="getclientareabounds"></a>CDockingManager::GetClientAreaBounds

Obtém o retângulo que contém os limites da área do cliente.

```
CRect GetClientAreaBounds() const;

void GetClientAreaBounds(CRect& rcClient);
```

### <a name="parameters"></a>Parâmetros

*rcClient*<br/>
fora Uma referência ao retângulo que contém os limites da área do cliente.

### <a name="return-value"></a>Valor retornado

O retângulo que contém os limites da área do cliente.

##  <a name="getdockingmode"></a>CDockingManager::GetDockingMode

Retorna o modo de encaixe atual.

```
static AFX_DOCK_TYPE GetDockingMode();
```

### <a name="return-value"></a>Valor retornado

Um valor de enumerador que representa o modo de encaixe atual. Pode ser um dos seguintes valores:

- DT_STANDARD

- DT_IMMEDIATE

- DT_SMART

### <a name="remarks"></a>Comentários

Para definir o modo de encaixe, chame [CDockingManager:: SetDockingMode](#setdockingmode).

##  <a name="getdocksiteframewnd"></a>CDockingManager::GetDockSiteFrameWnd

Obtém um ponteiro para o quadro da janela pai.

```
CFrameWnd* GetDockSiteFrameWnd() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o quadro da janela pai.

##  <a name="getenabledautohidealignment"></a>CDockingManager::GetEnabledAutoHideAlignment

Retorna o alinhamento habilitado dos painéis.

```
DWORD GetEnabledAutoHideAlignment() const;
```

### <a name="return-value"></a>Valor retornado

Uma combinação de bits de CBRS_ALIGN_ de sinalizadores ou 0 se os painéis de AutoOcultar não estiverem habilitados. Para obter mais informações, consulte [CFrameWnd:: EnableDocking](../../mfc/reference/cframewnd-class.md#enabledocking).

### <a name="remarks"></a>Comentários

O método retorna o alinhamento habilitado para ocultar barras de controle automaticamente. Para habilitar as barras de AutoOcultar, chame [CFrameWndEx:: EnableAutoHidePanes](../../mfc/reference/cframewndex-class.md#enableautohidepanes).

##  <a name="getminiframes"></a>CDockingManager::GetMiniFrames

Obtém uma lista de miniframes.

```
const CObList& GetMiniFrames() const;
```

### <a name="return-value"></a>Valor retornado

Uma lista de miniframes que contêm as barras de controle que pertencem ao Gerenciador de encaixe.

##  <a name="getouteredgebounds"></a>CDockingManager::GetOuterEdgeBounds

Obtém um retângulo que contém as bordas externas do quadro.

```
CRect GetOuterEdgeBounds() const;
```

### <a name="return-value"></a>Valor retornado

Um retângulo que contém as bordas externas do quadro.

##  <a name="getpanelist"></a>CDockingManager:: getpanelista

Retorna uma lista de painéis que pertencem ao Gerenciador de encaixe. Isso inclui todos os painéis flutuantes.

```
void GetPaneList(
    CObList& lstBars,
    BOOL bIncludeAutohide = FALSE,
    CRuntimeClass* pRTCFilter = NULL,
    BOOL bIncludeTabs = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lstBars*<br/>
[entrada, saída] Contém todos os painéis do Gerenciador de encaixe atual.

*bIncludeAutohide*<br/>
no TRUE para incluir os painéis que estão no modo de AutoOcultar; caso contrário, FALSE.

*pRTCFilter*<br/>
no Se não for NULL, a lista retornada conterá painéis somente da classe de tempo de execução especificada.

*bIncludeTabs*<br/>
no TRUE para incluir guias; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se houver qualquer painel com guias no Gerenciador de encaixe, o método retornará ponteiros para objetos de [classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md) e você deverá enumerar as guias explicitamente.

Use *pRTCFilter* para obter uma classe de painéis específica. Por exemplo, você pode obter apenas barras de ferramentas definindo esse valor adequadamente.

##  <a name="getsmartdockingmanager"></a>CDockingManager::GetSmartDockingManager

Recupera um ponteiro para o Gerenciador de encaixe inteligente.

```
CSmartDockingManager* GetSmartDockingManager();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o Gerenciador de encaixe inteligente.

##  <a name="getsmartdockingmanagerpermanent"></a>CDockingManager::GetSmartDockingManagerPermanent

Recupera um ponteiro para o Gerenciador de encaixe inteligente.

```
CSmartDockingManager* GetSmartDockingManagerPermanent() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o Gerenciador de encaixe inteligente.

##  <a name="getsmartdockingparams"></a>CDockingManager::GetSmartDockingParams

Retorna os parâmetros de encaixe inteligente para o Gerenciador de encaixe.

```
static CSmartDockingInfo& GetSmartDockingParams();
```

### <a name="return-value"></a>Valor retornado

A classe que contém os parâmetros de encaixe inteligente para o Gerenciador de encaixe atual. Para obter mais informações, consulte [classe CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md).

### <a name="remarks"></a>Comentários

##  <a name="hideautohidepanes"></a>CDockingManager::HideAutoHidePanes

Oculta um painel que está no modo de AutoOcultar.

```
void HideAutoHidePanes(
    CDockablePane* pBarToExclude = NULL,
    BOOL bImmediately = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pBarToExclude*<br/>
no Um ponteiro para uma barra a ser excluído da ocultação.

*bImmediately*<br/>
no TRUE para ocultar o painel imediatamente; FALSE para ocultar o painel com o efeito de AutoOcultar.

##  <a name="insertdocksite"></a>CDockingManager::InsertDockSite

Cria um painel de encaixe e o insere na lista de barras de controle.

```
BOOL InsertDockSite(
    const AFX_DOCKSITE_INFO& info,
    DWORD dwAlignToInsertAfter,
    CDockSite** ppDockBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*info*<br/>
no Uma estrutura que contém as informações de alinhamento sobre o painel de encaixe.

*dwAlignToInsertAfter*<br/>
no Alinhamento do painel Dock.

*ppDockBar*<br/>
fora Um ponteiro para um ponteiro para um painel de encaixe.

### <a name="return-value"></a>Valor retornado

TRUE se o painel de encaixe tiver sido criado com êxito; Caso contrário, FALSE.

##  <a name="insertpane"></a>CDockingManager::InsertPane

Insere um painel de controle na lista de barras de controle.

```
BOOL InsertPane(
    CBasePane* pControlBar,
    CBasePane* pTarget,
    BOOL bAfter = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pControlBar*<br/>
no Um ponteiro para um painel de controle.

*pTarget*<br/>
no Um ponteiro para um painel de destino.

*bAfter*<br/>
no TRUE para inserir o painel após a posição do painel de destino; Caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

TRUE se o painel de controle for adicionado com êxito à lista de barras de controle; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retornará false se o painel de controle já estiver na lista de barras de controle ou se o painel de destino não existir na lista de barras de controle.

##  <a name="isdocksitemenu"></a>CDockingManager::IsDockSiteMenu

Especifica se um menu pop-up é exibido nas legendas de todos os painéis.

```
static BOOL IsDockSiteMenu();
```

### <a name="return-value"></a>Valor retornado

TRUE se um menu do site de encaixe for exibido nas legendas de todos os painéis de encaixe; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Você pode habilitar o menu encaixar site chamando [CDockingManager:: EnableDockSiteMenu](#enabledocksitemenu).

##  <a name="isinadjustlayout"></a>CDockingManager::IsInAdjustLayout

Determina se os layouts de todos os painéis são ajustados.

```
BOOL IsInAdjustLayout() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se os layouts de todos os painéis forem ajustados; Caso contrário, FALSE.

##  <a name="isolecontainermode"></a>CDockingManager::IsOLEContainerMode

Especifica se o Gerenciador de encaixe está no modo de contêiner OLE.

```
BOOL IsOLEContainerMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o Gerenciador de encaixe estiver no modo de contêiner OLE; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

No modo de contêiner OLE, todos os painéis de encaixe e as barras de ferramentas do aplicativo ficam ocultos. Os painéis também estarão ocultos nesse modo se você tiver definido [CDockingManager:: m_bHideDockingBarsInContainerMode](#m_bhidedockingbarsincontainermode) como true.

##  <a name="ispointneardocksite"></a>CDockingManager::IsPointNearDockSite

Determina se um ponto especificado está próximo ao site de encaixe.

```
BOOL IsPointNearDockSite(
    CPoint point,
    DWORD& dwBarAlignment,
    BOOL& bOuterEdge) const;
```

### <a name="parameters"></a>Parâmetros

*empresas*<br/>
no O ponto especificado.

*dwBarAlignment*<br/>
fora Especifica em qual borda o ponto está próximo. Os valores possíveis são CBRS_ALIGN_LEFT, CBRS_ALIGN_RIGHT, CBRS_ALIGN_TOP e CBRS_ALIGN_BOTTOM.

*bOuterEdge*<br/>
fora TRUE se o ponto estiver próximo à borda externa do site de encaixe; Caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

TRUE se o ponto estiver próximo do site de encaixe; caso contrário, FALSE.

##  <a name="isprintpreviewvalid"></a>CDockingManager::IsPrintPreviewValid

Determina se o modo de visualização de impressão está definido.

```
BOOL IsPrintPreviewValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o modo de visualização de impressão estiver definido; Caso contrário, FALSE.

##  <a name="loadstate"></a>CDockingManager:: LoadState

Carrega o estado do Gerenciador de encaixe do registro.

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
no Nome do perfil.

*uiID*<br/>
no A ID do Gerenciador de encaixe.

### <a name="return-value"></a>Valor retornado

TRUE se o estado do Gerenciador de encaixe tiver sido carregado com êxito; caso contrário, FALSE.

##  <a name="lockupdate"></a>CDockingManager::LockUpdate

Bloqueia a janela especificada.

```
void LockUpdate(BOOL bLock);
```

### <a name="parameters"></a>Parâmetros

*Impeça*<br/>
no TRUE se a janela estiver bloqueada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando uma janela é bloqueada, ela não pode ser movida e não pode ser redesenhada.

##  <a name="m_bhidedockingbarsincontainermode"></a>CDockingManager:: m_bHideDockingBarsInContainerMode

Especifica se o Gerenciador de encaixe oculta painéis no modo de contêiner OLE.

```
AFX_IMPORT_DATA static BOOL m_bHideDockingBarsInContainerMode;
```

### <a name="remarks"></a>Comentários

Defina esse valor como FALSE se desejar manter todos os painéis encaixados no quadro principal visível quando o aplicativo estiver no modo de contêiner OLE. Por padrão, esse valor é TRUE.

##  <a name="m_dockmodeglobal"></a>CDockingManager:: m_dockModeGlobal

Especifica o modo de encaixe global.

```
AFX_IMPORT_DATA static AFX_DOCK_TYPE m_dockModeGlobal;
```

### <a name="remarks"></a>Comentários

Por padrão, cada painel de encaixe usa esse modo de encaixe. Para obter mais informações sobre os valores para os quais esse campo pode ser definido, consulte [CBasePane:: GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).

##  <a name="m_ndocksensitivity"></a>CDockingManager:: m_nDockSensitivity

Especifica a sensibilidade de encaixe.

```
AFX_IMPORT_DATA static int m_nDockSensitivity;
```

### <a name="remarks"></a>Comentários

A sensibilidade de encaixe define como fechar um painel flutuante pode abordar um painel de encaixe, um site de encaixe ou outro painel antes que a estrutura mude seu estado para encaixado.

##  <a name="m_ntimeoutbeforedockingbardock"></a>CDockingManager:: m_nTimeOutBeforeDockingBarDock

Especifica o tempo, em milissegundos, antes que um painel de encaixe seja encaixado no modo de encaixe imediato.

```
static UINT m_nTimeOutBeforeDockingBarDock;
```

### <a name="remarks"></a>Comentários

Antes que um painel seja encaixado, a estrutura aguarda o período de tempo especificado. Isso impede que o painel seja encaixado acidentalmente em um local enquanto o usuário ainda está arrastando-o.

##  <a name="m_ntimeoutbeforetoolbardock"></a>CDockingManager:: m_nTimeOutBeforeToolBarDock

Especifica o tempo, em milissegundos, antes que uma barra de ferramentas seja encaixada na janela do quadro principal.

```
static UINT m_nTimeOutBeforeToolBarDock;
```

### <a name="remarks"></a>Comentários

Antes que uma barra de ferramentas seja encaixada, a estrutura aguarda o período de tempo especificado. Isso impede que a barra de ferramentas seja encaixada acidentalmente em um local enquanto o usuário ainda está arrastando-a.

##  <a name="onactivateframe"></a>CDockingManager::OnActivateFrame

Chamado pelo Framework quando a janela do quadro é ativada ou desativada.

```
virtual void OnActivateFrame(BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*bActivate*<br/>
no Se for TRUE, a janela do quadro será ativada; Se for FALSE, a janela do quadro será desativada.

##  <a name="onclosepopupmenu"></a>CDockingManager::OnClosePopupMenu

Chamado pelo Framework quando um menu pop-up ativo processa uma mensagem de WM_DESTROY.

```
void OnClosePopupMenu();
```

### <a name="remarks"></a>Comentários

A estrutura envia uma mensagem de WM_DESTROY quando está prestes a fechar a janela principal atual. Substitua esse método para manipular notificações de objetos `CMFCPopupMenu` que pertencem à janela do quadro quando um objeto `CMFCPopupMenu` processa uma mensagem WM_DESTROY.

##  <a name="onmoveminiframe"></a>CDockingManager::OnMoveMiniFrame

Chamado pelo Framework para mover uma janela de mini-quadro.

```
virtual BOOL OnMoveMiniFrame(CWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
no Um ponteiro para uma janela de mini-quadro.

### <a name="return-value"></a>Valor retornado

TRUE se o método for executado com sucesso; caso contrário, FALSE.

##  <a name="onpanecontextmenu"></a>CDockingManager::OnPaneContextMenu

Chamado pelo Framework quando ele cria um menu que tem uma lista de painéis.

```
void OnPaneContextMenu(CPoint point);
```

### <a name="parameters"></a>Parâmetros

*empresas*<br/>
no Especifica o local do menu.

##  <a name="panefrompoint"></a>CDockingManager::P aneFromPoint

Retorna o painel que contém o ponto determinado.

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

*empresas*<br/>
no Especifica o ponto, em coordenadas da tela, para verificar.

*nSensitivity*<br/>
no O valor para inflar o retângulo da janela de cada painel selecionado. Um painel satisfaz os critérios de pesquisa se o ponto determinado estiver nessa região inplana.

*bExactBar*<br/>
no TRUE para ignorar o parâmetro *nSensitivity* ; caso contrário, FALSE.

*pRTCBarType*<br/>
no Se não for NULL, o método pesquisará apenas os painéis do tipo especificado.

*bCheckVisibility*<br/>
no TRUE para verificar apenas os painéis visíveis; caso contrário, FALSE.

*dwAlignment*<br/>
fora Se um painel for encontrado no ponto especificado, esse parâmetro conterá o lado do painel mais próximo do ponto especificado. Para obter mais informações, consulte a seção Comentários.

*pBarToIgnore*<br/>
no Se não for NULL, o método ignorará os painéis especificados por esse parâmetro.

### <a name="return-value"></a>Valor retornado

O objeto derivado de [CBasePane](../../mfc/reference/cbasepane-class.md)que contém o ponto determinado, ou NULL se nenhum painel foi encontrado.

### <a name="remarks"></a>Comentários

Quando a função retorna e um painel foi encontrado, *dwAlignment* contém o alinhamento do ponto especificado. Por exemplo, se o ponto estava mais próximo da parte superior do painel, *dwAlignment* é definido como CBRS_ALIGN_TOP.

##  <a name="processpanecontextmenucommand"></a>CDockingManager::P rocessPaneContextMenuCommand

Chamado pelo Framework para marcar ou desmarcar uma caixa de seleção para o comando especificado e recalcular o layout de um painel mostrado.

```
BOOL ProcessPaneContextMenuCommand(
    UINT nID,
    int nCode,
    void* pExtra,
    AFX_CMDHANDLERINFO* pHandlerInfo);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
no A ID de uma barra de controle no menu.

*nCode*<br/>
no O código de notificação do comando.

*pExtra*<br/>
no Um ponteiro para void que é convertido em um ponteiro para `CCmdUI` se *nCode* for CN_UPDATE_COMMAND_UI.

*pHandlerInfo*<br/>
no Um ponteiro para uma estrutura de informações. Este parâmetro não é usado.

### <a name="return-value"></a>Valor retornado

TRUE se *pExtra* não for nulo e *nCode* for igual a CN_UPDATE_COMMAND_UI, ou se houver uma barra de controle com o *NID*especificado.

##  <a name="recalclayout"></a>CDockingManager::RecalcLayout

Recalcula o layout interno dos controles presentes na lista de controles.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bNotify*<br/>
no Esse parâmetro não é usado.

##  <a name="releaseemptypanecontainers"></a>CDockingManager::ReleaseEmptyPaneContainers

Libera os contêineres de painel vazios.

```
void ReleaseEmptyPaneContainers();
```

##  <a name="removehiddenmditabbedbar"></a>CDockingManager::RemoveHiddenMDITabbedBar

Remove o painel de barras ocultos especificado.

```
void RemoveHiddenMDITabbedBar(CDockablePane* pBar);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
no Um ponteiro para um painel de barras a ser removido.

##  <a name="removeminiframe"></a>CDockingManager::RemoveMiniFrame

Remove um quadro especificado da lista de mini quadros.

```
virtual BOOL RemoveMiniFrame(CPaneFrameWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para um quadro a ser removido.

### <a name="return-value"></a>Valor retornado

TRUE se o quadro especificado for removido; Caso contrário, FALSE.

##  <a name="removepanefromdockmanager"></a>CDockingManager::RemovePaneFromDockManager

Cancela o registro de um painel e o Remove da lista no Gerenciador de encaixe.

```
void RemovePaneFromDockManager(
    CBasePane* pWnd,
    BOOL bDestroy,
    BOOL bAdjustLayout,
    BOOL bAutoHide = FALSE,
    CBasePane* pBarReplacement = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para um painel a ser removido.

*bDestroy*<br/>
no Se for TRUE, o painel removido será destruído.

*bAdjustLayout*<br/>
no Se for TRUE, ajuste o layout de encaixe imediatamente.

*bAutoHide*<br/>
no Se for TRUE, o painel será removido da lista de barras de AutoOcultar. Se for FALSE, o painel será removido da lista de painéis normais.

*pBarReplacement*<br/>
no Um ponteiro para um painel que substitui o painel removido.

##  <a name="replacepane"></a>CDockingManager::ReplacePane

Substitui um painel por outro.

```
BOOL ReplacePane(
    CDockablePane* pOriginalBar,
    CDockablePane* pNewBar);
```

### <a name="parameters"></a>Parâmetros

*pOriginalBar*<br/>
no Um ponteiro para o painel original.

*pNewBar*<br/>
no Um ponteiro para o painel que substitui o painel original.

### <a name="return-value"></a>Valor retornado

TRUE se o painel for substituído com êxito; Caso contrário, FALSE.

##  <a name="resortminiframesforzorder"></a>CDockingManager::ResortMiniFramesForZOrder

Resort os quadros na lista de mini quadros.

```
void ResortMiniFramesForZOrder();
```

##  <a name="savestate"></a>CDockingManager:: SaveState

Salva o estado do Gerenciador de encaixe no registro.

```
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
no Um caminho para uma chave do registro.

*uiID*<br/>
no A ID do Gerenciador de encaixe.

### <a name="return-value"></a>Valor retornado

TRUE se o estado foi salvo com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Salvar o estado do Gerenciador de encaixe no registro envolve salvar os Estados das barras de controle, os Estados das barras de AutoOcultar e os Estados dos mini quadros presentes no Gerenciador de encaixe.

##  <a name="sendmessagetominiframes"></a>CDockingManager::SendMessageToMiniFrames

Envia a mensagem especificada para todos os mini quadros.

```
BOOL SendMessageToMiniFrames(
    UINT uMessage,
    WPARAM wParam = 0,
    LPARAM lParam = 0);
```

### <a name="parameters"></a>Parâmetros

*uMessage*<br/>
no A mensagem a ser enviada.

*wParam*<br/>
no Informações adicionais dependentes da mensagem.

*lParam*<br/>
no Informações adicionais dependentes da mensagem.

### <a name="return-value"></a>Valor retornado

Sempre verdadeiro.

##  <a name="serialize"></a>CDockingManager:: Serialize

Grava o Gerenciador de encaixe em um arquivo morto.

```
void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*multi-hop*<br/>
no Uma referência a um objeto de arquivo morto.

### <a name="remarks"></a>Comentários

Escrever o Gerenciador de encaixe em um arquivo envolve determinar o número de barras de controle de encaixe e controles deslizantes e escrever as barras de controle, os mini quadros, as barras de AutoOcultar e as barras com guias MDI para o arquivo morto.

##  <a name="setautohidezorder"></a>CDockingManager::SetAutohideZOrder

Define o tamanho, a largura e a altura das barras de controle e o painel especificado.

```
void SetAutohideZOrder(CDockablePane* pAHDockingBar);
```

### <a name="parameters"></a>Parâmetros

*pAHDockingBar*<br/>
no Um ponteiro para um painel de encaixáveis.

##  <a name="setdockingmode"></a>CDockingManager::SetDockingMode

Define o modo de encaixe.

```
static void SetDockingMode(
    AFX_DOCK_TYPE dockMode,
    AFX_SMARTDOCK_THEME theme = AFX_SDT_DEFAULT);
```

### <a name="parameters"></a>Parâmetros

*dockMode*<br/>
Especifica o novo modo de encaixe. Para obter mais informações, consulte a seção Comentários.

*-*<br/>
Especifica o tema a ser usado para marcadores de encaixe inteligente. Pode ser um dos seguintes valores enumerados: AFX_SDT_DEFAULT, AFX_SDT_VS2005 AFX_SDT_VS2008.

### <a name="remarks"></a>Comentários

Chame esse método estático para definir o modo de encaixe.

*dockMode* pode ser um dos seguintes valores:

- DT_STANDARD-modo de encaixe padrão, conforme implementado no Visual Studio .NET 2003. Os painéis são arrastados sem um contexto de arrastar.

- DT_IMMEDIATE – modo de encaixe imediato conforme implementado no Microsoft Visio. Os painéis são arrastados com um contexto de arrastar, mas nenhum marcador é exibido.

- DT_SMART – modo de encaixe inteligente conforme implementado no Visual Studio 2005. Os painéis são arrastados com um contexto de arrastar e os marcadores inteligentes são exibidos mostrando onde o painel pode ser encaixado.

##  <a name="setdockstate"></a>CDockingManager:: SetDockState

Define o estado de encaixe das barras de controle, os mini quadros e as barras de AutoOcultar.

```
virtual void SetDockState();
```

##  <a name="setprintpreviewmode"></a>CDockingManager::SetPrintPreviewMode

Define o modo de visualização de impressão das barras exibidas na visualização de impressão.

```
void SetPrintPreviewMode(
    BOOL bPreview,
    CPrintPreviewState* pState);
```

### <a name="parameters"></a>Parâmetros

*bPreview*<br/>
no TRUE se o modo de visualização de impressão estiver definido; Caso contrário, FALSE.

*pState*<br/>
no Um ponteiro para um estado de visualização. Este parâmetro não é usado.

##  <a name="setsmartdockingparams"></a>CDockingManager::SetSmartDockingParams

Define os parâmetros que definem o comportamento do encaixe inteligente.

```
static void SetSmartDockingParams(CSmartDockingInfo& params);
```

### <a name="parameters"></a>Parâmetros

*params*<br/>
[entrada, saída] Define os parâmetros para encaixe inteligente.

### <a name="remarks"></a>Comentários

Chame esse método se desejar personalizar a aparência, a cor ou a forma dos marcadores de encaixe inteligente.

Para usar a aparência padrão para marcadores de encaixe inteligente, passe uma instância não inicializada da [classe CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) para *params*.

##  <a name="showdelayshowminiframes"></a>CDockingManager::ShowDelayShowMiniFrames

Mostra ou oculta as janelas dos mini quadros.

```
void ShowDelayShowMiniFrames(BOOL bshow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
no TRUE para tornar a janela do quadro mostrado ativa; FALSE para ocultar a janela do quadro.

##  <a name="showpanes"></a>CDockingManager:: os painéis

Mostra ou oculta os painéis do controle e as barras de AutoOcultar.

```
virtual BOOL ShowPanes(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
no TRUE para mostrar os painéis; FALSE para ocultar os painéis.

### <a name="return-value"></a>Valor retornado

Sempre FALSE.

##  <a name="startsdocking"></a>CDockingManager::StartSDocking

Inicia o encaixe inteligente da janela especificada de acordo com o alinhamento do Gerenciador de encaixe inteligente.

```
void StartSDocking(CWnd* pDockingWnd);
```

### <a name="parameters"></a>Parâmetros

*pDockingWnd*<br/>
no Um ponteiro para uma janela a ser encaixada.

##  <a name="stopsdocking"></a>CDockingManager::StopSDocking

Para o encaixe inteligente.

```
void StopSDocking();
```

##  <a name="getsmartdockingtheme"></a>CDockingManager::GetSmartDockingTheme

Um método estático que retorna um tema usado para exibir marcadores de encaixe inteligente.

```
static AFX_SMARTDOCK_THEME __stdcall GetSmartDockingTheme();
```

### <a name="return-value"></a>Valor retornado

Retorna um dos seguintes valores enumerados: AFX_SDT_DEFAULT, AFX_SDT_VS2005 AFX_SDT_VS2008.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Classe CFrameWndEx](../../mfc/reference/cframewndex-class.md)<br/>
[Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)<br/>
[Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)
