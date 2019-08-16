---
title: Classe CMFCColorButton
ms.date: 11/04/2016
f1_keywords:
- CMFCColorButton
- AFXCOLORBUTTON/CMFCColorButton
- AFXCOLORBUTTON/CMFCColorButton::CMFCColorButton
- AFXCOLORBUTTON/CMFCColorButton::EnableAutomaticButton
- AFXCOLORBUTTON/CMFCColorButton::EnableOtherButton
- AFXCOLORBUTTON/CMFCColorButton::GetAutomaticColor
- AFXCOLORBUTTON/CMFCColorButton::GetColor
- AFXCOLORBUTTON/CMFCColorButton::SetColor
- AFXCOLORBUTTON/CMFCColorButton::SetColorName
- AFXCOLORBUTTON/CMFCColorButton::SetColumnsNumber
- AFXCOLORBUTTON/CMFCColorButton::SetDocumentColors
- AFXCOLORBUTTON/CMFCColorButton::SetPalette
- AFXCOLORBUTTON/CMFCColorButton::SizeToContent
- AFXCOLORBUTTON/CMFCColorButton::IsDrawXPTheme
- AFXCOLORBUTTON/CMFCColorButton::OnDraw
- AFXCOLORBUTTON/CMFCColorButton::OnDrawBorder
- AFXCOLORBUTTON/CMFCColorButton::OnDrawFocusRect
- AFXCOLORBUTTON/CMFCColorButton::OnShowColorPopup
- AFXCOLORBUTTON/CMFCColorButton::RebuildPalette
- AFXCOLORBUTTON/CMFCColorButton::UpdateColor
- AFXCOLORBUTTON/CMFCColorButton::m_bEnabledInCustomizeMode
helpviewer_keywords:
- CMFCColorButton [MFC], CMFCColorButton
- CMFCColorButton [MFC], EnableAutomaticButton
- CMFCColorButton [MFC], EnableOtherButton
- CMFCColorButton [MFC], GetAutomaticColor
- CMFCColorButton [MFC], GetColor
- CMFCColorButton [MFC], SetColor
- CMFCColorButton [MFC], SetColorName
- CMFCColorButton [MFC], SetColumnsNumber
- CMFCColorButton [MFC], SetDocumentColors
- CMFCColorButton [MFC], SetPalette
- CMFCColorButton [MFC], SizeToContent
- CMFCColorButton [MFC], IsDrawXPTheme
- CMFCColorButton [MFC], OnDraw
- CMFCColorButton [MFC], OnDrawBorder
- CMFCColorButton [MFC], OnDrawFocusRect
- CMFCColorButton [MFC], OnShowColorPopup
- CMFCColorButton [MFC], RebuildPalette
- CMFCColorButton [MFC], UpdateColor
- CMFCColorButton [MFC], m_bEnabledInCustomizeMode
ms.assetid: 9fdf34ae-4cc5-4c5e-9d89-1c50e8a73699
ms.openlocfilehash: ac49957f075f8798607535286d6c4518c0eeeeae
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505369"
---
# <a name="cmfccolorbutton-class"></a>Classe CMFCColorButton

