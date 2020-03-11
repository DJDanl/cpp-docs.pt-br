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
ms.openlocfilehash: fec8379a3944d981672754274f50dd4e60f71b61
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78883987"
---
# <a name="ctreeview-class"></a>Classe CTreeView

Simplifica o uso do controle de árvore e do [CTreeCtrl](../../mfc/reference/ctreectrl-class.md), a classe que encapsula a funcionalidade de controle de árvore, com a arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CTreeView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CTreeView::CTreeView](#ctreeview)|Constrói um objeto `CTreeView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CTreeView:: GetTreeCtrl](#gettreectrl)|Retorna o controle de árvore associado à exibição.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre essa arquitetura, consulte a visão geral da classe [cvisualização](../../mfc/reference/cview-class.md) e as referências cruzadas citadas ali.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cvisualização](../../mfc/reference/cview-class.md)

[CCtrlView](../../mfc/reference/cctrlview-class.md)

`CTreeView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcview. h

##  <a name="ctreeview"></a>CTreeView::CTreeView

Constrói um objeto `CTreeView`.

```
CTreeView();
```

##  <a name="gettreectrl"></a>CTreeView:: GetTreeCtrl

Retorna uma referência ao controle de árvore associado à exibição.

```
CTreeCtrl& GetTreeCtrl() const;
```

## <a name="see-also"></a>Confira também

[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Classe CTreeCtrl](../../mfc/reference/ctreectrl-class.md)
