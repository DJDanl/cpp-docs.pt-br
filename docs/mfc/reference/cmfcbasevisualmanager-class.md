---
title: Classe CMFCBaseVisualManager | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec48152b918fb43cf859377e64eeb64478ad15f3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374269"
---
# <a name="cmfcbasevisualmanager-class"></a>Classe CMFCBaseVisualManager

Uma camada entre gerentes visuais derivados e a API de tema do Windows.

`CMFCBaseVisualManager` carrega o uxtheme, se disponível e gerencia o acesso aos métodos da API de tema do Windows.

Essa classe é apenas para uso interno.

## <a name="syntax"></a>Sintaxe

```
class CMFCBaseVisualManager: public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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
|[CMFCBaseVisualManager::DrawComboBorder](#drawcomboborder)|Desenha uma borda da caixa de combinação usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawComboDropButton](#drawcombodropbutton)|Desenha um botão de lista suspensa da caixa de combinação usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawPushButton](#drawpushbutton)|Desenha um botão de envio por push usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawRadioButton](#drawradiobutton)|Desenha um controle de botão de opção usando o tema atual do Windows.|
|[CMFCBaseVisualManager::DrawStatusBarProgress](#drawstatusbarprogress)|Desenha uma barra de progresso em um controle de barra de status ( [classe CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)) usando o tema atual do Windows.|
|[CMFCBaseVisualManager::FillReBarPane](#fillrebarpane)|Preenche a tela de fundo do controle rebar, usando o tema atual do Windows.|
|[CMFCBaseVisualManager::GetStandardWindowsTheme](#getstandardwindowstheme)|Obtém o tema atual do Windows.|

### <a name="protected-methods"></a>Métodos Protegidos

|||
|-|-|
|Nome|Descrição|
|[CMFCBaseVisualManager::CleanUpThemes](#cleanupthemes)|Chamadas `CloseThemeData` para todos os identificadores obtido em `UpdateSystemColors`.|
|[CMFCBaseVisualManager::UpdateSystemColors](#updatesystemcolors)|Chamadas `OpenThemeData` obter identificadores para desenhar vários controles: windows, as barras de ferramentas, botões e assim por diante.|

## <a name="remarks"></a>Comentários

Não é necessário que instanciar objetos dessa classe diretamente.

Porque é uma classe base para todos os gerenciadores de visual, você pode simplesmente chamar [CMFCVisualManager::GetInstance](../../mfc/reference/cmfcvisualmanager-class.md#getinstance), obter um ponteiro para o Gerenciador Visual atual e acessar os métodos para `CMFCBaseVisualManager` usando esse ponteiro. No entanto, se você tiver que exibir um controle usando o tema atual do Windows, é melhor usar o `CMFCVisualManagerWindows` interface.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxvisualmanager.h

##  <a name="cleanupthemes"></a>  CMFCBaseVisualManager::CleanUpThemes

Chamadas `CloseThemeData` para todos os identificadores obtido em `UpdateSystemColors`.

```
void CleanUpThemes();
```

### <a name="remarks"></a>Comentários

Somente para uso interno.

##  <a name="cmfcbasevisualmanager"></a>  CMFCBaseVisualManager::CMFCBaseVisualManager

Constrói e inicializa um objeto `CMFCBaseVisualManager`.

```
CMFCBaseVisualManager();
```

##  <a name="drawcheckbox"></a>  CMFCBaseVisualManager::DrawCheckBox

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
[in] Um ponteiro para um contexto de dispositivo

*Rect*<br/>
[in] O retângulo delimitador da caixa de seleção.

*bHighlighted*<br/>
[in] Especifica se a caixa de seleção está realçada.

*nState*<br/>
[in] 0 para 1 desmarcada, para verificado normal,

2 para misto normal.

*bAtivado*<br/>
[in] Especifica se a caixa de seleção está habilitada.

*bPressed*<br/>
[in] Especifica se a caixa de seleção é pressionada.

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Os valores de *nState* correspondem aos seguintes estilos de caixa de seleção.

|nState|Estilo de caixa de seleção|
|------------|---------------------|
|0|CBS_UNCHECKEDNORMAL|
|1|CBS_CHECKEDNORMAL|
|2|CBS_MIXEDNORMAL|

##  <a name="drawcomboborder"></a>  CMFCBaseVisualManager::DrawComboBorder

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
[in] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[in] Retângulo delimitador da borda da caixa de combinação.

*bDesabilitado*<br/>
[in] Especifica se a borda da caixa de combinação está desabilitada.

*bIsDropped*<br/>
[in] Especifica se a borda da caixa de combinação está aberta.

*bIsHighlighted*<br/>
[in] Especifica se a borda da caixa de combinação está realçada.

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

##  <a name="drawcombodropbutton"></a>  CMFCBaseVisualManager::DrawComboDropButton

Desenha um botão de lista suspensa da caixa de combinação usando o tema atual do Windows.

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
|*pDC*|[in] Um ponteiro para um contexto de dispositivo.|
|*Rect*|[in] O retângulo delimitador do botão de lista suspensa da caixa de combinação.|
|*bDesabilitado*|[in] Especifica se o botão de lista suspensa da caixa de combinação está desabilitado.|
|*bIsDropped*|[in] Especifica se o botão de lista suspensa da caixa de combinação está aberto.|
|*bIsHighlighted*|[in] Especifica se o botão de lista suspensa da caixa de combinação está realçado.|

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

##  <a name="drawpushbutton"></a>  CMFCBaseVisualManager::DrawPushButton

Desenha um botão de envio por push usando o tema atual do Windows.

```
virtual BOOL DrawPushButton(
    CDC* pDC,
    CRect rect,
    CMFCButton* pButton,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[in] O retângulo delimitador do botão de envio por push.

*pButton*<br/>
[in] Um ponteiro para o [classe CMFCButton](../../mfc/reference/cmfcbutton-class.md) objeto a ser desenhado.

*uiState*<br/>
[in] Ignorado. O estado é obtido *pButton*.

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

##  <a name="drawradiobutton"></a>  CMFCBaseVisualManager::DrawRadioButton

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

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[in] O retângulo delimitador do botão de opção.

*bHighlighted*<br/>
[in] Especifica se o botão de opção está realçado.

*bChecked*<br/>
[in] Especifica se o botão de opção é verificado.

*bAtivado*<br/>
[in] Especifica se o botão de opção está habilitado.

*bPressed*<br/>
[in] Especifica se o botão de opção é pressionado.

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

##  <a name="drawstatusbarprogress"></a>  CMFCBaseVisualManager::DrawStatusBarProgress

Desenha a barra de progresso em controle de barra de status ( [classe CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)) usando o tema atual do Windows.

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
[in] Um ponteiro para um contexto de dispositivo.

*pStatusBar*<br/>
[in] Um ponteiro para a barra de status. Este valor é ignorado.

*rectProgress*<br/>
[in] O retângulo delimitador da barra de progresso na *pDC* coordenadas.

*nProgressTotal*<br/>
[in] O valor de progresso total.

*nProgressCurr*<br/>
[in] O valor atual do progresso.

*clrBar*<br/>
[in] A cor inicial. `CMFCBaseVisualManager` ignora isso. As classes derivadas podem usá-lo para gradientes de cor.

*clrProgressBarDest*<br/>
[in] A cor final. `CMFCBaseVisualManager` ignora isso. As classes derivadas podem usá-lo para gradientes de cor.

*clrProgressText*<br/>
[in] Cor do texto de progresso. `CMFCBaseVisualManager` ignora isso. A cor do texto é definida por `afxGlobalData.clrBtnText`.

*bProgressText*<br/>
[in] Especifica se deve exibir o texto de progresso.

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

##  <a name="fillrebarpane"></a>  CMFCBaseVisualManager::FillReBarPane

Preenche a tela de fundo do controle rebar, usando o tema atual do Windows.

```
virtual void FillReBarPane(
    CDC* pDC,
    CBasePane* pBar,
    CRect rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*pBar*<br/>
[in] Um ponteiro para um painel cujo plano de fundo deve ser desenhado.

*rectClient*<br/>
[in] O retângulo delimitador da área a ser preenchido.

### <a name="return-value"></a>Valor de retorno

TRUE se a API de temas está habilitada; Caso contrário, FALSE.

##  <a name="getstandardwindowstheme"></a>  CMFCBaseVisualManager::GetStandardWindowsTheme

Obtém o tema atual do Windows.

```
virtual WinXpTheme GetStandardWindowsTheme();
```

### <a name="return-value"></a>Valor de retorno

A cor de tema do Windows atualmente selecionada. Pode ser um dos seguintes valores enumerados:

- `WinXpTheme_None` -Não há nenhum tema habilitado.

- `WinXpTheme_NonStandard` -tema padrão não está selecionado (ou seja, um tema é selecionado, mas nenhum da lista abaixo).

- `WinXpTheme_Blue` -tema azul (Luna).

- `WinXpTheme_Olive` -tema verde-oliva.

- `WinXpTheme_Silver` -tema prata.

##  <a name="updatesystemcolors"></a>  CMFCBaseVisualManager::UpdateSystemColors

Chamadas `OpenThemeData` obter identificadores para desenhar vários controles: windows, as barras de ferramentas, botões e assim por diante.

```
void UpdateSystemColors();
```

### <a name="remarks"></a>Comentários

Somente para uso interno.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
