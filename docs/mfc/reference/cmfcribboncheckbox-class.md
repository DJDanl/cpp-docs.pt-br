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
ms.openlocfilehash: 067f38522c1be112d6e12200c2c10e1d439e5057
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612414"
---
# <a name="cmfcribboncheckbox-class"></a>Classe CMFCRibbonCheckBox

O `CMFCRibbonCheckBox` classe implementa uma caixa de seleção que você pode adicionar a um menu pop-up, ferramentas de acesso rápido ou painel de faixa de opções.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCheckBox : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonCheckBox::CMFCRibbonCheckBox](#cmfcribboncheckbox)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonCheckBox::GetCompactSize](#getcompactsize)|(Substitui [CMFCRibbonButton::GetCompactSize](../../mfc/reference/cmfcribbonbutton-class.md#getcompactsize).)|
|[CMFCRibbonCheckBox::GetIntermediateSize](#getintermediatesize)|(Substitui [CMFCRibbonButton::GetIntermediateSize](../../mfc/reference/cmfcribbonbutton-class.md#getintermediatesize).)|
|[CMFCRibbonCheckBox::GetRegularSize](#getregularsize)|(Substitui [CMFCRibbonButton::GetRegularSize](../../mfc/reference/cmfcribbonbutton-class.md#getregularsize).)|
|[CMFCRibbonCheckBox::IsDrawTooltipImage](#isdrawtooltipimage)|(Substitui `CMFCRibbonButton::IsDrawTooltipImage`.)|
|[CMFCRibbonCheckBox::OnDraw](#ondraw)|(Substitui [CMFCRibbonButton::OnDraw](../../mfc/reference/cmfcribbonbutton-class.md#ondraw).)|
|[CMFCRibbonCheckBox::OnDrawMenuImage](#ondrawmenuimage)|(Substitui [CMFCRibbonBaseElement::OnDrawMenuImage](../../mfc/reference/cmfcribbonbaseelement-class.md#ondrawmenuimage).)|
|[CMFCRibbonCheckBox::OnDrawOnList](#ondrawonlist)|(Substitui `CMFCRibbonButton::OnDrawOnList`.)|
|[CMFCRibbonCheckBox::SetACCData](#setaccdata)|(Substitui [CMFCRibbonButton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|

## <a name="remarks"></a>Comentários

Para usar um `CMFCRibbonCheckBox` em seu aplicativo, adicione o seguinte construtor ao seu código:

```
CMFCRibbonCheckBox (UINT nID, LPCTSTR lpszText)
```
em que *nID* é a ID de comando de caixa de seleção e *lpszText* é o rótulo de texto da caixa de seleção.

Você pode adicionar uma caixa de seleção a um painel de faixa de opções usando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonCheckBox](../../mfc/reference/cmfcribboncheckbox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncheckbox.h

##  <a name="cmfcribboncheckbox"></a>  CMFCRibbonCheckBox::CMFCRibbonCheckBox

Construtor de um objeto de caixa de seleção de faixa de opções

```
CMFCRibbonCheckBox(
    UINT nID,
    LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[in] Especifica a ID de comando.

*lpszText*<br/>
[in] Especifica o rótulo de texto.

### <a name="return-value"></a>Valor de retorno

Constrói um objeto de caixa de seleção de faixa de opções.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCRibbonCheckBox` classe.

[!code-cpp[NVC_MFC_RibbonApp#17](../../mfc/reference/codesnippet/cpp/cmfcribboncheckbox-class_1.cpp)]

##  <a name="getcompactsize"></a>  CMFCRibbonCheckBox::GetCompactSize

Quando substituído, obtém o tamanho compacto da caixa de seleção.

```
virtual CSize GetCompactSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para o CDC associado com a caixa de seleção.

### <a name="return-value"></a>Valor de retorno

Retorna um `CSize` objeto que contém o tamanho compacto da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna o tamanho intermediário da caixa de seleção.

##  <a name="getintermediatesize"></a>  CMFCRibbonCheckBox::GetIntermediateSize

Obtém o tamanho intermediário da caixa de seleção.

```
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para o CDC associado com esta caixa de seleção.

### <a name="return-value"></a>Valor de retorno

Um `CSize` objeto que contém o tamanho intermediário da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, calcula o tamanho intermediário como o tamanho da caixa de seleção padrão ( `AFX_CHECK_BOX_DEFAULT_SIZE`) mais o tamanho do texto, além de margens.

##  <a name="getregularsize"></a>  CMFCRibbonCheckBox::GetRegularSize

Obtém o tamanho regular da caixa de seleção.

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para o objeto de CDC associado com esta caixa de seleção.

### <a name="return-value"></a>Valor de retorno

Retorna um `CSize` objeto que contém o tamanho regular da caixa de seleção.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna o tamanho intermediário da caixa de seleção.

##  <a name="isdrawtooltipimage"></a>  CMFCRibbonCheckBox::IsDrawTooltipImage

Indica se há uma imagem de dica de ferramenta associada com a caixa de seleção.

```
virtual BOOL IsDrawTooltipImage() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se houver uma imagem de dica de ferramenta associada com a caixa de seleção, ou FALSE se não.

### <a name="remarks"></a>Comentários

##  <a name="ondraw"></a>  CMFCRibbonCheckBox::OnDraw

Chamado pelo framework para desenhar a caixa de seleção usando um contexto de dispositivo especificado.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para o CDC no qual desenhar a caixa de seleção.

### <a name="remarks"></a>Comentários

##  <a name="ondrawmenuimage"></a>  CMFCRibbonCheckBox::OnDrawMenuImage

Chamado pelo framework para desenhar uma imagem do menu da caixa de seleção.

```
virtual BOOL OnDrawMenuImage(CDC*, CRect);
```

### <a name="parameters"></a>Parâmetros

[in] *CDC&#42;*<br/>
Ponteiro para o CDC associado com a caixa de seleção.

*CRect*<br/>
[in] Um `CRect` objeto que especifica o retângulo no qual desenhar a imagem do menu.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se a imagem foi desenhada, ou falso se não.

### <a name="remarks"></a>Comentários

Se não for substituído, retorna FALSE.

##  <a name="ondrawonlist"></a>  CMFCRibbonCheckBox::OnDrawOnList

Chamado pelo framework para desenhar a caixa de seleção em uma caixa de listagem de comandos.

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
[in] Ponteiro para o contexto de dispositivo no qual desenhar a caixa de seleção.

*strText*<br/>
[in] O texto de exibição.

*nTextOffset*<br/>
[in] A distância, em pixels, do lado esquerdo da caixa de listagem para o texto de exibição.

*Rect*<br/>
[in] O retângulo de exibição da caixa de seleção.

*bIsSelected*<br/>
[in] TRUE se a caixa de seleção for marcada, ou FALSE se não.

*bHighlighted*<br/>
[in] TRUE se a caixa de seleção estiver realçada, ou FALSE se não for.

### <a name="remarks"></a>Comentários

##  <a name="setaccdata"></a>  CMFCRibbonCheckBox::SetACCData

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

### <a name="return-value"></a>Valor de retorno

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, esse método define os dados de acessibilidade para a caixa de seleção e sempre retorna TRUE. Substitua este método para definir os dados de acessibilidade e retornar um valor que indica êxito ou falha.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)
