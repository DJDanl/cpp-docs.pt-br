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
ms.openlocfilehash: 5b18a15f8bfd98396acae0558d121b32bc4127c3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367622"
---
# <a name="cmfcdesktopalertwndbutton-class"></a>Classe CMFCDesktopAlertWndButton

Permite que os botões sejam adicionados a uma caixa de diálogo de alerta de área de trabalho.

## <a name="syntax"></a>Sintaxe

```
class CMFCDesktopAlertWndButton : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|`CMFCDesktopAlertWndButton::CMFCDesktopAlertWndButton`|Construtor padrão.|
|`CMFCDesktopAlertWndButton::~CMFCDesktopAlertWndButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCDesktopAlertWndButton::IsCaptionButton](#iscaptionbutton)|Determina se o botão é exibido na área de legenda da caixa de diálogo de alerta.|
|[CMFCDesktopAlertWndButton::IsCloseButton](#isclosebutton)|Determina se o botão fecha a caixa de diálogo de alerta.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|Nome|Descrição|
|`CMFCDesktopAlertWndButton::m_bIsCaptionButton`|Um valor booleano que especifica se o botão é exibido na área de legenda da caixa de diálogo de alerta.|
|`CMFCDesktopAlertWndButton::m_bIsCloseButton`|Um valor booleano que especifica se o botão fecha a caixa de diálogo de alerta.|

### <a name="remarks"></a>Comentários

Por padrão, o construtor `m_bIsCaptionButton` `m_bIsCloseButton` define os membros e dados como FALSOs. O `CMFCDesktopAlertDialog` objeto `m_bIsCaptionButton` pai é configurado como TRUE se o botão estiver posicionado na área de legenda da caixa de diálogo de alerta. A `CMFCDesktopAlertDialog` classe `CMFCDesktopAlertWndButton` cria um objeto que serve como o botão `m_bIsCloseButton` que fecha a caixa de diálogo de alerta e define como TRUE.

Adicione `CMFCDesktopAlertWndButton` objetos `CMFCDesktopAlertDialog` a um objeto como você adicionaria qualquer botão. Para obter `CMFCDesktopAlertDialog`mais informações sobre, consulte [CMFCDesktopAlertSala Class](../../mfc/reference/cmfcdesktopalertdialog-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir `SetImage` demonstra como `CMFCDesktopAlertWndButton` usar o método na classe. Este trecho de código faz parte da [amostra de demonstração de alerta de área de trabalho](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DesktopAlertDemo#4](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndbutton-class_1.h)]
[!code-cpp[NVC_MFC_DesktopAlertDemo#5](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[Cmfcbutton](../../mfc/reference/cmfcbutton-class.md)

[CMFCDesktopAlertWndButton](../../mfc/reference/cmfcdesktopalertwndbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdesktopalertwnd.h

## <a name="cmfcdesktopalertwndbuttoniscaptionbutton"></a><a name="iscaptionbutton"></a>CMFCDesktopAlertWndButton::IsCaptionButton

Determina se o botão é exibido na área de legenda da caixa de diálogo de alerta.

```
BOOL IsCaptionButton() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o botão for exibido na área de legenda da caixa de diálogo de alerta; caso contrário, 0.

## <a name="cmfcdesktopalertwndbuttonisclosebutton"></a><a name="isclosebutton"></a>CMFCDesktopAlertWndButton::IsCloseButton

Determina se o botão fecha a caixa de diálogo de alerta.

```
BOOL IsCloseButton() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o botão fechar a caixa de diálogo de alerta; caso contrário, 0.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)
