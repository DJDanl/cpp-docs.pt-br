---
title: Classe CMFCCustomColorsPropertyPage
ms.date: 11/04/2016
f1_keywords:
- CMFCCustomColorsPropertyPage
- AFXCUSTOMCOLORSPROPERTYPAGE/CMFCCustomColorsPropertyPage
- AFXCUSTOMCOLORSPROPERTYPAGE/CMFCCustomColorsPropertyPage::Setup
helpviewer_keywords:
- CMFCCustomColorsPropertyPage [MFC], Setup
ms.assetid: 46a45ba2-1fda-440d-8018-d4dcd44f5816
ms.openlocfilehash: b28711991835dd14929e5387709046c3867c715e
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57299875"
---
# <a name="cmfccustomcolorspropertypage-class"></a>Classe CMFCCustomColorsPropertyPage

Representa uma página de propriedade que pode selecionar cores personalizadas em uma caixa de diálogo de cor.

## <a name="syntax"></a>Sintaxe

```
class CMFCCustomColorsPropertyPage : public CPropertyPage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCCustomColorsPropertyPage::CMFCCustomColorsPropertyPage`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCCustomColorsPropertyPage::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCCustomColorsPropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCCustomColorsPropertyPage::Setup](#setup)|Define os componentes de cor da página de propriedades.|

### <a name="remarks"></a>Comentários

O `CMFCColorDialog` classe usa essa classe para exibir a página de propriedade de cor personalizada. Para obter mais informações sobre `CMFCColorDialog`, consulte [classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCCustomColorsPropertyPage` do objeto e defina os componentes de cor da página de propriedades.

[!code-cpp[NVC_MFC_RibbonApp#35](../../mfc/reference/codesnippet/cpp/cmfccustomcolorspropertypage-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CPropertyPage](../../mfc/reference/cpropertypage-class.md)

[CMFCCustomColorsPropertyPage](../../mfc/reference/cmfccustomcolorspropertypage-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcustomcolorspropertypage.h

##  <a name="setup"></a>  CMFCCustomColorsPropertyPage::Setup

Define os componentes de cor da página de propriedades.

```
void Setup(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*R*|[in] O componente vermelho do valor RGB.|
|*G*|[in] O componente verde do valor RGB.|
|*B*|[in] O componente azul do valor RGB.|

### <a name="remarks"></a>Comentários

Esse método atualiza o atual RGB e HLS (matiz, luminosidade e saturação) cor valores associados da página de propriedades. O [CMFCColorDialog::SetPageTwo](../../mfc/reference/cmfccolordialog-class.md#setpagetwo) método chama esse método quando o framework inicializa a caixa de diálogo de cor ou o usuário pressiona o botão esquerdo do mouse. Para obter mais informações sobre `CMFCColorDialog`, consulte [classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)<br/>
[Classe CMFCStandardColorsPropertyPage](../../mfc/reference/cmfcstandardcolorspropertypage-class.md)
