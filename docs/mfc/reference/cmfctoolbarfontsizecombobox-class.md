---
title: Classe CMFCToolBarFontSizeComboBox
ms.date: 11/04/2016
f1_keywords:
- CMFCToolBarFontSizeComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::GetTwipSize
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::RebuildFontSizes
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::SetTwipSize
helpviewer_keywords:
- CMFCToolBarFontSizeComboBox [MFC], CMFCToolBarFontSizeComboBox
- CMFCToolBarFontSizeComboBox [MFC], GetTwipSize
- CMFCToolBarFontSizeComboBox [MFC], RebuildFontSizes
- CMFCToolBarFontSizeComboBox [MFC], SetTwipSize
ms.assetid: 72e0c44c-6a0e-4194-a71f-ab64e3afb9b5
ms.openlocfilehash: a1dd85ed7bf80f5307bf0bd07ef5ef74875c8562
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258938"
---
# <a name="cmfctoolbarfontsizecombobox-class"></a>Classe CMFCToolBarFontSizeComboBox

Um botão de barra de ferramentas que contém um controle de caixa de combinação que permite que o usuário selecione um tamanho de fonte.

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarFontSizeComboBox : public CMFCToolBarComboBoxButton
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox](#cmfctoolbarfontsizecombobox)|Constrói um objeto `CMFCToolBarFontSizeComboBox`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarFontSizeComboBox::GetTwipSize](#gettwipsize)|Retorna o tamanho da fonte selecionada em twips.|
|[CMFCToolBarFontSizeComboBox::RebuildFontSizes](#rebuildfontsizes)|Preenche a lista de caixa de combinação com todos os tamanhos de fonte com suporte para uma fonte especificada.|
|[CMFCToolBarFontSizeComboBox::SetTwipSize](#settwipsize)|Define o tamanho da fonte em twips.|

## <a name="remarks"></a>Comentários

Você pode usar um `CMFCToolBarFontSizeComboBox` do objeto junto com um [classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) objeto para permitir que um usuário selecione uma fonte e tamanho da fonte.

Você pode adicionar um botão de caixa de combinação do tamanho da fonte para uma barra de ferramentas, assim como você adicionar um botão de caixa de combinação de fonte. Para obter mais informações, consulte [classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md).

Quando o usuário seleciona uma nova fonte em uma `CMFCToolBarFontComboBox` do objeto, você pode preencher a caixa de combinação do tamanho de fonte com os tamanhos com suporte para essa fonte usando o [CMFCToolBarFontSizeComboBox::RebuildFontSizes](#rebuildfontsizes) método.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCToolBarFontSizeComboBox` classe para configurar um `CMFCToolBarFontSizeComboBox` objeto. O exemplo ilustra como recuperar o tamanho da fonte, em twips, a caixa de texto, preencher a caixa de combinação do tamanho de fonte com todos os tamanhos válidos de determinada fonte e especifique o tamanho da fonte em twips. Este trecho de código é parte do [exemplo de Word Pad](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#8](../../mfc/reference/codesnippet/cpp/cmfctoolbarfontsizecombobox-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

[CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarfontcombobox.h

##  <a name="cmfctoolbarfontsizecombobox"></a>  CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox

Constrói um objeto `CMFCToolBarFontSizeComboBox`.

```
CMFCToolBarFontSizeComboBox();
```

##  <a name="gettwipsize"></a>  CMFCToolBarFontSizeComboBox::GetTwipSize

Recupera o tamanho da fonte, em twips, a caixa de texto de uma caixa de combinação do tamanho da fonte.

```
int GetTwipSize() const;
```

### <a name="return-value"></a>Valor de retorno

Se o valor retornado for positivo, ele é o tamanho da fonte em twips. Ele é -1 se a caixa de texto da caixa de combinação está vazia. Ele é -2 se ocorrer um erro.

##  <a name="rebuildfontsizes"></a>  CMFCToolBarFontSizeComboBox::RebuildFontSizes

Preenche uma caixa de combinação do tamanho de fonte com todos os tamanhos válidos da fonte determinada.

```
void RebuildFontSizes(const CString& strFontName);
```

### <a name="parameters"></a>Parâmetros

*strFontName*<br/>
[in] Especifica um nome de fonte.

### <a name="remarks"></a>Comentários

Chame essa função quando você deseja sincronizar entre a seleção em uma caixa de combinação de fonte e uma caixa de combinação do tamanho da fonte, como uma [classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md).

##  <a name="settwipsize"></a>  CMFCToolBarFontSizeComboBox::SetTwipSize

Arredonda especificada o tamanho (em twips) até o tamanho mais próximo em pontos e, em seguida, define o tamanho selecionado na caixa de combinação para esse valor.

```
void SetTwipSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*nSize*<br/>
[in] Especifica o tamanho da fonte (em twips) para definir.

### <a name="remarks"></a>Comentários

Você pode recuperar o tamanho de uma fonte válida anterior posteriormente por meio da chamada a [CMFCToolBarFontSizeComboBox::GetTwipSize](#gettwipsize) método.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)<br/>
[CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Passo a passo: Colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
