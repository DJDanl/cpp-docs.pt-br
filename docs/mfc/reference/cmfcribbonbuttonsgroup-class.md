---
title: Classe CMFCRibbonButtonsGroup
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonButtonsGroup
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::AddButton
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::AddButtons
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::GetButton
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::GetCount
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::GetImageSize
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::GetRegularSize
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::HasImages
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::OnDrawImage
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::RemoveAll
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::SetImages
- AFXRIBBONBUTTONSGROUP/CMFCRibbonButtonsGroup::SetParentCategory
helpviewer_keywords:
- CMFCRibbonButtonsGroup [MFC], CMFCRibbonButtonsGroup
- CMFCRibbonButtonsGroup [MFC], AddButton
- CMFCRibbonButtonsGroup [MFC], AddButtons
- CMFCRibbonButtonsGroup [MFC], GetButton
- CMFCRibbonButtonsGroup [MFC], GetCount
- CMFCRibbonButtonsGroup [MFC], GetImageSize
- CMFCRibbonButtonsGroup [MFC], GetRegularSize
- CMFCRibbonButtonsGroup [MFC], HasImages
- CMFCRibbonButtonsGroup [MFC], OnDrawImage
- CMFCRibbonButtonsGroup [MFC], RemoveAll
- CMFCRibbonButtonsGroup [MFC], SetImages
- CMFCRibbonButtonsGroup [MFC], SetParentCategory
ms.assetid: b993d93e-fc1a-472f-a87f-1d7b7b499845
ms.openlocfilehash: af5919ff2a72fc2aa1eeeb95fc93afbe9e743582
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375280"
---
# <a name="cmfcribbonbuttonsgroup-class"></a>Classe CMFCRibbonButtonsGroup

