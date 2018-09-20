---
title: Classe CMFCPropertyGridFileProperty | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty
dev_langs:
- C++
helpviewer_keywords:
- CMFCPropertyGridFileProperty [MFC], CMFCPropertyGridFileProperty
ms.assetid: 2bb8b8b4-47fc-4798-bd5e-dc8ea0b4cd9d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fc80d2a40ee9381ad982cd548dddc0702ce7bdad
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390117"
---
# <a name="cmfcpropertygridfileproperty-class"></a>Classe CMFCPropertyGridFileProperty

O `CMFCPropertyGridFileProperty` classe dá suporte a um item de controle de lista de propriedade que abre uma caixa de diálogo de seleção de arquivo.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridFileProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty](#cmfcpropertygridfileproperty)|Constrói um objeto `CMFCPropertyGridFileProperty`.|
|`CMFCPropertyGridFileProperty::~CMFCPropertyGridFileProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCPropertyGridFileProperty::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|`CMFCPropertyGridFileProperty::OnClickButton`|(Substitui [CMFCPropertyGridProperty::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|

### <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[CMFCPropertyGridFileProperty](../../mfc/reference/cmfcpropertygridfileproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridctrl.h

##  <a name="cmfcpropertygridfileproperty"></a>  CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty

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
[in] O nome da propriedade.

*bOpenFileDialog*<br/>
[in] True para abrir um **abrir arquivo** caixa de diálogo. FALSE para abrir um **salvar arquivo** caixa de diálogo.

*strFileName*<br/>
[in] O nome do arquivo inicial.

*lpszDefExt*<br/>
[in] Uma cadeia de caracteres de um ou mais extensões de nome de arquivo. O valor padrão é NULL.

*dwFlags*<br/>
[in] Sinalizadores de caixa de diálogo. O valor padrão é uma combinação bit a bit (OR) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.

*lpszFilter*<br/>
[in] Uma cadeia de caracteres de um ou mais filtros de arquivo. O valor padrão é NULL.

*lpszDescr*<br/>
[in] A descrição do item de propriedade. O valor padrão é NULL.

*dwData*<br/>
[in] Dados específicos do aplicativo que está associados com o item de propriedade. Por exemplo, um inteiro de 32 bits ou um ponteiro para outros dados. O valor padrão é 0.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Para obter uma lista completa dos sinalizadores disponíveis, consulte [estrutura OPENFILENAME](/windows/desktop/api/commdlg/ns-commdlg-tagofna).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto usando o construtor do `CMFCPropertyGridFileProperty` classe. Este exemplo faz parte do [amostra de demonstração do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#22](../../mfc/codesnippet/cpp/cmfcpropertygridfileproperty-class_1.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
