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
ms.openlocfilehash: 393a871a881aa4bddd786b1d4333e02d5e0dbef1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751834"
---
# <a name="cmfcpropertygridcolorproperty-class"></a>Classe CMFCPropertyGridColorProperty

A `CMFCPropertyGridColorProperty` classe suporta um item de controle de lista de propriedades que abre uma caixa de diálogo de seleção de cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridColorProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridColorPropriedade::CMFCPropertyGridColorProperty](#cmfcpropertygridcolorproperty)|Constrói um objeto `CMFCPropertyGridColorProperty`.|
|`CMFCPropertyGridColorProperty::~CMFCPropertyGridColorProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridColorProperty::Ativarbotão automático](#enableautomaticbutton)|Habilita o botão *automático* na caixa de diálogo de seleção de cores. (O botão automático padrão é rotulado **como Automático**.)|
|[CMFCPropertyGridColorProperty::EnableOtherButton](#enableotherbutton)|Habilita o *outro* botão na caixa de diálogo de seleção de cores. (O outro botão padrão é rotulado **como Mais Cores**.)|
|`CMFCPropertyGridColorProperty::FormatProperty`|Formata a representação de texto de um valor de propriedade. (Substitui [cmfcPropertyGridProperty::FormatProperty](../../mfc/reference/cmfcpropertygridproperty-class.md#formatproperty).)|
|[CMFCPropertyGridColorProperty::GetColor](#getcolor)|Fica com a cor atual da propriedade.|
|`CMFCPropertyGridColorProperty::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|`CMFCPropertyGridColorProperty::OnClickButton`|Chamado pela estrutura quando o usuário clica em um botão que está contido em uma propriedade. (Substitui [cmfcpropertygridpropriedade::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|
|`CMFCPropertyGridColorProperty::OnDrawValue`|Chamado pela estrutura para exibir o valor da propriedade. (Substitui [cmfcPropertyGridProperty::OnDrawValue](../../mfc/reference/cmfcpropertygridproperty-class.md#ondrawvalue).)|
|`CMFCPropertyGridColorProperty::OnEdit`|Chamado pela estrutura quando o usuário está prestes a modificar um valor de propriedade. (Substitui [cmfcPropertyGridProperty::OnEdit](../../mfc/reference/cmfcpropertygridproperty-class.md#onedit).)|
|`CMFCPropertyGridColorProperty::OnUpdateValue`|Chamado pelo framework quando o valor de uma propriedade editável foi alterado. (Substitui [cmfcpropertygridpropriedade:onUpdateValue](../../mfc/reference/cmfcpropertygridproperty-class.md#onupdatevalue).)|
|[CMFCPropertyGridColorProperty::setColor](#setcolor)|Define uma nova cor para a propriedade.|
|[CMFCPropertyGridColorProperty::SetColunasNúmero de colunas](#setcolumnsnumber)|Especifica o número de colunas na grade de propriedade de cor atual.|
|[CMFCPropertyGridColorProperty::SetOriginalValue](#setoriginalvalue)|Define o valor original de uma propriedade editável.|

## <a name="remarks"></a>Comentários

A `CMFCPropertyGridColorProperty` classe suporta uma propriedade de cor que pode ser adicionada a um controle de lista de propriedades. Para obter mais informações, consulte a [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCPropertyGridColorProperty` construir um objeto da classe e `CMFCPropertyGridColorProperty` configurar este objeto usando vários métodos da classe. O código explica como ativar os botões automáticos e outros, e como definir a cor e o número das colunas. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#13](../../mfc/reference/codesnippet/cpp/cmfcpropertygridcolorproperty-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcpropertygridproperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[Cmfcpropertygridcolorproperty](../../mfc/reference/cmfcpropertygridcolorproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridctrl.h

## <a name="cmfcpropertygridcolorpropertycmfcpropertygridcolorproperty"></a><a name="cmfcpropertygridcolorproperty"></a>CMFCPropertyGridColorPropriedade::CMFCPropertyGridColorProperty

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
[em] O nome da propriedade.

*cor*<br/>
[em] O valor de cor da propriedade.

*Ppalette*<br/>
[em] Ponteiro para uma paleta de cores. O valor padrão é NULL.

*lpszDescr*<br/>
[em] A descrição da propriedade. O valor padrão é NULL.

*Dwdata*<br/>
[em] Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados associados à propriedade. O valor padrão é 0.

## <a name="cmfcpropertygridcolorpropertyenableautomaticbutton"></a><a name="enableautomaticbutton"></a>CMFCPropertyGridColorProperty::Ativarbotão automático

Habilita o botão *automático* na caixa de diálogo de seleção de cores. (O botão automático padrão é rotulado **como Automático**.)

```cpp
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] O texto da etiqueta do botão automático.

*corAutomático*<br/>
[em] O valor de cor RGB da cor automática (padrão).

*Benable*<br/>
[em] TRUE para ativar o botão automático; caso contrário, FALSE. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

## <a name="cmfcpropertygridcolorpropertyenableotherbutton"></a><a name="enableotherbutton"></a>CMFCPropertyGridColorProperty::EnableOtherButton

Habilita o *outro* botão na caixa de diálogo de seleção de cores. (O outro botão padrão é rotulado **como Mais Cores**.)

```cpp
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg = TRUE,
    BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] O texto da etiqueta do outro botão.

*bAltColorDlg*<br/>
[em] TRUE para `CMFCColorDialog` exibir a caixa de diálogo; FALSE para exibir a caixa de diálogo de seleção de cores padrão. O valor padrão é TRUE.

*Benable*<br/>
[em] TRUE para exibir o outro botão; caso contrário, FALSE.  O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

## <a name="cmfcpropertygridcolorpropertygetcolor"></a><a name="getcolor"></a>CMFCPropertyGridColorProperty::GetColor

Fica com a cor atual da propriedade.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de cor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfcpropertygridcolorpropertysetcolor"></a><a name="setcolor"></a>CMFCPropertyGridColorProperty::setColor

Define uma nova cor para a propriedade.

```cpp
void SetColor(COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfcpropertygridcolorpropertysetcolumnsnumber"></a><a name="setcolumnsnumber"></a>CMFCPropertyGridColorProperty::SetColunasNúmero de colunas

Especifica o número de colunas na grade de propriedade de cor atual.

```cpp
void SetColumnsNumber(int nColumnsNumber);
```

### <a name="parameters"></a>Parâmetros

*nColumnsNumber*<br/>
[em] O número preferencial de colunas na grade de propriedade de cores.

### <a name="remarks"></a>Comentários

Este método define o `m_nColumnsNumber` valor do membro de dados protegido.

## <a name="cmfcpropertygridcolorpropertysetoriginalvalue"></a><a name="setoriginalvalue"></a>CMFCPropertyGridColorProperty::setOriginalValue

Define o valor original de uma propriedade editável.

```
virtual void SetOriginalValue(const COleVariant& varValue);
```

### <a name="parameters"></a>Parâmetros

*varValue*<br/>
[em] Um valor.

### <a name="remarks"></a>Comentários

Use o [método CMFCPropertyGridProperty::ResetOriginalValue](../../mfc/reference/cmfcpropertygridproperty-class.md#resetoriginalvalue) para redefinir o valor original de uma propriedade editada.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
