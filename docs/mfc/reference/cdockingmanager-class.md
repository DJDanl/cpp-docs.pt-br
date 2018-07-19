---
title: Classe CDockingManager | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 87fcaf93823e504f3631d50de4f981ae30e882e9
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39027817"
---
# <a name="cdockingmanager-class"></a>Classe CDockingManager
Implementa a funcionalidade básica que controla o layout de encaixe em uma janela de quadro principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDockingManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockingManager::AddDockSite](#adddocksite)|Cria um painel de encaixe e o adiciona à lista de barras de controle.|  
|[CDockingManager::AddHiddenMDITabbedBar](#addhiddenmditabbedbar)|Adiciona um identificador para uma barra de painel para a lista de oculto MDI com guias painéis da barra.|  
|[CDockingManager::AddMiniFrame](#addminiframe)|Adiciona um quadro à lista de quadros minidespejos.|  
|[CDockingManager::AddPane](#addpane)|Registra um painel com o Gerenciador de encaixe.|  
|[CDockingManager::AdjustDockingLayout](#adjustdockinglayout)|Recalcula e ajusta o layout de todos os painéis em uma janela do quadro.|  
|[CDockingManager::AdjustPaneFrames](#adjustpaneframes)|Faz com que a mensagem WM_NCCALCSIZE seja enviada para todos os painéis e `CPaneFrameWnd` windows.|  
|[CDockingManager::AdjustRectToClientArea](#adjustrecttoclientarea)|Ajusta o alinhamento de um retângulo.|  
|[CDockingManager::AlignAutoHidePane](#alignautohidepane)|Redimensiona um painel de encaixe no modo de ocultar automaticamente para que ele utiliza a largura total ou altura da área de cliente do quadro cercada por sites de encaixe.|  
|[CDockingManager::AutoHidePane](#autohidepane)|Cria uma barra de ferramentas de ocultar automaticamente.|  
|[CDockingManager::BringBarsToTop](#bringbarstotop)|Traz as barras encaixadas que têm o alinhamento especificado para a parte superior.|  
|[CDockingManager::BuildPanesMenu](#buildpanesmenu)|Adiciona os nomes dos painéis de encaixe e barras de ferramentas a um menu.|  
|[CDockingManager::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcula o retângulo esperado de uma janela encaixada.|  
|[CDockingManager::Create](#create)|Cria um Gerenciador de encaixe.|  
|[CDockingManager::DeterminePaneAndStatus](#determinepaneandstatus)|Determina o painel que contém um determinado ponto e seu status de encaixe.|  
|[CDockingManager::DisableRestoreDockState](#disablerestoredockstate)|Habilita ou desabilita o carregamento de layout de encaixe do registro.|  
|[CDockingManager::DockPane](#dockpane)|Encaixa um painel para outro painel ou para uma janela de quadro.|  
|[CDockingManager::DockPaneLeftOf](#dockpaneleftof)|Encaixa um painel à esquerda de outro painel.|  
|[CDockingManager::EnableAutoHidePanes](#enableautohidepanes)|Permite o encaixe do painel para o quadro principal, cria um painel de encaixe e adiciona-o à lista de barras de controle.|  
|[CDockingManager::EnableDocking](#enabledocking)|Cria um painel de encaixe e habilita o encaixe do painel para o quadro principal.|  
|[CDockingManager::EnableDockSiteMenu](#enabledocksitemenu)|Exibe mais um botão que abre um menu pop-up nas legendas de todos os painéis de encaixe.|  
|[CDockingManager::EnablePaneContextMenu](#enablepanecontextmenu)|Informa a biblioteca para exibir um menu de contexto especial que tem uma lista de painéis de encaixe e barras de ferramentas de aplicativo quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem WM_CONTEXTMENU.|  
|[CDockingManager::FindDockSite](#finddocksite)|Recupera a barra de painel que está na posição especificada e que tem o alinhamento especificado.|  
|[CDockingManager::FindDockSiteByPane](#finddocksitebypane)|Retorna a barra de painel que tem a id do painel da barra de destino.|  
|[CDockingManager::FindPaneByID](#findpanebyid)|Localiza um painel pela ID do controle especificado.|  
|[CDockingManager::FixupVirtualRects](#fixupvirtualrects)|Confirma todas as posições de barra de ferramentas atual a retângulos virtuais.|  
|[CDockingManager::FrameFromPoint](#framefrompoint)|Retorna o quadro que contém o ponto especificado.|  
|[CDockingManager::GetClientAreaBounds](#getclientareabounds)|Obtém o retângulo que contém os limites da área de cliente.|  
|[CDockingManager::GetDockingMode](#getdockingmode)|Retorna o modo atual de encaixe.|  
|[CDockingManager::GetDockSiteFrameWnd](#getdocksiteframewnd)|Obtém um ponteiro para o quadro de janela pai.|  
|[CDockingManager::GetEnabledAutoHideAlignment](#getenabledautohidealignment)|Retorna o alinhamento habilitado dos painéis.|  
|[CDockingManager::GetMiniFrames](#getminiframes)|Obtém uma lista de miniframes.|  
|[CDockingManager::GetOuterEdgeBounds](#getouteredgebounds)|Obtém um retângulo que contém as bordas externas do quadro.|  
|[CDockingManager::GetPaneList](#getpanelist)|Retorna uma lista de painéis que pertencem ao Gerenciador de encaixe. Isso inclui todos os painéis flutuantes.|  
|[CDockingManager::GetSmartDockingManager](#getsmartdockingmanager)|Recupera um ponteiro para o Gerenciador de encaixe inteligente.|  
|[CDockingManager::GetSmartDockingManagerPermanent](#getsmartdockingmanagerpermanent)|Recupera um ponteiro para o Gerenciador de encaixe inteligente.|  
|[CDockingManager::GetSmartDockingParams](#getsmartdockingparams)|Retorna os parâmetros de encaixe inteligentes para o Gerenciador de encaixe.|  
|[CDockingManager::GetSmartDockingTheme](#getsmartdockingtheme)|Um método estático que retorna um tema usado para exibir os marcadores inteligentes de encaixe.|  
|[CDockingManager::HideAutoHidePanes](#hideautohidepanes)|Oculta um painel que está no modo de ocultar automaticamente.|  
|[CDockingManager::InsertDockSite](#insertdocksite)|Cria um painel de encaixe e o insere na lista de barras de controle.|  
|[CDockingManager::InsertPane](#insertpane)|Insere um painel de controle na lista de barras de controle.|  
|[CDockingManager::IsDockSiteMenu](#isdocksitemenu)|Especifica se um menu pop-up é exibido nas legendas de todos os painéis.|  
|[CDockingManager::IsInAdjustLayout](#isinadjustlayout)|Determina se os layouts de todos os painéis são ajustados.|  
|[CDockingManager::IsOLEContainerMode](#isolecontainermode)|Especifica se o Gerenciador de encaixe está no modo de contêiner OLE.|  
|[CDockingManager::IsPointNearDockSite](#ispointneardocksite)|Determina se um ponto especificado está perto o local de encaixe.|  
|[CDockingManager::IsPrintPreviewValid](#isprintpreviewvalid)|Determina se o modo de visualização de impressão está definido.|  
|[CDockingManager::LoadState](#loadstate)|Carrega o estado do Gerenciador de encaixe do registro.|  
|[CDockingManager::LockUpdate](#lockupdate)|Bloqueia a determinada janela.|  
|[CDockingManager::OnActivateFrame](#onactivateframe)|Chamado pelo framework quando a janela do quadro ficará ativa ou está desativada.|  
|[CDockingManager::OnClosePopupMenu](#onclosepopupmenu)|Chamado pelo framework quando um menu pop-up ativo processa uma mensagem WM_DESTROY.|  
|[CDockingManager::OnMoveMiniFrame](#onmoveminiframe)|Chamado pelo framework para mover uma janela com minimoldura.|  
|[CDockingManager::OnPaneContextMenu](#onpanecontextmenu)|Chamado pelo framework quando ele cria um menu que tem uma lista de painéis.|  
|[CDockingManager::PaneFromPoint](#panefrompoint)|Retorna o painel que contém o ponto especificado.|  
|[CDockingManager::ProcessPaneContextMenuCommand](#processpanecontextmenucommand)|Chamado pelo framework para selecionar ou para limpar uma caixa de seleção para o comando especificado e recalcular o layout de um painel mostrado.|  
|[CDockingManager::RecalcLayout](#recalclayout)|Recalcula o layout interno dos controles presentes na lista de controles.|  
|[CDockingManager::ReleaseEmptyPaneContainers](#releaseemptypanecontainers)|Libera os contêineres de painel vazio.|  
|[CDockingManager::RemoveHiddenMDITabbedBar](#removehiddenmditabbedbar)|Remove o oculta o painel da barra.|  
|[CDockingManager::RemoveMiniFrame](#removeminiframe)|Remove um intervalo especificado da lista de quadros minidespejos.|  
|[CDockingManager::RemovePaneFromDockManager](#removepanefromdockmanager)|Cancela o registro de um painel e a remove da lista no Gerenciador de encaixe.|  
|[CDockingManager::ReplacePane](#replacepane)|Substitui um painel com outra.|  
|[CDockingManager::ResortMiniFramesForZOrder](#resortminiframesforzorder)|Recorre os quadros na lista de quadros minidespejos.|  
|[CDockingManager::SaveState](#savestate)|Salva o estado do Gerenciador de encaixe no registro.|  
|[CDockingManager::SendMessageToMiniFrames](#sendmessagetominiframes)|Envia a mensagem especificada para todos os quadros de minidespejos.|  
|[CDockingManager::Serialize](#serialize)|Grava o encaixe Gerenciador em um arquivo morto. (Substitui [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize).)|  
|[CDockingManager::SetAutohideZOrder](#setautohidezorder)|Define o tamanho, largura e altura das barras de controle e o painel especificado.|  
|[CDockingManager::SetDockingMode](#setdockingmode)|Define o modo de encaixe.|  
|[CDockingManager::SetDockState](#setdockstate)|Define o estado de encaixe das barras de controle, os quadros minidespejos e as barras de ocultar automaticamente.|  
|[CDockingManager::SetPrintPreviewMode](#setprintpreviewmode)|Define o modo de visualização de impressão das barras que são exibidos na visualização de impressão.|  
|[CDockingManager::SetSmartDockingParams](#setsmartdockingparams)|Define os parâmetros que definem o comportamento de encaixe inteligente.|  
|[CDockingManager::ShowDelayShowMiniFrames](#showdelayshowminiframes)|Mostra ou oculta as janelas dos quadros minidespejos.|  
|[CDockingManager::ShowPanes](#showpanes)|Mostra ou oculta os painéis das barras de controle e ocultar automaticamente.|  
|[CDockingManager::StartSDocking](#startsdocking)|Inicia o encaixe inteligente da janela especificada de acordo com o alinhamento do encaixe Gerenciador inteligente.|  
|[CDockingManager::StopSDocking](#stopsdocking)|Paradas de inteligentes de encaixe.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockingManager::m_bHideDockingBarsInContainerMode](#m_bhidedockingbarsincontainermode)|Especifica se o Gerenciador de encaixe oculta os painéis no modo de contêiner OLE.|  
|[CDockingManager::m_dockModeGlobal](#m_dockmodeglobal)|Especifica o modo de encaixe global.|  
|[CDockingManager::m_nDockSensitivity](#m_ndocksensitivity)|Especifica a sensibilidade de encaixe.|  
|[CDockingManager::m_nTimeOutBeforeDockingBarDock](#m_ntimeoutbeforedockingbardock)|Especifica o tempo, em milissegundos, antes de um painel de encaixe é encaixado no modo de encaixe imediato.|  
|[CDockingManager::m_nTimeOutBeforeToolBarDock](#m_ntimeoutbeforetoolbardock)|Especifica o tempo, em milissegundos, antes de uma barra de ferramentas é encaixada na janela do quadro principal.|  
  
## <a name="remarks"></a>Comentários  
 A janela do quadro principal cria e inicializa essa classe automaticamente.  
  
 O objeto do Gerenciador de encaixe mantém uma lista de todos os painéis que estão no layout de encaixe e também uma lista de todos os [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) windows que pertencem a janela principal do quadro.  
  
 O `CDockingManager` classe implementa alguns serviços que você pode usar para localizar um painel ou um `CPaneFrameWnd` janela. Você normalmente não chamar esses serviços diretamente porque eles são encapsulados no objeto de janela de quadro principal. Para obter mais informações, consulte [classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).  
  
## <a name="customization-tips"></a>Dicas de personalização  
 As dicas a seguir se aplicam a `CDockingManager` objetos:  
  
- [Classe CDockingManager](../../mfc/reference/cdockingmanager-class.md) dá suporte a esses modos de encaixe:  
  
    - `AFX_DOCK_TYPE::DT_IMMEDIATE`  
  
    - `AFX_DOCK_TYPE::DT_STANDARD`  
  
    - `AFX_DOCK_TYPE::DT_SMART`  
  
     Esses modos de encaixe são definidos por [CDockingManager::m_dockModeGlobal](#m_dockmodeglobal) e são definidos chamando [CDockingManager::SetDockingMode](#setdockingmode).  
  
-   Se você quiser criar um painel flutuante não, não redimensionável, chame o [CDockingManager::AddPane](#addpane) método. Esse método registra o painel com o Gerenciador de encaixe, que é responsável pelo layout do painel.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na `CDockingManager` classe para configurar um `CDockingManager` objeto. O exemplo mostra como exibir mais um botão que abre um menu pop-up nas legendas de todos os painéis de encaixe e como definir o modo de encaixe do objeto. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#24](../../mfc/codesnippet/cpp/cdockingmanager-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CDockingManager](../../mfc/reference/cdockingmanager-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDockingManager.h  
  
##  <a name="adddocksite"></a>  CDockingManager::AddDockSite  
 Cria um painel de encaixe e o adiciona à lista de barras de controle.  
  
```  
BOOL AddDockSite(
    const AFX_DOCKSITE_INFO& info,  
    CDockSite** ppDockBar = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *informações*  
 Uma referência a uma estrutura de informações que contém encaixar o alinhamento do painel.  
  
 [out] *ppDockBar*  
 Um ponteiro para um ponteiro para o novo painel de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se o painel de encaixe foi criado com êxito; FALSE caso contrário.  
  
##  <a name="addhiddenmditabbedbar"></a>  CDockingManager::AddHiddenMDITabbedBar  
 Adiciona um identificador para uma barra de painel para a lista de oculto MDI com guias painéis da barra.  
  
```  
void AddHiddenMDITabbedBar(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBar*  
 Um ponteiro para uma barra de painel  
  
##  <a name="addpane"></a>  CDockingManager::AddPane  
 Registra um painel com o Gerenciador de encaixe.  
  
```  
BOOL AddPane(
    CBasePane* pWnd,  
    BOOL bTail = TRUE,  
    BOOL bAutoHide = FALSE,  
    BOOL bInsertForOuterEdge = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [no, out] *Apropriei*  
 Especifica o painel para adicionar ao Gerenciador de encaixe.  
  
 [in] *bTail*  
 TRUE para adicionar o painel ao final da lista de painéis para o Gerenciador de encaixe; Caso contrário, FALSE.  
  
 [in] *bAutoHide*  
 Somente para uso interno. Sempre use o valor padrão FALSE.  
  
 [in] *bInsertForOuterEdge*  
 Somente para uso interno. Sempre use o valor padrão FALSE.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o painel foi registrado com êxito com o Gerenciador do encaixe. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para registrar os painéis não redimensionável, não flutuante com o Gerenciador de encaixe. Se você não registrar os painéis, eles não serão exibidos quando o Gerenciador de encaixe é apresentado.  
  
##  <a name="adjustdockinglayout"></a>  CDockingManager::AdjustDockingLayout  
 Recalcula e ajusta o layout de todos os painéis em uma janela do quadro.  
  
```  
virtual void AdjustDockingLayout(HDWP hdwp = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *hdwp*  
 Especifica a estrutura de posição da janela adiada. Para obter mais informações, consulte [tipos de dados do Windows](http://msdn.microsoft.com/library/windows/desktop/aa383751).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addminiframe"></a>  CDockingManager::AddMiniFrame  
 Adiciona um quadro à lista de quadros minidespejos.  
  
```  
virtual BOOL AddMiniFrame(CPaneFrameWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Apropriei*  
 Um ponteiro para um quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro não está na lista de quadros minidespejos e foi adicionado com êxito; FALSE caso contrário.  
  
##  <a name="adjustpaneframes"></a>  CDockingManager::AdjustPaneFrames  
 Faz com que a mensagem WM_NCCALCSIZE seja enviada para todos os painéis e `CPaneFrameWnd` windows.  
  
```  
virtual void AdjustPaneFrames();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="adjustrecttoclientarea"></a>  CDockingManager::AdjustRectToClientArea  
 Ajusta o alinhamento de um retângulo.  
  
```  
virtual BOOL AdjustRectToClientArea(
    CRect& rectResult,  
    DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *rectResult*  
 Uma referência a um `CRect` objeto  
  
 [in] *dwAlignment*  
 O alinhamento do `CRect` objeto  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o alinhamento do `CRect` objeto foi ajustado; FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 O *dwAlignment* parâmetro pode ter um dos seguintes valores:  
  
-   CBRS_ALIGN_TOP  
  
-   CBRS_ALIGN_BOTTOM  
  
-   CBRS_ALIGN_LEFT  
  
-   CBRS_ALIGN_RIGHT  
  
##  <a name="alignautohidepane"></a>  CDockingManager::AlignAutoHidePane  
 Redimensiona um painel de encaixe no modo de ocultar automaticamente para que ele utiliza a largura total ou altura da área de cliente do quadro cercada por sites de encaixe.  
  
```  
void AlignAutoHidePane(
    CPaneDivider* pDefaultSlider,  
    BOOL bIsVisible = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDefaultSlider*  
 O painel de controle deslizante de encaixe.  
  
 [in] *bIsVisible*  
 TRUE se o painel de encaixe estiver visível; FALSE caso contrário.  
  
##  <a name="autohidepane"></a>  CDockingManager::AutoHidePane  
 Cria uma barra de ferramentas de ocultar automaticamente.  
  
```  
CMFCAutoHideToolBar* AutoHidePane(
    CDockablePane* pBar,  
    CMFCAutoHideToolBar* pCurrAutoHideToolBar = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBar*  
 Um ponteiro para a barra de painel.  
  
 [in] *pCurrAutoHideToolBar*  
 Um ponteiro para um automaticamente ocultar barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 NULL se ocultar a barra de ferramentas automática não foi criada; Caso contrário, um ponteiro para a nova barra de ferramentas.  
  
##  <a name="bringbarstotop"></a>  CDockingManager::BringBarsToTop  
 Traz as barras encaixadas que têm o alinhamento especificado para a parte superior.  
  
```  
void BringBarsToTop(
    DWORD dwAlignment = 0,  
    BOOL bExcludeDockedBars = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *dwAlignment*  
 O alinhamento das barras de encaixe que são colocados na parte superior de outras janelas.  
  
 [in] *bExcludeDockedBars*  
 TRUE para impedir que as barras encaixadas sejam na parte superior; Caso contrário, FALSE.  
  
##  <a name="buildpanesmenu"></a>  CDockingManager::BuildPanesMenu  
 Adiciona os nomes dos painéis de encaixe e barras de ferramentas a um menu.  
  
```  
void BuildPanesMenu(
    CMenu& menu,  
    BOOL bToolbarsOnly);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *menu*  
 Um menu para adicionar os nomes dos painéis de encaixe e barras de ferramentas para.  
  
 [in] *bToolbarsOnly*  
 TRUE para adicionar nomes de barra de ferramentas apenas para o menu; FALSE caso contrário.  
  
##  <a name="calcexpecteddockedrect"></a>  CDockingManager::CalcExpectedDockedRect  
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
 [in] *Apropriei*  
 Um ponteiro para a janela encaixar.  
  
 [in] *ptMouse*  
 O local do mouse.  
  
 [out] *rectResult*  
 O retângulo calculado.  
  
 [in] *bDrawTab*  
 True para desenhar uma guia; Caso contrário, FALSE.  
  
 [out] *ppTargetBar*  
 Um ponteiro para um ponteiro para o painel de destino.  
  
### <a name="remarks"></a>Comentários  
 Esse método calcula o retângulo que uma janela deve ocupar se um usuário arrastava a janela para o ponto especificado por *ptMouse* e encaixados-lo lá.  
  
##  <a name="create"></a>  CDockingManager::Create  
 Cria um Gerenciador de encaixe.  
  
```  
BOOL Create(CFrameWnd* pParentWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pParentWnd*  
 Um ponteiro para o quadro principal do Gerenciador de encaixe. Esse valor não deve ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre TRUE.  
  
##  <a name="determinepaneandstatus"></a>  CDockingManager::DeterminePaneAndStatus  
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
 [in] *pt*  
 O local do painel para verificar.  
  
 [in] *nSensitivity*  
 O valor para aumentar o retângulo da janela de cada painel selecionado. Um painel satisfaz os critérios de pesquisa, se o ponto especificado está nesta região maior.  
  
 [in] *dwEnabledAlignment*  
 O alinhamento do painel de encaixe.  
  
 [out] *ppTargetBar*  
 Um ponteiro para um ponteiro para o painel de destino.  
  
 [in] *pBarToIgnore*  
 O painel que o método ignora.  
  
 [in] *pBarToDock*  
 O painel que está encaixado.  
  
### <a name="return-value"></a>Valor de retorno  
 O status de encaixe.  
  
### <a name="remarks"></a>Comentários  
 O status de encaixe pode ser um dos seguintes valores:  
  
|Valor AFX_CS_STATUS|Significado|  
|---------------------------|-------------|  
|CS_NOTHING|O ponteiro não está sobre um local de encaixe. Portanto, mantenha o painel flutuante.|  
|CS_DOCK_IMMEDIATELY|O ponteiro está sobre o local de encaixe no modo imediato (estilo DT_IMMEDIATE estiver habilitado), portanto, o painel deve ser encaixado imediatamente.|  
|CS_DELAY_DOCK|O ponteiro está sobre um local de encaixe que é outro painel de encaixe ou é uma borda do quadro principal.|  
|CS_DELAY_DOCK_TO_TAB|O ponteiro está sobre um local de encaixe que faz com que o painel seja encaixado em uma janela com guias. Isso ocorre quando o mouse está sobre uma legenda de outro painel de encaixe ou sobre uma área da guia de um painel com guias.|  
  
##  <a name="disablerestoredockstate"></a>  CDockingManager::DisableRestoreDockState  
 Habilita ou desabilita o carregamento de layout de encaixe do registro.  
  
```  
void DisableRestoreDockState(BOOL bDisable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bDesative*  
 True para desabilitar o carregamento do layout de encaixe do registro; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método quando você deve preservar o layout atual de painéis de encaixe e barras de ferramentas quando o estado do aplicativo está sendo carregado.  
  
##  <a name="dockpane"></a>  CDockingManager::DockPane  
 Encaixa um painel para outro painel ou para uma janela de quadro.  
  
```  
void DockPane(
    CBasePane* pBar,  
    UINT nDockBarID = 0,  
    LPCRECT lpRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBar*  
 Um ponteiro para uma barra de painel para encaixar.  
  
 [in] *nDockBarID*  
 A id da barra para encaixar.  
  
 [in] *lpRect*  
 O retângulo de destino.  
  
##  <a name="dockpaneleftof"></a>  CDockingManager::DockPaneLeftOf  
 Encaixa um painel à esquerda de outro painel.  
  
```  
BOOL DockPaneLeftOf(
    CPane* pBarToDock,  
    CPane* pTargetBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBarToDock*  
 Um ponteiro para o painel para ser encaixado à esquerda do *pTargetBar*.  
  
 [in] *pTargetBar*  
 Um ponteiro para o painel de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o painel foi encaixado com êxito; Caso contrário, FALSE.  
  
##  <a name="enableautohidepanes"></a>  CDockingManager::EnableAutoHidePanes  
 Permite o encaixe do painel para o quadro principal, cria um painel de encaixe e adiciona-o à lista de barras de controle.  
  
```  
BOOL EnableAutoHidePanes(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *dwStyle*  
 O alinhamento de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se o painel de encaixe foi criado com êxito; FALSE caso contrário.  
  
##  <a name="enabledocking"></a>  CDockingManager::EnableDocking  
 Cria um painel de encaixe e habilita o encaixe do painel para o quadro principal.  
  
```  
BOOL EnableDocking(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *dwStyle*  
 O alinhamento de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se o painel de encaixe foi criado com êxito; FALSE caso contrário.  
  
##  <a name="enabledocksitemenu"></a>  CDockingManager::EnableDockSiteMenu  
 Exibe mais um botão que abre um menu pop-up nas legendas de todos os painéis de encaixe.  
  
```  
static void EnableDockSiteMenu(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bAtivar*  
 TRUE para habilitar o menu de encaixe de site; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 O menu de encaixe site exibe as seguintes opções para alterar o estado de encaixe do painel:  
  
- `Floating` -Flutua um painel  
  
- `Docking` -Encaixa um painel de quadro principal no local onde o painel foi ancorado pela última vez  
  
- `AutoHide` – Alterna o painel para o modo de ocultar automaticamente  
  
- `Hide` -Oculta um painel  
  
 Por padrão, esse menu não é exibido.  
  
##  <a name="enablepanecontextmenu"></a>  CDockingManager::EnablePaneContextMenu  
 Informa a biblioteca para exibir um menu de contexto especial que tem uma lista de painéis de encaixe e barras de ferramentas de aplicativo quando o usuário clica no botão direito do mouse e a biblioteca está processando a mensagem WM_CONTEXTMENU.  
  
```  
void EnablePaneContextMenu(
    BOOL bEnable,  
    UINT uiCustomizeCmd,  
    const CString& strCustomizeText,  
    BOOL bToolbarsOnly = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bAtivar*  
 Se for TRUE, a biblioteca ativa o suporte para o menu de contexto automático: Se FALSE a biblioteca desativa o suporte para o menu de contexto automática.  
  
 [in] *uiCustomizeCmd*  
 Uma id de comando para o **personalizar** item no menu.  
  
 [in] *strCustomizeText*  
 O texto do **personalizar** item.  
  
 [in] *bToolbarsOnly*  
 Se for TRUE, o menu exibe apenas uma lista das barras de ferramentas do aplicativo; Se for FALSE, a biblioteca adiciona os painéis de encaixe de aplicativo a essa lista.  
  
##  <a name="finddocksite"></a>  CDockingManager::FindDockSite  
 Recupera a barra de painel que está na posição especificada e que tem o alinhamento especificado.  
  
```  
virtual CDockSite* FindDockSite(
    DWORD dwAlignment,  
    BOOL bOuter);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *dwAlignment*  
 O alinhamento da barra de painel.  
  
 [in] *bOuter*  
 Se for TRUE, recupere a barra na posição principal na lista de barras de controle. Caso contrário, recupere a barra na posição final na lista das barras de controle.  
  
### <a name="return-value"></a>Valor de retorno  
 O painel de encaixe que tem o alinhamento especificado; Do contrário, nulo.  
  
##  <a name="findpanebyid"></a>  CDockingManager::FindPaneByID  
 Localiza um painel pela ID do controle especificado.  
  
```  
virtual CBasePane* FindPaneByID(
    UINT uBarID,  
    BOOL bSearchMiniFrames = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uBarID*  
 Especifica a ID de controle do painel para localizar.  
  
 [in] *bSearchMiniFrames*  
 TRUE para incluir painéis flutuantes tudo na pesquisa. FALSO para incluir apenas os painéis encaixados.  
  
### <a name="return-value"></a>Valor de retorno  
 O [CBasePane](../../mfc/reference/cbasepane-class.md) objeto que tem o controle especificado ID, ou nulo se o painel especificado não pode ser encontrado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="finddocksitebypane"></a>  CDockingManager::FindDockSiteByPane  
 Retorna a barra de painel que tem a id do painel da barra de destino.  
  
```  
virtual CDockSite* FindDockSiteByPane(CPane* pTargetBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pTargetBar*  
 Um ponteiro para o painel da barra de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 A barra de painel que tem a id do painel de barra de destino; NULO se não há como um painel da barra existe.  
  
##  <a name="fixupvirtualrects"></a>  CDockingManager::FixupVirtualRects  
 Confirma todas as posições de barra de ferramentas atual a retângulos virtuais.  
  
```  
virtual void FixupVirtualRects();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário começa a arrastar uma barra de ferramentas, o aplicativo se lembra de sua posição original na *retângulo virtual*. Quando o usuário move uma barra de ferramentas em seu local de encaixe, a barra de ferramentas pode ser deslocados outras barras de ferramentas. As posições originais das outras barras de ferramentas são armazenadas em retângulos virtuais correspondentes.  
  
##  <a name="framefrompoint"></a>  CDockingManager::FrameFromPoint  
 Retorna o quadro que contém o ponto especificado.  
  
```  
virtual CPaneFrameWnd* FrameFromPoint(
    CPoint pt,  
    CPaneFrameWnd* pFrameToExclude,  
    BOOL bFloatMultiOnly) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pt*  
 Especifica o ponto em coordenadas da tela, para verificar.  
  
 [in] *pFrameToExclude*  
 Um ponteiro para um quadro a ser excluído.  
  
 [in] *bFloatMultiOnly*  
 True para excluir os registros não são instâncias do `CMultiPaneFrameWnd`; FALSE caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 O quadro que contém o ponto fornecido; Do contrário, nulo.  
  
##  <a name="getclientareabounds"></a>  CDockingManager::GetClientAreaBounds  
 Obtém o retângulo que contém os limites da área de cliente.  
  
```  
CRect GetClientAreaBounds() const;

void GetClientAreaBounds(CRect& rcClient);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] *rcClient*  
 Uma referência para o retângulo que contém os limites da área de cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo que contém os limites da área de cliente.  
  
##  <a name="getdockingmode"></a>  CDockingManager::GetDockingMode  
 Retorna o modo atual de encaixe.  
  
```  
static AFX_DOCK_TYPE GetDockingMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de enumerador que representa o modo atual de encaixe. Ele pode ser um dos seguintes valores:  
  
- DT_STANDARD  
  
- DT_IMMEDIATE  
  
- DT_SMART  
  
### <a name="remarks"></a>Comentários  
 Para definir o modo de encaixe, chame [CDockingManager::SetDockingMode](#setdockingmode).  
  
##  <a name="getdocksiteframewnd"></a>  CDockingManager::GetDockSiteFrameWnd  
 Obtém um ponteiro para o quadro de janela pai.  
  
```  
CFrameWnd* GetDockSiteFrameWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o quadro de janela pai.  
  
##  <a name="getenabledautohidealignment"></a>  CDockingManager::GetEnabledAutoHideAlignment  
 Retorna o alinhamento habilitado dos painéis.  
  
```  
DWORD GetEnabledAutoHideAlignment() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação bit a bit dos sinalizadores CBRS_ALIGN_ ou 0 se os painéis de ocultar automaticamente não estiverem habilitados. Para obter mais informações, consulte [CFrameWnd::EnableDocking](../../mfc/reference/cframewnd-class.md#enabledocking).  
  
### <a name="remarks"></a>Comentários  
 O método retorna o alinhamento habilitado para barras de controle de ocultar automaticamente. Para habilitar as barras de ocultar automaticamente, chame [CFrameWndEx::EnableAutoHidePanes](../../mfc/reference/cframewndex-class.md#enableautohidepanes).  
  
##  <a name="getminiframes"></a>  CDockingManager::GetMiniFrames  
 Obtém uma lista de miniframes.  
  
```  
const CObList& GetMiniFrames() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma lista de miniframes que contêm as barras de controle que pertencem ao Gerenciador de encaixe.  
  
##  <a name="getouteredgebounds"></a>  CDockingManager::GetOuterEdgeBounds  
 Obtém um retângulo que contém as bordas externas do quadro.  
  
```  
CRect GetOuterEdgeBounds() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um retângulo que contém as bordas externas do quadro.  
  
##  <a name="getpanelist"></a>  CDockingManager::GetPaneList  
 Retorna uma lista de painéis que pertencem ao Gerenciador de encaixe. Isso inclui todos os painéis flutuantes.  
  
```  
void GetPaneList(
    CObList& lstBars,  
    BOOL bIncludeAutohide = FALSE,  
    CRuntimeClass* pRTCFilter = NULL,  
    BOOL bIncludeTabs = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [no, out] *lstBars*  
 Contém todos os painéis do Gerenciador de encaixe atual.  
  
 [in] *bIncludeAutohide*  
 TRUE para incluir os painéis que estão no modo de ocultar automaticamente; Caso contrário, FALSE.  
  
 [in] *pRTCFilter*  
 Se não for NULL, a lista retornada contém painéis apenas da classe de tempo de execução especificado.  
  
 [in] *bIncludeTabs*  
 TRUE para incluir guias; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Se houver qualquer painéis com guias no Gerenciador de encaixe, o método retorna ponteiros para [classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md) objetos e você deve enumerar as guias explicitamente.  
  
 Use *pRTCFilter* para obter uma classe específica de painéis. Por exemplo, você pode obter somente as barras de ferramentas ao definir esse valor apropriadamente.  
  
##  <a name="getsmartdockingmanager"></a>  CDockingManager::GetSmartDockingManager  
 Recupera um ponteiro para o Gerenciador de encaixe inteligente.  
  
```  
CSmartDockingManager* GetSmartDockingManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [Gerenciador de encaixe inteligente](http://msdn.microsoft.com/f537a1a6-fb9e-41d7-952f-0f25d5ee7534).  
  
##  <a name="getsmartdockingmanagerpermanent"></a>  CDockingManager::GetSmartDockingManagerPermanent  
 Recupera um ponteiro para o Gerenciador de encaixe inteligente.  
  
```  
CSmartDockingManager* GetSmartDockingManagerPermanent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o Gerenciador de encaixe inteligente.  
  
##  <a name="getsmartdockingparams"></a>  CDockingManager::GetSmartDockingParams  
 Retorna os parâmetros de encaixe inteligentes para o Gerenciador de encaixe.  
  
```  
static CSmartDockingInfo& GetSmartDockingParams();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A classe que contém os parâmetros de encaixe inteligentes para o Gerenciador de encaixe atual. Para obter mais informações, consulte [classe CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hideautohidepanes"></a>  CDockingManager::HideAutoHidePanes  
 Oculta um painel que está no modo de ocultar automaticamente.  
  
```  
void HideAutoHidePanes(
    CDockablePane* pBarToExclude = NULL,  
    BOOL bImmediately = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBarToExclude*  
 Um ponteiro para uma barra para excluir de ocultação.  
  
 [in] *bImmediately*  
 TRUE para ocultar o painel imediatamente; FALSO para ocultar o painel com o efeito de ocultar automaticamente.  
  
##  <a name="insertdocksite"></a>  CDockingManager::InsertDockSite  
 Cria um painel de encaixe e o insere na lista de barras de controle.  
  
```  
BOOL InsertDockSite(
    const AFX_DOCKSITE_INFO& info,  
    DWORD dwAlignToInsertAfter,  
    CDockSite** ppDockBar = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *informações*  
 Uma estrutura que contém as informações de alinhamento sobre o painel de encaixe.  
  
 [in] *dwAlignToInsertAfter*  
 Alinhamento do painel de encaixe.  
  
 [out] *ppDockBar*  
 Um ponteiro para um ponteiro para um painel de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 VERDADEIRO se o painel de encaixe foi criado com êxito; FALSE caso contrário.  
  
##  <a name="insertpane"></a>  CDockingManager::InsertPane  
 Insere um painel de controle na lista de barras de controle.  
  
```  
BOOL InsertPane(
    CBasePane* pControlBar,  
    CBasePane* pTarget,  
    BOOL bAfter = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pControlBar*  
 Um ponteiro para um painel de controle.  
  
 [in] *pTarget*  
 Um ponteiro para um painel de destino.  
  
 [in] *bDepois*  
 TRUE para inserir o painel após a posição do painel de destino; FALSE caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o painel de controle é adicionado com êxito à lista de barras de controle; FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este método retornará false se o painel de controle já estiver na lista de barras de controle ou se o painel de destino não existe na lista de barras de controle.  
  
##  <a name="isdocksitemenu"></a>  CDockingManager::IsDockSiteMenu  
 Especifica se um menu pop-up é exibido nas legendas de todos os painéis.  
  
```  
static BOOL IsDockSiteMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se um menu do site de encaixe é exibido nas legendas de todos os painéis de encaixe; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Você pode habilitar o menu de encaixe do site ao chamar [CDockingManager::EnableDockSiteMenu](#enabledocksitemenu).  
  
##  <a name="isinadjustlayout"></a>  CDockingManager::IsInAdjustLayout  
 Determina se os layouts de todos os painéis são ajustados.  
  
```  
BOOL IsInAdjustLayout() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se os layouts de todos os painéis são ajustados; FALSE caso contrário.  
  
##  <a name="isolecontainermode"></a>  CDockingManager::IsOLEContainerMode  
 Especifica se o Gerenciador de encaixe está no modo de contêiner OLE.  
  
```  
BOOL IsOLEContainerMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o Gerenciador de encaixe estiver no modo de contêiner OLE. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 No modo de contêiner OLE, todos os painéis de encaixe e barras de ferramentas do aplicativo estão ocultos. Os painéis também são ocultos nesse modo, se você tiver definido [CDockingManager::m_bHideDockingBarsInContainerMode](#m_bhidedockingbarsincontainermode) como TRUE.  
  
##  <a name="ispointneardocksite"></a>  CDockingManager::IsPointNearDockSite  
 Determina se um ponto especificado está perto o local de encaixe.  
  
```  
BOOL IsPointNearDockSite(
    CPoint point,  
    DWORD& dwBarAlignment,  
    BOOL& bOuterEdge) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *ponto*  
 O ponto especificado.  
  
 [out] *dwBarAlignment*  
 Especifica que o ponto está próximo de borda. Os valores possíveis são CBRS_ALIGN_LEFT, CBRS_ALIGN_RIGHT, CBRS_ALIGN_TOP e CBRS_ALIGN_BOTTOM.  
  
 [out] *bOuterEdge*  
 TRUE se o ponto está próximo a borda externa do local de encaixe; FALSE caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o ponto é quase o local de encaixe; Caso contrário, FALSE.  
  
##  <a name="isprintpreviewvalid"></a>  CDockingManager::IsPrintPreviewValid  
 Determina se o modo de visualização de impressão está definido.  
  
```  
BOOL IsPrintPreviewValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o modo de visualização de impressão estiver definido; FALSE caso contrário.  
  
##  <a name="loadstate"></a>  CDockingManager::LoadState  
 Carrega o estado do Gerenciador de encaixe do registro.  
  
```  
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,  
    UINT uiID = (UINT) -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszProfileName*  
 Nome do perfil.  
  
 [in] *uiID*  
 A id do Gerenciador de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o estado de encaixe Gerenciador foi carregado com êxito; Caso contrário, FALSE.  
  
##  <a name="lockupdate"></a>  CDockingManager::LockUpdate  
 Bloqueia a determinada janela.  
  
```  
void LockUpdate(BOOL bLock);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bloco*  
 TRUE se a janela está bloqueada; FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Quando uma janela é bloqueada, ele não pode ser movido e ele não pode ser redesenhado.  
  
##  <a name="m_bhidedockingbarsincontainermode"></a>  CDockingManager::m_bHideDockingBarsInContainerMode  
 Especifica se o Gerenciador de encaixe oculta os painéis no modo de contêiner OLE.  
  
```  
AFX_IMPORT_DATA static BOOL m_bHideDockingBarsInContainerMode;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse valor como FALSE se você quiser manter todos os painéis encaixados quadro principal visível quando o aplicativo está no modo de contêiner OLE. Por padrão, esse valor for TRUE.  
  
##  <a name="m_dockmodeglobal"></a>  CDockingManager::m_dockModeGlobal  
 Especifica o modo de encaixe global.  
  
```  
AFX_IMPORT_DATA static AFX_DOCK_TYPE m_dockModeGlobal;  
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, cada painel de encaixe usa esse modo de encaixe. Para obter mais informações sobre os valores que esse campo pode ser definido como, consulte [CBasePane::GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).  
  
##  <a name="m_ndocksensitivity"></a>  CDockingManager::m_nDockSensitivity  
 Especifica a sensibilidade de encaixe.  
  
```  
AFX_IMPORT_DATA static int m_nDockSensitivity;  
```  
  
### <a name="remarks"></a>Comentários  
 A sensibilidade de encaixe define quão próximo flutuante painel pode abordar um painel de encaixe, ancoragem site ou outro painel antes que o framework muda seu estado para encaixado.  
  
##  <a name="m_ntimeoutbeforedockingbardock"></a>  CDockingManager::m_nTimeOutBeforeDockingBarDock  
 Especifica o tempo, em milissegundos, antes de um painel de encaixe é encaixado no modo de encaixe imediato.  
  
```  
static UINT m_nTimeOutBeforeDockingBarDock;  
```  
  
### <a name="remarks"></a>Comentários  
 Antes de um painel é encaixado, o framework aguarda o período de tempo especificado. Isso impede que o painel acidentalmente sendo encaixado em um local enquanto o usuário está arrastando ainda.  
  
##  <a name="m_ntimeoutbeforetoolbardock"></a>  CDockingManager::m_nTimeOutBeforeToolBarDock  
 Especifica o tempo, em milissegundos, antes de uma barra de ferramentas é encaixada na janela do quadro principal.  
  
```  
static UINT m_nTimeOutBeforeToolBarDock;  
```  
  
### <a name="remarks"></a>Comentários  
 Antes de uma barra de ferramentas estiver encaixada, a estrutura aguarda o período de tempo especificado. Isso impede que a barra de ferramentas que está sendo encaixado acidentalmente para um local enquanto o usuário está arrastando ainda.  
  
##  <a name="onactivateframe"></a>  CDockingManager::OnActivateFrame  
 Chamado pelo framework quando a janela do quadro ficará ativa ou está desativada.  
  
```  
virtual void OnActivateFrame(BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bActivate*  
 Se for TRUE, a janela do quadro é ativada; Se for FALSE, a janela do quadro é desativada.  
  
##  <a name="onclosepopupmenu"></a>  CDockingManager::OnClosePopupMenu  
 Chamado pelo framework quando um menu pop-up ativo processa uma mensagem WM_DESTROY.  
  
```  
void OnClosePopupMenu();
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura envia uma mensagem WM_DESTROY quando ele está prestes a fechar a janela principal atual. Substitua este método para lidar com notificações de `CMFCPopupMenu` objetos que pertencem à janela do quadro quando uma `CMFCPopupMenu` objeto processa uma mensagem WM_DESTROY.  
  
##  <a name="onmoveminiframe"></a>  CDockingManager::OnMoveMiniFrame  
 Chamado pelo framework para mover uma janela com minimoldura.  
  
```  
virtual BOOL OnMoveMiniFrame(CWnd* pFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pFrame*  
 Um ponteiro para uma janela com minimoldura.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o método for bem-sucedido; Caso contrário, FALSE.  
  
##  <a name="onpanecontextmenu"></a>  CDockingManager::OnPaneContextMenu  
 Chamado pelo framework quando ele cria um menu que tem uma lista de painéis.  
  
```  
void OnPaneContextMenu(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *ponto*  
 Especifica o local do menu.  
  
##  <a name="panefrompoint"></a>  CDockingManager::PaneFromPoint  
 Retorna o painel que contém o ponto especificado.  
  
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
 [in] *ponto*  
 Especifica o ponto em coordenadas da tela, para verificar.  
  
 [in] *nSensitivity*  
 O valor para inflar o retângulo da janela de cada painel selecionado. Um painel satisfaz os critérios de pesquisa, se o ponto especificado está nesta região inflado.  
  
 [in] *bExactBar*  
 TRUE para ignorar a *nSensitivity* parâmetro; caso contrário, FALSE.  
  
 [in] *pRTCBarType*  
 Se não for NULL, o método procura apenas os painéis do tipo especificado.  
  
 [in] *bCheckVisibility*  
 True para painéis de seleção visível somente; Caso contrário, FALSE.  
  
 [out] *dwAlignment*  
 Se um painel for encontrado no ponto especificado, este parâmetro conterá o lado do painel que foi mais próximo ao ponto especificado. Para obter mais informações, consulte a seção Comentários.  
  
 [in] *pBarToIgnore*  
 Se não for NULL, o método ignora painéis especificados por esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 O [CBasePane](../../mfc/reference/cbasepane-class.md)-objeto derivado que contém o ponto especificado ou nulo se nenhum painel foi encontrado.  
  
### <a name="remarks"></a>Comentários  
 Quando a função retornará e um painel foi encontrado, *dwAlignment* contém o alinhamento do ponto especificado. Por exemplo, se o ponto fosse mais próximo à parte superior do painel de *dwAlignment* é definido como CBRS_ALIGN_TOP.  
  
##  <a name="processpanecontextmenucommand"></a>  CDockingManager::ProcessPaneContextMenuCommand  
 Chamado pelo framework para selecionar ou para limpar uma caixa de seleção para o comando especificado e recalcular o layout de um painel mostrado.  
  
```  
BOOL ProcessPaneContextMenuCommand(
    UINT nID,  
    int nCode,  
    void* pExtra,  
    AFX_CMDHANDLERINFO* pHandlerInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nID*  
 A id de uma barra de controle no menu.  
  
 [in] *nCode*  
 O código de notificação do comando.  
  
 [in] *pExtra*  
 Um ponteiro para void que é convertido em um ponteiro para `CCmdUI` se *nCode* é CN_UPDATE_COMMAND_UI.  
  
 [in] *pHandlerInfo*  
 Um ponteiro para uma estrutura de informações. Este parâmetro não é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se *pEXtra* não for nulo e *nCode* é igual a CN_UPDATE_COMMAND_UI, ou se houver uma barra de controle com especificado *nID*.  
  
##  <a name="recalclayout"></a>  CDockingManager::RecalcLayout  
 Recalcula o layout interno dos controles presentes na lista de controles.  
  
```  
virtual void RecalcLayout(BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bNotify*  
 Este parâmetro não é usado.  
  
##  <a name="releaseemptypanecontainers"></a>  CDockingManager::ReleaseEmptyPaneContainers  
 Libera os contêineres de painel vazio.  
  
```  
void ReleaseEmptyPaneContainers();
```  
  
##  <a name="removehiddenmditabbedbar"></a>  CDockingManager::RemoveHiddenMDITabbedBar  
 Remove o oculta o painel da barra.  
  
```  
void RemoveHiddenMDITabbedBar(CDockablePane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pBar*  
 Um ponteiro para uma barra de painel a ser removido.  
  
##  <a name="removeminiframe"></a>  CDockingManager::RemoveMiniFrame  
 Remove um intervalo especificado da lista de quadros minidespejos.  
  
```  
virtual BOOL RemoveMiniFrame(CPaneFrameWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Apropriei*  
 Um ponteiro para um quadro a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro especificado for removido; FALSE caso contrário.  
  
##  <a name="removepanefromdockmanager"></a>  CDockingManager::RemovePaneFromDockManager  
 Cancela o registro de um painel e a remove da lista no Gerenciador de encaixe.  
  
```  
void RemovePaneFromDockManager(
    CBasePane* pWnd,  
    BOOL bDestroy,  
    BOOL bAdjustLayout,  
    BOOL bAutoHide = FALSE,  
    CBasePane* pBarReplacement = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Apropriei*  
 Um ponteiro para um painel a ser removido.  
  
 [in] *bDestroy*  
 Se for TRUE, o painel removido é destruído.  
  
 [in] *bAdjustLayout*  
 Se for TRUE, ajuste o layout de encaixe imediatamente.  
  
 [in] *bAutoHide*  
 Se for TRUE, o painel é removido da lista de barras de ocultar automaticamente. Se for FALSE, o painel é removido da lista de painéis regulares.  
  
 [in] *pBarReplacement*  
 Um ponteiro para um painel que substitui o painel removido.  
  
##  <a name="replacepane"></a>  CDockingManager::ReplacePane  
 Substitui um painel com outra.  
  
```  
BOOL ReplacePane(
    CDockablePane* pOriginalBar,  
    CDockablePane* pNewBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pOriginalBar*  
 Um ponteiro para o painel original.  
  
 [in] *pNewBar*  
 Um ponteiro para o painel que substitui o painel de dados original.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o painel é substituído com êxito; FALSE caso contrário.  
  
##  <a name="resortminiframesforzorder"></a>  CDockingManager::ResortMiniFramesForZOrder  
 Recorre os quadros na lista de quadros minidespejos.  
  
```  
void ResortMiniFramesForZOrder();
```  
  
##  <a name="savestate"></a>  CDockingManager::SaveState  
 Salva o estado do Gerenciador de encaixe no registro.  
  
```  
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,  
    UINT uiID = (UINT) -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszProfileName*  
 Um caminho para uma chave do registro.  
  
 [in] *uiID*  
 A ID de gerente encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o estado foi salvo com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Salvamento do estado de encaixe do gerente para o registro envolve a salvar os estados das barras de controle, os estados das barras de ocultar automaticamente e os estados dos quadros minidespejos presentes no Gerenciador de encaixe.  
  
##  <a name="sendmessagetominiframes"></a>  CDockingManager::SendMessageToMiniFrames  
 Envia a mensagem especificada para todos os quadros de minidespejos.  
  
```  
BOOL SendMessageToMiniFrames(
    UINT uMessage,  
    WPARAM wParam = 0,  
    LPARAM lParam = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uMessage*  
 A mensagem a ser enviada.  
  
 [in] *wParam*  
 Informações de dependentes adicionais da mensagem.  
  
 [in] *lParam*  
 Informações de dependentes adicionais da mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre TRUE.  
  
##  <a name="serialize"></a>  CDockingManager::Serialize  
 Grava o encaixe Gerenciador em um arquivo morto.  
  
```  
void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *ar*  
 Uma referência a um objeto de arquivo morto.  
  
### <a name="remarks"></a>Comentários  
 Gravando o encaixe Gerenciador em um arquivo morto envolve a determinação do número de controles deslizantes e barras de controle de encaixe e escrever as barras de controle, os quadros minidespejos, as barras de ocultar automaticamente e as barras MDI com guias para o arquivo morto.  
  
##  <a name="setautohidezorder"></a>  CDockingManager::SetAutohideZOrder  
 Define o tamanho, largura e altura das barras de controle e o painel especificado.  
  
```  
void SetAutohideZOrder(CDockablePane* pAHDockingBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pAHDockingBar*  
 Um ponteiro para um painel encaixável.  
  
##  <a name="setdockingmode"></a>  CDockingManager::SetDockingMode  
 Define o modo de encaixe.  
  
```  
static void SetDockingMode(
    AFX_DOCK_TYPE dockMode,  
    AFX_SMARTDOCK_THEME theme = AFX_SDT_DEFAULT);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dockMode*  
 Especifica o novo modo de encaixe. Para obter mais informações, consulte a seção Comentários.  
  
 *Tema*  
 Especifica o tema a ser usado para marcadores inteligentes de encaixe. Ele pode ser um dos seguintes valores enumerados: AFX_SDT_DEFAULT, AFX_SDT_VS2005, AFX_SDT_VS2008.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método estático para definir o modo de encaixe.  
  
 *dockMode* pode ser um dos seguintes valores:  
  
- DT_STANDARD - modo de encaixe padrão como implementado no Visual Studio .NET 2003. Painéis são arrastados sem um contexto de arrastar.  
  
- DT_IMMEDIATE - modo de encaixe imediato como implementado no Microsoft Visio. Painéis são arrastados com um contexto de arrastar, mas nenhum marcadores são exibidos.  
  
- DT_SMART - modo de encaixe inteligente como implementado no Visual Studio 2005. Painéis são arrastados com um contexto de arrastar e marcadores inteligentes são exibidos para mostrar onde o painel pode ser encaixado.  
  
##  <a name="setdockstate"></a>  CDockingManager::SetDockState  
 Define o estado de encaixe das barras de controle, os quadros minidespejos e as barras de ocultar automaticamente.  
  
```  
virtual void SetDockState();
```  
  
##  <a name="setprintpreviewmode"></a>  CDockingManager::SetPrintPreviewMode  
 Define o modo de visualização de impressão das barras que são exibidos na visualização de impressão.  
  
```  
void SetPrintPreviewMode(
    BOOL bPreview,  
    CPrintPreviewState* pState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bPreview*  
 TRUE se o modo de visualização de impressão estiver definido; FALSE caso contrário.  
  
 [in] *pState*  
 Um ponteiro para um estado de visualização. Este parâmetro não é usado.  
  
##  <a name="setsmartdockingparams"></a>  CDockingManager::SetSmartDockingParams  
 Define os parâmetros que definem o comportamento de encaixe inteligente.  
  
```  
static void SetSmartDockingParams(CSmartDockingInfo& params);
```  
  
### <a name="parameters"></a>Parâmetros  
 [no, out] *param. autom.*  
 Define os parâmetros para encaixar inteligente.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método se você quiser personalizar a aparência, a cor ou a forma de marcadores inteligentes de encaixe.  
  
 Para usar a aparência padrão de marcadores inteligentes de encaixe, passe uma instância não inicializada de [classe CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) à *params*.  
  
##  <a name="showdelayshowminiframes"></a>  CDockingManager::ShowDelayShowMiniFrames  
 Mostra ou oculta as janelas dos quadros minidespejos.  
  
```  
void ShowDelayShowMiniFrames(BOOL bshow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bMostrar*  
 TRUE para ativar a janela do quadro mostrado; FALSO para ocultar a janela do quadro.  
  
##  <a name="showpanes"></a>  CDockingManager::ShowPanes  
 Mostra ou oculta os painéis das barras de controle e ocultar automaticamente.  
  
```  
virtual BOOL ShowPanes(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bMostrar*  
 TRUE para mostrar os painéis; FALSO para ocultar os painéis.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre FALSE.  
  
##  <a name="startsdocking"></a>  CDockingManager::StartSDocking  
 Inicia o encaixe inteligente da janela especificada de acordo com o alinhamento do encaixe Gerenciador inteligente.  
  
```  
void StartSDocking(CWnd* pDockingWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDockingWnd*  
 Um ponteiro para uma janela de encaixe.  
  
##  <a name="stopsdocking"></a>  CDockingManager::StopSDocking  
 Paradas de inteligentes de encaixe.  
  
```  
void StopSDocking();
```  
  
##  <a name="getsmartdockingtheme"></a>  CDockingManager::GetSmartDockingTheme  
 Um método estático que retorna um tema usado para exibir os marcadores inteligentes de encaixe.  
  
```  
static AFX_SMARTDOCK_THEME __stdcall GetSmartDockingTheme();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um dos seguintes valores enumerados: AFX_SDT_DEFAULT, AFX_SDT_VS2005, AFX_SDT_VS2008.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Classe CFrameWndEx](../../mfc/reference/cframewndex-class.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)   
 [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)
