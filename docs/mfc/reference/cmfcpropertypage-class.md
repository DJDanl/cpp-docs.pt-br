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
ms.openlocfilehash: 4be584135ef789d7fbe3b1743ac0ad6ce66ac5b1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505039"
---
# <a name="cmfcpropertypage-class"></a>Classe CMFCPropertyPage

A `CMFCPropertyPage` classe dá suporte à exibição de menus pop-up em uma página de propriedades.

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
|`CMFCPropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|`CMFCPropertyPage::OnSetActive`|Essa função de membro é chamada pelo Framework quando a página é escolhida pelo usuário e se torna a página ativa. (Substitui [CPropertyPage:: OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).)|
|`CMFCPropertyPage::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . Para obter mais informações e sintaxe de método, consulte [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CPropertyPage::PreTranslateMessage`.)|

## <a name="remarks"></a>Comentários

A `CMFCPropertyPage` classe representa páginas individuais de uma folha de propriedades, também conhecida como caixa de diálogo de tabulação.

Use a `CMFCPropertyPage` classe junto com a classe [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) . Para usar menus em uma página de propriedades, substitua todas as ocorrências `CPropertyPage` da classe `CMFCPropertyPage` pela classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CPropertyPage](../../mfc/reference/cpropertypage-class.md)

[CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertypage. h

##  <a name="cmfcpropertypage"></a>CMFCPropertyPage::CMFCPropertyPage

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

*nIDTemplate*<br/>
ID de recurso do modelo para esta página.

*nIDCaption*<br/>
ID de recurso do rótulo a ser colocado na guia desta página. Se for 0, o nome será obtido do modelo da caixa de diálogo para esta página. O valor padrão é 0.

*lpszTemplateName*<br/>
Aponta para o nome do modelo desta página. Não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Para obter mais informações sobre os parâmetros do Construtor, consulte [CPropertyPage:: CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)
