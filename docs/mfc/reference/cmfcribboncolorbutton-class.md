---
title: Classe CMFCRibbonColorButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb80e0e839169b0f78648cc2090f339b43f6360a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415326"
---
# <a name="cmfcribboncolorbutton-class"></a>Classe CMFCRibbonColorButton

O `CMFCRibbonColorButton` classe implementa um botão de cor que você pode adicionar a uma barra de faixa de opções. Botão de cor da faixa de opções exibe um menu suspenso que contém um ou mais paletas de cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonColorButton : public CMFCRibbonGallery
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonColorButton::CMFCRibbonColorButton](#cmfcribboncolorbutton)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonColorButton::AddColorsGroup](#addcolorsgroup)|Adiciona um grupo de cores para a área de cores regular.|
|[CMFCRibbonColorButton::EnableAutomaticButton](#enableautomaticbutton)|Especifica se o **automática** botão está habilitado.|
|[CMFCRibbonColorButton::EnableOtherButton](#enableotherbutton)|Permite que o **outros** botão.|
|[CMFCRibbonColorButton::GetAutomaticColor](#getautomaticcolor)||
|[CMFCRibbonColorButton::GetColor](#getcolor)|Retorna a cor atualmente selecionada.|
|[CMFCRibbonColorButton::GetColorBoxSize](#getcolorboxsize)|Retorna o tamanho dos elementos da cor que aparecem na barra de cores.|
|[CMFCRibbonColorButton::GetColumns](#getcolumns)||
|[CMFCRibbonColorButton::GetHighlightedColor](#gethighlightedcolor)|Retorna a cor do elemento atualmente selecionado na paleta de cores do pop-up.|
|[CMFCRibbonColorButton::RemoveAllColorGroups](#removeallcolorgroups)|Remove todos os grupos de cores da área de cores normal.|
|[CMFCRibbonColorButton::SetColor](#setcolor)|Seleciona uma cor da área de cores normal.|
|[CMFCRibbonColorButton::SetColorBoxSize](#setcolorboxsize)|Define o tamanho de todos os elementos de cor que aparecem na barra de cores.|
|[CMFCRibbonColorButton::SetColorName](#setcolorname)||
|[CMFCRibbonColorButton::SetColumns](#setcolumns)||
|[CMFCRibbonColorButton::SetDocumentColors](#setdocumentcolors)|Especifica uma lista de valores RGB para exibir na área de cor do documento.|
|[CMFCRibbonColorButton::SetPalette](#setpalette)||
|[CMFCRibbonColorButton::UpdateColor](#updatecolor)||

## <a name="remarks"></a>Comentários

Botão de cor da faixa de opções exibe uma barra de cores quando um usuário pressiona ele. Por padrão, essa barra de cor contém uma paleta de seleção de cor chamada a área de cores regular. Opcionalmente, a barra de cor pode exibir uma **automáticas** botão, que permite ao usuário selecionar uma cor padrão, e uma **outros** botão, que exibe uma paleta de cores de pop-up que contém cores adicionais.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonColorButton` classe. O exemplo mostra como construir um `CMFCRibbonColorButton` do objeto, defina a imagem grande, habilitar o **automática** botão, habilite o **outros** botão, defina o número de colunas, defina o tamanho de todos os elementos de cor que aparecem na barra de cores, adicionar um grupo de cores para a área de cores regular e especificar uma lista de valores RGB para exibir na área de cor do documento. Este trecho de código é parte do [desenhar o cliente de exemplo](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#3](../../mfc/reference/codesnippet/cpp/cmfcribboncolorbutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)

[CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncolorbutton.h

##  <a name="addcolorsgroup"></a>  CMFCRibbonColorButton::AddColorsGroup

Adiciona um grupo de cores para a área de cores regular.

```
void AddColorsGroup(
    LPCTSTR lpszName,
    const CList<COLORREF,COLORREF>& lstColors,
    BOOL bContiguousColumns=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[in] O nome do grupo.

*lstColors*<br/>
[in] A lista de cores.

*bContiguousColumns*<br/>
[in] Controla como os itens de cor são exibidos no grupo. Se for TRUE, os itens de cor são desenhados sem um espaçamento vertical. Se for FALSE, os itens de cor são desenhados com um espaçamento vertical.

### <a name="remarks"></a>Comentários

Use essa função para tornar a cor de pop-up exibe vários grupos de cores. Você pode controlar como as cores são exibidas no grupo.

##  <a name="cmfcribboncolorbutton"></a>  CMFCRibbonColorButton::CMFCRibbonColorButton

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
[in] Especifica a ID do comando a ser executado quando um usuário clica no botão de comando.

*lpszText*<br/>
[in] Especifica o texto a ser exibido no botão.

*nSmallImageIndex*<br/>
[in] O índice baseado em zero da imagem pequena apareça no botão.

*Cor*<br/>
[in] A cor do botão (o padrão é preto).

*bSimpleButtonLook*<br/>
[in] Se for TRUE, o botão é desenhado como um retângulo simples.

*nLargeImageIndex*<br/>
[in] O índice baseado em zero da imagem grande para ser exibido no botão.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="enableautomaticbutton"></a>  CMFCRibbonColorButton::EnableAutomaticButton

Especifica se o **automática** botão está habilitado.

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
[in] O rótulo para o **automática** botão.

*automáticaCor*<br/>
[in] Um valor RGB que especifica o **automática** cor do padrão do botão.

*bAtivar*<br/>
[in] TRUE se o **automática** botão estiver habilitado; FALSE se ele estiver desabilitado.

*lpszToolTip*<br/>
[in] A dica de ferramenta do **automática** botão.

*bOnTop*<br/>
[in] Especifica se o **automática** botão está no topo, antes da paleta de cores.

*bDrawBorder*<br/>
[in] TRUE se o aplicativo desenha uma borda em torno da barra de cores do botão de cor da faixa de opções. Barra de cores exibe a cor atualmente selecionada. FALSE se o aplicativo não desenhar uma borda

##  <a name="enableotherbutton"></a>  CMFCRibbonColorButton::EnableOtherButton

Permite que o **outros** botão.

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    LPCTSTR lpszToolTip=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
O rótulo do botão.

*lpszToolTip*<br/>
O texto de dica de ferramenta para o **outros** botão.

### <a name="remarks"></a>Comentários

O **outros** botão é o que é exibido abaixo do grupo de cores. Quando o usuário clica o **outros** botão, ele exibe uma caixa de diálogo de cor.

##  <a name="getautomaticcolor"></a>  CMFCRibbonColorButton::GetAutomaticColor

Recupera a cor atual do botão automático.

```
COLORREF GetAutomaticColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de cor RGB que representa a cor atual do botão automático.

### <a name="remarks"></a>Comentários

A cor do botão automático é definida pela `colorAutomatic` parâmetro passado para o `CMFCRibbonColorButton::EnableAutomaticButton` método.

##  <a name="getcolor"></a>  CMFCRibbonColorButton::GetColor

Retorna a cor atualmente selecionada.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor selecionada clicando no botão.

##  <a name="getcolorboxsize"></a>  CMFCRibbonColorButton::GetColorBoxSize

Retorna o tamanho dos elementos da cor que aparecem na barra de cores.

```
CSize GetColorBoxSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho dos botões de cor na paleta de cores da lista suspensa.

##  <a name="getcolumns"></a>  CMFCRibbonColorButton::GetColumns

Obtém o número de itens em uma linha da exibição de galeria do botão de cor da faixa de opções.

```
int GetColumns() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de ícones em cada linha.

### <a name="remarks"></a>Comentários

##  <a name="gethighlightedcolor"></a>  CMFCRibbonColorButton::GetHighlightedColor

Retorna a cor do elemento atualmente selecionado na paleta de cores pop-up.

```
COLORREF GetHighlightedColor() const;
```

### <a name="return-value"></a>Valor de retorno

A cor do elemento atualmente selecionado na paleta de cores pop-up.

##  <a name="removeallcolorgroups"></a>  CMFCRibbonColorButton::RemoveAllColorGroups

Remove todos os grupos de cores da área de cores normal.

```
void RemoveAllColorGroups();
```

##  <a name="setcolor"></a>  CMFCRibbonColorButton::SetColor

Seleciona uma cor da área de cores normal.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*Cor*<br/>
[in] Uma cor a ser definido.

##  <a name="setcolorboxsize"></a>  CMFCRibbonColorButton::SetColorBoxSize

Define o tamanho de todos os elementos de cor que aparecem na barra de cores.

```
void SetColorBoxSize(CSize sizeBox);
```

### <a name="parameters"></a>Parâmetros

*sizeBox*<br/>
[in] O novo tamanho dos botões de cor na paleta de cores.

##  <a name="setcolorname"></a>  CMFCRibbonColorButton::SetColorName

Define um novo nome para uma cor especificada.

```
static void __stdcall SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*Cor*<br/>
[in] O valor RGB da cor.

*strName*<br/>
[in] O novo nome para a cor especificada.

### <a name="remarks"></a>Comentários

Pois ele chama `CMFCColorBar::SetColorName`, esse método altera o nome da cor especificada em todos os `CMFCColorBar` objetos em seu aplicativo.

##  <a name="setcolumns"></a>  CMFCRibbonColorButton::SetColumns

Define o número de colunas exibidas na tabela de cores que é apresentada ao usuário durante o processo de seleção de cor do usuário.

```
void SetColumns(int nColumns);
```

### <a name="parameters"></a>Parâmetros

*nColumns*<br/>
[in] O número de ícones de cor para exibir em cada linha.

### <a name="remarks"></a>Comentários

##  <a name="setdocumentcolors"></a>  CMFCRibbonColorButton::SetDocumentColors

Especifica uma lista de valores RGB para exibir na área de cor do documento.

```
void SetDocumentColors(
    LPCTSTR lpszLabel,
    CList<COLORREF,COLORREF>& lstColors);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[in] O texto a ser exibido com as cores de documento.

*lstColors*<br/>
[in] Uma referência a uma lista de valores RGB.

##  <a name="setpalette"></a>  CMFCRibbonColorButton::SetPalette

Especifica as cores padrão para exibir na tabela de cores que exibe o botão de cor.

```
void SetPalette(CPalette* pPalette);
```

### <a name="parameters"></a>Parâmetros

*pPalette*<br/>
[in] Um ponteiro para uma paleta de cores.

### <a name="remarks"></a>Comentários

##  <a name="updatecolor"></a>  CMFCRibbonColorButton::UpdateColor

Chamado pelo framework quando o usuário seleciona uma cor na tabela de cores exibida quando o usuário clica no botão de cor.

```
void UpdateColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*Cor*<br/>
[in] Cor selecionada pelo usuário.

### <a name="remarks"></a>Comentários

O `CMFCRibbonColorButton::UpdateColor` método altera a cor do botão selecionado no momento e notificará seu pai, enviando uma mensagem WM_COMMAND com uma notificação de BN_CLICKED padrão. Use o [CMFCRibbonColorButton::GetColor](#getcolor) método para recuperar a cor selecionada.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)
