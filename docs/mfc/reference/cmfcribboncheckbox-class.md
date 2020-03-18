---
title: Classe CMFCRibbonCheckBox
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonCheckBox
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::CMFCRibbonCheckBox
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::GetCompactSize
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::GetIntermediateSize
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::GetRegularSize
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::IsDrawTooltipImage
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::OnDraw
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::OnDrawMenuImage
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::OnDrawOnList
- AFXRIBBONCHECKBOX/CMFCRibbonCheckBox::SetACCData
helpviewer_keywords:
- CMFCRibbonCheckBox [MFC], CMFCRibbonCheckBox
- CMFCRibbonCheckBox [MFC], GetCompactSize
- CMFCRibbonCheckBox [MFC], GetIntermediateSize
- CMFCRibbonCheckBox [MFC], GetRegularSize
- CMFCRibbonCheckBox [MFC], IsDrawTooltipImage
- CMFCRibbonCheckBox [MFC], OnDraw
- CMFCRibbonCheckBox [MFC], OnDrawMenuImage
- CMFCRibbonCheckBox [MFC], OnDrawOnList
- CMFCRibbonCheckBox [MFC], SetACCData
ms.assetid: 3a6c3891-c8d1-4af0-b954-7b9ab048782a
ms.openlocfilehash: a8048f860a2cce75c37a065cfdd2751141054f1b
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446234"
---
# <a name="cmfcribboncheckbox-class"></a>Classe CMFCRibbonCheckBox

