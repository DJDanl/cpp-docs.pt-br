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
ms.openlocfilehash: 024fbad44af2fb11e967141fc8e7ccc0aad0ccbe
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753473"
---
# <a name="cmfcstatusbar-class"></a>Classe CMFCStatusBar

A `CMFCStatusBar` classe implementa uma barra `CStatusBar` de status semelhante à classe. No entanto, a `CMFCStatusBar` classe tem `CStatusBar` recursos não oferecidos pela classe, como a capacidade de exibir imagens, animações e barras de progresso; e a capacidade de responder a cliques duplos do mouse.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCStatusBar : public CPane
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCStatusBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [cbasepane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|
|[CMFCStatusBar::CommandToIndex](#commandtoindex)||
|[CMFCStatusBar::Criar](#create)|Cria uma barra de controle e a prende ao objeto [CPane.](../../mfc/reference/cpane-class.md) (Substitui [cpane::criar](../../mfc/reference/cpane-class.md#create).)|
|[CMFCStatusbar::CreateEx](#createex)|Cria uma barra de controle e a prende ao objeto [CPane.](../../mfc/reference/cpane-class.md) (Substitui [cpane::CreateEx](../../mfc/reference/cpane-class.md#createex).)|
|[CMFCStatusBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Determina se outro painel pode ser inserido dinamicamente entre este painel e o quadro pai. (Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|
|[CMFCStatusBar::EnablePaneDoubleClick](#enablepanedoubleclick)|Ativa ou desativa o manuseio de cliques duplos do mouse na barra de status.|
|[CMFCStatusBar::EnablePaneProgressBar](#enablepaneprogressbar)|Exibe uma barra de progresso no painel especificado.|
|[CMFCStatusBar::GetCount](#getcount)|Retorna o número de painéis na barra de status.|
|[CMFCStatusBar::GetdrawExtendedArea](#getdrawextendedarea)||
|[CMFCStatusBar::getExtendedarea](#getextendedarea)||
|[CMFCStatusBar::GetItemID](#getitemid)||
|[CMFCStatusBar::GetItemRect](#getitemrect)||
|[CMFCStatusBar::GetPaneInfo](#getpaneinfo)||
|[CMFCStatusBar::GetPaneProgress](#getpaneprogress)||
|[CMFCStatusBar::GetPaneStyle](#getpanestyle)|Retorna o estilo painel. (Substitui [cbasepane::GetPaneStyle](../../mfc/reference/cbasepane-class.md#getpanestyle).)|
|[CMFCStatusBar::GetPaneText](#getpanetext)||
|[CMFCStatusBar::GetPaneWidth](#getpanewidth)|Retorna a largura, em pixels, do painel especificado da barra de status.|
|[CMFCStatusBar::GetTipText](#gettiptext)|Retorna o texto da ponta da ferramenta para o painel especificado da barra de status.|
|[CMFCStatusBar::InvalidpaneContent](#invalidatepanecontent)|Invalida o painel especificado e redesenha seu conteúdo.|
|[CMFCStatusBar::PreCriarjanela](#precreatewindow)|Chamado pela estrutura antes da criação da janela `CWnd` do Windows anexada a este objeto. (Substitui [cwnd::PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow).)|
|[CMFCStatusBar::setDrawExtendedarea](#setdrawextendedarea)||
|[CMFCStatusBar::Indicadores de conjunto](#setindicators)||
|[CMFCStatusBar::SetPaneAnimation](#setpaneanimation)|Atribui uma animação ao painel especificado.|
|[CMFCStatusBar::SetPaneBackgroundColor](#setpanebackgroundcolor)|Define a cor de fundo para o painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneIcon](#setpaneicon)|Define o ícone indicador para o painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneInfo](#setpaneinfo)||
|[CMFCStatusBar::SetPaneProgress](#setpaneprogress)|Define o progresso atual da barra de progresso para o painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do painel. (Substitui [cbasepane::SetPaneStyle](../../mfc/reference/cbasepane-class.md#setpanestyle).)|
|[CMFCStatusBar::SetPaneText](#setpanetext)||
|[CMFCStatusBar::SetPaneTextColor](#setpanetextcolor)|Define a cor do texto para o painel especificado da barra de status.|
|[CMFCStatusBar::SetPaneWidth](#setpanewidth)|Define a largura em pixels do painel especificado da barra de status.|
|[CMFCStatusBar::SetTipText](#settiptext)|Define o texto da ponta da ferramenta para o painel especificado da barra de status.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCStatusBar::OnDrawPane](#ondrawpane)|Chamado pelo framework quando ele redesenha o painel da barra de status.|

## <a name="remarks"></a>Comentários

O diagrama a seguir mostra uma figura da barra de status do aplicativo de [amostra Status Bar Demo.](../../overview/visual-cpp-samples.md)

![Exemplo de CMFCStatusBar](../../mfc/reference/media/cmfcstatusbar.png "Exemplo de CMFCStatusBar")

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra as variáveis locais que o `CMFCStatusBar` aplicativo usa para chamar vários métodos na classe. Essas variáveis são declaradas em StatusBarDemoView.h. O quadro principal é declarado em MainFrm.h, o documento é declarado em StatusBarDemoDoc.h e a exibição é declarada em StatusBarDemoView.h. Este trecho de código faz parte da [amostra de demonstração da barra de status](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#9](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_1.h)]

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra `CMFCStatusBar` como obter uma `GetStatusBar` referência ao objeto introduzindo o método `GetStatusBar` em MainFrm.h e, em seguida, chamando este método a partir do método em StatusBarDemoView.h. Este trecho de código faz parte da [amostra de demonstração da barra de status](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#7](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_2.h)]
[!code-cpp[NVC_MFC_StatusBarDemo#8](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_3.h)]

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCStatusBar` chamar vários métodos na classe em StatusBarDemoView.cpp. As constantes são declaradas em MainFrm.h. O exemplo mostra como definir o ícone, definir o texto da dica de ferramenta do painel da barra de status, exibir uma barra de progresso no painel especificado, atribuir uma animação ao painel especificado, definir o texto e a largura do painel da barra de status e definir o indicador de progresso atual da barra de progresso para o painel da barra de status. Este trecho de código faz parte da [amostra de demonstração da barra de status](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#6](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_4.h)]
[!code-cpp[NVC_MFC_StatusBarDemo#1](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_5.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#2](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_6.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#3](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_7.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#4](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_8.cpp)]
[!code-cpp[NVC_MFC_StatusBarDemo#5](../../mfc/reference/codesnippet/cpp/cmfcstatusbar-class_9.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cbasepane](../../mfc/reference/cbasepane-class.md)

[Cpane](../../mfc/reference/cpane-class.md)

[CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstatusbar.h

## <a name="cmfcstatusbarcalcfixedlayout"></a><a name="calcfixedlayout"></a>CMFCStatusBar::CalcFixedLayout

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

[em] *bStretch*<br/>
[em] *bHorz*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarcommandtoindex"></a><a name="commandtoindex"></a>CMFCStatusBar::CommandToIndex

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIDFind*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarcreate"></a><a name="create"></a>CMFCStatusBar::Criar

```
BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

[em] *pParentWnd*<br/>
[em] *dwStyle*<br/>
[em] *nID*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarcreateex"></a><a name="createex"></a>CMFCStatusbar::CreateEx

```
BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = 0,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

[em] *pParentWnd*<br/>
[em] *dwCtrlStyle*<br/>
[em] *dwStyle*<br/>
[em] *nID*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbardoesallowdyninsertbefore"></a><a name="doesallowdyninsertbefore"></a>CMFCStatusBar::DoesAllowDynInsertBefore

```
virtual BOOL DoesAllowDynInsertBefore() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarenablepanedoubleclick"></a><a name="enablepanedoubleclick"></a>CMFCStatusBar::EnablePaneDoubleClick

Ativa ou desativa o manuseio de cliques duplos do mouse na barra de status.

```cpp
void EnablePaneDoubleClick(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] Se TRUE, habilite o processamento do mouse com dois cliques. Caso contrário, desative o processamento do mouse com duplo clique.

### <a name="remarks"></a>Comentários

Se a barra de status estiver habilitada para processar cliques duplos, o Windows envia a notificação WM_COMMAND juntamente com um ID de recurso para o proprietário da barra de status toda vez que o usuário clicar duas vezes no painel da barra de status.

## <a name="cmfcstatusbarenablepaneprogressbar"></a><a name="enablepaneprogressbar"></a>CMFCStatusBar::EnablePaneProgressBar

Exibir uma barra de progresso no painel especificado.

```cpp
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
[em] Especifica o índice do painel cuja barra de progresso é habilitada.

*nTotal*<br/>
[em] Especifica o valor máximo para a barra de progresso.

*bDisplayText*<br/>
[em] Especifica se a barra de progresso deve exibir o valor de progresso atual.

*clrBar*<br/>
[em] Especifica a cor de fundo da barra de progresso.

*clrBarDest*<br/>
[em] Especifica a cor secundária do plano de fundo da barra de progresso. Use um valor diferente do *clrBar* para preencher por uma cor misturada em um gradiente.

*clrProgressText*<br/>
[em] Especifica a cor do texto da barra de progresso.

### <a name="remarks"></a>Comentários

Se você quiser desativar a `EnablePaneProgressBar` chamada da barra de progresso com *nTotal* definido como -1. Por padrão *nTotal* é definido como 100. Portanto, você não precisa de nenhum cálculo adicional para exibir o progresso como porcentagem.

Você deve passar valores diferentes para *clrBar* e *clrBarDest* para que a cor de fundo da barra de progresso exiba uma cor misturada em um gradiente. .

Para definir o progresso atual, ligue para o método [CMFCStatusBar::SetPaneProgress.](#setpaneprogress)

## <a name="cmfcstatusbargetcount"></a><a name="getcount"></a>CMFCStatusBar::GetCount

Recupera o número de painéis na barra de status.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de painéis na barra de status.

## <a name="cmfcstatusbargetdrawextendedarea"></a><a name="getdrawextendedarea"></a>CMFCStatusBar::GetdrawExtendedArea

```
BOOL GetDrawExtendedArea() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetextendedarea"></a><a name="getextendedarea"></a>CMFCStatusBar::getExtendedarea

```
virtual BOOL GetExtendedArea(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

[em] *rect*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetitemid"></a><a name="getitemid"></a>CMFCStatusBar::GetItemID

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetitemrect"></a><a name="getitemrect"></a>CMFCStatusBar::GetItemRect

```cpp
void GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>
[em] *lpRect*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetpaneinfo"></a><a name="getpaneinfo"></a>CMFCStatusBar::GetPaneInfo

```cpp
void GetPaneInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& cxWidth) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>
[em] *nID*<br/>
[em] *nEstilo*<br/>
[em] *cxWidth*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetpaneprogress"></a><a name="getpaneprogress"></a>CMFCStatusBar::GetPaneProgress

```
long GetPaneProgress(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetpanestyle"></a><a name="getpanestyle"></a>CMFCStatusBar::GetPaneStyle

```
UINT GetPaneStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetpanetext"></a><a name="getpanetext"></a>CMFCStatusBar::GetPaneText

```cpp
void GetPaneText(
    int nIndex,
    CString& s) const;

CString GetPaneText(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>
[em] *s*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbargetpanewidth"></a><a name="getpanewidth"></a>CMFCStatusBar::GetPaneWidth

Recupera a largura do painel de uma barra de status.

```
int GetPaneWidth(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel da barra de status.

### <a name="return-value"></a>Valor retornado

A largura do painel da barra de status que *o nIndex* especifica; caso contrário, zero se um painel de barra de status não existe.

## <a name="cmfcstatusbargettiptext"></a><a name="gettiptext"></a>CMFCStatusBar::GetTipText

Recupere o texto da dica de ferramenta do painel de uma barra de status.

```
CString GetTipText(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel para o qual recuperar o texto da ponta da ferramenta.

### <a name="return-value"></a>Valor retornado

O texto da dica de ferramenta do painel de barra de status que *o nIndex* especifica. Caso contrário, a seqüência vazia se um painel de barra de status não existir para o *nIndex* especificado ou se seu texto de dica de ferramenta estiver vazio.

## <a name="cmfcstatusbarinvalidatepanecontent"></a><a name="invalidatepanecontent"></a>CMFCStatusBar::InvalidpaneContent

Invalidar o painel da barra de status e redesenhar seu conteúdo.

```cpp
void InvalidatePaneContent(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel cujo conteúdo deve ser invalidado e redesenhado.

### <a name="remarks"></a>Comentários

Quando a barra de status é invalidada, ela é marcada para redesenho. O Windows o `UpdateWindow` redesenha quando o `OnPaint` método envia uma mensagem WM_PAINT para o método.

## <a name="cmfcstatusbarondrawpane"></a><a name="ondrawpane"></a>CMFCStatusBar::OnDrawPane

Redesenhar o painel da barra de status.

```
virtual void OnDrawPane(
    CDC* pDC,
    CMFCStatusBarPaneInfo* pPane);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo para desenhar.

*pPane*<br/>
[em] Um ponteiro `CMFCStatusBarPaneInfo` para uma estrutura que contém as informações sobre o painel a ser redesenhado.

### <a name="remarks"></a>Comentários

Por padrão, `OnDrawPane` redesenha o painel usando o *pDC* do contexto do dispositivo de acordo com o estilo e conteúdo do painel.

Anular este método `CMFCStatusBar`em uma classe derivada para personalizar a aparência de um painel.

## <a name="cmfcstatusbarprecreatewindow"></a><a name="precreatewindow"></a>CMFCStatusBar::PreCriarjanela

```
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```

### <a name="parameters"></a>Parâmetros

[em] *cs*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarsetdrawextendedarea"></a><a name="setdrawextendedarea"></a>CMFCStatusBar::setDrawExtendedarea

```cpp
void SetDrawExtendedArea(BOOL bSet = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *bSet*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarsetindicators"></a><a name="setindicators"></a>CMFCStatusBar::Indicadores de conjunto

```
BOOL SetIndicators(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

[em] *lpIDArray*<br/>
[em] *nIDCount*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarsetpaneanimation"></a><a name="setpaneanimation"></a>CMFCStatusBar::SetPaneAnimation

Atribui uma animação ao painel especificado.

```cpp
void SetPaneAnimation(
    int nIndex,
    HIMAGELIST hImageList,
    UINT nFrameRate=500,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel ao qual você deseja atribuir a ele uma animação.

*Himagelist*<br/>
[em] Especifica uma alça para a lista de imagens que contém os quadros de animação.

*nFrameRate*<br/>
[em] Especifica a taxa de quadros, em milissegundos, para a animação.

*bAtualização*<br/>
[em] Se TRUE, atualize o conteúdo do painel imediatamente. Caso contrário, o conteúdo do painel é atualizado quando invalidado.

### <a name="remarks"></a>Comentários

Se você quiser desativar a animação `SetPaneAnimation` `hImageList` atual, ligue com set para NULL.

## <a name="cmfcstatusbarsetpanebackgroundcolor"></a><a name="setpanebackgroundcolor"></a>CMFCStatusBar::SetPaneBackgroundColor

Define a cor de fundo do painel da barra de status.

```cpp
void SetPaneBackgroundColor(
    int nIndex,
    COLORREF clrBackground=(COLORREF)-1,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel para o qual definir uma nova cor de fundo.

*clrBackground*<br/>
[em] Especifica a nova cor de fundo.

*bAtualização*<br/>
[em] Se TRUE, atualize o conteúdo do painel imediatamente. Caso contrário, não atualize o conteúdo do painel até que o painel seja invalidado por outro método.

## <a name="cmfcstatusbarsetpaneicon"></a><a name="setpaneicon"></a>CMFCStatusBar::SetPaneIcon

Defina o ícone do painel da barra de status.

```cpp
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
[em] Especifica o índice do painel para o qual definir a imagem.

*Hicon*<br/>
[em] Especifica uma alça para o ícone a ser definido como a imagem do painel.

*bAtualização*<br/>
[em] Especifica se deve atualizar o conteúdo do painel imediatamente.

*hBmp*<br/>
[em] Especifica uma alça para o bitmap a ser definida como a imagem do painel.

*clrTransparent*<br/>
[em] Especifica a cor transparente do bitmap que o *hBmp* indica.

### <a name="remarks"></a>Comentários

Você pode passar o HICON ou o HBITMAP juntamente com a cor transparente para definir a imagem do painel. Se você não quiser exibir a imagem por mais tempo, passe o valor NULL como o cabo da imagem.

Se houver alguma animação em execução que [cmfcStatusBar::SetPaneAnimation](#setpaneanimation) tenha definido, a animação será interrompida.

## <a name="cmfcstatusbarsetpaneinfo"></a><a name="setpaneinfo"></a>CMFCStatusBar::SetPaneInfo

```cpp
void SetPaneInfo(
    int nIndex,
    UINT nID,
    UINT nStyle,
    int cxWidth);
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>
[em] *nID*<br/>
[em] *nEstilo*<br/>
[em] *cxWidth*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarsetpaneprogress"></a><a name="setpaneprogress"></a>CMFCStatusBar::SetPaneProgress

Defina o indicador de progresso atual da barra de progresso para o painel especificado.

```cpp
void SetPaneProgress(
    int nIndex,
    long nCurr,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel para o qual atualizar o indicador de progresso.

*nCurr*<br/>
[em] Especifica o valor atual do indicador de progresso.

*bAtualização*<br/>
[em] Especifica se o painel deve ser atualizado imediatamente.

### <a name="remarks"></a>Comentários

Chame este método quando quiser atualizar o indicador de progresso para a barra de progresso no painel especificado.

Para usar esta função para o painel dado, você deve chamar [CMFCStatusBar::EnablePaneProgressBar](#enablepaneprogressbar) primeiro.

## <a name="cmfcstatusbarsetpanestyle"></a><a name="setpanestyle"></a>CMFCStatusBar::SetPaneStyle

```cpp
void SetPaneStyle(
    int nIndex,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>
[em] *nEstilo*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarsetpanetext"></a><a name="setpanetext"></a>CMFCStatusBar::SetPaneText

```
virtual BOOL SetPaneText(
    int nIndex,
    LPCTSTR lpszNewText,
    BOOL bUpdate = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *nIndex*<br/>
[em] *lpszNewText*<br/>
[em] *bAtualização*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcstatusbarsetpanetextcolor"></a><a name="setpanetextcolor"></a>CMFCStatusBar::SetPaneTextColor

Define a cor do texto do painel especificado.

```cpp
void SetPaneTextColor(
    int nIndex,
    COLORREF clrText=(COLORREF)-1,
    BOOL bUpdate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] Especifica o índice do painel ao qual você deseja atribuir uma nova cor de texto.

*clrText*<br/>
[em] Especifica a cor do texto.

*bAtualização*<br/>
[em] Se TRUE, atualize o conteúdo do painel imediatamente. Caso contrário, não atualize o conteúdo do painel até que o painel seja invalidado por outro método.

## <a name="cmfcstatusbarsetpanewidth"></a><a name="setpanewidth"></a>CMFCStatusBar::SetPaneWidth

Defina a largura do painel da barra de status.

```cpp
void SetPaneWidth(
    int nIndex,
    int cx);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] O índice do painel da barra de status para o qual definir uma nova largura.

*Cx*<br/>
[em] A nova largura do painel da barra de status, em pixels.

## <a name="cmfcstatusbarsettiptext"></a><a name="settiptext"></a>CMFCStatusBar::SetTipText

Defina o texto da dica de ferramenta de um painel de barra de status.

```cpp
void SetTipText(
    int nIndex,
    LPCTSTR pszTipText);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
[em] O índice do painel ao qual você deseja atribuir o texto da dica de ferramenta.

*pszTipText*<br/>
[em] O novo texto da dica de ferramenta.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPane](../../mfc/reference/cpane-class.md)<br/>
[Classe CStatusBar](../../mfc/reference/cstatusbar-class.md)
