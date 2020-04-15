---
title: Classe COleResizeBar
ms.date: 11/04/2016
f1_keywords:
- COleResizeBar
- AFXOLE/COleResizeBar
- AFXOLE/COleResizeBar::COleResizeBar
- AFXOLE/COleResizeBar::Create
helpviewer_keywords:
- COleResizeBar [MFC], COleResizeBar
- COleResizeBar [MFC], Create
ms.assetid: 56a708d9-28c5-4eb0-9404-77b688d91c63
ms.openlocfilehash: beb0c37b6ac23310b7d5c8506fbdaf677dd74d8d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376149"
---
# <a name="coleresizebar-class"></a>Classe COleResizeBar

Um tipo de barra de controle que suporta o redimensionamento de itens OLE no local.

## <a name="syntax"></a>Sintaxe

```
class COleResizeBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Barra de tamanho coleResize::COleResizeBar](#coleresizebar)|Constrói um objeto `COleResizeBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleResizeBar::Criar](#create)|Cria e inicializa uma janela do windows `COleResizeBar` child e a associa ao objeto.|

## <a name="remarks"></a>Comentários

`COleResizeBar`objetos aparecem como um [CRectTracker](../../mfc/reference/crecttracker-class.md) com uma borda eclodida e alças externas de redimensionamento.

`COleResizeBar`objetos geralmente são membros incorporados de objetos de janela de quadro derivados da classe [COleIPFrameWnd.](../../mfc/reference/coleipframewnd-class.md)

Para obter mais informações, consulte o artigo [Ativação](../../mfc/activation-cpp.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Ccontrolbar](../../mfc/reference/ccontrolbar-class.md)

`COleResizeBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coleresizebarcoleresizebar"></a><a name="coleresizebar"></a>Barra de tamanho coleResize::COleResizeBar

Constrói um objeto `COleResizeBar`.

```
COleResizeBar();
```

### <a name="remarks"></a>Comentários

Chamada `Create` para criar o objeto de barra de redimensionamento.

## <a name="coleresizebarcreate"></a><a name="create"></a>COleResizeBar::Criar

Cria uma janela de criança `COleResizeBar` e associa-a ao objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE,
    UINT nID = AFX_IDW_RESIZE_BAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para a janela pai da barra de redimensionamento.

*Dwstyle*<br/>
Especifica os atributos de estilo da [janela.](../../mfc/reference/styles-used-by-mfc.md#window-styles)

*nID*<br/>
A janela do bar redimensionada iD da janela.

### <a name="return-value"></a>Valor retornado

Não zero se a barra de redimensionamento foi criada; caso contrário, 0.

## <a name="see-also"></a>Confira também

[SuperPAD de amostra de MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)
