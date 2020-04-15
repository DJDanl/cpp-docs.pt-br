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
ms.openlocfilehash: 09811b14ed805b1965015a32a25c0b67c947ff4e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358300"
---
# <a name="cmfctoolbarfontsizecombobox-class"></a>Classe CMFCToolBarFontSizeComboBox

Um botão de barra de ferramentas que contém um controle de caixa de combinação que permite ao usuário selecionar um tamanho de fonte.

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarFontSizeComboBox : public CMFCToolBarComboBoxButton
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox](#cmfctoolbarfontsizecombobox)|Constrói um objeto `CMFCToolBarFontSizeComboBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarFontSizeComboBox::GetTwipSize](#gettwipsize)|Retorna o tamanho da fonte selecionada em twips.|
|[CMFCToolBarFontSizeComboBox::RebuildFontSizes](#rebuildfontsizes)|Preenche a lista de caixas de combinação com todos os tamanhos de fonte suportados para uma fonte especificada.|
|[CMFCToolBarFontSizeComboBox::SetTwipSize](#settwipsize)|Define o tamanho da fonte em twips.|

## <a name="remarks"></a>Comentários

Você pode `CMFCToolBarFontSizeComboBox` usar um objeto juntamente com um objeto [CMFCToolBarComboBox Class](../../mfc/reference/cmfctoolbarfontcombobox-class.md) para permitir que um usuário selecione uma fonte e tamanho de fonte.

Você pode adicionar um botão de caixa de combinação de tamanho de fonte a uma barra de ferramentas assim como adicionar um botão de caixa de combinação de fonte. Para obter mais informações, consulte [CMFCToolBarFontComboBox Class](../../mfc/reference/cmfctoolbarfontcombobox-class.md).

Quando o usuário seleciona uma `CMFCToolBarFontComboBox` nova fonte em um objeto, você pode preencher a caixa de combinação de tamanho de fonte com os tamanhos suportados para essa fonte usando o método [CMFCToolBarFontSizeComboBox::RebuildFontSizes.](#rebuildfontsizes)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCToolBarFontSizeComboBox` usar vários métodos na classe para configurar um `CMFCToolBarFontSizeComboBox` objeto. O exemplo ilustra como recuperar o tamanho da fonte, em twips, da caixa de texto, preencher a caixa de combinação tamanho da fonte com todos os tamanhos válidos da fonte dada e especificar o tamanho da fonte em twips. Este trecho de código faz parte da amostra do [Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#8](../../mfc/reference/codesnippet/cpp/cmfctoolbarfontsizecombobox-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

[Cmfctoolbarcomboboxbutton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

[Cmfctoolbarfontsizecombobox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarfontcombobox.h

## <a name="cmfctoolbarfontsizecomboboxcmfctoolbarfontsizecombobox"></a><a name="cmfctoolbarfontsizecombobox"></a>CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox

Constrói um objeto `CMFCToolBarFontSizeComboBox`.

```
CMFCToolBarFontSizeComboBox();
```

## <a name="cmfctoolbarfontsizecomboboxgettwipsize"></a><a name="gettwipsize"></a>CMFCToolBarFontSizeComboBox::GetTwipSize

Recupera o tamanho da fonte, em twips, da caixa de texto de uma caixa combo de tamanho de fonte.

```
int GetTwipSize() const;
```

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for positivo, é o tamanho da fonte em twips. É -1 se a caixa de texto da caixa de combinação estiver vazia. É -2 se ocorrer um erro.

## <a name="cmfctoolbarfontsizecomboboxrebuildfontsizes"></a><a name="rebuildfontsizes"></a>CMFCToolBarFontSizeComboBox::RebuildFontSizes

Preenche uma caixa de combinação de tamanho de fonte com todos os tamanhos válidos da fonte dada.

```
void RebuildFontSizes(const CString& strFontName);
```

### <a name="parameters"></a>Parâmetros

*strFontName*<br/>
[em] Especifica um nome de fonte.

### <a name="remarks"></a>Comentários

Chame esta função quando quiser sincronizar entre a seleção em uma caixa de combinação de fonte e uma caixa de combinação de tamanho de fonte, como uma [classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md).

## <a name="cmfctoolbarfontsizecomboboxsettwipsize"></a><a name="settwipsize"></a>CMFCToolBarFontSizeComboBox::SetTwipSize

Arredonda o tamanho especificado (em twips) para o tamanho mais próximo em pontos e, em seguida, define o tamanho selecionado na caixa de combinação para esse valor.

```
void SetTwipSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
[em] Especifica o tamanho da fonte (em twips) a definir.

### <a name="remarks"></a>Comentários

Você pode recuperar o tamanho da fonte válido anterior mais tarde, chamando o [CMFCToolBarFontSizeComboBox::GetTwipSize](#gettwipsize) método.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[CMFCToolBarComboBoxClasse de botão](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)<br/>
[CMFCToolBar::Substituir botão](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