As `CMFCColorButton` classes de [classe e CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) são usadas juntas para implementar um controle de seletor de cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorButton : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorButton::CMFCColorButton](#cmfccolorbutton)|Constrói um novo objeto `CMFCColorButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorButton::EnableAutomaticButton](#enableautomaticbutton)|Habilita e desabilita um botão "automático" posicionado acima dos botões de cor normais. (O botão automático do sistema padrão é rotulado como **automático**.)|
|[CMFCColorButton::EnableOtherButton](#enableotherbutton)|Habilita e desabilita um botão "outro" que está posicionado abaixo dos botões de cor normais. (O botão "outros" do sistema padrão é rotulado como **mais cores**.)|
|[CMFCColorButton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|
|[CMFCColorButton::GetColor](#getcolor)|Recupera a cor de um botão.|
|[CMFCColorButton::SetColor](#setcolor)|Define a cor de um botão.|
|[CMFCColorButton::SetColorName](#setcolorname)|Define um nome de cor.|
|[CMFCColorButton::SetColumnsNumber](#setcolumnsnumber)|Define o número de colunas na caixa de diálogo Seletor de cores.|
|[CMFCColorButton::SetDocumentColors](#setdocumentcolors)|Especifica uma lista de cores específicas de documento que são exibidas na caixa de diálogo Seletor de cores.|
|[CMFCColorButton::SetPalette](#setpalette)|Especifica uma paleta de cores de exibição padrão.|
|[CMFCColorButton::SizeToContent](#sizetocontent)|Altera o tamanho do controle de botão, dependendo do tamanho do texto e da imagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorButton::IsDrawXPTheme](#isdrawxptheme)|Indica se o botão de cor atual é exibido no estilo visual do Windows XP.|
|[CMFCColorButton:: OnDraw](#ondraw)|Chamado pelo Framework para exibir uma imagem do botão.|
|[CMFCColorButton::OnDrawBorder](#ondrawborder)|Chamado pelo Framework para exibir a borda do botão.|
|[CMFCColorButton::OnDrawFocusRect](#ondrawfocusrect)|Chamado pelo Framework para exibir um retângulo de foco quando o botão tem um foco.|
|[CMFCColorButton::OnShowColorPopup](#onshowcolorpopup)|Chamado pelo Framework quando a caixa de diálogo Seletor de cor está prestes a ser exibida.|
|[CMFCColorButton::RebuildPalette](#rebuildpalette)|Inicializa o `m_pPalette` membro de dados protegidos para a paleta especificada ou para a paleta padrão do sistema.|
|[CMFCColorButton::UpdateColor](#updatecolor)|Chamado pelo Framework quando o usuário seleciona uma cor na paleta da caixa de diálogo Seletor de cores.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|`m_bAltColorDlg`|Um booliano. Se for TRUE, a estrutura exibirá a caixa de diálogo cor do [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) quando o *outro* botão for clicado, ou se for false, a caixa de diálogo cor do sistema. O valor padrão é TRUE. Para obter mais informações, consulte [CMFCColorButton:: EnableOtherButton](#enableotherbutton).|
|`m_bAutoSetFocus`|Um booliano. Se for TRUE, a estrutura definirá o foco no menu de cores quando o menu for exibido ou, se for FALSE, não alterará o foco. O valor padrão é TRUE.|
|[CMFCColorButton::m_bEnabledInCustomizeMode](#m_benabledincustomizemode)|Indica se o modo de personalização está habilitado para o botão de cor.|
|`m_Color`|Um valor de [COLORREF](/windows/win32/gdi/colorref) . Contém a cor atualmente selecionada.|
|`m_ColorAutomatic`|Um valor de [COLORREF](/windows/win32/gdi/colorref) . Contém a cor padrão selecionada no momento.|
|`m_Colors`|Um [CArray](../../mfc/reference/carray-class.md) de valores de [COLORREF](/windows/win32/gdi/colorref) . Contém as cores disponíveis no momento.|
|`m_lstDocColors`|Um [CList](../../mfc/reference/clist-class.md) de valores de [COLORREF](/windows/win32/gdi/colorref) . Contém as cores atuais do documento.|
|`m_nColumns`|Um inteiro. Contém o número de colunas a serem exibidas na grade de cores em um menu de seleção de cores.|
|`m_pPalette`|Um ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md). Contém as cores disponíveis no menu de seleção de cor atual.|
|`m_pPopup`|Um ponteiro para um objeto de [Classe CMFCColorPopupMenu](../../mfc/reference/cmfccolorpopupmenu-class.md) . O menu de seleção de cores que é exibido quando você clica no botão de cor.|
|`m_strAutoColorText`|Uma cadeia de caracteres. O rótulo do botão "automático" em um menu de seleção de cores.|
|`m_strDocColorsText`|Uma cadeia de caracteres. O rótulo do botão em um menu de seleção de cores que exibe as cores do documento.|
|`m_strOtherText`|Uma cadeia de caracteres. O rótulo do botão "outros" em um menu de seleção de cores.|

## <a name="remarks"></a>Comentários

Por padrão, a `CMFCColorButton` classe se comporta como um botão de ação que abre uma caixa de diálogo Seletor de cores. A caixa de diálogo Seletor de cores contém uma matriz de botões de cores pequenos e um botão "outro" que exibe um seletor de cores personalizado. (O botão "outros" do sistema padrão é rotulado como **mais cores**.) Quando um usuário seleciona uma nova cor, o `CMFCColorButton` objeto reflete a alteração e exibe a cor selecionada.

Crie um controle de botão de cor diretamente no seu código ou usando a ferramenta **ClassWizard** e um modelo de caixa de diálogo. Se você criar um controle de botão de cor diretamente, `CMFCColorButton` adicione uma variável ao seu aplicativo e, em seguida, `Create` chame o construtor `CMFCColorButton` e os métodos do objeto. Se você usar o **ClassWizard**, adicione uma `CButton` variável ao seu aplicativo e, em seguida, altere o tipo da variável `CButton` de `CMFCColorButton`para.

A caixa de diálogo Seletor de cores ( [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)) é exibida pelo método [CMFCColorButton:: OnShowColorPopup](#onshowcolorpopup) quando a estrutura `OnLButtonDown` chama o manipulador de eventos. O método [CMFCColorButton:: OnShowColorPopup](#onshowcolorpopup) pode ser substituído para dar suporte à seleção de cores personalizada.

O `CMFCColorButton` objeto notifica seu pai de que uma cor está mudando enviando-a um WM_COMMAND | Notificação de BN_CLICKED. O pai usa o método [CMFCColorButton:: GetColor](#getcolor) para recuperar a cor atual.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar um botão de cor usando vários métodos na `CMFCColorButton` classe. Os métodos definem a cor do botão de cor e seu número de colunas e habilitam os botões automático e outros. Este exemplo faz parte do [exemplo de demonstração da barra de status](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#10](../../mfc/reference/codesnippet/cpp/cmfccolorbutton-class_1.h)]
[!code-cpp[NVC_MFC_StatusBarDemo#11](../../mfc/reference/codesnippet/cpp/cmfccolorbutton-class_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorbutton. h

##  <a name="cmfccolorbutton"></a>CMFCColorButton::CMFCColorButton

Constrói um novo objeto `CMFCColorButton`.

```
CMFCColorButton();
```

##  <a name="enableautomaticbutton"></a>CMFCColorButton::EnableAutomaticButton

Habilitar ou desabilitar o botão "automático" de um controle de seletor de cor e definir a cor automática (padrão).

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
no Especifica o texto do botão automático.

*colorAutomatic*<br/>
no Um valor RGB que especifica a cor padrão do botão automático.

*bEnable*<br/>
no Especifica se o botão automático está habilitado ou desabilitado.

### <a name="remarks"></a>Comentários

##  <a name="enableotherbutton"></a>CMFCColorButton::EnableOtherButton

Habilitar ou desabilitar o botão "outros", que aparece abaixo dos botões de cor regular.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg=TRUE,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
no Especifica o texto do botão.

*bAltColorDlg*<br/>
no Especifica se a caixa de diálogo [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) ou a caixa de diálogo cor do sistema é aberta quando o usuário clica no botão.

*bEnable*<br/>
no Especifica se o botão "outros" está habilitado ou desabilitado.

### <a name="remarks"></a>Comentários

Clique no botão "outros" para exibir uma caixa de diálogo de cor. Se o parâmetro *bAltColorDlg* for true, a [Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) será exibida; caso contrário, a caixa de diálogo cor do sistema será exibida.

##  <a name="getautomaticcolor"></a>CMFCColorButton::GetAutomaticColor

Recupera a cor automática (padrão) atual.

```
COLORREF GetAutomaticColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor RGB que representa a cor automática atual.

### <a name="remarks"></a>Comentários

A cor automática atual é definida pelo método [CMFCColorButton:: EnableAutomaticButton](#enableautomaticbutton) .

##  <a name="getcolor"></a>CMFCColorButton:: GetColor

Recupera a cor atualmente selecionada.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor RGB.

### <a name="remarks"></a>Comentários

##  <a name="isdrawxptheme"></a>CMFCColorButton::IsDrawXPTheme

Indica se o botão de cor atual é exibido no estilo visual do Windows XP.

```
BOOL IsDrawXPTheme() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se houver suporte para estilos visuais e o botão de cor atual for exibido no estilo visual do Windows XP; caso contrário, FALSE.

##  <a name="m_benabledincustomizemode"></a>CMFCColorButton::m_bEnabledInCustomizeMode

Define um botão de cor para o modo de personalização.

```
BOOL m_bEnabledInCustomizeMode;
```

### <a name="remarks"></a>Comentários

Se você precisar adicionar um botão de cor à página de uma caixa de diálogo de personalização (ou permitir que o usuário faça outra seleção de cores durante a personalização), habilite o botão definindo o `m_bEnabledInCustomizeMode` membro como verdadeiro. Por padrão, esse membro é definido como FALSE.

##  <a name="ondraw"></a>CMFCColorButton:: OnDraw

Chamado pelo Framework para renderizar uma imagem do botão.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Aponta para o contexto do dispositivo que é usado para renderizar a imagem do botão.

*rect*<br/>
no Um retângulo que limita o botão.

*uiState*<br/>
no Especifica o estado visual do botão.

### <a name="remarks"></a>Comentários

Substitua esse método para personalizar o processo de renderização.

##  <a name="ondrawborder"></a>CMFCColorButton::OnDrawBorder

Chamado pelo Framework para exibir a borda do botão.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect& rectClient,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Aponta para o contexto do dispositivo usado para desenhar a borda.

*rectClient*<br/>
no Um retângulo no contexto do dispositivo que é especificado pelo parâmetro do *PDC* que define os limites do botão a ser desenhado.

*uiState*<br/>
no Especifica o estado visual do botão.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar a aparência da borda do botão de cor.

##  <a name="ondrawfocusrect"></a>CMFCColorButton::OnDrawFocusRect

Chamado pelo Framework para exibir um retângulo de foco quando o botão tem foco.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Aponta para o contexto do dispositivo usado para desenhar o retângulo de foco.

*rectClient*<br/>
no Um retângulo no contexto do dispositivo especificado pelo parâmetro do *PDC* que define os limites do botão.

### <a name="remarks"></a>Comentários

Substitua esse método para personalizar a aparência do retângulo de foco.

##  <a name="onshowcolorpopup"></a>  CMFCColorButton::OnShowColorPopup

Chamado antes da barra de cores pop-up ser exibida.

```
virtual void OnShowColorPopup();
```

### <a name="remarks"></a>Comentários

##  <a name="rebuildpalette"></a>  CMFCColorButton::RebuildPalette

Inicializa o `m_pPalette` membro de dados protegidos para a paleta especificada ou para a paleta padrão do sistema.

```
void RebuildPalette(CPalette* pPal);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pPal*|no Um ponteiro para uma paleta lógica ou nulo. Se for NULL, a paleta padrão do sistema será usada.|

##  <a name="setcolor"></a>CMFCColorButton:: setColor

Especifica a cor do botão.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
no Um valor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setcolorname"></a>  CMFCColorButton::SetColorName

Especifica o nome de uma cor.

```
static void SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
no O valor RGB da cor.

*strName*<br/>
no O nome da cor.

### <a name="remarks"></a>Comentários

A lista de nomes de cores é global por aplicativo. Consequentemente, esse método transfere seus parâmetros para [CMFCColorBar::](../../mfc/reference/cmfccolorbar-class.md#setcolorname)SetColorName.

##  <a name="setcolumnsnumber"></a>  CMFCColorButton::SetColumnsNumber

Define o número de colunas que são exibidas na tabela de cores que é apresentada ao usuário durante o processo de seleção de cores do usuário.

```
void SetColumnsNumber(int nColumns);
```

### <a name="parameters"></a>Parâmetros

*nColumns*<br/>
no Especifica o número de colunas.

### <a name="remarks"></a>Comentários

O usuário pode selecionar uma cor em uma barra de cores pop-up que exibe uma tabela de cores predefinidas. Use este método para definir o número de colunas na tabela.

##  <a name="setdocumentcolors"></a>CMFCColorButton::SetDocumentColors

Especifica um conjunto de cores e o nome do conjunto. O conjunto de cores é exibido usando um objeto de [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) .

```
void SetDocumentColors(
    LPCTSTR lpszLabel,
    CList<COLORREF,COLORREF>& lstColors);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
no Especifica o rótulo a ser exibido com o conjunto de cores do documento.

*lstColors*<br/>
no Uma referência a uma lista de valores RGB.

### <a name="remarks"></a>Comentários

Um `CMFCColorButton` objeto mantém uma lista de valores RGB que são transferidos para um objeto de [Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) . Quando a barra de cores é exibida, essas cores são mostradas em uma seção especial cujo rótulo é especificado pelo parâmetro *lpszLabel* .

##  <a name="setpalette"></a>CMFCColorButton:: SetPalette

Especifica as cores padrão a serem exibidas na barra de cores pop-up.

```
void SetPalette(CPalette* pPalette);
```

### <a name="parameters"></a>Parâmetros

*pPalette*<br/>
no Um ponteiro para uma paleta de cores.

### <a name="remarks"></a>Comentários

##  <a name="sizetocontent"></a>CMFCColorButton::SizeToContent

Redimensiona o controle de botão para ajustá-lo ao texto e à imagem.

```
virtual CSize SizeToContent(BOOL bCalcOnly=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
no Se for diferente de zero, o novo tamanho do controle de botão será calculado, mas o tamanho real não será alterado.

### <a name="return-value"></a>Valor de retorno

Um `CSize` objeto que especifica um novo tamanho de controle de botão.

### <a name="remarks"></a>Comentários

##  <a name="updatecolor"></a>CMFCColorButton::UpdateColor

Chamado pelo Framework quando o usuário seleciona uma cor na barra de cores exibida quando o usuário clica no botão de cor.

```
virtual void UpdateColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
no Uma cor selecionada pelo usuário.

### <a name="remarks"></a>Comentários

A `UpdateColor` função altera a cor do botão atualmente selecionado e notifica seu pai enviando uma mensagem WM_COMMAND com uma notificação padrão do BN_CLICKED. Use o método [CMFCColorButton:: GetColor](#getcolor) para recuperar a cor selecionada.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)<br/>
[Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)<br/>
[CMFCColorButton::OnShowColorPopup](#onshowcolorpopup)<br/>
[COLORREF](/windows/win32/gdi/colorref)<br/>
[Classe CPalette](../../mfc/reference/cpalette-class.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)<br/>
[Classe CList](../../mfc/reference/clist-class.md)<br/>
[CString](../../atl-mfc-shared/reference/cstringt-class.md)
