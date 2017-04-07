---
title: Classe COleIPFrameWndEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleIPFrameWndEx
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::AddDockSite
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::AddPane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::AdjustDockingLayout
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::DockPane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::DockPaneLeftOf
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::EnableAutoHidePanes
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::EnableDocking
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::EnablePaneMenu
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetActivePopup
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetContainerFrameWindow
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetDefaultResId
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetDockFrame
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetDockingManager
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetMainFrame
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetMenuBar
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetPane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetTearOffBars
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::GetToolbarButtonToolTipText
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::InsertPane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::IsMenuBarAvailable
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::IsPointNearDockSite
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::LoadFrame
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnCloseDockingPane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnCloseMiniFrame
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnClosePopupMenu
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnCmdMsg
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnDrawMenuImage
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnDrawMenuLogo
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnMenuButtonToolHitTest
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnMoveMiniFrame
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnSetPreviewMode
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnShowCustomizePane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnShowPanes
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnShowPopupMenu
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::OnTearOffMenu
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::PaneFromPoint
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::PreTranslateMessage
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::RecalcLayout
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::RemovePaneFromDockManager
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::SetDockState
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::SetupToolbarMenu
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::ShowPane
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::WinHelpA
- AFXOLEIPFRAMEWNDEX/COleIPFrameWndEx::InitUserToobars
dev_langs:
- C++
helpviewer_keywords:
- COleIPFrameWndEx class
ms.assetid: ebff1560-a1eb-4854-af00-95d4a192bd55
caps.latest.revision: 34
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5eec8e3a9cc4ad71a1ee3de9f6d5f25cffef1242
ms.lasthandoff: 02/25/2017

