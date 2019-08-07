---
title: Classe CMFCPropertyGridFileProperty
ms.date: 11/04/2016
f1_keywords:
- CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty
helpviewer_keywords:
- CMFCPropertyGridFileProperty [MFC], CMFCPropertyGridFileProperty
ms.assetid: 2bb8b8b4-47fc-4798-bd5e-dc8ea0b4cd9d
ms.openlocfilehash: 4b64d18a67ea499c202b81481684227200846483
ms.sourcegitcommit: c3bf94210bdb73be80527166264d49e33784152c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2019
ms.locfileid: "68821286"
---
# <a name="cmfcpropertygridfileproperty-class"></a>Classe CMFCPropertyGridFileProperty

A `CMFCPropertyGridFileProperty` classe oferece suporte a um item de controle de lista de propriedades que abre uma caixa de diálogo de seleção de arquivo.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridFileProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty](#cmfcpropertygridfileproperty)|Constrói um objeto `CMFCPropertyGridFileProperty`.|
|`CMFCPropertyGridFileProperty::~CMFCPropertyGridFileProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCPropertyGridFileProperty::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|`CMFCPropertyGridFileProperty::OnClickButton`|(Substitui [CMFCPropertyGridProperty:: OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|

### <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[CMFCPropertyGridFileProperty](../../mfc/reference/cmfcpropertygridfileproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxPropertyGridCtrl. h

##  <a name="cmfcpropertygridfileproperty"></a>CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty

Constrói um objeto `CMFCPropertyGridFileProperty`.

```
CMFCPropertyGridFileProperty(
    const CString& strName,
    BOOL bOpenFileDialog,
    const CString& strFileName,
    LPCTSTR lpszDefExt=NULL,
    DWORD dwFlags=OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
    LPCTSTR lpszFilter=NULL,
    LPCTSTR lpszDescr=NULL,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*strName*<br/>
no O nome da propriedade.

*bOpenFileDialog*<br/>
no TRUE para abrir uma caixa de diálogo **Abrir arquivo** ; FALSE para abrir uma caixa de diálogo **salvar arquivo** .

*strFileName*<br/>
no O nome de arquivo inicial.

*lpszDefExt*<br/>
no Uma cadeia de caracteres de uma ou mais extensões de nome de arquivo. O valor padrão é NULL.

*dwFlags*<br/>
no Sinalizadores da caixa de diálogo. O valor padrão é uma combinação de bits (ou) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.

*lpszFilter*<br/>
no Uma cadeia de caracteres de um ou mais filtros de arquivo. O valor padrão é NULL.

*lpszDescr*<br/>
no A descrição do item de propriedade. O valor padrão é NULL.

*dwData*<br/>
no Dados específicos do aplicativo que estão associados ao item de propriedade. Por exemplo, um inteiro de 32 bits ou um ponteiro para outros dados. O valor padrão é 0.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Para obter uma lista completa dos sinalizadores disponíveis, consulte [estrutura da OPENFILENAME](/windows/win32/api/commdlg/ns-commdlg-openfilenamew).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto usando o construtor da `CMFCPropertyGridFileProperty` classe. Este exemplo faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#22](../../mfc/codesnippet/cpp/cmfcpropertygridfileproperty-class_1.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
