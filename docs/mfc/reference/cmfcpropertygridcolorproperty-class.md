---
title: Classe CMFCPropertyGridColorProperty
ms.date: 11/04/2016
f1_keywords:
- CMFCPropertyGridColorProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::CMFCPropertyGridColorProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::EnableAutomaticButton
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::EnableOtherButton
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::GetColor
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::SetColor
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::SetColumnsNumber
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridColorProperty::SetOriginalValue
helpviewer_keywords:
- CMFCPropertyGridColorProperty [MFC], CMFCPropertyGridColorProperty
- CMFCPropertyGridColorProperty [MFC], EnableAutomaticButton
- CMFCPropertyGridColorProperty [MFC], EnableOtherButton
- CMFCPropertyGridColorProperty [MFC], GetColor
- CMFCPropertyGridColorProperty [MFC], SetColor
- CMFCPropertyGridColorProperty [MFC], SetColumnsNumber
- CMFCPropertyGridColorProperty [MFC], SetOriginalValue
ms.assetid: af37be93-a91e-40a2-9a65-0f3412c6f0f8
ms.openlocfilehash: 65c2c22c93dc3acb50fc4627c3710a3f0c86aeb0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57303957"
---
# <a name="cmfcpropertygridcolorproperty-class"></a>Classe CMFCPropertyGridColorProperty

