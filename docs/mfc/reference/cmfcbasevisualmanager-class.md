---
title: Classe CMFCBaseVisualManager
ms.date: 11/04/2016
f1_keywords:
- CMFCBaseVisualManager
- AFXVISUALMANAGER/CMFCBaseVisualManager
- AFXVISUALMANAGER/CMFCBaseVisualManager::CMFCBaseVisualManager
- AFXVISUALMANAGER/CMFCBaseVisualManager::DrawCheckBox
- AFXVISUALMANAGER/CMFCBaseVisualManager::DrawComboBorder
- AFXVISUALMANAGER/CMFCBaseVisualManager::DrawComboDropButton
- AFXVISUALMANAGER/CMFCBaseVisualManager::DrawPushButton
- AFXVISUALMANAGER/CMFCBaseVisualManager::DrawRadioButton
- AFXVISUALMANAGER/CMFCBaseVisualManager::DrawStatusBarProgress
- AFXVISUALMANAGER/CMFCBaseVisualManager::FillReBarPane
- AFXVISUALMANAGER/CMFCBaseVisualManager::GetStandardWindowsTheme
- AFXVISUALMANAGER/CMFCBaseVisualManager::CleanUpThemes
- AFXVISUALMANAGER/CMFCBaseVisualManager::UpdateSystemColors
helpviewer_keywords:
- CMFCBaseVisualManager [MFC], CMFCBaseVisualManager
- CMFCBaseVisualManager [MFC], DrawCheckBox
- CMFCBaseVisualManager [MFC], DrawComboBorder
- CMFCBaseVisualManager [MFC], DrawComboDropButton
- CMFCBaseVisualManager [MFC], DrawPushButton
- CMFCBaseVisualManager [MFC], DrawRadioButton
- CMFCBaseVisualManager [MFC], DrawStatusBarProgress
- CMFCBaseVisualManager [MFC], FillReBarPane
- CMFCBaseVisualManager [MFC], GetStandardWindowsTheme
- CMFCBaseVisualManager [MFC], CleanUpThemes
- CMFCBaseVisualManager [MFC], UpdateSystemColors
ms.assetid: d56f3afc-cdea-4de1-825a-a08999c571e0
ms.openlocfilehash: a3288949bd4867115c32d2cbffd09cf4f7c6b40b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367804"
---
# <a name="cmfcbasevisualmanager-class"></a>Classe CMFCBaseVisualManager

Uma camada entre os gerentes visuais derivados e a API do Tema do Windows.

`CMFCBaseVisualManager`carrega O UxTheme.dll, se disponível, e gerencia o acesso aos métodos de API do Windows Theme.

Esta aula é apenas para uso interno.

## <a name="syntax"></a>Sintaxe

```
class CMFCBaseVisualManager: public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCBaseVisualManager::CMFCBaseVisualManager](#cmfcbasevisualmanager)|Constrói e inicializa um objeto `CMFCBaseVisualManager`.|
|`CMFCBaseVisualManager::~CMFCBaseVisualManager`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCBaseVisualManager::DrawCheckBox](#drawcheckbox)|Desenha um controle de caixa de seleção usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawComboBorder](#drawcomboborder)|Desenha uma borda de caixa combo usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawComboDropButton](#drawcombodropbutton)|Desenha um botão de saque da caixa combo usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawPushButton](#drawpushbutton)|Desenha um botão usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawRadioButton](#drawradiobutton)|Desenha um controle de botão de rádio usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawStatusBarProgress](#drawstatusbarprogress)|Desenha uma barra de progresso em um controle de barra de status [(CMFCStatusBar Class)](../../mfc/reference/cmfcstatusbar-class.md)usando o tema atual do Windows.|
|[CMFCBaseVisualManager::FillReBarPane](#fillrebarpane)|Preenche o plano de fundo do controle do vergalhão usando o tema atual do Windows.|
|[CMFCBaseVisualManager::GetStandardWindowsTheme](#getstandardwindowstheme)|Obtém o tema atual do Windows.|

### <a name="protected-methods"></a>Métodos Protegidos

|||
|-|-|
|Nome|Descrição|
|[CMFCBaseVisualManager::CleanUpThemes](#cleanupthemes)|Chamadas `CloseThemeData` para todas as `UpdateSystemColors`alças obtidas em .|
|[CMFCBaseVisualManager::AtualizaçãoCores do sistema](#updatesystemcolors)|Chamadas `OpenThemeData` para obter alças para desenhar vários controles: janelas, barras de ferramentas, botões e assim por diante.|

## <a name="remarks"></a>Comentários

Você não precisa instanciar objetos desta classe diretamente.

Como é uma classe base para todos os gerentes visuais, basta ligar para [cmfcvisualmanager::GetInstance](../../mfc/reference/cmfcvisualmanager-class.md#getinstance), `CMFCBaseVisualManager` obter um ponteiro para o Gerenciador Visual atual e acessar os métodos para usar esse ponteiro. No entanto, se você tiver que exibir um controle usando o `CMFCVisualManagerWindows` tema atual do Windows, é melhor usar a interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcbasevisualmanager](../../mfc/reference/cmfcbasevisualmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvisualmanager.h

## <a name="cmfcbasevisualmanagercleanupthemes"></a><a name="cleanupthemes"></a>CMFCBaseVisualManager::CleanUpThemes

Chamadas `CloseThemeData` para todas as `UpdateSystemColors`alças obtidas em .

```
void CleanUpThemes();
```

### <a name="remarks"></a>Comentários

Apenas para uso interno.

## <a name="cmfcbasevisualmanagercmfcbasevisualmanager"></a><a name="cmfcbasevisualmanager"></a>CMFCBaseVisualManager::CMFCBaseVisualManager

Constrói e inicializa um objeto `CMFCBaseVisualManager`.

```
CMFCBaseVisualManager();
```

## <a name="cmfcbasevisualmanagerdrawcheckbox"></a><a name="drawcheckbox"></a>CMFCBaseVisualManager::DrawCheckBox

Desenha um controle de caixa de seleção usando o tema atual do Windows.

```
virtual BOOL DrawCheckBox(
    CDC* pDC,
    CRect rect,
    BOOL bHighlighted,
    int nState,
    BOOL bEnabled,
    BOOL bPressed);

);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo

