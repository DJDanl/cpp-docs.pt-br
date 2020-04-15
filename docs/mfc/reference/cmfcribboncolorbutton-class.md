---
title: Classe CMFCRibbonColorButton
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonColorButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::CMFCRibbonColorButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::AddColorsGroup
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::EnableAutomaticButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::EnableOtherButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetAutomaticColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetColorBoxSize
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetColumns
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetHighlightedColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::RemoveAllColorGroups
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColorBoxSize
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColorName
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColumns
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetDocumentColors
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetPalette
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::UpdateColor
helpviewer_keywords:
- CMFCRibbonColorButton [MFC], CMFCRibbonColorButton
- CMFCRibbonColorButton [MFC], AddColorsGroup
- CMFCRibbonColorButton [MFC], EnableAutomaticButton
- CMFCRibbonColorButton [MFC], EnableOtherButton
- CMFCRibbonColorButton [MFC], GetAutomaticColor
- CMFCRibbonColorButton [MFC], GetColor
- CMFCRibbonColorButton [MFC], GetColorBoxSize
- CMFCRibbonColorButton [MFC], GetColumns
- CMFCRibbonColorButton [MFC], GetHighlightedColor
- CMFCRibbonColorButton [MFC], RemoveAllColorGroups
- CMFCRibbonColorButton [MFC], SetColor
- CMFCRibbonColorButton [MFC], SetColorBoxSize
- CMFCRibbonColorButton [MFC], SetColorName
- CMFCRibbonColorButton [MFC], SetColumns
- CMFCRibbonColorButton [MFC], SetDocumentColors
- CMFCRibbonColorButton [MFC], SetPalette
- CMFCRibbonColorButton [MFC], UpdateColor
ms.assetid: 6b4b4ee3-8cc0-41b4-a4eb-93e8847008e1
ms.openlocfilehash: 8cf92d8d4b1b113f751bee85ac2a7df6eb06afea
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375247"
---
# <a name="cmfcribboncolorbutton-class"></a>Classe CMFCRibbonColorButton

