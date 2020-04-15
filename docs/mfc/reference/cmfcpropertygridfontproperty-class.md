---
title: Classe CMFCPropertyGridFontProperty
ms.date: 11/04/2016
f1_keywords:
- CMFCPropertyGridFontProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty::GetColor
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFontProperty::GetLogFont
helpviewer_keywords:
- CMFCPropertyGridFontProperty [MFC], CMFCPropertyGridFontProperty
- CMFCPropertyGridFontProperty [MFC], GetColor
- CMFCPropertyGridFontProperty [MFC], GetLogFont
ms.assetid: 83693f33-bbd3-4fcb-a9ad-fa79fcf2ca24
ms.openlocfilehash: a1c9905d8d7f32a049496c4e164c9eaac13455d6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361844"
---
# <a name="cmfcpropertygridfontproperty-class"></a>Classe CMFCPropertyGridFontProperty

A `CMFCPropertyGridFileProperty` classe suporta um item de controle de lista de propriedades que abre uma caixa de diálogo de seleção de fontes.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridFontProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridFontPropriedade::CMFCPropertyGridFontProperty](#cmfcpropertygridfontproperty)|Constrói um objeto `CMFCPropertyGridFontProperty`.|
|`CMFCPropertyGridFontProperty::~CMFCPropertyGridFontProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCPropertyGridFontProperty::FormatProperty`|Formata a representação de texto de um valor de propriedade. (Substitui [cmfcPropertyGridProperty::FormatProperty](../../mfc/reference/cmfcpropertygridproperty-class.md#formatproperty).)|
|[CMFCPropertygridFontPropriedade::getColor](#getcolor)|Recupera a cor da fonte que o usuário seleciona na caixa de diálogo da fonte.|
|[CMFCPropertyGridFontPropriedade::getlogfont](#getlogfont)|Recupera a fonte que o usuário seleciona na caixa de diálogo da fonte.|
|`CMFCPropertyGridFontProperty::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|`CMFCPropertyGridFontProperty::OnClickButton`|Chamado pela estrutura quando o usuário clica em um botão que está contido em uma propriedade. (Substitui [cmfcpropertygridpropriedade::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcpropertygridproperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[CMFCPropertyGridFontProperty](../../mfc/reference/cmfcpropertygridfontproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridctrl.h

## <a name="cmfcpropertygridfontpropertycmfcpropertygridfontproperty"></a><a name="cmfcpropertygridfontproperty"></a>CMFCPropertyGridFontPropriedade::CMFCPropertyGridFontProperty

Constrói um objeto `CMFCPropertyGridFontProperty`.

```
CMFCPropertyGridFontProperty(
    const CString& strName,
    LOGFONT& lf,
    DWORD dwFontDialogFlags = CF_EFFECTS | CF_SCREENFONTS,
    LPCTSTR lpszDescr = NULL,
    DWORD_PTR dwData = 0,
    COLORREF color = (COLORREF)-1);
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
[em] O nome da propriedade.

*Se*<br/>
[em] Uma estrutura de fonte lógica que especifica os atributos da fonte.

*dwFontDialogFlags*<br/>
[em] Estilos aplicados à caixa de diálogo de fonte exibida quando você clica no botão suspenso valor da propriedade. O valor padrão é a combinação bitwise (OR) de CF_EFFECTS e CF_SCREENFONTS. Para obter mais informações, consulte o parâmetro *Sinalizadores* da [Estrutura CHOOSEFONT](/windows/win32/api/commdlg/ns-commdlg-choosefontw).

*lpszDescr*<br/>
[em] Descrição da propriedade da fonte. O valor padrão é NULL.

*Dwdata*<br/>
[em] Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados associados à propriedade. O valor padrão é 0.

*cor*<br/>
[em] A cor da fonte. O valor padrão é a cor padrão.

### <a name="remarks"></a>Comentários

Um `CMFCPropertyGridFontProperty` objeto representa uma propriedade de fonte em um controle de fonte de grade de propriedade.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra `CMFCPropertyGridFontProperty` como construir um objeto da classe. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#26](../../mfc/reference/codesnippet/cpp/cmfcpropertygridfontproperty-class_1.cpp)]

## <a name="cmfcpropertygridfontpropertygetcolor"></a><a name="getcolor"></a>CMFCPropertygridFontPropriedade::getColor

Recupera a cor da fonte que o usuário seleciona na caixa de diálogo da fonte.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de cor RGB que representa a cor da fonte selecionada.

### <a name="remarks"></a>Comentários

## <a name="cmfcpropertygridfontpropertygetlogfont"></a><a name="getlogfont"></a>CMFCPropertyGridFontPropriedade::getlogfont

Recupera a fonte que o usuário seleciona na caixa de diálogo da fonte.

```
LPLOGFONT GetLogFont();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) que descreve a fonte selecionada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
