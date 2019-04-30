---
title: Classe CMFCStandardColorsPropertyPage
ms.date: 11/04/2016
helpviewer_keywords:
- CMFCStandardColorsPropertyPage class [MFC]
ms.assetid: b84b7cfb-bb24-4c65-804a-5b642cb64400
ms.openlocfilehash: 91cfa609c31e83c02cce8b2a474a9b66ec3ba56f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62388625"
---
# <a name="cmfcstandardcolorspropertypage-class"></a>Classe CMFCStandardColorsPropertyPage

Representa uma página de propriedades que os usuários usam para selecionar cores padrão em uma caixa de diálogo de cor.

## <a name="syntax"></a>Sintaxe

```
class CMFCStandardColorsPropertyPage : public CPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCStandardColorsPropertyPage::CMFCStandardColorsPropertyPage`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCStandardColorsPropertyPage::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCStandardColorsPropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|

### <a name="remarks"></a>Comentários

O `CMFCColorDialog` classe usa essa classe para exibir a página de propriedades de cores padrão. Para obter mais informações sobre `CMFCColorDialog`, consulte [classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CPropertyPage](../../mfc/reference/cpropertypage-class.md)

[CMFCStandardColorsPropertyPage](../../mfc/reference/cmfcstandardcolorspropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxstandardcolorspropertypage.h

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)<br/>
[Classe CMFCCustomColorsPropertyPage](../../mfc/reference/cmfccustomcolorspropertypage-class.md)
