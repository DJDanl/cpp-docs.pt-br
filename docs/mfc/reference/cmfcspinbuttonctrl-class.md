---
title: Classe CMFCSpinButtonCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCSpinButtonCtrl
- AFXSPINBUTTONCTRL/CMFCSpinButtonCtrl
- AFXSPINBUTTONCTRL/CMFCSpinButtonCtrl::OnDraw
helpviewer_keywords:
- CMFCSpinButtonCtrl [MFC], OnDraw
ms.assetid: 8773f259-4d3f-4bca-a71c-09e0c71bc843
ms.openlocfilehash: 445b857400d8c82109ca7220b84bac692a2abf89
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376185"
---
# <a name="cmfcspinbuttonctrl-class"></a>Classe CMFCSpinButtonCtrl

A `CMFCSpinButtonCtrl` classe suporta um gerenciador visual que desenha um controle de botão de giro.

## <a name="syntax"></a>Sintaxe

```
class CMFCSpinButtonCtrl : public CSpinButtonCtrl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCSpinButtonCtrl::CMFCSpinButtonCtrl`|Construtor padrão.|
|`CMFCSpinButtonCtrl::~CMFCSpinButtonCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCSpinButtonCtrl::OnDraw](#ondraw)|Repinta o controle do botão de giro atual.|

## <a name="remarks"></a>Comentários

Para usar um gerenciador visual para desenhar um controle de `CSpinButtonCtrl` botão `CMFCSpinButtonCtrl` de giro em seu aplicativo, substitua todas as instâncias da classe pela classe.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCSpinButtonCtrl` criar um `Create` objeto da classe e usar seu método.

[!code-cpp[NVC_MFC_RibbonApp#25](../../mfc/reference/codesnippet/cpp/cmfcspinbuttonctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CSpinButtonCtrl](../../mfc/reference/cspinbuttonctrl-class.md)

[CMFCSpinButtonCtrl](../../mfc/reference/cmfcspinbuttonctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxspinbuttonctrl.h

## <a name="cmfcspinbuttonctrlondraw"></a><a name="ondraw"></a>CMFCSpinButtonCtrl::OnDraw

Repinta o controle do botão de giro atual.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

A estrutura `CMFCSpinButtonCtrl::OnPaint` chama o método para lidar com a mensagem [CWnd::OnPaint,](../../mfc/reference/cwnd-class.md#onpaint) e esse método, por sua vez, chama esse `CMFCSpinButtonCtrl::OnDraw` método. Anular este método para personalizar a forma como a estrutura desenha o controle do botão de giro.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)