O `CMFCPropertyGridColorProperty` classe dá suporte a um item de controle de lista de propriedade que abre uma caixa de diálogo de seleção de cor.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridColorProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridColorProperty::CMFCPropertyGridColorProperty](#cmfcpropertygridcolorproperty)|Constrói um objeto `CMFCPropertyGridColorProperty`.|
|`CMFCPropertyGridColorProperty::~CMFCPropertyGridColorProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridColorProperty::EnableAutomaticButton](#enableautomaticbutton)|Permite que o *automática* botão na caixa de diálogo de seleção de cor. (O botão automático padrão é rotulado **automática**.)|
|[CMFCPropertyGridColorProperty::EnableOtherButton](#enableotherbutton)|Permite que o *outros* botão na caixa de diálogo de seleção de cor. (O padrão de outro botão é rotulado **mais cores**.)|
|`CMFCPropertyGridColorProperty::FormatProperty`|Formata a representação de texto de um valor de propriedade. (Substitui [CMFCPropertyGridProperty::FormatProperty](../../mfc/reference/cmfcpropertygridproperty-class.md#formatproperty).)|
|[CMFCPropertyGridColorProperty::GetColor](#getcolor)|Obtém a cor atual da propriedade.|
|`CMFCPropertyGridColorProperty::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|`CMFCPropertyGridColorProperty::OnClickButton`|Chamado pelo framework quando o usuário clica em um botão que está contido em uma propriedade. (Substitui [CMFCPropertyGridProperty::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|
|`CMFCPropertyGridColorProperty::OnDrawValue`|Chamado pelo framework para exibir o valor da propriedade. (Substitui [CMFCPropertyGridProperty::OnDrawValue](../../mfc/reference/cmfcpropertygridproperty-class.md#ondrawvalue).)|
|`CMFCPropertyGridColorProperty::OnEdit`|Chamado pelo framework quando o usuário está prestes a modificar um valor da propriedade. (Substitui [CMFCPropertyGridProperty::OnEdit](../../mfc/reference/cmfcpropertygridproperty-class.md#onedit).)|
|`CMFCPropertyGridColorProperty::OnUpdateValue`|Chamado pelo framework quando o valor de uma propriedade editável foi alterado. (Substitui [CMFCPropertyGridProperty::OnUpdateValue](../../mfc/reference/cmfcpropertygridproperty-class.md#onupdatevalue).)|
|[CMFCPropertyGridColorProperty::SetColor](#setcolor)|Define uma nova cor para a propriedade.|
|[CMFCPropertyGridColorProperty::SetColumnsNumber](#setcolumnsnumber)|Especifica o número de colunas na grade de propriedade de cor atual.|
|[CMFCPropertyGridColorProperty::SetOriginalValue](#setoriginalvalue)|Define o valor original de uma propriedade editável.|

## <a name="remarks"></a>Comentários

O `CMFCPropertyGridColorProperty` classe dá suporte a uma propriedade de cor que pode ser adicionada a um controle de lista de propriedade. Para obter mais informações, consulte o [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCPropertyGridColorProperty` de classe e configurar esse objeto usando vários métodos para o `CMFCPropertyGridColorProperty` classe. O código explica como habilitar os botões automático e outros e como definir a cor e o número de colunas. Este exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#13](../../mfc/reference/codesnippet/cpp/cmfcpropertygridcolorproperty-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[CMFCPropertyGridColorProperty](../../mfc/reference/cmfcpropertygridcolorproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridctrl.h

##  <a name="cmfcpropertygridcolorproperty"></a>  CMFCPropertyGridColorProperty::CMFCPropertyGridColorProperty

Constrói um objeto `CMFCPropertyGridColorProperty`.

```
CMFCPropertyGridColorProperty(
    const CString& strName,
    const COLORREF& color,
    CPalette* pPalette = NULL,
    LPCTSTR lpszDescr = NULL,
    DWORD_PTR dwData = 0);
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
[in] O nome da propriedade.

*color*<br/>
[in] O valor da propriedade de cor.

*pPalette*<br/>
[in] Ponteiro para uma paleta de cores. O valor padrão é NULL.

*lpszDescr*<br/>
[in] A descrição da propriedade. O valor padrão é NULL.

*dwData*<br/>
[in] Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados que está associados com a propriedade. O valor padrão é 0.

##  <a name="enableautomaticbutton"></a>  CMFCPropertyGridColorProperty::EnableAutomaticButton

Permite que o *automática* botão na caixa de diálogo de seleção de cor. (O botão automático padrão é rotulado **automática**.)

```
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[in] O texto do rótulo do botão automático.

*colorAutomatic*<br/>
[in] O valor de cor RGB da cor automático (padrão).

*bEnable*<br/>
[in] TRUE para habilitar o botão automático; Caso contrário, FALSE. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

##  <a name="enableotherbutton"></a>  CMFCPropertyGridColorProperty::EnableOtherButton

Permite que o *outros* botão na caixa de diálogo de seleção de cor. (O padrão de outro botão é rotulado **mais cores**.)

```
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg = TRUE,
    BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[in] O texto do rótulo do botão outro.

*bAltColorDlg*<br/>
[in] True para exibir o `CMFCColorDialog` caixa de diálogo. FALSE para exibir a caixa de diálogo de seleção de cores padrão. O valor padrão é TRUE.

*bEnable*<br/>
[in] TRUE para exibir o botão; Caso contrário, FALSE.  O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

##  <a name="getcolor"></a>  CMFCPropertyGridColorProperty::GetColor

Obtém a cor atual da propriedade.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setcolor"></a>  CMFCPropertyGridColorProperty::SetColor

Define uma nova cor para a propriedade.

```
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
[in] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setcolumnsnumber"></a>  CMFCPropertyGridColorProperty::SetColumnsNumber

Especifica o número de colunas na grade de propriedade de cor atual.

```
void SetColumnsNumber(int nColumnsNumber);
```

### <a name="parameters"></a>Parâmetros

*nColumnsNumber*<br/>
[in] O número preferido de colunas na grade de propriedade de cor.

### <a name="remarks"></a>Comentários

Esse método define o valor da `m_nColumnsNumber` protegido membro de dados.

##  <a name="setoriginalvalue"></a>  CMFCPropertyGridColorProperty::SetOriginalValue

Define o valor original de uma propriedade editável.

```
virtual void SetOriginalValue(const COleVariant& varValue);
```

### <a name="parameters"></a>Parâmetros

*varValue*<br/>
[in] Um valor.

### <a name="remarks"></a>Comentários

Use o [CMFCPropertyGridProperty::ResetOriginalValue](../../mfc/reference/cmfcpropertygridproperty-class.md#resetoriginalvalue) método para redefinir o valor original de uma propriedade editada.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
