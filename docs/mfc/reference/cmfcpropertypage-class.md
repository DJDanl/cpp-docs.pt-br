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
ms.openlocfilehash: 62e33da998f1e5332436d887c38d3fd65526561b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62310481"
---
# <a name="cmfcpropertypage-class"></a>Classe CMFCPropertyPage

O `CMFCPropertyPage` classe oferece suporte a exibição de menus pop-up em uma página de propriedades.

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
|`CMFCPropertyPage::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCPropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|`CMFCPropertyPage::OnSetActive`|Essa função membro é chamada pelo framework quando a página é escolhida pelo usuário e torna-se a página ativa. (Substitui [CPropertyPage::OnSetActive](../../mfc/reference/cpropertypage-class.md#onsetactive).)|
|`CMFCPropertyPage::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. Para obter mais informações e a sintaxe de método, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CPropertyPage::PreTranslateMessage`.)|

## <a name="remarks"></a>Comentários

O `CMFCPropertyPage` classe representa páginas individuais de uma folha de propriedades, também conhecido como uma caixa de diálogo de guia.

Use o `CMFCPropertyPage` classe junto com o [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) classe. Para usar menus em uma página de propriedades, substitua todas as ocorrências de `CPropertyPage` classe com o `CMFCPropertyPage` classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CPropertyPage](../../mfc/reference/cpropertypage-class.md)

[CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertypage.h

##  <a name="cmfcpropertypage"></a>  CMFCPropertyPage::CMFCPropertyPage

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
ID de recurso do modelo para essa página.

*nIDCaption*<br/>
ID de recurso do rótulo para colocar na guia para esta página. Se for 0, o nome é obtido do modelo de caixa de diálogo para essa página. O valor padrão é 0.

*lpszTemplateName*<br/>
Aponta para o nome do modelo para essa página. Não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Para obter mais informações sobre os parâmetros do construtor, consulte [CPropertyPage::CPropertyPage](../../mfc/reference/cpropertypage-class.md#cpropertypage).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)
