---
title: Classe CMFCStatusBar
ms.date: 11/19/2018
f1_keywords:
- CMFCStatusBar
- AFXSTATUSBAR/CMFCStatusBar
- AFXSTATUSBAR/CMFCStatusBar::CalcFixedLayout
- AFXSTATUSBAR/CMFCStatusBar::CommandToIndex
- AFXSTATUSBAR/CMFCStatusBar::Create
- AFXSTATUSBAR/CMFCStatusBar::CreateEx
- AFXSTATUSBAR/CMFCStatusBar::DoesAllowDynInsertBefore
- AFXSTATUSBAR/CMFCStatusBar::EnablePaneDoubleClick
- AFXSTATUSBAR/CMFCStatusBar::EnablePaneProgressBar
- AFXSTATUSBAR/CMFCStatusBar::GetCount
- AFXSTATUSBAR/CMFCStatusBar::GetDrawExtendedArea
- AFXSTATUSBAR/CMFCStatusBar::GetExtendedArea
- AFXSTATUSBAR/CMFCStatusBar::GetItemID
- AFXSTATUSBAR/CMFCStatusBar::GetItemRect
- AFXSTATUSBAR/CMFCStatusBar::GetPaneInfo
- AFXSTATUSBAR/CMFCStatusBar::GetPaneProgress
- AFXSTATUSBAR/CMFCStatusBar::GetPaneStyle
- AFXSTATUSBAR/CMFCStatusBar::GetPaneText
- AFXSTATUSBAR/CMFCStatusBar::GetPaneWidth
- AFXSTATUSBAR/CMFCStatusBar::GetTipText
- AFXSTATUSBAR/CMFCStatusBar::InvalidatePaneContent
- AFXSTATUSBAR/CMFCStatusBar::PreCreateWindow
- AFXSTATUSBAR/CMFCStatusBar::SetDrawExtendedArea
- AFXSTATUSBAR/CMFCStatusBar::SetIndicators
- AFXSTATUSBAR/CMFCStatusBar::SetPaneAnimation
- AFXSTATUSBAR/CMFCStatusBar::SetPaneBackgroundColor
- AFXSTATUSBAR/CMFCStatusBar::SetPaneIcon
- AFXSTATUSBAR/CMFCStatusBar::SetPaneInfo
- AFXSTATUSBAR/CMFCStatusBar::SetPaneProgress
- AFXSTATUSBAR/CMFCStatusBar::SetPaneStyle
- AFXSTATUSBAR/CMFCStatusBar::SetPaneText
- AFXSTATUSBAR/CMFCStatusBar::SetPaneTextColor
- AFXSTATUSBAR/CMFCStatusBar::SetPaneWidth
- AFXSTATUSBAR/CMFCStatusBar::SetTipText
- AFXSTATUSBAR/CMFCStatusBar::OnDrawPane
helpviewer_keywords:
- CMFCStatusBar [MFC], CalcFixedLayout
- CMFCStatusBar [MFC], CommandToIndex
- CMFCStatusBar [MFC], Create
- CMFCStatusBar [MFC], CreateEx
- CMFCStatusBar [MFC], DoesAllowDynInsertBefore
- CMFCStatusBar [MFC], EnablePaneDoubleClick
- CMFCStatusBar [MFC], EnablePaneProgressBar
- CMFCStatusBar [MFC], GetCount
- CMFCStatusBar [MFC], GetDrawExtendedArea
- CMFCStatusBar [MFC], GetExtendedArea
- CMFCStatusBar [MFC], GetItemID
- CMFCStatusBar [MFC], GetItemRect
- CMFCStatusBar [MFC], GetPaneInfo
- CMFCStatusBar [MFC], GetPaneProgress
- CMFCStatusBar [MFC], GetPaneStyle
- CMFCStatusBar [MFC], GetPaneText
- CMFCStatusBar [MFC], GetPaneWidth
- CMFCStatusBar [MFC], GetTipText
- CMFCStatusBar [MFC], InvalidatePaneContent
- CMFCStatusBar [MFC], PreCreateWindow
- CMFCStatusBar [MFC], SetDrawExtendedArea
- CMFCStatusBar [MFC], SetIndicators
- CMFCStatusBar [MFC], SetPaneAnimation
- CMFCStatusBar [MFC], SetPaneBackgroundColor
- CMFCStatusBar [MFC], SetPaneIcon
- CMFCStatusBar [MFC], SetPaneInfo
- CMFCStatusBar [MFC], SetPaneProgress
- CMFCStatusBar [MFC], SetPaneStyle
- CMFCStatusBar [MFC], SetPaneText
- CMFCStatusBar [MFC], SetPaneTextColor
- CMFCStatusBar [MFC], SetPaneWidth
- CMFCStatusBar [MFC], SetTipText
- CMFCStatusBar [MFC], OnDrawPane
ms.assetid: f2960d1d-f4ed-41e8-bd99-0382b2f8d88e
ms.openlocfilehash: c4891c6bb66fe5e4b737ca9b128a01bcedcf39e7
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176569"
---
# <a name="cmfcstatusbar-class"></a>Classe CMFCStatusBar