A classe `CMFCRibbonCheckBox` implementa uma caixa de seleção que você pode adicionar a um painel da faixa de, barra de ferramentas de acesso rápido ou menu pop-up.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCheckBox : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CMFCRibbonCheckBox::CMFCRibbonCheckBox](#cmfcribboncheckbox)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CMFCRibbonCheckBox::GetCompactSize](#getcompactsize)|(Substitui [CMFCRibbonButton:: GetCompactSize](../../mfc/reference/cmfcribbonbutton-class.md#getcompactsize).)|
|[CMFCRibbonCheckBox::GetIntermediateSize](#getintermediatesize)|(Substitui [CMFCRibbonButton:: GetIntermediateSize](../../mfc/reference/cmfcribbonbutton-class.md#getintermediatesize).)|
|[CMFCRibbonCheckBox::GetRegularSize](#getregularsize)|(Substitui [CMFCRibbonButton:: GetRegularSize](../../mfc/reference/cmfcribbonbutton-class.md#getregularsize).)|
|[CMFCRibbonCheckBox::IsDrawTooltipImage](#isdrawtooltipimage)|(Substitui `CMFCRibbonButton::IsDrawTooltipImage`.)|
|[CMFCRibbonCheckBox:: OnDraw](#ondraw)|(Substitui [CMFCRibbonButton:: OnDraw](../../mfc/reference/cmfcribbonbutton-class.md#ondraw).)|
|[CMFCRibbonCheckBox::OnDrawMenuImage](#ondrawmenuimage)|(Substitui [CMFCRibbonBaseElement:: OnDrawMenuImage](../../mfc/reference/cmfcribbonbaseelement-class.md#ondrawmenuimage).)|
|[CMFCRibbonCheckBox::OnDrawOnList](#ondrawonlist)|(Substitui `CMFCRibbonButton::OnDrawOnList`.)|
|[CMFCRibbonCheckBox::SetACCData](#setaccdata)|(Substitui [CMFCRibbonButton:: SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|

## <a name="remarks"></a>Comentários

Para usar um `CMFCRibbonCheckBox` em seu aplicativo, adicione o seguinte construtor ao seu código:

```
CMFCRibbonCheckBox (UINT nID, LPCTSTR lpszText)
```

em que *NID* é a ID de comando da caixa de seleção e *lpszText* é o rótulo de texto da caixa de seleção.

Você pode adicionar uma caixa de seleção a um painel da faixa de lista usando [CMFCRibbonPanel:: Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonCheckBox](../../mfc/reference/cmfcribboncheckbox-class.md)

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxribboncheckbox. h

##  <a name="cmfcribboncheckbox"></a>CMFCRibbonCheckBox::CMFCRibbonCheckBox

Construtor de um objeto caixa de seleção de faixa de faixas

```
CMFCRibbonCheckBox(
    UINT nID,
    LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
no Especifica a ID de comando.

*lpszText*<br/>
no Especifica o rótulo de texto.

### <a name="return-value"></a>Valor retornado

Constrói um objeto da caixa de seleção da faixa de faixas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra como construir um objeto da classe `CMFCRibbonCheckBox`.

[!code-cpp[NVC_MFC_RibbonApp#17](../../mfc/reference/codesnippet/cpp/cmfcribboncheckbox-class_1.cpp)]

##  <a name="getcompactsize"></a>CMFCRibbonCheckBox::GetCompactSize

Quando substituído, obtém o tamanho do Compact da caixa de seleção.

```
virtual CSize GetCompactSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para o CDC associado à caixa de seleção.

### <a name="return-value"></a>Valor retornado

Retorna um objeto `CSize` que contém o tamanho do Compact da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna o tamanho intermediário da caixa de seleção.

##  <a name="getintermediatesize"></a>CMFCRibbonCheckBox::GetIntermediateSize

Obtém o tamanho intermediário da caixa de seleção.

```
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para o CDC associado a essa caixa de seleção.

### <a name="return-value"></a>Valor retornado

Um objeto `CSize` que contém o tamanho intermediário da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, o calculará o tamanho intermediário como o tamanho da caixa de seleção padrão (`AFX_CHECK_BOX_DEFAULT_SIZE`) mais o tamanho do texto, além das margens.

##  <a name="getregularsize"></a>CMFCRibbonCheckBox::GetRegularSize

Obtém o tamanho regular da caixa de seleção.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para o objeto CDC associado a essa caixa de seleção.

### <a name="return-value"></a>Valor retornado

Retorna um objeto `CSize` que contém o tamanho regular da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna o tamanho intermediário da caixa de seleção.

##  <a name="isdrawtooltipimage"></a>CMFCRibbonCheckBox::IsDrawTooltipImage

Indica se há uma imagem de dica de ferramenta associada à caixa de seleção.

```
virtual BOOL IsDrawTooltipImage() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se houver uma imagem de dica de ferramenta associada à caixa de seleção ou FALSE se não.

### <a name="remarks"></a>Comentários

##  <a name="ondraw"></a>CMFCRibbonCheckBox:: OnDraw

Chamado pelo Framework para desenhar a caixa de seleção usando um contexto de dispositivo especificado.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para o CDC no qual desenhar a caixa de seleção.

### <a name="remarks"></a>Comentários

##  <a name="ondrawmenuimage"></a>CMFCRibbonCheckBox::OnDrawMenuImage

Chamado pelo Framework para desenhar uma imagem de menu para a caixa de seleção.

```
virtual BOOL OnDrawMenuImage(CDC*, CRect);
```

### <a name="parameters"></a>Parâmetros

no *CDC&#42;*<br/>
Ponteiro para o CDC associado à caixa de seleção.

*CRect*<br/>
no Um objeto `CRect` especificando o retângulo no qual desenhar a imagem do menu.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a imagem foi desenhada ou FALSE se não.

### <a name="remarks"></a>Comentários

Se não for substituído, retornará FALSE.

##  <a name="ondrawonlist"></a>CMFCRibbonCheckBox::OnDrawOnList

Chamado pelo Framework para desenhar a caixa de seleção em uma caixa de listagem de comandos.

```
virtual void OnDrawOnList(
    CDC* pDC,
    CString strText,
    int nTextOffset,
    CRect rect,
    BOOL bIsSelected,
    BOOL bHighlighted);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para o contexto do dispositivo no qual desenhar a caixa de seleção.

*strText*<br/>
no O texto de exibição.

*nTextOffset*<br/>
no A distância, em pixels, do lado esquerdo da caixa de listagem até o texto de exibição.

*Rect*<br/>
no O retângulo de exibição da caixa de seleção.

*bIsSelected*<br/>
no TRUE se a caixa de seleção estiver marcada ou FALSE se não.

*bHighlighted*<br/>
no TRUE se a caixa de seleção estiver realçada ou FALSE se não.

### <a name="remarks"></a>Comentários

##  <a name="setaccdata"></a>CMFCRibbonCheckBox::SetACCData

Define os dados de acessibilidade para a caixa de seleção.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
A janela pai da caixa de seleção.

*data*<br/>
Os dados de acessibilidade para a caixa de seleção.

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, esse método define os dados de acessibilidade para a caixa de seleção e sempre retorna TRUE. Substitua esse método para definir os dados de acessibilidade e retornar um valor que indique êxito ou falha.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)
