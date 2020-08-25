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
ms.openlocfilehash: 79a3c0945fdd0df04e9ee52d7bad97dc0847fa91
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834291"
---
# <a name="cmfcbasevisualmanager-class"></a>Classe CMFCBaseVisualManager

Uma camada entre os gerenciadores visuais derivados e a API de tema do Windows.

`CMFCBaseVisualManager` carrega UxTheme.dll, se disponível, e gerencia o acesso aos métodos da API do tema do Windows.

Essa classe é somente para uso interno.

## <a name="syntax"></a>Sintaxe

```
class CMFCBaseVisualManager: public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|[CMFCBaseVisualManager::CMFCBaseVisualManager](#cmfcbasevisualmanager)|Constrói e inicializa um objeto `CMFCBaseVisualManager`.|
|`CMFCBaseVisualManager::~CMFCBaseVisualManager`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCBaseVisualManager::D rawCheckBox](#drawcheckbox)|Desenha um controle de caixa de seleção usando o tema atual do Windows.|
|[CMFCBaseVisualManager::D rawComboBorder](#drawcomboborder)|Desenha uma borda da caixa de combinação usando o tema atual do Windows.|
|[CMFCBaseVisualManager::D rawComboDropButton](#drawcombodropbutton)|Desenha um botão suspenso de caixa de combinação usando o tema atual do Windows.|
|[CMFCBaseVisualManager::D rawPushButton](#drawpushbutton)|Desenha um botão de ação usando o tema atual do Windows.|
|[CMFCBaseVisualManager::D rawRadioButton](#drawradiobutton)|Desenha um controle de botão de opção usando o tema atual do Windows.|
|[CMFCBaseVisualManager::D rawStatusBarProgress](#drawstatusbarprogress)|Desenha uma barra de progresso em um controle de barra de status ( [classe CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)) usando o tema atual do Windows.|
|[CMFCBaseVisualManager::FillReBarPane](#fillrebarpane)|Preenche o plano de fundo do controle rebar usando o tema atual do Windows.|
|[CMFCBaseVisualManager::GetStandardWindowsTheme](#getstandardwindowstheme)|Obtém o tema atual do Windows.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|-|-|
|[CMFCBaseVisualManager::CleanUpThemes](#cleanupthemes)|Chamadas `CloseThemeData` para todos os identificadores obtidos no `UpdateSystemColors` .|
|[CMFCBaseVisualManager::UpdateSystemColors](#updatesystemcolors)|Chamadas `OpenThemeData` para obter identificadores para desenhar vários controles: Windows, barras de ferramentas, botões e assim por diante.|

## <a name="remarks"></a>Comentários

Você não precisa criar uma instância de objetos dessa classe diretamente.

Como é uma classe base para todos os gerenciadores visuais, você pode simplesmente chamar [CMFCVisualManager:: GetInstance](../../mfc/reference/cmfcvisualmanager-class.md#getinstance), obter um ponteiro para o Gerenciador do visual atual e acessar os métodos para `CMFCBaseVisualManager` usar esse ponteiro. No entanto, se você precisa exibir um controle usando o tema atual do Windows, é melhor usar a `CMFCVisualManagerWindows` interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvisualmanager. h

## <a name="cmfcbasevisualmanagercleanupthemes"></a><a name="cleanupthemes"></a> CMFCBaseVisualManager::CleanUpThemes

Chamadas `CloseThemeData` para todos os identificadores obtidos no `UpdateSystemColors` .

```cpp
void CleanUpThemes();
```

### <a name="remarks"></a>Comentários

Somente para uso interno.

## <a name="cmfcbasevisualmanagercmfcbasevisualmanager"></a><a name="cmfcbasevisualmanager"></a> CMFCBaseVisualManager::CMFCBaseVisualManager

Constrói e inicializa um objeto `CMFCBaseVisualManager`.

```
CMFCBaseVisualManager();
```

## <a name="cmfcbasevisualmanagerdrawcheckbox"></a><a name="drawcheckbox"></a> CMFCBaseVisualManager::D rawCheckBox

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

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo

*Rect*<br/>
no O retângulo delimitador da caixa de seleção.

*bHighlighted*<br/>
no Especifica se a caixa de seleção está realçada.

*nState*<br/>
[in] 0 para desmarcado, 1 para marcada normal,

2 para normal misto.

*bEnabled*<br/>
no Especifica se a caixa de seleção está habilitada.

*bPressed*<br/>
no Especifica se a caixa de seleção é pressionada.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Os valores de *nState* correspondem aos seguintes estilos de caixa de seleção.

|nState|Estilo da caixa de seleção|
|------------|---------------------|
|0|CBS_UNCHECKEDNORMAL|
|1|CBS_CHECKEDNORMAL|
|2|CBS_MIXEDNORMAL|

## <a name="cmfcbasevisualmanagerdrawcomboborder"></a><a name="drawcomboborder"></a> CMFCBaseVisualManager::D rawComboBorder

Desenha a borda da caixa de combinação usando o tema atual do Windows.

```
virtual BOOL DrawComboBorder(
    CDC* pDC,
    CRect rect,
    BOOL bDisabled,
    BOOL bIsDropped,
    BOOL bIsHighlighted);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
no Retângulo delimitador da borda da caixa de combinação.

*bDisabled*<br/>
no Especifica se a borda da caixa de combinação está desabilitada.

*bIsDropped*<br/>
no Especifica se a borda da caixa de combinação é descartada.

*bIsHighlighted*<br/>
no Especifica se a borda da caixa de combinação está realçada.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