O `CMFCStatusBar` classe implementa uma barra de status semelhante ao `CStatusBar` classe. No entanto, o `CMFCStatusBar` classe tem recursos não oferecidos pela `CStatusBar` classe, como a capacidade de exibir imagens, animações e barras de progresso; e a capacidade de responder passar o mouse clica duas vezes.

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCStatusBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCStatusBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [CBasePane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CMFCStatusBar::CommandToIndex](#commandtoindex)||
|[CMFCStatusBar::Create](#create)|Cria uma barra de controle e anexa-o para o [CPane](../../mfc/reference/cpane-class.md) objeto. (Substitui [CPane::Create](../../mfc/reference/cpane-class.md#create).)|
|[CMFCStatusBar::CreateEx](#createex)|Cria uma barra de controle e anexa-o para o [CPane](../../mfc/reference/cpane-class.md) objeto. (Substitui [CPane::CreateEx](../../mfc/reference/cpane-class.md#createex).)|
|[CMFCStatusBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Determina se outro painel pode ser inserido dinamicamente entre esse painel e o quadro principal. (Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|
|[CMFCStatusBar::EnablePaneDoubleClick](#enablepanedoubleclick)|Habilita ou desabilita a manipulação de mouse clica duas vezes na barra de status.|
|[CMFCStatusBar::EnablePaneProgressBar](#enablepaneprogressbar)|Exibe uma barra de progresso no painel de dados especificado.|
|[CMFCStatusBar::GetCount](#getcount)|Retorna o número de painéis na barra de status.|
|[CMFCStatusBar::GetDrawExtendedArea](#getdrawextendedarea)||
|[CMFCStatusBar::GetExtendedArea](#getextendedarea)||
|[CMFCStatusBar::GetItemID](#getitemid)||
|[CMFCStatusBar::GetItemRect](#getitemrect)||
|[CMFCStatusBar::GetPaneInfo](#getpaneinfo)||
|[CMFCStatusBar::GetPaneProgress](#getpaneprogress)||
|[CMFCStatusBar::GetPaneStyle](#getpanestyle)|Retorna o estilo de painel. (Substitui [CBasePane::GetPaneStyle](../../mfc/reference/cbasepane-class.md#getpanestyle).)|
|[CMFCStatusBar::GetPaneText](#getpanetext)||
|[CMFCStatusBar::GetPaneWidth](#getpanewidth)|Retorna a largura, em pixels, do painel da barra de status especificado.|
|[CMFCStatusBar::GetTipText](#gettiptext)|Retorna o texto da dica de ferramenta do painel especificado da barra de status.|
|[CMFCStatusBar::InvalidatePaneContent](#invalidatepanecontent)|Invalida o painel especificado e seu conteúdo é redesenhado.|
|[CMFCStatusBar::PreCreateWindow](#precreatewindow)|Chamado pelo framework antes da criação da janela Windows anexada a esta `CWnd` objeto. (Substitui [CWnd::PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow).)|
|[CMFCStatusBar::SetDrawExtendedArea](#setdrawextendedarea)||
|[CMFCStatusBar::SetIndicators](#setindicators)||
|[CMFCStatusBar::SetPaneAnimation](#setpaneanimation)|Atribui uma animação para o painel especificado.|
|[CMFCStatusBar::SetPaneBackgroundColor](#setpanebackgroundcolor)|Define a cor do plano de fundo do painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneIcon](#setpaneicon)|Define o ícone de indicador para o painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneInfo](#setpaneinfo)||
|[CMFCStatusBar::SetPaneProgress](#setpaneprogress)|Define o progresso atual da barra de progresso para o painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do painel. (Substitui [CBasePane::SetPaneStyle](../../mfc/reference/cbasepane-class.md#setpanestyle).)|
|[CMFCStatusBar::SetPaneText](#setpanetext)||
|[CMFCStatusBar::SetPaneTextColor](#setpanetextcolor)|Define a cor do texto do painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneWidth](#setpanewidth)|Define a largura em pixels, do painel da barra de status especificado.|
|[CMFCStatusBar::SetTipText](#settiptext)|Define o texto da dica de ferramenta do painel especificado da barra de status.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCStatusBar::OnDrawPane](#ondrawpane)|Chamado pelo framework quando ele redesenha o painel da barra de status.|

## <a name="remarks"></a>Comentários

O diagrama a seguir mostra uma figura da barra de status de [amostra de demonstração da barra de Status](../../visual-cpp-samples.md) aplicativo.

![Exemplo de CMFCStatusBar](../../mfc/reference/media/cmfcstatusbar.png "exemplo de CMFCStatusBar")

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra as variáveis locais que o aplicativo usa para chamar vários métodos `CMFCStatusBar` classe. Essas variáveis são declaradas no StatusBarDemoView.h. O quadro principal é declarado em MainFrm.h, o documento é declarado em StatusBarDemoDoc.h e o modo de exibição é declarado em StatusBarDemoView.h. Este trecho de código faz parte do [amostra de demonstração da barra de Status](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#9](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_1.h)]

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como obter uma referência a `CMFCStatusBar` objeto introduzindo o `GetStatusBar` método em MainFrm.h e, em seguida, chamar esse método da `GetStatusBar` método na StatusBarDemoView.h. Este trecho de código faz parte do [amostra de demonstração da barra de Status](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#7](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_2.h)]
[!code-cpp[NVC_MFC_StatusBarDemo#8](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_3.h)]

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como chamar vários métodos `CMFCStatusBar` classe no StatusBarDemoView.cpp. As constantes são declaradas no MainFrm.h. O exemplo mostra como definir o ícone, definir o texto de dica de ferramenta do painel de barra de status, exibir uma barra de progresso no painel de dados especificado, atribuir uma animação ao painel especificado, o texto e a largura do painel da barra de status e o indicador de progresso atual do progr barra de ESS do painel da barra de status. Este trecho de código faz parte do [amostra de demonstração da barra de Status](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#6](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_4.h)]
[!code-cpp[NVC_MFC_StatusBarDemo#1](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_5.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#2](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_6.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#3](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_7.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#4](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_8.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#5](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_9.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CBasePane](../../mfc/reference/cbasepane-class.md)

[CPane](../../mfc/reference/cpane-class.md)

[CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstatusbar.h

##  <a name="calcfixedlayout"></a>  CMFCStatusBar::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

[in] *bStretch*<br/>
[in] *bHorz*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="commandtoindex"></a>  CMFCStatusBar::CommandToIndex

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIDFind*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="create"></a>  CMFCStatusBar::Create

```
BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

[in] *pParentWnd*<br/>
[in] *dwStyle*<br/>
[in] *nID*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="createex"></a>  CMFCStatusBar::CreateEx

```
BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = 0,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

[in] *pParentWnd*<br/>
[in] *dwCtrlStyle*<br/>
[in] *dwStyle*<br/>
[in] *nID*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="doesallowdyninsertbefore"></a>  CMFCStatusBar::DoesAllowDynInsertBefore

```
virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="enablepanedoubleclick"></a>  CMFCStatusBar::EnablePaneDoubleClick

Habilita ou desabilita a manipulação de mouse clica duas vezes na barra de status.

```
void EnablePaneDoubleClick(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] Se for TRUE, habilite o processamento de mouse clique duas vezes. Caso contrário, desabilite o processamento de mouse clique duas vezes.

### <a name="remarks"></a>Comentários

Se a barra de status estiver habilitada para processar cliques do double, o Windows envia a notificação de WM_COMMAND junto com uma ID de recurso para o proprietário da barra toda vez que o usuário clica duas vezes no painel de barra de status de status.

##  <a name="enablepaneprogressbar"></a>  CMFCStatusBar::EnablePaneProgressBar

Exiba uma barra de progresso no painel de dados especificado.

```
void EnablePaneProgressBar(
    int nIndex,
    long nTotal=100,
    BOOL bDisplayText=FALSE,
    COLORREF clrBar=-1,
    COLORREF clrBarDest=-1,
    COLORREF clrProgressText=-1);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel cuja barra de progresso para habilitar.

*nLargura*<br/>
[in] Especifica o valor máximo para a barra de progresso.

*bDisplayText*<br/>
[in] Especifica se a barra de progresso deve exibir o valor atual do progresso.

*clrBar*<br/>
[in] Especifica a cor do plano de fundo da barra de progresso.

*clrBarDest*<br/>
[in] Especifica a cor secundária da tela de fundo de barra de progresso. Use outro valor diferente *clrBar* para preencher por uma cor em um gradiente.

*clrProgressText*<br/>
[in] Especifica a cor do texto da barra de progresso.

### <a name="remarks"></a>Comentários

Se você quiser desabilitar a chamada de barra de progresso `EnablePaneProgressBar` com *nLargura* definido como -1. Por padrão *nLargura* é definido como 100. Portanto, não é necessário qualquer cálculos adicionais para exibir o andamento como um percentual.

Você deve passar valores diferentes *clrBar* e *clrBarDest* para que a cor do plano de fundo da barra de progresso exibe uma cor em um gradiente. .

Para definir o andamento atual, chame o [CMFCStatusBar::SetPaneProgress](#setpaneprogress) método.

##  <a name="getcount"></a>  CMFCStatusBar::GetCount

Recupera o número de painéis na barra de status.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de painéis da barra de status.

##  <a name="getdrawextendedarea"></a>  CMFCStatusBar::GetDrawExtendedArea

```
BOOL GetDrawExtendedArea() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getextendedarea"></a>  CMFCStatusBar::GetExtendedArea

```
virtual BOOL GetExtendedArea(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

[in] *rect*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getitemid"></a>  CMFCStatusBar::GetItemID

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getitemrect"></a>  CMFCStatusBar::GetItemRect

```
void GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>
[in] *lpRect*<br/>

### <a name="remarks"></a>Comentários

##  <a name="getpaneinfo"></a>  CMFCStatusBar::GetPaneInfo

```
void GetPaneInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& cxWidth) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>
[in] *nID*<br/>
[in] *nStyle*<br/>
[in] *cxWidth*<br/>

### <a name="remarks"></a>Comentários

##  <a name="getpaneprogress"></a>  CMFCStatusBar::GetPaneProgress

```
long GetPaneProgress(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanestyle"></a>  CMFCStatusBar::GetPaneStyle

```
UINT GetPaneStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanetext"></a>  CMFCStatusBar::GetPaneText

```
void GetPaneText(
    int nIndex,
    CString& s) const;

CString GetPaneText(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>
[in] *s*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getpanewidth"></a>  CMFCStatusBar::GetPaneWidth

Recupera a largura do painel de uma barra de status.

```
int GetPaneWidth(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel da barra de status.

### <a name="return-value"></a>Valor de retorno

A largura do painel da barra de status que *nIndex* Especifica; caso contrário, zero se não existir um painel da barra de status.

##  <a name="gettiptext"></a>  CMFCStatusBar::GetTipText

Recupere o texto de dica de ferramenta do painel da barra de status.

```
CString GetTipText(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel para o qual recuperar o texto da dica de ferramenta.

### <a name="return-value"></a>Valor de retorno

O texto de dica de ferramenta do painel de barra de status que *nIndex* especifica. Caso contrário, a cadeia de caracteres vazia se não existir um painel da barra de status especificado *nIndex* ou se o seu texto de dica de ferramenta está vazio.

##  <a name="invalidatepanecontent"></a>  CMFCStatusBar::InvalidatePaneContent

Invalidar o painel da barra de status e redesenhar seu conteúdo.

```
void InvalidatePaneContent(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel cujo conteúdo deve ser invalidado e redesenhado.

### <a name="remarks"></a>Comentários

Quando a barra de status é invalidada, ela está marcada para ser redesenhada. Windows redesenha quando o `UpdateWindow` método envia uma mensagem WM_PAINT para a `OnPaint` método.

##  <a name="ondrawpane"></a>  CMFCStatusBar::OnDrawPane

Redesenhe o painel da barra de status.

```
virtual void OnDrawPane(
    CDC* pDC,
    CMFCStatusBarPaneInfo* pPane);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo para o desenho.

*pPane*<br/>
[in] Um ponteiro para um `CMFCStatusBarPaneInfo` estrutura que contém as informações sobre o painel a ser redesenhado.

### <a name="remarks"></a>Comentários

Por padrão, `OnDrawPane` redesenha o painel usando o contexto de dispositivo *pDC* acordo com o estilo e o conteúdo do painel.

Substitua este método em um `CMFCStatusBar`-derivado da classe para personalizar a aparência de um painel.

##  <a name="precreatewindow"></a>  CMFCStatusBar::PreCreateWindow

```
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```

### <a name="parameters"></a>Parâmetros

[in] *cs*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="setdrawextendedarea"></a>  CMFCStatusBar::SetDrawExtendedArea

```
void SetDrawExtendedArea(BOOL bSet = TRUE);
```

### <a name="parameters"></a>Parâmetros

[in] *bSet*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setindicators"></a>  CMFCStatusBar::SetIndicators

```
BOOL SetIndicators(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

[in] *lpIDArray*<br/>
[in] *nIDCount*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="setpaneanimation"></a>  CMFCStatusBar::SetPaneAnimation

Atribui uma animação para o painel especificado.

```
void SetPaneAnimation(
    int nIndex,
    HIMAGELIST hImageList,
    UINT nFrameRate=500,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel ao qual você deseja atribuir a ela uma animação.

*hImageList*<br/>
[in] Especifica um identificador para a lista de imagens que contêm os quadros de animação.

*nFrameRate*<br/>
[in] Especifica a taxa de quadros, em milissegundos, para a animação.

*b Update*<br/>
[in] Se for TRUE, atualize o conteúdo do painel imediatamente. Caso contrário, o conteúdo do painel é atualizado quando são invalidado.

### <a name="remarks"></a>Comentários

Se você quiser desabilitar a animação atual, chame `SetPaneAnimation` com `hImageList` definido como NULL.

##  <a name="setpanebackgroundcolor"></a>  CMFCStatusBar::SetPaneBackgroundColor

Define a cor do plano de fundo do painel de barra de status.

```
void SetPaneBackgroundColor(
    int nIndex,
    COLORREF clrBackground=(COLORREF)-1,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel para o qual definir uma nova cor de plano de fundo.

*clrBackground*<br/>
[in] Especifica a nova cor de plano de fundo.

*b Update*<br/>
[in] Se for TRUE, atualize o conteúdo do painel imediatamente. Caso contrário, não atualize o conteúdo do painel até que o painel é invalidado por outro método.

##  <a name="setpaneicon"></a>  CMFCStatusBar::SetPaneIcon

Defina o ícone do painel de barra de status.

```
void SetPaneIcon(
    int nIndex,
    HICON hIcon,
    BOOL bUpdate=TRUE);

void SetPaneIcon(
    int nIndex,
    HBITMAP hBmp,
    COLORREF clrTransparent=RGB(255, 0, 255),
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel para o qual definir a imagem.

*hIcon*<br/>
[in] Especifica um identificador para o ícone a ser definido como a imagem do painel.

*b Update*<br/>
[in] Especifica se deve atualizar o conteúdo do painel imediatamente.

*hBmp*<br/>
[in] Especifica um identificador para o bitmap a ser definido como a imagem do painel.

*clrTransparent*<br/>
[in] Especifica a cor transparente do bitmap que o *hBmp* indica.

### <a name="remarks"></a>Comentários

Você pode passar HICON ou HBITMAP junto com a cor transparente para definir a imagem do painel. Se você não quiser exibir a imagem mais, passe o valor NULL como a alça da imagem.

Se houver qualquer animação em execução que [CMFCStatusBar::SetPaneAnimation](#setpaneanimation) foi definida, a animação será interrompida.

##  <a name="setpaneinfo"></a>  CMFCStatusBar::SetPaneInfo

```
void SetPaneInfo(
    int nIndex,
    UINT nID,
    UINT nStyle,
    int cxWidth);
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>
[in] *nID*<br/>
[in] *nStyle*<br/>
[in] *cxWidth*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setpaneprogress"></a>  CMFCStatusBar::SetPaneProgress

Defina o indicador de progresso atual da barra de progresso para o painel especificado.

```
void SetPaneProgress(
    int nIndex,
    long nCurr,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel para o qual atualizar o indicador de progresso.

*nCurr*<br/>
[in] Especifica o valor atual do indicador de progresso.

*b Update*<br/>
[in] Especifica se o painel deve ser atualizado imediatamente.

### <a name="remarks"></a>Comentários

Chame esse método quando você deseja atualizar o indicador de progresso para a barra de progresso no painel especificado.

Para usar essa função para o painel de determinado, você deve chamar [CMFCStatusBar::EnablePaneProgressBar](#enablepaneprogressbar) primeiro.

##  <a name="setpanestyle"></a>  CMFCStatusBar::SetPaneStyle

```
void SetPaneStyle(
    int nIndex,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>
[in] *nStyle*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setpanetext"></a>  CMFCStatusBar::SetPaneText

```
virtual BOOL SetPaneText(
    int nIndex,
    LPCTSTR lpszNewText,
    BOOL bUpdate = TRUE);
```

### <a name="parameters"></a>Parâmetros

[in] *nIndex*<br/>
[in] *lpszNewText*<br/>
[in] *b Update*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="setpanetextcolor"></a>  CMFCStatusBar::SetPaneTextColor

Define a cor do texto do painel especificado.

```
void SetPaneTextColor(
    int nIndex,
    COLORREF clrText=(COLORREF)-1,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] Especifica o índice do painel ao qual você deseja atribuir uma nova cor do texto.

*clrText*<br/>
[in] Especifica a cor do texto.

*b Update*<br/>
[in] Se for TRUE, atualize o conteúdo do painel imediatamente. Caso contrário, não atualize o conteúdo do painel até que o painel é invalidado por outro método.

##  <a name="setpanewidth"></a>  CMFCStatusBar::SetPaneWidth

Defina a largura do painel de barra de status.

```
void SetPaneWidth(
    int nIndex,
    int cx);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] O índice do painel de barra de status para o qual definir uma nova largura.

*CX*<br/>
[in] A nova largura do painel da barra de status, em pixels.

##  <a name="settiptext"></a>  CMFCStatusBar::SetTipText

Defina o texto de dica de ferramenta de um painel da barra de status.

```
void SetTipText(
    int nIndex,
    LPCTSTR pszTipText);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[in] O índice do painel ao qual você deseja atribuir o texto de dica de ferramenta.

*pszTipText*<br/>
[in] O novo texto de dica de ferramenta.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPane](../../mfc/reference/cpane-class.md)<br/>
[Classe CStatusBar](../../mfc/reference/cstatusbar-class.md)
