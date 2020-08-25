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
ms.openlocfilehash: 92408e91b41b474da3a2da6ad0646feb3a6b8fc2
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831834"
---
# <a name="cmfcribboncustomizepropertypage-class"></a>Classe CMFCRibbonCustomizePropertyPage

Implementa uma página personalizada para a caixa de diálogo **Personalizar** em aplicativos baseados na faixa de bits.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCustomizePropertyPage: public CMFCPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|[CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage](#cmfcribboncustomizepropertypage)|Constrói um objeto `CMFCRibbonCustomizePropertyPage`.|
|`CMFCRibbonCustomizePropertyPage::~CMFCRibbonCustomizePropertyPage`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCRibbonCustomizePropertyPage::AddCustomCategory](#addcustomcategory)|Adiciona uma categoria personalizada à caixa de combinação **comandos** .|
|`CMFCRibbonCustomizePropertyPage::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonCustomizePropertyPage::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCRibbonCustomizePropertyPage::OnOK](#onok)|Chamado pelo sistema quando um usuário clica em **OK** na caixa de diálogo **Personalizar** .|

## <a name="remarks"></a>Comentários

Se você quiser adicionar comandos personalizados à caixa de diálogo **Personalizar** , você deve manipular a mensagem de AFX_WM_ON_RIBBON_CUSTOMIZE. No manipulador de mensagens, crie uma instância de um `CMFCRibbonCustomizePropertyPage` objeto na pilha. Crie uma lista de comandos personalizados e, em seguida, chame `AddCustomCategory` para adicionar a nova página à caixa de diálogo **Personalizar** .

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCRibbonCustomizePropertyPage` objeto e adicionar uma categoria personalizada.

[!code-cpp[NVC_MFC_RibbonApp#22](../../mfc/reference/codesnippet/cpp/cmfcribboncustomizepropertypage-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CPropertyPage](../../mfc/reference/cpropertypage-class.md)

[CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)

[CMFCRibbonCustomizePropertyPage](../../mfc/reference/cmfcribboncustomizepropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncustomizedialog. h

## <a name="cmfcribboncustomizepropertypageaddcustomcategory"></a><a name="addcustomcategory"></a> CMFCRibbonCustomizePropertyPage::AddCustomCategory

Adiciona uma categoria personalizada à caixa de combinação **comandos** .

```cpp
void AddCustomCategory(
    LPCTSTR lpszName,
    const CList<UINT, UINT>& lstIDS);
```

### <a name="parameters"></a>parâmetros

*lpszName*\
no Especifica o nome da categoria personalizada.

*lstIDS*\
no Contém as IDs de comando da faixa de das para serem mostradas na categoria personalizada.

### <a name="remarks"></a>Comentários

Esse método adiciona uma categoria chamada *lpszName* à caixa de combinação **comandos** . Quando o usuário seleciona a categoria, os comandos especificados em *lstIDS* aparecem na lista de comandos.

## <a name="cmfcribboncustomizepropertypagecmfcribboncustomizepropertypage"></a><a name="cmfcribboncustomizepropertypage"></a> CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage

Constrói um objeto `CMFCRibbonCustomizePropertyPage`.

```
CMFCRibbonCustomizePropertyPage(CMFCRibbonBar* pRibbonBar = NULL);
```

### <a name="parameters"></a>parâmetros

*pRibbonBar*<br/>
no Um ponteiro para um controle Ribbon para o qual as opções são personalizadas.

## <a name="cmfcribboncustomizepropertypageonok"></a><a name="onok"></a> CMFCRibbonCustomizePropertyPage::OnOK

Calleld pelo sistema quando um usuário clica em **OK** na caixa de diálogo **Personalizar** .

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

A implementação padrão aplica as opções selecionadas na caixa de diálogo **Personalizar** à barra de ferramentas de acesso rápido.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
