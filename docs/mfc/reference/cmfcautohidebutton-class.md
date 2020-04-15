---
title: Classe CMFCAutoHideButton
ms.date: 10/18/2018
f1_keywords:
- CMFCAutoHideButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::BringToTop
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::Create
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetAlignment
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetAutoHideWindow
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetParentToolBar
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetRect
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetSize
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetTextSize
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::HighlightButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsActive
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsHighlighted
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsHorizontal
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsTop
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsVisible
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::Move
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::OnDraw
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::OnDrawBorder
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::OnFillBackground
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::ReplacePane
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::ShowAttachedWindow
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::ShowButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::UnSetAutoHideMode
helpviewer_keywords:
- CMFCAutoHideButton [MFC], BringToTop
- CMFCAutoHideButton [MFC], Create
- CMFCAutoHideButton [MFC], GetAlignment
- CMFCAutoHideButton [MFC], GetAutoHideWindow
- CMFCAutoHideButton [MFC], GetParentToolBar
- CMFCAutoHideButton [MFC], GetRect
- CMFCAutoHideButton [MFC], GetSize
- CMFCAutoHideButton [MFC], GetTextSize
- CMFCAutoHideButton [MFC], HighlightButton
- CMFCAutoHideButton [MFC], IsActive
- CMFCAutoHideButton [MFC], IsHighlighted
- CMFCAutoHideButton [MFC], IsHorizontal
- CMFCAutoHideButton [MFC], IsTop
- CMFCAutoHideButton [MFC], IsVisible
- CMFCAutoHideButton [MFC], Move
- CMFCAutoHideButton [MFC], OnDraw
- CMFCAutoHideButton [MFC], OnDrawBorder
- CMFCAutoHideButton [MFC], OnFillBackground
- CMFCAutoHideButton [MFC], ReplacePane
- CMFCAutoHideButton [MFC], ShowAttachedWindow
- CMFCAutoHideButton [MFC], ShowButton
- CMFCAutoHideButton [MFC], UnSetAutoHideMode
ms.assetid: c80e6b8b-25ca-4d12-9d27-457731028ab0
ms.openlocfilehash: 84f17896cc3c4f5cd6099a9ccf7e4e000f43b1f1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369917"
---
# <a name="cmfcautohidebutton-class"></a>Classe CMFCAutoHideButton

