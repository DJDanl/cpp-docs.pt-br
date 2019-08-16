---
title: Classe CPaneFrameWnd
ms.date: 11/04/2016
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
helpviewer_keywords:
- CPaneFrameWnd [MFC], AddPane
- CPaneFrameWnd [MFC], AddRemovePaneFromGlobalList
- CPaneFrameWnd [MFC], AdjustLayout
- CPaneFrameWnd [MFC], AdjustPaneFrames
- CPaneFrameWnd [MFC], CalcBorderSize
- CPaneFrameWnd [MFC], CalcExpectedDockedRect
- CPaneFrameWnd [MFC], CanBeAttached
- CPaneFrameWnd [MFC], CanBeDockedToPane
- CPaneFrameWnd [MFC], CheckGripperVisibility
- CPaneFrameWnd [MFC], ConvertToTabbedDocument
- CPaneFrameWnd [MFC], Create
- CPaneFrameWnd [MFC], CreateEx
- CPaneFrameWnd [MFC], DockPane
- CPaneFrameWnd [MFC], FindFloatingPaneByID
- CPaneFrameWnd [MFC], FrameFromPoint
- CPaneFrameWnd [MFC], GetCaptionHeight
- CPaneFrameWnd [MFC], GetCaptionRect
- CPaneFrameWnd [MFC], GetCaptionText
- CPaneFrameWnd [MFC], GetDockingManager
- CPaneFrameWnd [MFC], GetDockingMode
- CPaneFrameWnd [MFC], GetFirstVisiblePane
- CPaneFrameWnd [MFC], GetHotPoint
- CPaneFrameWnd [MFC], GetPane
- CPaneFrameWnd [MFC], GetPaneCount
- CPaneFrameWnd [MFC], GetParent
- CPaneFrameWnd [MFC], GetPinState
- CPaneFrameWnd [MFC], GetRecentFloatingRect
- CPaneFrameWnd [MFC], GetVisiblePaneCount
- CPaneFrameWnd [MFC], HitTest
- CPaneFrameWnd [MFC], IsCaptured
- CPaneFrameWnd [MFC], IsDelayShow
- CPaneFrameWnd [MFC], IsRollDown
- CPaneFrameWnd [MFC], IsRollUp
- CPaneFrameWnd [MFC], KillDockingTimer
- CPaneFrameWnd [MFC], LoadState
- CPaneFrameWnd [MFC], OnBeforeDock
- CPaneFrameWnd [MFC], OnDockToRecentPos
- CPaneFrameWnd [MFC], OnKillRollUpTimer
- CPaneFrameWnd [MFC], OnMovePane
- CPaneFrameWnd [MFC], OnPaneRecalcLayout
- CPaneFrameWnd [MFC], OnSetRollUpTimer
- CPaneFrameWnd [MFC], OnShowPane
- CPaneFrameWnd [MFC], PaneFromPoint
- CPaneFrameWnd [MFC], Pin
- CPaneFrameWnd [MFC], RedrawAll
- CPaneFrameWnd [MFC], RemoveNonValidPanes
- CPaneFrameWnd [MFC], RemovePane
- CPaneFrameWnd [MFC], ReplacePane
- CPaneFrameWnd [MFC], SaveState
- CPaneFrameWnd [MFC], SetCaptionButtons
- CPaneFrameWnd [MFC], SetDelayShow
- CPaneFrameWnd [MFC], SetDockingManager
- CPaneFrameWnd [MFC], SetDockingTimer
- CPaneFrameWnd [MFC], SetDockState
- CPaneFrameWnd [MFC], SetHotPoint
- CPaneFrameWnd [MFC], SetPreDockState
- CPaneFrameWnd [MFC], SizeToContent
- CPaneFrameWnd [MFC], StartTearOff
- CPaneFrameWnd [MFC], StoreRecentDockSiteInfo
- CPaneFrameWnd [MFC], StoreRecentTabRelatedInfo
- CPaneFrameWnd [MFC], OnCheckRollState
- CPaneFrameWnd [MFC], OnDrawBorder
- CPaneFrameWnd [MFC], m_bUseSaveBits
ms.assetid: ea3423a3-2763-482e-b763-817036ded10d
ms.openlocfilehash: 37ab241219f28336e73ea459a4e32ff413de8964
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502969"
---
# <a name="cpaneframewnd-class"></a>Classe CPaneFrameWnd

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

