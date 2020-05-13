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
ms.openlocfilehash: 089c8056afebef31ff98a435bf145566ae64fe1e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375252"
---
# <a name="cmfcribboncheckbox-class"></a>Classe CMFCRibbonCheckBox

A `CMFCRibbonCheckBox` classe implementa uma caixa de seleção que você pode adicionar a um painel de fita, barra de ferramentas de acesso rápido ou menu popup.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCheckBox : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonCheckBox::CMFCRibbonCheckBox](#cmfcribboncheckbox)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonCheckBox::GetCompactSize](#getcompactsize)|(Substitui [cmfcribbonbutton::GetCompactSize](../../mfc/reference/cmfcribbonbutton-class.md#getcompactsize).)|
|[CMFCRibbonCheckbox::GetIntermediateSize](#getintermediatesize)|(Substitui [cmfcribbonbutton::GetIntermediateSize](../../mfc/reference/cmfcribbonbutton-class.md#getintermediatesize).)|
|[CMFCRibbonCheckbox::getRegularsize](#getregularsize)|(Substitui [cmfcribbonbutton::GetRegularSize](../../mfc/reference/cmfcribbonbutton-class.md#getregularsize).)|
|[CMFCRibbonCheckBox::IsDrawtooltipImage](#isdrawtooltipimage)|(Substitui `CMFCRibbonButton::IsDrawTooltipImage`.)|
|[CMFCRibbonCheckbox::OnDraw](#ondraw)|(Substitui [cmfcribbonbutton::OnDraw](../../mfc/reference/cmfcribbonbutton-class.md#ondraw).)|
|[CMFCRibbonCheckBox::OnDrawMenuImage](#ondrawmenuimage)|(Substitui [cmfcribbonbaseelement::OnDrawMenuImage](../../mfc/reference/cmfcribbonbaseelement-class.md#ondrawmenuimage).)|
|[CMFCRibbonCheckbox::Ondrawonlist](#ondrawonlist)|(Substitui `CMFCRibbonButton::OnDrawOnList`.)|
|[CMFCRibbonCheckBox::setACCData](#setaccdata)|(Substitui [cmfcribbonbutton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|

## <a name="remarks"></a>Comentários

Para usar `CMFCRibbonCheckBox` um em seu aplicativo, adicione o seguinte construtor ao seu código:

```
CMFCRibbonCheckBox (UINT nID, LPCTSTR lpszText)
```

onde *nID* é o iD de comando caixa de seleção e *lpszText* é a etiqueta de texto da caixa de seleção.

Você pode adicionar uma caixa de seleção a um painel de fita usando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonCheckBox](../../mfc/reference/cmfcribboncheckbox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncheckbox.h

## <a name="cmfcribboncheckboxcmfcribboncheckbox"></a><a name="cmfcribboncheckbox"></a>CMFCRibbonCheckBox::CMFCRibbonCheckBox

Construtor de um objeto de caixa de seleção de fita

```
CMFCRibbonCheckBox(
    UINT nID,
    LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] Especifica o ID de comando.

*lpszText*<br/>
[em] Especifica o rótulo de texto.

### <a name="return-value"></a>Valor retornado

Constrói um objeto de caixa de seleção de fita.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonCheckBox` construir um objeto da classe.

[!code-cpp[NVC_MFC_RibbonApp#17](../../mfc/reference/codesnippet/cpp/cmfcribboncheckbox-class_1.cpp)]

## <a name="cmfcribboncheckboxgetcompactsize"></a><a name="getcompactsize"></a>CMFCRibbonCheckBox::GetCompactSize

Quando substituído, obtém o tamanho compacto da caixa de seleção.

```
virtual CSize GetCompactSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o CDC associado com a caixa de seleção.

### <a name="return-value"></a>Valor retornado

Retorna `CSize` um objeto que contém o tamanho compacto da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna o tamanho intermediário da caixa de seleção.

## <a name="cmfcribboncheckboxgetintermediatesize"></a><a name="getintermediatesize"></a>CMFCRibbonCheckbox::GetIntermediateSize

Obtém o tamanho intermediário da caixa de seleção.

```
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o CDC associado a esta caixa de seleção.

### <a name="return-value"></a>Valor retornado

Um `CSize` objeto contendo o tamanho intermediário da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, calcula o tamanho intermediário `AFX_CHECK_BOX_DEFAULT_SIZE`como o tamanho da caixa de seleção padrão ( ) mais o tamanho do texto, mais as margens.

## <a name="cmfcribboncheckboxgetregularsize"></a><a name="getregularsize"></a>CMFCRibbonCheckbox::getRegularsize

Obtém o tamanho normal da caixa de seleção.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o objeto CDC associado a esta caixa de seleção.

### <a name="return-value"></a>Valor retornado

Retorna `CSize` um objeto que contém o tamanho regular da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna o tamanho intermediário da caixa de seleção.

## <a name="cmfcribboncheckboxisdrawtooltipimage"></a><a name="isdrawtooltipimage"></a>CMFCRibbonCheckBox::IsDrawtooltipImage

Indica se há uma imagem de dica de ferramenta associada à caixa de seleção.

```
virtual BOOL IsDrawTooltipImage() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se houver uma imagem de dica de ferramenta associada à caixa de seleção, ou FALSA se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncheckboxondraw"></a><a name="ondraw"></a>CMFCRibbonCheckbox::OnDraw

Chamado pela estrutura para desenhar a caixa de seleção usando um contexto de dispositivo especificado.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para o CDC para desenhar a caixa de seleção.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncheckboxondrawmenuimage"></a><a name="ondrawmenuimage"></a>CMFCRibbonCheckBox::OnDrawMenuImage

Chamado pelo framework para desenhar uma imagem do menu para a caixa de seleção.

```
virtual BOOL OnDrawMenuImage(CDC*, CRect);
```

### <a name="parameters"></a>Parâmetros

[em] *CDC&#42;*<br/>
Ponteiro para o CDC associado com a caixa de seleção.

*Crect*<br/>
[em] Um `CRect` objeto especificando o retângulo no qual desenhar a imagem do menu.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a imagem foi desenhada, ou FALSA se não.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna FALSO.

## <a name="cmfcribboncheckboxondrawonlist"></a><a name="ondrawonlist"></a>CMFCRibbonCheckbox::Ondrawonlist

Chamado pela estrutura para desenhar a caixa de seleção em uma caixa de lista de comandos.

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
[em] Ponteiro para o contexto do dispositivo para desenhar a caixa de seleção.

*strText*<br/>
[em] O texto de exibição.

*nTextOffset*<br/>
[em] A distância, em pixels, do lado esquerdo da caixa de lista para o texto de exibição.

*Rect*<br/>
[em] O retângulo do visor para a caixa de seleção.

*bIsSelected*<br/>
[em] TRUE se a caixa de seleção for selecionada ou FALSA se não for.

*bHighlighted*<br/>
[em] TRUE se a caixa de seleção for destacada, ou FALSA se não.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncheckboxsetaccdata"></a><a name="setaccdata"></a>CMFCRibbonCheckBox::setACCData

Define os dados de acessibilidade para a caixa de seleção.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
A janela dos pais da caixa de seleção.

*dados*<br/>
Os dados de acessibilidade da caixa de seleção.

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, este método define os dados de acessibilidade para a caixa de seleção e sempre retorna TRUE. Substituir este método para definir os dados de acessibilidade e retornar um valor que indique sucesso ou falha.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)
