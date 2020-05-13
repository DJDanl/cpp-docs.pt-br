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
ms.openlocfilehash: a66c0a19c04e0a900b91c0c28c45bb9c766d25c0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375203"
---
# <a name="cmfcribboncustomizedialog-class"></a>Classe CMFCRibbonCustomizeDialog

Exibe a página **Personalizar** fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCustomizeDialog : public CMFCPropertySheet
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonCustomCustomDialog::CMFCRibbonPersonalize-seDiálogo](#cmfcribboncustomizedialog)|Constrói um objeto `CMFCRibbonCustomizeDialog`.|
|`CMFCRibbonCustomizeDialog::~CMFCRibbonCustomizeDialog`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonCustomizeDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|

## <a name="remarks"></a>Comentários

O MFC instancia essa classe automaticamente se você não processar a mensagem AFX_WM_ON_RIBBON_CUSTOMIZE ou se você retornar 0 do manipulador de mensagens.

Se você quiser usar esta classe em seu aplicativo para exibir a caixa `DoModal` de diálogo **Personalizar,** basta instancia-la e chamar o método.

Como essa classe é derivada do [CMFCPropertySheet Class,](../../mfc/reference/cmfcpropertysheet-class.md) `CMFCPropertySheet` você pode adicionar páginas personalizadas usando a API.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cpropertysheet](../../mfc/reference/cpropertysheet-class.md)

[Cmfcpropertysheet](../../mfc/reference/cmfcpropertysheet-class.md)

[CMFCRibbonCustomCustomDialog](../../mfc/reference/cmfcribboncustomizedialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncustomdialog.h

## <a name="cmfcribboncustomizedialogcmfcribboncustomizedialog"></a><a name="cmfcribboncustomizedialog"></a>CMFCRibbonCustomCustomDialog::CMFCRibbonPersonalize-seDiálogo

Constrói um objeto `CMFCRibbonCustomizeDialog`.

```
CMFCRibbonCustomizeDialog(
    CWnd* pWndParent,
    CMFCRibbonBar* pRibbon);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a janela pai (geralmente o quadro principal).

*pRibbon*<br/>
[em] Um ponteiro `CMFCRibbonBar` para o que deve ser personalizado.

### <a name="example"></a>Exemplo

O exemplo a seguir `CMFCRibbonCustomizeDialog` demonstra como construir um objeto.

[!code-cpp[NVC_MFC_RibbonApp#18](../../mfc/reference/codesnippet/cpp/cmfcribboncustomizedialog-class_1.cpp)]

### <a name="remarks"></a>Comentários

O construtor instancia um objeto [CMFCRibbonCustomizePropertyPage Class](../../mfc/reference/cmfcribboncustomizepropertypage-class.md) e o adiciona à coleção de páginas da folha de propriedade.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
