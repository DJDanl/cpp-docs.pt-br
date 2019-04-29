---
title: Classe CMFCRibbonCustomizeDialog
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonCustomizeDialog
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizeDialog
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog
helpviewer_keywords:
- CMFCRibbonCustomizeDialog [MFC], CMFCRibbonCustomizeDialog
ms.assetid: ce67de7f-5eaa-4c75-9b94-f290f36df073
ms.openlocfilehash: d73fd05a775ac26f5d289a5233341102f40e9af3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62237598"
---
# <a name="cmfcribboncustomizedialog-class"></a>Classe CMFCRibbonCustomizeDialog

Exibe a faixa de opções **personalizar** página.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCustomizeDialog : public CMFCPropertySheet
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog](#cmfcribboncustomizedialog)|Constrói um objeto `CMFCRibbonCustomizeDialog`.|
|`CMFCRibbonCustomizeDialog::~CMFCRibbonCustomizeDialog`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonCustomizeDialog::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|

## <a name="remarks"></a>Comentários

MFC cria uma instância dessa classe automaticamente se você não processar a mensagem AFX_WM_ON_RIBBON_CUSTOMIZE, ou se você retornar 0 de manipulador de mensagens.

Se você deseja usar essa classe em seu aplicativo para exibir a faixa de opções **personalizar** diálogo caixa, apenas uma instância e chamar o `DoModal` método.

Porque essa classe é derivada de [classe CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md), você pode adicionar páginas personalizadas, usando o `CMFCPropertySheet` API.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CPropertySheet](../../mfc/reference/cpropertysheet-class.md)

[CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)

[CMFCRibbonCustomizeDialog](../../mfc/reference/cmfcribboncustomizedialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncustomizedialog.h

##  <a name="cmfcribboncustomizedialog"></a>  CMFCRibbonCustomizeDialog::CMFCRibbonCustomizeDialog

Constrói um objeto `CMFCRibbonCustomizeDialog`.

```
CMFCRibbonCustomizeDialog(
    CWnd* pWndParent,
    CMFCRibbonBar* pRibbon);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[in] Um ponteiro para a janela pai (normalmente, o quadro principal).

*pRibbon*<br/>
[in] Um ponteiro para o `CMFCRibbonBar` que deve ser personalizado.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCRibbonCustomizeDialog` objeto.

[!code-cpp[NVC_MFC_RibbonApp#18](../../mfc/reference/codesnippet/cpp/cmfcribboncustomizedialog-class_1.cpp)]

### <a name="remarks"></a>Comentários

O construtor instancia uma [classe CMFCRibbonCustomizePropertyPage](../../mfc/reference/cmfcribboncustomizepropertypage-class.md) do objeto e o adiciona à coleção de páginas de folha de propriedades.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
