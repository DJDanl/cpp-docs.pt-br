---
title: Classe CMFCDragFrameImpl
ms.date: 10/18/2018
f1_keywords:
- CMFCDragFrameImpl
helpviewer_keywords:
- CMFCDragFrameImpl class [MFC]
ms.assetid: 500cd824-8188-43c2-8754-b7bb46b5648a
ms.openlocfilehash: a2f6f558d6b4452ca06429c7e3017b7c575c6676
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367559"
---
# <a name="cmfcdragframeimpl-class"></a>Classe CMFCDragFrameImpl

A `CMFCDragFrameImpl` classe desenha o retângulo de arrasto que aparece quando o usuário arrasta um painel no modo de doca padrão.
Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCDragFrameImpl
```

## <a name="remarks"></a>Comentários

Um objeto desta classe está incorporado em cada objeto [da Classe CPane.](../../mfc/reference/cpane-class.md) Assim, cada painel que `CanFloat` usa o método exibe um retângulo de arrasto quando o usuário o arrasta.

Você pode controlar a espessura do retângulo de arrasto usando [AFX_GLOBAL_DATA::m_nDragFrameThicknessFloat](afx-global-data-structure.md#m_ndragframethicknessfloat) e [AFX_GLOBAL_DATA::m_nDragFrameThicknessDock](afx-global-data-structure.md#m_ndragframethicknessdock).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CMFCDragFrameImpl](../../mfc/reference/cmfcdragframeimpl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdragframeimpl.h

## <a name="cmfcdragframeimplenddrawdragframe"></a><a name="enddrawdragframe"></a>CMFCDragFrameImpl::EndDrawDragFrame

```
void EndDrawDragFrame(BOOL bClearInternalRects = TRUE);
```

### <a name="parameters"></a>Parâmetros

[em] *bClearInternalRects*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdragframeimplinit"></a><a name="init"></a>CMFCDragFrameImpl::Init

```
void Init(CWnd* pDraggedWnd);
```

### <a name="parameters"></a>Parâmetros

[em] *pDraggedwnd*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdragframeimplmovedragframe"></a><a name="movedragframe"></a>CMFCDragFrameImpl::MoveDragFrame

```
void MoveDragFrame(BOOL bForceMove = FALSE);
```

### <a name="parameters"></a>Parâmetros

[em] *bForceMove*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdragframeimplplacetabpredocking"></a><a name="placetabpredocking"></a>CMFCDragFrameImpl::PlaceTabPreDocking

```
void PlaceTabPreDocking(
    CBaseTabbedPane* pTabbedBar,
    BOOL bFirstTime);

void PlaceTabPreDocking(CWnd* pCBarToPlaceOn);
```

### <a name="parameters"></a>Parâmetros

[em] *barra pTabbed*<br/>

[em] *bFirstTime*<br/>

[em] *pCbartoplaceon*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdragframeimplremovetabpredocking"></a><a name="removetabpredocking"></a>CMFCDragFrameImpl::RemoveTabPreDocking

```
void RemoveTabPreDocking(CDockablePane* pOldTargetBar = NULL);
```

### <a name="parameters"></a>Parâmetros

[em] *pOldTargetBar*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfcdragframeimplresetstate"></a><a name="resetstate"></a>CMFCDragFrameImpl::ResetState

```
void ResetState();
```

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPane](../../mfc/reference/cpane-class.md)