*Rect*<br/>
[em] O retângulo delimitador da caixa de seleção.

*bHighlighted*<br/>
[em] Especifica se a caixa de seleção está destacada.

*Nstate*<br/>
[in] 0 para desmarcado, 1 para verificado normal,

2 para o normal misto.

*bEnabled*<br/>
[em] Especifica se a caixa de seleção está ativada.

*bPressed*<br/>
[em] Especifica se a caixa de seleção está pressionada.

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Os valores do *nState* correspondem aos seguintes estilos de caixa de seleção.

|Nstate|Estilo caixa de seleção|
|------------|---------------------|
|0|CBS_UNCHECKEDNORMAL|
|1|CBS_CHECKEDNORMAL|
|2|CBS_MIXEDNORMAL|

## <a name="cmfcbasevisualmanagerdrawcomboborder"></a><a name="drawcomboborder"></a>CMFCBaseVisualManager::DrawComboBorder

Desenha a borda da caixa de combinação usando o tema atual do Windows.

```
virtual BOOL DrawComboBorder(
    CDC* pDC,
    CRect rect,
    BOOL bDisabled,
    BOOL bIsDropped,
    BOOL bIsHighlighted);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Retângulo delimitador da borda da caixa de combinação.

*bDisabled*<br/>
[em] Especifica se a borda da caixa de combinação está desativada.

*bIsD caiu*<br/>
[em] Especifica se a borda da caixa de combinação é derrubada.

*bIshighlighted*<br/>
[em] Especifica se a borda da caixa de combinação está destacada.

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

## <a name="cmfcbasevisualmanagerdrawcombodropbutton"></a><a name="drawcombodropbutton"></a>CMFCBaseVisualManager::DrawComboDropButton

Desenha um botão de saque da caixa combo usando o tema atual do Windows.

```
virtual BOOL DrawComboDropButton(
    CDC* pDC,
    CRect rect,
    BOOL bDisabled,
    BOOL bIsDropped,
    BOOL bIsHighlighted);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pDC*|[em] Um ponteiro para um contexto de dispositivo.|
|*Rect*|[em] O retângulo delimitador do botão de saque da caixa combo.|
|*bDisabled*|[em] Especifica se o botão de parada da caixa combo está desativado.|
|*bIsD caiu*|[em] Especifica se o botão de parada da caixa combo está descartado.|
|*bIshighlighted*|[em] Especifica se o botão de parada da caixa combo está destacado.|

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

## <a name="cmfcbasevisualmanagerdrawpushbutton"></a><a name="drawpushbutton"></a>CMFCBaseVisualManager::DrawPushButton

Desenha um botão usando o tema atual do Windows.

