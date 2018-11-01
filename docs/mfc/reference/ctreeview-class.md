---
title: Classe CTreeView
ms.date: 11/04/2016
f1_keywords:
- CTreeView
- AFXCVIEW/CTreeView
- AFXCVIEW/CTreeView::CTreeView
- AFXCVIEW/CTreeView::GetTreeCtrl
helpviewer_keywords:
- CTreeView [MFC], CTreeView
- CTreeView [MFC], GetTreeCtrl
ms.assetid: 5df583a6-d69f-42ca-9d8d-57e04558afff
ms.openlocfilehash: db899b58c68dabc25e571c390db0575a2d2ebb58
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496326"
---
# <a name="ctreeview-class"></a>Classe CTreeView

Simplifica o uso de controle de árvore e de [CTreeCtrl](../../mfc/reference/ctreectrl-class.md), a classe que encapsula a funcionalidade de controle de árvore, com a arquitetura de exibição de documento do MFC.

## <a name="syntax"></a>Sintaxe

```
class CTreeView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTreeView::CTreeView](#ctreeview)|Constrói um objeto `CTreeView`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTreeView::GetTreeCtrl](#gettreectrl)|Retorna o controle de árvore associado com o modo de exibição.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre essa arquitetura, consulte a visão geral para o [CView](../../mfc/reference/cview-class.md) classe e as referências cruzadas citadas lá.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CCtrlView](../../mfc/reference/cctrlview-class.md)

`CTreeView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcview.h

##  <a name="ctreeview"></a>  CTreeView::CTreeView

Constrói um objeto `CTreeView`.

```
CTreeView();
```

##  <a name="gettreectrl"></a>  CTreeView::GetTreeCtrl

Retorna uma referência ao controle de árvore associado com o modo de exibição.

```
CTreeCtrl& GetTreeCtrl() const;
```

## <a name="see-also"></a>Consulte também

[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)