A `CMFCRibbonButtonsGroup` classe permite que você organize um conjunto de botões de fita em um grupo. Todos os botões do grupo são diretamente adjacentes um ao outro horizontalmente e fechados em uma borda.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonButtonsGroup : public CMFCRibbonBaseElement
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup](#cmfcribbonbuttonsgroup)|Constrói um objeto `CMFCRibbonButtonsGroup`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonButtonsGroup::AddButton](#addbutton)|Adiciona um botão a um grupo.|
|[CMFCRibbonButtonsGroup::AddButtons](#addbuttons)|Adiciona uma lista de botões a um grupo.|
|[CMFCRibbonButtonsGroup::GetButton](#getbutton)|Retorna um ponteiro para o botão localizado em um índice especificado.|
|[CMFCRibbonButtonsGroup::GetCount](#getcount)|Retorna o número de botões no grupo.|
|[CMFCRibbonButtonsGroup::GetImageSize](#getimagesize)|Retorna o tamanho da imagem das imagens normais no grupo de fitas (substitui [CMFCRibbonBaseElement::GetImageSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getimagesize).)|
|[CMFCRibbonButtonsGroup::GetRegularSize](#getregularsize)|Retorna o tamanho regular do elemento de fita (substitui [CMFCRibbonBaseElement::GetRegularSize](../../mfc/reference/cmfcribbonbaseelement-class.md#getregularsize).)|
|[CMFCRibbonButtonsGroup::HasImages](#hasimages)|Informa se `CMFCRibbonButtonsGroup` o objeto contém imagens da barra de ferramentas.|
|[CMFCRibbonButtonsGroup::OnDrawImage](#ondrawimage)|Desenha a imagem apropriada para um botão especificado, dependendo se o botão está normal, destacado ou desativado.|
|[CMFCRibbonButtonsGroup::RemoveAll](#removeall)|Remove todos os botões `CMFCRibbonButtonsGroup` do objeto.|
|[CMFCRibbonButtonsGroup::SetImages](#setimages)|Atribui imagens ao grupo.|
|[CMFCRibbonButtonsGroup::SetParentCategory](#setparentcategory)|Define o `CMFCRibbonCategory` pai `CMFCRibbonButtonsGroup` do objeto e todos os botões dentro dele (substitui [CMFCRibbonBaseElement::SetParentCategory](../../mfc/reference/cmfcribbonbaseelement-class.md#setparentcategory).)|

## <a name="remarks"></a>Comentários

O grupo é derivado do [CMFCBaseRibbonElement](../../mfc/reference/cmfcribbonbaseelement-class.md) e pode ser manipulado como uma única entidade. Você pode posicionar o grupo em qualquer painel ou menu pop-up.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonButtonsGroup` usar vários métodos na classe. O exemplo mostra como `CMFCRibbonButtonsGroup` construir um objeto, atribuir imagens ao grupo de botões de fita e adicionar um botão ao grupo de botões de fita. Este trecho de código faz parte da [amostra Draw Client](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#2](../../mfc/reference/codesnippet/cpp/cmfcribbonbuttonsgroup-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButtonsGroup](../../mfc/reference/cmfcribbonbuttonsgroup-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonbuttonsgroup.h

## <a name="cmfcribbonbuttonsgroupaddbutton"></a><a name="addbutton"></a>CMFCRibbonButtonsGroup::AddButton

Adiciona um botão a um grupo.

```
void AddButton(CMFCRibbonBaseElement* pButton);
```

### <a name="parameters"></a>Parâmetros

*Pbutton*<br/>
[em] Um ponteiro para um botão para adicionar.

## <a name="cmfcribbonbuttonsgroupaddbuttons"></a><a name="addbuttons"></a>CMFCRibbonButtonsGroup::AddButtons

Adiciona uma lista de botões a um grupo.

```
void AddButtons(
    const CList<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>& lstButtons);
```

### <a name="parameters"></a>Parâmetros

*LstButtons*<br/>
[em] Uma lista de ponteiros para os botões que você deseja adicionar.

## <a name="cmfcribbonbuttonsgroupcmfcribbonbuttonsgroup"></a><a name="cmfcribbonbuttonsgroup"></a>CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup

Constrói um objeto `CMFCRibbonButtonsGroup`.

```
CMFCRibbonButtonsGroup();
CMFCRibbonButtonsGroup(CMFCRibbonBaseElement* pButton);
```

### <a name="parameters"></a>Parâmetros

*Pbutton*<br/>
[em] Especifica um botão para adicionar ao `CMFCRibbonButtonsGroup` objeto recém-criado.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgroupgetbutton"></a><a name="getbutton"></a>CMFCRibbonButtonsGroup::GetButton

Retorna um ponteiro para o botão localizado em um índice especificado.

```
CMFCRibbonBaseElement* GetButton(int i) const;
```

### <a name="parameters"></a>Parâmetros

*Eu*<br/>
[em] Um índice baseado em zero de um botão para retornar.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o botão localizado no índice especificado. NULL se o índice especificado estiver fora de alcance.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgroupgetcount"></a><a name="getcount"></a>CMFCRibbonButtonsGroup::GetCount

Retorna o número de botões no grupo.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de botões no grupo.

## <a name="cmfcribbonbuttonsgroupgetimagesize"></a><a name="getimagesize"></a>CMFCRibbonButtonsGroup::GetImageSize

Recupera o tamanho da imagem `CMFCToolBarImages` `m_Images`de origem do membro protegido .

```
const CSize GetImageSize() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o tamanho da imagem de origem das imagens `CSize` da barra de ferramentas, se alguma estiver presente, ou uma de zero, se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgroupgetregularsize"></a><a name="getregularsize"></a>CMFCRibbonButtonsGroup::GetRegularSize

Recupera o tamanho máximo possível do elemento do grupo de fita.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o contexto do dispositivo do grupo de fita.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgrouphasimages"></a><a name="hasimages"></a>CMFCRibbonButtonsGroup::HasImages

Informa se `CMFCRibbonButtonsGroup` o objeto contém imagens da barra de ferramentas.

```
BOOL HasImages() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se `CMFCToolBarImages` `m_Images` o membro protegido contiver imagens ou FALSOs, se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgroupondrawimage"></a><a name="ondrawimage"></a>CMFCRibbonButtonsGroup::OnDrawImage

Desenha a imagem apropriada para um botão especificado, dependendo se o botão está normal, destacado ou desativado.

```
virtual void OnDrawImage(
    CDC* pDC,
    CRect rectImage,
    CMFCRibbonBaseElement* pButton,
    int nImageIndex);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o contexto `CMFCRibbonButtonsGroup` do dispositivo do objeto.

*rectImage*<br/>
[em] O retângulo dentro do qual desenhar a imagem.

*Pbutton*<br/>
[em] O botão para desenhar a imagem.

*nImageIndex*<br/>
[em] O índice da imagem para desenhar no botão (em um dos três arrays de imagem para botões normais, destacados ou desativados).

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgroupremoveall"></a><a name="removeall"></a>CMFCRibbonButtonsGroup::RemoveAll

Remove todos os botões `CMFCRibbonButtonsGroup` do objeto.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonbuttonsgroupsetimages"></a><a name="setimages"></a>CMFCRibbonButtonsGroup::SetImages

Atribui imagens ao grupo de botões de fita.

```
void SetImages(
    CMFCToolBarImages* pImages,
    CMFCToolBarImages* pHotImages,
    CMFCToolBarImages* pDisabledImages);
```

### <a name="parameters"></a>Parâmetros

*pImagens*<br/>
[em] Imagens regulares.

*pHotImages*<br/>
[em] Imagens quentes.

*pDisabledImages*<br/>
[em] Imagens desativadas.

### <a name="remarks"></a>Comentários

Ligue `SetImages` antes de adicionar botões a um grupo. O número de imagens deve ser maior ou igual ao número de botões a serem adicionados ao grupo.

> [!NOTE]
> Imagens quentes são imagens que são exibidas quando o usuário paira sobre o botão. Imagens desativadas são imagens que são exibidas quando o botão é desativado.

## <a name="cmfcribbonbuttonsgroupsetparentcategory"></a><a name="setparentcategory"></a>CMFCRibbonButtonsGroup::SetParentCategory

Define o `CMFCRibbonCategory` pai `CMFCRibbonButtonsGroup` do objeto e todos os botões dentro dele.

```
virtual void SetParentCategory(CMFCRibbonCategory* pCategory);
```

### <a name="parameters"></a>Parâmetros

*Pcategory*<br/>
[em] Ponteiro para a categoria pai para definir (os grupos com guias nos controles de fita são chamados categorias).

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