```
virtual BOOL DrawPushButton(
    CDC* pDC,
    CRect rect,
    CMFCButton* pButton,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] O retângulo delimitador do botão de pressão.

*Pbutton*<br/>
[em] Um ponteiro para o objeto [CMFCButton Class](../../mfc/reference/cmfcbutton-class.md) para desenhar.

*uiState*<br/>
[em] Ignorado. O estado é tirado de *pButton*.

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

## <a name="cmfcbasevisualmanagerdrawradiobutton"></a><a name="drawradiobutton"></a>CMFCBaseVisualManager::DrawRadioButton

Desenha um controle de botão de rádio usando o tema atual do Windows.

```
virtual BOOL DrawRadioButton(
    CDC* pDC,
    CRect rect,
    BOOL bHighlighted,
    BOOL bChecked,
    BOOL bEnabled,
    BOOL bPressed);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] O retângulo delimitador do botão de rádio.

*bHighlighted*<br/>
[em] Especifica se o botão de rádio está destacado.

*bChecked*<br/>
[em] Especifica se o botão de rádio é verificado.

*bEnabled*<br/>
[em] Especifica se o botão de rádio está ativado.

*bPressed*<br/>
[em] Especifica se o botão de rádio é pressionado.

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

## <a name="cmfcbasevisualmanagerdrawstatusbarprogress"></a><a name="drawstatusbarprogress"></a>CMFCBaseVisualManager::DrawStatusBarProgress

Desenha a barra de progresso no controle da barra de status [(CMFCStatusBar Class)](../../mfc/reference/cmfcstatusbar-class.md)usando o tema atual do Windows.

```
virtual BOOL DrawStatusBarProgress(
    CDC* pDC,
    CMFCStatusBar* pStatusBar,
    CRect rectProgress,
    int nProgressTotal,
    int nProgressCurr,
    COLORREF clrBar,
    COLORREF clrProgressBarDest,
    COLORREF clrProgressText,
    BOOL bProgressText);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*pStatusBar*<br/>
[em] Um ponteiro para a barra de status. Este valor é ignorado.

*rectProgress*<br/>
[em] O retângulo delimitador da barra de progresso nas coordenadas *pDC.*

*nProgressTotal*<br/>
[em] O valor total do progresso.

*nProgressCurr*<br/>
[em] O valor atual do progresso.

*clrBar*<br/>
[em] A cor inicial. `CMFCBaseVisualManager`ignora isso. Classes derivadas podem usá-lo para gradientes de cor.

*clrProgressBarDest*<br/>
[em] A cor final. `CMFCBaseVisualManager`ignora isso. Classes derivadas podem usá-lo para gradientes de cor.

*clrProgressText*<br/>
[em] Progress a cor do texto. `CMFCBaseVisualManager`ignora isso. A cor do `afxGlobalData.clrBtnText`texto é definida por .

*bProgressText*<br/>
[em] Especifica se deve exibir o texto de progresso.

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

## <a name="cmfcbasevisualmanagerfillrebarpane"></a><a name="fillrebarpane"></a>CMFCBaseVisualManager::FillReBarPane

Preenche o plano de fundo do controle do vergalhão usando o tema atual do Windows.

```
virtual void FillReBarPane(
    CDC* pDC,
    CBasePane* pBar,
    CRect rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Pbar*<br/>
[em] Um ponteiro para um painel cujo fundo deve ser desenhado.

*rectClient*<br/>
[em] O retângulo delimitador da área a ser preenchida.

### <a name="return-value"></a>Valor retornado

TRUE se a API tema estiver habilitada; caso contrário, FALSO.

## <a name="cmfcbasevisualmanagergetstandardwindowstheme"></a><a name="getstandardwindowstheme"></a>CMFCBaseVisualManager::GetStandardWindowsTheme

Obtém o tema atual do Windows.

```
virtual WinXpTheme GetStandardWindowsTheme();
```

### <a name="return-value"></a>Valor retornado

A cor tema do Windows atualmente selecionada. Pode ser um dos seguintes valores enumerados:

- `WinXpTheme_None`- não há tema habilitado.

- `WinXpTheme_NonStandard`- é selecionado um tema não padrão (o que significa que um tema é selecionado, mas nenhum da lista abaixo).

- `WinXpTheme_Blue`- tema azul (Luna).

- `WinXpTheme_Olive`- tema de azeitona.

- `WinXpTheme_Silver`- tema prateado.

## <a name="cmfcbasevisualmanagerupdatesystemcolors"></a><a name="updatesystemcolors"></a>CMFCBaseVisualManager::AtualizaçãoCores do sistema

Chamadas `OpenThemeData` para obter alças para desenhar vários controles: janelas, barras de ferramentas, botões e assim por diante.

```
void UpdateSystemColors();
```

### <a name="remarks"></a>Comentários

Apenas para uso interno.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
