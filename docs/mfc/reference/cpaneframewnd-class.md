---
title: Classe CPaneFrameWnd | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPaneFrameWnd
- AFXPANEFRAMEWND/CPaneFrameWnd
- AFXPANEFRAMEWND/CPaneFrameWnd::AddPane
- AFXPANEFRAMEWND/CPaneFrameWnd::AddRemovePaneFromGlobalList
- AFXPANEFRAMEWND/CPaneFrameWnd::AdjustLayout
- AFXPANEFRAMEWND/CPaneFrameWnd::AdjustPaneFrames
- AFXPANEFRAMEWND/CPaneFrameWnd::CalcBorderSize
- AFXPANEFRAMEWND/CPaneFrameWnd::CalcExpectedDockedRect
- AFXPANEFRAMEWND/CPaneFrameWnd::CanBeAttached
- AFXPANEFRAMEWND/CPaneFrameWnd::CanBeDockedToPane
- AFXPANEFRAMEWND/CPaneFrameWnd::CheckGripperVisibility
- AFXPANEFRAMEWND/CPaneFrameWnd::ConvertToTabbedDocument
- AFXPANEFRAMEWND/CPaneFrameWnd::Create
- AFXPANEFRAMEWND/CPaneFrameWnd::CreateEx
- AFXPANEFRAMEWND/CPaneFrameWnd::DockPane
- AFXPANEFRAMEWND/CPaneFrameWnd::FindFloatingPaneByID
- AFXPANEFRAMEWND/CPaneFrameWnd::FrameFromPoint
- AFXPANEFRAMEWND/CPaneFrameWnd::GetCaptionHeight
- AFXPANEFRAMEWND/CPaneFrameWnd::GetCaptionRect
- AFXPANEFRAMEWND/CPaneFrameWnd::GetCaptionText
- AFXPANEFRAMEWND/CPaneFrameWnd::GetDockingManager
- AFXPANEFRAMEWND/CPaneFrameWnd::GetDockingMode
- AFXPANEFRAMEWND/CPaneFrameWnd::GetFirstVisiblePane
- AFXPANEFRAMEWND/CPaneFrameWnd::GetHotPoint
- AFXPANEFRAMEWND/CPaneFrameWnd::GetPane
- AFXPANEFRAMEWND/CPaneFrameWnd::GetPaneCount
- AFXPANEFRAMEWND/CPaneFrameWnd::GetParent
- AFXPANEFRAMEWND/CPaneFrameWnd::GetPinState
- AFXPANEFRAMEWND/CPaneFrameWnd::GetRecentFloatingRect
- AFXPANEFRAMEWND/CPaneFrameWnd::GetVisiblePaneCount
- AFXPANEFRAMEWND/CPaneFrameWnd::HitTest
- AFXPANEFRAMEWND/CPaneFrameWnd::IsCaptured
- AFXPANEFRAMEWND/CPaneFrameWnd::IsDelayShow
- AFXPANEFRAMEWND/CPaneFrameWnd::IsRollDown
- AFXPANEFRAMEWND/CPaneFrameWnd::IsRollUp
- AFXPANEFRAMEWND/CPaneFrameWnd::KillDockingTimer
- AFXPANEFRAMEWND/CPaneFrameWnd::LoadState
- AFXPANEFRAMEWND/CPaneFrameWnd::OnBeforeDock
- AFXPANEFRAMEWND/CPaneFrameWnd::OnDockToRecentPos
- AFXPANEFRAMEWND/CPaneFrameWnd::OnKillRollUpTimer
- AFXPANEFRAMEWND/CPaneFrameWnd::OnMovePane
- AFXPANEFRAMEWND/CPaneFrameWnd::OnPaneRecalcLayout
- AFXPANEFRAMEWND/CPaneFrameWnd::OnSetRollUpTimer
- AFXPANEFRAMEWND/CPaneFrameWnd::OnShowPane
- AFXPANEFRAMEWND/CPaneFrameWnd::PaneFromPoint
- AFXPANEFRAMEWND/CPaneFrameWnd::Pin
- AFXPANEFRAMEWND/CPaneFrameWnd::RedrawAll
- AFXPANEFRAMEWND/CPaneFrameWnd::RemoveNonValidPanes
- AFXPANEFRAMEWND/CPaneFrameWnd::RemovePane
- AFXPANEFRAMEWND/CPaneFrameWnd::ReplacePane
- AFXPANEFRAMEWND/CPaneFrameWnd::SaveState
- AFXPANEFRAMEWND/CPaneFrameWnd::SetCaptionButtons
- AFXPANEFRAMEWND/CPaneFrameWnd::SetDelayShow
- AFXPANEFRAMEWND/CPaneFrameWnd::SetDockingManager
- AFXPANEFRAMEWND/CPaneFrameWnd::SetDockingTimer
- AFXPANEFRAMEWND/CPaneFrameWnd::SetDockState
- AFXPANEFRAMEWND/CPaneFrameWnd::SetHotPoint
- AFXPANEFRAMEWND/CPaneFrameWnd::SetPreDockState
- AFXPANEFRAMEWND/CPaneFrameWnd::SizeToContent
- AFXPANEFRAMEWND/CPaneFrameWnd::StartTearOff
- AFXPANEFRAMEWND/CPaneFrameWnd::StoreRecentDockSiteInfo
- AFXPANEFRAMEWND/CPaneFrameWnd::StoreRecentTabRelatedInfo
- AFXPANEFRAMEWND/CPaneFrameWnd::OnCheckRollState
- AFXPANEFRAMEWND/CPaneFrameWnd::OnDrawBorder
- AFXPANEFRAMEWND/CPaneFrameWnd::m_bUseSaveBits
dev_langs:
- C++
helpviewer_keywords:
- CPaneFrameWnd class
- Serialize method
- PreTranslateMessage method
ms.assetid: ea3423a3-2763-482e-b763-817036ded10d
caps.latest.revision: 28
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: a8609643a9e64127af1d8035c496cedab4b1b1e9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cpaneframewnd-class"></a>Classe CPaneFrameWnd
[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 Implementa uma janela de quadro simplificado que contém um painel. O painel preenche a área cliente da janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPaneFrameWnd : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaneFrameWnd::AddPane](#addpane)|Adiciona um painel.|  
|[CPaneFrameWnd::AddRemovePaneFromGlobalList](#addremovepanefromgloballist)|Adiciona ou remove um painel da lista global.|  
|[CPaneFrameWnd::AdjustLayout](#adjustlayout)|Ajusta o layout da janela de quadro simplificado.|  
|[CPaneFrameWnd::AdjustPaneFrames](#adjustpaneframes)||  
|[CPaneFrameWnd::CalcBorderSize](#calcbordersize)|Calcula o tamanho das bordas de uma janela de quadro simplificado.|  
|[CPaneFrameWnd::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcule o retângulo esperado de uma janela encaixada.|  
|[CPaneFrameWnd::CanBeAttached](#canbeattached)|Determina se o painel atual pode ser encaixado em outra janela do painel ou quadro.|  
|[CPaneFrameWnd::CanBeDockedToPane](#canbedockedtopane)|Determina se a janela do minipode quadro ser encaixada para um painel.|  
|[CPaneFrameWnd::CheckGripperVisibility](#checkgrippervisibility)||  
|[CPaneFrameWnd::ConvertToTabbedDocument](#converttotabbeddocument)|Converte o painel em um documento com guias.|  
|[CPaneFrameWnd::Create](#create)|Cria uma janela de quadro simplificado e anexa-o para o `CPaneFrameWnd` objeto.|  
|[CPaneFrameWnd::CreateEx](#createex)|Cria uma janela de quadro simplificado e anexa-o para o `CPaneFrameWnd` objeto.|  
|[CPaneFrameWnd::DockPane](#dockpane)|Encaixa o painel.|  
|[CPaneFrameWnd::FindFloatingPaneByID](#findfloatingpanebyid)|Localiza um painel com a ID do controle especificado na lista global de painéis flutuantes.|  
|[CPaneFrameWnd::FrameFromPoint](#framefrompoint)|Localiza a janela do quadro simplificado que contém um ponto fornecido pelo usuário.|  
|[CPaneFrameWnd::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda da janela de quadro simplificado.|  
|[CPaneFrameWnd::GetCaptionRect](#getcaptionrect)|Calcula o retângulo delimitador de uma legenda de janela de quadro simplificado.|  
|[CPaneFrameWnd::GetCaptionText](#getcaptiontext)|Retorna o texto da legenda.|  
|[CPaneFrameWnd::GetDockingManager](#getdockingmanager)||  
|[CPaneFrameWnd::GetDockingMode](#getdockingmode)|Retorna o modo de encaixe.|  
|[CPaneFrameWnd::GetFirstVisiblePane](#getfirstvisiblepane)|Retorna o primeiro painel visível que está contido em uma janela de quadro simplificado.|  
|[CPaneFrameWnd::GetHotPoint](#gethotpoint)||  
|[CPaneFrameWnd::GetPane](#getpane)|Retorna um painel que está contido na janela do quadro simplificado.|  
|[CPaneFrameWnd::GetPaneCount](#getpanecount)|Retorna o número de painéis que estão contidos em uma janela de quadro simplificado.|  
|[CPaneFrameWnd::GetParent](#getparent)||  
|[CPaneFrameWnd::GetPinState](#getpinstate)||  
|[CPaneFrameWnd::GetRecentFloatingRect](#getrecentfloatingrect)||  
|[CPaneFrameWnd::GetVisiblePaneCount](#getvisiblepanecount)|Retorna o número de painéis visíveis que estão contidos em uma janela de quadro simplificado.|  
|[CPaneFrameWnd::HitTest](#hittest)|Determina qual parte de uma janela de miniem quadro um determinado ponto.|  
|[CPaneFrameWnd::IsCaptured](#iscaptured)||  
|[CPaneFrameWnd::IsDelayShow](#isdelayshow)||  
|[CPaneFrameWnd::IsRollDown](#isrolldown)|Determina se uma janela de minideve quadro ser revertida para baixo.|  
|[CPaneFrameWnd::IsRollUp](#isrollup)|Determina se uma janela de quadro mini deve ser acumulada.|  
|[CPaneFrameWnd::KillDockingTimer](#killdockingtimer)|Interrompe o timer de encaixe.|  
|[CPaneFrameWnd::LoadState](#loadstate)|Carrega o estado do painel do registro.|  
|[CPaneFrameWnd::OnBeforeDock](#onbeforedock)|Determina se é possível encaixar.|  
|[CPaneFrameWnd::OnDockToRecentPos](#ondocktorecentpos)|Encaixa a janela do quadro mini em sua posição mais recente.|  
|[CPaneFrameWnd::OnKillRollUpTimer](#onkillrolluptimer)|Interrompe o cronômetro do pacote cumulativo de atualizações.|  
|[CPaneFrameWnd::OnMovePane](#onmovepane)|Move a janela de quadro simplificado por um deslocamento especificado.|  
|[CPaneFrameWnd::OnPaneRecalcLayout](#onpanerecalclayout)|Ajusta o layout de um painel independente.|  
|[CPaneFrameWnd::OnSetRollUpTimer](#onsetrolluptimer)|Define o timer do pacote cumulativo de atualizações.|  
|[CPaneFrameWnd::OnShowPane](#onshowpane)|Chamado pela estrutura quando um painel na janela do quadro mini é ocultado ou exibido.|  
|[CPaneFrameWnd::PaneFromPoint](#panefrompoint)|Retorna um painel se ele contiver um ponto dentro de uma janela de quadro mini fornecido pelo usuário.|  
|[CPaneFrameWnd::Pin](#pin)||  
|`CPaneFrameWnd::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows.|  
|[CPaneFrameWnd::RedrawAll](#redrawall)|Todas as janelas de quadro mini é redesenhado.|  
|[CPaneFrameWnd::RemoveNonValidPanes](#removenonvalidpanes)|Chamado pela estrutura para remover painéis não válido.|  
|[CPaneFrameWnd::RemovePane](#removepane)|Remove um painel da janela de quadro simplificado.|  
|[CPaneFrameWnd::ReplacePane](#replacepane)|Substitui um painel com outra.|  
|[CPaneFrameWnd::SaveState](#savestate)|Salva o estado do painel no registro.|  
|`CPaneFrameWnd::Serialize`|Lê ou grava este objeto de ou para um arquivo morto.|  
|[CPaneFrameWnd::SetCaptionButtons](#setcaptionbuttons)|Conjuntos de botões de legenda.|  
|[CPaneFrameWnd::SetDelayShow](#setdelayshow)||  
|[CPaneFrameWnd::SetDockingManager](#setdockingmanager)||  
|[CPaneFrameWnd::SetDockingTimer](#setdockingtimer)|Define o timer de encaixe.|  
|[CPaneFrameWnd::SetDockState](#setdockstate)|Define o estado de encaixe.|  
|[CPaneFrameWnd::SetHotPoint](#sethotpoint)||  
|[CPaneFrameWnd::SetPreDockState](#setpredockstate)|Chamado pela estrutura para definir o estado predocking.|  
|[CPaneFrameWnd::SizeToContent](#sizetocontent)|Ajusta o tamanho de uma janela de quadro simplificado para que seja equivalente de tamanho para um painel independente.|  
|[CPaneFrameWnd::StartTearOff](#starttearoff)|Lágrimas um menu.|  
|[CPaneFrameWnd::StoreRecentDockSiteInfo](#storerecentdocksiteinfo)||  
|[CPaneFrameWnd::StoreRecentTabRelatedInfo](#storerecenttabrelatedinfo)||  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaneFrameWnd::OnCheckRollState](#oncheckrollstate)|Determina se uma janela de minideve quadro ser revertida para cima ou para baixo.|  
|[CPaneFrameWnd::OnDrawBorder](#ondrawborder)|Desenha as bordas de uma janela de quadro simplificado.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaneFrameWnd::m_bUseSaveBits](#m_busesavebits)|Especifica se deve registrar a classe de janela com o `CS_SAVEBITS` estilo de classe.|  
  
## <a name="remarks"></a>Comentários  
 O framework cria automaticamente uma `CPaneFrameWnd` objeto quando um painel é alternado de um estado encaixado para o estado flutuante.  
  
 Uma janela de minipode quadro ser arrastada com seu conteúdo visível (imediata de ancoragem) ou usando um retângulo de arrastar (encaixe padrão). O modo de encaixe do painel do contêiner do quadro mini determina que a mini-frame do arrastando o comportamento. Para obter mais informações, consulte [CBasePane::GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).  
  
 Uma janela de miniexibe quadro botões na legenda de acordo com o estilo de painel independente. Se o painel pode ser fechado ( [CBasePane::CanBeClosed](../../mfc/reference/cbasepane-class.md#canbeclosed)), ele exibe um botão Fechar. Se o painel tem o `AFX_CBRS_AUTO_ROLLUP` estilo, ele exibe um pin.  
  
 Se você derivar uma classe de `CPaneFrameWnd`, você deve informar o framework como criá-lo. Crie a classe substituindo [CPane::CreateDefaultMiniframe](../../mfc/reference/cpane-class.md#createdefaultminiframe), ou defina o `CPane::m_pMiniFrameRTC` para que ele aponte para as informações de classe de tempo de execução para a sua classe de membro.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CPaneFrameWnd`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxPaneFrameWnd.h  
  
##  <a name="addpane"></a>CPaneFrameWnd::AddPane  
 Adiciona um painel.  
  
```  
virtual void AddPane(CBasePane* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 O painel para adicionar.  
  
##  <a name="addremovepanefromgloballist"></a>CPaneFrameWnd::AddRemovePaneFromGlobalList  
 Adiciona ou remove um painel da lista global.  
  
```  
static BOOL __stdcall AddRemovePaneFromGlobalList(
    CBasePane* pWnd,  
    BOOL bAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 O painel para adicionar ou remover.  
  
 [in] `bAdd`  
 Se diferente de zero, adicione o painel. Se for 0, remova o painel.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; Caso contrário, 0.  
  
##  <a name="adjustlayout"></a>CPaneFrameWnd::AdjustLayout  
 Ajusta o layout da janela de quadro simplificado.  
  
```  
virtual void AdjustLayout();
```  
  
##  <a name="adjustpaneframes"></a>CPaneFrameWnd::AdjustPaneFrames  

  
```  
virtual void AdjustPaneFrames();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="calcbordersize"></a>CPaneFrameWnd::CalcBorderSize  
 Calcula o tamanho das bordas de uma janela miniframe.  
  
```  
virtual void CalcBorderSize(CRect& rectBorderSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectBorderSize`  
 Contém o tamanho, em pixels, da borda da janela miniframe.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para calcular o tamanho da borda de uma janela miniframe. O tamanho retornado depende se uma janela miniframe contém uma barra de ferramentas ou uma [CDockablePane](../../mfc/reference/cdockablepane-class.md).  
  
##  <a name="calcexpecteddockedrect"></a>CPaneFrameWnd::CalcExpectedDockedRect  
 Calcule o retângulo esperado de uma janela encaixada.  
  
```  
virtual void CalcExpectedDockedRect(
    CWnd* pWndToDock,  
    CPoint ptMouse,  
    CRect& rectResult,  
    BOOL& bDrawTab,  
    CDockablePane** ppTargetBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndToDock`  
 Um ponteiro para a janela de encaixe.  
  
 [in] `ptMouse`  
 O local do mouse.  
  
 [out] `rectResult`  
 O retângulo calculado.  
  
 [out] `bDrawTab`  
 Se `TRUE`, desenhar uma guia. Se `FALSE`, não desenhar uma guia.  
  
 [out] `ppTargetBar`  
 Um ponteiro para o painel de destino.  
  
### <a name="remarks"></a>Comentários  
 Esse método calcula o retângulo que uma janela deve ocupar se um usuário arrastava a janela para o ponto especificado por `ptMouse` e encaixado ele existe.  
  
##  <a name="canbeattached"></a>CPaneFrameWnd::CanBeAttached  
 Determina se o painel atual pode ser encaixado em outra janela do painel ou quadro.  
  
```  
virtual BOOL CanBeAttached() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel pode ser encaixado para outra janela do painel ou quadro; Caso contrário, `FALSE`.  
  
##  <a name="canbedockedtopane"></a>CPaneFrameWnd::CanBeDockedToPane  
 Determina se a janela do minipode quadro ser encaixada para um painel.  
  
```  
virtual BOOL CanBeDockedToPane(const CDockablePane* pDockingBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockingBar`  
 Um painel.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o minipode quadro ser encaixado às `pDockingBar`; caso contrário, 0.  
  
##  <a name="checkgrippervisibility"></a>CPaneFrameWnd::CheckGripperVisibility  

  
```  
virtual void CheckGripperVisibility();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="converttotabbeddocument"></a>CPaneFrameWnd::ConvertToTabbedDocument  
 Converte o painel em um documento com guias.  
  
```  
virtual void ConvertToTabbedDocument();
```  
  
##  <a name="create"></a>CPaneFrameWnd::Create  
 Cria uma janela miniframe e anexa-o para o [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszWindowName`  
 Especifica o texto a ser exibido na janela miniframe.  
  
 [in] `dwStyle`  
 Especifica o estilo da janela. Para obter mais informações, consulte [estilos de janela](../../mfc/reference/window-styles.md).  
  
 [in] `rect`  
 Especifica o tamanho inicial e a posição da janela miniframe.  
  
 [in] [out]`pParentWnd`  
 Especifica o quadro principal da janela miniframe. Esse valor não deve ser `NULL`.  
  
 [in] [out]`pContext`  
 Especifica o contexto definido pelo usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela foi criada com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Uma janela miniframe é criada em duas etapas. Primeiro, o framework cria uma `CPaneFrameWnd` objeto. Em segundo lugar, ele chama `Create` para criar a janela do Windows miniframe e anexá-lo a `CPaneFrameWnd` objeto.  
  
##  <a name="createex"></a>CPaneFrameWnd::CreateEx  
 Cria uma janela miniframe e anexa-o para o [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwStyleEx,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    CCreateContext* pContext=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwStyleEx`  
 Especifica o estilo de janela estendidos. Para obter mais informações, consulte [estilos de janela estendidos](../../mfc/reference/extended-window-styles.md)  
  
 [in] `lpszWindowName`  
 Especifica o texto a ser exibido na janela miniframe.  
  
 [in] `dwStyle`  
 Especifica o estilo da janela. Para obter mais informações, consulte [estilos de janela](../../mfc/reference/window-styles.md).  
  
 [in] `rect`  
 Especifica o tamanho inicial e a posição da janela miniframe.  
  
 [in] [out]`pParentWnd`  
 Especifica o quadro principal da janela miniframe. Esse valor não deve ser `NULL`.  
  
 [in] [out]`pContext`  
 Especifica o contexto definido pelo usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela foi criada com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Uma janela miniframe é criada em duas etapas. Primeiro, o framework cria uma `CPaneFrameWnd` objeto. Em segundo lugar, ele chama `Create` para criar a janela do Windows miniframe e anexá-lo a `CPaneFrameWnd` objeto.  
  
##  <a name="dockpane"></a>CPaneFrameWnd::DockPane  
 Encaixa o painel.  
  
```  
virtual CDockablePane* DockPane(BOOL& bWasDocked);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `bWasDocked`  
 `TRUE`Se o painel já foi encaixado; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a operação foi bem-sucedida, o `CDockablePane` que o painel foi encaixado como; caso contrário, `NULL`.  
  
##  <a name="findfloatingpanebyid"></a>CPaneFrameWnd::FindFloatingPaneByID  
 Localiza um painel com a ID do controle especificado na lista global de painéis flutuantes.  
  
```  
static CBasePane* FindFloatingPaneByID(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Representa a ID de controle do painel Localizar.  
  
### <a name="return-value"></a>Valor de retorno  
 O painel com a ID do controle especificado; Caso contrário, `NULL`, se nenhum painel tem a ID do controle especificado.  
  
##  <a name="framefrompoint"></a>CPaneFrameWnd::FrameFromPoint  
 Localiza a janela do quadro simplificado que contém o ponto especificado.  
  
```  
static CPaneFrameWnd* __stdcall FrameFromPoint(
    CPoint pt,  
    int nSensitivity,  
    CPaneFrameWnd* pFrameToExclude = NULL,  
    BOOL bFloatMultiOnly = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pt`  
 O ponto em coordenadas de tela.  
  
 [in] `nSensitivity`  
 A área de pesquisa da janela de miniaumente quadro esse tamanho. Uma janela de quadro mini satisfaz os critérios de pesquisa se determinado ponto está na área de trabalho maior.  
  
 [in] `pFrameToExclude`  
 Especifica uma janela de minipara quadro excluir da pesquisa.  
  
 [in] `bFloatMultiOnly`  
 Se `TRUE`, pesquisar somente janelas com moldura simplificado que têm o `CBRS_FLOAT_MULTI` estilo. Se `FALSE`, pesquisar todas as janelas de quadro simplificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela de quadro simplificado que contém `pt`; caso contrário, `NULL`.  
  
##  <a name="getcaptionheight"></a>CPaneFrameWnd::GetCaptionHeight  
 Retorna a altura da legenda da janela de quadro simplificado.  
  
```  
virtual int GetCaptionHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, da janela de quadro simplificado.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para determinar a altura de uma janela de quadro simplificado. Por padrão, a altura é definida como `SM_CYSMCAPTION`. Para obter mais informações, consulte [função GetSystemMetrics](http://msdn.microsoft.com/library/windows/desktop/ms724385).  
  
##  <a name="getcaptionrect"></a>CPaneFrameWnd::GetCaptionRect  
 Calcula o retângulo delimitador de uma legenda de janela de quadro simplificado.  
  
```  
virtual void GetCaptionRect(CRect& rectCaption) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectCaption`  
 Contém o tamanho e a posição da legenda da janela de quadro mini em coordenadas de tela.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para calcular o retângulo delimitador de uma legenda de janela de quadro simplificado.  
  
##  <a name="getcaptiontext"></a>CPaneFrameWnd::GetCaptionText  
 Retorna o texto da legenda.  
  
```  
virtual CString GetCaptionText();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O texto de legenda da janela de quadro simplificado.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pela estrutura quando ele exibe o texto da legenda.  
  
##  <a name="getdockingmanager"></a>CPaneFrameWnd::GetDockingManager  

  
```  
CDockingManager* GetDockingManager() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdockingmode"></a>CPaneFrameWnd::GetDockingMode  
 Retorna o modo de encaixe.  
  
```  
virtual AFX_DOCK_TYPE GetDockingMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de encaixe. Um dos seguintes valores:  
  
- `DT_STANDARD`  
  
- `DT_IMMEDIATE`  
  
- `DT_SMART`  
  
##  <a name="getfirstvisiblepane"></a>CPaneFrameWnd::GetFirstVisiblePane  
 Retorna o primeiro painel visível que está contido em uma janela de quadro simplificado.  
  
```  
virtual CWnd* GetFirstVisiblePane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro painel na janela do quadro simplificado, ou `NULL` se a janela do quadro mini não contém nenhuma painéis.  
  
##  <a name="gethotpoint"></a>CPaneFrameWnd::GetHotPoint  

  
```  
CPoint GetHotPoint() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpane"></a>CPaneFrameWnd::GetPane  
 Retorna um painel que está contido na janela do quadro simplificado.  
  
```  
virtual CWnd* GetPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O painel que está contido no quadro simplificado, ou `NULL` se a janela do quadro mini não contém nenhuma painéis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpanecount"></a>CPaneFrameWnd::GetPaneCount  
 Retorna o número de painéis que estão contidos em uma janela de quadro simplificado.  
  
```  
virtual int GetPaneCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de painéis da janela de quadro simplificado. Esse valor pode ser zero.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getparent"></a>CPaneFrameWnd::GetParent  

  
```  
CWnd* GetParent();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpinstate"></a>CPaneFrameWnd::GetPinState  

  
```  
BOOL GetPinState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getrecentfloatingrect"></a>CPaneFrameWnd::GetRecentFloatingRect  

  
```  
CRect GetRecentFloatingRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getvisiblepanecount"></a>CPaneFrameWnd::GetVisiblePaneCount  
 Retorna o número de painéis visíveis que estão contidos em uma janela de quadro simplificado.  
  
```  
virtual int GetVisiblePaneCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de painéis visíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hittest"></a>CPaneFrameWnd::HitTest  
 Determina qual parte de uma janela de miniem quadro um determinado ponto.  
  
```  
virtual LRESULT HitTest(
    CPoint point,  
    BOOL bDetectCaption);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto de teste.  
  
 [in] `bDetectCaption`  
 Se `TRUE`, verifique o ponto em relação a legenda. Se `FALSE`, ignore a legenda.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|`HTNOWHERE`|O ponto está fora da janela de quadro simplificado.|  
|`HTCLIENT`|É o ponto na área do cliente.|  
|`HTCAPTION`|O ponto é na legenda.|  
|`HTTOP`|O ponto é na parte superior.|  
|`HTTOPLEFT`|O ponto é na parte superior esquerda.|  
|`HTTOPRIGHT`|É o ponto no canto superior direito.|  
|`HTLEFT`|O ponto é à esquerda.|  
|`HTRIGHT`|O ponto é à direita.|  
|`HTBOTTOM`|O ponto é na parte inferior.|  
|`HTBOTTOMLEFT`|O ponto é na parte inferior esquerda.|  
|`HTBOTTOMRIGHT`|É o ponto no canto inferior direito.|  
  
##  <a name="iscaptured"></a>CPaneFrameWnd::IsCaptured  

  
```  
BOOL IsCaptured() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isdelayshow"></a>CPaneFrameWnd::IsDelayShow  

  
```  
BOOL IsDelayShow() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isrolldown"></a>CPaneFrameWnd::IsRollDown  
 Determina se uma janela de minideve quadro ser revertida para baixo.  
  
```  
virtual BOOL IsRollDown() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela do minideve quadro ser revertida para baixo; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para determinar se uma janela de minideve quadro ser revertida para baixo. O recurso de pacote cumulativo de atualizações/rolldown está habilitado para uma janela de minise quadro ele contém pelo menos um painel que tenha o `AFX_CBRS_AUTO_ROLLUP` sinalizador. Esse sinalizador é definido quando um painel é criado. Para obter mais informações, consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).  
  
 Por padrão, o framework verifica se o ponteiro do mouse dentro do retângulo delimitador de janela miniquadro para determinar se a janela tem que ser revertida para baixo. Você pode substituir esse comportamento em uma classe derivada.  
  
##  <a name="isrollup"></a>CPaneFrameWnd::IsRollUp  
 Determina se uma janela de quadro mini deve ser acumulada.  
  
```  
virtual BOOL IsRollUp() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela do miniprecisa quadro ser restaurada. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para determinar se uma janela de quadro mini deve ser acumulada. O recurso de pacote cumulativo de atualizações/rolldown está habilitado para uma janela de minise quadro ele contém pelo menos um painel que tenha o `AFX_CBRS_AUTO_ROLLUP` sinalizador. Esse sinalizador é definido quando um painel é criado. Para obter mais informações, consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).  
  
 Por padrão, o framework verifica se o ponteiro do mouse dentro do retângulo delimitador de janela miniquadro para determinar se a janela tem que ser acumulados. Você pode substituir esse comportamento em uma classe derivada.  
  
##  <a name="killdockingtimer"></a>CPaneFrameWnd::KillDockingTimer  
 Interrompe o timer de encaixe.  
  
```  
void KillDockingTimer();
```  
  
##  <a name="loadstate"></a>CPaneFrameWnd::LoadState  
 Carrega o estado do painel do registro.  
  
```  
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,  
    UINT uiID = (UINT) -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 O nome do perfil.  
  
 [in] `uiID`  
 A ID do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o estado do painel foi carregado com êxito; Caso contrário, `FALSE`.  
  
##  <a name="m_busesavebits"></a>CPaneFrameWnd::m_bUseSaveBits  
 Especifica se deve registrar a classe de janela que tem o `CS_SAVEBITS` estilo de classe.  
  
```  
AFX_IMPORT_DATA static BOOL m_bUseSaveBits;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina este membro estático como `TRUE` para registrar a classe de janela de minique quadro tem o `CS_SAVEBITS` estilo. Isso pode ajudar a reduzir a cintilação quando o usuário arrasta a janela do quadro simplificado.  
  
##  <a name="onbeforedock"></a>CPaneFrameWnd::OnBeforeDock  
 Determina se é possível encaixar.  
  
```  
virtual BOOL OnBeforeDock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o encaixe é possível; Caso contrário, `FALSE`.  
  
##  <a name="oncheckrollstate"></a>CPaneFrameWnd::OnCheckRollState  
 Determina se uma janela de minideve quadro ser revertida para cima ou para baixo.  
  
```  
virtual void OnCheckRollState();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para determinar se uma janela de minideve quadro ser revertida para cima ou para baixo.  
  
 Por padrão, o framework chama [CPaneFrameWnd::IsRollUp](#isrollup) e [CPaneFrameWnd::IsRollDown](#isrolldown) apenas alonga ou restaura a janela do quadro simplificado. Você pode substituir esse método em uma classe derivada para usar outro efeito visual.  
  
##  <a name="ondocktorecentpos"></a>CPaneFrameWnd::OnDockToRecentPos  
 Encaixa a janela do quadro mini em sua posição mais recente.  
  
```  
virtual void OnDockToRecentPos();
```  
  
##  <a name="ondrawborder"></a>CPaneFrameWnd::OnDrawBorder  
 Desenha as bordas de uma janela de quadro simplificado.  
  
```  
virtual void OnDrawBorder(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo usado para desenhar a borda.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para desenhar as bordas da janela de quadro simplificado.  
  
##  <a name="onkillrolluptimer"></a>CPaneFrameWnd::OnKillRollUpTimer  
 Interrompe o cronômetro do pacote cumulativo de atualizações.  
  
```  
virtual void OnKillRollUpTimer();
```  
  
##  <a name="onmovepane"></a>CPaneFrameWnd::OnMovePane  
 Move a janela de quadro simplificado por um deslocamento especificado.  
  
```  
virtual void OnMovePane(
    CPane* pBar,  
    CPoint ptOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Um ponteiro para um painel (ignorado).  
  
 [in] `ptOffset`  
 O deslocamento pela qual mover o painel.  
  
##  <a name="onpanerecalclayout"></a>CPaneFrameWnd::OnPaneRecalcLayout  
 Ajusta o layout de um painel em uma janela de quadro simplificado.  
  
```  
virtual void OnPaneRecalcLayout();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele deve ajustar o layout de um painel dentro da janela de quadro simplificado.  
  
 Por padrão, o painel está posicionado para abranger a área do cliente completo da janela de quadro simplificado.  
  
##  <a name="onsetrolluptimer"></a>CPaneFrameWnd::OnSetRollUpTimer  
 Define o timer do pacote cumulativo de atualizações.  
  
```  
virtual void OnSetRollUpTimer();
```  
  
##  <a name="onshowpane"></a>CPaneFrameWnd::OnShowPane  
 Chamado pela estrutura quando um painel na janela do quadro mini é ocultado ou exibido.  
  
```  
virtual void OnShowPane(
    CDockablePane* pBar,  
    BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 O painel que está sendo mostrado ou oculto.  
  
 [in] `bShow`  
 `TRUE`Se o painel está sendo mostrado; `FALSE` se o painel está sendo ocultado.  
  
### <a name="remarks"></a>Comentários  
 Chamado pela estrutura quando um painel na janela do quadro mini é mostrado ou oculto. A implementação padrão não faz nada.  
  
##  <a name="pin"></a>CPaneFrameWnd::Pin  

  
```  
void Pin(BOOL bPin = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bPin`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="panefrompoint"></a>CPaneFrameWnd::PaneFromPoint  
 Retorna um painel se ele contiver um ponto dentro de uma janela de quadro mini fornecido pelo usuário.  
  
```  
virtual CBasePane* PaneFromPoint(
    CPoint point,  
    int nSensitivity,  
    BOOL bCheckVisibility);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto que o usuário clicou em coordenadas de tela.  
  
 [in] `nSensitivity`  
 Este parâmetro não é usado.  
  
 [in] `bCheckVisibility`  
 `TRUE`para especificar que apenas os painéis visíveis devem ser retornados; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 O painel que o usuário clicou, ou `NULL` se nenhum painel existe nesse local.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para obter um painel que contém o ponto especificado.  
  
##  <a name="redrawall"></a>CPaneFrameWnd::RedrawAll  
 Todas as janelas de quadro mini é redesenhado.  
  
```  
static void RedrawAll();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método atualiza todas as janelas de quadro mini chamando [CWnd::RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) para cada janela.  
  
##  <a name="removenonvalidpanes"></a>CPaneFrameWnd::RemoveNonValidPanes  
 Chamado pela estrutura para remover painéis não válido.  
  
```  
virtual void RemoveNonValidPanes();
```  
  
##  <a name="removepane"></a>CPaneFrameWnd::RemovePane  
 Remove um painel da janela de quadro simplificado.  
  
```  
virtual void RemovePane(
    CBasePane* pWnd,  
    BOOL bDestroy = FALSE,  
    BOOL bNoDelayedDestroy = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Um ponteiro para o painel para remover.  
  
 [in] `bDestroy`  
 Especifica o que acontece com a janela do quadro simplificado. Se `bDestroy` é `TRUE`, este método destrói a janela do quadro mini imediatamente. Se for `FALSE`, este método destrói a janela do quadro mini após um determinado intervalo.  
  
 [in] `bNoDelayedDestroy`  
 Se `TRUE`, atrasada destruição está desabilitada. Se `FALSE`, atrasada destruição está habilitada.  
  
### <a name="remarks"></a>Comentários  
 A estrutura pode destruir janelas com moldura mini imediatamente ou após um determinado intervalo. Se você deseja atrasar a destruição de janelas com moldura simplificado, passe `FALSE` no `bNoDelayedDestroy` parâmetro. Destruição atrasada ocorre quando o framework processa o `AFX_WM_CHECKEMPTYMINIFRAME` mensagem.  
  
##  <a name="replacepane"></a>CPaneFrameWnd::ReplacePane  
 Substitui um painel com outra.  
  
```  
virtual void ReplacePane(
    CBasePane* pBarOrg,  
    CBasePane* pBarReplaceWith);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBarOrg`  
 Um ponteiro para o painel original.  
  
 [in] `pBarReplaceWith`  
 Um ponteiro para o painel que substitui o painel original.  
  
##  <a name="savestate"></a>CPaneFrameWnd::SaveState  
 Salva o estado do painel no registro.  
  
```  
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,  
    UINT uiID = (UINT) -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 O nome do perfil.  
  
 [in] `uiID`  
 A ID do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o estado do painel foi salvo com êxito; Caso contrário, `FALSE`.  
  
##  <a name="setcaptionbuttons"></a>CPaneFrameWnd::SetCaptionButtons  
 Conjuntos de botões de legenda.  
  
```  
virtual void SetCaptionButtons(DWORD dwButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwButtons`  
 Combinação OR bit a bit dos valores a seguir:  
  
- `AFX_CAPTION_BTN_CLOSE`  
  
- `AFX_CAPTION_BTN_PIN`  
  
- `AFX_CAPTION_BTN_MENU`  
  
- `AFX_CAPTION_BTN_CUSTOMIZE`  
  
##  <a name="setdelayshow"></a>CPaneFrameWnd::SetDelayShow  

  
```  
void SetDelayShow(BOOL bDelayShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDelayShow`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setdockingmanager"></a>CPaneFrameWnd::SetDockingManager  

  
```  
void SetDockingManager(CDockingManager* pManager);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pManager`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setdockingtimer"></a>CPaneFrameWnd::SetDockingTimer  
 Define o timer de encaixe.  
  
```  
void SetDockingTimer(UINT nTimeOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTimeOut`  
 Valor de tempo limite em milissegundos.  
  
##  <a name="setdockstate"></a>CPaneFrameWnd::SetDockState  
 Define o estado de encaixe.  
  
```  
virtual void SetDockState(CDockingManager* pDockManager);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockManager`  
 Um ponteiro para um Gerenciador de encaixe.  
  
##  <a name="sethotpoint"></a>CPaneFrameWnd::SetHotPoint  

  
```  
void SetHotPoint(CPoint& ptNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ptNew`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpredockstate"></a>CPaneFrameWnd::SetPreDockState  
 Chamado pela estrutura para definir o estado predocking.  
  
```  
virtual BOOL SetPreDockState(
    AFX_PREDOCK_STATE preDockState,  
    CBasePane* pBarToDock = NULL,  
    AFX_DOCK_METHOD dockMethod = DM_MOUSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `preDockState`  
 Valores possíveis:  
  
- `PDS_NOTHING`,  
  
- `PDS_DOCK_REGULAR`,  
  
- `PDS_DOCK_TO_TAB`  
  
 [in] `pBarToDock`  
 Um ponteiro para o painel de encaixe.  
  
 [in] `dockMethod`  
 O método de encaixe. (Esse parâmetro é ignorado).  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela de quadro mini estiver desencaixada; `FALSE` se ela estiver encaixada.  
  
##  <a name="sizetocontent"></a>CPaneFrameWnd::SizeToContent  
 Ajusta o tamanho de uma janela de quadro simplificado para que seja equivalente a um painel independente.  
  
```  
virtual void SizeToContent();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para ajustar o tamanho de uma janela de quadro simplificado para o tamanho de um painel independente.  
  
##  <a name="starttearoff"></a>CPaneFrameWnd::StartTearOff  
 Lágrimas um menu.  
  
```  
BOOL StartTearOff(CMFCPopu* pMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenu`  
 Um ponteiro para um menu.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso o método tenha sido bem-sucedido; do contrário, `FALSE`.  
  
##  <a name="storerecentdocksiteinfo"></a>CPaneFrameWnd::StoreRecentDockSiteInfo  

  
```  
virtual void StoreRecentDockSiteInfo(CPane* pBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="storerecenttabrelatedinfo"></a>CPaneFrameWnd::StoreRecentTabRelatedInfo  

  
```  
virtual void StoreRecentTabRelatedInfo(
    CDockablePane* pDockingBar,  
    CDockablePane* pTabbedBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDockingBar`  
 [in] `pTabbedBar`  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)