Implementa uma janela de mini-quadro que contém um painel. O painel preenche a área do cliente da janela.

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
|[CPaneFrameWnd::AdjustLayout](#adjustlayout)|Ajusta o layout da janela de mini-quadro.|
|[CPaneFrameWnd::AdjustPaneFrames](#adjustpaneframes)||
|[CPaneFrameWnd::CalcBorderSize](#calcbordersize)|Calcula o tamanho das bordas de uma janela de mini-quadro.|
|[CPaneFrameWnd::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcular o retângulo esperado de uma janela encaixada.|
|[CPaneFrameWnd::CanBeAttached](#canbeattached)|Determina se o painel atual pode ser encaixado em outra janela de painel ou quadro.|
|[CPaneFrameWnd::CanBeDockedToPane](#canbedockedtopane)|Determina se a janela do mini-quadro pode ser encaixada em um painel.|
|[CPaneFrameWnd::CheckGripperVisibility](#checkgrippervisibility)||
|[CPaneFrameWnd::ConvertToTabbedDocument](#converttotabbeddocument)|Converte o painel em um documento com guias.|
|[CPaneFrameWnd::Create](#create)|Cria uma janela de mini-quadro e a anexa ao `CPaneFrameWnd` objeto.|
|[CPaneFrameWnd::CreateEx](#createex)|Cria uma janela de mini-quadro e a anexa ao `CPaneFrameWnd` objeto.|
|[CPaneFrameWnd::DockPane](#dockpane)|Encaixa o painel.|
|[CPaneFrameWnd::FindFloatingPaneByID](#findfloatingpanebyid)|Localiza um painel com a ID de controle especificada na lista global de painéis flutuantes.|
|[CPaneFrameWnd::FrameFromPoint](#framefrompoint)|Localiza a janela do mini-quadro que contém um ponto fornecido pelo usuário.|
|[CPaneFrameWnd::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda da janela de mini-quadro.|
|[CPaneFrameWnd::GetCaptionRect](#getcaptionrect)|Calcula o retângulo delimitador de uma legenda de janela de mini-quadro.|
|[CPaneFrameWnd::GetCaptionText](#getcaptiontext)|Retorna o texto da legenda.|
|[CPaneFrameWnd::GetDockingManager](#getdockingmanager)||
|[CPaneFrameWnd::GetDockingMode](#getdockingmode)|Retorna o modo de encaixe.|
|[CPaneFrameWnd::GetFirstVisiblePane](#getfirstvisiblepane)|Retorna o primeiro painel visível contido em uma janela de mini-quadro.|
|[CPaneFrameWnd::GetHotPoint](#gethotpoint)||
|[CPaneFrameWnd::GetPane](#getpane)|Retorna um painel contido na janela de mini-quadro.|
|[CPaneFrameWnd::GetPaneCount](#getpanecount)|Retorna o número de painéis contidos em uma janela de mini-quadro.|
|[CPaneFrameWnd::GetParent](#getparent)||
|[CPaneFrameWnd::GetPinState](#getpinstate)||
|[CPaneFrameWnd::GetRecentFloatingRect](#getrecentfloatingrect)||
|[CPaneFrameWnd::GetVisiblePaneCount](#getvisiblepanecount)|Retorna o número de painéis visíveis que estão contidos em uma janela de mini-quadro.|
|[CPaneFrameWnd::HitTest](#hittest)|Determina qual parte de uma janela de mini-quadro está em um determinado ponto.|
|[CPaneFrameWnd::IsCaptured](#iscaptured)||
|[CPaneFrameWnd::IsDelayShow](#isdelayshow)||
|[CPaneFrameWnd::IsRollDown](#isrolldown)|Determina se uma janela de mini-quadro deve ser desfeita.|
|[CPaneFrameWnd::IsRollUp](#isrollup)|Determina se uma janela de mini-quadro deve ser acumulada.|
|[CPaneFrameWnd::KillDockingTimer](#killdockingtimer)|Interrompe o timer de encaixe.|
|[CPaneFrameWnd::LoadState](#loadstate)|Carrega o estado do painel do registro.|
|[CPaneFrameWnd::OnBeforeDock](#onbeforedock)|Determina se o encaixe é possível.|
|[CPaneFrameWnd::OnDockToRecentPos](#ondocktorecentpos)|Encaixa a janela de mini-quadro em sua posição mais recente.|
|[CPaneFrameWnd::OnKillRollUpTimer](#onkillrolluptimer)|Interrompe o timer de ROLLUP.|
|[CPaneFrameWnd::OnMovePane](#onmovepane)|Move a janela do mini-quadro por um deslocamento especificado.|
|[CPaneFrameWnd::OnPaneRecalcLayout](#onpanerecalclayout)|Ajusta o layout de um painel contido.|
|[CPaneFrameWnd::OnSetRollUpTimer](#onsetrolluptimer)|Define o timer de ROLLUP.|
|[CPaneFrameWnd::OnShowPane](#onshowpane)|Chamado pelo Framework quando um painel na janela do mini-quadro é ocultado ou exibido.|
|[CPaneFrameWnd::PaneFromPoint](#panefrompoint)|Retorna um painel se ele contiver um ponto fornecido pelo usuário dentro de uma janela de mini-quadro.|
|[CPaneFrameWnd::Pin](#pin)||
|`CPaneFrameWnd::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para traduzir as mensagens de janela antes que elas sejam expedidas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) do Windows.|
|[CPaneFrameWnd::RedrawAll](#redrawall)|Redesenha todas as janelas de mini quadros.|
|[CPaneFrameWnd::RemoveNonValidPanes](#removenonvalidpanes)|Chamado pelo Framework para remover painéis não válidos.|
|[CPaneFrameWnd::RemovePane](#removepane)|Remove um painel da janela de mini-quadro.|
|[CPaneFrameWnd::ReplacePane](#replacepane)|Substitui um painel por outro.|
|[CPaneFrameWnd::SaveState](#savestate)|Salva o estado do painel no registro.|
|`CPaneFrameWnd::Serialize`|Lê ou grava esse objeto de ou para um arquivo.|
|[CPaneFrameWnd::SetCaptionButtons](#setcaptionbuttons)|Define botões de legenda.|
|[CPaneFrameWnd::SetDelayShow](#setdelayshow)||
|[CPaneFrameWnd::SetDockingManager](#setdockingmanager)||
|[CPaneFrameWnd::SetDockingTimer](#setdockingtimer)|Define o timer de encaixe.|
|[CPaneFrameWnd::SetDockState](#setdockstate)|Define o estado de encaixe.|
|[CPaneFrameWnd::SetHotPoint](#sethotpoint)||
|[CPaneFrameWnd::SetPreDockState](#setpredockstate)|Chamado pelo Framework para definir o estado de acoplamento.|
|[CPaneFrameWnd::SizeToContent](#sizetocontent)|Ajusta o tamanho de uma janela de mini-quadro para que ela seja equivalente em tamanho a um painel contido.|
|[CPaneFrameWnd::StartTearOff](#starttearoff)|Deslágrimasu um menu.|
|[CPaneFrameWnd::StoreRecentDockSiteInfo](#storerecentdocksiteinfo)||
|[CPaneFrameWnd::StoreRecentTabRelatedInfo](#storerecenttabrelatedinfo)||

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CPaneFrameWnd::OnCheckRollState](#oncheckrollstate)|Determina se uma janela de mini-quadro deve ser acumulada ou reduzida.|
|[CPaneFrameWnd::OnDrawBorder](#ondrawborder)|Desenha as bordas de uma janela de mini-quadro.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CPaneFrameWnd::m_bUseSaveBits](#m_busesavebits)|Especifica se a classe de janela deve ser registrada com o estilo de classe CS_SAVEBITS.|

## <a name="remarks"></a>Comentários

A estrutura cria automaticamente um `CPaneFrameWnd` objeto quando um painel é alternado de um estado encaixado para um estado flutuante.

Uma janela de mini-quadro pode ser arrastada com seu conteúdo visível (encaixe imediato) ou usando um retângulo de arrastar (encaixe padrão). O modo de encaixe do painel contêiner do mini-quadro determina o comportamento de arrastar do mini-quadro. Para obter mais informações, consulte [CBasePane:: GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).

Uma janela de mini-quadro exibe botões na legenda de acordo com o estilo de painel contido. Se o painel puder ser fechado ( [CBasePane:: CanBeClosed](../../mfc/reference/cbasepane-class.md#canbeclosed)), ele exibirá um botão fechar. Se o painel tiver o estilo AFX_CBRS_AUTO_ROLLUP, ele exibirá um PIN.

Se você derivar uma classe `CPaneFrameWnd`de, deverá informar à estrutura como criá-la. Crie a classe substituindo [CPane:: CreateDefaultMiniframe](../../mfc/reference/cpane-class.md#createdefaultminiframe)ou defina o `CPane::m_pMiniFrameRTC` membro para que ele aponte para as informações de classe de tempo de execução para sua classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CPaneFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxPaneFrameWnd. h

##  <a name="addpane"></a>  CPaneFrameWnd::AddPane

Adiciona um painel.

```
virtual void AddPane(CBasePane* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no O painel a ser adicionado.

##  <a name="addremovepanefromgloballist"></a>  CPaneFrameWnd::AddRemovePaneFromGlobalList

Adiciona ou remove um painel da lista global.

```
static BOOL __stdcall AddRemovePaneFromGlobalList(
    CBasePane* pWnd,
    BOOL bAdd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no O painel a ser adicionado ou removido.

*bAdd*<br/>
no Se for diferente de zero, adicione o painel. Se for 0, remova o painel.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método foi bem-sucedido; caso contrário, 0.

##  <a name="adjustlayout"></a>CPaneFrameWnd::AdjustLayout

Ajusta o layout da janela de mini-quadro.

```
virtual void AdjustLayout();
```

##  <a name="adjustpaneframes"></a>  CPaneFrameWnd::AdjustPaneFrames

```
virtual void AdjustPaneFrames();
```

### <a name="remarks"></a>Comentários

##  <a name="calcbordersize"></a>CPaneFrameWnd::CalcBorderSize

Calcula o tamanho das bordas de uma janela miniquadros.

```
virtual void CalcBorderSize(CRect& rectBorderSize) const;
```

### <a name="parameters"></a>Parâmetros

*rectBorderSize*<br/>
fora Contém o tamanho, em pixels, da borda da janela miniquadros.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework para calcular o tamanho da borda de uma janela miniquadros. O tamanho retornado depende se uma janela miniquadros contém uma barra de ferramentas ou um [CDockablePane](../../mfc/reference/cdockablepane-class.md).

##  <a name="calcexpecteddockedrect"></a>  CPaneFrameWnd::CalcExpectedDockedRect

Calcular o retângulo esperado de uma janela encaixada.

```
virtual void CalcExpectedDockedRect(
    CWnd* pWndToDock,
    CPoint ptMouse,
    CRect& rectResult,
    BOOL& bDrawTab,
    CDockablePane** ppTargetBar);
```

### <a name="parameters"></a>Parâmetros

*pWndToDock*<br/>
no Um ponteiro para a janela a ser encaixada.

*ptMouse*<br/>
no O local do mouse.

*rectResult*<br/>
fora O retângulo calculado.

*bDrawTab*<br/>
fora Se for TRUE, desenhe uma guia. Se for FALSE, não desenhe uma guia.

*ppTargetBar*<br/>
fora Um ponteiro para o painel de destino.

### <a name="remarks"></a>Comentários

Esse método calcula o retângulo que uma janela ocuparia se um usuário arrastasse a janela para o ponto especificado por *ptMouse* e o encaixava lá.

##  <a name="canbeattached"></a>  CPaneFrameWnd::CanBeAttached

Determina se o painel atual pode ser encaixado em outra janela de painel ou quadro.

```
virtual BOOL CanBeAttached() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o painel puder ser encaixado em outra janela de painel ou quadro; caso contrário, FALSE.

##  <a name="canbedockedtopane"></a>  CPaneFrameWnd::CanBeDockedToPane

Determina se a janela do mini-quadro pode ser encaixada em um painel.

```
virtual BOOL CanBeDockedToPane(const CDockablePane* pDockingBar) const;
```

### <a name="parameters"></a>Parâmetros

*pDockingBar*<br/>
no Um painel.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o mini-quadro puder ser encaixado no *pDockingBar*; caso contrário, 0.

##  <a name="checkgrippervisibility"></a>CPaneFrameWnd::CheckGripperVisibility

```
virtual void CheckGripperVisibility();
```

### <a name="remarks"></a>Comentários

##  <a name="converttotabbeddocument"></a>  CPaneFrameWnd::ConvertToTabbedDocument

Converte o painel em um documento com guias.

```
virtual void ConvertToTabbedDocument();
```

##  <a name="create"></a>  CPaneFrameWnd::Create

Cria uma janela miniquadros e a anexa ao objeto [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) .

```
virtual BOOL Create(
    LPCTSTR lpszWindowName,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszWindowName*<br/>
no Especifica o texto a ser exibido na janela miniquadros.

*dwStyle*<br/>
no Especifica o estilo da janela. Para obter mais informações, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*rect*<br/>
no Especifica o tamanho inicial e a posição da janela miniquadros.

*pParentWnd*<br/>
[entrada, saída] Especifica o quadro pai da janela miniquadros. Esse valor não deve ser nulo.

*pContext*<br/>
[entrada, saída] Especifica o contexto definido pelo usuário.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela foi criada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Uma janela miniquadros é criada em duas etapas. Primeiro, a estrutura cria um `CPaneFrameWnd` objeto. Em segundo lugar, `Create` ele chama para criar a janela miniquadros do Windows e anexá `CPaneFrameWnd` -la ao objeto.

##  <a name="createex"></a>  CPaneFrameWnd::CreateEx

Cria uma janela miniquadros e a anexa ao objeto [CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md) .

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

*dwStyleEx*<br/>
no Especifica o estilo de janela estendida. Para obter mais informações, consulte [estilos de janela estendida](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles)

*lpszWindowName*<br/>
no Especifica o texto a ser exibido na janela miniquadros.

*dwStyle*<br/>
no Especifica o estilo da janela. Para obter mais informações, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*rect*<br/>
no Especifica o tamanho inicial e a posição da janela miniquadros.

*pParentWnd*<br/>
[entrada, saída] Especifica o quadro pai da janela miniquadros. Esse valor não deve ser nulo.

*pContext*<br/>
[entrada, saída] Especifica o contexto definido pelo usuário.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela foi criada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Uma janela miniquadros é criada em duas etapas. Primeiro, a estrutura cria um `CPaneFrameWnd` objeto. Em segundo lugar, `Create` ele chama para criar a janela miniquadros do Windows e anexá `CPaneFrameWnd` -la ao objeto.

##  <a name="dockpane"></a>  CPaneFrameWnd::DockPane

Encaixa o painel.

```
virtual CDockablePane* DockPane(BOOL& bWasDocked);
```

### <a name="parameters"></a>Parâmetros

*bWasDocked*<br/>
fora TRUE se o painel já estava encaixado; caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

Se a operação foi bem-sucedida, a `CDockablePane` que o painel foi encaixado; caso contrário, é nulo.

##  <a name="findfloatingpanebyid"></a>CPaneFrameWnd::FindFloatingPaneByID

Localiza um painel com a ID de controle especificada na lista global de painéis flutuantes.

```
static CBasePane* FindFloatingPaneByID(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
no Representa a ID de controle do painel a ser localizado.

### <a name="return-value"></a>Valor de retorno

O painel com a ID de controle especificada; caso contrário, NULL, se nenhum painel tiver a ID de controle especificada.

##  <a name="framefrompoint"></a>CPaneFrameWnd::FrameFromPoint

Localiza a janela do mini-quadro que contém o ponto especificado.

```
static CPaneFrameWnd* __stdcall FrameFromPoint(
    CPoint pt,
    int nSensitivity,
    CPaneFrameWnd* pFrameToExclude = NULL,
    BOOL bFloatMultiOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
no O ponto, em coordenadas da tela.

*nSensitivity*<br/>
no Aumentar a área de pesquisa da janela de mini-quadro por este tamanho. Uma janela de mini-quadro satisfaz os critérios de pesquisa se o ponto determinado estiver na área aumentada.

*pFrameToExclude*<br/>
no Especifica uma janela de mini-quadro a ser excluída da pesquisa.

*bFloatMultiOnly*<br/>
no Se for TRUE, somente pesquise janelas de mini-quadro que tenham o estilo CBRS_FLOAT_MULTI. Se for FALSE, pesquise todas as janelas de mini quadros.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela de mini-quadro que contém *pt*; caso contrário, NULL.

##  <a name="getcaptionheight"></a>  CPaneFrameWnd::GetCaptionHeight

Retorna a altura da legenda da janela de mini-quadro.

```
virtual int GetCaptionHeight() const;
```

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, da janela de mini-quadro.

### <a name="remarks"></a>Comentários

Chame esse método para determinar a altura de uma janela de mini quadros. Por padrão, a altura é definida como SM_CYSMCAPTION. Para obter mais informações, consulte [função GetSystemMetrics](/windows/win32/api/winuser/nf-winuser-getsystemmetrics).

##  <a name="getcaptionrect"></a>  CPaneFrameWnd::GetCaptionRect

Calcula o retângulo delimitador de uma legenda de janela de mini-quadro.

```
virtual void GetCaptionRect(CRect& rectCaption) const;
```

### <a name="parameters"></a>Parâmetros

*rectCaption*<br/>
fora Contém o tamanho e a posição da legenda da janela do mini-quadro, em coordenadas da tela.

### <a name="remarks"></a>Comentários

Esse método é chamado pela estrutura para calcular o retângulo delimitador de uma legenda de janela de mini-quadro.

##  <a name="getcaptiontext"></a>  CPaneFrameWnd::GetCaptionText

Retorna o texto da legenda.

```
virtual CString GetCaptionText();
```

### <a name="return-value"></a>Valor de retorno

O texto da legenda da janela de mini-quadro.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework quando ele exibe o texto da legenda.

##  <a name="getdockingmanager"></a>  CPaneFrameWnd::GetDockingManager

```
CDockingManager* GetDockingManager() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getdockingmode"></a>  CPaneFrameWnd::GetDockingMode

Retorna o modo de encaixe.

```
virtual AFX_DOCK_TYPE GetDockingMode() const;
```

### <a name="return-value"></a>Valor de retorno

O modo de encaixe. Um dos seguintes valores:

- DT_STANDARD

- DT_IMMEDIATE

- DT_SMART

##  <a name="getfirstvisiblepane"></a>  CPaneFrameWnd::GetFirstVisiblePane

Retorna o primeiro painel visível contido em uma janela de mini-quadro.

```
virtual CWnd* GetFirstVisiblePane() const;
```

### <a name="return-value"></a>Valor de retorno

O primeiro painel na janela de mini-quadro, ou NULL, se a janela de mini quadros não contiver painéis.

##  <a name="gethotpoint"></a>  CPaneFrameWnd::GetHotPoint

```
CPoint GetHotPoint() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpane"></a>  CPaneFrameWnd::GetPane

Retorna um painel contido na janela de mini-quadro.

```
virtual CWnd* GetPane() const;
```

### <a name="return-value"></a>Valor de retorno

O painel contido no mini-quadro, ou NULL, se a janela do mini-quadro não contiver painéis.

### <a name="remarks"></a>Comentários

##  <a name="getpanecount"></a>  CPaneFrameWnd::GetPaneCount

Retorna o número de painéis contidos em uma janela de mini-quadro.

```
virtual int GetPaneCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de painéis na janela de mini-quadro. Esse valor pode ser zero.

### <a name="remarks"></a>Comentários

##  <a name="getparent"></a>  CPaneFrameWnd::GetParent

```
CWnd* GetParent();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpinstate"></a>  CPaneFrameWnd::GetPinState

```
BOOL GetPinState() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getrecentfloatingrect"></a>  CPaneFrameWnd::GetRecentFloatingRect

```
CRect GetRecentFloatingRect() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getvisiblepanecount"></a>  CPaneFrameWnd::GetVisiblePaneCount

Retorna o número de painéis visíveis que estão contidos em uma janela de mini-quadro.

```
virtual int GetVisiblePaneCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de painéis visíveis.

### <a name="remarks"></a>Comentários

##  <a name="hittest"></a>  CPaneFrameWnd::HitTest

Determina qual parte de uma janela de mini-quadro está em um determinado ponto.

```
virtual LRESULT HitTest(
    CPoint point,
    BOOL bDetectCaption);
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
no O ponto a ser testado.

*bDetectCaption*<br/>
no Se for TRUE, verifique o ponto em relação à legenda. Se for FALSE, ignore a legenda.

### <a name="return-value"></a>Valor de retorno

Um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|HTNOWHERE|O ponto está fora da janela de mini-quadro.|
|HTCLIENT|O ponto está na área do cliente.|
|HTCAPTION|O ponto está na legenda.|
|HTTOP|O ponto está na parte superior.|
|HTTOPLEFT|O ponto está na parte superior esquerda.|
|HTTOPRIGHT|O ponto está no canto superior direito.|
|HTLEFT|O ponto está à esquerda.|
|HTRIGHT|O ponto está à direita.|
|HTBOTTOM|O ponto está na parte inferior.|
|HTBOTTOMLEFT|O ponto está na parte inferior esquerda.|
|HTBOTTOMRIGHT|O ponto está no canto inferior direito.|

##  <a name="iscaptured"></a>  CPaneFrameWnd::IsCaptured

```
BOOL IsCaptured() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isdelayshow"></a>  CPaneFrameWnd::IsDelayShow

```
BOOL IsDelayShow() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isrolldown"></a>  CPaneFrameWnd::IsRollDown

Determina se uma janela de mini-quadro deve ser desfeita.

```
virtual BOOL IsRollDown() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a janela do mini-frame precisar ser acumulada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework para determinar se uma janela de mini-quadro deve ser desfeita. O recurso ROLLUP/rolldown será habilitado para uma janela de mini-quadro se contiver pelo menos um painel que tenha o sinalizador AFX_CBRS_AUTO_ROLLUP. Esse sinalizador é definido quando um painel é criado. Para obter mais informações, consulte [CBasePane:: CreateEx](../../mfc/reference/cbasepane-class.md#createex).

Por padrão, a estrutura verifica se o ponteiro do mouse está dentro do retângulo delimitador da janela do mini-quadro para determinar se a janela deve ser acumulada. Você pode substituir esse comportamento em uma classe derivada.

##  <a name="isrollup"></a>  CPaneFrameWnd::IsRollUp

Determina se uma janela de mini-quadro deve ser acumulada.

```
virtual BOOL IsRollUp() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a janela do mini-frame precisar ser acumulada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework para determinar se uma janela de mini-quadro deve ser acumulada. O recurso ROLLUP/rolldown será habilitado para uma janela de mini-quadro se contiver pelo menos um painel que tenha o sinalizador AFX_CBRS_AUTO_ROLLUP. Esse sinalizador é definido quando um painel é criado. Para obter mais informações, consulte [CBasePane:: CreateEx](../../mfc/reference/cbasepane-class.md#createex).

Por padrão, a estrutura verifica se o ponteiro do mouse está dentro do retângulo delimitador da janela do mini-quadro para determinar se a janela deve ser acumulada. Você pode substituir esse comportamento em uma classe derivada.

##  <a name="killdockingtimer"></a>  CPaneFrameWnd::KillDockingTimer

Interrompe o timer de encaixe.

```
void KillDockingTimer();
```

##  <a name="loadstate"></a>CPaneFrameWnd:: LoadState

Carrega o estado do painel do registro.

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
no O nome do perfil.

*uiID*<br/>
no A ID do painel.

### <a name="return-value"></a>Valor de retorno

TRUE se o estado do painel tiver sido carregado com êxito; caso contrário, FALSE.

##  <a name="m_busesavebits"></a>  CPaneFrameWnd::m_bUseSaveBits

Especifica se é para registrar a classe de janela que tem o estilo de classe CS_SAVEBITS.

```
AFX_IMPORT_DATA static BOOL m_bUseSaveBits;
```

### <a name="remarks"></a>Comentários

Defina esse membro estático como TRUE para registrar a classe de janela do mini-quadro que tem o estilo CS_SAVEBITS. Isso pode ajudar a reduzir a oscilação quando um usuário arrasta a janela de mini quadros.

##  <a name="onbeforedock"></a>  CPaneFrameWnd::OnBeforeDock

Determina se o encaixe é possível.

```
virtual BOOL OnBeforeDock();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o encaixe for possível; caso contrário, FALSE.

##  <a name="oncheckrollstate"></a>  CPaneFrameWnd::OnCheckRollState

Determina se uma janela de mini-quadro deve ser acumulada ou reduzida.

```
virtual void OnCheckRollState();
```

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework para determinar se uma janela de mini-quadro deve ser acumulada ou reduzida.

Por padrão, a estrutura chama [CPaneFrameWnd:: IsRollUp](#isrollup) e [CPaneFrameWnd:: IsRollDown](#isrolldown) e apenas amplia ou restaura a janela do mini-frame. Você pode substituir esse método em uma classe derivada para usar um efeito visual diferente.

##  <a name="ondocktorecentpos"></a>  CPaneFrameWnd::OnDockToRecentPos

Encaixa a janela de mini-quadro em sua posição mais recente.

```
virtual void OnDockToRecentPos();
```

##  <a name="ondrawborder"></a>  CPaneFrameWnd::OnDrawBorder

Desenha as bordas de uma janela de mini-quadro.

```
virtual void OnDrawBorder(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo usado para desenhar a borda.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework para desenhar as bordas da janela de mini-quadro.

##  <a name="onkillrolluptimer"></a>  CPaneFrameWnd::OnKillRollUpTimer

Interrompe o timer de ROLLUP.

```
virtual void OnKillRollUpTimer();
```

##  <a name="onmovepane"></a>  CPaneFrameWnd::OnMovePane

Move a janela do mini-quadro por um deslocamento especificado.

```
virtual void OnMovePane(
    CPane* pBar,
    CPoint ptOffset);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
no Um ponteiro para um painel (ignorado).

*ptOffset*<br/>
no O deslocamento pelo qual mover o painel.

##  <a name="onpanerecalclayout"></a>  CPaneFrameWnd::OnPaneRecalcLayout

Ajusta o layout de um painel dentro de uma janela de mini-quadro.

```
virtual void OnPaneRecalcLayout();
```

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando ele deve ajustar o layout de um painel dentro da janela do mini-quadro.

Por padrão, o painel é posicionado para cobrir a área completa do cliente da janela de mini-quadro.

##  <a name="onsetrolluptimer"></a>  CPaneFrameWnd::OnSetRollUpTimer

Define o timer de ROLLUP.

```
virtual void OnSetRollUpTimer();
```

##  <a name="onshowpane"></a>  CPaneFrameWnd::OnShowPane

Chamado pelo Framework quando um painel na janela do mini-quadro é ocultado ou exibido.

```
virtual void OnShowPane(
    CDockablePane* pBar,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
no O painel que está sendo mostrado ou oculto.

*bShow*<br/>
no TRUE se o painel estiver sendo mostrado; FALSE se o painel estiver sendo ocultado.

### <a name="remarks"></a>Comentários

Chamado pelo Framework quando um painel na janela do mini-quadro é mostrado ou ocultado. A implementação padrão não faz nada.

##  <a name="pin"></a>  CPaneFrameWnd::Pin

```
void Pin(BOOL bPin = TRUE);
```

### <a name="parameters"></a>Parâmetros

no *bPin*<br/>

### <a name="remarks"></a>Comentários

##  <a name="panefrompoint"></a>  CPaneFrameWnd::PaneFromPoint

Retorna um painel se ele contiver um ponto fornecido pelo usuário dentro de uma janela de mini-quadro.

```
virtual CBasePane* PaneFromPoint(
    CPoint point,
    int nSensitivity,
    BOOL bCheckVisibility);
```

### <a name="parameters"></a>Parâmetros

*point*<br/>
no O ponto em que o usuário clicou em coordenadas de tela.

*nSensitivity*<br/>
no Esse parâmetro não é usado.

*bCheckVisibility*<br/>
no TRUE para especificar que somente os painéis visíveis devem ser retornados; caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

O painel no qual o usuário clicou, ou nulo, se nenhum painel existir nesse local.

### <a name="remarks"></a>Comentários

Chame esse método para obter um painel que contém o ponto determinado.

##  <a name="redrawall"></a>  CPaneFrameWnd::RedrawAll

Redesenha todas as janelas de mini quadros.

```
static void RedrawAll();
```

### <a name="remarks"></a>Comentários

Esse método atualiza todas as janelas de mini quadros chamando [CWnd:: RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) para cada janela.

##  <a name="removenonvalidpanes"></a>  CPaneFrameWnd::RemoveNonValidPanes

Chamado pelo Framework para remover painéis não válidos.

```
virtual void RemoveNonValidPanes();
```

##  <a name="removepane"></a>  CPaneFrameWnd::RemovePane

Remove um painel da janela de mini-quadro.

```
virtual void RemovePane(
    CBasePane* pWnd,
    BOOL bDestroy = FALSE,
    BOOL bNoDelayedDestroy = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Um ponteiro para o painel a ser removido.

*bDestroy*<br/>
no Especifica o que acontece com a janela de mini-quadro. Se *bDestroy* for true, esse método destruirá a janela de mini-quadro imediatamente. Se for FALSE, esse método destruirá a janela de mini-quadro após um determinado atraso.

*bNoDelayedDestroy*<br/>
no Se for TRUE, a destruição atrasada será desabilitada. Se for FALSE, a destruição atrasada será habilitada.

### <a name="remarks"></a>Comentários

A estrutura pode destruir janelas de mini quadros imediatamente ou após um determinado atraso. Se você quiser atrasar a destruição de janelas de mini quadros, passe FALSE no parâmetro *bNoDelayedDestroy* . A destruição atrasada ocorre quando a estrutura processa a mensagem AFX_WM_CHECKEMPTYMINIFRAME.

##  <a name="replacepane"></a>  CPaneFrameWnd::ReplacePane

Substitui um painel por outro.

```
virtual void ReplacePane(
    CBasePane* pBarOrg,
    CBasePane* pBarReplaceWith);
```

### <a name="parameters"></a>Parâmetros

*pBarOrg*<br/>
no Um ponteiro para o painel original.

*pBarReplaceWith*<br/>
no Um ponteiro para o painel que substitui o painel original.

##  <a name="savestate"></a>  CPaneFrameWnd::SaveState

Salva o estado do painel no registro.

```
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
no O nome do perfil.

*uiID*<br/>
no A ID do painel.

### <a name="return-value"></a>Valor de retorno

TRUE se o estado do painel foi salvo com êxito; caso contrário, FALSE.

##  <a name="setcaptionbuttons"></a>CPaneFrameWnd::SetCaptionButtons

Define botões de legenda.

```
virtual void SetCaptionButtons(DWORD dwButtons);
```

### <a name="parameters"></a>Parâmetros

*dwButtons*<br/>
no Combinação bit-a-OR dos seguintes valores:

- AFX_CAPTION_BTN_CLOSE

- AFX_CAPTION_BTN_PIN

- AFX_CAPTION_BTN_MENU

- AFX_CAPTION_BTN_CUSTOMIZE

##  <a name="setdelayshow"></a>  CPaneFrameWnd::SetDelayShow

```
void SetDelayShow(BOOL bDelayShow);
```

### <a name="parameters"></a>Parâmetros

no *bDelayShow*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setdockingmanager"></a>  CPaneFrameWnd::SetDockingManager

```
void SetDockingManager(CDockingManager* pManager);
```

### <a name="parameters"></a>Parâmetros

no *pManager*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setdockingtimer"></a>  CPaneFrameWnd::SetDockingTimer

Define o timer de encaixe.

```
void SetDockingTimer(UINT nTimeOut);
```

### <a name="parameters"></a>Parâmetros

*nTimeOut*<br/>
no Valor de tempo limite em milissegundos.

##  <a name="setdockstate"></a>  CPaneFrameWnd::SetDockState

Define o estado de encaixe.

```
virtual void SetDockState(CDockingManager* pDockManager);
```

### <a name="parameters"></a>Parâmetros

*pDockManager*<br/>
no Um ponteiro para um Gerenciador de encaixe.

##  <a name="sethotpoint"></a>  CPaneFrameWnd::SetHotPoint

```
void SetHotPoint(CPoint& ptNew);
```

### <a name="parameters"></a>Parâmetros

[in] *ptNew*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setpredockstate"></a>  CPaneFrameWnd::SetPreDockState

Chamado pelo Framework para definir o estado de acoplamento.

```
virtual BOOL SetPreDockState(
    AFX_PREDOCK_STATE preDockState,
    CBasePane* pBarToDock = NULL,
    AFX_DOCK_METHOD dockMethod = DM_MOUSE);
```

### <a name="parameters"></a>Parâmetros

*preDockState*<br/>
no Valores possíveis:

- PDS_NOTHING,

- PDS_DOCK_REGULAR,

- PDS_DOCK_TO_TAB

*pBarToDock*<br/>
no Um ponteiro para o painel a ser encaixado.

*dockMethod*<br/>
no O método de encaixe. (Esse parâmetro é ignorado.)

### <a name="return-value"></a>Valor de retorno

TRUE se a janela do mini-frame estiver desencaixada; FALSE se estiver encaixado.

##  <a name="sizetocontent"></a>  CPaneFrameWnd::SizeToContent

Ajusta o tamanho de uma janela de mini-quadro para que ela seja equivalente a um painel contido.

```
virtual void SizeToContent();
```

### <a name="remarks"></a>Comentários

Chame esse método para ajustar o tamanho de uma janela de mini-quadro ao tamanho de um painel contido.

##  <a name="starttearoff"></a>  CPaneFrameWnd::StartTearOff

Deslágrimasu um menu.

```
BOOL StartTearOff(CMFCPopu* pMenu);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
no Um ponteiro para um menu.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

##  <a name="storerecentdocksiteinfo"></a>  CPaneFrameWnd::StoreRecentDockSiteInfo

```
virtual void StoreRecentDockSiteInfo(CPane* pBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pBar*<br/>

### <a name="remarks"></a>Comentários

##  <a name="storerecenttabrelatedinfo"></a>  CPaneFrameWnd::StoreRecentTabRelatedInfo

```
virtual void StoreRecentTabRelatedInfo(
    CDockablePane* pDockingBar,
    CDockablePane* pTabbedBar);
```

### <a name="parameters"></a>Parâmetros

[in] *pDockingBar*<br/>
[in] *pTabbedBar*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
