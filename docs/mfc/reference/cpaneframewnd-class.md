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
ms.openlocfilehash: 02eee13928979a7d220ce03f9f61c789c6320b6e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364106"
---
# <a name="cpaneframewnd-class"></a>Classe CPaneFrameWnd

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

Implementa uma janela de mini-quadro que contém um painel. O painel preenche a área do cliente da janela.

## <a name="syntax"></a>Sintaxe

```
class CPaneFrameWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaneFrameWnd::AddPane](#addpane)|Adiciona um painel.|
|[CPaneFrameWnd::AddRemovePaneFromGlobalList](#addremovepanefromgloballist)|Adiciona ou remove um painel da lista global.|
|[CPaneFrameWnd::AdjustLayout](#adjustlayout)|Ajusta o layout da janela do miniquadro.|
|[CPaneFrameWnd::AdjustPaneFrames](#adjustpaneframes)||
|[CPaneFrameWnd::CalcBorderSize](#calcbordersize)|Calcula o tamanho das bordas para uma janela de mini-quadro.|
|[CPaneFrameWnd::CalcExpectedDockedRect](#calcexpecteddockedrect)|Calcule o retângulo esperado de uma janela ancorada.|
|[CPaneFrameWnd::CanBeAttached](#canbeattached)|Determina se o painel atual pode ser encaixado em outro painel ou janela de quadro.|
|[CPaneFrameWnd::CanBeDockedToPane](#canbedockedtopane)|Determina se a janela do miniquadro pode ser encaixada em um painel.|
|[CPaneFrameWnd::CheckGripperVisibilidade](#checkgrippervisibility)||
|[CPaneFrameWnd::ConvertTo'TbedDocument](#converttotabbeddocument)|Converte o painel em um documento com guias.|
|[CPaneFrameWnd::Criar](#create)|Cria uma janela de miniquadro e `CPaneFrameWnd` a anexa ao objeto.|
|[CPaneFrameWnd::CreateEx](#createex)|Cria uma janela de miniquadro e `CPaneFrameWnd` a anexa ao objeto.|
|[CPaneFrameWnd::DockPane](#dockpane)|Acopla o painel.|
|[CPaneFrameWnd::FindFloatingPaneByID](#findfloatingpanebyid)|Encontra um painel com o ID de controle especificado na lista global de painéis flutuantes.|
|[CPaneFrameWnd::FrameFromPoint](#framefrompoint)|Encontra a janela de mini-quadro contendo um ponto fornecido pelo usuário.|
|[CPaneFrameWnd::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda da janela do miniquadro.|
|[CPaneFrameWnd::GetCaptionRect](#getcaptionrect)|Calcula o retângulo delimitador de uma legenda de janela de miniquadro.|
|[CPaneFrameWnd::GetCaptionText](#getcaptiontext)|Retorna o texto da legenda.|
|[CPaneFrameWnd::GetDockingManager](#getdockingmanager)||
|[CPaneFrameWnd::GetDockingMode](#getdockingmode)|Retorna o modo de acoplamento.|
|[CPaneFrameWnd::GetFirstVisiblePane](#getfirstvisiblepane)|Retorna o primeiro painel visível que está contido em uma janela de mini-quadro.|
|[CPaneFrameWnd::GetHotPoint](#gethotpoint)||
|[CPaneFrameWnd::GetPane](#getpane)|Retorna um painel que está contido na janela do miniquadro.|
|[CPaneFrameWnd::GetPaneCount](#getpanecount)|Retorna o número de painéis que estão contidos em uma janela de mini-quadro.|
|[CPaneFrameWnd::GetParent](#getparent)||
|[CPaneFrameWnd::GetPinState](#getpinstate)||
|[CPaneFrameWnd::GetRecentFloatingRect](#getrecentfloatingrect)||
|[CPaneFrameWnd::GetVisiblePaneCount](#getvisiblepanecount)|Retorna o número de painéis visíveis que estão contidos em uma janela de mini-quadro.|
|[CPaneFrameWnd::HitTest](#hittest)|Determina qual parte de uma janela de miniquadro está em um dado ponto.|
|[CPaneFrameWnd::IsCaptured](#iscaptured)||
|[CPaneFrameWnd::IsDelayShow](#isdelayshow)||
|[CPaneFrameWnd::IsRollDown](#isrolldown)|Determina se uma janela de miniquadro deve ser rolada para baixo.|
|[CPaneFrameWnd::IsRollUp](#isrollup)|Determina se uma janela de miniquadro deve ser enrolada.|
|[CPaneFrameWnd::KillDockingTimer](#killdockingtimer)|Pára o temporizador de acoplamento.|
|[CPaneFrameWnd::LoadState](#loadstate)|Carrega o estado do painel do registro.|
|[CPaneFrameWnd::OnBeforeDock](#onbeforedock)|Determina se o encaixe é possível.|
|[CPaneFrameWnd::OnDockToRecentPos](#ondocktorecentpos)|Encaixa a janela do miniquadro em sua posição mais recente.|
|[CPaneFrameWnd::OnKillRollUpTimer](#onkillrolluptimer)|Pára o temporizador de rollup.|
|[CPaneFrameWnd::OnMovePane](#onmovepane)|Move a janela do miniquadro por um deslocamento especificado.|
|[CPaneFrameWnd::OnPaneRecalcLayout](#onpanerecalclayout)|Ajusta o layout de um painel contido.|
|[CPaneFrameWnd::OnSetRollUpTimer](#onsetrolluptimer)|Define o temporizador de rollup.|
|[CPaneFrameWnd::OnShowPane](#onshowpane)|Chamado pela estrutura quando um painel na janela do miniquadro é oculto ou exibido.|
|[CPaneFrameWnd::PaneFromPoint](#panefrompoint)|Retorna um painel se ele contiver um ponto fornecido pelo usuário dentro de uma janela de miniquadro.|
|[CPaneFrameWnd::Pin](#pin)||
|`CPaneFrameWnd::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para traduzir mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows.|
|[CPaneFrameWnd::RedrawAll](#redrawall)|Redesenha todas as janelas de mini-quadros.|
|[CPaneFrameWnd::RemoveNonValidPanes](#removenonvalidpanes)|Chamado pelo framework para remover painéis não válidos.|
|[CPaneFrameWnd::RemovePane](#removepane)|Remove um painel da janela do miniquadro.|
|[CPaneFrameWnd::ReplacePane](#replacepane)|Substitui um painel por outro.|
|[CPaneFrameWnd::SaveState](#savestate)|Salva o estado do painel para o registro.|
|`CPaneFrameWnd::Serialize`|Lê ou escreve este objeto de ou para um arquivo.|
|[CPaneFrameWnd::SetCaptionButtons](#setcaptionbuttons)|Define botões de legenda.|
|[CPaneFrameWnd::SetDelayShow](#setdelayshow)||
|[CPaneFrameWnd::SetDockingManager](#setdockingmanager)||
|[CPaneFrameWnd::SetDockingTimer](#setdockingtimer)|Define o temporizador de acoplamento.|
|[CPaneFrameWnd::SetDockState](#setdockstate)|Define o estado de acoplamento.|
|[CPaneFrameWnd::SetHotPoint](#sethotpoint)||
|[CPaneFrameWnd::SetPreDockState](#setpredockstate)|Chamado pelo quadro para definir o estado de pré-docking.|
|[CPaneFrameWnd::SizeToContent](#sizetocontent)|Ajusta o tamanho de uma janela de miniquadro para que seja equivalente em tamanho a um painel contido.|
|[CPaneFrameWnd::StartTearOff](#starttearoff)|Tira o cardápio.|
|[CPaneFrameWnd::StoreRecentDockSiteInfo](#storerecentdocksiteinfo)||
|[CPaneFrameWnd::StoreRecentTabRelatedInfo](#storerecenttabrelatedinfo)||

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CPaneFrameWnd::OnCheckRollState](#oncheckrollstate)|Determina se uma janela de miniquadro deve ser enrolada para cima ou para baixo.|
|[CPaneFrameWnd::OnDrawBorder](#ondrawborder)|Desenha as bordas de uma janela de mini-quadros.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CPaneFrameWnd::m_bUseSaveBits](#m_busesavebits)|Especifica se deve registrar a classe de janela com o estilo de classe CS_SAVEBITS.|

## <a name="remarks"></a>Comentários

A estrutura cria `CPaneFrameWnd` automaticamente um objeto quando um painel é trocado de um estado ancorado para um estado flutuante.

Uma janela de miniquadro pode ser arrastada com seu conteúdo visível (acoplamento imediato) ou usando um retângulo de arrasto (acoplamento padrão). O modo de acoplamento do painel de recipiente do miniquadro determina o comportamento de arrasto do miniquadro. Para obter mais informações, consulte [CBasePane::GetDockingMode](../../mfc/reference/cbasepane-class.md#getdockingmode).

Uma janela de miniquadro exibe botões na legenda de acordo com o estilo de painel contido. Se o painel puder ser fechado [(CBasePane::CanBeClosed),](../../mfc/reference/cbasepane-class.md#canbeclosed)ele exibirá um botão Fechar. Se o painel tiver o estilo AFX_CBRS_AUTO_ROLLUP, ele exibe um pino.

Se você deriva `CPaneFrameWnd`ruma classe de , você deve dizer à estrutura como criá-la. Crie a classe substituindo [CPane::CreateDefaultMiniframe](../../mfc/reference/cpane-class.md#createdefaultminiframe)ou `CPane::m_pMiniFrameRTC` defina o membro de modo que ele aponte para as informações da classe de tempo de execução para sua classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CPaneFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxPaneFrameWnd.h

## <a name="cpaneframewndaddpane"></a><a name="addpane"></a>CPaneFrameWnd::AddPane

Adiciona um painel.

```
virtual void AddPane(CBasePane* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] O painel para adicionar.

## <a name="cpaneframewndaddremovepanefromgloballist"></a><a name="addremovepanefromgloballist"></a>CPaneFrameWnd::AddRemovePaneFromGlobalList

Adiciona ou remove um painel da lista global.

```
static BOOL __stdcall AddRemovePaneFromGlobalList(
    CBasePane* pWnd,
    BOOL bAdd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] O painel para adicionar ou remover.

*bAdd*<br/>
[em] Se não for zero, adicione o painel. Se 0, remova o painel.

### <a name="return-value"></a>Valor retornado

Não zero se o método foi bem sucedido; caso contrário, 0.

## <a name="cpaneframewndadjustlayout"></a><a name="adjustlayout"></a>CPaneFrameWnd::AdjustLayout

Ajusta o layout da janela do miniquadro.

```
virtual void AdjustLayout();
```

## <a name="cpaneframewndadjustpaneframes"></a><a name="adjustpaneframes"></a>CPaneFrameWnd::AdjustPaneFrames

```
virtual void AdjustPaneFrames();
```

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndcalcbordersize"></a><a name="calcbordersize"></a>CPaneFrameWnd::CalcBorderSize

Calcula o tamanho das bordas para uma janela de miniquadro.

```
virtual void CalcBorderSize(CRect& rectBorderSize) const;
```

### <a name="parameters"></a>Parâmetros

*rectBorderSize*<br/>
[fora] Contém o tamanho, em pixels, da borda da janela de miniquadro.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura para calcular o tamanho da borda de uma janela de miniquadro. O tamanho retornado depende se uma janela de miniquadro contém uma barra de ferramentas ou um [CDockablePane](../../mfc/reference/cdockablepane-class.md).

## <a name="cpaneframewndcalcexpecteddockedrect"></a><a name="calcexpecteddockedrect"></a>CPaneFrameWnd::CalcExpectedDockedRect

Calcule o retângulo esperado de uma janela ancorada.

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
[em] Um ponteiro para a janela para acoplar.

*ptMouse*<br/>
[em] A localização do rato.

*rectResult*<br/>
[fora] O retângulo calculado.

*bDrawTab*<br/>
[fora] Se TRUE, desenhe uma guia. Se FALSO, não desenhe uma guia.

*ppTargetBar*<br/>
[fora] Um ponteiro para o painel alvo.

### <a name="remarks"></a>Comentários

Este método calcula o retângulo que uma janela ocuparia se um usuário arrastasse a janela até o ponto especificado pelo *ptMouse* e a encaixasse lá.

## <a name="cpaneframewndcanbeattached"></a><a name="canbeattached"></a>CPaneFrameWnd::CanBeAttached

Determina se o painel atual pode ser encaixado em outro painel ou janela de quadro.

```
virtual BOOL CanBeAttached() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se o painel pode ser ancorado em outro painel ou janela de quadro; caso contrário, FALSO.

## <a name="cpaneframewndcanbedockedtopane"></a><a name="canbedockedtopane"></a>CPaneFrameWnd::CanBeDockedToPane

Determina se a janela do miniquadro pode ser encaixada em um painel.

```
virtual BOOL CanBeDockedToPane(const CDockablePane* pDockingBar) const;
```

### <a name="parameters"></a>Parâmetros

*pDockingBar*<br/>
[em] Um painel.

### <a name="return-value"></a>Valor retornado

Não zero se o miniquadro puder ser encaixado *em pDockingBar*; caso contrário, 0.

## <a name="cpaneframewndcheckgrippervisibility"></a><a name="checkgrippervisibility"></a>CPaneFrameWnd::CheckGripperVisibilidade

```
virtual void CheckGripperVisibility();
```

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndconverttotabbeddocument"></a><a name="converttotabbeddocument"></a>CPaneFrameWnd::ConvertTo'TbedDocument

Converte o painel em um documento com guias.

```
virtual void ConvertToTabbedDocument();
```

## <a name="cpaneframewndcreate"></a><a name="create"></a>CPaneFrameWnd::Criar

Cria uma janela de miniquadro e a anexa ao objeto [CPaneFrameWnd.](../../mfc/reference/cpaneframewnd-class.md)

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
[em] Especifica o texto a ser exibido na janela do miniquadro.

*Dwstyle*<br/>
[em] Especifica o estilo da janela. Para obter mais informações, consulte [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*Rect*<br/>
[em] Especifica o tamanho e a posição iniciais da janela do miniquadro.

*Pparentwnd*<br/>
[dentro, fora] Especifica o quadro pai da janela de miniquadro. Este valor não deve ser NULO.

*pContext*<br/>
[dentro, fora] Especifica o contexto definido pelo usuário.

### <a name="return-value"></a>Valor retornado

VERDADE se a janela foi criada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Uma janela de miniquadro é criada em dois passos. Primeiro, a estrutura `CPaneFrameWnd` cria um objeto. Em segundo `Create` lugar, ele chama para criar a `CPaneFrameWnd` janela de miniquadro do Windows e anexá-la ao objeto.

## <a name="cpaneframewndcreateex"></a><a name="createex"></a>CPaneFrameWnd::CreateEx

Cria uma janela de miniquadro e a anexa ao objeto [CPaneFrameWnd.](../../mfc/reference/cpaneframewnd-class.md)

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
[em] Especifica o estilo de janela estendida. Para obter mais informações, consulte [Estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles)

*lpszWindowName*<br/>
[em] Especifica o texto a ser exibido na janela do miniquadro.

*Dwstyle*<br/>
[em] Especifica o estilo da janela. Para obter mais informações, consulte [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

*Rect*<br/>
[em] Especifica o tamanho e a posição iniciais da janela do miniquadro.

*Pparentwnd*<br/>
[dentro, fora] Especifica o quadro pai da janela de miniquadro. Este valor não deve ser NULO.

*pContext*<br/>
[dentro, fora] Especifica o contexto definido pelo usuário.

### <a name="return-value"></a>Valor retornado

VERDADE se a janela foi criada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Uma janela de miniquadro é criada em dois passos. Primeiro, a estrutura `CPaneFrameWnd` cria um objeto. Em segundo `Create` lugar, ele chama para criar a `CPaneFrameWnd` janela de miniquadro do Windows e anexá-la ao objeto.

## <a name="cpaneframewnddockpane"></a><a name="dockpane"></a>CPaneFrameWnd::DockPane

Acopla o painel.

```
virtual CDockablePane* DockPane(BOOL& bWasDocked);
```

### <a name="parameters"></a>Parâmetros

*bWasDocked*<br/>
[fora] VERDADE se o painel já estava ancorado; caso contrário, FALSO.

### <a name="return-value"></a>Valor retornado

Se a operação foi `CDockablePane` bem sucedida, o que o painel foi ancorado para; caso contrário, NULL.

## <a name="cpaneframewndfindfloatingpanebyid"></a><a name="findfloatingpanebyid"></a>CPaneFrameWnd::FindFloatingPaneByID

Encontra um painel com o ID de controle especificado na lista global de painéis flutuantes.

```
static CBasePane* FindFloatingPaneByID(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] Representa a id de controle do painel para encontrar.

### <a name="return-value"></a>Valor retornado

O painel com o ID de controle especificado; caso contrário, NULL, se nenhum painel tiver o ID de controle especificado.

## <a name="cpaneframewndframefrompoint"></a><a name="framefrompoint"></a>CPaneFrameWnd::FrameFromPoint

Encontra a janela de mini-quadro que contém o ponto especificado.

```
static CPaneFrameWnd* __stdcall FrameFromPoint(
    CPoint pt,
    int nSensitivity,
    CPaneFrameWnd* pFrameToExclude = NULL,
    BOOL bFloatMultiOnly = FALSE);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
[em] O ponto, nas coordenadas da tela.

*nSensibilidade*<br/>
[em] Aumente a área de pesquisa da janela de mini-quadros por este tamanho. Uma janela de mini-quadro satisfaz os critérios de pesquisa se o ponto dado cair na área aumentada.

*pFrameParaexcluir*<br/>
[em] Especifica uma janela de miniquadro para excluir da pesquisa.

*bFloatMultiOnly*<br/>
[em] Se TRUE, procure apenas janelas de miniquadros que tenham o estilo CBRS_FLOAT_MULTI. Se FALSO, procure em todas as janelas de mini-quadros.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela de miniquadro que contém *pt;* caso contrário, NULL.

## <a name="cpaneframewndgetcaptionheight"></a><a name="getcaptionheight"></a>CPaneFrameWnd::GetCaptionHeight

Retorna a altura da legenda da janela do miniquadro.

```
virtual int GetCaptionHeight() const;
```

### <a name="return-value"></a>Valor retornado

A altura, em pixels, da janela do miniquadro.

### <a name="remarks"></a>Comentários

Chame este método para determinar a altura de uma janela de mini-quadro. Por padrão, a altura é definida como SM_CYSMCAPTION. Para obter mais informações, consulte [GetSystemMetrics Function](/windows/win32/api/winuser/nf-winuser-getsystemmetrics).

## <a name="cpaneframewndgetcaptionrect"></a><a name="getcaptionrect"></a>CPaneFrameWnd::GetCaptionRect

Calcula o retângulo delimitador de uma legenda de janela de miniquadro.

```
virtual void GetCaptionRect(CRect& rectCaption) const;
```

### <a name="parameters"></a>Parâmetros

*rectCaption*<br/>
[fora] Contém o tamanho e a posição da legenda da janela do miniquadro, nas coordenadas da tela.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura para calcular o retângulo delimitador de uma legenda de janela de miniquadro.

## <a name="cpaneframewndgetcaptiontext"></a><a name="getcaptiontext"></a>CPaneFrameWnd::GetCaptionText

Retorna o texto da legenda.

```
virtual CString GetCaptionText();
```

### <a name="return-value"></a>Valor retornado

O texto da legenda da janela do miniquadro.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura quando exibe o texto da legenda.

## <a name="cpaneframewndgetdockingmanager"></a><a name="getdockingmanager"></a>CPaneFrameWnd::GetDockingManager

```
CDockingManager* GetDockingManager() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetdockingmode"></a><a name="getdockingmode"></a>CPaneFrameWnd::GetDockingMode

Retorna o modo de acoplamento.

```
virtual AFX_DOCK_TYPE GetDockingMode() const;
```

### <a name="return-value"></a>Valor retornado

O modo de acoplamento. Um dos seguintes valores:

- DT_STANDARD

- DT_IMMEDIATE

- DT_SMART

## <a name="cpaneframewndgetfirstvisiblepane"></a><a name="getfirstvisiblepane"></a>CPaneFrameWnd::GetFirstVisiblePane

Retorna o primeiro painel visível que está contido em uma janela de mini-quadro.

```
virtual CWnd* GetFirstVisiblePane() const;
```

### <a name="return-value"></a>Valor retornado

O primeiro painel na janela do miniquadro, ou NULL, se a janela do miniquadro não contiver painéis.

## <a name="cpaneframewndgethotpoint"></a><a name="gethotpoint"></a>CPaneFrameWnd::GetHotPoint

```
CPoint GetHotPoint() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetpane"></a><a name="getpane"></a>CPaneFrameWnd::GetPane

Retorna um painel que está contido na janela do miniquadro.

```
virtual CWnd* GetPane() const;
```

### <a name="return-value"></a>Valor retornado

O painel que está contido no miniquadro, ou NULL se a janela do miniquadro não contiver painéis.

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetpanecount"></a><a name="getpanecount"></a>CPaneFrameWnd::GetPaneCount

Retorna o número de painéis que estão contidos em uma janela de mini-quadro.

```
virtual int GetPaneCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de painéis na janela do miniquadro. Esse valor pode ser zero.

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetparent"></a><a name="getparent"></a>CPaneFrameWnd::GetParent

```
CWnd* GetParent();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetpinstate"></a><a name="getpinstate"></a>CPaneFrameWnd::GetPinState

```
BOOL GetPinState() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetrecentfloatingrect"></a><a name="getrecentfloatingrect"></a>CPaneFrameWnd::GetRecentFloatingRect

```
CRect GetRecentFloatingRect() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndgetvisiblepanecount"></a><a name="getvisiblepanecount"></a>CPaneFrameWnd::GetVisiblePaneCount

Retorna o número de painéis visíveis que estão contidos em uma janela de mini-quadro.

```
virtual int GetVisiblePaneCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de painéis visíveis.

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndhittest"></a><a name="hittest"></a>CPaneFrameWnd::HitTest

Determina qual parte de uma janela de miniquadro está em um dado ponto.

```
virtual LRESULT HitTest(
    CPoint point,
    BOOL bDetectCaption);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] O ponto a ser testado.

*bDetectcaption*<br/>
[em] Se TRUE, verifique o ponto contra a legenda. Se FALSO, ignore a legenda.

### <a name="return-value"></a>Valor retornado

Um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|Htnowhere|O ponto está fora da janela do mini-quadro.|
|HTCLIENT|A questão é na área do cliente.|
|Htcaption|A questão está na legenda.|
|HTTOP|O ponto está no topo.|
|HTTOPLEFT|O ponto é no canto superior esquerdo.|
|HTTOPRIGHT|O ponto está no canto superior direito.|
|HTLEFT|O ponto é à esquerda.|
|HTRIGHT|O ponto é à direita.|
|HTBOTTOM|A questão é a parte de baixo.|
|HTBOTTOMLEFT|A questão é no canto inferior esquerdo.|
|HTBOTTOMRIGHT|A questão é no canto inferior direito.|

## <a name="cpaneframewndiscaptured"></a><a name="iscaptured"></a>CPaneFrameWnd::IsCaptured

```
BOOL IsCaptured() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndisdelayshow"></a><a name="isdelayshow"></a>CPaneFrameWnd::IsDelayShow

```
BOOL IsDelayShow() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndisrolldown"></a><a name="isrolldown"></a>CPaneFrameWnd::IsRollDown

Determina se uma janela de miniquadro deve ser rolada para baixo.

```
virtual BOOL IsRollDown() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a janela do miniquadro deve ser rolada para baixo; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura para determinar se uma janela de miniquadro deve ser rolada para baixo. O recurso rollup/rolldown está habilitado para uma janela de mini-quadro se contiver pelo menos um painel que tenha a bandeira AFX_CBRS_AUTO_ROLLUP. Esta bandeira é definida quando um painel é criado. Para obter mais informações, consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).

Por padrão, a estrutura verifica se o ponteiro do mouse está dentro do retângulo delimitador da janela do miniquadro para determinar se a janela deve ser rolada para baixo. Você pode substituir esse comportamento em uma classe derivada.

## <a name="cpaneframewndisrollup"></a><a name="isrollup"></a>CPaneFrameWnd::IsRollUp

Determina se uma janela de miniquadro deve ser enrolada.

```
virtual BOOL IsRollUp() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a janela de mini-quadro deve ser enrolada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura para determinar se uma janela de miniquadro deve ser enrolada. O recurso rollup/rolldown está habilitado para uma janela de mini-quadro se contiver pelo menos um painel que tenha a bandeira AFX_CBRS_AUTO_ROLLUP. Esta bandeira é definida quando um painel é criado. Para obter mais informações, consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).

Por padrão, a estrutura verifica se o ponteiro do mouse está dentro do retângulo delimitador da janela do miniquadro para determinar se a janela deve ser enrolada. Você pode substituir esse comportamento em uma classe derivada.

## <a name="cpaneframewndkilldockingtimer"></a><a name="killdockingtimer"></a>CPaneFrameWnd::KillDockingTimer

Pára o temporizador de acoplamento.

```
void KillDockingTimer();
```

## <a name="cpaneframewndloadstate"></a><a name="loadstate"></a>CPaneFrameWnd::LoadState

Carrega o estado do painel do registro.

```
virtual BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] O nome do perfil.

*Uiid*<br/>
[em] O painel de ida.

### <a name="return-value"></a>Valor retornado

VERDADE se o estado do painel foi carregado com sucesso; caso contrário, FALSO.

## <a name="cpaneframewndm_busesavebits"></a><a name="m_busesavebits"></a>CPaneFrameWnd::m_bUseSaveBits

Especifica se deve registrar a classe de janela que tem o estilo de classe CS_SAVEBITS.

```
AFX_IMPORT_DATA static BOOL m_bUseSaveBits;
```

### <a name="remarks"></a>Comentários

Defina este membro estático como TRUE para registrar a classe de janela de miniquadro que tem o estilo CS_SAVEBITS. Isso pode ajudar a reduzir a cintilação quando um usuário arrasta a janela do miniquadro.

## <a name="cpaneframewndonbeforedock"></a><a name="onbeforedock"></a>CPaneFrameWnd::OnBeforeDock

Determina se o encaixe é possível.

```
virtual BOOL OnBeforeDock();
```

### <a name="return-value"></a>Valor retornado

VERDADE se o acoplamento for possível; caso contrário, FALSE.

## <a name="cpaneframewndoncheckrollstate"></a><a name="oncheckrollstate"></a>CPaneFrameWnd::OnCheckRollState

Determina se uma janela de miniquadro deve ser enrolada para cima ou para baixo.

```
virtual void OnCheckRollState();
```

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura para determinar se uma janela de mini-quadro deve ser enrolada ou para baixo.

Por padrão, a estrutura chama [CPaneFrameWnd::IsRollUp](#isrollup) e [CPaneFrameWnd::IsRollDown](#isrolldown) e apenas alonga ou restaura a janela do miniquadro. Você pode substituir este método em uma classe derivada para usar um efeito visual diferente.

## <a name="cpaneframewndondocktorecentpos"></a><a name="ondocktorecentpos"></a>CPaneFrameWnd::OnDockToRecentPos

Encaixa a janela do miniquadro em sua posição mais recente.

```
virtual void OnDockToRecentPos();
```

## <a name="cpaneframewndondrawborder"></a><a name="ondrawborder"></a>CPaneFrameWnd::OnDrawBorder

Desenha as bordas de uma janela de mini-quadros.

```
virtual void OnDrawBorder(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo usado para desenhar a fronteira.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura para desenhar as bordas da janela de mini-quadros.

## <a name="cpaneframewndonkillrolluptimer"></a><a name="onkillrolluptimer"></a>CPaneFrameWnd::OnKillRollUpTimer

Pára o temporizador de rollup.

```
virtual void OnKillRollUpTimer();
```

## <a name="cpaneframewndonmovepane"></a><a name="onmovepane"></a>CPaneFrameWnd::OnMovePane

Move a janela do miniquadro por um deslocamento especificado.

```
virtual void OnMovePane(
    CPane* pBar,
    CPoint ptOffset);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] Um ponteiro para um painel (ignorado).

*ptOffset*<br/>
[em] O deslocamento pelo qual mover o painel.

## <a name="cpaneframewndonpanerecalclayout"></a><a name="onpanerecalclayout"></a>CPaneFrameWnd::OnPaneRecalcLayout

Ajusta o layout de um painel dentro de uma janela de mini-quadro.

```
virtual void OnPaneRecalcLayout();
```

### <a name="remarks"></a>Comentários

A estrutura chama este método quando deve ajustar o layout de um painel dentro da janela do miniquadro.

Por padrão, o painel está posicionado para cobrir a área completa do cliente da janela de miniquadro.

## <a name="cpaneframewndonsetrolluptimer"></a><a name="onsetrolluptimer"></a>CPaneFrameWnd::OnSetRollUpTimer

Define o temporizador de rollup.

```
virtual void OnSetRollUpTimer();
```

## <a name="cpaneframewndonshowpane"></a><a name="onshowpane"></a>CPaneFrameWnd::OnShowPane

Chamado pela estrutura quando um painel na janela do miniquadro é oculto ou exibido.

```
virtual void OnShowPane(
    CDockablePane* pBar,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
[em] O painel que está sendo mostrado ou escondido.

*Bshow*<br/>
[em] VERDADE se o painel está sendo mostrado; FALSO se o painel está sendo escondido.

### <a name="remarks"></a>Comentários

Chamado pela estrutura quando um painel na janela do miniquadro é mostrado ou escondido. A implementação padrão não faz nada.

## <a name="cpaneframewndpin"></a><a name="pin"></a>CPaneFrameWnd::Pin

```
void Pin(BOOL bPin = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *bPin*<br/>

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndpanefrompoint"></a><a name="panefrompoint"></a>CPaneFrameWnd::PaneFromPoint

Retorna um painel se ele contiver um ponto fornecido pelo usuário dentro de uma janela de miniquadro.

```
virtual CBasePane* PaneFromPoint(
    CPoint point,
    int nSensitivity,
    BOOL bCheckVisibility);
```

### <a name="parameters"></a>Parâmetros

*Ponto*<br/>
[em] O ponto que o usuário clicou, em coordenadas de tela.

*nSensibilidade*<br/>
[em] Este parâmetro não é usado.

*bCheckVisibility*<br/>
[em] TRUE para especificar que apenas painéis visíveis devem ser devolvidos; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

O painel que o usuário clicou, ou NULL se não houver painel naquele local.

### <a name="remarks"></a>Comentários

Chame este método para obter um painel que contenha o ponto dado.

## <a name="cpaneframewndredrawall"></a><a name="redrawall"></a>CPaneFrameWnd::RedrawAll

Redesenha todas as janelas de mini-quadros.

```
static void RedrawAll();
```

### <a name="remarks"></a>Comentários

Este método atualiza todas as janelas de miniquadros chamando [CWnd::RedrawWindow](../../mfc/reference/cwnd-class.md#redrawwindow) para cada janela.

## <a name="cpaneframewndremovenonvalidpanes"></a><a name="removenonvalidpanes"></a>CPaneFrameWnd::RemoveNonValidPanes

Chamado pelo framework para remover painéis não válidos.

```
virtual void RemoveNonValidPanes();
```

## <a name="cpaneframewndremovepane"></a><a name="removepane"></a>CPaneFrameWnd::RemovePane

Remove um painel da janela do miniquadro.

```
virtual void RemovePane(
    CBasePane* pWnd,
    BOOL bDestroy = FALSE,
    BOOL bNoDelayedDestroy = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Um ponteiro para o painel para remover.

*bDestruir*<br/>
[em] Especifica o que acontece com a janela do miniquadro. Se *bDestroy* for TRUE, este método destruirá a janela do miniquadro imediatamente. Se for FALSE, este método destrói a janela do miniquadro após um certo atraso.

*bNoDelayedDestroy*<br/>
[em] Se VERDADEIRO, a destruição atrasada é desativada. Se FALSO, destruição retardada é habilitada.

### <a name="remarks"></a>Comentários

A estrutura pode destruir janelas de mini-quadros imediatamente ou após um certo atraso. Se você quiser atrasar a destruição de janelas de mini-quadros, passe FALSE no parâmetro *bNoDelayedDestroy.* A destruição retardada ocorre quando o quadro processa a mensagem AFX_WM_CHECKEMPTYMINIFRAME.

## <a name="cpaneframewndreplacepane"></a><a name="replacepane"></a>CPaneFrameWnd::ReplacePane

Substitui um painel por outro.

```
virtual void ReplacePane(
    CBasePane* pBarOrg,
    CBasePane* pBarReplaceWith);
```

### <a name="parameters"></a>Parâmetros

*pBarOrg*<br/>
[em] Um ponteiro para o painel original.

*pBarReplaceWith*<br/>
[em] Um ponteiro para o painel que substitui o painel original.

## <a name="cpaneframewndsavestate"></a><a name="savestate"></a>CPaneFrameWnd::SaveState

Salva o estado do painel para o registro.

```
virtual BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    UINT uiID = (UINT) -1);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] O nome do perfil.

*Uiid*<br/>
[em] O painel de ida.

### <a name="return-value"></a>Valor retornado

VERDADE se o estado do painel foi salvo com sucesso; caso contrário, FALSO.

## <a name="cpaneframewndsetcaptionbuttons"></a><a name="setcaptionbuttons"></a>CPaneFrameWnd::SetCaptionButtons

Define botões de legenda.

```
virtual void SetCaptionButtons(DWORD dwButtons);
```

### <a name="parameters"></a>Parâmetros

*dwButtons*<br/>
[em] Combinação bitwise-OR dos seguintes valores:

- AFX_CAPTION_BTN_CLOSE

- AFX_CAPTION_BTN_PIN

- AFX_CAPTION_BTN_MENU

- AFX_CAPTION_BTN_CUSTOMIZE

## <a name="cpaneframewndsetdelayshow"></a><a name="setdelayshow"></a>CPaneFrameWnd::SetDelayShow

```
void SetDelayShow(BOOL bDelayShow);
```

### <a name="parameters"></a>Parâmetros

[em] *bDelayShow*<br/>

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndsetdockingmanager"></a><a name="setdockingmanager"></a>CPaneFrameWnd::SetDockingManager

```
void SetDockingManager(CDockingManager* pManager);
```

### <a name="parameters"></a>Parâmetros

[em] *pManager*<br/>

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndsetdockingtimer"></a><a name="setdockingtimer"></a>CPaneFrameWnd::SetDockingTimer

Define o temporizador de acoplamento.

```
void SetDockingTimer(UINT nTimeOut);
```

### <a name="parameters"></a>Parâmetros

*nTimeOut*<br/>
[em] Valor de tempo em milissegundos.

## <a name="cpaneframewndsetdockstate"></a><a name="setdockstate"></a>CPaneFrameWnd::SetDockState

Define o estado de acoplamento.

```
virtual void SetDockState(CDockingManager* pDockManager);
```

### <a name="parameters"></a>Parâmetros

*gerente de pDock*<br/>
[em] Um ponteiro para um gerente de ancoragem.

## <a name="cpaneframewndsethotpoint"></a><a name="sethotpoint"></a>CPaneFrameWnd::SetHotPoint

```
void SetHotPoint(CPoint& ptNew);
```

### <a name="parameters"></a>Parâmetros

[em] *ptNovo*<br/>

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndsetpredockstate"></a><a name="setpredockstate"></a>CPaneFrameWnd::SetPreDockState

Chamado pelo quadro para definir o estado de pré-docking.

```
virtual BOOL SetPreDockState(
    AFX_PREDOCK_STATE preDockState,
    CBasePane* pBarToDock = NULL,
    AFX_DOCK_METHOD dockMethod = DM_MOUSE);
```

### <a name="parameters"></a>Parâmetros

*preDockState*<br/>
[em] Valores possíveis:

- PDS_NOTHING.

- PDS_DOCK_REGULAR

- PDS_DOCK_TO_TAB

*pBarToDock*<br/>
[em] Um ponteiro para o painel para acoplar.

*Dockmethod*<br/>
[em] O método de acoplamento. (Este parâmetro é ignorado.)

### <a name="return-value"></a>Valor retornado

VERDADE se a janela do miniquadro for desencaixada; FALSO se estiver ancorado.

## <a name="cpaneframewndsizetocontent"></a><a name="sizetocontent"></a>CPaneFrameWnd::SizeToContent

Ajusta o tamanho de uma janela de miniquadro para que seja equivalente a um painel contido.

```
virtual void SizeToContent();
```

### <a name="remarks"></a>Comentários

Chame este método para ajustar o tamanho de uma janela de mini-quadro para o tamanho de um painel contido.

## <a name="cpaneframewndstarttearoff"></a><a name="starttearoff"></a>CPaneFrameWnd::StartTearOff

Tira o cardápio.

```
BOOL StartTearOff(CMFCPopu* pMenu);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
[em] Um ponteiro para um menu.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSE.

## <a name="cpaneframewndstorerecentdocksiteinfo"></a><a name="storerecentdocksiteinfo"></a>CPaneFrameWnd::StoreRecentDockSiteInfo

```
virtual void StoreRecentDockSiteInfo(CPane* pBar);
```

### <a name="parameters"></a>Parâmetros

[em] *pBar*<br/>

### <a name="remarks"></a>Comentários

## <a name="cpaneframewndstorerecenttabrelatedinfo"></a><a name="storerecenttabrelatedinfo"></a>CPaneFrameWnd::StoreRecentTabRelatedInfo

```
virtual void StoreRecentTabRelatedInfo(
    CDockablePane* pDockingBar,
    CDockablePane* pTabbedBar);
```

### <a name="parameters"></a>Parâmetros

[em] *pDockingBar*<br/>
[em] *barra pTabbed*<br/>

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
