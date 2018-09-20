---
title: Classe CMFCRibbonCustomizePropertyPage | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonCustomizePropertyPage
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage::AddCustomCategory
- AFXRIBBONCUSTOMIZEDIALOG/CMFCRibbonCustomizePropertyPage::OnOK
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonCustomizePropertyPage [MFC], CMFCRibbonCustomizePropertyPage
- CMFCRibbonCustomizePropertyPage [MFC], AddCustomCategory
- CMFCRibbonCustomizePropertyPage [MFC], OnOK
ms.assetid: ea32a99a-dfbe-401e-8975-aa191552532f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 42c57d8ba06e5678b8385c102c70a23dcf12b18f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46406705"
---
# <a name="cmfcribboncustomizepropertypage-class"></a>Classe CMFCRibbonCustomizePropertyPage

Implementa uma página personalizada para o **personalizar** caixa de diálogo em aplicativos baseados na faixa de opções.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonCustomizePropertyPage: public CMFCPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage](#cmfcribboncustomizepropertypage)|Constrói um objeto `CMFCRibbonCustomizePropertyPage`.|
|`CMFCRibbonCustomizePropertyPage::~CMFCRibbonCustomizePropertyPage`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCRibbonCustomizePropertyPage::AddCustomCategory](#addcustomcategory)|Adiciona uma categoria personalizada para o **comandos** caixa de combinação.|
|`CMFCRibbonCustomizePropertyPage::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonCustomizePropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCRibbonCustomizePropertyPage::OnOK](#onok)|Chamado pelo sistema quando um usuário clica **Okey** sobre o **personalizar** caixa de diálogo.|

## <a name="remarks"></a>Comentários

Se você quiser adicionar comandos personalizados para o **personalizar** caixa de diálogo, você deve lidar com a mensagem AFX_WM_ON_RIBBON_CUSTOMIZE. No manipulador de mensagens, instanciar um `CMFCRibbonCustomizePropertyPage` objeto na pilha. Criar uma lista de comandos personalizados e, em seguida, chamar `AddCustomCategory` para adicionar a nova página para o **personalizar** caixa de diálogo.

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

**Cabeçalho:** afxribboncustomizedialog.h

##  <a name="addcustomcategory"></a>  CMFCRibbonCustomizePropertyPage::AddCustomCategory

Adiciona uma categoria personalizada para o **comandos** caixa de combinação.

```
void AddCustomCategory(
    LPCTSTR lpszName,
    const CList<UINT, UINT>& lstIDS);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*lpszName*|[in] Especifica o nome da categoria personalizada.|
|*lstIDS*|[in] Contém as IDs de comando de faixa de opções a serem mostrados na categoria personalizada.|

### <a name="remarks"></a>Comentários

Esse método adiciona uma categoria chamada *lpszName* para o **comandos** caixa de combinação. Quando o usuário seleciona a categoria, os comandos especificados em *lstIDS* aparecem na lista de comandos.

##  <a name="cmfcribboncustomizepropertypage"></a>  CMFCRibbonCustomizePropertyPage::CMFCRibbonCustomizePropertyPage

Constrói um objeto `CMFCRibbonCustomizePropertyPage`.

```
CMFCRibbonCustomizePropertyPage(CMFCRibbonBar* pRibbonBar = NULL);
```

### <a name="parameters"></a>Parâmetros

*pRibbonBar*<br/>
[in] Um ponteiro para um controle de faixa de opções para o qual as opções para personalizar.

##  <a name="onok"></a>  CMFCRibbonCustomizePropertyPage::OnOK

Calleld pelo sistema quando um usuário clica **Okey** sobre o **personalizar** caixa de diálogo.

```
virtual void OnOK();
```

### <a name="remarks"></a>Comentários

A implementação padrão aplica-se as opções selecionadas na **personalizar** caixa de diálogo para a barra de ferramentas de acesso rápido.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
