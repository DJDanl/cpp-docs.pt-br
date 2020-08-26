---
title: Classe CMFCDesktopAlertWndButton
ms.date: 11/04/2016
f1_keywords:
- CMFCDesktopAlertWndButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWndButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWndButton::IsCaptionButton
- AFXDESKTOPALERTWND/CMFCDesktopAlertWndButton::IsCloseButton
helpviewer_keywords:
- CMFCDesktopAlertWndButton [MFC], IsCaptionButton
- CMFCDesktopAlertWndButton [MFC], IsCloseButton
ms.assetid: df39a0c8-0c39-4ab0-8c64-78c5b2c4ecaf
ms.openlocfilehash: 6d296966001dcbc2279a298bdd1d9c21195d61fd
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840773"
---
# <a name="cmfcdesktopalertwndbutton-class"></a>Classe CMFCDesktopAlertWndButton

Permite que os botões sejam adicionados a uma caixa de diálogo de alerta da área de trabalho.

## <a name="syntax"></a>Sintaxe

```
class CMFCDesktopAlertWndButton : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|`CMFCDesktopAlertWndButton::CMFCDesktopAlertWndButton`|Construtor padrão.|
|`CMFCDesktopAlertWndButton::~CMFCDesktopAlertWndButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCDesktopAlertWndButton::IsCaptionButton](#iscaptionbutton)|Determina se o botão é exibido na área de legenda da caixa de diálogo de alerta.|
|[CMFCDesktopAlertWndButton:: isbotãofechar](#isclosebutton)|Determina se o botão fecha a caixa de diálogo de alerta.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|-|-|
|`CMFCDesktopAlertWndButton::m_bIsCaptionButton`|Um valor booliano que especifica se o botão é exibido na área de legenda da caixa de diálogo de alerta.|
|`CMFCDesktopAlertWndButton::m_bIsCloseButton`|Um valor booliano que especifica se o botão fecha a caixa de diálogo de alerta.|

### <a name="remarks"></a>Comentários

Por padrão, o construtor define os `m_bIsCaptionButton` `m_bIsCloseButton` membros de dados e como false. O `CMFCDesktopAlertDialog` objeto pai `m_bIsCaptionButton` será definido como true se o botão estiver posicionado na área de legenda da caixa de diálogo de alerta. A `CMFCDesktopAlertDialog` classe cria um `CMFCDesktopAlertWndButton` objeto que serve como o botão que fecha a caixa de diálogo de alerta e define `m_bIsCloseButton` como true.

Adicione `CMFCDesktopAlertWndButton` objetos a um `CMFCDesktopAlertDialog` objeto como você adicionaria qualquer botão. Para obter mais informações sobre `CMFCDesktopAlertDialog` , consulte [classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `SetImage` método na `CMFCDesktopAlertWndButton` classe. Este trecho de código faz parte do [exemplo de demonstração de alerta de desktop](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DesktopAlertDemo#4](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndbutton-class_1.h)]
[!code-cpp[NVC_MFC_DesktopAlertDemo#5](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[CMFCButton](../../mfc/reference/cmfcbutton-class.md)

[CMFCDesktopAlertWndButton](../../mfc/reference/cmfcdesktopalertwndbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdesktopalertwnd. h

## <a name="cmfcdesktopalertwndbuttoniscaptionbutton"></a><a name="iscaptionbutton"></a> CMFCDesktopAlertWndButton::IsCaptionButton

Determina se o botão é exibido na área de legenda da caixa de diálogo de alerta.

```
BOOL IsCaptionButton() const;
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o botão for exibido na área de legenda da caixa de diálogo de alerta; caso contrário, 0.

## <a name="cmfcdesktopalertwndbuttonisclosebutton"></a><a name="isclosebutton"></a> CMFCDesktopAlertWndButton:: isbotãofechar

Determina se o botão fecha a caixa de diálogo de alerta.

```
BOOL IsCloseButton() const;
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o botão fechar a caixa de diálogo de alerta; caso contrário, 0.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)
