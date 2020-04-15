---
title: Classe CMFCPropertyPage
ms.date: 11/04/2016
f1_keywords:
- CMFCPropertyPage
- AFXPROPERTYPAGE/CMFCPropertyPage
- AFXPROPERTYPAGE/CMFCPropertyPage::CMFCPropertyPage
helpviewer_keywords:
- CMFCPropertyPage [MFC], CMFCPropertyPage
ms.assetid: d279d7f2-2d81-418d-9f23-6147d6e8df09
ms.openlocfilehash: e493f016b6384a768935186c31e3fc71ade6382f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361766"
---
# <a name="cmfcpropertypage-class"></a>Classe CMFCPropertyPage

A `CMFCPropertyPage` classe suporta a exibição de menus pop-up em uma página de propriedade.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyPage : public CPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertyPage::CMFCPropertyPage](#cmfcpropertypage)|Constrói um objeto `CMFCPropertyPage`.|
|`CMFCPropertyPage::~CMFCPropertyPage`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCPropertyPage::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCPropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|`CMFCPropertyPage::OnSetActive`|Essa função de membro é chamada pela framework quando a página é escolhida pelo usuário e se torna a página ativa. (Substitui [cpropertyPage::OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).)|
|`CMFCPropertyPage::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. Para obter mais informações e sintaxe do método, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CPropertyPage::PreTranslateMessage`.)|

## <a name="remarks"></a>Comentários

A `CMFCPropertyPage` classe representa páginas individuais de uma folha de propriedades, também conhecida como caixa de diálogo de guia.

Use `CMFCPropertyPage` a classe juntamente com a classe [CMFCPropertySheet.](../../mfc/reference/cmfcpropertysheet-class.md) Para usar menus em uma página de `CPropertyPage` propriedade, `CMFCPropertyPage` substitua todas as ocorrências da classe pela classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cpropertypage](../../mfc/reference/cpropertypage-class.md)

[Cmfcpropertypage](../../mfc/reference/cmfcpropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertypage.h

## <a name="cmfcpropertypagecmfcpropertypage"></a><a name="cmfcpropertypage"></a>CMFCPropertyPage::CMFCPropertyPage

Constrói um objeto `CMFCPropertyPage`.

```
CMFCPropertyPage(
    UINT nIDTemplate,
    UINT nIDCaption=0);

CMFCPropertyPage(
    LPCTSTR lpszTemplateName,
    UINT nIDCaption=0);
```

### <a name="parameters"></a>Parâmetros

*Nidtemplate*<br/>
ID de recursos do modelo para esta página.

*nIDCaption*<br/>
ID de recurso do rótulo para colocar na guia para esta página. Se 0, o nome é obtido no modelo da caixa de diálogo para esta página. O valor padrão é 0.

*lpszTemplateName*<br/>
Aponta para o nome do modelo para esta página. Não pode ser NULL.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Para obter mais informações sobre os parâmetros do construtor, consulte [CPropertyPage::CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)
