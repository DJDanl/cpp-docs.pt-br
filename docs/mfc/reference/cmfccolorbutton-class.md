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
ms.openlocfilehash: 21d05fd8e805467f1a7a77d20c81d5ba0401455e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367728"
---
# <a name="cmfccolorbutton-class"></a>Classe CMFCColorButton

As `CMFCColorButton` classes [CMFCColorBar Class](../../mfc/reference/cmfccolorbar-class.md) são usadas juntas para implementar um controle de seletor de cores.

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
|[CMFCColorButton::Ativarbotão automático](#enableautomaticbutton)|Ativa e desativa um botão "automático" posicionado acima dos botões de cor regulares. (O botão automático do sistema padrão é rotulado **como Automático**.)|
|[CMFCColorButton::Ativaroutro botão](#enableotherbutton)|Ativa e desativa um botão "outro" posicionado abaixo dos botões de cor regulares. (O botão padrão do sistema "outros" está rotulado como **Mais Cores**.)|
|[CMFCColorbutton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|
|[CMFCColorbutton::GetColor](#getcolor)|Recupera a cor de um botão.|
|[CMFCColorButton::setColor](#setcolor)|Define a cor de um botão.|
|[CMFCColorButton::setNome de cores](#setcolorname)|Define um nome de cor.|
|[CMFCColorButton::ConjuntoColunasNúmero](#setcolumnsnumber)|Define o número de colunas na caixa de diálogo seletor de cores.|
|[CMFCColorButton::conjuntoDocumentCores](#setdocumentcolors)|Especifica uma lista de cores específicas do documento exibidas na caixa de diálogo seletor de cores.|
|[CMFCColorButton::SetPalette](#setpalette)|Especifica uma paleta de cores padrão de exibição.|
|[CMFCColorButton::SizeToContent](#sizetocontent)|Altera o tamanho do controle do botão, dependendo do seu texto e tamanho da imagem.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorButton::IsDrawXPTheme](#isdrawxptheme)|Indica se o botão de cor atual é exibido no estilo visual do Windows XP.|
|[CMFCColorButton::OnDraw](#ondraw)|Chamado pela estrutura para exibir uma imagem do botão.|
|[CMFCColorbutton::OnDrawBorder](#ondrawborder)|Chamado pela estrutura para exibir a borda do botão.|
|[CMFCColorButton::OnDrawFocusRect](#ondrawfocusrect)|Chamado pela estrutura para exibir um retângulo de foco quando o botão tiver um foco.|
|[CMFCColorButton::OnShowColorPopup](#onshowcolorpopup)|Chamada pela estrutura quando a caixa de diálogo do seletor de cores está prestes a ser exibida.|
|[CMFCColorButton::RebuildPalette](#rebuildpalette)|Inicializa o `m_pPalette` membro de dados protegido para a paleta especificada ou a paleta padrão do sistema.|
|[CMFCColorButton::AtualizaçãoCor](#updatecolor)|Chamado pela estrutura quando o usuário seleciona uma cor da paleta da caixa de diálogo do seletor de cores.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|`m_bAltColorDlg`|Um valor booleano. Se TRUE, a estrutura exibirá a caixa de diálogo de cor [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) quando o *outro* botão estiver clicado ou, se FALSO, a caixa de diálogo de cor do sistema. O valor padrão é TRUE. Para obter mais informações, consulte [CMFCColorButton::EnableOtherButton](#enableotherbutton).|
|`m_bAutoSetFocus`|Um valor booleano. Se TRUE, a estrutura define o foco no menu de cores quando o menu é exibido, ou se FALSO, não altera o foco. O valor padrão é TRUE.|
|[CMFCColorButton::m_bEnabledInCustomizeMode](#m_benabledincustomizemode)|Indica se o modo de personalização está ativado para o botão de cor.|
|`m_Color`|Um valor [COLORREF.](/windows/win32/gdi/colorref) Contém a cor selecionada no momento.|
|`m_ColorAutomatic`|Um valor [COLORREF.](/windows/win32/gdi/colorref) Contém a cor padrão selecionada no momento.|
|`m_Colors`|Um [CArray](../../mfc/reference/carray-class.md) de valores [COLORREF.](/windows/win32/gdi/colorref) Contém as cores disponíveis no momento.|
|`m_lstDocColors`|Uma [Lista C](../../mfc/reference/clist-class.md) de valores [COLORREF.](/windows/win32/gdi/colorref) Contém as cores atuais do documento.|
|`m_nColumns`|Um inteiro. Contém o número de colunas a serem exibidas na grade de cores em um menu de seleção de cores.|
|`m_pPalette`|Um ponteiro para uma [Paleta C](../../mfc/reference/cpalette-class.md). Contém as cores disponíveis no menu de seleção de cores atual.|
|`m_pPopup`|Um ponteiro para um objeto [CMFCColorPopupMenu Class.](../../mfc/reference/cmfccolorpopupmenu-class.md) O menu de seleção de cores exibido quando você clica no botão de cor.|
|`m_strAutoColorText`|Uma cadeia de caracteres. O rótulo do botão "automático" em um menu de seleção de cores.|
|`m_strDocColorsText`|Uma cadeia de caracteres. O rótulo do botão em um menu de seleção de cores que exibe as cores do documento.|
|`m_strOtherText`|Uma cadeia de caracteres. O rótulo do botão "outro" em um menu de seleção de cores.|

## <a name="remarks"></a>Comentários

Por padrão, `CMFCColorButton` a classe se comporta como um botão que abre uma caixa de diálogo do seletor de cores. A caixa de diálogo do seletor de cores contém uma matriz de pequenos botões de cor e um botão "outro" que exibe um seletor de cores personalizado. (O botão padrão do sistema "outros" está rotulado como **Mais Cores**.) Quando um usuário seleciona uma `CMFCColorButton` nova cor, o objeto reflete a alteração e exibe a cor selecionada.

Crie um controle de botão de cor diretamente em seu código ou usando a ferramenta **ClassWizard** e um modelo de caixa de diálogo. Se você criar um controle de `CMFCColorButton` botão de cor diretamente, adicione `Create` uma variável `CMFCColorButton` ao seu aplicativo e, em seguida, chame o construtor e os métodos do objeto. Se você usar o **ClassWizard,** adicione uma `CButton` variável ao seu aplicativo `CButton` `CMFCColorButton`e, em seguida, altere o tipo da variável de .

A caixa de diálogo do seletor de cores [(CMFCColorBar Class)](../../mfc/reference/cmfccolorbar-class.md)é exibida pelo método `OnLButtonDown` [CMFCColorButton::OnShowColorPopup](#onshowcolorpopup) quando a estrutura chama o manipulador de eventos. O método [CMFCColorButton::OnShowColorPopup](#onshowcolorpopup) pode ser substituído para suportar a seleção personalizada de cores.

O `CMFCColorButton` objeto notifica seu pai de que uma cor está mudando enviando-a um WM_COMMAND | BN_CLICKED notificação. O pai usa o método [CMFCColorButton::GetColor](#getcolor) para recuperar a cor atual.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar um botão `CMFCColorButton` de cor usando vários métodos na classe. Os métodos definem a cor do botão de cor e seu número de colunas e ativam os botões automáticos e os outros. Este exemplo faz parte da [amostra de demonstração da barra de status](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_StatusBarDemo#10](../../mfc/reference/codesnippet/cpp/cmfccolorbutton-class_1.h)]
[!code-cpp[NVC_MFC_StatusBarDemo#11](../../mfc/reference/codesnippet/cpp/cmfccolorbutton-class_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorbutton.h

## <a name="cmfccolorbuttoncmfccolorbutton"></a><a name="cmfccolorbutton"></a>CMFCColorButton::CMFCColorButton

Constrói um novo objeto `CMFCColorButton`.

```
CMFCColorButton();
```

## <a name="cmfccolorbuttonenableautomaticbutton"></a><a name="enableautomaticbutton"></a>CMFCColorButton::Ativarbotão automático

Habilite ou desative o botão "automático" de um controle de seleção de cores e defina a cor automática (padrão).

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] Especifica o texto do botão automático.

*corAutomático*<br/>
[em] Um valor RGB que especifica a cor padrão do botão automático.

*Benable*<br/>
[em] Especifica se o botão automático está ativado ou desativado.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbuttonenableotherbutton"></a><a name="enableotherbutton"></a>CMFCColorButton::Ativaroutro botão

Habilite ou desative o botão "outro", que aparece abaixo dos botões de cor regulares.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg=TRUE,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] Especifica o texto do botão.

*bAltColorDlg*<br/>
[em] Especifica se a caixa de diálogo [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) ou a caixa de diálogo de cor do sistema são abertas quando o usuário clica no botão.

*Benable*<br/>
[em] Especifica se o botão "outro" está ativado ou desativado.

### <a name="remarks"></a>Comentários

Clique no botão "outro" para exibir uma caixa de diálogo de cor. Se o parâmetro *bAltColorDlg* for TRUE, a [classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) será exibida; caso contrário, a caixa de diálogo de cor do sistema é exibida.

## <a name="cmfccolorbuttongetautomaticcolor"></a><a name="getautomaticcolor"></a>CMFCColorbutton::GetAutomaticColor

Recupera a cor automática (padrão) atual.

```
COLORREF GetAutomaticColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor RGB representando a cor automática atual.

### <a name="remarks"></a>Comentários

A cor automática atual é definida pelo método [CMFCColorButton::EnableAutomaticButton.](#enableautomaticbutton)

## <a name="cmfccolorbuttongetcolor"></a><a name="getcolor"></a>CMFCColorbutton::GetColor

Recupera a cor selecionada no momento.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbuttonisdrawxptheme"></a><a name="isdrawxptheme"></a>CMFCColorButton::IsDrawXPTheme

Indica se o botão de cor atual é exibido no estilo visual do Windows XP.

```
BOOL IsDrawXPTheme() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se os estilos visuais forem suportados e o botão de cor atual for exibido no estilo visual do Windows XP; caso contrário, FALSE.

## <a name="cmfccolorbuttonm_benabledincustomizemode"></a><a name="m_benabledincustomizemode"></a>CMFCColorButton::m_bEnabledInCustomizeMode

Define um botão de cor para o modo de personalização.

```
BOOL m_bEnabledInCustomizeMode;
```

### <a name="remarks"></a>Comentários

Se você precisar adicionar um botão de cor à página de uma caixa de diálogo de personalização (ou permitir que o usuário faça outra seleção de cores durante a personalização), habilite o botão definindo o `m_bEnabledInCustomizeMode` membro como TRUE. Por padrão, este membro é definido como FALSE.

## <a name="cmfccolorbuttonondraw"></a><a name="ondraw"></a>CMFCColorButton::OnDraw

Chamado pela estrutura para renderizar uma imagem do botão.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Aponta para o contexto do dispositivo que é usado para renderizar a imagem do botão.

*Rect*<br/>
[em] Um retângulo que limita o botão.

*uiState*<br/>
[em] Especifica o estado visual do botão.

### <a name="remarks"></a>Comentários

Anular este método para personalizar o processo de renderização.

## <a name="cmfccolorbuttonondrawborder"></a><a name="ondrawborder"></a>CMFCColorbutton::OnDrawBorder

Chamado pela estrutura para exibir a borda do botão.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect& rectClient,
    UINT uiState);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Aponta para o contexto do dispositivo usado para desenhar a borda.

*rectClient*<br/>
[em] Um retângulo no contexto do dispositivo especificado pelo parâmetro *pDC* que define os limites do botão a ser desenhado.

*uiState*<br/>
[em] Especifica o estado visual do botão.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar a aparência da borda do botão de cor.

## <a name="cmfccolorbuttonondrawfocusrect"></a><a name="ondrawfocusrect"></a>CMFCColorButton::OnDrawFocusRect

Chamado pela estrutura para exibir um retângulo de foco quando o botão tiver foco.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Aponta para o contexto do dispositivo usado para desenhar o retângulo de foco.

*rectClient*<br/>
[em] Um retângulo no contexto do dispositivo especificado pelo parâmetro *pDC* que define os limites do botão.

### <a name="remarks"></a>Comentários

Anular este método para personalizar a aparência do retângulo de foco.

## <a name="cmfccolorbuttononshowcolorpopup"></a><a name="onshowcolorpopup"></a>CMFCColorButton::OnShowColorPopup

Chamado antes da barra de cores pop-up ser exibida.

```
virtual void OnShowColorPopup();
```

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbuttonrebuildpalette"></a><a name="rebuildpalette"></a>CMFCColorButton::RebuildPalette

Inicializa o `m_pPalette` membro de dados protegido para a paleta especificada ou a paleta padrão do sistema.

```
void RebuildPalette(CPalette* pPal);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pPal*|[em] Um ponteiro para uma paleta lógica ou NULL. Se NULL, a paleta padrão do sistema é usada.|

## <a name="cmfccolorbuttonsetcolor"></a><a name="setcolor"></a>CMFCColorButton::setColor

Especifica a cor do botão.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Um valor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbuttonsetcolorname"></a><a name="setcolorname"></a>CMFCColorButton::setNome de cores

Especifica o nome de uma cor.

```
static void SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] A cor é o valor RGB.

*strName*<br/>
[em] O nome da cor.

### <a name="remarks"></a>Comentários

A lista de nomes de cores é global por aplicativo. Consequentemente, este método transfere seus parâmetros para [CMFCColorBar::SetColorName](../../mfc/reference/cmfccolorbar-class.md#setcolorname).

## <a name="cmfccolorbuttonsetcolumnsnumber"></a><a name="setcolumnsnumber"></a>CMFCColorButton::ConjuntoColunasNúmero

Define o número de colunas exibidas na tabela de cores que é apresentada ao usuário durante o processo de seleção de cores do usuário.

```
void SetColumnsNumber(int nColumns);
```

### <a name="parameters"></a>Parâmetros

*nColumns*<br/>
[em] Especifica o número de colunas.

### <a name="remarks"></a>Comentários

O usuário pode selecionar uma cor de uma barra de cores popup que exibe uma tabela de cores predefinidas. Use este método para definir o número de colunas na tabela.

## <a name="cmfccolorbuttonsetdocumentcolors"></a><a name="setdocumentcolors"></a>CMFCColorButton::conjuntoDocumentCores

Especifica um conjunto de cores e o nome do conjunto. O conjunto de cores é exibido usando um objeto [CMFCColorBar Class.](../../mfc/reference/cmfccolorbar-class.md)

```
void SetDocumentColors(
    LPCTSTR lpszLabel,
    CList<COLORREF,COLORREF>& lstColors);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] Especifica o rótulo a ser exibido com o conjunto de cores do documento.

*LstColors*<br/>
[em] Uma referência a uma lista de valores RGB.

### <a name="remarks"></a>Comentários

Um `CMFCColorButton` objeto mantém uma lista de valores RGB que são transferidos para um objeto [CMFCColorBar Class.](../../mfc/reference/cmfccolorbar-class.md) Quando a barra de cores é exibida, essas cores são mostradas em uma seção especial cujo rótulo é especificado pelo parâmetro *lpszLabel.*

## <a name="cmfccolorbuttonsetpalette"></a><a name="setpalette"></a>CMFCColorButton::SetPalette

Especifica as cores padrão a serem exibidas na barra de cores popup.

```
void SetPalette(CPalette* pPalette);
```

### <a name="parameters"></a>Parâmetros

*Ppalette*<br/>
[em] Um ponteiro para uma paleta de cores.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbuttonsizetocontent"></a><a name="sizetocontent"></a>CMFCColorButton::SizeToContent

Redimensiona o controle do botão para ajustar seu texto e imagem.

```
virtual CSize SizeToContent(BOOL bCalcOnly=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bCalcOnly*<br/>
[em] Se não zero, o novo tamanho do controle do botão é calculado, mas o tamanho real não é alterado.

### <a name="return-value"></a>Valor retornado

Um `CSize` objeto que especifica um novo tamanho de controle de botão.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorbuttonupdatecolor"></a><a name="updatecolor"></a>CMFCColorButton::AtualizaçãoCor

Chamado pela estrutura quando o usuário seleciona uma cor da barra de cores que é exibida quando o usuário clica no botão de cor.

```
virtual void UpdateColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Uma cor selecionada pelo usuário.

### <a name="remarks"></a>Comentários

A `UpdateColor` função altera a cor do botão selecionado no momento e notifica seu pai enviando uma mensagem WM_COMMAND com uma notificação padrão BN_CLICKED. Use o [método CMFCColorButton::GetColor](#getcolor) para recuperar a cor selecionada.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)<br/>
[Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)<br/>
[CMFCColorButton::OnShowColorPopup](#onshowcolorpopup)<br/>
[COLORREF](/windows/win32/gdi/colorref)<br/>
[Classe CPalette](../../mfc/reference/cpalette-class.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)<br/>
[Classe CList](../../mfc/reference/clist-class.md)<br/>
[Cstring](../../atl-mfc-shared/reference/cstringt-class.md)