## <a name="cmfcbasevisualmanagerdrawcombodropbutton"></a><a name="drawcombodropbutton"></a> CMFCBaseVisualManager::D rawComboDropButton

Desenha um botão suspenso de caixa de combinação usando o tema atual do Windows.

```
virtual BOOL DrawComboDropButton(
    CDC* pDC,
    CRect rect,
    BOOL bDisabled,
    BOOL bIsDropped,
    BOOL bIsHighlighted);
```

### <a name="parameters"></a>parâmetros

*Primário*\
no Um ponteiro para um contexto de dispositivo.

*Rect*\
no O retângulo delimitador do botão suspenso da caixa de combinação.

*bDisabled*\
no Especifica se o botão suspenso da caixa de combinação está desabilitado.

*bIsDropped*\
no Especifica se o botão suspenso da caixa de combinação é Descartado.

*bIsHighlighted*\
no Especifica se o botão suspenso da caixa de combinação está realçado.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

## <a name="cmfcbasevisualmanagerdrawpushbutton"></a><a name="drawpushbutton"></a> CMFCBaseVisualManager::D rawPushButton

Desenha um botão de ação usando o tema atual do Windows.

```
virtual BOOL DrawPushButton(
    CDC* pDC,
    CRect rect,
    CMFCButton* pButton,
    UINT uiState);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
no O retângulo delimitador do botão de ação.

*pButton*<br/>
no Um ponteiro para o objeto da [classe CMFCButton](../../mfc/reference/cmfcbutton-class.md) a ser desenhado.

*uiState*<br/>
no Aceita. O estado é obtido de *pButton*.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

## <a name="cmfcbasevisualmanagerdrawradiobutton"></a><a name="drawradiobutton"></a> CMFCBaseVisualManager::D rawRadioButton

Desenha um controle de botão de opção usando o tema atual do Windows.

```
virtual BOOL DrawRadioButton(
    CDC* pDC,
    CRect rect,
    BOOL bHighlighted,
    BOOL bChecked,
    BOOL bEnabled,
    BOOL bPressed);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
no O retângulo delimitador do botão de opção.

*bHighlighted*<br/>
no Especifica se o botão de opção está realçado.

*bChecked*<br/>
no Especifica se o botão de opção está marcado.

*bEnabled*<br/>
no Especifica se o botão de opção está habilitado.

*bPressed*<br/>
no Especifica se o botão de opção é pressionado.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

## <a name="cmfcbasevisualmanagerdrawstatusbarprogress"></a><a name="drawstatusbarprogress"></a> CMFCBaseVisualManager::D rawStatusBarProgress

Desenha a barra de progresso no controle da barra de status ( [classe CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)) usando o tema atual do Windows.

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

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo.

*pStatusBar*<br/>
no Um ponteiro para a barra de status. Este valor é ignorado.

*rectProgress*<br/>
no O retângulo delimitador da barra de progresso em coordenadas de *PDC* .

*nProgressTotal*<br/>
no O valor de progresso total.

*nProgressCurr*<br/>
no O valor de progresso atual.

*clrBar*<br/>
no A cor inicial. `CMFCBaseVisualManager` Ignora isso. As classes derivadas podem usá-lo para gradientes de cor.

*clrProgressBarDest*<br/>
no A cor final. `CMFCBaseVisualManager` Ignora isso. As classes derivadas podem usá-lo para gradientes de cor.

*clrProgressText*<br/>
no Cor do texto de progresso. `CMFCBaseVisualManager` Ignora isso. A cor do texto é definida por `afxGlobalData.clrBtnText` .

*bProgressText*<br/>
no Especifica se o texto de progresso deve ser exibido.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

## <a name="cmfcbasevisualmanagerfillrebarpane"></a><a name="fillrebarpane"></a> CMFCBaseVisualManager::FillReBarPane

Preenche o plano de fundo do controle rebar usando o tema atual do Windows.

```
virtual void FillReBarPane(
    CDC* pDC,
    CBasePane* pBar,
    CRect rectClient);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
no Um ponteiro para um contexto de dispositivo.

*pBar*<br/>
no Um ponteiro para um painel cujo plano de fundo deve ser desenhado.

*rectClient*<br/>
no O retângulo delimitador da área a ser preenchida.

### <a name="return-value"></a>Valor Retornado

TRUE se a API de tema estiver habilitada; caso contrário, FALSE.

## <a name="cmfcbasevisualmanagergetstandardwindowstheme"></a><a name="getstandardwindowstheme"></a> CMFCBaseVisualManager::GetStandardWindowsTheme

Obtém o tema atual do Windows.

```
virtual WinXpTheme GetStandardWindowsTheme();
```

### <a name="return-value"></a>Valor Retornado

A cor do tema do Windows selecionada no momento. Pode ser um dos seguintes valores enumerados:

- `WinXpTheme_None` -Não há nenhum tema habilitado.

- `WinXpTheme_NonStandard` -o tema não padrão é selecionado (o que significa que um tema está selecionado, mas nenhum na lista abaixo).

- `WinXpTheme_Blue` -tema azul (lunar).

- `WinXpTheme_Olive` -Tema verde-oliva.

- `WinXpTheme_Silver` -tema prata.

## <a name="cmfcbasevisualmanagerupdatesystemcolors"></a><a name="updatesystemcolors"></a> CMFCBaseVisualManager::UpdateSystemColors

Chamadas `OpenThemeData` para obter identificadores para desenhar vários controles: Windows, barras de ferramentas, botões e assim por diante.

```cpp
void UpdateSystemColors();
```

### <a name="remarks"></a>Comentários

Somente para uso interno.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