Um botão que exibe ou oculta uma [classe CDockablePane](../../mfc/reference/cdockablepane-class.md) que está configurada para ocultar.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCAutoHideButton : public CObject
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCAutoHidebutton::BringToTop](#bringtotop)||
|[CMFCAutoHideButton::Criar](#create)|Cria e inicializa o botão de ocultação automática.|
|[CMFCAutoHidebutton::GetAlignment](#getalignment)|Recupera o alinhamento do botão de ocultação automática.|
|[CMFCAutoHidebutton::GetAutoHideWindow](#getautohidewindow)|Retorna o objeto [CDockablePane](../../mfc/reference/cdockablepane-class.md) associado ao botão de ocultação automática.|
|[CMFCAutoHidebutton::GetParenttoolbar](#getparenttoolbar)||
|[CMFCAutoHideButton::GetRect](#getrect)||
|[CMFCAutoHidebutton::GetSize](#getsize)|Determina o tamanho do botão de ocultação automática.|
|[CMFCAutoHidebutton::getTextSize](#gettextsize)|Retorna o tamanho da etiqueta de texto para o botão de ocultação automática.|
|[CMFCAutoHidebutton::HighlightButton](#highlightbutton)|Destaca o botão de ocultação automática.|
|[CMFCAutoHidebutton::isActive](#isactive)|Indica se o botão de ocultação automática está ativo.|
|[CMFCAutoHidebutton::ishighlighted](#ishighlighted)|Retorna o estado de destaque do botão de ocultação automática.|
|[CMFCAutoHidebutton::IsHorizontal](#ishorizontal)|Determina se o botão de ocultação automática é horizontal ou vertical.|
|[CMFCAutoHidebutton::Lista de reinicialização](#istop)||
|[CMFCAutoHidebutton::IsVisible](#isvisible)|Indica se o botão está visível.|
|[CMFCAutoHidebutton::Mover](#move)||
|[CMFCAutoHidebutton::OnDraw](#ondraw)|A estrutura chama esse método quando ele desenha o botão de ocultação automática.|
|[CMFCAutoHidebutton::OnDrawBorder](#ondrawborder)|A estrutura chama esse método quando ele desenha a borda de um botão de ocultação automática.|
|[CMFCAutoHidebutton::OnFillBackground](#onfillbackground)|A estrutura chama esse método quando preenche o plano de fundo de um botão de ocultação automática.|
|[CMFCAutoHideButton::Substituir pane](#replacepane)||
|[CMFCAuto'SButton::MostrarAnexoJanela](#showattachedwindow)|Mostra ou esconde a [classe CDockablePane associada](../../mfc/reference/cdockablepane-class.md).|
|[CMFCAutoHidebutton::ShowButton](#showbutton)|Mostra ou esconde o botão de ocultação automática.|
|[CMFCAuto'SButton de ocultação::''Ocultar automaticamente''](#unsetautohidemode)||

## <a name="remarks"></a>Comentários

Na criação, `CMFCAutoHideButton` o objeto é anexado a uma [classe CDockablePane](../../mfc/reference/cdockablepane-class.md). O `CDockablePane` objeto é oculto ou exibido à `CMFCAutoHideButton` medida que o usuário interage com o objeto.

Por padrão, a estrutura `CMFCAutoHideButton` cria automaticamente um quando o usuário ativa o ocultação automático. A estrutura pode criar um elemento de uma `CMFCAutoHideButton` classe de IU personalizada em vez da classe. Para especificar qual classe de ui personalizada a `CMFCAutoHideBar::m_pAutoHideButtonRTS` estrutura deve usar, defina a variável membro estático igual à classe de UI personalizada. Por padrão, essa variável é definida como `CMFCAutoHideButton`.

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCAutoHideButton` demonstra como construir um `CMFCAutoHideButton` objeto e usar vários métodos na classe. O exemplo mostra como `CMFCAutoHideButton` inicializar um `Create` objeto usando `CDockablePane` seu método, mostrar a classe associada e mostrar o botão de ocultação automática.

[!code-cpp[NVC_MFC_RibbonApp#32](../../mfc/reference/codesnippet/cpp/cmfcautohidebutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMFCAutoHideButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxautohidebutton.h

## <a name="cmfcautohidebuttonbringtotop"></a><a name="bringtotop"></a>CMFCAutoHidebutton::BringToTop

```
void BringToTop();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttoncreate"></a><a name="create"></a>CMFCAutoHideButton::Criar

Cria e inicializa um botão de ocultação automática.

```
virtual BOOL Create(
    CMFCAutoHideBar* pParentBar,
    CDockablePane* pAutoHideWnd,
    DWORD dwAlignment);
```

### <a name="parameters"></a>Parâmetros

*pParentBar*<br/>
[em] Um ponteiro para a barra de ferramentas dos pais.

*pAutoHideWnd*<br/>
[em] Um ponteiro para um objeto [CDockablePane.](../../mfc/reference/cdockablepane-class.md) Este botão de ocultação automática `CDockablePane`esconde e mostra que .

*Dwalignment*<br/>
[em] Um valor que especifica o alinhamento do botão com a janela principal do quadro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ao criar `CMFCAutoHideButton` um objeto, você deve associar o `CDockablePane`botão de ocultação automática a um específico . O usuário pode usar o botão de ocultar automaticamente para ocultar e mostrar o associado `CDockablePane`.

O parâmetro *dwAlignment* indica onde o botão de ocultação automática reside no aplicativo. O parâmetro pode ser qualquer um dos seguintes valores:

- Cbrs_align_left

- Cbrs_align_right

- Cbrs_align_top

- Cbrs_align_bottom

## <a name="cmfcautohidebuttongetalignment"></a><a name="getalignment"></a>CMFCAutoHidebutton::GetAlignment

Recupera o alinhamento do botão de ocultação automática.

```
DWORD GetAlignment() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DWORD que contém o alinhamento atual do botão de ocultação automática.

### <a name="remarks"></a>Comentários

O alinhamento do botão de ocultação automática indica onde o botão reside no aplicativo. Pode ser qualquer um dos seguintes valores:

- Cbrs_align_left

- Cbrs_align_right

- CRBS_ALIGN_TOP

- Cbrs_align_bottom

## <a name="cmfcautohidebuttongetautohidewindow"></a><a name="getautohidewindow"></a>CMFCAutoHidebutton::GetAutoHideWindow

Retorna o objeto [CDockablePane](../../mfc/reference/cdockablepane-class.md) associado ao botão de ocultação automática.

```
CDockablePane* GetAutoHideWindow() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `CDockablePane` o objeto associado.

### <a name="remarks"></a>Comentários

Para associar um botão de `CDockablePane`ocultação `CDockablePane` automática a um , passe o como parâmetro para o [CMFCAutoHideButton:::Criar](#create) método.

## <a name="cmfcautohidebuttongetparenttoolbar"></a><a name="getparenttoolbar"></a>CMFCAutoHidebutton::GetParenttoolbar

```
CMFCAutoHideBar* GetParentToolBar();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttongetrect"></a><a name="getrect"></a>CMFCAutoHideButton::GetRect

```
CRect GetRect() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttongetsize"></a><a name="getsize"></a>CMFCAutoHidebutton::GetSize

Determina o tamanho do botão de ocultação automática.

```
CSize GetSize() const;
```

### <a name="return-value"></a>Valor retornado

Um `CSize` objeto que contém o tamanho do botão.

### <a name="remarks"></a>Comentários

O tamanho calculado inclui o tamanho da borda do botão de ocultação automática.

## <a name="cmfcautohidebuttongettextsize"></a><a name="gettextsize"></a>CMFCAutoHidebutton::getTextSize

Retorna o tamanho da etiqueta de texto para o botão de ocultação automática.

```
virtual CSize GetTextSize() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que contém o tamanho do texto para o botão de ocultação automática.

## <a name="cmfcautohidebuttonisactive"></a><a name="isactive"></a>CMFCAutoHidebutton::isActive

Indica se o botão de ocultação automática está ativo.

```
BOOL IsActive() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão de ocultação automática estiver ativo; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Um botão de ocultação automática está ativo quando a janela [CDockablePane Class](../../mfc/reference/cdockablepane-class.md) associada é mostrada.

## <a name="cmfcautohidebuttonishorizontal"></a><a name="ishorizontal"></a>CMFCAutoHidebutton::IsHorizontal

Determina se o botão de ocultação automática é horizontal ou vertical.

```
BOOL IsHorizontal() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o botão for horizontal; 0 caso contrário.

### <a name="remarks"></a>Comentários

A estrutura define a orientação de um objeto [CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md) ao criá-lo.  Você pode controlar a orientação usando o parâmetro *dwAlignment* no [método CMFCAutoHideButton:::Criar.](#create)

## <a name="cmfcautohidebuttonistop"></a><a name="istop"></a>CMFCAutoHidebutton::Lista de reinicialização

```
BOOL IsTop() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttonisvisible"></a><a name="isvisible"></a>CMFCAutoHidebutton::IsVisible

Indica se o botão de ocultação automática está visível.

```
virtual BOOL IsVisible() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o botão estiver visível; FALSO de outra forma.

## <a name="cmfcautohidebuttonondraw"></a><a name="ondraw"></a>CMFCAutoHidebutton::OnDraw

A estrutura chama esse método quando ele desenha o botão de ocultação automática.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

Se você quiser personalizar a aparência de botões de ocultação automática em `CMFCAutoHideButton`seu aplicativo, crie uma nova classe derivada de . Na sua classe derivada, anule este método.

## <a name="cmfcautohidebuttonondrawborder"></a><a name="ondrawborder"></a>CMFCAutoHidebutton::OnDrawBorder

A estrutura chama esse método quando ele desenha a borda de um botão de ocultação automática.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect rectBounds,
    CRect rectBorderSize);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectBounds*<br/>
[em] O retângulo delimitador do botão de ocultação automática.

*rectBorderSize*<br/>
[em] A espessura da borda para cada lado do botão de ocultação automática.

### <a name="remarks"></a>Comentários

Se você quiser personalizar a borda de cada botão de ocultação automática `CMFCAutoHideButton`em seu aplicativo, crie uma nova classe derivada do . Na sua classe derivada, anule este método.

## <a name="cmfcautohidebuttononfillbackground"></a><a name="onfillbackground"></a>CMFCAutoHidebutton::OnFillBackground

A estrutura chama esse método quando preenche o plano de fundo de um botão de ocultação automática.

```
virtual void OnFillBackground(
    CDC* pDC,
    CRect rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] O retângulo delimitador do botão de ocultação automática.

### <a name="remarks"></a>Comentários

Se você quiser personalizar o plano de fundo para botões de ocultação `CMFCAutoHideButton`automática em seu aplicativo, crie uma nova classe derivada do . Na sua classe derivada, anule este método.

## <a name="cmfcautohidebuttonshowattachedwindow"></a><a name="showattachedwindow"></a>CMFCAuto'SButton::MostrarAnexoJanela

Mostra ou esconde a [classe CDockablePane associada](../../mfc/reference/cdockablepane-class.md).

```
void ShowAttachedWindow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] Um booleano que especifica se este `CDockablePane`método mostra o anexo .

## <a name="cmfcautohidebuttonshowbutton"></a><a name="showbutton"></a>CMFCAutoHidebutton::ShowButton

Mostra ou esconde o botão de ocultação automática.

```
virtual void ShowButton(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] Um booleano que especifica se deve mostrar o botão de ocultação automática.

## <a name="cmfcautohidebuttonmove"></a><a name="move"></a>CMFCAutoHidebutton::Mover

```
void Move(int nOffset);
```

### <a name="parameters"></a>Parâmetros

[em] *nOffset*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttonreplacepane"></a><a name="replacepane"></a>CMFCAutoHideButton::Substituir pane

```
void ReplacePane(CDockablePane* pNewBar);
```

### <a name="parameters"></a>Parâmetros

[em] *pNewBar*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttonunsetautohidemode"></a><a name="unsetautohidemode"></a>CMFCAuto'SButton de ocultação::''Ocultar automaticamente''

Desativar o modo de ocultação automática.

```
virtual void UnSetAutoHideMode(CDockablePane* pFirstBarInGroup);
```

### <a name="parameters"></a>Parâmetros

*pFirstBarInGroup*<br/>
[em] Um ponteiro para a primeira barra do grupo.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttonhighlightbutton"></a><a name="highlightbutton"></a>CMFCAutoHidebutton::HighlightButton

Destaca o botão de ocultação automática.

```
virtual void HighlightButton(BOOL bHighlight);
```

### <a name="parameters"></a>Parâmetros

*bDestaque*<br/>
Especifica o novo estado do botão de ocultação automática. TRUE indica que o botão está destacado, FALSE indica que o botão não está destacado.

### <a name="remarks"></a>Comentários

## <a name="cmfcautohidebuttonishighlighted"></a><a name="ishighlighted"></a>CMFCAutoHidebutton::ishighlighted

Retorna o estado de destaque do botão de ocultação automática.

```
virtual BOOL IsHighlighted() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o botão de ocultação automática for destacado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md)<br/>
[Classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md)
