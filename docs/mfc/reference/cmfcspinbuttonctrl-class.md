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
ms.openlocfilehash: 60808359c11604368493031e1b6f4573b3b2026f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410086"
---
# <a name="cmfcspinbuttonctrl-class"></a>Classe CMFCSpinButtonCtrl

O `CMFCSpinButtonCtrl` classe dá suporte a um gerente que desenha um controle de botão de rotação.

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
|[CMFCSpinButtonCtrl::OnDraw](#ondraw)|Redesenha o controle de botão de rotação atual.|

## <a name="remarks"></a>Comentários

Para usar um Gerenciador visual para desenhar um controle de botão de rotação em seu aplicativo, substitua todas as instâncias do `CSpinButtonCtrl` classe com o `CMFCSpinButtonCtrl` classe.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto do `CMFCSpinButtonCtrl` de classe e usar seu `Create` método.

[!code-cpp[NVC_MFC_RibbonApp#25](../../mfc/reference/codesnippet/cpp/cmfcspinbuttonctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CSpinButtonCtrl](../../mfc/reference/cspinbuttonctrl-class.md)

[CMFCSpinButtonCtrl](../../mfc/reference/cmfcspinbuttonctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxspinbuttonctrl.h

##  <a name="ondraw"></a>  CMFCSpinButtonCtrl::OnDraw

Redesenha o controle de botão de rotação atual.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

A estrutura chama o `CMFCSpinButtonCtrl::OnPaint` método para lidar com o [CWnd::OnPaint](../../mfc/reference/cwnd-class.md#onpaint) mensagem e que método por sua vez chama isso `CMFCSpinButtonCtrl::OnDraw` método. Substitua este método para personalizar a maneira como o framework desenha o controle de botão de rotação.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCVisualManager](../../mfc/reference/cmfcvisualmanager-class.md)
