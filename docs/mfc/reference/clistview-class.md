---
title: Classe CListView
ms.date: 11/04/2016
f1_keywords:
- CListView
- AFXCVIEW/CListView
- AFXCVIEW/CListView::CListView
- AFXCVIEW/CListView::GetListCtrl
- AFXCVIEW/CListView::RemoveImageList
helpviewer_keywords:
- CListView [MFC], CListView
- CListView [MFC], GetListCtrl
- CListView [MFC], RemoveImageList
ms.assetid: 7626bdb2-a1b8-4eab-b631-6743710a8432
ms.openlocfilehash: 4507c2a640296c2d2619b1da7a0ebae2bc6ef401
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57291269"
---
# <a name="clistview-class"></a>Classe CListView

Simplifica o uso do controle de lista e de [CListCtrl](../../mfc/reference/clistctrl-class.md), a classe que encapsula a funcionalidade de controle de lista, com a arquitetura de exibição de documento do MFC.

## <a name="syntax"></a>Sintaxe

```
class CListView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CListView::CListView](#clistview)|Constrói um objeto `CListView`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CListView::GetListCtrl](#getlistctrl)|Retorna o controle de lista associado com o modo de exibição.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CListView::RemoveImageList](#removeimagelist)|Remove a lista de imagem especificado da exibição de lista.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre essa arquitetura, consulte a visão geral para o [CView](../../mfc/reference/cview-class.md) classe e as referências cruzadas citadas lá.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CCtrlView](../../mfc/reference/cctrlview-class.md)

`CListView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcview.h

##  <a name="clistview"></a>  CListView::CListView

Constrói um objeto `CListView`.

```
CListView();
```

##  <a name="getlistctrl"></a>  CListView::GetListCtrl

Chame essa função de membro para obter uma referência para o controle de lista associado com o modo de exibição.

```
CListCtrl& GetListCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência ao controle de lista associado com o modo de exibição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCListView#7](../../atl/reference/codesnippet/cpp/clistview-class_1.cpp)]

##  <a name="removeimagelist"></a>  CListView::RemoveImageList

Remove a lista de imagem especificado da exibição de lista.

```
void RemoveImageList(int nImageList);
```

### <a name="parameters"></a>Parâmetros

*nImageList*<br/>
O índice baseado em zero da imagem a ser removida.

## <a name="see-also"></a>Consulte também

[Exemplo MFC ROWLIST](../../visual-cpp-samples.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)
