---
title: Classe CMFCRibbonCustomizePropertyPage
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonCustomizePropertyPage
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage::AddCustomCategory
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage::OnOK
helpviewer_keywords:
- CMFCRibbonCustomizePropertyPage [MFC], CMFCRibbonCustomizePropertyPage
- CMFCRibbonCustomizePropertyPage [MFC], AddCustomCategory
- CMFCRibbonCustomizePropertyPage [MFC], OnOK
ms.assetid: ea32a99a-dfbe-401e-8975-aa191552532f
ms.openlocfilehash: 57fbd1e1f574beebff8baab014e7ab615f56333f
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754166"
---
# <a name="cmfcribboncustomizepropertypage-class"></a>Classe CMFCRibbonCustomizePropertyPage

Implementa uma página personalizada para a caixa de diálogo **Personalizar** em aplicativos baseados em Fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCustomizePropertyPage: public CMFCPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonPersonalizePropriedadePágina::CMFCRibbonPersonalizePropriedadePage](#cmfcribboncustomizepropertypage)|Constrói um objeto `CMFCRibbonCustomizePropertyPage`.|
|`CMFCRibbonCustomizePropertyPage::~CMFCRibbonCustomizePropertyPage`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonPersonalizePropriedadePágina::Adicionacategoria de personalizados](#addcustomcategory)|Adiciona uma categoria personalizada à caixa de combinação **Comandos.**|
|`CMFCRibbonCustomizePropertyPage::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonCustomizePropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCRibbonPersonalizePropriedadePage::OnOK](#onok)|Chamado pelo sistema quando um usuário clica **OK** na caixa de diálogo **Personalizar.**|

## <a name="remarks"></a>Comentários

Se você quiser adicionar comandos personalizados à caixa de diálogo **Personalizar,** você deve lidar com a mensagem AFX_WM_ON_RIBBON_CUSTOMIZE. No manipulador de mensagens, instanciar um `CMFCRibbonCustomizePropertyPage` objeto na pilha. Crie uma lista de comandos `AddCustomCategory` personalizados e, em seguida, ligue para adicionar a nova página à caixa de diálogo **Personalizar.**

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCRibbonCustomizePropertyPage` demonstra como construir um objeto e adicionar uma categoria personalizada.

[!code-cpp[NVC_MFC_RibbonApp#22](../../mfc/reference/codesnippet/cpp/cmfcribboncustomizepropertypage-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cpropertypage](../../mfc/reference/cpropertypage-class.md)

[Cmfcpropertypage](../../mfc/reference/cmfcpropertypage-class.md)

[Cmfcribboncustomizepropertypage](../../mfc/reference/cmfcribboncustomizepropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncustomdialog.h

## <a name="cmfcribboncustomizepropertypageaddcustomcategory"></a><a name="addcustomcategory"></a>CMFCRibbonPersonalizePropriedadePágina::Adicionacategoria de personalizados

Adiciona uma categoria personalizada à caixa de combinação **Comandos.**

```cpp
void AddCustomCategory(
    LPCTSTR lpszName,
    const CList<UINT, UINT>& lstIDS);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*lpszName*|[em] Especifica o nome da categoria personalizada.|
|*ISTDS*|[em] Contém IDs de comando de fita a serem mostrados na categoria personalizada.|

### <a name="remarks"></a>Comentários

Este método adiciona uma categoria chamada *lpszName* à caixa de combinação **Comandos.** Quando o usuário seleciona a categoria, os comandos especificados no *ISTDS* aparecem na lista de comandos.

## <a name="cmfcribboncustomizepropertypagecmfcribboncustomizepropertypage"></a><a name="cmfcribboncustomizepropertypage"></a>CMFCRibbonPersonalizePropriedadePágina::CMFCRibbonPersonalizePropriedadePage

Constrói um objeto `CMFCRibbonCustomizePropertyPage`.

```
CMFCRibbonCustomizePropertyPage(CMFCRibbonBar* pRibbonBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*pRibbonBar*<br/>
[em] Um ponteiro para um controle de fita para o qual as opções para personalizar.

## <a name="cmfcribboncustomizepropertypageonok"></a><a name="onok"></a>CMFCRibbonPersonalizePropriedadePage::OnOK

Chamado pelo sistema quando um usuário clica **OK** na caixa de diálogo **Personalizar.**

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

A implementação padrão aplica as opções selecionadas na caixa de diálogo **Personalizar** à barra de ferramentas de acesso rápido.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
