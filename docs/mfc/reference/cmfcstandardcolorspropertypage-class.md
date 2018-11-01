---
title: Classe CMFCStandardColorsPropertyPage
ms.date: 11/04/2016
helpviewer_keywords:
- CMFCStandardColorsPropertyPage class [MFC]
ms.assetid: b84b7cfb-bb24-4c65-804a-5b642cb64400
ms.openlocfilehash: 7663f85b20ab88c999af7ba37b260237d0fd869e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50520660"
---
# <a name="cmfcstandardcolorspropertypage-class"></a>Classe CMFCStandardColorsPropertyPage

Representa uma página de propriedades que os usuários usam para selecionar cores padrão em uma caixa de diálogo de cor.

## <a name="syntax"></a>Sintaxe

```
class CMFCStandardColorsPropertyPage : public CPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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