---
# <a name="coleipframewndex-class"></a>Classe COleIPFrameWndEx
O `COleIPFrameWndEx` classe implementa um recipiente OLE que dá suporte a MFC. Você deve derivar a classe de janela de quadro in-loco para o aplicativo a partir o `COleIPFrameWndEx` classe, em vez de derivar do [COleIPFrameWnd](../../mfc/reference/coleipframewnd-class.md)classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleIPFrameWndEx : public COleIPFrameWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleIPFrameWndEx::AddDockSite](#adddocksite)||  
|[COleIPFrameWndEx::AddPane](#addpane)||  
|[COleIPFrameWndEx::AdjustDockingLayout](#adjustdockinglayout)||  
|[COleIPFrameWndEx::DockPane](#dockpane)||  
|[COleIPFrameWndEx::DockPaneLeftOf](#dockpaneleftof)|Encaixa um painel à esquerda do outro painel.|  
|[COleIPFrameWndEx::EnableAutoHidePanes](#enableautohidepanes)||  
|[COleIPFrameWndEx::EnableDocking](#enabledocking)||  
|[COleIPFrameWndEx::EnablePaneMenu](#enablepanemenu)||  
|[COleIPFrameWndEx::GetActivePopup](#getactivepopup)|Retorna um ponteiro para o menu pop-up exibido atualmente.|  
|[COleIPFrameWndEx::GetContainerFrameWindow](#getcontainerframewindow)||  
|[COleIPFrameWndEx::GetDefaultResId](#getdefaultresid)|Retorna a ID de recurso da janela do quadro que você especificou quando a janela foi carregada.|  
|[COleIPFrameWndEx::GetDockFrame](#getdockframe)||  
|[COleIPFrameWndEx::GetDockingManager](#getdockingmanager)||  
|[COleIPFrameWndEx::GetMainFrame](#getmainframe)||  
|[COleIPFrameWndEx::GetMenuBar](#getmenubar)|Retorna um ponteiro para o objeto de barra de menu anexado à janela de quadro.|  
|[COleIPFrameWndEx::GetPane](#getpane)||  
|[COleIPFrameWndEx::GetTearOffBars](#gettearoffbars)|Retorna uma lista de objetos do painel que estão em um estado destacável.|  
|[COleIPFrameWndEx::GetToolbarButtonToolTipText](#gettoolbarbuttontooltiptext)|Chamado pela estrutura antes que a dica de ferramenta para um botão é exibida.|  
|[COleIPFrameWndEx::InsertPane](#insertpane)||  
|[COleIPFrameWndEx::IsMenuBarAvailable](#ismenubaravailable)|Determina se o ponteiro para o objeto de barra de menu não é `NULL`.|  
|[COleIPFrameWndEx::IsPointNearDockSite](#ispointneardocksite)||  
|[COleIPFrameWndEx::LoadFrame](#loadframe)|(Substitui `COleIPFrameWnd::LoadFrame`.)|  
|[COleIPFrameWndEx::OnCloseDockingPane](#onclosedockingpane)||  
|[COleIPFrameWndEx::OnCloseMiniFrame](#oncloseminiframe)||  
|[COleIPFrameWndEx::OnClosePopupMenu](#onclosepopupmenu)|Chamado pela estrutura quando um menu pop-up active processa uma mensagem WM_DESTROY.|  
|[COleIPFrameWndEx::OnCmdMsg](#oncmdmsg)|(Substitui `CFrameWnd::OnCmdMsg`.)|  
|[COleIPFrameWndEx::OnDrawMenuImage](#ondrawmenuimage)|Chamado pela estrutura quando a imagem associada a um item de menu é desenhada.|  
|[COleIPFrameWndEx::OnDrawMenuLogo](#ondrawmenulogo)|Chamado pela estrutura quando um [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)objeto processa uma mensagem WM_PAINT.|  
|[COleIPFrameWndEx::OnMenuButtonToolHitTest](#onmenubuttontoolhittest)|Chamado pela estrutura quando um [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)mensagem WM_NCHITTEST de processos do objeto.|  
|[COleIPFrameWndEx::OnMoveMiniFrame](#onmoveminiframe)||  
|[COleIPFrameWndEx::OnSetPreviewMode](#onsetpreviewmode)|Chame essa função de membro para definir a janela do quadro principal do aplicativo dentro e fora do modo de visualização de impressão. (Substitui [CFrameWnd::OnSetPreviewMode](../../mfc/reference/cframewnd-class.md#onsetpreviewmode).)|  
|[COleIPFrameWndEx::OnShowCustomizePane](#onshowcustomizepane)||  
|[COleIPFrameWndEx::OnShowPanes](#onshowpanes)||  
|[COleIPFrameWndEx::OnShowPopupMenu](#onshowpopupmenu)|Chamado pela estrutura quando um menu pop-up é ativado.|  
|[COleIPFrameWndEx::OnTearOffMenu](#ontearoffmenu)|Chamado pela estrutura quando um menu que tem uma barra destacável é ativado.|  
|[COleIPFrameWndEx::PaneFromPoint](#panefrompoint)||  
|[COleIPFrameWndEx::PreTranslateMessage](#pretranslatemessage)|(Substitui `COleIPFrameWnd::PreTranslateMessage`.)|  
|[COleIPFrameWndEx::RecalcLayout](#recalclayout)|(Substitui `COleIPFrameWnd::RecalcLayout`.)|  
|[COleIPFrameWndEx::RemovePaneFromDockManager](#removepanefromdockmanager)||  
|[COleIPFrameWndEx::SetDockState](#setdockstate)|Aplica o estado de encaixe especificado para os painéis que pertencem à janela de quadro.|  
|[COleIPFrameWndEx::SetupToolbarMenu](#setuptoolbarmenu)|Modifica um objeto toolbar procurando itens fictícios e substituí-los com os itens definidos pelo usuário especificados.|  
|[COleIPFrameWndEx::ShowPane](#showpane)||  
|[COleIPFrameWndEx::WinHelpA](#winhelpa)|Chamado pela estrutura para iniciar a Ajuda de contexto ou aplicativo WinHelp.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleIPFrameWndEx::InitUserToobars](#initusertoobars)|Informa a estrutura para inicializar um intervalo de identificações de controle que são atribuídos a barras de ferramentas definidas pelo usuário.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como subclasse uma instância do `COleIPFrameWndEx` de classe e sobre propagar seus métodos. O exemplo mostra como ir mais a `OnDestory` método, o `RepositionFrame` método, o `RecalcLayout` método e o `CalcWindowRect` método. Este trecho de código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad n º&1;](../../mfc/reference/codesnippet/cpp/coleipframewndex-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 [COleIPFrameWnd](../../mfc/reference/coleipframewnd-class.md)  
  
 [COleIPFrameWndEx](../../mfc/reference/coleipframewndex-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxoleipframewndex.h  
  
##  <a name="adddocksite"></a>COleIPFrameWndEx::AddDockSite  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void AddDockSite();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addpane"></a>COleIPFrameWndEx::AddPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL AddPane(
    CBasePane* pControlBar,  
    BOOL bTail = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 [in] `bTail`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="adjustdockinglayout"></a>COleIPFrameWndEx::AdjustDockingLayout  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void AdjustDockingLayout(HDWP hdwp = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hdwp`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="dockpane"></a>COleIPFrameWndEx::DockPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void DockPane(
    CBasePane* pBar,  
    UINT nDockBarID = 0,  
    LPCRECT lpRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `nDockBarID`  
 [in] `lpRect`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="dockpaneleftof"></a>COleIPFrameWndEx::DockPaneLeftOf  
 Encaixa um painel à esquerda do outro painel.  
  
```  
BOOL DockPaneLeftOf(
    CPane* pBar,  
    CPane* pLeftOf);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para o painel de encaixe.  
  
 [in] `pLeftOf`  
 Um ponteiro para o painel que atua como origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a operação for bem-sucedida. Caso contrário, retornará `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para encaixar vários objetos de painel em uma ordem predefinida. Esse método encaixa o painel especificado por `pBar` à esquerda do painel especificado por `pLeftOf`.  
  
##  <a name="enableautohidepanes"></a>COleIPFrameWndEx::EnableAutoHidePanes  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL EnableAutoHidePanes(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwDockStyle`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enabledocking"></a>COleIPFrameWndEx::EnableDocking  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL EnableDocking(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwDockStyle`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enablepanemenu"></a>COleIPFrameWndEx::EnablePaneMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void EnablePaneMenu(
    BOOL bEnable,  
    UINT uiCustomizeCmd,  
    const CString& strCustomizeLabel,  
    UINT uiViewToolbarsMenuEntryID,  
    BOOL bContextMenuShowsToolbarsOnly = FALSE,  
    BOOL bViewMenuShowsToolbarsOnly = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 [in] `uiCustomizeCmd`  
 [in] `strCustomizeLabel`  
 [in] `uiViewToolbarsMenuEntryID`  
 [in] `bContextMenuShowsToolbarsOnly`  
 [in] `bViewMenuShowsToolbarsOnly`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getactivepopup"></a>COleIPFrameWndEx::GetActivePopup  
 Retorna um ponteiro para o menu pop-up exibido atualmente.  
  
```  
CMFCPopupMenu* GetActivePopup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o menu pop-up ativo; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Use este método para obter um ponteiro para o [CMFCPopupMenu classe](../../mfc/reference/cmfcpopupmenu-class.md) objeto que está sendo exibido.  
  
##  <a name="getcontainerframewindow"></a>COleIPFrameWndEx::GetContainerFrameWindow  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
COleCntrFrameWndEx* GetContainerFrameWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdefaultresid"></a>COleIPFrameWndEx::GetDefaultResId  
 Retorna a ID de recurso de menu que foi especificada quando a janela do quadro carregado no menu.  
  
```  
UINT GetDefaultResId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a ID de recurso do menu ou 0 se a janela de quadro não possui nenhuma barra de menu.  
  
### <a name="remarks"></a>Comentários  
 Essa função para recuperar a ID de recurso que foi especificado quando a janela do quadro carregado o recurso do menu chamando de chamada `COleIPFrameWndEx::LoadFrame`.  
  
##  <a name="getdockframe"></a>COleIPFrameWndEx::GetDockFrame  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CFrameWnd* GetDockFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdockingmanager"></a>COleIPFrameWndEx::GetDockingManager  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CDockingManager* GetDockingManager();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getmainframe"></a>COleIPFrameWndEx::GetMainFrame  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CFrameWnd* GetMainFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getmenubar"></a>COleIPFrameWndEx::GetMenuBar  
 Retorna um ponteiro para o objeto de barra de menu anexado à janela de quadro.  
  
```  
const CMFCMenuBar* GetMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto de barra de menu.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para recuperar um ponteiro para o objeto de barra de menu pertence a `COleIPFrameWndEx` objeto.  
  
##  <a name="getpane"></a>COleIPFrameWndEx::GetPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CBasePane* GetPane(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettearoffbars"></a>COleIPFrameWndEx::GetTearOffBars  
 Retorna uma lista de objetos do painel que estão em um estado destacável.  
  
```  
const CObList& GetTearOffBars() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um `CObList` objeto que contém uma coleção de ponteiros para o [CBasePane classe](../../mfc/reference/cbasepane-class.md)-objetos derivados.  
  
### <a name="remarks"></a>Comentários  
 O `COleIPFrameWndEx` objeto mantém a coleção de menus destacável como uma lista de [CBasePane classe](../../mfc/reference/cbasepane-class.md)-objetos derivados. Use esse método para recuperar uma referência a essa lista.  
  
##  <a name="gettoolbarbuttontooltiptext"></a>COleIPFrameWndEx::GetToolbarButtonToolTipText  
 Chamado pela estrutura antes que a dica de ferramenta para um botão é exibida.  
  
```  
virtual BOOL GetToolbarButtonToolTipText(
    CMFCToolBarButton* pButton,  
    CString& strTTText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Ponteiro para o botão.  
  
 [in] `strTTText`  
 Ponteiro para o texto de dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar a exibição de dicas de ferramentas em botões da barra de ferramentas.  
  
##  <a name="initusertoobars"></a>COleIPFrameWndEx::InitUserToobars  
 Especifica um intervalo de identificações de controle que o framework atribui às barras de ferramentas definidas pelo usuário.  
  
```  
void InitUserToolbars(
    LPCTSTR lpszRegEntry,   
    UINT uiUserToolbarFirst,   
    UINT uiUserToolbarLast)  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszRegEntry`  
 A entrada do registro em que a biblioteca armazena as configurações do usuário da barra de ferramentas.  
  
 [in] `uiUserToolbarFirst`  
 ID de controle atribuído à primeira barra de ferramentas definidas pelo usuário.  
  
 [in] `uiUserToolbarLast`  
 ID do controle atribuído à última barra de ferramentas definidas pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para inicializar um intervalo de IDs de controle para atribuição às barras de ferramentas que os usuários definir dinamicamente. Os parâmetros `uiUserToolbarFirst` e `uiUserToolbarLast` definem um intervalo de IDs de controle de barra de ferramentas permitidos. Para desabilitar a criação de barras de ferramentas definidas pelo usuário, defina `uiUserToolbarFirst` ou `uiUserToolbarLast` como -1.  
  
##  <a name="insertpane"></a>COleIPFrameWndEx::InsertPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL InsertPane(
    CBasePane* pControlBar,  
    CBasePane* pTarget,  
    BOOL bAfter = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 [in] `pTarget`  
 [in] `bAfter`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ismenubaravailable"></a>COleIPFrameWndEx::IsMenuBarAvailable  
 Determina se o ponteiro para o objeto de barra de menu não é`NULL`  
  
```  
BOOL IsMenuBarAvailable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Valor diferente de zero retorna se a janela de quadro tem uma barra de menus; Caso contrário, retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para determinar se a janela do quadro mantém um não - `NULL` ponteiro para seu objeto de barra de menu.  
  
##  <a name="ispointneardocksite"></a>COleIPFrameWndEx::IsPointNearDockSite  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsPointNearDockSite(
    CPoint point,  
    DWORD& dwBarAlignment,  
    BOOL& bOuterEdge) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 [in] `dwBarAlignment`  
 [in] `bOuterEdge`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="loadframe"></a>COleIPFrameWndEx::LoadFrame  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL LoadFrame(
    UINT nIDResource,  
    DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,  
    CWnd* pParentWnd = NULL,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIDResource`  
 [in] `dwDefaultStyle`  
 [in] `pParentWnd`  
 [in] `pContext`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onclosedockingpane"></a>COleIPFrameWndEx::OnCloseDockingPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnCloseDockingPane(CDockablePane*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CDockablePane*`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oncloseminiframe"></a>COleIPFrameWndEx::OnCloseMiniFrame  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnCloseMiniFrame(CPaneFrameWnd*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CPaneFrameWnd*`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onclosepopupmenu"></a>COleIPFrameWndEx::OnClosePopupMenu  
 Chamado pela estrutura quando processa um menu pop-up ativa um `WM_DESTROY` mensagem.  
  
```  
virtual void OnClosePopupMenu(CMFCPopupMenu* pMenuPopup);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuPopup`  
 Um ponteiro para o objeto do menu pop-up.  
  
### <a name="remarks"></a>Comentários  
 Substituir este método para receber notificações de `CMFCPopupMenu` objetos quando eles processem `WM_DESTROY` mensagens.  
  
##  <a name="oncmdmsg"></a>COleIPFrameWndEx::OnCmdMsg  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnCmdMsg(
    UINT nID,  
    int nCode,  
    void* pExtra,  
    AFX_CMDHANDLERINFO* pHandlerInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 [in] `nCode`  
 [in] `pExtra`  
 [in] `pHandlerInfo`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawmenuimage"></a>COleIPFrameWndEx::OnDrawMenuImage  
 Chamado pela estrutura quando a imagem que está associada um item de menu é desenhada.  
  
```  
virtual BOOL OnDrawMenuImage(
    CDC* pDC,  
    const CMFCToolBarMenuButton* pMenuButton,  
    const CRect& rectImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o contexto do dispositivo.  
  
 [in] `pMenuButton`  
 Ponteiro para o botão de menu.  
  
 [in] `rectImage`  
 A imagem associada ao item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão não faz nada e retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método se você quiser personalizar a imagem de desenho dos itens de menu que pertencem à barra de menus pertencente a `COleIPFrameWndEx`-objeto derivado.  
  
##  <a name="ondrawmenulogo"></a>COleIPFrameWndEx::OnDrawMenuLogo  
 Chamado pela estrutura quando um [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md)objeto processos um `WM_PAINT` mensagem.  
  
```  
virtual void OnDrawMenuLogo(
    CDC* pDC,  
    CMFCPopupMenu* pMenu,  
    const CRect& rectLogo);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para o contexto do dispositivo.  
  
 [in] `pMenu`  
 Ponteiro para o objeto do menu pop-up.  
  
 [in] `rectLogo`  
 Ponteiro para o logotipo a ser exibido.  
  
### <a name="remarks"></a>Comentários  
 Substituir este método para exibir um logotipo no menu pop-up associado com a barra de menus pertencente a `COleIPFrameWndEx`-objeto derivado. A implementação padrão não faz nada.  
  
##  <a name="onmenubuttontoolhittest"></a>COleIPFrameWndEx::OnMenuButtonToolHitTest  
 Chamado pela estrutura quando um [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)objeto processos um `WM_NCHITTEST` mensagem.  
  
```  
virtual BOOL OnMenuButtonToolHitTest(
    CMFCToolBarButton* pButton,  
    TOOLINFO* pTI);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] pButton  
 Ponteiro para um botão de menu.  
  
 [out] pTI  
 Ponteiro para uma estrutura `TOOLINFO`.  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão não faz nada e retornará 0. Sua implementação deve retornar um valor diferente de zero se ele preenche o `pTI` parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Substitui esse método para fornecer informações de dica de ferramenta sobre um item de menu específico.  
  
##  <a name="onmoveminiframe"></a>COleIPFrameWndEx::OnMoveMiniFrame  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnMoveMiniFrame(CWnd* pFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrame`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onsetpreviewmode"></a>COleIPFrameWndEx::OnSetPreviewMode  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnSetPreviewMode(
    BOOL bPreview,  
    CPrintPreviewState* pState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bPreview`  
 [in] `pState`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onshowcustomizepane"></a>COleIPFrameWndEx::OnShowCustomizePane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnShowCustomizePane(
    CMFCPopupMenu* pMenuPane,  
    UINT uiToolbarID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuPane`  
 [in] `uiToolbarID`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onshowpanes"></a>COleIPFrameWndEx::OnShowPanes  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnShowPanes(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onshowpopupmenu"></a>COleIPFrameWndEx::OnShowPopupMenu  
 Chamado pela estrutura quando um menu pop-up é exibido.  
  
```  
virtual BOOL OnShowPopupMenu(CMFCPopupMenu* pMenuPopup);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pMenuPopup`  
 Ponteiro para o menu pop-up a ser exibido.  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão não faz nada e retorna um valor diferente de zero. Sua implementação deve retornar `FALSE` se não pode ser exibido no menu pop-up.  
  
### <a name="remarks"></a>Comentários  
 Substitui esse método para personalizar a exibição de um menu pop-up. Por exemplo, você pode alterar os botões de menu para botões de menu cor ou inicializar destacável barras.  
  
##  <a name="ontearoffmenu"></a>COleIPFrameWndEx::OnTearOffMenu  
 Chamado pela estrutura quando o usuário seleciona um menu que tem uma barra destacável.  
  
```  
virtual BOOL OnTearOffMenu(
    CMFCPopupMenu* pMenuPopup,  
    CPane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuPopup`  
 Um ponteiro para o menu pop-up que o usuário selecionado.  
  
 [in] `pBar`  
 Um ponteiro para o painel que hospeda o menu.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se você quiser que a estrutura para ativar o menu pop-up; Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se você quiser personalizar a configuração da barra de ferramentas destacável.  
  
##  <a name="panefrompoint"></a>COleIPFrameWndEx::PaneFromPoint  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CBasePane* PaneFromPoint(
    CPoint point,  
    int nSensitivity,  
    bool bExactBar,  
    CRuntimeClass* pRTCBarType) const;  
  
CBasePane* PaneFromPoint(
    CPoint point,  
    int nSensitivity,  
    DWORD& dwAlignment,  
    CRuntimeClass* pRTCBarType) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 [in] `nSensitivity`  
 [in] `bExactBar`  
 [in] `pRTCBarType`  
 [in] `dwAlignment`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="pretranslatemessage"></a>COleIPFrameWndEx::PreTranslateMessage  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMsg`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="recalclayout"></a>COleIPFrameWndEx::RecalcLayout  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void RecalcLayout(BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bNotify`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removepanefromdockmanager"></a>COleIPFrameWndEx::RemovePaneFromDockManager  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void RemovePaneFromDockManager(
    CBasePane* pControlBar,  
    BOOL bDestroy,  
    BOOL bAdjustLayout,  
    BOOL bAutoHide,  
    CBasePane* pBarReplacement);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pControlBar`  
 [in] `bDestroy`  
 [in] `bAdjustLayout`  
 [in] `bAutoHide`  
 [in] `pBarReplacement`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setdockstate"></a>COleIPFrameWndEx::SetDockState  
 Aplica o estado de encaixe especificado para painéis que pertencem à janela de quadro.  
  
```  
void SetDockState(const CDockState& state);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `state`  
 Especifica o estado de encaixe.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para especificar um novo estado de encaixe para painéis que pertencem ao `COleIPFrameWndEx` objeto.  
  
##  <a name="setuptoolbarmenu"></a>COleIPFrameWndEx::SetupToolbarMenu  
 Modifica um objeto toolbar procurando itens fictícios e substituí-los com os itens definidos pelo usuário especificados.  
  
```  
void SetupToolbarMenu(
    CMenu& menu,  
    const UINT uiViewUserToolbarCmdFirst,  
    const UINT uiViewUserToolbarCmdLast);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `menu`  
 Uma referência a um [CMenu](../../mfc/reference/cmenu-class.md) objeto a ser modificado.  
  
 [in] `uiViewUserToolbarCmdFirst`  
 Especifica o primeiro comando definidos pelo usuário.  
  
 [in] `uiViewUserToolbarCmdLast`  
 Especifica o último comando definidos pelo usuário.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="showpane"></a>COleIPFrameWndEx::ShowPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void ShowPane(
    CBasePane* pBar,  
    BOOL bShow,  
    BOOL bDelay,  
    BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `bShow`  
 [in] `bDelay`  
 [in] `bActivate`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="winhelpa"></a>COleIPFrameWndEx::WinHelpA  
 Chamado pela estrutura para iniciar a Ajuda de contexto ou aplicativo WinHelp.  
  
```  
virtual void WinHelp(
    DWORD dwData,  
    UINT nCmd = HELP_CONTEXT);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] dwData  
 Especifica os dados conforme necessário para o tipo de ajuda especificado por `nCmd`.  
  
 [in] `nCmd`  
 Especifica o tipo de ajuda solicitado. Para obter uma lista de valores possíveis e como eles afetam o `dwData` parâmetro, consulte o [função WinHelp](http://msdn.microsoft.com/library/windows/desktop/bb762267) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [CWinAppEx é classe](../../mfc/reference/cframewndex-class.md)   
 [Classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)

