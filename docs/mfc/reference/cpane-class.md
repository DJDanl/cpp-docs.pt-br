---
title: Classe CPane | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPane
- AFXPANE/CPane
- AFXPANE/CPane::AdjustSizeImmediate
- AFXPANE/CPane::AllocElements
- AFXPANE/CPane::AllowShowOnPaneMenu
- AFXPANE/CPane::CalcAvailableSize
- AFXPANE/CPane::CalcInsideRect
- AFXPANE/CPane::CalcRecentDockedRect
- AFXPANE/CPane::CalcSize
- AFXPANE/CPane::CanBeDocked
- AFXPANE/CPane::CanBeTabbedDocument
- AFXPANE/CPane::ConvertToTabbedDocument
- AFXPANE/CPane::CopyState
- AFXPANE/CPane::Create
- AFXPANE/CPane::CreateDefaultMiniframe
- AFXPANE/CPane::CreateEx
- AFXPANE/CPane::DockByMouse
- AFXPANE/CPane::DockPane
- AFXPANE/CPane::DockPaneStandard
- AFXPANE/CPane::DockToFrameWindow
- AFXPANE/CPane::DoesAllowSiblingBars
- AFXPANE/CPane::FloatPane
- AFXPANE/CPane::GetAvailableExpandSize
- AFXPANE/CPane::GetAvailableStretchSize
- AFXPANE/CPane::GetBorders
- AFXPANE/CPane::GetClientHotSpot
- AFXPANE/CPane::GetDockSiteRow
- AFXPANE/CPane::GetExclusiveRowMode
- AFXPANE/CPane::GetHotSpot
- AFXPANE/CPane::GetMinSize
- AFXPANE/CPane::GetPaneName
- AFXPANE/CPane::GetVirtualRect
- AFXPANE/CPane::IsChangeState
- AFXPANE/CPane::IsDragMode
- AFXPANE/CPane::IsInFloatingMultiPaneFrameWnd
- AFXPANE/CPane::IsLeftOf
- AFXPANE/CPane::IsResizable
- AFXPANE/CPane::IsTabbed
- AFXPANE/CPane::LoadState
- AFXPANE/CPane::MoveByAlignment
- AFXPANE/CPane::MovePane
- AFXPANE/CPane::OnAfterChangeParent
- AFXPANE/CPane::OnBeforeChangeParent
- AFXPANE/CPane::OnPressCloseButton
- AFXPANE/CPane::OnShowControlBarMenu
- AFXPANE/CPane::RecalcLayout
- AFXPANE/CPane::SaveState
- AFXPANE/CPane::SetActiveInGroup
- AFXPANE/CPane::SetBorders
- AFXPANE/CPane::SetClientHotSpot
- AFXPANE/CPane::SetDockState
- AFXPANE/CPane::SetExclusiveRowMode
- AFXPANE/CPane::SetMiniFrameRTC
- AFXPANE/CPane::SetMinSize
- AFXPANE/CPane::SetVirtualRect
- AFXPANE/CPane::StretchPaneDeferWndPos
- AFXPANE/CPane::ToggleAutoHide
- AFXPANE/CPane::UndockPane
- AFXPANE/CPane::UpdateVirtualRect
- AFXPANE/CPane::OnAfterDock
- AFXPANE/CPane::OnAfterFloat
- AFXPANE/CPane::OnBeforeDock
- AFXPANE/CPane::OnBeforeFloat
- AFXPANE/CPane::m_bHandleMinSize
- AFXPANE/CPane::m_recentDockInfo
dev_langs:
- C++
helpviewer_keywords:
- CPane [MFC], AdjustSizeImmediate
- CPane [MFC], AllocElements
- CPane [MFC], AllowShowOnPaneMenu
- CPane [MFC], CalcAvailableSize
- CPane [MFC], CalcInsideRect
- CPane [MFC], CalcRecentDockedRect
- CPane [MFC], CalcSize
- CPane [MFC], CanBeDocked
- CPane [MFC], CanBeTabbedDocument
- CPane [MFC], ConvertToTabbedDocument
- CPane [MFC], CopyState
- CPane [MFC], Create
- CPane [MFC], CreateDefaultMiniframe
- CPane [MFC], CreateEx
- CPane [MFC], DockByMouse
- CPane [MFC], DockPane
- CPane [MFC], DockPaneStandard
- CPane [MFC], DockToFrameWindow
- CPane [MFC], DoesAllowSiblingBars
- CPane [MFC], FloatPane
- CPane [MFC], GetAvailableExpandSize
- CPane [MFC], GetAvailableStretchSize
- CPane [MFC], GetBorders
- CPane [MFC], GetClientHotSpot
- CPane [MFC], GetDockSiteRow
- CPane [MFC], GetExclusiveRowMode
- CPane [MFC], GetHotSpot
- CPane [MFC], GetMinSize
- CPane [MFC], GetPaneName
- CPane [MFC], GetVirtualRect
- CPane [MFC], IsChangeState
- CPane [MFC], IsDragMode
- CPane [MFC], IsInFloatingMultiPaneFrameWnd
- CPane [MFC], IsLeftOf
- CPane [MFC], IsResizable
- CPane [MFC], IsTabbed
- CPane [MFC], LoadState
- CPane [MFC], MoveByAlignment
- CPane [MFC], MovePane
- CPane [MFC], OnAfterChangeParent
- CPane [MFC], OnBeforeChangeParent
- CPane [MFC], OnPressCloseButton
- CPane [MFC], OnShowControlBarMenu
- CPane [MFC], OnShowControlBarMenu
- CPane [MFC], RecalcLayout
- CPane [MFC], SaveState
- CPane [MFC], SetActiveInGroup
- CPane [MFC], SetBorders
- CPane [MFC], SetClientHotSpot
- CPane [MFC], SetDockState
- CPane [MFC], SetExclusiveRowMode
- CPane [MFC], SetMiniFrameRTC
- CPane [MFC], SetMinSize
- CPane [MFC], SetVirtualRect
- CPane [MFC], StretchPaneDeferWndPos
- CPane [MFC], ToggleAutoHide
- CPane [MFC], UndockPane
- CPane [MFC], UpdateVirtualRect
- CPane [MFC], OnAfterDock
- CPane [MFC], OnAfterFloat
- CPane [MFC], OnBeforeDock
- CPane [MFC], OnBeforeFloat
- CPane [MFC], m_bHandleMinSize
- CPane [MFC], m_recentDockInfo
ms.assetid: 5c651a64-3c79-4d94-9676-45f6402a6bc5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5b764777f33b0ae8ea1521e931ee45740f7057ef
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33378435"
---
# <a name="cpane-class"></a>Classe CPane
O `CPane` classe é um aprimoramento do [classe CControlBar](../../mfc/reference/ccontrolbar-class.md). Se você estiver atualizando um projeto MFC existente, substitua todas as ocorrências de `CControlBar` com `CPane`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPane : public CBasePane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CPane::~CPane`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPane::AdjustSizeImmediate](#adjustsizeimmediate)|Recalcula o layout de um painel imediatamente.|  
|[CPane::AllocElements](#allocelements)|Aloca armazenamento para uso interno.|  
|[CPane::AllowShowOnPaneMenu](#allowshowonpanemenu)|Especifica se o painel é listado na lista gerados pelo tempo de execução de painéis para o aplicativo.|  
|[CPane::CalcAvailableSize](#calcavailablesize)|Calcula a diferença no tamanho entre um retângulo especificado e o retângulo da janela atual.|  
|[CPane::CalcInsideRect](#calcinsiderect)|Calcula o interior retângulo de um painel, levando em conta as bordas e as garras.|  
|[CPane::CalcRecentDockedRect](#calcrecentdockedrect)|Calcula o retângulo recentemente encaixado.|  
|[CPane::CalcSize](#calcsize)|Calcula o tamanho do painel.|  
|[CPane::CanBeDocked](#canbedocked)|Determina se o painel pode ser encaixado no painel de base especificado.|  
|[CPane::CanBeTabbedDocument](#canbetabbeddocument)|Determina se o painel pode ser convertido em um documento com guias.|  
|[CPane::ConvertToTabbedDocument](#converttotabbeddocument)|Converte um painel encaixável em um documento com guias.|  
|[CPane::CopyState](#copystate)|Copia o estado de um painel. (Substitui [CBasePane::CopyState](../../mfc/reference/cbasepane-class.md#copystate).)|  
|[CPane::Create](#create)|Cria uma barra de controle e anexa-o para o `CPane` objeto.|  
|[CPane::CreateDefaultMiniframe](#createdefaultminiframe)|Cria uma janela do quadro simplificado para um painel flutuante.|  
|[CPane::CreateEx](#createex)|Cria uma barra de controle e anexa-o para o `CPane` objeto.|  
|`CPane::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CPane::DockByMouse](#dockbymouse)|Encaixa um painel usando o método de encaixe de mouse.|  
|[CPane::DockPane](#dockpane)|Encaixa o painel flutuante para um painel de base.|  
|[CPane::DockPaneStandard](#dockpanestandard)|Encaixa um painel usando a estrutura de tópicos de encaixe (padrão).|  
|[CPane::DockToFrameWindow](#docktoframewindow)|Encaixa um painel encaixável a um quadro. (Substitui `CBasePane::DockToFrameWindow`.)|  
|[CPane::DoesAllowSiblingBars](#doesallowsiblingbars)|Indica se você pode encaixar o painel outra na mesma linha em que o painel atual está encaixado.|  
|[CPane::FloatPane](#floatpane)|Flutua o painel.|  
|[CPane::GetAvailableExpandSize](#getavailableexpandsize)|Retorna a quantidade, em pixels, que pode expandir o painel.|  
|[CPane::GetAvailableStretchSize](#getavailablestretchsize)|Retorna a quantidade, em pixels, que pode reduzir o painel.|  
|[CPane::GetBorders](#getborders)|Retorna a largura das bordas do painel.|  
|[CPane::GetClientHotSpot](#getclienthotspot)|Retorna o *ponto de acesso* para o painel.|  
|[CPane::GetDockSiteRow](#getdocksiterow)|Retorna a linha de encaixe em que o painel está encaixado.|  
|[CPane::GetExclusiveRowMode](#getexclusiverowmode)|Determina se o painel está no modo de linha exclusivo.|  
|[CPane::GetHotSpot](#gethotspot)|Retorna o ponto de acesso que é armazenado em uma base `CMFCDragFrameImpl` objeto.|  
|[CPane::GetMinSize](#getminsize)|Recupera o mínimo permitido de tamanho para o painel.|  
|[CPane::GetPaneName](#getpanename)|Recupera o título do painel.|  
|`CPane::GetResizeStep`|Usado internamente.|  
|`CPane::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CPane::GetVirtualRect](#getvirtualrect)|Recupera o *virtual retângulo* do painel.|  
|[CPane::IsChangeState](#ischangestate)|Como o painel está sendo movido, esse método analisa a posição do painel em relação a outros painéis, linhas de encaixe e janelas com moldura simplificado e retorna apropriada `AFX_CS_STATUS` valor.|  
|[CPane::IsDragMode](#isdragmode)|Especifica se o painel estiver sendo arrastado.|  
|[CPane::IsInFloatingMultiPaneFrameWnd](#isinfloatingmultipaneframewnd)|Especifica se o painel estiver em uma janela do quadro de vários painéis. (Substitui `CBasePane::IsInFloatingMultiPaneFrameWnd`.)|  
|[CPane::IsLeftOf](#isleftof)|Determina se o painel à esquerda do (ou superior) o retângulo especificado.|  
|[CPane::IsResizable](#isresizable)|Determina se o painel pode ser redimensionado. (Substitui [CBasePane::IsResizable](../../mfc/reference/cbasepane-class.md#isresizable).)|  
|[CPane::IsTabbed](#istabbed)|Determina se o painel foi inserido no controle de guia de uma janela com guias. (Substitui [CBasePane::IsTabbed](../../mfc/reference/cbasepane-class.md#istabbed).)|  
|[CPane::LoadState](#loadstate)|Carrega o estado do painel do registro. (Substitui [CBasePane::LoadState](../../mfc/reference/cbasepane-class.md#loadstate).)|  
|[CPane::MoveByAlignment](#movebyalignment)|Move o painel e o retângulo virtual pelo valor especificado.|  
|[CPane::MovePane](#movepane)|Move o painel para o retângulo especificado.|  
|[CPane::OnAfterChangeParent](#onafterchangeparent)|Chamado pelo framework quando o pai de um painel é alterado.|  
|[CPane::OnBeforeChangeParent](#onbeforechangeparent)|Chamado pelo framework quando o pai do painel está prestes a alterar.|  
|[CPane::OnPressCloseButton](#onpressclosebutton)|Chamado pelo framework quando o usuário escolhe o botão Fechar na legenda para o painel.|  
|`CPane::OnProcessDblClk`|Usado internamente.|  
|[CPane::OnShowControlBarMenu](#onshowcontrolbarmenu)|Chamado pelo framework quando um menu de painel especial está prestes a ser exibido.|  
|[CPane::OnShowControlBarMenu](#onshowcontrolbarmenu)|Chamado pelo framework quando um menu de painel especial está prestes a ser exibido.|  
|`CPane::PrepareToDock`|Usado internamente.|  
|[CPane::RecalcLayout](#recalclayout)|Recalcula as informações de layout para o painel. (Substitui [CBasePane::RecalcLayout](../../mfc/reference/cbasepane-class.md#recalclayout).)|  
|[CPane::SaveState](#savestate)|Salva o estado do painel no registro. (Substitui [CBasePane::SaveState](../../mfc/reference/cbasepane-class.md#savestate).)|  
|[CPane::SetActiveInGroup](#setactiveingroup)|Sinalizadores de um painel como ativo.|  
|[CPane::SetBorders](#setborders)|Define os valores de borda do painel.|  
|[CPane::SetClientHotSpot](#setclienthotspot)|Define o ponto de acesso para o painel.|  
|[CPane::SetDockState](#setdockstate)|Restaura as informações de estado para o painel de encaixe.|  
|[CPane::SetExclusiveRowMode](#setexclusiverowmode)|Habilita ou desabilita o modo de linha exclusivo.|  
|[CPane::SetMiniFrameRTC](#setminiframertc)|Define as informações de classe de tempo de execução para a janela do minipadrão quadro.|  
|[CPane::SetMinSize](#setminsize)|Define o mínimo permitido de tamanho para o painel.|  
|[CPane::SetVirtualRect](#setvirtualrect)|Conjuntos de *virtual retângulo* do painel.|  
|[CPane::StretchPaneDeferWndPos](#stretchpanedeferwndpos)|Expande o painel vertical ou horizontalmente com base no estilo de encaixe.|  
|[CPane::ToggleAutoHide](#toggleautohide)|Modo de ocultar automaticamente alterna.|  
|[CPane::UndockPane](#undockpane)|Remove o painel do local de encaixe, controle deslizante do padrão ou janela do quadro mini onde ela estiver encaixada. (Substitui [CBasePane::UndockPane](../../mfc/reference/cbasepane-class.md#undockpane).)|  
|[CPane::UpdateVirtualRect](#updatevirtualrect)|Atualiza o retângulo virtual.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPane::OnAfterDock](#onafterdock)|Chamado pelo framework quando um painel foi encaixado.|  
|[CPane::OnAfterFloat](#onafterfloat)|Chamado pelo framework quando um painel foram flutuante.|  
|[CPane::OnBeforeDock](#onbeforedock)|Chamado pelo framework quando o painel está prestes a ser encaixado.|  
|[CPane::OnBeforeFloat](#onbeforefloat)|Chamado pelo framework quando um painel está prestes a ser flutuante.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPane::m_bHandleMinSize](#m_bhandleminsize)|Permite tratamento consistente do tamanho mínimo de painéis.|  
|[CPane::m_recentDockInfo](#m_recentdockinfo)|Contém informações recentes de encaixe.|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, `CPane` objetos não serão instanciados diretamente. Se você precisar de um painel que possui funcionalidade de encaixe, derivar seu objeto de [CDockablePane](../../mfc/reference/cdockablepane-class.md). Se você precisar de funcionalidade de barra de ferramentas, derivar seu objeto de [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).  
  
 Quando você derivar uma classe de `CPane`, ela pode ser encaixada em um [CDockSite](../../mfc/reference/cdocksite-class.md) e ele pode ser flutuante em um [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxPane.h  
  
##  <a name="adjustsizeimmediate"></a>  CPane::AdjustSizeImmediate  
 Recalcula o layout de um painel imediatamente.  
  
```  
virtual void AdjustSizeImmediate(BOOL bRecalcLayout = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bRecalcLayout`  
 `TRUE` para recalcular automaticamente o layout do painel. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame este método quando você alterar dinamicamente o layout de um painel. Por exemplo, você talvez queira chamar este método quando você ocultar ou Mostrar botões de barra de ferramentas.  
  
##  <a name="allocelements"></a>  CPane::AllocElements  
 Aloca armazenamento para uso interno.  
  
```  
BOOL AllocElements(
    int nElements,  
    int cbElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nElements`  
 O número de elementos para os quais a alocação do armazenamento.  
  
 [in] `cbElement`  
 O tamanho, em bytes, de um elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 `FALSE` Se a falha na alocação de memória; Caso contrário, `TRUE`.  
  
##  <a name="allowshowonpanemenu"></a>  CPane::AllowShowOnPaneMenu  
 Especifica se o painel é listado na lista gerados pelo tempo de execução de painéis para o aplicativo.  
  
```  
virtual BOOL AllowShowOnPaneMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel é exibido na lista; Caso contrário, `FALSE`. A implementação base sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo AppWizard gerado contém uma opção de menu que lista os painéis que ele contém. Este método determina se o painel é exibido na lista.  
  
##  <a name="calcavailablesize"></a>  CPane::CalcAvailableSize  
 Calcula a diferença no tamanho entre um retângulo especificado e o retângulo da janela atual.  
  
```  
virtual CSize CalcAvailableSize(CRect rectRequired);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectRequired`  
 O retângulo necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 A diferença em largura e altura entre `rectRequired` e o retângulo da janela atual.  
  
##  <a name="calcinsiderect"></a>  CPane::CalcInsideRect  
 Calcula o interior retângulo de um painel, incluindo as bordas e as garras.  
  
```  
void CalcInsideRect(
    CRect& rect,  
    BOOL bHorz) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rect`  
 Contém o tamanho e o deslocamento da área cliente do painel.  
  
 [in] `bHorz`  
 `TRUE` Se o painel é orientado horizontal; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando ele terá de recalcular o layout de um painel. O `rect` parâmetro é preenchido com o tamanho e o deslocamento da área cliente do painel. Isso inclui suas bordas e as garras.  
  
##  <a name="calcrecentdockedrect"></a>  CPane::CalcRecentDockedRect  
 Calcula o retângulo recentemente encaixado.  
  
```  
void CalcRecentDockedRect();
```  
  
### <a name="remarks"></a>Comentários  
 Este método atualizará [CPane::m_recentDockInfo](#m_recentdockinfo).  
  
##  <a name="calcsize"></a>  CPane::CalcSize  
 Calcula o tamanho do painel.  
  
```  
virtual CSize CalcSize(BOOL bVertDock);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bVertDock`  
 `TRUE` Se o painel está sendo encaixado verticalmente, `FALSE` caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão desse método retorna um tamanho de (0, 0).  
  
### <a name="remarks"></a>Comentários  
 Classes derivadas devem substituir este método.  
  
##  <a name="canbedocked"></a>  CPane::CanBeDocked  
 Determina se o painel pode ser encaixado no painel de base especificado.  
  
```  
virtual BOOL CanBeDocked(CBasePane* pDockBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockBar`  
 Especifica o painel em que este painel é encaixado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse painel pode ser encaixado no painel de encaixe especificado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Geralmente, esse método é chamado pelo framework para determinar se um painel pode ser encaixado no painel de encaixe especificado. Para determinar que se o painel pode ser encaixado, o método avalia o painel atualmente habilitado alinhamento de encaixe.  
  
 Ativar o encaixe para os vários lados da janela do quadro chamando [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).  
  
##  <a name="canbetabbeddocument"></a>  CPane::CanBeTabbedDocument  
 Determina se o painel pode ser convertido em um documento com guias.  
  
```  
virtual BOOL CanBeTabbedDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser convertido em um documento com guias. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada e retornar `FALSE` se você quiser impedir que um painel que está sendo convertido em um documento com guias. Um documento com guias não será listado no menu de posição da janela.  
  
##  <a name="converttotabbeddocument"></a>  CPane::ConvertToTabbedDocument  
 Converte um painel encaixável em um documento com guias.  
  
```  
virtual void ConvertToTabbedDocument(BOOL bActiveTabOnly = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bActiveTabOnly`  
 Não é usado no `CPane::ConvertToTabbedDocument`.  
  
### <a name="remarks"></a>Comentários  
 Somente os painéis encaixáveis podem ser convertidos em documentos com guias. Para obter informações, consulte [CDockablePane::ConvertToTabbedDocument](../../mfc/reference/cdockablepane-class.md#converttotabbeddocument).  
  
##  <a name="copystate"></a>  CPane::CopyState  
 Copia o estado de um painel.  
  
```  
virtual void CopyState(CPane* pOrgBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pOrgBar`  
 Um ponteiro para um painel.  
  
### <a name="remarks"></a>Comentários  
 Esse método copia o estado do `pOrgBar` para o painel atual.  
  
##  <a name="create"></a>  CPane::Create  
 Cria uma barra de controle e anexa-o para o [CPane](../../mfc/reference/cpane-class.md) objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszClassName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    DWORD dwControlBarStyle = AFX_DEFAULT_PANE_STYLE,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszClassName`  
 Especifica o nome da classe Windows.  
  
 [in] `dwStyle`  
 Especifica os atributos de estilo de janela. Para obter mais informações, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
 [in] `rect`  
 Especifica o tamanho inicial e a posição do `pParentWnd` janela, nas coordenadas do cliente.  
  
 [in] [out] `pParentWnd`  
 Especifica a janela pai deste painel.  
  
 [in] `nID`  
 Especifica a ID do painel.  
  
 [in] `dwControlBarStyle`  
 Especifica o estilo para o painel. Para obter mais informações, consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).  
  
 [in] [out] `pContext`  
 Especifica o contexto de criação do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria um painel do Windows e anexa-o para o `CPane` objeto.  
  
 Se você não tiver inicializado explicitamente [CPane::m_recentDockInfo](#m_recentdockinfo) antes de chamar `Create`, o parâmetro `rect` será usado como o retângulo quando flutuante ou encaixar o painel.  
  
##  <a name="createdefaultminiframe"></a>  CPane::CreateDefaultMiniframe  
 Cria uma janela do quadro simplificado para um painel flutuante.  
  
```  
virtual CPaneFrameWnd* CreateDefaultMiniframe(CRect rectInitial);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectInitial`  
 Especifica o tamanho inicial e a posição, em coordenadas de tela da janela do quadro simplificado para criar.  
  
### <a name="return-value"></a>Valor de retorno  
 A janela do mini-quadro de recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pelo framework para criar uma janela do miniquando quadro um painel é flutuante. A janela do minipode quadro ser do tipo [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) ou de tipo [CMultiPaneFrameWnd](../../mfc/reference/cmultipaneframewnd-class.md). Uma janela com minivárias moldura será criada se o painel tem o `AFX_CBRS_FLOAT_MULTI` estilo.  
  
 As informações de classe de tempo de execução para a janela do quadro mini são armazenadas no `CPane::m_pMiniFrameRTC` membro. Você pode usar uma classe derivada para definir esse membro, se você optar por criar janelas de minipersonalizado quadro.  
  
##  <a name="createex"></a>  CPane::CreateEx  
 Cria uma barra de controle e anexa-o para o [CPane](../../mfc/reference/cpane-class.md) objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwStyleEx,  
    LPCTSTR lpszClassName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    DWORD dwControlBarStyle = AFX_DEFAULT_PANE_STYLE,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwStyleEx`  
 Especifica os atributos de estilo de janela estendidos. Para obter mais informações, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).  
  
 [in] `lpszClassName`  
 Especifica o nome da classe Windows.  
  
 [in] `dwStyle`  
 Especifica os atributos de estilo de janela. Para obter mais informações, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
 [in] `rect`  
 Especifica o tamanho inicial e a posição do `pParentWnd` janela, nas coordenadas do cliente.  
  
 [in] [out] `pParentWnd`  
 Especifica a janela pai deste painel.  
  
 [in] `nID`  
 Especifica a ID do painel.  
  
 [in] `dwControlBarStyle`  
 Especifica o estilo para o painel. Para obter mais informações, consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).  
  
 [in] [out] `pContext`  
 Especifica o contexto de criação para o painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria um painel do Windows e anexa-o para o `CPane` objeto.  
  
 Se você não tiver inicializado explicitamente [CPane::m_recentDockInfo](#m_recentdockinfo) antes de chamar `CreateEx`, o parâmetro `rect` será usado como o retângulo quando flutuante ou encaixar o painel.  
  
##  <a name="dockbymouse"></a>  CPane::DockByMouse  
 Encaixa um painel usando o mouse.  
  
```  
virtual BOOL DockByMouse(CBasePane* pDockBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockBar`  
 Especifica o painel de base ao qual se encaixar nesse painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi encaixado com êxito; Caso contrário, `FALSE`.  
  
##  <a name="dockpane"></a>  CPane::DockPane  
 Encaixa o painel flutuante para um painel de base.  
  
```  
virtual BOOL DockPane(
    CBasePane* pDockBar,  
    LPCRECT lpRect,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out] `pDockBar`  
 Especifica o painel de base para encaixar nesse painel para.  
  
 [in] `lpRect`  
 Especifica o retângulo no painel de base onde o este painel está encaixado.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe para usar. As opções disponíveis são as seguintes:  
  
|Opção|Descrição|  
|------------|-----------------|  
|`DM_UNKNOWN`|A estrutura usa esta opção quando o método de encaixe é desconhecido. O painel não armazena sua posição flutuante mais recente. Você também pode usar essa opção para encaixar programaticamente um painel, quando você não precisa armazenar a posição flutuante recente.|  
|`DM_MOUSE`|Usado internamente.|  
|`DM_DBL_CLICK`|Essa opção é usada quando garra é clicado duas vezes. O painel é reposicionado na sua posição de encaixe mais recente. Se o painel é desencaixado clicando duas vezes, o painel é reposicionado na sua posição flutuante mais recente.|  
|`DM_SHOW`|Essa opção pode ser usada para programaticamente encaixar o painel. O painel armazena sua posição flutuante mais recente.|  
|`DM_RECT`|O painel está encaixado na região especificada pelo `lpRect`.|  
|`DM_STANDARD`|Quando você usar essa opção, a estrutura desenha painel como um quadro de estrutura de tópicos enquanto ele é movido.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi encaixado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método encaixa o painel ao painel de base que é especificado pelo `pDockBar` parâmetro. Você deve primeiro habilitar encaixe chamando [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).  
  
##  <a name="dockpanestandard"></a>  CPane::DockPaneStandard  
 Encaixa um painel usando a estrutura de tópicos de encaixe (padrão).  
  
```  
virtual CPane* DockPaneStandard(BOOL& bWasDocked);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bWasDocked`  
 `TRUE` Se o painel foi encaixado com êxito; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método sempre retornará o `this` ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado apenas para painéis que derivam de [CDockablePane classe](../../mfc/reference/cdockablepane-class.md). Para obter mais informações, consulte [CDockablePane::DockPaneStandard](../../mfc/reference/cdockablepane-class.md#dockpanestandard).  
  
##  <a name="docktoframewindow"></a>  CPane::DockToFrameWindow  
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
 O tamanho especificado.  
  
 [in] `dwDockFlags`  
 Ignorado.  
  
 [in] `pRelativeBar`  
 Ignorado.  
  
 [in] `nRelativeIndex`  
 Ignorado.  
  
 [in] `bOuterEdge`  
 Se `TRUE` e há outros painéis encaixáveis no lado que são especificados pelo `dwAlignment`, o painel estiver encaixado fora os painéis, a borda do quadro pai mais próximo. Se `FALSE`, o painel está encaixado aproximando-se para o centro da área do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 `FALSE` Se um divisor de painel ( [CPaneDivider classe](../../mfc/reference/cpanedivider-class.md)) não pode ser criado; caso contrário, `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="doesallowsiblingbars"></a>  CPane::DoesAllowSiblingBars  
 Indica se você pode encaixar o painel outra na mesma linha em que o painel atual está encaixado.  
  
```  
virtual BOOL DoesAllowSiblingBars() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse painel pode encaixar outro painel na mesma linha como em si; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode habilitar ou desabilitar esse comportamento chamando [CPane::SetExclusiveRowMode](#setexclusiverowmode).  
  
 Por padrão, as barras de ferramentas tem desabilitado de modo de linha exclusivo e a barra de menus com o modo de linha exclusivos habilitado.  
  
##  <a name="floatpane"></a>  CPane::FloatPane  
 Flutua o painel.  
  
```  
virtual BOOL FloatPane(
    CRect rectFloat,  
    AFX_DOCK_METHOD dockMethod = DM_UNKNOWN,  
    bool bShow = true);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectFloat`  
 Especifica o local, em coordenadas da tela, para posicionar o painel quando ele é flutuante.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe para usar quando o painel é flutuante. Para obter uma lista de valores possíveis, consulte [CPane::DockPane](#dockpane).  
  
 [in] `bShow`  
 `TRUE` para mostrar o painel quando flutuante; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel foi flutuante com êxito ou se o painel não pode ser flutuante porque [CBasePane::CanFloat](../../mfc/reference/cbasepane-class.md#canfloat) retorna `FALSE`; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para desencaixar o painel na posição especificada pelo `rectFloat` parâmetro. Esse método cria automaticamente uma janela com minipai moldura para o painel.  
  
##  <a name="getavailableexpandsize"></a>  CPane::GetAvailableExpandSize  
 Retorna a quantidade, em pixels, que pode expandir o painel.  
  
```  
virtual int GetAvailableExpandSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o painel está encaixado na horizontal, o valor de retorno é a largura disponível; Caso contrário, o valor de retorno é a altura disponível.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getavailablestretchsize"></a>  CPane::GetAvailableStretchSize  
 Retorna a quantidade, em pixels, que pode reduzir o painel.  
  
```  
virtual int GetAvailableStretchSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A quantidade, em pixels, que pode reduzir o painel. Se o painel está encaixado na horizontal, esse valor é a largura disponível; Caso contrário, é a altura disponível.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de ampliação disponível é calculado subtraindo o mínimo permitido de tamanho para o painel ( [CPane::GetMinSize](#getminsize)) do tamanho atual ( [CWnd::GetWindowRect](../../mfc/reference/cwnd-class.md#getwindowrect)).  
  
##  <a name="getborders"></a>  CPane::GetBorders  
 Retorna a largura das bordas do painel.  
  
```  
CRect GetBorders() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém a largura atual, em pixels, de cada lado do painel. Por exemplo, o valor da `left` membro do `CRect` objeto é a largura da borda esquerda.  
  
### <a name="remarks"></a>Comentários  
 Para definir o tamanho das bordas, chame [CPane::SetBorders](#setborders).  
  
##  <a name="getclienthotspot"></a>  CPane::GetClientHotSpot  
 Retorna o *ponto de acesso* para o painel.  
  
```  
CPoint GetClientHotSpot() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 O *ponto de acesso* é o ponto no painel de que o usuário seleciona e mantém para mover o painel. Um ponto de acesso é usado para animação suave quando o painel é movido de uma posição ancorada.  
  
##  <a name="getdocksiterow"></a>  CPane::GetDockSiteRow  
 Retorna a linha de encaixe ( [CDockingPanesRow classe](../../mfc/reference/cdockingpanesrow-class.md)) em que o painel está encaixado.  
  
```  
CDockingPanesRow* GetDockSiteRow() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CDockingPanesRow`* que aponta para a linha de encaixe em que o painel está encaixado, ou `NULL` se o painel não está encaixado.  
  
##  <a name="getexclusiverowmode"></a>  CPane::GetExclusiveRowMode  
 Determina se o painel está no modo de linha exclusivo.  
  
```  
virtual BOOL GetExclusiveRowMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel estiver no modo de linha exclusivo. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre o modo de linha exclusivos, consulte [CPane::SetExclusiveRowMode](#setexclusiverowmode).  
  
##  <a name="gethotspot"></a>  CPane::GetHotSpot  
 Retorna o ponto de acesso que é armazenado em uma base `CMFCDragFrameImpl` objeto.  
  
```  
CPoint GetHotSpot() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 O `CPane` classe contém um `CMFCDragFrameImpl` objeto, `m_dragFrameImpl`, que é responsável por desenhar um retângulo que é exibida quando o usuário move um painel no modo de encaixe padrão. O ponto de acesso é usado para desenhar o retângulo em relação à posição atual do mouse, como o usuário move o painel.  
  
##  <a name="getminsize"></a>  CPane::GetMinSize  
 Recupera o mínimo permitido de tamanho para o painel.  
  
```  
virtual void GetMinSize(CSize& size) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `size`  
 Um `CSize` objeto que é preenchido com o mínimo permitido de tamanho.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpanename"></a>  CPane::GetPaneName  
 Recupera o título do painel.  
  
```  
virtual void GetPaneName(CString& strName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `strName`  
 Um `CString` objeto que é preenchido com o nome da legenda.  
  
### <a name="remarks"></a>Comentários  
 O título do painel é exibido na área de legenda quando o painel está encaixado ou flutuante. Se o painel for parte de um grupo com guias, o título é exibido na área da guia. Se o painel estiver no modo de ocultar automaticamente, o título é exibido em um `CMFCAutoHideButton`.  
  
##  <a name="getvirtualrect"></a>  CPane::GetVirtualRect  
 Recupera o *virtual retângulo* do painel.  
  
```  
void GetVirtualRect(CRect& rectVirtual) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectVirtual`  
 Um `CRect` objeto que é preenchido com o retângulo virtual.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel é movido, o framework armazena a posição original do painel em um retângulo virtual. A estrutura pode usar o retângulo virtual para restaurar a posição original do painel.  
  
 Não chame métodos relacionados a retângulos virtuais, a menos que você está movendo painéis programaticamente.  
  
##  <a name="ischangestate"></a>  CPane::IsChangeState  
 Como o painel está sendo movido, esse método analisa sua posição em relação a outros painéis, linhas de encaixe e janelas com moldura simplificado e retorna apropriada `AFX_CS_STATUS` valor.  
  
```  
virtual AFX_CS_STATUS IsChangeState(
    int nOffset,  
    CBasePane** ppTargetBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 Especifica diferenciação de encaixe. Por exemplo, um painel que é movido dentro `nOffset` pixels a partir de uma linha de encaixe serão encaixados.  
  
 [in] `ppTargetBar`  
 Quando o método retorna, `ppTargetBar` contém um ponteiro para o objeto ao qual o painel atual deve ser encaixado, ou `NULL` se nenhum encaixe deve ocorrer.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores `AFX_CS_STATUS`:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`CS_NOTHING`|O painel não estiver perto de um site de encaixe. A estrutura não encaixar o painel.|  
|`CS_DOCK_IMMEDIATELY`|O painel estiver em um site de encaixe e o `DT_IMMEDIATE` estilo está habilitado. A estrutura encaixa painel imediatamente.|  
|`CS_DELAY_DOCK`|O painel está em um site de encaixe outro painel de encaixe ou uma borda do quadro principal. A estrutura encaixa painel quando o usuário libera a movimentação.|  
|`CS_DELAY_DOCK_TO_TAB`|O painel está em um site de encaixe que faz com que o painel para ser encaixada em uma janela com guias. Isso ocorre quando o painel está sobre a legenda de outro painel de encaixe ou sobre a área da guia de um painel com guias. A estrutura encaixa painel quando o usuário libera a movimentação.|  
  
##  <a name="isdragmode"></a>  CPane::IsDragMode  
 Especifica se o painel está sendo movido.  
  
```  
virtual BOOL IsDragMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel está sendo movido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isinfloatingmultipaneframewnd"></a>  CPane::IsInFloatingMultiPaneFrameWnd  
 Especifica se o painel estiver em uma janela do quadro de vários painéis ( [CMultiPaneFrameWnd classe](../../mfc/reference/cmultipaneframewnd-class.md)).  
  
```  
virtual BOOL IsInFloatingMultiPaneFrameWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel estiver em uma janela do quadro de vários painéis; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Somente os painéis encaixáveis podem flutuar em uma janela do quadro de vários painéis. Portanto, `CPane::IsInFloatingMultiPaneFrameWnd` sempre retorna `FALSE`.  
  
##  <a name="isleftof"></a>  CPane::IsLeftOf  
 Determina se o painel à esquerda do (ou superior) o retângulo especificado.  
  
```  
bool IsLeftOf(
    CRect rect,  
    bool bWindowRect = true) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rect`  
 Um `CRect` objeto que será usado para comparação.  
  
 [in] `bWindowRect`  
 Se `TRUE`, `rect` devem para conter as coordenadas da tela; se `FALSE`, `rect` devem para conter as coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Se o painel está encaixado na horizontal, esse método verifica se o seu local é deixado de `rect`. Caso contrário, esse método verifica se o local está acima `rect`.  
  
##  <a name="isresizable"></a>  CPane::IsResizable  
 Especifica se o painel é redimensionável.  
  
```  
virtual BOOL IsResizable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel é redimensionável; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Base `CPane` objetos não são redimensionáveis.  
  
 O Gerenciador de encaixe usa o sinalizador redimensionável para determinar o layout do painel. Painéis não redimensionável sempre estão localizados nas bordas externas do quadro pai.  
  
 Painéis não redimensionável não podem residir em contêineres de encaixe.  
  
##  <a name="istabbed"></a>  CPane::IsTabbed  
 Determina se o painel foi inserido no controle de guia de uma janela com guias.  
  
```  
virtual BOOL IsTabbed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel está com guias; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O estado com guias é tratado separadamente do flutuante, encaixado e estados de ocultar automaticamente.  
  
##  <a name="loadstate"></a>  CPane::LoadState  
 Carrega o estado do painel do registro.  
  
```  
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,  
    int nIndex = -1,  
    UINT uiID = (UINT) -1);
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
 O framework chama esse método para carregar o estado do painel do registro. Substituí-la em uma classe derivada para carregar informações adicionais que é salvas, [CPane::SaveState](#savestate).  
  
 Quando você substituir esse método, também chamar o método base e retornar `FALSE` se o método base retorna `FALSE`.  
  
##  <a name="m_bhandleminsize"></a>  CPane::m_bHandleMinSize  
 Permite tratamento consistente de tamanhos mínimo do painel.  
  
```  
AFX_IMPORT_DATA static BOOL m_bHandleMinSize;  
```  
  
### <a name="remarks"></a>Comentários  
 Se substituem um ou mais painéis de encaixe em seu aplicativo `GetMinSize`, ou se o aplicativo chama `SetMinSize`, você talvez queira definir este membro estático `TRUE` para permitir que a estrutura consistentemente manipular como os painéis são dimensionados.  
  
 Se esse valor é definido como `TRUE`, cujo tamanho deve ser reduzido abaixo de seu tamanho mínimo de todos os painéis são cortados não estendida. Como o framework usa regiões de janela para fins de dimensionamento do painel, não altere o tamanho da região de janela de encaixe painéis se esse valor é definido como `TRUE`.  
  
##  <a name="m_recentdockinfo"></a>  CPane::m_recentDockInfo  
 Contém informações recentes de encaixe.  
  
```  
CRecentDockSiteInfo m_recentDockInfo;  
```  
  
### <a name="remarks"></a>Comentários  
 O framework armazena as informações de estado mais recente de encaixe do painel nesse membro.  
  
##  <a name="movebyalignment"></a>  CPane::MoveByAlignment  
 Move o painel e o retângulo virtual pelo valor especificado.  
  
```  
BOOL MoveByAlignment(
    DWORD dwAlignment,  
    int nOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
 Especifica o alinhamento do painel.  
  
 [in] `nOffset`  
 A quantidade, em pixels, pela qual mover o painel e o retângulo virtual.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 `dwAlignment` pode ser qualquer um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`CBRS_ALIGN_TOP`|Permite que o painel para ser encaixado à parte superior da área cliente de uma janela do quadro.|  
|`CBRS_ALIGN_BOTTOM`|Permite que o painel para ser encaixado na parte inferior da área cliente de uma janela do quadro.|  
|`CBRS_ALIGN_LEFT`|Permite que o painel para ser encaixado à esquerda da área cliente de uma janela do quadro.|  
|`CBRS_ALIGN_RIGHT`|Permite que o painel encaixado à direita da área cliente de uma janela do quadro.|  
|`CBRS_ALIGN_ANY`|Permite que o painel ser encaixada para qualquer lado da área cliente de uma janela do quadro.|  
  
 Se `dwAlignment` contém o `CBRS_ALIGN_LEFT` ou `CBRS_ALIGN_RIGHT` sinalizador, o painel e retângulo virtual são movidos horizontalmente; caso contrário, se `dwAlignment` contém o `CBRS_ALIGN_TOP` ou `CBRS_ALIGN_BOTTOM` sinalizador, o painel e o retângulo virtual são movidos verticalmente.  
  
##  <a name="movepane"></a>  CPane::MovePane  
 Move o painel para o retângulo especificado.  
  
```  
virtual CSize MovePane(
    CRect rectNew,  
    BOOL bForceMove,  
    HDWP& hdwp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectNew`  
 Especifica o novo retângulo para o painel.  
  
 [in] `bForceMove`  
 Se `TRUE`, esse método ignora o tamanho mínimo permitido do painel ( [CPane::GetMinSize](#getminsize)); caso contrário, o painel é ajustado, se necessário, para garantir que ele seja pelo menos o mínimo permitido de tamanho.  
  
 [in] `hdwp`  
 Não usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que contém as diferenças em largura e altura entre os retângulos antigos e novos (antigo retângulo - `rectNew`).  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado apenas para painéis encaixáveis.  
  
##  <a name="onafterchangeparent"></a>  CPane::OnAfterChangeParent  
 Chamado pelo framework quando o pai de um painel é alterado.  
  
```  
virtual void OnAfterChangeParent(CWnd* pWndOldParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out] `pWndOldParent`  
 Janela de pai anterior do painel.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando o pai de um painel é alterado devido a uma operação de encaixe ou flutuante.  
  
##  <a name="onafterdock"></a>  CPane::OnAfterDock  
 Chamado pelo framework quando um painel foi encaixado.  
  
```  
virtual void OnAfterDock(
    CBasePane* pBar,  
    LPCRECT lpRect,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Este parâmetro não é usado.  
  
 [in] `lpRect`  
 Este parâmetro não é usado.  
  
 [in] `dockMethod`  
 Este parâmetro não é usado.  
  
##  <a name="onafterfloat"></a>  CPane::OnAfterFloat  
 Chamado pelo framework depois que um painel flutua.  
  
```  
virtual void OnAfterFloat();
```  
  
### <a name="remarks"></a>Comentários  
 Se você quiser executar qualquer processamento depois que um painel flutua, você pode substituir esse método em uma classe derivada.  
  
##  <a name="onbeforechangeparent"></a>  CPane::OnBeforeChangeParent  
 Chamado pelo framework quando o pai do painel está prestes a alterar.  
  
```  
virtual void OnBeforeChangeParent(
    CWnd* pWndNewParent,  
    BOOL bDelay = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out] `pWndNewParent`  
 Especifica a nova janela pai.  
  
 [in] `bDelay`  
 `TRUE` Para atrasar o ajuste de layout encaixe global; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando o pai do painel está prestes a ser alterada porque o painel está sendo encaixado ou flutuante.  
  
 Por padrão, o painel é cancelar o registro com o painel de encaixe chamando `CDockSite::RemovePane`.  
  
##  <a name="onbeforedock"></a>  CPane::OnBeforeDock  
 Chamado pelo framework quando o painel está prestes a encaixar.  
  
```  
virtual BOOL OnBeforeDock(
    CBasePane** ppDockBar,  
    LPCRECT lpRect,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out] `ppDockBar`  
 Especifica o painel que este painel é integrada ao.  
  
 [in] `lpRect`  
 Especifica o retângulo de encaixe.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser encaixado. Se a função retornar `FALSE`, a operação de encaixe será anulada.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando um painel está prestes a ser encaixado. Se você quiser executar qualquer processamento antes de um painel estiver encaixado Finalmente, você pode substituir esse método em uma classe derivada.  
  
##  <a name="onbeforefloat"></a>  CPane::OnBeforeFloat  
 Chamado pelo framework quando um painel está prestes a float.  
  
```  
virtual BOOL OnBeforeFloat(
    CRect& rectFloat,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectFloat`  
 Especifica a posição e o tamanho do painel quando ele está em um estado flutuante.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o painel pode ser flutuante; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando um painel está prestes a float. Se você quiser executar qualquer processamento antes de finalmente flutua o painel, você pode substituir esse método em uma classe derivada.  
  
##  <a name="onpressclosebutton"></a>  CPane::OnPressCloseButton  
 Chamado pelo framework quando o usuário pressiona o botão Fechar na legenda para o painel.  
  
```  
virtual void OnPressCloseButton();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo framework quando um usuário pressiona o **fechar** botão na legenda do painel. Para receber notificações sobre o **fechar** eventos, você pode substituir esse método em uma classe derivada.  
  
##  <a name="onshowcontrolbarmenu"></a>  CPane::OnShowControlBarMenu  
 Chamado pelo framework quando um menu de painel especial está prestes a ser exibido.  
  
```  
virtual BOOL OnShowControlBarMenu(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Especifica o local do menu.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o menu pode ser exibido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O menu contém vários itens que permitem especificar o comportamento do painel, ou seja: **flutuante**, **encaixe**, **AutoHide**, e **ocultar**. Você pode habilitar esse menu para todos os painéis chamando [CDockingManager::EnableDockSiteMenu](../../mfc/reference/cdockingmanager-class.md#enabledocksitemenu).  
  
##  <a name="recalclayout"></a>  CPane::RecalcLayout  
 Recalcula as informações de layout para o painel.  
  
```  
virtual void RecalcLayout();
```  
  
### <a name="remarks"></a>Comentários  
 Se o painel está encaixado, este método atualizará o retângulo virtual para o painel, definindo o tamanho para o tamanho atual do painel.  
  
 Se o painel estiver flutuando, este método notifica-quadro para ajustar o tamanho do painel para o tamanho do minimini quadro pai. A estrutura garante que o minipelo quadro menos é o mínimo permitido de tamanho para o painel ( [CPane::GetMinSize](#getminsize)) e redimensiona o quadro simplificado, se necessário.  
  
##  <a name="savestate"></a>  CPane::SaveState  
 Salva o estado do painel no registro.  
  
```  
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,  
    int nIndex = -1,  
    UINT uiID = (UINT) -1);
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
  
 Quando você substituir esse método, também chamar o método base e retornar `FALSE` se o método base retorna `FALSE`.  
  
##  <a name="setactiveingroup"></a>  CPane::SetActiveInGroup  
 Sinalizadores de um painel como ativo.  
  
```  
virtual void SetActiveInGroup(BOOL bActive);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bActive`  
 Um `BOOL` que especifica se o painel é sinalizado como ativa.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel encaixável é mostrado ou um botão Ocultar automaticamente é escolhido, o painel de ocultar automaticamente correspondente é marcado como ativo.  
  
 A aparência de um botão Ocultar automaticamente que está associado com o painel se baseia em dois fatores. Se o painel estiver ativo e o `static BOOL CMFCAutoHideButton::m_bOverlappingTabs` é `TRUE`, o framework exibe o botão Ocultar automaticamente como um ícone e um rótulo. Para um painel inativo, a estrutura exibe apenas o ícone de ocultar automaticamente.  
  
 Se `CMFCAutoHideButton::m_bOverlappingTabs` é `FALSE`, ou se o painel não está localizado em um grupo, o framework exibe o botão Ocultar automaticamente associado como um ícone e um rótulo.  
  
##  <a name="setborders"></a>  CPane::SetBorders  
 Define os valores de borda do painel.  
  
```  
void SetBorders(
    int cxLeft = 0,  
    int cyTop = 0,  
    int cxRight = 0,  
    int cyBottom = 0);  
  
void SetBorders(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `cxLeft`  
 Especifica a largura, em pixels, da borda esquerda do painel.  
  
 [in] `cyTop`  
 Especifica a largura, em pixels, da borda superior do painel.  
  
 [in] `cxRight`  
 Especifica a largura, em pixels, da borda direita do painel.  
  
 [in] `cyBottom`  
 Especifica a largura, em pixels, da borda inferior do painel.  
  
 [in] `lpRect`  
 Um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém a largura, em pixels, da cada borda do painel.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir os tamanhos das bordas do painel.  
  
##  <a name="setclienthotspot"></a>  CPane::SetClientHotSpot  
 Conjuntos de *ponto de acesso* para o painel.  
  
```  
void SetClientHotSpot(const CPoint& ptNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ptNew`  
 Um `CPoint` objeto que especifica o novo ponto de acesso.  
  
### <a name="remarks"></a>Comentários  
 O *ponto de acesso* é o ponto no painel de que o usuário seleciona e mantém para mover o painel. Um ponto de acesso é usado para animação suave quando o painel é arrastado de uma posição ancorada.  
  
##  <a name="setdockstate"></a>  CPane::SetDockState  
 Restaura as informações de estado para o painel de encaixe.  
  
```  
virtual void SetDockState(CDockingManager* pDockManager);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockManager`  
 Ponteiro para o Gerenciador de encaixe para a janela do quadro principal.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pelo framework para restaurar informações de estado de encaixe recentes para o painel. Um painel armazena informações de estado de encaixe recentes no [CPane::m_recentDockInfo](#m_recentdockinfo). Para obter mais informações, consulte o [CRecentDockSiteInfo classe](../../mfc/reference/crecentdocksiteinfo-class.md).  
  
 Você também pode chamar esse método para definir o estado de encaixe quando você carregar informações do painel de uma fonte externa.  
  
##  <a name="setexclusiverowmode"></a>  CPane::SetExclusiveRowMode  
 Habilita ou desabilita o modo de linha exclusivo.  
  
```  
virtual void SetExclusiveRowMode(BOOL bExclusive = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bExclusive`  
 `TRUE` Para habilitar o modo de linha exclusivos; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para habilitar ou desabilitar o modo de linha exclusivo. Quando um painel está no modo de linha exclusivos, ele não pode compartilhar a mesma linha com outras barras de ferramentas.  
  
 Por padrão, todas as barras de ferramentas tem o modo de linha exclusivos desabilitado e a barra de menus com o modo de linha exclusivos habilitado.  
  
##  <a name="setminsize"></a>  CPane::SetMinSize  
 Define o mínimo permitido de tamanho para o painel.  
  
```  
void SetMinSize(const CSize& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `size`  
 Um `CSize` objeto que contém o mínimo permitido de tamanho para o painel.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setvirtualrect"></a>  CPane::SetVirtualRect  
 Conjuntos de *virtual retângulo* do painel.  
  
```  
void SetVirtualRect(
    const CRect& rect,  
    BOOL bMapToParent = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rect`  
 Um `CRect` objeto que especifica o retângulo virtual a ser definido.  
  
 [in] `bMapToParent`  
 Especifique `TRUE` se `rect` contém pontos em relação a janela pai.  
  
### <a name="remarks"></a>Comentários  
 Um *virtual retângulo* armazena a posição original de um painel quando ele é movido. A estrutura pode usar o retângulo virtual para restaurar a posição original.  
  
 Não chame métodos relacionados a retângulos virtuais, a menos que você está movendo painéis programaticamente.  
  
##  <a name="setminiframertc"></a>  CPane::SetMiniFrameRTC  
 Define as informações de classe de tempo de execução para a janela do minipadrão quadro.  
  
```  
void SetMiniFrameRTC(CRuntimeClass* pClass);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out] `pClass`  
 Especifica as informações de classe de tempo de execução para a janela do quadro simplificado.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel é flutuante, ele é colocado uma [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) janela (miniquadro). Você pode fornecer um personalizado `CPaneFrameWnd`-derivada da classe que será usado quando [CPane::CreateDefaultMiniframe](#createdefaultminiframe) é chamado.  
  
##  <a name="stretchpanedeferwndpos"></a>  CPane::StretchPaneDeferWndPos  
 Expande o painel vertical ou horizontalmente com base no estilo de encaixe.  
  
```  
virtual int StretchPaneDeferWndPos(
    int nStretchSize,  
    HDWP& hdwp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nStretchSize`  
 A quantidade, em pixels, para ampliar o painel. Use um valor negativo para reduzir o painel.  
  
 [in] `hdwp`  
 Não usado.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor real, em pixels, que o painel foi ampliado.  
  
### <a name="remarks"></a>Comentários  
 Se necessário, esse método modifica `nStretchSize` para garantir que o painel não exceda os limites de tamanho. Esses limites são obtidos chamando [CPane::GetAvailableStretchSize](#getavailablestretchsize) e [CPane::GetAvailableExpandSize](#getavailableexpandsize).  
  
##  <a name="toggleautohide"></a>  CPane::ToggleAutoHide  
 Modo de ocultar automaticamente alterna.  
  
```  
virtual void ToggleAutoHide();
```  
  
### <a name="remarks"></a>Comentários  
 Chame este método para alternar o modo de ocultar automaticamente. Um painel deve estar encaixado para uma janela do quadro principal para alternar para o modo de ocultar automaticamente.  
  
##  <a name="undockpane"></a>  CPane::UndockPane  
 Remove o painel do local de encaixe, controle deslizante do padrão ou janela do quadro mini onde ela estiver encaixada.  
  
```  
virtual void UndockPane(BOOL bDelay = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDelay`  
 Se `FALSE`, a estrutura chama [CBasePane::AdjustDockingLayout](../../mfc/reference/cbasepane-class.md#adjustdockinglayout) para ajustar o layout de encaixe.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para desencaixar programaticamente um painel.  
  
##  <a name="updatevirtualrect"></a>  CPane::UpdateVirtualRect  
 Atualiza o retângulo virtual.  
  
```  
void UpdateVirtualRect();  
void UpdateVirtualRect(CPoint ptOffset);  
  void UpdateVirtualRect(CSize sizeNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ptOffset`  
 Um `CPoint` objeto que especifica um deslocamento pelo qual deslocar o painel.  
  
 [in] `sizeNew`  
 Um `CSize` objeto que especifica um novo tamanho para o painel.  
  
### <a name="remarks"></a>Comentários  
 A primeira sobrecarga define o retângulo virtual usando a posição atual e o tamanho do painel.  
  
 A segunda sobrecarga desloca o retângulo virtual a quantidade que é especificada pelo `ptOffset`.  
  
 A terceira sobrecarga define o retângulo virtual usando a posição atual do painel e o tamanho é especificado pelo `sizeNew`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CBasePane](../../mfc/reference/cbasepane-class.md)
