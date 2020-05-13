---
title: CMFCPropertyGridFilePropertyPropertyProperty
ms.date: 11/04/2016
f1_keywords:
- CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty
helpviewer_keywords:
- CMFCPropertyGridFileProperty [MFC], CMFCPropertyGridFileProperty
ms.assetid: 2bb8b8b4-47fc-4798-bd5e-dc8ea0b4cd9d
ms.openlocfilehash: 0ce3321968f0c29ce3b946f6127e4435b531c422
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360576"
---
# <a name="cmfcpropertygridfileproperty-class"></a>CMFCPropertyGridFilePropertyPropertyProperty

A `CMFCPropertyGridFileProperty` classe suporta um item de controle de lista de propriedades que abre uma caixa de diálogo de seleção de arquivos.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridFileProperty : public CMFCPropertyGridProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyGridFilePropriedade::CMFCPropertyGridFileProperty](#cmfcpropertygridfileproperty)|Constrói um objeto `CMFCPropertyGridFileProperty`.|
|`CMFCPropertyGridFileProperty::~CMFCPropertyGridFileProperty`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCPropertyGridFileProperty::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|`CMFCPropertyGridFileProperty::OnClickButton`|(Substitui [cmfcpropertygridpropriedade::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|

### <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcpropertygridproperty](../../mfc/reference/cmfcpropertygridproperty-class.md)

[CMFCPropertyGridFileProperty](../../mfc/reference/cmfcpropertygridfileproperty-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridctrl.h

## <a name="cmfcpropertygridfilepropertycmfcpropertygridfileproperty"></a><a name="cmfcpropertygridfileproperty"></a>CMFCPropertyGridFilePropriedade::CMFCPropertyGridFileProperty

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
[em] O nome da propriedade.

*bOpenFileDialog*<br/>
[em] TRUE para abrir uma caixa de diálogo **Arquivo Aberto;** FALSO para abrir uma caixa de diálogo **Salvar arquivo.**

*Strfilename*<br/>
[em] O nome do arquivo inicial.

*lpszDefExt*<br/>
[em] Uma seqüência de uma ou mais extensões de nome de arquivo. O valor padrão é NULL.

*dwFlags*<br/>
[em] Bandeiras da caixa de diálogo. O valor padrão é uma combinação bitwise (OR) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.

*lpszFilter*<br/>
[em] Uma seqüência de um ou mais filtros de arquivo. O valor padrão é NULL.

*lpszDescr*<br/>
[em] A descrição do item da propriedade. O valor padrão é NULL.

*Dwdata*<br/>
[em] Dados específicos do aplicativo associados ao item da propriedade. Por exemplo, um inteiro de 32 bits ou um ponteiro para outros dados. O valor padrão é 0.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Para obter uma lista completa de sinalizadores disponíveis, consulte [a estrutura OPENFILENAME](/windows/win32/api/commdlg/ns-commdlg-openfilenamew).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um `CMFCPropertyGridFileProperty` objeto usando o construtor da classe. Este exemplo faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#22](../../mfc/codesnippet/cpp/cmfcpropertygridfileproperty-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)<br/>
[Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
