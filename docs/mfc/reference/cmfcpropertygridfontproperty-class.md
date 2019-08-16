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
ms.openlocfilehash: a3c5b806482a97d64a9ffab92877781cb8778b6b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505117"
---
# <a name="cmfcpropertygridfontproperty-class"></a>Classe CMFCPropertyGridFontProperty

A `CMFCPropertyGridFileProperty` classe oferece suporte a um item de controle de lista de propriedades que abre uma caixa de diálogo de seleção de fonte.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridFontProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty](#cmfcpropertygridfontproperty)|Constrói um objeto `CMFCPropertyGridFontProperty`.|
|`CMFCPropertyGridFontProperty::~CMFCPropertyGridFontProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCPropertyGridFontProperty::FormatProperty`|Formata a representação de texto de um valor de propriedade. (Substitui [CMFCPropertyGridProperty:: FormatProperty](../../mfc/reference/cmfcpropertygridproperty-class.md#formatproperty).)|
|[CMFCPropertyGridFontProperty::GetColor](#getcolor)|Recupera a cor da fonte que o usuário seleciona na caixa de diálogo fonte.|
|[CMFCPropertyGridFontProperty::GetLogFont](#getlogfont)|Recupera a fonte que o usuário seleciona na caixa de diálogo fonte.|
|`CMFCPropertyGridFontProperty::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|`CMFCPropertyGridFontProperty::OnClickButton`|Chamado pelo Framework quando o usuário clica em um botão que está contido em uma propriedade. (Substitui [CMFCPropertyGridProperty:: OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[CMFCPropertyGridFontProperty](../../mfc/reference/cmfcpropertygridfontproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxPropertyGridCtrl. h

##  <a name="cmfcpropertygridfontproperty"></a>CMFCPropertyGridFontProperty::CMFCPropertyGridFontProperty

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
no O nome da propriedade.

*lf*<br/>
no Uma estrutura de fontes lógica que especifica os atributos da fonte.

*dwFontDialogFlags*<br/>
no Estilos que são aplicados à caixa de diálogo fonte que é exibida quando você clica no botão suspenso valor da propriedade. O valor padrão é a combinação de bits (ou) de CF_EFFECTS e CF_SCREENFONTS. Para obter mais informações, consulte o parâmetro *flags* da [estrutura CHOOSEFONT](/windows/win32/api/commdlg/ns-commdlg-choosefontw).

*lpszDescr*<br/>
no Descrição da propriedade Font. O valor padrão é NULL.

*dwData*<br/>
no Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados associados à propriedade. O valor padrão é 0.

*color*<br/>
no A cor da fonte. O valor padrão é a cor padrão.

### <a name="remarks"></a>Comentários

Um `CMFCPropertyGridFontProperty` objeto representa uma propriedade Font em um controle Font da grade de propriedades.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCPropertyGridFontProperty` classe. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#26](../../mfc/reference/codesnippet/cpp/cmfcpropertygridfontproperty-class_1.cpp)]

##  <a name="getcolor"></a>CMFCPropertyGridFontProperty:: GetColor

Recupera a cor da fonte que o usuário seleciona na caixa de diálogo fonte.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de cor RGB que representa a cor da fonte selecionada.

### <a name="remarks"></a>Comentários

##  <a name="getlogfont"></a>  CMFCPropertyGridFontProperty::GetLogFont

Recupera a fonte que o usuário seleciona na caixa de diálogo fonte.

```
LPLOGFONT GetLogFont();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) que descreve a fonte selecionada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