A `CMFCRibbonColorButton` classe implementa um botão de cor que você pode adicionar a uma barra de fita. O botão de cor da fita exibe um menu suspenso que contém uma ou mais paletas de cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonColorButton : public CMFCRibbonGallery
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonColorButton::CMFCRibbonColorButton](#cmfcribboncolorbutton)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonColorButton::AddColorsGroup](#addcolorsgroup)|Adiciona um grupo de cores à área de cores regulares.|
|[CMFCRibbonColorButton::Ativarbotão automático](#enableautomaticbutton)|Especifica se o botão **Automático** está ativado.|
|[CMFCRibbonColorButton::Ativaroutro botão](#enableotherbutton)|Habilita o **outro** botão.|
|[CMFCRibbonColorbutton::getAutomaticColor](#getautomaticcolor)||
|[CMFCRibbonColorbutton::GetColor](#getcolor)|Retorna a cor selecionada no momento.|
|[CMFCRibbonColorbutton::getColorBoxsize](#getcolorboxsize)|Retorna o tamanho dos elementos de cor que aparecem na barra de cores.|
|[CMFCRibbonColorButton::GetColumns](#getcolumns)||
|[CMFCRibbonColorbutton::gethighlightedColor](#gethighlightedcolor)|Retorna a cor do elemento selecionado no momento na paleta de cores popup.|
|[CMFCRibbonColorbutton::removeAllColorGroups](#removeallcolorgroups)|Remove todos os grupos de cores da área de cores regulares.|
|[CMFCRibbonColorButton::setColor](#setcolor)|Seleciona uma cor da área de cores regular.|
|[CMFCRibbonColorButton::setColorBoxsize](#setcolorboxsize)|Define o tamanho de todos os elementos de cor que aparecem na barra de cores.|
|[CMFCRibbonColorButton::setNome de cores](#setcolorname)||
|[CMFCRibbonColorButton::SetColunas](#setcolumns)||
|[CMFCRibbonColorButton::setDocumentCores](#setdocumentcolors)|Especifica uma lista de valores RGB a serem exibidos na área de cor do documento.|
|[CMFCRibbonColorButton::setPalette](#setpalette)||
|[CMFCRibbonColorButton::AtualizaçãoCor](#updatecolor)||

## <a name="remarks"></a>Comentários

O botão de cor da fita exibe uma barra de cor quando um usuário a pressiona. Por padrão, esta barra de cores contém uma paleta de seleção de cores chamada área de cor regular. Opcionalmente, a barra de cores pode exibir um botão **Automático,** que permite ao usuário selecionar uma cor padrão, e **um** outro botão, que exibe uma paleta de cores pop-up que contém cores adicionais.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonColorButton` usar vários métodos na classe. O exemplo mostra como `CMFCRibbonColorButton` construir um objeto, definir a imagem grande, ativar o botão **Automático,** ativar **o** outro botão, definir o número de colunas, definir o tamanho de todos os elementos de cor que aparecem na barra de cores, adicionar um grupo de cores à área de cor regular e especificar uma lista de valores RGB para exibir na área de cor do documento. Este trecho de código faz parte da [amostra Draw Client](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#3](../../mfc/reference/codesnippet/cpp/cmfcribboncolorbutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[Cmfcribbongallery](../../mfc/reference/cmfcribbongallery-class.md)

[Cmfcribboncolorbutton](../../mfc/reference/cmfcribboncolorbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncolorbutton.h

## <a name="cmfcribboncolorbuttonaddcolorsgroup"></a><a name="addcolorsgroup"></a>CMFCRibbonColorButton::AddColorsGroup

Adiciona um grupo de cores à área de cores regulares.

```
void AddColorsGroup(
    LPCTSTR lpszName,
    const CList<COLORREF,COLORREF>& lstColors,
    BOOL bContiguousColumns=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[em] O nome do grupo.

*LstColors*<br/>
[em] A lista de cores.

*bContiguousColumns*<br/>
[em] Controla como os itens de cor são exibidos no grupo. Se TRUE, os itens de cor são desenhados sem um espaçamento vertical. Se FALSO, os itens de cor são desenhados com um espaçamento vertical.

### <a name="remarks"></a>Comentários

Use esta função para fazer com que a cor pop-up exiba vários grupos de cores. Você pode controlar como as cores são exibidas em grupo.

## <a name="cmfcribboncolorbuttoncmfcribboncolorbutton"></a><a name="cmfcribboncolorbutton"></a>CMFCRibbonColorButton::CMFCRibbonColorButton

Constrói um objeto `CMFCRibbonColorButton`.

```
CMFCRibbonColorButton();

CMFCRibbonColorButton(
    UINT nID,
    LPCTSTR lpszText,
    int nSmallImageIndex,
    COLORREF color = RGB(0, 0, 0));

CMFCRibbonColorButton(
    UINT nID,
    LPCTSTR lpszText,
    BOOL bSimpleButtonLook,
    int nSmallImageIndex,
    int nLargeImageIndex,
    COLORREF color = RGB(0, 0, 0));
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] Especifica o ID de comando do comando para ser executado quando um usuário clica no botão.

*lpszText*<br/>
[em] Especifica o texto para aparecer no botão.

*nSmallImageIndex*<br/>
[em] O índice baseado em zero da pequena imagem para aparecer no botão.

*cor*<br/>
[em] A cor do botão (padrão para preto).

*bSimpleButtonLook*<br/>
[em] Se TRUE, o botão é desenhado como um retângulo simples.

*nLargeImageIndex*<br/>
[em] O índice baseado em zero da imagem grande para aparecer no botão.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncolorbuttonenableautomaticbutton"></a><a name="enableautomaticbutton"></a>CMFCRibbonColorButton::Ativarbotão automático

Especifica se o botão **Automático** está ativado.

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE,
    LPCTSTR lpszToolTip=NULL,
    BOOL bOnTop=TRUE,
    BOOL bDrawBorder=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] A etiqueta para o botão **Automático.**

*corAutomático*<br/>
[em] Um valor RGB que especifica a cor padrão do botão **Automático.**

*Benable*<br/>
[em] TRUE se o botão **Automático** estiver ativado; FALSO se estiver desativado.

*lpszToolTip*<br/>
[em] A dica de ferramenta do botão **Automático.**

*Bontop*<br/>
[em] Especifica se o botão **Automático** está na parte superior, antes da paleta de cores.

*bDrawBorder*<br/>
[em] VERDADE se o aplicativo desenhar uma borda em torno da barra de cores no botão de cor da fita. A barra de cores exibe a cor selecionada no momento. FALSO se o aplicativo não desenhar uma borda

## <a name="cmfcribboncolorbuttonenableotherbutton"></a><a name="enableotherbutton"></a>CMFCRibbonColorButton::Ativaroutro botão

Habilita o **outro** botão.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    LPCTSTR lpszToolTip=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
A etiqueta do botão.

*lpszToolTip*<br/>
O texto da dica de ferramenta para o **outro** botão.

### <a name="remarks"></a>Comentários

O **outro** botão é o botão exibido abaixo do grupo de cores. Quando o usuário clica no **outro** botão, ele exibe uma caixa de diálogo de cor.

## <a name="cmfcribboncolorbuttongetautomaticcolor"></a><a name="getautomaticcolor"></a>CMFCRibbonColorbutton::getAutomaticColor

Recupera a cor atual do botão automático.

```
COLORREF GetAutomaticColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de cor RGB que representa a cor atual do botão automático.

### <a name="remarks"></a>Comentários

A cor do botão automático `colorAutomatic` é definida `CMFCRibbonColorButton::EnableAutomaticButton` pelo parâmetro passado para o método.

## <a name="cmfcribboncolorbuttongetcolor"></a><a name="getcolor"></a>CMFCRibbonColorbutton::GetColor

Retorna a cor selecionada no momento.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor selecionada clicando no botão.

## <a name="cmfcribboncolorbuttongetcolorboxsize"></a><a name="getcolorboxsize"></a>CMFCRibbonColorbutton::getColorBoxsize

Retorna o tamanho dos elementos de cor que aparecem na barra de cores.

```
CSize GetColorBoxSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho dos botões de cor na paleta de cores gota.

## <a name="cmfcribboncolorbuttongetcolumns"></a><a name="getcolumns"></a>CMFCRibbonColorButton::GetColumns

Obtém o número de itens em uma linha da exibição da galeria do botão de cor da fita.

```
int GetColumns() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de ícones em cada linha.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncolorbuttongethighlightedcolor"></a><a name="gethighlightedcolor"></a>CMFCRibbonColorbutton::gethighlightedColor

Retorna a cor do elemento selecionado no momento na paleta de cores pop-up.

```
COLORREF GetHighlightedColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor do elemento selecionado atualmente na paleta de cores pop-up.

## <a name="cmfcribboncolorbuttonremoveallcolorgroups"></a><a name="removeallcolorgroups"></a>CMFCRibbonColorbutton::removeAllColorGroups

Remove todos os grupos de cores da área de cores regulares.

```
void RemoveAllColorGroups();
```

## <a name="cmfcribboncolorbuttonsetcolor"></a><a name="setcolor"></a>CMFCRibbonColorButton::setColor

Seleciona uma cor da área de cores regular.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Uma cor para definir.

## <a name="cmfcribboncolorbuttonsetcolorboxsize"></a><a name="setcolorboxsize"></a>CMFCRibbonColorButton::setColorBoxsize

Define o tamanho de todos os elementos de cor que aparecem na barra de cores.

```
void SetColorBoxSize(CSize sizeBox);
```

### <a name="parameters"></a>Parâmetros

*Sizebox*<br/>
[em] O novo tamanho dos botões de cor na paleta de cores.

## <a name="cmfcribboncolorbuttonsetcolorname"></a><a name="setcolorname"></a>CMFCRibbonColorButton::setNome de cores

Define um novo nome para uma cor especificada.

```
static void __stdcall SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] O valor RGB de uma cor.

*strName*<br/>
[em] O novo nome para a cor especificada.

### <a name="remarks"></a>Comentários

Por ser `CMFCColorBar::SetColorName`chamado, este método altera o nome `CMFCColorBar` da cor especificada em todos os objetos da sua aplicação.

## <a name="cmfcribboncolorbuttonsetcolumns"></a><a name="setcolumns"></a>CMFCRibbonColorButton::SetColunas

Define o número de colunas exibidas na tabela de cores que é apresentada ao usuário durante o processo de seleção de cores do usuário.

```
void SetColumns(int nColumns);
```

### <a name="parameters"></a>Parâmetros

*nColumns*<br/>
[em] O número de ícones de cor a serem exibidos em cada linha.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncolorbuttonsetdocumentcolors"></a><a name="setdocumentcolors"></a>CMFCRibbonColorButton::setDocumentCores

Especifica uma lista de valores RGB a serem exibidos na área de cor do documento.

```
void SetDocumentColors(
    LPCTSTR lpszLabel,
    CList<COLORREF,COLORREF>& lstColors);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] O texto a ser exibido com as cores do documento.

*LstColors*<br/>
[em] Uma referência a uma lista de valores RGB.

## <a name="cmfcribboncolorbuttonsetpalette"></a><a name="setpalette"></a>CMFCRibbonColorButton::setPalette

Especifica as cores padrão a serem exibidas na tabela de cores que o botão de cor exibe.

```
void SetPalette(CPalette* pPalette);
```

### <a name="parameters"></a>Parâmetros

*Ppalette*<br/>
[em] Um ponteiro para uma paleta de cores.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncolorbuttonupdatecolor"></a><a name="updatecolor"></a>CMFCRibbonColorButton::AtualizaçãoCor

Chamado pela estrutura quando o usuário seleciona uma cor da tabela de cores exibida quando o usuário clica no botão de cor.

```
void UpdateColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Uma cor selecionada pelo usuário.

### <a name="remarks"></a>Comentários

O `CMFCRibbonColorButton::UpdateColor` método altera a cor do botão selecionado no momento e notifica seu pai enviando uma mensagem de WM_COMMAND com uma notificação padrão BN_CLICKED. Use o [método CMFCRibbonColorButton::GetColor](#getcolor) para recuperar a cor selecionada.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)
