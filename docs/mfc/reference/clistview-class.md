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
ms.openlocfilehash: ae1a76e4cdd052ff44dcbd69d467c51741bcc2ff
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370146"
---
# <a name="clistview-class"></a>Classe CListView

Simplifica o uso do controle de lista e do [CListCtrl](../../mfc/reference/clistctrl-class.md), a classe que encapsula a funcionalidade de controle de lista, com a arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CListView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CListView:CListView](#clistview)|Constrói um objeto `CListView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CListView::GetListCtrl](#getlistctrl)|Retorna o controle de lista associado à exibição.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CListView::RemoveImageList](#removeimagelist)|Remove a lista de imagens especificada da exibição da lista.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre essa arquitetura, consulte a visão geral da classe [CView](../../mfc/reference/cview-class.md) e as referências cruzadas citadas lá.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[Cctrlview](../../mfc/reference/cctrlview-class.md)

`CListView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcview.h

## <a name="clistviewclistview"></a><a name="clistview"></a>CListView:CListView

Constrói um objeto `CListView`.

```
CListView();
```

## <a name="clistviewgetlistctrl"></a><a name="getlistctrl"></a>CListView::GetListCtrl

Ligue para esta função de membro para obter uma referência ao controle de lista associado à exibição.

```
CListCtrl& GetListCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao controle de lista associado à exibição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCListView#7](../../atl/reference/codesnippet/cpp/clistview-class_1.cpp)]

## <a name="clistviewremoveimagelist"></a><a name="removeimagelist"></a>CListView::RemoveImageList

Remove a lista de imagens especificada da exibição da lista.

```
void RemoveImageList(int nImageList);
```

### <a name="parameters"></a>Parâmetros

*nImageList*<br/>
O índice baseado em zero da imagem para remover.

## <a name="see-also"></a>Confira também

[Lista de linhas de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)
